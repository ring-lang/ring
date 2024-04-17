/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osprogress.c
 *
 */

/* Operating System native progress indicator */

#include "osprogress.h"
#include "osgui_win.inl"
#include "oscontrol_win.inl"
#include "ospanel_win.inl"
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

/* Avoid Microsoft Warnings */
#pragma warning(push, 0)
#include <Commctrl.h>
#pragma warning(pop)

struct _osprogress_t
{
    OSControl control;
    real32_t last_position;
};

static const uint16_t i_MAX_RANGE = 32768;

/*---------------------------------------------------------------------------*/

OSProgress *osprogress_create(const uint32_t flags)
{
    OSProgress *progress = NULL;
    DWORD dwStyle = WS_CHILD | WS_CLIPSIBLINGS;
    cassert_unref(progress_get_type(flags) == ekPROGRESS_HORZ, flags);
    progress = heap_new(OSProgress);
    progress->control.type = ekGUI_TYPE_PROGRESS;
    progress->last_position = 0.f;
    _oscontrol_init((OSControl *)progress, PARAM(dwExStyle, 0), dwStyle, PROGRESS_CLASS, 0, 0, NULL, kDEFAULT_PARENT_WINDOW);
    SendMessage(progress->control.hwnd, PBM_SETRANGE, (WPARAM)0, (LPARAM)MAKELONG(0, i_MAX_RANGE));
    return progress;
}

/*---------------------------------------------------------------------------*/

void osprogress_destroy(OSProgress **progress)
{
    cassert_no_null(progress);
    cassert_no_null(*progress);
    _oscontrol_destroy(&(*progress)->control);
    heap_delete(progress, OSProgress);
}

/*---------------------------------------------------------------------------*/

void osprogress_position(OSProgress *progress, const real32_t position)
{
    DWORD dwStyle = 0;
    cassert_no_null(progress);
    dwStyle = GetWindowLong(progress->control.hwnd, GWL_STYLE);

    /* Indeterminate progress */
    if (position < 0.f)
    {
        BOOL current_running = progress->last_position < -1.f;
        BOOL running = FALSE;
        if ((dwStyle & PBS_MARQUEE) != PBS_MARQUEE)
        {
            dwStyle |= PBS_MARQUEE;
            SetWindowLong(progress->control.hwnd, GWL_STYLE, dwStyle);
        }

        if (position < -1.f)
            running = TRUE;

        if (running != current_running)
            SendMessage(progress->control.hwnd, PBM_SETMARQUEE, (WPARAM)running, (LPARAM)0);
    }
    /* Determinte progress */
    else
    {
        DWORD pos = 0;
        cassert(position <= 1.f);
        if ((dwStyle & PBS_MARQUEE) == PBS_MARQUEE)
        {
            dwStyle &= ~PBS_MARQUEE;
            SetWindowLong(progress->control.hwnd, GWL_STYLE, dwStyle);
        }

        pos = (DWORD)(position * (real32_t)i_MAX_RANGE);
        SendMessage(progress->control.hwnd, PBM_SETPOS, (WPARAM)pos, (LPARAM)0);
    }

    progress->last_position = position;
}

/*---------------------------------------------------------------------------*/

real32_t osprogress_thickness(const OSProgress *progress, const gui_size_t size)
{
    unref(progress);
    switch (size)
    {
    case ekGUI_SIZE_REGULAR:
    case ekGUI_SIZE_SMALL:
        return 15.f;
    case ekGUI_SIZE_MINI:
        return 10.f;
        cassert_default();
    }

    return 0.f;
}

/*---------------------------------------------------------------------------*/

void osprogress_attach(OSProgress *progress, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)progress);
}

/*---------------------------------------------------------------------------*/

void osprogress_detach(OSProgress *progress, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)progress);
}

/*---------------------------------------------------------------------------*/

void osprogress_visible(OSProgress *progress, const bool_t visible)
{
    _oscontrol_set_visible((OSControl *)progress, visible);
}

/*---------------------------------------------------------------------------*/

void osprogress_enabled(OSProgress *progress, const bool_t enabled)
{
    _oscontrol_set_enabled((OSControl *)progress, enabled);
}

/*---------------------------------------------------------------------------*/

void osprogress_size(const OSProgress *progress, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)progress, width, height);
}

/*---------------------------------------------------------------------------*/

void osprogress_origin(const OSProgress *progress, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)progress, x, y);
}

/*---------------------------------------------------------------------------*/

void osprogress_frame(OSProgress *progress, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)progress, x, y, width, height);
}
