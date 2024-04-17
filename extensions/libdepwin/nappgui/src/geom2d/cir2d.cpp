/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: cir2d.cpp
 *
 */

/* Circle 2d */

#include "cir2d.h"
#include "cir2d.hpp"
#include <core/heap.h>
#include <sewer/bmath.hpp>
#include <sewer/bmem.h>
#include <sewer/cassert.h>

// Indices of points that support current minimum area circle
struct Support
{
    uint32_t n;
    uint32_t index[3];
};

/*---------------------------------------------------------------------------*/

Cir2Df cir2df(const real32_t x, const real32_t y, const real32_t r)
{
    Cir2Df c;
    cassert(r >= 0);
    c.c.x = x;
    c.c.y = y;
    c.r = r;
    return c;
}

/*---------------------------------------------------------------------------*/

Cir2Dd cir2dd(const real64_t x, const real64_t y, const real64_t r)
{
    Cir2Dd c;
    cassert(r >= 0);
    c.c.x = x;
    c.c.y = y;
    c.r = r;
    return c;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Cir2D<real> i_from_box(const Box2D<real> *box)
{
    Cir2D<real> cir;
    V2D<real> d;
    cir.c = Box2D<real>::center(box);
    d.x = (box->max.x - box->min.x) / 2;
    d.y = (box->max.y - box->min.y) / 2;
    cir.r = V2D<real>::length(&d);
    return cir;
}

/*---------------------------------------------------------------------------*/

Cir2Df cir2d_from_boxf(const Box2Df *box)
{
    Cir2D<real32_t> c = i_from_box<real32_t>((const Box2D<real32_t> *)box);
    Cir2Df *cc = (Cir2Df *)&c;
    return *cc;
}

/*---------------------------------------------------------------------------*/

Cir2Dd cir2d_from_boxd(const Box2Dd *box)
{
    Cir2D<real64_t> c = i_from_box<real64_t>((const Box2D<real64_t> *)box);
    Cir2Dd *cc = (Cir2Dd *)&c;
    return *cc;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Cir2D<real> i_from_points(const V2D<real> *p, const uint32_t n)
{
    Cir2D<real> cir = Cir2D<real>(0, 0, 0);
    uint32_t i;
    cassert_no_null(p);
    cassert(n > 0);

    for (i = 0; i < n; ++i)
    {
        cir.c.x += p[i].x;
        cir.c.y += p[i].y;
    }

    cir.c.x /= n;
    cir.c.y /= n;
    for (i = 0; i < n; ++i)
    {
        real sqdist = V2D<real>::sqdist(&p[i], &cir.c);
        if (sqdist > cir.r)
            cir.r = sqdist;
    }

    cir.r = BMath<real>::sqrt(cir.r);
    return cir;
}

/*---------------------------------------------------------------------------*/

Cir2Df cir2d_from_pointsf(const V2Df *p, const uint32_t n)
{
    Cir2D<real32_t> c = i_from_points((const V2D<real32_t> *)p, n);
    Cir2Df *cc = (Cir2Df *)&c;
    return *cc;
}

/*---------------------------------------------------------------------------*/

Cir2Dd cir2d_from_pointsd(const V2Dd *p, const uint32_t n)
{
    Cir2D<real64_t> c = i_from_points((const V2D<real64_t> *)p, n);
    Cir2Dd *cc = (Cir2Dd *)&c;
    return *cc;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_support(const Support *support, const uint32_t idx, const V2D<real> **p)
{
    uint32_t i = 0;
    cassert_no_null(support);
    cassert(support->n <= 3);
    for (i = 0; i < support->n; ++i)
    {
        if (V2D<real>::sqdist(p[idx], p[support->index[i]]) < (real).000001)
            return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static __INLINE bool_t i_point_in_circle(const Cir2D<real> *cir, const V2D<real> *p)
{
    real sqdist = V2D<real>::sqdist(p, &cir->c);
    return sqdist <= cir->r ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Cir2D<real> i_exact_circle1(const V2D<real> *p)
{
    Cir2D<real> min;
    cassert_no_null(p);
    min.c = *p;
    min.r = 0;
    return min;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Cir2D<real> i_exact_circle2(const V2D<real> *p0, const V2D<real> *p1)
{
    Cir2D<real> min;
    cassert_no_null(p0);
    cassert_no_null(p1);
    min.c.x = (real).5 * (p0->x + p1->x);
    min.c.y = (real).5 * (p0->y + p1->y);
    min.r = (real).25 * V2D<real>::sqdist(p1, p0);
    return min;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Cir2D<real> i_exact_circle3(const V2D<real> *p0, const V2D<real> *p1, const V2D<real> *p2)
{
    V2D<real> e10 = V2D<real>::sub(p1, p0);
    V2D<real> e20 = V2D<real>::sub(p2, p0);
    real aafA[2][2];
    real afB[2];
    Cir2D<real> min;
    real det;

    aafA[0][0] = e10.x;
    aafA[0][1] = e10.y;
    aafA[1][0] = e20.x;
    aafA[1][1] = e20.y;

    afB[0] = (real)0.5 * V2D<real>::sqlength(&e10);
    afB[1] = (real)0.5 * V2D<real>::sqlength(&e20);

    det = aafA[0][0] * aafA[1][1] - aafA[0][1] * aafA[1][0];

    if (BMath<real>::abs(det) > (real).000001)
    {
        real idet = 1 / det;
        V2D<real> q;
        q.x = (aafA[1][1] * afB[0] - aafA[0][1] * afB[1]) * idet;
        q.y = (aafA[0][0] * afB[1] - aafA[1][0] * afB[0]) * idet;
        min.c = V2D<real>::add(p0, &q);
        min.r = V2D<real>::sqlength(&q);
    }
    else
    {
        min.c = *V2D<real>::kZERO;
        min.r = BMath<real>::kINFINITY;
    }

    return min;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Cir2D<real> i_update_support1(uint32_t i, const V2D<real> **p, Support *support)
{
    const V2D<real> *p0 = p[support->index[0]];
    const V2D<real> *p1 = p[i];
    Cir2D<real> min = i_exact_circle2<real>(p0, p1);
    cassert_no_null(support);
    support->n = 2;
    support->index[i] = i;
    return min;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Cir2D<real> i_update_support2(uint32_t i, const V2D<real> **p, Support *support)
{
    const V2D<real> *p0 = p[support->index[0]];
    const V2D<real> *p1 = p[support->index[1]];
    const V2D<real> *p2 = p[i];
    Cir2D<real> akC[2];
    Cir2D<real> min;
    real min_sqlen = BMath<real>::kINFINITY;
    uint32_t idx = UINT32_MAX;

    cassert_no_null(support);
    akC[0] = i_exact_circle2<real>(p0, p2);
    if (i_point_in_circle<real>(&akC[0], p1) == TRUE)
    {
        min_sqlen = akC[0].r;
        idx = 0;
    }

    akC[1] = i_exact_circle2<real>(p1, p2);
    if (i_point_in_circle<real>(&akC[1], p0) == TRUE)
    {
        if (akC[1].r < min_sqlen)
        {
            min_sqlen = akC[1].r;
            idx = 1;
        }
    }

    if (idx != UINT32_MAX)
    {
        cassert(idx <= 1);
        min = akC[idx];
        support->index[1 - idx] = i;
    }
    else
    {
        min = i_exact_circle3<real>(p0, p1, p2);
        cassert(min.r <= min_sqlen);
        support->n = 3;
        support->index[2] = i;
    }

    return min;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Cir2D<real> i_update_support3(uint32_t i, const V2D<real> **p, Support *support)
{
    const V2D<real> *p0 = p[support->index[0]];
    const V2D<real> *p1 = p[support->index[1]];
    const V2D<real> *p2 = p[support->index[2]];
    const V2D<real> *p3 = p[i];
    Cir2D<real> akC[6];
    Cir2D<real> min;
    real min_sqlen = BMath<real>::kINFINITY;
    uint32_t idx = UINT32_MAX;

    akC[0] = i_exact_circle2<real>(p0, p3);
    if (i_point_in_circle<real>(&akC[0], p1) == TRUE && i_point_in_circle<real>(&akC[0], p2) == TRUE)
    {
        min_sqlen = akC[0].r;
        idx = 0;
    }

    akC[1] = i_exact_circle2<real>(p1, p3);
    if (i_point_in_circle<real>(&akC[1], p0) == TRUE && i_point_in_circle<real>(&akC[1], p2) == TRUE)
    {
        if (akC[1].r < min_sqlen)
        {
            min_sqlen = akC[1].r;
            idx = 1;
        }
    }

    akC[2] = i_exact_circle2<real>(p2, p3);
    if (i_point_in_circle<real>(&akC[2], p0) == TRUE && i_point_in_circle<real>(&akC[2], p1) == TRUE)
    {
        if (akC[2].r < min_sqlen)
        {
            min_sqlen = akC[2].r;
            idx = 2;
        }
    }

    akC[3] = i_exact_circle3<real>(p0, p1, p3);
    if (i_point_in_circle<real>(&akC[3], p2) == TRUE)
    {
        if (akC[3].r < min_sqlen)
        {
            min_sqlen = akC[3].r;
            idx = 3;
        }
    }

    akC[4] = i_exact_circle3<real>(p0, p2, p3);
    if (i_point_in_circle<real>(&akC[4], p1) == TRUE)
    {
        if (akC[4].r < min_sqlen)
        {
            min_sqlen = akC[4].r;
            idx = 4;
        }
    }

    akC[5] = i_exact_circle3<real>(p1, p2, p3);
    if (i_point_in_circle<real>(&akC[5], p0) == TRUE)
    {
        if (akC[5].r < min_sqlen)
        {
            min_sqlen = akC[5].r;
            idx = 5;
        }
    }

    cassert(idx != UINT32_MAX);
    min = akC[idx];

    switch (idx)
    {
    case 0:
        support->n = 2;
        support->index[1] = i;
        break;

    case 1:
        support->n = 2;
        support->index[0] = i;
        break;

    case 2:
        support->n = 2;
        support->index[0] = support->index[2];
        support->index[1] = i;
        break;

    case 3:
        cassert(support->n == 3);
        support->index[2] = i;
        break;

    case 4:
        cassert(support->n == 3);
        support->index[1] = i;
        break;

    case 5:
        cassert(support->n == 3);
        support->index[0] = i;
        break;
    }

    return min;
}

/*---------------------------------------------------------------------------*/

// Magic Software: 3D Game Engine Design book
template <typename real>
static Cir2D<real> i_minimum(const V2D<real> *p, const uint32_t n)
{
    Cir2D<real> min;
    Support support;
    const V2D<real> **perm = NULL;
    uint32_t i = 0;
    cassert(n > 0);

    perm = heap_new_n(n, const V2D<real> *);
    for (i = 0; i < n; i++)
        perm[i] = &p[i];

    // generate random permutation
    bmem_shuffle_n(perm, n, const V2D<real> *);

    min = i_exact_circle1<real>(perm[0]);
    support.n = 1;
    support.index[0] = 0;
    i = 1;

    while (i < n)
    {
        if (i_support<real>(&support, i, perm) == FALSE)
        {
            if (i_point_in_circle<real>(&min, perm[i]) == FALSE)
            {
                switch (support.n)
                {
                case 1:
                    min = i_update_support1<real>(i, perm, &support);
                    break;

                case 2:
                    min = i_update_support2<real>(i, perm, &support);
                    break;

                case 3:
                    min = i_update_support3<real>(i, perm, &support);
                    break;

                    cassert_default();
                }

                i = 0;
                continue;
            }
        }

        i++;
    }

    heap_delete_n(&perm, n, const V2D<real> *);
    min.r = BMath<real>::sqrt(min.r);
    return min;
}

/*---------------------------------------------------------------------------*/

Cir2Df cir2d_minimumf(const V2Df *p, const uint32_t n)
{
    Cir2D<real32_t> c = i_minimum<real32_t>((const V2D<real32_t> *)p, n);
    Cir2Df *cc = (Cir2Df *)&c;
    return *cc;
}

/*---------------------------------------------------------------------------*/

Cir2Dd cir2d_minimumd(const V2Dd *p, const uint32_t n)
{
    Cir2D<real64_t> c = i_minimum<real64_t>((const V2D<real64_t> *)p, n);
    Cir2Dd *cc = (Cir2Dd *)&c;
    return *cc;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_area(const Cir2D<real> *cir)
{
    cassert_no_null(cir);
    return BMath<real>::kPI * cir->r * cir->r;
}

/*---------------------------------------------------------------------------*/

real32_t cir2d_areaf(const Cir2Df *cir)
{
    return i_area<real32_t>((const Cir2D<real32_t> *)cir);
}

/*---------------------------------------------------------------------------*/

real64_t cir2d_aread(const Cir2Dd *cir)
{
    return i_area<real64_t>((const Cir2D<real64_t> *)cir);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_is_null(const Cir2D<real> *cir)
{
    cassert_no_null(cir);
    return cir->r < 0 ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t cir2d_is_nullf(const Cir2Df *cir)
{
    return i_is_null<real32_t>((const Cir2D<real32_t> *)cir);
}

/*---------------------------------------------------------------------------*/

bool_t cir2d_is_nulld(const Cir2Dd *cir)
{
    return i_is_null<real64_t>((const Cir2D<real64_t> *)cir);
}

/*---------------------------------------------------------------------------*/

const Cir2Df kCIR2D_NULLf = {{0, 0}, -1};
const Cir2Dd kCIR2D_NULLd = {{0, 0}, -1};

template <>
const Cir2D<real32_t>(*Cir2D<real32_t>::kNULL) = ((Cir2D<real32_t> *)&kCIR2D_NULLf);

template <>
const Cir2D<real64_t>(*Cir2D<real64_t>::kNULL) = ((Cir2D<real64_t> *)&kCIR2D_NULLd);

/*---------------------------------------------------------------------------*/

template <>
Cir2D<real32_t> (*Cir2D<real32_t>::from_box)(const Box2D<real32_t> *) = i_from_box<real32_t>;

template <>
Cir2D<real64_t> (*Cir2D<real64_t>::from_box)(const Box2D<real64_t> *) = i_from_box<real64_t>;

template <>
Cir2D<real32_t> (*Cir2D<real32_t>::from_points)(const V2D<real32_t> *, const uint32_t) = i_from_points<real32_t>;

template <>
Cir2D<real64_t> (*Cir2D<real64_t>::from_points)(const V2D<real64_t> *, const uint32_t) = i_from_points<real64_t>;

template <>
Cir2D<real32_t> (*Cir2D<real32_t>::minimum)(const V2D<real32_t> *, const uint32_t) = i_minimum<real32_t>;

template <>
Cir2D<real64_t> (*Cir2D<real64_t>::minimum)(const V2D<real64_t> *, const uint32_t) = i_minimum<real64_t>;

template <>
real32_t (*Cir2D<real32_t>::area)(const Cir2D<real32_t> *) = i_area<real32_t>;

template <>
real64_t (*Cir2D<real64_t>::area)(const Cir2D<real64_t> *) = i_area<real64_t>;

template <>
bool_t (*Cir2D<real32_t>::is_null)(const Cir2D<real32_t> *) = i_is_null<real32_t>;

template <>
bool_t (*Cir2D<real64_t>::is_null)(const Cir2D<real64_t> *) = i_is_null<real64_t>;
