/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: v2d.cpp
 *
 */

/* Vector 2d */

#include "v2d.h"
#include "v2d.hpp"
#include <sewer/bmath.hpp>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

V2Df v2df(const real32_t x, const real32_t y)
{
    V2Df v;
    v.x = x;
    v.y = y;
    return v;
}

/*---------------------------------------------------------------------------*/

V2Dd v2dd(const real64_t x, const real64_t y)
{
    V2Dd v;
    v.x = x;
    v.y = y;
    return v;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_tof(const V2Dd *v)
{
    V2Df vf;
    cassert_no_null(v);
    vf.x = (real32_t)v->x;
    vf.y = (real32_t)v->y;
    return vf;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_tod(const V2Df *v)
{
    V2Dd vd;
    cassert_no_null(v);
    vd.x = (real64_t)v->x;
    vd.y = (real64_t)v->y;
    return vd;
}

/*---------------------------------------------------------------------------*/

void v2d_tofn(V2Df *vf, const V2Dd *vd, const uint32_t n)
{
    uint32_t i = 0;
    for (i = 0; i < n; ++i)
    {
        vf[i].x = (real32_t)vd[i].x;
        vf[i].y = (real32_t)vd[i].y;
    }
}

/*---------------------------------------------------------------------------*/

void v2d_todn(V2Dd *vd, const V2Df *vf, const uint32_t n)
{
    uint32_t i = 0;
    for (i = 0; i < n; ++i)
    {
        vd[i].x = (real64_t)vf[i].x;
        vd[i].y = (real64_t)vf[i].y;
    }
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_add(const V2D<real> *v1, const V2D<real> *v2)
{
    V2D<real> r;
    r.x = v1->x + v2->x;
    r.y = v1->y + v2->y;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_addf(const V2Df *v1, const V2Df *v2)
{
    V2Df r;
    r.x = v1->x + v2->x;
    r.y = v1->y + v2->y;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_addd(const V2Dd *v1, const V2Dd *v2)
{
    V2Dd r;
    r.x = v1->x + v2->x;
    r.y = v1->y + v2->y;
    return r;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_sub(const V2D<real> *v1, const V2D<real> *v2)
{
    V2D<real> r;
    r.x = v1->x - v2->x;
    r.y = v1->y - v2->y;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_subf(const V2Df *v1, const V2Df *v2)
{
    V2Df r;
    r.x = v1->x - v2->x;
    r.y = v1->y - v2->y;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_subd(const V2Dd *v1, const V2Dd *v2)
{
    V2Dd r;
    r.x = v1->x - v2->x;
    r.y = v1->y - v2->y;
    return r;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_mul(const V2D<real> *v, const real s)
{
    V2D<real> r;
    r.x = v->x * s;
    r.y = v->y * s;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_mulf(const V2Df *v, const real32_t s)
{
    V2Df r;
    r.x = v->x * s;
    r.y = v->y * s;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_muld(const V2Dd *v, const real64_t s)
{
    V2Dd r;
    r.x = v->x * s;
    r.y = v->y * s;
    return r;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_unit_xy(const real x1, const real y1, const real x2, const real y2, real *length)
{
    real dX, dY;
    real dot;
    V2D<real> r;
    dX = x2 - x1;
    dY = y2 - y1;
    dot = dX * dX + dY * dY;
    if (dot > 0)
    {
        dot = BMath<real>::sqrt(dot);

        if (length != NULL)
            *length = dot;

        r.x = dX / dot;
        r.y = dY / dot;
    }
    else
    {
        if (length != NULL)
            *length = 0;

        r.x = 0;
        r.y = 0;
    }

    return r;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_unit(const V2D<real> *v1, const V2D<real> *v2, real *length)
{
    cassert_no_null(v1);
    cassert_no_null(v2);
    return i_unit_xy<real>(v1->x, v1->y, v2->x, v2->y, length);
}

/*---------------------------------------------------------------------------*/

V2Df v2d_unitf(const V2Df *v1, const V2Df *v2, real32_t *length)
{
    V2D<real32_t> r = i_unit<real32_t>((const V2D<real32_t> *)v1, (const V2D<real32_t> *)v2, length);
    V2Df rr;
    rr.x = r.x;
    rr.y = r.y;
    return rr;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_unitd(const V2Dd *v1, const V2Dd *v2, real64_t *length)
{
    V2D<real64_t> r = i_unit<real64_t>((const V2D<real64_t> *)v1, (const V2D<real64_t> *)v2, length);
    V2Dd rr;
    rr.x = r.x;
    rr.y = r.y;
    return rr;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_unit_xyf(const real32_t x1, const real32_t y1, const real32_t x2, const real32_t y2, real32_t *length)
{
    V2D<real32_t> r = i_unit_xy<real32_t>(x1, y1, x2, y2, length);
    V2Df rr;
    rr.x = r.x;
    rr.y = r.y;
    return rr;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_unit_xyd(const real64_t x1, const real64_t y1, const real64_t x2, const real64_t y2, real64_t *length)
{
    V2D<real64_t> r = i_unit_xy<real64_t>(x1, y1, x2, y2, length);
    V2Dd rr;
    rr.x = r.x;
    rr.y = r.y;
    return rr;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_perp_pos(const V2D<real> *v)
{
    V2D<real> r;
    cassert_no_null(v);
    r.x = -v->y;
    r.y = v->x;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_perp_posf(const V2Df *v)
{
    V2Df r;
    cassert_no_null(v);
    r.x = -v->y;
    r.y = v->x;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_perp_posd(const V2Dd *v)
{
    V2Dd r;
    cassert_no_null(v);
    r.x = -v->y;
    r.y = v->x;
    return r;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_perp_neg(const V2D<real> *v)
{
    V2D<real> r;
    cassert_no_null(v);
    r.x = v->y;
    r.y = -v->x;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_perp_negf(const V2Df *v)
{
    V2Df r;
    cassert_no_null(v);
    r.x = v->y;
    r.y = -v->x;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_perp_negd(const V2Dd *v)
{
    V2Dd r;
    cassert_no_null(v);
    r.x = v->y;
    r.y = -v->x;
    return r;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_from_angle(const real a)
{
    V2D<real> v;
    v.x = BMath<real>::cos(a);
    v.y = BMath<real>::sin(a);
    return v;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_from_anglef(const real32_t a)
{
    V2D<real32_t> v = i_from_angle<real32_t>(a);
    V2Df *vv = (V2Df *)&v;
    return *vv;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_from_angled(const real64_t a)
{
    V2D<real64_t> v = i_from_angle<real64_t>(a);
    V2Dd *vv = (V2Dd *)&v;
    return *vv;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_from(const V2D<real> *v, const V2D<real> *dir, const real length)
{
    V2D<real> r;
    cassert_no_null(v);
    cassert_no_null(dir);
    r.x = v->x + dir->x * length;
    r.y = v->y + dir->y * length;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_fromf(const V2Df *v, const V2Df *dir, const real32_t length)
{
    V2Df r;
    cassert_no_null(v);
    cassert_no_null(dir);
    r.x = v->x + dir->x * length;
    r.y = v->y + dir->y * length;
    return r;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_fromd(const V2Dd *v, const V2Dd *dir, const real64_t length)
{
    V2Dd r;
    cassert_no_null(v);
    cassert_no_null(dir);
    r.x = v->x + dir->x * length;
    r.y = v->y + dir->y * length;
    return r;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_mid(const V2D<real> *v1, const V2D<real> *v2)
{
    V2D<real> r;
    cassert_no_null(v1);
    cassert_no_null(v2);
    r.x = (real).5 * (v1->x + v2->x);
    r.y = (real).5 * (v1->y + v2->y);
    return r;
}

/*---------------------------------------------------------------------------*/

V2Df v2d_midf(const V2Df *v1, const V2Df *v2)
{
    V2Df r;
    cassert_no_null(v1);
    cassert_no_null(v2);
    r.x = .5f * (v1->x + v2->x);
    r.y = .5f * (v1->y + v2->y);
    return r;
}

/*---------------------------------------------------------------------------*/

V2Dd v2d_midd(const V2Dd *v1, const V2Dd *v2)
{
    V2Dd r;
    cassert_no_null(v1);
    cassert_no_null(v2);
    r.x = .5 * (v1->x + v2->x);
    r.y = .5 * (v1->y + v2->y);
    return r;
}

/*---------------------------------------------------------------------------*/

/*bool_t v2d_is_normdf(const V2Df *v2d);
bool_t v2d_is_normdf(const V2Df *v2d)
{
    real32_t dotprod;
    cassert_no_null(v2d);
    dotprod = v2d->x * v2d->x + v2d->y * v2d->y;
    if (bmath_absf(dotprod - 1.f) < kTINY3f)
        return TRUE;
    else
        return FALSE;
}*/

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_norm(V2D<real> *v)
{
    register real dot_prod;
    cassert_no_null(v);
    dot_prod = v->x * v->x + v->y * v->y;
    if (dot_prod > 0)
    {
        real one_over_norm = BMath<real>::isqrt(dot_prod);
        v->x *= one_over_norm;
        v->y *= one_over_norm;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t v2d_normf(V2Df *v)
{
    return i_norm<real32_t>((V2D<real32_t> *)v);
}

/*---------------------------------------------------------------------------*/

bool_t v2d_normd(V2Dd *v)
{
    return i_norm<real64_t>((V2D<real64_t> *)v);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_length(const V2D<real> *v)
{
    real dot;
    cassert_no_null(v);
    dot = v->x * v->x + v->y * v->y;
    if (dot > 0)
        return BMath<real>::sqrt(dot);
    else
        return 0;
}

/*---------------------------------------------------------------------------*/

real32_t v2d_lengthf(const V2Df *v)
{
    return i_length<real32_t>((const V2D<real32_t> *)v);
}

/*---------------------------------------------------------------------------*/

real64_t v2d_lengthd(const V2Dd *v)
{
    return i_length<real64_t>((const V2D<real64_t> *)v);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_sqlength(const V2D<real> *v)
{
    cassert_no_null(v);
    return v->x * v->x + v->y * v->y;
}

/*---------------------------------------------------------------------------*/

real32_t v2d_sqlengthf(const V2Df *v)
{
    return i_sqlength<real32_t>((const V2D<real32_t> *)v);
}

/*---------------------------------------------------------------------------*/

real64_t v2d_sqlengthd(const V2Dd *v)
{
    return i_sqlength<real64_t>((const V2D<real64_t> *)v);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_dot(const V2D<real> *v1, const V2D<real> *v2)
{
    cassert_no_null(v1);
    cassert_no_null(v2);
    return v1->x * v2->x + v1->y * v2->y;
}

/*---------------------------------------------------------------------------*/

real32_t v2d_dotf(const V2Df *v1, const V2Df *v2)
{
    return i_dot<real32_t>((const V2D<real32_t> *)v1, (const V2D<real32_t> *)v2);
}

/*---------------------------------------------------------------------------*/

real64_t v2d_dotd(const V2Dd *v1, const V2Dd *v2)
{
    return i_dot<real64_t>((const V2D<real64_t> *)v1, (const V2D<real64_t> *)v2);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_dist(const V2D<real> *v1, const V2D<real> *v2)
{
    real dX, dY;
    real dot;
    cassert_no_null(v1);
    cassert_no_null(v2);
    dX = v2->x - v1->x;
    dY = v2->y - v1->y;
    dot = dX * dX + dY * dY;
    if (dot > 0)
        return BMath<real>::sqrt(dot);
    else
        return 0;
}

/*---------------------------------------------------------------------------*/

real32_t v2d_distf(const V2Df *v1, const V2Df *v2)
{
    return i_dist<real32_t>((const V2D<real32_t> *)v1, (const V2D<real32_t> *)v2);
}

/*---------------------------------------------------------------------------*/

real64_t v2d_distd(const V2Dd *v1, const V2Dd *v2)
{
    return i_dist<real64_t>((const V2D<real64_t> *)v1, (const V2D<real64_t> *)v2);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_sqdist(const V2D<real> *v1, const V2D<real> *v2)
{
    real dX, dY;
    cassert_no_null(v1);
    cassert_no_null(v2);
    dX = v2->x - v1->x;
    dY = v2->y - v1->y;
    return dX * dX + dY * dY;
}

/*---------------------------------------------------------------------------*/

real32_t v2d_sqdistf(const V2Df *v1, const V2Df *v2)
{
    return i_sqdist<real32_t>((const V2D<real32_t> *)v1, (const V2D<real32_t> *)v2);
}

/*---------------------------------------------------------------------------*/

real64_t v2d_sqdistd(const V2Dd *v1, const V2Dd *v2)
{
    return i_sqdist<real64_t>((const V2D<real64_t> *)v1, (const V2D<real64_t> *)v2);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_angle(const V2D<real> *v1, const V2D<real> *v2)
{
    //real d, d1, d2, l1, l2, c;
    //cassert_no_null(v1);
    //cassert_no_null(v2);
    //d = v1->x * v2->x + v1->y * v2->y;
    //d1 = v1->x * v1->x + v1->y * v1->y;
    //d2 = v2->x * v2->x + v2->y * v2->y;
    //l1 = BMath<real>::sqrt(d1);
    //l2 = BMath<real>::sqrt(d2);
    //c = d / (l1 * l2);
    //return BMath<real>::acos(c);
    // https://www.mathworks.com/matlabcentral/answers/180131-how-can-i-find-the-angle-between-two-vectors-including-directional-information
    register real y, x;
    cassert_no_null(v1);
    cassert_no_null(v2);
    y = v1->x * v2->y - v1->y * v2->x;
    x = v1->x * v2->x + v1->y * v2->y;
    return BMath<real>::atan2(y, x);
}

/*---------------------------------------------------------------------------*/

real32_t v2d_anglef(const V2Df *v1, const V2Df *v2)
{
    return i_angle<real32_t>((const V2D<real32_t> *)v1, (const V2D<real32_t> *)v2);
}

/*---------------------------------------------------------------------------*/

real64_t v2d_angled(const V2Dd *v1, const V2Dd *v2)
{
    return i_angle<real64_t>((const V2D<real64_t> *)v1, (const V2D<real64_t> *)v2);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_rotate(V2D<real> *v, const real a)
{
    V2D<real> r;
    real c, s;
    cassert_no_null(v);
    c = BMath<real>::cos(a);
    s = BMath<real>::sin(a);
    r.x = v->x * c - v->y * s;
    r.y = v->x * s + v->y * c;
    *v = r;
}

/*---------------------------------------------------------------------------*/

void v2d_rotatef(V2Df *v, const real32_t a)
{
    i_rotate<real32_t>((V2D<real32_t> *)v, a);
}

/*---------------------------------------------------------------------------*/

void v2d_rotated(V2Dd *v, const real64_t a)
{
    i_rotate<real64_t>((V2D<real64_t> *)v, a);
}

/*---------------------------------------------------------------------------*/

const V2Df kV2D_ZEROf = {0, 0};
const V2Dd kV2D_ZEROd = {0, 0};
const V2Df kV2D_Xf = {1, 0};
const V2Dd kV2D_Xd = {1, 0};
const V2Df kV2D_Yf = {0, 1};
const V2Dd kV2D_Yd = {0, 1};

template <>
const V2D<real32_t>(*V2D<real32_t>::kZERO) = ((V2D<real32_t> *)&kV2D_ZEROf);

template <>
const V2D<real64_t>(*V2D<real64_t>::kZERO) = ((V2D<real64_t> *)&kV2D_ZEROd);

template <>
const V2D<real32_t>(*V2D<real32_t>::kX) = ((V2D<real32_t> *)&kV2D_Xf);

template <>
const V2D<real64_t>(*V2D<real64_t>::kX) = ((V2D<real64_t> *)&kV2D_Xd);

template <>
const V2D<real32_t>(*V2D<real32_t>::kY) = ((V2D<real32_t> *)&kV2D_Yf);

template <>
const V2D<real64_t>(*V2D<real64_t>::kY) = ((V2D<real64_t> *)&kV2D_Yd);

/*---------------------------------------------------------------------------*/

template <>
V2D<real32_t> (*V2D<real32_t>::add)(const V2D<real32_t> *, const V2D<real32_t> *) = i_add<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::add)(const V2D<real64_t> *, const V2D<real64_t> *) = i_add<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::sub)(const V2D<real32_t> *, const V2D<real32_t> *) = i_sub<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::sub)(const V2D<real64_t> *, const V2D<real64_t> *) = i_sub<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::mul)(const V2D<real32_t> *, const real32_t) = i_mul<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::mul)(const V2D<real64_t> *, const real64_t) = i_mul<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::from)(const V2D<real32_t> *, const V2D<real32_t> *, const real32_t) = i_from<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::from)(const V2D<real64_t> *, const V2D<real64_t> *, const real64_t) = i_from<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::mid)(const V2D<real32_t> *, const V2D<real32_t> *) = i_mid<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::mid)(const V2D<real64_t> *, const V2D<real64_t> *) = i_mid<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::unit)(const V2D<real32_t> *, const V2D<real32_t> *, real32_t *) = i_unit<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::unit)(const V2D<real64_t> *, const V2D<real64_t> *, real64_t *) = i_unit<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::unit_xy)(const real32_t, const real32_t, const real32_t, const real32_t, real32_t *) = i_unit_xy<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::unit_xy)(const real64_t, const real64_t, const real64_t, const real64_t, real64_t *) = i_unit_xy<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::perp_pos)(const V2D<real32_t> *) = i_perp_pos<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::perp_pos)(const V2D<real64_t> *) = i_perp_pos<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::perp_neg)(const V2D<real32_t> *) = i_perp_neg<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::perp_neg)(const V2D<real64_t> *) = i_perp_neg<real64_t>;

template <>
V2D<real32_t> (*V2D<real32_t>::from_angle)(const real32_t) = i_from_angle<real32_t>;

template <>
V2D<real64_t> (*V2D<real64_t>::from_angle)(const real64_t) = i_from_angle<real64_t>;

template <>
bool_t (*V2D<real32_t>::norm)(V2D<real32_t> *) = i_norm<real32_t>;

template <>
bool_t (*V2D<real64_t>::norm)(V2D<real64_t> *) = i_norm<real64_t>;

template <>
real32_t (*V2D<real32_t>::length)(const V2D<real32_t> *) = i_length<real32_t>;

template <>
real64_t (*V2D<real64_t>::length)(const V2D<real64_t> *) = i_length<real64_t>;

template <>
real32_t (*V2D<real32_t>::sqlength)(const V2D<real32_t> *) = i_sqlength<real32_t>;

template <>
real64_t (*V2D<real64_t>::sqlength)(const V2D<real64_t> *) = i_sqlength<real64_t>;

template <>
real32_t (*V2D<real32_t>::dot)(const V2D<real32_t> *, const V2D<real32_t> *) = i_dot<real32_t>;

template <>
real64_t (*V2D<real64_t>::dot)(const V2D<real64_t> *, const V2D<real64_t> *) = i_dot<real64_t>;

template <>
real32_t (*V2D<real32_t>::dist)(const V2D<real32_t> *, const V2D<real32_t> *) = i_dist<real32_t>;

template <>
real64_t (*V2D<real64_t>::dist)(const V2D<real64_t> *, const V2D<real64_t> *) = i_dist<real64_t>;

template <>
real32_t (*V2D<real32_t>::sqdist)(const V2D<real32_t> *, const V2D<real32_t> *) = i_sqdist<real32_t>;

template <>
real64_t (*V2D<real64_t>::sqdist)(const V2D<real64_t> *, const V2D<real64_t> *) = i_sqdist<real64_t>;

template <>
real32_t (*V2D<real32_t>::angle)(const V2D<real32_t> *, const V2D<real32_t> *) = i_angle<real32_t>;

template <>
real64_t (*V2D<real64_t>::angle)(const V2D<real64_t> *, const V2D<real64_t> *) = i_angle<real64_t>;

template <>
void (*V2D<real32_t>::rotate)(V2D<real32_t> *, const real32_t) = i_rotate<real32_t>;

template <>
void (*V2D<real64_t>::rotate)(V2D<real64_t> *, const real64_t) = i_rotate<real64_t>;
