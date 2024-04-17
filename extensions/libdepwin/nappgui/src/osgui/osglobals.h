/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osglobals.h
 *
 */

/* Operating System globals */

#include "osgui.hxx"

__EXTERN_C

_osgui_api device_t osglobals_device(const void *non_used);

_osgui_api color_t osglobals_color(const syscolor_t *color);

_osgui_api void osglobals_resolution(const void *non_used, real32_t *width, real32_t *height);

_osgui_api void osglobals_mouse_position(const void *non_used, real32_t *x, real32_t *y);

_osgui_api Cursor *osglobals_cursor(const gui_cursor_t cursor, const Image *image, const real32_t hot_x, const real32_t hot_y);

_osgui_api void osglobals_cursor_destroy(Cursor **cursor);

_osgui_api void osglobals_value(const uint32_t index, void *value);

_osgui_api void osglobals_transitions(void *nonused, const real64_t prtime, const real64_t crtime);

_osgui_api void osglobals_OnIdle(void *nonused, Listener *listener);

/* TODO: GOTO context */
_osgui_api void osglobals_theme_changed(void);

__END_C
