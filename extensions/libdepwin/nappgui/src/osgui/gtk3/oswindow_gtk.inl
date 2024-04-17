/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oswindow_gtk.inl
 *
 */

/* Operating System native window */

#include "osgui_gtk.ixx"

__EXTERN_C

void _oswindow_set_menubar(OSWindow *window, OSMenu *menu);

void _oswindow_unset_menubar(OSWindow *window, OSMenu *menu);

void _oswindow_unset_focus(OSWindow *window);

bool_t _oswindow_mouse_down(OSControl *control);

void _oswindow_release_transient_focus(OSControl *control);

__END_C
