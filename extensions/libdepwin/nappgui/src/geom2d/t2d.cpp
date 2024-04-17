/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: t2d.cpp
 *
 */

/* 2D affine transformations */

#include "t2d.h"
#include "t2d.hpp"
#include <sewer/bmath.hpp>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void t2d_tof(T2Df *dest, const T2Dd *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    dest->i.x = (real32_t)src->i.x;
    dest->i.y = (real32_t)src->i.y;
    dest->j.x = (real32_t)src->j.x;
    dest->j.y = (real32_t)src->j.y;
    dest->p.x = (real32_t)src->p.x;
    dest->p.y = (real32_t)src->p.y;
}

/*---------------------------------------------------------------------------*/

void t2d_tod(T2Dd *dest, const T2Df *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    dest->i.x = src->i.x;
    dest->i.y = src->i.y;
    dest->j.x = src->j.x;
    dest->j.y = src->j.y;
    dest->p.x = src->p.x;
    dest->p.y = src->p.y;
}

///*---------------------------------------------------------------------------*/
//
//template<typename real>
//static void i_init_move(T2D<real> *dest, const real x, const real y)
//{
//    cassert_no_null(dest);
//    dest->i.x = 1;
//    dest->i.y = 0;
//    dest->j.x = 0;
//    dest->j.y = 1;
//    dest->p.x = x;
//    dest->p.y = y;
//}
//
///*---------------------------------------------------------------------------*/
//
//void t2d_init_movef(T2Df *dest, const real32_t x, const real32_t y)
//{
//    i_init_move<real32_t>((T2D<real32_t>*)dest, x, y);
//}
//
///*---------------------------------------------------------------------------*/
//
//void t2d_init_moved(T2Dd *dest, const real64_t x, const real64_t y)
//{
//    i_init_move<real64_t>((T2D<real64_t>*)dest, x, y);
//}
//
///*---------------------------------------------------------------------------*/
//
//template<typename real>
//static void i_init_rotate(T2D<real> *dest, const real angle)
//{
//    real c, s;
//    cassert_no_null(dest);
//    c = BMath<real>::cos(angle);
//    s = BMath<real>::sin(angle);
//    dest->i.x = c;
//    dest->i.y = s;
//    dest->j.x = -s;
//    dest->j.y = c;
//    dest->p.x = 0;
//    dest->p.y = 0;
//}
//
///*---------------------------------------------------------------------------*/
//
//void t2d_init_rotatef(T2Df *dest, const real32_t angle)
//{
//    i_init_rotate<real32_t>((T2D<real32_t>*)dest, angle);
//}
//
///*---------------------------------------------------------------------------*/
//
//void t2d_init_rotated(T2Dd *dest, const real64_t angle)
//{
//    i_init_rotate<real64_t>((T2D<real64_t>*)dest, angle);
//}
//
///*---------------------------------------------------------------------------*/
//
//template<typename real>
//static void i_init_scale(T2D<real> *dest, const real sx, const real sy)
//{
//    cassert_no_null(dest);
//    dest->i.x = sx;
//    dest->i.y = 0;
//    dest->j.x = 0;
//    dest->j.y = sy;
//    dest->p.x = 0;
//    dest->p.y = 0;
//}
//
///*---------------------------------------------------------------------------*/
//
//void t2d_init_scalef(T2Df *dest, const real32_t sx, const real32_t sy)
//{
//    i_init_scale<real32_t>((T2D<real32_t>*)dest, sx, sy);
//}
//
///*---------------------------------------------------------------------------*/
//
//void t2d_init_scaled(T2Dd *dest, const real64_t sx, const real64_t sy)
//{
//    i_init_scale<real64_t>((T2D<real64_t>*)dest, sx, sy);
//}
//
///*---------------------------------------------------------------------------*/
//
//template<typename real>
//static void i_init_move_scale(T2D<real> *dest, const real x, const real y, const real sx, const real sy)
//{
//    cassert_no_null(dest);
//    dest->i.x = sx;
//    dest->i.y = 0;
//    dest->j.x = 0;
//    dest->j.y = sy;
//    dest->p.x = x;
//    dest->p.y = y;
//}
//
///*---------------------------------------------------------------------------*/
//
//void t2d_init_move_scalef(T2Df *dest, const real32_t x, const real32_t y, const real32_t sx, const real32_t sy)
//{
//    i_init_move_scale<real32_t>((T2D<real32_t>*)dest, x, y, sx, sy);
//}
//
///*---------------------------------------------------------------------------*/
//
//void t2d_init_move_scaled(T2Dd *dest, const real64_t x, const real64_t y, const real64_t sx, const real64_t sy)
//{
//    i_init_move_scale<real64_t>((T2D<real64_t>*)dest, x, y, sx, sy);
//}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_move(T2D<real> *dest, const T2D<real> *src, const real x, const real y)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    if (dest != src)
        *dest = *src;
    dest->p.x += src->i.x * x + src->j.x * y;
    dest->p.y += src->i.y * x + src->j.y * y;
}

