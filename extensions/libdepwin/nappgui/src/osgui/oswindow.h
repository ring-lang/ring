/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oswindow.h
 *
 */

/* Operating System native window */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSWindow *oswindow_create(const uint32_t flags);

_osgui_api OSWindow *oswindow_managed(void *native_ptr);

_osgui_api void oswindow_destroy(OSWindow **window);

_osgui_api void oswindow_OnMoved(OSWindow *window, Listener *listener);

_osgui_api void oswindow_OnResize(OSWindow *window, Listener *listener);

_osgui_api void oswindow_OnClose(OSWindow *window, Listener *listener);

_osgui_api void oswindow_title(OSWindow *window, const char_t *text);

_osgui_api void oswindow_edited(OSWindow *window, const bool_t is_edited);

_osgui_api void oswindow_movable(OSWindow *window, const bool_t is_movable);

_osgui_api void oswindow_z_order(OSWindow *window, OSWindow *below_window);

_osgui_api void oswindow_alpha(OSWindow *window, const real32_t alpha);

_osgui_api void oswindow_enable_mouse_events(OSWindow *window, const bool_t enabled);

_osgui_api void oswindow_hotkey(OSWindow *window, const vkey_t key, const uint32_t modifiers, Listener *listener);

_osgui_api void oswindow_taborder(OSWindow *window, OSControl *control);

_osgui_api void oswindow_tabcycle(OSWindow *window, const bool_t cycle);

_osgui_api gui_focus_t oswindow_tabstop(OSWindow *window, const bool_t next);

_osgui_api gui_focus_t oswindow_focus(OSWindow *window, OSControl *control);

_osgui_api OSControl *oswindow_get_focus(const OSWindow *window);

_osgui_api gui_tab_t oswindow_info_focus(const OSWindow *window, void **next_ctrl);

_osgui_api void oswindow_attach_panel(OSWindow *window, OSPanel *panel);

_osgui_api void oswindow_detach_panel(OSWindow *window, OSPanel *panel);

_osgui_api void oswindow_attach_window(OSWindow *parent_window, OSWindow *child_window);

_osgui_api void oswindow_detach_window(OSWindow *parent_window, OSWindow *child_window);

_osgui_api void oswindow_launch(OSWindow *window, OSWindow *parent_window);

_osgui_api void oswindow_hide(OSWindow *window, OSWindow *parent_window);

_osgui_api uint32_t oswindow_launch_modal(OSWindow *window, OSWindow *parent_window);

_osgui_api void oswindow_stop_modal(OSWindow *window, const uint32_t return_value);

_osgui_api void oswindow_get_origin(const OSWindow *window, real32_t *x, real32_t *y);

_osgui_api void oswindow_origin(OSWindow *window, const real32_t x, const real32_t y);

_osgui_api void oswindow_get_size(const OSWindow *window, real32_t *width, real32_t *height);

_osgui_api void oswindow_size(OSWindow *window, const real32_t content_width, const real32_t content_height);

_osgui_api void oswindow_set_default_pushbutton(OSWindow *window, OSButton *button);

_osgui_api void oswindow_set_cursor(OSWindow *window, Cursor *cursor);

_osgui_api void oswindow_property(OSWindow *window, const gui_prop_t prop, const void *value);

__END_C
