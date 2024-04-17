/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osupdown.c
 *
 */

/* Operating System native updown */

#include "osupdown.h"
#include "osupdown.inl"
#include "osgui.inl"
#include "osglobals_gtk.inl"
#include "oscontrol_gtk.inl"
#include "ospanel_gtk.inl"
#include "oswindow_gtk.inl"
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

typedef enum _udstate_t
{
    ekNORMAL = 0,
    ekUP_HOVER,
    ekDOWN_HOVER,
    ekUP_CLICK,
    ekDOWN_CLICK
} udstate_t;

struct _osupdown_t
{
    OSControl control;
    udstate_t state;
    GtkBorder padding;
    Listener *OnClick;
};

/*---------------------------------------------------------------------------*/

static gboolean i_OnDraw(GtkWidget *widget, cairo_t *cr, OSUpDown *updown)
{
    GtkStyleContext *ctx = osglobals_button_context();
    int w = gtk_widget_get_allocated_width(widget);
    int h = gtk_widget_get_allocated_height(widget);
    GtkStateFlags upstate = gtk_widget_get_state_flags(widget);
    GtkStateFlags downstate = upstate;
    int aw = w / 3;
    int ax = (w - aw) / 2;
    int ay = (h / 2 - aw) / 2;
    cassert_no_null(updown);

    switch (updown->state)
    {
    case ekUP_HOVER:
        upstate = GTK_STATE_FLAG_PRELIGHT;
        break;
    case ekDOWN_HOVER:
        downstate = GTK_STATE_FLAG_PRELIGHT;
        break;
    case ekUP_CLICK:
        upstate = GTK_STATE_FLAG_PRELIGHT | GTK_STATE_FLAG_FOCUSED | GTK_STATE_FLAG_ACTIVE;
        break;
    case ekDOWN_CLICK:
        downstate = GTK_STATE_FLAG_PRELIGHT | GTK_STATE_FLAG_FOCUSED | GTK_STATE_FLAG_ACTIVE;
        break;
    default:
        break;
    }

    gtk_style_context_save(ctx);
    gtk_style_context_set_state(ctx, upstate);
    gtk_render_frame(ctx, cr, 0, 0, w, (h / 2) + 1);
    gtk_style_context_set_state(ctx, downstate);
    gtk_render_frame(ctx, cr, 0, (h / 2), w, (h / 2));
    gtk_style_context_restore(ctx);
    gtk_render_arrow(ctx, cr, 0, ax, ay, aw);
    gtk_render_arrow(ctx, cr, G_PI, ax, (h / 2) + ay, aw);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

static void i_OnClick(OSUpDown *updown, const uint32_t index)
{
    if (updown->OnClick != NULL)
    {
        EvButton params;
        params.text = "";
        params.state = ekGUI_ON;
        params.index = index;
        listener_event(updown->OnClick, ekGUI_EVENT_UPDOWN, updown, &params, NULL, OSUpDown, EvButton, void);
    }
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnPress(GtkWidget *widget, GdkEventButton *event, OSUpDown *updown)
{
    if (_oswindow_mouse_down(OSControlPtr(updown)) == TRUE)
    {
        int w = gtk_widget_get_allocated_height(widget);
        int h = gtk_widget_get_allocated_height(widget);
        cassert_no_null(updown);
        if (event->x < 0 || event->x > w || event->y < 0 || event->y > h)
        {
            updown->state = ekNORMAL;
        }
        else if (event->y < h / 2)
        {
            if (event->type == GDK_BUTTON_RELEASE)
            {
                updown->state = ekUP_HOVER;
            }
            else
            {
                updown->state = ekUP_CLICK;
                i_OnClick(updown, 0);
            }
        }
        else
        {
            if (event->type == GDK_BUTTON_RELEASE)
            {
                updown->state = ekDOWN_HOVER;
            }
            else
            {
                updown->state = ekDOWN_CLICK;
                i_OnClick(updown, 1);
            }
        }

        gtk_widget_queue_draw(widget);
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnMove(GtkWidget *widget, GdkEventMotion *event, OSUpDown *updown)
{
    int h = gtk_widget_get_allocated_height(widget);
    cassert_no_null(updown);
    if (event->y < h / 2)
        updown->state = ekUP_HOVER;
    else
        updown->state = ekDOWN_HOVER;
    gtk_widget_queue_draw(widget);
    return TRUE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnExit(GtkWidget *widget, GdkEventCrossing *event, OSUpDown *updown)
{
    cassert_no_null(updown);
    unref(event);
    updown->state = ekNORMAL;
    gtk_widget_queue_draw(widget);
    return TRUE;
}

/*---------------------------------------------------------------------------*/

OSUpDown *osupdown_create(const uint32_t flags)
{
    OSUpDown *updown = heap_new0(OSUpDown);
    GtkWidget *widget = gtk_drawing_area_new();
    unref(flags);
    _oscontrol_init(&updown->control, ekGUI_TYPE_UPDOWN, widget, widget, TRUE);
    gtk_widget_add_events(widget, GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK);
    g_signal_connect(widget, "motion-notify-event", G_CALLBACK(i_OnMove), (gpointer)updown);
    g_signal_connect(widget, "leave-notify-event", G_CALLBACK(i_OnExit), (gpointer)updown);
    g_signal_connect(widget, "button-press-event", G_CALLBACK(i_OnPress), (gpointer)updown);
    g_signal_connect(widget, "button-release-event", G_CALLBACK(i_OnPress), (gpointer)updown);
    g_signal_connect(widget, "draw", G_CALLBACK(i_OnDraw), (gpointer)updown);
    osglobals_register_entry(&updown->padding);
    return updown;
}

/*---------------------------------------------------------------------------*/

void osupdown_destroy(OSUpDown **updown)
{
    cassert_no_null(updown);
    cassert_no_null(*updown);
    listener_destroy(&(*updown)->OnClick);
    _oscontrol_destroy(*(OSControl **)updown);
    heap_delete(updown, OSUpDown);
}

/*---------------------------------------------------------------------------*/

void osupdown_OnClick(OSUpDown *updown, Listener *listener)
{
    cassert_no_null(updown);
    listener_update(&updown->OnClick, listener);
}

/*---------------------------------------------------------------------------*/

void osupdown_tooltip(OSUpDown *updown, const char_t *text)
{
    cassert_no_null(updown);
    gtk_widget_set_tooltip_text(updown->control.widget, (const gchar *)text);
}

/*---------------------------------------------------------------------------*/

void osupdown_attach(OSUpDown *updown, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)updown);
}

/*---------------------------------------------------------------------------*/

void osupdown_detach(OSUpDown *updown, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)updown);
}

/*---------------------------------------------------------------------------*/

void osupdown_visible(OSUpDown *updown, const bool_t is_visible)
{
    _oscontrol_set_visible((OSControl *)updown, is_visible);
}

/*---------------------------------------------------------------------------*/

void osupdown_enabled(OSUpDown *updown, const bool_t is_enabled)
{
    _oscontrol_set_enabled((OSControl *)updown, is_enabled);
}

/*---------------------------------------------------------------------------*/

void osupdown_size(const OSUpDown *updown, real32_t *width, real32_t *height)
{
    uint32_t eheight = osglobals_entry_height();
    cassert_no_null(width);
    cassert_no_null(height);
    *height = (real32_t)eheight;
    if (eheight > 32)
        *width = 32;
    else
        *width = *height;
    unref(updown);
}

/*---------------------------------------------------------------------------*/

void osupdown_origin(const OSUpDown *updown, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)updown, x, y);
}

/*---------------------------------------------------------------------------*/

void osupdown_frame(OSUpDown *updown, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)updown, x, y, width, height);
}
