/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmenuitem.h
 *
 */

/* Operating System native menu item */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSMenuItem *osmenuitem_create(const uint32_t flags);

_osgui_api void osmenuitem_destroy(OSMenuItem **item);

_osgui_api void osmenuitem_OnClick(OSMenuItem *item, Listener *listener);

_osgui_api void osmenuitem_enabled(OSMenuItem *item, const bool_t enabled);

_osgui_api void osmenuitem_visible(OSMenuItem *item, const bool_t visible);

_osgui_api void osmenuitem_text(OSMenuItem *item, const char_t *text);

_osgui_api void osmenuitem_image(OSMenuItem *item, const Image *image);

_osgui_api void osmenuitem_key(OSMenuItem *item, const uint32_t key, const uint32_t modifiers);

_osgui_api void osmenuitem_state(OSMenuItem *item, const gui_state_t state);

_osgui_api void osmenuitem_submenu(OSMenuItem *item, OSMenu *menu);

_osgui_api void osmenuitem_unset_submenu(OSMenuItem *item, OSMenu *menu);

__END_C
