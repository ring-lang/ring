/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: r2d.h
 * https://nappgui.com/en/geom2d/r2d.html
 *
 */

/* 2D rectangles */

#include "geom2d.hxx"

__EXTERN_C

_geom2d_api R2Df r2df(const real32_t x, const real32_t y, const real32_t width, const real32_t height);

_geom2d_api R2Dd r2dd(const real64_t x, const real64_t y, const real64_t width, const real64_t height);

_geom2d_api V2Df r2d_centerf(const R2Df *r2d);

_geom2d_api V2Dd r2d_centerd(const R2Dd *r2d);

_geom2d_api bool_t r2d_collidef(const R2Df *r2d1, const R2Df *r2d2);

_geom2d_api bool_t r2d_collided(const R2Dd *r2d1, const R2Dd *r2d2);

_geom2d_api bool_t r2d_containsf(const R2Df *r2d, const real32_t x, const real32_t y);

_geom2d_api bool_t r2d_containsd(const R2Dd *r2d, const real64_t x, const real64_t y);

_geom2d_api bool_t r2d_clipf(const R2Df *viewport, const R2Df *r2d);

_geom2d_api bool_t r2d_clipd(const R2Dd *viewport, const R2Dd *r2d);

_geom2d_api void r2d_joinf(R2Df *r2d, const R2Df *src);

_geom2d_api void r2d_joind(R2Dd *r2d, const R2Dd *src);

_geom2d_api extern const R2Df kR2D_ZEROf;
_geom2d_api extern const R2Dd kR2D_ZEROd;

__END_C
