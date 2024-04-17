/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscontrol.c
 *
 */

/* Gtk Widgets common functions */

#include "oscontrol.inl"
#include "oscontrol_gtk.inl"
#include "osgui.inl"
#include "osgui_gtk.inl"
#include "osbutton_gtk.inl"
#include "oscombo_gtk.inl"
#include "osedit_gtk.inl"
#include "ospopup_gtk.inl"
#include "ostext_gtk.inl"
#include "osview_gtk.inl"
#include "oswindow_gtk.inl"
#include <draw2d/color.h>
#include <draw2d/font.h>
#include <core/stream.h>
#include <core/strings.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

/*---------------------------------------------------------------------------*/

static void i_OnFocus(GtkWidget *widget, OSControl *control)
{
    unref(widget);
    unref(control);
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnFocusOut(GtkWidget *widget, GdkEvent *e, OSControl *control)
{
    cassert_no_null(control);
    if (control->type == ekGUI_TYPE_WINDOW)
        _oswindow_unset_focus((OSWindow *)control);

    unref(widget);
    unref(e);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

void _oscontrol_init(OSControl *control, const gui_type_t type, GtkWidget *widget, GtkWidget *focus_widget, const bool_t show)
{
    cassert_no_null(control);
    control->type = type;
    control->widget = widget;
#if defined(__ASSERTS__)
    control->is_alive = TRUE;
#endif
    g_signal_connect(focus_widget, "grab-focus", G_CALLBACK(i_OnFocus), (gpointer)control);
    g_signal_connect(focus_widget, "focus-out-event", G_CALLBACK(i_OnFocusOut), (gpointer)control);
    g_object_ref(control->widget);
    g_object_set_data(G_OBJECT(control->widget), "OSControl", control);

    if (control->widget != focus_widget)
        g_object_set_data(G_OBJECT(focus_widget), "OSControl", control);

    gtk_widget_hide(control->widget);
    unref(show);
    /*    if (show == TRUE)
       gtk_widget_show(control->widget);
   else
       gtk_widget_hide(control->widget);
 */
}

/*---------------------------------------------------------------------------*/

static void i_count(GtkWidget *widget, gpointer data)
{
    uint32_t *n = (uint32_t *)data;
    unref(widget);
    *n += 1;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_num_children(GtkContainer *container)
{
    uint32_t n = 0;
    gtk_container_foreach(container, i_count, (gpointer)&n);
    return n;
}

/*---------------------------------------------------------------------------*/

#if defined(__ASSERTS__)

static void i_OnDestroy(GtkWidget *obj, OSControl *control)
{
    unref(obj);
    if (control->type < GUI_CONTEXT_NUM_COMPONENTS)
    {
        cassert(control->is_alive == TRUE);
        control->is_alive = FALSE;
    }
}

#endif

/*---------------------------------------------------------------------------*/

void _oscontrol_destroy(OSControl *control)
{
    cassert_no_null(control);
#if defined(__ASSERTS__)
    cassert(control->is_alive == TRUE);
    g_signal_connect(control->widget, "destroy", G_CALLBACK(i_OnDestroy), (gpointer)control);
/* if (GTK_IS_LAYOUT(control->widget) || GTK_IS_WINDOW(control->widget) || GTK_IS_SCROLLED_WINDOW(control->widget))
    {
       cassert(i_num_children(GTK_CONTAINER(control->widget)) == 0);
    }
    */
#endif

    g_object_unref(control->widget);

#if defined(__ASSERTS__)
    /*cassert(control->is_alive == FALSE);*/
#endif
}

/*---------------------------------------------------------------------------*/

static GtkAlign i_align(const align_t align)
{
    switch (align)
    {
    case ekLEFT:
        return GTK_ALIGN_START;
    case ekCENTER:
        return GTK_ALIGN_CENTER;
    case ekRIGHT:
        return GTK_ALIGN_END;
    case ekJUSTIFY:
        return GTK_ALIGN_FILL;
        cassert_default();
    }
    return GTK_ALIGN_START;
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_halign(OSControl *control, const align_t align)
{
    GtkAlign a = i_align(align);
    cassert_no_null(control);
    gtk_widget_set_halign(control->widget, a);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_text_bounds(const OSControl *control, PangoLayout *layout, const char_t *text, const Font *font, const real32_t refwidth, real32_t *width, real32_t *height)
{
    int w, h;

    if (layout == NULL)
    {
        const PangoFontDescription *fdesc = (PangoFontDescription *)font_native(font);
        pango_layout_set_font_description(kPANGO_LAYOUT, fdesc);
        pango_layout_set_wrap(kPANGO_LAYOUT, PANGO_WRAP_WORD);
        pango_layout_set_ellipsize(kPANGO_LAYOUT, PANGO_ELLIPSIZE_NONE);
        pango_layout_set_alignment(kPANGO_LAYOUT, PANGO_ALIGN_CENTER);
        pango_layout_set_width(kPANGO_LAYOUT, refwidth > 0.f ? (int)(refwidth * (real32_t)PANGO_SCALE) : -1);
        pango_layout_set_text(kPANGO_LAYOUT, (const char *)text, -1);
        pango_layout_get_pixel_size(kPANGO_LAYOUT, &w, &h);
    }
    else
    {
        pango_layout_set_width(layout, refwidth > 0.f ? (int)(refwidth * (real32_t)PANGO_SCALE) : -1);
        pango_layout_set_text(layout, (const char *)text, -1);
        pango_layout_get_pixel_size(layout, &w, &h);
    }

    *width = (real32_t)w;
    *height = (real32_t)h;
    unref(control);
    /*
    data.layout = kPANGO_LAYOUT;
    osgui_text_bounds(&data, text, refwidth, width, height);
    */
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_visible(OSControl *control, const bool_t is_visible)
{
    cassert_no_null(control);
    if (is_visible == TRUE)
        gtk_widget_show(control->widget);
    else
        gtk_widget_hide(control->widget);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_enabled(OSControl *control, const bool_t is_enabled)
{
    cassert_no_null(control);
    gtk_widget_set_sensitive(control->widget, (gboolean)is_enabled);
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_widget_allocation(GtkWidget *widget, GtkAllocation *alloc)
{
#if GTK_CHECK_VERSION(3, 20, 0)
    gtk_widget_get_allocated_size(widget, alloc, NULL);
#else
    gtk_widget_get_allocation(widget, alloc);
#endif
}

/*---------------------------------------------------------------------------*/

void _oscontrol_get_origin(const OSControl *control, real32_t *x, real32_t *y)
{
    GtkAllocation alloc;
    cassert_no_null(control);
    cassert_no_null(x);
    cassert_no_null(y);
    i_widget_allocation(control->widget, &alloc);
    *x = (real32_t)alloc.x;
    *y = (real32_t)alloc.y;
}

/*---------------------------------------------------------------------------*/

void _oscontrol_get_size(const OSControl *control, real32_t *width, real32_t *height)
{
    cassert_no_null(control);
    _oscontrol_widget_size(control->widget, width, height);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_set_frame(OSControl *control, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    GtkWidget *parent;
    const gchar *ptype;
    cassert_no_null(control);
    parent = gtk_widget_get_parent(control->widget);
    cassert_no_null(parent);
    ptype = G_OBJECT_TYPE_NAME(parent);
    /* 	GtkLayout inside GtkLayout
	https://stackoverflow.com/questions/47879677/is-it-possible-to-put-gtklayouts-inside-gtklayout */
    if (str_equ_c(ptype, "GtkLayout"))
    {
        gtk_layout_move(GTK_LAYOUT(parent), control->widget, (gint)x, (gint)y);
        gtk_widget_set_size_request(control->widget, (gint)width, (gint)height);
    }
    else
    {
        cassert(str_equ_c(ptype, "GtkBox"));
        cassert(str_equ_c(G_OBJECT_TYPE_NAME(control->widget), "GtkLayout") || str_equ_c(G_OBJECT_TYPE_NAME(control->widget), "GtkScrolledWindow"));
        cassert(control->type == ekGUI_TYPE_PANEL);
        cassert(x == 0.f);
        cassert(y == 0.f);
        /* gtk_widget_set_size_request(control->widget, (gint)width, (gint)height);
        gtk_widget_set_size_request(control->widget, 0, 0);
        gtk_layout_set_size(GTK_LAYOUT(control->widget), (gint)width, (gint)height); */
    }
}

/*---------------------------------------------------------------------------*/

void _oscontrol_attach_to_parent(OSControl *control, GtkWidget *parent_widget)
{
#if defined(__ASSERTS__)
    uint32_t c = i_num_children(GTK_CONTAINER(parent_widget));
#endif
    cassert_no_null(control);
    cassert(str_equ_c(G_OBJECT_TYPE_NAME(parent_widget), "GtkLayout"));
    gtk_layout_put(GTK_LAYOUT(parent_widget), control->widget, 0, 0);
    cassert(i_num_children(GTK_CONTAINER(parent_widget)) == c + 1);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_detach_from_parent(OSControl *control, GtkWidget *parent_widget)
{
    cassert_no_null(control);
    _oscontrol_widget_detach(control->widget, parent_widget);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_detach(GtkWidget *widget, GtkWidget *parent_widget)
{
#if defined(__ASSERTS__)
    uint32_t c = i_num_children(GTK_CONTAINER(parent_widget));
    cassert(c > 0);
#endif
    gtk_container_remove(GTK_CONTAINER(parent_widget), widget);
    cassert(i_num_children(GTK_CONTAINER(parent_widget)) == c - 1);
}

/*---------------------------------------------------------------------------*/

uint32_t _oscontrol_num_children(GtkContainer *container)
{
    cassert_no_null(container);
    return i_num_children(container);
}

/*---------------------------------------------------------------------------*/

GtkWidget *_oscontrol_get_child(GtkContainer *container, const uint32_t index)
{
    GList *children = NULL;
    uint32_t i = 0;
    cassert_no_null(container);
    children = gtk_container_get_children(container);
    for (i = 0; i < index; ++i)
    {
        cassert_no_null(children);
        children = children->next;
    }

    cassert_no_null(children);
    return (GtkWidget *)children->data;
}

/*---------------------------------------------------------------------------*/

bool_t _oscontrol_widget_mouse_over(GtkWidget *widget, GdkEvent *event)
{
    double x, y;
    if (gdk_event_get_coords(event, &x, &y) == TRUE)
    {
        GtkAllocation alloc;
        gint event_x = (gint)x;
        gint event_y = (gint)y;
        i_widget_allocation(widget, &alloc);

        if (event_x >= alloc.x && event_x <= alloc.x + alloc.width && event_y >= alloc.y && event_y <= alloc.y + alloc.height)
        {
            return TRUE;
        }
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t _oscontrol_widget_mouse_over_right(GtkWidget *widget, GdkEvent *event, gint right_px)
{
    double x, y;
    if (gdk_event_get_coords(event, &x, &y) == TRUE)
    {
        GtkAllocation alloc;
        gint event_x = (gint)x;
        gint event_y = (gint)y;
        i_widget_allocation(widget, &alloc);

        if (event_x >= alloc.x + alloc.width - right_px && event_x <= alloc.x + alloc.width && event_y >= alloc.y && event_y <= alloc.y + alloc.height)
        {
            return TRUE;
        }
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_set_css(GtkWidget *widget, const char_t *css)
{
    _oscontrol_widget_set_provider(widget, css, NULL);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_set_provider(GtkWidget *widget, const char_t *css, GtkCssProvider **css_prov)
{
    GtkCssProvider *p = gtk_css_provider_new();
    GtkStyleContext *c = gtk_widget_get_style_context(widget);
    gtk_css_provider_load_from_data(GTK_CSS_PROVIDER(p), (gchar *)css, -1, NULL);
    gtk_style_context_add_provider(c, GTK_STYLE_PROVIDER(p), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(p);
    ptr_assign(css_prov, p);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_add_provider(GtkWidget *widget, GtkCssProvider *css_prov)
{
    GtkStyleContext *c = gtk_widget_get_style_context(widget);
    cassert_no_null(css_prov);
    gtk_style_context_add_provider(c, GTK_STYLE_PROVIDER(css_prov), GTK_STYLE_PROVIDER_PRIORITY_USER);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_remove_provider(GtkWidget *widget, GtkCssProvider *css_prov)
{
    GtkStyleContext *c = gtk_widget_get_style_context(widget);
    cassert_no_null(css_prov);
    gtk_style_context_remove_provider(c, GTK_STYLE_PROVIDER(css_prov));
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_color(GtkWidget *widget, const char_t *css_type, const color_t color, GtkCssProvider **css_provider)
{
    char_t html[16];
    String *css;
    color_to_html(color, html, sizeof(html));
    css = str_printf("%s {color:%s;}", css_type, html);
    _oscontrol_widget_set_provider(widget, tc(css), css_provider);
    str_destroy(&css);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_bg_color(GtkWidget *widget, const char_t *css_type, const color_t color, GtkCssProvider **css_provider)
{
    char_t html[16];
    String *css;
    color_to_html(color, html, sizeof(html));
    css = str_printf("%s {background-color:%s;background-image:none;}", css_type, html);
    _oscontrol_widget_set_provider(widget, tc(css), css_provider);
    str_destroy(&css);
}

/*---------------------------------------------------------------------------*/

uint32_t _oscontrol_widget_font_size(GtkWidget *widget)
{
    PangoFontDescription *fdesc;
    GtkStyleContext *ctx = gtk_widget_get_style_context(widget);
    PangoFontMap *fontmap = pango_cairo_font_map_get_default();
    real32_t dpi = (real32_t)pango_cairo_font_map_get_resolution((PangoCairoFontMap *)fontmap);
    real32_t fsize = 0;
    gtk_style_context_get(ctx, GTK_STATE_FLAG_NORMAL, "font", &fdesc, NULL);
    fsize = (real32_t)pango_font_description_get_size(fdesc);
    pango_font_description_free(fdesc);
    fsize = fsize * (dpi / 72.f) / (real32_t)PANGO_SCALE;
    return (uint32_t)fsize;
}

/*---------------------------------------------------------------------------*/

static real32_t i_font_pt(const real32_t fsize, const uint32_t fstyle)
{
    if ((fstyle & ekFPOINTS) == ekFPOINTS)
    {
        return fsize;
    }
    else
    {
        PangoFontMap *fontmap = pango_cairo_font_map_get_default();
        real32_t dpi = (real32_t)pango_cairo_font_map_get_resolution((PangoCairoFontMap *)fontmap);
        return fsize / (dpi / 72.f);
    }
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_font_desc(GtkWidget *widget, const char_t *css_type, const char_t *ffamily, const real32_t fsize, const uint32_t fstyle, GtkCssProvider **css_prov)
{
    real32_t ptsize = i_font_pt(fsize, fstyle);
    const char *italic = (fstyle & ekFITALIC) ? "italic" : "normal";
    const char *bold = (fstyle & ekFBOLD) ? "bold" : "normal";
    Stream *stm = stm_memory(256);
    String *css = NULL;

    stm_printf(stm, "%s { ", css_type);
    stm_printf(stm, "font-family: \"%s\"; ", ffamily);

#if GTK_CHECK_VERSION(3, 22, 0)
    stm_printf(stm, "font-size: %.2fpt; ", ptsize);
#elif GTK_CHECK_VERSION(3, 10, 0)
    stm_printf(stm, "font-size: %.2fpx; ", ptsize);
#else
    stm_printf(stm, "font-size: %.2f; ", ptsize);
#endif

    stm_printf(stm, "font-style: %s; ", italic);
    stm_printf(stm, "font-weight: %s; ", bold);

#if GTK_CHECK_VERSION(3, 22, 0)
    if (fstyle & ekFUNDERLINE)
    {
        if (fstyle & ekFSTRIKEOUT)
            stm_printf(stm, "text-decoration-line: underline | line-through; ");
        else
            stm_printf(stm, "text-decoration-line: underline; ");
    }
    else if (fstyle & ekFSTRIKEOUT)
    {
        stm_printf(stm, "text-decoration-line: line-through; ");
    }
    else
    {
        stm_printf(stm, "text-decoration-line: none; ");
    }
#endif

    stm_printf(stm, "}");
    css = stm_str(stm);
    _oscontrol_widget_set_provider(widget, tc(css), css_prov);
    str_destroy(&css);
    stm_close(&stm);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_font(GtkWidget *widget, const char_t *css_type, const Font *font, GtkCssProvider **css_prov)
{
    PangoFontDescription *fdesc = (PangoFontDescription *)font_native(font);
    const char *ffamily = pango_font_description_get_family(fdesc);
    real32_t fsize = font_size(font);
    uint32_t fstyle = font_style(font);
    _oscontrol_widget_font_desc(widget, css_type, ffamily, fsize, fstyle, css_prov);
}

/*---------------------------------------------------------------------------*/

void _oscontrol_widget_size(GtkWidget *widget, real32_t *width, real32_t *height)
{
    GtkAllocation alloc;
    cassert_no_null(widget);
    cassert_no_null(width);
    cassert_no_null(height);
    i_widget_allocation(widget, &alloc);
    *width = (real32_t)alloc.width;
    *height = (real32_t)alloc.height;
}

/*---------------------------------------------------------------------------*/

color_t _oscontrol_from_gdkrgba(const GdkRGBA *gdkcolor)
{
    return color_rgba(
        (uint8_t)(gdkcolor->red * 255.),
        (uint8_t)(gdkcolor->green * 255.),
        (uint8_t)(gdkcolor->blue * 255.),
        (uint8_t)(gdkcolor->alpha * 255.));
}

/*---------------------------------------------------------------------------*/

void _oscontrol_to_gdkrgba(const color_t color, GdkRGBA *gdkcolor)
{
    if (color != kCOLOR_TRANSPARENT)
    {
        real32_t r, g, b, a;
        color_get_rgbaf(color, &r, &g, &b, &a);
        gdkcolor->red = (double)r;
        gdkcolor->green = (double)g;
        gdkcolor->blue = (double)b;
        gdkcolor->alpha = (double)a;
    }
    else
    {
        gdkcolor->red = 0;
        gdkcolor->green = 0;
        gdkcolor->blue = 0;
        gdkcolor->alpha = 0;
    }
}

/*---------------------------------------------------------------------------*/

void _oscontrol_to_css_rgb(const color_t color, char_t *css, const uint32_t size)
{
    uint8_t r, g, b;
    color_get_rgb(color, &r, &g, &b);
    bstd_sprintf(css, size, "rgb(%d,%d,%d)", r, g, b);
}

/*---------------------------------------------------------------------------*/

GtkJustification _oscontrol_justification(const align_t align)
{
    switch (align)
    {
    case ekLEFT:
        return GTK_JUSTIFY_LEFT;
    case ekCENTER:
        return GTK_JUSTIFY_CENTER;
    case ekJUSTIFY:
        return GTK_JUSTIFY_FILL;
    case ekRIGHT:
        return GTK_JUSTIFY_RIGHT;
        cassert_default();
    }

    return GTK_JUSTIFY_LEFT;
}

/*---------------------------------------------------------------------------*/

gui_type_t oscontrol_type(const OSControl *control)
{
    cassert_no_null(control);
    return control->type;
}

/*---------------------------------------------------------------------------*/

OSControl *oscontrol_parent(const OSControl *control)
{
    GtkWidget *parentWidget = NULL;
    OSControl *parent = NULL;
    cassert_no_null(control);
    parentWidget = gtk_widget_get_parent(control->widget);
    /*const gchar *ptype = G_OBJECT_TYPE_NAME(parentWidget);*/
    parent = (OSControl *)g_object_get_data(G_OBJECT(parentWidget), "OSControl");
    return parent;
}

/*---------------------------------------------------------------------------*/

void oscontrol_frame(const OSControl *control, OSFrame *rect)
{
    real32_t x, y, w, h;
    cassert_no_null(rect);
    _oscontrol_get_origin(control, &x, &y);
    _oscontrol_get_size(control, &w, &h);
    rect->left = (int32_t)x;
    rect->top = (int32_t)y;
    rect->right = (int32_t)(x + w);
    rect->bottom = (int32_t)(y + h);
}

/*---------------------------------------------------------------------------*/

OSWidget *oscontrol_focus_widget(const OSControl *control)
{
    cassert_no_null(control);
    switch (control->type)
    {
    case ekGUI_TYPE_LABEL:
    case ekGUI_TYPE_PROGRESS:
        return NULL;

    case ekGUI_TYPE_SLIDER:
    case ekGUI_TYPE_UPDOWN:
        return (OSWidget *)control->widget;

    case ekGUI_TYPE_TEXTVIEW:
        return (OSWidget *)_ostext_focus_widget((OSText *)control);

    case ekGUI_TYPE_CUSTOMVIEW:
        return (OSWidget *)_osview_focus_widget((OSView *)control);

    case ekGUI_TYPE_EDITBOX:
        return (OSWidget *)_osedit_focus_widget((OSEdit *)control);

    case ekGUI_TYPE_BUTTON:
        return (OSWidget *)_osbutton_focus_widget((OSButton *)control);

    case ekGUI_TYPE_POPUP:
        return (OSWidget *)_ospopup_focus_widget((OSPopUp *)control);

    case ekGUI_TYPE_COMBOBOX:
        return (OSWidget *)_oscombo_focus_widget((OSCombo *)control);

    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

bool_t oscontrol_widget_visible(const OSWidget *widget)
{
    cassert_no_null(widget);
    return (bool_t)gtk_widget_get_visible((GtkWidget *)widget);
}

/*---------------------------------------------------------------------------*/

bool_t oscontrol_widget_enable(const OSWidget *widget)
{
    cassert_no_null(widget);
    return (bool_t)gtk_widget_is_sensitive((GtkWidget *)widget);
}
