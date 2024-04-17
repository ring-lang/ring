/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw_osx.m
 *
 */

/* Operating System native drawings */

#include "draw2d_osx.ixx"

#include "draw.h"
#include "dctxh.h"
#include "draw.inl"
#include "draw2d.inl"
#include "color.h"
#include "font.h"
#include "image.inl"
#include <sewer/bmath.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

NSNumber *kUNDERLINE_NONE = nil;
NSNumber *kUNDERLINE_SINGLE = nil;

/*---------------------------------------------------------------------------*/

void draw_alloc_globals(void)
{
    kUNDERLINE_NONE = [[NSNumber alloc] initWithInt:NSUnderlineStyleNone];
    kUNDERLINE_SINGLE = [[NSNumber alloc] initWithInt:NSUnderlineStyleSingle];
}

/*---------------------------------------------------------------------------*/

void draw_dealloc_globals(void)
{
    [kUNDERLINE_NONE release];
    [kUNDERLINE_SINGLE release];
}

/*---------------------------------------------------------------------------*/

void draw_word_extents(MeasureStr *data, const char_t *word, real32_t *width, real32_t *height)
{
    NSString *str = nil;
    NSSize word_size;
    cassert_no_null(data);
    cassert_no_null(width);
    cassert_no_null(height);
    str = [NSString stringWithUTF8String:word];
    word_size = [str sizeWithAttributes:data->dict];
    *width = (real32_t)word_size.width;
    *height = (real32_t)word_size.height;
}

/*---------------------------------------------------------------------------*/

static void i_set_raster_mode(DCtx *ctx)
{
    CGAffineTransform curtrans;
    cassert_no_null(ctx);
    cassert(ctx->raster_mode == FALSE);
    /* Invalidate previous transform. Equivalent to hypothetical SetIdentity() */
    curtrans = CGContextGetCTM(ctx->context);
    curtrans = CGAffineTransformInvert(curtrans);
    CGContextConcatCTM(ctx->context, curtrans);
    /* Apply context origin */
    CGContextConcatCTM(ctx->context, ctx->origin);
    ctx->raster_mode = TRUE;
}

/*---------------------------------------------------------------------------*/

static void i_set_real2d_mode(DCtx *ctx)
{
    CGAffineTransform curtrans;
    cassert_no_null(ctx);
    cassert(ctx->raster_mode == TRUE);
    /* Invalidate previous transform. Equivalent to hypothetical SetIdentity() */
    curtrans = CGContextGetCTM(ctx->context);
    curtrans = CGAffineTransformInvert(curtrans);
    CGContextConcatCTM(ctx->context, curtrans);
    /* Apply context origin */
    CGContextConcatCTM(ctx->context, ctx->origin);
    /* Apply transform */
    CGContextConcatCTM(ctx->context, ctx->transform);
    ctx->raster_mode = FALSE;
}

/*---------------------------------------------------------------------------*/

