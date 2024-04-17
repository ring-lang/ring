/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: scrollview.inl
 *
 */

/* Scroll views common functionality */

#include "gui.ixx"

__EXTERN_C

ScrollView *scrollview_create(View *view);

void scrollview_destroy(ScrollView **view);

uint32_t scrollview_content_width(const ScrollView *view);

uint32_t scrollview_content_height(const ScrollView *view);

uint32_t scrollview_control_width(const ScrollView *view);

uint32_t scrollview_control_height(const ScrollView *view);

uint32_t scrollview_scrollbar_width(const ScrollView *view);

uint32_t scrollview_scrollbar_height(const ScrollView *view);

uint32_t scrollview_xpos(const ScrollView *view);

uint32_t scrollview_ypos(const ScrollView *view);

void scrollview_control_size(ScrollView *view, const uint32_t control_width, const uint32_t control_height);

void scrollview_content_size(ScrollView *view, const uint32_t content_width, const uint32_t content_height, const uint32_t line_width, const uint32_t line_height);

void scrollview_scroll_x(ScrollView *view, const uint32_t xpos, const bool_t redraw);

void scrollview_scroll_x_incr(ScrollView *view, const int32_t incr_x, const bool_t redraw);

bool_t scrollview_scroll_y_visible(ScrollView *view, const uint32_t ypos, const bool_t redraw);

void scrollview_update(ScrollView *view);

__END_C
