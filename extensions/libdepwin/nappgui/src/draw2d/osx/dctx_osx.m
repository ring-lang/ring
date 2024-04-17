/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dctx_osx.m
 *
 */

/* Draw context */

#include <sewer/nowarn.hxx>
#include <Cocoa/Cocoa.h>
#include <sewer/warn.hxx>
#include "draw2d_osx.ixx"

#include "dctx.h"
#include "dctxh.h"
#include "dctx.inl"
#include "color.h"
#include "font.h"
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

static void i_init_text_attr(DCtx *ctx)
{
    id objects[5];
    id keys[5];

    cassert(ctx->text_parag == NULL);
    cassert(ctx->text_dict == NULL);
    ctx->text_parag = [[[NSParagraphStyle defaultParagraphStyle] mutableCopy] retain];
    [ctx->text_parag setLineBreakMode:NSLineBreakByWordWrapping];

    objects[0] = kUNDERLINE_NONE;
    objects[1] = kUNDERLINE_NONE;
    objects[2] = ctx->text_parag;
    objects[3] = [NSColor blackColor];
    objects[4] = [NSFont systemFontOfSize:[NSFont systemFontSize]];
    keys[0] = NSUnderlineStyleAttributeName;
    keys[1] = NSStrikethroughStyleAttributeName;
    keys[2] = NSParagraphStyleAttributeName;
    keys[3] = NSForegroundColorAttributeName;
    keys[4] = NSFontAttributeName;

    ctx->text_dict = [[NSMutableDictionary alloc] initWithObjects:objects forKeys:keys count:5];
}

/*---------------------------------------------------------------------------*/

DCtx *dctx_create(void)
{
    DCtx *ctx = heap_new0(DCtx);
    ctx->line_width = 1;
    ctx->gradient_matrix = CGAffineTransformIdentity;
    i_init_text_attr(ctx);
    return ctx;
}

/*---------------------------------------------------------------------------*/

void dctx_destroy(DCtx **ctx)
{
    cassert_no_null(ctx);
    cassert_no_null(*ctx);

    if ((*ctx)->gradient != NULL)
        CGGradientRelease((*ctx)->gradient);

    if ((*ctx)->context != NULL)
    {
        CGContextRelease((*ctx)->context);
        (*ctx)->context = NULL;
    }

    [(*ctx)->text_dict release];
    [(*ctx)->text_parag release];

    if ((*ctx)->data != NULL)
    {
        if ((*ctx)->func_destroy_data != NULL)
            (*ctx)->func_destroy_data(&(*ctx)->data);
    }

    heap_delete(ctx, DCtx);
}

/*---------------------------------------------------------------------------*/

static __INLINE CGContextRef i_CGContext(NSGraphicsContext *nscontext)
{
#if defined(MAC_OS_X_VERSION_10_10) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_10
    return [nscontext CGContext];
#else
    return (CGContextRef)[nscontext graphicsPort];
#endif
}

/*---------------------------------------------------------------------------*/

void dctx_set_gcontext(DCtx *ctx, void *gcontext, const uint32_t width, const uint32_t height, const real32_t offset_x, const real32_t offset_y, const uint32_t background, const bool_t reset)
{
    cassert_no_null(ctx);
    cassert(ctx->context == NULL);
    unref(background);
    ctx->width = width;
    ctx->height = height;
    ctx->context = i_CGContext((NSGraphicsContext *)gcontext);
    CGContextSaveGState(ctx->context);
    CGContextTranslateCTM(ctx->context, -(CGFloat)offset_x, -(CGFloat)offset_y);
    ctx->origin = CGContextGetCTM(ctx->context);
    ctx->raster_mode = FALSE;
    if (reset == TRUE)
        dctx_init(ctx);
}

/*---------------------------------------------------------------------------*/

void dctx_unset_gcontext(DCtx *ctx)
{
    cassert_no_null(ctx);
    cassert(ctx->context != NULL);
    CGContextRestoreGState(ctx->context);
    ctx->context = NULL;
}

/*---------------------------------------------------------------------------*/

