/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osdrawctrl.c
 *
 */

/* Drawing custom GUI controls */

#include "osdrawctrl.h"
#include "osglobals_gtk.inl"
#include <draw2d/draw.h>
#include <draw2d/dctxh.h>
#include <draw2d/font.h>
#include <draw2d/color.h>
#include <sewer/cassert.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

/*---------------------------------------------------------------------------*/

Font *osdrawctrl_font(const DCtx *ctx)
{
    unref(ctx);
    return font_system(font_regular_size(), 0);
}

/*---------------------------------------------------------------------------*/

uint32_t osdrawctrl_row_padding(const DCtx *ctx)
{
    unref(ctx);
    return 4;
}

/*---------------------------------------------------------------------------*/

uint32_t osdrawctrl_check_width(const DCtx *ctx)
{
    unref(ctx);
    return osglobals_check_width();
}

/*---------------------------------------------------------------------------*/

uint32_t osdrawctrl_check_height(const DCtx *ctx)
{
    unref(ctx);
    return osglobals_check_height();
}

/*---------------------------------------------------------------------------*/

ctrl_msel_t osdrawctrl_multisel(const DCtx *ctx, const vkey_t key)
{
    unref(ctx);
    if (key == ekKEY_LCTRL || key == ekKEY_RCTRL)
        return ekCTRL_MSEL_SINGLE;
    else if (key == ekKEY_LSHIFT || key == ekKEY_RSHIFT)
        return ekCTRL_MSEL_BURST;
    return ekCTRL_MSEL_NO;
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_clear(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const enum_t nonused)
{
    GtkStyleContext *c = osglobals_entry_context();
    cairo_t *cairo = (cairo_t *)dctx_native(ctx);
    gtk_style_context_save(c);
    gtk_style_context_set_state(c, GTK_STATE_FLAG_NORMAL);
    gtk_render_background(c, cairo, (gdouble)x, (gdouble)y, (gdouble)width, (gdouble)height);
    gtk_style_context_restore(c);
    unref(nonused);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_header(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    static const uint32_t backoffset = 10;
    GtkStyleContext *c = osglobals_button_context();
    color_t border = osglobals_border_color();
    cairo_t *cairo = (cairo_t *)dctx_native(ctx);
    GtkStateFlags flags = 0;
    real32_t r, g, b, a;

    switch (state)
    {
    case ekCTRL_STATE_NORMAL:
    case ekCTRL_STATE_BKNORMAL:
        flags = GTK_STATE_FLAG_NORMAL;
        break;

    case ekCTRL_STATE_HOT:
    case ekCTRL_STATE_BKHOT:
        flags = GTK_STATE_FLAG_PRELIGHT;
        break;

    case ekCTRL_STATE_PRESSED:
    case ekCTRL_STATE_BKPRESSED:
#if GTK_CHECK_VERSION(3, 14, 0)
        flags = GTK_STATE_FLAG_CHECKED;
#else
        flags = GTK_STATE_FLAG_SELECTED;
#endif
        break;

    case ekCTRL_STATE_DISABLED:
        flags = GTK_STATE_FLAG_INSENSITIVE;
        break;

        cassert_default();
    }

    /* Preserve cairo context */
    cairo_save(cairo);
    cairo_set_antialias(cairo, CAIRO_ANTIALIAS_NONE);

    /* Avoid drawing outside the header rectangle */
    cairo_rectangle(cairo, (double)x, (double)y, (double)width, (double)height);
    cairo_clip(cairo);

    /* Background offset avoid roundness/alpha in button context borders */
    gtk_style_context_save(c);
    gtk_style_context_set_state(c, flags);
    gtk_render_background(c, cairo, (double)x - backoffset, (double)y - backoffset, (double)width + 2 * backoffset, (double)height + backoffset);
    gtk_style_context_restore(c);

    /* Draw the border */
    color_get_rgbaf(border, &r, &g, &b, &a);
    cairo_set_source_rgba(cairo, (double)r, (double)g, (double)b, (double)a);
    cairo_rectangle(cairo, (double)x, (double)y, (double)width, (double)height);
    cairo_stroke(cairo);

    /* Restore cairo context */
    cairo_restore(cairo);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_indicator(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const indicator_t indicator)
{
    static const gdouble ind_size = 8;
    cairo_t *cairo = (cairo_t *)dctx_native(ctx);

    unref(height);
    cairo_save(cairo);
    cairo_set_antialias(cairo, CAIRO_ANTIALIAS_NONE);

    if (indicator & ekINDDOWN_ARROW)
    {
        GtkStyleContext *c = osglobals_table_context();
        gtk_render_arrow(c, cairo, 3.14159, (gdouble)(x + width / 2. - ind_size / 2.), y, ind_size);
    }
    else if (indicator & ekINDUP_ARROW)
    {
        GtkStyleContext *c = osglobals_table_context();
        gtk_render_arrow(c, cairo, 0, (gdouble)(x + width / 2. - ind_size / 2.), y, ind_size);
    }

    cairo_restore(cairo);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_fill(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    GtkStyleContext *c = osglobals_table_context();
    cairo_t *cairo = (cairo_t *)dctx_native(ctx);
    GtkStateFlags flags = 0;

    switch (state)
    {
    case ekCTRL_STATE_NORMAL:
        flags = GTK_STATE_FLAG_NORMAL;
        break;

    case ekCTRL_STATE_HOT:
        flags = GTK_STATE_FLAG_PRELIGHT;
        break;

    case ekCTRL_STATE_PRESSED:
        flags = GTK_STATE_FLAG_SELECTED;
        break;

    case ekCTRL_STATE_BKNORMAL:
        flags = GTK_STATE_FLAG_NORMAL | GTK_STATE_FLAG_BACKDROP;
        break;

    case ekCTRL_STATE_BKHOT:
        flags = GTK_STATE_FLAG_PRELIGHT | GTK_STATE_FLAG_BACKDROP;
        break;

    case ekCTRL_STATE_BKPRESSED:
        flags = GTK_STATE_FLAG_SELECTED | GTK_STATE_FLAG_BACKDROP;
        break;

    case ekCTRL_STATE_DISABLED:
        flags = GTK_STATE_FLAG_INSENSITIVE;
        break;

        cassert_default();
    }

    gtk_style_context_save(c);
    gtk_style_context_set_state(c, flags);
    gtk_render_background(c, cairo, (double)x, (double)y, (double)width, (double)height);
    gtk_style_context_restore(c);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_focus(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    color_t color = osglobals_text_color();
    cairo_t *cairo = (cairo_t *)dctx_native(ctx);
    real32_t pattern[2] = {2.f, 1.f};
    real32_t r, g, b, a;
    unref(state);
    cairo_save(cairo);
    cairo_set_antialias(cairo, CAIRO_ANTIALIAS_NONE);
    draw_line_width(ctx, 1);
    draw_line_dash(ctx, pattern, 2);
    color_get_rgbaf(color, &r, &g, &b, &a);
    cairo_set_source_rgba(cairo, (double)r, (double)g, (double)b, (double)a);
    cairo_rectangle(cairo, (double)x + 2, (double)y + 2, (double)width - 4, (double)height - 4);
    cairo_stroke(cairo);
    cairo_restore(cairo);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_line(DCtx *ctx, const int32_t x0, const int32_t y0, const int32_t x1, const int32_t y1)
{
    draw_line_imp(ctx, (real32_t)x0, (real32_t)y0, (real32_t)x1, (real32_t)y1, TRUE);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_text(DCtx *ctx, const char_t *text, const int32_t x, const int32_t y, const ctrl_state_t state)
{
    color_t color = dctx_text_color(ctx);
    ellipsis_t ellipsis = dctx_text_trim(ctx);

    if (color == kCOLOR_TRANSPARENT)
    {
        switch (state)
        {
        case ekCTRL_STATE_NORMAL:
            color = osglobals_text_color();
            break;

        case ekCTRL_STATE_BKNORMAL:
            color = osglobals_textbackdrop_color();
            break;

        case ekCTRL_STATE_HOT:
            color = osglobals_hottext_color();
            break;

        case ekCTRL_STATE_BKHOT:
            color = osglobals_hottextbackdrop_color();
            break;

        case ekCTRL_STATE_PRESSED:
            color = osglobals_seltext_color();
            break;

        case ekCTRL_STATE_BKPRESSED:
            color = osglobals_seltextbackdrop_color();
            break;

        case ekCTRL_STATE_DISABLED:
            color = osglobals_text_color();
            break;

            cassert_default();
        }
    }

    draw_text_color(ctx, color);
    draw_text_trim(ctx, ekELLIPEND);
    draw_text_raster(ctx, text, x, y);
    draw_text_trim(ctx, ellipsis);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_image(DCtx *ctx, const Image *image, const int32_t x, const int32_t y, const ctrl_state_t state)
{
    draw_image(ctx, image, (real32_t)x, (real32_t)y);
    unref(state);
}

/*---------------------------------------------------------------------------*/

static void i_draw_check(cairo_t *cairo, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state, const uint32_t start)
{
    GdkPixbuf *bitmap = osglobals_checks_bitmap();
    uint32_t offset = start;

    switch (state)
    {
    case ekCTRL_STATE_NORMAL:
    case ekCTRL_STATE_BKNORMAL:
        offset += 0;
        break;

    case ekCTRL_STATE_HOT:
    case ekCTRL_STATE_BKHOT:
        offset += 1;
        break;

    case ekCTRL_STATE_PRESSED:
        offset += 2;
        break;

    case ekCTRL_STATE_BKPRESSED:
        offset += 3;
        break;

    case ekCTRL_STATE_DISABLED:
        offset += 4;
        break;

        cassert_default();
    }

    cassert(width == osglobals_check_width());
    cassert(height == osglobals_check_height());
    gdk_cairo_set_source_pixbuf(cairo, bitmap, (gdouble)x - (gdouble)(offset * width), (gdouble)y);
    cairo_rectangle(cairo, (double)x, (double)y, (double)width, (double)height);
    cairo_fill(cairo);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_checkbox(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    cairo_t *cairo = (cairo_t *)dctx_native(ctx);
    i_draw_check(cairo, x, y, width, height, state, 5);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_uncheckbox(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    cairo_t *cairo = (cairo_t *)dctx_native(ctx);
    i_draw_check(cairo, x, y, width, height, state, 0);
}
