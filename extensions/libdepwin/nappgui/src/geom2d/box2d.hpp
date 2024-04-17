/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: box2d.hpp
 *
 */

/* Box 2d */

#ifndef __B2D_HPP__
#define __B2D_HPP__

#include "seg2d.hpp"

template <typename real>
struct Box2D
{
    _geom2d_api Box2D()
    {
        *this = *kNULL;
    }

    _geom2d_api Box2D(const real minX, const real minY, const real maxX, const real maxY)
    {
        min.x = minX, min.y = minY, max.x = maxX, max.y = maxY;
    }

    _geom2d_api static Box2D<real> (*from_points)(const V2D<real> *p, const uint32_t n);

    _geom2d_api static V2D<real> (*center)(const Box2D<real> *box);

    _geom2d_api static void (*add)(Box2D<real> *box, const V2D<real> *p);

    _geom2d_api static void (*addn)(Box2D<real> *box, const V2D<real> *p, const uint32_t n);

    _geom2d_api static void (*merge)(Box2D<real> *dest, const Box2D<real> *src);

    _geom2d_api static void (*segments)(const Box2D<real> *box, Seg2D<real> *segs);

    _geom2d_api static real (*area)(const Box2D<real> *box);

    _geom2d_api static bool_t (*is_null)(const Box2D<real> *box);

    _geom2d_api static const Box2D<real> *kNULL;

    V2D<real> min;
    V2D<real> max;
};

template <typename real, typename real2>
struct Box2D2
{
    _geom2d_api static void (*copy)(Box2D<real> *dest, const Box2D<real2> *src);
};

#endif
