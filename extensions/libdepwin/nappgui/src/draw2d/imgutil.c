/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: imgutil.c
 *
 */

/* Image utilities */

#include "imgutil.inl"
#include "color.h"
#include "palette.h"
#include "pixbuf.h"
#include <core/buffer.h>
#include <core/strings.h>
#include <core/stream.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>

typedef struct _gif_desc_t GifDesc;
typedef struct _gif_image_t GifImage;

struct _gif_desc_t
{
    uint16_t width;
    uint16_t height;
    byte_t flags;
    byte_t bgcolor;
    byte_t aspect;
};

struct _gif_image_t
{
    uint16_t left;
    uint16_t top;
    uint16_t width;
    uint16_t height;
    byte_t flags;
};

/*---------------------------------------------------------------------------*/

static bool_t i_parse_png(Stream *stm_in, Stream *stm_out)
{
    endian_t rendian = stm_get_read_endian(stm_in);
    endian_t wendian = ekBIGEND;

    stm_set_read_endian(stm_in, ekBIGEND);

    if (stm_out)
    {
        wendian = stm_get_write_endian(stm_out);
        stm_set_write_endian(stm_out, ekBIGEND);
    }

    /* PNG chunks */
    for (;;)
    {
        uint32_t size;
        byte_t type[4];
        uint32_t crc;
        size = stm_read_u32(stm_in);
        stm_read(stm_in, type, 4);

        if (stm_out)
        {
            stm_write_u32(stm_out, size);
            stm_write(stm_out, type, 4);
        }

        if (size > 0)
        {
            if (stm_out)
                stm_pipe(stm_in, stm_out, size);
            else
                stm_skip(stm_in, size);
        }

        crc = stm_read_u32(stm_in);

        if (stm_out)
            stm_write_u32(stm_out, crc);

        if (str_equ_cn((const char_t *)type, "IEND", 4) == TRUE)
            break;
    }

    stm_set_read_endian(stm_in, rendian);

    if (stm_out)
        stm_set_write_endian(stm_out, wendian);

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static void i_read_compressed(Stream *stm_in, byte_t *marker)
{
    for (;;)
    {
        byte_t data[2];
        stm_read(stm_in, data, 1);

        if (data[0] == 0xFF)
        {
            stm_read(stm_in, data + 1, 1);
            if (data[1] == 0x00 || (data[1] >= 0xd0 && data[1] <= 0xd7))
            {
            }
            else
            {
                marker[0] = data[0];
                marker[1] = data[1];
                return;
            }
        }
    }
}

/*---------------------------------------------------------------------------*/

static void i_read_compressed2(Stream *stm_in, Stream *stm_out, byte_t *marker)
{
    for (;;)
    {
        byte_t data[2];
        stm_read(stm_in, data, 1);

        if (data[0] == 0xFF)
        {
            stm_read(stm_in, data + 1, 1);
            if (data[1] == 0x00 || (data[1] >= 0xd0 && data[1] <= 0xd7))
            {
                stm_write(stm_out, data, 2);
            }
            else
            {
                marker[0] = data[0];
                marker[1] = data[1];
                return;
            }
        }
        else
        {
            stm_write(stm_out, data, 1);
        }
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_parse_jpg(Stream *stm_in, Stream *stm_out)
{
    endian_t rendian = stm_get_read_endian(stm_in);
    endian_t wendian = ekBIGEND;
    byte_t marker[2];
    bool_t ok = TRUE;

    stm_set_read_endian(stm_in, ekBIGEND);

    if (stm_out)
    {
        wendian = stm_get_write_endian(stm_out);
        stm_set_write_endian(stm_out, ekBIGEND);
    }

    stm_read(stm_in, marker, 2);

    /* JPG chunks */
    for (;;)
    {
        if (stm_out)
            stm_write(stm_out, marker, 2);

        /* Wrong marker */
        if (marker[0] != 0xFF)
        {
            ok = FALSE;
            break;
        }

        /* Stand-alone marker */
        if (marker[1] == 0x01 || (marker[1] >= 0xD0 && marker[1] <= 0xD9))
        {
            /* End Of Image marker */
            if (marker[1] == 0xD9)
                break;

            stm_read(stm_in, marker, 2);
        }
        /* Data marker */
        else
        {
            uint16_t size = stm_read_u16(stm_in);

            if (stm_out)
                stm_write_u16(stm_out, size);

            /* Wrong size */
            if (size < 2)
            {
                ok = FALSE;
                break;
            }

            /* Length integer is included in size */
            size -= 2;

            if (size > 0)
            {
                if (stm_out)
                    stm_pipe(stm_in, stm_out, size);
                else
                    stm_skip(stm_in, size);
            }

            if (marker[1] == 0xDA)
            {
                if (stm_out != NULL)
                    i_read_compressed2(stm_in, stm_out, marker);
                else
                    i_read_compressed(stm_in, marker);
            }
            else
            {
                stm_read(stm_in, marker, 2);
            }
        }
    }

    stm_set_read_endian(stm_in, rendian);

    if (stm_out)
        stm_set_write_endian(stm_out, wendian);

    return ok;
}

/*---------------------------------------------------------------------------*/

static void i_read_gif_desc(GifDesc *desc, Stream *stm)
{
    desc->width = stm_read_u16(stm);
    desc->height = stm_read_u16(stm);
    desc->flags = stm_read_u8(stm);
    desc->bgcolor = stm_read_u8(stm);
    desc->aspect = stm_read_u8(stm);
}

/*---------------------------------------------------------------------------*/

static void i_write_gif_desc(const GifDesc *desc, Stream *stm)
{
    stm_write_u16(stm, desc->width);
    stm_write_u16(stm, desc->height);
    stm_write_u8(stm, desc->flags);
    stm_write_u8(stm, desc->bgcolor);
    stm_write_u8(stm, desc->aspect);
}

/*---------------------------------------------------------------------------*/

static void i_read_gif_imgdesc(GifImage *desc, Stream *stm)
{
    desc->left = stm_read_u16(stm);
    desc->top = stm_read_u16(stm);
    desc->width = stm_read_u16(stm);
    desc->height = stm_read_u16(stm);
    desc->flags = stm_read_u8(stm);
}

/*---------------------------------------------------------------------------*/

static void i_write_gif_imgdesc(const GifImage *desc, Stream *stm)
{
    stm_write_u16(stm, desc->left);
    stm_write_u16(stm, desc->top);
    stm_write_u16(stm, desc->width);
    stm_write_u16(stm, desc->height);
    stm_write_u8(stm, desc->flags);
}

/*---------------------------------------------------------------------------*/

static bool_t i_read_gif_image(Stream *stm_in, Stream *stm_out)
{
    GifImage desc;
    byte_t compress_size;

    i_read_gif_imgdesc(&desc, stm_in);

    if (stm_out)
        i_write_gif_imgdesc(&desc, stm_out);

    /* With Local color table */
    if (BIT_TEST(desc.flags, 7) == TRUE)
    {
        /* 2^(bits0-2)+1 = Number of entries in color table */
        uint32_t size = 1 << ((desc.flags & 0x07) + 1);
        /* Each entry RBG (1 byte per channed) */
        size *= 3;

        if (stm_out)
            stm_pipe(stm_in, stm_out, size);
        else
            stm_skip(stm_in, size);
    }

    stm_read(stm_in, &compress_size, 1);

    if (stm_out)
        stm_write(stm_out, &compress_size, 1);

    /* Data blocks */
    for (;;)
    {
        uint8_t size = stm_read_u8(stm_in);

        if (stm_out)
            stm_write_u8(stm_out, size);

        /* Last block */
        if (size == 0)
            break;

        if (stm_out)
            stm_pipe(stm_in, stm_out, size);
        else
            stm_skip(stm_in, size);
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_read_gif_extension(Stream *stm_in, Stream *stm_out)
{
    byte_t type;

    stm_read(stm_in, &type, 1);

    if (stm_out)
        stm_write(stm_out, &type, 1);

    /* Extension blocks */
    for (;;)
    {
        uint8_t size = stm_read_u8(stm_in);

        if (stm_out)
            stm_write_u8(stm_out, size);

        /* Last block */
        if (size == 0)
            break;

        if (stm_out)
            stm_pipe(stm_in, stm_out, size);
        else
            stm_skip(stm_in, size);
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_parse_gif(Stream *stm_in, Stream *stm_out, uint32_t *num_frames)
{
    endian_t rendian = stm_get_read_endian(stm_in);
    endian_t wendian = ekBIGEND;
    GifDesc desc;
    bool_t ok = TRUE;
    cassert_no_null(num_frames);

    *num_frames = 0;
    stm_set_read_endian(stm_in, ekLITEND);

    if (stm_out)
    {
        wendian = stm_get_write_endian(stm_out);
        stm_set_write_endian(stm_out, ekLITEND);
    }

    i_read_gif_desc(&desc, stm_in);

    if (stm_out)
        i_write_gif_desc(&desc, stm_out);

    /* With Global color table */
    if (BIT_TEST(desc.flags, 7) == TRUE)
    {
        /* 2^(bits0-2)+1 = Number of entries in color table */
        uint32_t size = 1 << ((desc.flags & 0x07) + 1);
        size *= 3; /* Each entry RBG (1 byte per channed) */

        if (stm_out)
            stm_pipe(stm_in, stm_out, size);
        else
            stm_skip(stm_in, size);
    }

    /* GIF Blocks */
    for (;;)
    {
        byte_t type;
        stm_read(stm_in, &type, 1);

        if (stm_out)
            stm_write(stm_out, &type, 1);

        if (type == 0x21)
        {
            if (i_read_gif_extension(stm_in, stm_out) == FALSE)
            {
                ok = FALSE;
                break;
            }
        }
        else if (type == 0x2c)
        {
            if (i_read_gif_image(stm_in, stm_out) == FALSE)
            {
                ok = FALSE;
                break;
            }

            *num_frames += 1;
        }
        /* GIF Terminator */
        else if (type == 0x3b)
        {
            break;
        }
        /* Unknown block */
        else
        {
            ok = FALSE;
            break;
        }
    }

    stm_set_read_endian(stm_in, rendian);

    if (stm_out)
        stm_set_write_endian(stm_out, wendian);

    return ok;
}

/*---------------------------------------------------------------------------*/

static bool_t i_parse_bmp(Stream *stm_in, Stream *stm_out)
{
    endian_t rendian = stm_get_read_endian(stm_in);
    endian_t wendian = ekBIGEND;
    uint32_t size;
    bool_t ok = TRUE;

    stm_set_read_endian(stm_in, ekLITEND);

    if (stm_out)
    {
        wendian = stm_get_write_endian(stm_out);
        stm_set_write_endian(stm_out, ekLITEND);
    }

    /* Total file size. 6 = Number of bytes already read */
    size = stm_read_u32(stm_in);

    if (stm_out)
    {
        stm_write_u32(stm_out, size);
        stm_pipe(stm_in, stm_out, size - 6);
    }
    else
    {
        stm_skip(stm_in, size - 6);
    }

    stm_set_read_endian(stm_in, rendian);

    if (stm_out)
        stm_set_write_endian(stm_out, wendian);

    return ok;
}

/*---------------------------------------------------------------------------*/

static codec_t i_header(Stream *stm_in, Stream *stm_out)
{
    byte_t first;

    stm_read(stm_in, &first, 1);

    /*
    Image Headers (only one byte for select)
    PNG: 0x89 0x50 0x4E 0x47 0x0D 0x0A 0x1A 0x0A
    JPG: 0xFF 0xD8
    GIF: 'GIF87a' 'GIF89a'
    BMP; 'BM' 'BA' 'CI' 'CP' 'IC' 'PT'
 */
    if (first == 0x89)
    {
        const byte_t header[] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
        byte_t rhead[7];
        stm_read(stm_in, rhead, 7);

        if (stm_out)
            stm_write(stm_out, header, 8);

        if (str_equ_cn((const char_t *)rhead, (const char_t *)(header + 1), 7) == TRUE)
            return ekPNG;

        return ENUM_MAX(codec_t);
    }
    else if (first == 0xFF)
    {
        const byte_t header[] = {0xFF, 0xD8};
        byte_t rhead;
        stm_read(stm_in, &rhead, 1);

        if (stm_out)
            stm_write(stm_out, header, 2);

        if (rhead == header[1])
            return ekJPG;

        return ENUM_MAX(codec_t);
    }
    else if (first == 'G')
    {
        const char_t *header1 = "GIF87a";
        const char_t *header2 = "GIF89a";
        byte_t rhead[5];
        stm_read(stm_in, rhead, 5);

        if (stm_out)
        {
            stm_write(stm_out, &first, 1);
            stm_write(stm_out, rhead, 5);
        }

        if (str_equ_cn((const char_t *)rhead, header1 + 1, 5) == TRUE)
            return ekGIF;

        if (str_equ_cn((const char_t *)rhead, header2 + 1, 5) == TRUE)
            return ekGIF;

        return ENUM_MAX(codec_t);
    }
    else if (first == 'B')
    {
        byte_t head[2] = {'B', '_'};
        stm_read(stm_in, head + 1, 1);

        if (stm_out)
            stm_write(stm_out, head, 2);

        if (head[1] == 'M')
            return ekBMP;

        else if (head[1] == 'A')
            return ekBMP;

        return ENUM_MAX(codec_t);
    }
    else if (first == 'C')
    {
        byte_t head[2] = {'C', '_'};
        stm_read(stm_in, head + 1, 1);

        if (stm_out)
            stm_write(stm_out, head, 2);

        if (head[1] == 'I')
            return ekBMP;

        else if (head[1] == 'P')
            return ekBMP;

        return ENUM_MAX(codec_t);
    }
    else if (first == 'I')
    {
        byte_t head[2] = {'I', '_'};
        stm_read(stm_in, head + 1, 1);

        if (stm_out)
            stm_write(stm_out, head, 2);

        if (head[1] == 'C')
            return ekBMP;

        return ENUM_MAX(codec_t);
    }
    else if (first == 'P')
    {
        byte_t head[2] = {'P', '_'};
        stm_read(stm_in, head + 1, 1);

        if (stm_out)
            stm_write(stm_out, head, 2);

        if (head[1] == 'T')
            return ekBMP;

        return ENUM_MAX(codec_t);
    }
    else
    {
        if (stm_out)
            stm_write(stm_out, &first, 1);

        cassert_msg(FALSE, "Unknown image encoding");
        return ENUM_MAX(codec_t);
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_parse_img(Stream *stm_in, Stream *stm_out, uint32_t *num_frames)
{
    codec_t codec = i_header(stm_in, stm_out);
    cassert_no_null(num_frames);

    switch (codec)
    {
    case ekPNG:
        *num_frames = 1;
        return i_parse_png(stm_in, stm_out);
    case ekJPG:
        *num_frames = 1;
        return i_parse_jpg(stm_in, stm_out);
    case ekGIF:
        return i_parse_gif(stm_in, stm_out, num_frames);
    case ekBMP:
        *num_frames = 1;
        return i_parse_bmp(stm_in, stm_out);
    default:
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t imgutil_parse(Stream *stm_in, Stream *stm_out)
{
    uint32_t num_frames = 0;
    return i_parse_img(stm_in, stm_out, &num_frames);
}

/*---------------------------------------------------------------------------*/

uint32_t imgutil_num_frames(const byte_t *data, const uint32_t size)
{
    Stream *stm = stm_from_block(data, size);
    uint32_t num_frames = 0;
    i_parse_img(stm, NULL, &num_frames);
    stm_close(&stm);
    return num_frames;
}

/*---------------------------------------------------------------------------*/

Palette *imgutil_def_palette(const pixformat_t format)
{
    switch (format)
    {
    case ekINDEX1:
        return palette_binary(kCOLOR_WHITE, kCOLOR_BLACK);

    case ekINDEX2:
        return palette_cga2(FALSE, FALSE);

    case ekINDEX4:
        return palette_ega4();

    case ekINDEX8:
        return palette_rgb8();

    case ekRGB24:
    case ekRGBA32:
    case ekGRAY8:
    case ekFIMAGE:
        cassert_default();
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_rgba_to_rgb(const byte_t *data, const uint32_t width, const uint32_t height)
{
    register uint32_t i, n = width * height;
    Pixbuf *pixbuf = pixbuf_create(width, height, ekRGB24);
    byte_t *dest = pixbuf_data(pixbuf);
    for (i = 0; i < n; ++i, data += 4, dest += 3)
    {
        dest[0] = data[0];
        dest[1] = data[1];
        dest[2] = data[2];
    }

    return pixbuf;
}

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_rgb_to_rgba(const byte_t *data, const uint32_t width, const uint32_t height)
{
    register uint32_t i, n = width * height;
    Pixbuf *pixbuf = pixbuf_create(width, height, ekRGBA32);
    byte_t *dest = pixbuf_data(pixbuf);
    for (i = 0; i < n; ++i, data += 3, dest += 4)
    {
        dest[0] = data[0];
        dest[1] = data[1];
        dest[2] = data[2];
        dest[3] = 255;
    }

    return pixbuf;
}

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_rgba_to_gray(const byte_t *data, const uint32_t width, const uint32_t height)
{
    register uint32_t i, n = width * height;
    Pixbuf *pixbuf = pixbuf_create(width, height, ekGRAY8);
    byte_t *dest = pixbuf_data(pixbuf);
    for (i = 0; i < n; ++i, data += 4, dest += 1)
        *dest = (byte_t)((77 * (uint32_t)data[0] + 148 * (uint32_t)data[1] + 30 * (uint32_t)data[2]) / 255);
    return pixbuf;
}

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_rgb_to_gray(const byte_t *data, const uint32_t width, const uint32_t height)
{
    register uint32_t i, n = width * height;
    Pixbuf *pixbuf = pixbuf_create(width, height, ekGRAY8);
    byte_t *dest = pixbuf_data(pixbuf);
    for (i = 0; i < n; ++i, data += 3, dest += 1)
        *dest = (byte_t)((77 * (uint32_t)data[0] + 148 * (uint32_t)data[1] + 30 * (uint32_t)data[2]) / 255);
    return pixbuf;
}

/*---------------------------------------------------------------------------*/

Buffer *imgutil_gray_to_rgba(const byte_t *data, const uint32_t width, const uint32_t height)
{
    register uint32_t i, n = width * height;
    Buffer *buffer = buffer_create(n * 4);
    byte_t *dest = buffer_data(buffer);
    for (i = 0; i < n; ++i, data += 1, dest += 4)
    {
        dest[0] = data[0];
        dest[1] = data[0];
        dest[2] = data[0];
        dest[3] = 255;
    }

    return buffer;
}

/*---------------------------------------------------------------------------*/

Buffer *imgutil_gray_to_rgb(const byte_t *data, const uint32_t width, const uint32_t height)
{
    register uint32_t i, n = width * height;
    Buffer *buffer = buffer_create(n * 3);
    byte_t *dest = buffer_data(buffer);
    for (i = 0; i < n; ++i, data += 1, dest += 3)
    {
        dest[0] = data[0];
        dest[1] = data[0];
        dest[2] = data[0];
    }

    return buffer;
}

/*---------------------------------------------------------------------------*/
/*
static pixformat_t i_gray_to_rgb(const byte_t *data, const uint32_t width, const uint32_t height, const uint32_t bpp, const uint8_t *palette, Buffer **pixels)
{
   register uint32_t i, n = width * height;
   register byte_t imask = (1 << bpp) - 1;
   register byte_t *pixdata = NULL;

   cassert_no_null(palette);
   *pixels = buffer_create(n * 3);
   pixdata = buffer_data(*pixels);

   for (i = 0; i < n; ++i)
   {
       Get the pixel value
       register byte_t ibyte = data[i / (8 / bpp)];
       register byte_t ipos = i % (8 / (uint8_t)bpp);
       register byte_t value = (ibyte & (imask << (ipos * bpp))) >> (ipos * bpp);
       value = palette[value];
       pixdata[0] = (uint8_t)value;
       pixdata[1] = (uint8_t)value;
       pixdata[2] = (uint8_t)value;
       pixdata += 3;
   }

   return ekRGB24;
}
 */

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_indexed_to_gray(const uint32_t width, const uint32_t height, const byte_t *pixdata, const uint32_t stride, const uint32_t ibpp, const color_t *palette)
{
    Pixbuf *buffer = NULL;
    byte_t *data = NULL;
    register byte_t ibyte;
    register byte_t ipos;
    register byte_t value;
    register color_t c;

    /* mask = 1, 3, 15, 255 */
    register byte_t imask = (byte_t)(1 << ibpp) - 1;
    register uint32_t j, i;

    cassert(ibpp == 1 || ibpp == 2 || ibpp == 4 || ibpp == 8);
    cassert_no_null(palette);

    buffer = pixbuf_create(width, height, ekGRAY8);
    data = pixbuf_data(buffer);

    if (stride == 0)
    {
        uint32_t n = width * height;

        for (i = 0; i < n; ++i)
        {
            /* 1) Get the pixel value */
            ibyte = pixdata[i / (8 / ibpp)];
            ipos = (byte_t)(i % (8 / ibpp));
            value = (byte_t)((ibyte & (imask << (ipos * ibpp))) >> (ipos * ibpp));
            c = palette[value];

            /* Its a gray palette */
            cassert((byte_t)c == (byte_t)(c >> 8));
            cassert((byte_t)c == (byte_t)(c >> 16));

            /* 2) Write the pixel value */
            *data = (byte_t)c;
            data += 1;
        }
    }
    else
    {
        for (j = 0; j < height; ++j)
        {
            for (i = 0; i < width; ++i)
            {
                /* 1) Get the pixel value */
                ibyte = pixdata[i / (8 / ibpp)];
                ipos = (byte_t)((8 / (uint8_t)ibpp) - 1 - (i % (8 / (uint8_t)ibpp)));
                value = (byte_t)((ibyte & (imask << (ipos * ibpp))) >> (ipos * ibpp));
                c = palette[value];

                /* Its a gray palette */
                cassert((byte_t)c == (byte_t)(c >> 8));
                cassert((byte_t)c == (byte_t)(c >> 16));

                /* 2) Write the pixel value */
                *data = (byte_t)c;
                data += 1;
            }

            pixdata += stride;
        }
    }

    return buffer;
}

/*---------------------------------------------------------------------------*/
/*
static Pixbuf *i_index_to_rgba(const byte_t *data, const uint32_t width, const uint32_t height, const uint32_t bpp, const pixformat_t format, const color_t *palette)
{
   Palette *pal = NULL;
   Pixbuf *pixbuf = NULL;
   register color_t *pixdata = NULL;
   register uint32_t i, n = width * height;
   register byte_t imask = (byte_t)(1 << bpp) - 1;

   if (palette == NULL)
   {
       pal = i_def_palette(format);
       palette = palette_colors(pal);
   }

   pixbuf = pixbuf_create(width, height, ekRGBA32);
   pixdata = (color_t*)pixbuf_data(pixbuf);

   for (i = 0; i < n; ++i)
   {
       Get the pixel value
       register byte_t ibyte = data[i / (8 / bpp)];
       register byte_t ipos = (byte_t)(i % (8 / (uint8_t)bpp));
       register byte_t value = (byte_t)((ibyte & (imask << (ipos * bpp))) >> (ipos * bpp));
       *pixdata = palette[value];
       pixdata += 1;
   }

   if (pal != NULL)
       palette_destroy(&pal);

   return pixbuf;
}
 */

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_indexed_to_rgba(const uint32_t width, const uint32_t height, const byte_t *pixdata, const uint32_t stride, const uint32_t ibpp, const color_t *palette)
{
    Pixbuf *buffer = NULL;
    uint32_t *data = NULL;
    register byte_t ibyte;
    register byte_t ipos;
    register byte_t value;
    register color_t c;

    /* mask = 1, 3, 15, 255 */
    register byte_t imask = (byte_t)(1 << ibpp) - 1;
    register uint32_t j, i;

    cassert(ibpp == 1 || ibpp == 2 || ibpp == 4 || ibpp == 8);
    cassert_no_null(palette);

    buffer = pixbuf_create(width, height, ekRGBA32);
    data = (uint32_t *)pixbuf_data(buffer);

    if (stride == 0)
    {
        uint32_t n = width * height;

        for (i = 0; i < n; ++i)
        {
            /* 1) Get the pixel value */
            ibyte = pixdata[i / (8 / ibpp)];
            ipos = (byte_t)(i % (8 / ibpp));
            value = (byte_t)((ibyte & (imask << (ipos * ibpp))) >> (ipos * ibpp));
            c = palette[value];

            /* 2) Write the pixel value */
            *data = (uint32_t)c;
            data += 1;
        }
    }
    else
    {
        for (j = 0; j < height; ++j)
        {
            for (i = 0; i < width; ++i)
            {
                /* 1) Get the pixel value */
                ibyte = pixdata[i / (8 / ibpp)];
                ipos = (byte_t)((8 / (uint8_t)ibpp) - 1 - (i % (8 / (uint8_t)ibpp)));
                value = (byte_t)((ibyte & (imask << (ipos * ibpp))) >> (ipos * ibpp));
                c = palette[value];

                /* 2) Write the pixel value */
                *data = (uint32_t)c;
                data += 1;
            }

            pixdata += stride;
        }
    }

    return buffer;
}

/*---------------------------------------------------------------------------*/

/* static Pixbuf *i_index_to_rgb(const byte_t *data, const uint32_t width, const uint32_t height, const uint32_t bpp, const color_t *palette)
{
   Palette *pal = NULL;
   Pixbuf *pixbuf = NULL;
   register byte_t *pixdata = NULL;
   register uint32_t i, n = width * height;
   register byte_t imask = (byte_t)(1 << bpp) - 1;

   if (palette == NULL)
   {
       pal = i_def_palette(format);
       palette = palette_colors(pal);
   }

   pixbuf = pixbuf_create(width, height, ekRGB24);
   pixdata = pixbuf_data(pixbuf);

   for (i = 0; i < n; ++i)
   {
       Get the pixel value
       register byte_t ibyte = data[i / (8 / bpp)];
       register byte_t ipos = (byte_t)(i % (8 / (uint8_t)bpp));
       register byte_t value = (byte_t)((ibyte & (imask << (ipos * bpp))) >> (ipos * bpp));
       register color_t c = palette[value];
       pixdata[0] = (byte_t)c;
       pixdata[1] = (byte_t)(c >> 8);
       pixdata[2] = (byte_t)(c >> 16);
       pixdata += 3;
   }

   if (pal != NULL)
       palette_destroy(&pal);

   return pixbuf;
}
 */

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_indexed_to_rgb(const uint32_t width, const uint32_t height, const byte_t *pixdata, const uint32_t stride, const uint32_t ibpp, const color_t *palette)
{
    Pixbuf *buffer = NULL;
    byte_t *data = NULL;
    register byte_t ibyte;
    register byte_t ipos;
    register byte_t value;
    register color_t c;

    /* mask = 1, 3, 15, 255 */
    register byte_t imask = (byte_t)(1 << ibpp) - 1;
    register uint32_t j, i;

    cassert(ibpp == 1 || ibpp == 2 || ibpp == 4 || ibpp == 8);
    cassert_no_null(palette);

    buffer = pixbuf_create(width, height, ekRGB24);
    data = pixbuf_data(buffer);

    if (stride == 0)
    {
        uint32_t n = width * height;

        for (i = 0; i < n; ++i)
        {
            /* 1) Get the pixel value */
            ibyte = pixdata[i / (8 / ibpp)];
            ipos = (byte_t)(i % (8 / ibpp));
            value = (byte_t)((ibyte & (imask << (ipos * ibpp))) >> (ipos * ibpp));
            c = palette[value];

            /* 2) Write the pixel value */
            data[0] = (byte_t)c;
            data[1] = (byte_t)(c >> 8);
            data[2] = (byte_t)(c >> 16);
            data += 3;
        }
    }
    else
    {
        for (j = 0; j < height; ++j)
        {
            for (i = 0; i < width; ++i)
            {
                /* 1) Get the pixel value */
                ibyte = pixdata[i / (8 / ibpp)];
                ipos = (byte_t)((8 / (uint8_t)ibpp) - 1 - (i % (8 / (uint8_t)ibpp)));
                value = (byte_t)((ibyte & (imask << (ipos * ibpp))) >> (ipos * ibpp));
                c = palette[value];

                /* 2) Write the pixel value */
                data[0] = (byte_t)c;
                data[1] = (byte_t)(c >> 8);
                data[2] = (byte_t)(c >> 16);
                data += 3;
            }

            pixdata += stride;
        }
    }

    return buffer;
}

/*---------------------------------------------------------------------------*/

uint32_t imgutil_effective_palette(const uint32_t *ipalette, const uint32_t isize, uint32_t *opalette, uint8_t *oindex)
{
    register uint32_t i, j;
    uint32_t n = 0;
    /* Maximum 8bit palettes */
    cassert(isize <= 256);
    for (i = 0; i < isize; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (ipalette[i] == opalette[j])
            {
                oindex[i] = (uint8_t)j;
                break;
            }
        }

        /* No color in effective palete */
        if (j == n)
        {
            opalette[n] = ipalette[i];
            oindex[i] = (uint8_t)n;
            n += 1;
        }
    }

    return n;
}

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_indexed_to_indexed(const uint32_t width, const uint32_t height, const byte_t *pixdata, const uint32_t stride, const uint32_t ibpp, const pixformat_t oformat, const uint8_t *palette_index)
{
    Pixbuf *buffer = NULL;
    byte_t *data = NULL;
    uint32_t obpp = pixbuf_format_bpp(oformat);
    /* mask = 1, 3, 15, 255 */
    register byte_t imask = (byte_t)(1 << ibpp) - 1;
    register byte_t omask = (byte_t)(1 << obpp) - 1;
    register uint32_t j, i;

    cassert(ibpp == 1 || ibpp == 2 || ibpp == 4 || ibpp == 8);
    cassert(obpp == 1 || obpp == 2 || obpp == 4 || obpp == 8);
    cassert_no_null(palette_index);

    buffer = pixbuf_create(width, height, oformat);
    data = pixbuf_data(buffer);

    for (j = 0; j < height; ++j)
    {
        register byte_t ibyte;
        register byte_t ipos;
        register byte_t value;
        register byte_t *obyte;
        register byte_t opos;

        for (i = 0; i < width; ++i)
        {
            /* 1) Get the pixel value */
            ibyte = pixdata[i / (8 / ibpp)];
            ipos = (byte_t)((8 / (uint8_t)ibpp) - 1 - (i % (8 / (uint8_t)ibpp)));
            value = (byte_t)((ibyte & (imask << (ipos * ibpp))) >> (ipos * ibpp));
            value = palette_index[value];
            cassert(value <= omask);

            /* 2) Write the pixel value leaving intact the other bits */
            obyte = data + ((j * width) + i) / (8 / obpp);
            opos = (byte_t)(((j * width) + i) % (8 / (uint8_t)obpp));
            *obyte &= ~(omask << (opos * obpp));
            *obyte |= (value << (opos * obpp));
        }

        pixdata += stride;
    }

    return buffer;
}

/*---------------------------------------------------------------------------*/
/*
static __INLINE bool_t i_is_gray_palette(const color_t *palette, const uint32_t n)
{
   const byte_t *pal = (const byte_t*)palette;
   register uint32_t i;
   for (i = 0; i < n; ++i)
   {
       if (pal[0] != pal[1] || pal[0] != pal[2] || pal[3] != 255)
           return FALSE;
       pal += 4;
   }

   return TRUE;
}
 */

/*---------------------------------------------------------------------------*/

#define i_color(r, g, b, a) \
    (color_t)(((a) << 24) | ((b) << 16) | ((g) << 8) | (r))

/*---------------------------------------------------------------------------*/

static Pixbuf *i_rgb_to_indexed(const byte_t *pixdata, const uint32_t width, const uint32_t height, const uint32_t bytespp, const color_t *palrgb, const uint32_t pn, Palette **palette)
{
    uint32_t bpp = 0;
    pixformat_t format = ENUM_MAX(pixformat_t);
    Pixbuf *pixels = NULL;
    register uint32_t n = width * height;
    register byte_t omask = 0;
    register byte_t *destdata = NULL;
    register uint32_t i, j;

    cassert(pn <= 256);

    if (pn <= 2)
    {
        format = ekINDEX1;
        bpp = 1;
    }
    else if (pn <= 4)
    {
        format = ekINDEX2;
        bpp = 2;
    }
    else if (pn <= 16)
    {
        format = ekINDEX4;
        bpp = 4;
    }
    else
    {
        format = ekINDEX8;
        bpp = 8;
    }

    omask = (byte_t)(1 << bpp) - 1;
    pixels = pixbuf_create(width, height, format);
    destdata = pixbuf_data(pixels);

    for (i = 0; i < n; ++i)
    {
        register color_t c;

        if (bytespp == 3)
            c = i_color(pixdata[0], pixdata[1], pixdata[2], 255);
        else
            c = i_color(pixdata[0], pixdata[1], pixdata[2], pixdata[3]);

        for (j = 0; j < pn; ++j)
        {
            if (palrgb[j] == c)
            {
                /* Write the pixel value leaving intact the other bits */
                register byte_t *obyte = destdata + i / (8 / bpp);
                register byte_t opos = (byte_t)(i % (8 / (uint8_t)bpp));
                *obyte &= ~(omask << (opos * bpp));
                *obyte |= (j << (opos * bpp));
                break;
            }
        }

        /* RGB must exists in palette */
        cassert(j < pn);
        pixdata += bytespp;
    }

    if (palette != NULL)
    {
        *palette = palette_create(pn);
        bmem_copy_n(palette_colors(*palette), palrgb, pn, color_t);
    }

    return pixels;
}

/*---------------------------------------------------------------------------*/

Pixbuf *imgutil_to_indexed(const uint32_t width, const uint32_t height, const byte_t *pixdata, const uint32_t bytespp, Palette **palette)
{
    register uint32_t i, n = width * height;
    register uint32_t j, pn = 0;
    register const byte_t *datai = pixdata;
    color_t pal[256];

    for (i = 0; i < n; ++i)
    {
        register color_t c;

        if (bytespp == 3)
            c = i_color(datai[0], datai[1], datai[2], 255);
        else
            c = i_color(datai[0], datai[1], datai[2], datai[3]);

        for (j = 0; j < pn; ++j)
        {
            if (pal[j] == c)
                break;
        }

        if (j == pn)
        {
            if (pn < 256)
            {
                pal[pn] = c;
                pn += 1;
            }
            else
            {
                if (palette != NULL)
                    *palette = NULL;

                return NULL;
            }
        }

        datai += bytespp;
    }

    return i_rgb_to_indexed(pixdata, width, height, bytespp, pal, pn, palette);
}
