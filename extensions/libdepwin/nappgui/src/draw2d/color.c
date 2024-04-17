/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: color.c
 *
 */

/* Color */

#include "color.h"
#include "draw2d.inl"
#include <core/strings.h>
#include <sewer/bmath.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#define i_red(rgba) (uint8_t)(rgba)
#define i_green(rgba) (uint8_t)(rgba >> 8)
#define i_blue(rgba) (uint8_t)(rgba >> 16)
#define i_alpha(rgba) (uint8_t)(rgba >> 24)
#define i_redf(rgba) (real32_t)((uint8_t)(rgba) / 255.f)
#define i_greenf(rgba) (real32_t)((uint8_t)(rgba >> 8) / 255.f)
#define i_bluef(rgba) (real32_t)((uint8_t)(rgba >> 16) / 255.f)
#define i_alphaf(rgba) (real32_t)((uint8_t)(rgba >> 24) / 255.f)
#define i_rgb(r, g, b) (color_t)(((255) << 24) | ((b) << 16) | ((g) << 8) | (r))

const color_t kCOLOR_TRANSPARENT = 0;
const color_t kCOLOR_DEFAULT = 0;
const color_t kCOLOR_BLACK = 0xFF000000;
const color_t kCOLOR_WHITE = 0xFFFFFFFF;
const color_t kCOLOR_RED = 0xFF0000FF;
const color_t kCOLOR_GREEN = 0xFF00FF00;
const color_t kCOLOR_BLUE = 0xFFFF0000;
const color_t kCOLOR_YELLOW = 0xFF00FFFF;
const color_t kCOLOR_CYAN = 0xFFFFFF00;
const color_t kCOLOR_MAGENTA = 0xFFFF00FF;

/*---------------------------------------------------------------------------*/

color_t color_rgb(const uint8_t r, const uint8_t g, const uint8_t b)
{
    return i_rgb(r, g, b);
}

/*---------------------------------------------------------------------------*/

color_t color_rgba(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a)
{
    return (color_t)(((a) << 24) | ((b) << 16) | ((g) << 8) | (r));
}

/*---------------------------------------------------------------------------*/

color_t color_rgbaf(const real32_t r, const real32_t g, const real32_t b, const real32_t a)
{
    register uint8_t ru = (uint8_t)(r * 255.f);
    register uint8_t gu = (uint8_t)(g * 255.f);
    register uint8_t bu = (uint8_t)(b * 255.f);
    register uint8_t au = (uint8_t)(a * 255.f);
    cassert(a != 0);
    return (color_t)(((au) << 24) | ((bu) << 16) | ((gu) << 8) | (ru));
}

/*---------------------------------------------------------------------------*/

color_t color_hsbf(const real32_t hue, const real32_t sat, const real32_t bright)
{
    cassert(hue >= 0 && hue <= 1);
    cassert(sat >= 0 && sat <= 1);
    cassert(bright >= 0 && bright <= 1);

    if (bright == 0)
        return kCOLOR_BLACK;

    if (sat == 0)
    {
        uint8_t grey = (uint8_t)(bright * 255.f);
        return i_rgb(grey, grey, grey);
    }

    {
        real32_t hue_domain = hue * 6.0f;
        uint16_t domain;
        real32_t f1, f2, f3;

        if (hue_domain >= 6.f)
            hue_domain = 0;

        domain = (uint16_t)hue_domain;

        f1 = bright * (1 - sat);
        f2 = bright * (1 - sat * (hue_domain - (real32_t)domain));
        f3 = bright * (1 - sat * (1 - (hue_domain - (real32_t)domain)));

        switch (domain)
        {
        case 0:
            return i_rgb((uint8_t)(bright * 255.f), (uint8_t)(f3 * 255.f), (uint8_t)(f1 * 255.f));

        case 1:
            return i_rgb((uint8_t)(f2 * 255.f), (uint8_t)(bright * 255.f), (uint8_t)(f1 * 255.f));

        case 2:
            return i_rgb((uint8_t)(f1 * 255.f), (uint8_t)(bright * 255.f), (uint8_t)(f3 * 255.f));

        case 3:
            return i_rgb((uint8_t)(f1 * 255.f), (uint8_t)(f2 * 255.f), (uint8_t)(bright * 255.f));

        case 4:
            return i_rgb((uint8_t)(f3 * 255.f), (uint8_t)(f1 * 255.f), (uint8_t)(bright * 255.f));

        case 5:
            return i_rgb((uint8_t)(bright * 255.f), (uint8_t)(f1 * 255.f), (uint8_t)(f2 * 255.f));

            cassert_default();
        }
    }

    return kCOLOR_BLACK;
}

/*---------------------------------------------------------------------------*/

color_t color_red(const uint8_t r)
{
    return i_rgb(r, 0, 0);
}

/*---------------------------------------------------------------------------*/

color_t color_green(const uint8_t g)
{
    return i_rgb(0, g, 0);
}

/*---------------------------------------------------------------------------*/

color_t color_blue(const uint8_t b)
{
    return i_rgb(0, 0, b);
}

/*---------------------------------------------------------------------------*/

color_t color_gray(const uint8_t l)
{
    return i_rgb(l, l, l);
}

/*---------------------------------------------------------------------------*/

