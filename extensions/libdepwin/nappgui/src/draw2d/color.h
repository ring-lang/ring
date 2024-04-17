/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: color.h
 * https://nappgui.com/en/draw2d/color.html
 *
 */

/* Color */

#include "draw2d.hxx"

__EXTERN_C

_draw2d_api color_t color_rgb(const uint8_t r, const uint8_t g, const uint8_t b);

_draw2d_api color_t color_rgba(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a);

_draw2d_api color_t color_rgbaf(const real32_t r, const real32_t g, const real32_t b, const real32_t a);

_draw2d_api color_t color_hsbf(const real32_t hue, const real32_t sat, const real32_t bright);

_draw2d_api color_t color_red(const uint8_t r);

_draw2d_api color_t color_green(const uint8_t g);

_draw2d_api color_t color_blue(const uint8_t b);

_draw2d_api color_t color_gray(const uint8_t l);

_draw2d_api color_t color_bgr(const uint32_t bgr);

_draw2d_api color_t color_html(const char_t *html);

_draw2d_api color_t color_indexed(const uint16_t index, const color_t color);

_draw2d_api void color_to_hsbf(const color_t color, real32_t *hue, real32_t *sat, real32_t *bright);

_draw2d_api void color_to_html(const color_t color, char_t *html, const uint32_t size);

_draw2d_api void color_get_rgb(const color_t color, uint8_t *r, uint8_t *g, uint8_t *b);

_draw2d_api void color_get_rgbf(const color_t color, real32_t *r, real32_t *g, real32_t *b);

_draw2d_api void color_get_rgba(const color_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a);

_draw2d_api void color_get_rgbaf(const color_t color, real32_t *r, real32_t *g, real32_t *b, real32_t *a);

_draw2d_api uint8_t color_get_alpha(const color_t color);

_draw2d_api color_t color_set_alpha(const color_t color, const uint8_t alpha);

_draw2d_api extern const color_t kCOLOR_TRANSPARENT;

_draw2d_api extern const color_t kCOLOR_DEFAULT;

_draw2d_api extern const color_t kCOLOR_BLACK;

_draw2d_api extern const color_t kCOLOR_WHITE;

_draw2d_api extern const color_t kCOLOR_RED;

_draw2d_api extern const color_t kCOLOR_GREEN;

_draw2d_api extern const color_t kCOLOR_BLUE;

_draw2d_api extern const color_t kCOLOR_YELLOW;

_draw2d_api extern const color_t kCOLOR_CYAN;

_draw2d_api extern const color_t kCOLOR_MAGENTA;

__END_C