void draw_imgimp(DCtx *ctx, const OSImage *image, const uint32_t frame_index, const real32_t x, const real32_t y, const bool_t raster)
{
    cassert_no_null(ctx);
    cassert_no_null(image);

    if (raster != ctx->raster_mode)
    {
        if (raster == TRUE)
            i_set_raster_mode(ctx);
        else
            i_set_real2d_mode(ctx);
    }

    if (frame_index != UINT32_MAX)
    {
        NSBitmapImageRep *image_rep = nil;
        cassert([[(NSImage *)image representations] count] == 1);
        image_rep = (NSBitmapImageRep *)[[(NSImage *)image representations] objectAtIndex:0];
        cassert_no_null(image_rep);
        [image_rep setProperty:NSImageCurrentFrame withValue:[NSNumber numberWithUnsignedInt:frame_index]];
    }

    {
        NSRect rect;
        /*BOOL isFlipped = ctx->nsview != nil ? [ctx->nsview isFlipped] : YES;*/
        rect.origin = NSMakePoint((CGFloat)x, (CGFloat)y);
        rect.size = [(NSImage *)image size];
        switch (ctx->image_halign)
        {
        case ekLEFT:
        case ekJUSTIFY:
            break;
        case ekCENTER:
            rect.origin.x -= rect.size.width / 2;
            break;
        case ekRIGHT:
            rect.origin.x -= rect.size.width;
            break;
        }

        switch (ctx->image_valign)
        {
        case ekTOP:
        case ekJUSTIFY:
            break;
        case ekCENTER:
            rect.origin.y -= rect.size.height / 2;
            break;
        case ekRIGHT:
            rect.origin.y -= rect.size.height;
            break;
        }

        {
#if defined(MAC_OS_X_VERSION_10_6) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6
#if defined(MAC_OS_X_VERSION_10_12) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
            NSCompositingOperation op = NSCompositingOperationSourceOver;
#else
            NSCompositingOperation op = NSCompositeSourceOver;
#endif
            [(NSImage *)image drawInRect:rect
                                fromRect:NSZeroRect
                               operation:op
                                fraction:1.0f
                          respectFlipped:ctx->is_flipped
                                   hints:nil];
#else
#error Usar NSImage IsFlipped = TRUE y despues restaurar isFlipped = false;
#endif
        }
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_draw_linear(DCtx *ctx)
{
    CGAffineTransform transform;
    CGContextSaveGState(ctx->context);
    CGContextClip(ctx->context);
    /* Invalidate previous transform. Equivalent to hypothetical SetIdentity() */
    transform = CGContextGetCTM(ctx->context);
    transform = CGAffineTransformInvert(transform);
    CGContextConcatCTM(ctx->context, transform);
    /* Apply the gradient transform */
    CGContextConcatCTM(ctx->context, ctx->origin);
    CGContextConcatCTM(ctx->context, ctx->gradient_matrix);
    CGContextDrawLinearGradient(ctx->context, ctx->gradient, CGPointMake(ctx->gradient_rx0, ctx->gradient_ry0), CGPointMake(ctx->gradient_rx1, ctx->gradient_ry1), (CGGradientDrawingOptions)(kCGGradientDrawsBeforeStartLocation | kCGGradientDrawsAfterEndLocation));
    CGContextRestoreGState(ctx->context);
}

/*---------------------------------------------------------------------------*/

static CGPathRef i_solid_path(DCtx *ctx)
{
    CGPathRef path = CGContextCopyPath(ctx->context);

#if defined(MAC_OS_X_VERSION_10_7) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_7
    CGPathRef spath = NULL;
    if (ctx->dash_count > 0)
    {
        CGFloat p[16];
        uint32_t i;
        CGPathRef dpath = NULL;

        for (i = 0; i < ctx->dash_count; ++i)
            p[i] = ctx->line_dash[i] * ctx->line_width;

        dpath = CGPathCreateCopyByDashingPath(path, NULL, 0, p, ctx->dash_count);
        spath = CGPathCreateCopyByStrokingPath(dpath, NULL, ctx->line_width, ctx->linecap, ctx->linejoin, 100);
        CGPathRelease(dpath);
    }
    else
    {
        spath = CGPathCreateCopyByStrokingPath(path, NULL, ctx->line_width, ctx->linecap, ctx->linejoin, 100);
    }

    CGPathRelease(path);
    return spath;
#else
    return path;
#endif
}

/*---------------------------------------------------------------------------*/

static void i_color(const color_t c, CGFloat *r, CGFloat *g, CGFloat *b, CGFloat *a)
{
    real32_t r1, g1, b1, a1;
    color_get_rgbaf(c, &r1, &g1, &b1, &a1);
    *r = (CGFloat)r1;
    *g = (CGFloat)g1;
    *b = (CGFloat)b1;
    *a = (CGFloat)a1;
}

/*---------------------------------------------------------------------------*/

static void i_stroke_path(DCtx *ctx)
{
    cassert_no_null(ctx);
    if (ctx->line_fill == TRUE)
    {
        switch (ctx->fillmode)
        {
        case ekFILL_SOLID:
        {
            CGFloat r, g, b, a;
            i_color(ctx->fillcolor, &r, &g, &b, &a);
            CGContextSaveGState(ctx->context);
            CGContextSetRGBStrokeColor(ctx->context, r, g, b, a);
            CGContextStrokePath(ctx->context);
            CGContextRestoreGState(ctx->context);
            break;
        }

        case ekFILL_LINEAR:
        {
            /* https://stackoverflow.com/questions/15159486/clear-the-current-path-in-cgcontextref */
            CGPathRef path = i_solid_path(ctx);
            CGContextBeginPath(ctx->context);
            CGContextAddPath(ctx->context, path);
            i_draw_linear(ctx);
            CGPathRelease(path);
            break;
        }

            cassert_default();
        }
    }
    else
    {
        CGFloat r, g, b, a;
        i_color(ctx->skcolor, &r, &g, &b, &a);
        CGContextSetRGBStrokeColor(ctx->context, r, g, b, a);
        CGContextStrokePath(ctx->context);
    }
}

/*---------------------------------------------------------------------------*/

void draw_line(DCtx *ctx, const real32_t x0, const real32_t y00, const real32_t x1, const real32_t y11)
{
    draw_line_imp(ctx, x0, y00, x1, y11, FALSE);
}

/*---------------------------------------------------------------------------*/

static void i_line_path(CGContextRef context, const V2Df *points, const uint32_t n, bool_t closed)
{
    register uint32_t i;
    const V2Df *lpoints;
    cassert_no_null(context);
    cassert_no_null(points);
    cassert(n > 0);

    lpoints = points;
    CGContextMoveToPoint(context, (CGFloat)lpoints->x, (CGFloat)lpoints->y);
    lpoints += 1;

    for (i = 1; i < n; ++i, ++lpoints)
        CGContextAddLineToPoint(context, (CGFloat)lpoints->x, (CGFloat)lpoints->y);

    if (closed)
        CGContextClosePath(context);
}

/*---------------------------------------------------------------------------*/

void draw_polyline(DCtx *ctx, bool_t closed, const V2Df *points, const uint32_t n)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    i_line_path(ctx->context, points, n, closed);
    i_stroke_path(ctx);
}

/*---------------------------------------------------------------------------*/

void draw_arc(DCtx *ctx, const real32_t x, const real32_t y, const real32_t radius, const real32_t start, const real32_t sweep)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    CGContextAddArc(ctx->context, (CGFloat)x, (CGFloat)y, (CGFloat)radius, (CGFloat)start, (CGFloat)(start + sweep), sweep < 0 ? 1 : 0);
    i_stroke_path(ctx);
}

