/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: obb2d.h
 * https://nappgui.com/en/geom2d/obb2d.html
 *
 */

/* Oriented Box 2d */

#include "geom2d.hxx"

__EXTERN_C

_geom2d_api OBB2Df *obb2d_createf(const V2Df *center, const real32_t width, const real32_t height, const real32_t angle);

_geom2d_api OBB2Dd *obb2d_created(const V2Dd *center, const real64_t width, const real64_t height, const real64_t angle);

_geom2d_api OBB2Df *obb2d_from_linef(const V2Df *p0, const V2Df *p1, const real32_t thickness);

_geom2d_api OBB2Dd *obb2d_from_lined(const V2Dd *p0, const V2Dd *p1, const real64_t thickness);

_geom2d_api OBB2Df *obb2d_from_pointsf(const V2Df *p, const uint32_t n);

_geom2d_api OBB2Dd *obb2d_from_pointsd(const V2Dd *p, const uint32_t n);

_geom2d_api OBB2Df *obb2d_copyf(const OBB2Df *obb);

_geom2d_api OBB2Dd *obb2d_copyd(const OBB2Dd *obb);

_geom2d_api void obb2d_destroyf(OBB2Df **obb);

_geom2d_api void obb2d_destroyd(OBB2Dd **obb);

_geom2d_api void obb2d_updatef(OBB2Df *obb, const V2Df *center, const real32_t width, const real32_t height, const real32_t angle);

_geom2d_api void obb2d_updated(OBB2Dd *obb, const V2Dd *center, const real64_t width, const real64_t height, const real64_t angle);

_geom2d_api void obb2d_movef(OBB2Df *obb, const real32_t offset_x, const real32_t offset_y);

_geom2d_api void obb2d_moved(OBB2Dd *obb, const real64_t offset_x, const real64_t offset_y);

_geom2d_api void obb2d_transformf(OBB2Df *obb, const T2Df *t2d);

_geom2d_api void obb2d_transformd(OBB2Dd *obb, const T2Dd *t2d);

_geom2d_api const V2Df *obb2d_cornersf(const OBB2Df *obb);

_geom2d_api const V2Dd *obb2d_cornersd(const OBB2Dd *obb);

_geom2d_api V2Df obb2d_centerf(const OBB2Df *obb);

_geom2d_api V2Dd obb2d_centerd(const OBB2Dd *obb);

_geom2d_api real32_t obb2d_widthf(const OBB2Df *obb);

_geom2d_api real64_t obb2d_widthd(const OBB2Dd *obb);

_geom2d_api real32_t obb2d_heightf(const OBB2Df *obb);

_geom2d_api real64_t obb2d_heightd(const OBB2Dd *obb);

_geom2d_api real32_t obb2d_anglef(const OBB2Df *obb);

_geom2d_api real64_t obb2d_angled(const OBB2Dd *obb);

_geom2d_api real32_t obb2d_areaf(const OBB2Df *obb);

_geom2d_api real64_t obb2d_aread(const OBB2Dd *obb);

_geom2d_api Box2Df obb2d_boxf(const OBB2Df *obb);

_geom2d_api Box2Dd obb2d_boxd(const OBB2Dd *obb);

__END_C
