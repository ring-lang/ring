/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw2d_gtk.ixx
 *
 */

/* 2D drawing support */

#ifndef __DRAWLIB_GTK_IXX__
#define __DRAWLIB_GTK_IXX__

#include <sewer/nowarn.hxx>
#include <cairo.h>
#include <pango/pango.h>
#include <sewer/warn.hxx>

typedef enum _fillmode_t
{
    ekFILL_SOLID,
    ekFILL_LINEAR
} fillmode_t;

struct _dctx_t
{
    pixformat_t format;
    double offset_x;
    double offset_y;
    uint32_t width;
    uint32_t height;
    cairo_t *cairo;
    cairo_matrix_t origin;
    cairo_surface_t *surface;
    cairo_pattern_t *lpattern;
    cairo_extend_t wrap_mode;
    cairo_matrix_t transform;
    cairo_matrix_t pattern_matrix;
    color_t text_color;
    color_t fill_color;
    color_t stroke_color;
    color_t source_color;
    fillmode_t fillmode;
    double line_dash[16];
    int dash_count;
    real32_t text_width;
    align_t text_halign;
    align_t text_valign;
    PangoAlignment text_intalign;
    PangoEllipsizeMode ellipsis;
    Font *font;
    PangoLayout *layout;
    align_t image_halign;
    align_t image_valign;
    bool_t cartesian_system;
    bool_t raster_mode;
    bool_t fill_line;
};

#endif
