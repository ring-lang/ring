/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: menu.inl
 *
 */

/* Menu */

#include "gui.ixx"

__EXTERN_C

void _menu_destroy(Menu **menu);

void _menu_set_parent(Menu *menu);

void _menu_unset_parent(Menu *menu);

void _menu_locale(Menu *menu);

void *_menu_ositem(Menu *menu);

__END_C
