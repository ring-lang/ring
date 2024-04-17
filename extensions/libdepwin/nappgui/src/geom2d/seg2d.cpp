/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: seg2d.cpp
 *
 */

/* 2d segments */

#include "seg2d.h"
#include "seg2d.hpp"
#include <sewer/cassert.h>
#include <sewer/ptr.h>

/*---------------------------------------------------------------------------*/

Seg2Df seg2df(const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1)
{
    Seg2Df seg2d;
    seg2d.p0.x = x0;
    seg2d.p0.y = y0;
    seg2d.p1.x = x1;
    seg2d.p1.y = y1;
    return seg2d;
}

/*---------------------------------------------------------------------------*/

Seg2Dd seg2dd(const real64_t x0, const real64_t y0, const real64_t x1, const real64_t y1)
{
    Seg2Dd seg2d;
    seg2d.p0.x = x0;
    seg2d.p0.y = y0;
    seg2d.p1.x = x1;
    seg2d.p1.y = y1;
    return seg2d;
}

/*---------------------------------------------------------------------------*/

Seg2Df seg2d_vf(const V2Df *p0, const V2Df *p1)
{
    Seg2Df seg2d;
    cassert_no_null(p0);
    cassert_no_null(p1);
    seg2d.p0 = *p0;
    seg2d.p1 = *p1;
    return seg2d;
}

/*---------------------------------------------------------------------------*/

