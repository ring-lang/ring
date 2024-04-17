/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oswindow_win.inl
 *
 */

/* Operating System native window */

#include "osgui_win.ixx"

__EXTERN_C

void _oswindow_destroy_idles(void);

void _oswindow_set_menubar(OSWindow *window, HMENU hmenu);

void _oswindow_unset_menubar(OSWindow *window, HMENU hmenu);

void _oswindow_change_menubar(OSWindow *window, HMENU prev_hmenu, HMENU new_hmenu);

HWND _oswindow_set_current_popup_menu(OSWindow *window, HMENU hmenu);

HWND _oswindow_hwnd(OSWindow *window);

void _oswindow_OnIdle(Listener *listener);

uint32_t _oswindow_message_loop(OSWindow *window);

bool_t _oswindow_in_resizing(HWND child_hwnd);

bool_t _oswindow_mouse_down(OSControl *control);

void _oswindow_release_transient_focus(OSControl *control);

__END_C
