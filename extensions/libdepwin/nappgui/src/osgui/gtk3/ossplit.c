/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ossplit.c
 *
 */

/* Operating System split view */

#include "ossplit.h"
#include "oslistener.inl"
#include "ossplit_gtk.inl"
#include "ospanel_gtk.inl"
#include "ostext_gtk.inl"
#include "osview_gtk.inl"
#include "osgui_gtk.inl"
#include "oscontrol_gtk.inl"
#include <geom2d/r2d.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _ossplit_t
{
    OSControl control;
    split_flag_t flags;
    R2Df divrect;
    bool_t left_button;
    bool_t inside_rect;
    Listener *OnDrag;
};

/*---------------------------------------------------------------------------*/

static void i_set_capture(GtkWidget *widget, OSSplit *split)
{
    if (GTK_IS_CONTAINER(widget) == TRUE && GTK_IS_SCROLLED_WINDOW(widget) == FALSE)
    {
        gtk_container_foreach(GTK_CONTAINER(widget), (GtkCallback)i_set_capture, split);
    }
    else
    {
        OSControl *control = (OSControl *)g_object_get_data(G_OBJECT(widget), "OSControl");
        if (control != NULL)
        {
            if (control->type == ekGUI_TYPE_PANEL)
                _ospanel_set_capture((OSPanel *)control, (OSControl *)split);
            else if (control->type == ekGUI_TYPE_TEXTVIEW)
                _ostext_set_capture((OSText *)control, (OSControl *)split);
            else if (control->type == ekGUI_TYPE_CUSTOMVIEW)
                _osview_set_capture((OSView *)control, (OSControl *)split);
        }
    }
}

/*---------------------------------------------------------------------------*/

static void i_release_capture(GtkWidget *widget, gpointer data)
{
    unref(data);
    if (GTK_IS_CONTAINER(widget) == TRUE && GTK_IS_SCROLLED_WINDOW(widget) == FALSE)
    {
        gtk_container_foreach(GTK_CONTAINER(widget), i_release_capture, NULL);
    }
    else
    {
        OSControl *control = (OSControl *)g_object_get_data(G_OBJECT(widget), "OSControl");
        if (control != NULL)
        {
            if (control->type == ekGUI_TYPE_PANEL)
                _ospanel_release_capture((OSPanel *)control);
            else if (control->type == ekGUI_TYPE_TEXTVIEW)
                _ostext_release_capture((OSText *)control);
            else if (control->type == ekGUI_TYPE_CUSTOMVIEW)
                _osview_release_capture((OSView *)control);
        }
    }
}

