/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: popup.h
 * https://nappgui.com/en/gui/popup.html
 *
 */

/* Pop-up button */

#include "gui.hxx"

__EXTERN_C

_gui_api PopUp *popup_create(void);

_gui_api void popup_OnSelect(PopUp *popup, Listener *listener);

_gui_api void popup_tooltip(PopUp *popup, const char_t *text);

_gui_api void popup_add_elem(PopUp *popup, const char_t *text, const Image *image);

_gui_api void popup_set_elem(PopUp *popup, const uint32_t index, const char_t *text, const Image *image);

_gui_api void popup_clear(PopUp *popup);

_gui_api uint32_t popup_count(const PopUp *popup);

_gui_api void popup_list_height(PopUp *popup, const uint32_t elems);

_gui_api void popup_selected(PopUp *popup, const uint32_t index);

_gui_api uint32_t popup_get_selected(const PopUp *popup);

_gui_api const char_t *popup_get_text(const PopUp *popup, const uint32_t index);

__END_C
