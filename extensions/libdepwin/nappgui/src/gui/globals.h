/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: globals.h
 *
 */

/* System globals */

#include "gui.hxx"

__EXTERN_C

_gui_api device_t globals_device(void);

_gui_api void globals_resolution(S2Df *resolution);

_gui_api V2Df globals_mouse_position(void);

__END_C
