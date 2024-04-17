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
#include "osprogress.inl"
#include "osgui.inl"
#include "osgui_gtk.inl"
#include "oscontrol_gtk.inl"
#include "osglobals_gtk.inl"
#include "ospanel_gtk.inl"
#include <sewer/cassert.h>
#include <core/heap.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _osprogress_t
{
    OSControl control;
    guint pulse_id;
};

/*---------------------------------------------------------------------------*/

OSProgress *osprogress_create(const uint32_t flags)
{
    OSProgress *progress = heap_new0(OSProgress);
    GtkWidget *widget = gtk_progress_bar_new();
    _oscontrol_init(&progress->control, ekGUI_TYPE_PROGRESS, widget, widget, TRUE);
    progress->pulse_id = UINT32_MAX;
    unref(flags);
    return progress;
}

/*---------------------------------------------------------------------------*/

void osprogress_destroy(OSProgress **progress)
{
    cassert_no_null(progress);
    cassert_no_null(*progress);
    if ((*progress)->pulse_id != UINT32_MAX)
        g_source_remove((*progress)->pulse_id);
    _oscontrol_destroy(*(OSControl **)progress);
    heap_delete(progress, OSProgress);
}

/*---------------------------------------------------------------------------*/

static gboolean i_animation(OSProgress *progress)
{
    cassert_no_null(progress);
    gtk_progress_bar_pulse(GTK_PROGRESS_BAR(progress->control.widget));
    return progress->pulse_id != UINT32_MAX;
}

/*---------------------------------------------------------------------------*/

void osprogress_position(OSProgress *progress, const real32_t position)
{
    cassert_no_null(progress);
    if (position < 0)
    {
        if (progress->pulse_id == UINT32_MAX)
            progress->pulse_id = g_timeout_add(100, (GSourceFunc)i_animation, progress);
    }
    else
    {
        progress->pulse_id = UINT32_MAX;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress->control.widget), (gdouble)position);
    }
}

/*---------------------------------------------------------------------------*/

real32_t osprogress_thickness(const OSProgress *progress, const gui_size_t size)
{
    cassert_no_null(progress);
    cassert_unref(size == ekGUI_SIZE_REGULAR, size);
    return (real32_t)osglobals_progress_height();
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

void osprogress_visible(OSProgress *progress, const bool_t is_visible)
{
    _oscontrol_set_visible((OSControl *)progress, is_visible);
}

/*---------------------------------------------------------------------------*/

void osprogress_enabled(OSProgress *progress, const bool_t is_enabled)
{
    _oscontrol_set_enabled((OSControl *)progress, is_enabled);
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
