/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscontrol_osx.inl
 *
 */

/* Cocoa control */

#include "osgui_osx.ixx"

void _oscontrol_init(NSView *control);

void _oscontrol_origin_in_screen_coordinates(const NSRect *frame, CGFloat *x, CGFloat *y);

NSTextAlignment _oscontrol_text_alignment(const align_t halign);

void _oscontrol_size_from_font(NSCell *cell, const Font *font);

void _oscontrol_cell_set_control_size(NSCell *cell, const gui_size_t size);

NSControlSize _oscontrol_control_size(const gui_size_t size);

void _oscontrol_cell_set_image(NSCell *cell, const Image *image);

void _oscontrol_text_bounds(const Font *font, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height);

void _oscontrol_tooltip_set(NSView *view, const char_t *text);

NSColor *_oscontrol_color(const color_t color);

color_t _oscontrol_from_NSColor(NSColor *color);

void _oscontrol_init_textattr(OSTextAttr *attr);

void _oscontrol_remove_textattr(OSTextAttr *attr);

void _oscontrol_set_text(NSControl *control, const OSTextAttr *attrs, const char_t *text);

void _oscontrol_set_font(NSControl *control, OSTextAttr *attrs, const Font *font);

void _oscontrol_set_align(NSControl *control, OSTextAttr *attrs, const align_t align);

void _oscontrol_set_text_color(NSTextField *control, OSTextAttr *attrs, const color_t color);

void _oscontrol_attach_to_parent(NSView *control, NSView *parent);

void _oscontrol_detach_from_parent(NSView *control, NSView *parent);

void _oscontrol_set_visible(NSView *object, const bool_t is_visible);

void _oscontrol_set_enabled(NSControl *object, const bool_t is_enabled);

void _oscontrol_get_size(const NSView *object, real32_t *width, real32_t *height);

void _oscontrol_get_origin(const NSView *object, real32_t *x, real32_t *y);

void _oscontrol_set_frame(NSView *object, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

OSControl *_oscontrol_from_nsview(NSView *object);
