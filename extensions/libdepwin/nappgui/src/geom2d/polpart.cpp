/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: polpart.cpp
 *
 */

/* 2d polygon convex partition */

#include "pol2d.ipp"
#include "pol2d.h"
#include <core/arrst.h>
#include <core/heap.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

template <typename real>
struct PartitionVertex
{
    bool_t is_active;
    bool_t is_convex;
    bool_t is_ear;
    uint32_t p;
    real angle;
    PartitionVertex<real> *prev;
    PartitionVertex<real> *next;
};

struct Poly
{
    uint32_t *ids;
    uint32_t n;
};

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_is_convex(const V2D<real> *p1, const V2D<real> *p2, const V2D<real> *p3)
{
    real tmp;
    cassert_no_null(p1);
    cassert_no_null(p2);
    cassert_no_null(p3);
    tmp = (p3->y - p1->y) * (p2->x - p1->x) - (p3->x - p1->x) * (p2->y - p1->y);
    return tmp > 0 ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_is_inside(const V2D<real> *p1, const V2D<real> *p2, const V2D<real> *p3, const V2D<real> *p)
{
    if (i_is_convex<real>(p1, p, p2) == TRUE)
        return FALSE;

    if (i_is_convex<real>(p2, p, p3) == TRUE)
        return FALSE;

    if (i_is_convex<real>(p3, p, p1) == TRUE)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_update_vertex(PartitionVertex<real> *v, PartitionVertex<real> *vertices, const V2D<real> *points, const uint32_t n)
{
    PartitionVertex<real> *v1 = NULL, *v3 = NULL;
    const V2D<real> *v_pt = NULL, *v1_pt = NULL, *v3_pt = NULL;
    V2D<real> vec1, vec3;

    cassert_no_null(v);
    cassert_no_null(points);
    v1 = v->prev;
    v3 = v->next;
    v_pt = &points[v->p];
    v1_pt = &points[v1->p];
    v3_pt = &points[v3->p];

    v->is_convex = i_is_convex<real>(v1_pt, v_pt, v3_pt);
    vec1 = V2D<real>::sub(v1_pt, v_pt);
    vec3 = V2D<real>::sub(v3_pt, v_pt);
    V2D<real>::norm(&vec1);
    V2D<real>::norm(&vec3);
    v->angle = vec1.x * vec3.x + vec1.y * vec3.y;

    if (v->is_convex == TRUE)
    {
        uint32_t i;
        v->is_ear = TRUE;
        for (i = 0; i < n; i++)
        {
            const V2D<real> *vi_pt = &points[vertices[i].p];
            if ((vi_pt->x == v_pt->x) && (vi_pt->y == v_pt->y))
                continue;

            if ((vi_pt->x == v1_pt->x) && (vi_pt->y == v1_pt->y))
                continue;

            if ((vi_pt->x == v3_pt->x) && (vi_pt->y == v3_pt->y))
                continue;

            if (i_is_inside<real>(v1_pt, v_pt, v3_pt, vi_pt) == TRUE)
            {
                v->is_ear = FALSE;
                break;
            }
        }
    }
    else
    {
        v->is_ear = FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_add_tri(ArrSt<uint32_t> *tri_vertices, const uint32_t p0, const uint32_t p1, const uint32_t p2, const bool_t revert)
{
    uint32_t *tri = ArrSt<uint32_t>::new_n(tri_vertices, 3);
    if (revert == TRUE)
    {
        tri[0] = p2;
        tri[1] = p1;
        tri[2] = p0;
    }
    else
    {
        tri[0] = p0;
        tri[1] = p1;
        tri[2] = p2;
    }
}

/*---------------------------------------------------------------------------*/

// Triangulates a polygon by ear clipping.
// Time complexity: O(n^2), n is the number of vertices.
// Space complexity: O(n)
template <typename real>
static void i_triangulate_ear_clipping(const Pol2D<real> *pol, ArrSt<uint32_t> *tri_vertices, const bool_t revert)
{
    const V2D<real> *points = Pol2D<real>::points(pol);
    uint32_t n = Pol2D<real>::n(pol);

    cassert(n >= 3);

    if (n > 3)
    {
        PartitionVertex<real> *part_vertex = heap_new_n0(n, PartitionVertex<real>);
        uint32_t i, j;

        if (revert == TRUE)
        {
            for (i = 0; i < n; i++)
            {
                part_vertex[i].is_active = TRUE;
                part_vertex[i].p = n - i - 1;
                part_vertex[i].next = &(part_vertex[(i + 1) % n]);
                part_vertex[i].prev = &(part_vertex[i == 0 ? (n - 1) : (i - 1)]);
            }
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                part_vertex[i].is_active = TRUE;
                part_vertex[i].p = i;
                part_vertex[i].next = &(part_vertex[(i + 1) % n]);
                part_vertex[i].prev = &(part_vertex[i == 0 ? (n - 1) : (i - 1)]);
            }
        }

        for (i = 0; i < n; i++)
            i_update_vertex<real>(&part_vertex[i], part_vertex, points, n);

        for (i = 0; i < n - 3; i++)
        {
            PartitionVertex<real> *ear = NULL;

            // Find the most extruded ear.
            for (j = 0; j < n; j++)
            {
                if (part_vertex[j].is_active == FALSE)
                    continue;

                if (part_vertex[j].is_ear == FALSE)
                    continue;

                if (ear == NULL || part_vertex[j].angle > ear->angle)
                    ear = &(part_vertex[j]);
            }

            // Mejorar esta salida!!!!
            if (ear == NULL)
            {
                heap_delete_n(&part_vertex, n, PartitionVertex<real>);
                ArrSt<uint32_t>::clear(tri_vertices, NULL);
                return;
            }

            i_add_tri(tri_vertices, ear->prev->p, ear->p, ear->next->p, revert);
            ear->is_active = FALSE;
            ear->prev->next = ear->next;
            ear->next->prev = ear->prev;

            if (i == n - 4)
            {
                break;
            }
            else
            {
                i_update_vertex<real>(ear->prev, part_vertex, points, n);
                i_update_vertex<real>(ear->next, part_vertex, points, n);
            }
        }

        for (i = 0; i < n; i++)
        {
            if (part_vertex[i].is_active == TRUE)
            {
                i_add_tri(tri_vertices, part_vertex[i].prev->p, part_vertex[i].p, part_vertex[i].next->p, revert);
                break;
            }
        }

        heap_delete_n(&part_vertex, n, PartitionVertex<real>);
    }
    else
    {
        i_add_tri(tri_vertices, 0, 1, 2, revert);
    }
}

/*---------------------------------------------------------------------------*/

// Triangulates a polygon by ear clipping.
// Time complexity: O(n^2), n is the number of vertices.
// Space complexity: O(n)
template <typename real>
static void i_triangulate_polygon(const Pol2D<real> *pol, ArrSt<Tri2D<real> > *triangles)
{
    const V2D<real> *point = Pol2D<real>::points(pol);
    ArrSt<uint32_t> *vids = ArrSt<uint32_t>::create();
    bool_t revert = !Pol2D<real>::ccw(pol);
    const uint32_t *vid = NULL;
    uint32_t i, n;

    i_triangulate_ear_clipping<real>(pol, vids, revert);
    vid = ArrSt<uint32_t>::all(vids);
    n = ArrSt<uint32_t>::size(vids);
    cassert(n % 3 == 0);
    for (i = 0; i < n; i += 3)
    {
        Tri2D<real> *tri = ArrSt<Tri2D<real> >::nnew(triangles);
        tri->p0 = point[vid[i]];
        tri->p1 = point[vid[i + 1]];
        tri->p2 = point[vid[i + 2]];
    }

    ArrSt<uint32_t>::destroy(&vids, NULL);
}

/*---------------------------------------------------------------------------*/

ArrSt(Tri2Df) *pol2d_trianglesf(const Pol2Df *pol)
{
    ArrSt(Tri2Df) *triangles = arrst_create(Tri2Df);
    i_triangulate_polygon<real32_t>((const Pol2D<real32_t> *)pol, (ArrSt<Tri2D<real32_t> > *)triangles);
    return triangles;
}

/*---------------------------------------------------------------------------*/

ArrSt(Tri2Dd) *pol2d_trianglesd(const Pol2Dd *pol)
{
    ArrSt(Tri2Dd) *triangles = arrst_create(Tri2Dd);
    i_triangulate_polygon<real64_t>((const Pol2D<real64_t> *)pol, (ArrSt<Tri2D<real64_t> > *)triangles);
    return triangles;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static ArrSt<Tri2D<real> > *i_triangles(const Pol2D<real> *pol)
{
    ArrSt<Tri2D<real> > *triangles = ArrSt<Tri2D<real> >::create();
    i_triangulate_polygon<real>(pol, triangles);
    return triangles;
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_init_poly(Poly *poly, const uint32_t n)
{
    cassert_no_null(poly);
    poly->n = n;
    poly->ids = heap_new_n(n, uint32_t);
}

/*---------------------------------------------------------------------------*/

static void i_remove_poly(Poly *poly)
{
    cassert_no_null(poly);
    heap_delete_n(&poly->ids, poly->n, uint32_t);
}

/*---------------------------------------------------------------------------*/

static ArrSt<Poly> *i_polys_from_triangles(const ArrSt<uint32_t> *vids)
{
    ArrSt<Poly> *polys = ArrSt<Poly>::create();
    const uint32_t *vid = ArrSt<uint32_t>::all(vids);
    uint32_t i, n = ArrSt<uint32_t>::size(vids);
    cassert(n % 3 == 0);
    for (i = 0; i < n; i += 3)
    {
        Poly *poly = ArrSt<Poly>::nnew(polys);
        i_init_poly(poly, 3);
        poly->ids[0] = vid[i];
        poly->ids[1] = vid[i + 1];
        poly->ids[2] = vid[i + 2];
    }

    return polys;
}

/*---------------------------------------------------------------------------*/

// https://github.com/ivanfratric/polypartition
// Implements the simple approximation algorithm of Hertel and Mehlhorn [HM83]
// that produces a convex partitioning of a polygon from a triangulation by throwing
// out unnecessary triangulation edges.
template <typename real>
static ArrPt<SATPoly<real> > *i_get_convex_sat_polys(const Pol2D<real> *pol)
{
    ArrPt<SATPoly<real> > *convex_sats = ArrPt<SATPoly<real> >::create();
    const V2D<real> *point = Pol2D<real>::points(pol);
    ArrSt<uint32_t> *vids = ArrSt<uint32_t>::create();
    bool_t revert = !Pol2D<real>::ccw(pol);
    ArrSt<Poly> *polys = NULL;
    const Poly *poly1 = NULL;
    const Poly *poly2 = NULL;
    const Poly *poly = NULL;
    uint32_t i, j, num_polys;
    uint32_t d1, d2, p1, p2, p3;
    uint32_t i11, i12, i13, i21, i22, i23;
    bool_t joined, isdiagonal;

    cassert(Pol2D<real>::convex(pol) == FALSE);
    i_triangulate_ear_clipping<real>(pol, vids, revert);

    polys = i_polys_from_triangles(vids);
    num_polys = ArrSt<Poly>::size(polys);

    for (i = 0; i < num_polys;)
    {
        joined = FALSE;
        poly1 = ArrSt<Poly>::get(polys, i);

        for (i11 = 0; i11 < poly1->n && joined == FALSE; ++i11)
        {
            d1 = poly1->ids[i11];
            i12 = (i11 + 1) % poly1->n;
            d2 = poly1->ids[i12];

            isdiagonal = FALSE;
            i21 = 0;
            i22 = 0;
            for (j = i + 1; j < num_polys; ++j)
            {
                poly2 = ArrSt<Poly>::get(polys, j);

                for (i21 = 0; i21 < poly2->n; ++i21)
                {
                    if (d2 != poly2->ids[i21])
                        continue;

                    i22 = (i21 + 1) % poly2->n;
                    if (d1 != poly2->ids[i22])
                        continue;

                    isdiagonal = TRUE;
                    break;
                }

                if (isdiagonal == TRUE)
                    break;
            }

            if (isdiagonal == FALSE)
                continue;

            p2 = poly1->ids[i11];
            if (i11 == 0)
                i13 = poly1->n - 1;
            else
                i13 = i11 - 1;

            p1 = poly1->ids[i13];
            if (i22 == poly2->n - 1)
                i23 = 0;
            else
                i23 = i22 + 1;

            p3 = poly2->ids[i23];

            if (i_is_convex<real>(&point[p1], &point[p2], &point[p3]) == revert)
                continue;

            p2 = poly1->ids[i12];
            if (i12 == poly1->n - 1)
                i13 = 0;
            else
                i13 = i12 + 1;

            p3 = poly1->ids[i13];
            if (i21 == 0)
                i23 = poly2->n - 1;
            else
                i23 = i21 - 1;

            p1 = poly2->ids[i23];

            if (i_is_convex<real>(&point[p1], &point[p2], &point[p3]) == revert)
                continue;

            {
                Poly newpoly;
                uint32_t k = 0, l = 0;
                i_init_poly(&newpoly, poly1->n + poly2->n - 2);

                for (l = i12; l != i11; l = (l + 1) % poly1->n)
                {
                    newpoly.ids[k] = poly1->ids[l];
                    k++;
                }

                for (l = i22; l != i21; l = (l + 1) % poly2->n)
                {
                    newpoly.ids[k] = poly2->ids[l];
                    k++;
                }

                cassert(k == newpoly.n);
                cassert(j > i);
                ArrSt<Poly>::ddelete(polys, j, i_remove_poly);
                ArrSt<Poly>::ddelete(polys, i, i_remove_poly);
                ArrSt<Poly>::insert(polys, i, newpoly);
                joined = TRUE;
            }
        }

        if (joined == TRUE)
        {
            cassert(num_polys >= 2);
            num_polys -= 1;
        }
        else
        {
            i += 1;
        }
    }

    poly = ArrSt<Poly>::all(polys);
    cassert(ArrSt<Poly>::size(polys) == num_polys);
    for (i = 0; i < num_polys; ++i)
    {
        register uint32_t n = poly[i].n;
        SATPoly<real> *sat = SATPoly<real>::create(n, n);
        V2D<real> *v = sat->vertex;
        V2D<real> *a = sat->axis;

        for (j = 0; j < n; ++j)
            v[j] = point[poly[i].ids[j]];

        for (j = 0; j < n; ++j)
        {
            a[j].x = -(v[j + 1 % n].y - v[j].y);
            a[j].y = v[j + 1 % n].x - v[j].x;
        }

        SATPoly<real>::limits(v, a, n, n, sat->min, sat->max);
        sat->updated = TRUE;
        ArrPt<SATPoly<real> >::append(convex_sats, sat);
    }

    ArrSt<uint32_t>::destroy(&vids, NULL);
    ArrSt<Poly>::destroy(&polys, i_remove_poly);
    return convex_sats;
}

/*---------------------------------------------------------------------------*/

template <>
ArrSt<Tri2D<real32_t> > *(*Pol2D<real32_t>::triangles)(const Pol2D<real32_t> *) = i_triangles<real32_t>;

template <>
ArrSt<Tri2D<real64_t> > *(*Pol2D<real64_t>::triangles)(const Pol2D<real64_t> *) = i_triangles<real64_t>;

template <>
ArrPt<SATPoly<real32_t> > *(*Pol2DI<real32_t>::get_convex_sat_polys)(const Pol2D<real32_t> *) = i_get_convex_sat_polys<real32_t>;

template <>
ArrPt<SATPoly<real64_t> > *(*Pol2DI<real64_t>::get_convex_sat_polys)(const Pol2D<real64_t> *) = i_get_convex_sat_polys<real64_t>;
