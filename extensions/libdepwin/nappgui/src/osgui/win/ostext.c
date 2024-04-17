/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ostext.c
 *
 */

/* Operating System native text view */

#include "ostext.h"
#include "ostext_win.inl"
#include "osgui.inl"
#include "osgui_win.inl"
#include "oscontrol_win.inl"
#include "ospanel_win.inl"
#include "oswindow_win.inl"
#include <draw2d/color.h>
#include <draw2d/font.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/stream.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

#include <sewer/nowarn.hxx>
#include <Richedit.h>
#include <sewer/warn.hxx>

struct _ostext_t
{
    OSControl control;
    uint32_t units;
    DWORD dwEffects;
    LONG yHeight;
    COLORREF crTextColor;
    COLORREF crBackColor;
    WORD wAlignment;
    LONG dyLineSpacing;
    LONG dySpaceBefore;
    LONG dySpaceAfter;
    WCHAR szFaceName[LF_FACESIZE];
    char_t *text;
    uint32_t text_size;
    uint32_t num_chars;
    bool_t is_editable;
    bool_t launch_event;
    bool_t focused;
    RECT border;
    Listener *OnFilter;
    Listener *OnFocus;
};

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSText *view = (OSText *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(view);

    switch (uMsg)
    {
    case WM_NCCALCSIZE:
    {
        LRESULT res = CallWindowProc(view->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
        res = _osgui_nccalcsize(hwnd, wParam, lParam, TRUE, 0, &view->border);
        return res;
    }

    case WM_NCPAINT:
    {
        LRESULT res = CallWindowProc(view->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
        res = _osgui_ncpaint(hwnd, view->focused, &view->border, NULL);
        return res;
    }

    case WM_PAINT:
        if (_oswindow_in_resizing(hwnd) == TRUE)
            return 0;
        break;

    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
        if (_oswindow_mouse_down(OSControlPtr(view)) == TRUE)
            break;
        return 0;
    }

    return CallWindowProc(view->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

static void i_set_editable(HWND hwnd, const BOOL is_editable)
{
    LRESULT res = 0;
    res = SendMessage(hwnd, EM_SETREADONLY, (WPARAM)!is_editable, (LPARAM)0);
    cassert(res != 0);
}

/*---------------------------------------------------------------------------*/

static void i_set_rich_text(HWND hwnd, const BOOL rich_text)
{
    DWORD flags;
    LRESULT res;
    flags = (rich_text == TRUE) ? TM_RICHTEXT : TM_PLAINTEXT;
    res = SendMessage(hwnd, EM_SETTEXTMODE, flags, 0);
    cassert(res == 0);
}

/*---------------------------------------------------------------------------*/

OSText *ostext_create(const uint32_t flags)
{
    OSText *view = NULL;
    DWORD dwStyle = 0;
    unref(flags);
    view = heap_new0(OSText);
    view->control.type = ekGUI_TYPE_TEXTVIEW;
    dwStyle = WS_CHILD | WS_CLIPSIBLINGS | ES_MULTILINE | ES_WANTRETURN /*| ES_AUTOVSCROLL*/ | WS_VSCROLL /*| WS_HSCROLL*/;
    _oscontrol_init((OSControl *)view, PARAM(dwExStyle, WS_EX_NOPARENTNOTIFY), dwStyle, kRICHEDIT_CLASS, 0, 0, i_WndProc, kDEFAULT_PARENT_WINDOW);
    i_set_rich_text(view->control.hwnd, TRUE);
    i_set_editable(view->control.hwnd, FALSE);
    view->launch_event = TRUE;
    view->focused = FALSE;
    view->dyLineSpacing = 20;
    view->num_chars = 0;
    return view;
}

/*---------------------------------------------------------------------------*/

void ostext_destroy(OSText **view)
{
    cassert_no_null(view);
    cassert_no_null(*view);
    listener_destroy(&(*view)->OnFilter);
    listener_destroy(&(*view)->OnFocus);

    if ((*view)->text != NULL)
        heap_free((byte_t **)&(*view)->text, (*view)->text_size, "OSTextText");

    _oscontrol_destroy((OSControl *)*view);
    heap_delete(view, OSText);
}

/*---------------------------------------------------------------------------*/

void ostext_OnFilter(OSText *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->OnFilter, listener);

    if (listener != NULL)
        SendMessage(view->control.hwnd, EM_SETEVENTMASK, (WPARAM)0, ENM_CHANGE);
    else
        SendMessage(view->control.hwnd, EM_SETEVENTMASK, (WPARAM)0, ENM_NONE);
}

/*---------------------------------------------------------------------------*/

void ostext_OnFocus(OSText *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->OnFocus, listener);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_text_num_chars(HWND hwnd)
{
    GETTEXTLENGTHEX textl;
    textl.flags = GTL_PRECISE | GTL_NUMCHARS;
    textl.codepage = 1200;
    return (uint32_t)SendMessage(hwnd, EM_GETTEXTLENGTHEX, (WPARAM)&textl, (LPARAM)0);
}

/*---------------------------------------------------------------------------*/

static void i_add_text(OSText *view, CHARRANGE *cr, const char_t *text)
{
    uint32_t num_bytes = 0;
    WCHAR *wtext_alloc = NULL;
    WCHAR wtext_static[WCHAR_BUFFER_SIZE];
    WCHAR *wtext;
    CHARFORMAT2 format;
    PARAFORMAT2 pformat;
    LRESULT res = 0;

    view->launch_event = FALSE;
    num_bytes = unicode_convers_nbytes(text, ekUTF8, kWINDOWS_UNICODE);
    if (num_bytes < sizeof(wtext_static))
    {
        wtext = wtext_static;
    }
    else
    {
        wtext_alloc = (WCHAR *)heap_malloc(num_bytes, "OSTextAddText");
        wtext = wtext_alloc;
    }

    {
        register uint32_t bytes = unicode_convers(text, (char_t *)wtext, ekUTF8, kWINDOWS_UNICODE, num_bytes);
        cassert_unref(bytes == num_bytes, bytes);
    }

    SendMessage(view->control.hwnd, EM_EXSETSEL, 0, (LPARAM)cr);

    format.cbSize = sizeof(CHARFORMAT2);
    format.dwMask = CFM_FACE | CFM_BOLD | CFM_ITALIC | CFM_UNDERLINE | CFM_STRIKEOUT | CFM_SUBSCRIPT | CFM_SIZE | CFM_COLOR | CFM_BACKCOLOR;
    format.dwEffects = view->dwEffects;
    format.yHeight = view->yHeight;

    if (view->crTextColor == 0)
        format.dwEffects |= CFE_AUTOCOLOR;
    else
        format.crTextColor = view->crTextColor;

    if (view->crBackColor == 0)
        format.dwEffects |= CFE_AUTOBACKCOLOR;
    else
        format.crBackColor = view->crBackColor;

    wcscpy_s(format.szFaceName, sizeof(format.szFaceName) / sizeof(WCHAR), view->szFaceName);
    res = SendMessage(view->control.hwnd, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&format);
    cassert_unref(res != 0, res);

    pformat.cbSize = sizeof(PARAFORMAT2);
    pformat.dwMask = PFM_ALIGNMENT | PFM_LINESPACING | PFM_SPACEAFTER | PFM_SPACEBEFORE;
    pformat.wAlignment = view->wAlignment;
    pformat.bLineSpacingRule = 5;
    pformat.dyLineSpacing = view->dyLineSpacing;
    pformat.dySpaceBefore = view->dySpaceBefore;
    pformat.dySpaceAfter = view->dySpaceAfter;
    res = SendMessage(view->control.hwnd, EM_SETPARAFORMAT, 0, (LPARAM)&pformat);
    cassert_unref(res != 0, res);

    SendMessage(view->control.hwnd, EM_REPLACESEL, 0, (LPARAM)wtext);

    if (wtext_alloc != NULL)
        heap_free((byte_t **)&wtext_alloc, num_bytes, "OSTextAddText");

    view->launch_event = TRUE;
}

/*---------------------------------------------------------------------------*/

void ostext_insert_text(OSText *view, const char_t *text)
{
    CHARRANGE cr;
    cr.cpMin = -1;
    cr.cpMax = -1;
    i_add_text(view, &cr, text);
    view->num_chars = i_text_num_chars(view->control.hwnd);
}

/*---------------------------------------------------------------------------*/

void ostext_set_text(OSText *view, const char_t *text)
{
    CHARRANGE cr;
    cr.cpMin = 0;
    cr.cpMax = -1;
    i_add_text(view, &cr, text);
    view->num_chars = i_text_num_chars(view->control.hwnd);
}

/*---------------------------------------------------------------------------*/

static DWORD CALLBACK i_set_rtf(DWORD_PTR dwCookie, LPBYTE lpBuff, LONG cb, PLONG pcb)
{
    Stream *stm = (Stream *)dwCookie;
    *pcb = stm_read(stm, (byte_t *)lpBuff, (uint32_t)cb);
    return 0;
}

/*---------------------------------------------------------------------------*/

void ostext_set_rtf(OSText *view, Stream *rtf_in)
{
    EDITSTREAM es = {0};
    cassert_no_null(view);
    es.pfnCallback = i_set_rtf;
    es.dwCookie = (DWORD_PTR)rtf_in;
    view->launch_event = FALSE;
    SendMessage(view->control.hwnd, EM_STREAMIN, SF_RTF, (LPARAM)&es);
    view->launch_event = TRUE;
}

/*---------------------------------------------------------------------------*/

void ostext_property(OSText *view, const gui_text_t prop, const void *value)
{
    cassert_no_null(view);
    cassert_no_null(value);
    switch (prop)
    {
    case ekGUI_TEXT_FAMILY:
        unicode_convers((const char_t *)value, (char_t *)view->szFaceName, ekUTF8, ekUTF16, sizeof(view->szFaceName));
        break;

    case ekGUI_TEXT_UNITS:
        view->units = *((const uint32_t *)value);
        break;

    case ekGUI_TEXT_SIZE:
    {
        real32_t size = *((real32_t *)value);
        if (view->units & ekFPOINTS)
            size = size * (real32_t)kLOG_PIXY_GUI / 72.f;
        view->yHeight = (LONG)(size * kTWIPS_PER_PIXEL_GUI);
        break;
    }

    case ekGUI_TEXT_STYLE:
    {
        uint32_t style = *((uint32_t *)value);
        view->dwEffects = 0;
        if (style & ekFBOLD)
            view->dwEffects |= CFE_BOLD;

        if (style & ekFITALIC)
            view->dwEffects |= CFE_ITALIC;

        if (style & ekFSTRIKEOUT)
            view->dwEffects |= CFE_STRIKEOUT;

        if (style & ekFUNDERLINE)
            view->dwEffects |= CFE_UNDERLINE;

        if (style & ekFSUBSCRIPT)
            view->dwEffects |= CFE_SUBSCRIPT;

        if (style & ekFSUPSCRIPT)
            view->dwEffects |= CFE_SUPERSCRIPT;

        break;
    }

    case ekGUI_TEXT_COLOR:
        if (*((color_t *)value) == kCOLOR_TRANSPARENT)
            view->crTextColor = 0;
        else
            view->crTextColor = _oscontrol_colorref(*((color_t *)value));
        break;

    case ekGUI_TEXT_BGCOLOR:
        if (*((color_t *)value) == kCOLOR_TRANSPARENT)
            view->crBackColor = 0;
        else
            view->crBackColor = _oscontrol_colorref(*((color_t *)value));
        break;

    case ekGUI_TEXT_PGCOLOR:
        if (*((color_t *)value) == kCOLOR_TRANSPARENT)
            SendMessage(view->control.hwnd, EM_SETBKGNDCOLOR, 1, (LPARAM)0);
        else
            SendMessage(view->control.hwnd, EM_SETBKGNDCOLOR, 0, (LPARAM)_oscontrol_colorref(*((color_t *)value)));
        break;

    case ekGUI_TEXT_PARALIGN:
        switch (*((align_t *)value))
        {
        case ekLEFT:
        case ekJUSTIFY:
            view->wAlignment = PFA_LEFT;
            break;
        case ekCENTER:
            view->wAlignment = PFA_CENTER;
            break;
        case ekRIGHT:
            view->wAlignment = PFA_RIGHT;
            break;
        }
        break;

    case ekGUI_TEXT_LSPACING:
        view->dyLineSpacing = (LONG)(20 * *((real32_t *)value));
        break;

    case ekGUI_TEXT_AFPARSPACE:
        view->dySpaceAfter = (LONG)(20 /*kTWIPS_PER_PIXEL*/ * *((real32_t *)value) /** (real32_t)kLOG_PIXY / 72.f*/);
        break;

    case ekGUI_TEXT_BFPARSPACE:
        view->dySpaceBefore = (LONG)(20 /*kTWIPS_PER_PIXEL*/ * *((real32_t *)value) /** (real32_t)kLOG_PIXY / 72.f*/);
        break;

    case ekGUI_TEXT_SELECT:
    {
        int32_t *range = (int32_t *)value;
        int32_t platform_st, platform_ed;
        osgui_select_text(range[0], range[1], &platform_st, &platform_ed);

        {
            HWND focus = GetFocus();
            bool_t prev = view->launch_event;
            view->launch_event = FALSE;
            SetFocus(view->control.hwnd);
            SendMessage(view->control.hwnd, EM_SETSEL, (WPARAM)platform_st, (LPARAM)platform_ed);
            SetFocus(focus);
            view->launch_event = prev;
        }

        break;
    }

    case ekGUI_TEXT_SCROLL:
    {
        HWND focus = GetFocus();
        bool_t prev = view->launch_event;
        view->launch_event = FALSE;
        SetFocus(view->control.hwnd);
        SendMessage(view->control.hwnd, EM_SCROLLCARET, 0, 0);
        SetFocus(focus);
        view->launch_event = prev;
        break;
    }

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void ostext_editable(OSText *view, const bool_t is_editable)
{
    cassert_no_null(view);
    view->is_editable = is_editable;
    i_set_editable(view->control.hwnd, (BOOL)is_editable);
}

/*---------------------------------------------------------------------------*/

static char_t *i_get_text(HWND hwnd, uint32_t *size, uint32_t *nchars)
{
    uint32_t num_chars = 0;
    WCHAR *wtext_alloc = NULL;
    WCHAR wtext_static[WCHAR_BUFFER_SIZE];
    WCHAR *wtext = NULL;
    char_t *text = NULL;

    cassert_no_null(size);

    {
        GETTEXTLENGTHEX textl;
        textl.flags = GTL_DEFAULT;
        textl.codepage = 1200;
        num_chars = 1 + (uint32_t)SendMessage(hwnd, EM_GETTEXTLENGTHEX, (WPARAM)&textl, (LPARAM)0);
        if (nchars != NULL)
            *nchars = num_chars - 1;
    }

    if (num_chars < WCHAR_BUFFER_SIZE)
    {
        wtext = wtext_static;
    }
    else
    {
        wtext_alloc = (WCHAR *)heap_malloc(num_chars * sizeof(WCHAR), "OSTextGetText");
        wtext = wtext_alloc;
    }

    {
        GETTEXTEX gtext;
        uint32_t num_charsw;
        gtext.cb = num_chars * sizeof(WCHAR);
        gtext.flags = GT_DEFAULT;
        gtext.codepage = 1200;
        gtext.lpDefaultChar = NULL;
        gtext.lpUsedDefChar = NULL;
        /* EM_GETTEXTEX: The return value is the number of TCHARs copied into the output buffer, including the null terminator. */
        num_charsw = (uint32_t)SendMessage(hwnd, EM_GETTEXTEX, (WPARAM)&gtext, (LPARAM)wtext);
        cassert(num_chars == num_charsw + 1);
    }

    *size = unicode_convers_nbytes((const char_t *)wtext, kWINDOWS_UNICODE, ekUTF8);
    text = (char_t *)heap_malloc(*size, "OSTextText");

    {
        register uint32_t bytes = unicode_convers((const char_t *)wtext, text, kWINDOWS_UNICODE, ekUTF8, *size);
        cassert_unref(bytes == *size, bytes);
    }

    if (wtext_alloc != NULL)
        heap_free((byte_t **)&wtext_alloc, num_chars * sizeof(WCHAR), "OSTextGetText");

    return text;
}

/*---------------------------------------------------------------------------*/

static char_t *i_get_seltext(HWND hwnd, const CHARRANGE *cr, uint32_t *size)
{
    uint32_t num_chars = 0;
    WCHAR *wtext_alloc = NULL;
    WCHAR wtext_static[WCHAR_BUFFER_SIZE];
    WCHAR *wtext = NULL;
    char_t *text = NULL;

    cassert_no_null(cr);
    cassert_no_null(size);
    num_chars = cr->cpMax - cr->cpMin;

    if (num_chars < WCHAR_BUFFER_SIZE)
    {
        wtext = wtext_static;
    }
    else
    {
        wtext_alloc = (WCHAR *)heap_malloc(num_chars * sizeof(WCHAR), "OSTextGetText");
        wtext = wtext_alloc;
    }

    {
        GETTEXTEX gtext;
        uint32_t num_charsw;
        gtext.cb = num_chars * sizeof(WCHAR);
        gtext.flags = GT_DEFAULT;
        gtext.codepage = 1200;
        gtext.lpDefaultChar = NULL;
        gtext.lpUsedDefChar = NULL;
        /* EM_GETSELTEXT: The return value is the number of TCHARs copied into the output buffer, NOT including the null terminator. */
        num_charsw = (uint32_t)SendMessage(hwnd, EM_GETSELTEXT, (WPARAM)0, (LPARAM)wtext);
        cassert(num_chars == num_charsw);
    }

    *size = unicode_convers_nbytes((const char_t *)wtext, kWINDOWS_UNICODE, ekUTF8);
    text = (char_t *)heap_malloc(*size, "OSTextSelText");

    {
        register uint32_t bytes = unicode_convers((const char_t *)wtext, text, kWINDOWS_UNICODE, ekUTF8, *size);
        cassert_unref(bytes == *size, bytes);
    }

    if (wtext_alloc != NULL)
        heap_free((byte_t **)&wtext_alloc, num_chars * sizeof(WCHAR), "OSTextGetText");

    return text;
}

/*---------------------------------------------------------------------------*/

const char_t *ostext_get_text(const OSText *view)
{
    cassert_no_null(view);
    if (view->text != NULL)
        heap_free((byte_t **)&view->text, view->text_size, "OSTextText");
    ((OSText *)view)->text = i_get_text(view->control.hwnd, &((OSText *)view)->text_size, NULL);
    return view->text;
}

/*---------------------------------------------------------------------------*/

void ostext_scroller_visible(OSText *view, const bool_t horizontal, const bool_t vertical)
{
    cassert_no_null(view);
    unref(horizontal);
    SendMessage(view->control.hwnd, EM_SHOWSCROLLBAR, (WPARAM)SB_HORZ, (LPARAM)FALSE);
    SendMessage(view->control.hwnd, EM_SHOWSCROLLBAR, (WPARAM)SB_VERT, (LPARAM)vertical);
}

/*---------------------------------------------------------------------------*/

void ostext_set_need_display(OSText *view)
{
    unref(view);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void ostext_clipboard(OSText *view, const clipboard_t clipboard)
{
    cassert_no_null(view);
    switch (clipboard)
    {
    case ekCLIPBOARD_COPY:
        SendMessage(view->control.hwnd, WM_COPY, (WPARAM)0, (LPARAM)0);
        break;
    case ekCLIPBOARD_PASTE:
        SendMessage(view->control.hwnd, WM_PASTE, (WPARAM)0, (LPARAM)0);
        break;
    case ekCLIPBOARD_CUT:
        SendMessage(view->control.hwnd, WM_CUT, (WPARAM)0, (LPARAM)0);
        break;
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void ostext_attach(OSText *view, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)view);
}

/*---------------------------------------------------------------------------*/

void ostext_detach(OSText *view, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)view);
}

/*---------------------------------------------------------------------------*/

void ostext_visible(OSText *view, const bool_t visible)
{
    _oscontrol_set_visible((OSControl *)view, visible);
}

/*---------------------------------------------------------------------------*/

void ostext_enabled(OSText *view, const bool_t enabled)
{
    _oscontrol_set_enabled((OSControl *)view, enabled);
}

/*---------------------------------------------------------------------------*/

void ostext_size(const OSText *view, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)view, width, height);
}

/*---------------------------------------------------------------------------*/

void ostext_origin(const OSText *view, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)view, x, y);
}

