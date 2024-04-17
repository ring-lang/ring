/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospopup_win.inl
 *
 */

/* Operating System native popup button */

#include "osgui_win.ixx"

__EXTERN_C

void _ospopup_command(OSPopUp *popup, WPARAM wParam);

HWND _ospopup_focus_widget(OSPopUp *popup);

__END_C
