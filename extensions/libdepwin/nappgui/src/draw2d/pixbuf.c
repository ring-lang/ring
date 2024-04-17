/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: pixbuf.c
 *
 */

/* Pixel buffers */

#include "pixbuf.h"
#include "imgutil.inl"
#include <geom2d/t2d.h>
#include <core/heap.h>
#include <sewer/bmath.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _pixbuf_t
{
    uint32_t width;
    uint32_t height;
    pixformat_t format;
};

typedef uint32_t (*FPtr_get)(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width);
typedef void (*FPtr_set)(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value);

static uint32_t i_get1(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width);
static uint32_t i_get2(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width);
static uint32_t i_get4(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width);
static uint32_t i_get8(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width);
static uint32_t i_get24(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width);
static uint32_t i_get32(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width);
static void i_set1(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value);
static void i_set2(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value);
static void i_set4(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value);
static void i_set8(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value);
static void i_set24(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value);
static void i_set32(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value);

static const FPtr_get i_GET[] = {
    i_get1,  /* ekINDEX1 */
    i_get2,  /* ekINDEX2 */
    i_get4,  /* ekINDEX4 */
    i_get8,  /* ekINDEX8 */
    i_get8,  /* ekGRAY8 */
    i_get24, /* ekRGB24 */
    i_get32  /* ekRGBA32 */
};

static const FPtr_set i_SET[] = {
    i_set1,  /* ekINDEX1 */
    i_set2,  /* ekINDEX2 */
    i_set4,  /* ekINDEX4 */
    i_set8,  /* ekINDEX8 */
    i_set8,  /* ekGRAY8 */
    i_set24, /* ekRGB24 */
    i_set32  /* ekRGBA32 */
};

/*---------------------------------------------------------------------------*/

#define i_DATA(pixbuf) ((byte_t *)(pixbuf) + sizeof(Pixbuf))

/*---------------------------------------------------------------------------*/

