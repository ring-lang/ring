/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospanel.inl
 *
 */

/* Operating System native panel */

#include "osgui.ixx"

__EXTERN_C

void ospanel_detach_and_destroy(OSPanel **child, OSPanel *panel);

bool_t ospanel_with_scroll(const OSPanel *panel);

void ospanel_scroll(OSPanel *panel, const int32_t x, const int32_t y);

void ospanel_scroll_frame(const OSPanel *panel, OSFrame *rect);

__END_C
