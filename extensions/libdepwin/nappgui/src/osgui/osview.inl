/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osview.inl
 *
 */

/* Operating System native custom view */

#include "osgui.ixx"

__EXTERN_C

void osview_detach_and_destroy(OSView **view, OSPanel *panel);

bool_t osview_resign_focus(const OSView *view);

bool_t osview_accept_focus(const OSView *view);

void osview_focus(OSView *view, const bool_t focus);

__END_C
