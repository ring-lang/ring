/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw2d.inl
 *
 */

/* Operating system 2D drawing support */

#include "draw2d.ixx"

__EXTERN_C

uint32_t draw2d_register_font(const char_t *font_family);

const char_t *draw2d_font_family(const uint32_t family);

color_t draw2d_get_indexed_color(const uint16_t index);

void draw2d_extents_imp(void *data, FPtr_word_extents func_word_extents, const bool_t newlines, const char_t *str, const real32_t refwidth, real32_t *width, real32_t *height);

__END_C

#define draw2d_extents(data, func_word_extents, newlines, str, refwidth, width, height, type) \
    ((void)((type *)(data) == (data)), \
     FUNC_CHECK_WORD_EXTENTS(func_word_extents, type), \
     draw2d_extents_imp((void *)data, (FPtr_word_extents)func_word_extents, newlines, str, refwidth, width, height))
