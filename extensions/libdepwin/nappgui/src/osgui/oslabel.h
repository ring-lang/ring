/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslabel.h
 *
 */

/* Operating System label */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSLabel *oslabel_create(const uint32_t flags);

_osgui_api void oslabel_destroy(OSLabel **label);

_osgui_api void oslabel_OnClick(OSLabel *label, Listener *listener);

_osgui_api void oslabel_OnEnter(OSLabel *label, Listener *listener);

_osgui_api void oslabel_OnExit(OSLabel *label, Listener *listener);

_osgui_api void oslabel_text(OSLabel *label, const char_t *text);

_osgui_api void oslabel_font(OSLabel *label, const Font *font);

_osgui_api void oslabel_align(OSLabel *label, const align_t align);

_osgui_api void oslabel_ellipsis(OSLabel *label, const ellipsis_t ellipsis);

_osgui_api void oslabel_color(OSLabel *label, const color_t color);

_osgui_api void oslabel_bgcolor(OSLabel *label, const color_t color);

_osgui_api void oslabel_bounds(const OSLabel *label, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height);

_osgui_api void oslabel_attach(OSLabel *label, OSPanel *panel);

_osgui_api void oslabel_detach(OSLabel *label, OSPanel *panel);

_osgui_api void oslabel_visible(OSLabel *label, const bool_t visible);

_osgui_api void oslabel_enabled(OSLabel *label, const bool_t enabled);

_osgui_api void oslabel_size(const OSLabel *label, real32_t *width, real32_t *height);

_osgui_api void oslabel_origin(const OSLabel *label, real32_t *x, real32_t *y);

_osgui_api void oslabel_frame(OSLabel *label, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
