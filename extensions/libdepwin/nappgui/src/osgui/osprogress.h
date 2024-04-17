/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osprogress.h
 *
 */

/* Operating System native progress indicator */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSProgress *osprogress_create(const uint32_t flags);

_osgui_api void osprogress_destroy(OSProgress **progress);

_osgui_api void osprogress_position(OSProgress *progress, const real32_t position);

_osgui_api real32_t osprogress_thickness(const OSProgress *progress, const gui_size_t size);

_osgui_api void osprogress_attach(OSProgress *progress, OSPanel *panel);

_osgui_api void osprogress_detach(OSProgress *progress, OSPanel *panel);

_osgui_api void osprogress_visible(OSProgress *progress, const bool_t visible);

_osgui_api void osprogress_enabled(OSProgress *progress, const bool_t enabled);

_osgui_api void osprogress_size(const OSProgress *progress, real32_t *width, real32_t *height);

_osgui_api void osprogress_origin(const OSProgress *progress, real32_t *x, real32_t *y);

_osgui_api void osprogress_frame(OSProgress *progress, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
