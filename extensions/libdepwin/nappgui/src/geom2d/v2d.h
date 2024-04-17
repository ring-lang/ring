/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: v2d.h
 * https://nappgui.com/en/geom2d/v2d.html
 *
 */

/* Vector 2d */

#include "geom2d.hxx"

__EXTERN_C

_geom2d_api V2Df v2df(const real32_t x, const real32_t y);

_geom2d_api V2Dd v2dd(const real64_t x, const real64_t y);

_geom2d_api V2Df v2d_tof(const V2Dd *v);

_geom2d_api V2Dd v2d_tod(const V2Df *v);

_geom2d_api void v2d_tofn(V2Df *vf, const V2Dd *vd, const uint32_t n);

_geom2d_api void v2d_todn(V2Dd *vd, const V2Df *vf, const uint32_t n);

_geom2d_api V2Df v2d_addf(const V2Df *v1, const V2Df *v2);

_geom2d_api V2Dd v2d_addd(const V2Dd *v1, const V2Dd *v2);

_geom2d_api V2Df v2d_subf(const V2Df *v1, const V2Df *v2);

_geom2d_api V2Dd v2d_subd(const V2Dd *v1, const V2Dd *v2);

_geom2d_api V2Df v2d_mulf(const V2Df *v, const real32_t s);

_geom2d_api V2Dd v2d_muld(const V2Dd *v, const real64_t s);

_geom2d_api V2Df v2d_fromf(const V2Df *v, const V2Df *dir, const real32_t length);

_geom2d_api V2Dd v2d_fromd(const V2Dd *v, const V2Dd *dir, const real64_t length);

_geom2d_api V2Df v2d_midf(const V2Df *v1, const V2Df *v2);

_geom2d_api V2Dd v2d_midd(const V2Dd *v1, const V2Dd *v2);

_geom2d_api V2Df v2d_unitf(const V2Df *v1, const V2Df *v2, real32_t *dist);

_geom2d_api V2Dd v2d_unitd(const V2Dd *v1, const V2Dd *v2, real64_t *dist);

_geom2d_api V2Df v2d_unit_xyf(const real32_t x1, const real32_t y1, const real32_t x2, const real32_t y2, real32_t *dist);

_geom2d_api V2Dd v2d_unit_xyd(const real64_t x1, const real64_t y1, const real64_t x2, const real64_t y2, real64_t *dist);

_geom2d_api V2Df v2d_perp_posf(const V2Df *v);

_geom2d_api V2Dd v2d_perp_posd(const V2Dd *v);

_geom2d_api V2Df v2d_perp_negf(const V2Df *v);

_geom2d_api V2Dd v2d_perp_negd(const V2Dd *v);

_geom2d_api V2Df v2d_from_anglef(const real32_t a);

_geom2d_api V2Dd v2d_from_angled(const real64_t a);

_geom2d_api bool_t v2d_normf(V2Df *v);

_geom2d_api bool_t v2d_normd(V2Dd *v);

_geom2d_api real32_t v2d_lengthf(const V2Df *v);

_geom2d_api real64_t v2d_lengthd(const V2Dd *v);

_geom2d_api real32_t v2d_sqlengthf(const V2Df *v);

_geom2d_api real64_t v2d_sqlengthd(const V2Dd *v);

_geom2d_api real32_t v2d_dotf(const V2Df *v1, const V2Df *v2);

_geom2d_api real64_t v2d_dotd(const V2Dd *v1, const V2Dd *v2);

_geom2d_api real32_t v2d_distf(const V2Df *v1, const V2Df *v2);

_geom2d_api real64_t v2d_distd(const V2Dd *v1, const V2Dd *v2);

_geom2d_api real32_t v2d_sqdistf(const V2Df *v1, const V2Df *v2);

_geom2d_api real64_t v2d_sqdistd(const V2Dd *v1, const V2Dd *v2);

_geom2d_api real32_t v2d_anglef(const V2Df *v1, const V2Df *v2);

_geom2d_api real64_t v2d_angled(const V2Dd *v1, const V2Dd *v2);

_geom2d_api void v2d_rotatef(V2Df *v, const real32_t a);

_geom2d_api void v2d_rotated(V2Dd *v, const real64_t a);

_geom2d_api extern const V2Df kV2D_ZEROf;
_geom2d_api extern const V2Dd kV2D_ZEROd;
_geom2d_api extern const V2Df kV2D_Xf;
_geom2d_api extern const V2Dd kV2D_Xd;
_geom2d_api extern const V2Df kV2D_Yf;
_geom2d_api extern const V2Dd kV2D_Yd;

__END_C
