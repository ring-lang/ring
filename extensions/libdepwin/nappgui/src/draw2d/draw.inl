/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw.inl
 *
 */

/* Drawing commands */

#include "draw2d.ixx"

__EXTERN_C

void draw_alloc_globals(void);

void draw_dealloc_globals(void);

void draw_word_extents(MeasureStr *data, const char_t *word, real32_t *width, real32_t *height);

void draw_imgimp(DCtx *ctx, const OSImage *image, const uint32_t frame_index, const real32_t x, const real32_t y, const bool_t raster);

__END_C
