/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslistener.inl
 *
 */

/* View listeners */

#include "osgui_win.ixx"

__EXTERN_C

void oslistener_init(ViewListeners *listeners);

void oslistener_remove(ViewListeners *listeners);

void oslistener_set_enabled(ViewListeners *listeners, bool_t enabled);

void oslistener_draw(OSControl *sender, DCtx *ctx, const real32_t width, const real32_t height, const real32_t visible_x, const real32_t visible_y, const real32_t visible_width, const real32_t visible_height, ViewListeners *listeners);

void oslistener_mouse_exit(OSControl *sender, ViewListeners *listeners);

void oslistener_mouse_moved(OSControl *sender, WPARAM event_wParam, const real32_t x, const real32_t y, const OSScrolls *scroll, ViewListeners *listeners);

void oslistener_mouse_down(OSControl *sender, const gui_mouse_t button, const real32_t x, const real32_t y, const OSScrolls *scroll, ViewListeners *listeners);

void oslistener_mouse_up(OSControl *sender, const gui_mouse_t button, const real32_t x, const real32_t y, const OSScrolls *scroll, ViewListeners *listeners);

void oslistener_whell(OSControl *sender, WPARAM event_wParam, LPARAM event_lParam, const OSScrolls *scroll, ViewListeners *listeners);

bool_t oslistener_key_down(OSControl *sender, WPARAM wParam, LPARAM lParam, ViewListeners *listeners);

bool_t oslistener_key_up(OSControl *sender, WPARAM wParam, LPARAM lParam, ViewListeners *listeners);

__END_C
