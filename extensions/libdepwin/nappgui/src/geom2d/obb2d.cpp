/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: obb2d.cpp
 *
 */

/* Oriented Box 2d */

#include "obb2d.h"
#include "obb2d.hpp"
#include "obb2d.ipp"
#include "box2d.hpp"
#include "col2d.ipp"
#include "t2d.hpp"
#include <core/heap.h>
#include <sewer/bmath.hpp>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

template <typename real>
struct OBB2DImp
{
    V2D<real> center;
    real hwidth;
    real hheight;
    real angle;
    SATPoly<real> *poly;
};

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_obb_corners(const OBB2DImp<real> *obb, V2D<real> *corner)
{
    register real c = BMath<real>::cos(obb->angle);
    register real s = BMath<real>::sin(obb->angle);
    V2D<real> vX(c, s);
    V2D<real> vY(-s, c);
    vX.x *= obb->hwidth;
    vX.y *= obb->hwidth;
    vY.x *= obb->hheight;
    vY.y *= obb->hheight;
    corner[0].x = obb->center.x - vX.x - vY.x;
    corner[0].y = obb->center.y - vX.y - vY.y;
    corner[1].x = obb->center.x + vX.x - vY.x;
    corner[1].y = obb->center.y + vX.y - vY.y;
    corner[2].x = obb->center.x + vX.x + vY.x;
    corner[2].y = obb->center.y + vX.y + vY.y;
    corner[3].x = obb->center.x - vX.x + vY.x;
    corner[3].y = obb->center.y - vX.y + vY.y;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_obb_axes(V2D<real> *axis, const V2D<real> *vertex, real *min, real *max)
{
    axis[0].x = -(vertex[1].y - vertex[0].y);
    axis[0].y = vertex[1].x - vertex[0].x;
    axis[1].x = -(vertex[3].y - vertex[0].y);
    axis[1].y = vertex[3].x - vertex[0].x;
    SATPoly<real>::limits(vertex, axis, 4, 2, min, max);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static OBB2D<real> *i_create(const V2D<real> *center, const real width, const real height, const real angle)
{
    OBB2DImp<real> *obb = heap_new(OBB2DImp<real>);
    cassert_no_null(center);
    cassert(width > 0);
    cassert(height > 0);
    obb->center = *center;
    obb->hwidth = width / 2;
    obb->hheight = height / 2;
    obb->angle = angle;
    obb->poly = NULL;
    return (OBB2D<real> *)obb;
}

/*---------------------------------------------------------------------------*/

OBB2Df *obb2d_createf(const V2Df *center, const real32_t width, const real32_t height, const real32_t angle)
{
    return (OBB2Df *)i_create<real32_t>((const V2D<real32_t> *)center, width, height, angle);
}

/*---------------------------------------------------------------------------*/

OBB2Dd *obb2d_created(const V2Dd *center, const real64_t width, const real64_t height, const real64_t angle)
{
    return (OBB2Dd *)i_create<real64_t>((const V2D<real64_t> *)center, width, height, angle);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static OBB2D<real> *i_from_line(const V2D<real> *p0, const V2D<real> *p1, const real thickness)
{
    V2D<real> center;
    V2D<real> dir;
    real width = 0;
    real angle = 0;
    cassert_no_null(p0);
    cassert_no_null(p1);
    center.x = (p0->x + p1->x) / 2;
    center.y = (p0->y + p1->y) / 2;
    dir = V2D<real>::unit(p0, p1, &width);
    angle = V2D<real>::angle(V2D<real>::kX, &dir);
    return i_create<real>(&center, width, thickness, angle);
}

/*---------------------------------------------------------------------------*/

OBB2Df *obb2d_from_linef(const V2Df *p0, const V2Df *p1, const real32_t thickness)
{
    return (OBB2Df *)i_from_line<real32_t>((const V2D<real32_t> *)p0, (const V2D<real32_t> *)p1, thickness);
}

/*---------------------------------------------------------------------------*/

OBB2Dd *obb2d_from_lined(const V2Dd *p0, const V2Dd *p1, const real64_t thickness)
{
    return (OBB2Dd *)i_from_line<real64_t>((const V2D<real64_t> *)p0, (const V2D<real64_t> *)p1, thickness);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static __INLINE void i_quad_eq(const real a, const real b, const real c, real *r1, real *r2)
{
    real sq = BMath<real>::sqrt((b * b) - (4 * a * c));
    *r1 = (-b + sq) / (2 * a);
    *r2 = (-b - sq) / (2 * a);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static __INLINE bool_t i_angle_equal(const real a1, const real a2)
{
    return (bool_t)(BMath<real>::abs(a1 - a2) < BMath<real>::kDEG2RAD);
}

/*---------------------------------------------------------------------------*/
//#include "bstd.h"
template <typename real>
static OBB2D<real> *i_from_points(const V2D<real> *p, const uint32_t n)
{
    const real i_VARIANCE_TOL = (real).001;
    real sumXiYi = 0;
    real sumXiXi = 0;
    real sumYiYi = 0;
    real sumXi = 0;
    real sumYi = 0;
    real sigma[4];
    real angle;
    real width = 0;
    real height = 0;
    V2D<real> m = *V2D<real>::kZERO;
    V2D<real> dir;

    cassert_no_null(p);
    cassert(n > 0);

    for (uint32_t i = 0; i < n; ++i)
    {
        sumXiYi += p[i].x * p[i].y;
        sumXiXi += p[i].x * p[i].x;
        sumYiYi += p[i].y * p[i].y;
        sumXi += p[i].x;
        sumYi += p[i].y;
    }

    m.x = sumXi / n;
    m.y = sumYi / n;

    // Covariance matrix
    sigma[0] = sumXiXi / n - m.x * m.x;
    sigma[1] = sumXiYi / n - m.x * m.y;
    sigma[2] = sigma[1];
    sigma[3] = sumYiYi / n - m.y * m.y;

    // Perfect fit in Y-Axis
    if (BMath<real>::abs(sigma[0]) < i_VARIANCE_TOL)
    {
        cassert(BMath<real>::abs(sigma[1]) < i_VARIANCE_TOL);
        cassert(BMath<real>::abs(sigma[2]) < i_VARIANCE_TOL);
        dir.x = 0;
        dir.y = 1;
        angle = BMath<real>::kPI / 2;
    }
    // Perfect fit in X-Axis
    else if (BMath<real>::abs(sigma[3]) < i_VARIANCE_TOL)
    {
        cassert(BMath<real>::abs(sigma[1]) < i_VARIANCE_TOL);
        cassert(BMath<real>::abs(sigma[2]) < i_VARIANCE_TOL);
        dir.x = 1;
        dir.y = 0;
        angle = 0;
    }
    else
    {
        // No XY covariance --> Cluster aligned to axis
        if (BMath<real>::abs(sigma[1]) < i_VARIANCE_TOL)
        {
            // Y-Axis alignment
            if (sigma[3] > sigma[0])
            {
                dir.x = 0;
                dir.y = 1;
                angle = BMath<real>::kPI / 2;
            }
            // X-Axis alignment
            else
            {
                dir.x = 1;
                dir.y = 0;
                angle = 0;
            }
        }
        // Cluster is rotated
        else
        {
            real varianze0 = 0, varianze1 = 0;
            //real deviation0 = 0, deviation1 = 0;
            //V2D<real> t0 = *V2D<real>::kZERO;
            //V2D<real> t1 = *V2D<real>::kZERO;
            V2D<real> v0, v1;

            // Eigenvalues
            {
                real l2 = 1;
                real l1 = -(sigma[0] + sigma[3]);
                real l0 = (sigma[0] * sigma[3]) - (sigma[1] * sigma[1]);
                i_quad_eq<real>(l2, l1, l0, &varianze0, &varianze1);
            }

            // Eigenvectors
            v0.x = 1;
            v0.y = (-sigma[0] + varianze0) / sigma[1];
            v1.x = 1;
            v1.y = (-sigma[0] + varianze1) / sigma[1];
            V2D<real>::norm(&v0);
            V2D<real>::norm(&v1);

            if (i_angle_equal<real>(BMath<real>::acos(v0.x), BMath<real>::asin(v0.y)) == FALSE)
            {
                // cosTh != cosTH --> Reverse the first vector
                if (i_angle_equal<real>(BMath<real>::acos(v0.x), BMath<real>::acos(v1.y)) == FALSE)
                {
                    //cassert_msg(FALSE, "It's a mirror matrix --> Impossible!");
                    v0.x *= (real)-1.0;
                    v0.y *= (real)-1.0;
                }
                // Eigenvectors in wrong order (should make a rotation matrix)
                else
                {
                    V2D<real> vtemp = v0;
                    real ltemp = varianze0;
                    v0 = v1;
                    v1 = vtemp;
                    varianze0 = varianze1;
                    varianze1 = ltemp;
                }
            }

            //if (varianze0 > 0)
            //    deviation0 = BMath<real>::sqrt(varianze0);
            //else
            //    deviation0 = 0;

            //if (varianze1 > 0)
            //    deviation1 = BMath<real>::sqrt(varianze1);
            //else
            //    deviation1 = 0;

            //bstd_printf("sigma0: %.2f, sigma1: %.2f", deviation0, deviation1);
            //if (deviation0 > deviation1)
            if (varianze0 > varianze1)
            {
                //t0.x = deviation0;
                //t1.x = - deviation0;
                //t0.y = 0;
                //t1.y = 0;
                angle = 0;
            }
            else
            {
                //t0.x = 0;
                //t1.x = 0;
                //t0.y = deviation1;
                //t1.y = - deviation1;
                angle = BMath<real>::kPI / 2;
            }

            {
                real theta = BMath<real>::acos(v0.x);
                //real costh = BMath<real>::cos(-theta);
                //real sinth = BMath<real>::sin(-theta);
                //V2D<real> p0, p1;
                //p0.x =  (t0.x * costh) + (t0.y * sinth);
                //p0.y = -(t0.x * sinth) + (t0.y * costh);
                //p1.x =  (t1.x * costh) + (t1.y * sinth);
                //p1.y = -(t1.x * sinth) + (t1.y * costh);
                angle += theta;

                dir = V2D<real>::from_angle(angle);
            }
        }
    }

    {
        real min_proj = BMath<real>::kINFINITY;
        real max_proj = -BMath<real>::kINFINITY;
        real max_sqdist = 0;

        for (uint32_t i = 0; i < n; ++i)
        {
            V2D<real> pt(p[i].x - m.x, p[i].y - m.y);
            real proj = dir.x * pt.x + dir.y * pt.y;
            V2D<real> proj_pt;
            real sqdist = 0;

            if (proj < min_proj)
                min_proj = proj;
            if (proj > max_proj)
                max_proj = proj;

            proj_pt.x = dir.x * proj;
            proj_pt.y = dir.y * proj;

            sqdist = V2D<real>::sqdist(&pt, &proj_pt);
            if (sqdist > max_sqdist)
                max_sqdist = sqdist;
        }

        height = BMath<real>::sqrt(max_sqdist);
        width = BMath<real>::max(BMath<real>::abs(min_proj), BMath<real>::abs(max_proj));
        //bstd_printf(" width: %.2f, height: %.2f\n", width, height);
        width *= 2;
        height *= 2;
    }

    return i_create<real>(&m, width, height, angle);
}

/*---------------------------------------------------------------------------*/

OBB2Df *obb2d_from_pointsf(const V2Df *p, const uint32_t n)
{
    return (OBB2Df *)i_from_points<real32_t>((const V2D<real32_t> *)p, n);
}

/*---------------------------------------------------------------------------*/

OBB2Dd *obb2d_from_pointsd(const V2Dd *p, const uint32_t n)
{
    return (OBB2Dd *)i_from_points<real64_t>((const V2D<real64_t> *)p, n);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static OBB2D<real> *i_copy(const OBB2D<real> *obb)
{
    OBB2DImp<real> *obbi = (OBB2DImp<real> *)obb;
    cassert_no_null(obbi);
    return i_create<real>(&obbi->center, 2 * obbi->hwidth, 2 * obbi->hheight, obbi->angle);
}

/*---------------------------------------------------------------------------*/

OBB2Df *obb2d_copyf(const OBB2Df *obb)
{
    return (OBB2Df *)i_copy<real32_t>((const OBB2D<real32_t> *)obb);
}

/*---------------------------------------------------------------------------*/

OBB2Dd *obb2d_copyd(const OBB2Dd *obb)
{
    return (OBB2Dd *)i_copy<real64_t>((const OBB2D<real64_t> *)obb);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_destroy(OBB2D<real> **obb)
{
    OBB2DImp<real> **obbi = (OBB2DImp<real> **)obb;
    cassert_no_null(obbi);
    cassert_no_null(*obbi);
    if ((*obbi)->poly != NULL)
        SATPoly<real>::destroy(&(*obbi)->poly);
    heap_delete(obbi, OBB2DImp<real>);
}

/*---------------------------------------------------------------------------*/

void obb2d_destroyf(OBB2Df **obb)
{
    i_destroy<real32_t>((OBB2D<real32_t> **)obb);
}

/*---------------------------------------------------------------------------*/

void obb2d_destroyd(OBB2Dd **obb)
{
    i_destroy<real64_t>((OBB2D<real64_t> **)obb);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_update(OBB2D<real> *obbl, const V2D<real> *center, const real width, const real height, const real angle)
{
    OBB2DImp<real> *obb = (OBB2DImp<real> *)obbl;
    cassert_no_null(obb);
    cassert_no_null(center);
    cassert(width > 0);
    cassert(height > 0);
    obb->center = *center;
    obb->hwidth = width / 2;
    obb->hheight = height / 2;
    obb->angle = angle;
    if (obb->poly != NULL)
        obb->poly->updated = FALSE;
}

/*---------------------------------------------------------------------------*/

void obb2d_updatef(OBB2Df *obb, const V2Df *center, const real32_t width, const real32_t height, const real32_t angle)
{
    i_update<real32_t>((OBB2D<real32_t> *)obb, (const V2D<real32_t> *)center, width, height, angle);
}

/*---------------------------------------------------------------------------*/

void obb2d_updated(OBB2Dd *obb, const V2Dd *center, const real64_t width, const real64_t height, const real64_t angle)
{
    i_update<real64_t>((OBB2D<real64_t> *)obb, (const V2D<real64_t> *)center, width, height, angle);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_move(OBB2D<real> *obb, const real offset_x, const real offset_y)
{
    register OBB2DImp<real> *obbi = (OBB2DImp<real> *)obb;
    V2D<real> center;
    center.x = obbi->center.x += offset_x;
    center.y = obbi->center.y += offset_y;
    i_update<real>(obb, &center, obbi->hwidth * 2, obbi->hheight * 2, obbi->angle);
}

/*---------------------------------------------------------------------------*/

void obb2d_movef(OBB2Df *obb, const real32_t offset_x, const real32_t offset_y)
{
    i_move((OBB2D<real32_t> *)obb, offset_x, offset_y);
}

/*---------------------------------------------------------------------------*/

void obb2d_moved(OBB2Dd *obb, const real64_t offset_x, const real64_t offset_y)
{
    i_move((OBB2D<real64_t> *)obb, offset_x, offset_y);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_transform(OBB2D<real> *obb, const T2D<real> *t2d)
{
    register OBB2DImp<real> *obbi = (OBB2DImp<real> *)obb;
    V2D<real> center, scale;
    real angle;
    T2D<real>::vmult(&center, t2d, &obbi->center);
    T2D<real>::decompose(t2d, NULL, &angle, &scale);
    i_update<real>(obb, &center, obbi->hwidth * 2 * scale.x, obbi->hheight * 2 * scale.y, obbi->angle + angle);
}

/*---------------------------------------------------------------------------*/

void obb2d_transformf(OBB2Df *obb, const T2Df *t2d)
{
    i_transform<real32_t>((OBB2D<real32_t> *)obb, (const T2D<real32_t> *)t2d);
}

/*---------------------------------------------------------------------------*/

void obb2d_transformd(OBB2Dd *obb, const T2Dd *t2d)
{
    i_transform<real64_t>((OBB2D<real64_t> *)obb, (const T2D<real64_t> *)t2d);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static SATPoly<real> *i_sat_poly(const OBB2D<real> *obb)
{
    OBB2DImp<real> *obbi = (OBB2DImp<real> *)obb;
    cassert_no_null(obbi);
    if (obbi->poly == NULL)
        obbi->poly = SATPoly<real>::create(4, 2);

    if (obbi->poly->updated == FALSE)
    {
        i_obb_corners<real>(obbi, obbi->poly->vertex);
        i_obb_axes<real>(obbi->poly->axis, obbi->poly->vertex, obbi->poly->min, obbi->poly->max);
        obbi->poly->updated = TRUE;
    }

    return obbi->poly;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static const V2D<real> *i_corners(const OBB2D<real> *obb)
{
    SATPoly<real> *poly = i_sat_poly<real>(obb);
    return poly->vertex;
}

/*---------------------------------------------------------------------------*/

const V2Df *obb2d_cornersf(const OBB2Df *obb)
{
    return (V2Df *)i_corners<real32_t>((const OBB2D<real32_t> *)obb);
}

/*---------------------------------------------------------------------------*/

const V2Dd *obb2d_cornersd(const OBB2Dd *obb)
{
    return (V2Dd *)i_corners<real64_t>((const OBB2D<real64_t> *)obb);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_center(const OBB2D<real> *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real> *)obb)->center;
}

/*---------------------------------------------------------------------------*/

V2Df obb2d_centerf(const OBB2Df *obb)
{
    V2Df c;
    cassert_no_null(obb);
    c.x = ((OBB2DImp<real32_t> *)obb)->center.x;
    c.y = ((OBB2DImp<real32_t> *)obb)->center.y;
    return c;
}

/*---------------------------------------------------------------------------*/

V2Dd obb2d_centerd(const OBB2Dd *obb)
{
    V2Dd c;
    cassert_no_null(obb);
    c.x = ((OBB2DImp<real64_t> *)obb)->center.x;
    c.y = ((OBB2DImp<real64_t> *)obb)->center.y;
    return c;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_width(const OBB2D<real> *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real> *)obb)->hwidth * 2;
}

/*---------------------------------------------------------------------------*/

real32_t obb2d_widthf(const OBB2Df *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real32_t> *)obb)->hwidth * 2;
}

/*---------------------------------------------------------------------------*/

real64_t obb2d_widthd(const OBB2Dd *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real64_t> *)obb)->hwidth * 2;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_height(const OBB2D<real> *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real> *)obb)->hheight * 2;
}

/*---------------------------------------------------------------------------*/

real32_t obb2d_heightf(const OBB2Df *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real32_t> *)obb)->hheight * 2;
}

/*---------------------------------------------------------------------------*/

real64_t obb2d_heightd(const OBB2Dd *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real64_t> *)obb)->hheight * 2;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_angle(const OBB2D<real> *obb)
{
    cassert_no_null(obb);
    return ((const OBB2DImp<real> *)obb)->angle;
}

/*---------------------------------------------------------------------------*/

real32_t obb2d_anglef(const OBB2Df *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real32_t> *)obb)->angle;
}