void dctx_set_flipped(DCtx *ctx, const bool_t flipped)
{
    cassert_no_null(ctx);
    ctx->is_flipped = (BOOL)flipped;
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
    unref(ctx);
    unref(offset_x);
    unref(offset_y);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void dctx_line_dash(const DCtx *ctx, real32_t *pattern, uint32_t *size)
{
    uint32_t i;
    cassert_no_null(ctx);
    cassert_no_null(pattern);
    cassert_no_null(size);
    *size = ctx->dash_count;
    for (i = 0; i < ctx->dash_count; ++i)
        pattern[i] = (real32_t)ctx->line_dash[i];
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
    cassert_no_null(ctx);
    return ctx->skcolor;
}

/*---------------------------------------------------------------------------*/

color_t dctx_background_color(const DCtx *ctx)
{
    unref(ctx);
    cassert(FALSE);
    return 0;
}

/*---------------------------------------------------------------------------*/

static ellipsis_t i_ellipsis(NSLineBreakMode mode)
{
    switch (mode)
    {
    case NSLineBreakByWordWrapping:
        return ekELLIPMLINE;
    case NSLineBreakByClipping:
        return ekELLIPNONE;
    case NSLineBreakByTruncatingHead:
        return ekELLIPBEGIN;
    case NSLineBreakByTruncatingTail:
        return ekELLIPEND;
    case NSLineBreakByTruncatingMiddle:
        return ekELLIPMIDDLE;
    case NSLineBreakByCharWrapping:
        break;
    }
    return ENUM_MAX(ellipsis_t);
}

/*---------------------------------------------------------------------------*/

ellipsis_t dctx_text_trim(const DCtx *ctx)
{
    cassert_no_null(ctx);
    return i_ellipsis(ctx->text_parag.lineBreakMode);
}

/*---------------------------------------------------------------------------*/

void *dctx_native(DCtx *ctx)
{
    cassert_no_null(ctx);
    return ctx->context;
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
    cassert_no_null(ctx);
    cassert(ctx->data == NULL);
    cassert(ctx->func_destroy_data == NULL);
    ctx->data = data;
    ctx->func_destroy_data = func_destroy_data;
}

/*---------------------------------------------------------------------------*/

void *dctx_get_data_imp(const DCtx *ctx)
{
    cassert_no_null(ctx);
    return ctx->data;
}

/*---------------------------------------------------------------------------*/

DCtx *dctx_bitmap(const uint32_t width, const uint32_t height, const pixformat_t format)
{
    DCtx *ctx = heap_new0(DCtx);
    CGColorSpaceRef space = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
    byte_t *pixdata = heap_malloc(width * height * 4, "OSXBitmapContextData");
    NSGraphicsContext *nscontext = nil;
    ctx->context = CGBitmapContextCreate((void *)pixdata, (size_t)width, (size_t)height, 8, (size_t)(width * 4), space, (CGBitmapInfo)kCGImageAlphaPremultipliedLast);
    CGColorSpaceRelease(space);

#if defined(MAC_OS_X_VERSION_10_10) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_10
    nscontext = [NSGraphicsContext graphicsContextWithCGContext:ctx->context flipped:YES];
#else
    nscontext = [NSGraphicsContext graphicsContextWithGraphicsPort:ctx->context flipped:YES];
#endif

    [NSGraphicsContext setCurrentContext:nscontext];
    ctx->format = format;
    ctx->width = (uint32_t)CGBitmapContextGetWidth(ctx->context);
    ctx->height = (uint32_t)CGBitmapContextGetHeight(ctx->context);
    ctx->is_flipped = YES;
    ctx->origin = CGAffineTransformMake(1, 0, 0, -1, 0, (CGFloat)height);
    ctx->line_width = 1;
    ctx->gradient_matrix = CGAffineTransformIdentity;
    CGContextConcatCTM(ctx->context, ctx->origin);
    i_init_text_attr(ctx);
    dctx_init(ctx);
    return ctx;
}

/*---------------------------------------------------------------------------*/

void dctx_transform(DCtx *ctx, const T2Df *t2d, const bool_t cartesian)
{
    CGAffineTransform transform;
    cassert_no_null(ctx);
    cassert_no_null(t2d);
    transform.a = (CGFloat)t2d->i.x;
    transform.b = (CGFloat)t2d->i.y;
    transform.c = (CGFloat)t2d->j.x;
    transform.d = (CGFloat)t2d->j.y;
    transform.tx = (CGFloat)t2d->p.x;
    transform.ty = (CGFloat)t2d->p.y;
    ctx->transform = transform;
    ctx->cartesian_system = cartesian;

    if (ctx->raster_mode == FALSE)
    {
        /* Invalidate previous transform. Equivalent to hypothetical SetIdentity() */
        CGAffineTransform curtrans = CGContextGetCTM(ctx->context);
        curtrans = CGAffineTransformInvert(curtrans);
        CGContextConcatCTM(ctx->context, curtrans);

        /* Apply new transform */
        CGContextConcatCTM(ctx->context, ctx->origin);
        CGContextConcatCTM(ctx->context, ctx->transform);
    }
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

void draw_clear(DCtx *ctx, const color_t color)
{
    cassert_no_null(ctx);
    if (color != 0)
    {
        uint32_t width, height;
        CGRect rect;
        CGFloat r, g, b, a;
        dctx_size(ctx, &width, &height);
        rect.origin.x = 0;
        rect.origin.y = 0;
        rect.size.width = (CGFloat)width;
        rect.size.height = (CGFloat)height;
        i_color(color, &r, &g, &b, &a);
        CGContextSetRGBFillColor(ctx->context, r, g, b, a);
        CGContextFillRect(ctx->context, rect);
        i_color(ctx->fillcolor, &r, &g, &b, &a);
        CGContextSetRGBFillColor(ctx->context, r, g, b, a);
    }
}

/*---------------------------------------------------------------------------*/

void draw_antialias(DCtx *ctx, const bool_t on)
{
    cassert_no_null(ctx);
    CGContextSetShouldAntialias(ctx->context, on);
}

/*---------------------------------------------------------------------------*/

void dctx_set_default_osfont(DCtx *ctx, const void *font)
{
    unref(ctx);
    unref(font);
    cassert(FALSE);
}
