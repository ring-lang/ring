/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscolor.inl
 *
 */

/* Color */

#include "osgui_osx.ixx"

void oscolor_init(void);

void oscolor_finish(void);

color_t oscolor_from_NSColor(NSColor *color);

void oscolor_NSColor_rgba(NSColor *color, CGFloat *r, CGFloat *g, CGFloat *b, CGFloat *a);

void oscolor_NSColor_rgba_v(NSColor *color, CGFloat *rgba);

NSColor *oscolor_NSColor(const color_t color);
