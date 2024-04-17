/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: box2d.cpp
 *
 */

/* Box 2d */

#include "box2d.h"
#include "box2d.hpp"
#include "cir2d.hpp"
#include <sewer/bmath.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

Box2Df box2df(const real32_t minX, const real32_t minY, const real32_t maxX, const real32_t maxY)
{
    Box2Df box;
    cassert(minX <= maxX);
    cassert(minY <= maxY);
    box.min.x = minX;
    box.min.y = minY;
    box.max.x = maxX;
    box.max.y = maxY;
    return box;
}

/*---------------------------------------------------------------------------*/

Box2Dd box2dd(const real64_t minX, const real64_t minY, const real64_t maxX, const real64_t maxY)
{
    Box2Dd box;
    box.min.x = minX;
    box.min.y = minY;
    box.max.x = maxX;
    box.max.y = maxY;
    return box;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static __INLINE void i_add(Box2D<real> *box, const V2D<real> *p)
{
    cassert_no_null(box);
    cassert_no_null(p);
    if (p->x < box->min.x)
        box->min.x = p->x;
    if (p->y < box->min.y)
        box->min.y = p->y;
    if (p->x > box->max.x)
        box->max.x = p->x;
    if (p->y > box->max.y)
        box->max.y = p->y;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_addn(Box2D<real> *box, const V2D<real> *p, const uint32_t n)
{
    cassert_no_null(box);
    for (uint32_t i = 0; i < n; ++i, ++p)
        i_add<real>(box, p);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Box2D<real> i_from_points(const V2D<real> *p, const uint32_t n)
{
    Box2D<real> box = *Box2D<real>::kNULL;
    i_addn<real>(&box, p, n);
    return box;
}

/*---------------------------------------------------------------------------*/

Box2Df box2d_from_pointsf(const V2Df *p, const uint32_t n)
{
    Box2Df boxf;
    Box2D<real32_t> box = i_from_points<real32_t>((const V2D<real32_t> *)p, n);
    boxf.min.x = box.min.x;
    boxf.min.y = box.min.y;
    boxf.max.x = box.max.x;
    boxf.max.y = box.max.y;
    return boxf;
}

/*---------------------------------------------------------------------------*/

Box2Dd box2d_from_pointsd(const V2Dd *p, const uint32_t n)
{
    Box2Dd boxd;
    Box2D<real64_t> box = i_from_points<real64_t>((const V2D<real64_t> *)p, n);
    boxd.min.x = box.min.x;
    boxd.min.y = box.min.y;
    boxd.max.x = box.max.x;
    boxd.max.y = box.max.y;
    return boxd;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_center(const Box2D<real> *box)
{
    V2D<real> c;
    cassert_no_null(box);
    c.x = (box->min.x + box->max.x) / 2;
    c.y = (box->min.y + box->max.y) / 2;
    return c;
}

/*---------------------------------------------------------------------------*/

V2Df box2d_centerf(const Box2Df *box)
{
    V2Df c;
    cassert_no_null(box);
    c.x = (box->min.x + box->max.x) / 2;
    c.y = (box->min.y + box->max.y) / 2;
    return c;
}

/*---------------------------------------------------------------------------*/

V2Dd box2d_centerd(const Box2Dd *box)
{
    V2Dd c;
    cassert_no_null(box);
    c.x = (box->min.x + box->max.x) / 2;
    c.y = (box->min.y + box->max.y) / 2;
    return c;
}

/*---------------------------------------------------------------------------*/

void box2d_addf(Box2Df *box, const V2Df *p)
{
    i_add<real32_t>((Box2D<real32_t> *)box, (V2D<real32_t> *)p);
}

/*---------------------------------------------------------------------------*/

void box2d_addd(Box2Dd *box, const V2Dd *p)
{
    i_add<real64_t>((Box2D<real64_t> *)box, (V2D<real64_t> *)p);
}

/*---------------------------------------------------------------------------*/

void box2d_addnf(Box2Df *box, const V2Df *p, const uint32_t n)
{
    i_addn<real32_t>((Box2D<real32_t> *)box, (const V2D<real32_t> *)p, n);
}

/*---------------------------------------------------------------------------*/

void box2d_addnd(Box2Dd *box, const V2Dd *p, const uint32_t n)
{
    i_addn<real64_t>((Box2D<real64_t> *)box, (const V2D<real64_t> *)p, n);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_add_circle(Box2D<real> *box, const Cir2D<real> *cir)
{
    cassert_no_null(box);
    cassert_no_null(cir);
    if (box->min.x > cir->c.x - cir->r)
        box->min.x = cir->c.x - cir->r;

    if (box->max.x < cir->c.x + cir->r)
        box->max.x = cir->c.x + cir->r;

    if (box->min.y > cir->c.y - cir->r)
        box->min.y = cir->c.y - cir->r;

    if (box->max.y < cir->c.y + cir->r)
        box->max.y = cir->c.y + cir->r;
}

/*---------------------------------------------------------------------------*/

void box2d_add_circlef(Box2Df *box, const Cir2Df *cir)
{
    i_add_circle<real32_t>((Box2D<real32_t> *)box, (const Cir2D<real32_t> *)cir);
}

/*---------------------------------------------------------------------------*/

void box2d_add_circled(Box2Dd *box, const Cir2Dd *cir)
{
    i_add_circle<real64_t>((Box2D<real64_t> *)box, (const Cir2D<real64_t> *)cir);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_is_null(const Box2D<real> *box)
{
    cassert_no_null(box);
    if (box->min.x > box->max.x)
    {
        cassert(box->min.y > box->max.y);
        return TRUE;
    }
    else
    {
        cassert(box->min.x <= box->max.x);
        cassert(box->min.y <= box->max.y);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_merge(Box2D<real> *dest, const Box2D<real> *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    if (__TRUE_EXPECTED(i_is_null<real>(src) == FALSE))
    {
        if (__TRUE_EXPECTED(i_is_null<real>(dest) == FALSE))
        {
            if (src->min.x < dest->min.x)
                dest->min.x = src->min.x;
            if (src->min.y < dest->min.y)
                dest->min.y = src->min.y;
            if (src->max.x > dest->max.x)
                dest->max.x = src->max.x;
            if (src->max.y > dest->max.y)
                dest->max.y = src->max.y;
        }
        else
        {
            *dest = *src;
        }
    }
}

/*---------------------------------------------------------------------------*/

void box2d_mergef(Box2Df *dest, const Box2Df *src)
{
    i_merge<real32_t>((Box2D<real32_t> *)dest, (const Box2D<real32_t> *)src);
}

/*---------------------------------------------------------------------------*/

void box2d_merged(Box2Dd *dest, const Box2Dd *src)
{
    i_merge<real64_t>((Box2D<real64_t> *)dest, (const Box2D<real64_t> *)src);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_segments(const Box2D<real> *box, Seg2D<real> *segs)
{
    cassert_no_null(box);
    cassert_no_null(segs);
    segs[0] = Seg2D<real>(box->min.x, box->min.y, box->max.x, box->min.y);
    segs[1] = Seg2D<real>(box->max.x, box->min.y, box->max.x, box->max.y);
    segs[2] = Seg2D<real>(box->max.x, box->max.y, box->min.x, box->max.y);
    segs[3] = Seg2D<real>(box->min.x, box->max.y, box->min.x, box->min.y);
}

/*---------------------------------------------------------------------------*/

void box2d_segmentsf(const Box2Df *box, Seg2Df *segs)
{
    i_segments<real32_t>((const Box2D<real32_t> *)box, (Seg2D<real32_t> *)segs);
}

/*---------------------------------------------------------------------------*/

void box2d_segmentsd(const Box2Dd *box, Seg2Dd *segs)
{
    i_segments<real64_t>((const Box2D<real64_t> *)box, (Seg2D<real64_t> *)segs);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_area(const Box2D<real> *box)
{
    real w, h;
    cassert_no_null(box);
    w = box->max.x - box->min.x;
    h = box->max.y - box->min.y;
    cassert(w > 0);
    cassert(h > 0);
    return w * h;
}

/*---------------------------------------------------------------------------*/

real32_t box2d_areaf(const Box2Df *box)
{
    return i_area<real32_t>((const Box2D<real32_t> *)box);
}

/*---------------------------------------------------------------------------*/

real64_t box2d_aread(const Box2Dd *box)
{
    return i_area<real64_t>((const Box2D<real64_t> *)box);
}

/*---------------------------------------------------------------------------*/

bool_t box2d_is_nullf(const Box2Df *box)
{
    return i_is_null<real32_t>((const Box2D<real32_t> *)box);
}

/*---------------------------------------------------------------------------*/

bool_t box2d_is_nulld(const Box2Dd *box)
{
    return i_is_null<real64_t>((const Box2D<real64_t> *)box);
}

/*---------------------------------------------------------------------------*/

static void i_copyff(Box2D<real32_t> *dest, const Box2D<real32_t> *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    *dest = *src;
}

/*---------------------------------------------------------------------------*/

static void i_copyfd(Box2D<real32_t> *dest, const Box2D<real64_t> *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    dest->min.x = (real32_t)src->min.x;
    dest->min.y = (real32_t)src->min.y;
    dest->max.x = (real32_t)src->max.x;
    dest->max.y = (real32_t)src->max.y;
}

/*---------------------------------------------------------------------------*/

static void i_copydf(Box2D<real64_t> *dest, const Box2D<real32_t> *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    dest->min.x = (real64_t)src->min.x;
    dest->min.y = (real64_t)src->min.y;
    dest->max.x = (real64_t)src->max.x;
    dest->max.y = (real64_t)src->max.y;
}

/*---------------------------------------------------------------------------*/

static void i_copydd(Box2D<real64_t> *dest, const Box2D<real64_t> *src)
{
    cassert_no_null(dest);
    cassert_no_null(src);
    *dest = *src;
}

/*---------------------------------------------------------------------------*/

const Box2Df kBOX2D_NULLf = {{REAL32_MAX, REAL32_MAX}, {-REAL32_MAX, -REAL32_MAX}};
const Box2Dd kBOX2D_NULLd = {{REAL64_MAX, REAL64_MAX}, {-REAL64_MAX, -REAL64_MAX}};

template <>
const Box2D<real32_t>(*Box2D<real32_t>::kNULL) = ((Box2D<real32_t> *)&kBOX2D_NULLf);

template <>
const Box2D<real64_t>(*Box2D<real64_t>::kNULL) = ((Box2D<real64_t> *)&kBOX2D_NULLd);

/*---------------------------------------------------------------------------*/

template <>
Box2D<real32_t> (*Box2D<real32_t>::from_points)(const V2D<real32_t> *, const uint32_t) = i_from_points<real32_t>;

template <>
Box2D<real64_t> (*Box2D<real64_t>::from_points)(const V2D<real64_t> *, const uint32_t) = i_from_points<real64_t>;

template <>
V2D<real32_t> (*Box2D<real32_t>::center)(const Box2D<real32_t> *) = i_center<real32_t>;

template <>
V2D<real64_t> (*Box2D<real64_t>::center)(const Box2D<real64_t> *) = i_center<real64_t>;

template <>
void (*Box2D<real32_t>::add)(Box2D<real32_t> *, const V2D<real32_t> *) = i_add<real32_t>;

template <>
void (*Box2D<real64_t>::add)(Box2D<real64_t> *, const V2D<real64_t> *) = i_add<real64_t>;

template <>
void (*Box2D<real32_t>::addn)(Box2D<real32_t> *, const V2D<real32_t> *, const uint32_t) = i_addn<real32_t>;

template <>
void (*Box2D<real64_t>::addn)(Box2D<real64_t> *, const V2D<real64_t> *, const uint32_t) = i_addn<real64_t>;

template <>
void (*Box2D<real32_t>::merge)(Box2D<real32_t> *, const Box2D<real32_t> *) = i_merge<real32_t>;

template <>
void (*Box2D<real64_t>::merge)(Box2D<real64_t> *, const Box2D<real64_t> *) = i_merge<real64_t>;

template <>
void (*Box2D<real32_t>::segments)(const Box2D<real32_t> *, Seg2D<real32_t> *) = i_segments<real32_t>;

template <>
void (*Box2D<real64_t>::segments)(const Box2D<real64_t> *, Seg2D<real64_t> *) = i_segments<real64_t>;

template <>
real32_t (*Box2D<real32_t>::area)(const Box2D<real32_t> *) = i_area<real32_t>;

template <>
real64_t (*Box2D<real64_t>::area)(const Box2D<real64_t> *) = i_area<real64_t>;

template <>
bool_t (*Box2D<real32_t>::is_null)(const Box2D<real32_t> *) = i_is_null<real32_t>;

template <>
bool_t (*Box2D<real64_t>::is_null)(const Box2D<real64_t> *) = i_is_null<real64_t>;

template <>
void (*Box2D2<real32_t, real32_t>::copy)(Box2D<real32_t> *, const Box2D<real32_t> *) = i_copyff;

template <>
void (*Box2D2<real32_t, real64_t>::copy)(Box2D<real32_t> *, const Box2D<real64_t> *) = i_copyfd;

template <>
void (*Box2D2<real64_t, real32_t>::copy)(Box2D<real64_t> *, const Box2D<real32_t> *) = i_copydf;

template <>
void (*Box2D2<real64_t, real64_t>::copy)(Box2D<real64_t> *, const Box2D<real64_t> *) = i_copydd;
