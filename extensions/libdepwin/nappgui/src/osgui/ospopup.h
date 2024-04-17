/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospopup.h
 *
 */

/* Operating System native popup button */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSPopUp *ospopup_create(const uint32_t flags);

_osgui_api void ospopup_destroy(OSPopUp **popup);

_osgui_api void ospopup_OnSelect(OSPopUp *popup, Listener *listener);

_osgui_api void ospopup_elem(OSPopUp *popup, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *image);

_osgui_api void ospopup_tooltip(OSPopUp *popup, const char_t *text);

_osgui_api void ospopup_font(OSPopUp *popup, const Font *font);

_osgui_api void ospopup_list_height(OSPopUp *popup, const uint32_t num_elems);

_osgui_api void ospopup_selected(OSPopUp *popup, const uint32_t index);

_osgui_api uint32_t ospopup_get_selected(const OSPopUp *popup);

_osgui_api void ospopup_bounds(const OSPopUp *popup, const char_t *text, real32_t *width, real32_t *height);

_osgui_api void ospopup_attach(OSPopUp *popup, OSPanel *panel);

_osgui_api void ospopup_detach(OSPopUp *popup, OSPanel *panel);

_osgui_api void ospopup_visible(OSPopUp *popup, const bool_t visible);

_osgui_api void ospopup_enabled(OSPopUp *popup, const bool_t enabled);

_osgui_api void ospopup_size(const OSPopUp *popup, real32_t *width, real32_t *height);

_osgui_api void ospopup_origin(const OSPopUp *popup, real32_t *x, real32_t *y);

_osgui_api void ospopup_frame(OSPopUp *popup, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