/*---------------------------------------------------------------------------*/

void ostext_frame(OSText *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)view, x, y, width, height);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get_cursor_pos(HWND hwnd)
{
    DWORD start;
    SendMessage(hwnd, EM_GETSEL, (WPARAM)&start, (LPARAM)NULL);
    return (uint32_t)start;
}

/*---------------------------------------------------------------------------*/

static void i_set_cursor_pos(HWND hwnd, const uint32_t pos)
{
    SendMessage(hwnd, EM_SETSEL, (WPARAM)pos, (LPARAM)pos);
}

/*---------------------------------------------------------------------------*/

static void i_replace_text(OSText *view, const char_t *text)
{
    uint32_t num_bytes = 0;
    WCHAR *wtext_alloc = NULL;
    WCHAR wtext_static[WCHAR_BUFFER_SIZE];
    WCHAR *wtext;

    cassert_no_null(view);

    view->launch_event = FALSE;
    num_bytes = unicode_convers_nbytes(text, ekUTF8, kWINDOWS_UNICODE);
    if (num_bytes < sizeof(wtext_static))
    {
        wtext = wtext_static;
    }
    else
    {
        wtext_alloc = (WCHAR *)heap_malloc(num_bytes, "OSTextReplaceText");
        wtext = wtext_alloc;
    }

    {
        register uint32_t bytes = unicode_convers(text, (char_t *)wtext, ekUTF8, kWINDOWS_UNICODE, num_bytes);
        cassert_unref(bytes == num_bytes, bytes);
    }

    SendMessage(view->control.hwnd, EM_REPLACESEL, 0, (LPARAM)wtext);

    if (wtext_alloc != NULL)
        heap_free((byte_t **)&wtext_alloc, num_bytes, "OSTextReplaceText");

    view->launch_event = TRUE;
}

