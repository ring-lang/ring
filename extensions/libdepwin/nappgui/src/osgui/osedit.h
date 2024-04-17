/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osedit.h
 *
 */

/* Operating System edit box */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSEdit *osedit_create(const uint32_t flags);

_osgui_api void osedit_destroy(OSEdit **edit);

_osgui_api void osedit_OnFilter(OSEdit *edit, Listener *listener);

_osgui_api void osedit_OnChange(OSEdit *edit, Listener *listener);

_osgui_api void osedit_OnFocus(OSEdit *edit, Listener *listener);

_osgui_api void osedit_text(OSEdit *edit, const char_t *text);

_osgui_api void osedit_tooltip(OSEdit *edit, const char_t *text);

_osgui_api void osedit_font(OSEdit *edit, const Font *font);

_osgui_api void osedit_align(OSEdit *edit, const align_t align);

_osgui_api void osedit_passmode(OSEdit *edit, const bool_t passmode);

_osgui_api void osedit_editable(OSEdit *edit, const bool_t is_editable);

_osgui_api void osedit_autoselect(OSEdit *edit, const bool_t autoselect);

_osgui_api void osedit_select(OSEdit *edit, const int32_t start, const int32_t end);

_osgui_api void osedit_color(OSEdit *edit, const color_t color);

_osgui_api void osedit_bgcolor(OSEdit *edit, const color_t color);

_osgui_api void osedit_vpadding(OSEdit *edit, const real32_t padding);

_osgui_api void osedit_bounds(const OSEdit *edit, const real32_t refwidth, const uint32_t lines, real32_t *width, real32_t *height);

_osgui_api void osedit_clipboard(OSEdit *edit, const clipboard_t clipboard);

_osgui_api void osedit_attach(OSEdit *edit, OSPanel *panel);

_osgui_api void osedit_detach(OSEdit *edit, OSPanel *panel);

_osgui_api void osedit_visible(OSEdit *edit, const bool_t visible);

_osgui_api void osedit_enabled(OSEdit *edit, const bool_t enabled);

_osgui_api void osedit_size(const OSEdit *edit, real32_t *width, real32_t *height);

_osgui_api void osedit_origin(const OSEdit *edit, real32_t *x, real32_t *y);

_osgui_api void osedit_frame(OSEdit *edit, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
