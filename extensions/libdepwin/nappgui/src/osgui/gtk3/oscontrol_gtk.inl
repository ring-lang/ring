/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscontrol_gtk.inl
 *
 */

/* Gtk Widgets common functions */

#include "osgui_gtk.ixx"

__EXTERN_C

void _oscontrol_init(OSControl *control, const gui_type_t type, GtkWidget *widget, GtkWidget *focus_widget, const bool_t show);

void _oscontrol_destroy(OSControl *control);

void _oscontrol_set_halign(OSControl *control, const align_t align);

void _oscontrol_text_bounds(const OSControl *control, PangoLayout *layout, const char_t *text, const Font *font, const real32_t refwidth, real32_t *width, real32_t *height);

void _oscontrol_set_visible(OSControl *control, const bool_t is_visible);

void _oscontrol_set_enabled(OSControl *control, const bool_t is_enabled);

void _oscontrol_get_origin(const OSControl *control, real32_t *x, real32_t *y);

void _oscontrol_get_size(const OSControl *control, real32_t *width, real32_t *height);

void _oscontrol_set_frame(OSControl *control, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

void _oscontrol_attach_to_parent(OSControl *control, GtkWidget *parent_widget);

void _oscontrol_detach_from_parent(OSControl *control, GtkWidget *parent_widget);

void _oscontrol_widget_detach(GtkWidget *widget, GtkWidget *parent_widget);

uint32_t _oscontrol_num_children(GtkContainer *container);

GtkWidget *_oscontrol_get_child(GtkContainer *container, const uint32_t index);

void _oscontrol_widget_set_css(GtkWidget *widget, const char_t *css);

void _oscontrol_widget_set_provider(GtkWidget *widget, const char_t *css, GtkCssProvider **css_prov);

void _oscontrol_widget_add_provider(GtkWidget *widget, GtkCssProvider *css_prov);

void _oscontrol_widget_remove_provider(GtkWidget *widget, GtkCssProvider *css_prov);

void _oscontrol_widget_color(GtkWidget *widget, const char_t *css_type, const color_t color, GtkCssProvider **css_provider);

void _oscontrol_widget_bg_color(GtkWidget *widget, const char_t *css_type, const color_t color, GtkCssProvider **css_provider);

uint32_t _oscontrol_widget_font_size(GtkWidget *widget);

void _oscontrol_widget_font_desc(GtkWidget *widget, const char_t *css_type, const char_t *ffamily, const real32_t fsize, const uint32_t fstyle, GtkCssProvider **css_prov);

void _oscontrol_widget_font(GtkWidget *widget, const char_t *css_type, const Font *font, GtkCssProvider **css_prov);

void _oscontrol_widget_size(GtkWidget *widget, real32_t *width, real32_t *height);

bool_t _oscontrol_widget_mouse_over(GtkWidget *widget, GdkEvent *event);

bool_t _oscontrol_widget_mouse_over_right(GtkWidget *widget, GdkEvent *event, gint right_px);

color_t _oscontrol_from_gdkrgba(const GdkRGBA *gdkcolor);

void _oscontrol_to_gdkrgba(const color_t color, GdkRGBA *gdkcolor);

void _oscontrol_to_css_rgb(const color_t color, char_t *css, const uint32_t size);

GtkJustification _oscontrol_justification(const align_t align);

__END_C
