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

#include "osgui_osx.ixx"

void _oslistener_init(ViewListeners *listeners);

void _oslistener_release(ViewListeners *listeners);

void _oslistener_set_enabled(ViewListeners *listeners, bool_t is_enabled);

void _oslistener_mouse_position_in_view_coordinates(const NSView *view, const NSPoint mouse_location_in_window, real32_t *x, real32_t *y);

void _oslistener_mouse_enter(const NSView *view, NSEvent *theEvent, const OSScrolls *scroll, ViewListeners *listeners);

void _oslistener_mouse_exit(const NSView *view, ViewListeners *listeners);

void _oslistener_mouse_moved(const NSView *view, NSEvent *theEvent, const OSScrolls *scroll, ViewListeners *listeners);

void _oslistener_mouse_down(const NSView *view, NSEvent *theEvent, const gui_mouse_t button, const OSScrolls *scroll, ViewListeners *listeners);

void _oslistener_mouse_up(const NSView *view, NSEvent *theEvent, const gui_mouse_t button, const OSScrolls *scroll, ViewListeners *listeners);

void _oslistener_mouse_dragged2(const NSView *view, NSEvent *theEvent, const gui_mouse_t button, const OSScrolls *scroll, Listener *OnDrag_listener);

void _oslistener_mouse_dragged(const NSView *view, NSEvent *theEvent, const gui_mouse_t button, const OSScrolls *scroll, ViewListeners *listeners);

void _oslistener_scroll_whell(const NSView *view, NSEvent *theEvent, const OSScrolls *scroll, ViewListeners *listeners);

void _oslistener_key_down(const NSView *view, NSEvent *theEvent, ViewListeners *listeners);

void _oslistener_key_up(const NSView *view, NSEvent *theEvent, ViewListeners *listeners);

void _oslistener_key_flags_changed(const NSView *view, NSEvent *theEvent, ViewListeners *listeners);
