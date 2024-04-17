/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: tri2d.hpp
 *
 */

/* 2D triangles */

#ifndef __TRI2D_HPP__
#define __TRI2D_HPP__

#include "t2d.hpp"

template <typename real>
struct Tri2D
{
    _geom2d_api Tri2D()
    {
        p0.x = 0, p0.y = 0, p1.x = 0, p1.y = 0, p2.x = 0, p2.y = 0;
    }

    _geom2d_api Tri2D(const real x0, const real y0, const real x1, const real y1, const real x2, const real y2)
    {
        p0.x = x0, p0.y = y0, p1.x = x1, p1.y = y1, p2.x = x2, p2.y = y2;
    }

    _geom2d_api Tri2D(const V2D<real> *_p0, const V2D<real> *_p1, const V2D<real> *_p2)
    {
        p0 = *_p0, p1 = *_p1, p2 = *_p2;
    }

    _geom2d_api static void (*transform)(Tri2D<real> *tri, const T2D<real> *t2d);

    _geom2d_api static real (*area)(const Tri2D<real> *tri);

    _geom2d_api static bool_t (*ccw)(const Tri2D<real> *tri);

    _geom2d_api static V2D<real> (*centroid)(const Tri2D<real> *tri);

    V2D<real> p0;
    V2D<real> p1;
    V2D<real> p2;
};

#endif
