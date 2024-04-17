/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospanel.c
 *
 */

/* Operating System native panel */

#include "ospanel.h"
#include "osgui.inl"
#include "oscontrol.inl"
#include "osgui_gtk.inl"
#include "ospanel_gtk.inl"
#include "oscontrol_gtk.inl"
#include "ossplit_gtk.inl"
#include <draw2d/color.h>
#include <core/arrst.h>
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

typedef struct _area_t Area;

struct _area_t
{
    void *obj;
    real32_t x;
    real32_t y;
    real32_t w;
    real32_t h;
    color_t bgcolor;
    color_t skcolor;
};

struct _ospanel_t
{
    OSControl control;
    OSControl *capture;
    GtkWidget *layout;
    GtkWidget *scroll;
    GtkAdjustment *hadjust;
    GtkAdjustment *vadjust;
    ArrSt(Area) *areas;
};

DeclSt(Area);
#define i_red(rgba) (((double)((uint8_t)((rgba) >> 0))) / 255.)
#define i_green(rgba) (((double)((uint8_t)((rgba) >> 8))) / 255.)
#define i_blue(rgba) (((double)((uint8_t)((rgba) >> 16))) / 255.)
#define i_alpha(rgba) (((double)((uint8_t)((rgba) >> 24))) / 255.)

/*---------------------------------------------------------------------------*/

