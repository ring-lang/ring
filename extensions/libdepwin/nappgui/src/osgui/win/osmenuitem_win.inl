/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmenuitem_win.inl
 *
 */

/* Operating System native menu item */

#include "osgui_win.ixx"

__EXTERN_C

void _osmenuitem_insert_in_hmenu(OSMenuItem *item, OSMenu *menu);

bool_t _osmenuitem_remove_from_hmenu(OSMenuItem *item, OSMenu *menu);

void _osmenuitem_click(OSMenuItem *item, UINT id, UINT type, UINT state);

void _osmenuitem_image_size(OSMenuItem *item, UINT id, UINT *width, UINT *height);

void _osmenuitem_draw_image(OSMenuItem *item, UINT id, UINT state, HDC hdc, const RECT *rect);

__END_C
