/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: tri2d.cpp
 *
 */

/* 2D triangles */

#include "tri2d.h"
#include "tri2d.hpp"
#include <sewer/bmath.hpp>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

Tri2Df tri2df(const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1, const real32_t x2, const real32_t y2)
{
    Tri2Df tri2d;
    tri2d.p0.x = x0;
    tri2d.p0.y = y0;
    tri2d.p1.x = x1;
    tri2d.p1.y = y1;
    tri2d.p2.x = x2;
    tri2d.p2.y = y2;
    return tri2d;
}

/*---------------------------------------------------------------------------*/

Tri2Dd tri2dd(const real64_t x0, const real64_t y0, const real64_t x1, const real64_t y1, const real64_t x2, const real64_t y2)
{
    Tri2Dd tri2d;
    tri2d.p0.x = x0;
    tri2d.p0.y = y0;
    tri2d.p1.x = x1;
    tri2d.p1.y = y1;
    tri2d.p2.x = x2;
    tri2d.p2.y = y2;
    return tri2d;
}

/*---------------------------------------------------------------------------*/

Tri2Df tri2d_vf(const V2Df *p0, const V2Df *p1, const V2Df *p2)
{
    Tri2Df tri2d;
    cassert_no_null(p0);
    cassert_no_null(p1);
    cassert_no_null(p2);
    tri2d.p0 = *p0;
    tri2d.p1 = *p1;
    tri2d.p2 = *p2;
    return tri2d;
}

/*---------------------------------------------------------------------------*/

Tri2Dd tri2d_vd(const V2Dd *p0, const V2Dd *p1, const V2Dd *p2)
{
    Tri2Dd tri2d;
    cassert_no_null(p0);
    cassert_no_null(p1);
    cassert_no_null(p2);
    tri2d.p0 = *p0;
    tri2d.p1 = *p1;
    tri2d.p2 = *p2;
    return tri2d;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_transform(Tri2D<real> *tri, const T2D<real> *t2d)
{
    cassert_no_null(tri);
    T2D<real>::vmult(&tri->p0, t2d, &tri->p0);
    T2D<real>::vmult(&tri->p1, t2d, &tri->p1);
    T2D<real>::vmult(&tri->p2, t2d, &tri->p2);
}

/*---------------------------------------------------------------------------*/

void tri2d_transformf(Tri2Df *tri, const T2Df *t2d)
{
    i_transform<real32_t>((Tri2D<real32_t> *)tri, (const T2D<real32_t> *)t2d);
}

/*---------------------------------------------------------------------------*/

void tri2d_transformd(Tri2Dd *tri, const T2Dd *t2d)
{
    i_transform<real64_t>((Tri2D<real64_t> *)tri, (const T2D<real64_t> *)t2d);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_area(const Tri2D<real> *tri)
{
    real area = 0;
    cassert_no_null(tri);
    area = tri->p0.x * (tri->p1.y - tri->p2.y) + tri->p1.x * (tri->p2.y - tri->p0.y) + tri->p2.x * (tri->p0.y - tri->p1.y);
    area /= 2;
    return (area > 0) ? area : -area;
}

/*---------------------------------------------------------------------------*/

real32_t tri2d_areaf(const Tri2Df *tri)
{
    return i_area<real32_t>((const Tri2D<real32_t> *)tri);
}

/*---------------------------------------------------------------------------*/

real64_t tri2d_aread(const Tri2Dd *tri)
{
    return i_area<real64_t>((const Tri2D<real64_t> *)tri);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_ccw(const Tri2D<real> *tri)
{
    real area = 0;
    cassert_no_null(tri);
    area = tri->p0.x * (tri->p1.y - tri->p2.y) + tri->p1.x * (tri->p2.y - tri->p0.y) + tri->p2.x * (tri->p0.y - tri->p1.y);
    return (area > 0) ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t tri2d_ccwf(const Tri2Df *tri)
{
    return i_ccw<real32_t>((const Tri2D<real32_t> *)tri);
}

/*---------------------------------------------------------------------------*/

bool_t tri2d_ccwd(const Tri2Dd *tri)
{
    return i_ccw<real64_t>((const Tri2D<real64_t> *)tri);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_centroid(const Tri2D<real> *tri)
{
    V2D<real> c(0, 0);
    cassert_no_null(tri);
    c.x = (tri->p0.x + tri->p1.x + tri->p2.x) / 3;
    c.y = (tri->p0.y + tri->p1.y + tri->p2.y) / 3;
    return c;
}

/*---------------------------------------------------------------------------*/

V2Df tri2d_centroidf(const Tri2Df *tri)
{
    V2D<real32_t> v = i_centroid<real32_t>((const Tri2D<real32_t> *)tri);
    V2Df vf;
    vf.x = v.x;
    vf.y = v.y;
    return vf;
}

/*---------------------------------------------------------------------------*/

V2Dd tri2d_centroidd(const Tri2Dd *tri)
{
    V2D<real64_t> v = i_centroid<real64_t>((const Tri2D<real64_t> *)tri);
    V2Dd vd;
    vd.x = v.x;
    vd.y = v.y;
    return vd;
}

/*---------------------------------------------------------------------------*/

template <>
void (*Tri2D<real32_t>::transform)(Tri2D<real32_t> *, const T2D<real32_t> *) = i_transform<real32_t>;

template <>
void (*Tri2D<real64_t>::transform)(Tri2D<real64_t> *, const T2D<real64_t> *) = i_transform<real64_t>;

template <>
real32_t (*Tri2D<real32_t>::area)(const Tri2D<real32_t> *) = i_area<real32_t>;

template <>
real64_t (*Tri2D<real64_t>::area)(const Tri2D<real64_t> *) = i_area<real64_t>;

template <>
bool_t (*Tri2D<real32_t>::ccw)(const Tri2D<real32_t> *) = i_ccw<real32_t>;

template <>
bool_t (*Tri2D<real64_t>::ccw)(const Tri2D<real64_t> *) = i_ccw<real64_t>;

template <>
V2D<real32_t> (*Tri2D<real32_t>::centroid)(const Tri2D<real32_t> *) = i_centroid<real32_t>;

template <>
V2D<real64_t> (*Tri2D<real64_t>::centroid)(const Tri2D<real64_t> *) = i_centroid<real64_t>;