static gboolean i_OnDraw(GtkWidget *widget, cairo_t *cr, OSPanel *panel)
{
    cassert_no_null(panel);
    unref(widget);

    if (panel->areas == NULL)
        return FALSE;

    cairo_save(cr);

    if (panel->hadjust != NULL)
    {
        gdouble x = gtk_adjustment_get_value(panel->hadjust);
        gdouble y = gtk_adjustment_get_value(panel->vadjust);
        cairo_translate(cr, -(double)x, -(double)y);
    }

    arrst_foreach(area, panel->areas, Area)
        if (area->bgcolor != kCOLOR_TRANSPARENT)
        {
            real32_t r, g, b, a;
            color_get_rgbaf(area->bgcolor, &r, &g, &b, &a);
            cairo_set_source_rgba(cr, (double)r, (double)g, (double)b, (double)a);
            cairo_rectangle(cr, (double)area->x, (double)area->y, (double)area->w, (double)area->h);
            cairo_fill(cr);
        }

        if (area->skcolor != kCOLOR_TRANSPARENT)
        {
            real32_t r, g, b, a;
            cairo_antialias_t ca;
            color_get_rgbaf(area->skcolor, &r, &g, &b, &a);
            cairo_set_source_rgba(cr, (double)r, (double)g, (double)b, (double)a);
            cairo_set_line_width(cr, 1.);
            ca = cairo_get_antialias(cr);
            cairo_set_antialias(cr, CAIRO_ANTIALIAS_NONE);
            cairo_rectangle(cr, (double)area->x + 1, (double)area->y + 1, (double)area->w - 1, (double)area->h - 1);
            cairo_stroke(cr);
            cairo_set_antialias(cr, ca);
        }
    arrst_end()

    cairo_restore(cr);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnPressed(GtkWidget *widget, GdkEventButton *event, OSPanel *panel)
{
    unref(widget);

    if (panel->capture != NULL)
    {
        if (panel->capture->type == ekGUI_TYPE_SPLITVIEW)
            _ossplit_OnPress((OSSplit *)panel->capture, event);

        return TRUE;
    }
    /* The handler will be called before the default handler of the signal.
    This is the default behaviour */
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

OSPanel *ospanel_create(const uint32_t flags)
{
    OSPanel *panel = heap_new0(OSPanel);
    GtkWidget *widget = gtk_layout_new(NULL, NULL);
    GtkWidget *top = widget;
    GtkWidget *focus = widget;

    panel->layout = widget;
    g_signal_connect(G_OBJECT(widget), "draw", G_CALLBACK(i_OnDraw), panel);
    g_signal_connect(G_OBJECT(widget), "button-press-event", G_CALLBACK(i_OnPressed), panel);

    if (flags & ekVIEW_HSCROLL || flags & ekVIEW_VSCROLL)
    {
        panel->scroll = gtk_scrolled_window_new(NULL, NULL);
        gtk_widget_show(panel->layout);
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(panel->scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
        gtk_container_add(GTK_CONTAINER(panel->scroll), panel->layout);

        /* A parent widget can "capture" the mouse */
        {
            GtkWidget *vscroll = gtk_scrolled_window_get_vscrollbar(GTK_SCROLLED_WINDOW(panel->scroll));
            GtkWidget *hscroll = gtk_scrolled_window_get_hscrollbar(GTK_SCROLLED_WINDOW(panel->scroll));
            g_signal_connect(G_OBJECT(vscroll), "button-press-event", G_CALLBACK(i_OnPressed), panel);
            g_signal_connect(G_OBJECT(hscroll), "button-press-event", G_CALLBACK(i_OnPressed), panel);
            g_signal_connect(G_OBJECT(panel->scroll), "button-press-event", G_CALLBACK(i_OnPressed), panel);
        }

        panel->hadjust = gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(panel->scroll));
        panel->vadjust = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(panel->scroll));
        top = panel->scroll;
        focus = panel->scroll;
    }

    /* Creating the frame (border) view */
    if (flags & ekVIEW_BORDER)
    {
        GtkWidget *frame = gtk_frame_new(NULL);
        cassert(gtk_widget_get_has_window(frame) == FALSE);
        gtk_container_add(GTK_CONTAINER(frame), top);
        gtk_widget_show(top);
        top = frame;
    }

    _oscontrol_init(&panel->control, ekGUI_TYPE_PANEL, top, focus, TRUE);
    g_object_set_data(G_OBJECT(panel->layout), "OSControl", &panel->control);
    return panel;
}

/*---------------------------------------------------------------------------*/

void ospanel_destroy(OSPanel **panel)
{
    cassert_no_null(panel);
    cassert_no_null(*panel);

    if ((*panel)->areas != NULL)
        arrst_destroy(&(*panel)->areas, NULL, Area);

    _oscontrol_destroy(*(OSControl **)panel);
    heap_delete(panel, OSPanel);
}

/*---------------------------------------------------------------------------*/

void ospanel_area(OSPanel *panel, void *obj, const color_t bgcolor, const color_t skcolor, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    cassert_no_null(panel);
    if (obj != NULL)
    {
        Area *area = NULL;

        if (panel->areas == NULL)
            panel->areas = arrst_create(Area);

        arrst_foreach(larea, panel->areas, Area)
            if (larea->obj == obj)
            {
                area = larea;
                break;
            }
        arrst_end()

        if (area == NULL)
        {
            area = arrst_new(panel->areas, Area);
            area->obj = obj;
        }

        area->x = x;
        area->y = y;
        area->w = width;
        area->h = height;
        area->bgcolor = bgcolor;
        area->skcolor = skcolor;
    }
    else
    {
        if (panel->areas != NULL)
            arrst_clear(panel->areas, NULL, Area);
    }
}

/*---------------------------------------------------------------------------*/

void ospanel_scroller_size(const OSPanel *panel, real32_t *width, real32_t *height)
{
    cassert_no_null(panel);

    if (width != NULL)
    {
        GtkWidget *vscroll = gtk_scrolled_window_get_vscrollbar(GTK_SCROLLED_WINDOW(panel->scroll));
        *width = (real32_t)gtk_widget_get_allocated_width(vscroll);
    }

    if (height != NULL)
    {
        GtkWidget *hscroll = gtk_scrolled_window_get_hscrollbar(GTK_SCROLLED_WINDOW(panel->scroll));
        *height = (real32_t)gtk_widget_get_allocated_height(hscroll);
    }
}

/*---------------------------------------------------------------------------*/

void ospanel_content_size(OSPanel *panel, const real32_t width, const real32_t height, const real32_t line_width, const real32_t line_height)
{
    cassert_no_null(panel);
    cassert(panel->layout != NULL);
    cassert(panel->hadjust != NULL && panel->vadjust != NULL);
    unref(line_width);
    unref(line_height);
    gtk_layout_set_size(GTK_LAYOUT(panel->layout), (guint)width, (guint)height);
}

/*---------------------------------------------------------------------------*/

void ospanel_display(OSPanel *panel)
{
    cassert_no_null(panel);
    gtk_widget_queue_draw(panel->control.widget);
}

/*---------------------------------------------------------------------------*/

void ospanel_attach(OSPanel *panel, OSPanel *parent_panel)
{
    _ospanel_attach_control(parent_panel, (OSControl *)panel);
}

/*---------------------------------------------------------------------------*/

void ospanel_detach(OSPanel *panel, OSPanel *parent_panel)
{
    _ospanel_detach_control(parent_panel, (OSControl *)panel);
}

/*---------------------------------------------------------------------------*/

void ospanel_visible(OSPanel *panel, const bool_t is_visible)
{
    _oscontrol_set_visible((OSControl *)panel, is_visible);
}

/*---------------------------------------------------------------------------*/

void ospanel_enabled(OSPanel *panel, const bool_t is_enabled)
{
    _oscontrol_set_enabled((OSControl *)panel, is_enabled);
}

/*---------------------------------------------------------------------------*/

void ospanel_size(const OSPanel *panel, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)panel, width, height);
}