Seg2Dd seg2d_vd(const V2Dd *p0, const V2Dd *p1)
{
    Seg2Dd seg2d;
    cassert_no_null(p0);
    cassert_no_null(p1);
    seg2d.p0 = *p0;
    seg2d.p1 = *p1;
    return seg2d;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_length(const Seg2D<real> *seg)
{
    cassert_no_null(seg);
    return V2D<real>::dist(&seg->p0, &seg->p1);
}

/*---------------------------------------------------------------------------*/

real32_t seg2d_lengthf(const Seg2Df *seg)
{
    return i_length<real32_t>((const Seg2D<real32_t> *)seg);
}

/*---------------------------------------------------------------------------*/

real64_t seg2d_lengthd(const Seg2Dd *seg)
{
    return i_length<real64_t>((const Seg2D<real64_t> *)seg);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_sqlength(const Seg2D<real> *seg)
{
    cassert_no_null(seg);
    return V2D<real>::sqdist(&seg->p0, &seg->p1);
}

/*---------------------------------------------------------------------------*/

real32_t seg2d_sqlengthf(const Seg2Df *seg)
{
    return i_sqlength<real32_t>((const Seg2D<real32_t> *)seg);
}

/*---------------------------------------------------------------------------*/

real64_t seg2d_sqlengthd(const Seg2Dd *seg)
{
    return i_sqlength<real64_t>((const Seg2D<real64_t> *)seg);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_eval(const Seg2D<real> *seg, const real t)
{
    V2D<real> pt;
    cassert_no_null(seg);
    pt.x = seg->p0.x + t * (seg->p1.x - seg->p0.x);
    pt.y = seg->p0.y + t * (seg->p1.y - seg->p0.y);
    return pt;
}

/*---------------------------------------------------------------------------*/

V2Df seg2d_evalf(const Seg2Df *seg, const real32_t t)
{
    V2D<real32_t> v = i_eval<real32_t>((const Seg2D<real32_t> *)seg, t);
    V2Df vf;
    vf.x = v.x;
    vf.y = v.y;
    return vf;
}

/*---------------------------------------------------------------------------*/

V2Dd seg2d_evald(const Seg2Dd *seg, const real64_t t)
{
    V2D<real64_t> v = i_eval<real64_t>((const Seg2D<real64_t> *)seg, t);
    V2Dd vf;
    vf.x = v.x;
    vf.y = v.y;
    return vf;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_close_param(const Seg2D<real> *seg, const V2D<real> *pnt)
{
    V2D<real> dir, v;
    real dot1, dot2;
    cassert_no_null(seg);
    cassert_no_null(pnt);
    dir.x = seg->p1.x - seg->p0.x;
    dir.y = seg->p1.y - seg->p0.y;
    v.x = pnt->x - seg->p0.x;
    v.y = pnt->y - seg->p0.y;
    dot1 = V2D<real>::dot(&v, &dir);
    dot2 = V2D<real>::dot(&dir, &dir);

    if (dot2 != 0)
    {
        real p = dot1 / dot2;
        if (p < 0)
            return 0;
        else if (p > 1)
            return 1;
        else
            return p;
    }
    else
    {
        return 0;
    }
}

/*---------------------------------------------------------------------------*/

real32_t seg2d_close_paramf(const Seg2Df *seg, const V2Df *pnt)
{
    return i_close_param<real32_t>((const Seg2D<real32_t> *)seg, (const V2D<real32_t> *)pnt);
}

/*---------------------------------------------------------------------------*/

real64_t seg2d_close_paramd(const Seg2Dd *seg, const V2Dd *pnt)
{
    return i_close_param<real64_t>((const Seg2D<real64_t> *)seg, (const V2D<real64_t> *)pnt);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_point_sqdist(const Seg2D<real> *seg, const V2D<real> *pnt, real *t)
{
    real tp = i_close_param<real>(seg, pnt);
    V2D<real> pt = i_eval<real>(seg, tp);
    ptr_assign(t, tp);
    return V2D<real>::sqdist(pnt, &pt);
}

/*---------------------------------------------------------------------------*/

real32_t seg2d_point_sqdistf(const Seg2Df *seg, const V2Df *pnt, real32_t *t)
{
    return i_point_sqdist<real32_t>((const Seg2D<real32_t> *)seg, (const V2D<real32_t> *)pnt, t);
}

/*---------------------------------------------------------------------------*/

real64_t seg2d_point_sqdistd(const Seg2Dd *seg, const V2Dd *pnt, real64_t *t)
{
    return i_point_sqdist<real64_t>((const Seg2D<real64_t> *)seg, (const V2D<real64_t> *)pnt, t);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_sqdist(const Seg2D<real> *seg1, const Seg2D<real> *seg2, real *t1, real *t2)
{
    real min_sqdist = REAL32_MAX;
    real sqdist;
    real lt1 = 0, lt2 = 0, ltt = 0;
    cassert_no_null(seg1);
    cassert_no_null(seg2);
    min_sqdist = i_point_sqdist<real>(seg1, &seg2->p0, &lt1);
    lt2 = 0;

    sqdist = i_point_sqdist<real>(seg1, &seg2->p1, &ltt);
    if (sqdist < min_sqdist)
    {
        lt1 = ltt;
        lt2 = 1;
        min_sqdist = sqdist;
    }

    sqdist = i_point_sqdist<real>(seg2, &seg1->p0, &ltt);
    if (sqdist < min_sqdist)
    {
        lt1 = 0;
        lt2 = ltt;
        min_sqdist = sqdist;
    }

    sqdist = i_point_sqdist<real>(seg2, &seg1->p1, &ltt);
    if (sqdist < min_sqdist)
    {
        lt1 = 1;
        lt2 = ltt;
        min_sqdist = sqdist;
    }

    ptr_assign(t1, lt1);
    ptr_assign(t2, lt2);
    return min_sqdist;
}

/*---------------------------------------------------------------------------*/

real32_t seg2d_sqdistf(const Seg2Df *seg1, const Seg2Df *seg2, real32_t *t1, real32_t *t2)
{
    return i_sqdist<real32_t>((const Seg2D<real32_t> *)seg1, (const Seg2D<real32_t> *)seg2, t1, t2);
}

/*---------------------------------------------------------------------------*/

real64_t seg2d_sqdistd(const Seg2Dd *seg1, const Seg2Dd *seg2, real64_t *t1, real64_t *t2)
{
    return i_sqdist<real64_t>((const Seg2D<real64_t> *)seg1, (const Seg2D<real64_t> *)seg2, t1, t2);
}

/*---------------------------------------------------------------------------*/

//static void (*corners)(const Seg2D<real> *seg2d, const real thickness, V2D<real> *corners);
//
//template<typename real>
//static void i_corners(const Seg2D<real> *s, const real thickness, V2D<real> *corners)
//{
//    V2D<real> dir;
//    real pX, pY;
//    real ht = thickness / 2;
//    cassert_no_null(s);
//    cassert_no_null(corners);
//    dir = V2D<real>::unit(&s->p0, &s->p1, NULL);
//    pX = -dir.y;
//    pY = dir.x;
//    corners[0].x = s->p0.x + pX * ht;
//    corners[0].y = s->p0.y + pY * ht;
//    corners[1].x = s->p1.x + pX * ht;
//    corners[1].y = s->p1.y + pY * ht;
//    corners[2].x = s->p1.x - pX * ht;
//    corners[2].y = s->p1.y - pY * ht;
//    corners[3].x = s->p0.x - pX * ht;
//    corners[3].y = s->p0.y - pY * ht;
//}
//
///*---------------------------------------------------------------------------*/
//
//void seg2d_cornersf(const Seg2Df *seg2d, const real32_t thickness, V2Df *corners);
//
//void seg2d_cornersd(const Seg2Dd *seg2d, const real64_t thickness, V2Dd *corners);
//
//void seg2d_cornersf(const Seg2Df *seg2d, const real32_t thickness, V2Df *corners)
//{
//    i_corners<real32_t>((const Seg2D<real32_t>*)seg2d, thickness, (V2D<real32_t>*)corners);
//}
//
///*---------------------------------------------------------------------------*/
//
//void seg2d_cornersd(const Seg2Dd *seg2d, const real64_t thickness, V2Dd *corners)
//{
//    i_corners<real64_t>((const Seg2D<real64_t>*)seg2d, thickness, (V2D<real64_t>*)corners);
//}

/*---------------------------------------------------------------------------*/

//template<>
//void(*Seg2D<real32_t>::corners)(const Seg2D<real32_t>*, const real32_t, V2D<real32_t>*) = i_corners<real32_t>;
//
//template<>
//void(*Seg2D<real64_t>::corners)(const Seg2D<real64_t>*, const real64_t, V2D<real64_t>*) = i_corners<real64_t>;

template <>
real32_t (*Seg2D<real32_t>::length)(const Seg2D<real32_t> *) = i_length<real32_t>;

template <>
real64_t (*Seg2D<real64_t>::length)(const Seg2D<real64_t> *) = i_length<real64_t>;

template <>
V2D<real32_t> (*Seg2D<real32_t>::eval)(const Seg2D<real32_t> *, const real32_t) = i_eval<real32_t>;

template <>
V2D<real64_t> (*Seg2D<real64_t>::eval)(const Seg2D<real64_t> *, const real64_t) = i_eval<real64_t>;

template <>
real32_t (*Seg2D<real32_t>::close_param)(const Seg2D<real32_t> *, const V2D<real32_t> *) = i_close_param<real32_t>;

template <>
real64_t (*Seg2D<real64_t>::close_param)(const Seg2D<real64_t> *, const V2D<real64_t> *) = i_close_param<real64_t>;

template <>
real32_t (*Seg2D<real32_t>::point_sqdist)(const Seg2D<real32_t> *, const V2D<real32_t> *, real32_t *) = i_point_sqdist<real32_t>;

template <>
real64_t (*Seg2D<real64_t>::point_sqdist)(const Seg2D<real64_t> *, const V2D<real64_t> *, real64_t *) = i_point_sqdist<real64_t>;

template <>
real32_t (*Seg2D<real32_t>::sqdist)(const Seg2D<real32_t> *, const Seg2D<real32_t> *, real32_t *, real32_t *) = i_sqdist<real32_t>;

template <>
real64_t (*Seg2D<real64_t>::sqdist)(const Seg2D<real64_t> *, const Seg2D<real64_t> *, real64_t *, real64_t *) = i_sqdist<real64_t>;
