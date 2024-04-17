/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscontrol.cpp
 *
 */

/* Windows controls commons */

#include "oscontrol.inl"
#include "oscontrol_win.inl"
#include "osgui.inl"
#include "osgui_win.inl"
#include "oscombo_win.inl"
#include "ospanel_win.inl"
#include "ospopup_win.inl"
#include "ostooltip.inl"
#include <draw2d/color.h>
#include <draw2d/font.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

#include <sewer/nowarn.hxx>
#include <math.h>
#include <sewer/warn.hxx>

static const unicode_t i_SYSTEM_FORMAT = ekUTF16;

typedef struct i_children_t i_Children;

struct i_children_t
{
    uint32_t num_children;
    HWND *children;
    uint32_t children_size;
};

/*---------------------------------------------------------------------------*/

static void i_init(OSControl *control, const DWORD dwExStyle, const DWORD dwStyle, const LPCWSTR lpClassName, int nWidth, int nHeight, WNDPROC wndProc, HWND parent_window)
{
    HINSTANCE instance;
    cassert_no_null(control);
    instance = _osgui_instance();
    cassert_no_null(instance);

    control->hwnd = CreateWindowEx(
        dwExStyle,
        lpClassName,
        PARAM(lpWindowName, NULL),
        dwStyle,
        PARAM(x, 0),
        PARAM(y, 0),
        nWidth, nHeight,
        PARAM(hWndParent, parent_window),
        (HMENU)NULL,
        instance,
        PARAM(lpParam, NULL));

    cassert_no_null(control->hwnd);
    control->tooltip_hwnd = NULL;

    if (wndProc != NULL)
        control->def_wnd_proc = (WNDPROC)SetWindowLongPtr(control->hwnd, GWLP_WNDPROC, (LONG_PTR)wndProc);
    else
        control->def_wnd_proc = NULL;

    {
        void *data = (void *)SetWindowLongPtr(control->hwnd, GWLP_USERDATA, (LONG_PTR)control);
        cassert_unref(data == NULL, data);
    }
}

/*---------------------------------------------------------------------------*/

