/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: menu.h
 * https://nappgui.com/en/gui/menu.html
 *
 */

/* Menu */

#include "gui.hxx"

__EXTERN_C

_gui_api Menu *menu_create(void);

_gui_api void menu_destroy(Menu **menu);

_gui_api void menu_item(Menu *menu, MenuItem *item);

_gui_api void menu_launch(Menu *menu, const V2Df position);

_gui_api void menu_hide(Menu *menu);

_gui_api void menu_off_items(Menu *menu);

_gui_api MenuItem *menu_get_item(Menu *menu, const uint32_t index);

_gui_api uint32_t menu_size(const Menu *menu);

_gui_api void *menu_imp(const Menu *menu);

__END_C
