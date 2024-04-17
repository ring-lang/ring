/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osview_osx.inl
 *
 */

/* Operating System native custom view */

#include "osgui_osx.ixx"

BOOL _osview_is(NSView *view);

NSView *_osview_focus_widget(NSView *view);

void _osview_scroll_event(NSView *view, const gui_orient_t orient, const gui_scroll_t event);
