/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: pol2d.hpp
 *
 */

/* 2d polygon */

#ifndef __POL2D_HPP__
#define __POL2D_HPP__

#include "t2d.hpp"
#include "tri2d.hpp"
#include "box2d.hpp"
#include <core/arrst.hpp>
#include <core/arrpt.hpp>

template <typename real>
struct Pol2D
{
    _geom2d_api static Pol2D<real> *(*create)(const V2D<real> *points, const uint32_t n);

    _geom2d_api static Pol2D<real> *(*convex_hull)(const V2D<real> *points, const uint32_t n);

    _geom2d_api static Pol2D<real> *(*copy)(const Pol2D<real> *pol);

    _geom2d_api static void (*destroy)(Pol2D<real> **pol);

    _geom2d_api static void (*transform)(Pol2D<real> *pol, const T2D<real> *t2d);

    _geom2d_api static const V2D<real> *(*points)(const Pol2D<real> *pol);

    _geom2d_api static uint32_t (*n)(const Pol2D<real> *pol);

    _geom2d_api static real (*area)(const Pol2D<real> *pol);

    _geom2d_api static Box2D<real> (*box)(const Pol2D<real> *pol);

    _geom2d_api static bool_t (*ccw)(const Pol2D<real> *pol);

    _geom2d_api static bool_t (*convex)(const Pol2D<real> *pol);

    _geom2d_api static V2D<real> (*centroid)(const Pol2D<real> *pol);

    _geom2d_api static V2D<real> (*visual_center)(const Pol2D<real> *pol, const real tol);

    _geom2d_api static ArrSt<Tri2D<real> > *(*triangles)(const Pol2D<real> *pol);

    _geom2d_api static ArrPt<Pol2D<real> > *(*convex_partition)(const Pol2D<real> *pol);
};

#endif
