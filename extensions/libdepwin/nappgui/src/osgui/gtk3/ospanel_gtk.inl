/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospanel_gtk.inl
 *
 */

/* Operating System native panel */

#include "osgui_gtk.ixx"

__EXTERN_C

void _ospanel_destroy(OSPanel **panel);

void _ospanel_attach_control(OSPanel *panel, OSControl *control);

void _ospanel_detach_control(OSPanel *panel, OSControl *control);

void _ospanel_set_capture(OSPanel *panel, OSControl *control);

void _ospanel_release_capture(OSPanel *panel);

__END_C
