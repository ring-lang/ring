/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospanel_win.inl
 *
 */

/* Operating System native panel */

#include "osgui_win.ixx"

__EXTERN_C

OSPanel *_ospanel_create_default(void);

void _ospanel_destroy_default(OSPanel **panel);

void _ospanel_destroy(OSPanel **panel);

void _ospanel_resize_double_buffer(OSPanel *panel, LONG width, LONG height);

HDC _ospanel_paint_double_buffer(OSPanel *panel, const uint32_t resize_strategy, LONG *width, LONG *height);

void _ospanel_attach_control(OSPanel *panel, OSControl *control);

void _ospanel_detach_control(OSPanel *panel, OSControl *control);

COLORREF _ospanel_background_color(OSPanel *panel, OSControl *control);

void _ospanel_scroll_pos(OSPanel *panel, int *scroll_x, int *scroll_y);

__END_C
