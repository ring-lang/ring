/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osimage.c
 *
 */

/* Images */

#include "image.inl"
#include "osimage.inl"
#include "imgutil.inl"
#include "dctxh.h"
#include "pixbuf.h"
#include "draw2d_gtk.ixx"
#include <core/buffer.h>
#include <core/heap.h>
#include <core/strings.h>
#include <core/stream.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#if (GDK_PIXBUF_MAJOR < 2 || (GDK_PIXBUF_MAJOR == 2 && GDK_PIXBUF_MINOR < 28))
#include <osbs/bfile.h>
#include <core/hfile.h>
#endif

#include <sewer/nowarn.hxx>
#include <gdk/gdk.h>
#include <sewer/warn.hxx>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _osimage_t
{
    GdkPixbuf *pixbuf;
    GdkPixbufAnimation *animation;
    uint32_t num_frames;
};

/*---------------------------------------------------------------------------*/

void osimage_alloc_globals(void)
{
}

/*---------------------------------------------------------------------------*/

void osimage_dealloc_globals(void)
{
}

/*---------------------------------------------------------------------------*/

static __INLINE OSImage *i_osimage(GdkPixbuf *pixbuf)
{
    OSImage *image = heap_new(OSImage);
    image->pixbuf = pixbuf;
    image->animation = NULL;
    image->num_frames = 1;
    return image;
}

/*---------------------------------------------------------------------------*/

static __INLINE OSImage *i_osanimation(GdkPixbufAnimation *animation, const uint32_t num_frames)
{
    OSImage *image = heap_new(OSImage);
    image->pixbuf = NULL;
    image->animation = animation;
    image->num_frames = num_frames;
    return image;
}

/*---------------------------------------------------------------------------*/

