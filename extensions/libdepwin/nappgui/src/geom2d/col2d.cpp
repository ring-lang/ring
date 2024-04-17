/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: col2d.cpp
 *
 */

/* 2D Collision detection */

#include "col2d.h"
#include "col2d.ipp"
#include "col2d.hpp"
#include "obb2d.ipp"
#include "pol2d.ipp"
#include <core/heap.h>
#include <sewer/bmath.hpp>
#include <sewer/bmem.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

template <typename real>
static SATPoly<real> *i_create(const uint32_t num_vertices, const uint32_t num_axis)
{
    // Only one memory allocation
    register uint32_t msize = (uint32_t)(sizeof(SATPoly<real>) + num_vertices * sizeof(V2D<real>) + num_axis * sizeof(V2D<real>) + 2 * num_axis * sizeof(real));
    SATPoly<real> *poly = (SATPoly<real> *)heap_malloc(msize, "SATPoly");
    byte_t *mem = ((byte_t *)poly) + sizeof(SATPoly<real>);
    poly->num_vertices = num_vertices;
    poly->num_axis = num_axis;
    poly->vertex = (V2D<real> *)(mem);
    poly->axis = (V2D<real> *)(mem + num_vertices * sizeof(V2D<real>));
    poly->min = (real *)(mem + num_vertices * sizeof(V2D<real>) + num_axis * sizeof(V2D<real>));
    poly->max = (real *)(mem + num_vertices * sizeof(V2D<real>) + num_axis * sizeof(V2D<real>) + num_axis * sizeof(real));
    poly->updated = FALSE;
    return poly;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static SATPoly<real> *i_copy(const SATPoly<real> *poly)
{
    SATPoly<real> *cpoly = NULL;
    cassert_no_null(poly);
    cpoly = i_create<real>(poly->num_vertices, poly->num_axis);
    bmem_copy_n(cpoly->vertex, poly->vertex, poly->num_vertices, V2D<real>);
    bmem_copy_n(cpoly->axis, poly->axis, poly->num_axis, V2D<real>);
    bmem_copy_n(cpoly->min, poly->min, poly->num_axis, real);
    bmem_copy_n(cpoly->max, poly->max, poly->num_axis, real);
    cpoly->updated = poly->updated;
    return cpoly;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_destroy(SATPoly<real> **poly)
{
    register uint32_t msize = 0;
    cassert_no_null(poly);
    cassert_no_null(*poly);
    msize = (uint32_t)(sizeof(SATPoly<real>) + (*poly)->num_vertices * sizeof(V2D<real>) + (*poly)->num_axis * sizeof(V2D<real>) + 2 * (*poly)->num_axis * sizeof(real));
    heap_free((byte_t **)poly, msize, "SATPoly");
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Box2D<real> i_bbox(const SATPoly<real> *poly)
{
    Box2D<real> box = *Box2D<real>::kNULL;
    cassert_no_null(poly);
    Box2D<real>::addn(&box, poly->vertex, poly->num_vertices);
    return box;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_limits(const V2D<real> *vertex, const V2D<real> *axis, const uint32_t num_vertices, const uint32_t num_axis, real *min, real *max)
{
    register uint32_t i, j;
    for (i = 0; i < num_axis; ++i)
    {
        register real t = vertex[0].x * axis[i].x + vertex[0].y * axis[i].y;
        min[i] = t, max[i] = t;

        for (j = 1; j < num_vertices; ++j)
        {
            t = vertex[j].x * axis[i].x + vertex[j].y * axis[i].y;
            if (t < min[i])
                min[i] = t;
            else if (t > max[i])
                max[i] = t;
        }
    }
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_sat_overlaps(const V2D<real> *poly1_axis, const real *poly1_min, const real *poly1_max, const uint32_t poly1_num_axis, const V2D<real> *poly2_vertex, const uint32_t poly2_num_vertices)
{
    register uint32_t i, j;
    for (i = 0; i < poly1_num_axis; ++i)
    {
        register real t = poly2_vertex[0].x * poly1_axis[i].x + poly2_vertex[0].y * poly1_axis[i].y;
        register real min = t, max = t;

        for (j = 1; j < poly2_num_vertices; ++j)
        {
            t = poly2_vertex[j].x * poly1_axis[i].x + poly2_vertex[j].y * poly1_axis[i].y;
            if (t < min)
                min = t;
            else if (t > max)
                max = t;
        }

        if ((min >= poly1_min[i] && min <= poly1_max[i]) || (poly1_min[i] >= min && poly1_min[i] <= max))
            continue;
        else
            return FALSE;
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_point_point(const V2D<real> *pnt1, const V2D<real> *pnt2, const real tol, Col2D<real> *col)
{
    real dX, dY;
    cassert_no_null(pnt1);
    cassert_no_null(pnt2);
    unref(col);
    dX = pnt2->x - pnt1->x;
    dY = pnt2->y - pnt1->y;
    if (dX * dX + dY * dY < tol * tol)
    {
        return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t col2d_point_pointf(const V2Df *pnt1, const V2Df *pnt2, const real32_t tol, Col2Df *col)
{
    return i_point_point<real32_t>((const V2D<real32_t> *)pnt1, (const V2D<real32_t> *)pnt2, tol, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_point_pointd(const V2Dd *pnt1, const V2Dd *pnt2, const real64_t tol, Col2Dd *col)
{
    return i_point_point<real64_t>((const V2D<real64_t> *)pnt1, (const V2D<real64_t> *)pnt2, tol, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_line_point(const V2D<real> *p0, const V2D<real> *p1, const V2D<real> *pnt, const real tol, Col2D<real> *col)
{
    cassert_no_null(p0);
    cassert_no_null(p1);
    cassert_no_null(pnt);

    V2D<real> ab(p1->x - p0->x, p1->y - p0->y);
    V2D<real> ac(pnt->x - p0->x, pnt->y - p0->y);
    V2D<real> bc(pnt->x - p1->x, pnt->y - p1->y);
    real e = V2D<real>::dot(&ac, &ab);
    real sqdist = 0;

    if (e <= 0)
    {
        sqdist = V2D<real>::dot(&ac, &ac);
    }
    else
    {
        real f = V2D<real>::dot(&ab, &ab);
        if (e >= f)
            sqdist = V2D<real>::dot(&bc, &bc);
        else
            sqdist = V2D<real>::dot(&ac, &ac) - e * e / f;
    }

    if (col != NULL)
        col->d = sqdist;

    if (sqdist < tol * tol)
    {
        return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_segment_point(const Seg2D<real> *seg, const V2D<real> *pnt, const real tol, Col2D<real> *col)
{
    cassert_no_null(seg);
    return i_line_point<real>(&seg->p0, &seg->p1, pnt, tol, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_segment_pointf(const Seg2Df *seg, const V2Df *pnt, const real32_t tol, Col2Df *col)
{
    return i_segment_point<real32_t>((const Seg2D<real32_t> *)seg, (const V2D<real32_t> *)pnt, tol, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_segment_pointd(const Seg2Dd *seg, const V2Dd *pnt, const real64_t tol, Col2Dd *col)
{
    return i_segment_point<real64_t>((const Seg2D<real64_t> *)seg, (const V2D<real64_t> *)pnt, tol, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_line_line(const V2D<real> *a1, const V2D<real> *a2, const V2D<real> *b1, const V2D<real> *b2, Col2D<real> *col)
{
    //intersection = Vector2.Zero;
    V2D<real> b(a2->x - a1->x, a2->y - a1->y);
    V2D<real> d(b2->x - b1->x, b2->y - b1->y);
    real bDotDPerp = b.x * d.y - b.y * d.x;

    // if b dot d == 0, it means the lines are parallel so have infinite intersection points
    if (bDotDPerp == 0)
        return FALSE;

    V2D<real> c(b1->x - a1->x, b1->y - a1->y);
    real t = (c.x * d.y - c.y * d.x) / bDotDPerp;
    if (t < 0 || t > 1)
        return FALSE;

    real u = (c.x * b.y - c.y * b.x) / bDotDPerp;
    if (u < 0 || u > 1)
        return FALSE;

    if (col != NULL)
    {
        col->p.x = a1->x + t * b.x;
        col->p.y = a1->y + t * b.y;
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_segment_segment(const Seg2D<real> *seg1, const Seg2D<real> *seg2, Col2D<real> *col)
{
    cassert_no_null(seg1);
    cassert_no_null(seg2);
    return i_line_line<real>(&seg1->p0, &seg1->p1, &seg2->p0, &seg2->p1, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_segment_segmentf(const Seg2Df *seg1, const Seg2Df *seg2, Col2Df *col)
{
    return i_segment_segment<real32_t>((const Seg2D<real32_t> *)seg1, (const Seg2D<real32_t> *)seg2, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_segment_segmentd(const Seg2Dd *seg1, const Seg2Dd *seg2, Col2Dd *col)
{
    return i_segment_segment<real64_t>((const Seg2D<real64_t> *)seg1, (const Seg2D<real64_t> *)seg2, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_circle_point(const Cir2D<real> *cir, const V2D<real> *p, Col2D<real> *col)
{
    register real dX, dY, dot;
    cassert_no_null(cir);
    cassert_no_null(p);
    dX = p->x - cir->c.x;
    dY = p->y - cir->c.y;
    dot = dX * dX + dY * dY;
    if (dot <= cir->r * cir->r)
    {
        if (col != NULL)
        {
            col->n = V2D<real>::unit(&cir->c, p, NULL);
            col->p.x = cir->c.x + col->n.x * cir->r;
            col->p.y = cir->c.y + col->n.y * cir->r;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t col2d_circle_pointf(const Cir2Df *cir, const V2Df *p, Col2Df *col)
{
    return i_circle_point<real32_t>((const Cir2D<real32_t> *)cir, (const V2D<real32_t> *)p, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_circle_pointd(const Cir2Dd *cir, const V2Dd *p, Col2Dd *col)
{
    return i_circle_point<real64_t>((const Cir2D<real64_t> *)cir, (const V2D<real64_t> *)p, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_circle_segment(const Cir2D<real> *cir, const Seg2D<real> *seg, Col2D<real> *col)
{
    cassert_no_null(cir);
    return i_segment_point<real>(seg, &cir->c, cir->r, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_circle_segmentf(const Cir2Df *cir, const Seg2Df *seg, Col2Df *col)
{
    return i_circle_segment<real32_t>((const Cir2D<real32_t> *)cir, (const Seg2D<real32_t> *)seg, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_circle_segmentd(const Cir2Dd *cir, const Seg2Dd *seg, Col2Dd *col)
{
    return i_circle_segment<real64_t>((const Cir2D<real64_t> *)cir, (const Seg2D<real64_t> *)seg, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_circle_circle(const Cir2D<real> *cir1, const Cir2D<real> *cir2, Col2D<real> *col)
{
    register real rt = 0;
    cassert_no_null(cir1);
    cassert_no_null(cir2);
    rt = cir1->r + cir2->r;
    rt *= rt;
    if (V2D<real>::sqdist(&cir1->c, &cir2->c) < rt)
    {
        if (col != NULL)
        {
            col->n = V2D<real>::unit(&cir1->c, &cir2->c, NULL);
            col->p.x = cir1->c.x + col->n.x * cir1->r;
            col->p.y = cir1->c.y + col->n.y * cir1->r;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t col2d_circle_circlef(const Cir2Df *cir1, const Cir2Df *cir2, Col2Df *col)
{
    return i_circle_circle<real32_t>((const Cir2D<real32_t> *)cir1, (const Cir2D<real32_t> *)cir2, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_circle_circled(const Cir2Dd *cir1, const Cir2Dd *cir2, Col2Dd *col)
{
    return i_circle_circle<real64_t>((const Cir2D<real64_t> *)cir1, (const Cir2D<real64_t> *)cir2, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_box_point(const Box2D<real> *b, const V2D<real> *p, Col2D<real> *col)
{
    cassert_no_null(b);
    cassert_no_null(p);
    if (col == NULL)
    {
        if (p->x < b->min.x)
            return FALSE;

        if (p->x > b->max.x)
            return FALSE;

        if (p->y < b->min.y)
            return FALSE;

        if (p->y > b->max.y)
            return FALSE;

        return TRUE;
    }
    else
    {
        real mind = (real)1e8, d;
        bool_t inside = TRUE;

        if (p->x < b->min.x)
        {
            inside = FALSE;
            d = b->min.x - p->x;
        }
        else
        {
            d = p->x - b->min.x;
        }

        if (d < mind)
            mind = d;

        if (p->x > b->max.x)
        {
            inside = FALSE;
            d = p->x - b->max.x;
        }
        else
        {
            d = b->max.x - p->x;
        }

        if (d < mind)
            mind = d;

        if (p->y < b->min.y)
        {
            inside = FALSE;
            d = b->min.y - p->y;
        }
        else
        {
            d = p->y - b->min.y;
        }

        if (d < mind)
            mind = d;

        if (p->y > b->max.y)
        {
            inside = FALSE;
            d = p->y - b->max.y;
        }
        else
        {
            d = b->max.y - p->y;
        }

        if (d < mind)
            mind = d;

        cassert(d >= 0);
        col->d = d;
        return inside;
    }
}

/*---------------------------------------------------------------------------*/

bool_t col2d_box_pointf(const Box2Df *box, const V2Df *pt, Col2Df *col)
{
    return i_box_point<real32_t>((const Box2D<real32_t> *)box, (const V2D<real32_t> *)pt, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_box_pointd(const Box2Dd *box, const V2Dd *pt, Col2Dd *col)
{
    return i_box_point<real64_t>((const Box2D<real64_t> *)box, (const V2D<real64_t> *)pt, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_box_segment(const Box2D<real> *box, const Seg2D<real> *seg, Col2D<real> *col)
{
    V2D<real> seg_axis;
    real seg_min;
    real seg_max;
    V2D<real> box_vertex[4];
    V2D<real> box_axis[2];
    real box_min[2];
    real box_max[2];

    cassert_no_null(box);
    cassert_no_null(seg);
    unref(col);

    box_axis[0].x = 1;
    box_axis[0].y = 0;
    box_axis[1].x = 0;
    box_axis[1].y = 1;
    box_min[0] = box->min.x;
    box_max[0] = box->max.x;
    box_min[1] = box->min.y;
    box_max[1] = box->max.y;

    if (i_sat_overlaps<real>(box_axis, box_min, box_max, 2, (const V2D<real> *)seg, 2) == FALSE)
        return FALSE;

    seg_axis.x = -(seg->p1.y - seg->p0.y);
    seg_axis.y = seg->p1.x - seg->p0.x;
    seg_min = seg_axis.x * seg->p0.x + seg_axis.y * seg->p0.y;
    seg_max = seg_axis.x * seg->p1.x + seg_axis.y * seg->p1.y;

    if (seg_min > seg_max)
    {
        real tmp = seg_max;
        seg_max = seg_min;
        seg_min = tmp;
    }

    box_vertex[0] = box->min;
    box_vertex[1].x = box->max.x;
    box_vertex[1].y = box->min.y;
    box_vertex[2] = box->max;
    box_vertex[3].x = box->min.x;
    box_vertex[3].y = box->max.y;

    if (i_sat_overlaps<real>(&seg_axis, &seg_min, &seg_max, 1, box_vertex, 4) == FALSE)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

bool_t col2d_box_segmentf(const Box2Df *box, const Seg2Df *seg, Col2Df *col)
{
    return i_box_segment<real32_t>((const Box2D<real32_t> *)box, (const Seg2D<real32_t> *)seg, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_box_segmentd(const Box2Dd *box, const Seg2Dd *seg, Col2Df *col)
{
    return i_box_segment<real64_t>((const Box2D<real64_t> *)box, (const Seg2D<real64_t> *)seg, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_box_circle(const Box2D<real> *box, const Cir2D<real> *cir, Col2D<real> *col)
{
    V2D<real> pt;

    cassert_no_null(box);
    cassert_no_null(cir);
    unref(col);

    pt = cir->c;

    if (pt.x < box->min.x)
        pt.x = box->min.x;
    else if (pt.x > box->max.x)
        pt.x = box->max.x;

    if (pt.y < box->min.y)
        pt.y = box->min.y;
    else if (pt.y > box->max.y)
        pt.y = box->max.y;

    return i_circle_point<real>(cir, &pt, NULL);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_box_circlef(const Box2Df *box, const Cir2Df *cir, Col2Df *col)
{
    return i_box_circle<real32_t>((const Box2D<real32_t> *)box, (const Cir2D<real32_t> *)cir, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_box_circled(const Box2Dd *box, const Cir2Dd *cir, Col2Dd *col)
{
    return i_box_circle<real64_t>((const Box2D<real64_t> *)box, (const Cir2D<real64_t> *)cir, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_box_box(const Box2D<real> *b0, const Box2D<real> *b1, Col2D<real> *col)
{
    cassert_no_null(b0);
    cassert_no_null(b1);
    unref(col);

    if (b0->min.x > b1->max.x)
        return FALSE;

    if (b1->min.x > b0->max.x)
        return FALSE;

    if (b0->min.y > b1->max.y)
        return FALSE;

    if (b1->min.y > b0->max.y)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

bool_t col2d_box_boxf(const Box2Df *b0, const Box2Df *b1, Col2Df *col)
{
    return i_box_box<real32_t>((const Box2D<real32_t> *)b0, (const Box2D<real32_t> *)b1, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_box_boxd(const Box2Dd *b0, const Box2Dd *b1, Col2Dd *col)
{
    return i_box_box<real64_t>((const Box2D<real64_t> *)b0, (const Box2D<real64_t> *)b1, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_obb_point(const OBB2D<real> *obb, const V2D<real> *pt, Col2D<real> *col)
{
    Box2D<real> b;
    V2D<real> npt;
    V2D<real> oc = OBB2D<real>::center(obb);
    register real ow = OBB2D<real>::width(obb);
    register real oh = OBB2D<real>::height(obb);
    register real oa = OBB2D<real>::angle(obb);
    cassert_no_null(pt);
    b.min.x = 0;
    b.min.y = 0;
    b.max.x = ow;
    b.max.y = oh;
    npt.x = pt->x - oc.x;
    npt.y = pt->y - oc.y;
    V2D<real>::rotate(&npt, -oa);
    npt.x += ow / 2;
    npt.y += oh / 2;
    return i_box_point<real>(&b, &npt, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_pointf(const OBB2Df *obb, const V2Df *pt, Col2Df *col)
{
    return i_obb_point<real32_t>((const OBB2D<real32_t> *)obb, (const V2D<real32_t> *)pt, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_pointd(const OBB2Dd *obb, const V2Dd *pt, Col2Dd *col)
{
    return i_obb_point<real64_t>((const OBB2D<real64_t> *)obb, (const V2D<real64_t> *)pt, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_sat_segment(const V2D<real> *sat_axis, const real *sat_min, const real *sat_max, const uint32_t sat_num_axis, const V2D<real> *sat_vertex, const uint32_t sat_num_vertices, const Seg2D<real> *seg, Col2D<real> *col)
{
    V2D<real> seg_axis;
    real seg_min;
    real seg_max;

    cassert_no_null(seg);
    unref(col);

    if (i_sat_overlaps<real>(sat_axis, sat_min, sat_max, sat_num_axis, (const V2D<real> *)seg, 2) == FALSE)
        return FALSE;

    seg_axis.x = -(seg->p1.y - seg->p0.y);
    seg_axis.y = seg->p1.x - seg->p0.x;
    seg_min = seg_axis.x * seg->p0.x + seg_axis.y * seg->p0.y;
    seg_max = seg_axis.x * seg->p1.x + seg_axis.y * seg->p1.y;

    if (seg_min > seg_max)
    {
        real tmp = seg_max;
        seg_max = seg_min;
        seg_min = tmp;
    }

    if (i_sat_overlaps<real>(&seg_axis, &seg_min, &seg_max, 1, sat_vertex, sat_num_vertices) == FALSE)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_obb_segment(const OBB2D<real> *obb, const Seg2D<real> *seg, Col2D<real> *col)
{
    const SATPoly<real> *sat = OBB2DI<real>::sat_poly(obb);
    cassert(sat->num_axis == 2);
    cassert(sat->num_vertices == 4);
    return i_sat_segment<real>(sat->axis, sat->min, sat->max, sat->num_axis, sat->vertex, sat->num_vertices, seg, col);
}
/*---------------------------------------------------------------------------*/

bool_t col2d_obb_segmentf(const OBB2Df *obb, const Seg2Df *seg, Col2Df *col)
{
    return i_obb_segment<real32_t>((const OBB2D<real32_t> *)obb, (const Seg2D<real32_t> *)seg, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_segmentd(const OBB2Dd *obb, const Seg2Dd *seg, Col2Dd *col)
{
    return i_obb_segment<real64_t>((const OBB2D<real64_t> *)obb, (const Seg2D<real64_t> *)seg, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_obb_circle(const OBB2D<real> *obb, const Cir2D<real> *cir, Col2D<real> *col)
{
    Box2D<real> b;
    Cir2D<real> nc;
    V2D<real> oc = OBB2D<real>::center(obb);
    register real ow = OBB2D<real>::width(obb);
    register real oh = OBB2D<real>::height(obb);
    register real oa = OBB2D<real>::angle(obb);
    cassert_no_null(cir);
    b.min.x = 0;
    b.min.y = 0;
    b.max.x = ow;
    b.max.y = oh;
    nc.c.x = cir->c.x - oc.x;
    nc.c.y = cir->c.y - oc.y;
    V2D<real>::rotate(&nc.c, -oa);
    nc.c.x += ow / 2;
    nc.c.y += oh / 2;
    nc.r = cir->r;
    return i_box_circle<real>(&b, &nc, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_circlef(const OBB2Df *obb, const Cir2Df *cir, Col2Df *col)
{
    return i_obb_circle<real32_t>((const OBB2D<real32_t> *)obb, (const Cir2D<real32_t> *)cir, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_circled(const OBB2Dd *obb, const Cir2Dd *cir, Col2Dd *col)
{
    return i_obb_circle<real64_t>((const OBB2D<real64_t> *)obb, (const Cir2D<real64_t> *)cir, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_sat_box(const V2D<real> *sat_axis, const real *sat_min, const real *sat_max, const uint32_t sat_num_axis, const V2D<real> *sat_vertex, const uint32_t sat_num_vertices, const Box2D<real> *box, Col2D<real> *col)
{
    V2D<real> box_vertex[4];
    V2D<real> box_axis[2];
    real box_min[2];
    real box_max[2];

    cassert_no_null(box);
    unref(col);
    box_vertex[0] = box->min;
    box_vertex[1].x = box->max.x;
    box_vertex[1].y = box->min.y;
    box_vertex[2] = box->max;
    box_vertex[3].x = box->min.x;
    box_vertex[3].y = box->max.y;

    if (i_sat_overlaps<real>(sat_axis, sat_min, sat_max, sat_num_axis, box_vertex, 4) == FALSE)
        return FALSE;

    box_axis[0].x = 1;
    box_axis[0].y = 0;
    box_axis[1].x = 0;
    box_axis[1].y = 1;
    box_min[0] = box->min.x;
    box_max[0] = box->max.x;
    box_min[1] = box->min.y;
    box_max[1] = box->max.y;

    if (i_sat_overlaps<real>(box_axis, box_min, box_max, 2, sat_vertex, sat_num_vertices) == FALSE)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_obb_box(const OBB2D<real> *obb, const Box2D<real> *box, Col2D<real> *col)
{
    const SATPoly<real> *sat = OBB2DI<real>::sat_poly(obb);
    cassert(sat->num_axis == 2);
    cassert(sat->num_vertices == 4);
    return i_sat_box<real>(sat->axis, sat->min, sat->max, sat->num_axis, sat->vertex, sat->num_vertices, box, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_boxf(const OBB2Df *obb, const Box2Df *box, Col2Df *col)
{
    return i_obb_box<real32_t>((const OBB2D<real32_t> *)obb, (const Box2D<real32_t> *)box, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_boxd(const OBB2Dd *obb, const Box2Dd *box, Col2Dd *col)
{
    return i_obb_box<real64_t>((const OBB2D<real64_t> *)obb, (const Box2D<real64_t> *)box, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/
//#include "bstd.h"
//template<typename real>
//static void i_dump(const SATPoly<real> *poly)
//{
//    register uint32_t i = 0;
//    bstd_printf("Vertices: ");
//    for (i = 0; i < poly->num_vertices; ++i)
//    {
//        bstd_printf("(%.2f,%2.f)", poly->vertex[i].x, poly->vertex[i].y);
//        if (i < poly->num_vertices - 1)
//            bstd_printf(", ");
//    }
//
//    bstd_printf("\n");
//    bstd_printf("Axis: ");
//    for (i = 0; i < poly->num_axis; ++i)
//    {
//        bstd_printf("(%.2f,%2.f)", poly->axis[i].x, poly->axis[i].y);
//        if (i < poly->num_axis - 1)
//            bstd_printf(", ");
//    }
//
//    bstd_printf("\n");
//    bstd_printf("Limits: ");
//    for (i = 0; i < poly->num_axis; ++i)
//    {
//        bstd_printf("Min: %.2f Max:%2.f\n", poly->min[i], poly->max[i]);
//    }
//
//    bstd_printf("\n");
//}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_sat_sat(const SATPoly<real> *sat1, const SATPoly<real> *sat2, Col2D<real> *col)
{
    cassert_no_null(sat1);
    cassert_no_null(sat2);
    unref(col);

    if (i_sat_overlaps<real>(sat1->axis, sat1->min, sat1->max, sat1->num_axis, sat2->vertex, sat2->num_vertices) == FALSE)
        return FALSE;

    if (i_sat_overlaps<real>(sat2->axis, sat2->min, sat2->max, sat2->num_axis, sat1->vertex, sat1->num_vertices) == FALSE)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_sat1_sat(const V2D<real> *sat1_axis, const real *sat1_min, const real *sat1_max, const uint32_t sat1_num_axis, const V2D<real> *sat1_vertex, const uint32_t sat1_num_vertices, const SATPoly<real> *sat2, Col2D<real> *col)
{
    cassert_no_null(sat2);
    unref(col);

    if (i_sat_overlaps<real>(sat1_axis, sat1_min, sat1_max, sat1_num_axis, sat2->vertex, sat2->num_vertices) == FALSE)
        return FALSE;

    if (i_sat_overlaps<real>(sat2->axis, sat2->min, sat2->max, sat2->num_axis, sat1_vertex, sat1_num_vertices) == FALSE)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_sat2_sat(
    const V2D<real> *sat1_axis, const real *sat1_min, const real *sat1_max, const uint32_t sat1_num_axis, const V2D<real> *sat1_vertex, const uint32_t sat1_num_vertices,
    const V2D<real> *sat2_axis, const real *sat2_min, const real *sat2_max, const uint32_t sat2_num_axis, const V2D<real> *sat2_vertex, const uint32_t sat2_num_vertices,
    Col2D<real> *col)
{
    unref(col);

    if (i_sat_overlaps<real>(sat1_axis, sat1_min, sat1_max, sat1_num_axis, sat2_vertex, sat2_num_vertices) == FALSE)
        return FALSE;

    if (i_sat_overlaps<real>(sat2_axis, sat2_min, sat2_max, sat2_num_axis, sat1_vertex, sat1_num_vertices) == FALSE)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_obb_obb(const OBB2D<real> *obb1, const OBB2D<real> *obb2, Col2D<real> *col)
{
    const SATPoly<real> *sat1 = OBB2DI<real>::sat_poly(obb1);
    const SATPoly<real> *sat2 = OBB2DI<real>::sat_poly(obb2);
    cassert(sat1->num_axis == 2);
    cassert(sat2->num_axis == 2);
    cassert(sat1->num_vertices == 4);
    cassert(sat2->num_vertices == 4);
    return i_sat_sat<real>(sat1, sat2, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_obbf(const OBB2Df *obb1, const OBB2Df *obb2, Col2Df *col)
{
    return i_obb_obb<real32_t>((const OBB2D<real32_t> *)obb1, (const OBB2D<real32_t> *)obb2, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_obb_obbd(const OBB2Dd *obb1, const OBB2Dd *obb2, Col2Dd *col)
{
    return i_obb_obb<real64_t>((const OBB2D<real64_t> *)obb1, (const OBB2D<real64_t> *)obb2, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static __INLINE bool_t i_sign(const V2D<real> *p1, const V2D<real> *p2, const V2D<real> *p3)
{
    return ((p1->x - p3->x) * (p2->y - p3->y) - (p2->x - p3->x) * (p1->y - p3->y)) > 0 ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_tri_point(const Tri2D<real> *tri, const V2D<real> *pnt, Col2D<real> *col)
{
    bool_t sign;

    cassert_no_null(tri);
    cassert_no_null(pnt);
    unref(col);
    sign = i_sign<real>(pnt, &tri->p0, &tri->p1);

    if (i_sign<real>(pnt, &tri->p1, &tri->p2) != sign)
        return FALSE;

    if (i_sign<real>(pnt, &tri->p2, &tri->p0) != sign)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_pointf(const Tri2Df *tri, const V2Df *pnt, Col2Df *col)
{
    return i_tri_point<real32_t>((const Tri2D<real32_t> *)tri, (const V2D<real32_t> *)pnt, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_pointd(const Tri2Dd *tri, const V2Dd *pnt, Col2Dd *col)
{
    return i_tri_point<real64_t>((const Tri2D<real64_t> *)tri, (const V2D<real64_t> *)pnt, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static __INLINE void i_tri_sat(const Tri2D<real> *tri, const V2D<real> **vt, V2D<real> *a, real *min, real *max)
{
    const V2D<real> *v;
    cassert_no_null(tri);
    v = (const V2D<real> *)tri;
    a[0].x = -(v[1].y - v[0].y);
    a[0].y = v[1].x - v[0].x;
    a[1].x = -(v[2].y - v[1].y);
    a[1].y = v[2].x - v[1].x;
    a[2].x = -(v[0].y - v[2].y);
    a[2].y = v[0].x - v[2].x;
    *vt = v;
    SATPoly<real>::limits(v, a, 3, 3, min, max);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_tri_segment(const Tri2D<real> *tri, const Seg2D<real> *seg, Col2D<real> *col)
{
    const V2D<real> *v = NULL;
    V2D<real> a[3];
    real sat_min[3];
    real sat_max[3];
    i_tri_sat<real>(tri, &v, a, sat_min, sat_max);
    return i_sat_segment<real>(a, sat_min, sat_max, 3, v, 3, seg, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_segmentf(const Tri2Df *tri, const Seg2Df *seg, Col2Df *col)
{
    return i_tri_segment<real32_t>((const Tri2D<real32_t> *)tri, (const Seg2D<real32_t> *)seg, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_segmentd(const Tri2Dd *tri, const Seg2Dd *seg, Col2Dd *col)
{
    return i_tri_segment<real64_t>((const Tri2D<real64_t> *)tri, (const Seg2D<real64_t> *)seg, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_tri_circle(const Tri2D<real> *tri, const Cir2D<real> *cir, Col2D<real> *col)
{
    cassert_no_null(tri);
    cassert_no_null(cir);

    if (i_line_point<real>(&tri->p0, &tri->p1, &cir->c, cir->r, col) == TRUE)
        return TRUE;

    if (i_line_point<real>(&tri->p1, &tri->p2, &cir->c, cir->r, col) == TRUE)
        return TRUE;

    if (i_line_point<real>(&tri->p2, &tri->p0, &cir->c, cir->r, col) == TRUE)
        return TRUE;

    return i_tri_point<real>(tri, &cir->c, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_circlef(const Tri2Df *tri, const Cir2Df *cir, Col2Df *col)
{
    return i_tri_circle<real32_t>((const Tri2D<real32_t> *)tri, (const Cir2D<real32_t> *)cir, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_circled(const Tri2Dd *tri, const Cir2Df *cir, Col2Df *col)
{
    return i_tri_circle<real64_t>((const Tri2D<real64_t> *)tri, (const Cir2D<real64_t> *)cir, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_tri_box(const Tri2D<real> *tri, const Box2D<real> *box, Col2D<real> *col)
{
    const V2D<real> *v = NULL;
    V2D<real> a[3];
    real sat_min[3];
    real sat_max[3];
    i_tri_sat<real>(tri, &v, a, sat_min, sat_max);
    return i_sat_box<real>(a, sat_min, sat_max, 3, v, 3, box, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_boxf(const Tri2Df *tri, const Box2Df *box, Col2Df *col)
{
    return i_tri_box<real32_t>((const Tri2D<real32_t> *)tri, (const Box2D<real32_t> *)box, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_boxd(const Tri2Dd *tri, const Box2Df *box, Col2Df *col)
{
    return i_tri_box<real64_t>((const Tri2D<real64_t> *)tri, (const Box2D<real64_t> *)box, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_tri_obb(const Tri2D<real> *tri, const OBB2D<real> *obb, Col2D<real> *col)
{
    const V2D<real> *v = NULL;
    V2D<real> a[3];
    real sat_min[3];
    real sat_max[3];
    const SATPoly<real> *sat_obb = OBB2DI<real>::sat_poly(obb);
    i_tri_sat<real>(tri, &v, a, sat_min, sat_max);
    cassert(sat_obb->num_axis == 2);
    cassert(sat_obb->num_vertices == 4);
    return i_sat1_sat<real>(a, sat_min, sat_max, 3, v, 3, sat_obb, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_obbf(const Tri2Df *tri, const OBB2Df *obb, Col2Df *col)
{
    return i_tri_obb<real32_t>((const Tri2D<real32_t> *)tri, (const OBB2D<real32_t> *)obb, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_obbd(const Tri2Dd *tri, const OBB2Dd *obb, Col2Dd *col)
{
    return i_tri_obb<real64_t>((const Tri2D<real64_t> *)tri, (const OBB2D<real64_t> *)obb, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_tri_tri(const Tri2D<real> *tri1, const Tri2D<real> *tri2, Col2D<real> *col)
{
    const V2D<real> *v1 = NULL, *v2 = NULL;
    V2D<real> a1[3], a2[3];
    real sat_min1[3], sat_min2[3];
    real sat_max1[3], sat_max2[3];
    i_tri_sat<real>(tri1, &v1, a1, sat_min1, sat_max1);
    i_tri_sat<real>(tri2, &v2, a2, sat_min2, sat_max2);
    return i_sat2_sat<real>(a1, sat_min1, sat_max1, 3, v1, 3, a2, sat_min2, sat_max2, 3, v2, 3, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_trif(const Tri2Df *tri1, const Tri2Df *tri2, Col2Df *col)
{
    return i_tri_tri<real32_t>((const Tri2D<real32_t> *)tri1, (const Tri2D<real32_t> *)tri2, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_tri_trid(const Tri2Dd *tri1, const Tri2Dd *tri2, Col2Dd *col)
{
    return i_tri_tri<real64_t>((const Tri2D<real64_t> *)tri1, (const Tri2D<real64_t> *)tri2, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

// http://www.eecs.umich.edu/courses/eecs380/HANDOUTS/PROJ2/InsidePoly.html
template <typename real>
static bool_t i_point_in_poly(const V2D<real> *v, const uint32_t n, const V2D<real> *pt, Col2D<real> *col)
{
    register uint32_t i, j;
    bool_t c = FALSE;

    cassert_no_null(v);
    unref(col);

    for (i = 0, j = n - 1; i < n; j = i++)
    {
        if ((((v[i].y <= pt->y) && (pt->y < v[j].y)) || ((v[j].y <= pt->y) && (pt->y < v[i].y))) &&
            (pt->x < (v[j].x - v[i].x) * (pt->y - v[i].y) / (v[j].y - v[i].y) + v[i].x))
            c = (bool_t)!c;
    }

    return c;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_poly_point(const Pol2D<real> *poly, const V2D<real> *pt, Col2D<real> *col)
{
    const V2D<real> *v = Pol2D<real>::points(poly);
    uint32_t n = Pol2D<real>::n(poly);
    return i_point_in_poly<real>(v, n, pt, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_pointf(const Pol2Df *poly, const V2Df *pt, Col2Df *col)
{
    return i_poly_point<real32_t>((const Pol2D<real32_t> *)poly, (const V2D<real32_t> *)pt, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_pointd(const Pol2Dd *poly, const V2Dd *pt, Col2Dd *col)
{
    return i_poly_point<real64_t>((const Pol2D<real64_t> *)poly, (const V2D<real64_t> *)pt, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_poly_segment(const Pol2D<real> *poly, const Seg2D<real> *seg, Col2D<real> *col)
{
    if (Pol2D<real>::convex(poly) == TRUE)
    {
        const SATPoly<real> *sat = Pol2DI<real>::sat_poly(poly);
        return i_sat_segment<real>(sat->axis, sat->min, sat->max, sat->num_axis, sat->vertex, sat->num_vertices, seg, col);
    }
    else
    {
        const ArrPt<SATPoly<real> > *sats = Pol2DI<real>::convex_sat_polys((Pol2D<real> *)poly);
        const SATPoly<real> **sat = ArrPt<SATPoly<real> >::all(sats);
        uint32_t i, n = ArrPt<SATPoly<real> >::size(sats);

        for (i = 0; i < n; ++i)
        {
            if (i_sat_segment<real>(sat[i]->axis, sat[i]->min, sat[i]->max, sat[i]->num_axis, sat[i]->vertex, sat[i]->num_vertices, seg, col) == TRUE)
                return TRUE;
        }

        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_segmentf(const Pol2Df *poly, const Seg2Df *seg, Col2Df *col)
{
    return i_poly_segment<real32_t>((const Pol2D<real32_t> *)poly, (const Seg2D<real32_t> *)seg, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_segmentd(const Pol2Dd *poly, const Seg2Dd *seg, Col2Dd *col)
{
    return i_poly_segment<real64_t>((const Pol2D<real64_t> *)poly, (const Seg2D<real64_t> *)seg, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_poly_circle(const Pol2D<real> *poly, const Cir2D<real> *cir, Col2D<real> *col)
{
    const V2D<real> *v = Pol2D<real>::points(poly);
    uint32_t n = Pol2D<real>::n(poly);
    register uint32_t i;

    cassert_no_null(cir);

    for (i = 0; i < n; ++i)
    {
        if (i_line_point<real>(&v[i], &v[(i + 1) % n], &cir->c, cir->r, col) == TRUE)
            return TRUE;
    }

    return i_point_in_poly<real>(v, n, &cir->c, col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_circlef(const Pol2Df *poly, const Cir2Df *cir, Col2Df *col)
{
    return i_poly_circle<real32_t>((const Pol2D<real32_t> *)poly, (const Cir2D<real32_t> *)cir, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_circled(const Pol2Dd *poly, const Cir2Dd *cir, Col2Dd *col)
{
    return i_poly_circle<real64_t>((const Pol2D<real64_t> *)poly, (const Cir2D<real64_t> *)cir, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_poly_box(const Pol2D<real> *poly, const Box2D<real> *box, Col2D<real> *col)
{
    if (Pol2D<real>::convex(poly) == TRUE)
    {
        const SATPoly<real> *sat = Pol2DI<real>::sat_poly(poly);
        return i_sat_box<real>(sat->axis, sat->min, sat->max, sat->num_axis, sat->vertex, sat->num_vertices, box, col);
    }
    else
    {
        const ArrPt<SATPoly<real> > *sats = Pol2DI<real>::convex_sat_polys((Pol2D<real> *)poly);
        const SATPoly<real> **sat = ArrPt<SATPoly<real> >::all(sats);
        uint32_t i, n = ArrPt<SATPoly<real> >::size(sats);

        for (i = 0; i < n; ++i)
        {
            if (i_sat_box<real>(sat[i]->axis, sat[i]->min, sat[i]->max, sat[i]->num_axis, sat[i]->vertex, sat[i]->num_vertices, box, col) == TRUE)
                return TRUE;
        }

        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_boxf(const Pol2Df *poly, const Box2Df *box, Col2Df *col)
{
    return i_poly_box<real32_t>((const Pol2D<real32_t> *)poly, (const Box2D<real32_t> *)box, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_boxd(const Pol2Dd *poly, const Box2Dd *box, Col2Dd *col)
{
    return i_poly_box<real64_t>((const Pol2D<real64_t> *)poly, (const Box2D<real64_t> *)box, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_poly_obb(const Pol2D<real> *poly, const OBB2D<real> *obb, Col2D<real> *col)
{
    const SATPoly<real> *sat_obb = OBB2DI<real>::sat_poly(obb);
    cassert(sat_obb->num_axis == 2);
    cassert(sat_obb->num_vertices == 4);

    if (Pol2D<real>::convex(poly) == TRUE)
    {
        const SATPoly<real> *sat = Pol2DI<real>::sat_poly(poly);
        return i_sat_sat<real>(sat, sat_obb, col);
    }
    else
    {
        const ArrPt<SATPoly<real> > *sats = Pol2DI<real>::convex_sat_polys((Pol2D<real> *)poly);
        const SATPoly<real> **sat = ArrPt<SATPoly<real> >::all(sats);
        uint32_t i, n = ArrPt<SATPoly<real> >::size(sats);

        for (i = 0; i < n; ++i)
        {
            if (i_sat_sat<real>(sat[i], sat_obb, col) == TRUE)
                return TRUE;
        }

        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_obbf(const Pol2Df *poly, const OBB2Df *obb, Col2Df *col)
{
    return i_poly_obb<real32_t>((const Pol2D<real32_t> *)poly, (const OBB2D<real32_t> *)obb, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_obbd(const Pol2Dd *poly, const OBB2Dd *obb, Col2Dd *col)
{
    return i_poly_obb<real64_t>((const Pol2D<real64_t> *)poly, (const OBB2D<real64_t> *)obb, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_poly_tri(const Pol2D<real> *poly, const Tri2D<real> *tri, Col2D<real> *col)
{
    const V2D<real> *v = NULL;
    V2D<real> a[3];
    real sat_min[3];
    real sat_max[3];
    i_tri_sat<real>(tri, &v, a, sat_min, sat_max);

    if (Pol2D<real>::convex(poly) == TRUE)
    {
        const SATPoly<real> *sat = Pol2DI<real>::sat_poly(poly);
        return i_sat1_sat<real>(a, sat_min, sat_max, 3, v, 3, sat, col);
    }
    else
    {
        const ArrPt<SATPoly<real> > *sats = Pol2DI<real>::convex_sat_polys((Pol2D<real> *)poly);
        const SATPoly<real> **sat = ArrPt<SATPoly<real> >::all(sats);
        uint32_t i, n = ArrPt<SATPoly<real> >::size(sats);

        for (i = 0; i < n; ++i)
        {
            if (i_sat1_sat<real>(a, sat_min, sat_max, 3, v, 3, sat[i], col) == TRUE)
                return TRUE;
        }

        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_trif(const Pol2Df *poly, const Tri2Df *tri, Col2Df *col)
{
    return i_poly_tri<real32_t>((const Pol2D<real32_t> *)poly, (const Tri2D<real32_t> *)tri, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_trid(const Pol2Dd *poly, const Tri2Dd *tri, Col2Dd *col)
{
    return i_poly_tri<real64_t>((const Pol2D<real64_t> *)poly, (const Tri2D<real64_t> *)tri, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_poly_poly(const Pol2D<real> *pol1, const Pol2D<real> *pol2, Col2D<real> *col)
{
    if (Pol2D<real>::convex(pol1) == TRUE)
    {
        const SATPoly<real> *sat1 = Pol2DI<real>::sat_poly(pol1);

        if (Pol2D<real>::convex(pol2) == TRUE)
        {
            const SATPoly<real> *sat2 = Pol2DI<real>::sat_poly(pol2);
            return i_sat_sat<real>(sat1, sat2, col);
        }
        else
        {
            const ArrPt<SATPoly<real> > *sats = Pol2DI<real>::convex_sat_polys((Pol2D<real> *)pol2);
            const SATPoly<real> **sat = ArrPt<SATPoly<real> >::all(sats);
            uint32_t i, n = ArrPt<SATPoly<real> >::size(sats);

            for (i = 0; i < n; ++i)
            {
                if (i_sat_sat<real>(sat1, sat[i], col) == TRUE)
                    return TRUE;
            }

            return FALSE;
        }
    }
    else
    {
        const ArrPt<SATPoly<real> > *sats1 = Pol2DI<real>::convex_sat_polys((Pol2D<real> *)pol1);
        const SATPoly<real> **sat1 = ArrPt<SATPoly<real> >::all(sats1);
        uint32_t n1 = ArrPt<SATPoly<real> >::size(sats1);
        uint32_t i;
        if (Pol2D<real>::convex(pol2) == TRUE)
        {
            const SATPoly<real> *sat2 = Pol2DI<real>::sat_poly(pol2);
            for (i = 0; i < n1; ++i)
            {
                if (i_sat_sat<real>(sat1[i], sat2, col) == TRUE)
                    return TRUE;
            }

            return FALSE;
        }
        else
        {
            const ArrPt<SATPoly<real> > *sats2 = Pol2DI<real>::convex_sat_polys((Pol2D<real> *)pol2);
            const SATPoly<real> **sat2 = ArrPt<SATPoly<real> >::all(sats2);
            uint32_t n2 = ArrPt<SATPoly<real> >::size(sats2);
            uint32_t j;

            for (i = 0; i < n1; ++i)
                for (j = 0; j < n2; ++j)
                {
                    if (i_sat_sat<real>(sat1[i], sat2[j], col) == TRUE)
                        return TRUE;
                }

            return FALSE;
        }
    }
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_polyf(const Pol2Df *poly1, const Pol2Df *poly2, Col2Df *col)
{
    return i_poly_poly<real32_t>((const Pol2D<real32_t> *)poly1, (const Pol2D<real32_t> *)poly2, (Col2D<real32_t> *)col);
}

/*---------------------------------------------------------------------------*/

bool_t col2d_poly_polyd(const Pol2Dd *poly1, const Pol2Dd *poly2, Col2Dd *col)
{
    return i_poly_poly<real64_t>((const Pol2D<real64_t> *)poly1, (const Pol2D<real64_t> *)poly2, (Col2D<real64_t> *)col);
}

/*---------------------------------------------------------------------------*/

template <>
bool_t (*Col2D<real32_t>::point_point)(const V2D<real32_t> *, const V2D<real32_t> *, const real32_t, Col2D<real32_t> *) = i_point_point<real32_t>;

template <>
bool_t (*Col2D<real64_t>::point_point)(const V2D<real64_t> *, const V2D<real64_t> *, const real64_t, Col2D<real64_t> *) = i_point_point<real64_t>;

template <>
bool_t (*Col2D<real32_t>::segment_point)(const Seg2D<real32_t> *, const V2D<real32_t> *, const real32_t, Col2D<real32_t> *) = i_segment_point<real32_t>;

template <>
bool_t (*Col2D<real64_t>::segment_point)(const Seg2D<real64_t> *, const V2D<real64_t> *, const real64_t, Col2D<real64_t> *) = i_segment_point<real64_t>;

template <>
bool_t (*Col2D<real32_t>::segment_segment)(const Seg2D<real32_t> *, const Seg2D<real32_t> *, Col2D<real32_t> *) = i_segment_segment<real32_t>;

template <>
bool_t (*Col2D<real64_t>::segment_segment)(const Seg2D<real64_t> *, const Seg2D<real64_t> *, Col2D<real64_t> *) = i_segment_segment<real64_t>;

template <>
bool_t (*Col2D<real32_t>::circle_point)(const Cir2D<real32_t> *, const V2D<real32_t> *, Col2D<real32_t> *) = i_circle_point<real32_t>;

template <>
bool_t (*Col2D<real64_t>::circle_point)(const Cir2D<real64_t> *, const V2D<real64_t> *, Col2D<real64_t> *) = i_circle_point<real64_t>;

template <>
bool_t (*Col2D<real32_t>::circle_segment)(const Cir2D<real32_t> *, const Seg2D<real32_t> *, Col2D<real32_t> *) = i_circle_segment<real32_t>;

template <>
bool_t (*Col2D<real64_t>::circle_segment)(const Cir2D<real64_t> *, const Seg2D<real64_t> *, Col2D<real64_t> *) = i_circle_segment<real64_t>;

template <>
bool_t (*Col2D<real32_t>::circle_circle)(const Cir2D<real32_t> *, const Cir2D<real32_t> *, Col2D<real32_t> *) = i_circle_circle<real32_t>;

template <>
bool_t (*Col2D<real64_t>::circle_circle)(const Cir2D<real64_t> *, const Cir2D<real64_t> *, Col2D<real64_t> *) = i_circle_circle<real64_t>;

template <>
bool_t (*Col2D<real32_t>::box_point)(const Box2D<real32_t> *, const V2D<real32_t> *, Col2D<real32_t> *) = i_box_point<real32_t>;

template <>
bool_t (*Col2D<real64_t>::box_point)(const Box2D<real64_t> *, const V2D<real64_t> *, Col2D<real64_t> *) = i_box_point<real64_t>;

template <>
bool_t (*Col2D<real32_t>::box_segment)(const Box2D<real32_t> *, const Seg2D<real32_t> *, Col2D<real32_t> *) = i_box_segment<real32_t>;

template <>
bool_t (*Col2D<real64_t>::box_segment)(const Box2D<real64_t> *, const Seg2D<real64_t> *, Col2D<real64_t> *) = i_box_segment<real64_t>;

template <>
bool_t (*Col2D<real32_t>::box_circle)(const Box2D<real32_t> *, const Cir2D<real32_t> *, Col2D<real32_t> *) = i_box_circle<real32_t>;

template <>
bool_t (*Col2D<real64_t>::box_circle)(const Box2D<real64_t> *, const Cir2D<real64_t> *, Col2D<real64_t> *) = i_box_circle<real64_t>;

template <>
bool_t (*Col2D<real32_t>::box_box)(const Box2D<real32_t> *, const Box2D<real32_t> *, Col2D<real32_t> *) = i_box_box<real32_t>;

template <>
bool_t (*Col2D<real64_t>::box_box)(const Box2D<real64_t> *, const Box2D<real64_t> *, Col2D<real64_t> *) = i_box_box<real64_t>;

template <>
bool_t (*Col2D<real32_t>::obb_point)(const OBB2D<real32_t> *, const V2D<real32_t> *, Col2D<real32_t> *) = i_obb_point<real32_t>;

template <>
bool_t (*Col2D<real64_t>::obb_point)(const OBB2D<real64_t> *, const V2D<real64_t> *, Col2D<real64_t> *) = i_obb_point<real64_t>;

template <>
bool_t (*Col2D<real32_t>::obb_segment)(const OBB2D<real32_t> *, const Seg2D<real32_t> *, Col2D<real32_t> *) = i_obb_segment<real32_t>;

template <>
bool_t (*Col2D<real64_t>::obb_segment)(const OBB2D<real64_t> *, const Seg2D<real64_t> *, Col2D<real64_t> *) = i_obb_segment<real64_t>;

template <>
bool_t (*Col2D<real32_t>::obb_circle)(const OBB2D<real32_t> *, const Cir2D<real32_t> *, Col2D<real32_t> *) = i_obb_circle<real32_t>;

template <>
bool_t (*Col2D<real64_t>::obb_circle)(const OBB2D<real64_t> *, const Cir2D<real64_t> *, Col2D<real64_t> *) = i_obb_circle<real64_t>;

template <>
bool_t (*Col2D<real32_t>::obb_box)(const OBB2D<real32_t> *, const Box2D<real32_t> *, Col2D<real32_t> *) = i_obb_box<real32_t>;

template <>
bool_t (*Col2D<real64_t>::obb_box)(const OBB2D<real64_t> *, const Box2D<real64_t> *, Col2D<real64_t> *) = i_obb_box<real64_t>;

template <>
bool_t (*Col2D<real32_t>::obb_obb)(const OBB2D<real32_t> *, const OBB2D<real32_t> *, Col2D<real32_t> *) = i_obb_obb<real32_t>;

template <>
bool_t (*Col2D<real64_t>::obb_obb)(const OBB2D<real64_t> *, const OBB2D<real64_t> *, Col2D<real64_t> *) = i_obb_obb<real64_t>;

template <>
bool_t (*Col2D<real32_t>::tri_point)(const Tri2D<real32_t> *, const V2D<real32_t> *, Col2D<real32_t> *) = i_tri_point<real32_t>;

template <>
bool_t (*Col2D<real64_t>::tri_point)(const Tri2D<real64_t> *, const V2D<real64_t> *, Col2D<real64_t> *) = i_tri_point<real64_t>;

template <>
bool_t (*Col2D<real32_t>::tri_segment)(const Tri2D<real32_t> *, const Seg2D<real32_t> *, Col2D<real32_t> *) = i_tri_segment<real32_t>;

template <>
bool_t (*Col2D<real64_t>::tri_segment)(const Tri2D<real64_t> *, const Seg2D<real64_t> *, Col2D<real64_t> *) = i_tri_segment<real64_t>;

template <>
bool_t (*Col2D<real32_t>::tri_circle)(const Tri2D<real32_t> *, const Cir2D<real32_t> *, Col2D<real32_t> *) = i_tri_circle<real32_t>;

template <>
bool_t (*Col2D<real64_t>::tri_circle)(const Tri2D<real64_t> *, const Cir2D<real64_t> *, Col2D<real64_t> *) = i_tri_circle<real64_t>;

template <>
bool_t (*Col2D<real32_t>::tri_box)(const Tri2D<real32_t> *, const Box2D<real32_t> *, Col2D<real32_t> *) = i_tri_box<real32_t>;

template <>
bool_t (*Col2D<real64_t>::tri_box)(const Tri2D<real64_t> *, const Box2D<real64_t> *, Col2D<real64_t> *) = i_tri_box<real64_t>;

template <>
bool_t (*Col2D<real32_t>::tri_tri)(const Tri2D<real32_t> *, const Tri2D<real32_t> *, Col2D<real32_t> *) = i_tri_tri<real32_t>;

template <>
bool_t (*Col2D<real64_t>::tri_tri)(const Tri2D<real64_t> *, const Tri2D<real64_t> *, Col2D<real64_t> *) = i_tri_tri<real64_t>;

template <>
bool_t (*Col2D<real32_t>::tri_obb)(const Tri2D<real32_t> *, const OBB2D<real32_t> *, Col2D<real32_t> *) = i_tri_obb<real32_t>;

template <>
bool_t (*Col2D<real64_t>::tri_obb)(const Tri2D<real64_t> *, const OBB2D<real64_t> *, Col2D<real64_t> *) = i_tri_obb<real64_t>;

template <>
bool_t (*Col2D<real32_t>::poly_point)(const Pol2D<real32_t> *, const V2D<real32_t> *, Col2D<real32_t> *) = i_poly_point<real32_t>;

template <>
bool_t (*Col2D<real64_t>::poly_point)(const Pol2D<real64_t> *, const V2D<real64_t> *, Col2D<real64_t> *) = i_poly_point<real64_t>;

template <>
bool_t (*Col2D<real32_t>::poly_segment)(const Pol2D<real32_t> *, const Seg2D<real32_t> *, Col2D<real32_t> *) = i_poly_segment<real32_t>;

template <>
bool_t (*Col2D<real64_t>::poly_segment)(const Pol2D<real64_t> *, const Seg2D<real64_t> *, Col2D<real64_t> *) = i_poly_segment<real64_t>;

template <>
bool_t (*Col2D<real32_t>::poly_circle)(const Pol2D<real32_t> *, const Cir2D<real32_t> *, Col2D<real32_t> *) = i_poly_circle<real32_t>;

template <>
bool_t (*Col2D<real64_t>::poly_circle)(const Pol2D<real64_t> *, const Cir2D<real64_t> *, Col2D<real64_t> *) = i_poly_circle<real64_t>;

template <>
bool_t (*Col2D<real32_t>::poly_box)(const Pol2D<real32_t> *, const Box2D<real32_t> *, Col2D<real32_t> *) = i_poly_box<real32_t>;

template <>
bool_t (*Col2D<real64_t>::poly_box)(const Pol2D<real64_t> *, const Box2D<real64_t> *, Col2D<real64_t> *) = i_poly_box<real64_t>;

template <>
bool_t (*Col2D<real32_t>::poly_obb)(const Pol2D<real32_t> *, const OBB2D<real32_t> *, Col2D<real32_t> *) = i_poly_obb<real32_t>;

template <>
bool_t (*Col2D<real64_t>::poly_obb)(const Pol2D<real64_t> *, const OBB2D<real64_t> *, Col2D<real64_t> *) = i_poly_obb<real64_t>;

template <>
bool_t (*Col2D<real32_t>::poly_tri)(const Pol2D<real32_t> *, const Tri2D<real32_t> *, Col2D<real32_t> *) = i_poly_tri<real32_t>;

template <>
bool_t (*Col2D<real64_t>::poly_tri)(const Pol2D<real64_t> *, const Tri2D<real64_t> *, Col2D<real64_t> *) = i_poly_tri<real64_t>;

template <>
bool_t (*Col2D<real32_t>::poly_poly)(const Pol2D<real32_t> *, const Pol2D<real32_t> *, Col2D<real32_t> *) = i_poly_poly<real32_t>;

template <>
bool_t (*Col2D<real64_t>::poly_poly)(const Pol2D<real64_t> *, const Pol2D<real64_t> *, Col2D<real64_t> *) = i_poly_poly<real64_t>;

/*---------------------------------------------------------------------------*/

template <>
SATPoly<real32_t> *(*SATPoly<real32_t>::create)(const uint32_t, const uint32_t) = i_create<real32_t>;

template <>
SATPoly<real64_t> *(*SATPoly<real64_t>::create)(const uint32_t, const uint32_t) = i_create<real64_t>;

template <>
SATPoly<real32_t> *(*SATPoly<real32_t>::copy)(const SATPoly<real32_t> *) = i_copy<real32_t>;

template <>
SATPoly<real64_t> *(*SATPoly<real64_t>::copy)(const SATPoly<real64_t> *) = i_copy<real64_t>;

template <>
void (*SATPoly<real32_t>::destroy)(SATPoly<real32_t> **) = i_destroy<real32_t>;

template <>
void (*SATPoly<real64_t>::destroy)(SATPoly<real64_t> **) = i_destroy<real64_t>;

template <>
Box2D<real32_t> (*SATPoly<real32_t>::bbox)(const SATPoly<real32_t> *) = i_bbox<real32_t>;

template <>
Box2D<real64_t> (*SATPoly<real64_t>::bbox)(const SATPoly<real64_t> *) = i_bbox<real64_t>;

template <>
void (*SATPoly<real32_t>::limits)(const V2D<real32_t> *, const V2D<real32_t> *, const uint32_t, const uint32_t, real32_t *, real32_t *) = i_limits<real32_t>;

template <>
void (*SATPoly<real64_t>::limits)(const V2D<real64_t> *, const V2D<real64_t> *, const uint32_t, const uint32_t, real64_t *, real64_t *) = i_limits<real64_t>;
