/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dctxh.h
 *
 */

/* Undocumented (hidden) API about drawing context */

#include "draw2d.hxx"

__EXTERN_C

_draw2d_api DCtx *dctx_create(void);

_draw2d_api void dctx_destroy(DCtx **ctx);

_draw2d_api void dctx_set_gcontext(DCtx *ctx, void *gcontext, const uint32_t width, const uint32_t height, const real32_t offset_x, const real32_t offset_y, const uint32_t background, const bool_t reset);

_draw2d_api void dctx_unset_gcontext(DCtx *ctx);

_draw2d_api void dctx_set_flipped(DCtx *ctx, const bool_t flipped);

_draw2d_api void dctx_size(const DCtx *ctx, uint32_t *width, uint32_t *height);

_draw2d_api void dctx_offset(const DCtx *ctx, real32_t *offset_x, real32_t *offset_y);

_draw2d_api void dctx_line_dash(const DCtx *ctx, real32_t *pattern, uint32_t *size);

_draw2d_api real32_t dctx_text_width(const DCtx *ctx);

_draw2d_api align_t dctx_text_intalign(const DCtx *ctx);

_draw2d_api color_t dctx_text_color(const DCtx *ctx);

_draw2d_api color_t dctx_line_color(const DCtx *ctx);

_draw2d_api color_t dctx_background_color(const DCtx *ctx);

_draw2d_api ellipsis_t dctx_text_trim(const DCtx *ctx);

_draw2d_api void *dctx_native(DCtx *ctx);

_draw2d_api void *dctx_internal_bitmap(DCtx *ctx);

_draw2d_api void dctx_data_imp(DCtx *ctx, void *data, FPtr_destroy func_destroy_data);

_draw2d_api void *dctx_get_data_imp(const DCtx *ctx);

_draw2d_api void dctx_set_default_osfont(DCtx *ctx, const void *font);

_draw2d_api void draw_set_raster_mode(DCtx *ctx);

_draw2d_api void draw_text_raster(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y);

_draw2d_api void draw_image_raster(DCtx *ctx, const Image *image, const real32_t x, const real32_t y);

_draw2d_api void draw_line_imp(DCtx *ctx, const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1, const bool_t raster);

_draw2d_api void draw_rect_imp(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t width, const real32_t height, const bool_t raster);

__END_C

#define dctx_data(ctx, data, func_destroy_data, type) \
    ( \
        (void)((type *)data == data), \
        FUNC_CHECK_DESTROY(func_destroy_data, type), \
        dctx_data_imp(ctx, (void *)data, (FPtr_destroy)func_destroy_data))

#define dctx_get_data(ctx, type) \
    (type *)dctx_get_data_imp(ctx)
