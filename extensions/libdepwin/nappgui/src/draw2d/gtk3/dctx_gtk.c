/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dctx_gtk.c
 *
 */

/* Draw context */

#include "dctx.h"
#include "dctxh.h"
#include "dctx.inl"
#include "dctx_gtk.inl"
#include "draw2d_gtk.ixx"
#include "color.h"
#include "font.h"
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <core/heap.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

/*---------------------------------------------------------------------------*/

DCtx *dctx_create(void)
{
    DCtx *ctx = heap_new0(DCtx);
    cairo_matrix_init_identity(&ctx->transform);
    cairo_matrix_init_identity(&ctx->pattern_matrix);
    return ctx;
}

/*---------------------------------------------------------------------------*/

void dctx_destroy(DCtx **ctx)
{
    cassert_no_null(ctx);
    cassert_no_null(*ctx);

    if ((*ctx)->surface != NULL)
    {
        cairo_surface_destroy((*ctx)->surface);
        cairo_destroy((*ctx)->cairo);
    }
    else
    {
        cassert((*ctx)->cairo == NULL);
    }

    if ((*ctx)->lpattern != NULL)
        cairo_pattern_destroy((*ctx)->lpattern);

    if ((*ctx)->font != NULL)
        font_destroy(&(*ctx)->font);

    if ((*ctx)->layout != NULL)
        g_object_unref((*ctx)->layout);

    heap_delete(ctx, DCtx);
}

/*---------------------------------------------------------------------------*/

void dctx_set_gcontext(DCtx *ctx, void *gcontext, const uint32_t width, const uint32_t height, const real32_t offset_x, const real32_t offset_y, const uint32_t background, const bool_t reset)
{
    cassert_no_null(ctx);
    cassert_no_null(gcontext);
    unref(background);
    ctx->offset_x = (double)offset_x;
    ctx->offset_y = (double)offset_y;
    ctx->width = width;
    ctx->height = height;
    ctx->cairo = (cairo_t *)gcontext;
    cairo_translate(ctx->cairo, -(double)offset_x, -(double)offset_y);
    cairo_get_matrix(ctx->cairo, &ctx->origin);
    ctx->raster_mode = FALSE;

    if (reset == TRUE)
        dctx_init(ctx);
}

/*---------------------------------------------------------------------------*/

void dctx_unset_gcontext(DCtx *ctx)
{
    cassert_no_null(ctx);
    cassert_unref(ctx->cairo != NULL, ctx);
    cairo_translate(ctx->cairo, ctx->offset_x, ctx->offset_y);
    ctx->cairo = NULL;
}

/*---------------------------------------------------------------------------*/

