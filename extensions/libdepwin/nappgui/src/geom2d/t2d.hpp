/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: t2d.hpp
 *
 */

/* 2D affine transformations */

#ifndef __T2D_HPP__
#define __T2D_HPP__

#include "v2d.hpp"

template <typename real>
struct T2D
{
    _geom2d_api static void (*move)(T2D<real> *dest, const T2D<real> *src, const real x, const real y);

    _geom2d_api static void (*rotate)(T2D<real> *dest, const T2D<real> *src, const real angle);

    _geom2d_api static void (*scale)(T2D<real> *dest, const T2D<real> *src, const real sx, const real sy);

    _geom2d_api static void (*invfast)(T2D<real> *dest, const T2D<real> *src);

    _geom2d_api static void (*inverse)(T2D<real> *dest, const T2D<real> *src);

    _geom2d_api static void (*mult)(T2D<real> *dest, const T2D<real> *src1, const T2D<real> *src2);

    _geom2d_api static void (*vmult)(V2D<real> *dest, const T2D<real> *t2d, const V2D<real> *src);

    _geom2d_api static void (*vmultn)(V2D<real> *dest, const T2D<real> *t2d, const V2D<real> *src, const uint32_t n);

    _geom2d_api static void (*decompose)(const T2D<real> *t2d, V2D<real> *pos, real *angle, V2D<real> *sc);

    _geom2d_api static const T2D<real> *kIDENT;

    V2D<real> i;
    V2D<real> j;
    V2D<real> p;
};

#endif