color_t color_bgr(const uint32_t bgr)
{
    return (color_t)((uint32_t)((255) << 24) | (uint32_t)(((bgr)&0x000000FF) << 16) | (uint32_t)((bgr)&0x0000FF00) | (uint32_t)(((bgr)&0x00FF0000) >> 16));
}

/*---------------------------------------------------------------------------*/

color_t color_html(const char_t *html)
{
    uint32_t col;
    cassert_no_null(html);
    if (html[0] == '#')
        html++;
    col = str_to_u32(html, 16, NULL);
    return color_bgr(col);
}

/*---------------------------------------------------------------------------*/

static __INLINE color_t i_effective(color_t c)
{
    if (i_alpha(c) == 0)
    {
        cassert(c <= 0xFFFF);
        return draw2d_get_indexed_color((uint16_t)c);
    }
    else
    {
        return c;
    }
}

/*---------------------------------------------------------------------------*/

void color_to_hsbf(const color_t color, real32_t *hue, real32_t *sat, real32_t *bright)
{
    const real32_t i_TOL = 1e-6f;
    real32_t r = (real32_t)i_red(color) / 255.f;
    real32_t g = (real32_t)i_green(color) / 255.f;
    real32_t b = (real32_t)i_blue(color) / 255.f;
    real32_t min = r, max = r;
    real32_t delta;

    cassert_no_null(hue);
    cassert_no_null(sat);
    cassert_no_null(bright);

    /* Very improbable */
    if (i_alpha(color) == 0)
    {
        register color_t c = i_effective(color);
        r = (real32_t)i_red(c) / 255.f;
        g = (real32_t)i_green(c) / 255.f;
        b = (real32_t)i_blue(c) / 255.f;
        min = r;
        max = r;
    }

    if (g < min)
        min = g;
    if (b < min)
        min = b;
    if (g > max)
        max = g;
    if (b > max)
        max = b;

    delta = max - min;
    *bright = max;

    /* Grey */
    if (delta < i_TOL)
    {
        *hue = 0;
        *sat = 0;
    }
    /* Color */
    else
    {
        real32_t deltaR, deltaG, deltaB;

        cassert(max > 0);
        *sat = delta / max;

        deltaR = (((max - r) / 6.0f) + (delta / 2.0f)) / delta;
        deltaG = (((max - g) / 6.0f) + (delta / 2.0f)) / delta;
        deltaB = (((max - b) / 6.0f) + (delta / 2.0f)) / delta;

        if (bmath_absf(r - max) < i_TOL)
            *hue = deltaB - deltaG;
        else if (bmath_absf(g - max) < i_TOL)
            *hue = 0.3333333f + deltaR - deltaB;
        else if (bmath_absf(b - max) < i_TOL)
            *hue = 0.6666667f + deltaG - deltaR;

        if (*hue < 0)
            *hue += 1.f;
        else if (*hue > 1.0f)
            *hue -= 1.f;
    }
}

/*---------------------------------------------------------------------------*/

void color_to_html(const color_t color, char_t *html, const uint32_t size)
{
    register color_t c = color;
    if (i_alpha(c) == 0)
        c = i_effective(c);
    bstd_sprintf(html, size, "#%02X%02X%02X", i_red(c), i_green(c), i_blue(c));
}

/*---------------------------------------------------------------------------*/

void color_get_rgb(const color_t color, uint8_t *r, uint8_t *g, uint8_t *b)
{
    register color_t c = color;
    if (i_alpha(c) == 0)
        c = i_effective(c);
    ptr_assign(r, i_red(c));
    ptr_assign(g, i_green(c));
    ptr_assign(b, i_blue(c));
}

/*---------------------------------------------------------------------------*/

void color_get_rgbf(const color_t color, real32_t *r, real32_t *g, real32_t *b)
{
    register color_t c = color;
    if (i_alpha(c) == 0)
        c = i_effective(c);
    ptr_assign(r, i_redf(c));
    ptr_assign(g, i_greenf(c));
    ptr_assign(b, i_bluef(c));
}

/*---------------------------------------------------------------------------*/

void color_get_rgba(const color_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a)
{
    register color_t c = color;
    if (i_alpha(c) == 0)
        c = i_effective(c);
    ptr_assign(r, i_red(c));
    ptr_assign(g, i_green(c));
    ptr_assign(b, i_blue(c));
    ptr_assign(a, i_alpha(c));
}

/*---------------------------------------------------------------------------*/

void color_get_rgbaf(const color_t color, real32_t *r, real32_t *g, real32_t *b, real32_t *a)
{
    register color_t c = color;
    if (i_alpha(c) == 0)
        c = i_effective(c);
    ptr_assign(r, i_redf(c));
    ptr_assign(g, i_greenf(c));
    ptr_assign(b, i_bluef(c));
    ptr_assign(a, i_alphaf(c));
}

/*---------------------------------------------------------------------------*/

uint8_t color_get_alpha(const color_t color)
{
    uint8_t a = i_alpha(color);
    if (a == 0)
    {
        color_t c = i_effective(color);
        return i_alpha(c);
    }
    return a;
}

/*---------------------------------------------------------------------------*/

color_t color_set_alpha(const color_t color, const uint8_t alpha)
{
    color_t c = color;
    if (i_alpha(color) == 0)
        c = i_effective(color);
    return (color_t)(((uint32_t)c & 0x00FFFFFF) | ((uint32_t)alpha << 24));
}
