/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: listbox.inl
 *
 */

/* Listbox */

#include "gui.hxx"

__EXTERN_C

uint32_t _listbox_count(const ListBox *listbox);

void _listbox_add_enum_item(ListBox *listbox, const char_t *text);

__END_C
