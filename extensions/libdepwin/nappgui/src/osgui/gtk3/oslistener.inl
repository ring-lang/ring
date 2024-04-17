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

#include "osgui_gtk.ixx"

__EXTERN_C

void _oslistener_init(ViewListeners *listeners);

void _oslistener_remove(ViewListeners *listeners);

void _oslistener_signal(GtkWidget *widget, bool_t add, gint *signal_id, gint signal_mask, const gchar *signal_name, GCallback callback, gpointer callback_data);

void _oslistener_redraw(OSControl *sender, EvDraw *params, ViewListeners *listeners);

void _oslistener_mouse_enter(OSControl *sender, GdkEventCrossing *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners);

void _oslistener_mouse_exit(OSControl *sender, GdkEventCrossing *event, ViewListeners *listeners);

void _oslistener_mouse_moved(OSControl *sender, GdkEventMotion *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners);

void _oslistener_mouse_down(OSControl *sender, GdkEventButton *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners);

void _oslistener_mouse_up(OSControl *sender, GdkEventButton *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners);

void _oslistener_scroll_whell(OSControl *sender, GdkEventScroll *event, const real32_t scroll_x, const real32_t scroll_y, ViewListeners *listeners);

bool_t _oslistener_key_down(OSControl *sender, GdkEventKey *event, ViewListeners *listeners);

bool_t _oslistener_key_up(OSControl *sender, GdkEventKey *event, ViewListeners *listeners);

__END_C
