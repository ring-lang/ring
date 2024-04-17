/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oswindow_osx.inl
 *
 */

/* Operating System native view */

#include "osgui_osx.ixx"

__EXTERN_C

BOOL _oswindow_in_destroy(NSWindow *window);

NSView *_oswindow_main_view(OSWindow *window);

void _oswindow_next_tabstop(NSWindow *window, const bool_t keypress);

void _oswindow_prev_tabstop(NSWindow *window, const bool_t keypress);

void _oswindow_restore_focus(NSWindow *window);

bool_t _oswindow_key_down(OSControl *control, NSEvent *theEvent);

bool_t _oswindow_mouse_down(OSControl *control);

void _oswindow_release_transient_focus(OSControl *control);

__END_C
