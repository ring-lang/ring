/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: edit.h
 * https://nappgui.com/en/gui/edit.html
 *
 */

/* Edit Box */

#include "gui.hxx"

__EXTERN_C

_gui_api Edit *edit_create(void);

_gui_api Edit *edit_multiline(void);

_gui_api void edit_OnFilter(Edit *edit, Listener *listener);

_gui_api void edit_OnChange(Edit *edit, Listener *listener);

_gui_api void edit_OnFocus(Edit *edit, Listener *listener);

_gui_api void edit_text(Edit *edit, const char_t *text);

_gui_api void edit_font(Edit *edit, const Font *font);

_gui_api void edit_align(Edit *edit, const align_t align);

_gui_api void edit_passmode(Edit *edit, const bool_t passmode);

_gui_api void edit_editable(Edit *edit, const bool_t is_editable);

_gui_api void edit_autoselect(Edit *edit, const bool_t autoselect);

_gui_api void edit_select(Edit *edit, const int32_t start, const int32_t end);

_gui_api void edit_tooltip(Edit *edit, const char_t *text);

_gui_api void edit_color(Edit *edit, const color_t color);

_gui_api void edit_color_focus(Edit *edit, const color_t color);

_gui_api void edit_bgcolor(Edit *edit, const color_t color);

_gui_api void edit_bgcolor_focus(Edit *edit, const color_t color);

_gui_api void edit_phtext(Edit *edit, const char_t *text);

_gui_api void edit_phcolor(Edit *edit, const color_t color);

_gui_api void edit_phstyle(Edit *edit, const uint32_t fstyle);

_gui_api void edit_vpadding(Edit *edit, const real32_t padding);

_gui_api const char_t *edit_get_text(const Edit *edit);

_gui_api real32_t edit_get_height(const Edit *edit);

_gui_api void edit_copy(const Edit *edit);

_gui_api void edit_cut(Edit *edit);

_gui_api void edit_paste(Edit *edit);

__END_C
