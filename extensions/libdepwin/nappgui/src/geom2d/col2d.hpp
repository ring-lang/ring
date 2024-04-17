/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: col2d.hpp
 *
 */

/* 2D Collision detection */

#ifndef __COL2D_HPP__
#define __COL2D_HPP__

#include "cir2d.hpp"
#include "box2d.hpp"
#include "obb2d.hpp"
#include "pol2d.hpp"
#include "v2d.hpp"

template <typename real>
struct Col2D
{
    _geom2d_api static bool_t (*point_point)(const V2D<real> *pnt1, const V2D<real> *pnt2, const real tol, Col2D<real> *col);

    _geom2d_api static bool_t (*segment_point)(const Seg2D<real> *seg, const V2D<real> *pnt, const real tol, Col2D<real> *col);

    _geom2d_api static bool_t (*segment_segment)(const Seg2D<real> *seg1, const Seg2D<real> *seg2, Col2D<real> *col);

    _geom2d_api static bool_t (*circle_point)(const Cir2D<real> *cir, const V2D<real> *p, Col2D<real> *col);

    _geom2d_api static bool_t (*circle_segment)(const Cir2D<real> *cir, const Seg2D<real> *seg, Col2D<real> *col);

    _geom2d_api static bool_t (*circle_circle)(const Cir2D<real> *cir1, const Cir2D<real> *cir2, Col2D<real> *col);

    _geom2d_api static bool_t (*box_point)(const Box2D<real> *box, const V2D<real> *pt, Col2D<real> *col);

    _geom2d_api static bool_t (*box_segment)(const Box2D<real> *box, const Seg2D<real> *seg, Col2D<real> *col);

    _geom2d_api static bool_t (*box_circle)(const Box2D<real> *box, const Cir2D<real> *cir, Col2D<real> *col);

    _geom2d_api static bool_t (*box_box)(const Box2D<real> *box1, const Box2D<real> *box2, Col2D<real> *col);

    _geom2d_api static bool_t (*obb_point)(const OBB2D<real> *obb, const V2D<real> *pt, Col2D<real> *col);

    _geom2d_api static bool_t (*obb_segment)(const OBB2D<real> *obb, const Seg2D<real> *seg, Col2D<real> *col);

    _geom2d_api static bool_t (*obb_circle)(const OBB2D<real> *obb, const Cir2D<real> *cir, Col2D<real> *col);

    _geom2d_api static bool_t (*obb_box)(const OBB2D<real> *obb, const Box2D<real> *box, Col2D<real> *col);

    _geom2d_api static bool_t (*obb_obb)(const OBB2D<real> *obb1, const OBB2D<real> *obb2, Col2D<real> *col);

    _geom2d_api static bool_t (*tri_point)(const Tri2D<real> *tri, const V2D<real> *pnt, Col2D<real> *col);

    _geom2d_api static bool_t (*tri_segment)(const Tri2D<real> *tri, const Seg2D<real> *seg, Col2D<real> *col);

    _geom2d_api static bool_t (*tri_circle)(const Tri2D<real> *tri, const Cir2D<real> *cir, Col2D<real> *col);

    _geom2d_api static bool_t (*tri_box)(const Tri2D<real> *tri, const Box2D<real> *box, Col2D<real> *col);

    _geom2d_api static bool_t (*tri_obb)(const Tri2D<real> *tri, const OBB2D<real> *obb, Col2D<real> *col);

    _geom2d_api static bool_t (*tri_tri)(const Tri2D<real> *tri1, const Tri2D<real> *tri2, Col2D<real> *col);

    _geom2d_api static bool_t (*poly_point)(const Pol2D<real> *poly, const V2D<real> *pt, Col2D<real> *col);

    _geom2d_api static bool_t (*poly_segment)(const Pol2D<real> *poly, const Seg2D<real> *seg, Col2D<real> *col);

    _geom2d_api static bool_t (*poly_circle)(const Pol2D<real> *poly, const Cir2D<real> *cir, Col2D<real> *col);

    _geom2d_api static bool_t (*poly_box)(const Pol2D<real> *poly, const Box2D<real> *box, Col2D<real> *col);

    _geom2d_api static bool_t (*poly_obb)(const Pol2D<real> *poly, const OBB2D<real> *obb, Col2D<real> *col);

    _geom2d_api static bool_t (*poly_tri)(const Pol2D<real> *poly, const Tri2D<real> *tri, Col2D<real> *col);

    _geom2d_api static bool_t (*poly_poly)(const Pol2D<real> *poly1, const Pol2D<real> *poly2, Col2D<real> *col);

    V2D<real> p;
    V2D<real> n;
    real d;
};

#endif
