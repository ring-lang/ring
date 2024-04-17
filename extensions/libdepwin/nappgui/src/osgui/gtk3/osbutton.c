/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osbutton.c
 *
 */

/* Operating System native button */

#include "osbutton.h"
#include "osbutton.inl"
#include "osgui.inl"
#include "osbutton_gtk.inl"
#include "osgui_gtk.inl"
#include "osglobals_gtk.inl"
#include "oscontrol_gtk.inl"
#include "ospanel_gtk.inl"
#include "oswindow_gtk.inl"
#include <draw2d/font.h>
#include <draw2d/image.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _osbutton_t
{
    OSControl control;
    button_flag_t flags;
    bool_t launch_event;
    bool_t is_default;
    GtkWidget *radio;
    Font *font;
    GtkCssProvider *pfont;
    Listener *OnClick;
};

/*---------------------------------------------------------------------------*/

static gui_state_t i_get_state(const OSButton *button)
{
    cassert_no_null(button);
    switch (button_get_type(button->flags))
    {
    case ekBUTTON_PUSH:
    case ekBUTTON_FLAT:
        return ekGUI_ON;

    case ekBUTTON_RADIO:
    case ekBUTTON_CHECK2:
    {
        gboolean active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button->control.widget));
        return active == TRUE ? ekGUI_ON : ekGUI_OFF;
    }

    case ekBUTTON_CHECK3:
        if (gtk_toggle_button_get_inconsistent(GTK_TOGGLE_BUTTON(button->control.widget)) == TRUE)
        {
            return ekGUI_MIXED;
        }
        else
        {
            gboolean active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button->control.widget));
            return active == TRUE ? ekGUI_ON : ekGUI_OFF;
        }

    case ekBUTTON_FLATGLE:
    {
        gboolean active = gtk_toggle_tool_button_get_active(GTK_TOGGLE_TOOL_BUTTON(button->control.widget));
        return active == TRUE ? ekGUI_ON : ekGUI_OFF;
    }

        cassert_default();
    }

    return ekGUI_OFF;
}

/*---------------------------------------------------------------------------*/

