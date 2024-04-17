/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: menuitem.inl
 *
 */

/* Menu Item */

#include "gui.ixx"

__EXTERN_C

void _menuitem_destroy(MenuItem **item);

void *_menuitem_get_renderable(const MenuItem *item);

void _menuitem_set_parent(MenuItem *item, const uint32_t index);

void _menuitem_unset_parent(MenuItem *item);

void _menuitem_locale(MenuItem *item);

__END_C
