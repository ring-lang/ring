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
#include "osscroll_gtk.inl"
#include "osgui_gtk.inl"
#include "oscontrol_gtk.inl"
#include "osview_gtk.inl"
#include <core/heap.h>
#include <sewer/cassert.h>

struct _osscroll_t
{
    OSControl *control;
    GtkOrientation orient;
    GtkWidget *widget;
    GtkAdjustment *adjust;
    bool_t visible;
    uint32_t pos;
};

/*---------------------------------------------------------------------------*/

static uint32_t i_BAR_SIZE = 12;

/*---------------------------------------------------------------------------*/

static void i_set_visible(OSScroll *scroll)
{
    cassert_no_null(scroll);
    if (gtk_widget_get_realized(scroll->widget) == TRUE)
    {
        if (scroll->visible == TRUE)
            gtk_widget_show(scroll->widget);
        else
            gtk_widget_hide(scroll->widget);
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnRealize(GtkWidget *widget, OSScroll *scroll)
{
    cassert_no_null(scroll);
    cassert_unref(scroll->widget == widget, widget);
    i_set_visible(scroll);
}

/*---------------------------------------------------------------------------*/

static void i_OnScrollMoved(GtkRange *range, OSScroll *scroll)
{
    gui_orient_t orient = ekGUI_HORIZONTAL;
    gui_scroll_t event = ekGUI_SCROLL_THUMB;

    cassert_no_null(scroll);
    cassert_unref(range == GTK_RANGE(scroll->widget), range);
    if (scroll->orient == GTK_ORIENTATION_VERTICAL)
        orient = ekGUI_VERTICAL;

    /*
     * There is not a "secure" way in GTK to detect scrollbar steppers
     * Steppers have been removed in GTK3
     * https://blogs.gnome.org/mclasen/2013/08/05/scrolling-in-gtk/
     */
    event = ekGUI_SCROLL_THUMB;

    if (scroll->control->type == ekGUI_TYPE_CUSTOMVIEW)
    {
        _osview_scroll_event(OSViewPtr(scroll->control), orient, event);
    }
    else
    {
        cassert(FALSE);
    }
}

/*---------------------------------------------------------------------------*/

/*
TODO: Scrollbars size
static gboolean i_OnScrollEnter(GtkWidget *widget, GdkEventCrossing *event, OSScroll *scroll)
{
    cassert_no_null(scroll);
    cassert_no_null(event);
    if (event->type == GDK_ENTER_NOTIFY)
    {
        GtkRequisition size;
        gtk_widget_get_preferred_size(widget, &size, NULL);
        if (scroll->orient == GTK_ORIENTATION_VERTICAL)
        {
            i_BAR_SIZE = size.width;
        }
        else
        {
            i_BAR_SIZE = size.height;
        }
    }

    return FALSE;
}
*/

/*---------------------------------------------------------------------------*/

static GtkWidget *i_parent(const OSScroll *scroll)
{
    cassert_no_null(scroll);
    cassert_no_null(scroll->control);
    if (scroll->control->type == ekGUI_TYPE_CUSTOMVIEW)
        return _osview_area_widget(OSViewPtr(scroll->control));
    cassert(FALSE);
    return NULL;
}

/*---------------------------------------------------------------------------*/

static OSScroll *i_scroll_create(GtkOrientation orient, OSControl *control)
{
    OSScroll *scroll = heap_new0(OSScroll);
    GtkWidget *parent = NULL;
    scroll->control = control;
    scroll->orient = orient;
    scroll->widget = gtk_scrollbar_new(orient, NULL);
    scroll->adjust = gtk_range_get_adjustment(GTK_RANGE(scroll->widget));
    scroll->visible = FALSE;
    scroll->pos = 0;
    parent = i_parent(scroll);
    cassert(GTK_IS_LAYOUT(parent));
    gtk_layout_put(GTK_LAYOUT(parent), scroll->widget, 0, 0);
    gtk_widget_show(scroll->widget);
    g_signal_connect(scroll->widget, "realize", G_CALLBACK(i_OnRealize), (gpointer)scroll);
    g_signal_connect(scroll->widget, "value-changed", G_CALLBACK(i_OnScrollMoved), (gpointer)scroll);
    /*g_signal_connect(scroll->widget, "enter-notify-event", G_CALLBACK(i_OnScrollEnter), (gpointer)scroll);*/
    return scroll;
}

/*---------------------------------------------------------------------------*/

OSScroll *osscroll_horizontal(OSControl *control)
{
    return i_scroll_create(GTK_ORIENTATION_HORIZONTAL, control);
}

/*---------------------------------------------------------------------------*/

OSScroll *osscroll_vertical(OSControl *control)
{
    return i_scroll_create(GTK_ORIENTATION_VERTICAL, control);
}

/*---------------------------------------------------------------------------*/

void osscroll_destroy(OSScroll **scroll, OSControl *control)
{
    GtkWidget *parent = NULL;
    cassert_no_null(scroll);
    cassert_no_null(*scroll);
    cassert_unref((*scroll)->control == control, control);
    parent = i_parent(*scroll);
    _oscontrol_widget_detach((*scroll)->widget, parent);
    heap_delete(scroll, OSScroll);
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_pos(const OSScroll *scroll)
{
    cassert_no_null(scroll);
    return scroll->pos;
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_trackpos(const OSScroll *scroll)
{
    cassert_no_null(scroll);
    return (uint32_t)gtk_adjustment_get_value(scroll->adjust);
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_bar_width(const OSScroll *scroll)
{
    cassert_no_null(scroll);
    cassert_unref(scroll->orient == GTK_ORIENTATION_VERTICAL, scroll);
    return i_BAR_SIZE;
}

/*---------------------------------------------------------------------------*/

uint32_t osscroll_bar_height(const OSScroll *scroll)
{
    cassert_no_null(scroll);
    cassert_unref(scroll->orient == GTK_ORIENTATION_HORIZONTAL, scroll);
    return i_BAR_SIZE;
}

/*---------------------------------------------------------------------------*/

void osscroll_set_pos(OSScroll *scroll, const uint32_t pos)
{
    guint nref = 0;
    cassert_no_null(scroll);
    scroll->pos = pos;
    nref = g_signal_handlers_block_by_func(scroll->widget, (gpointer)(intptr_t)i_OnScrollMoved, (gpointer)scroll);
    cassert_unref(nref == 1, nref);
    gtk_adjustment_set_value(scroll->adjust, (gdouble)pos);
    nref = g_signal_handlers_unblock_by_func(scroll->widget, (gpointer)(intptr_t)i_OnScrollMoved, (gpointer)scroll);
    cassert_unref(nref == 1, nref);
}

/*---------------------------------------------------------------------------*/

void osscroll_visible(OSScroll *scroll, const bool_t visible)
{
    cassert_no_null(scroll);
    scroll->visible = visible;
    i_set_visible(scroll);
}

/*---------------------------------------------------------------------------*/

void osscroll_config(OSScroll *scroll, const uint32_t pos, const uint32_t max, const uint32_t page)
{
    cassert_no_null(scroll);
    gtk_adjustment_set_lower(scroll->adjust, 0);
    gtk_adjustment_set_upper(scroll->adjust, (gdouble)max);
    gtk_adjustment_set_page_size(scroll->adjust, (gdouble)page);
    osscroll_set_pos(scroll, pos);
}

/*---------------------------------------------------------------------------*/

void osscroll_frame(OSScroll *scroll, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height)
{
    GtkWidget *parent = i_parent(scroll);
    gint nx = (gint)x;
    gint ny = (gint)y;
    cassert_no_null(scroll);
    cassert(GTK_IS_LAYOUT(parent));
    if (scroll->orient == GTK_ORIENTATION_HORIZONTAL)
    {
        cassert((uint32_t)height == i_BAR_SIZE);
        ny -= 1;
    }
    else
    {
        cassert(scroll->orient == GTK_ORIENTATION_VERTICAL);
        cassert((uint32_t)width == i_BAR_SIZE);
        nx -= 1;
    }
    gtk_layout_move(GTK_LAYOUT(parent), scroll->widget, nx, ny);
    gtk_widget_set_size_request(scroll->widget, (gint)width, (gint)height);
}

/*---------------------------------------------------------------------------*/

void osscroll_control_scroll(OSControl *control, const int32_t incr_x, const int32_t incr_y)
{
    unref(control);
    unref(incr_x);
    unref(incr_y);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

gui_scroll_t osscroll_wheel_event(const GdkEventScroll *event)
{
    cassert_no_null(event);
    switch (event->direction)
    {
    case GDK_SCROLL_LEFT:
    case GDK_SCROLL_UP:
        return ekGUI_SCROLL_STEP_LEFT;
    case GDK_SCROLL_DOWN:
    case GDK_SCROLL_RIGHT:
        return ekGUI_SCROLL_STEP_RIGHT;
    case GDK_SCROLL_SMOOTH:
        if (event->delta_y > 0)
            return ekGUI_SCROLL_STEP_RIGHT;
        else if (event->delta_y < 0)
            return ekGUI_SCROLL_STEP_LEFT;

        break;
    }

    return ENUM_MAX(gui_scroll_t);
}
