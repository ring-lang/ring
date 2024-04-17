/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osbutton_gtk.inl
 *
 */

/* Operating System native button */

#include "osgui_gtk.ixx"

__EXTERN_C

GtkWidget *_osbutton_focus_widget(OSButton *button);

void _osbutton_command(OSButton *button);

__END_C
