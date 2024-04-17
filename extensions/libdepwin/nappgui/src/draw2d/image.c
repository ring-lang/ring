/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: image.c
 *
 */

/* Images */

#include "image.h"
#include "image.inl"
#include "imgutil.inl"
#include "dctx.h"
#include "draw.h"
#include "draw.inl"
#include "palette.h"
#include "pixbuf.h"
#include <geom2d/t2d.h>
#include <core/buffer.h>
#include <core/heap.h>
#include <core/hfile.h>
#include <core/respackh.h>
#include <core/stream.h>
#include <core/strings.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

/*---------------------------------------------------------------------------*/

struct _image_t
{
    uint32_t num_instances;
    uint32_t num_frames;
    real32_t *frame_length;
    codec_t codec;
    OSImage *osimage;
    void *data;
    FPtr_destroy func_destroy_data;
};

/*---------------------------------------------------------------------------*/

static Image *i_create_image(const uint32_t num_instances, const uint32_t num_frames, real32_t **frame_length, const codec_t codec, OSImage **osimage)
{
    Image *image = heap_new(Image);
    image->num_instances = num_instances;
    image->num_frames = num_frames;
    image->frame_length = ptr_dget(frame_length, real32_t);
    image->codec = codec;
    image->osimage = ptr_dget_no_null(osimage, OSImage);
    image->data = NULL;
    image->func_destroy_data = NULL;
    return image;
}

/*---------------------------------------------------------------------------*/

