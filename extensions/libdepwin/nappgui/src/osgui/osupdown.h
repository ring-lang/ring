/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osupdown.h
 *
 */

/* Operating System native updown */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSUpDown *osupdown_create(const uint32_t flags);

_osgui_api void osupdown_destroy(OSUpDown **updown);

_osgui_api void osupdown_OnClick(OSUpDown *updown, Listener *listener);

_osgui_api void osupdown_tooltip(OSUpDown *updown, const char_t *text);

_osgui_api void osupdown_attach(OSUpDown *updown, OSPanel *panel);

_osgui_api void osupdown_detach(OSUpDown *updown, OSPanel *panel);

_osgui_api void osupdown_visible(OSUpDown *updown, const bool_t visible);

_osgui_api void osupdown_enabled(OSUpDown *updown, const bool_t enabled);

_osgui_api void osupdown_size(const OSUpDown *updown, real32_t *width, real32_t *height);

_osgui_api void osupdown_origin(const OSUpDown *updown, real32_t *x, real32_t *y);

_osgui_api void osupdown_frame(OSUpDown *updown, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
