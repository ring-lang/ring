/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscomwin.c
 *
 */

/* Operating System native common windows */

#include "oscomwin.h"
#include "osgui.inl"
#include "osgui_gtk.inl"
#include "oscontrol_gtk.inl"
#include <draw2d/color.h>
#include <core/event.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

static char *kFILENAME = NULL;
typedef struct _cdata_t CData;

struct _cdata_t
{
    gint x;
    gint y;
    align_t halign;
    align_t valign;
    GtkWidget *parent;
};

/*---------------------------------------------------------------------------*/

const char_t *oscomwin_file(OSWindow *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir, const bool_t open)
{
    GtkWidget *dialog = NULL;
    GtkFileChooserAction action;
    bool_t dirmode = FALSE;
    gint res;

    unref(start_dir);

    if (size == 1 && str_equ_c(ftypes[0], "..DIR..") == TRUE)
    {
        action = open ? GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER : GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
        dirmode = TRUE;
    }
    else
    {
        action = open ? GTK_FILE_CHOOSER_ACTION_OPEN : GTK_FILE_CHOOSER_ACTION_SAVE;
        dirmode = FALSE;
    }

    dialog = gtk_file_chooser_dialog_new(
        /*"Open File"*/ NULL,
        parent ? GTK_WINDOW(((OSControl *)parent)->widget) : NULL, action,
        "_Cancel", GTK_RESPONSE_CANCEL,
        open ? "_Open" : "_Save", GTK_RESPONSE_ACCEPT,
        NULL);

    if (!dirmode && size > 0)
    {
        uint32_t i = 0;
        for (i = 0; i < size; ++i)
        {
            String *pattern = str_printf("*.%s", ftypes[i]);
            GtkFileFilter *filter = gtk_file_filter_new();
            gtk_file_filter_set_name(filter, (const gchar *)tc(pattern));
            gtk_file_filter_add_pattern(filter, (const gchar *)tc(pattern));
            gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);
            str_destroy(&pattern);
            /* g_object_unref(filter); */
        }
    }

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (kFILENAME)
    {
        g_free(kFILENAME);
        kFILENAME = NULL;
    }

    if (res == GTK_RESPONSE_ACCEPT)
    {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        kFILENAME = gtk_file_chooser_get_filename(chooser);
    }

    gtk_widget_destroy(dialog);
    return (const char_t *)kFILENAME;
}

/*---------------------------------------------------------------------------*/

static void i_OnRealize(GtkWidget *widget, CData *data)
{
    cassert_no_null(data);

    if (data->halign != ekLEFT || data->valign != ekTOP)
    {
        gint width, height;
        gtk_window_get_size(GTK_WINDOW(widget), &width, &height);

        switch (data->halign)
        {
        case ekLEFT:
        case ekJUSTIFY:
            break;
        case ekCENTER:
            data->x -= width / 2;
            break;
        case ekRIGHT:
            data->x -= width;
            break;
        }

        switch (data->valign)
        {
        case ekTOP:
        case ekJUSTIFY:
            break;
        case ekCENTER:
            data->y -= height / 2;
            break;
        case ekRIGHT:
            data->y -= height;
            break;
        }
    }

    /* With transient windows is not possible control the global window position.
    if (data->parent != NULL)
     gtk_window_set_transient_for(GTK_WINDOW(widget), GTK_WINDOW(data->parent));
    gtk_window_set_position(GTK_WINDOW(widget), GTK_WIN_POS_NONE); */
    gtk_window_move(GTK_WINDOW(widget), data->x, data->y + 5);
}

/*---------------------------------------------------------------------------*/

void oscomwin_color(OSWindow *parent, const char_t *title, const real32_t x, const real32_t y, const align_t halign, const align_t valign, const color_t current, color_t *colors, const uint32_t n, Listener *OnChange)
{
    GtkWidget *dialog = NULL;
    GtkColorChooser *chooser = NULL;
    CData data;
    gint res = 0;
    GdkRGBA curcol;

    dialog = gtk_color_chooser_dialog_new(title, NULL);
    chooser = GTK_COLOR_CHOOSER(dialog);

    _oscontrol_to_gdkrgba(current, &curcol);
    gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
    gtk_color_chooser_set_use_alpha(chooser, TRUE);
    gtk_color_chooser_set_rgba(chooser, &curcol);

    if (n > 0)
    {
        uint32_t i, nm = MIN(n, 16);
        GdkRGBA cols[16];
        for (i = 0; i < nm; ++i)
            _oscontrol_to_gdkrgba(colors[i], &cols[i]);
        gtk_color_chooser_add_palette(chooser, GTK_ORIENTATION_HORIZONTAL, 8, nm, cols);
    }

    data.x = (gint)x;
    data.y = (gint)y;
    data.halign = halign;
    data.valign = valign;
    data.parent = parent ? ((OSControl *)parent)->widget : NULL;
    g_signal_connect(dialog, "realize", G_CALLBACK(i_OnRealize), &data);

    /* gtk_widget_show(dialog); */
    res = gtk_dialog_run(GTK_DIALOG(dialog));

    if (res == -5)
    {
        color_t selcol = 0;
        gtk_color_chooser_get_rgba(chooser, &curcol);
        selcol = _oscontrol_from_gdkrgba(&curcol);
        listener_event(OnChange, ekGUI_EVENT_COLOR, NULL, &selcol, NULL, void, color_t, void);
    }

    gtk_widget_destroy(dialog);
    listener_destroy(&OnChange);
}

/*---------------------------------------------------------------------------*/
