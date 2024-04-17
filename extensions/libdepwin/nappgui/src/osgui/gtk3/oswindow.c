/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oswindow.c
 *
 */

/* Operating System native window */

#include "oswindow.h"
#include "oswindow.inl"
#include "oscontrol.inl"
#include "ostabstop.inl"
#include "osgui_gtk.inl"
#include "oscontrol_gtk.inl"
#include "osbutton_gtk.inl"
#include "oscombo_gtk.inl"
#include "osedit_gtk.inl"
#include "osglobals_gtk.inl"
#include "osmenu_gtk.inl"
#include "ospanel_gtk.inl"
#include "oswindow_gtk.inl"
#include <core/arrpt.h>
#include <core/arrst.h>
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _oswindow_t
{
    OSControl control;
    OSMenu *menu;
    GMainLoop *runloop;
    uint32_t modal_return;
    uint32_t flags;
    gui_role_t role;
    GtkAccelGroup *accel;
    OSPanel *main_panel;
    gint signal_delete;
    gint signal_config;
    gint signal_key;
    gint signal_state;
    Listener *OnMoved;
    Listener *OnResize;
    Listener *OnClose;
    OSTabStop tabstop;
    ArrSt(OSHotKey) *hotkeys;
    bool_t destroy_main_view;
    bool_t is_resizable;
    bool_t resize_event;
    gint current_x;
    gint current_y;
    gint current_width;
    gint current_height;
    gint minimun_width;
    gint minimun_height;
};

/*---------------------------------------------------------------------------*/

static GtkApplication *i_GTK_APP = NULL;
static GdkPixbuf *i_APP_ICON = NULL;
static bool_t i_APP_TERMINATE = FALSE;

/*---------------------------------------------------------------------------*/