/*---------------------------------------------------------------------------*/

void t2d_movef(T2Df *dest, const T2Df *t2d, const real32_t x, const real32_t y)
{
    i_move<real32_t>((T2D<real32_t> *)dest, (const T2D<real32_t> *)t2d, x, y);
}

/*---------------------------------------------------------------------------*/

void t2d_moved(T2Dd *dest, const T2Dd *t2d, const real64_t x, const real64_t y)
{
    i_move<real64_t>((T2D<real64_t> *)dest, (const T2D<real64_t> *)t2d, x, y);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_rotate(T2D<real> *dest, const T2D<real> *t2d, const real angle)
{
    real c, s;
    real ix, iy, jx, jy;
    cassert_no_null(dest);
    cassert_no_null(t2d);
    c = BMath<real>::cos(angle);
    s = BMath<real>::sin(angle);
    ix = t2d->i.x * c + t2d->j.x * s;
    iy = t2d->i.y * c + t2d->j.y * s;
    jx = -t2d->i.x * s + t2d->j.x * c;
    jy = -t2d->i.y * s + t2d->j.y * c;
    dest->i.x = ix;
    dest->i.y = iy;
    dest->j.x = jx;
    dest->j.y = jy;
    dest->p.x = t2d->p.x;
    dest->p.y = t2d->p.y;
}

/*---------------------------------------------------------------------------*/

void t2d_rotatef(T2Df *dest, const T2Df *t2d, const real32_t angle)
{
    i_rotate<real32_t>((T2D<real32_t> *)dest, (const T2D<real32_t> *)t2d, angle);
}

/*---------------------------------------------------------------------------*/

void t2d_rotated(T2Dd *dest, const T2Dd *t2d, const real64_t angle)
{
    i_rotate<real64_t>((T2D<real64_t> *)dest, (const T2D<real64_t> *)t2d, angle);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_scale(T2D<real> *dest, const T2D<real> *t2d, const real sx, const real sy)
{
    cassert_no_null(dest);
    cassert_no_null(t2d);
    if (dest != t2d)
        *dest = *t2d;
    dest->i.x *= sx;
    dest->i.y *= sx;
    dest->j.x *= sy;
    dest->j.y *= sy;
}

/*---------------------------------------------------------------------------*/

void t2d_scalef(T2Df *dest, const T2Df *t2d, const real32_t sx, const real32_t sy)
{
    i_scale<real32_t>((T2D<real32_t> *)dest, (const T2D<real32_t> *)t2d, sx, sy);
}

/*---------------------------------------------------------------------------*/

void t2d_scaled(T2Dd *dest, const T2Dd *t2d, const real64_t sx, const real64_t sy)
{
    i_scale<real64_t>((T2D<real64_t> *)dest, (const T2D<real64_t> *)t2d, sx, sy);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_inverse(T2D<real> *dest, const T2D<real> *src)
{
    V2D<real> i, j, p;
    real det = 0;
    cassert_no_null(dest);
    cassert_no_null(src);
    det = (src->i.x * src->j.y) - (src->j.x * src->i.y);
    cassert(det != 0);
    i.x = src->j.y / det;
    i.y = -src->i.y / det;
    j.x = -src->j.x / det;
    j.y = src->i.x / det;
    p = src->p;
    dest->p.x = -(i.x * p.x + j.x * p.y);
    dest->p.y = -(i.y * p.x + j.y * p.y);
    dest->i = i;
    dest->j = j;
}

/*---------------------------------------------------------------------------*/

void t2d_inversef(T2Df *dest, const T2Df *src)
{
    i_inverse<real32_t>((T2D<real32_t> *)dest, (const T2D<real32_t> *)src);
}

/*---------------------------------------------------------------------------*/

void t2d_inversed(T2Dd *dest, const T2Dd *src)
{
    i_inverse<real64_t>((T2D<real64_t> *)dest, (const T2D<real64_t> *)src);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_invfast(T2D<real> *dest, const T2D<real> *src)
{
    V2D<real> i, j, p;
    cassert_no_null(dest);
    cassert_no_null(src);
    i.x = src->i.x;
    i.y = src->j.x;
    j.x = src->i.y;
    j.y = src->j.y;
    p = src->p;
    dest->p.x = -(i.x * p.x + j.x * p.y);
    dest->p.y = -(i.y * p.x + j.y * p.y);
    dest->i = i;
    dest->j = j;
}

/*---------------------------------------------------------------------------*/

void t2d_invfastf(T2Df *dest, const T2Df *src)
{
    i_invfast<real32_t>((T2D<real32_t> *)dest, (const T2D<real32_t> *)src);
}

/*---------------------------------------------------------------------------*/

void t2d_invfastd(T2Dd *dest, const T2Dd *src)
{
    i_invfast<real64_t>((T2D<real64_t> *)dest, (const T2D<real64_t> *)src);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_mult(T2D<real> *dest, const T2D<real> *t2d, const T2D<real> *src)
{
    real ix, iy, jx, jy, px, py;
    cassert_no_null(dest);
    cassert_no_null(t2d);
    cassert_no_null(src);
    ix = t2d->i.x * src->i.x + t2d->j.x * src->i.y;
    iy = t2d->i.y * src->i.x + t2d->j.y * src->i.y;
    jx = t2d->i.x * src->j.x + t2d->j.x * src->j.y;
    jy = t2d->i.y * src->j.x + t2d->j.y * src->j.y;
    px = t2d->i.x * src->p.x + t2d->j.x * src->p.y + t2d->p.x;
    py = t2d->i.y * src->p.x + t2d->j.y * src->p.y + t2d->p.y;
    dest->i.x = ix;
    dest->i.y = iy;
    dest->j.x = jx;
    dest->j.y = jy;
    dest->p.x = px;
    dest->p.y = py;
}

/*---------------------------------------------------------------------------*/

void t2d_multf(T2Df *dest, const T2Df *t2d, const T2Df *src)
{
    i_mult<real32_t>((T2D<real32_t> *)dest, (const T2D<real32_t> *)t2d, (const T2D<real32_t> *)src);
}

/*---------------------------------------------------------------------------*/

void t2d_multd(T2Dd *dest, const T2Dd *t2d, const T2Dd *src)
{
    i_mult<real64_t>((T2D<real64_t> *)dest, (const T2D<real64_t> *)t2d, (const T2D<real64_t> *)src);
}

/*---------------------------------------------------------------------------*/

//void at2d_rot_with_centerf(AT2Df *t2d, const real32_t cos_a, const real32_t sin_a, const V2Df *center);
//void at2d_rot_with_centerf(AT2Df *affine, const real32_t cos_a, const real32_t sin_a, const V2Df *center)
//{
//    cassert_no_null(affine);
//    cassert_no_null(center);
//    affine->lt2d.i.x = cos_a;
//    affine->lt2d.i.y = sin_a;
//    affine->lt2d.j.x = - sin_a;
//    affine->lt2d.j.y = cos_a;
//    affine->pos.x = - center->x * cos_a + center->y * sin_a + center->x;
//    affine->pos.y = - center->x * sin_a - center->y * cos_a + center->y;
//}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_vmult(V2D<real> *dest, const T2D<real> *t2d, const V2D<real> *src)
{
    real x, y;
    cassert_no_null(dest);
    cassert_no_null(t2d);
    cassert_no_null(src);
    x = t2d->i.x * src->x + t2d->j.x * src->y + t2d->p.x;
    y = t2d->i.y * src->x + t2d->j.y * src->y + t2d->p.y;
    dest->x = x;
    dest->y = y;
}

/*---------------------------------------------------------------------------*/

void t2d_vmultf(V2Df *dest, const T2Df *t2d, const V2Df *src)
{
    i_vmult<real32_t>((V2D<real32_t> *)dest, (const T2D<real32_t> *)t2d, (const V2D<real32_t> *)src);
}

/*---------------------------------------------------------------------------*/

void t2d_vmultd(V2Dd *dest, const T2Dd *t2d, const V2Dd *src)
{
    i_vmult<real64_t>((V2D<real64_t> *)dest, (T2D<real64_t> *)t2d, (const V2D<real64_t> *)src);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_vmultn(V2D<real> *dest, const T2D<real> *t2d, const V2D<real> *src, const uint32_t n)
{
    cassert_no_null(dest);
    cassert_no_null(t2d);
    cassert_no_null(src);
    if (dest != src)
    {
        for (uint32_t i = 0; i < n; ++i, ++dest, ++src)
        {
            dest->x = t2d->i.x * src->x + t2d->j.x * src->y + t2d->p.x;
            dest->y = t2d->i.y * src->x + t2d->j.y * src->y + t2d->p.y;
        }
    }
    else
    {
        real x, y;
        for (uint32_t i = 0; i < n; ++i, ++dest, ++src)
        {
            x = t2d->i.x * src->x + t2d->j.x * src->y + t2d->p.x;
            y = t2d->i.y * src->x + t2d->j.y * src->y + t2d->p.y;
            dest->x = x;
            dest->y = y;
        }
    }
}

/*---------------------------------------------------------------------------*/

void t2d_vmultnf(V2Df *dest, const T2Df *t2d, const V2Df *src, const uint32_t n)
{
    i_vmultn<real32_t>((V2D<real32_t> *)dest, (const T2D<real32_t> *)t2d, (const V2D<real32_t> *)src, n);
}

/*---------------------------------------------------------------------------*/

void t2d_vmultnd(V2Dd *dest, const T2Dd *t2d, const V2Dd *src, const uint32_t n)
{
    i_vmultn<real64_t>((V2D<real64_t> *)dest, (T2D<real64_t> *)t2d, (const V2D<real64_t> *)src, n);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_decompose(const T2D<real> *t2d, V2D<real> *pos, real *angle, V2D<real> *sc)
{
    real a = 0;

    cassert_no_null(t2d);
    a = V2D<real>::angle(V2D<real>::kX, &t2d->i);

    if (sc != NULL)
    {
        const real hpi = BMath<real>::kPI / 2;
        if (BMath<real>::abs(a - hpi) < .0001)
        {
            a = hpi;
            sc->x = t2d->i.y;
            sc->y = -t2d->j.x;
        }
        else if (BMath<real>::abs(a + hpi) < .0001)
        {
            a = -hpi;
            sc->x = -t2d->i.y;
            sc->y = t2d->j.x;
        }
        else
        {
            real ca = BMath<real>::cos(a);
            sc->x = t2d->i.x / ca;
            sc->y = t2d->j.y / ca;
        }
    }

    if (pos != NULL)
        *pos = t2d->p;

    if (angle != NULL)
        *angle = a;
}

//T2Df t, inv, inv2, t2;
//V2Df v = v2df(14.14f, 0);
//V2Df vr;
//V2Df fv, fs, fv2, fs2;
//real32_t fa, fa2,fd;
//t2d_rotatef(&t, kT2D_IDENTf, kBMATH_PIf / 4);
//t2d_movef(&t, &t, 11, 0);
//t2d_movef(&t, &t, 10, - 10);
//t2d_rotatef(&t, &t, - kBMATH_PIf / 2);
//t2d_scalef(&t, &t, 1.5f, 1);
//
//t2d_decomposef(&t, &fv, &fa, &fs);
//fd = fa * kBMATH_RAD2DEGf;
//t2d_inversef(&inv, &t);
//t2d_decomposef(&inv, &fv2, &fa2, &fs2);
//
//t2d_multf(&t2, &t, &inv);
//
//t2d_scalef(&t, &t, 1/ fs.x, 1/fs.y);
//t2d_rotatef(&t, &t, - fa);
//t2d_movef(&t, &t, -fv.x, -fv.y);
////t2d_invfastf(&inv2, &t);
//t2d_vmultf(&vr, &inv, &v);

/*---------------------------------------------------------------------------*/

void t2d_decomposef(const T2Df *t2d, V2Df *pos, real32_t *angle, V2Df *sc)
{
    i_decompose<real32_t>((const T2D<real32_t> *)t2d, (V2D<real32_t> *)pos, angle, (V2D<real32_t> *)sc);
}

/*---------------------------------------------------------------------------*/

void t2d_decomposed(const T2Dd *t2d, V2Dd *pos, real64_t *angle, V2Dd *sc)
{
    i_decompose<real64_t>((const T2D<real64_t> *)t2d, (V2D<real64_t> *)pos, angle, (V2D<real64_t> *)sc);
}

/*---------------------------------------------------------------------------*/

static const T2Df i_kT2D_IDENTf = {{1, 0}, {0, 1}, {0, 0}};
static const T2Dd i_kT2D_IDENTd = {{1, 0}, {0, 1}, {0, 0}};

const T2Df *kT2D_IDENTf = &i_kT2D_IDENTf;
const T2Dd *kT2D_IDENTd = &i_kT2D_IDENTd;

template <>
const T2D<real32_t>(*T2D<real32_t>::kIDENT) = (T2D<real32_t> *)kT2D_IDENTf;

template <>
const T2D<real64_t>(*T2D<real64_t>::kIDENT) = (T2D<real64_t> *)kT2D_IDENTd;

/*---------------------------------------------------------------------------*/

//static void (*init_move)(T2D<real> *dest, const real x, const real y);

//static void (*init_rotate)(T2D<real> *dest, const real angle);

//static void (*init_scale)(T2D<real> *dest, const real sx, const real sy);

//static void (*init_move_scale)(T2D<real> *dest, const real x, const real y, const real sx, const real sy);

//template<>
//void(*T2D<real32_t>::init_move)(T2D<real32_t>*, const real32_t, const real32_t) = i_init_move<real32_t>;
//
//template<>
//void(*T2D<real64_t>::init_move)(T2D<real64_t>*, const real64_t, const real64_t) = i_init_move<real64_t>;
//
//template<>
//void(*T2D<real32_t>::init_rotate)(T2D<real32_t>*, const real32_t) = i_init_rotate<real32_t>;
//
//template<>
//void(*T2D<real64_t>::init_rotate)(T2D<real64_t>*, const real64_t) = i_init_rotate<real64_t>;
//
//template<>
//void(*T2D<real32_t>::init_scale)(T2D<real32_t>*, const real32_t, const real32_t) = i_init_scale<real32_t>;
//
//template<>
//void(*T2D<real64_t>::init_scale)(T2D<real64_t>*, const real64_t, const real64_t) = i_init_scale<real64_t>;
//
//template<>
//void(*T2D<real32_t>::init_move_scale)(T2D<real32_t>*, const real32_t, const real32_t, const real32_t, const real32_t) = i_init_move_scale<real32_t>;
//
//template<>
//void(*T2D<real64_t>::init_move_scale)(T2D<real64_t>*, const real64_t, const real64_t, const real64_t, const real64_t) = i_init_move_scale<real64_t>;

template <>
void (*T2D<real32_t>::move)(T2D<real32_t> *, const T2D<real32_t> *, const real32_t, const real32_t) = i_move<real32_t>;

template <>
void (*T2D<real64_t>::move)(T2D<real64_t> *, const T2D<real64_t> *, const real64_t, const real64_t) = i_move<real64_t>;

template <>
void (*T2D<real32_t>::rotate)(T2D<real32_t> *, const T2D<real32_t> *, const real32_t) = i_rotate<real32_t>;

template <>
void (*T2D<real64_t>::rotate)(T2D<real64_t> *, const T2D<real64_t> *, const real64_t) = i_rotate<real64_t>;

template <>
void (*T2D<real32_t>::scale)(T2D<real32_t> *, const T2D<real32_t> *, const real32_t, const real32_t) = i_scale<real32_t>;

template <>
void (*T2D<real64_t>::scale)(T2D<real64_t> *, const T2D<real64_t> *, const real64_t, const real64_t) = i_scale<real64_t>;

template <>
void (*T2D<real32_t>::invfast)(T2D<real32_t> *, const T2D<real32_t> *) = i_invfast<real32_t>;

template <>
void (*T2D<real64_t>::invfast)(T2D<real64_t> *, const T2D<real64_t> *) = i_invfast<real64_t>;

template <>
void (*T2D<real32_t>::inverse)(T2D<real32_t> *, const T2D<real32_t> *) = i_inverse<real32_t>;

template <>
void (*T2D<real64_t>::inverse)(T2D<real64_t> *, const T2D<real64_t> *) = i_inverse<real64_t>;

template <>
void (*T2D<real32_t>::mult)(T2D<real32_t> *, const T2D<real32_t> *, const T2D<real32_t> *) = i_mult<real32_t>;

template <>
void (*T2D<real64_t>::mult)(T2D<real64_t> *, const T2D<real64_t> *, const T2D<real64_t> *) = i_mult<real64_t>;

template <>
void (*T2D<real32_t>::vmult)(V2D<real32_t> *, const T2D<real32_t> *, const V2D<real32_t> *) = i_vmult<real32_t>;

template <>
void (*T2D<real64_t>::vmult)(V2D<real64_t> *, const T2D<real64_t> *, const V2D<real64_t> *) = i_vmult<real64_t>;

template <>
void (*T2D<real32_t>::vmultn)(V2D<real32_t> *, const T2D<real32_t> *, const V2D<real32_t> *, const uint32_t) = i_vmultn<real32_t>;

template <>
void (*T2D<real64_t>::vmultn)(V2D<real64_t> *, const T2D<real64_t> *, const V2D<real64_t> *, const uint32_t) = i_vmultn<real64_t>;

template <>
void (*T2D<real32_t>::decompose)(const T2D<real32_t> *, V2D<real32_t> *, real32_t *, V2D<real32_t> *) = i_decompose<real32_t>;

template <>
void (*T2D<real64_t>::decompose)(const T2D<real64_t> *, V2D<real64_t> *, real64_t *, V2D<real64_t> *) = i_decompose<real64_t>;
