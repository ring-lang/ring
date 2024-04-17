/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osscroll.c
 *
 */

/* Operating System native scrollbar */

#include "osscroll.inl"
#include "osscroll_win.inl"
#include "osgui_win.inl"
#include <core/heap.h>
#include <sewer/cassert.h>

struct _osscroll_t
{
    int type;
    HWND hwnd;
};

/*---------------------------------------------------------------------------*/

static HWND i_create_scroll(DWORD type, HWND hwnd, int width, int height)
{
    return CreateWindowEx(
        0, L"SCROLLBAR", NULL,
        WS_CHILD | WS_CLIPSIBLINGS | type,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        hwnd,
        (HMENU)NULL,
        _osgui_instance(),
        NULL);
}

/*---------------------------------------------------------------------------*/

OSScroll *osscroll_horizontal(OSControl *control)
{
    OSScroll *scroll = heap_new(OSScroll);
    DWORD dwStyle = 0;
    cassert_no_null(control);
    dwStyle = (DWORD)GetWindowLong(control->hwnd, GWL_STYLE);

    /* The window has standard horizontal scrollbar */
    if (dwStyle & WS_HSCROLL)
    {
        scroll->type = SBS_HORZ;
        scroll->hwnd = control->hwnd;
    }
    else
    {
        scroll->type = SB_CTL;
        scroll->hwnd = i_create_scroll(scroll->type, control->hwnd, 100, GetSystemMetrics(SM_CXHSCROLL));
    }

    return scroll;
}

/*---------------------------------------------------------------------------*/

OSScroll *osscroll_vertical(OSControl *control)
{
    OSScroll *scroll = heap_new(OSScroll);
    DWORD dwStyle = 0;
    cassert_no_null(control);
    dwStyle = (DWORD)GetWindowLong(control->hwnd, GWL_STYLE);

    /* The window has standard vertical scrollbar */
    if (dwStyle & WS_VSCROLL)
    {
        scroll->type = SBS_VERT;
        scroll->hwnd = control->hwnd;
    }
    else
    {
        scroll->type = SB_CTL;
        scroll->hwnd = i_create_scroll(SBS_VERT, control->hwnd, GetSystemMetrics(SM_CXVSCROLL), 100);
    }

    return scroll;
}

/*---------------------------------------------------------------------------*/

void osscroll_destroy(OSScroll **scroll, OSControl *control)
{
    cassert_no_null(scroll);
    cassert_no_null(*scroll);
    cassert_no_null(control);
    if ((*scroll)->hwnd != control->hwnd)
    {
        HWND ret0 = NULL;
        BOOL ret1 = 0;
        cassert(GetParent((*scroll)->hwnd) == control->hwnd);
        ret0 = SetParent((*scroll)->hwnd, NULL);
        cassert_unref(ret0 == control->hwnd, ret0);
        ret1 = DestroyWindow((*scroll)->hwnd);
        cassert_unref(ret1 != 0, ret1);
    }

    heap_delete(scroll, OSScroll);
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_pos(const OSScroll *scroll)
{
    return (uint32_t)GetScrollPos(scroll->hwnd, scroll->type);
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_trackpos(const OSScroll *scroll)
{
    SCROLLINFO si;
    BOOL ok;
    cassert_no_null(scroll);
    si.cbSize = sizeof(SCROLLINFO);
    si.fMask = SIF_TRACKPOS;
    ok = GetScrollInfo(scroll->hwnd, scroll->type, &si);
    cassert_unref(ok != 0, ok);
    return (uint32_t)si.nTrackPos;
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_bar_width(const OSScroll *scroll)
{
    unref(scroll);
    return (uint32_t)GetSystemMetrics(SM_CXVSCROLL);
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_bar_height(const OSScroll *scroll)
{
    unref(scroll);
    return (uint32_t)GetSystemMetrics(SM_CXHSCROLL);
}

/*---------------------------------------------------------------------------*/

void osscroll_set_pos(OSScroll *scroll, const uint32_t pos)
{
    cassert_no_null(scroll);
    SetScrollPos(scroll->hwnd, scroll->type, (int)pos, TRUE);
}

/*---------------------------------------------------------------------------*/

void osscroll_visible(OSScroll *scroll, const bool_t visible)
{
    BOOL ret;
    cassert_no_null(scroll);
    ret = ShowScrollBar(scroll->hwnd, scroll->type, visible);
    cassert_unref(ret != 0, ret);
}

/*---------------------------------------------------------------------------*/

void osscroll_config(OSScroll *scroll, const uint32_t pos, const uint32_t max, const uint32_t page)
{
    SCROLLINFO si;
    cassert_no_null(scroll);
    si.cbSize = sizeof(SCROLLINFO);
    si.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;
    si.nPage = (UINT)page;
    si.nMin = 0;
    si.nMax = (int)max;
    si.nPos = (int)pos;
    SetScrollInfo(scroll->hwnd, scroll->type, &si, FALSE);
}

/*---------------------------------------------------------------------------*/

void osscroll_frame(OSScroll *scroll, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height)
{
    cassert_no_null(scroll);
    if (scroll->type == SB_CTL)
    {
        /* The control-owner scrollbars are automatically positioned  */
        BOOL ret = SetWindowPos(scroll->hwnd, NULL, (int)x, (int)y, (int)width, (int)height, SWP_NOZORDER);
        cassert_unref(ret != 0, ret);
    }
}

/*---------------------------------------------------------------------------*/

void osscroll_control_scroll(OSControl *control, const int32_t incr_x, const int32_t incr_y)
{
    cassert_no_null(control);
    ScrollWindowEx(control->hwnd, (int)incr_x, (int)incr_y, NULL, NULL, NULL, NULL, SW_SCROLLCHILDREN | SW_INVALIDATE | SW_ERASE);
}

/*---------------------------------------------------------------------------*/

gui_scroll_t osscroll_event(WPARAM wParam)
{
    WORD lw = LOWORD(wParam);
    switch (lw)
    {
    case SB_TOP:
        return ekGUI_SCROLL_BEGIN;
    case SB_BOTTOM:
        return ekGUI_SCROLL_END;
    case SB_LINEUP:
        return ekGUI_SCROLL_STEP_LEFT;
    case SB_LINEDOWN:
        return ekGUI_SCROLL_STEP_RIGHT;
    case SB_PAGEUP:
        return ekGUI_SCROLL_PAGE_LEFT;
    case SB_PAGEDOWN:
        return ekGUI_SCROLL_PAGE_RIGHT;
    case SB_THUMBTRACK:
    case SB_THUMBPOSITION:
        return ekGUI_SCROLL_THUMB;
    case SB_ENDSCROLL:
        break;
        cassert_default();
    }

    return ENUM_MAX(gui_scroll_t);
}
