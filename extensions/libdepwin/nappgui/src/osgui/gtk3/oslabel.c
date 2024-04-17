/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslabel.c
 *
 */

/* Operating System label */

#include "oslabel.h"
#include "oslabel.inl"
#include "osgui.inl"
#include "oslistener.inl"
#include "osgui_gtk.inl"
#include "oscontrol_gtk.inl"
#include "ospanel_gtk.inl"
#include <draw2d/color.h>
#include <draw2d/font.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/cassert.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _oslabel_t
{
    OSControl control;
    GtkWidget *label;
    String *text;
    Font *font;
    color_t _color;
    GtkCssProvider *bgcolor;
    gint enter_signal;
    gint exit_signal;
    gint click_signal;
    Listener *OnClick;
    Listener *OnMouseEnter;
    Listener *OnMouseExit;
};

/*---------------------------------------------------------------------------*/

static gboolean i_OnEnter(GtkWidget *widget, GdkEventCrossing *event, OSLabel *label)
{
    unref(widget);
    unref(event);
    cassert_no_null(label);
    if (label->OnMouseEnter != NULL)
    {
        EvMouse params;
        params.x = (real32_t)event->x;
        params.y = (real32_t)event->y;
        params.lx = params.x;
        params.ly = params.y;
        params.button = ENUM_MAX(gui_mouse_t);
        params.count = 0;
        params.modifiers = 0;
        params.tag = 0;
        listener_event(label->OnMouseEnter, ekGUI_EVENT_ENTER, label, &params, NULL, OSLabel, EvMouse, void);
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnExit(GtkWidget *widget, GdkEventCrossing *event, OSLabel *label)
{
    unref(widget);
    unref(event);
    cassert_no_null(label);
    if (label->OnMouseExit != NULL)
        listener_event(label->OnMouseExit, ekGUI_EVENT_EXIT, label, NULL, NULL, OSLabel, void, void);

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnClick(GtkWidget *widget, GdkEventButton *event, OSLabel *label)
{
    unref(widget);
    unref(event);
    cassert_no_null(label);
    if (label->OnClick != NULL)
    {
        EvText params;
        params.text = NULL;
        listener_event(label->OnClick, ekGUI_EVENT_LABEL, label, &params, NULL, OSLabel, EvText, void);
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_font_px(const real32_t fsize, const uint32_t fstyle)
{
    if ((fstyle & ekFPOINTS) == ekFPOINTS)
    {
        PangoFontMap *fontmap = pango_cairo_font_map_get_default();
        real32_t dpi = (real32_t)pango_cairo_font_map_get_resolution((PangoCairoFontMap *)fontmap);
        return (uint32_t)(fsize / (dpi / 72.f));
    }
    else
    {
        return (uint32_t)fsize;
    }
}

/*---------------------------------------------------------------------------*/

static void i_set_text(OSLabel *label)
{
    PangoFontDescription *fdesc = (PangoFontDescription *)font_native(label->font);
    const char *family = pango_font_description_get_family(fdesc);
    real32_t fsize = font_size(label->font);
    uint32_t fstyle = font_style(label->font);
    real32_t fpoints = i_font_px(fsize, fstyle);
    String *format = str_printf("<span font_desc=\"%s %.2fpx\"", family, fpoints);

    if (fstyle & ekFITALIC)
        str_cat(&format, " style=\"italic\"");

    if (fstyle & ekFBOLD)
        str_cat(&format, " weight=\"bold\"");

    if (fstyle & ekFUNDERLINE)
        str_cat(&format, " underline=\"single\"");

    if (fstyle & ekFSTRIKEOUT)
        str_cat(&format, " strikethrough=\"true\"");

    if (label->_color != 0)
    {
        char_t html[16];
        color_to_html(label->_color, html, sizeof(html));
        str_cat(&format, " foreground=\"");
        str_cat(&format, html);
        str_cat(&format, "\"");
    }

    str_cat(&format, ">");
    str_cat(&format, tc(label->text));
    str_cat(&format, "</span>");

    gtk_label_set_markup(GTK_LABEL(label->label), tc(format));
    str_destroy(&format);
}

/*---------------------------------------------------------------------------*/

static void i_set_bg_color(OSLabel *label, const color_t color)
{
    cassert_no_null(label);

#if GTK_CHECK_VERSION(3, 22, 0)
    if (label->bgcolor != NULL)
    {
        _oscontrol_widget_remove_provider(label->label, label->bgcolor);
        label->bgcolor = NULL;
    }

    if (color != kCOLOR_TRANSPARENT)
        _oscontrol_widget_bg_color(label->label, "label", color, &label->bgcolor);

#else
    {
        GdkRGBA gdkcolor;
        _oscontrol_to_gdkrgba(color, &gdkcolor);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
        gtk_widget_override_background_color(label->control.widget, GTK_STATE_FLAG_NORMAL, &gdkcolor);
        gtk_widget_override_background_color(label->label, GTK_STATE_FLAG_NORMAL, &gdkcolor);
#pragma GCC diagnostic pop
    }

#endif
}

/*---------------------------------------------------------------------------*/

OSLabel *oslabel_create(const uint32_t flags)
{
    OSLabel *label = heap_new0(OSLabel);
    GtkWidget *widget = gtk_event_box_new();
    _oscontrol_init(&label->control, ekGUI_TYPE_LABEL, widget, widget, TRUE);
    label->label = gtk_label_new(NULL);
    label->text = str_c("");
    label->font = osgui_create_default_font();
    label->_color = kCOLOR_DEFAULT;
    gtk_label_set_use_markup(GTK_LABEL(label->label), TRUE);
    gtk_widget_show(label->label);
    gtk_container_add(GTK_CONTAINER(widget), label->label);
    gtk_label_set_line_wrap(GTK_LABEL(label->label), label_get_type(flags) == ekLABEL_MULTI ? TRUE : FALSE);
    i_set_text(label);
    i_set_bg_color(label, kCOLOR_TRANSPARENT);
    return label;
}

/*---------------------------------------------------------------------------*/

void oslabel_destroy(OSLabel **label)
{
    cassert_no_null(label);
    cassert_no_null(*label);

    if ((*label)->bgcolor != NULL)
    {
        /* Not g_object_unref
        g_object_unref((*label)->bgcolor); */
        (*label)->bgcolor = NULL;
    }

    listener_destroy(&(*label)->OnClick);
    listener_destroy(&(*label)->OnMouseEnter);
    listener_destroy(&(*label)->OnMouseExit);
    font_destroy(&(*label)->font);
    str_destroy(&(*label)->text);
    _oscontrol_destroy(*(OSControl **)label);
    heap_delete(label, OSLabel);
}

/*---------------------------------------------------------------------------*/

void oslabel_OnClick(OSLabel *label, Listener *listener)
{
    cassert_no_null(label);
    listener_update(&label->OnClick, listener);
    _oslistener_signal(label->control.widget, listener != NULL, &label->click_signal, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK, "button-press-event", G_CALLBACK(i_OnClick), (gpointer)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_OnEnter(OSLabel *label, Listener *listener)
{
    cassert_no_null(label);
    listener_update(&label->OnMouseEnter, listener);
    _oslistener_signal(label->control.widget, listener != NULL, &label->enter_signal, GDK_ENTER_NOTIFY_MASK, "enter-notify-event", G_CALLBACK(i_OnEnter), (gpointer)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_OnExit(OSLabel *label, Listener *listener)
{
    cassert_no_null(label);
    listener_update(&label->OnMouseExit, listener);
    _oslistener_signal(label->control.widget, listener != NULL, &label->exit_signal, GDK_LEAVE_NOTIFY_MASK, "leave-notify-event", G_CALLBACK(i_OnExit), (gpointer)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_text(OSLabel *label, const char_t *text)
{
    cassert_no_null(label);
    str_upd(&label->text, text);
    i_set_text(label);
}

/*---------------------------------------------------------------------------*/

void oslabel_font(OSLabel *label, const Font *font)
{
    cassert_no_null(label);
    if (font != label->font)
    {
        font_destroy(&label->font);
        label->font = font_copy(font);
        i_set_text(label);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE GtkJustification i_align(const align_t align, gfloat *xalign)
{
    switch (align)
    {
    case ekLEFT:
        *xalign = 0;
        return GTK_JUSTIFY_LEFT;
    case ekJUSTIFY:
        *xalign = 0;
        return GTK_JUSTIFY_FILL;
    case ekCENTER:
        *xalign = .5f;
        return GTK_JUSTIFY_CENTER;
    case ekRIGHT:
        *xalign = .99f;
        return GTK_JUSTIFY_RIGHT;
        cassert_default();
    }

    return GTK_JUSTIFY_LEFT;
}

/*---------------------------------------------------------------------------*/

void oslabel_align(OSLabel *label, const align_t align)
{
    gfloat xalign = 0;
    cassert_no_null(label);
    gtk_label_set_justify(GTK_LABEL(label->label), i_align(align, &xalign));

#if GTK_CHECK_VERSION(3, 16, 0)
    gtk_label_set_xalign(GTK_LABEL(label->label), xalign);

#else
    gtk_misc_set_alignment(GTK_MISC(label->label), xalign, 0);

#endif
}

/*---------------------------------------------------------------------------*/

static PangoEllipsizeMode i_ellipsis(const ellipsis_t ellipsis)
{
    switch (ellipsis)
    {
    case ekELLIPNONE:
    case ekELLIPMLINE:
        return PANGO_ELLIPSIZE_NONE;
    case ekELLIPBEGIN:
        return PANGO_ELLIPSIZE_START;
    case ekELLIPMIDDLE:
        return PANGO_ELLIPSIZE_MIDDLE;
    case ekELLIPEND:
        return PANGO_ELLIPSIZE_END;
        cassert_default();
    }

    return PANGO_ELLIPSIZE_NONE;
}

/*---------------------------------------------------------------------------*/

void oslabel_ellipsis(OSLabel *label, const ellipsis_t ellipsis)
{
    PangoEllipsizeMode e = i_ellipsis(ellipsis);
    cassert_no_null(label);
    gtk_label_set_ellipsize(GTK_LABEL(label->label), e);
}

/*---------------------------------------------------------------------------*/

void oslabel_color(OSLabel *label, const color_t color)
{
    cassert_no_null(label);
    if (label->_color != color)
    {
        label->_color = color;
        i_set_text(label);
    }
}

/*---------------------------------------------------------------------------*/

void oslabel_bgcolor(OSLabel *label, const color_t color)
{
    i_set_bg_color(label, color);
}

/*---------------------------------------------------------------------------*/

void oslabel_bounds(const OSLabel *label, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    PangoLayout *layout;
    int w, h;
    String *curstr = NULL;
    cassert_no_null(label);
    cassert_no_null(width);
    cassert_no_null(height);

    if (str_equ(label->text, text) == FALSE)
    {
        curstr = str_copy(label->text);
        str_upd(&((OSLabel *)label)->text, text);
        i_set_text((OSLabel *)label);
    }

    layout = gtk_label_get_layout(GTK_LABEL(label->label));
    pango_layout_set_width(layout, refwidth > 0.f ? (int)(refwidth * (real32_t)PANGO_SCALE) : -1);
    pango_layout_get_pixel_size(layout, &w, &h);

    if (curstr != NULL)
    {
        str_upd(&((OSLabel *)label)->text, tc(curstr));
        i_set_text((OSLabel *)label);
        str_destroy(&curstr);
    }

    *width = (real32_t)w;
    *height = (real32_t)h;
}

/*---------------------------------------------------------------------------*/

void oslabel_attach(OSLabel *label, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_detach(OSLabel *label, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)label);
}

/*---------------------------------------------------------------------------*/

void oslabel_visible(OSLabel *label, const bool_t is_visible)
{
    _oscontrol_set_visible((OSControl *)label, is_visible);
}

/*---------------------------------------------------------------------------*/

void oslabel_enabled(OSLabel *label, const bool_t is_enabled)
{
    _oscontrol_set_enabled((OSControl *)label, is_enabled);
}

/*---------------------------------------------------------------------------*/

void oslabel_size(const OSLabel *label, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)label, width, height);
}

/*---------------------------------------------------------------------------*/

void oslabel_origin(const OSLabel *label, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)label, x, y);
}

/*---------------------------------------------------------------------------*/

void oslabel_frame(OSLabel *label, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)label, x, y, width, height);

#if GTK_CHECK_VERSION(3, 10, 0)
    /* Internal label doesn't need resize */
#else
    cassert_no_null(label);
    gtk_widget_set_size_request(label->label, (gint)width, (gint)height);
#endif
}