/*---------------------------------------------------------------------------*/

void draw_bezier(DCtx *ctx, const real32_t x0, const real32_t y00, const real32_t x1, const real32_t y11, const real32_t x2, const real32_t y2, const real32_t x3, const real32_t y3)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    CGContextMoveToPoint(ctx->context, (CGFloat)x0, (CGFloat)y00);
    CGContextAddCurveToPoint(ctx->context, (CGFloat)x1, (CGFloat)y11, (CGFloat)x2, (CGFloat)y2, (CGFloat)x3, (CGFloat)y3);
    i_stroke_path(ctx);
}

/*---------------------------------------------------------------------------*/

void draw_line_color(DCtx *ctx, const color_t color)
{
    cassert_no_null(ctx);
    ctx->skcolor = color;
    ctx->line_fill = FALSE;
}

/*---------------------------------------------------------------------------*/

void draw_line_fill(DCtx *ctx)
{
    cassert_no_null(ctx);
    ctx->line_fill = TRUE;
}

/*---------------------------------------------------------------------------*/

void draw_line_width(DCtx *ctx, const real32_t width)
{
    cassert_no_null(ctx);
    ctx->line_width = (CGFloat)width;
    CGContextSetLineWidth(ctx->context, (CGFloat)width);

    if (ctx->dash_count > 0)
    {
        CGFloat p[16];
        register uint32_t i, n = ctx->dash_count;
        for (i = 0; i < n; ++i)
            p[i] = ctx->line_dash[i] * ctx->line_width;
        CGContextSetLineDash(ctx->context, 0.f, p, ctx->dash_count);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE CGLineCap i_linecap(const linecap_t linecap)
{
    switch (linecap)
    {
    case ekLCFLAT:
        return kCGLineCapButt;
    case ekLCSQUARE:
        return kCGLineCapSquare;
    case ekLCROUND:
        return kCGLineCapRound;
        cassert_default();
    }
    return kCGLineCapButt;
}

/*---------------------------------------------------------------------------*/

void draw_line_cap(DCtx *ctx, const linecap_t cap)
{
    cassert_no_null(ctx);
    ctx->linecap = i_linecap(cap);
    CGContextSetLineCap(ctx->context, ctx->linecap);
}

/*---------------------------------------------------------------------------*/

static __INLINE CGLineJoin i_linejoin(const linejoin_t join)
{
    switch (join)
    {
    case ekLJMITER:
        return kCGLineJoinMiter;
    case ekLJROUND:
        return kCGLineJoinRound;
    case ekLJBEVEL:
        return kCGLineJoinBevel;
        cassert_default();
    }
    return kCGLineJoinMiter;
}

/*---------------------------------------------------------------------------*/

void draw_line_join(DCtx *ctx, const linejoin_t join)
{
    cassert_no_null(ctx);
    ctx->linejoin = i_linejoin(join);
    CGContextSetLineJoin(ctx->context, ctx->linejoin);
}

/*---------------------------------------------------------------------------*/

void draw_line_dash(DCtx *ctx, const real32_t *pattern, const uint32_t n)
{
    if (pattern != NULL && n > 0)
    {
        CGFloat p[16];
        uint32_t i, pn = n < 16 ? n : 16;

        for (i = 0; i < pn; ++i)
        {
            ctx->line_dash[i] = (CGFloat)pattern[i];
            p[i] = (CGFloat)pattern[i] * ctx->line_width;
        }

        ctx->dash_count = pn;
        CGContextSetLineDash(ctx->context, 0.f, p, pn);
    }
    else
    {
        ctx->dash_count = 0;
        CGContextSetLineDash(ctx->context, 0.f, NULL, 0);
    }
}

/*---------------------------------------------------------------------------*/

static void i_fill_color(DCtx *ctx)
{
    CGFloat r, g, b, a;
    i_color(ctx->fillcolor, &r, &g, &b, &a);
    CGContextSetRGBFillColor(ctx->context, r, g, b, a);
}

/*---------------------------------------------------------------------------*/

static void i_draw(DCtx *ctx, const drawop_t op)
{
    switch (op)
    {
    case ekSTROKE:
        i_stroke_path(ctx);
        break;

    case ekFILL:
        switch (ctx->fillmode)
        {
        case ekFILL_SOLID:
            i_fill_color(ctx);
            CGContextDrawPath(ctx->context, kCGPathFill);
            break;
        case ekFILL_LINEAR:
            i_draw_linear(ctx);
            break;
            cassert_default();
        }
        break;

    case ekFILLSK:
    {
        CGPathRef path = CGContextCopyPath(ctx->context);
        switch (ctx->fillmode)
        {
        case ekFILL_SOLID:
            i_fill_color(ctx);
            CGContextDrawPath(ctx->context, kCGPathFill);
            CGContextAddPath(ctx->context, path);
            i_stroke_path(ctx);
            break;
        case ekFILL_LINEAR:
            i_draw_linear(ctx);
            CGContextAddPath(ctx->context, path);
            i_stroke_path(ctx);
            break;

            cassert_default();
        }

        CGPathRelease(path);
        break;
    }

    case ekSKFILL:
    {
        CGPathRef path = CGContextCopyPath(ctx->context);
        i_stroke_path(ctx);
        CGContextAddPath(ctx->context, path);

        switch (ctx->fillmode)
        {
        case ekFILL_SOLID:
            i_fill_color(ctx);
            CGContextDrawPath(ctx->context, kCGPathFill);
            break;
        case ekFILL_LINEAR:
            i_draw_linear(ctx);
            break;
            cassert_default();
        }

        CGPathRelease(path);
        break;
    }

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void draw_rect(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    draw_rect_imp(ctx, op, x, y, width, height, FALSE);
}

/*---------------------------------------------------------------------------*/

void draw_rndrect(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t width, const real32_t height, const real32_t radius)
{
    /*       minx    midx    maxx
     * miny    2       3       4
     * midy    1               5
     * maxy    8       7       6
    */
    CGFloat minx = (CGFloat)x;
    CGFloat miny = (CGFloat)y;
    CGFloat w = (CGFloat)width;
    CGFloat h = (CGFloat)height;
    CGFloat r = (CGFloat)radius;
    CGFloat maxx = minx + w;
    CGFloat maxy = miny + h;
    CGFloat midx = .5f * (minx + maxx);
    CGFloat midy = .5f * (miny + maxy);
    register CGContextRef context;
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    context = ctx->context;
    CGContextBeginPath(context);
    CGContextMoveToPoint(context, minx, midy);
    CGContextAddArcToPoint(context, minx, miny, midx, miny, r);
    CGContextAddArcToPoint(context, maxx, miny, maxx, midy, r);
    CGContextAddArcToPoint(context, maxx, maxy, midx, maxy, r);
    CGContextAddArcToPoint(context, minx, maxy, minx, midy, r);
    CGContextClosePath(context);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_circle(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t radius)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    CGContextBeginPath(ctx->context);
    CGContextAddArc(ctx->context, (CGFloat)x, (CGFloat)y, (CGFloat)radius, 0, (CGFloat)6.28318530718, false);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_ellipse(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t radx, const real32_t rady)
{
    CGRect rect;
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    rect.origin.x = (CGFloat)(x - radx);
    rect.origin.y = (CGFloat)(y - rady);
    rect.size.width = (CGFloat)(radx + radx);
    rect.size.height = (CGFloat)(rady + rady);
    CGContextBeginPath(ctx->context);
    CGContextAddEllipseInRect(ctx->context, rect);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_polygon(DCtx *ctx, const drawop_t op, const V2Df *points, const uint32_t n)
{
    cassert_no_null(ctx);
    if (ctx->raster_mode == TRUE)
        i_set_real2d_mode(ctx);

    i_line_path(ctx->context, points, n, TRUE);
    i_draw(ctx, op);
}

/*---------------------------------------------------------------------------*/

void draw_fill_color(DCtx *ctx, const color_t color)
{
    cassert_no_null(ctx);
    ctx->fillmode = ekFILL_SOLID;
    ctx->fillcolor = color;
}

/*---------------------------------------------------------------------------*/

static void i_gradient(DCtx *ctx)
{
    CGFloat locations[MAX_RANGE];
    CGFloat colors[4 * MAX_RANGE];
    CGColorSpaceRef cspace = CGColorSpaceCreateDeviceRGB();
    register uint32_t j, nl = ctx->wrap == ekFCLAMP ? 1 : MAX_RANGE / MAX_COLORS;
    register uint32_t i, total = ctx->gradient_n;
    bool_t invert = FALSE;
    register uint32_t ci = 0, li = 0;
    cassert(nl % 2 == 1);

    if (ctx->wrap == ekFFLIP)
        invert = (((nl - 1) / 2) % 2) == 1 ? TRUE : FALSE;

    for (j = 0; j < nl; ++j)
    {
        if (invert == TRUE)
        {
            register uint32_t ii;
            for (i = 0; i < total; ++i)
            {
                CGFloat *c = &colors[ci];
                ii = total - i - 1;
                i_color(ctx->gradient_colors[ii], c, c + 1, c + 2, c + 3);
                locations[li++] = (CGFloat)(((1.f - ctx->gradient_stops[ii]) / nl) + ((real32_t)j / (real32_t)nl));
                ci += 4;
            }
        }
        else
        {
            for (i = 0; i < total; ++i)
            {
                CGFloat *c = &colors[ci];
                i_color(ctx->gradient_colors[i], c, c + 1, c + 2, c + 3);
                locations[li++] = (CGFloat)((ctx->gradient_stops[i] / nl) + ((real32_t)j / (real32_t)nl));
                ci += 4;
            }
        }

        if (ctx->wrap == ekFFLIP)
            invert = !invert;
    }

    ctx->gradient = CGGradientCreateWithColorComponents(cspace, colors, locations, total * nl);
    CGColorSpaceRelease(cspace);
}

/*---------------------------------------------------------------------------*/

static void i_gradient_vector(DCtx *ctx)
{
    switch (ctx->wrap)
    {
    case ekFCLAMP:
        ctx->gradient_rx0 = (CGFloat)ctx->gradient_x0;
        ctx->gradient_ry0 = (CGFloat)ctx->gradient_y0;
        ctx->gradient_rx1 = (CGFloat)ctx->gradient_x1;
        ctx->gradient_ry1 = (CGFloat)ctx->gradient_y1;
        break;

    case ekFTILE:
    case ekFFLIP:
    {
        real32_t vx = ctx->gradient_x1 - ctx->gradient_x0;
        real32_t vy = ctx->gradient_y1 - ctx->gradient_y0;
        real32_t scale = ((MAX_RANGE / MAX_COLORS) - 1) / 2;
        ctx->gradient_rx0 = (CGFloat)(ctx->gradient_x0 - scale * vx);
        ctx->gradient_ry0 = (CGFloat)(ctx->gradient_y0 - scale * vy);
        ctx->gradient_rx1 = (CGFloat)(ctx->gradient_x1 + scale * vx);
        ctx->gradient_ry1 = (CGFloat)(ctx->gradient_y1 + scale * vy);
        break;
    }

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static color_t i_effective_color(const color_t color)
{
    uint8_t r, g, b, a;
    color_get_rgba(color, &r, &g, &b, &a);
    return color_rgba(r, g, b, a);
}

/*---------------------------------------------------------------------------*/

void draw_fill_linear(DCtx *ctx, const color_t *color, const real32_t *stop, const uint32_t n, const real32_t x0, const real32_t yy0, const real32_t x1, const real32_t yy1)
{
    cassert_no_null(ctx);
    cassert_no_null(color);
    cassert_no_null(stop);

    if (ctx->gradient != NULL)
    {
        if (ctx->gradient_n != n)
        {
            CGGradientRelease(ctx->gradient);
            ctx->gradient = NULL;
        }
        else
        {
            register uint32_t i;
            for (i = 0; i < n; ++i)
            {
                if (ctx->gradient_colors[i] != i_effective_color(color[i]))
                {
                    CGGradientRelease(ctx->gradient);
                    ctx->gradient = NULL;
                    break;
                }

                if (ctx->gradient_stops[i] != stop[i])
                {
                    CGGradientRelease(ctx->gradient);
                    ctx->gradient = NULL;
                    break;
                }
            }
        }
    }

    if (ctx->gradient == NULL)
    {
        register uint32_t i, total = n < MAX_COLORS ? n : MAX_COLORS;
        for (i = 0; i < total; ++i)
        {
            ctx->gradient_colors[i] = i_effective_color(color[i]);
            ctx->gradient_stops[i] = stop[i];
        }

        ctx->gradient_n = total;
        i_gradient(ctx);
    }

    ctx->gradient_x0 = x0;
    ctx->gradient_y0 = yy0;
    ctx->gradient_x1 = x1;
    ctx->gradient_y1 = yy1;
    i_gradient_vector(ctx);

    ctx->fillmode = ekFILL_LINEAR;
}

/*---------------------------------------------------------------------------*/

void draw_fill_matrix(DCtx *ctx, const T2Df *t2d)
{
    cassert_no_null(ctx);
    cassert_no_null(t2d);
    ctx->gradient_matrix.a = (CGFloat)t2d->i.x;
    ctx->gradient_matrix.b = (CGFloat)t2d->i.y;
    ctx->gradient_matrix.c = (CGFloat)t2d->j.x;
    ctx->gradient_matrix.d = (CGFloat)t2d->j.y;
    ctx->gradient_matrix.tx = (CGFloat)t2d->p.x;
    ctx->gradient_matrix.ty = (CGFloat)t2d->p.y;
}

/*---------------------------------------------------------------------------*/

void draw_fill_wrap(DCtx *ctx, const fillwrap_t wrap)
{
    cassert_no_null(ctx);
    if (wrap != ctx->wrap)
    {
        if (ctx->gradient != NULL)
        {
            CGGradientRelease(ctx->gradient);
            ctx->gradient = NULL;
        }

        ctx->wrap = wrap;
        i_gradient(ctx);
        i_gradient_vector(ctx);
    }
}

/*---------------------------------------------------------------------------*/

void draw_font(DCtx *ctx, const Font *font)
{
    uint32_t fstyle;
    cassert_no_null(ctx);
    fstyle = font_style(font);
    [ctx->text_dict setObject:(fstyle & ekFUNDERLINE) ? kUNDERLINE_SINGLE : kUNDERLINE_NONE forKey:NSUnderlineStyleAttributeName];
    [ctx->text_dict setObject:(fstyle & ekFSTRIKEOUT) ? kUNDERLINE_SINGLE : kUNDERLINE_NONE forKey:NSStrikethroughStyleAttributeName];
    [ctx->text_dict setObject:(NSFont *)font_native(font) forKey:NSFontAttributeName];
}

/*---------------------------------------------------------------------------*/

static NSColor *i_NSColor(color_t color)
{
    real32_t r, g, b, a;
    color_get_rgbaf(color, &r, &g, &b, &a);
    return [NSColor colorWithCalibratedRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a];
}

/*---------------------------------------------------------------------------*/

void draw_text_color(DCtx *ctx, const color_t color)
{
    cassert_no_null(ctx);
    ctx->text_color = color;
    [ctx->text_dict setObject:i_NSColor(color) forKey:NSForegroundColorAttributeName];
}

/*---------------------------------------------------------------------------*/

static NSString *i_begin_text(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y, const bool_t raster, const bool_t single_line, NSRect *rect)
{
    NSString *str = nil;
    real32_t width, height;

    cassert_no_null(ctx);
    cassert_no_null(rect);

    if (raster != ctx->raster_mode)
    {
        if (raster == TRUE)
            i_set_raster_mode(ctx);
        else
            i_set_real2d_mode(ctx);
    }

    rect->origin.x = (CGFloat)x;
    rect->origin.y = (CGFloat)y;
    str = [NSString stringWithUTF8String:(const char *)text];

    if (single_line == TRUE)
    {
        MeasureStr data;
        data.dict = ctx->text_dict;
        draw_word_extents(&data, text, &width, &height);

        if (ctx->text_width > 0)
            width = ctx->text_width;
    }
    else
    {
        draw_text_extents(ctx, text, ctx->text_width, &width, &height);

        if (ctx->text_width > 0 && width > ctx->text_width)
            width = ctx->text_width;
    }

    rect->size.width = (CGFloat)width;
    rect->size.height = (CGFloat)height;

    switch (ctx->text_halign)
    {
    case ekLEFT:
    case ekJUSTIFY:
        break;
    case ekRIGHT:
        rect->origin.x -= (CGFloat)width;
        break;
    case ekCENTER:
        rect->origin.x -= (CGFloat)round(.5 * width);
        break;
        cassert_default();
    }

    switch (ctx->text_valign)
    {
    case ekTOP:
    case ekJUSTIFY:
        break;
    case ekBOTTOM:
        rect->origin.y -= (CGFloat)height;
        break;
    case ekCENTER:
        rect->origin.y -= (CGFloat)round(.5 * height);
        break;
        cassert_default();
    }

    return str;
}

/*---------------------------------------------------------------------------*/

void draw_text(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y)
{
    NSRect rect;
    NSString *str = i_begin_text(ctx, text, x, y, FALSE, FALSE, &rect);
    [str drawInRect:rect withAttributes:ctx->text_dict];
}

/*---------------------------------------------------------------------------*/

void draw_text_single_line(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y)
{
    NSRect rect;
    NSString *str = i_begin_text(ctx, text, x, y, FALSE, TRUE, &rect);
    [str drawInRect:rect withAttributes:ctx->text_dict];
}

/*---------------------------------------------------------------------------*/
/* https://github.com/aderussell/string-to-CGPathRef/blob/master/ARCGPathFromString/ARCGPathFromString.m */
static CGPathRef i_CGPathCreateSingleLineStringWithAttributedString(NSAttributedString *attrString, CGFloat nx, CGFloat ny, CGFloat fheight)
{
    CGMutablePathRef letters = CGPathCreateMutable();
    CTLineRef line = CTLineCreateWithAttributedString((CFAttributedStringRef)attrString);
    CFArrayRef runArray = CTLineGetGlyphRuns(line);
    CFIndex runTotal = CFArrayGetCount(runArray);
    CFIndex runIndex = 0;

    /* for each RUN */
    for (runIndex = 0; runIndex < runTotal; runIndex++)
    {
        /* Get FONT for this run */
        CTRunRef run = (CTRunRef)CFArrayGetValueAtIndex(runArray, runIndex);
        CTFontRef runFont = CFDictionaryGetValue(CTRunGetAttributes(run), kCTFontAttributeName);
        CFIndex glyphTotal = CTRunGetGlyphCount(run);
        CFIndex runGlyphIndex = 0;

        /* for each GLYPH in run */
        for (runGlyphIndex = 0; runGlyphIndex < glyphTotal; runGlyphIndex++)
        {
            /* Get Glyph & Glyph-data */
            CFRange thisGlyphRange = CFRangeMake(runGlyphIndex, 1);
            CGGlyph glyph;
            CGPoint position;
            CTRunGetGlyphs(run, thisGlyphRange, &glyph);
            CTRunGetPositions(run, thisGlyphRange, &position);

            /* Get PATH of outline */
            {
                CGAffineTransform af = CGAffineTransformMakeScale(1, -1);
                CGPathRef letter = CTFontCreatePathForGlyph(runFont, glyph, &af);
                /* CGRect r = CGPathGetBoundingBox(letter); */
                CGAffineTransform t = CGAffineTransformMakeTranslation(position.x + nx, position.y + ny + fheight);
                CGPathAddPath(letters, &t, letter);
                CGPathRelease(letter);
            }
        }
    }

    CFRelease(line);
    return letters;
}

/*---------------------------------------------------------------------------*/

void draw_text_path(DCtx *ctx, const drawop_t op, const char_t *text, const real32_t x, const real32_t y)
{
    NSRect rect;
    NSString *str = i_begin_text(ctx, text, x, y, FALSE, FALSE, &rect);

    if (op == ekFILL && ctx->fillmode == ekFILL_SOLID)
    {
        NSColor *textcolor = [ctx->text_dict objectForKey:NSForegroundColorAttributeName];
        [ctx->text_dict setObject:i_NSColor(ctx->fillcolor) forKey:NSForegroundColorAttributeName];

        if (ctx->text_width <= 0)
            [str drawAtPoint:rect.origin withAttributes:ctx->text_dict];
        else
            [str drawInRect:rect withAttributes:ctx->text_dict];

        [ctx->text_dict setObject:textcolor forKey:NSForegroundColorAttributeName];
        [textcolor release];
    }
    else
    {
        NSAttributedString *astr = [[NSAttributedString alloc] initWithString:str attributes:ctx->text_dict];
        NSFont *font = [ctx->text_dict objectForKey:NSFontAttributeName];
        /*        CGFloat h1 = [font xHeight]; */
        /*        CGFloat h2 = [font boundingRectForFont].size.height; */
        CGFloat h3 = [font ascender] + [font descender];
        CGPathRef path = i_CGPathCreateSingleLineStringWithAttributedString(astr, rect.origin.x, rect.origin.y, h3);
        /* Artistic text only one line */
        cassert(ctx->text_width <= 0);
        CGContextAddPath(ctx->context, path);
        i_draw(ctx, op);
        CGPathRelease(path);
        [astr release];
    }
}

/*---------------------------------------------------------------------------*/

void draw_text_width(DCtx *ctx, const real32_t width)
{
    cassert_no_null(ctx);
    ctx->text_width = width;
}

/*---------------------------------------------------------------------------*/

void draw_text_trim(DCtx *ctx, const ellipsis_t ellipsis)
{
    NSLineBreakMode mode = NSLineBreakByWordWrapping;
    cassert_no_null(ctx);

    if (ellipsis != ENUM_MAX(ellipsis_t))
    {
        switch (ellipsis)
        {
        case ekELLIPNONE:
            mode = NSLineBreakByClipping;
            break;
        case ekELLIPBEGIN:
            mode = NSLineBreakByTruncatingHead;
            break;
        case ekELLIPMIDDLE:
            mode = NSLineBreakByTruncatingMiddle;
            break;
        case ekELLIPEND:
            mode = NSLineBreakByTruncatingTail;
            break;
        case ekELLIPMLINE:
            mode = NSLineBreakByWordWrapping;
            break;
            cassert_default();
        }
    }

    [ctx->text_parag setLineBreakMode:mode];
}

/*---------------------------------------------------------------------------*/

void draw_text_align(DCtx *ctx, const align_t halign, const align_t valign)
{
    cassert_no_null(ctx);
    ctx->text_halign = halign;
    ctx->text_valign = valign;
}

/*---------------------------------------------------------------------------*/

static NSTextAlignment i_text_alignment(const align_t halign)
{
#if defined(MAC_OS_X_VERSION_10_12) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
    switch (halign)
    {
    case ekLEFT:
        return NSTextAlignmentLeft;
    case ekCENTER:
        return NSTextAlignmentCenter;
    case ekJUSTIFY:
        return NSTextAlignmentJustified;
    case ekRIGHT:
        return NSTextAlignmentRight;
        cassert_default();
    }
    return NSTextAlignmentLeft;

#else
    switch (halign)
    {
    case ekLEFT:
        return NSLeftTextAlignment;
    case ekCENTER:
        return NSCenterTextAlignment;
    case ekJUSTIFY:
        return NSJustifiedTextAlignment;
    case ekRIGHT:
        return NSRightTextAlignment;
        cassert_default();
    }

    return NSLeftTextAlignment;
#endif
}

/*---------------------------------------------------------------------------*/

void draw_text_halign(DCtx *ctx, const align_t halign)
{
    cassert_no_null(ctx);
    cassert_no_null(ctx->text_parag);
    {
        /* Crash in macOS Mountain Lion and lowers if we reuse the same paragraph */
        NSLineBreakMode lb = [ctx->text_parag lineBreakMode];
        [ctx->text_parag release];
        ctx->text_parag = [[[NSParagraphStyle defaultParagraphStyle] mutableCopy] retain];
        [ctx->text_parag setLineBreakMode:lb];
        [ctx->text_parag setAlignment:i_text_alignment(halign)];
        [ctx->text_dict setObject:ctx->text_parag forKey:NSParagraphStyleAttributeName];
    }

    /*
     TODO Check in lower versions and use this faster alternative
#if defined (MAC_OS_X_VERSION_10_9) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_9
	{
        [ctx->text_parag setAlignment:i_text_alignment(halign)];
	}
#else
#endif
    */
}

/*---------------------------------------------------------------------------*/

static bool_t i_with_newline(const char_t *text)
{
    cassert_no_null(text);
    while (*text != 0)
    {
        if (*text == '\n')
            return TRUE;
        text += 1;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

void draw_text_extents(DCtx *ctx, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    MeasureStr data;
    cassert_no_null(ctx);
    cassert_no_null(width);
    cassert_no_null(height);
    data.dict = ctx->text_dict;
    if (refwidth > 0 || i_with_newline(text) == TRUE)
    {
        draw2d_extents(&data, draw_word_extents, TRUE, text, refwidth, width, height, MeasureStr);
    }
    else
    {
        draw_word_extents(&data, text, width, height);
        *width = bmath_ceilf(*width);
        *height = bmath_ceilf(*height);
    }
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
    cassert_no_null(ctx);
    if (ctx->raster_mode == FALSE)
        i_set_raster_mode(ctx);
}

/*---------------------------------------------------------------------------*/

void draw_text_raster(DCtx *ctx, const char_t *text, const real32_t x, const real32_t y)
{
    NSRect rect;
    NSString *str = i_begin_text(ctx, text, x, y, TRUE, TRUE, &rect);
    [str drawInRect:rect withAttributes:ctx->text_dict];
}

/*---------------------------------------------------------------------------*/

void draw_image_raster(DCtx *ctx, const Image *image, const real32_t x, const real32_t y)
{
    const OSImage *osimage = osimage_from_image(image);
    draw_imgimp(ctx, osimage, UINT32_MAX, x, y, TRUE);
}

/*---------------------------------------------------------------------------*/

void draw_line_imp(DCtx *ctx, const real32_t x0, const real32_t y00, const real32_t x1, const real32_t y11, const bool_t raster)
{
    cassert_no_null(ctx);
    if (raster != ctx->raster_mode)
    {
        if (raster == TRUE)
            i_set_raster_mode(ctx);
        else
            i_set_real2d_mode(ctx);
    }

    CGContextMoveToPoint(ctx->context, (CGFloat)x0, (CGFloat)y00);
    CGContextAddLineToPoint(ctx->context, (CGFloat)x1, (CGFloat)y11);
    i_stroke_path(ctx);
}

/*---------------------------------------------------------------------------*/

void draw_rect_imp(DCtx *ctx, const drawop_t op, const real32_t x, const real32_t y, const real32_t width, const real32_t height, const bool_t raster)
{
    CGRect rect;
    cassert_no_null(ctx);
    if (raster != ctx->raster_mode)
    {
        if (raster == TRUE)
            i_set_raster_mode(ctx);
        else
            i_set_real2d_mode(ctx);
    }

    rect.origin.x = (CGFloat)x;
    rect.origin.y = (CGFloat)y;
    rect.size.width = (CGFloat)width;
    rect.size.height = (CGFloat)height;
    CGContextBeginPath(ctx->context);
    CGContextAddRect(ctx->context, rect);
    i_draw(ctx, op);
}
