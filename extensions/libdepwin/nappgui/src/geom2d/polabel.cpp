/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: polabel.cpp
 *
 */

/* 2d polygon visual label */
/* It's an adaptation of https://github.com/mapbox/polylabel */

#include "pol2d.ipp"
#include "s2d.hpp"
#include <sewer/bmath.hpp>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

template <typename real>
struct Cell
{
    V2D<real> center;
    real hsize;
    real dist;
    real maxdist;
};

/*---------------------------------------------------------------------------*/

// Signed distance from point to polygon outline (negative if point is outside)
template <typename real>
static real i_poly_point_dist(const V2D<real> *verts, const uint32_t n, const V2D<real> *pt)
{
    bool_t inside = FALSE;
    real min_sqdist = BMath<real>::kINFINITY;
    uint32_t i = 0, j = n - 1;

    cassert_no_null(verts);
    cassert_no_null(pt);
    cassert(n >= 3);

    for (i = 0; i < n; j = i++)
    {
        const V2D<real> *a = &verts[i];
        const V2D<real> *b = &verts[j];
        Seg2D<real> seg(a, b);
        real sqdist = 0;

        if ((a->y > pt->y) != (b->y > pt->y))
        {
            real t1 = (b->x - a->x) * (pt->y - a->y);
            real t2 = b->y - a->y;
            real t3 = 0;
            cassert(t2 != 0);
            t3 = (t1 / t2) + a->x;

            if (pt->x < t3)
                inside = (bool_t)!inside;
        }

        sqdist = Seg2D<real>::point_sqdist(&seg, pt, NULL);

        if (sqdist < min_sqdist)
            min_sqdist = sqdist;
    }

    return (inside ? 1 : -1) * BMath<real>::sqrt(min_sqdist);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_init_cell(Cell<real> *cell, const V2D<real> center, const real hsize, const V2D<real> *verts, const uint32_t n)
{
    cassert_no_null(cell);
    cell->center = center;
    cell->hsize = hsize;
    cell->dist = i_poly_point_dist<real>(verts, n, &cell->center);
    cell->maxdist = cell->dist + cell->hsize * BMath<real>::kSQRT2;
}

/*---------------------------------------------------------------------------*/

// Get polygon centroid
template <typename real>
static void i_centroid_cell(const V2D<real> *verts, const uint32_t n, Cell<real> *cell)
{
    real area = 0;
    V2D<real> c(0, 0);
    uint32_t i = 0, j = n - 1;

    cassert(n >= 3);
    cassert_no_null(cell);

    for (i = 0; i < n; j = i++)
    {
        const V2D<real> *a = &verts[i];
        const V2D<real> *b = &verts[j];
        real f = a->x * b->y - b->x * a->y;
        c.x += (a->x + b->x) * f;
        c.y += (a->y + b->y) * f;
        area += f * 3;
    }

    if (area == 0)
    {
        c = verts[0];
    }
    else
    {
        c.x /= area;
        c.y /= area;
    }

    cell->hsize = 0;

    i_init_cell<real>(cell, c, 0, verts, n);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static int i_cmp_cell(const Cell<real> *c1, const Cell<real> *c2)
{
    cassert_no_null(c1);
    cassert_no_null(c2);
    return c1->maxdist < c1->maxdist ? -1 : 1;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_poly_label(const Pol2D<real> *pol, const real norm_tol)
{
    Box2D<real> box = Pol2D<real>::box(pol);
    S2D<real> size(box.max.x - box.min.x, box.max.y - box.min.y);
    real cell_size = BMath<real>::min(size.width, size.height);

    if (cell_size > 0)
    {
        const V2D<real> *verts = Pol2D<real>::points(pol);
        uint32_t n = Pol2D<real>::n(pol);
        real hsize = cell_size / 2;
        Cell<real> best_cell;
        ArrSt<Cell<real> > *queue = ArrSt<Cell<real> >::create();
        real tol = cell_size * norm_tol;
        uint32_t num_probes = 0;

        // Cover polygon with initial cells
        for (real x = box.min.x; x < box.max.x; x += cell_size)
            for (real y = box.min.y; y < box.max.y; y += cell_size)
            {
                Cell<real> *cell = ArrSt<Cell<real> >::nnew(queue);
                i_init_cell<real>(cell, V2D<real>(x + hsize, y + hsize), hsize, verts, n);
                num_probes += 1;
            }

        // Take centroid as the first best guess
        i_centroid_cell<real>(verts, n, &best_cell);

        // Second guess: bounding box centroid
        {
            Cell<real> box_cell;
            i_init_cell<real>(&box_cell, Box2D<real>::center(&box), 0, verts, n);
            if (box_cell.dist > best_cell.dist)
                best_cell = box_cell;
        }

        while (ArrSt<Cell<real> >::size(queue) > 0)
        {
            Cell<real> cell;

            // Pick the most promising cell from the queue
            ArrSt<Cell<real> >::sort(queue, i_cmp_cell<real>);
            cell = *ArrSt<Cell<real> >::last(queue);
            ArrSt<Cell<real> >::pop(queue, NULL);

            // Update the best cell if we found a better one
            if (cell.dist > best_cell.dist)
                best_cell = cell;

            // Do not drill down further if there's no chance of a better solution
            if (cell.maxdist - best_cell.dist > tol)
            {
                // Split the cell into four cells
                Cell<real> *ncell = ArrSt<Cell<real> >::new_n(queue, 4);
                hsize = cell.hsize / 2;
                i_init_cell<real>(&ncell[0], V2D<real>(cell.center.x - hsize, cell.center.y - hsize), hsize, verts, n);
                i_init_cell<real>(&ncell[1], V2D<real>(cell.center.x + hsize, cell.center.y - hsize), hsize, verts, n);
                i_init_cell<real>(&ncell[2], V2D<real>(cell.center.x - hsize, cell.center.y + hsize), hsize, verts, n);
                i_init_cell<real>(&ncell[3], V2D<real>(cell.center.x + hsize, cell.center.y + hsize), hsize, verts, n);
                num_probes += 4;
            }
        }

        unref(num_probes);
        ArrSt<Cell<real> >::destroy(&queue, NULL);
        return best_cell.center;
    }
    else
    {
        return box.min;
    }
}

/*---------------------------------------------------------------------------*/

template <>
V2D<real32_t> (*Pol2DI<real32_t>::poly_label)(const Pol2D<real32_t> *, const real32_t) = i_poly_label<real32_t>;

template <>
V2D<real64_t> (*Pol2DI<real64_t>::poly_label)(const Pol2D<real64_t> *, const real64_t) = i_poly_label<real64_t>;