static void i_OnClick(GtkWidget *widget, OSButton *button)
{
    cassert_no_null(button);
    cassert_unref(widget == button->control.widget, widget);
    if (button_get_type(button->flags) == ekBUTTON_CHECK3)
    {
        if (gtk_toggle_button_get_inconsistent(GTK_TOGGLE_BUTTON(button->control.widget)) == TRUE)
            gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(button->control.widget), FALSE);
    }

    if (button->launch_event == TRUE && button->OnClick != NULL)
    {
        EvButton params;
        params.index = 0;
        params.state = i_get_state(button);
        params.text = NULL;
        listener_event(button->OnClick, ekGUI_EVENT_BUTTON, button, &params, NULL, OSButton, EvButton, void);
    }

    _oswindow_release_transient_focus(OSControlPtr(button));
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnKeyPress(GtkWidget *widget, GdkEventKey *event, OSButton *button)
{
    guint key = 0;
    cassert_no_null(event);
    unref(widget);
    unref(button);

    key = event->keyval;

    /* Avoid the "DUMMY" GTK button navigation using arrows */
    if (key == GDK_KEY_Left || key == GDK_KEY_Right || key == GDK_KEY_Down || key == GDK_KEY_Up)
        return TRUE;

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnPressed(GtkWidget *widget, GdkEventButton *event, OSButton *button)
{
    unref(widget);
    unref(event);
    if (_oswindow_mouse_down(OSControlPtr(button)) == TRUE)
        return FALSE;
    return TRUE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnPushDraw(GtkWidget *widget, cairo_t *cr, OSButton *button)
{
    unref(cr);
    unref(button);
    if (button->is_default == TRUE)
        gtk_widget_set_state_flags(widget, GTK_STATE_FLAG_PRELIGHT | GTK_STATE_FLAG_FOCUSED, FALSE);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

OSButton *osbutton_create(const uint32_t flags)
{
    OSButton *button = heap_new0(OSButton);
    GtkWidget *widget = NULL;
    GtkWidget *focus_widget = NULL;
    button->flags = flags;

    switch (button_get_type(flags))
    {
    case ekBUTTON_PUSH:
        widget = gtk_button_new();
        gtk_button_set_use_underline(GTK_BUTTON(widget), TRUE);
        g_signal_connect(widget, "draw", G_CALLBACK(i_OnPushDraw), button);
        focus_widget = widget;
        break;

    case ekBUTTON_FLAT:
        widget = (GtkWidget *)gtk_tool_button_new(NULL, NULL);
        focus_widget = gtk_bin_get_child(GTK_BIN(widget));
        break;

    case ekBUTTON_FLATGLE:
        widget = (GtkWidget *)gtk_toggle_tool_button_new();
        focus_widget = gtk_bin_get_child(GTK_BIN(widget));
        break;

    case ekBUTTON_RADIO:
        widget = gtk_radio_button_new_with_label(NULL, "");
        gtk_button_set_use_underline(GTK_BUTTON(widget), TRUE);
        _oscontrol_widget_set_css(widget, "radiobutton {padding-left:0px;padding-right:0px;padding-top:0px;padding-bottom:0px;}");
        button->radio = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(widget), "");
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button->radio), TRUE);
        focus_widget = widget;
        break;

    case ekBUTTON_CHECK2:
    case ekBUTTON_CHECK3:
        widget = gtk_check_button_new();
        gtk_button_set_use_underline(GTK_BUTTON(widget), TRUE);
        _oscontrol_widget_set_css(widget, "checkbutton {padding-left:0px;padding-right:0px;padding-top:0px;padding-bottom:0px;}");
        focus_widget = widget;
        break;
    }

    g_signal_connect(G_OBJECT(widget), "clicked", G_CALLBACK(i_OnClick), (gpointer)button);
    _oscontrol_init(&button->control, ekGUI_TYPE_BUTTON, widget, focus_widget, FALSE);

    if (osbutton_text_allowed(flags) == TRUE)
    {
        const char_t *cssbut = osglobals_css_button();
        button->font = osgui_create_default_font();
        _oscontrol_widget_font(button->control.widget, cssbut, button->font, &button->pfont);
    }

    g_signal_connect(G_OBJECT(widget), "button-press-event", G_CALLBACK(i_OnPressed), (gpointer)button);
    g_signal_connect(G_OBJECT(widget), "key-press-event", G_CALLBACK(i_OnKeyPress), (gpointer)button);
    button->launch_event = TRUE;
    return button;
}

/*---------------------------------------------------------------------------*/

void osbutton_destroy(OSButton **button)
{
    cassert_no_null(button);
    cassert_no_null(*button);

    listener_destroy(&(*button)->OnClick);
    if ((*button)->radio != NULL)
    {
        /*
        A floating object was finalized. This means that someone
        called g_object_unref() on an object that had only a floating
        reference; the initial floating reference is not owned by anyone
        and must be removed with g_object_ref_sink().
        */
        g_object_ref_sink((*button)->radio);
        g_object_unref((*button)->radio);
    }

    ptr_destopt(font_destroy, &(*button)->font, Font);
    _oscontrol_destroy(*(OSControl **)button);
    heap_delete(button, OSButton);
}

/*---------------------------------------------------------------------------*/

void osbutton_OnClick(OSButton *button, Listener *listener)
{
    cassert_no_null(button);
    listener_update(&button->OnClick, listener);
}

/*---------------------------------------------------------------------------*/

void osbutton_text(OSButton *button, const char_t *text)
{
    char_t tbuff[256];
    cassert_no_null(button);
    cassert(osbutton_text_allowed(button->flags) == TRUE);
    _osgui_underline_gtk_text(text, tbuff, sizeof(tbuff));
    gtk_button_set_label(GTK_BUTTON(button->control.widget), tbuff);
}

/*---------------------------------------------------------------------------*/

void osbutton_tooltip(OSButton *button, const char_t *text)
{
    cassert_no_null(button);
    gtk_widget_set_tooltip_text(button->control.widget, (const gchar *)text);
}

/*---------------------------------------------------------------------------*/

void osbutton_font(OSButton *button, const Font *font)
{
    const char_t *cssbut = osglobals_css_button();
    cassert_no_null(button);
    cassert(osbutton_text_allowed(button->flags) == TRUE);
    _oscontrol_widget_remove_provider(button->control.widget, button->pfont);
    _oscontrol_widget_font(button->control.widget, cssbut, font, &button->pfont);
}

