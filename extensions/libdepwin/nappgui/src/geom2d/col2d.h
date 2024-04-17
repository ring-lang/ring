/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: col2d.h
 * https://nappgui.com/en/geom2d/col2d.html
 *
 */

/* 2D Collision detection */

#include "geom2d.hxx"

__EXTERN_C

_geom2d_api bool_t col2d_point_pointf(const V2Df *pnt1, const V2Df *pnt2, const real32_t tol, Col2Df *col);

_geom2d_api bool_t col2d_point_pointd(const V2Dd *pnt1, const V2Dd *pnt2, const real64_t tol, Col2Dd *col);

_geom2d_api bool_t col2d_segment_pointf(const Seg2Df *seg, const V2Df *pnt, const real32_t tol, Col2Df *col);

_geom2d_api bool_t col2d_segment_pointd(const Seg2Dd *seg, const V2Dd *pnt, const real64_t tol, Col2Dd *col);

_geom2d_api bool_t col2d_segment_segmentf(const Seg2Df *seg1, const Seg2Df *seg2, Col2Df *col);

_geom2d_api bool_t col2d_segment_segmentd(const Seg2Dd *seg1, const Seg2Dd *seg2, Col2Dd *col);

_geom2d_api bool_t col2d_circle_pointf(const Cir2Df *cir, const V2Df *pnt, Col2Df *col);

_geom2d_api bool_t col2d_circle_pointd(const Cir2Dd *cir, const V2Dd *pnt, Col2Dd *col);

_geom2d_api bool_t col2d_circle_segmentf(const Cir2Df *cir, const Seg2Df *seg, Col2Df *col);

_geom2d_api bool_t col2d_circle_segmentd(const Cir2Dd *cir, const Seg2Dd *seg, Col2Dd *col);

_geom2d_api bool_t col2d_circle_circlef(const Cir2Df *cir1, const Cir2Df *cir2, Col2Df *col);

_geom2d_api bool_t col2d_circle_circled(const Cir2Dd *cir1, const Cir2Dd *cir2, Col2Dd *col);

_geom2d_api bool_t col2d_box_pointf(const Box2Df *box, const V2Df *pnt, Col2Df *col);

_geom2d_api bool_t col2d_box_pointd(const Box2Dd *box, const V2Dd *pnt, Col2Dd *col);

_geom2d_api bool_t col2d_box_segmentf(const Box2Df *box, const Seg2Df *seg, Col2Df *col);

_geom2d_api bool_t col2d_box_segmentd(const Box2Dd *box, const Seg2Dd *seg, Col2Df *col);

_geom2d_api bool_t col2d_box_circlef(const Box2Df *box, const Cir2Df *cir, Col2Df *col);

_geom2d_api bool_t col2d_box_circled(const Box2Dd *box, const Cir2Dd *cir, Col2Dd *col);

_geom2d_api bool_t col2d_box_boxf(const Box2Df *box1, const Box2Df *box2, Col2Df *col);

_geom2d_api bool_t col2d_box_boxd(const Box2Dd *box1, const Box2Dd *box2, Col2Dd *col);

_geom2d_api bool_t col2d_obb_pointf(const OBB2Df *obb, const V2Df *pnt, Col2Df *col);

_geom2d_api bool_t col2d_obb_pointd(const OBB2Dd *obb, const V2Dd *pnt, Col2Dd *col);

_geom2d_api bool_t col2d_obb_segmentf(const OBB2Df *obb, const Seg2Df *seg, Col2Df *col);

_geom2d_api bool_t col2d_obb_segmentd(const OBB2Dd *obb, const Seg2Dd *seg, Col2Dd *col);

_geom2d_api bool_t col2d_obb_circlef(const OBB2Df *obb, const Cir2Df *cir, Col2Df *col);

_geom2d_api bool_t col2d_obb_circled(const OBB2Dd *obb, const Cir2Dd *cir, Col2Dd *col);

_geom2d_api bool_t col2d_obb_boxf(const OBB2Df *obb, const Box2Df *box, Col2Df *col);

