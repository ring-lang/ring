/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: combo.h
 * https://nappgui.com/en/gui/combo.html
 *
 */

/* Combo box */

#include "gui.hxx"

__EXTERN_C

_gui_api Combo *combo_create(void);

_gui_api void combo_OnFilter(Combo *combo, Listener *listener);

_gui_api void combo_OnChange(Combo *combo, Listener *listener);

_gui_api void combo_text(Combo *combo, const char_t *text);

_gui_api void combo_align(Combo *combo, const align_t align);

_gui_api void combo_tooltip(Combo *combo, const char_t *text);

_gui_api void combo_color(Combo *combo, const color_t color);

_gui_api void combo_color_focus(Combo *combo, const color_t color);

_gui_api void combo_bgcolor(Combo *combo, const color_t color);

_gui_api void combo_bgcolor_focus(Combo *combo, const color_t color);

_gui_api void combo_phtext(Combo *combo, const char_t *text);

_gui_api void combo_phcolor(Combo *combo, const color_t color);

_gui_api void combo_phstyle(Combo *combo, const uint32_t fstyle);

_gui_api const char_t *combo_get_text(const Combo *combo, const uint32_t index);

_gui_api uint32_t combo_count(const Combo *combo);

_gui_api void combo_add_elem(Combo *combo, const char_t *text, const Image *image);

_gui_api void combo_set_elem(Combo *combo, const uint32_t index, const char_t *text, const Image *image);

_gui_api void combo_ins_elem(Combo *combo, const uint32_t index, const char_t *text, const Image *image);

_gui_api void combo_del_elem(Combo *combo, const uint32_t index);

_gui_api void combo_duplicates(Combo *combo, const bool_t duplicates);

__END_C
