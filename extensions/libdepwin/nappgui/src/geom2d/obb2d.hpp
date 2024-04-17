/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: obb2d.hpp
 *
 */

/* Oriented Box 2d */

#ifndef __OBB2D_HPP__
#define __OBB2D_HPP__

#include "box2d.hpp"
#include "t2d.hpp"

template <typename real>
struct OBB2D
{
    _geom2d_api static OBB2D<real> *(*create)(const V2D<real> *center, const real width, const real height, const real angle);

    _geom2d_api static OBB2D<real> *(*from_line)(const V2D<real> *p0, const V2D<real> *p1, const real thickness);

    _geom2d_api static OBB2D<real> *(*from_points)(const V2D<real> *p, const uint32_t n);

    _geom2d_api static OBB2D<real> *(*copy)(const OBB2D<real> *obb);

    _geom2d_api static void (*destroy)(OBB2D<real> **obb);

    _geom2d_api static void (*update)(OBB2D<real> *obb, const V2D<real> *center, const real width, const real height, const real angle);

    _geom2d_api static void (*move)(OBB2D<real> *obb, const real offset_x, const real offset_y);

    _geom2d_api static void (*transform)(OBB2D<real> *obb, const T2D<real> *t2d);

    _geom2d_api static const V2D<real> *(*corners)(const OBB2D<real> *obb);

    _geom2d_api static V2D<real> (*center)(const OBB2D<real> *obb);

    _geom2d_api static real (*width)(const OBB2D<real> *obb);

    _geom2d_api static real (*height)(const OBB2D<real> *obb);

    _geom2d_api static real (*angle)(const OBB2D<real> *obb);

    _geom2d_api static real (*area)(const OBB2D<real> *obb);

    _geom2d_api static Box2D<real> (*box)(const OBB2D<real> *obb);
};

#endif
