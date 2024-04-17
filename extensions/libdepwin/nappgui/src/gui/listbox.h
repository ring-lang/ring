/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: listbox.h
 * https://nappgui.com/en/gui/listbox.html
 *
 */

/* Listbox */

#include "gui.hxx"

__EXTERN_C

_gui_api ListBox *listbox_create(void);

_gui_api void listbox_OnDown(ListBox *listbox, Listener *listener);

_gui_api void listbox_OnSelect(ListBox *listbox, Listener *listener);

_gui_api void listbox_size(ListBox *listbox, S2Df size);

_gui_api void listbox_checkbox(ListBox *listbox, const bool_t show);

_gui_api void listbox_multisel(ListBox *listbox, const bool_t multisel);

_gui_api void listbox_add_elem(ListBox *listbox, const char_t *text, const Image *image);

_gui_api void listbox_set_elem(ListBox *listbox, const uint32_t index, const char_t *text, const Image *image);

_gui_api void listbox_clear(ListBox *listbox);

_gui_api void listbox_color(ListBox *listbox, const uint32_t index, const color_t color);

_gui_api void listbox_select(ListBox *listbox, const uint32_t index, const bool_t select);

_gui_api void listbox_check(ListBox *listbox, const uint32_t index, const bool_t check);

_gui_api uint32_t listbox_count(const ListBox *listbox);

_gui_api const char_t *listbox_text(const ListBox *listbox, const uint32_t index);

_gui_api bool_t listbox_selected(const ListBox *listbox, uint32_t index);

_gui_api bool_t listbox_checked(const ListBox *listbox, uint32_t index);

__END_C
