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
#include "osgui_gtk.inl"
#include <core/event.h>
#include <sewer/cassert.h>
#include <sewer/bmem.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

/*---------------------------------------------------------------------------*/

void _oslistener_init(ViewListeners *listeners)
{
    cassert_no_null(listeners);
    bmem_zero(listeners, ViewListeners);
    listeners->is_enabled = TRUE;
    listeners->button = ENUM_MAX(gui_mouse_t);
}

/*---------------------------------------------------------------------------*/

void _oslistener_remove(ViewListeners *listeners)
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

void _oslistener_signal(GtkWidget *widget, bool_t add, gint *signal_id, gint signal_mask, const gchar *signal_name, GCallback callback, gpointer callback_data)
{
    gboolean is_realized = gtk_widget_get_realized(widget);
#if defined(__DEBUG__)
    const gchar *type = G_OBJECT_TYPE_NAME(widget);
#endif
    cassert(gtk_widget_get_has_window(widget) == TRUE);

    /*
     * gtk_widget_set_events(): This function must be called while a widget is unrealized.
     * Consider gtk_widget_add_events() for widgets that are already realized, or if you
     * want to preserve the existing event mask. This function can’t be used with widgets
     * that have no window. (See gtk_widget_get_has_window()). To get events on those widgets,
     * place them inside a GtkEventBox and receive events on the event box.
     */
    if (is_realized == FALSE)
    {
        if (add == TRUE)
        {
            if (*signal_id == 0)
            {
                gtk_widget_add_events(widget, signal_mask);
                *signal_id = g_signal_connect(G_OBJECT(widget), signal_name, callback, callback_data);
            }
        }
        else
        {
            /* We want to delete the signal */
            if (*signal_id != 0)
            {
                /* We delete the event mask */
                gint emask = gtk_widget_get_events(widget);
                emask &= ~signal_mask;
                gtk_widget_set_events(widget, emask);
                g_signal_handler_disconnect(G_OBJECT(widget), *signal_id);
                *signal_id = 0;
            }
        }
    }
    /* Widget is realized */
    else
    {
        if (add == TRUE)
        {
            if (*signal_id == 0)
            {
                gtk_widget_add_events(widget, signal_mask);
                *signal_id = g_signal_connect(G_OBJECT(widget), signal_name, callback, callback_data);
            }
        }
        /* If widget */
        else
        {
            /* We want to delete the signal */
            if (*signal_id != 0)
            {
                /* We can't delete the event mask if widget is realized */
                g_signal_handler_disconnect(G_OBJECT(widget), *signal_id);
                *signal_id = 0;
            }
        }
    }

#if defined(__DEBUG__)
    unref(type);
#endif
}

/*---------------------------------------------------------------------------*/