/*---------------------------------------------------------------------------*/

void osbutton_align(OSButton *button, const align_t align)
{
    cassert_no_null(button);
    cassert(osbutton_text_allowed(button->flags) == TRUE);
    _oscontrol_set_halign((OSControl *)button, align);
}

/*---------------------------------------------------------------------------*/

void osbutton_image(OSButton *button, const Image *image)
{
    cassert_no_null(button);
    cassert_no_null(image);
    switch (button_get_type(button->flags))
    {
    case ekBUTTON_FLAT:
    case ekBUTTON_FLATGLE:
    {
        const char_t *icon_name = _osgui_register_icon(image);
        gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(button->control.widget), icon_name);
        break;
    }

    case ekBUTTON_PUSH:
        if (image != NULL)
        {
            GdkPixbuf *pixbuf = (GdkPixbuf *)image_native(image);
            GtkWidget *widget = gtk_image_new_from_pixbuf(pixbuf);
            gtk_button_set_image(GTK_BUTTON(button->control.widget), widget);
#if GTK_CHECK_VERSION(3, 6, 0)
            gtk_button_set_always_show_image(GTK_BUTTON(button->control.widget), TRUE);
#endif
            /* g_object_unref(widget); */
        }
        else
        {
            gtk_button_set_image(GTK_BUTTON(button->control.widget), NULL);
#if GTK_CHECK_VERSION(3, 6, 0)
            gtk_button_set_always_show_image(GTK_BUTTON(button->control.widget), FALSE);
#endif
        }
        break;

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void osbutton_state(OSButton *button, const gui_state_t state)
{
    cassert_no_null(button);
    button->launch_event = FALSE;
    switch (button_get_type(button->flags))
    {
    case ekBUTTON_RADIO:
        if (state == ekGUI_ON)
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button->control.widget), TRUE);
        else
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button->radio), TRUE);
        break;

    case ekBUTTON_CHECK2:
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button->control.widget), state == ekGUI_ON ? TRUE : FALSE);
        break;

    case ekBUTTON_CHECK3:
        switch (state)
        {
        case ekGUI_ON:
            gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(button->control.widget), FALSE);
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button->control.widget), TRUE);
            break;
        case ekGUI_OFF:
            gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(button->control.widget), FALSE);
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(button->control.widget), FALSE);
            break;
        case ekGUI_MIXED:
            gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(button->control.widget), TRUE);
            break;
            cassert_default();
        }

        break;

    case ekBUTTON_FLATGLE:
        gtk_toggle_tool_button_set_active(GTK_TOGGLE_TOOL_BUTTON(button->control.widget), (state == ekGUI_ON) ? TRUE : FALSE);
        break;
        cassert_default();
    }
    button->launch_event = TRUE;
}

/*---------------------------------------------------------------------------*/

gui_state_t osbutton_get_state(const OSButton *button)
{
    return i_get_state(button);
}

/*---------------------------------------------------------------------------*/

#if defined __ASSERTS__

static __INLINE const char *i_button_label(const OSButton *button)
{
    const char *label = NULL;
    cassert_no_null(button);
    label = gtk_button_get_label(GTK_BUTTON(button->control.widget));
    if (label != NULL)
        return label;
    else
        return "";
}

/*---------------------------------------------------------------------------*/

static __INLINE bool_t i_equal_button_label(const OSButton *button, const char_t *text)
{
    char_t buff[256];
    _osgui_underline_gtk_text(text, buff, sizeof(buff));
    return str_equ_c(buff, i_button_label(button));
}

#endif

/*---------------------------------------------------------------------------*/

void osbutton_vpadding(OSButton *button, const real32_t padding)
{
    cassert_no_null(button);
    if (button_get_type(button->flags) == ekBUTTON_PUSH)
    {
        const char_t *cssbut = osglobals_css_button();
        uint32_t mpad = (uint32_t)((padding / 2) + .5f);
        char_t css[256];
#if GTK_CHECK_VERSION(3, 22, 0)
        bstd_sprintf(css, sizeof(css), "%s {padding-top:%dpx;padding-bottom:%dpx;padding-left:4px;padding-right:4px;min-height:0}", cssbut, mpad, mpad);
#else
        bstd_sprintf(css, sizeof(css), "%s {padding-top:%dpx;padding-bottom:%dpx;padding-left:4px;padding-right:4px}", cssbut, mpad, mpad);
#endif
        _oscontrol_widget_set_css(button->control.widget, css);
    }
}

