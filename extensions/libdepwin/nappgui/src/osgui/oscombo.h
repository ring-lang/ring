/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscombo.h
 *
 */

/* Operating System native combo box */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSCombo *oscombo_create(const uint32_t flags);

_osgui_api void oscombo_destroy(OSCombo **combo);

_osgui_api void oscombo_OnFilter(OSCombo *combo, Listener *listener);

_osgui_api void oscombo_OnChange(OSCombo *combo, Listener *listener);

_osgui_api void oscombo_OnFocus(OSCombo *combo, Listener *listener);

_osgui_api void oscombo_OnSelect(OSCombo *combo, Listener *listener);

_osgui_api void oscombo_text(OSCombo *combo, const char_t *text);

_osgui_api void oscombo_tooltip(OSCombo *combo, const char_t *text);

_osgui_api void oscombo_font(OSCombo *combo, const Font *font);

_osgui_api void oscombo_align(OSCombo *combo, const align_t align);

_osgui_api void oscombo_passmode(OSCombo *combo, const bool_t passmode);

_osgui_api void oscombo_color(OSCombo *combo, const color_t color);

_osgui_api void oscombo_bgcolor(OSCombo *combo, const color_t color);

_osgui_api void oscombo_elem(OSCombo *combo, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *image);

_osgui_api void oscombo_selected(OSCombo *combo, const uint32_t index);

_osgui_api uint32_t oscombo_get_selected(const OSCombo *combo);

_osgui_api void oscombo_bounds(const OSCombo *combo, const real32_t refwidth, real32_t *width, real32_t *height);

_osgui_api void oscombo_attach(OSCombo *combo, OSPanel *panel);

_osgui_api void oscombo_detach(OSCombo *combo, OSPanel *panel);

_osgui_api void oscombo_visible(OSCombo *combo, const bool_t visible);

_osgui_api void oscombo_enabled(OSCombo *combo, const bool_t enabled);

_osgui_api void oscombo_size(const OSCombo *combo, real32_t *width, real32_t *height);

_osgui_api void oscombo_origin(const OSCombo *combo, real32_t *x, real32_t *y);

_osgui_api void oscombo_frame(OSCombo *combo, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