static uint32_t i_bufsize(const uint32_t width, const uint32_t height, const pixformat_t format)
{
    register uint32_t n = 0;
    switch (format)
    {
    case ekINDEX1:
        n = width * height / 8;
        if ((width * height) % 8 != 0)
            n += 1;
        return n;

    case ekINDEX2:
        n = width * height / 4;
        if ((width * height) % 4 != 0)
            n += 1;
        return n;

    case ekINDEX4:
        n = width * height / 2;
        if ((width * height) % 2 != 0)
            n += 1;
        return n;

    case ekINDEX8:
    case ekGRAY8:
        return width * height;

    case ekRGB24:
        return width * height * 3;

    case ekRGBA32:
        return width * height * 4;

    case ekFIMAGE:
        cassert_default();
    }

    return n;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get1(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width)
{
    register byte_t b = data[(y * width + x) / 8];
    register byte_t pos = (byte_t)((y * width + x) % 8);
    return (uint32_t)((b >> pos) & 1);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get2(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width)
{
    register byte_t b = data[(y * width + x) / 4];
    register byte_t pos = (byte_t)((y * width + x) % 4);
    return (uint32_t)((b >> (pos * 2)) & 3);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get4(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width)
{
    register byte_t b = data[(y * width + x) / 2];
    register byte_t pos = (byte_t)((y * width + x) % 2);
    return (uint32_t)((b >> (pos * 4)) & 7);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get8(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width)
{
    return (uint32_t)data[y * width + x];
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get24(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width)
{
    register const byte_t *b = data + (y * width + x) * 3;
    return (uint32_t)(((255) << 24) | ((b[2]) << 16) | ((b[1]) << 8) | (b[0]));
}

/*---------------------------------------------------------------------------*/

static uint32_t i_get32(const byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width)
{
    register const byte_t *b = data + (y * width + x) * 4;
    return (uint32_t)(((b[3]) << 24) | ((b[2]) << 16) | ((b[1]) << 8) | (b[0]));
}

/*---------------------------------------------------------------------------*/

static void i_set1(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value)
{
    register byte_t *obyte = data + ((y * width) + x) / 8;
    register byte_t opos = (byte_t)(((y * width) + x) % 8);
    cassert(value < 2);
    *obyte &= ~(1 << opos);
    *obyte |= (value << opos);
}

/*---------------------------------------------------------------------------*/

static void i_set2(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value)
{
    register byte_t *obyte = data + ((y * width) + x) / 4;
    register byte_t opos = (byte_t)(((y * width) + x) % 4);
    cassert(value < 4);
    *obyte &= ~(3 << (opos * 2));
    *obyte |= (value << (opos * 2));
}

/*---------------------------------------------------------------------------*/

static void i_set4(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value)
{
    register byte_t *obyte = data + ((y * width) + x) / 2;
    register byte_t opos = (byte_t)(((y * width) + x) % 2);
    cassert(value < 16);
    *obyte &= ~(15 << (opos * 4));
    *obyte |= (value << (opos * 4));
}

/*---------------------------------------------------------------------------*/

static void i_set8(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value)
{
    register byte_t *obyte = data + ((y * width) + x);
    cassert(value < 256);
    *obyte = (byte_t)(value & 0xFF);
}

/*---------------------------------------------------------------------------*/

static void i_set24(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value)
{
    register byte_t *obyte = data + ((y * width) + x) * 3;
    obyte[0] = (byte_t)(value & 0xFF);
    obyte[1] = (byte_t)((value >> 8) & 0xFF);
    obyte[2] = (byte_t)((value >> 16) & 0xFF);
}

/*---------------------------------------------------------------------------*/

static void i_set32(byte_t *data, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t value)
{
    register uint32_t *ovalue = ((uint32_t *)data) + ((y * width) + x);
    *ovalue = value;
}

/*---------------------------------------------------------------------------*/

Pixbuf *pixbuf_create(const uint32_t width, const uint32_t height, const pixformat_t format)
{
    uint32_t n = sizeof32(Pixbuf) + i_bufsize(width, height, format);
    Pixbuf *pixbuf = (Pixbuf *)heap_malloc(n, "Pixbuf");
    pixbuf->width = width;
    pixbuf->height = height;
    pixbuf->format = format;
    return pixbuf;
}

/*---------------------------------------------------------------------------*/

Pixbuf *pixbuf_copy(const Pixbuf *pixbuf)
{
    Pixbuf *npixbuf = NULL;
    cassert_no_null(pixbuf);
    npixbuf = pixbuf_create(pixbuf->width, pixbuf->height, pixbuf->format);
    bmem_copy(i_DATA(npixbuf), i_DATA(pixbuf), i_bufsize(pixbuf->width, pixbuf->height, pixbuf->format));
    return npixbuf;
}

/*---------------------------------------------------------------------------*/

Pixbuf *pixbuf_trim(const Pixbuf *pixbuf, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height)
{
    Pixbuf *npixbuf = NULL;
    register const byte_t *sdata = NULL;
    register byte_t *data = NULL;
    register pixformat_t format;
    register uint32_t i, j, v, w;
    cassert_no_null(pixbuf);
    npixbuf = pixbuf_create(width, height, pixbuf->format);
    sdata = i_DATA(pixbuf);
    data = i_DATA(npixbuf);
    format = npixbuf->format;
    w = pixbuf->width;
    for (i = 0; i < width; ++i)
        for (j = 0; j < height; ++j)
        {
            v = i_GET[format](sdata, x + i, y + j, w);
            i_SET[format](data, i, j, width, v);
        }

    return npixbuf;
}

/*---------------------------------------------------------------------------*/

Pixbuf *pixbuf_convert(const Pixbuf *pixbuf, const Palette *palette, const pixformat_t oformat)
{
    cassert_no_null(pixbuf);
    unref(palette);
    if (pixbuf->format != oformat)
    {
        switch (pixbuf->format)
        {
        case ekRGBA32:
            switch (oformat)
            {
            case ekRGB24:
                return imgutil_rgba_to_rgb(i_DATA(pixbuf), pixbuf->width, pixbuf->height);

            case ekGRAY8:
                return imgutil_rgba_to_gray(i_DATA(pixbuf), pixbuf->width, pixbuf->height);

            case ekINDEX1:

            case ekINDEX2:
            case ekINDEX4:
            case ekINDEX8:
            case ekRGBA32:
            case ekFIMAGE:
                cassert_default();
            }
            break;

        case ekRGB24:
            switch (oformat)
            {
            case ekRGBA32:
                return imgutil_rgb_to_rgba(i_DATA(pixbuf), pixbuf->width, pixbuf->height);

            case ekGRAY8:
                return imgutil_rgb_to_gray(i_DATA(pixbuf), pixbuf->width, pixbuf->height);

            case ekINDEX1:
            case ekINDEX2:
            case ekINDEX4:
            case ekINDEX8:
            case ekRGB24:
            case ekFIMAGE:
                cassert_default();
            }
            break;

        case ekINDEX1:
        case ekINDEX2:
        case ekINDEX4:
        case ekINDEX8:
        case ekGRAY8:
        case ekFIMAGE:
            cassert_default();
        }
    }
    else
    {
        Pixbuf *npixbuf = pixbuf_create(pixbuf->width, pixbuf->height, pixbuf->format);
        bmem_copy(i_DATA(npixbuf), i_DATA(pixbuf), i_bufsize(pixbuf->width, pixbuf->height, pixbuf->format));
        return npixbuf;
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

void pixbuf_destroy(Pixbuf **pixbuf)
{
    uint32_t n;
    cassert_no_null(pixbuf);
    cassert_no_null(*pixbuf);
    n = sizeof32(Pixbuf) + i_bufsize((*pixbuf)->width, (*pixbuf)->height, (*pixbuf)->format);
    heap_free((byte_t **)pixbuf, n, "Pixbuf");
}

/*---------------------------------------------------------------------------*/

pixformat_t pixbuf_format(const Pixbuf *pixbuf)
{
    cassert_no_null(pixbuf);
    return pixbuf->format;
}

/*---------------------------------------------------------------------------*/

uint32_t pixbuf_width(const Pixbuf *pixbuf)
{
    cassert_no_null(pixbuf);
    return pixbuf->width;
}

/*---------------------------------------------------------------------------*/

uint32_t pixbuf_height(const Pixbuf *pixbuf)
{
    cassert_no_null(pixbuf);
    return pixbuf->height;
}

/*---------------------------------------------------------------------------*/

uint32_t pixbuf_size(const Pixbuf *pixbuf)
{
    cassert_no_null(pixbuf);
    return pixbuf->width * pixbuf->height;
}

/*---------------------------------------------------------------------------*/

uint32_t pixbuf_dsize(const Pixbuf *pixbuf)
{
    cassert_no_null(pixbuf);
    return i_bufsize(pixbuf->width, pixbuf->height, pixbuf->format);
}

/*---------------------------------------------------------------------------*/

const byte_t *pixbuf_cdata(const Pixbuf *pixbuf)
{
    cassert_no_null(pixbuf);
    return i_DATA(pixbuf);
}

/*---------------------------------------------------------------------------*/

byte_t *pixbuf_data(Pixbuf *pixbuf)
{
    cassert_no_null(pixbuf);
    return i_DATA(pixbuf);
}

/*---------------------------------------------------------------------------*/

uint32_t pixbuf_format_bpp(const pixformat_t format)
{
    switch (format)
    {
    case ekINDEX1:
        return 1;

    case ekINDEX2:
        return 2;

    case ekINDEX4:
        return 4;

    case ekINDEX8:
    case ekGRAY8:
        return 8;

    case ekRGB24:
        return 24;

    case ekRGBA32:
        return 32;

    case ekFIMAGE:
        cassert_default();
    }

    return 0;
}

/*---------------------------------------------------------------------------*/

uint32_t pixbuf_get(const Pixbuf *pixbuf, const uint32_t x, const uint32_t y)
{
    cassert_no_null(pixbuf);
    cassert(x < pixbuf->width);
    cassert(y < pixbuf->height);
    return i_GET[pixbuf->format](i_DATA(pixbuf), x, y, pixbuf->width);
}

/*---------------------------------------------------------------------------*/

void pixbuf_set(Pixbuf *pixbuf, const uint32_t x, const uint32_t y, const uint32_t value)
{
    cassert_no_null(pixbuf);
    cassert(x < pixbuf->width);
    cassert(y < pixbuf->height);
    i_SET[pixbuf->format](i_DATA(pixbuf), x, y, pixbuf->width, value);
}
