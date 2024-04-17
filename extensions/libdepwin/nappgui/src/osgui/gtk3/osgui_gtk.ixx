/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui_gtk.ixx
 *
 */

/* Operating system native gui */

#ifndef __OSGUIGTK_IXX__
#define __OSGUIGTK_IXX__

#include "osgui.ixx"

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

#include <sewer/nowarn.hxx>
#include <gtk/gtk.h>
#include <sewer/warn.hxx>

typedef struct _view_listeners_t ViewListeners;

struct _view_listeners_t
{
    bool_t is_enabled;
    gui_mouse_t button;
    gint enter_signal;
    gint leave_signal;
    gint pressed_signal;
    gint release_signal;
    gint moved_signal;
    gint wheel_signal;
    gint keypressed_signal;
    gint keyrelease_signal;
    Listener *OnDraw;
    Listener *OnEnter;
    Listener *OnExit;
    Listener *OnMoved;
    Listener *OnDown;
    Listener *OnUp;
    Listener *OnClick;
    Listener *OnDrag;
    Listener *OnWheel;
    Listener *OnKeyDown;
    Listener *OnKeyUp;
};

struct _oscontrol_t
{
    gui_type_t type;
    GtkWidget *widget;

#if defined(__ASSERTS__)
    bool_t is_alive;
#endif
};

struct _strsize_data_t
{
    PangoLayout *layout;
};

#endif
