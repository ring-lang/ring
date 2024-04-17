/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: pol2d.cpp
 *
 */

/* 2d polygon */

#include "pol2d.h"
#include "pol2d.hpp"
#include "pol2d.ipp"
#include "col2d.ipp"
#include <core/arrpt.h>
#include <core/heap.h>
#include <sewer/bmem.h>
#include <sewer/bmath.hpp>
#include <sewer/cassert.h>

#define i_AREA_UPDATE 1
#define i_CCW_ORDER 2
#define i_CONVEX_UPDATE 3
#define i_CONVEX 4

template <typename real>
struct Pol2DImp
{
    uint32_t flags;
    real area;
    SATPoly<real> *sat;
    ArrPt<SATPoly<real> > *convex_sat;
};

/*---------------------------------------------------------------------------*/

template <typename real>
static Pol2D<real> *i_create(const V2D<real> *points, const uint32_t n)
{
    Pol2DImp<real> *poly = heap_new(Pol2DImp<real>);
    poly->flags = 0;
    poly->area = -1;
    poly->sat = SATPoly<real>::create(n, n);
    poly->convex_sat = NULL;
    bmem_copy_n(poly->sat->vertex, points, n, V2D<real>);
    poly->sat->updated = FALSE;
    return (Pol2D<real> *)poly;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Pol2D<real> *i_create_with_sat(SATPoly<real> *sat)
{
    Pol2DImp<real> *poly = heap_new(Pol2DImp<real>);
    poly->flags = 0;
    poly->area = -1;
    poly->sat = sat;
    poly->convex_sat = NULL;
    return (Pol2D<real> *)poly;
}

/*---------------------------------------------------------------------------*/

Pol2Df *pol2d_createf(const V2Df *points, const uint32_t n)
{
    return (Pol2Df *)i_create<real32_t>((const V2D<real32_t> *)points, n);
}

/*---------------------------------------------------------------------------*/

Pol2Dd *pol2d_created(const V2Dd *points, const uint32_t n)
{
    return (Pol2Dd *)i_create<real64_t>((const V2D<real64_t> *)points, n);
}

/*---------------------------------------------------------------------------*/
// https://stackoverflow.com/questions/471962/how-do-i-efficiently-determine-if-a-polygon-is-convex-non-convex-or-complex
template <typename real>
static bool_t i_check_convex(const V2D<real> *v, const uint32_t n)
{
    if (n >= 4)
    {
        register bool_t sign = FALSE;
        register uint32_t i;
        for (i = 0; i < n; ++i)
        {
            real dx1 = v[(i + 2) % n].x - v[(i + 1) % n].x;
            real dy1 = v[(i + 2) % n].y - v[(i + 1) % n].y;
            real dx2 = v[i].x - v[(i + 1) % n].x;
            real dy2 = v[i].y - v[(i + 1) % n].y;
            real cross = dx1 * dy2 - dy1 * dx2;

            if (i == 0)
                sign = (bool_t)(cross > 0);
            else if (sign != (bool_t)(cross > 0))
                return FALSE;
        }
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_convex(const Pol2D<real> *pol)
{
    Pol2DImp<real> *poly = (Pol2DImp<real> *)pol;
    if (BIT_TEST(poly->flags, i_CONVEX_UPDATE) == FALSE)
    {
        if (i_check_convex<real>(poly->sat->vertex, poly->sat->num_vertices) == TRUE)
            BIT_SET(poly->flags, i_CONVEX);
        else
            BIT_CLEAR(poly->flags, i_CONVEX);

        BIT_SET(poly->flags, i_CONVEX_UPDATE);
    }

    return BIT_TEST(poly->flags, i_CONVEX);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static __INLINE real i_ccw(const V2D<real> *a, const V2D<real> *b, const V2D<real> *c)
{
    cassert_no_null(a);
    cassert_no_null(b);
    cassert_no_null(c);
    return (b->x - a->x) * (c->y - a->y) - (b->y - a->y) * (c->x - a->x);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_min_max_points(const V2D<real> *p, const uint32_t n, uint32_t *min_pt, uint32_t *max_pt)
{
    uint32_t min = 0, max = 0;

    cassert_no_null(p);
    cassert_no_null(min_pt);
    cassert_no_null(max_pt);
    cassert(n > 0);

    for (uint32_t i = 1; i < n; ++i)
    {
        if (p[i].x < p[min].x || (p[i].x == p[min].x && p[i].y < p[min].y))
            min = i;

        if (p[i].x > p[max].x || (p[i].x == p[max].x && p[i].y > p[max].y))
            max = i;
    }

    *min_pt = min;
    *max_pt = max;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static __INLINE real i_dist(const V2D<real> *a, const V2D<real> *b, const V2D<real> *p, const real ab_dist)
{
    return BMath<real>::abs((b->x - a->x) * (a->y - p->y) - (b->y - a->y) * (a->x - p->x)) / ab_dist;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static uint32_t i_get_farthest(const V2D<real> *a, const V2D<real> *b, const ArrSt<uint32_t> *indices, const V2D<real> *v)
{
    const uint32_t *index = ArrSt<uint32_t>::all(indices);
    uint32_t n = ArrSt<uint32_t>::size(indices);
    uint32_t max_id = 0;
    real ab_dist = V2D<real>::dist(a, b);
    real max_dist = i_dist<real>(a, b, &v[index[max_id]], ab_dist);

    for (uint32_t i = 1; i < n; ++i)
    {
        real cur_dist = i_dist<real>(a, b, &v[index[i]], ab_dist);
        if (cur_dist > max_dist)
        {
            max_id = i;
            max_dist = cur_dist;
        }
    }

    return index[max_id];
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_quick_hull(const ArrSt<uint32_t> *indices, const V2D<real> *v, const V2D<real> *a, const V2D<real> *b, ArrSt<uint32_t> *hull)
{
    uint32_t n = ArrSt<uint32_t>::size(indices);

    if (n > 0)
    {
        const uint32_t *index = ArrSt<uint32_t>::all(indices);
        uint32_t far_id = i_get_farthest<real>(a, b, indices, v);
        const V2D<real> *f = &v[far_id];
        ArrSt<uint32_t> *temp = ArrSt<uint32_t>::create();

        // Collect points to the left of segment (a, f)
        for (uint32_t i = 0; i < n; ++i)
        {
            if (i_ccw<real>(a, f, &v[index[i]]) > 0)
                ArrSt<uint32_t>::append(temp, index[i]);
        }

        i_quick_hull<real>(temp, v, a, f, hull);

        // Add f to the hull
        ArrSt<uint32_t>::append(hull, far_id);

        // Collect points to the left of segment (f, b)
        ArrSt<uint32_t>::clear(temp, NULL);
        for (uint32_t i = 0; i < n; ++i)
        {
            if (i_ccw<real>(f, b, &v[index[i]]) > 0)
                ArrSt<uint32_t>::append(temp, index[i]);
        }

        i_quick_hull<real>(temp, v, f, b, hull);

        ArrSt<uint32_t>::destroy(&temp, NULL);
    }
}

/*---------------------------------------------------------------------------*/

// https://github.com/MiguelVieira/ConvexHull2D/blob/master/ConvexHull.cpp
template <typename real>
static Pol2D<real> *i_convex_hull(const V2D<real> *points, const uint32_t n)
{
    Pol2D<real> *pol = NULL;
    ArrSt<uint32_t> *hull = ArrSt<uint32_t>::create();
    ArrSt<uint32_t> *left = ArrSt<uint32_t>::create();
    ArrSt<uint32_t> *right = ArrSt<uint32_t>::create();
    uint32_t a, b;

    // Start with the leftmost and rightmost points
    i_min_max_points<real>(points, n, &a, &b);

    // Split the points on either side of segment (a, b)
    for (uint32_t i = 0; i < n; ++i)
    {
        if (i_ccw<real>(&points[a], &points[b], &points[i]) > 0)
            ArrSt<uint32_t>::append(left, i);
        else
            ArrSt<uint32_t>::append(right, i);
    }

    // Be careful to add points to the hull
    // in the correct order. Add our leftmost point.
    ArrSt<uint32_t>::append(hull, a);

    // Add hull points from the left (top)
    i_quick_hull<real>(left, points, &points[a], &points[b], hull);

    ArrSt<uint32_t>::append(hull, b);

    // Add hull points from the right (bottom)
    i_quick_hull<real>(right, points, &points[b], &points[a], hull);

    {
        const uint32_t *index = ArrSt<uint32_t>::all(hull);
        uint32_t hn = ArrSt<uint32_t>::size(hull);
        V2D<real> *hp = heap_new_n(hn, V2D<real>);
        for (uint32_t i = 0; i < hn; ++i)
            hp[i] = points[index[i]];

        pol = i_create<real>(hp, hn);

        heap_delete_n(&hp, hn, V2D<real>);
    }

    ArrSt<uint32_t>::destroy(&hull, NULL);
    ArrSt<uint32_t>::destroy(&left, NULL);
    ArrSt<uint32_t>::destroy(&right, NULL);

    cassert(i_convex<real>(pol) == TRUE);
    return pol;
}

/*---------------------------------------------------------------------------*/

Pol2Df *pol2d_convex_hullf(const V2Df *points, const uint32_t n)
{
    return (Pol2Df *)i_convex_hull<real32_t>((const V2D<real32_t> *)points, n);
}

/*---------------------------------------------------------------------------*/

Pol2Dd *pol2d_convex_hulld(const V2Dd *points, const uint32_t n)
{
    return (Pol2Dd *)i_convex_hull<real64_t>((const V2D<real64_t> *)points, n);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Pol2D<real> *i_copy(const Pol2D<real> *pol)
{
    const Pol2DImp<real> *src = (const Pol2DImp<real> *)pol;
    Pol2DImp<real> *dest = heap_new(Pol2DImp<real>);
    dest->area = src->area;
    dest->flags = src->flags;
    dest->sat = SATPoly<real>::copy(src->sat);

    if (src->convex_sat != NULL)
        dest->convex_sat = ArrPt<SATPoly<real> >::copy(src->convex_sat, SATPoly<real>::copy);
    else
        dest->convex_sat = NULL;

    return (Pol2D<real> *)dest;
}

/*---------------------------------------------------------------------------*/

Pol2Df *pol2d_copyf(const Pol2Df *pol)
{
    return (Pol2Df *)i_copy<real32_t>((const Pol2D<real32_t> *)pol);
}

/*---------------------------------------------------------------------------*/

Pol2Dd *pol2d_copyd(const Pol2Dd *pol)
{
    return (Pol2Dd *)i_copy<real64_t>((const Pol2D<real64_t> *)pol);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_destroy(Pol2D<real> **pol)
{
    Pol2DImp<real> **poly = (Pol2DImp<real> **)pol;
    SATPoly<real>::destroy(&(*poly)->sat);

    if ((*poly)->convex_sat != NULL)
        ArrPt<SATPoly<real> >::destroy(&(*poly)->convex_sat, SATPoly<real>::destroy);

    heap_delete(poly, Pol2DImp<real>);
}

/*---------------------------------------------------------------------------*/

void pol2d_destroyf(Pol2Df **pol)
{
    i_destroy<real32_t>((Pol2D<real32_t> **)pol);
}

/*---------------------------------------------------------------------------*/

void pol2d_destroyd(Pol2Dd **pol)
{
    i_destroy<real64_t>((Pol2D<real64_t> **)pol);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_transform(Pol2D<real> *pol, const T2D<real> *t2d)
{
    Pol2DImp<real> *poly = (Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    cassert_no_null(poly->sat);
    T2D<real>::vmultn(poly->sat->vertex, t2d, poly->sat->vertex, poly->sat->num_vertices);

    if (poly->convex_sat != NULL)
        ArrPt<SATPoly<real> >::destroy(&poly->convex_sat, SATPoly<real>::destroy);

    poly->sat->updated = FALSE;
    poly->flags = 0;
    poly->area = -1;
}

/*---------------------------------------------------------------------------*/

void pol2d_transformf(Pol2Df *pol, const T2Df *t2d)
{
    i_transform<real32_t>((Pol2D<real32_t> *)pol, (const T2D<real32_t> *)t2d);
}

/*---------------------------------------------------------------------------*/

void pol2d_transformd(Pol2Dd *pol, const T2Dd *t2d)
{
    i_transform<real64_t>((Pol2D<real64_t> *)pol, (const T2D<real64_t> *)t2d);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static const V2D<real> *i_points(const Pol2D<real> *pol)
{
    const Pol2DImp<real> *poly = (const Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    cassert_no_null(poly->sat);
    return poly->sat->vertex;
}

/*---------------------------------------------------------------------------*/

const V2Df *pol2d_pointsf(const Pol2Df *pol)
{
    return (const V2Df *)i_points<real32_t>((const Pol2D<real32_t> *)pol);
}

/*---------------------------------------------------------------------------*/

const V2Dd *pol2d_pointsd(const Pol2Dd *pol)
{
    return (const V2Dd *)i_points<real64_t>((const Pol2D<real64_t> *)pol);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static uint32_t i_n(const Pol2D<real> *pol)
{
    const Pol2DImp<real> *poly = (const Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    cassert_no_null(poly->sat);
    return poly->sat->num_vertices;
}

/*---------------------------------------------------------------------------*/

uint32_t pol2d_nf(const Pol2Df *pol)
{
    return i_n<real32_t>((const Pol2D<real32_t> *)pol);
}

/*---------------------------------------------------------------------------*/

uint32_t pol2d_nd(const Pol2Dd *pol)
{
    return i_n<real64_t>((const Pol2D<real64_t> *)pol);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_compute_area(Pol2DImp<real> *poly)
{
    const V2D<real> *p;
    register uint32_t i, n;
    real area = 0;
    cassert_no_null(poly);
    cassert(BIT_TEST(poly->flags, i_AREA_UPDATE) == FALSE);
    cassert(poly->area == -1);
    p = poly->sat->vertex;
    n = poly->sat->num_vertices;

    for (i = 0; i < n; ++i)
    {
        const V2D<real> *p0 = p + i;
        const V2D<real> *p1 = p + ((i + 1) % n);
        area += (p1->x - p0->x) * (p1->y + p0->y);
    }

    area /= 2;

    if (area > 0)
    {
        BIT_CLEAR(poly->flags, i_CCW_ORDER);
        poly->area = area;
    }
    else
    {
        BIT_SET(poly->flags, i_CCW_ORDER);
        poly->area = -area;
    }

    BIT_SET(poly->flags, i_AREA_UPDATE);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_area(const Pol2D<real> *pol)
{
    Pol2DImp<real> *poly = (Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    if (BIT_TEST(poly->flags, i_AREA_UPDATE) == FALSE)
        i_compute_area<real>(poly);
    return poly->area;
}

/*---------------------------------------------------------------------------*/

real32_t pol2d_areaf(const Pol2Df *pol)
{
    return i_area<real32_t>((const Pol2D<real32_t> *)pol);
}

/*---------------------------------------------------------------------------*/

real64_t pol2d_aread(const Pol2Dd *pol)
{
    return i_area<real64_t>((const Pol2D<real64_t> *)pol);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Box2D<real> i_box(const Pol2D<real> *pol)
{
    Pol2DImp<real> *poly = (Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    return Box2D<real>::from_points(poly->sat->vertex, poly->sat->num_vertices);
}

/*---------------------------------------------------------------------------*/

Box2Df pol2d_boxf(const Pol2Df *pol)
{
    Box2Df boxf;
    Box2D<real32_t> box = i_box<real32_t>((const Pol2D<real32_t> *)pol);
    register Box2D<real32_t> *boxp = (Box2D<real32_t> *)&boxf;
    *boxp = box;
    return boxf;
}

/*---------------------------------------------------------------------------*/

Box2Dd pol2d_boxd(const Pol2Dd *pol)
{
    Box2Dd boxd;
    Box2D<real64_t> box = i_box<real64_t>((const Pol2D<real64_t> *)pol);
    register Box2D<real64_t> *boxp = (Box2D<real64_t> *)&boxd;
    *boxp = box;
    return boxd;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_ccw(const Pol2D<real> *pol)
{
    Pol2DImp<real> *poly = (Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    if (BIT_TEST(poly->flags, i_AREA_UPDATE) == FALSE)
        i_compute_area<real>(poly);
    return BIT_TEST(poly->flags, i_CCW_ORDER);
}

/*---------------------------------------------------------------------------*/

bool_t pol2d_ccwf(const Pol2Df *pol)
{
    return i_ccw<real32_t>((const Pol2D<real32_t> *)pol);
}

/*---------------------------------------------------------------------------*/

bool_t pol2d_ccwd(const Pol2Dd *pol)
{
    return i_ccw<real64_t>((const Pol2D<real64_t> *)pol);
}

/*---------------------------------------------------------------------------*/

bool_t pol2d_convexf(const Pol2Df *pol)
{
    return i_convex<real32_t>((const Pol2D<real32_t> *)pol);
}

/*---------------------------------------------------------------------------*/

bool_t pol2d_convexd(const Pol2Dd *pol)
{
    return i_convex<real64_t>((const Pol2D<real64_t> *)pol);
}

/*---------------------------------------------------------------------------*/

// https://www.seas.upenn.edu/~ese502/lab-content/extra_materials/Polygon%20Area%20and%20Centroid.pdf
// http://paulbourke.net/geometry/polygonmesh/PolygonUtilities.java
template <typename real>
static V2D<real> i_centroid(const Pol2D<real> *pol)
{
    V2D<real> c(0, 0);
    Pol2DImp<real> *poly = (Pol2DImp<real> *)pol;
    real area = i_area<real>(pol);
    const V2D<real> *v = poly->sat->vertex;
    register uint32_t i, n = poly->sat->num_vertices;

    for (i = 0; i < n; ++i)
    {
        const V2D<real> *vi = v + i;
        const V2D<real> *vj = v + ((i + 1) % n);
        real factor = (vi->x * vj->y) - (vj->x * vi->y);
        c.x += (vi->x + vj->x) * factor;
        c.y += (vi->y + vj->y) * factor;
    }

    area *= 6;
    if (BIT_TEST(poly->flags, i_CCW_ORDER) == TRUE)
    {
        c.x *= 1 / area;
        c.y *= 1 / area;
    }
    else
    {
        c.x *= -1 / area;
        c.y *= -1 / area;
    }

    return c;
}

/*---------------------------------------------------------------------------*/

V2Df pol2d_centroidf(const Pol2Df *pol)
{
    V2D<real32_t> v = i_centroid<real32_t>((const Pol2D<real32_t> *)pol);
    V2Df vf;
    vf.x = v.x;
    vf.y = v.y;
    return vf;
}

/*---------------------------------------------------------------------------*/

V2Dd pol2d_centroidd(const Pol2Dd *pol)
{
    V2D<real64_t> v = i_centroid<real64_t>((const Pol2D<real64_t> *)pol);
    V2Dd vd;
    vd.x = v.x;
    vd.y = v.y;
    return vd;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_visual_center(const Pol2D<real> *pol, const real norm_tol)
{
    if (i_convex<real>(pol) == TRUE)
        return i_centroid<real>(pol);
    else
        return Pol2DI<real>::poly_label(pol, norm_tol);
}

/*---------------------------------------------------------------------------*/

V2Df pol2d_visual_centerf(const Pol2Df *pol, const real32_t norm_tol)
{
    V2D<real32_t> v = i_visual_center<real32_t>((const Pol2D<real32_t> *)pol, norm_tol);
    V2Df vf;
    vf.x = v.x;
    vf.y = v.y;
    return vf;
}

/*---------------------------------------------------------------------------*/

V2Dd pol2d_visual_centerd(const Pol2Dd *pol, const real64_t norm_tol)
{
    V2D<real64_t> v = i_visual_center<real64_t>((const Pol2D<real64_t> *)pol, norm_tol);
    V2Dd vd;
    vd.x = v.x;
    vd.y = v.y;
    return vd;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static const V2D<real> *i_vertices(const Pol2D<real> *pol, uint32_t *n)
{
    const Pol2DImp<real> *poly = (const Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    cassert_no_null(poly->sat);
    cassert_no_null(n);
    *n = poly->sat->num_vertices;
    return poly->sat->vertex;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static SATPoly<real> *i_sat_poly(const Pol2D<real> *pol)
{
    const Pol2DImp<real> *poly = (const Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    cassert_no_null(poly->sat);

    if (poly->sat->updated == FALSE)
    {
        V2D<real> *v = poly->sat->vertex;
        V2D<real> *a = poly->sat->axis;
        register uint32_t i = 0, n = poly->sat->num_vertices;
        cassert(n == poly->sat->num_axis);

        for (i = 0; i < n; ++i)
        {
            a[i].x = -(v[i + 1 % n].y - v[i].y);
            a[i].y = v[i + 1 % n].x - v[i].x;
        }

        SATPoly<real>::limits(v, a, n, poly->sat->num_axis, poly->sat->min, poly->sat->max);
        poly->sat->updated = TRUE;
    }

    return poly->sat;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static ArrPt<SATPoly<real> > *i_convex_sat_polys(Pol2D<real> *pol)
{
    Pol2DImp<real> *poly = (Pol2DImp<real> *)pol;
    cassert_no_null(poly);
    cassert_no_null(poly->sat);
    if (poly->convex_sat == NULL && i_convex<real>(pol) == FALSE)
        poly->convex_sat = Pol2DI<real>::get_convex_sat_polys(pol);
    return poly->convex_sat;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_convex_polygons(const Pol2D<real> *pol, ArrPt<Pol2D<real> > *polys)
{
    if (i_convex<real>(pol) == TRUE)
    {
        Pol2D<real> *pcopy = Pol2D<real>::copy(pol);
        ArrPt<Pol2D<real> >::append(polys, pcopy);
    }
    else
    {
        const ArrPt<SATPoly<real> > *sats = i_convex_sat_polys<real>((Pol2D<real> *)pol);
        const SATPoly<real> **sat = ArrPt<SATPoly<real> >::all(sats);
        uint32_t i, n = ArrPt<SATPoly<real> >::size(sats);
        for (i = 0; i < n; ++i)
        {
            SATPoly<real> *sat_copy = SATPoly<real>::copy(sat[i]);
            Pol2D<real> *npol = i_create_with_sat<real>(sat_copy);
            ArrPt<Pol2D<real> >::append(polys, npol);
        }
    }
}

/*---------------------------------------------------------------------------*/

ArrPt(Pol2Df) *pol2d_convex_partitionf(const Pol2Df *pol)
{
    ArrPt(Pol2Df) *polys = arrpt_create(Pol2Df);
    i_convex_polygons<real32_t>((const Pol2D<real32_t> *)pol, (ArrPt<Pol2D<real32_t> > *)polys);
    return polys;
}

/*---------------------------------------------------------------------------*/

ArrPt(Pol2Dd) *pol2d_convex_partitiond(const Pol2Dd *pol)
{
    ArrPt(Pol2Dd) *polys = arrpt_create(Pol2Dd);
    i_convex_polygons<real64_t>((const Pol2D<real64_t> *)pol, (ArrPt<Pol2D<real64_t> > *)polys);
    return polys;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static ArrPt<Pol2D<real> > *i_convex_partition(const Pol2D<real> *pol)
{
    ArrPt<Pol2D<real> > *polys = ArrPt<Pol2D<real> >::create();
    i_convex_polygons<real>(pol, polys);
    return polys;
}

/*---------------------------------------------------------------------------*/

template <>
Pol2D<real32_t> *(*Pol2D<real32_t>::create)(const V2D<real32_t> *, const uint32_t) = i_create<real32_t>;

template <>
Pol2D<real64_t> *(*Pol2D<real64_t>::create)(const V2D<real64_t> *, const uint32_t) = i_create<real64_t>;

template <>
Pol2D<real32_t> *(*Pol2D<real32_t>::convex_hull)(const V2D<real32_t> *, const uint32_t) = i_convex_hull<real32_t>;

template <>
Pol2D<real64_t> *(*Pol2D<real64_t>::convex_hull)(const V2D<real64_t> *, const uint32_t) = i_convex_hull<real64_t>;

template <>
Pol2D<real32_t> *(*Pol2D<real32_t>::copy)(const Pol2D<real32_t> *) = i_copy<real32_t>;

template <>
Pol2D<real64_t> *(*Pol2D<real64_t>::copy)(const Pol2D<real64_t> *) = i_copy<real64_t>;

template <>
void (*Pol2D<real32_t>::destroy)(Pol2D<real32_t> **) = i_destroy<real32_t>;

template <>
void (*Pol2D<real64_t>::destroy)(Pol2D<real64_t> **) = i_destroy<real64_t>;

template <>
void (*Pol2D<real32_t>::transform)(Pol2D<real32_t> *, const T2D<real32_t> *) = i_transform<real32_t>;

template <>
void (*Pol2D<real64_t>::transform)(Pol2D<real64_t> *, const T2D<real64_t> *) = i_transform<real64_t>;

template <>
const V2D<real32_t> *(*Pol2D<real32_t>::points)(const Pol2D<real32_t> *) = i_points<real32_t>;

template <>
const V2D<real64_t> *(*Pol2D<real64_t>::points)(const Pol2D<real64_t> *) = i_points<real64_t>;

template <>
uint32_t (*Pol2D<real32_t>::n)(const Pol2D<real32_t> *) = i_n<real32_t>;

template <>
uint32_t (*Pol2D<real64_t>::n)(const Pol2D<real64_t> *) = i_n<real64_t>;

template <>
real32_t (*Pol2D<real32_t>::area)(const Pol2D<real32_t> *) = i_area<real32_t>;

template <>
real64_t (*Pol2D<real64_t>::area)(const Pol2D<real64_t> *) = i_area<real64_t>;

template <>
Box2D<real32_t> (*Pol2D<real32_t>::box)(const Pol2D<real32_t> *) = i_box<real32_t>;

template <>
Box2D<real64_t> (*Pol2D<real64_t>::box)(const Pol2D<real64_t> *) = i_box<real64_t>;

template <>
bool_t (*Pol2D<real32_t>::ccw)(const Pol2D<real32_t> *) = i_ccw<real32_t>;

template <>
bool_t (*Pol2D<real64_t>::ccw)(const Pol2D<real64_t> *) = i_ccw<real64_t>;

template <>
bool_t (*Pol2D<real32_t>::convex)(const Pol2D<real32_t> *) = i_convex<real32_t>;

template <>
bool_t (*Pol2D<real64_t>::convex)(const Pol2D<real64_t> *) = i_convex<real64_t>;

template <>
V2D<real32_t> (*Pol2D<real32_t>::centroid)(const Pol2D<real32_t> *) = i_centroid<real32_t>;

template <>
V2D<real64_t> (*Pol2D<real64_t>::centroid)(const Pol2D<real64_t> *) = i_centroid<real64_t>;

template <>
V2D<real32_t> (*Pol2D<real32_t>::visual_center)(const Pol2D<real32_t> *, const real32_t) = i_visual_center<real32_t>;

template <>
V2D<real64_t> (*Pol2D<real64_t>::visual_center)(const Pol2D<real64_t> *, const real64_t) = i_visual_center<real64_t>;

template <>
ArrPt<Pol2D<real32_t> > *(*Pol2D<real32_t>::convex_partition)(const Pol2D<real32_t> *pol) = i_convex_partition<real32_t>;

template <>
ArrPt<Pol2D<real64_t> > *(*Pol2D<real64_t>::convex_partition)(const Pol2D<real64_t> *pol) = i_convex_partition<real64_t>;

template <>
const V2D<real32_t> *(*Pol2DI<real32_t>::vertices)(const Pol2D<real32_t> *, uint32_t *) = i_vertices<real32_t>;

template <>
const V2D<real64_t> *(*Pol2DI<real64_t>::vertices)(const Pol2D<real64_t> *, uint32_t *) = i_vertices<real64_t>;

template <>
SATPoly<real32_t> *(*Pol2DI<real32_t>::sat_poly)(const Pol2D<real32_t> *) = i_sat_poly<real32_t>;

template <>
SATPoly<real64_t> *(*Pol2DI<real64_t>::sat_poly)(const Pol2D<real64_t> *) = i_sat_poly<real64_t>;

template <>
ArrPt<SATPoly<real32_t> > *(*Pol2DI<real32_t>::convex_sat_polys)(Pol2D<real32_t> *) = i_convex_sat_polys<real32_t>;

template <>
ArrPt<SATPoly<real64_t> > *(*Pol2DI<real64_t>::convex_sat_polys)(Pol2D<real64_t> *) = i_convex_sat_polys<real64_t>;
