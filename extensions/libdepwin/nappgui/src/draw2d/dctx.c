/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dctx.c
 *
 */

/* Draw context */

#include "dctx.h"
#include "dctxh.h"
#include "dctx.inl"
#include "draw.h"
#include "color.h"
#include "font.h"
#include <core/strings.h>
#include <geom2d/t2d.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void dctx_init(DCtx *ctx)
{
    Font *font = font_system(font_regular_size(), 0);
    draw_matrixf(ctx, kT2D_IDENTf);
    draw_antialias(ctx, TRUE);
    draw_line_color(ctx, kCOLOR_BLACK);
    draw_line_width(ctx, 1);
    draw_line_cap(ctx, ekLCFLAT);
    draw_line_join(ctx, ekLJMITER);
    draw_line_dash(ctx, NULL, 0);
    draw_fill_color(ctx, kCOLOR_BLACK);
    draw_fill_matrix(ctx, kT2D_IDENTf);
    draw_fill_wrap(ctx, ekFCLAMP);
    draw_font(ctx, font);
    draw_text_color(ctx, kCOLOR_BLACK);
    draw_text_width(ctx, -1);
    draw_text_trim(ctx, ekELLIPMLINE);
    draw_text_align(ctx, ekLEFT, ekTOP);
    draw_text_halign(ctx, ekLEFT);
    draw_image_align(ctx, ekLEFT, ekTOP);
    font_destroy(&font);
}

/*---------------------------------------------------------------------------*/

void draw_matrixf(DCtx *ctx, const T2Df *t2d)
{
    dctx_transform(ctx, t2d, FALSE);
}

/*---------------------------------------------------------------------------*/

void draw_matrixd(DCtx *ctx, const T2Dd *t2d)
{
    T2Df t2df;
    t2df.i.x = (real32_t)t2d->i.x;
    t2df.i.y = (real32_t)t2d->i.y;
    t2df.j.x = (real32_t)t2d->j.x;
    t2df.j.y = (real32_t)t2d->j.y;
    t2df.p.x = (real32_t)t2d->p.x;
    t2df.p.y = (real32_t)t2d->p.y;
    dctx_transform(ctx, &t2df, FALSE);
}

/*---------------------------------------------------------------------------*/

void draw_matrix_cartesianf(DCtx *ctx, const T2Df *t2d)
{
    uint32_t h;
    T2Df ct2d;
    dctx_size(ctx, NULL, &h);
    ct2d.i.x = 1;
    ct2d.i.y = 0;
    ct2d.j.x = 0;
    ct2d.j.y = -1;
    ct2d.p.x = 0;
    ct2d.p.y = (real32_t)h;
    t2d_multf(&ct2d, &ct2d, t2d);
    dctx_transform(ctx, &ct2d, TRUE);
}

/*---------------------------------------------------------------------------*/

void draw_matrix_cartesiand(DCtx *ctx, const T2Dd *t2d)
{
    uint32_t h;
    T2Df ct2d;
    T2Df t2df;
    dctx_size(ctx, NULL, &h);
    t2df.i.x = (real32_t)t2d->i.x;
    t2df.i.y = (real32_t)t2d->i.y;
    t2df.j.x = (real32_t)t2d->j.x;
    t2df.j.y = (real32_t)t2d->j.y;
    t2df.p.x = (real32_t)t2d->p.x;
    t2df.p.y = (real32_t)t2d->p.y;
    ct2d.i.x = 1;
    ct2d.i.y = 0;
    ct2d.j.x = 0;
    ct2d.j.y = -1;
    ct2d.p.x = 0;
    ct2d.p.y = (real32_t)h;
    t2d_multf(&ct2d, &ct2d, &t2df);
    dctx_transform(ctx, &ct2d, TRUE);
}

/*---------------------------------------------------------------------------*/
