/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscolor.m
 *
 */

/* Color */

#include "oscolor.inl"
#include <draw2d/color.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

@interface OSXViewRGBA : NSView
{
  @public
    NSColor *nscolor;
}
@end

static OSXViewRGBA *i_COLOR_VIEW = nil;

/*---------------------------------------------------------------------------*/

@implementation OSXViewRGBA

- (void)drawRect:(NSRect)rect
{
    [self->nscolor setFill];
    NSRectFill(rect);
}

/*---------------------------------------------------------------------------*/

- (void)getRed:(CGFloat *)r green:(CGFloat *)g blue:(CGFloat *)b alpha:(CGFloat *)a
{
    NSRect rect = [self frame];
    NSBitmapImageRep *irep = [self bitmapImageRepForCachingDisplayInRect:rect];
    NSColor *color = nil;
    [irep setSize:rect.size];
    [self cacheDisplayInRect:rect toBitmapImageRep:irep];
    color = [irep colorAtX:0 y:0];
    [color getRed:r green:g blue:b alpha:a];
}

@end

/*---------------------------------------------------------------------------*/

static void i_NSColor_rgba(NSColor *color, CGFloat *r, CGFloat *g, CGFloat *b, CGFloat *a)
{
#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
    NSAppearance *aper = [NSApp effectiveAppearance];
    [i_COLOR_VIEW setAppearance:aper];
#endif
    cassert_no_null(color);
    i_COLOR_VIEW->nscolor = color;
    [i_COLOR_VIEW getRed:r green:g blue:b alpha:a];
}

/*---------------------------------------------------------------------------*/

static color_t i_from_NSColor(NSColor *c)
{
    CGFloat r, g, b, a;
    i_NSColor_rgba(c, &r, &g, &b, &a);
    return color_rgbaf((real32_t)r, (real32_t)g, (real32_t)b, (real32_t)a);
}

/*---------------------------------------------------------------------------*/

void oscolor_init(void)
{
    cassert(i_COLOR_VIEW == nil);
    i_COLOR_VIEW = [[OSXViewRGBA alloc] initWithFrame:NSMakeRect(0, 0, 1, 1)];
}

/*---------------------------------------------------------------------------*/

void oscolor_finish(void)
{
    [i_COLOR_VIEW release];
}

/*---------------------------------------------------------------------------*/

color_t oscolor_from_NSColor(NSColor *color)
{
    return i_from_NSColor(color);
}

/*---------------------------------------------------------------------------*/

void oscolor_NSColor_rgba(NSColor *color, CGFloat *r, CGFloat *g, CGFloat *b, CGFloat *a)
{
    i_NSColor_rgba(color, r, g, b, a);
}

/*---------------------------------------------------------------------------*/

void oscolor_NSColor_rgba_v(NSColor *color, CGFloat *rgba)
{
    i_NSColor_rgba(color, rgba, rgba + 1, rgba + 2, rgba + 3);
}

/*---------------------------------------------------------------------------*/

NSColor *oscolor_NSColor(color_t color)
{
    real32_t r, g, b, a;
    color_get_rgbaf(color, &r, &g, &b, &a);
    return [NSColor colorWithCalibratedRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a];
}
