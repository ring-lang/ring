/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: r2d.hpp
 *
 */

/* 2D rectangles */

#ifndef __R2D_HPP__
#define __R2D_HPP__

#include "v2d.hpp"
#include "s2d.hpp"

template <typename real>
struct R2D
{
    _geom2d_api R2D()
    {
        pos.x = 0, pos.y = 0, size.width = 0, size.height = 0;
    }

    _geom2d_api R2D(const real x, const real y, const real width, const real height)
    {
        pos.x = x, pos.y = y, size.width = width, size.height = height;
    }

    _geom2d_api static V2D<real> (*center)(const R2D *r2d);

    _geom2d_api static bool_t (*collide)(const R2D *r2d1, const R2D *r2d2);

    _geom2d_api static bool_t (*contains)(const R2D *r2d, const real x, const real y);

    _geom2d_api static bool_t (*clip)(const R2D *viewport, const R2D *r2d);

    _geom2d_api static void (*join)(R2D *r2d, const R2D *src);

    _geom2d_api static const R2D<real> *kZERO;

    V2D<real> pos;
    S2D<real> size;
};

#endif
