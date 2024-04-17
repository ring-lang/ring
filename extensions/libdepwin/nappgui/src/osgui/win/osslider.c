/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osslider.c
 *
 */

/* Operating System native slider */

#include "osslider.h"
#include "osslider_win.inl"
#include "osgui_win.inl"
#include "oscontrol_win.inl"
#include "ospanel_win.inl"
#include "oswindow_win.inl"
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

/* Avoid Microsoft Warnings */
#pragma warning(push, 0)
#include <Commctrl.h>
#pragma warning(pop)

struct _osslider_t
{
    OSControl control;
    uint32_t flags;
    Listener *OnMoved;
};

/*---------------------------------------------------------------------------*/

#define i_SLIDER_MAX 2048

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSSlider *slider = (OSSlider *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(slider);

    switch (uMsg)
    {
    case WM_ERASEBKGND:
        return 1;

    case WM_LBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
        if (_oswindow_mouse_down(OSControlPtr(slider)) == TRUE)
            break;
        return 0;

    case WM_PAINT:
        if (_oswindow_in_resizing(hwnd) == TRUE)
            return 0;
        break;
    }

    return CallWindowProc(slider->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

static DWORD i_slider_style(const uint32_t flags)
{
    DWORD dwStyle = WS_CHILD | WS_CLIPSIBLINGS | TBS_NOTICKS;

#if _MSC_VER > 1400
    dwStyle |= TBS_TRANSPARENTBKGND;
#endif

    if (slider_get_type(flags) == ekSLIDER_HORZ)
        dwStyle |= TBS_HORZ;
    else
        dwStyle |= TBS_VERT;

    return dwStyle;
}

/*---------------------------------------------------------------------------*/

OSSlider *osslider_create(const uint32_t flags)
{
    OSSlider *slider = NULL;
    DWORD dwStyle = 0;
    slider = heap_new(OSSlider);
    slider->control.type = ekGUI_TYPE_SLIDER;
    slider->flags = flags;
    slider->OnMoved = NULL;
    dwStyle = i_slider_style(flags);
    _oscontrol_init((OSControl *)slider, PARAM(dwExStyle, WS_EX_NOPARENTNOTIFY), dwStyle, TRACKBAR_CLASS, 0, 0, i_WndProc, kDEFAULT_PARENT_WINDOW);
    SendMessage(slider->control.hwnd, TBM_SETRANGE, (WPARAM)TRUE, (LPARAM)MAKELONG(0, i_SLIDER_MAX));
    SendMessage(slider->control.hwnd, TBM_SETPAGESIZE, (WPARAM)0, (LPARAM)(i_SLIDER_MAX / 10));
    SendMessage(slider->control.hwnd, TBM_SETPOS, (WPARAM)TRUE, (LPARAM)0);
    return slider;
}

/*---------------------------------------------------------------------------*/

void osslider_destroy(OSSlider **slider)
{
    cassert_no_null(slider);
    cassert_no_null(*slider);
    listener_destroy(&(*slider)->OnMoved);
    _oscontrol_destroy((OSControl *)*slider);
    heap_delete(slider, OSSlider);
}

/*---------------------------------------------------------------------------*/

void osslider_OnMoved(OSSlider *slider, Listener *listener)
{
    cassert_no_null(slider);
    listener_update(&slider->OnMoved, listener);
}

/*---------------------------------------------------------------------------*/

void osslider_tooltip(OSSlider *slider, const char_t *text)
{
    _oscontrol_set_tooltip((OSControl *)slider, text);
}

/*---------------------------------------------------------------------------*/

void osslider_tickmarks(OSSlider *slider, const uint32_t num_tickmarks, const bool_t tickmarks_at_left_top)
{
    LPARAM psize = (LPARAM)(i_SLIDER_MAX / 10);
    cassert_no_null(slider);
    cassert(num_tickmarks > 1);
    if (num_tickmarks != UINT32_MAX)
        psize = (LPARAM)(i_SLIDER_MAX / (num_tickmarks - 1));

    SendMessage(slider->control.hwnd, TBM_SETPAGESIZE, (WPARAM)0, psize);
    unref(tickmarks_at_left_top);
}

/*---------------------------------------------------------------------------*/

static real32_t i_get_pos(HWND hwnd)
{
    LRESULT pos = SendMessage(hwnd, TBM_GETPOS, (WPARAM)0, (LPARAM)0);
    cassert(pos >= 0 && pos <= i_SLIDER_MAX);
    return (real32_t)pos / (real32_t)i_SLIDER_MAX;
}

/*---------------------------------------------------------------------------*/

void osslider_position(OSSlider *slider, const real32_t position)
{
    int pos = (int)(position * i_SLIDER_MAX);
    cassert_no_null(slider);
    cassert(position >= 0.f && position <= 1.f);
    SendMessage(slider->control.hwnd, TBM_SETPOS, (WPARAM)TRUE, (LPARAM)pos);
}

/*---------------------------------------------------------------------------*/

real32_t osslider_get_position(const OSSlider *slider)
{
    cassert_no_null(slider);
    return i_get_pos(slider->control.hwnd);
}

/*---------------------------------------------------------------------------*/

static real32_t i_thickness(const gui_size_t knob_size)
{
    switch (knob_size)
    {
    case ekGUI_SIZE_MINI:
        return 15.f;
    case ekGUI_SIZE_SMALL:
        return 20.f;
    case ekGUI_SIZE_REGULAR:
        return 20.f;
        cassert_default();
    }

    return 0.f;
}

/*---------------------------------------------------------------------------*/

void osslider_bounds(const OSSlider *slider, const real32_t length, const gui_size_t knob_size, real32_t *width, real32_t *height)
{
    cassert_no_null(slider);
    cassert_no_null(width);
    cassert_no_null(height);
    if (slider_get_type(slider->flags) == ekSLIDER_HORZ)
    {
        *width = length;
        *height = i_thickness(knob_size);
    }
    else
    {
        *width = i_thickness(knob_size);
        *height = length;
    }
}

/*---------------------------------------------------------------------------*/

void osslider_attach(OSSlider *slider, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)slider);
}

/*---------------------------------------------------------------------------*/

void osslider_detach(OSSlider *slider, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)slider);
}

/*---------------------------------------------------------------------------*/

void osslider_visible(OSSlider *slider, const bool_t visible)
{
    _oscontrol_set_visible((OSControl *)slider, visible);
}

/*---------------------------------------------------------------------------*/

void osslider_enabled(OSSlider *slider, const bool_t enabled)
{
    _oscontrol_set_enabled((OSControl *)slider, enabled);
}

/*---------------------------------------------------------------------------*/

void osslider_size(const OSSlider *slider, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)slider, width, height);
}

/*---------------------------------------------------------------------------*/

void osslider_origin(const OSSlider *slider, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)slider, x, y);
}

/*---------------------------------------------------------------------------*/

void osslider_frame(OSSlider *slider, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    cassert_no_null(slider);
    _oscontrol_set_frame((OSControl *)slider, x, y, width, height);
    InvalidateRect(slider->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

void _osslider_message(OSSlider *slider, WPARAM wParam)
{
    cassert_no_null(slider);
    if (LOWORD(wParam) != SB_ENDSCROLL)
    {
        if (IsWindowEnabled(slider->control.hwnd) && slider->OnMoved != NULL)
        {
            EvSlider params;
            params.pos = i_get_pos(slider->control.hwnd);
            params.incr = 0;
            params.step = UINT32_MAX;
            listener_event(slider->OnMoved, ekGUI_EVENT_SLIDER, slider, &params, NULL, OSSlider, EvSlider, void);
        }
    }
}
