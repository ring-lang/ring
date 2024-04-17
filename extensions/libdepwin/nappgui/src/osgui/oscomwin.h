/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscomwin.h
 *
 */

/* Operating System native common windows */

#include "osgui.hxx"

__EXTERN_C

_osgui_api const char_t *oscomwin_file(OSWindow *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir, const bool_t open);

_osgui_api void oscomwin_color(OSWindow *parent, const char_t *title, const real32_t x, const real32_t y, const align_t halign, const align_t valign, const color_t current, color_t *colors, const uint32_t n, Listener *OnChange);

__END_C