static bool_t i_close(OSWindow *window, const gui_close_t close_origin)
{
    bool_t closed = TRUE;
    cassert_no_null(window);

    /* Checks if the current control allows the window to be closed */
    if (close_origin == ekGUI_CLOSE_INTRO)
        closed = ostabstop_can_close_window(&window->tabstop);

    /* Notify the user and check if allows the window to be closed */
    if (closed == TRUE && window->OnClose != NULL)
    {
        EvWinClose params;
        params.origin = close_origin;
        listener_event(window->OnClose, ekGUI_EVENT_WND_CLOSE, window, &params, &closed, OSWindow, EvWinClose, bool_t);
    }

    if (closed == TRUE)
        gtk_widget_hide(window->control.widget);

    return closed;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnClose(GtkWidget *widget, GdkEvent *event, OSWindow *window)
{
    cassert_no_null(window);
    cassert_unref(window->control.widget == widget, widget);
    unref(event);
    return (gboolean)i_close(window, ekGUI_CLOSE_BUTTON);
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnConfigure(GtkWidget *widget, GdkEventConfigure *event, OSWindow *window)
{
    if (i_APP_TERMINATE == TRUE)
        return FALSE;

    cassert_no_null(window);
    cassert_unref(window->control.widget == widget, widget);
    if (window->resize_event == FALSE)
    {
        window->resize_event = TRUE;
        return FALSE;
    }

    if (window->current_width > 0 && (window->current_width != event->width || window->current_height != event->height))
    {
        if (window->is_resizable == TRUE && window->OnResize != NULL)
        {
            EvSize params;
            EvSize result;
            params.width = (real32_t)event->width;
            params.height = (real32_t)event->height;
            listener_event(window->OnResize, ekGUI_EVENT_WND_SIZING, window, &params, &result, OSWindow, EvSize, EvSize);
            listener_event(window->OnResize, ekGUI_EVENT_WND_SIZE, window, &result, NULL, OSWindow, EvSize, void);

            if ((gint)result.width > event->width)
            {
                GdkGeometry hints;
                window->minimun_width = (gint)result.width;
                hints.min_width = window->minimun_width;
                hints.min_height = window->minimun_height;
                gtk_window_set_geometry_hints(GTK_WINDOW(window->control.widget), window->control.widget, &hints, (GdkWindowHints)GDK_HINT_MIN_SIZE);
            }

            if ((gint)result.height > event->height)
            {
                GdkGeometry hints;
                window->minimun_height = (gint)result.height;
                hints.min_width = window->minimun_width;
                hints.min_height = window->minimun_height;
                gtk_window_set_geometry_hints(GTK_WINDOW(window->control.widget), window->control.widget, &hints, (GdkWindowHints)GDK_HINT_MIN_SIZE);
            }

            window->current_width = (gint)result.width;
            window->current_height = (gint)result.height;
        }
        else
        {
            window->current_width = event->width;
            window->current_height = event->height;
        }
    }
    /* Window dimensions have not changed */
    else
    {
        /* When window is moved dragging the titlebar */
        if (window->OnMoved != NULL)
        {
            EvPos p;
            p.x = (real32_t)event->x;
            p.y = (real32_t)event->y;
            listener_event(window->OnMoved, ekGUI_EVENT_WND_MOVED, window, &p, NULL, OSWindow, EvPos, void);
        }

        /* When window is moved dragging the titlebar, the focus is lost */
        ostabstop_restore(&window->tabstop);
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnKeyPress(GtkWidget *widget, GdkEventKey *event, OSWindow *window)
{
    guint key = 0;
    cassert_no_null(window);
    cassert_no_null(event);
    key = event->keyval;

    switch (key)
    {
    case GDK_KEY_Tab:
        ostabstop_next(&window->tabstop, TRUE);
        return TRUE;

    /* https://mail.gnome.org/archives/gtk-list/1999-August/msg00127.html */
    case GDK_KEY_ISO_Left_Tab:
        ostabstop_prev(&window->tabstop, TRUE);
        return TRUE;

    case GDK_KEY_Escape:
        if (window->flags & ekWINDOW_ESC)
        {
            i_close(window, ekGUI_CLOSE_ESC);
            return TRUE;
        }
        break;

    case GDK_KEY_Return:
    case GDK_KEY_KP_Enter:
        if (window->tabstop.defbutton != NULL)
        {
            GtkWidget *focus = gtk_window_get_focus(GTK_WINDOW(widget));
            GtkWidget *bfocus = _osbutton_focus_widget(window->tabstop.defbutton);
            if (gtk_widget_get_can_focus(bfocus) == TRUE)
                gtk_window_set_focus(GTK_WINDOW(widget), bfocus);
            _osbutton_command(window->tabstop.defbutton);
            osglobals_restore_focus(widget, focus);
        }

        if (window->flags & ekWINDOW_RETURN)
        {
            i_close(window, ekGUI_CLOSE_INTRO);
            return TRUE;
        }
        break;

    default:
        break;
    }

    /* Check hotkeys */
    if (window->hotkeys != NULL)
    {
        vkey_t key = _osgui_vkey(event->keyval);
        uint32_t modifiers = _osgui_modifiers(event->state);
        if (oswindow_hotkey_process(window, window->hotkeys, key, modifiers) == TRUE)
            return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static __INLINE GtkWidget *i_gtk_window(const uint32_t flags)
{
    GtkWidget *window = NULL;
    if (flags & ekWINDOW_OFFSCREEN)
    {
        window = gtk_offscreen_window_new();
    }
    else
    {
        window = gtk_application_window_new(i_GTK_APP);
        gtk_window_set_decorated(GTK_WINDOW(window), (flags & ekWINDOW_TITLE) ? TRUE : FALSE);
    }

    return window;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnWindowState(GtkWindow *widget, GdkEventWindowState *event, OSWindow *window)
{
    unref(widget);
    cassert_no_null(event);
    cassert_no_null(window);
    if (event->new_window_state & GDK_WINDOW_STATE_FOCUSED)
        ostabstop_restore(&window->tabstop);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

OSWindow *oswindow_create(const uint32_t flags)
{
    OSWindow *window = heap_new0(OSWindow);
    GtkWidget *widget = i_gtk_window(flags);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_show(box);
    gtk_container_add(GTK_CONTAINER(widget), box);
    _oscontrol_init((OSControl *)window, ekGUI_TYPE_WINDOW, widget, widget, FALSE);
    window->flags = flags;
    window->role = ENUM_MAX(gui_role_t);
    window->destroy_main_view = TRUE;
    window->is_resizable = (flags & ekWINDOW_RESIZE) == ekWINDOW_RESIZE ? TRUE : FALSE;
    window->resize_event = TRUE;
    ostabstop_init(&window->tabstop, window);
    gtk_window_set_resizable(GTK_WINDOW(window->control.widget), (gboolean)window->is_resizable);

    if ((flags & ekWINDOW_MIN) == 0)
    {
        /* TODO: Research a secure way to disable the minimize button */
        /*
        const char *css = "window headerbar minimize titlebutton { background-image: none; }";
        GtkCssProvider *css_provider = gtk_css_provider_new();
        GtkStyleContext *style_context = gtk_widget_get_style_context(window->control.widget);
        gtk_css_provider_load_from_data(css_provider, css, -1, NULL);
        gtk_style_context_add_provider(style_context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
        const char* gdk_x11_screen_get_window_manager_name (GdkScreen *screen);
        // gtk_window_set_type_hint(GTK_WINDOW(window->control.widget), GDK_WINDOW_TYPE_HINT_MENU);
        {
            GdkDisplay *display = gdk_display_get_default();
            GdkScreen *screen = gdk_display_get_default_screen(display);
            //GdkWindow *window = gdk_screen_get_root_window(screen);
            const gchar *windowManagerName = gdk_x11_screen_get_window_manager_name(screen);
            g_print("Window Manager: %s\n", windowManagerName);
        } */
    }

    window->signal_delete = g_signal_connect(G_OBJECT(widget), "delete-event", G_CALLBACK(i_OnClose), (gpointer)window);
    window->signal_config = g_signal_connect(G_OBJECT(widget), "configure-event", G_CALLBACK(i_OnConfigure), (gpointer)window);
    window->signal_key = g_signal_connect(G_OBJECT(widget), "key-press-event", G_CALLBACK(i_OnKeyPress), (gpointer)window);
    window->signal_state = g_signal_connect(G_OBJECT(widget), "window-state-event", G_CALLBACK(i_OnWindowState), (gpointer)window);

    if (i_APP_ICON != NULL)
    {
        gtk_window_set_icon(GTK_WINDOW(window->control.widget), i_APP_ICON);
    }

    return window;
}

/*---------------------------------------------------------------------------*/

OSWindow *oswindow_managed(void *native_ptr)
{
    cassert(FALSE);
    unref(native_ptr);
    return NULL;
}

#if defined(__ASSERTS__)
/*---------------------------------------------------------------------------*/

static void i_count(GtkWidget *widget, gpointer data)
{
    uint32_t *n = (uint32_t *)data;
    unref(widget);
    *n += 1;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_num_children(GtkContainer *container)
{
    uint32_t n = 0;
    gtk_container_foreach(container, i_count, (gpointer)&n);
    return n;
}

#endif

/*---------------------------------------------------------------------------*/

void oswindow_destroy(OSWindow **window)
{
    cassert_no_null(window);
    cassert_no_null(*window);
    cassert((*window)->menu == NULL);

    gtk_widget_hide((*window)->control.widget);
    g_signal_handler_disconnect(G_OBJECT((*window)->control.widget), (*window)->signal_delete);
    g_signal_handler_disconnect(G_OBJECT((*window)->control.widget), (*window)->signal_config);
    g_signal_handler_disconnect(G_OBJECT((*window)->control.widget), (*window)->signal_key);
    g_signal_handler_disconnect(G_OBJECT((*window)->control.widget), (*window)->signal_state);

    if ((*window)->destroy_main_view == TRUE && (*window)->main_panel != NULL)
    {
        OSPanel *panel = (*window)->main_panel;
        oswindow_detach_panel(*window, panel);
        _ospanel_destroy(&panel);
    }

    cassert((*window)->main_panel == NULL);
    if ((*window)->accel != NULL)
    {
        gtk_window_remove_accel_group(GTK_WINDOW((*window)->control.widget), (*window)->accel);
        g_object_unref((*window)->accel);
    }

    listener_destroy(&(*window)->OnMoved);
    listener_destroy(&(*window)->OnResize);
    listener_destroy(&(*window)->OnClose);
    oswindow_hotkey_destroy(&(*window)->hotkeys);
    ostabstop_remove(&(*window)->tabstop);
    cassert(i_num_children(GTK_CONTAINER((*window)->control.widget)) == 1);
    cassert(i_num_children(GTK_CONTAINER(gtk_bin_get_child(GTK_BIN((*window)->control.widget)))) == 0);
    g_object_unref((*window)->control.widget);
    heap_delete(window, OSWindow);
}

/*---------------------------------------------------------------------------*/

void oswindow_OnMoved(OSWindow *window, Listener *listener)
{
    cassert_no_null(window);
    listener_update(&window->OnMoved, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_OnResize(OSWindow *window, Listener *listener)
{
    cassert_no_null(window);
    listener_update(&window->OnResize, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_OnClose(OSWindow *window, Listener *listener)
{
    cassert_no_null(window);
    listener_update(&window->OnClose, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_title(OSWindow *window, const char_t *text)
{
    cassert_no_null(window);
    gtk_window_set_title(GTK_WINDOW(window->control.widget), (const gchar *)text);
}

/*---------------------------------------------------------------------------*/

void oswindow_edited(OSWindow *window, const bool_t is_edited)
{
    unref(window);
    unref(is_edited);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oswindow_movable(OSWindow *window, const bool_t is_movable)
{
    unref(window);
    unref(is_movable);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oswindow_z_order(OSWindow *window, OSWindow *below_window)
{
    cassert_no_null(window);
    unref(window);
    unref(below_window);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oswindow_alpha(OSWindow *window, const real32_t alpha)
{
    unref(window);
    unref(alpha);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oswindow_enable_mouse_events(OSWindow *window, const bool_t enabled)
{
    unref(window);
    unref(enabled);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oswindow_hotkey(OSWindow *window, const vkey_t key, const uint32_t modifiers, Listener *listener)
{
    cassert_no_null(window);
    oswindow_hotkey_set(&window->hotkeys, key, modifiers, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_taborder(OSWindow *window, OSControl *control)
{
    cassert_no_null(window);
    ostabstop_list_add(&window->tabstop, control);
    if (control == NULL)
    {
        /* The window main panel has changed. We ensure that default button is still valid */
        window->tabstop.defbutton = oswindow_apply_default_button(window, window->tabstop.defbutton);
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_tabcycle(OSWindow *window, const bool_t cycle)
{
    cassert_no_null(window);
    window->tabstop.cycle = cycle;
}

/*---------------------------------------------------------------------------*/

gui_focus_t oswindow_tabstop(OSWindow *window, const bool_t next)
{
    cassert_no_null(window);
    if (next == TRUE)
        return ostabstop_next(&window->tabstop, FALSE);
    else
        return ostabstop_prev(&window->tabstop, FALSE);
}

/*---------------------------------------------------------------------------*/

gui_focus_t oswindow_focus(OSWindow *window, OSControl *control)
{
    cassert_no_null(window);
    cassert_no_null(control);
    return ostabstop_move(&window->tabstop, control);
}

/*---------------------------------------------------------------------------*/

OSControl *oswindow_get_focus(const OSWindow *window)
{
    cassert_no_null(window);
    return window->tabstop.current;
}

/*---------------------------------------------------------------------------*/

gui_tab_t oswindow_info_focus(const OSWindow *window, void **next_ctrl)
{
    cassert_no_null(window);
    return ostabstop_info_focus(&window->tabstop, next_ctrl);
}

/*---------------------------------------------------------------------------*/

void oswindow_attach_panel(OSWindow *window, OSPanel *panel)
{
    GtkWidget *box;
    cassert_no_null(window);
    cassert(window->main_panel == NULL);
    box = gtk_bin_get_child(GTK_BIN(window->control.widget));
    gtk_box_pack_end(GTK_BOX(box), ((OSControl *)panel)->widget, TRUE, TRUE, 0);
    window->main_panel = panel;
}

/*---------------------------------------------------------------------------*/

void oswindow_detach_panel(OSWindow *window, OSPanel *panel)
{
    GtkWidget *box;
    cassert_no_null(window);
    cassert(window->main_panel == panel);
    box = gtk_bin_get_child(GTK_BIN(window->control.widget));
    gtk_container_remove(GTK_CONTAINER(box), ((OSControl *)panel)->widget);
    window->main_panel = NULL;
}

/*---------------------------------------------------------------------------*/

void oswindow_attach_window(OSWindow *parent_window, OSWindow *child_window)
{
    unref(parent_window);
    unref(child_window);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oswindow_detach_window(OSWindow *parent_window, OSWindow *child_window)
{
    unref(parent_window);
    unref(child_window);
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void oswindow_launch(OSWindow *window, OSWindow *parent_window)
{
    cassert_no_null(window);
    window->resize_event = FALSE;
    if (parent_window != NULL)
    {
        gtk_window_set_transient_for(GTK_WINDOW(window->control.widget), GTK_WINDOW(parent_window->control.widget));
        window->role = ekGUI_ROLE_OVERLAY;
    }
    else
    {
        window->role = ekGUI_ROLE_MAIN;
    }

    gtk_widget_show(window->control.widget);
    ostabstop_restore(&window->tabstop);
}

/*---------------------------------------------------------------------------*/

void oswindow_hide(OSWindow *window, OSWindow *parent_window)
{
    cassert_no_null(window);
    unref(parent_window);
    window->role = ENUM_MAX(gui_role_t);
    gtk_window_set_transient_for(GTK_WINDOW(window->control.widget), NULL);
    gtk_widget_hide(window->control.widget);
}

/*---------------------------------------------------------------------------*/

uint32_t oswindow_launch_modal(OSWindow *window, OSWindow *parent_window)
{
    cassert_no_null(window);
    cassert(window->runloop == NULL);
    ostabstop_restore(&window->tabstop);
    gtk_window_set_modal(GTK_WINDOW(window->control.widget), TRUE);
    window->resize_event = FALSE;
    window->role = ekGUI_ROLE_MODAL;
    window->runloop = g_main_loop_new(NULL, FALSE);

    if (parent_window != NULL)
        gtk_window_set_transient_for(GTK_WINDOW(window->control.widget), GTK_WINDOW(parent_window->control.widget));

    gtk_widget_show(window->control.widget);
    g_main_loop_run(window->runloop);
    g_main_loop_unref(window->runloop);
    gtk_window_set_transient_for(GTK_WINDOW(window->control.widget), NULL);

    if (parent_window != NULL)
        ostabstop_restore(&parent_window->tabstop);

    window->runloop = NULL;
    return window->modal_return;
}

/*---------------------------------------------------------------------------*/

void oswindow_stop_modal(OSWindow *window, const uint32_t return_value)
{
    cassert_no_null(window);
    cassert_no_null(window->runloop);
    cassert(g_main_loop_is_running(window->runloop) == TRUE);
    window->modal_return = return_value;
    window->role = ENUM_MAX(gui_role_t);
    if (!(window->flags & ekWINDOW_MODAL_NOHIDE))
        gtk_widget_hide(window->control.widget);
    g_main_loop_quit(window->runloop);
    gtk_window_set_modal(GTK_WINDOW(window->control.widget), FALSE);
}

/*---------------------------------------------------------------------------*/

void oswindow_get_origin(const OSWindow *window, real32_t *x, real32_t *y)
{
    gint wx, wy;
    cassert_no_null(window);
    cassert_no_null(x);
    cassert_no_null(y);
    gtk_window_get_position(GTK_WINDOW(window->control.widget), &wx, &wy);

    if (*x == REAL32_MAX && *y == REAL32_MAX)
    {
        *x = (real32_t)wx;
        *y = (real32_t)wy;
    }
    else
    {
        gint gx, gy;
        GdkWindow *gdkwindow = gtk_widget_get_window(window->control.widget);
        gdk_window_get_geometry(gdkwindow, &gx, &gy, NULL, NULL);
        *x = (real32_t)wx + (real32_t)gx + *x;
        *y = (real32_t)wy + (real32_t)gy + *y;
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_origin(OSWindow *window, const real32_t x, const real32_t y)
{
    cassert_no_null(window);
    window->resize_event = FALSE;
    gtk_window_move(GTK_WINDOW(window->control.widget), (gint)x, (gint)y);
}

/*---------------------------------------------------------------------------*/

void oswindow_get_size(const OSWindow *window, real32_t *width, real32_t *height)
{
    gint w, h;
    cassert_no_null(window);
    cassert_no_null(width);
    cassert_no_null(height);
    gtk_window_get_size(GTK_WINDOW(window->control.widget), &w, &h);
    *width = (real32_t)w;
    *height = (real32_t)h;
}

/*---------------------------------------------------------------------------*/

static void i_update_menu_size(OSWindow *window)
{
    if (window->menu != NULL)
    {
        GtkRequisition ws, ms;
        GtkWidget *wmenu = _osmenu_widget(window->menu);
        gtk_widget_get_preferred_size(window->control.widget, &ws, NULL);
        gtk_widget_get_preferred_size(wmenu, &ms, NULL);
        if (window->is_resizable == TRUE)
        {
            gtk_widget_set_size_request(window->control.widget, -1, -1);
            gtk_window_resize(GTK_WINDOW(window->control.widget), MAX(ws.width, ms.width), ws.height + ms.height);
        }
        else
        {
            gtk_widget_set_size_request(window->control.widget, MAX(ws.width, ms.width), ws.height + ms.height);
        }
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_size(OSWindow *window, const real32_t width, const real32_t height)
{
    cassert_no_null(window);
    if (window->is_resizable == TRUE)
    {
        window->resize_event = FALSE;
        gtk_window_resize(GTK_WINDOW(window->control.widget), (gint)width, (gint)height);
        window->current_width = (gint)width;
        window->current_height = (gint)height;
        window->minimun_width = -1;
        window->minimun_height = -1;
    }
    else
    {
        gtk_widget_set_size_request(window->control.widget, (gint)width, (gint)height);
    }

    i_update_menu_size(window);
}

/*---------------------------------------------------------------------------*/

void oswindow_set_default_pushbutton(OSWindow *window, OSButton *button)
{
    cassert_no_null(window);
    window->tabstop.defbutton = oswindow_apply_default_button(window, button);
}

/*---------------------------------------------------------------------------*/

void oswindow_set_cursor(OSWindow *window, Cursor *cursor)
{
    GdkWindow *gdkwindow = NULL;
    cassert_no_null(window);
    gdkwindow = gtk_widget_get_window(window->control.widget);
    gdk_window_set_cursor(gdkwindow, (GdkCursor *)cursor);
}

/*---------------------------------------------------------------------------*/

void oswindow_property(OSWindow *window, const gui_prop_t property, const void *value)
{
    cassert_no_null(window);
    unref(value);
    switch (property)
    {
    case ekGUI_PROP_RESIZE:
        break;
    case ekGUI_PROP_CHILDREN:
        window->destroy_main_view = FALSE;
        break;
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_widget_set_focus(OSWindow *window, OSWidget *widget)
{
    OSControl *control = NULL;
    cassert_no_null(widget);
    unref(window);
    control = (OSControl *)g_object_get_data(G_OBJECT(widget), "OSControl");
    cassert_no_null(control);
    if (control->type == ekGUI_TYPE_EDITBOX)
    {
        if (_osedit_autosel((OSEdit *)control) == FALSE)
        {
#if GTK_CHECK_VERSION(3, 16, 0)
            /* osedit can be multiline text-view */
            if (GTK_IS_ENTRY(widget))
            {
                gtk_entry_grab_focus_without_selecting((GTK_ENTRY(widget)));
                return;
            }
#endif
        }
    }
    else if (control->type == ekGUI_TYPE_COMBOBOX)
    {
#if GTK_CHECK_VERSION(3, 16, 0)
        cassert(GTK_IS_ENTRY(widget));
        gtk_entry_grab_focus_without_selecting((GTK_ENTRY(widget)));
        return;
#endif
    }

    gtk_widget_grab_focus(GTK_WIDGET(widget));
}

/*---------------------------------------------------------------------------*/

static void i_get_controls(GtkWidget *widget, gpointer data)
{
    OSControl *control = OSControlPtr(g_object_get_data(G_OBJECT(widget), "OSControl"));
    if (control != NULL)
    {
        ArrPt(OSControl) *controls = (ArrPt(OSControl) *)data;
        if (arrpt_find(controls, control, OSControl) == UINT32_MAX)
            arrpt_append(controls, control, OSControl);
    }

    if (GTK_IS_CONTAINER(widget) == TRUE)
        gtk_container_foreach(GTK_CONTAINER(widget), i_get_controls, data);
}

/*---------------------------------------------------------------------------*/

void oswindow_find_all_controls(OSWindow *window, ArrPt(OSControl) *controls)
{
    cassert_no_null(window);
    cassert(arrpt_size(controls, OSControl) == 0);
    gtk_container_foreach(GTK_CONTAINER(window->control.widget), i_get_controls, (gpointer)controls);
}

/*---------------------------------------------------------------------------*/

const ArrPt(OSControl) *oswindow_get_all_controls(const OSWindow *window)
{
    cassert_no_null(window);
    return window->tabstop.controls;
}

/*---------------------------------------------------------------------------*/

void oswindow_set_app(void *app, void *icon)
{
    cassert(i_GTK_APP == NULL);
    cassert(i_APP_ICON == NULL);
    i_GTK_APP = (GtkApplication *)app;
    i_APP_ICON = (GdkPixbuf *)icon;
}

/*---------------------------------------------------------------------------*/

void oswindow_set_app_terminate(void)
{
    cassert(i_APP_TERMINATE == FALSE);
    i_APP_TERMINATE = TRUE;
}

/*---------------------------------------------------------------------------*/

void _oswindow_set_menubar(OSWindow *window, OSMenu *menu)
{
    GtkWidget *box, *wmenu;
    cassert_no_null(window);
    cassert(window->menu == NULL);
    box = gtk_bin_get_child(GTK_BIN(window->control.widget));
    wmenu = _osmenu_widget(menu);
    gtk_box_pack_start(GTK_BOX(box), wmenu, FALSE, FALSE, 0);
    gtk_widget_show_all(wmenu);
    window->menu = menu;
    if (window->accel == NULL)
    {
        window->accel = gtk_accel_group_new();
        gtk_window_add_accel_group(GTK_WINDOW(window->control.widget), window->accel);
    }

    _osmenu_set_accel(window->menu, window->accel);
    i_update_menu_size(window);
}

/*---------------------------------------------------------------------------*/

void _oswindow_unset_menubar(OSWindow *window, OSMenu *menu)
{
    GtkWidget *box, *wmenu;
    cassert_no_null(window);
    cassert(window->menu == menu);
    cassert(window->accel != NULL);
    box = gtk_bin_get_child(GTK_BIN(window->control.widget));
    wmenu = _osmenu_widget(menu);
    _osmenu_unset_accel(menu, window->accel);
    g_object_ref(wmenu);
    gtk_container_remove(GTK_CONTAINER(box), wmenu);
    window->menu = NULL;
    i_update_menu_size(window);
}

/*---------------------------------------------------------------------------*/

void _oswindow_unset_focus(OSWindow *window)
{
    cassert_no_null(window);
    /* This event can be received during window destroy */
    if (window->tabstop.tablist != NULL)
    {
        if (window->role == ekGUI_ROLE_OVERLAY)
        {
            if (i_close(window, ekGUI_CLOSE_DEACT) == TRUE)
                window->role = ENUM_MAX(gui_role_t);
        }
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE OSWindow *i_root(GtkWidget *widget)
{
    GtkWidget *root_widget = NULL;
    cassert_no_null(widget);
    root_widget = gtk_widget_get_ancestor(widget, GTK_TYPE_WINDOW);
    if (root_widget != NULL)
    {
        OSControl *control = (OSControl *)g_object_get_data(G_OBJECT(root_widget), "OSControl");
        cassert_no_null(control);
        cassert(control->type == ekGUI_TYPE_WINDOW);
        return (OSWindow *)control;
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

bool_t _oswindow_mouse_down(OSControl *control)
{
    OSWindow *window = NULL;
    cassert_no_null(control);
    window = i_root(control->widget);
    if (window != NULL)
        return ostabstop_mouse_down(&window->tabstop, control);
    return TRUE;
}

/*---------------------------------------------------------------------------*/

void _oswindow_release_transient_focus(OSControl *control)
{
    OSWindow *window = NULL;
    cassert_no_null(control);
    window = i_root(control->widget);
    if (window != NULL)
        ostabstop_release_transient(&window->tabstop, control);
}
