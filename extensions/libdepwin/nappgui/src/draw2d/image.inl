/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: image.inl
 *
 */

/* Images */

#include "draw2d.ixx"

__EXTERN_C

void osimage_alloc_globals(void);

void osimage_dealloc_globals(void);

OSImage *osimage_create_from_pixels(const uint32_t width, const uint32_t height, const pixformat_t format, const byte_t *pixel_data);

OSImage *osimage_create_from_data(const byte_t *data, const uint32_t size);

OSImage *osimage_create_from_type(const char_t *file_type);

OSImage *osimage_create_scaled(const OSImage *image, const uint32_t new_width, const uint32_t new_height);

OSImage *osimage_from_context(DCtx **ctx);

const OSImage *osimage_from_image(const Image *image);

void osimage_destroy(OSImage **image);

void osimage_info(const OSImage *image, uint32_t *width, uint32_t *height, pixformat_t *format, Pixbuf **pixels);

bool_t osimage_available_codec(const OSImage *image, const codec_t codec);

void osimage_write(const OSImage *image, const codec_t codec, Stream *stm);

void osimage_frames(const OSImage *image, uint32_t *num_frames, uint32_t *num_loops);

void osimage_frame(const OSImage *image, const uint32_t frame_index, real32_t *frame_length);

const void *osimage_native(const OSImage *image);

__END_C
