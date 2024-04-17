/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslistener.c
 *
 */

/* View listeners */

#include "oslistener.inl"
#include "oscontrol.inl"
#include "osgui.inl"
#include "osgui_win.inl"
#include "osscrolls.inl"
#include <core/event.h>
#include <osbs/btime.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/types.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

#if _MSC_VER > 1400
#define MAPVK_VSC MAPVK_VSC_TO_VK_EX
#else
#define MAPVK_VSC 1
#endif

/*---------------------------------------------------------------------------*/

void oslistener_init(ViewListeners *listeners)
{
    cassert_no_null(listeners);
    bmem_zero(listeners, ViewListeners);
    listeners->enabled = TRUE;
    listeners->button = ENUM_MAX(gui_mouse_t);
}

/*---------------------------------------------------------------------------*/

void oslistener_remove(ViewListeners *listeners)
{
    cassert_no_null(listeners);
    listener_destroy(&listeners->OnDraw);
    listener_destroy(&listeners->OnEnter);
    listener_destroy(&listeners->OnExit);
    listener_destroy(&listeners->OnMoved);
    listener_destroy(&listeners->OnDown);
    listener_destroy(&listeners->OnUp);
    listener_destroy(&listeners->OnClick);
    listener_destroy(&listeners->OnDrag);
    listener_destroy(&listeners->OnWheel);
    listener_destroy(&listeners->OnKeyDown);
    listener_destroy(&listeners->OnKeyUp);
}

/*---------------------------------------------------------------------------*/

void oslistener_set_enabled(ViewListeners *listeners, bool_t enabled)
{
    cassert_no_null(listeners);
    listeners->enabled = enabled;
}

/*---------------------------------------------------------------------------*/

void oslistener_draw(OSControl *sender, DCtx *ctx, const real32_t width, const real32_t height, const real32_t visible_x, const real32_t visible_y, const real32_t visible_width, const real32_t visible_height, ViewListeners *listeners)
{
    cassert_no_null(sender);
    cassert_no_null(listeners);
    if (listeners->OnDraw != NULL)
    {
        EvDraw params;
        params.ctx = ctx;
        params.x = visible_x;
        params.y = visible_y;
        params.width = visible_width;
        params.height = visible_height;
        unref(width);
        unref(height);
        listener_event(listeners->OnDraw, ekGUI_EVENT_DRAW, sender, &params, NULL, OSControl, EvDraw, void);
    }
}

/*---------------------------------------------------------------------------*/

void oslistener_mouse_exit(OSControl *sender, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert(listeners->is_mouse_inside == TRUE);
    listeners->is_mouse_inside = FALSE;
    if (listeners->OnExit != NULL)
        listener_event(listeners->OnExit, ekGUI_EVENT_EXIT, sender, NULL, NULL, OSControl, void, void);
}

/*---------------------------------------------------------------------------*/

void oslistener_mouse_moved(OSControl *sender, WPARAM event_wParam, const real32_t x, const real32_t y, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(sender);
    if (listeners->enabled == TRUE)
    {
        EvMouse params;

        if ((event_wParam & MK_LBUTTON) && listeners->button != ekGUI_MOUSE_LEFT)
            return;

        if ((event_wParam & MK_RBUTTON) && listeners->button != ekGUI_MOUSE_RIGHT)
            return;

        if ((event_wParam & MK_MBUTTON) && listeners->button != ekGUI_MOUSE_MIDDLE)
            return;

        params.x = x + (scroll ? osscrolls_x_pos(scroll) : 0);
        params.y = y + (scroll ? osscrolls_y_pos(scroll) : 0);
        params.lx = x;
        params.ly = y;
        params.button = listeners->button;
        params.count = 0;
        params.modifiers = _osgui_modifiers();
        params.tag = 0;

        if (listeners->button != ENUM_MAX(gui_mouse_t))
        {
            /*if (x >= 0.f && x < frame.size.width && y >= 0.f && y < frame.size.height)*/
            {
                if (listeners->OnDrag != NULL)
                    listener_event(listeners->OnDrag, ekGUI_EVENT_DRAG, sender, &params, NULL, OSControl, EvMouse, void);
            }
        }
        else
        {
            if (listeners->is_mouse_inside == FALSE)
            {
                TRACKMOUSEEVENT track;
                BOOL ok;
                listeners->is_mouse_inside = TRUE;
                track.cbSize = sizeof(TRACKMOUSEEVENT);
                track.dwFlags = /*TME_HOVER | */ TME_LEAVE;
                track.hwndTrack = sender->hwnd;
                track.dwHoverTime = HOVER_DEFAULT;
                ok = TrackMouseEvent(&track);
                cassert_unref(ok == TRUE, ok);

                if (listeners->OnEnter != NULL)
                    listener_event(listeners->OnEnter, ekGUI_EVENT_ENTER, sender, &params, NULL, OSControl, EvMouse, void);
            }
            else if (listeners->OnMoved != NULL)
            {
                listener_event(listeners->OnMoved, ekGUI_EVENT_MOVED, sender, &params, NULL, OSControl, EvMouse, void);
            }
        }
    }
}

/*---------------------------------------------------------------------------*/

