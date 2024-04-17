/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscombo.c
 *
 */

/* Operating System native combo box */

#include "oscombo.h"
#include "oscombo_win.inl"
#include "osgui.inl"
#include "osgui_win.inl"
#include "oscontrol_win.inl"
#include "osimglist.inl"
#include "ospanel_win.inl"
#include "ostooltip.inl"
#include "oswindow_win.inl"
#include <draw2d/font.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

struct _oscombo_t
{
    OSControl control;
    Font *font;
    bool_t launch_event;
    bool_t with_initial_size;
    HWND combo_hwnd;
    HWND edit_hwnd;
    HWND tooltip_combo;
    HWND tooltip_edit;
    WNDPROC def_combo_proc;
    WNDPROC def_edit_proc;
    OSImgList *image_list;
    COLORREF color;
    COLORREF bgcolor;
    HBRUSH bgbrush;
    Listener *OnFilter;
    Listener *OnChange;
    Listener *OnFocus;
    Listener *OnSelect;
};

/*---------------------------------------------------------------------------*/

static COLORREF i_color(const OSCombo *combo)
{
    cassert_no_null(combo);
    if (combo->color != UINT32_MAX)
        return combo->color & 0x00FFFFFF;
    return UINT32_MAX;
}

/*---------------------------------------------------------------------------*/