void dctx_set_flipped(DCtx *ctx, const bool_t flipped)
{
    unref(ctx);
    unref(flipped);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void dctx_size(const DCtx *ctx, uint32_t *width, uint32_t *height)
{
    cassert_no_null(ctx);
    ptr_assign(width, ctx->width);
    ptr_assign(height, ctx->height);
}

/*---------------------------------------------------------------------------*/

void dctx_offset(const DCtx *ctx, real32_t *offset_x, real32_t *offset_y)
{
    cassert_no_null(ctx);
    cassert_no_null(offset_x);
    cassert_no_null(offset_y);
    *offset_x = (real32_t)ctx->offset_x;
    *offset_y = (real32_t)ctx->offset_y;
}

/*---------------------------------------------------------------------------*/

void dctx_line_dash(const DCtx *ctx, real32_t *pattern, uint32_t *size)
{
    unref(ctx);
    unref(pattern);
    unref(size);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

real32_t dctx_text_width(const DCtx *ctx)
{
    unref(ctx);
    cassert(FALSE);
    return 0;
}

/*---------------------------------------------------------------------------*/

align_t dctx_text_intalign(const DCtx *ctx)
{
    unref(ctx);
    cassert(FALSE);
    return ekLEFT;
}

/*---------------------------------------------------------------------------*/

color_t dctx_text_color(const DCtx *ctx)
{
    cassert_no_null(ctx);
    return ctx->text_color;
}

/*---------------------------------------------------------------------------*/

color_t dctx_line_color(const DCtx *ctx)
{
    unref(ctx);
    cassert(FALSE);
    return 0;
}

/*---------------------------------------------------------------------------*/

color_t dctx_background_color(const DCtx *ctx)
{
    unref(ctx);
    cassert(FALSE);
    return 0;
}

/*---------------------------------------------------------------------------*/

static __INLINE ellipsis_t i_nellipsis(const PangoEllipsizeMode ellipsis)
{
    switch (ellipsis)
    {
    case PANGO_ELLIPSIZE_NONE:
        return ekELLIPNONE;
    case PANGO_ELLIPSIZE_START:
        return ekELLIPBEGIN;
    case PANGO_ELLIPSIZE_MIDDLE:
        return ekELLIPMIDDLE;
    case PANGO_ELLIPSIZE_END:
        return ekELLIPEND;
        cassert_default();
    }

    return ekELLIPNONE;
}

/*---------------------------------------------------------------------------*/

ellipsis_t dctx_text_trim(const DCtx *ctx)
{
    cassert_no_null(ctx);
    return i_nellipsis(ctx->ellipsis);
}

/*---------------------------------------------------------------------------*/

void *dctx_native(DCtx *ctx)
{
    cassert_no_null(ctx);
    return (void *)ctx->cairo;
}

/*---------------------------------------------------------------------------*/

void *dctx_internal_bitmap(DCtx *ctx)
{
    unref(ctx);
    cassert(FALSE);
    return NULL;
}

/*---------------------------------------------------------------------------*/

void dctx_data_imp(DCtx *ctx, void *data, FPtr_destroy func_destroy_data)
{
    unref(ctx);
    unref(data);
    unref(func_destroy_data);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void *dctx_get_data_imp(const DCtx *ctx)
{
    unref(ctx);
    cassert(FALSE);
    return NULL;
}

/*---------------------------------------------------------------------------*/

DCtx *dctx_bitmap(const uint32_t width, const uint32_t height, const pixformat_t format)
{
    DCtx *ctx = heap_new0(DCtx);
    cairo_format_t pf = CAIRO_FORMAT_INVALID;

    switch (format)
    {
    case ekGRAY8:
    case ekRGB24:
        pf = CAIRO_FORMAT_RGB24;
        break;
    case ekRGBA32:
        pf = CAIRO_FORMAT_ARGB32;
        break;
    case ekINDEX1:
    case ekINDEX2:
    case ekINDEX4:
    case ekINDEX8:
        cassert_default();
    }

    ctx->format = format;
    ctx->offset_x = 0;
    ctx->offset_y = 0;
    ctx->width = width;
    ctx->height = height;
    ctx->surface = cairo_image_surface_create(pf, (int)width, (int)height);
    ctx->cairo = cairo_create(ctx->surface);
    cairo_matrix_init_identity(&ctx->origin);
    cairo_matrix_init_identity(&ctx->transform);
    cairo_matrix_init_identity(&ctx->pattern_matrix);
    dctx_init(ctx);
    return ctx;
}

/*---------------------------------------------------------------------------*/

void dctx_transform(DCtx *ctx, const T2Df *t2d, const bool_t cartesian)
{
    cairo_matrix_t transform;
    cassert_no_null(ctx);
    cassert_no_null(t2d);
    transform.xx = (double)t2d->i.x;
    transform.yx = (double)t2d->i.y;
    transform.xy = (double)t2d->j.x;
    transform.yy = (double)t2d->j.y;
    transform.x0 = (double)t2d->p.x;
    transform.y0 = (double)t2d->p.y;
    ctx->transform = transform;
    ctx->cartesian_system = cartesian;

    if (ctx->raster_mode == FALSE)
    {
        cairo_set_matrix(ctx->cairo, &ctx->origin);
        cairo_transform(ctx->cairo, &transform);
        _dctx_gradient_transform(ctx);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_color(cairo_t *cairo, const color_t color, color_t *source_color)
{
    /*if (color != *source_color)*/
    {
        real32_t r, g, b, a;
        color_get_rgbaf(color, &r, &g, &b, &a);
        cairo_set_source_rgba(cairo, (double)r, (double)g, (double)b, (double)a);
        *source_color = color;
    }
}

/*---------------------------------------------------------------------------*/

void draw_clear(DCtx *ctx, const color_t color)
{
    cassert_no_null(ctx);
    i_color(ctx->cairo, color, &ctx->source_color);
    cairo_paint(ctx->cairo);
}

/*---------------------------------------------------------------------------*/

void draw_antialias(DCtx *ctx, const bool_t on)
{
    cairo_antialias_t anti;
    cassert_no_null(ctx);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
    anti = on ? CAIRO_ANTIALIAS_GOOD : CAIRO_ANTIALIAS_NONE;
#else
    anti = on ? CAIRO_ANTIALIAS_SUBPIXEL : CAIRO_ANTIALIAS_NONE;
#endif

    cairo_set_antialias(ctx->cairo, anti);
}

/*---------------------------------------------------------------------------*/

void _dctx_gradient_transform(DCtx *ctx)
{
    cassert_no_null(ctx);
    if (ctx->lpattern != NULL)
    {
        cairo_matrix_t matrix = ctx->pattern_matrix;
        cairo_matrix_invert(&matrix);
        cairo_matrix_multiply(&matrix, &ctx->transform, &matrix);
        cairo_pattern_set_matrix(ctx->lpattern, &matrix);
    }
}
