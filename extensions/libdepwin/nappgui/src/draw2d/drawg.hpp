/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: drawg.hpp
 *
 */

/* Drawing 2D Geometry entities */

#ifndef __DRAWG_HPP__
#define __DRAWG_HPP__

#include "draw2d.hxx"
#include <geom2d/cir2d.hpp>
#include <geom2d/obb2d.hpp>
#include <geom2d/pol2d.hpp>

template <typename real>
struct Draw
{
    _draw2d_api static void (*v2d)(DCtx *ctx, const drawop_t op, const V2D<real> *v2d, const real radius);

    _draw2d_api static void (*seg2d)(DCtx *ctx, const Seg2D<real> *seg);

    _draw2d_api static void (*cir2d)(DCtx *ctx, const drawop_t op, const Cir2D<real> *cir);

    _draw2d_api static void (*box2d)(DCtx *ctx, const drawop_t op, const Box2D<real> *box);

    _draw2d_api static void (*obb2d)(DCtx *ctx, const drawop_t op, const OBB2D<real> *obb);

    _draw2d_api static void (*tri2d)(DCtx *ctx, const drawop_t op, const Tri2D<real> *tri);

    _draw2d_api static void (*pol2d)(DCtx *ctx, const drawop_t op, const Pol2D<real> *pol);
};

#endif
