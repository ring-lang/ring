/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: window.inl
 *
 */

/* Windows */

#include "gui.ixx"

__EXTERN_C

void _window_update(Window *window);

void *_window_ositem(Window *window);

bool_t _window_is_visible(const Window *window);

Panel *_window_main_panel(Window *window);

#if defined(__DESKTOP__)

void _window_taborder(Window *window, void *ositem);

#endif

void _window_locale(Window *window);

gui_role_t _window_role(const Window *window);

__END_C