/*---------------------------------------------------------------------------*/

real64_t obb2d_angled(const OBB2Dd *obb)
{
    cassert_no_null(obb);
    return ((OBB2DImp<real64_t> *)obb)->angle;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static real i_area(const OBB2D<real> *obb)
{
    const OBB2DImp<real> *obbi = (const OBB2DImp<real> *)obb;
    cassert_no_null(obbi);
    return (obbi->hwidth * 2) * (obbi->hheight * 2);
}

/*---------------------------------------------------------------------------*/

real32_t obb2d_areaf(const OBB2Df *obb)
{
    return i_area<real32_t>((const OBB2D<real32_t> *)obb);
}

/*---------------------------------------------------------------------------*/

real64_t obb2d_aread(const OBB2Dd *obb)
{
    return i_area<real64_t>((const OBB2D<real64_t> *)obb);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static Box2D<real> i_box(const OBB2D<real> *obb)
{
    SATPoly<real> *poly = i_sat_poly<real>(obb);
    return SATPoly<real>::bbox(poly);
}

/*---------------------------------------------------------------------------*/

Box2Df obb2d_boxf(const OBB2Df *obb)
{
    Box2D<real32_t> box = i_box<real32_t>((const OBB2D<real32_t> *)obb);
    Box2Df *bbox = (Box2Df *)&box;
    return *bbox;
}

/*---------------------------------------------------------------------------*/

Box2Dd obb2d_boxd(const OBB2Dd *obb)
{
    Box2D<real64_t> box = i_box<real64_t>((const OBB2D<real64_t> *)obb);
    Box2Dd *bbox = (Box2Dd *)&box;
    return *bbox;
}

/*---------------------------------------------------------------------------*/

//template<typename real>
//static void i_corners(const OBB2D<real> *obb, V2D<real> *corner)
//{
//    register real c = BMath<real>::cos(obb->angle);
//    register real s = BMath<real>::sin(obb->angle);
//    V2D<real> vX(c, s);
//    V2D<real> vY(-s, c);
//    vX.x *= obb->hwidth;
//    vX.y *= obb->hwidth;
//    vY.x *= obb->hheight;
//    vY.y *= obb->hheight;
//    corner[0].x = obb->center.x - vX.x - vY.x;
//    corner[0].y = obb->center.y - vX.y - vY.y;
//    corner[1].x = obb->center.x + vX.x - vY.x;
//    corner[1].y = obb->center.y + vX.y - vY.y;
//    corner[2].x = obb->center.x + vX.x + vY.x;
//    corner[2].y = obb->center.y + vX.y + vY.y;
//    corner[3].x = obb->center.x - vX.x + vY.x;
//    corner[3].y = obb->center.y - vX.y + vY.y;
//}

/*---------------------------------------------------------------------------*/

//void obb_cornersf(const OBB2Df *obb, V2Df *corner);
//
//void obb_cornersd(const OBB2Dd *obb, V2Dd *corner);
//
//void obb_from_segmentf(OBB2Df *box, const Seg2Df *seg, const real32_t thickness);
//
//void obb_from_segmentd(OBB2Dd *box, const Seg2Dd *seg, const real64_t thickness);
//
//void obb_cornersf(const OBB2Df *obb, V2Df *corner)
//{
//    i_corners<real32_t>((const OBB2D<real32_t>*)obb, (V2D<real32_t>*)corner);
//}
//
///*---------------------------------------------------------------------------*/
//
//void obb_cornersd(const OBB2Dd *obb, V2Dd *corner)
//{
//    i_corners<real64_t>((const OBB2D<real64_t>*)obb, (V2D<real64_t>*)corner);
//}
//
///*---------------------------------------------------------------------------*/
//
//template<typename real>
//static void i_from_segment(OBB2D<real> *box, const Seg2D<real> *seg, const real thickness)
//{
//    real l;
//    cassert_no_null(box);
//    cassert_no_null(seg);
//    l = V2D<real>::dist(&seg->p0, &seg->p1) / 2;
//    box->center.x = seg->p0.x + seg->d.x * l;
//    box->center.y = seg->p0.y + seg->d.y * l;
//    box->hwidth = l;
//    box->hheight = thickness / 2;
//    // Angle between two unit vectors = acos(dot(a,b))
//    // a = d = Unit segment director, b = (1,0) --> dx * 1 + dy * 0
//    box->angle = BMath<real>::acos(seg->d.x);
//}
//
///*---------------------------------------------------------------------------*/
//
//void obb_from_segmentf(OBB2Df *box, const Seg2Df *seg, const real32_t thickness)
//{
//    i_from_segment<real32_t>((OBB2D<real32_t>*)box, (const Seg2D<real32_t>*)seg, thickness);
//}
//
///*---------------------------------------------------------------------------*/
//
//void obb_from_segmentd(OBB2Dd *box, const Seg2Dd *seg, const real64_t thickness)
//{
//    i_from_segment<real64_t>((OBB2D<real64_t>*)box, (const Seg2D<real64_t>*)seg, thickness);
//}
//
///*---------------------------------------------------------------------------*/
//

template <>
OBB2D<real32_t> *(*OBB2D<real32_t>::create)(const V2D<real32_t> *, const real32_t, const real32_t, const real32_t) = i_create<real32_t>;

template <>
OBB2D<real64_t> *(*OBB2D<real64_t>::create)(const V2D<real64_t> *, const real64_t, const real64_t, const real64_t) = i_create<real64_t>;

template <>
OBB2D<real32_t> *(*OBB2D<real32_t>::from_line)(const V2D<real32_t> *, const V2D<real32_t> *, const real32_t) = i_from_line<real32_t>;

template <>
OBB2D<real64_t> *(*OBB2D<real64_t>::from_line)(const V2D<real64_t> *, const V2D<real64_t> *, const real64_t) = i_from_line<real64_t>;

//template<>
//OBB2D<real32_t>*(*OBB2D<real32_t>::from_points)(const V2D<real32_t>*) = i_from_points<real32_t>;
//
//template<>
//OBB2D<real64_t>*(*OBB2D<real64_t>::from_points)(const V2D<real64_t>*) = i_from_points<real64_t>;

template <>
OBB2D<real32_t> *(*OBB2D<real32_t>::copy)(const OBB2D<real32_t> *) = i_copy<real32_t>;

template <>
OBB2D<real64_t> *(*OBB2D<real64_t>::copy)(const OBB2D<real64_t> *) = i_copy<real64_t>;

template <>
void (*OBB2D<real32_t>::update)(OBB2D<real32_t> *, const V2D<real32_t> *, const real32_t, const real32_t, const real32_t) = i_update<real32_t>;

template <>
void (*OBB2D<real64_t>::update)(OBB2D<real64_t> *, const V2D<real64_t> *, const real64_t, const real64_t, const real64_t) = i_update<real64_t>;

template <>
void (*OBB2D<real32_t>::move)(OBB2D<real32_t> *, const real32_t, const real32_t) = i_move<real32_t>;

template <>
void (*OBB2D<real64_t>::move)(OBB2D<real64_t> *, const real64_t, const real64_t) = i_move<real64_t>;

template <>
void (*OBB2D<real32_t>::transform)(OBB2D<real32_t> *, const T2D<real32_t> *) = i_transform<real32_t>;

template <>
void (*OBB2D<real64_t>::transform)(OBB2D<real64_t> *, const T2D<real64_t> *) = i_transform<real64_t>;

template <>
void (*OBB2D<real32_t>::destroy)(OBB2D<real32_t> **) = i_destroy<real32_t>;

template <>
void (*OBB2D<real64_t>::destroy)(OBB2D<real64_t> **) = i_destroy<real64_t>;

template <>
const V2D<real32_t> *(*OBB2D<real32_t>::corners)(const OBB2D<real32_t> *) = i_corners<real32_t>;

template <>
const V2D<real64_t> *(*OBB2D<real64_t>::corners)(const OBB2D<real64_t> *) = i_corners<real64_t>;

template <>
V2D<real32_t> (*OBB2D<real32_t>::center)(const OBB2D<real32_t> *) = i_center<real32_t>;

template <>
V2D<real64_t> (*OBB2D<real64_t>::center)(const OBB2D<real64_t> *) = i_center<real64_t>;

template <>
real32_t (*OBB2D<real32_t>::width)(const OBB2D<real32_t> *) = i_width<real32_t>;

template <>
real64_t (*OBB2D<real64_t>::width)(const OBB2D<real64_t> *) = i_width<real64_t>;

template <>
real32_t (*OBB2D<real32_t>::height)(const OBB2D<real32_t> *) = i_height<real32_t>;

template <>
real64_t (*OBB2D<real64_t>::height)(const OBB2D<real64_t> *) = i_height<real64_t>;

template <>
real32_t (*OBB2D<real32_t>::angle)(const OBB2D<real32_t> *) = i_angle<real32_t>;

template <>
real64_t (*OBB2D<real64_t>::angle)(const OBB2D<real64_t> *) = i_angle<real64_t>;

template <>
real32_t (*OBB2D<real32_t>::area)(const OBB2D<real32_t> *) = i_area<real32_t>;

template <>
real64_t (*OBB2D<real64_t>::area)(const OBB2D<real64_t> *) = i_area<real64_t>;

template <>
Box2D<real32_t> (*OBB2D<real32_t>::box)(const OBB2D<real32_t> *) = i_box<real32_t>;

template <>
Box2D<real64_t> (*OBB2D<real64_t>::box)(const OBB2D<real64_t> *) = i_box<real64_t>;

template <>
SATPoly<real32_t> *(*OBB2DI<real32_t>::sat_poly)(const OBB2D<real32_t> *) = i_sat_poly<real32_t>;

template <>
SATPoly<real64_t> *(*OBB2DI<real64_t>::sat_poly)(const OBB2D<real64_t> *) = i_sat_poly<real64_t>;