static void i_destroy_pixbuf_data(guchar *pixels, gpointer data)
{
    uint32_t size = (uint32_t)(intptr_t)data;
    heap_delete_n(&pixels, size, guchar);
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_create_from_pixels(const uint32_t width, const uint32_t height, const pixformat_t format, const byte_t *pixel_data)
{
    OSImage *image = NULL;
    GdkPixbuf *pixbuf = NULL;
    GdkColorspace colorspace = GDK_COLORSPACE_RGB;
    gboolean has_alpha = FALSE;
    int bits_per_sample = 8;
    int rowstride = 0;
    int offset = 0;
    uint32_t size = 0;
    guchar *data = NULL;

    switch (format)
    {
    case ekRGBA32:
        colorspace = GDK_COLORSPACE_RGB;
        has_alpha = TRUE;
        rowstride = width * 4;
        size = width * height * 4;
        data = heap_new_n(size, guchar);
        bmem_copy(data, pixel_data, size);
        break;

    case ekRGB24:
    {
        register uint32_t i, j;
        guchar *dest = NULL;
        colorspace = GDK_COLORSPACE_RGB;
        has_alpha = FALSE;
        rowstride = width * 3;
        offset = (rowstride % 4) == 0 ? 0 : 4 - (rowstride % 4);
        rowstride += offset;
        size = rowstride * height;
        data = heap_new_n(size, guchar);
        dest = data;
        bmem_copy(data, pixel_data, size);
        for (j = 0; j < height; ++j)
        {
            for (i = 0; i < width; ++i, dest += 3)
            {
                dest[0] = pixel_data[0];
                dest[1] = pixel_data[1];
                dest[2] = pixel_data[2];
                pixel_data += 3;
            }

            dest += offset;
        }

        break;
    }

    case ekGRAY8:
    {
        register uint32_t i, j;
        guchar *dest = NULL;
        colorspace = GDK_COLORSPACE_RGB;
        has_alpha = FALSE;
        rowstride = width * 3;
        offset = (rowstride % 4) == 0 ? 0 : 4 - (rowstride % 4);
        rowstride += offset;
        size = rowstride * height;
        data = heap_new_n(size, guchar);
        dest = data;
        for (j = 0; j < height; ++j)
        {
            for (i = 0; i < width; ++i, dest += 3)
            {
                dest[0] = *pixel_data;
                dest[1] = *pixel_data;
                dest[2] = *pixel_data;
                pixel_data += 1;
            }

            dest += offset;
        }
        break;
    }

        cassert_default();
    }

    pixbuf = gdk_pixbuf_new_from_data((const guchar *)data, colorspace, has_alpha, bits_per_sample, (int)width, (int)height, rowstride, i_destroy_pixbuf_data, (gpointer)(intptr_t)size);
    image = i_osimage(pixbuf);
    return image;
}

/*---------------------------------------------------------------------------*/

static __INLINE bool_t i_is_gif_buffer(const byte_t *data, const uint32_t size)
{
    if (size >= 6)
    {
        const char_t *str = (const char_t *)data;
        if (str_equ_cn(str, "GIF87a", 6) == TRUE || str_equ_cn(str, "GIF89a", 6) == TRUE)
            return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static GdkPixbuf *i_pixbuf_from_data(const byte_t *data, const uint32_t size)
{
#if (GDK_PIXBUF_MAJOR > 2 || (GDK_PIXBUF_MAJOR == 2 && GDK_PIXBUF_MINOR >= 14))
    GInputStream *stream = g_memory_input_stream_new_from_data((const void *)data, (gssize)size, NULL);
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_stream(stream, NULL, NULL);
    gboolean ok = g_input_stream_close(stream, NULL, NULL);
    cassert_unref(ok == TRUE, ok);
    return pixbuf;

#else
    /* Only support for GdkPixbuf from file */
    const char_t *tempfile = "/tmp/___imgdata2303temp___.bin";
    GdkPixbuf *pixbuf = NULL;
    if (hfile_from_data(tempfile, data, size, NULL) == TRUE)
    {
        pixbuf = gdk_pixbuf_new_from_file((const char *)tempfile, NULL);
        bfile_delete(tempfile, NULL);
    }

    return pixbuf;

#endif
}

/*---------------------------------------------------------------------------*/

static GdkPixbufAnimation *i_animation_from_data(const byte_t *data, const uint32_t size)
{
#if (GDK_PIXBUF_MAJOR > 2 || (GDK_PIXBUF_MAJOR == 2 && GDK_PIXBUF_MINOR >= 28))
    GInputStream *stream = g_memory_input_stream_new_from_data((const void *)data, (gssize)size, NULL);
    GdkPixbufAnimation *animation = gdk_pixbuf_animation_new_from_stream(stream, NULL, NULL);
    gboolean ok = g_input_stream_close(stream, NULL, NULL);
    cassert_unref(ok == TRUE, ok);
    return animation;

#else
    /* Only support for GdkPixbufAnimation from file */
    const char_t *tempfile = "/tmp/___imgdata2303temp___.bin";
    GdkPixbufAnimation *animation = NULL;
    if (hfile_from_data(tempfile, data, size, NULL) == TRUE)
    {
        animation = gdk_pixbuf_animation_new_from_file((const char *)tempfile, NULL);
        bfile_delete(tempfile, NULL);
    }

    return animation;

#endif
}

/*---------------------------------------------------------------------------*/

#if (GDK_PIXBUF_MAJOR > 2 || (GDK_PIXBUF_MAJOR == 2 && GDK_PIXBUF_MINOR >= 4))

static gboolean i_encode(const gchar *data, gsize size, GError **error, gpointer stream)
{
    stm_write((Stream *)stream, (const byte_t *)data, (uint32_t)size);
    unref(error);
    return TRUE;
}

#endif

/*---------------------------------------------------------------------------*/

static void i_pixbuf_save(GdkPixbuf *pixbuf, const char *type, Stream *stm)
{
    gboolean ok = FALSE;
#if (GDK_PIXBUF_MAJOR > 2 || (GDK_PIXBUF_MAJOR == 2 && GDK_PIXBUF_MINOR >= 4))
    ok = gdk_pixbuf_save_to_callback(pixbuf, i_encode, (gpointer)stm, type, NULL, NULL);
    cassert_unref(ok == TRUE, ok);

#else
    const char_t *tempfile = "/tmp/___imgdata2303temp___.bin";
    Buffer *buffer = NULL;
    ok = gdk_pixbuf_save(pixbuf, tempfile, type, NULL, NULL);
    cassert_unref(ok == TRUE, ok);
    buffer = hfile_buffer(tempfile, NULL);
    if (buffer != NULL)
    {
        const byte_t *data = buffer_data(buffer);
        uint32_t size = buffer_size(buffer);
        stm_write(stm, data, size);
        buffer_destroy(&buffer);
    }

#endif
}

/*---------------------------------------------------------------------------*/

static OSImage *i_single_osimage_from_data(const byte_t *data, const uint32_t size)
{
    GdkPixbuf *pixbuf = i_pixbuf_from_data(data, size);
    return i_osimage(pixbuf);
}

/*---------------------------------------------------------------------------*/

static OSImage *i_multiple_osimage_from_data(const byte_t *data, const uint32_t size, const uint32_t num_frames)
{
    GdkPixbufAnimation *animation = i_animation_from_data(data, size);
    return i_osanimation(animation, num_frames);
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_create_from_data(const byte_t *data, const uint32_t size)
{
    OSImage *image = NULL;

    cassert_no_null(data);
    cassert(size > 0);

    if (i_is_gif_buffer(data, size) == FALSE)
    {
        image = i_single_osimage_from_data(data, size);
    }
    else
    {
        uint32_t num_frames = imgutil_num_frames(data, size);
        if (num_frames == 1)
            image = i_single_osimage_from_data(data, size);
        else
            image = i_multiple_osimage_from_data(data, size, num_frames);
    }

    return image;
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_create_from_type(const char_t *file_type)
{
    /* TODO */
    unref(file_type);
    cassert(FALSE);
    return NULL;
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_create_scaled(const OSImage *image, const uint32_t new_width, const uint32_t new_height)
{
    cassert_no_null(image);
    if (image->pixbuf != NULL)
    {
        GdkPixbuf *cpixbuf = gdk_pixbuf_scale_simple(image->pixbuf, (int)new_width, (int)new_height, GDK_INTERP_BILINEAR);
        return i_osimage(cpixbuf);
    }
    else
    {
        /* At the moment, animations are not scaled */
        GdkPixbufAnimation *canimation = NULL;
        cassert(image->animation != NULL);
        canimation = g_object_ref(image->animation);
        return i_osanimation(canimation, image->num_frames);
    }
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_from_context(DCtx **ctx)
{
    gint w, h;
    GdkPixbuf *pixbuf = NULL;

    cassert_no_null(ctx);
    cassert_no_null(*ctx);

    w = cairo_image_surface_get_width((*ctx)->surface);
    h = cairo_image_surface_get_height((*ctx)->surface);
    pixbuf = gdk_pixbuf_get_from_surface((*ctx)->surface, 0, 0, w, h);

    if ((*ctx)->format == ekGRAY8)
    {
        guchar *pixels = gdk_pixbuf_get_pixels(pixbuf);
        gboolean alpha = gdk_pixbuf_get_has_alpha(pixbuf);
        register uint32_t i, j, offset = alpha ? 4 : 3;
        int stride = gdk_pixbuf_get_rowstride(pixbuf) - (offset * w);
        for (j = 0; j < (uint32_t)h; ++j)
        {
            for (i = 0; i < (uint32_t)w; ++i)
            {
                guchar gray = (guchar)((77 * pixels[0] + 148 * pixels[1] + 30 * pixels[2]) / 255);
                pixels[0] = gray;
                pixels[1] = gray;
                pixels[2] = gray;
                pixels += offset;
            }

            pixels += stride;
        }
    }

    dctx_destroy(ctx);

    return i_osimage(pixbuf);
}

/*---------------------------------------------------------------------------*/

void osimage_destroy(OSImage **image)
{
    cassert_no_null(image);
    cassert_no_null(*image);
    if ((*image)->pixbuf != NULL)
    {
        g_object_unref((*image)->pixbuf);
    }
    else
    {
        cassert_no_null((*image)->animation);
        g_object_unref((*image)->animation);
    }

    heap_delete(image, OSImage);
}

/*---------------------------------------------------------------------------*/

static bool_t i_gray_image(const byte_t *data, const uint32_t width, const uint32_t height, const uint32_t bpp, const uint32_t stride)
{
    uint32_t i = 0, j = 0;
    for (j = 0; j < height; ++j)
    {
        for (i = 0; i < width; ++i)
        {
            if (data[0] != data[1] || data[0] != data[2])
                return FALSE;

            data += bpp;
        }

        data += stride;
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_has_alpha(const byte_t *data, const uint32_t width, const uint32_t height, const uint32_t bpp, const uint32_t stride)
{
    uint32_t i = 0, j = 0;
    cassert(bpp == 4);
    cassert(stride == 0);
    for (j = 0; j < height; ++j)
    {
        for (i = 0; i < width; ++i)
        {
            if (data[3] != 255)
                return TRUE;

            data += bpp;
        }

        data += stride;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static Pixbuf *i_bitmap_pixels(const byte_t *data, const uint32_t width, const uint32_t height, const uint32_t bpp, const uint32_t stride, const pixformat_t format)
{
    Pixbuf *pixels = pixbuf_create(width, height, format);
    byte_t *pdata = pixbuf_data(pixels);
    register uint32_t n = width * height, i = 0, j = 0;
    if (format == ekRGBA32)
    {
        cassert(bpp == 4);
        cassert(stride == 0);
        bmem_copy(pdata, data, n * 4);
    }
    else if (format == ekRGB24)
    {
        cassert(bpp == 3 || bpp == 4);
        for (j = 0; j < height; ++j)
        {
            for (i = 0; i < width; ++i)
            {
                pdata[0] = data[0];
                pdata[1] = data[1];
                pdata[2] = data[2];
                pdata += 3;
                data += bpp;
            }

            data += stride;
        }
    }
    else
    {
        cassert(bpp == 1 || bpp == 3 || bpp == 4);
        cassert(format == ekGRAY8);
        for (j = 0; j < height; ++j)
        {
            for (i = 0; i < width; ++i)
            {
                pdata[0] = data[0];
                pdata += 1;
                data += bpp;
            }

            data += stride;
        }
    }

    return pixels;
}

/*---------------------------------------------------------------------------*/

/* Avoid GTimeVal deprecation warnings */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static __INLINE GTimeVal i_time_init(void)
{
    GTimeVal tval;
    tval.tv_sec = 0;
    tval.tv_usec = 0;
    return tval;
}

/*---------------------------------------------------------------------------*/

static void i_time_add_ms(GTimeVal *tval, const uint32_t msecs)
{
    cassert_no_null(tval);
    tval->tv_usec += msecs * 1000;
    tval->tv_sec += tval->tv_usec / 1000000;
    tval->tv_usec = tval->tv_usec % 1000000;
}

#pragma GCC diagnostic pop

/*---------------------------------------------------------------------------*/

/* http://www.manpagez.com/html/gdk-pixbuf/gdk-pixbuf-2.34.0/gdk-pixbuf-Animations.php
Note that some formats, like GIF, might clamp the timeout values in the image
file to avoid updates that are just too quick. The minimum timeout for GIF
images is currently 20 milliseconds. */
static int i_animation_delay(GdkPixbufAnimation *animation, const uint32_t frame)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    GTimeVal tval = i_time_init();
#pragma GCC diagnostic pop

    GdkPixbufAnimationIter *iter = gdk_pixbuf_animation_get_iter(animation, &tval);
    int delay = gdk_pixbuf_animation_iter_get_delay_time(iter);
    uint32_t i = 0;

    for (i = 0; i < frame; ++i)
    {
        gboolean next_frame = FALSE;

#if defined(__ASSERTS__)
        i_time_add_ms(&tval, delay - 1);
        cassert(gdk_pixbuf_animation_iter_advance(iter, &tval) == FALSE);
        i_time_add_ms(&tval, 1);
#else
        i_time_add_ms(&tval, delay);
#endif

        next_frame = gdk_pixbuf_animation_iter_advance(iter, &tval);
        cassert_unref(next_frame == TRUE, next_frame);
        delay = gdk_pixbuf_animation_iter_get_delay_time(iter);
    }

    g_object_unref(iter);
    return delay;
}

/*---------------------------------------------------------------------------*/

static const GdkPixbuf *i_animation_pixbuf(GdkPixbufAnimation *animation, const uint32_t frame)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    GTimeVal tval = i_time_init();
#pragma GCC diagnostic pop

    GdkPixbufAnimationIter *iter = gdk_pixbuf_animation_get_iter(animation, &tval);
    GdkPixbuf *pixbuf = NULL;
    uint32_t i = 0;

    for (i = 0; i < frame; ++i)
    {
        int delay = gdk_pixbuf_animation_iter_get_delay_time(iter);
        gboolean next_frame = FALSE;

#if defined(__ASSERTS__)
        i_time_add_ms(&tval, delay - 1);
        cassert(gdk_pixbuf_animation_iter_advance(iter, &tval) == FALSE);
        i_time_add_ms(&tval, 1);
#else
        i_time_add_ms(&tval, delay);
#endif

        next_frame = gdk_pixbuf_animation_iter_advance(iter, &tval);
        cassert_unref(next_frame == TRUE, next_frame);
    }

    pixbuf = gdk_pixbuf_animation_iter_get_pixbuf(iter);
    g_object_unref(iter);
    return pixbuf;
}

/*---------------------------------------------------------------------------*/

static const GdkPixbuf *i_image_pixbuf(const OSImage *image)
{
    cassert_no_null(image);
    if (image->pixbuf != NULL)
    {
        return image->pixbuf;
    }
    else
    {
        cassert_no_null(image->animation);
        return i_animation_pixbuf(image->animation, 0);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE uint32_t i_width(const OSImage *image)
{
    cassert_no_null(image);
    if (image->pixbuf != NULL)
    {
        return gdk_pixbuf_get_width(image->pixbuf);
    }
    else
    {
        cassert_no_null(image->animation);
        return gdk_pixbuf_animation_get_width(image->animation);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE uint32_t i_height(const OSImage *image)
{
    cassert_no_null(image);
    if (image->pixbuf != NULL)
    {
        return gdk_pixbuf_get_height(image->pixbuf);
    }
    else
    {
        cassert_no_null(image->animation);
        return gdk_pixbuf_animation_get_height(image->animation);
    }
}

/*---------------------------------------------------------------------------*/

void osimage_info(const OSImage *image, uint32_t *width, uint32_t *height, pixformat_t *format, Pixbuf **pixels)
{
    cassert_no_null(image);

    if (width != NULL)
        *width = i_width(image);

    if (height != NULL)
        *height = i_height(image);

    if (format != NULL || pixels != NULL)
    {
        pixformat_t lformat = ENUM_MAX(pixformat_t);
        const GdkPixbuf *pixbuf = i_image_pixbuf(image);
        const byte_t *buffer = (const byte_t *)gdk_pixbuf_get_pixels(pixbuf);
        uint32_t w = gdk_pixbuf_get_width(pixbuf);
        uint32_t h = gdk_pixbuf_get_height(pixbuf);
        uint32_t bits_per_pixel = gdk_pixbuf_get_n_channels(pixbuf) * 8;
        uint32_t offset = bits_per_pixel / 8;
        uint32_t stride = gdk_pixbuf_get_rowstride(pixbuf) - (offset * w);

        cassert(bits_per_pixel == 24 || bits_per_pixel == 32);
        cassert(w == i_width(image));
        cassert(h == i_height(image));

        if (bits_per_pixel == 24 && gdk_pixbuf_get_has_alpha(pixbuf) == TRUE)
        {
            bits_per_pixel = 32;
            offset = 4;
        }

        if (bits_per_pixel == 8)
        {
            lformat = ekGRAY8;
        }
        else if (bits_per_pixel == 24)
        {
            if (i_gray_image(buffer, w, h, 3, stride) == TRUE)
                lformat = ekGRAY8;
            else
                lformat = ekRGB24;
        }
        else if (bits_per_pixel == 32)
        {
            if (i_has_alpha(buffer, w, h, 4, stride) == TRUE)
                lformat = ekRGBA32;
            else if (i_gray_image(buffer, w, h, 4, stride) == TRUE)
                lformat = ekGRAY8;
            else
                lformat = ekRGB24;
        }

        ptr_assign(format, lformat);

        if (pixels != NULL)
        {
            if (lformat != ENUM_MAX(pixformat_t))
                *pixels = i_bitmap_pixels(buffer, w, h, (uint32_t)(bits_per_pixel / 8), stride, lformat);
            else
                *pixels = NULL;
        }
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE const gchar *i_codec(const codec_t codec)
{
    switch (codec)
    {
    case ekJPG:
        return "jpeg";
    case ekPNG:
        return "png";
    case ekBMP:
        return "bmp";
    case ekGIF:
        return "gif";
        cassert_default();
    }

    return "";
}

/*---------------------------------------------------------------------------*/

bool_t osimage_available_codec(const OSImage *image, const codec_t codec)
{
    GSList *slist0 = gdk_pixbuf_get_formats();
    GSList *slist = NULL;
    const gchar *scodec = i_codec(codec);
    bool_t ok = FALSE;

    unref(image);

    for (slist = slist0; slist; slist = g_slist_next(slist))
    {
        GdkPixbufFormat *format = slist->data;
#if (GDK_PIXBUF_MAJOR > 2 || (GDK_PIXBUF_MAJOR == 2 && GDK_PIXBUF_MINOR >= 2))
        const gchar *name = gdk_pixbuf_format_get_name(format);
        gboolean writable = gdk_pixbuf_format_is_writable(format);
#else
        const gchar *name = format->name;
        gboolean writable = (format->flags & GDK_PIXBUF_FORMAT_WRITABLE) != 0;
#endif

        if (str_equ_c(name, scodec) == TRUE)
        {
            ok = writable;
            break;
        }
    }

    g_slist_free(slist0);
    return ok;
}

/*---------------------------------------------------------------------------*/

void osimage_write(const OSImage *image, const codec_t codec, Stream *stream)
{
    const char *type = i_codec(codec);
    cassert_no_null(image);
    if (image->pixbuf != NULL)
    {
        i_pixbuf_save(image->pixbuf, type, stream);
    }
    else
    {
        GdkPixbuf *pixbuf = NULL;
        cassert_no_null(image->animation);
        pixbuf = gdk_pixbuf_animation_get_static_image(image->animation);
        i_pixbuf_save(pixbuf, type, stream);
    }
}

/*---------------------------------------------------------------------------*/

void osimage_frames(const OSImage *image, uint32_t *num_frames, uint32_t *num_loops)
{
    cassert_no_null(image);
    unref(num_loops);
    if (num_frames != NULL)
        *num_frames = image->num_frames;
}

/*---------------------------------------------------------------------------*/

void osimage_frame(const OSImage *image, const uint32_t frame_index, real32_t *frame_length)
{
    cassert_no_null(image);
    cassert_no_null(frame_length);
    cassert_no_null(image->animation);
    cassert(frame_index < image->num_frames);
    *frame_length = .001f * i_animation_delay(image->animation, frame_index);
}

/*---------------------------------------------------------------------------*/

const void *osimage_native(const OSImage *image)
{
    return (const void *)osimage_pixbuf(image, 0);
}

/*---------------------------------------------------------------------------*/

const GdkPixbuf *osimage_pixbuf(const OSImage *image, const uint32_t frame_index)
{
    cassert_no_null(image);
    if (image->pixbuf != NULL)
    {
        return image->pixbuf;
    }
    else
    {
        cassert_no_null(image->animation);
        return i_animation_pixbuf(image->animation, frame_index);
    }
}
