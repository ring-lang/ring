/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: font.h
 * https://nappgui.com/en/draw2d/font.html
 *
 */

/* Fonts */

#include "draw2d.hxx"

__EXTERN_C

_draw2d_api Font *font_create(const char_t *family, const real32_t size, const uint32_t style);

_draw2d_api Font *font_system(const real32_t size, const uint32_t style);

_draw2d_api Font *font_monospace(const real32_t size, const uint32_t style);

_draw2d_api Font *font_with_style(const Font *font, const uint32_t style);

_draw2d_api Font *font_copy(const Font *font);

_draw2d_api void font_destroy(Font **font);

_draw2d_api bool_t font_equals(const Font *font1, const Font *font2);

_draw2d_api real32_t font_regular_size(void);

_draw2d_api real32_t font_small_size(void);

_draw2d_api real32_t font_mini_size(void);

_draw2d_api const char_t *font_family(const Font *font);

_draw2d_api real32_t font_size(const Font *font);

_draw2d_api real32_t font_height(const Font *font);

_draw2d_api real32_t font_leading(const Font *font);

_draw2d_api uint32_t font_style(const Font *font);

_draw2d_api void font_extents(const Font *font, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height);

_draw2d_api bool_t font_exists_family(const char_t *family);

_draw2d_api ArrPt(String) *font_installed_families(void);

_draw2d_api const void *font_native(const Font *font);

__END_C
