/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslabel.c
 *
 */

/* Operating System label */

#include "oslabel.h"
#include "oslabel_win.inl"
#include "osgui.inl"
#include "osgui_win.inl"
#include "oscontrol_win.inl"
#include "ospanel_win.inl"
#include <draw2d/font.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

struct _oslabel_t
{
    OSControl control;
    Font *font;
    bool_t mouse_inside;
    uint8_t align;
    uint8_t ellipsis;
    COLORREF color;
    COLORREF bgcolor;
    HBRUSH bgbrush;
    Listener *OnClick;
    Listener *OnMouseEnter;
    Listener *OnMouseExit;
};

/*---------------------------------------------------------------------------*/

static DWORD i_style(const align_t align, const ellipsis_t ellipsis)
{
    DWORD oshalign = _oscontrol_halign(align);
    DWORD osellipsis = _oscontrol_ellipsis(ellipsis);
    return WS_CHILD | WS_CLIPSIBLINGS | oshalign | osellipsis;
}

/*---------------------------------------------------------------------------*/

static bool_t i_is_mouse_sensible(const OSLabel *label)
{
    cassert_no_null(label);
    if (label->OnClick != NULL)
        return TRUE;
    if (label->OnMouseEnter != NULL)
        return TRUE;
    if (label->OnMouseExit != NULL)
        return TRUE;
    return FALSE;
}

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSLabel *label = (OSLabel *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(label);

    switch (uMsg)
    {
    case WM_NCHITTEST:
        if (i_is_mouse_sensible(label) == TRUE)
            return HTCLIENT;
        else
            return HTTRANSPARENT;

    case WM_LBUTTONUP:
        if (label->OnClick != NULL)
        {
            EvText params;
            params.text = NULL;
            listener_event(label->OnClick, ekGUI_EVENT_LABEL, label, &params, NULL, OSLabel, EvText, void);
            return 0;
        }
        break;

    case WM_MOUSELEAVE:
        cassert(label->mouse_inside == TRUE);
        label->mouse_inside = FALSE;
        if (label->OnMouseExit != NULL)
            listener_event(label->OnMouseExit, ekGUI_EVENT_EXIT, label, NULL, NULL, OSLabel, void, void);

        return 0;

    case WM_MOUSEMOVE:

        if (label->mouse_inside == FALSE)
        {
            TRACKMOUSEEVENT track;
            BOOL ok;
            label->mouse_inside = TRUE;
            track.cbSize = sizeof(TRACKMOUSEEVENT);
            track.dwFlags = /*TME_HOVER | */ TME_LEAVE;
            track.hwndTrack = label->control.hwnd;
            track.dwHoverTime = HOVER_DEFAULT;
            ok = TrackMouseEvent(&track);
            cassert_unref(ok == TRUE, ok);

            if (label->OnMouseEnter != NULL)
            {
                POINTS point = MAKEPOINTS(lParam);
                EvMouse params;
                params.x = (real32_t)point.x;
                params.y = (real32_t)point.y;
                params.lx = params.x;
                params.ly = params.y;
                params.button = ENUM_MAX(gui_mouse_t);
                params.count = 0;
                params.modifiers = 0;
                params.tag = 0;
                listener_event(label->OnMouseEnter, ekGUI_EVENT_ENTER, label, &params, NULL, OSLabel, EvMouse, void);
            }
        }
        return 0;
    }

    return CallWindowProc(label->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

OSLabel *oslabel_create(const uint32_t flags)
{
    OSLabel *label = NULL;
    DWORD dwStyle = 0;
    unref(flags);
    dwStyle = i_style(ekLEFT, ekELLIPNONE);
    label = heap_new0(OSLabel);
    label->control.type = ekGUI_TYPE_LABEL;
    label->font = osgui_create_default_font();
    label->mouse_inside = FALSE;
    label->align = ekLEFT;
    label->ellipsis = ekELLIPNONE;
    label->color = 0;
    _oscontrol_init((OSControl *)label, PARAM(dwExStyle, WS_EX_NOPARENTNOTIFY), dwStyle, L"static", 0, 0, i_WndProc, kDEFAULT_PARENT_WINDOW);
    _oscontrol_set_font((OSControl *)label, label->font);
    return label;
}

/*---------------------------------------------------------------------------*/

void oslabel_destroy(OSLabel **label)
{
    cassert_no_null(label);
    cassert_no_null(*label);
    font_destroy(&(*label)->font);
    listener_destroy(&(*label)->OnClick);
    listener_destroy(&(*label)->OnMouseEnter);
    listener_destroy(&(*label)->OnMouseExit);
    _oscontrol_destroy_brush(&(*label)->bgbrush);
    _oscontrol_destroy(&(*label)->control);
    heap_delete(label, OSLabel);
}

/*---------------------------------------------------------------------------*/

void oslabel_OnClick(OSLabel *label, Listener *listener)
{
    cassert_no_null(label);
    listener_update(&label->OnClick, listener);
    label->mouse_inside = FALSE;
}

/*---------------------------------------------------------------------------*/

void oslabel_OnEnter(OSLabel *label, Listener *listener)
{
    cassert_no_null(label);
    listener_update(&label->OnMouseEnter, listener);
    label->mouse_inside = FALSE;
}

/*---------------------------------------------------------------------------*/

void oslabel_OnExit(OSLabel *label, Listener *listener)
{
    cassert_no_null(label);
    listener_update(&label->OnMouseExit, listener);
    label->mouse_inside = FALSE;
}

/*---------------------------------------------------------------------------*/

void oslabel_text(OSLabel *label, const char_t *text)
{
    cassert_no_null(label);
    _oscontrol_set_text((OSControl *)label, text);
    InvalidateRect(label->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

void oslabel_font(OSLabel *label, const Font *font)
{
    cassert_no_null(label);
    _oscontrol_update_font((OSControl *)label, &label->font, font);
    InvalidateRect(label->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

void oslabel_align(OSLabel *label, const align_t align)
{
    DWORD dwStyle = 0;
    cassert_no_null(label);
    dwStyle = i_style(align, label->ellipsis);
    label->align = align;
    SetWindowLongPtr(label->control.hwnd, GWL_STYLE, dwStyle);
}

/*---------------------------------------------------------------------------*/

void oslabel_ellipsis(OSLabel *label, const ellipsis_t ellipsis)
{
    DWORD dwStyle = 0;
    cassert_no_null(label);
    dwStyle = i_style(label->align, ellipsis);
    label->ellipsis = ellipsis;
    SetWindowLongPtr(label->control.hwnd, GWL_STYLE, dwStyle);
}

/*---------------------------------------------------------------------------*/

void oslabel_color(OSLabel *label, const color_t color)
{
    cassert_no_null(label);
    label->color = _oscontrol_colorref(color);
    InvalidateRect(label->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

void oslabel_bgcolor(OSLabel *label, const color_t color)
{
    cassert_no_null(label);
    _oscontrol_update_brush(color, &label->bgbrush, &label->bgcolor);
    InvalidateRect(label->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

void oslabel_bounds(const OSLabel *label, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    cassert_no_null(label);
    _oscontrol_text_bounds((OSControl *)label, text, label->font, refwidth, width, height);
}

/*---------------------------------------------------------------------------*/

void oslabel_attach(OSLabel *label, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_detach(OSLabel *label, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_visible(OSLabel *label, const bool_t visible)
{
    _oscontrol_set_visible((OSControl *)label, visible);
}

/*---------------------------------------------------------------------------*/

void oslabel_enabled(OSLabel *label, const bool_t enabled)
{
    _oscontrol_set_enabled((OSControl *)label, enabled);
}

/*---------------------------------------------------------------------------*/

void oslabel_size(const OSLabel *label, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)label, width, height);
}

/*---------------------------------------------------------------------------*/

void oslabel_origin(const OSLabel *label, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)label, x, y);
}

/*---------------------------------------------------------------------------*/

void oslabel_frame(OSLabel *label, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    cassert_no_null(label);
    _oscontrol_set_frame((OSControl *)label, x, y, width, height);
    InvalidateRect(label->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

COLORREF _oslabel_color(const OSLabel *label)
{
    cassert_no_null(label);
    return label->color;
}

/*---------------------------------------------------------------------------*/

HBRUSH _oslabel_background_color(const OSLabel *label, COLORREF *color)
{
    cassert_no_null(label);
    cassert_no_null(color);
    if (label->bgbrush != NULL)
    {
        *color = label->bgcolor;
        return label->bgbrush;
    }
    return NULL;
}