void _oscontrol_init(OSControl *control, const DWORD dwExStyle, const DWORD dwStyle, const LPCWSTR lpClassName, int nWidth, int nHeight, WNDPROC wndProc, HWND parent_window)
{
    i_init(control, dwExStyle, dwStyle | WS_VISIBLE, lpClassName, nWidth, nHeight, wndProc, parent_window);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_init_hidden(OSControl *control, const DWORD dwExStyle, const DWORD dwStyle, const LPCWSTR lpClassName, int nWidth, int nHeight, WNDPROC wndProc, HWND parent_window)
{
    i_init(control, dwExStyle, dwStyle & ~WS_VISIBLE, lpClassName, nWidth, nHeight, wndProc, parent_window);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_destroy(OSControl *control)
{
    BOOL ret = 0;
    cassert_no_null(control);
    _ostooltip_destroy_optional(&control->tooltip_hwnd, control->hwnd);
    ret = DestroyWindow(control->hwnd);
    cassert_unref(ret != 0, ret);
}

/*---------------------------------------------------------------------------*/

char_t *_oscontrol_get_text(const OSControl *control, uint32_t *tsize)
{
    uint32_t num_chars = 0;
    WCHAR *wtext = NULL;
    WCHAR wtext_static[WCHAR_BUFFER_SIZE];
    WCHAR *wtext_alloc = NULL;
    char_t *control_text = NULL;
    cassert_no_null(control);
    cassert_no_null(tsize);
    /* WM_GETTEXTLENGTH: The return value is the length of the text in characters, not including the terminating null character. */
    num_chars = 1 + (uint32_t)SendMessage(control->hwnd, WM_GETTEXTLENGTH, (WPARAM)0, (LPARAM)0);
    if (num_chars < WCHAR_BUFFER_SIZE)
    {
        wtext = wtext_static;
    }
    else
    {
        wtext_alloc = (WCHAR *)heap_malloc(num_chars * sizeof(WCHAR), "OSControlGetTextBuf");
        wtext = wtext_alloc;
    }

    {
        uint32_t num_chars_copied = 0;
        /* WM_GETTEXT: The return value is the number of characters copied, not including the terminating null character.*/
        num_chars_copied = (uint32_t)SendMessage(control->hwnd, WM_GETTEXT, (WPARAM)num_chars, (LPARAM)wtext);
        cassert(num_chars == num_chars_copied + 1);
    }

    *tsize = unicode_convers_nbytes((const char_t *)wtext, kWINDOWS_UNICODE, ekUTF8);
    control_text = (char_t *)heap_malloc(*tsize, "OSControlGetText");

    {
        register uint32_t bytes = unicode_convers((const char_t *)wtext, control_text, kWINDOWS_UNICODE, ekUTF8, *tsize);
        cassert_unref(bytes == *tsize, bytes);
    }

    if (wtext_alloc != NULL)
        heap_free((byte_t **)&wtext_alloc, num_chars * sizeof(WCHAR), "OSControlGetTextBuf");

    return control_text;
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_text(OSControl *control, const char_t *text)
{
    uint32_t num_chars = 0;
    WCHAR *wtext = NULL;
    WCHAR wtext_static[WCHAR_BUFFER_SIZE];
    WCHAR *wtext_alloc = NULL;
    cassert_no_null(control);
    num_chars = 1 + unicode_nchars(text, ekUTF8);
    if (num_chars < WCHAR_BUFFER_SIZE)
    {
        wtext = wtext_static;
    }
    else
    {
        wtext_alloc = (WCHAR *)heap_malloc(num_chars * sizeof(WCHAR), "OSControlSetText");
        wtext = wtext_alloc;
    }

    {
        register uint32_t bytes = unicode_convers(text, (char_t *)wtext, ekUTF8, kWINDOWS_UNICODE, num_chars * sizeof(WCHAR));
        cassert_unref(bytes == num_chars * sizeof(WCHAR), bytes);
    }

    {
        BOOL ok = SetWindowText(control->hwnd, wtext);
        cassert_unref(ok != 0, ok);
    }

    if (wtext_alloc != NULL)
        heap_free((byte_t **)&wtext_alloc, num_chars * sizeof(WCHAR), "OSControlSetText");
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_tooltip(OSControl *control, const char_t *text)
{
    cassert_no_null(control);
    _ostooltip_set_text(&control->tooltip_hwnd, control->hwnd, text);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_font(OSControl *control, const Font *font)
{
    HFONT hfont = (HFONT)font_native(font);
    cassert_no_null(control);
    SendMessage(control->hwnd, WM_SETFONT, (WPARAM)hfont, (LPARAM)FALSE);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_update_font(OSControl *control, Font **current_font, const Font *font)
{
    HFONT hfont = (HFONT)font_native(font);
    cassert_no_null(control);
    cassert_no_null(current_font);
    if (font_equals(*current_font, font) == FALSE)
    {
        font_destroy(current_font);
        *current_font = font_copy(font);
    }
    SendMessage(control->hwnd, WM_SETFONT, (WPARAM)hfont, (LPARAM)FALSE);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_text_bounds(const OSControl *control, const char_t *text, const Font *font, const real32_t refwidth, real32_t *width, real32_t *height)
{
    StringSizeData data;
    HFONT current_font = NULL;
    int ret = 0;
    cassert_no_null(control);
    data.hdc = GetDC(control->hwnd);
    current_font = (HFONT)SelectObject(data.hdc, (HFONT)font_native(font));
    cassert_no_null(current_font);
    osgui_text_bounds(&data, text, refwidth, width, height);
    SelectObject(data.hdc, current_font);
    ret = ReleaseDC(NULL, data.hdc);
    cassert_unref(ret == 1, ret);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_visible(OSControl *control, const bool_t visible)
{
    cassert_no_null(control);
    ShowWindow(control->hwnd, (visible == TRUE) ? SW_SHOW : SW_HIDE);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_enabled(OSControl *control, const bool_t enabled)
{
    cassert_no_null(control);
    EnableWindow(control->hwnd, (BOOL)enabled);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_get_origin(const OSControl *control, real32_t *x, real32_t *y)
{
    cassert_no_null(control);
    cassert_no_null(x);
    cassert_no_null(y);
    *x = (real32_t)control->x;
    *y = (real32_t)control->y;
}

/*---------------------------------------------------------------------------*/

void _oscontrol_get_size(const OSControl *control, real32_t *width, real32_t *height)
{
    BOOL ret;
    RECT rect;
    cassert_no_null(control);
    cassert_no_null(width);
    cassert_no_null(height);
    ret = GetWindowRect(control->hwnd, &rect);
    cassert_unref(ret != 0, ret);
    *width = (real32_t)(rect.right - rect.left);
    *height = (real32_t)(rect.bottom - rect.top);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_position(OSControl *control, const int x, const int y)
{
    BOOL ret;
    cassert_no_null(control);
    ret = SetWindowPos(control->hwnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    cassert_unref(ret != 0, ret);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_frame(OSControl *control, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    BOOL ret = FALSE;
    OSControl *parent = NULL;
    int scroll_x = 0, scroll_y = 0;
    cassert_no_null(control);

    parent = (OSControl *)GetWindowLongPtr(GetParent(control->hwnd), GWLP_USERDATA);
    if (parent != NULL && parent->type == ekGUI_TYPE_PANEL)
        _ospanel_scroll_pos((OSPanel *)parent, &scroll_x, &scroll_y);

    ret = SetWindowPos(control->hwnd, NULL, (int)x - scroll_x, (int)y - scroll_y, (int)width, (int)height, SWP_NOZORDER);
    cassert_unref(ret != 0, ret);
    control->x = (int32_t)x;
    control->y = (int32_t)y;
}

/*---------------------------------------------------------------------------*/

void _oscontrol_attach_to_parent(OSControl *control, OSControl *parent_control)
{
    HWND ret;
    cassert_no_null(control);
    cassert_no_null(parent_control);
    ret = SetParent(control->hwnd, parent_control->hwnd);
    cassert_no_null(ret);
#if defined(__ASSERTS__)
    {
        HWND parent;
        parent = GetParent(control->hwnd);
        cassert_no_null(parent);
        cassert(parent == parent_control->hwnd);
    }
#endif
}

/*---------------------------------------------------------------------------*/

void _oscontrol_detach_from_parent(OSControl *control, OSControl *parent_control)
{
    HWND ret;
    cassert_no_null(control);
    cassert_no_null(parent_control);
    cassert(GetParent(control->hwnd) == parent_control->hwnd);
    ret = SetParent(control->hwnd, NULL);
    cassert(ret == parent_control->hwnd);
}

/*---------------------------------------------------------------------------*/

static BOOL CALLBACK i_children_count(HWND child_hwnd, LPARAM lParam)
{
    i_Children *children_str = (i_Children *)lParam;
    if (children_str->num_children < children_str->children_size)
        children_str->children[children_str->num_children] = child_hwnd;
    children_str->num_children += 1;
    return TRUE;
}

/*---------------------------------------------------------------------------*/

uint32_t _oscontrol_num_children(const OSControl *control)
{
    i_Children children_str;
    children_str.num_children = 0;
    children_str.children = NULL;
    children_str.children_size = 0;
    cassert_no_null(control);
    EnumChildWindows(control->hwnd, i_children_count, (LPARAM)&children_str);
    return children_str.num_children;
}

/*---------------------------------------------------------------------------*/

void _oscontrol_draw_focus(HWND hwnd, const INT left_offset, const INT right_offset, const INT top_offset, const INT bottom_offset)
{
    RECT rc;
    PAINTSTRUCT st;
    HDC hdc;
    GetClientRect(hwnd, &rc);
    rc.left += left_offset;
    rc.right -= right_offset;
    rc.top += top_offset;
    rc.bottom -= bottom_offset;
    InvalidateRect(hwnd, NULL, FALSE);
    hdc = BeginPaint(hwnd, &st);
    FrameRect(hdc, &rc, kCHESSBOARD_BRUSH);
    EndPaint(hwnd, &st);
}

/*---------------------------------------------------------------------------*/

DWORD _oscontrol_halign(const align_t halign)
{
    switch (halign)
    {
    case ekLEFT:
        return SS_LEFT;
    case ekCENTER:
    case ekJUSTIFY:
        return SS_CENTER;
    case ekRIGHT:
        return SS_RIGHT;
        cassert_default();
    }

    return UINT32_MAX;
}

/*---------------------------------------------------------------------------*/

DWORD _oscontrol_ellipsis(const ellipsis_t ellipsis)
{
    switch (ellipsis)
    {
    case ekELLIPNONE:
    case ekELLIPMLINE:
        return 0;
    case ekELLIPBEGIN:
        return SS_ENDELLIPSIS;
    case ekELLIPEND:
        return SS_ENDELLIPSIS;
    case ekELLIPMIDDLE:
        return SS_PATHELLIPSIS;
    }

    return 0;
}

/*---------------------------------------------------------------------------*/

COLORREF _oscontrol_colorref(const color_t color)
{
    uint8_t r, g, b;
    color_get_rgb(color, &r, &g, &b);
    return RGB(r, g, b);
}

/*---------------------------------------------------------------------------*/

color_t _oscontrol_from_colorref(const COLORREF color)
{
    return color_rgb(GetRValue(color), GetGValue(color), GetBValue(color));
}

/*---------------------------------------------------------------------------*/

void _oscontrol_update_brush(const color_t color, HBRUSH *brush, COLORREF *colorref)
{
    register COLORREF cf;
    cassert_no_null(brush);
    if (*brush != NULL)
    {
        BOOL ok = DeleteObject(*brush);
        cassert_unref(ok != 0, ok);
        *brush = NULL;
    }

    cf = _oscontrol_colorref(color);
    ptr_assign(colorref, cf);
    if (color != kCOLOR_TRANSPARENT)
        *brush = CreateSolidBrush(cf);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_destroy_brush(HBRUSH *brush)
{
    cassert_no_null(brush);
    if (*brush != NULL)
    {
        BOOL ok = DeleteObject(*brush);
        cassert_unref(ok != 0, ok);
        *brush = NULL;
    }
}

/*---------------------------------------------------------------------------*/

gui_type_t oscontrol_type(const OSControl *control)
{
    cassert_no_null(control);
    return control->type;
}

/*---------------------------------------------------------------------------*/

OSControl *oscontrol_parent(const OSControl *control)
{
    HWND parentHWND = NULL;
    OSControl *parent = NULL;
    cassert_no_null(control);
    parentHWND = GetParent(control->hwnd);
    parent = (OSControl *)GetWindowLongPtr(parentHWND, GWLP_USERDATA);
    return parent;
}

/*---------------------------------------------------------------------------*/

void oscontrol_frame(const OSControl *control, OSFrame *rect)
{
    real32_t width, height;
    cassert_no_null(control);
    cassert_no_null(rect);
    _oscontrol_get_size(control, &width, &height);
    rect->left = control->x;
    rect->top = control->y;
    rect->right = rect->left + (int32_t)width;
    rect->bottom = rect->top + (int32_t)height;
}

/*---------------------------------------------------------------------------*/

OSWidget *oscontrol_focus_widget(const OSControl *control)
{
    cassert_no_null(control);
    switch (control->type)
    {
    case ekGUI_TYPE_LABEL:
    case ekGUI_TYPE_PROGRESS:
        return NULL;

    case ekGUI_TYPE_BUTTON:
    case ekGUI_TYPE_EDITBOX:
    case ekGUI_TYPE_SLIDER:
    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_CUSTOMVIEW:
        return (OSWidget *)control->hwnd;

    case ekGUI_TYPE_POPUP:
        return (OSWidget *)_ospopup_focus_widget((OSPopUp *)control);

    case ekGUI_TYPE_COMBOBOX:
        return (OSWidget *)_oscombo_focus_widget((OSCombo *)control);

    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

bool_t oscontrol_widget_visible(const OSWidget *widget)
{
    cassert_no_null(widget);
    return (bool_t)IsWindowVisible((HWND)widget);
}

/*---------------------------------------------------------------------------*/

bool_t oscontrol_widget_enable(const OSWidget *widget)
{
    cassert_no_null(widget);
    return (bool_t)IsWindowEnabled((HWND)widget);
}
