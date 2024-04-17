/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osview.cpp
 *
 */

/* Operating System native custom view */

#include "osview.h"
#include "osview.inl"
#include "osgui.inl"
#include "osgui_win.inl"
#include "oscontrol_win.inl"
#include "ospanel_win.inl"
#include "osscroll_win.inl"
#include "oswindow_win.inl"
#include "oslistener.inl"
#include "osscrolls.inl"
#include "osstyleXP.inl"
#include <draw2d/color.h>
#include <draw2d/draw.h>
#include <draw2d/dctxh.h>
#include <core/event.h>
#include <core/heap.h>
#include <osbs/osbs.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

#include <sewer/nowarn.hxx>
#include <gdiplus.h>
#include <Commctrl.h>
#include <sewer/warn.hxx>

struct _osview_t
{
    OSControl control;
    OSPanel *parent_panel;
    OSScrolls *scroll;
    DCtx *ctx;
    uint32_t flags;
    bool_t focused;
    HBITMAP dbuffer;
    LONG dbuffer_width;
    LONG dbuffer_height;
    RECT border;
    ViewListeners listeners;
    OSDraw osdraw;
    Listener *OnOverlay;
    Listener *OnFocus;
    Listener *OnResignFocus;
    Listener *OnAcceptFocus;
};

/*---------------------------------------------------------------------------*/

