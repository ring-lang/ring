/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ostabstop.inl
 *
 */

/* Tabstops functionality */

#include "osgui.ixx"

__EXTERN_C

void ostabstop_init(OSTabStop *tabstop, OSWindow *window);

void ostabstop_remove(OSTabStop *tabstop);

bool_t ostabstop_in_tablist(const OSTabStop *tabstop, const OSControl *control);

bool_t ostabstop_resign_focus(OSTabStop *tabstop, const OSControl *control);

bool_t ostabstop_accept_focus(OSTabStop *tabstop, const OSControl *control);

bool_t ostabstop_can_close_window(OSTabStop *tabstop);

void ostabstop_list_add(OSTabStop *tabstop, OSControl *control);

gui_focus_t ostabstop_next(OSTabStop *tabstop, const bool_t from_key);

gui_focus_t ostabstop_prev(OSTabStop *tabstop, const bool_t from_key);

gui_focus_t ostabstop_move(OSTabStop *tabstop, OSControl *control);

gui_focus_t ostabstop_restore(OSTabStop *tabstop);

gui_tab_t ostabstop_info_focus(const OSTabStop *tabstop, void **next_ctrl);

bool_t ostabstop_mouse_down(OSTabStop *tabstop, OSControl *control);

void ostabstop_force(OSTabStop *tabstop);

void ostabstop_release_transient(OSTabStop *tabstop, OSControl *control);

__END_C
