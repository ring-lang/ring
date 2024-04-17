/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: image.h
 * https://nappgui.com/en/draw2d/image.html
 *
 */

/* Images */

#include "draw2d.hxx"

__EXTERN_C

_draw2d_api Image *image_from_pixels(const uint32_t width, const uint32_t height, const pixformat_t format, const byte_t *data, const color_t *palette, const uint32_t palsize);

_draw2d_api Image *image_from_pixbuf(const Pixbuf *pixbuf, const Palette *palette);

_draw2d_api Image *image_from_file(const char_t *pathname, ferror_t *error);

_draw2d_api Image *image_from_data(const byte_t *data, const uint32_t size);

_draw2d_api const Image *image_from_resource(const ResPack *pack, const ResId id);

_draw2d_api Image *image_copy(const Image *image);

_draw2d_api Image *image_trim(const Image *image, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height);

_draw2d_api Image *image_rotate(const Image *image, const real32_t angle, const bool_t nsize, const color_t background, T2Df *t2d);

_draw2d_api Image *image_scale(const Image *image, const uint32_t nwidth, const uint32_t nheight);

_draw2d_api Image *image_read(Stream *stm);

_draw2d_api bool_t image_to_file(const Image *image, const char_t *pathname, ferror_t *error);

_draw2d_api void image_write(Stream *stream, const Image *image);

_draw2d_api void image_destroy(Image **image);

_draw2d_api pixformat_t image_format(const Image *image);

_draw2d_api uint32_t image_width(const Image *image);

_draw2d_api uint32_t image_height(const Image *image);

_draw2d_api Pixbuf *image_pixels(const Image *image, const pixformat_t format);

_draw2d_api bool_t image_codec(const Image *image, const codec_t codec);

_draw2d_api codec_t image_get_codec(const Image *image);

_draw2d_api uint32_t image_num_frames(const Image *image);

_draw2d_api real32_t image_frame_length(const Image *image, const uint32_t findex);

_draw2d_api void image_data_imp(Image *image, void **data, FPtr_destroy func_destroy_data);

_draw2d_api void *image_get_data_imp(const Image *image);

_draw2d_api const void *image_native(const Image *image);

__END_C

#define image_data(image, data, func_destroy_data, type) \
    ( \
        (void)((type **)data == data), \
        FUNC_CHECK_DESTROY(func_destroy_data, type), \
        image_data_imp(image, (void **)data, (FPtr_destroy)func_destroy_data))

#define image_get_data(image, type) \
    (type *)image_get_data_imp(image)