#define i_color(c) \
    Gdiplus::Color((BYTE)(c), (BYTE)((c) >> 8), (BYTE)((c) >> 16))

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSView *view = (OSView *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(view);
    cassert(view->control.type == ekGUI_TYPE_CUSTOMVIEW);
    cassert(view->control.hwnd == hwnd);

    switch (uMsg)
    {
    case WM_ERASEBKGND:
        return 1;

    case WM_PRINTCLIENT:
        cassert(FALSE);
        oslistener_draw((OSControl *)view, NULL, 0, 0, 0, 0, 0, 0, &view->listeners);
        return 0;

    case WM_NCCALCSIZE:
        if (view->flags & ekVIEW_BORDER)
        {
            _osgui_nccalcsize(hwnd, wParam, lParam, FALSE, 0, &view->border);
            return CallWindowProc(view->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
        }
        break;

    case WM_NCPAINT:
        if (view->flags & ekVIEW_BORDER)
        {
            CallWindowProc(view->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
            return _osgui_ncpaint(hwnd, view->focused, &view->border, NULL);
        }
        break;

    case WM_PAINT:
    {
        LONG_PTR edata;

        if (_oswindow_in_resizing(hwnd) == TRUE)
            return 0;

        // Extra data is defined in 'i_registry_view_class::cbWndExtra'
        // 0 means GDI/GDI+ based drawing
        edata = GetWindowLongPtr(hwnd, 0);
        if (edata == 0)
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(view->control.hwnd, &ps);
            HDC memHdc = CreateCompatibleDC(hdc);

            if (view->ctx == NULL)
            {
                view->ctx = dctx_create();
                dctx_data(view->ctx, &view->osdraw, NULL, OSDraw);
            }

            if (__TRUE_EXPECTED(view->dbuffer == NULL))
                view->dbuffer = CreateCompatibleBitmap(hdc, view->dbuffer_width, view->dbuffer_height);

            // Draw on an image back-buffer
            SelectObject(memHdc, view->dbuffer);

            // Can be called from OSView attached to OSSplit (not OSPanel)
            uint32_t background;
            if (view->parent_panel != NULL)
            {
                cassert(((OSControl *)view->parent_panel)->type == ekGUI_TYPE_PANEL);
                background = (uint32_t)_ospanel_background_color(view->parent_panel, (OSControl *)view);
            }
            else
            {
                background = (uint32_t)GetSysColor(COLOR_3DFACE);
            }

            Gdiplus::Graphics *graphics = new Gdiplus::Graphics(memHdc);

            // Don't delete --> ImageView-like controls with standard background
            if ((view->flags & ekVIEW_NOERASE) == 0)
                graphics->Clear(i_color(background));

            uint32_t vx = 0;
            uint32_t vy = 0;
            uint32_t vwidth = (uint32_t)view->dbuffer_width;
            uint32_t vheight = (uint32_t)view->dbuffer_height;
            uint32_t twidth = vwidth;
            uint32_t theight = vheight;

            if (view->scroll != NULL)
                osscrolls_visible_area(view->scroll, &vx, &vy, &vwidth, &vheight, &twidth, &theight);

            void *ctx[2];
            ctx[0] = graphics;
            ctx[1] = memHdc;
            dctx_set_gcontext(view->ctx, ctx, (uint32_t)vwidth, (uint32_t)vheight, -(real32_t)vx, -(real32_t)vy, background, TRUE /*(view->flags & ekCONTROL) ? FALSE : TRUE*/);
            oslistener_draw((OSControl *)view, view->ctx, (real32_t)twidth, (real32_t)theight, (real32_t)vx, (real32_t)vy, (real32_t)vwidth, (real32_t)vheight, &view->listeners);
            dctx_unset_gcontext(view->ctx);

            if (view->OnOverlay != NULL)
            {
                EvDraw params;
                params.ctx = view->ctx;
                params.x = 0;
                params.y = 0;
                params.width = (real32_t)vwidth;
                params.height = (real32_t)vheight;
                dctx_set_gcontext(view->ctx, ctx, (uint32_t)vwidth, (uint32_t)vheight, 0, 0, 0, TRUE);
                listener_event(view->OnOverlay, ekGUI_EVENT_OVERLAY, (OSControl *)view, &params, NULL, OSControl, EvDraw, void);
                dctx_unset_gcontext(view->ctx);
            }

            delete graphics;
            graphics = NULL;

            // Back buffer image to window
            BitBlt(hdc, 0, 0, view->dbuffer_width, view->dbuffer_height, memHdc, 0, 0, SRCCOPY);

            BOOL ok = DeleteDC(memHdc);
            cassert_unref(ok != 0, ok);

            EndPaint(hwnd, &ps);
        }
        // The window is rendered with other technology
        else
        {
            oslistener_draw((OSControl *)view, NULL, (real32_t)view->dbuffer_width, (real32_t)view->dbuffer_height, 0, 0, (real32_t)view->dbuffer_width, (real32_t)view->dbuffer_height, &view->listeners);
        }

        return 0;
    }

    // This Window must process mouse events
    // case WM_NCHITTEST:
    //Automatic SetFocus for Mouse Wheel over view without click
    //     if (osbs_windows() <= ekWIN_8 && (view->listeners.OnWheel != NULL || view->vscroll != NULL))
    //         SetFocus(hwnd);
    //     return HTCLIENT;
    //
    case WM_MOUSELEAVE:
        oslistener_mouse_exit((OSControl *)view, &view->listeners);
        return 0;

    case WM_MOUSEMOVE:
    {
        POINTS point = MAKEPOINTS(lParam);
        oslistener_mouse_moved((OSControl *)view, wParam, (real32_t)point.x, (real32_t)point.y, view->scroll, &view->listeners);
        return 0;
    }

    case WM_LBUTTONDOWN:
        if (_oswindow_mouse_down(OSControlPtr(view)) == TRUE)
        {
            POINTS point = MAKEPOINTS(lParam);
            oslistener_mouse_down((OSControl *)view, ekGUI_MOUSE_LEFT, (real32_t)point.x, (real32_t)point.y, view->scroll, &view->listeners);
        }
        return 0;

    case WM_LBUTTONDBLCLK:
        if (_oswindow_mouse_down(OSControlPtr(view)) == TRUE)
            break;
        return 0;

    case WM_RBUTTONDOWN:
    {
        POINTS point = MAKEPOINTS(lParam);
        oslistener_mouse_down((OSControl *)view, ekGUI_MOUSE_RIGHT, (real32_t)point.x, (real32_t)point.y, view->scroll, &view->listeners);
        return 0;
    }

    case WM_MBUTTONDOWN:
    {
        POINTS point = MAKEPOINTS(lParam);
        oslistener_mouse_down((OSControl *)view, ekGUI_MOUSE_MIDDLE, (real32_t)point.x, (real32_t)point.y, view->scroll, &view->listeners);
        return 0;
    }

    case WM_LBUTTONUP:
    {
        POINTS point = MAKEPOINTS(lParam);
        oslistener_mouse_up((OSControl *)view, ekGUI_MOUSE_LEFT, (real32_t)point.x, (real32_t)point.y, view->scroll, &view->listeners);
        return 0;
    }

    case WM_RBUTTONUP:
    {
        POINTS point = MAKEPOINTS(lParam);
        oslistener_mouse_up((OSControl *)view, ekGUI_MOUSE_RIGHT, (real32_t)point.x, (real32_t)point.y, view->scroll, &view->listeners);
        return 0;
    }

    case WM_MBUTTONUP:
    {
        POINTS point = MAKEPOINTS(lParam);
        oslistener_mouse_up((OSControl *)view, ekGUI_MOUSE_MIDDLE, (real32_t)point.x, (real32_t)point.y, view->scroll, &view->listeners);
        return 0;
    }

    case WM_MOUSEWHEEL:
        if (view->scroll != NULL)
        {
            gui_scroll_t event = ekGUI_SCROLL_STEP_LEFT;
            if (GET_WHEEL_DELTA_WPARAM(wParam) < 0)
                event = ekGUI_SCROLL_STEP_RIGHT;
            if (osscrolls_event(view->scroll, ekGUI_VERTICAL, event, FALSE) == TRUE)
                InvalidateRect(view->control.hwnd, NULL, FALSE);
        }

        oslistener_whell((OSControl *)view, wParam, lParam, view->scroll, &view->listeners);
        break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        if (oslistener_key_down((OSControl *)view, wParam, lParam, &view->listeners) == TRUE)
            return 0;
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        if (oslistener_key_up((OSControl *)view, wParam, lParam, &view->listeners) == TRUE)
            return 0;
        break;

    case WM_HSCROLL:
    case WM_VSCROLL:
    {
        gui_scroll_t event = osscroll_event(wParam);
        if (event != ENUM_MAX(gui_scroll_t))
        {
            gui_orient_t orient = uMsg == WM_HSCROLL ? ekGUI_HORIZONTAL : ekGUI_VERTICAL;
            if (osscrolls_event(view->scroll, orient, event, FALSE) == TRUE)
                InvalidateRect(view->control.hwnd, NULL, FALSE);
        }
        return 0;
    }
    }

    return CallWindowProc(view->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

OSView *osview_create(const uint32_t flags)
{
    OSView *view = heap_new0(OSView);
    DWORD dwStyle = WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

    if (flags & ekVIEW_HSCROLL)
        dwStyle |= WS_HSCROLL;

    if (flags & ekVIEW_VSCROLL)
        dwStyle |= WS_VSCROLL;

    _oscontrol_init((OSControl *)view, PARAM(dwExStyle, WS_EX_NOPARENTNOTIFY), dwStyle, kVIEW_CLASS, 16, 16, i_WndProc, kDEFAULT_PARENT_WINDOW);
    view->control.type = ekGUI_TYPE_CUSTOMVIEW;
    view->flags = flags;
    view->focused = FALSE;

    // Extra data is defined in 'i_registry_view_class::cbWndExtra'
    // 0 means GDI/GDI+ based drawing
    SetWindowLongPtr(view->control.hwnd, 0, 0);

    if ((flags & ekVIEW_HSCROLL) || (flags & ekVIEW_VSCROLL))
        view->scroll = osscrolls_create((OSControl *)view, (bool_t)(flags & ekVIEW_HSCROLL) != 0, (bool_t)(flags & ekVIEW_VSCROLL) != 0);

    if (flags & ekVIEW_CONTROL)
    {
        view->osdraw.button_theme = osstyleXP_OpenTheme(view->control.hwnd, L"BUTTON");
        view->osdraw.list_theme = osstyleXP_OpenTheme(view->control.hwnd, L"Explorer::ListView");
        view->osdraw.header_theme = osstyleXP_OpenTheme(view->control.hwnd, L"HEADER");
        view->osdraw.sort_size.cx = -1;
        view->osdraw.sort_size.cy = -1;

        // WinXP
        if (view->osdraw.list_theme == NULL)
            view->osdraw.list_theme = osstyleXP_OpenTheme(view->control.hwnd, L"ListView");
    }

    oslistener_init(&view->listeners);
    return view;
}

/*---------------------------------------------------------------------------*/

void osview_destroy(OSView **view)
{
    cassert_no_null(view);
    cassert_no_null(*view);

    oslistener_remove(&(*view)->listeners);
    listener_destroy(&(*view)->OnOverlay);
    listener_destroy(&(*view)->OnFocus);
    listener_destroy(&(*view)->OnResignFocus);
    listener_destroy(&(*view)->OnAcceptFocus);

    if ((*view)->dbuffer != NULL)
    {
        BOOL ok = DeleteObject((*view)->dbuffer);
        cassert_unref(ok != 0, ok);
    }

    if ((*view)->ctx != NULL)
        dctx_destroy(&(*view)->ctx);

    if ((*view)->scroll != NULL)
        osscrolls_destroy(&(*view)->scroll);

    if ((*view)->osdraw.button_theme != NULL)
    {
        osstyleXP_CloseTheme((*view)->osdraw.button_theme);
        (*view)->osdraw.button_theme = NULL;
    }

    if ((*view)->osdraw.list_theme != NULL)
    {
        osstyleXP_CloseTheme((*view)->osdraw.list_theme);
        (*view)->osdraw.list_theme = NULL;
    }

    if ((*view)->osdraw.header_theme != NULL)
    {
        osstyleXP_CloseTheme((*view)->osdraw.header_theme);
        (*view)->osdraw.header_theme = NULL;
    }

    _oscontrol_destroy(&(*view)->control);
    heap_delete(view, OSView);
}

/*---------------------------------------------------------------------------*/

void osview_OnDraw(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnDraw, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnOverlay(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->OnOverlay, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnEnter(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnEnter, listener);
    view->listeners.is_mouse_inside = FALSE;
}

/*---------------------------------------------------------------------------*/

void osview_OnExit(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnExit, listener);
    view->listeners.is_mouse_inside = FALSE;
}

/*---------------------------------------------------------------------------*/

void osview_OnMoved(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnMoved, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnDown(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnDown, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnUp(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnUp, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnClick(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnClick, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnDrag(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnDrag, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnWheel(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnWheel, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnKeyDown(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnKeyDown, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnKeyUp(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->listeners.OnKeyUp, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnFocus(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->OnFocus, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnResignFocus(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->OnResignFocus, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnAcceptFocus(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->OnAcceptFocus, listener);
}

/*---------------------------------------------------------------------------*/

void osview_OnScroll(OSView *view, Listener *listener)
{
    cassert_no_null(view);
    osscrolls_OnScroll(view->scroll, listener);
}

/*---------------------------------------------------------------------------*/

void osview_scroll(OSView *view, const real32_t x, const real32_t y)
{
    cassert_no_null(view);
    osscrolls_set(view->scroll, x >= 0 ? (uint32_t)x : UINT32_MAX, y >= 0 ? (uint32_t)y : UINT32_MAX, FALSE);
}

/*---------------------------------------------------------------------------*/

void osview_scroll_get(const OSView *view, real32_t *x, real32_t *y)
{
    cassert_no_null(view);
    if (x != NULL)
        *x = (real32_t)osscrolls_x_pos(view->scroll);

    if (y != NULL)
        *y = (real32_t)osscrolls_y_pos(view->scroll);
}

/*---------------------------------------------------------------------------*/

void osview_scroller_size(const OSView *view, real32_t *width, real32_t *height)
{
    cassert_no_null(view);
    if (width != NULL)
        *width = (real32_t)osscrolls_bar_width(view->scroll, TRUE);

    if (height != NULL)
        *height = (real32_t)osscrolls_bar_height(view->scroll, TRUE);
}

/*---------------------------------------------------------------------------*/

void osview_scroller_visible(OSView *view, const bool_t horizontal, const bool_t vertical)
{
    cassert_no_null(view);
    osscrolls_visible(view->scroll, horizontal, vertical);
}

/*---------------------------------------------------------------------------*/

void osview_content_size(OSView *view, const real32_t width, const real32_t height, const real32_t line_width, const real32_t line_height)
{
    cassert_no_null(view);
    osscrolls_content_size(view->scroll, (uint32_t)width, (uint32_t)height, (uint32_t)line_width, (uint32_t)line_height);
}

/*---------------------------------------------------------------------------*/

real32_t osview_scale_factor(const OSView *view)
{
    unref(view);
    return 1;
}

/*---------------------------------------------------------------------------*/

void osview_set_need_display(OSView *view)
{
    cassert_no_null(view);
    InvalidateRect(view->control.hwnd, NULL, FALSE);
}

/*---------------------------------------------------------------------------*/

void *osview_get_native_view(const OSView *view)
{
    cassert_no_null(view);
    return (void *)view->control.hwnd;
}

/*---------------------------------------------------------------------------*/

void osview_attach(OSView *view, OSPanel *panel)
{
    cassert(view->parent_panel == NULL);
    view->parent_panel = panel;
    _ospanel_attach_control(panel, (OSControl *)view);
}

/*---------------------------------------------------------------------------*/

void osview_detach(OSView *view, OSPanel *panel)
{
    cassert(view->parent_panel == panel);
    view->parent_panel = NULL;
    _ospanel_detach_control(panel, (OSControl *)view);
}

/*---------------------------------------------------------------------------*/

void osview_visible(OSView *view, const bool_t visible)
{
    _oscontrol_set_visible((OSControl *)view, visible);
}

/*---------------------------------------------------------------------------*/

void osview_enabled(OSView *view, const bool_t enabled)
{
    _oscontrol_set_enabled((OSControl *)view, enabled);
}

/*---------------------------------------------------------------------------*/

void osview_size(const OSView *view, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)view, width, height);
}

/*---------------------------------------------------------------------------*/

void osview_origin(const OSView *view, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)view, x, y);
}

/*---------------------------------------------------------------------------*/

void osview_frame(OSView *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    cassert_no_null(view);
    _oscontrol_set_frame((OSControl *)view, x, y, width, height);
    view->dbuffer_width = (LONG)width;
    view->dbuffer_height = (LONG)height;

    if (view->dbuffer != NULL)
    {
        DeleteObject(view->dbuffer);
        view->dbuffer = NULL;
    }

    if (view->scroll != NULL)
        osscrolls_control_size(view->scroll, (uint32_t)width, (uint32_t)height);
}

/*---------------------------------------------------------------------------*/

bool_t osview_resign_focus(const OSView *view)
{
    bool_t resign = TRUE;
    cassert_no_null(view);
    if (view->OnResignFocus != NULL)
        listener_event(view->OnResignFocus, ekGUI_EVENT_FOCUS_RESIGN, view, NULL, &resign, OSView, void, bool_t);
    return resign;
}

/*---------------------------------------------------------------------------*/

bool_t osview_accept_focus(const OSView *view)
{
    bool_t accept = TRUE;
    cassert_no_null(view);
    if (view->OnAcceptFocus != NULL)
        listener_event(view->OnAcceptFocus, ekGUI_EVENT_FOCUS_ACCEPT, view, NULL, &accept, OSView, void, bool_t);
    return accept;
}

/*---------------------------------------------------------------------------*/

void osview_focus(OSView *view, const bool_t focus)
{
    cassert_no_null(view);

    view->focused = focus;

    if (view->OnFocus != NULL)
    {
        bool_t params = focus;
        listener_event(view->OnFocus, ekGUI_EVENT_FOCUS, view, &params, NULL, OSView, bool_t, void);
    }

    if (view->flags & ekVIEW_BORDER)
        RedrawWindow(view->control.hwnd, NULL, NULL, RDW_FRAME | RDW_INVALIDATE);
}
