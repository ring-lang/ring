/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: pol2d.h
 * https://nappgui.com/en/geom2d/pol2d.html
 *
 */

/* 2d polygon */

#include "geom2d.hxx"

__EXTERN_C

_geom2d_api Pol2Df *pol2d_createf(const V2Df *points, const uint32_t n);

_geom2d_api Pol2Dd *pol2d_created(const V2Dd *points, const uint32_t n);

_geom2d_api Pol2Df *pol2d_convex_hullf(const V2Df *points, const uint32_t n);

_geom2d_api Pol2Dd *pol2d_convex_hulld(const V2Dd *points, const uint32_t n);

_geom2d_api Pol2Df *pol2d_copyf(const Pol2Df *pol);

_geom2d_api Pol2Dd *pol2d_copyd(const Pol2Dd *pol);

_geom2d_api void pol2d_destroyf(Pol2Df **pol);

_geom2d_api void pol2d_destroyd(Pol2Dd **pol);

_geom2d_api void pol2d_transformf(Pol2Df *pol, const T2Df *t2d);

_geom2d_api void pol2d_transformd(Pol2Dd *pol, const T2Dd *t2d);

_geom2d_api const V2Df *pol2d_pointsf(const Pol2Df *pol);

_geom2d_api const V2Dd *pol2d_pointsd(const Pol2Dd *pol);

_geom2d_api uint32_t pol2d_nf(const Pol2Df *pol);

_geom2d_api uint32_t pol2d_nd(const Pol2Dd *pol);

_geom2d_api real32_t pol2d_areaf(const Pol2Df *pol);

_geom2d_api real64_t pol2d_aread(const Pol2Dd *pol);

_geom2d_api Box2Df pol2d_boxf(const Pol2Df *pol);

_geom2d_api Box2Dd pol2d_boxd(const Pol2Dd *pol);

_geom2d_api bool_t pol2d_ccwf(const Pol2Df *pol);

_geom2d_api bool_t pol2d_ccwd(const Pol2Dd *pol);

_geom2d_api bool_t pol2d_convexf(const Pol2Df *pol);

_geom2d_api bool_t pol2d_convexd(const Pol2Dd *pol);

_geom2d_api V2Df pol2d_centroidf(const Pol2Df *pol);

_geom2d_api V2Dd pol2d_centroidd(const Pol2Dd *pol);

_geom2d_api V2Df pol2d_visual_centerf(const Pol2Df *pol, const real32_t norm_tol);

_geom2d_api V2Dd pol2d_visual_centerd(const Pol2Dd *pol, const real64_t norm_tol);

_geom2d_api ArrSt(Tri2Df) *pol2d_trianglesf(const Pol2Df *pol);

_geom2d_api ArrSt(Tri2Dd) *pol2d_trianglesd(const Pol2Dd *pol);

_geom2d_api ArrPt(Pol2Df) *pol2d_convex_partitionf(const Pol2Df *pol);

_geom2d_api ArrPt(Pol2Dd) *pol2d_convex_partitiond(const Pol2Dd *pol);

__END_C
