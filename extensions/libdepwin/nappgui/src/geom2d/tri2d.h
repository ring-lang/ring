/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: tri2d.h
 * https://nappgui.com/en/geom2d/tri2d.html
 *
 */

/* 2D triangles */

#include "geom2d.hxx"

__EXTERN_C

_geom2d_api Tri2Df tri2df(const real32_t x0, const real32_t y0, const real32_t x1, const real32_t y1, const real32_t x2, const real32_t y2);

_geom2d_api Tri2Dd tri2dd(const real64_t x0, const real64_t y0, const real64_t x1, const real64_t y1, const real64_t x2, const real64_t y2);

_geom2d_api Tri2Df tri2d_vf(const V2Df *p0, const V2Df *p1, const V2Df *p2);

_geom2d_api Tri2Dd tri2d_vd(const V2Dd *p0, const V2Dd *p1, const V2Dd *p2);

_geom2d_api void tri2d_transformf(Tri2Df *tri, const T2Df *t2d);

_geom2d_api void tri2d_transformd(Tri2Dd *tri, const T2Dd *t2d);

_geom2d_api real32_t tri2d_areaf(const Tri2Df *tri);

_geom2d_api real64_t tri2d_aread(const Tri2Dd *tri);

_geom2d_api bool_t tri2d_ccwf(const Tri2Df *tri);

_geom2d_api bool_t tri2d_ccwd(const Tri2Dd *tri);

_geom2d_api V2Df tri2d_centroidf(const Tri2Df *tri);

_geom2d_api V2Dd tri2d_centroidd(const Tri2Dd *tri);

__END_C