void _oslistener_redraw(OSControl *sender, EvDraw *params, ViewListeners *listeners)
{
    cassert_no_null(sender);
    cassert(sender->type == ekGUI_TYPE_CUSTOMVIEW);
    cassert_no_null(listeners);
    if (listeners->OnDraw != NULL)
        listener_event(listeners->OnDraw, ekGUI_EVENT_DRAW, sender, params, NULL, OSControl, EvDraw, void);
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_enter(OSControl *sender, GdkEventCrossing *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(event);
    if (listeners->OnEnter != NULL)
    {
        EvMouse params;
        params.lx = (real32_t)event->x;
        params.ly = (real32_t)event->y;
        params.x = params.lx + scroll_x;
        params.y = params.ly + scroll_y;
        params.button = ENUM_MAX(gui_mouse_t);
        params.count = 0;
        params.modifiers = _osgui_modifiers(event->state);
        params.tag = 0;
        listener_event(listeners->OnEnter, ekGUI_EVENT_ENTER, sender, &params, NULL, OSControl, EvMouse, void);
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_exit(OSControl *sender, GdkEventCrossing *event, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    unref(event);
    if (listeners->OnExit != NULL)
        listener_event(listeners->OnExit, ekGUI_EVENT_EXIT, sender, NULL, NULL, OSControl, void, void);
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_moved(OSControl *sender, GdkEventMotion *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(sender);
    cassert_no_null(event);
    if (listeners->is_enabled == TRUE)
    {
        if (listeners->button != ENUM_MAX(gui_mouse_t))
        {
            if (listeners->OnDrag != NULL)
            {
                EvMouse params;
                params.lx = (real32_t)event->x;
                params.ly = (real32_t)event->y;
                params.x = params.lx + scroll_x;
                params.y = params.ly + scroll_y;
                params.button = listeners->button;
                params.count = 0;
                params.modifiers = _osgui_modifiers(event->state);
                params.tag = 0;
                listener_event(listeners->OnDrag, ekGUI_EVENT_DRAG, sender, &params, NULL, OSControl, EvMouse, void);
            }
        }
        else
        {
            if (listeners->OnMoved != NULL)
            {
                EvMouse params;
                params.lx = (real32_t)event->x;
                params.ly = (real32_t)event->y;
                params.x = params.lx + scroll_x;
                params.y = params.ly + scroll_y;
                params.button = ENUM_MAX(gui_mouse_t);
                params.count = 0;
                params.modifiers = _osgui_modifiers(event->state);
                params.tag = 0;
                listener_event(listeners->OnMoved, ekGUI_EVENT_MOVED, sender, &params, NULL, OSControl, EvMouse, void);
            }
        }
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_down(OSControl *sender, GdkEventButton *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(event);
    if (listeners->is_enabled == TRUE)
    {
        switch (event->button)
        {
        case 1:
            listeners->button = ekGUI_MOUSE_LEFT;
            break;
        case 2:
            listeners->button = ekGUI_MOUSE_MIDDLE;
            break;
        case 3:
            listeners->button = ekGUI_MOUSE_RIGHT;
            break;
        default:
            listeners->button = ekGUI_MOUSE_LEFT;
            break;
        }

        if (listeners->OnDown != NULL)
        {
            EvMouse params;
            params.lx = (real32_t)event->x;
            params.ly = (real32_t)event->y;
            params.x = params.lx + scroll_x;
            params.y = params.ly + scroll_y;
            params.button = listeners->button;
            params.count = 0;
            params.modifiers = _osgui_modifiers(event->state);
            params.tag = 0;
            listener_event(listeners->OnDown, ekGUI_EVENT_DOWN, sender, &params, NULL, OSControl, EvMouse, void);
        }
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_mouse_up(OSControl *sender, GdkEventButton *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(sender);
    cassert_no_null(event);
    if (listeners->is_enabled == TRUE && listeners->button != ENUM_MAX(gui_mouse_t))
    {
        if (listeners->OnUp != NULL)
        {
            EvMouse params;
            params.lx = (real32_t)event->x;
            params.ly = (real32_t)event->y;
            params.x = params.lx + scroll_x;
            params.y = params.ly + scroll_y;
            params.button = listeners->button;
            params.count = 0;
            params.modifiers = _osgui_modifiers(event->state);
            params.tag = 0;
            listener_event(listeners->OnUp, ekGUI_EVENT_UP, sender, &params, NULL, OSControl, EvMouse, void);
        }

        if (listeners->OnClick != NULL)
        {
            EvMouse params;
            params.lx = (real32_t)event->x;
            params.ly = (real32_t)event->y;
            params.x = params.lx + scroll_x;
            params.y = params.ly + scroll_y;
            params.button = listeners->button;
            params.modifiers = _osgui_modifiers(event->state);
            params.tag = 0;

            switch (event->type)
            {
            case GDK_BUTTON_PRESS:
                params.count = 1;
                break;
            case GDK_2BUTTON_PRESS:
                params.count = 2;
                break;
            case GDK_3BUTTON_PRESS:
                params.count = 3;
                break;
            default:
                params.count = 1;
                break;
            }

            listener_event(listeners->OnClick, ekGUI_EVENT_CLICK, sender, &params, NULL, OSControl, EvMouse, void);
        }

        listeners->button = ENUM_MAX(gui_mouse_t);
    }
}

/*---------------------------------------------------------------------------*/

void _oslistener_scroll_whell(OSControl *sender, GdkEventScroll *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    cassert_no_null(sender);
    if (listeners->is_enabled == TRUE)
    {
        if (listeners->OnWheel != NULL)
        {
            EvWheel params;
            params.x = (real32_t)event->x + scroll_x;
            params.y = (real32_t)event->y + scroll_y;
            params.dx = 0;
            params.dy = event->direction == GDK_SCROLL_DOWN ? -1 : 1;
            params.dz = 0;
            listener_event(listeners->OnWheel, ekGUI_EVENT_WHEEL, sender, &params, NULL, OSControl, EvWheel, void);
        }
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_key_event(OSControl *sender, const uint32_t type, GdkEventKey *event, Listener *listener)
{
    cassert_no_null(sender);
    cassert_unref(sender->type == ekGUI_TYPE_CUSTOMVIEW, sender);
    if (listener != NULL)
    {
        vkey_t key = _osgui_vkey(event->keyval);
        uint32_t modifiers = _osgui_modifiers(event->state);
        if (key != ENUM_MAX(vkey_t))
        {
            EvKey params;
            params.key = key;
            params.modifiers = modifiers;
            listener_event(listener, type, sender, &params, NULL, OSControl, EvKey, void);
            return TRUE;
        }
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t _oslistener_key_down(OSControl *sender, GdkEventKey *event, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    return i_key_event(sender, ekGUI_EVENT_KEYDOWN, event, listeners->OnKeyDown);
}

/*---------------------------------------------------------------------------*/

bool_t _oslistener_key_up(OSControl *sender, GdkEventKey *event, ViewListeners *listeners)
{
    cassert_no_null(listeners);
    return i_key_event(sender, ekGUI_EVENT_KEYUP, event, listeners->OnKeyUp);
}

/*---------------------------------------------------------------------------*/
