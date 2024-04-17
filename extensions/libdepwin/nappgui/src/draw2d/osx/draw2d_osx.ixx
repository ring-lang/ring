/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw2d_osx.ixx
 *
 */

/* 2D drawing support */

#ifndef __DRAW2D_OSX_IXX__
#define __DRAW2D_OSX_IXX__

#include <sewer/nowarn.hxx>
#include <Cocoa/Cocoa.h>
#include <sewer/warn.hxx>
#include "draw2d.ixx"

#define MAX_COLORS 16
#define MAX_RANGE 48

typedef enum _fillmode_t
{
    ekFILL_SOLID,
    ekFILL_LINEAR
} fillmode_t;

struct _dctx_t
{
    BOOL is_flipped;
    pixformat_t format;
    uint32_t width;
    uint32_t height;
    CGContextRef context;
    CGAffineTransform origin;
    CGAffineTransform transform;
    CGGradientRef gradient;
    CGAffineTransform gradient_matrix;
    color_t skcolor;
    color_t fillcolor;
    color_t text_color;
    color_t gradient_colors[MAX_COLORS];
    real32_t gradient_stops[MAX_COLORS];
    uint32_t gradient_n;
    real32_t gradient_x0;
    real32_t gradient_y0;
    real32_t gradient_x1;
    real32_t gradient_y1;
    CGFloat gradient_rx0;
    CGFloat gradient_ry0;
    CGFloat gradient_rx1;
    CGFloat gradient_ry1;
    fillwrap_t wrap;
    fillmode_t fillmode;
    CGFloat line_width;
    CGLineCap linecap;
    CGLineJoin linejoin;
    CGFloat line_dash[16];
    uint32_t dash_count;
    real32_t text_width;
    align_t text_halign;
    align_t text_valign;
    align_t image_halign;
    align_t image_valign;
    NSMutableParagraphStyle *text_parag;
    NSMutableDictionary *text_dict;
    bool_t cartesian_system;
    bool_t raster_mode;
    bool_t line_fill;
    void *data;
    FPtr_destroy func_destroy_data;
};

struct _measurestr_t
{
    NSDictionary *dict;
};

extern NSNumber *kUNDERLINE_NONE;
extern NSNumber *kUNDERLINE_SINGLE;

#endif