/*---------------------------------------------------------------------------*/

void osbutton_bounds(const OSButton *button, const char_t *text, const real32_t refwidth, const real32_t refheight, real32_t *width, real32_t *height)
{
    cassert_no_null(button);
    cassert_no_null(width);
    cassert_no_null(height);

    switch (button_get_type(button->flags))
    {
    case ekBUTTON_PUSH:
    {
        GtkRequisition s;
        real32_t tw, th;
        cassert_unref(i_equal_button_label(button, text) == TRUE, text);
        gtk_widget_set_size_request(button->control.widget, -1, -1);
        gtk_widget_get_preferred_size(button->control.widget, &s, NULL);
        _oscontrol_text_bounds(&button->control, NULL, "O", button->font, -1, &tw, &th);
        *width = (real32_t)s.width + 2 * tw;
        *height = (real32_t)s.height;
        break;
    }

    case ekBUTTON_CHECK2:
    case ekBUTTON_CHECK3:
    case ekBUTTON_RADIO:
    {
        GtkRequisition s;
        cassert_unref(i_equal_button_label(button, text) == TRUE, text);
        gtk_widget_get_preferred_size(button->control.widget, &s, NULL);
        *width = (real32_t)s.width;
        *height = (real32_t)s.height;
        break;
    }

    case ekBUTTON_FLAT:
    case ekBUTTON_FLATGLE:
        *width = (real32_t)(uint32_t)((refwidth * 1.5f) + .5f);
        *height = (real32_t)(uint32_t)((refheight * 1.5f) + .5f);
        break;

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void osbutton_attach(OSButton *button, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)button);
}

/*---------------------------------------------------------------------------*/

void osbutton_detach(OSButton *button, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)button);
}

/*---------------------------------------------------------------------------*/

void osbutton_visible(OSButton *button, const bool_t is_visible)
{
    _oscontrol_set_visible((OSControl *)button, is_visible);
}

/*---------------------------------------------------------------------------*/

void osbutton_enabled(OSButton *button, const bool_t is_enabled)
{
    _oscontrol_set_enabled((OSControl *)button, is_enabled);
}

/*---------------------------------------------------------------------------*/

void osbutton_size(const OSButton *button, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)button, width, height);
}

/*---------------------------------------------------------------------------*/

void osbutton_origin(const OSButton *button, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)button, x, y);
}

/*---------------------------------------------------------------------------*/

void osbutton_frame(OSButton *button, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)button, x, y, width, height);
}

/*---------------------------------------------------------------------------*/

GtkWidget *_osbutton_focus_widget(OSButton *button)
{
    cassert_no_null(button);
    switch (button_get_type(button->flags))
    {
    case ekBUTTON_PUSH:
    case ekBUTTON_RADIO:
    case ekBUTTON_CHECK2:
    case ekBUTTON_CHECK3:
        return button->control.widget;

    case ekBUTTON_FLAT:
    case ekBUTTON_FLATGLE:
        /* The button inside the toolbutton */
        return gtk_bin_get_child(GTK_BIN(button->control.widget));

        cassert_default();
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

void _osbutton_command(OSButton *button)
{
    cassert_no_null(button->control.widget);
    i_OnClick(button->control.widget, button);
}

/*---------------------------------------------------------------------------*/

void osbutton_set_default(OSButton *button, const bool_t is_default)
{
    cassert_no_null(button);
    if (button_get_type(button->flags) == ekBUTTON_PUSH)
    {
        if (button->is_default != is_default)
        {
            button->is_default = is_default;
            if (is_default == FALSE)
                gtk_widget_unset_state_flags(button->control.widget, GTK_STATE_FLAG_PRELIGHT | GTK_STATE_FLAG_FOCUSED);

            gtk_widget_queue_draw(button->control.widget);
        }
    }
}
