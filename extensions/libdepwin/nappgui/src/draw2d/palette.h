/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: palette.h
 * https://nappgui.com/en/draw2d/palette.html
 *
 */

/* Color palette */

#include "draw2d.hxx"

__EXTERN_C

_draw2d_api Palette *palette_create(const uint32_t size);

_draw2d_api Palette *palette_cga2(const bool_t mode, const bool_t intense);

_draw2d_api Palette *palette_ega4(void);

_draw2d_api Palette *palette_rgb8(void);

_draw2d_api Palette *palette_gray1(void);

_draw2d_api Palette *palette_gray2(void);

_draw2d_api Palette *palette_gray4(void);

_draw2d_api Palette *palette_gray8(void);

_draw2d_api Palette *palette_binary(const color_t zero, const color_t one);

_draw2d_api void palette_destroy(Palette **palette);

_draw2d_api uint32_t palette_size(const Palette *palette);

_draw2d_api color_t *palette_colors(Palette *palette);

_draw2d_api const color_t *palette_ccolors(const Palette *palette);

__END_C
