/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: cir2d.h
 * https://nappgui.com/en/geom2d/cir2d.html
 *
 */

/* Circle 2d */

#include "geom2d.hxx"

__EXTERN_C

_geom2d_api Cir2Df cir2df(const real32_t x, const real32_t y, const real32_t r);

_geom2d_api Cir2Dd cir2dd(const real64_t x, const real64_t y, const real64_t r);

_geom2d_api Cir2Df cir2d_from_boxf(const Box2Df *box);

_geom2d_api Cir2Dd cir2d_from_boxd(const Box2Dd *box);

_geom2d_api Cir2Df cir2d_from_pointsf(const V2Df *p, const uint32_t n);

_geom2d_api Cir2Dd cir2d_from_pointsd(const V2Dd *p, const uint32_t n);

_geom2d_api Cir2Df cir2d_minimumf(const V2Df *p, const uint32_t n);

_geom2d_api Cir2Dd cir2d_minimumd(const V2Dd *p, const uint32_t n);

_geom2d_api real32_t cir2d_areaf(const Cir2Df *cir);

_geom2d_api real64_t cir2d_aread(const Cir2Dd *cir);

_geom2d_api bool_t cir2d_is_nullf(const Cir2Df *cir);

_geom2d_api bool_t cir2d_is_nulld(const Cir2Dd *cir);

_geom2d_api extern const Cir2Df kCIR2D_NULLf;
_geom2d_api extern const Cir2Dd kCIR2D_NULLd;

__END_C
