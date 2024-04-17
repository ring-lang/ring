/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ossplit.h
 *
 */

/* Operating System split view */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSSplit *ossplit_create(const uint32_t flags);

_osgui_api void ossplit_destroy(OSSplit **view);

_osgui_api void ossplit_attach_control(OSSplit *view, OSControl *control);

_osgui_api void ossplit_detach_control(OSSplit *view, OSControl *control);

_osgui_api void ossplit_OnDrag(OSSplit *view, Listener *listener);

_osgui_api void ossplit_track_area(OSSplit *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

_osgui_api void ossplit_attach(OSSplit *view, OSPanel *panel);

_osgui_api void ossplit_detach(OSSplit *view, OSPanel *panel);

_osgui_api void ossplit_visible(OSSplit *view, const bool_t is_visible);

_osgui_api void ossplit_enabled(OSSplit *view, const bool_t is_enabled);

_osgui_api void ossplit_size(const OSSplit *view, real32_t *width, real32_t *height);

_osgui_api void ossplit_origin(const OSSplit *view, real32_t *x, real32_t *y);

_osgui_api void ossplit_frame(OSSplit *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
