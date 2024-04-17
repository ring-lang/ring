/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospopup.c
 *
 */

/* Operating System native popup button */

#include "ospopup.h"
#include "ospopup.inl"
#include "osgui.inl"
#include "osgui_win.inl"
#include "oscontrol_win.inl"
#include "oscombo_win.inl"
#include "ospanel_win.inl"
#include "oswindow_win.inl"
#include "osimglist.inl"
#include "ostooltip.inl"
#include <draw2d/font.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

struct _ospopup_t
{
    OSControl control;
    Font *font;
    HWND combo_hwnd;
    WNDPROC def_combo_proc;
    uint32_t list_num_elems;
    OSImgList *image_list;
    Listener *OnSelect;
};

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSPopUp *popup = (OSPopUp *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(popup);

    switch (uMsg)
    {
    case WM_ERASEBKGND:
        return 1;

    case WM_PAINT:
        if (_oswindow_in_resizing(hwnd) == TRUE)
            return 0;
        break;

    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
        if (_oswindow_mouse_down(OSControlPtr(popup)) == TRUE)
            break;
        return 0;
    }

    return CallWindowProc(popup->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_ComboWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSPopUp *popup = (OSPopUp *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(popup);

    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
        if (_oswindow_mouse_down(OSControlPtr(popup)) == TRUE)
            break;
        return 0;
    }

    return popup->def_combo_proc(hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

OSPopUp *ospopup_create(const uint32_t flags)
{
    OSPopUp *popup = NULL;
    DWORD dwStyle = WS_CHILD | WS_CLIPSIBLINGS | CBS_DROPDOWNLIST;
    unref(flags);
    popup = heap_new0(OSPopUp);
    popup->control.type = ekGUI_TYPE_POPUP;
    _oscontrol_init((OSControl *)popup, PARAM(dwExStyle, WS_EX_NOPARENTNOTIFY | CBES_EX_NOSIZELIMIT), dwStyle, WC_COMBOBOXEX, 0, 120, i_WndProc, kDEFAULT_PARENT_WINDOW);
    popup->font = osgui_create_default_font();
    popup->combo_hwnd = (HWND)SendMessage(popup->control.hwnd, CBEM_GETCOMBOCONTROL, (WPARAM)0, (LPARAM)0);
    popup->def_combo_proc = (WNDPROC)SetWindowLongPtr(popup->combo_hwnd, GWLP_WNDPROC, (LONG_PTR)i_ComboWndProc);
    SetWindowLongPtr(popup->combo_hwnd, GWLP_USERDATA, (LONG_PTR)popup);
    popup->image_list = _osimglist_create(16);
    popup->list_num_elems = 5;
    _oscontrol_set_font((OSControl *)popup, popup->font);
    return popup;
}

/*---------------------------------------------------------------------------*/

void ospopup_destroy(OSPopUp **popup)
{
    cassert_no_null(popup);
    cassert_no_null(*popup);
    font_destroy(&(*popup)->font);
    listener_destroy(&(*popup)->OnSelect);
    _osimglist_destroy(&(*popup)->image_list);
    _oscontrol_destroy(&(*popup)->control);
    heap_delete(popup, OSPopUp);
}

/*---------------------------------------------------------------------------*/

void ospopup_OnSelect(OSPopUp *popup, Listener *listener)
{
    cassert_no_null(popup);
    listener_update(&popup->OnSelect, listener);
}

/*---------------------------------------------------------------------------*/

void ospopup_elem(OSPopUp *popup, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *image)
{
    cassert_no_null(popup);
    _oscombo_elem(popup->control.hwnd, popup->image_list, op, index, text, image);
    if (SendMessage(popup->control.hwnd, CB_GETCURSEL, (WPARAM)0, (LPARAM)0) == -1)
        SendMessage(popup->control.hwnd, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
    InvalidateRect(popup->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

void ospopup_tooltip(OSPopUp *popup, const char_t *text)
{
    cassert_no_null(popup);
    _ostooltip_set_text(&popup->control.tooltip_hwnd, popup->combo_hwnd, text);
}

/*---------------------------------------------------------------------------*/

void ospopup_font(OSPopUp *popup, const Font *font)
{
    cassert_no_null(popup);
    _oscontrol_update_font((OSControl *)popup, &popup->font, font);
}

/*---------------------------------------------------------------------------*/

void ospopup_list_height(OSPopUp *popup, const uint32_t num_elems)
{
    cassert_no_null(popup);
    popup->list_num_elems = num_elems;
    _oscombo_set_list_height(popup->control.hwnd, popup->combo_hwnd, _osimglist_height(popup->image_list), popup->list_num_elems);
}

/*---------------------------------------------------------------------------*/

void ospopup_selected(OSPopUp *popup, const uint32_t index)
{
    cassert_no_null(popup);
    if (index != UINT32_MAX)
    {
        LRESULT ret = SendMessage(popup->control.hwnd, CB_SETCURSEL, (WPARAM)index, (LPARAM)0);
        cassert_unref(ret == (LRESULT)index, ret);
    }
    else
    {
        LRESULT ret = SendMessage(popup->control.hwnd, CB_SETCURSEL, (WPARAM)-1, (LPARAM)0);
        cassert_unref(ret == (LRESULT)-1, ret);
    }
}

/*---------------------------------------------------------------------------*/

uint32_t ospopup_get_selected(const OSPopUp *popup)
{
    cassert_no_null(popup);
    return (uint32_t)SendMessage(popup->control.hwnd, CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
}

/*---------------------------------------------------------------------------*/

void ospopup_bounds(const OSPopUp *popup, const char_t *text, real32_t *width, real32_t *height)
{
    uint32_t imgwidth = UINT32_MAX;
    cassert_no_null(popup);
    cassert_no_null(width);
    cassert_no_null(height);
    _oscontrol_text_bounds((const OSControl *)popup, text, popup->font, -1.f, width, height);

    *width += 40.f;
    *height = 24.f;
    imgwidth = _osimglist_width(popup->image_list);
    if (imgwidth != UINT32_MAX)
        *width += (real32_t)(imgwidth + 5);
}

/*---------------------------------------------------------------------------*/

void ospopup_attach(OSPopUp *popup, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)popup);
}

/*---------------------------------------------------------------------------*/

void ospopup_detach(OSPopUp *popup, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)popup);
}

/*---------------------------------------------------------------------------*/

void ospopup_visible(OSPopUp *popup, const bool_t visible)
{
    _oscontrol_set_visible((OSControl *)popup, visible);
}

/*---------------------------------------------------------------------------*/

void ospopup_enabled(OSPopUp *popup, const bool_t enabled)
{
    _oscontrol_set_enabled((OSControl *)popup, enabled);
}

/*---------------------------------------------------------------------------*/

void ospopup_size(const OSPopUp *popup, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)popup, width, height);
}

/*---------------------------------------------------------------------------*/

void ospopup_origin(const OSPopUp *popup, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)popup, x, y);
}

/*---------------------------------------------------------------------------*/

void ospopup_frame(OSPopUp *popup, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)popup, x, y, width, height);
    _oscombo_set_list_height(popup->control.hwnd, popup->combo_hwnd, _osimglist_height(popup->image_list), popup->list_num_elems);
}

/*---------------------------------------------------------------------------*/

void _ospopup_command(OSPopUp *popup, WPARAM wParam)
{
    cassert_no_null(popup);
    if (HIWORD(wParam) == CBN_SELCHANGE && IsWindowEnabled(popup->control.hwnd) && popup->OnSelect != NULL)
    {
        EvButton params;
        params.state = ekGUI_ON;
        params.index = (uint32_t)SendMessage(popup->control.hwnd, CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
        cassert(params.index < (uint32_t)SendMessage(popup->control.hwnd, CB_GETCOUNT, (WPARAM)0, (LPARAM)0));
        params.text = NULL;
        listener_event(popup->OnSelect, ekGUI_EVENT_POPUP, popup, &params, NULL, OSPopUp, EvButton, void);
    }
}

/*---------------------------------------------------------------------------*/

HWND _ospopup_focus_widget(OSPopUp *popup)
{
    cassert_no_null(popup);
    return popup->combo_hwnd;
}
