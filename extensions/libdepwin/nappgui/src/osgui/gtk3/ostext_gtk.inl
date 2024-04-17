/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ostext_gtk.inl
 *
 */

/* Operating System textview */

#include "osgui_gtk.ixx"

__EXTERN_C

GtkWidget *_ostext_focus_widget(OSText *view);

void _ostext_set_capture(OSText *view, OSControl *control);

void _ostext_release_capture(OSText *view);

__END_C