_geom2d_api bool_t col2d_obb_boxd(const OBB2Dd *obb, const Box2Dd *box, Col2Dd *col);

_geom2d_api bool_t col2d_obb_obbf(const OBB2Df *obb1, const OBB2Df *obb2, Col2Df *col);

_geom2d_api bool_t col2d_obb_obbd(const OBB2Dd *obb1, const OBB2Dd *obb2, Col2Dd *col);

_geom2d_api bool_t col2d_tri_pointf(const Tri2Df *tri, const V2Df *pnt, Col2Df *col);

_geom2d_api bool_t col2d_tri_pointd(const Tri2Dd *tri, const V2Dd *pnt, Col2Dd *col);

_geom2d_api bool_t col2d_tri_segmentf(const Tri2Df *tri, const Seg2Df *seg, Col2Df *col);

_geom2d_api bool_t col2d_tri_segmentd(const Tri2Dd *tri, const Seg2Dd *seg, Col2Dd *col);

_geom2d_api bool_t col2d_tri_circlef(const Tri2Df *tri, const Cir2Df *cir, Col2Df *col);

_geom2d_api bool_t col2d_tri_circled(const Tri2Dd *tri, const Cir2Df *cir, Col2Df *col);

_geom2d_api bool_t col2d_tri_boxf(const Tri2Df *tri, const Box2Df *box, Col2Df *col);

_geom2d_api bool_t col2d_tri_boxd(const Tri2Dd *tri, const Box2Df *box, Col2Df *col);

_geom2d_api bool_t col2d_tri_obbf(const Tri2Df *tri, const OBB2Df *obb, Col2Df *col);

_geom2d_api bool_t col2d_tri_obbd(const Tri2Dd *tri, const OBB2Dd *obb, Col2Dd *col);

_geom2d_api bool_t col2d_tri_trif(const Tri2Df *tri1, const Tri2Df *tri2, Col2Df *col);

_geom2d_api bool_t col2d_tri_trid(const Tri2Dd *tri1, const Tri2Dd *tri2, Col2Dd *col);

_geom2d_api bool_t col2d_poly_pointf(const Pol2Df *poly, const V2Df *pnt, Col2Df *col);

_geom2d_api bool_t col2d_poly_pointd(const Pol2Dd *poly, const V2Dd *pnt, Col2Dd *col);

_geom2d_api bool_t col2d_poly_segmentf(const Pol2Df *poly, const Seg2Df *seg, Col2Df *col);

_geom2d_api bool_t col2d_poly_segmentd(const Pol2Dd *poly, const Seg2Dd *seg, Col2Dd *col);

_geom2d_api bool_t col2d_poly_circlef(const Pol2Df *poly, const Cir2Df *cir, Col2Df *col);

_geom2d_api bool_t col2d_poly_circled(const Pol2Dd *poly, const Cir2Dd *cir, Col2Dd *col);

_geom2d_api bool_t col2d_poly_boxf(const Pol2Df *poly, const Box2Df *box, Col2Df *col);

_geom2d_api bool_t col2d_poly_boxd(const Pol2Dd *poly, const Box2Dd *box, Col2Dd *col);

_geom2d_api bool_t col2d_poly_obbf(const Pol2Df *poly, const OBB2Df *obb, Col2Df *col);

_geom2d_api bool_t col2d_poly_obbd(const Pol2Dd *poly, const OBB2Dd *obb, Col2Dd *col);

_geom2d_api bool_t col2d_poly_trif(const Pol2Df *poly, const Tri2Df *tri, Col2Df *col);

_geom2d_api bool_t col2d_poly_trid(const Pol2Dd *poly, const Tri2Dd *tri, Col2Dd *col);

_geom2d_api bool_t col2d_poly_polyf(const Pol2Df *poly1, const Pol2Df *poly2, Col2Df *col);

_geom2d_api bool_t col2d_poly_polyd(const Pol2Dd *poly1, const Pol2Dd *poly2, Col2Dd *col);

__END_C
