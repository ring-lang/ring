/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osbutton.h
 *
 */

/* Operating System native button */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSButton *osbutton_create(const uint32_t flags);

_osgui_api void osbutton_destroy(OSButton **button);

_osgui_api void osbutton_OnClick(OSButton *button, Listener *listener);

_osgui_api void osbutton_text(OSButton *button, const char_t *text);

_osgui_api void osbutton_tooltip(OSButton *button, const char_t *text);

_osgui_api void osbutton_font(OSButton *button, const Font *font);

_osgui_api void osbutton_align(OSButton *button, const align_t align);

_osgui_api void osbutton_image(OSButton *button, const Image *image);

_osgui_api void osbutton_state(OSButton *button, const gui_state_t state);

_osgui_api gui_state_t osbutton_get_state(const OSButton *button);

_osgui_api void osbutton_vpadding(OSButton *button, const real32_t padding);

_osgui_api void osbutton_bounds(const OSButton *button, const char_t *text, const real32_t refwidth, const real32_t refheight, real32_t *width, real32_t *height);

_osgui_api void osbutton_attach(OSButton *button, OSPanel *panel);

_osgui_api void osbutton_detach(OSButton *button, OSPanel *panel);

_osgui_api void osbutton_visible(OSButton *button, const bool_t visible);

_osgui_api void osbutton_enabled(OSButton *button, const bool_t enabled);

_osgui_api void osbutton_size(const OSButton *button, real32_t *width, real32_t *height);

_osgui_api void osbutton_origin(const OSButton *button, real32_t *x, real32_t *y);

_osgui_api void osbutton_frame(OSButton *button, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
