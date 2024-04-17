/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: window.h
 * https://nappgui.com/en/gui/window.html
 *
 */

/* Windows */

#include "gui.hxx"

__EXTERN_C

_gui_api Window *window_create(const uint32_t flags);

_gui_api void window_destroy(Window **window);

_gui_api void window_panel(Window *window, Panel *panel);

_gui_api void window_OnClose(Window *window, Listener *listener);

_gui_api void window_OnMoved(Window *window, Listener *listener);

_gui_api void window_OnResize(Window *window, Listener *listener);

_gui_api void window_title(Window *window, const char_t *text);

_gui_api void window_show(Window *window);

_gui_api void window_hide(Window *window);

_gui_api void window_overlay(Window *window, Window *parent);

_gui_api uint32_t window_modal(Window *window, Window *parent);

_gui_api void window_stop_modal(Window *window, const uint32_t return_value);

_gui_api void window_hotkey(Window *window, const vkey_t key, const uint32_t modifiers, Listener *listener);

_gui_api void window_clear_hotkeys(Window *window);

_gui_api void window_cycle_tabstop(Window *window, const bool_t cycle);

_gui_api gui_focus_t window_next_tabstop(Window *window);

_gui_api gui_focus_t window_previous_tabstop(Window *window);

_gui_api gui_focus_t window_focus(Window *window, GuiControl *control);

_gui_api GuiControl *window_get_focus(Window *window);

_gui_api void window_focus_info(const Window *window, FocusInfo *info);

_gui_api void window_update(Window *window);

_gui_api void window_origin(Window *window, const V2Df origin);

_gui_api void window_size(Window *window, const S2Df size);

_gui_api V2Df window_get_origin(const Window *window);

_gui_api S2Df window_get_size(const Window *window);

_gui_api S2Df window_get_client_size(const Window *window);

_gui_api R2Df window_control_frame(const Window *window, const GuiControl *control);

_gui_api V2Df window_client_to_screen(const Window *window, const V2Df point);

_gui_api void window_defbutton(Window *window, Button *button);

_gui_api void window_cursor(Window *window, const gui_cursor_t cursor, const Image *image, const real32_t hot_x, const real32_t hot_y);

_gui_api void *window_imp(const Window *window);

__END_C
