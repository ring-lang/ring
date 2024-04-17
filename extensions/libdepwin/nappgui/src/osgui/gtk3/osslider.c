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
#include "osslider.inl"
#include "osgui.inl"
#include "osgui_gtk.inl"
#include "oscontrol_gtk.inl"
#include "ospanel_gtk.inl"
#include "oswindow_gtk.inl"
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _osslider_t
{
    OSControl control;
    gui_size_t size;
    bool_t launch_event;
    bool_t discrete;
    uint32_t flags;
    Listener *OnMoved;
};

/*---------------------------------------------------------------------------*/

static gboolean i_OnMoved(GtkRange *range, GtkScrollType step, double value, OSSlider *slider)
{
    cassert_unref(slider->control.widget == GTK_WIDGET(range), range);
    unref(step);

    if (slider->launch_event == TRUE && slider->OnMoved != NULL)
    {
        EvSlider params;
        params.pos = value;
        params.incr = 0.f;
        params.step = UINT32_MAX;

        if (value < 0)
            params.pos = 0;
        else if (value > 1)
            params.pos = 1;

        listener_event(slider->OnMoved, ekGUI_EVENT_SLIDER, slider, &params, NULL, OSSlider, EvSlider, void);
        return slider->discrete;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnPressed(GtkWidget *widget, GdkEvent *event, OSSlider *slider)
{
    cassert_no_null(slider);
    unref(widget);
    unref(event);
    if (_oswindow_mouse_down(OSControlPtr(slider)) == TRUE)
        return FALSE;
    return TRUE;
}

/*---------------------------------------------------------------------------*/

OSSlider *osslider_create(const uint32_t flags)
{
    OSSlider *slider = heap_new0(OSSlider);
    GtkOrientation o = slider_get_type(flags) == ekSLIDER_HORZ ? GTK_ORIENTATION_HORIZONTAL : GTK_ORIENTATION_VERTICAL;
    GtkWidget *widget = gtk_scale_new_with_range(o, 0., 1., 0.1);
    gtk_scale_set_draw_value(GTK_SCALE(widget), FALSE);
    gtk_range_set_increments(GTK_RANGE(widget), .1, .1);
    g_signal_connect(widget, "button-press-event", G_CALLBACK(i_OnPressed), (gpointer)slider);
    g_signal_connect(widget, "change-value", G_CALLBACK(i_OnMoved), (gpointer)slider);

    /*
    if (o == GTK_ORIENTATION_HORIZONTAL)
       _oscontrol_widget_set_css(widget, "scale {min-height:5px;padding-left:5px;padding-right:5px}");
    else
       _oscontrol_widget_set_css(widget, "scale {min-height:5px;padding-top:5px;padding-bottom:5px}");
    */

    _oscontrol_init(&slider->control, ekGUI_TYPE_SLIDER, widget, widget, TRUE);
    slider->size = ENUM_MAX(gui_size_t);
    slider->flags = flags;
    slider->launch_event = TRUE;
    slider->discrete = FALSE;
    return slider;
}

/*---------------------------------------------------------------------------*/

void osslider_destroy(OSSlider **slider)
{
    cassert_no_null(slider);
    cassert_no_null(*slider);
    listener_destroy(&(*slider)->OnMoved);
    _oscontrol_destroy(*(OSControl **)slider);
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
    cassert_no_null(slider);
    gtk_widget_set_tooltip_text(slider->control.widget, (const gchar *)text);
}

/*---------------------------------------------------------------------------*/

void osslider_tickmarks(OSSlider *slider, const uint32_t num_tickmarks, const bool_t tickmarks_at_left_top)
{
    gdouble steps = 0.1;
    cassert_no_null(slider);
    cassert(num_tickmarks > 1);

    if (num_tickmarks != UINT32_MAX)
    {
        steps = 1. / (num_tickmarks - 1.);
        slider->discrete = TRUE;
    }
    else
    {
        slider->discrete = FALSE;
    }

    gtk_range_set_increments(GTK_RANGE(slider->control.widget), steps, steps);
    unref(tickmarks_at_left_top);
}

/*---------------------------------------------------------------------------*/

void osslider_position(OSSlider *slider, const real32_t position)
{
    cassert_no_null(slider);
    slider->launch_event = FALSE;
    gtk_range_set_value(GTK_RANGE(slider->control.widget), (gdouble)position);
    slider->launch_event = TRUE;
}

/*---------------------------------------------------------------------------*/

real32_t osslider_get_position(const OSSlider *slider)
{
    cassert_no_null(slider);
    return (real32_t)gtk_range_get_value(GTK_RANGE(slider->control.widget));
}

/*---------------------------------------------------------------------------*/

void osslider_bounds(const OSSlider *slider, const real32_t length, const gui_size_t knob_size, real32_t *width, real32_t *height)
{
    GtkRequisition s;
    cassert_no_null(slider);
    cassert_no_null(width);
    cassert_no_null(height);
    cassert_unref(knob_size == ekGUI_SIZE_REGULAR, knob_size);
    gtk_widget_get_preferred_size(slider->control.widget, &s, NULL);

    switch (slider_get_type(slider->flags))
    {
    case ekSLIDER_HORZ:
        *width = length;
        *height = (real32_t)s.height;
        break;
    case ekSLIDER_VERT:
        *width = (real32_t)s.width;
        *height = length;
        break;
        cassert_default();
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

void osslider_visible(OSSlider *slider, const bool_t is_visible)
{
    _oscontrol_set_visible((OSControl *)slider, is_visible);
}

/*---------------------------------------------------------------------------*/

void osslider_enabled(OSSlider *slider, const bool_t is_enabled)
{
    _oscontrol_set_enabled((OSControl *)slider, is_enabled);
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
    _oscontrol_set_frame((OSControl *)slider, x, y, width, height);
}
