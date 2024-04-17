/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ostext.h
 *
 */

/* Operating System native text view */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSText *ostext_create(const uint32_t flags);

_osgui_api void ostext_destroy(OSText **view);

_osgui_api void ostext_OnFilter(OSText *view, Listener *listener);

_osgui_api void ostext_OnFocus(OSText *view, Listener *listener);

_osgui_api void ostext_insert_text(OSText *view, const char_t *text);

_osgui_api void ostext_set_text(OSText *view, const char_t *text);

_osgui_api void ostext_set_rtf(OSText *view, Stream *rtf_in);

_osgui_api void ostext_property(OSText *view, const gui_text_t prop, const void *value);

_osgui_api void ostext_editable(OSText *view, const bool_t is_editable);

_osgui_api const char_t *ostext_get_text(const OSText *view);

_osgui_api void ostext_scroller_visible(OSText *view, const bool_t horizontal, const bool_t vertical);

_osgui_api void ostext_set_need_display(OSText *view);

_osgui_api void ostext_clipboard(OSText *view, const clipboard_t clipboard);

_osgui_api void ostext_attach(OSText *view, OSPanel *panel);

_osgui_api void ostext_detach(OSText *view, OSPanel *panel);

_osgui_api void ostext_visible(OSText *view, const bool_t visible);

_osgui_api void ostext_enabled(OSText *view, const bool_t enabled);

_osgui_api void ostext_size(const OSText *view, real32_t *width, real32_t *height);

_osgui_api void ostext_origin(const OSText *view, real32_t *x, real32_t *y);

_osgui_api void ostext_frame(OSText *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C
