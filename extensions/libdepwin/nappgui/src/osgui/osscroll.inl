/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osscroll.inl
 *
 */

/* Operating System native scrollbar */

#include "osgui.ixx"

__EXTERN_C

OSScroll *osscroll_horizontal(OSControl *control);

OSScroll *osscroll_vertical(OSControl *control);

void osscroll_destroy(OSScroll **scroll, OSControl *control);

uint32_t osscroll_pos(const OSScroll *scroll);

uint32_t osscroll_trackpos(const OSScroll *scroll);

uint32_t osscroll_bar_width(const OSScroll *scroll);

uint32_t osscroll_bar_height(const OSScroll *scroll);

void osscroll_set_pos(OSScroll *scroll, const uint32_t pos);

void osscroll_visible(OSScroll *scroll, const bool_t visible);

void osscroll_config(OSScroll *scroll, const uint32_t pos, const uint32_t max, const uint32_t page);

void osscroll_frame(OSScroll *scroll, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height);

void osscroll_control_scroll(OSControl *control, const int32_t incr_x, const int32_t incr_y);

__END_C