/*---------------------------------------------------------------------------*/

void ospanel_origin(const OSPanel *panel, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)panel, x, y);
}

/*---------------------------------------------------------------------------*/

void ospanel_frame(OSPanel *panel, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)panel, x, y, width, height);
}

/*---------------------------------------------------------------------------*/

void ospanel_position(OSPanel *panel, const real32_t x, const real32_t y)
{
    unref(panel);
    unref(x);
    unref(y);
    cassert_msg(FALSE, "Not implemented");
}

/*---------------------------------------------------------------------------*/

static void i_destroy_child(GtkWidget *widget, gpointer data)
{
    OSPanel *panel = OSPanelPtr(data);
    OSControl *control = OSControlPtr(g_object_get_data(G_OBJECT(widget), "OSControl"));
    oscontrol_detach_and_destroy(&control, panel);
}

/*---------------------------------------------------------------------------*/

void _ospanel_destroy(OSPanel **panel)
{
    cassert_no_null(panel);
    cassert_no_null(*panel);
    gtk_container_foreach(GTK_CONTAINER((*panel)->control.widget), i_destroy_child, (gpointer)*panel);
    ospanel_destroy(panel);
}

/*---------------------------------------------------------------------------*/

void _ospanel_attach_control(OSPanel *panel, OSControl *control)
{
    cassert_no_null(panel);
    _oscontrol_attach_to_parent(control, panel->layout);
}

/*---------------------------------------------------------------------------*/

void _ospanel_detach_control(OSPanel *panel, OSControl *control)
{
    cassert_no_null(panel);
    _oscontrol_detach_from_parent(control, panel->layout);
}

/*---------------------------------------------------------------------------*/

void _ospanel_set_capture(OSPanel *panel, OSControl *control)
{
    cassert_no_null(panel);
    panel->capture = control;
}

/*---------------------------------------------------------------------------*/

void _ospanel_release_capture(OSPanel *panel)
{
    cassert_no_null(panel);
    panel->capture = NULL;
}

/*---------------------------------------------------------------------------*/

bool_t ospanel_with_scroll(const OSPanel *panel)
{
    cassert_no_null(panel);
    return (bool_t)(panel->hadjust != NULL);
}

/*---------------------------------------------------------------------------*/

void ospanel_scroll(OSPanel *panel, const int32_t x, const int32_t y)
{
    cassert_no_null(panel);

    if (panel->hadjust != NULL && x != INT32_MAX)
        gtk_adjustment_set_value(panel->hadjust, (gdouble)x);

    if (panel->vadjust != NULL && y != INT32_MAX)
        gtk_adjustment_set_value(panel->vadjust, (gdouble)y);
}

/*---------------------------------------------------------------------------*/

void ospanel_scroll_frame(const OSPanel *panel, OSFrame *rect)
{
    real32_t w, h;
    cassert_no_null(panel);
    cassert_no_null(rect);
    if (panel->hadjust != NULL)
        rect->left = (int32_t)gtk_adjustment_get_value(panel->hadjust);
    else
        rect->left = 0;

    if (panel->vadjust != NULL)
        rect->top = (int32_t)gtk_adjustment_get_value(panel->vadjust);
    else
        rect->top = 0;

    _oscontrol_get_size(&panel->control, &w, &h);
    rect->right = rect->left + (int32_t)w;
    rect->bottom = rect->top + (int32_t)h;
}
