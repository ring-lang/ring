/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: palette.c
 *
 */

/* Color palette */

#include "palette.h"
#include "color.h"
#include <core/heap.h>
#include <sewer/cassert.h>

struct _palette_t
{
    uint16_t flags;
    uint16_t size;
};

/*---------------------------------------------------------------------------*/

Palette *palette_create(const uint32_t size)
{
    uint32_t n = sizeof32(Palette) + size * sizeof32(color_t);
    Palette *palette = (Palette *)heap_malloc(n, "Palette");
    palette->flags = 0;
    palette->size = (uint16_t)size;
    return palette;
}

/*---------------------------------------------------------------------------*/

Palette *palette_cga2(const bool_t mode, const bool_t intense)
{
    Palette *palette = palette_create(4);
    color_t *colors = palette_colors(palette);

    if (mode == FALSE)
    {
        if (intense == TRUE)
        {
            colors[0] = color_rgb(0, 0, 0);
            colors[1] = color_rgb(0x55, 0xff, 0x55);
            colors[2] = color_rgb(0xff, 0x55, 0x55);
            colors[3] = color_rgb(0xff, 0xff, 0x55);
        }
        else
        {
            colors[0] = color_rgb(0, 0, 0);
            colors[1] = color_rgb(0x00, 0xaa, 0x00);
            colors[2] = color_rgb(0xaa, 0x00, 0x00);
            colors[3] = color_rgb(0xaa, 0x55, 0x00);
        }
    }
    else
    {
        if (intense == TRUE)
        {
            colors[0] = color_rgb(0, 0, 0);
            colors[1] = color_rgb(0x55, 0xff, 0xff);
            colors[2] = color_rgb(0xff, 0x55, 0xff);
            colors[3] = color_rgb(0xff, 0xff, 0xff);
        }
        else
        {
            colors[0] = color_rgb(0, 0, 0);
            colors[1] = color_rgb(0x00, 0xaa, 0xaa);
            colors[2] = color_rgb(0xaa, 0x00, 0xaa);
            colors[3] = color_rgb(0xaa, 0xaa, 0xaa);
        }
    }

    return palette;
}

/*---------------------------------------------------------------------------*/

Palette *palette_ega4(void)
{
    Palette *palette = palette_create(16);
    color_t *colors = palette_colors(palette);
    colors[0] = color_rgb(0x00, 0x00, 0x00);
    colors[1] = color_rgb(0x00, 0x00, 0xaa);
    colors[2] = color_rgb(0x00, 0xaa, 0x00);
    colors[3] = color_rgb(0x00, 0xaa, 0xaa);
    colors[4] = color_rgb(0xaa, 0x00, 0x00);
    colors[5] = color_rgb(0xaa, 0x00, 0xaa);
    colors[6] = color_rgb(0xaa, 0x55, 0x00);
    colors[7] = color_rgb(0xaa, 0xaa, 0xaa);
    colors[8] = color_rgb(0x55, 0x55, 0x55);
    colors[9] = color_rgb(0x55, 0x55, 0xff);
    colors[10] = color_rgb(0x55, 0xff, 0x55);
    colors[11] = color_rgb(0x55, 0xff, 0xff);
    colors[12] = color_rgb(0xff, 0x55, 0x55);
    colors[13] = color_rgb(0xff, 0x55, 0xff);
    colors[14] = color_rgb(0xff, 0xff, 0x55);
    colors[15] = color_rgb(0xff, 0xff, 0xff);
    return palette;
}

/*---------------------------------------------------------------------------*/

Palette *palette_rgb8(void)
{
    Palette *palette = palette_create(256);
    color_t *colors = palette_colors(palette);
    register uint32_t i;
    for (i = 0; i < 256; ++i)
    {
        uint8_t r = (uint8_t)(i & 7);
        uint8_t g = (uint8_t)((i & 56) >> 3);
        uint8_t b = (uint8_t)((i & 192) >> 6);

        if (r == 7)
            r = 0xFF;
        else
            r *= 0x24;

        if (g == 7)
            g = 0xFF;
        else
            g *= 0x24;

        b *= 0x55;

        colors[i] = color_rgb(r, g, b);
    }
    return palette;
}

/*---------------------------------------------------------------------------*/

Palette *palette_gray1(void)
{
    Palette *palette = palette_create(2);
    color_t *colors = palette_colors(palette);
    colors[0] = color_gray(0);
    colors[1] = color_gray(255);
    return palette;
}

/*---------------------------------------------------------------------------*/

Palette *palette_gray2(void)
{
    Palette *palette = palette_create(4);
    color_t *colors = palette_colors(palette);
    colors[0] = color_gray(0x00);
    colors[1] = color_gray(0x55);
    colors[2] = color_gray(0xaa);
    colors[3] = color_gray(0xff);
    return palette;
}

/*---------------------------------------------------------------------------*/

Palette *palette_gray4(void)
{
    Palette *palette = palette_create(16);
    color_t *colors = palette_colors(palette);
    colors[0] = color_gray(0);
    colors[1] = color_gray(17);
    colors[2] = color_gray(34);
    colors[3] = color_gray(51);
    colors[4] = color_gray(68);
    colors[5] = color_gray(85);
    colors[6] = color_gray(102);
    colors[7] = color_gray(119);
    colors[8] = color_gray(136);
    colors[9] = color_gray(153);
    colors[10] = color_gray(170);
    colors[11] = color_gray(187);
    colors[12] = color_gray(204);
    colors[13] = color_gray(221);
    colors[14] = color_gray(238);
    colors[15] = color_gray(255);
    return palette;
}

/*---------------------------------------------------------------------------*/

Palette *palette_gray8(void)
{
    Palette *palette = palette_create(16);
    color_t *colors = palette_colors(palette);
    register uint32_t i;
    for (i = 0; i < 256; ++i)
        colors[i] = color_gray((uint8_t)i);
    return palette;
}

/*---------------------------------------------------------------------------*/

Palette *palette_binary(const color_t zero, const color_t one)
{
    Palette *palette = palette_create(2);
    color_t *colors = palette_colors(palette);
    colors[0] = zero;
    colors[1] = one;
    return palette;
}

/*---------------------------------------------------------------------------*/

void palette_destroy(Palette **palette)
{
    uint32_t n;
    cassert_no_null(palette);
    cassert_no_null(*palette);
    n = sizeof32(Palette) + (*palette)->size * sizeof32(color_t);
    heap_free((byte_t **)palette, n, "Palette");
}

/*---------------------------------------------------------------------------*/

uint32_t palette_size(const Palette *palette)
{
    cassert_no_null(palette);
    return palette->size;
}

/*---------------------------------------------------------------------------*/

color_t *palette_colors(Palette *palette)
{
    cassert_no_null(palette);
    return (color_t *)(((byte_t *)palette) + sizeof(Palette));
}

/*---------------------------------------------------------------------------*/

const color_t *palette_ccolors(const Palette *palette)
{
    cassert_no_null(palette);
    return (color_t *)(((byte_t *)palette) + sizeof(Palette));
}