void image_destroy(Image **image)
{
    cassert_no_null(image);
    cassert_no_null(*image);
    if ((*image)->num_instances == 1)
    {
        (*image)->num_instances = 0;

        if ((*image)->frame_length != NULL)
            heap_free((byte_t **)&(*image)->frame_length, (*image)->num_frames * sizeof32(real32_t), "ImageFrames");

        if ((*image)->data != NULL)
        {
            if ((*image)->func_destroy_data != NULL)
                (*image)->func_destroy_data(&(*image)->data);
        }

        osimage_destroy(&(*image)->osimage);
        heap_delete(image, Image);
    }
    else
    {
        cassert((*image)->num_instances > 0);
        (*image)->num_instances -= 1;
        *image = NULL;
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE bool_t i_with_alpha(const color_t *palette, const uint32_t palsize)
{
    register uint32_t i = 0;
    for (i = 0; i < palsize; ++i)
    {
        if ((byte_t)(palette[i] >> 24) != 255)
            return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static __INLINE bool_t i_gray_palette(const color_t *palette, const uint32_t palsize)
{
    register uint32_t i = 0;
    for (i = 0; i < palsize; ++i)
    {
        if (((byte_t)palette[i] != (byte_t)(palette[i] >> 8)) || ((byte_t)palette[i] != (byte_t)(palette[i] >> 16)))
            return FALSE;
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

Image *image_from_pixels(const uint32_t width, const uint32_t height, const pixformat_t format, const byte_t *data, const color_t *palette, const uint32_t palsize)
{
    OSImage *osimage = NULL;
    real32_t *frame_length = NULL;
    Pixbuf *rgb_pixels = NULL;
    pixformat_t nformat = format;

    switch (format)
    {
    case ekINDEX1:
    case ekINDEX2:
    case ekINDEX4:
    case ekINDEX8:
    {
        Palette *defpal = NULL;
        bool_t alpha_palette = FALSE;
        bool_t gray_palette = FALSE;
        const color_t *cpalette = palette;
        uint32_t bpp = pixbuf_format_bpp(format);

        if (cpalette == NULL)
        {
            defpal = imgutil_def_palette(format);
            cpalette = palette_ccolors(defpal);
        }
        else
        {
            alpha_palette = i_with_alpha(palette, palsize);
            if (alpha_palette == FALSE)
                gray_palette = i_gray_palette(palette, palsize);
        }

        if (alpha_palette == TRUE)
            rgb_pixels = imgutil_indexed_to_rgba(width, height, data, 0, bpp, cpalette);
        else if (gray_palette == TRUE)
            rgb_pixels = imgutil_indexed_to_gray(width, height, data, 0, bpp, cpalette);
        else
            rgb_pixels = imgutil_indexed_to_rgb(width, height, data, 0, bpp, cpalette);

        ptr_destopt(palette_destroy, &defpal, Palette);
        break;
    }

    case ekGRAY8:
    case ekRGB24:
    case ekRGBA32:
        break;

    case ekFIMAGE:
        cassert_default();
    }

    if (rgb_pixels != NULL)
    {
        nformat = pixbuf_format(rgb_pixels);
        cassert(nformat == ekRGB24 || nformat == ekRGBA32);
        osimage = osimage_create_from_pixels(width, height, nformat, pixbuf_data(rgb_pixels));
        pixbuf_destroy(&rgb_pixels);
    }
    else
    {
        osimage = osimage_create_from_pixels(width, height, format, data);
    }

    return i_create_image(1, PARAM(num_frames, 0), &frame_length, nformat == ekRGB24 ? ekJPG : ekPNG, &osimage);
}

/*---------------------------------------------------------------------------*/

Image *image_from_pixbuf(const Pixbuf *pixbuf, const Palette *palette)
{
    return image_from_pixels(
        pixbuf_width(pixbuf),
        pixbuf_height(pixbuf),
        pixbuf_format(pixbuf),
        pixbuf_cdata(pixbuf),
        palette ? palette_ccolors(palette) : NULL,
        palette ? palette_size(palette) : 0);
}

/*---------------------------------------------------------------------------*/

static codec_t i_codec(const byte_t first)
{
    /*
    Image Headers (only one byte for select)
    PNG: 0x89 0x50 0x4E 0x47 0x0D 0x0A 0x1A 0x0A
    JPG: 0xFF 0xD8
    GIF: 'GIF'
    BMP; 'BM' 'BA' 'CI' 'CP' 'IC' 'PT'
 */
    if (first == 0x89)
    {
        return ekPNG;
    }
    else if (first == 0xFF)
    {
        return ekJPG;
    }
    else if (first == 'G')
    {
        return ekGIF;
    }
    else if (first == 'B' || first == 'C' || first == 'I' || first == 'P')
    {
        return ekBMP;
    }
    else
    {
        cassert_msg(FALSE, "Unknown image encoding");
        return ENUM_MAX(codec_t);
    }
}

/*---------------------------------------------------------------------------*/

Image *image_from_file(const char_t *pathname, ferror_t *error)
{
    Image *img = NULL;
    Buffer *buffer = hfile_buffer(pathname, error);
    if (buffer != NULL)
    {
        const byte_t *data = buffer_data(buffer);
        uint32_t size = buffer_size(buffer);
        img = image_from_data(data, size);
        buffer_destroy(&buffer);
    }
    return img;
}

/*---------------------------------------------------------------------------*/

Image *image_from_data(const byte_t *data, const uint32_t size)
{
    codec_t codec = i_codec(data[0]);
    if (codec != ENUM_MAX(codec_t))
    {
        OSImage *osimage = NULL;
        real32_t *frame_length = NULL;
        osimage = osimage_create_from_data(data, size);
        return i_create_image(1, PARAM(num_frames, 0), &frame_length, codec, &osimage);
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

const Image *image_from_resource(const ResPack *pack, const ResId id)
{
    return respack_object(pack, id, image_from_data, image_destroy, Image);
}

/*---------------------------------------------------------------------------*/

Image *image_copy(const Image *image)
{
    cassert_no_null(image);
    ((Image *)image)->num_instances += 1;
    return (Image *)image;
}

/*---------------------------------------------------------------------------*/

Image *image_trim(const Image *image, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height)
{
    T2Df t2d;
    DCtx *ctx = dctx_bitmap(width, height, ekRGB24);
    t2d_movef(&t2d, kT2D_IDENTf, -(real32_t)x, -(real32_t)y);
    draw_matrixf(ctx, &t2d);
    draw_image(ctx, image, 0, 0);
    return dctx_image(&ctx);
}

/*---------------------------------------------------------------------------*/

static void i_rotated_image_size(const T2Df *t2d, const uint32_t width, const uint32_t height, real32_t *fx, real32_t *fy, uint32_t *fwidth, uint32_t *fheight)
{
    real32_t minx = 1e8f;
    real32_t maxx = -1e8f;
    real32_t miny = 1e8f;
    real32_t maxy = -1e8f;
    uint32_t i = 0;
    V2Df corners[4];
    corners[0].x = 0;
    corners[0].y = 0;
    corners[1].x = (real32_t)width;
    corners[1].y = 0;
    corners[2].x = (real32_t)width;
    corners[2].y = (real32_t)height;
    corners[3].x = 0;
    corners[3].y = (real32_t)height;
    for (i = 0; i < 4; ++i)
    {
        t2d_vmultf(corners + i, t2d, corners + i);
        if (corners[i].x < minx)
            minx = corners[i].x;
        if (corners[i].x > maxx)
            maxx = corners[i].x;
        if (corners[i].y < miny)
            miny = corners[i].y;
        if (corners[i].y > maxy)
            maxy = corners[i].y;
    }

    *fx = minx;
    *fy = miny;
    *fwidth = (uint32_t)(maxx - minx) + 1;
    *fheight = (uint32_t)(maxy - miny) + 1;
}

/*---------------------------------------------------------------------------*/

Image *image_rotate(const Image *image, const real32_t angle, const bool_t nsize, const color_t background, T2Df *t2dc)
{
    uint32_t width, height;
    uint32_t fwidth, fheight;
    real32_t cx, cy;
    real32_t fx, fy;
    T2Df t2d;
    DCtx *ctx = NULL;

    cassert_no_null(image);
    osimage_info(image->osimage, &width, &height, NULL, NULL);
    cx = width / 2.f;
    cy = height / 2.f;
    t2d_movef(&t2d, kT2D_IDENTf, cx, cy);
    t2d_rotatef(&t2d, &t2d, angle);
    t2d_movef(&t2d, &t2d, -cx, -cy);

    if (nsize == TRUE)
    {
        i_rotated_image_size(&t2d, width, height, &fx, &fy, &fwidth, &fheight);
    }
    else
    {
        fx = 0;
        fy = 0;
        fwidth = width;
        fheight = height;
    }

    ctx = dctx_bitmap(fwidth, fheight, ekRGB24);
    draw_clear(ctx, background);
    t2d_movef(&t2d, kT2D_IDENTf, -fx + cx, -fy + cy);
    t2d_rotatef(&t2d, &t2d, angle);
    t2d_movef(&t2d, &t2d, -cx, -cy);
    draw_matrixf(ctx, &t2d);

    if (t2dc != NULL)
        *t2dc = t2d;

    draw_image(ctx, image, 0, 0);
    return dctx_image(&ctx);
}

/*---------------------------------------------------------------------------*/

Image *image_scale(const Image *image, const uint32_t nwidth, const uint32_t nheight)
{
    uint32_t width = nwidth, height = nheight;
    uint32_t current_width, current_height;
    cassert_no_null(image);
    if (width == UINT32_MAX && height == UINT32_MAX)
    {
        ((Image *)image)->num_instances += 1;
        return (Image *)image;
    }

    osimage_info(image->osimage, &current_width, &current_height, NULL, NULL);
    if (width == UINT32_MAX)
    {
        width = (current_width * nheight) / current_height;
    }
    else if (height == UINT32_MAX)
    {
        height = (current_height * nwidth) / current_width;
    }

    if (current_width != width || current_height != height)
    {
        OSImage *osimage = NULL;
        real32_t *frame_length = NULL;
        cassert_no_null(image);
        osimage = osimage_create_scaled(image->osimage, width, height);
        return i_create_image(1, PARAM(num_frames, 0), &frame_length, image->codec, &osimage);
    }
    else
    {
        ((Image *)image)->num_instances += 1;
        return (Image *)image;
    }
}

/*---------------------------------------------------------------------------*/

Image *image_read(Stream *stm)
{
    if (stm_is_memory(stm) == TRUE)
    {
        const byte_t *data = stm_buffer(stm);
        uint64_t st = stm_bytes_readed(stm);

        if (imgutil_parse(stm, NULL) == TRUE)
        {
            uint64_t ed = stm_bytes_readed(stm);
            return image_from_data(data, (uint32_t)(ed - st));
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        Image *image = NULL;
        Stream *stm_out = stm_memory(4096);
        if (imgutil_parse(stm, stm_out) == TRUE)
        {
            const byte_t *data = stm_buffer(stm_out);
            uint32_t size = stm_buffer_size(stm_out);
            image = image_from_data(data, size);
        }

        stm_close(&stm_out);
        return image;
    }
}

/*---------------------------------------------------------------------------*/

bool_t image_to_file(const Image *image, const char_t *pathname, ferror_t *error)
{
    Stream *stm = stm_to_file(pathname, error);
    if (stm)
    {
        image_write(stm, image);
        stm_close(&stm);
        return TRUE;
    }
    return FALSE;
}

/*---------------------------------------------------------------------------*/

void image_write(Stream *stream, const Image *image)
{
    cassert_no_null(image);
    cassert(osimage_available_codec(image->osimage, image->codec) == TRUE);
    osimage_write(image->osimage, image->codec, stream);
}

/*---------------------------------------------------------------------------*/

pixformat_t image_format(const Image *image)
{
    pixformat_t format = ENUM_MAX(pixformat_t);
    cassert_no_null(image);
    osimage_info(image->osimage, NULL, NULL, &format, NULL);
    return format;
}

/*---------------------------------------------------------------------------*/

uint32_t image_width(const Image *image)
{
    uint32_t w;
    cassert_no_null(image);
    osimage_info(image->osimage, &w, NULL, NULL, NULL);
    return w;
}

/*---------------------------------------------------------------------------*/

uint32_t image_height(const Image *image)
{
    uint32_t h;
    cassert_no_null(image);
    osimage_info(image->osimage, NULL, &h, NULL, NULL);
    return h;
}

/*---------------------------------------------------------------------------*/

Pixbuf *image_pixels(const Image *image, const pixformat_t format)
{
    Pixbuf *pixels = NULL;
    cassert_no_null(image);
    cassert(format == ekRGB24 || format == ekRGBA32 || format == ekGRAY8 || format == ekFIMAGE);
    osimage_info(image->osimage, NULL, NULL, NULL, &pixels);

    if (pixels && format != ekFIMAGE && pixbuf_format(pixels) != format)
    {
        Pixbuf *npixels = pixbuf_convert(pixels, NULL, format);
        pixbuf_destroy(&pixels);
        pixels = npixels;
    }

    return pixels;
    /*     if (pixels != NULL)
    {
       pixformat_t rformat = pixbuf_format(*pixels);

       if (format == ekOPTIMAL)
       {
           if (rformat == ekRGB24 || rformat == ekRGBA32)
           {
               Pixbuf *npixels = NULL;
               cassert(palette == NULL || *palette == NULL);
               npixels = imgutil_to_indexed(pixbuf_width(*pixels), pixbuf_height(*pixels), pixbuf_data(*pixels), rformat == ekRGB24 ? 3 : 4, palette);
               if (npixels != NULL)
               {
                   pixbuf_destroy(pixels);
                   *pixels = npixels;
               }
           }
       }
       else if (format == ekFIMAGE)
       {
           // Keep the image original format
       }
       else if (format != rformat)
       {
           Pixbuf *npixels = pixbuf_convert(*pixels, palette != NULL ? *palette : NULL, format);
           if (npixels != NULL)
           {
               pixbuf_destroy(pixels);
               *pixels = npixels;
           }
       }
    }
 */
}

/*---------------------------------------------------------------------------*/

bool_t image_codec(const Image *image, const codec_t codec)
{
    cassert_no_null(image);
    if (osimage_available_codec(image->osimage, codec) == TRUE)
    {
        ((Image *)image)->codec = codec;
        return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

codec_t image_get_codec(const Image *image)
{
    cassert_no_null(image);
    return image->codec;
}

/*---------------------------------------------------------------------------*/

static void i_frames(Image *image)
{
    cassert_no_null(image);
    cassert(image->num_frames == 0);
    cassert(image->frame_length == NULL);
    osimage_frames(image->osimage, &image->num_frames, NULL);
    cassert(image->num_frames > 0);
    if (image->num_frames > 1)
    {
        register uint32_t i = 0;
        image->frame_length = (real32_t *)heap_malloc(image->num_frames * sizeof32(real32_t), "ImageFrames");
        for (i = 0; i < image->num_frames; ++i)
            osimage_frame(image->osimage, i, image->frame_length + i);
    }
}

/*---------------------------------------------------------------------------*/

uint32_t image_num_frames(const Image *image)
{
    cassert_no_null(image);
    if (image->num_frames == 0)
        i_frames((Image *)image);
    return image->num_frames;
}

/*---------------------------------------------------------------------------*/

real32_t image_frame_length(const Image *image, const uint32_t findex)
{
    cassert_no_null(image);
    if (image->num_frames == 0)
        i_frames((Image *)image);
    cassert(findex < image->num_frames);
    return image->frame_length[findex];
}

/*---------------------------------------------------------------------------*/

void image_data_imp(Image *image, void **data, FPtr_destroy func_destroy_data)
{
    cassert_no_null(image);
    cassert(image->data == NULL);
    cassert(image->func_destroy_data == NULL);
    image->data = ptr_dget_no_null(data, void);
    image->func_destroy_data = func_destroy_data;
}

/*---------------------------------------------------------------------------*/

void *image_get_data_imp(const Image *image)
{
    cassert_no_null(image);
    return image->data;
}

/*---------------------------------------------------------------------------*/

const OSImage *osimage_from_image(const Image *image)
{
    cassert_no_null(image);
    return image->osimage;
}

/*---------------------------------------------------------------------------*/

const void *image_native(const Image *image)
{
    cassert_no_null(image);
    return osimage_native(image->osimage);
}

/*---------------------------------------------------------------------------*/

Image *dctx_image(DCtx **ctx)
{
    OSImage *osimage = NULL;
    real32_t *frame_length = NULL;
    osimage = osimage_from_context(ctx);
    return i_create_image(1, PARAM(num_frames, 0), &frame_length, ekPNG, &osimage);
}

/*---------------------------------------------------------------------------*/

void draw_image(DCtx *ctx, const Image *image, const real32_t x, const real32_t y)
{
    cassert_no_null(image);
    draw_imgimp(ctx, image->osimage, UINT32_MAX, x, y, FALSE);
}

/*---------------------------------------------------------------------------*/

void draw_image_frame(DCtx *ctx, const Image *image, const uint32_t frame, const real32_t x, const real32_t y)
{
    cassert_no_null(image);
    draw_imgimp(ctx, image->osimage, frame, x, y, FALSE);
}
