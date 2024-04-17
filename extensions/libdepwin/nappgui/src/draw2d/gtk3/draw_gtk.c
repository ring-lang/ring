/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw_gtk.c
 *
 */

/* Drawing commands */

#include "draw.h"
#include "dctxh.h"
#include "draw.inl"
#include "dctx_gtk.inl"
#include "osimage.inl"
#include "color.h"
#include "font.h"
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#include <sewer/nowarn.hxx>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <pango/pangocairo.h>
#include <gdk/gdk.h>
#include <sewer/warn.hxx>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

/*---------------------------------------------------------------------------*/

#define HALF_PI 1.57079632679

/*---------------------------------------------------------------------------*/

void draw_alloc_globals(void)
{
    /* This for 'gtk_settings_get_default' works
    Used in osfont::i_default_font()
    gtk_init(0, NULL); */
}

/*---------------------------------------------------------------------------*/

void draw_dealloc_globals(void)
{
}

/*---------------------------------------------------------------------------*/

void draw_word_extents(MeasureStr *data, const char_t *word, real32_t *width, real32_t *height)
{
    unref(data);
    unref(word);
    unref(width);
    unref(height);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

static void i_set_raster_mode(DCtx *ctx)
{
    cassert_no_null(ctx);
    cassert(ctx->raster_mode == FALSE);
    cairo_set_matrix(ctx->cairo, &ctx->origin);
    ctx->raster_mode = TRUE;
}

/*---------------------------------------------------------------------------*/

static void i_set_real2d_mode(DCtx *ctx)
{
    cassert_no_null(ctx);
    cassert(ctx->raster_mode == TRUE);
    cairo_set_matrix(ctx->cairo, &ctx->origin);
    cairo_transform(ctx->cairo, &ctx->transform);
    _dctx_gradient_transform(ctx);
    ctx->raster_mode = FALSE;
}

/*---------------------------------------------------------------------------*/

void draw_imgimp(DCtx *ctx, const OSImage *image, const uint32_t frame_index, const real32_t x, const real32_t y, const bool_t raster)
{
    gdouble nx = (gdouble)x;
    gdouble ny = (gdouble)y;
    const GdkPixbuf *pixbuf = osimage_pixbuf(image, frame_index);

    cassert_no_null(ctx);
    if (raster != ctx->raster_mode)
    {
        if (raster == TRUE)
            i_set_raster_mode(ctx);
        else
            i_set_real2d_mode(ctx);
    }

    if (ctx->image_halign != ekLEFT || ctx->image_valign != ekTOP)
    {
        gdouble w = (gdouble)gdk_pixbuf_get_width(pixbuf);
        gdouble h = (gdouble)gdk_pixbuf_get_height(pixbuf);

        switch (ctx->image_halign)
        {
        case ekLEFT:
        case ekJUSTIFY:
            break;
        case ekCENTER:
            nx -= w / 2;
            break;
        case ekRIGHT:
            nx -= w;
            break;
        }

        switch (ctx->image_valign)
        {
        case ekTOP:
        case ekJUSTIFY:
            break;
        case ekCENTER:
            ny -= h / 2;
            break;
        case ekBOTTOM:
            ny -= h;
            break;
        }
    }

    gdk_cairo_set_source_pixbuf(ctx->cairo, pixbuf, nx, ny);
    cairo_paint(ctx->cairo);
    ctx->source_color = 0;
}

/*---------------------------------------------------------------------------*/

void draw_line(DCtx *ctx, const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1)
{
    draw_line_imp(ctx, x0, y0, x1, y1, FALSE);
}

/*---------------------------------------------------------------------------*/

static void i_line_path(cairo_t *cairo, const V2Df *points, const uint32_t n, const bool_t closed)
{
    register uint32_t i;
    cassert_no_null(cairo);
    cassert_no_null(points);
    cassert(n > 0);

    cairo_move_to(cairo, (double)points->x, (double)points->y);
    points += 1;

    for (i = 1; i < n; ++i, ++points)
        cairo_line_to(cairo, (double)points->x, (double)points->y);

    if (closed)
        cairo_close_path(cairo);
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_color(cairo_t *cairo, const color_t color, color_t *source_color)
{
    /* Check ColorView if de-comment
    if (color != *source_color) */
    {
        real32_t r, g, b, a;
        color_get_rgbaf(color, &r, &g, &b, &a);
        cairo_set_source_rgba(cairo, (double)r, (double)g, (double)b, (double)a);
        *source_color = color;
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_fill_pattern(cairo_t *cairo, color_t fill_color, cairo_pattern_t *lpattern, fillmode_t fillmode, color_t *source_color)
{
    switch (fillmode)
    {
    case ekFILL_SOLID:
        i_color(cairo, fill_color, source_color);
        break;

    case ekFILL_LINEAR:
        cairo_set_source(cairo, lpattern);
        *source_color = 0;
        break;

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_line_pattern(DCtx *ctx)
{
    if (ctx->fill_line == TRUE)
        i_fill_pattern(ctx->cairo, ctx->fill_color, ctx->lpattern, ctx->fillmode, &ctx->source_color);
    else
        i_color(ctx->cairo, ctx->stroke_color, &ctx->source_color);
}

/*---------------------------------------------------------------------------*/

void draw_polyline(DCtx *ctx, const bool_t closed, const V2Df *points, const uint32_t n)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    i_line_path(ctx->cairo, points, n, closed);
    i_line_pattern(ctx);
    cairo_stroke(ctx->cairo);
}

/*---------------------------------------------------------------------------*/

void draw_arc(DCtx *ctx, const real32_t x, const real32_t y, const real32_t radius, const real32_t start, const real32_t sweep)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    if (sweep > 0)
        cairo_arc(ctx->cairo, (double)x, (double)y, (double)radius, (double)start, (double)(start + sweep));
    else
        cairo_arc_negative(ctx->cairo, (double)x, (double)y, (double)radius, (double)start, (double)(start + sweep));

    i_line_pattern(ctx);
    cairo_stroke(ctx->cairo);
}

/*---------------------------------------------------------------------------*/

void draw_bezier(DCtx *ctx, const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1, const real32_t x2, const real32_t y2, const real32_t x3, const real32_t y3)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    cairo_move_to(ctx->cairo, (double)x0, (double)y0);
    cairo_curve_to(ctx->cairo, (double)x1, (double)y1, (double)x2, (double)y2, (double)x3, (double)y3);
    i_line_pattern(ctx);
    cairo_stroke(ctx->cairo);
}

/*---------------------------------------------------------------------------*/

void draw_line_color(DCtx *ctx, const color_t color)
{
    cassert_no_null(ctx);
    ctx->stroke_color = color;
    ctx->fill_line = FALSE;
}

/*---------------------------------------------------------------------------*/

void draw_line_fill(DCtx *ctx)
{
    cassert_no_null(ctx);
    ctx->fill_line = TRUE;
}

/*---------------------------------------------------------------------------*/

void draw_line_width(DCtx *ctx, const real32_t width)
{
    cassert_no_null(ctx);
    cairo_set_line_width(ctx->cairo, (double)width);

    if (ctx->dash_count > 0)
    {
        double p[16];
        int i;

        for (i = 0; i < ctx->dash_count; ++i)
            p[i] = ctx->line_dash[i] * width;

        cairo_set_dash(ctx->cairo, p, ctx->dash_count, 0.);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE cairo_line_cap_t i_linecap(const linecap_t cap)
{
    switch (cap)
    {
    case ekLCFLAT:
        return CAIRO_LINE_CAP_BUTT;
    case ekLCSQUARE:
        return CAIRO_LINE_CAP_SQUARE;
    case ekLCROUND:
        return CAIRO_LINE_CAP_ROUND;
        cassert_default();
    };

    return CAIRO_LINE_CAP_BUTT;
}

/*---------------------------------------------------------------------------*/

void draw_line_cap(DCtx *ctx, const linecap_t cap)
{
    cassert_no_null(ctx);
    cairo_set_line_cap(ctx->cairo, i_linecap(cap));
}

/*---------------------------------------------------------------------------*/

static __INLINE cairo_line_join_t i_linejoin(const linejoin_t join)
{
    switch (join)
    {
    case ekLJMITER:
        return CAIRO_LINE_JOIN_MITER;
    case ekLJROUND:
        return CAIRO_LINE_JOIN_ROUND;
    case ekLJBEVEL:
        return CAIRO_LINE_JOIN_BEVEL;
        cassert_default();
    };

    return CAIRO_LINE_JOIN_MITER;
}

/*---------------------------------------------------------------------------*/

void draw_line_join(DCtx *ctx, const linejoin_t join)
{
    cassert_no_null(ctx);
    cairo_set_line_join(ctx->cairo, i_linejoin(join));
}

/*---------------------------------------------------------------------------*/

void draw_line_dash(DCtx *ctx, const real32_t *pattern, const uint32_t n)
{
    if (pattern != NULL && n > 0)
    {
        double p[16];
        double width = cairo_get_line_width(ctx->cairo);
        uint32_t i, pn = n < 16 ? n : 16;

        for (i = 0; i < pn; ++i)
        {
            ctx->line_dash[i] = (double)pattern[i];
            p[i] = (double)pattern[i] * width;
        }

        ctx->dash_count = pn;
        cairo_set_dash(ctx->cairo, p, pn, 0.);
    }
    else
    {
        ctx->dash_count = 0;
        cairo_set_dash(ctx->cairo, NULL, 0, 0.);
    }
}

/*---------------------------------------------------------------------------*/

static void i_draw(DCtx *ctx, const drawop_t op)
{
    cassert_no_null(ctx);
    switch (op)
    {
    case ekSTROKE:
        i_line_pattern(ctx);
        cairo_stroke(ctx->cairo);
        break;

    case ekFILL:
        i_fill_pattern(ctx->cairo, ctx->fill_color, ctx->lpattern, ctx->fillmode, &ctx->source_color);
        cairo_fill(ctx->cairo);
        break;

    case ekSKFILL:
        i_line_pattern(ctx);
        cairo_stroke_preserve(ctx->cairo);
        i_fill_pattern(ctx->cairo, ctx->fill_color, ctx->lpattern, ctx->fillmode, &ctx->source_color);
        cairo_fill(ctx->cairo);
        break;

    case ekFILLSK:
        i_fill_pattern(ctx->cairo, ctx->fill_color, ctx->lpattern, ctx->fillmode, &ctx->source_color);
        cairo_fill_preserve(ctx->cairo);
        i_line_pattern(ctx);
        cairo_stroke(ctx->cairo);
        break;

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void draw_rect(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);
    cairo_rectangle(ctx->cairo, (double)x, (double)y, (double)width, (double)height);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_rndrect(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t width, const real32_t height, const real32_t radius)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);
    cairo_new_sub_path(ctx->cairo);
    cairo_arc(ctx->cairo, x + width - radius, y + radius, radius, -HALF_PI, 0);
    cairo_arc(ctx->cairo, x + width - radius, y + height - radius, radius, 0, HALF_PI);
    cairo_arc(ctx->cairo, x + radius, y + height - radius, radius, HALF_PI, 2. * HALF_PI);
    cairo_arc(ctx->cairo, x + radius, y + radius, radius, 2. * HALF_PI, 3. * HALF_PI);
    cairo_close_path(ctx->cairo);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_circle(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t radius)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);
    cairo_arc(ctx->cairo, (double)x, (double)y, (double)radius, 0, 6.28318530718);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_ellipse(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t radx, const real32_t rady)
{
    double dy = (double)(rady / radx);
    double ny = y / dy;
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);
    cairo_save(ctx->cairo);
    cairo_scale(ctx->cairo, 1, dy);
    cairo_arc(ctx->cairo, (double)x, ny, (double)radx, 0, 6.28318530718);
    cairo_restore(ctx->cairo);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_polygon(DCtx *ctx, const drawop_t op, const V2Df *points, const uint32_t n)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);
    i_line_path(ctx->cairo, points, n, TRUE);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_fill_color(DCtx *ctx, const color_t color)
{
    cassert_no_null(ctx);
    ctx->fill_color = color;
    ctx->fillmode = ekFILL_SOLID;
}

/*---------------------------------------------------------------------------*/

void draw_fill_linear(DCtx *ctx, const color_t *color, const real32_t *stop, const uint32_t n, const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1)
{
    register uint32_t i;

    if (ctx->lpattern != NULL)
        cairo_pattern_destroy(ctx->lpattern);

    ctx->lpattern = cairo_pattern_create_linear((double)x0, (double)y0, (double)x1, (double)y1);
    cairo_pattern_set_extend(ctx->lpattern, ctx->wrap_mode);

    for (i = 0; i < n; ++i)
    {
        real32_t r, g, b, a;
        color_get_rgbaf(color[i], &r, &g, &b, &a);
        cairo_pattern_add_color_stop_rgba(ctx->lpattern, (double)stop[i], (double)r, (double)g, (double)b, (double)a);
    }

    ctx->fillmode = ekFILL_LINEAR;

    if (ctx->raster_mode == FALSE)
        _dctx_gradient_transform(ctx);
}

/*---------------------------------------------------------------------------*/

void draw_fill_matrix(DCtx *ctx, const T2Df *t2d)
{
    cassert_no_null(ctx);
    cassert_no_null(t2d);
    if (ctx->lpattern != NULL)
    {
        ctx->pattern_matrix.xx = (double)t2d->i.x;
        ctx->pattern_matrix.yx = (double)t2d->i.y;
        ctx->pattern_matrix.xy = (double)t2d->j.x;
        ctx->pattern_matrix.yy = (double)t2d->j.y;
        ctx->pattern_matrix.x0 = (double)t2d->p.x;
        ctx->pattern_matrix.y0 = (double)t2d->p.y;

        if (ctx->raster_mode == FALSE)
            _dctx_gradient_transform(ctx);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE cairo_extend_t i_wrap(const fillwrap_t wrap)
{
    switch (wrap)
    {
    case ekFCLAMP:
        return CAIRO_EXTEND_PAD;
    case ekFTILE:
        return CAIRO_EXTEND_REPEAT;
    case ekFFLIP:
        return CAIRO_EXTEND_REFLECT;
        cassert_default();
    }

    return CAIRO_EXTEND_PAD;
}

/*---------------------------------------------------------------------------*/

void draw_fill_wrap(DCtx *ctx, const fillwrap_t wrap)
{
    cassert_no_null(ctx);
    ctx->wrap_mode = i_wrap(wrap);
    if (ctx->lpattern != NULL)
        cairo_pattern_set_extend(ctx->lpattern, ctx->wrap_mode);
}

/*---------------------------------------------------------------------------*/

void draw_font(DCtx *ctx, const Font *font)
{
    cassert_no_null(ctx);
    if (ctx->font == NULL || font_equals(ctx->font, font) == FALSE)
    {
        if (ctx->font != NULL)
            font_destroy(&ctx->font);

        ctx->font = font_copy(font);

        if (ctx->layout != NULL)
        {
            const PangoFontDescription *fdesc = (PangoFontDescription *)font_native(ctx->font);
            pango_layout_set_font_description(ctx->layout, fdesc);
        }
    }
}

/*---------------------------------------------------------------------------*/

void draw_text_color(DCtx *ctx, const color_t color)
{
    cassert_no_null(ctx);
    ctx->text_color = color;
}

/*---------------------------------------------------------------------------*/

static void i_begin_text(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y)
{
    double nx = (double)x;
    double ny = (double)y;

    cassert_no_null(ctx);

    if (ctx->layout == NULL)
    {
        const PangoFontDescription *fdesc = NULL;
        cassert(ctx->font != NULL);
        fdesc = (PangoFontDescription *)font_native(ctx->font);
        ctx->layout = pango_cairo_create_layout(ctx->cairo);
        pango_layout_set_font_description(ctx->layout, fdesc);
    }

    pango_layout_set_text(ctx->layout, (const char *)text, -1);
    pango_layout_set_alignment(ctx->layout, ctx->text_intalign);
    pango_layout_set_width(ctx->layout, ctx->text_width < 0 ? -1 : (int)(ctx->text_width * PANGO_SCALE));
    /* pango_layout_set_wrap(ctx->layout, ctx->text_width < 0 ? PANGO_WRAP_CHAR); */
    pango_layout_set_ellipsize(ctx->layout, ctx->ellipsis);

    if (ctx->text_halign != ekLEFT || ctx->text_valign != ekTOP)
    {
        int w, h;
        pango_layout_get_pixel_size(ctx->layout, &w, &h);

        switch (ctx->text_halign)
        {
        case ekLEFT:
        case ekJUSTIFY:
            break;
        case ekRIGHT:
            nx = (double)(x - w);
            break;
        case ekCENTER:
            nx = (double)(x - (w / 2));
            break;
            cassert_default();
        }

        switch (ctx->text_valign)
        {
        case ekTOP:
        case ekJUSTIFY:
            break;
        case ekBOTTOM:
            ny = (double)(y - h);
            break;
        case ekCENTER:
            ny = (double)(y - (h / 2));
            break;
            cassert_default();
        }
    }

    if (ctx->cartesian_system == TRUE)
    {
        cairo_matrix_t matrix;
        matrix.xx = 1;
        matrix.yx = 0;
        matrix.xy = 0;
        matrix.yy = 1;
        matrix.x0 = 0;
        matrix.y0 = 0;
        cairo_save(ctx->cairo);
        cairo_transform(ctx->cairo, &matrix);
    }

    cairo_move_to(ctx->cairo, nx, ny);
}

/*---------------------------------------------------------------------------*/

void draw_text(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y)
{
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    i_begin_text(ctx, text, x, y);
    i_color(ctx->cairo, ctx->text_color, &ctx->source_color);
    pango_cairo_show_layout(ctx->cairo, ctx->layout);
    if (ctx->cartesian_system == TRUE)
        cairo_restore(ctx->cairo);
}

/*---------------------------------------------------------------------------*/

void draw_text_single_line(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y)
{
    unref(ctx);
    unref(text);
    unref(x);
    unref(y);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void draw_text_path(DCtx *ctx, const drawop_t op, const char_t *text, const real32_t x, const real32_t y)
{
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    i_begin_text(ctx, text, x, y);

    if (op == ekFILL && ctx->fillmode == ekFILL_SOLID)
    {
        i_color(ctx->cairo, ctx->fill_color, &ctx->source_color);
        pango_cairo_show_layout(ctx->cairo, ctx->layout);
    }
    else
    {
        cassert(ctx->text_width <= 0);
        pango_cairo_layout_path(ctx->cairo, ctx->layout);
        i_draw(ctx, op);
    }

    if (ctx->cartesian_system == TRUE)
        cairo_restore(ctx->cairo);
}

/*---------------------------------------------------------------------------*/

void draw_text_width(DCtx *ctx, const real32_t width)
{
    cassert_no_null(ctx);
    ctx->text_width = width;
}

/*---------------------------------------------------------------------------*/

static __INLINE PangoEllipsizeMode i_ellipsis(const ellipsis_t ellipsis)
{
    switch (ellipsis)
    {
    case ekELLIPNONE:
    case ekELLIPMLINE:
        return PANGO_ELLIPSIZE_NONE;
    case ekELLIPBEGIN:
        return PANGO_ELLIPSIZE_START;
    case ekELLIPMIDDLE:
        return PANGO_ELLIPSIZE_MIDDLE;
    case ekELLIPEND:
        return PANGO_ELLIPSIZE_END;
        cassert_default();
    }

    return PANGO_ELLIPSIZE_NONE;
}

/*---------------------------------------------------------------------------*/

void draw_text_trim(DCtx *ctx, const ellipsis_t ellipsis)
{
    cassert_no_null(ctx);
    ctx->ellipsis = i_ellipsis(ellipsis);
}

/*---------------------------------------------------------------------------*/

void draw_text_align(DCtx *ctx, const align_t halign, const align_t valign)
{
    cassert_no_null(ctx);
    ctx->text_halign = halign;
    ctx->text_valign = valign;
}

/*---------------------------------------------------------------------------*/

static __INLINE PangoAlignment i_align(const align_t align)
{
    switch (align)
    {
    case ekLEFT:
    case ekJUSTIFY:
        return PANGO_ALIGN_LEFT;
    case ekCENTER:
        return PANGO_ALIGN_CENTER;
    case ekRIGHT:
        return PANGO_ALIGN_RIGHT;
        cassert_default();
    }

    return PANGO_ALIGN_LEFT;
}

/*---------------------------------------------------------------------------*/

void draw_text_halign(DCtx *ctx, const align_t halign)
{
    cassert_no_null(ctx);
    ctx->text_intalign = i_align(halign);
}

/*---------------------------------------------------------------------------*/

void draw_text_extents(DCtx *ctx, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    int w, h;
    cassert_no_null(ctx);
    if (ctx->layout == NULL)
    {
        const PangoFontDescription *fdesc = NULL;
        cassert(ctx->font != NULL);
        fdesc = (PangoFontDescription *)font_native(ctx->font);
        ctx->layout = pango_cairo_create_layout(ctx->cairo);
        pango_layout_set_font_description(ctx->layout, fdesc);
    }

    pango_layout_set_text(ctx->layout, (const char *)text, -1);
    pango_layout_set_width(ctx->layout, refwidth < 0 ? -1 : (int)(refwidth * PANGO_SCALE));
    pango_layout_get_pixel_size(ctx->layout, &w, &h);
    ptr_assign(width, (real32_t)w);
    ptr_assign(height, (real32_t)h);
}

/*---------------------------------------------------------------------------*/

void draw_image_align(DCtx *ctx, const align_t halign, const align_t valign)
{
    cassert_no_null(ctx);
    ctx->image_halign = halign;
    ctx->image_valign = valign;
}

/*---------------------------------------------------------------------------*/

void draw_set_raster_mode(DCtx *ctx)
{
    i_set_raster_mode(ctx);
}

/*---------------------------------------------------------------------------*/

void draw_text_raster(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y)
{
    if (ctx->raster_mode == FALSE)
        i_set_raster_mode(ctx);

    i_begin_text(ctx, text, x, y);
    i_color(ctx->cairo, ctx->text_color, &ctx->source_color);
    pango_cairo_show_layout(ctx->cairo, ctx->layout);
}

/*---------------------------------------------------------------------------*/

void draw_image_raster(DCtx *ctx, const Image *image, const real32_t x, const real32_t y)
{
    unref(ctx);
    unref(image);
    unref(x);
    unref(y);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void draw_line_imp(DCtx *ctx, const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1, const bool_t raster)
{
    cassert_no_null(ctx);
    if (raster != ctx->raster_mode)
    {
        if (raster == TRUE)
            i_set_raster_mode(ctx);
        else
            i_set_real2d_mode(ctx);
    }

    cairo_move_to(ctx->cairo, (double)x0, (double)y0);
    cairo_line_to(ctx->cairo, (double)x1, (double)y1);
    i_line_pattern(ctx);
    cairo_stroke(ctx->cairo);
}

/*---------------------------------------------------------------------------*/

void draw_rect_imp(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t width, const real32_t height, const bool_t raster)
{
    unref(ctx);
    unref(op);
    unref(x);
    unref(y);
    unref(width);
    unref(height);
    unref(raster);
    cassert(FALSE);
}
