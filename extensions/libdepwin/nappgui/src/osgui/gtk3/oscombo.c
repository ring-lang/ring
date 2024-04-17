/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscombo.c
 *
 */

/* Operating System native combo box */

#include "oscombo.h"
#include "oscombo.inl"
#include "osgui.inl"
#include "oscombo_gtk.inl"
#include "osgui_gtk.inl"
#include "oscontrol_gtk.inl"
#include "ospanel_gtk.inl"
#include "oswindow_gtk.inl"
#include <draw2d/font.h>
#include <draw2d/image.h>
#include <core/arrpt.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/cassert.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

struct _oscombo_t
{
    OSControl control;
    uint32_t fsize;
    GtkWidget *combo;
    GtkWidget *button;
    GtkCellRenderer *imgcell;
    GtkCellRenderer *txtcell;
    GtkCssProvider *color;
    GtkCssProvider *bgcolor;
    GtkCssProvider *font;
    bool_t launch_event;
    color_t ccolor;
    int32_t select_start;
    int32_t select_end;
    Listener *OnFilter;
    Listener *OnChange;
    Listener *OnFocus;
    Listener *OnSelect;
    ArrPt(String) *texts;
    ArrPt(Image) *images;
};

/*---------------------------------------------------------------------------*/

static void i_OnChange(GtkEditable *editable, OSCombo *combo)
{
    GtkWidget *entry = NULL;
    cassert_no_null(combo);
    entry = gtk_bin_get_child(GTK_BIN(combo->combo));
    if (combo->launch_event == TRUE && gtk_widget_is_sensitive(entry) && combo->OnFilter != NULL)
    {
        EvText params;
        EvTextFilter result;
        params.text = (const char_t *)gtk_entry_get_text(GTK_ENTRY(entry));
        params.cpos = (uint32_t)gtk_editable_get_position(editable);
        result.apply = FALSE;
        result.text[0] = '\0';
        result.cpos = UINT32_MAX;
        listener_event(combo->OnFilter, ekGUI_EVENT_TXTFILTER, combo, &params, &result, OSCombo, EvText, EvTextFilter);

        if (result.apply == TRUE)
        {
            bool_t prev = combo->launch_event;
            combo->launch_event = FALSE;
            oscombo_text(combo, result.text);
            combo->launch_event = prev;
        }

        if (result.cpos != UINT32_MAX)
            gtk_editable_set_position(editable, (gint)result.cpos);
        else
            gtk_editable_set_position(editable, (gint)params.cpos);
    }
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnPressed(GtkWidget *widget, GdkEvent *event, OSCombo *combo)
{
    cassert_no_null(combo);
    cassert_no_null(event);
    cassert_unref(widget == combo->control.widget, widget);
    cassert(GTK_IS_EVENT_BOX(widget) == TRUE);
    if (event->button.button == 1)
    {
        if (_oswindow_mouse_down(OSControlPtr(combo)) == TRUE)
        {
            bool_t over = FALSE;
#if GTK_CHECK_VERSION(3, 16, 0)
            over = _oscontrol_widget_mouse_over(combo->button, event);
#else
            over = _oscontrol_widget_mouse_over_right(combo->button, event, 30);
#endif
            if (over == TRUE)
                gtk_combo_box_popup(GTK_COMBO_BOX(combo->combo));
        }
    }
    return TRUE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnEnter(GtkWidget *widget, GdkEvent *event, OSCombo *combo)
{
    cassert_no_null(combo);
    cassert_unref(widget == combo->control.widget, widget);
    unref(event);
    gtk_widget_set_state_flags(combo->button, GTK_STATE_FLAG_PRELIGHT, FALSE);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnLeave(GtkWidget *widget, GdkEvent *event, OSCombo *combo)
{
    cassert_no_null(combo);
    cassert_unref(widget == combo->control.widget, widget);
    unref(event);
    gtk_widget_unset_state_flags(combo->button, GTK_STATE_FLAG_PRELIGHT);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

/*
static gboolean i_select(OSCombo *combo)
{
    cassert_no_null(combo);
    if (combo->select_start != INT32_MAX)
    {
        GtkWidget *entry = gtk_bin_get_child(GTK_BIN(combo->control.widget));
        cassert(edit->select_start >= -1);
        cassert(edit->select_end >= -1);
        gtk_editable_select_region(GTK_EDITABLE(entry), (gint)combo->select_start, (gint)combo->select_end);
        combo->select_start = INT32_MAX;
        combo->select_end = INT32_MAX;
    }

    return FALSE;
}*/

/*---------------------------------------------------------------------------*/

OSCombo *oscombo_create(const uint32_t flags)
{
    OSCombo *combo = heap_new0(OSCombo);
    Font *font = osgui_create_default_font();
    GtkWidget *widget = gtk_combo_box_new_with_entry();
    GtkWidget *entry = gtk_bin_get_child(GTK_BIN(widget));
    cassert_unref(flags == ekCOMBO_FLAG, flags);
    combo->select_start = INT32_MAX;
    combo->select_end = INT32_MAX;
    gtk_entry_set_width_chars(GTK_ENTRY(entry), 0);
    combo->imgcell = gtk_cell_renderer_pixbuf_new();
    combo->txtcell = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(widget), combo->imgcell, FALSE);
    gtk_cell_layout_pack_end(GTK_CELL_LAYOUT(widget), combo->txtcell, TRUE);
    gtk_cell_renderer_set_alignment(combo->imgcell, 0.f, .5);
    gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(widget), combo->imgcell, "pixbuf", 0, NULL);
    /* gtk_cell_renderer_set_padding(combo->imgcell, 0, 0); */
    gtk_cell_renderer_set_alignment(combo->txtcell, 0.f, .5);
    /* gtk_cell_renderer_set_padding(combo->txtcell, 0, 0); */
    gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(widget), combo->txtcell, "text", 1, NULL);
    g_signal_connect(G_OBJECT(entry), "changed", G_CALLBACK(i_OnChange), (gpointer)combo);

#if GTK_CHECK_VERSION(3, 22, 0)
    combo->button = gtk_bin_get_child(GTK_BIN(widget));
    cassert(GTK_IS_ENTRY(combo->button));
    combo->button = gtk_widget_get_parent(combo->button);
    cassert(GTK_IS_BOX(combo->button));
    cassert(_oscontrol_num_children(GTK_CONTAINER(combo->button)) == 2);
    combo->button = _oscontrol_get_child(GTK_CONTAINER(combo->button), 1);
    cassert(GTK_IS_TOGGLE_BUTTON(combo->button));
#else
    combo->button = widget;
#endif

    /*
      Encapsulate the combo widget in an event box
      We need to capture the 'button-press-event' and is not possible doing directly in GtkComboBox
      https://stackoverflow.com/questions/9145741/how-to-detect-mouse-click-in-gtkcombobox
    */
    combo->combo = widget;
    widget = gtk_event_box_new();
    gtk_container_add(GTK_CONTAINER(widget), combo->combo);
    gtk_event_box_set_above_child(GTK_EVENT_BOX(widget), TRUE);
    gtk_widget_add_events(widget, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK);
    g_signal_connect(G_OBJECT(widget), "button-press-event", G_CALLBACK(i_OnPressed), (gpointer)combo);
    g_signal_connect(G_OBJECT(widget), "enter-notify-event", G_CALLBACK(i_OnEnter), (gpointer)combo);
    g_signal_connect(G_OBJECT(widget), "leave-notify-event", G_CALLBACK(i_OnLeave), (gpointer)combo);
    gtk_widget_show(combo->combo);

    _oscontrol_init(&combo->control, ekGUI_TYPE_COMBOBOX, widget, entry, TRUE);
    _oscontrol_widget_font(entry, "entry", font, &combo->font);
    combo->fsize = (uint32_t)(font_size(font) + 2.5f);
    font_destroy(&font);
    combo->texts = arrpt_create(String);
    combo->images = arrpt_create(Image);
    combo->launch_event = TRUE;
    return combo;
}

/*---------------------------------------------------------------------------*/

static void i_img_dest(Image **image)
{
    cassert_no_null(image);
    if (*image != NULL)
        image_destroy(image);
}

/*---------------------------------------------------------------------------*/

void oscombo_destroy(OSCombo **combo)
{
    cassert_no_null(combo);
    cassert_no_null(*combo);
    listener_destroy(&(*combo)->OnFilter);
    listener_destroy(&(*combo)->OnChange);
    listener_destroy(&(*combo)->OnFocus);
    listener_destroy(&(*combo)->OnSelect);
    arrpt_destroy(&(*combo)->texts, str_destroy, String);
    arrpt_destroy(&(*combo)->images, i_img_dest, Image);
    _oscontrol_destroy(*(OSControl **)combo);
    heap_delete(combo, OSCombo);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnFilter(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnFilter, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnChange(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnChange, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnFocus(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnFocus, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_OnSelect(OSCombo *combo, Listener *listener)
{
    cassert_no_null(combo);
    listener_update(&combo->OnSelect, listener);
}

/*---------------------------------------------------------------------------*/

void oscombo_text(OSCombo *combo, const char_t *text)
{
    GtkWidget *entry;
    cassert_no_null(combo);
    cassert(GTK_IS_EVENT_BOX(combo->control.widget));
    cassert(GTK_IS_COMBO_BOX(combo->combo));
    combo->launch_event = FALSE;
    entry = gtk_bin_get_child(GTK_BIN(combo->combo));
    gtk_entry_set_text(GTK_ENTRY(entry), (const gchar *)text);
    combo->launch_event = TRUE;
}

/*---------------------------------------------------------------------------*/

void oscombo_tooltip(OSCombo *combo, const char_t *text)
{
    cassert_no_null(combo);
    cassert(GTK_IS_EVENT_BOX(combo->control.widget));
    cassert(GTK_IS_COMBO_BOX(combo->combo));
    gtk_widget_set_tooltip_text(combo->combo, (const gchar *)text);
}

/*---------------------------------------------------------------------------*/

void oscombo_font(OSCombo *combo, const Font *font)
{
    GtkWidget *entry;
    cassert_no_null(combo);
    cassert(GTK_IS_EVENT_BOX(combo->control.widget));
    cassert(GTK_IS_COMBO_BOX(combo->combo));
    entry = gtk_bin_get_child(GTK_BIN(combo->combo));
    _oscontrol_widget_remove_provider(entry, combo->font);
    _oscontrol_widget_font(entry, "entry", font, &combo->font);
    combo->fsize = (uint32_t)(font_size(font) + 2.5f);
}

/*---------------------------------------------------------------------------*/

void oscombo_align(OSCombo *combo, const align_t align)
{
    unref(combo);
    unref(align);
    cassert_msg(FALSE, "Not implemented");
}

/*---------------------------------------------------------------------------*/

void oscombo_passmode(OSCombo *combo, const bool_t passmode)
{
    unref(combo);
    unref(passmode);
    cassert_msg(FALSE, "Not implemented");
}

/*---------------------------------------------------------------------------*/

static void i_set_color(OSCombo *combo, const color_t color)
{
    GtkWidget *entry;
    cassert_no_null(combo);
    cassert(GTK_IS_EVENT_BOX(combo->control.widget));
    cassert(GTK_IS_COMBO_BOX(combo->combo));
    entry = gtk_bin_get_child(GTK_BIN(combo->combo));
    if (combo->color != NULL)
    {
        _oscontrol_widget_remove_provider(entry, combo->color);
        combo->color = NULL;
    }

    if (color != 0)
        _oscontrol_widget_color(entry, "entry", color, &combo->color);
}

/*---------------------------------------------------------------------------*/

void oscombo_color(OSCombo *combo, const color_t color)
{
    i_set_color(combo, color);
    combo->ccolor = color;
}

/*---------------------------------------------------------------------------*/

void oscombo_bgcolor(OSCombo *combo, const color_t color)
{
    GtkWidget *entry;
    cassert_no_null(combo);
    cassert(GTK_IS_EVENT_BOX(combo->control.widget));
    cassert(GTK_IS_COMBO_BOX(combo->combo));
    entry = gtk_bin_get_child(GTK_BIN(combo->combo));
    if (combo->bgcolor != NULL)
    {
        _oscontrol_widget_remove_provider(entry, combo->bgcolor);
        combo->bgcolor = NULL;
    }

    if (color != UINT32_MAX)
        _oscontrol_widget_bg_color(entry, "entry", color, &combo->bgcolor);
}

/*---------------------------------------------------------------------------*/

/* Is not possible configure the visible items in drop-down menu
   https://gitlab.gnome.org/GNOME/gtk/issues/158 */
void oscombo_elem(OSCombo *combo, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *image)
{
    uint32_t imgw, imgh;
    cassert_no_null(combo);
    cassert(GTK_IS_EVENT_BOX(combo->control.widget));
    cassert(GTK_IS_COMBO_BOX(combo->combo));

    _oscombo_elem(GTK_COMBO_BOX(combo->combo), op, index, text, image, combo->texts, combo->images, &imgw, &imgh);

    if (imgh < combo->fsize)
        imgh = combo->fsize;

    gtk_cell_renderer_set_fixed_size(combo->imgcell, imgw, imgh);
    gtk_cell_renderer_set_fixed_size(combo->txtcell, -1, imgh);

    /*    if (current == -1)
       current = 0;

   combo->launch_event = FALSE;
   gint current;
   current = gtk_combo_box_get_active(GTK_COMBO_BOX(combo->control.widget));
   gtk_combo_box_set_active(GTK_COMBO_BOX(popup->control.widget), current);
   combo->launch_event = TRUE;
 */
}

/*---------------------------------------------------------------------------*/

void oscombo_selected(OSCombo *combo, const uint32_t index)
{
    unref(combo);
    unref(index);
    cassert_msg(FALSE, "Not implemented");
}

/*---------------------------------------------------------------------------*/

uint32_t oscombo_get_selected(const OSCombo *combo)
{
    unref(combo);
    cassert_msg(FALSE, "Not implemented");
    return 0;
}

/*---------------------------------------------------------------------------*/

void oscombo_bounds(const OSCombo *combo, const real32_t refwidth, real32_t *width, real32_t *height)
{
    GtkRequisition minsize;
    cassert_no_null(combo);
    cassert_no_null(width);
    cassert_no_null(height);
    gtk_widget_set_size_request(combo->control.widget, -1, -1);
    gtk_widget_get_preferred_size(combo->control.widget, &minsize, NULL);
    *width = refwidth;
    *height = (real32_t)minsize.height;
}

/*---------------------------------------------------------------------------*/

void oscombo_attach(OSCombo *combo, OSPanel *panel)
{
    _ospanel_attach_control(panel, (OSControl *)combo);
}

/*---------------------------------------------------------------------------*/

void oscombo_detach(OSCombo *combo, OSPanel *panel)
{
    _ospanel_detach_control(panel, (OSControl *)combo);
}

/*---------------------------------------------------------------------------*/

void oscombo_visible(OSCombo *combo, const bool_t is_visible)
{
    _oscontrol_set_visible((OSControl *)combo, is_visible);
}

/*---------------------------------------------------------------------------*/

void oscombo_enabled(OSCombo *combo, const bool_t is_enabled)
{
    _oscontrol_set_enabled((OSControl *)combo, is_enabled);
    i_set_color(combo, is_enabled ? combo->ccolor : UINT32_MAX);
}

/*---------------------------------------------------------------------------*/

void oscombo_size(const OSCombo *combo, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)combo, width, height);
}

/*---------------------------------------------------------------------------*/

void oscombo_origin(const OSCombo *combo, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)combo, x, y);
}

/*---------------------------------------------------------------------------*/

void oscombo_frame(OSCombo *combo, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    _oscontrol_set_frame((OSControl *)combo, x, y, width, height);
    gtk_widget_set_size_request(combo->combo, (gint)width, (gint)height);
}

/*---------------------------------------------------------------------------*/

bool_t oscombo_resign_focus(const OSCombo *combo)
{
    bool_t lost_focus = TRUE;
    GtkWidget *entry = NULL;
    cassert_no_null(combo);
    cassert(GTK_IS_EVENT_BOX(combo->control.widget));
    cassert(GTK_IS_COMBO_BOX(combo->combo));
    entry = gtk_bin_get_child(GTK_BIN(combo->combo));
    if (combo->launch_event == TRUE && gtk_widget_is_sensitive(entry) && combo->OnChange != NULL)
    {
        EvText params;
        params.text = (const char_t *)gtk_entry_get_text(GTK_ENTRY(entry));
        listener_event(combo->OnChange, ekGUI_EVENT_TXTCHANGE, combo, &params, &lost_focus, OSCombo, EvText, bool_t);
    }

    return lost_focus;
}

/*---------------------------------------------------------------------------*/

void oscombo_focus(OSCombo *combo, const bool_t focus)
{
    cassert_no_null(combo);
    if (combo->OnFocus != NULL)
    {
        bool_t params = focus;
        listener_event(combo->OnFocus, ekGUI_EVENT_FOCUS, combo, &params, NULL, OSCombo, bool_t, void);
    }
}

/*---------------------------------------------------------------------------*/

GtkWidget *_oscombo_focus_widget(OSCombo *combo)
{
    cassert_no_null(combo);
    cassert(GTK_IS_EVENT_BOX(combo->control.widget));
    cassert(GTK_IS_COMBO_BOX(combo->combo));
    return gtk_bin_get_child(GTK_BIN(combo->combo));
}

/*---------------------------------------------------------------------------*/

void _oscombo_elem(GtkComboBox *combo, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *image, ArrPt(String) *texts, ArrPt(Image) *images, uint32_t *imgwidth, uint32_t *imgheight)
{
    cassert_no_null(combo);
    cassert_no_null(imgwidth);
    cassert_no_null(imgheight);
    switch (op)
    {
    case ekCTRL_OP_ADD:
    {
        String *str = str_c(text);
        Image *img = image ? image_copy(image) : NULL;
        arrpt_append(texts, str, String);
        arrpt_append(images, img, Image);
        break;
    }

    case ekCTRL_OP_DEL:
        arrpt_delete(texts, index, str_destroy, String);
        arrpt_delete(images, index, i_img_dest, Image);
        break;

    case ekCTRL_OP_INS:
    {
        String *str = str_c(text);
        Image *img = image ? image_copy(image) : NULL;
        arrpt_insert(texts, index, str, String);
        arrpt_insert(images, index, img, Image);
        break;
    }

    case ekCTRL_OP_SET:
    {
        String **str = arrpt_all(texts, String) + index;
        str_upd(str, text);
        if (image != NULL)
        {
            Image **img = arrpt_all(images, Image) + index;
            image_destroy(img);
            *img = image_copy(image);
        }
        break;
    }

        cassert_default();
    }

    {
        GtkListStore *store = gtk_list_store_new(2, GDK_TYPE_PIXBUF, G_TYPE_STRING);
        GtkTreeIter iter;
        String **strs = arrpt_all(texts, String);
        Image **imgs = arrpt_all(images, Image);
        uint32_t i, n = arrpt_size(texts, String);
        uint32_t maxw = 0, maxh = 0;
        cassert(n == arrpt_size(images, Image));
        for (i = 0; i < n; ++i, ++strs, ++imgs)
        {
            const void *pixbuf = NULL;
            if (*imgs != NULL)
            {
                uint32_t w = image_width(*imgs);
                uint32_t h = image_height(*imgs);
                pixbuf = image_native(*imgs);
                if (w > maxw)
                    maxw = w;
                if (h > maxh)
                    maxh = h;
            }

            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, pixbuf, 1, tc(*strs), -1);
        }

        if (maxw > 0)
            maxw += 5;

        *imgwidth = maxw;
        *imgheight = maxh;
        gtk_combo_box_set_model(combo, GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