/*---------------------------------------------------------------------------*/

void _ostext_command(OSText *view, WPARAM wParam)
{
    cassert_no_null(view);
    if (HIWORD(wParam) == EN_CHANGE)
    {
        if (view->launch_event == TRUE && IsWindowEnabled(view->control.hwnd) && view->OnFilter != NULL)
        {
            uint32_t num_chars = i_text_num_chars(view->control.hwnd);
            /* Event only if inserted text */
            if (num_chars > view->num_chars)
            {
                CHARRANGE cr;
                char_t *edit_text = NULL;
                uint32_t tsize;
                uint32_t inschars = num_chars - view->num_chars;
                EvText params;
                EvTextFilter result;
                cr.cpMax = (LONG)i_get_cursor_pos(view->control.hwnd);
                cr.cpMin = cr.cpMax - inschars;

                /* Select the inserted text */
                SendMessage(view->control.hwnd, EM_EXSETSEL, 0, (LPARAM)&cr);

                edit_text = i_get_seltext(view->control.hwnd, &cr, &tsize);
                params.text = (const char_t *)edit_text;
                params.cpos = (uint32_t)cr.cpMax;
                params.len = (int32_t)inschars;
                result.apply = FALSE;
                result.text[0] = '\0';
                result.cpos = UINT32_MAX;
                listener_event(view->OnFilter, ekGUI_EVENT_TXTFILTER, view, &params, &result, OSText, EvText, EvTextFilter);
                heap_free((byte_t **)&edit_text, tsize, "OSTextSelText");

                view->num_chars = num_chars;

                if (result.apply == TRUE)
                {
                    bool_t prev = view->launch_event;
                    uint32_t replnchars = unicode_nchars(result.text, ekUTF8);
                    view->launch_event = FALSE;
                    i_replace_text(view, result.text);
                    view->launch_event = prev;

                    if (replnchars > inschars)
                        view->num_chars += replnchars - inschars;
                    else
                        view->num_chars += inschars - replnchars;
                }
            }
            else
            {
                view->num_chars = num_chars;
            }
        }
    }
}

/*---------------------------------------------------------------------------*/

void ostext_focus(OSText *view, const bool_t focus)
{
    cassert_no_null(view);
    cassert(view->launch_event == TRUE);

    view->focused = focus;

    if (view->OnFocus != NULL)
    {
        bool_t params = focus;
        listener_event(view->OnFocus, ekGUI_EVENT_FOCUS, view, &params, NULL, OSText, bool_t, void);
    }

    RedrawWindow(view->control.hwnd, NULL, NULL, RDW_FRAME | RDW_INVALIDATE);
}