void oslistener_mouse_down(OSControl *sender, const gui_mouse_t button, const real32_t x, const real32_t y, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(sender);
    if (listeners->enabled == TRUE)
    {
        listeners->button = button;
        SetCapture(sender->hwnd);

        listeners->mouse_down_x = x;
        listeners->mouse_down_y = y;
        listeners->mouse_down_time = btime_now();

        if (listeners->OnDown != NULL)
        {
            EvMouse params;
            params.x = x + (scroll ? osscrolls_x_pos(scroll) : 0);
            params.y = y + (scroll ? osscrolls_y_pos(scroll) : 0);
            params.lx = x;
            params.ly = y;
            params.button = button;
            params.count = 0;
            params.modifiers = _osgui_modifiers();
            params.tag = 0;
            listener_event(listeners->OnDown, ekGUI_EVENT_DOWN, sender, &params, NULL, OSControl, EvMouse, void);
        }
    }
}

/*---------------------------------------------------------------------------*/

void oslistener_mouse_up(OSControl *sender, const gui_mouse_t button, const real32_t x, const real32_t y, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(sender);
    if (listeners->enabled == TRUE)
    {
        EvMouse params;
        params.x = x + (scroll ? osscrolls_x_pos(scroll) : 0);
        params.y = y + (scroll ? osscrolls_y_pos(scroll) : 0);
        params.lx = x;
        params.ly = y;
        params.button = button;
        params.count = 0;
        params.modifiers = _osgui_modifiers();
        params.tag = 0;

        {
            BOOL ok = ReleaseCapture();
            cassert_unref(ok != 0, ok);
        }

        if (listeners->OnUp != NULL)
            listener_event(listeners->OnUp, ekGUI_EVENT_UP, sender, &params, NULL, OSControl, EvMouse, void);

        if (listeners->OnClick != NULL)
        {
            // Milliseconds
            uint64_t ellapsed = (btime_now() - listeners->mouse_down_time) / 1000;
            UINT max = GetDoubleClickTime();
            real32_t dx = abs_r32(x - listeners->mouse_down_x);
            real32_t dy = abs_r32(y - listeners->mouse_down_y);
            if (ellapsed < max && dx < 5 && dy < 5)
                listener_event(listeners->OnClick, ekGUI_EVENT_CLICK, sender, &params, NULL, OSControl, EvMouse, void);
        }

        listeners->button = ENUM_MAX(gui_mouse_t);
    }
}

/*---------------------------------------------------------------------------*/

void oslistener_whell(OSControl *sender, WPARAM event_wParam, LPARAM event_lParam, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(sender);
    if (listeners->enabled == TRUE)
    {
        if (listeners->OnWheel != NULL)
        {
            POINTS spoint;
            POINT point;
            BOOL ok;
            EvWheel params;
            spoint = MAKEPOINTS(event_lParam);
            point.x = spoint.x;
            point.y = spoint.y;
            ok = ScreenToClient(sender->hwnd, &point);
            cassert_unref(ok == TRUE, ok);
            params.x = (real32_t)point.x + (scroll ? osscrolls_x_pos(scroll) : 0);
            params.y = (real32_t)point.y + (scroll ? osscrolls_y_pos(scroll) : 0);
            params.dx = 0;
            params.dy = (real32_t)(GET_WHEEL_DELTA_WPARAM(event_wParam) / WHEEL_DELTA);
            params.dz = 0;
            listener_event(listeners->OnWheel, ekGUI_EVENT_WHEEL, sender, &params, NULL, OSControl, EvWheel, void);
        }
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_key_event(OSControl *sender, const uint32_t type, WPARAM wParam, LPARAM lParam, Listener *listener)
{
    cassert_no_null(sender);
    cassert_unref(sender->type == ekGUI_TYPE_CUSTOMVIEW, sender);
    if (listener != NULL)
    {
        vkey_t key = ENUM_MAX(vkey_t);

        if (wParam == VK_SHIFT)
        {
            register UINT scancode = (lParam & 0x00ff0000) >> 16;
            wParam = MapVirtualKey(scancode, MAPVK_VSC);
            if (wParam == VK_LSHIFT)
                key = ekKEY_LSHIFT;
            else if (wParam == VK_RSHIFT)
                key = ekKEY_RSHIFT;
        }
        else if (wParam == VK_CONTROL)
        {
            if ((lParam & 0x01000000) != 0)
                key = ekKEY_RCTRL;
            else
                key = ekKEY_LCTRL;
        }
        else if (wParam == VK_MENU)
        {
            if ((lParam & 0x01000000) != 0)
                key = ekKEY_RALT;
            else
                key = ekKEY_LALT;
        }
        else
        {
            key = _osgui_vkey((WORD)wParam);
        }

        if (key != ENUM_MAX(vkey_t))
        {
            EvKey params;
            params.key = key;
            params.modifiers = _osgui_modifiers();
            listener_event(listener, type, sender, &params, NULL, OSControl, EvKey, void);
            return TRUE;
        }
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t oslistener_key_down(OSControl *sender, WPARAM wParam, LPARAM lParam, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    return i_key_event(sender, ekGUI_EVENT_KEYDOWN, wParam, lParam, listeners->OnKeyDown);
}

/*---------------------------------------------------------------------------*/

bool_t oslistener_key_up(OSControl *sender, WPARAM wParam, LPARAM lParam, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    return i_key_event(sender, ekGUI_EVENT_KEYUP, wParam, lParam, listeners->OnKeyUp);
}
