/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslistener.m
 *
 */

/* View listeners */

#include "oslistener.inl"
#include "osgui.inl"
#include "osscrolls.inl"
#include "osgui_osx.inl"
#include <core/event.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

void _oslistener_init(ViewListeners *listeners)
{
    cassert_no_null(listeners);
    bmem_zero(listeners, ViewListeners);
    /*listeners->is_dirty = YES;*/
    listeners->is_enabled = YES;
}

/*---------------------------------------------------------------------------*/

void _oslistener_release(ViewListeners *listeners)
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
    listener_destroy(&listeners->OnKeyUp);
    listener_destroy(&listeners->OnKeyDown);
}

/*---------------------------------------------------------------------------*/

void _oslistener_set_enabled(ViewListeners *listeners, bool_t is_enabled)
{
    cassert_no_null(listeners);
    listeners->is_enabled = (is_enabled == TRUE) ? YES : NO;
}

/*---------------------------------------------------------------------------*/

static void i_mouse_position_in_view_coordinates(const NSView *view, const NSPoint mouse_location_in_window, real32_t *x, real32_t *y)
{
    NSPoint local_point;
    cassert_no_null(view);
    cassert_no_null(x);
    cassert_no_null(y);
    local_point = [view convertPoint:mouse_location_in_window fromView:nil];
    *x = (real32_t)local_point.x;
    *y = (real32_t)local_point.y;
    /* Note: The y coordinate in the returned point starts from a base of 1, not 0. */
    /* *y -= 1.f; */
    /* *y = (real32_t)[view frame].size.height - *y - 1.f; */
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_position_in_view_coordinates(const NSView *view, const NSPoint mouse_location_in_window, real32_t *x, real32_t *y)
{
    i_mouse_position_in_view_coordinates(view, mouse_location_in_window, x, y);
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_enter(const NSView *view, NSEvent *theEvent, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(theEvent);
    if (listeners->is_enabled && listeners->OnEnter != NULL)
    {
        EvMouse params;
        i_mouse_position_in_view_coordinates(view, [theEvent locationInWindow], &params.lx, &params.ly);
        params.button = ENUM_MAX(gui_mouse_t);
        params.count = 0;
        params.x = params.lx;
        params.y = params.ly;
        params.modifiers = osgui_modifiers([theEvent modifierFlags]);
        params.tag = 0;

        if (scroll != NULL)
        {
            params.x += osscrolls_x_pos(scroll);
            params.y += osscrolls_y_pos(scroll);
        }
        listener_event(listeners->OnEnter, ekGUI_EVENT_ENTER, (OSView *)view, &params, NULL, OSView, EvMouse, void);
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_exit(const NSView *view, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    if (listeners->is_enabled && listeners->OnExit != NULL)
        listener_event(listeners->OnExit, ekGUI_EVENT_EXIT, (OSView *)view, NULL, NULL, OSView, void, void);
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_moved(const NSView *view, NSEvent *theEvent, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(theEvent);
    if (listeners->is_enabled && listeners->OnMoved != NULL)
    {
        real32_t x, y;
        /*NSSize size = [view frame].size;*/
        i_mouse_position_in_view_coordinates(view, [theEvent locationInWindow], &x, &y);
        /*if (x >= 0.f && x < size.width && y >= 0.f && y < size.height)*/
        {
            EvMouse params;
            params.lx = x;
            params.ly = y;
            params.button = ENUM_MAX(gui_mouse_t);
            params.count = 0;
            params.x = params.lx;
            params.y = params.ly;
            params.modifiers = osgui_modifiers([theEvent modifierFlags]);
            params.tag = 0;

            if (scroll != NULL)
            {
                params.x += osscrolls_x_pos(scroll);
                params.y += osscrolls_y_pos(scroll);
            }
            listener_event(listeners->OnMoved, ekGUI_EVENT_MOVED, (OSView *)view, &params, NULL, OSView, EvMouse, void);
        }
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_down(const NSView *view, NSEvent *theEvent, const gui_mouse_t button, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(theEvent);
    if (listeners->is_enabled && listeners->OnDown != NULL)
    {
        EvMouse params;
        i_mouse_position_in_view_coordinates(view, [theEvent locationInWindow], &params.lx, &params.ly);
        params.button = button;
        params.count = 0;
        params.x = params.lx;
        params.y = params.ly;
        params.modifiers = osgui_modifiers([theEvent modifierFlags]);
        params.tag = 0;

        if (scroll != NULL)
        {
            params.x += osscrolls_x_pos(scroll);
            params.y += osscrolls_y_pos(scroll);
        }
        listener_event(listeners->OnDown, ekGUI_EVENT_DOWN, (OSView *)view, &params, NULL, OSView, EvMouse, void);
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_up(const NSView *view, NSEvent *theEvent, const gui_mouse_t button, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(theEvent);
    if (listeners->is_enabled == YES)
    {
        real32_t x, y;
        cassert_no_null(theEvent);
        i_mouse_position_in_view_coordinates(view, [theEvent locationInWindow], &x, &y);

        if (listeners->OnUp != NULL)
        {
            EvMouse params;
            params.lx = x;
            params.ly = y;
            params.button = button;
            params.count = 0;
            params.x = params.lx;
            params.y = params.ly;
            params.modifiers = osgui_modifiers([theEvent modifierFlags]);
            params.tag = 0;

            if (scroll != NULL)
            {
                params.x += osscrolls_x_pos(scroll);
                params.y += osscrolls_y_pos(scroll);
            }
            listener_event(listeners->OnUp, ekGUI_EVENT_UP, (OSView *)view, &params, NULL, OSView, EvMouse, void);
        }

        if (listeners->OnClick != NULL)
        {
            EvMouse params;
            params.x = x;
            params.y = y;
            params.button = button;
            params.count = (uint32_t)[theEvent clickCount];
            params.modifiers = osgui_modifiers([theEvent modifierFlags]);
            params.tag = 0;
            listener_event(listeners->OnClick, ekGUI_EVENT_CLICK, (OSView *)view, &params, NULL, OSView, EvMouse, void);
        }
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_dragged2(const NSView *view, NSEvent *theEvent, const gui_mouse_t button, const OSScrolls *scroll, Listener *OnDrag_listener)
{
    cassert_no_null(theEvent);
    if (OnDrag_listener != NULL)
    {
        EvMouse params;
        i_mouse_position_in_view_coordinates(view, [theEvent locationInWindow], &params.lx, &params.ly);
        params.button = button;
        params.count = 0;
        params.x = params.lx;
        params.y = params.ly;
        params.modifiers = osgui_modifiers([theEvent modifierFlags]);
        params.tag = 0;

        if (scroll != NULL)
        {
            params.x += osscrolls_x_pos(scroll);
            params.y += osscrolls_y_pos(scroll);
        }
        listener_event(OnDrag_listener, ekGUI_EVENT_DRAG, (OSView *)view, &params, NULL, OSView, EvMouse, void);
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_dragged(const NSView *view, NSEvent *theEvent, const gui_mouse_t button, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    if (listeners->is_enabled == YES)
        _oslistener_mouse_dragged2(view, theEvent, button, scroll, listeners->OnDrag);
}

/*---------------------------------------------------------------------------*/

void _oslistener_scroll_whell(const NSView *view, NSEvent *theEvent, const OSScrolls *scroll, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    if (listeners->OnWheel != NULL && listeners->is_enabled == YES)
    {
        EvWheel params;
        cassert_no_null(theEvent);
        i_mouse_position_in_view_coordinates(view, [theEvent locationInWindow], &params.x, &params.y);
        params.dx = (real32_t)[theEvent deltaX];
        params.dy = (real32_t)[theEvent deltaY];
        params.dz = (real32_t)[theEvent deltaZ];
        if (scroll != NULL)
        {
            params.x += osscrolls_x_pos(scroll);
            params.y += osscrolls_y_pos(scroll);
        }
        listener_event(listeners->OnWheel, ekGUI_EVENT_WHEEL, (OSView *)view, &params, NULL, OSView, EvWheel, void);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_launch_key_event(const NSView *view, const gui_event_t evtype, vkey_t virtual_key_code, const uint32_t modifiers, Listener *OnKey)
{
    EvKey params;
    cassert_no_null(OnKey);
    params.key = virtual_key_code;
    params.modifiers = modifiers;
    listener_event(OnKey, evtype, (OSView *)view, &params, NULL, OSView, EvKey, void);
}

/*---------------------------------------------------------------------------*/

static void i_process_key_event(const NSView *view, NSEvent *theEvent, const gui_event_t evtype, Listener *OnKey)
{
    vkey_t vkey = osgui_vkey([theEvent keyCode]);
    if (vkey != ENUM_MAX(vkey_t))
    {
        uint32_t modifiers = osgui_modifiers((NSUInteger)[theEvent modifierFlags]);
        i_launch_key_event(view, evtype, vkey, modifiers, OnKey);
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_key_down(const NSView *view, NSEvent *theEvent, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    if (listeners->is_enabled == YES && listeners->OnKeyDown != NULL)
        i_process_key_event(view, theEvent, ekGUI_EVENT_KEYDOWN, listeners->OnKeyDown);
}

/*---------------------------------------------------------------------------*/

void _oslistener_key_up(const NSView *view, NSEvent *theEvent, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    if (listeners->is_enabled == YES && listeners->OnKeyUp != NULL)
        i_process_key_event(view, theEvent, ekGUI_EVENT_KEYUP, listeners->OnKeyUp);
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_flags_event(const NSView *view, NSUInteger flags, const bool_t press, const bool_t prevpress, const vkey_t key, Listener *OnKeyDown, Listener *OnKeyUp)
{
    if (press != prevpress)
    {
        if (press == TRUE)
        {
            if (OnKeyDown != NULL)
            {
                uint32_t modifiers = osgui_modifiers(flags);
                i_launch_key_event(view, ekGUI_EVENT_KEYDOWN, key, modifiers, OnKeyDown);
            }
        }
        else
        {
            if (OnKeyUp != NULL)
            {
                uint32_t modifiers = osgui_modifiers(flags);
                i_launch_key_event(view, ekGUI_EVENT_KEYUP, key, modifiers, OnKeyUp);
            }
        }
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_key_flags_changed(const NSView *view, NSEvent *theEvent, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(theEvent);
    if (listeners->is_enabled == YES)
    {
        NSUInteger flags;
        bool_t rshift, rctrl, rcommand, ralt;
        bool_t lshift, lctrl, lcommand, lalt;
        bool_t prshift, prctrl, prcommand, pralt;
        bool_t plshift, plctrl, plcommand, plalt;
        flags = [theEvent modifierFlags];
        osgui_modifier_flags(flags, &rshift, &rctrl, &rcommand, &ralt, &lshift, &lctrl, &lcommand, &lalt);
        osgui_modifier_flags(listeners->modifier_flags, &prshift, &prctrl, &prcommand, &pralt, &plshift, &plctrl, &plcommand, &plalt);
        i_flags_event(view, flags, rshift, prshift, ekKEY_RSHIFT, listeners->OnKeyDown, listeners->OnKeyUp);
        i_flags_event(view, flags, lshift, plshift, ekKEY_LSHIFT, listeners->OnKeyDown, listeners->OnKeyUp);
        i_flags_event(view, flags, rctrl, prctrl, ekKEY_RCTRL, listeners->OnKeyDown, listeners->OnKeyUp);
        i_flags_event(view, flags, lctrl, plctrl, ekKEY_LCTRL, listeners->OnKeyDown, listeners->OnKeyUp);
        i_flags_event(view, flags, rcommand, prcommand, ekKEY_RWIN, listeners->OnKeyDown, listeners->OnKeyUp);
        i_flags_event(view, flags, lcommand, plcommand, ekKEY_LWIN, listeners->OnKeyDown, listeners->OnKeyUp);
        i_flags_event(view, flags, ralt, pralt, ekKEY_RALT, listeners->OnKeyDown, listeners->OnKeyUp);
        i_flags_event(view, flags, lalt, plalt, ekKEY_LALT, listeners->OnKeyDown, listeners->OnKeyUp);
        listeners->modifier_flags = flags;
    }
}
