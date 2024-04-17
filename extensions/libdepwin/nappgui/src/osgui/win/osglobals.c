/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osglobals.c
 *
 */

/* Operating System native screen */

#include "osglobals.h"
#include "osgui_win.inl"
#include "oswindow_win.inl"
#include "osimg.inl"
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

/*---------------------------------------------------------------------------*/

device_t osglobals_device(const void *non_used)
{
    cassert(FALSE);
    cassert_unref(non_used == NULL, non_used);
    return ekDESKTOP;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_color(const syscolor_t *color)
{
    cassert_no_null(color);

    switch (*color)
    {
    case ekSYSCOLOR_DARKMODE:
    {
        uint32_t c = GetSysColor(COLOR_3DFACE);
        real32_t r = (real32_t)((uint8_t)(c) / 255.f);
        real32_t g = (real32_t)((uint8_t)(c >> 8) / 255.f);
        real32_t b = (real32_t)((uint8_t)(c >> 16) / 255.f);
        return (.21 * r + .72 * g + .07 * b) < .5 ? TRUE : FALSE;
    }

    case ekSYSCOLOR_LABEL:
        return GetSysColor(COLOR_BTNTEXT) | (255 << 24);

    case ekSYSCOLOR_VIEW:
        return GetSysColor(COLOR_3DFACE) | (255 << 24);

    case ekSYSCOLOR_LINE:
        return GetSysColor(COLOR_SCROLLBAR) | (255 << 24);

    case ekSYSCOLOR_LINK:
        return GetSysColor(COLOR_HOTLIGHT) | (255 << 24);

    case ekSYSCOLOR_BORDER:
        return GetSysColor(COLOR_ACTIVEBORDER) | (255 << 24);

        cassert_default();
    }

    return 0;
}

/*---------------------------------------------------------------------------*/

void osglobals_resolution(const void *non_used, real32_t *width, real32_t *height)
{
    unref(non_used);
    cassert_no_null(width);
    cassert_no_null(height);
    *width = (real32_t)GetSystemMetrics(SM_CXSCREEN);
    *height = (real32_t)GetSystemMetrics(SM_CYSCREEN);
}

/*---------------------------------------------------------------------------*/

void osglobals_mouse_position(const void *non_used, real32_t *x, real32_t *y)
{
    POINT pt = {0};
    BOOL ok = FALSE;
    unref(non_used);
    cassert_no_null(x);
    cassert_no_null(y);
    ok = GetCursorPos(&pt);
    cassert(ok != 0);
    *x = (real32_t)pt.x;
    *y = (real32_t)pt.y;
}

/*---------------------------------------------------------------------------*/

Cursor *osglobals_cursor(const gui_cursor_t cursor, const Image *image, const real32_t hot_x, const real32_t hot_y)
{
    HCURSOR hcursor = NULL;
    switch (cursor)
    {
    case ekGUI_CURSOR_ARROW:
        hcursor = LoadCursor(NULL, IDC_ARROW);
        break;
    case ekGUI_CURSOR_HAND:
        hcursor = LoadCursor(NULL, IDC_HAND);
        break;
    case ekGUI_CURSOR_IBEAM:
        hcursor = LoadCursor(NULL, IDC_IBEAM);
        break;
    case ekGUI_CURSOR_CROSS:
        hcursor = LoadCursor(NULL, IDC_CROSS);
        break;
    case ekGUI_CURSOR_SIZEWE:
        hcursor = LoadCursor(NULL, IDC_SIZEWE);
        break;
    case ekGUI_CURSOR_SIZENS:
        hcursor = LoadCursor(NULL, IDC_SIZENS);
        break;
    case ekGUI_CURSOR_USER:
        hcursor = osimg_hcursor(image, (uint32_t)hot_x, (uint32_t)hot_y);
        break;
        cassert_default();
    }

    heap_auditor_add("HCURSOR");
    return (Cursor *)hcursor;
}

/*---------------------------------------------------------------------------*/

void osglobals_cursor_destroy(Cursor **cursor)
{
    BOOL ret;
    cassert_no_null(cursor);
    cassert_no_null(*cursor);
    ret = DestroyCursor((HCURSOR)*cursor);
    cassert_unref(ret != 0, ret);
    heap_auditor_delete("HCURSOR");
    *cursor = NULL;
}

/*---------------------------------------------------------------------------*/

void osglobals_value(const uint32_t index, void *value)
{
    cassert_no_null(value);
    switch (index)
    {
    case 0:
        (*(uint32_t *)value) = GetSystemMetrics(SM_CXVSCROLL);
        break;

    case 1:
        (*(uint32_t *)value) = GetSystemMetrics(SM_CXHSCROLL);
        break;

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void osglobals_transitions(void *nonused, const real64_t prtime, const real64_t crtime)
{
    unref(nonused);
    unref(prtime);
    unref(crtime);
}

/*---------------------------------------------------------------------------*/

void osglobals_OnIdle(void *nonused, Listener *listener)
{
    unref(nonused);
    _oswindow_OnIdle(listener);
}