static HBRUSH i_background_color(const OSCombo *combo, COLORREF *color)
{
    cassert_no_null(combo);
    if (combo->bgbrush != NULL)
    {
        *color = combo->bgcolor & 0x00FFFFFF;
        return combo->bgbrush;
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSCombo *combo = (OSCombo *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(combo);

    switch (uMsg)
    {
    case WM_ERASEBKGND:
        return 1;

    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
        if (_oswindow_mouse_down(OSControlPtr(combo)) == TRUE)
            break;
        return 0;

    case WM_PAINT:
        if (_oswindow_in_resizing(hwnd) == TRUE)
            return 0;
        break;

    case WM_CTLCOLOREDIT:
    {
        HBRUSH default_brush = (HBRUSH)CallWindowProc(combo->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
        HDC hdc = (HDC)wParam;
        COLORREF color = UINT32_MAX, bgcolor = UINT32_MAX;
        HBRUSH bgbrush = NULL;
        color = i_color(combo);
        bgbrush = i_background_color(combo, &bgcolor);

        if (color != UINT32_MAX)
            SetTextColor(hdc, color);

        if (bgbrush != NULL)
        {
            SetBkColor(hdc, bgcolor);
            return (LRESULT)bgbrush;
        }

        return (LRESULT)default_brush;
    }
    }

    return CallWindowProc(combo->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_ComboWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSCombo *combo = (OSCombo *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(combo);

    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
        if (_oswindow_mouse_down(OSControlPtr(combo)) == TRUE)
            break;
        return 0;
    }

    return combo->def_combo_proc(hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_EditWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSCombo *combo = (OSCombo *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(combo);

    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
        if (_oswindow_mouse_down(OSControlPtr(combo)) == TRUE)
            break;
        return 0;
    }

    return combo->def_edit_proc(hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

OSCombo *oscombo_create(const uint32_t flags)
{
    OSCombo *combo = heap_new0(OSCombo);
    combo->control.type = ekGUI_TYPE_COMBOBOX;
    _oscontrol_init((OSControl *)combo, PARAM(dwExStyle, WS_EX_NOPARENTNOTIFY | CBES_EX_NOSIZELIMIT), WS_CHILD | WS_CLIPSIBLINGS | CBS_DROPDOWN, WC_COMBOBOXEX, 0, 0, i_WndProc, kDEFAULT_PARENT_WINDOW);
    combo->font = osgui_create_default_font();
    combo->launch_event = TRUE;
    combo->combo_hwnd = (HWND)SendMessage(combo->control.hwnd, CBEM_GETCOMBOCONTROL, (WPARAM)0, (LPARAM)0);
    combo->edit_hwnd = (HWND)SendMessage(combo->control.hwnd, CBEM_GETEDITCONTROL, (WPARAM)0, (LPARAM)0);
    combo->def_combo_proc = (WNDPROC)SetWindowLongPtr(combo->combo_hwnd, GWLP_WNDPROC, (LONG_PTR)i_ComboWndProc);
    combo->def_edit_proc = (WNDPROC)SetWindowLongPtr(combo->edit_hwnd, GWLP_WNDPROC, (LONG_PTR)i_EditWndProc);
    SetWindowLongPtr(combo->combo_hwnd, GWLP_USERDATA, (LONG_PTR)combo);
    SetWindowLongPtr(combo->edit_hwnd, GWLP_USERDATA, (LONG_PTR)combo);
    combo->image_list = _osimglist_create(16);
    combo->color = UINT32_MAX;
    combo->bgcolor = UINT32_MAX;
    _oscontrol_set_font((OSControl *)combo, combo->font);
    unref(flags);
    return combo;
}

/*---------------------------------------------------------------------------*/

void oscombo_destroy(OSCombo **combo)
{
    cassert_no_null(combo);
    cassert_no_null(*combo);
    cassert((*combo)->control.tooltip_hwnd == NULL);
    font_destroy(&(*combo)->font);
    listener_destroy(&(*combo)->OnFilter);
    listener_destroy(&(*combo)->OnChange);
    listener_destroy(&(*combo)->OnFocus);
    listener_destroy(&(*combo)->OnSelect);
    _ostooltip_destroy_optional(&(*combo)->tooltip_combo, (*combo)->combo_hwnd);
    _ostooltip_destroy_optional(&(*combo)->tooltip_edit, (*combo)->edit_hwnd);
    _oscontrol_destroy_brush(&(*combo)->bgbrush);
    _osimglist_destroy(&(*combo)->image_list);
    _oscontrol_destroy(&(*combo)->control);
    heap_delete(combo, OSCombo);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnFilter(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnFilter, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnChange(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnChange, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnFocus(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnFocus, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnSelect(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnSelect, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_text(OSCombo *combo, const char_t *text)
{
    cassert_no_null(combo);
    cassert(combo->launch_event == TRUE);
    combo->launch_event = FALSE;
    _oscontrol_set_text((OSControl *)combo, text);
    combo->launch_event = TRUE;
}

/*---------------------------------------------------------------------------*/

void oscombo_tooltip(OSCombo *combo, const char_t *text)
{
    cassert_no_null(combo);
    _ostooltip_set_text(&combo->tooltip_combo, combo->combo_hwnd, text);
    _ostooltip_set_text(&combo->tooltip_edit, combo->edit_hwnd, text);
}

/*---------------------------------------------------------------------------*/

void oscombo_font(OSCombo *combo, const Font *font)
{
    cassert_no_null(combo);
    _oscontrol_update_font((OSControl *)combo, &combo->font, font);
}

/*---------------------------------------------------------------------------*/

void oscombo_align(OSCombo *combo, const align_t align)
{
    cassert_no_null(combo);
    unref(align);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oscombo_passmode(OSCombo *combo, const bool_t passmode)
{
    cassert_no_null(combo);
    unref(passmode);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oscombo_color(OSCombo *combo, const color_t color)
{
    cassert_no_null(combo);
    combo->color = color;
    InvalidateRect(combo->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

void oscombo_bgcolor(OSCombo *combo, const color_t color)
{
    cassert_no_null(combo);
    _oscontrol_update_brush(color, &combo->bgbrush, &combo->bgcolor);
}

/*---------------------------------------------------------------------------*/

static int i_img_index(HWND hwnd, OSImgList *imglist, const Image *image)
{
    int index = 0;

    if (image != NULL)
    {
        /* Image exits in list --> rehuse */
        index = _osimglist_find(imglist, image);

        /* Check for unused image --> replace */
        if (index == -1)
        {
            register uint32_t num_images = _osimglist_num_elems(imglist);
            if (num_images > 0)
            {
                register uint32_t i = 0, num_elems = (uint32_t)SendMessage(hwnd, CB_GETCOUNT, 0, 0);
                bool_t *exists = heap_new_n0(num_images, bool_t);

                for (i = 0; i < num_elems; ++i)
                {
                    COMBOBOXEXITEM cbbi = {0};
                    LRESULT res;
                    cbbi.iItem = (INT_PTR)i;
                    cbbi.mask = CBEIF_IMAGE;
                    res = SendMessage(hwnd, CBEM_GETITEM, (WPARAM)0, (LPARAM)&cbbi);
                    cassert_unref(res != 0, res);
                    exists[cbbi.iImage] = TRUE;
                }

                for (i = 1; i < num_images && index == -1; ++i)
                {
                    if (exists[i] == FALSE)
                    {
                        index = (int)i;
                        _osimglist_replace(imglist, index, image);
                    }
                }

                heap_delete_n(&exists, num_images, bool_t);
            }
        }

        /* Add a new image */
        if (index == -1)
        {
            uint8_t result = 0;
            index = _osimglist_add(imglist, image, &result);
            if (result == HIMAGELIST_CREATED)
            {
                HIMAGELIST hlist = _osimglist_hlist(imglist);
                HIMAGELIST previous = (HIMAGELIST)SendMessage(hwnd, CBEM_SETIMAGELIST, 0, (LPARAM)hlist);
                cassert_unref(previous == NULL, previous);
            }
        }
    }

    return index;
}

/*---------------------------------------------------------------------------*/

void oscombo_elem(OSCombo *combo, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *image)
{
    cassert_no_null(combo);
    _oscombo_elem(combo->control.hwnd, combo->image_list, op, index, text, image);
    if (combo->with_initial_size == TRUE)
    {
        uint32_t num_elems = (uint32_t)SendMessage(combo->control.hwnd, CB_GETCOUNT, (WPARAM)0, (LPARAM)0);
        if (num_elems == 0)
            num_elems = 1;
        else if (num_elems > 10)
            num_elems = 10;

        _oscombo_set_list_height(combo->control.hwnd, combo->combo_hwnd, _osimglist_height(combo->image_list), num_elems);
    }
}

/*---------------------------------------------------------------------------*/

void oscombo_selected(OSCombo *combo, const uint32_t index)
{
    LRESULT ret = 0;
    cassert_no_null(combo);
    cassert(combo->launch_event == TRUE);
    combo->launch_event = FALSE;
    ret = SendMessage(combo->control.hwnd, CB_SETCURSEL, (WPARAM)((index != UINT32_MAX) ? index : -1), (LPARAM)0);
    cassert(ret == (LRESULT)index);
    combo->launch_event = TRUE;
}

/*---------------------------------------------------------------------------*/

uint32_t oscombo_get_selected(const OSCombo *combo)
{
    LRESULT res = CB_ERR;
    cassert_no_null(combo);
    res = SendMessage(combo->control.hwnd, CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
    if (res != CB_ERR)
        return (uint32_t)res;
    else
        return UINT32_MAX;
}

/*---------------------------------------------------------------------------*/

void oscombo_bounds(const OSCombo *combo, const real32_t refwidth, real32_t *width, real32_t *height)
{
    register WORD button_height = 0;
    cassert_no_null(combo);
    cassert_no_null(width);
    cassert_no_null(height);
    button_height = (14 * HIWORD(GetDialogBaseUnits())) / 8;
    *width = refwidth;
    *height = (real32_t)(button_height - 4);
}

/*---------------------------------------------------------------------------*/

void oscombo_attach(OSCombo *combo, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)combo);
}

/*---------------------------------------------------------------------------*/

void oscombo_detach(OSCombo *combo, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)combo);
}

/*---------------------------------------------------------------------------*/

void oscombo_visible(OSCombo *combo, const bool_t visible)
{
    _oscontrol_set_visible((OSControl *)combo, visible);
}

/*---------------------------------------------------------------------------*/

void oscombo_enabled(OSCombo *combo, const bool_t enabled)
{
    cassert(GetFocus() != combo->control.hwnd);
    _oscontrol_set_enabled((OSControl *)combo, enabled);
}

/*---------------------------------------------------------------------------*/

void oscombo_size(const OSCombo *combo, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)combo, width, height);
}

/*---------------------------------------------------------------------------*/

void oscombo_origin(const OSCombo *combo, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)combo, x, y);
}

/*---------------------------------------------------------------------------*/

void oscombo_frame(OSCombo *combo, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    uint32_t num_elems = (uint32_t)SendMessage(combo->control.hwnd, CB_GETCOUNT, (WPARAM)0, (LPARAM)0);
    _oscontrol_set_frame((OSControl *)combo, x, y, width, height);
    combo->with_initial_size = TRUE;

    if (num_elems == 0)
        num_elems = 1;
    else if (num_elems > 10)
        num_elems = 10;

    _oscombo_set_list_height(combo->control.hwnd, combo->combo_hwnd, _osimglist_height(combo->image_list), num_elems);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get_cursor_pos(HWND hwnd)
{
    DWORD start;
    SendMessage(hwnd, CB_GETEDITSEL, (WPARAM)&start, (LPARAM)NULL);
    return (uint32_t)start;
}

/*---------------------------------------------------------------------------*/

static void i_set_cursor_pos(HWND hwnd, const uint32_t pos)
{
    SendMessage(hwnd, CB_SETEDITSEL, (WPARAM)0, (LPARAM)MAKELONG((WORD)pos, (WORD)pos));
}

/*---------------------------------------------------------------------------*/

void _oscombo_command(OSCombo *combo, WPARAM wParam)
{
    cassert_no_null(combo);
    if (HIWORD(wParam) == CBN_EDITCHANGE)
    {
        if (combo->launch_event == TRUE && IsWindowEnabled(combo->control.hwnd) && combo->OnFilter != NULL)
        {
            char_t *combo_text;
            uint32_t tsize;
            EvText params;
            EvTextFilter result;
            combo_text = _oscontrol_get_text((const OSControl *)combo, &tsize);
            params.text = (const char_t *)combo_text;
            params.cpos = i_get_cursor_pos(combo->control.hwnd);
            result.apply = FALSE;
            result.text[0] = '\0';
            result.cpos = UINT32_MAX;
            listener_event(combo->OnFilter, ekGUI_EVENT_TXTFILTER, combo, &params, &result, OSCombo, EvText, EvTextFilter);
            heap_free((byte_t **)&combo_text, tsize, "OSControlGetText");

            if (result.apply == TRUE)
            {
                bool_t prev = combo->launch_event;
                combo->launch_event = FALSE;
                _oscontrol_set_text(&combo->control, result.text);
                combo->launch_event = prev;
            }

            if (result.cpos != UINT32_MAX)
                i_set_cursor_pos(combo->control.hwnd, result.cpos);
            else
                i_set_cursor_pos(combo->control.hwnd, params.cpos);
        }
    }

    else if (HIWORD(wParam) == CBN_SELCHANGE)
    {
        InvalidateRect((HWND)combo->control.hwnd, NULL, FALSE);
        InvalidateRect((HWND)combo->edit_hwnd, NULL, FALSE);
        InvalidateRect((HWND)combo->combo_hwnd, NULL, FALSE);

        SendMessage(combo->control.hwnd, CB_SETCURSEL, (WPARAM)1, (LPARAM)0);

        //if (IsWindowEnabled(combo->control.hwnd) && combo->OnSelect.object != NULL)
        //{
        //    Event event;
        //    EvButton params;
        //    uint32_t i,n;
        //    event.type = ekGUI_EVENT_BUTTON_PUSH;
        //    event.sender1 = combo;
        //    event.params1 = &params;
        //    event.result1 = NULL;
        //    #if defined (__ASSERTS__)
        //    event.sender_type = "OSCombo";
        //    event.params_type = "EvButton";
        //    event.result_type = "";
        //    #endif
        //    params.state = ekGUI_ON;
        //    params.index = (uint16_t)SendMessage(combo->control.hwnd, CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
        //    i = SendMessage(combo->combo_hwnd, CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
        //    n = SendMessage(combo->combo_hwnd, CB_GETCOUNT, (WPARAM)0, (LPARAM)0);
        //    cassert(params.index >= 0 && params.index < (uint16_t)SendMessage(combo->control.hwnd, CB_GETCOUNT, (WPARAM)0, (LPARAM)0));
        //    params.text = NULL;
        //    listener_event(&combo->OnSelect, &event);
        //}
    }
}

/*---------------------------------------------------------------------------*/

HWND _oscombo_focus_widget(OSCombo *combo)
{
    cassert_no_null(combo);
    return combo->edit_hwnd;
}

/*---------------------------------------------------------------------------*/

void _oscombo_elem(HWND hwnd, OSImgList *imglist, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *image)
{
    if (op != ekCTRL_OP_DEL)
    {
        uint32_t num_bytes = 0;
        WCHAR *wtext = NULL;
        WCHAR wtext_static[WCHAR_BUFFER_SIZE];
        WCHAR *wtext_alloc = NULL;
        UINT msg = 0;
        COMBOBOXEXITEM cbbi = {0};

        num_bytes = unicode_convers_nbytes(text, ekUTF8, kWINDOWS_UNICODE);
        if (num_bytes < sizeof(wtext_static))
        {
            wtext = wtext_static;
        }
        else
        {
            wtext_alloc = (WCHAR *)heap_malloc(num_bytes, "OSComboSetElem");
            wtext = wtext_alloc;
        }

        {
            register uint32_t bytes = unicode_convers(text, (char_t *)wtext, ekUTF8, kWINDOWS_UNICODE, num_bytes);
            cassert_unref(bytes == num_bytes, bytes);
        }

        switch (op)
        {
        case ekCTRL_OP_ADD:
            cbbi.iItem = -1;
            msg = CBEM_INSERTITEM;
            break;
        case ekCTRL_OP_INS:
            cbbi.iItem = (INT_PTR)index;
            msg = CBEM_INSERTITEM;
            break;
        case ekCTRL_OP_SET:
            cbbi.iItem = (INT_PTR)index;
            msg = CBEM_SETITEM;
            break;
        case ekCTRL_OP_DEL:
            cassert_default();
        }

        cbbi.mask = CBEIF_TEXT | CBEIF_IMAGE | CBEIF_SELECTEDIMAGE;
        cbbi.pszText = wtext;
        cbbi.iImage = i_img_index(hwnd, imglist, image);
        cbbi.iSelectedImage = cbbi.iImage;
        SendMessage(hwnd, msg, (WPARAM)0, (LPARAM)&cbbi);

        if (wtext_alloc != NULL)
            heap_free((byte_t **)(&wtext_alloc), num_bytes, "OSComboSetElem");
    }
    else
    {
        LRESULT res = SendMessage(hwnd, CBEM_DELETEITEM, (WPARAM)index, (LPARAM)0);
        cassert_unref(res != CB_ERR, res);
    }
}

/*---------------------------------------------------------------------------*/

void _oscombo_set_list_height(HWND hwnd, HWND combo_hwnd, const uint32_t image_height, uint32_t num_elems)
{
    uint32_t height = ((14 * HIWORD(GetDialogBaseUnits())) / 8) - 4;
    //uint32_t num_elems = (uint32_t)SendMessage(hwnd, CB_GETCOUNT, (WPARAM)0, (LPARAM)0);
    uint32_t line_height = (uint32_t)SendMessage(hwnd, CB_GETITEMHEIGHT, (WPARAM) /*-1*/ 0, (LPARAM)0);
    RECT rect;

    //if (num_elems == 0)
    //    num_elems = 1;
    //else if (num_elems > 10)
    //    num_elems = 10;

    GetClientRect(hwnd, &rect);

    if (image_height != UINT32_MAX)
    {
        if (line_height < image_height + 4)
            line_height = image_height + 4;
    }

    height += (num_elems /* - 1*/) * line_height;
    SetWindowPos(combo_hwnd, NULL, 0, 0, rect.right - rect.left, height, SWP_NOMOVE | SWP_NOZORDER);
}

/*---------------------------------------------------------------------------*/

bool_t oscombo_resign_focus(const OSCombo *combo)
{
    bool_t lost_focus = TRUE;
    if (combo->OnChange != NULL)
    {
        char_t *combo_text = NULL;
        uint32_t tsize = 0;
        EvText params;
        combo_text = _oscontrol_get_text((const OSControl *)combo, &tsize);
        params.text = (const char_t *)combo_text;
        listener_event(combo->OnChange, ekGUI_EVENT_TXTCHANGE, combo, &params, &lost_focus, OSCombo, EvText, bool_t);
        heap_free((byte_t **)&combo_text, tsize, "OSControlGetText");
    }

    return lost_focus;
}

/*---------------------------------------------------------------------------*/

void oscombo_focus(OSCombo *combo, const bool_t focus)
{
    cassert_no_null(combo);
    if (combo->OnFocus != NULL)
    {
        bool_t params = focus;
        listener_event(combo->OnFocus, ekGUI_EVENT_FOCUS, combo, &params, NULL, OSCombo, bool_t, void);
    }
}
