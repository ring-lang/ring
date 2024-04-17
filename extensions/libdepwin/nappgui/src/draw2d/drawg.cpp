/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: drawg.cpp
 *
 */

/* Drawing 2D Geometry entities */

#include "drawg.h"
#include "drawg.hpp"
#include "draw.h"
#include <geom2d/obb2d.h>
#include <geom2d/pol2d.h>
#include <geom2d/v2d.h>
#include <core/heap.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void draw_v2df(DCtx *ctx, const drawop_t op, const V2Df *v2d, const real32_t radius)
{
    cassert_no_null(v2d);
    draw_circle(ctx, op, v2d->x, v2d->y, radius);
}

/*---------------------------------------------------------------------------*/

void draw_v2dd(DCtx *ctx, const drawop_t op, const V2Dd *v2d, const real64_t radius)
{
    cassert_no_null(v2d);
    draw_circle(ctx, op, (real32_t)v2d->x, (real32_t)v2d->y, (real32_t)radius);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_v2d(DCtx *ctx, const drawop_t op, const V2D<real> *v2d, const real radius)
{
    cassert_no_null(v2d);
    draw_circle(ctx, op, (real32_t)v2d->x, (real32_t)v2d->y, (real32_t)radius);
}

/*---------------------------------------------------------------------------*/

void draw_seg2df(DCtx *ctx, const Seg2Df *seg)
{
    cassert_no_null(seg);
    draw_line(ctx, seg->p0.x, seg->p0.y, seg->p1.x, seg->p1.y);
}

/*---------------------------------------------------------------------------*/

void draw_seg2dd(DCtx *ctx, const Seg2Dd *seg)
{
    cassert_no_null(seg);
    draw_line(ctx, (real32_t)seg->p0.x, (real32_t)seg->p0.y, (real32_t)seg->p1.x, (real32_t)seg->p1.y);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_seg2d(DCtx *ctx, const Seg2D<real> *seg)
{
    cassert_no_null(seg);
    draw_line(ctx, (real32_t)seg->p0.x, (real32_t)seg->p0.y, (real32_t)seg->p1.x, (real32_t)seg->p1.y);
}

/*---------------------------------------------------------------------------*/

void draw_cir2df(DCtx *ctx, const drawop_t op, const Cir2Df *cir)
{
    cassert_no_null(cir);
    draw_circle(ctx, op, cir->c.x, cir->c.y, cir->r);
}

/*---------------------------------------------------------------------------*/

void draw_cir2dd(DCtx *ctx, const drawop_t op, const Cir2Dd *cir)
{
    cassert_no_null(cir);
    draw_circle(ctx, op, (real32_t)cir->c.x, (real32_t)cir->c.y, (real32_t)cir->r);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_cir2d(DCtx *ctx, const drawop_t op, const Cir2D<real> *cir)
{
    cassert_no_null(cir);
    draw_circle(ctx, op, (real32_t)cir->c.x, (real32_t)cir->c.y, (real32_t)cir->r);
}

/*---------------------------------------------------------------------------*/

void draw_box2df(DCtx *ctx, const drawop_t op, const Box2Df *box)
{
    cassert_no_null(box);
    draw_rect(ctx, op, box->min.x, box->min.y, (box->max.x - box->min.x), (box->max.y - box->min.y));
}

/*---------------------------------------------------------------------------*/

void draw_box2dd(DCtx *ctx, const drawop_t op, const Box2Dd *box)
{
    cassert_no_null(box);
    draw_rect(ctx, op, (real32_t)box->min.x, (real32_t)box->min.y, (real32_t)(box->max.x - box->min.x), (real32_t)(box->max.y - box->min.y));
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_box2d(DCtx *ctx, const drawop_t op, const Box2D<real> *box)
{
    cassert_no_null(box);
    draw_rect(ctx, op, (real32_t)box->min.x, (real32_t)box->min.y, (real32_t)(box->max.x - box->min.x), (real32_t)(box->max.y - box->min.y));
}

/*---------------------------------------------------------------------------*/

void draw_obb2df(DCtx *ctx, const drawop_t op, const OBB2Df *obb)
{
    const V2Df *v = obb2d_cornersf(obb);
    cassert_no_null(obb);
    draw_polygon(ctx, op, v, 4);
}

/*---------------------------------------------------------------------------*/

void draw_obb2dd(DCtx *ctx, const drawop_t op, const OBB2Dd *obb)
{
    const V2Dd *vd = obb2d_cornersd(obb);
    V2Df vf[4];
    cassert_no_null(obb);
    v2d_tofn(vf, vd, 4);
    draw_polygon(ctx, op, vf, 4);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_obb2d(DCtx *ctx, const drawop_t op, const OBB2D<real> *obb)
{
    const V2D<real> *v = OBB2D<real>::corners(obb);
    cassert_no_null(obb);
    cassert(sizeof(real) == 4);
    draw_polygon(ctx, op, (const V2Df *)v, 4);
}

/*---------------------------------------------------------------------------*/

template <>
void i_obb2d(DCtx *ctx, const drawop_t op, const OBB2D<real64_t> *obb)
{
    const V2D<real64_t> *vd = OBB2D<real64_t>::corners(obb);
    V2Df vf[4];
    cassert_no_null(obb);
    v2d_tofn(vf, (const V2Dd *)vd, 4);
    draw_polygon(ctx, op, vf, 4);
}

/*---------------------------------------------------------------------------*/

void draw_tri2df(DCtx *ctx, const drawop_t op, const Tri2Df *tri)
{
    draw_polygon(ctx, op, (const V2Df *)tri, 3);
}

/*---------------------------------------------------------------------------*/

void draw_tri2dd(DCtx *ctx, const drawop_t op, const Tri2Dd *tri)
{
    const V2Dd *vd = (const V2Dd *)tri;
    V2Df vf[3];
    cassert_no_null(tri);
    v2d_tofn(vf, vd, 3);
    draw_polygon(ctx, op, vf, 3);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_tri2d(DCtx *ctx, const drawop_t op, const Tri2D<real> *tri)
{
    cassert_no_null(tri);
    cassert(sizeof(real) == 4);
    draw_polygon(ctx, op, (const V2Df *)tri, 3);
}

/*---------------------------------------------------------------------------*/

template <>
void i_tri2d(DCtx *ctx, const drawop_t op, const Tri2D<real64_t> *tri)
{
    const V2D<real64_t> *vd = (const V2D<real64_t> *)tri;
    V2Df vf[3];
    cassert_no_null(tri);
    v2d_tofn(vf, (const V2Dd *)vd, 3);
    draw_polygon(ctx, op, vf, 3);
}

/*---------------------------------------------------------------------------*/

void draw_pol2df(DCtx *ctx, const drawop_t op, const Pol2Df *pol)
{
    const V2Df *v = pol2d_pointsf(pol);
    uint32_t n = pol2d_nf(pol);
    draw_polygon(ctx, op, v, n);
}

/*---------------------------------------------------------------------------*/

void draw_pol2dd(DCtx *ctx, const drawop_t op, const Pol2Dd *pol)
{
    const V2Dd *vd = pol2d_pointsd(pol);
    uint32_t n = pol2d_nd(pol);
    V2Df *vf = heap_new_n(n, V2Df);
    v2d_tofn(vf, vd, n);
    draw_polygon(ctx, op, vf, n);
    heap_delete_n(&vf, n, V2Df);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_pol2d(DCtx *ctx, const drawop_t op, const Pol2D<real> *pol)
{
    const V2D<real> *v = Pol2D<real>::points(pol);
    uint32_t n = Pol2D<real>::n(pol);
    cassert(sizeof(real) == 4);
    draw_polygon(ctx, op, (const V2Df *)v, n);
}

/*---------------------------------------------------------------------------*/

template <>
void i_pol2d(DCtx *ctx, const drawop_t op, const Pol2D<real64_t> *pol)
{
    const V2D<real64_t> *vd = Pol2D<real64_t>::points(pol);
    uint32_t n = Pol2D<real64_t>::n(pol);
    V2Df *vf = heap_new_n(n, V2Df);
    v2d_tofn(vf, (const V2Dd *)vd, n);
    draw_polygon(ctx, op, vf, n);
    heap_delete_n(&vf, n, V2Df);
}

/*---------------------------------------------------------------------------*/

template <>
void (*Draw<real32_t>::v2d)(DCtx *, const drawop_t, const V2D<real32_t> *, const real32_t) = i_v2d<real32_t>;

template <>
void (*Draw<real64_t>::v2d)(DCtx *, const drawop_t, const V2D<real64_t> *, const real64_t) = i_v2d<real64_t>;

template <>
void (*Draw<real32_t>::seg2d)(DCtx *, const Seg2D<real32_t> *) = i_seg2d<real32_t>;

template <>
void (*Draw<real64_t>::seg2d)(DCtx *, const Seg2D<real64_t> *) = i_seg2d<real64_t>;

template <>
void (*Draw<real32_t>::cir2d)(DCtx *, const drawop_t, const Cir2D<real32_t> *) = i_cir2d<real32_t>;

template <>
void (*Draw<real64_t>::cir2d)(DCtx *, const drawop_t, const Cir2D<real64_t> *) = i_cir2d<real64_t>;

template <>
void (*Draw<real32_t>::box2d)(DCtx *, const drawop_t, const Box2D<real32_t> *) = i_box2d<real32_t>;

template <>
void (*Draw<real64_t>::box2d)(DCtx *, const drawop_t, const Box2D<real64_t> *) = i_box2d<real64_t>;

template <>
void (*Draw<real32_t>::obb2d)(DCtx *, const drawop_t, const OBB2D<real32_t> *) = i_obb2d<real32_t>;

template <>
void (*Draw<real64_t>::obb2d)(DCtx *, const drawop_t, const OBB2D<real64_t> *) = i_obb2d<real64_t>;

template <>
void (*Draw<real32_t>::tri2d)(DCtx *, const drawop_t, const Tri2D<real32_t> *) = i_tri2d<real32_t>;

template <>
void (*Draw<real64_t>::tri2d)(DCtx *, const drawop_t, const Tri2D<real64_t> *) = i_tri2d<real64_t>;

template <>
void (*Draw<real32_t>::pol2d)(DCtx *, const drawop_t, const Pol2D<real32_t> *) = i_pol2d<real32_t>;

template <>
void (*Draw<real64_t>::pol2d)(DCtx *, const drawop_t, const Pol2D<real64_t> *) = i_pol2d<real64_t>;