/*---------------------------------------------------------------------------*/
/* https://stackoverflow.com/questions/63647507/gdkeventmotion-x-and-y-coordinates-appears-to-refer-to-location-within-a-differe */
static void i_mouse_pos(GtkWidget *widget, GdkEventMotion *event, real32_t *x, real32_t *y)
{
    int mouse_x = 0;
    int mouse_y = 0;
    cassert_no_null(x);
    cassert_no_null(y);
    gdk_window_get_origin(gtk_widget_get_window(widget), &mouse_x, &mouse_y);
    *x = (real32_t)(event->x_root - mouse_x);
    *y = (real32_t)(event->y_root - mouse_y);
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnMove(GtkWidget *widget, GdkEventMotion *event, OSSplit *view)
{
    cassert(widget == view->control.widget);
    if (view->left_button == TRUE)
    {
        if (view->OnDrag != NULL)
        {
            EvMouse params;
            i_mouse_pos(widget, event, &params.x, &params.y);
            params.button = ekGUI_MOUSE_LEFT;
            params.count = 0;
            params.modifiers = 0;
            params.tag = 0;
            listener_event(view->OnDrag, ekGUI_EVENT_DRAG, view, &params, NULL, OSSplit, EvMouse, void);
        }
    }
    else
    {
        real32_t mouse_x = 0;
        real32_t mouse_y = 0;
        i_mouse_pos(widget, event, &mouse_x, &mouse_y);

        if (r2d_containsf(&view->divrect, mouse_x, mouse_y) == TRUE)
        {
            if (view->inside_rect == FALSE)
            {
                i_set_capture(widget, view);
                view->inside_rect = TRUE;
            }

            if (split_get_type(view->flags) == ekSPLIT_HORZ)
                _osgui_ns_resize_cursor(widget);
            else
                _osgui_ew_resize_cursor(widget);
        }
        else
        {
            if (view->inside_rect == TRUE)
            {
                i_release_capture(widget, NULL);
                view->inside_rect = FALSE;
            }
            _osgui_default_cursor(widget);
        }
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnPressed(GtkWidget *widget, GdkEventButton *event, OSSplit *view)
{
    _ossplit_OnPress(view, event);
    unref(widget);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnRelease(GtkWidget *widget, GdkEventButton *event, OSSplit *view)
{
    unref(widget);
    unref(event);

    view->left_button = FALSE;
    if (view->inside_rect == TRUE)
    {
        i_release_capture(widget, NULL);
        view->inside_rect = FALSE;
    }

    _osgui_default_cursor(widget);
    return TRUE;
}

/*---------------------------------------------------------------------------*/

OSSplit *ossplit_create(const uint32_t flags)
{
    OSSplit *view = heap_new0(OSSplit);
    GtkWidget *widget = gtk_layout_new(NULL, NULL);
    gint moved_signal = 0;
    gint pressed_signal = 0;
    gint release_signal = 0;
    view->flags = flags;
    _oscontrol_init(&view->control, ekGUI_TYPE_SPLITVIEW, widget, widget, TRUE);
    _oslistener_signal(view->control.widget, TRUE, &moved_signal, GDK_POINTER_MOTION_MASK, "motion-notify-event", G_CALLBACK(i_OnMove), (gpointer)view);
    _oslistener_signal(view->control.widget, TRUE, &pressed_signal, GDK_BUTTON_PRESS_MASK, "button-press-event", G_CALLBACK(i_OnPressed), (gpointer)view);
    _oslistener_signal(view->control.widget, TRUE, &release_signal, GDK_BUTTON_RELEASE_MASK, "button-release-event", G_CALLBACK(i_OnRelease), (gpointer)view);
    return view;
}

/*---------------------------------------------------------------------------*/

void ossplit_destroy(OSSplit **view)
{
    cassert_no_null(view);
    cassert_no_null(*view);
    listener_destroy(&(*view)->OnDrag);
    _oscontrol_destroy(&(*view)->control);
    heap_delete(view, OSSplit);
}

/*---------------------------------------------------------------------------*/

void ossplit_attach_control(OSSplit *view, OSControl *control)
{
    cassert_no_null(view);
    _oscontrol_attach_to_parent(control, view->control.widget);
}

/*---------------------------------------------------------------------------*/

void ossplit_detach_control(OSSplit *view, OSControl *control)
{
    cassert_no_null(view);
    _oscontrol_detach_from_parent(control, view->control.widget);
}

/*---------------------------------------------------------------------------*/

void ossplit_OnDrag(OSSplit *view, Listener *listener)
{
    cassert_no_null(view);
    listener_update(&view->OnDrag, listener);
}

/*---------------------------------------------------------------------------*/

void ossplit_track_area(OSSplit *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    cassert_no_null(view);
    view->divrect.pos.x = x;
    view->divrect.pos.y = y;
    view->divrect.size.width = width;
    view->divrect.size.height = height;
}

/*---------------------------------------------------------------------------*/

void ossplit_attach(OSSplit *view, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)view);
}

/*---------------------------------------------------------------------------*/

void ossplit_detach(OSSplit *view, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)view);
}

/*---------------------------------------------------------------------------*/

void ossplit_visible(OSSplit *view, const bool_t is_visible)
{
    _oscontrol_set_visible((OSControl *)view, is_visible);
}

/*---------------------------------------------------------------------------*/

void ossplit_enabled(OSSplit *view, const bool_t is_enabled)
{
    _oscontrol_set_enabled((OSControl *)view, is_enabled);
}

/*---------------------------------------------------------------------------*/

void ossplit_size(const OSSplit *view, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)view, width, height);
}

/*---------------------------------------------------------------------------*/

void ossplit_origin(const OSSplit *view, real32_t *x, real32_t *y)
{
    unref(view);
    unref(x);
    unref(y);
    cassert_msg(FALSE, "Not implemented");
}

/*---------------------------------------------------------------------------*/

void ossplit_frame(OSSplit *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)view, x, y, width, height);
}

/*---------------------------------------------------------------------------*/

void _ossplit_OnPress(OSSplit *view, GdkEventButton *event)
{
    cassert_no_null(view);
    cassert_no_null(event);

    /* Left button */
    if (event->button == 1)
    {
        if (view->inside_rect == TRUE)
            view->left_button = TRUE;
    }
}
