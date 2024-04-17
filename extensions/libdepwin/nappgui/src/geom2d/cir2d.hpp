/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: cir2d.hpp
 *
 */

/* Circle 2d */

#ifndef __CIR2D_HPP__
#define __CIR2D_HPP__

#include "box2d.hpp"

template <typename real>
struct Cir2D
{
    _geom2d_api Cir2D()
    {
        c.x = 0, c.y = 0, r = 0;
    }

    _geom2d_api Cir2D(const real _x, const real _y, const real _r)
    {
        c.x = _x, c.y = _y, r = _r;
    }

    _geom2d_api static Cir2D<real> (*from_box)(const Box2D<real> *box);

    _geom2d_api static Cir2D<real> (*from_points)(const V2D<real> *p, const uint32_t n);

    _geom2d_api static Cir2D<real> (*minimum)(const V2D<real> *p, const uint32_t n);

    _geom2d_api static real (*area)(const Cir2D<real> *cir);

    _geom2d_api static bool_t (*is_null)(const Cir2D<real> *cir);

    _geom2d_api static const Cir2D<real> *kNULL;

    V2D<real> c;
    real r;
};

#endif
