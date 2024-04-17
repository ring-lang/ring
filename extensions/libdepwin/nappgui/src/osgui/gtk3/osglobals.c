/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osglobals.c
 *
 */

/* GTK System globals */

#include "osglobals.h"
#include "osglobals_gtk.inl"
#include "oscontrol_gtk.inl"
#include <draw2d/color.h>
#include <draw2d/image.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/strings.h>
#include <core/stream.h>
#include <osbs/log.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

static const char_t *i_HIGH_TEXT = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
static bool_t i_IMPOSTOR_MAPPED = FALSE;
static GtkWidget *kWINDOW = NULL;
static GtkWidget *kLABEL = NULL;
static GtkWidget *kENTRY = NULL;
static GtkWidget *kBUTTON = NULL;
static GtkWidget *kCHECK[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
static GtkWidget *kSEPARATOR = NULL;
static GtkWidget *kLINKBUTTON = NULL;
static GtkWidget *kPROGRESSBAR = NULL;
static GtkWidget *kFRAME = NULL;
static GtkWidget *kTABLE = NULL;
static GtkWidget *kSCROLLED = NULL;
static GtkWidget *kHEADER = NULL;
static GtkWidget *kRESTORE_FOCUS_WINDOW = NULL;
static GtkWidget *kRESTORE_FOCUS_WIDGET = NULL;
static GdkPixbuf *kCHECKSBITMAP = NULL;
static uint32_t kCHECK_WIDTH = 0;
static uint32_t kCHECK_HEIGHT = 0;
static uint32_t kENTRY_HEIGHT = 0;
static uint32_t kPROGRESS_HEIGHT = 0;
static bool_t kDARK_MODE = FALSE;
static color_t kLABEL_COLOR = 0;
static color_t kVIEW_COLOR = 0;
static color_t kLINE_COLOR = 0;
static color_t kLINK_COLOR = 0;
static color_t kBORD_COLOR = 0;
static color_t kBORDFOCUS_COLOR = 0;
static color_t kTEXT_COLOR = 0;
static color_t kSELTX_COLOR = 0;
static color_t kHOTTX_COLOR = 0;
static color_t kTEXTBACKDROP_COLOR = 0;
static color_t kSELTXBACKDROP_COLOR = 0;
static color_t kHOTTXBACKDROP_COLOR = 0;
static String *kCSS_ENTRY = NULL;
static String *kCSS_BUTTON = NULL;
static String *kCSS_COMBOBOX = NULL;
static String *kCSS_FRAME = NULL;
static String *kCSS_TEXTVIEW = NULL;
static String *kCSS_TEXTVIEWTEXT = NULL;

/*---------------------------------------------------------------------------*/

/* Gets the exact margins and size of a widget drawing, based on the generated pixels
Keep 'max_width', 'max_height' as small as possible, depending of widget type */
static void i_widget_margins(GtkWidget *widget, const uint32_t max_width, const uint32_t max_height, uint32_t *x, uint32_t *y, uint32_t *width, uint32_t *height, uint32_t *color)
{
    register uint32_t i, j;
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, max_width, max_height);
    cairo_t *cairo = cairo_create(surface);
    GdkPixbuf *bitmap = NULL;
    uint32_t *buffer = NULL;
    uint32_t x0 = max_width, x1 = 0, y0 = max_height, y1 = 0;
    gtk_widget_draw(widget, cairo);
    bitmap = gdk_pixbuf_get_from_surface(surface, 0, 0, max_width, max_height);
    cassert(gdk_pixbuf_get_rowstride(bitmap) % 4 == 0);
    buffer = (uint32_t *)gdk_pixbuf_get_pixels(bitmap);
    *color = 0;

    for (i = 0; i < max_width; ++i)
        for (j = 0; j < max_height; ++j)
        {
            if (buffer[j * max_width + i] != 0)
            {
                if (i < x0)
                    x0 = i;
                if (i > x1)
                    x1 = i;
                if (j < y0)
                    y0 = j;
                if (j > y1)
                    y1 = j;
                if (*color == 0)
                    *color = buffer[j * max_width + i];
            }
        }

    cairo_surface_destroy(surface);
    cairo_destroy(cairo);
    g_object_unref(bitmap);

    *x = x0;
    *y = y0;
    *width = x1 - x0 + 1;
    *height = y1 - y0 + 1;
}

/*---------------------------------------------------------------------------*/
/*
Button states (5)
Normal
Prelight - Hot or mouse over
Backdrop - Background primary window
Insensitive - Disabled
*/
static void i_button_images(cairo_t *cairo, GtkWidget **button, gdouble offset)
{
    cairo_translate(cairo, offset, 0);
    gtk_widget_draw(button[0], cairo);

    cairo_translate(cairo, offset, 0);
    gtk_widget_draw(button[1], cairo);

    cairo_translate(cairo, offset, 0);
    gtk_widget_draw(button[2], cairo);

    cairo_translate(cairo, offset, 0);
    gtk_widget_draw(button[3], cairo);

    cairo_translate(cairo, offset, 0);
    gtk_widget_draw(button[4], cairo);
}

/*---------------------------------------------------------------------------*/

static color_t i_from_gdkcolor(const GdkRGBA *gdkcolor)
{
    return color_rgba(
        (uint8_t)(gdkcolor->red * 255.),
        (uint8_t)(gdkcolor->green * 255.),
        (uint8_t)(gdkcolor->blue * 255.),
        (uint8_t)(gdkcolor->alpha * 255.));
}

/*---------------------------------------------------------------------------*/

static color_t i_color_prop(GtkWidget *widget, const char_t *prop, GtkStateFlags flags)
{
    GValue value = G_VALUE_INIT;
    GdkRGBA *gdkcolor = NULL;
    color_t color = 0;
    GtkStyleContext *c = gtk_widget_get_style_context(widget);
    gtk_style_context_get_property(c, prop, flags, &value);
    gdkcolor = (GdkRGBA *)g_value_get_boxed(&value);
    color = i_from_gdkcolor(gdkcolor);
    g_value_unset(&value);
    return color;
}

/*---------------------------------------------------------------------------*/

/*
static color_t i_backcolor_prop(GtkWidget *widget, GtkStateFlags flags)
{
   GValue value = G_VALUE_INIT;
   GdkRGBA *gdkcolor = NULL;
   color_t color = 0;
   GtkStyleContext *c = gtk_widget_get_style_context(widget);
   gtk_style_context_get_property(c, "background-color", flags, &value);
   gdkcolor = (GdkRGBA*)g_value_get_boxed(&value);
   color = i_from_gdkcolor(gdkcolor);
   g_value_unset(&value);
   return color;
}
*/

/*---------------------------------------------------------------------------*/

/* Useful debug code to save GdkPixbuf to file  */
/* #include <draw2d/image.inl>
static gboolean i_encode(const gchar *data, gsize size, GError **error, gpointer stream)
{
   stm_write((Stream*)stream, (const byte_t*)data, (uint32_t)size);
   unref(error);
   return TRUE;
}

static void i_pixbuf_save(GdkPixbuf *pixbuf, const char *type, Stream *stm)
{
   gboolean ok = FALSE;
   ok = gdk_pixbuf_save_to_callback(pixbuf, i_encode, (gpointer)stm, type, NULL, NULL);
   cassert_unref(ok == TRUE, ok);
}
*/

/*---------------------------------------------------------------------------*/

/* Trying to consistently get the color of the frame (border, line),
reading the CSS properties, is a kind of impossible mission.
So we draw a frame and get the color. We start with the row in the middle,
to avoid roundness and transparencies in the corner. */
static color_t i_frame_color(GtkWidget *widget, const uint32_t size, const bool_t middle_i, const bool_t middle_j)
{
    register uint32_t i = 0, j = 0;
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, size, size);
    cairo_t *cairo = cairo_create(surface);
    GdkPixbuf *bitmap = NULL;
    uint32_t *buffer = NULL;
    color_t col = 0;
    gtk_widget_draw(widget, cairo);
    bitmap = gdk_pixbuf_get_from_surface(surface, 0, 0, size, size);
    cassert(gdk_pixbuf_get_rowstride(bitmap) % 4 == 0);
    buffer = (uint32_t *)gdk_pixbuf_get_pixels(bitmap);

    if (middle_i == TRUE)
        i = size / 2;
    if (middle_j == TRUE)
        j = size / 2;

    for (; i < size && col == 0; ++i)
        for (; j < size && col == 0; ++j)
        {
            if (buffer[j * size + i] != 0)
                col = buffer[j * size + i];
        }

    /*
    {
        Stream *stm = stm_to_file("/home/fran/Desktop/frame.png", NULL);
        i_pixbuf_save(bitmap, "png", stm);
        stm_close(&stm);
    }
    */

    cairo_surface_destroy(surface);
    cairo_destroy(cairo);
    g_object_unref(bitmap);

    return col;
}

/*---------------------------------------------------------------------------*/

static void i_precompute_colors(void)
{
    real32_t r = 0, g = 0, b = 0;
    cassert(kLABEL_COLOR == 0);
    cassert(i_IMPOSTOR_MAPPED == TRUE);
    kLABEL_COLOR = i_color_prop(kLABEL, "color", GTK_STATE_FLAG_ACTIVE);
    kVIEW_COLOR = i_color_prop(kWINDOW, "background-color", GTK_STATE_FLAG_NORMAL);
    kLINE_COLOR = i_frame_color(kFRAME, 20, FALSE, TRUE);
    kBORDFOCUS_COLOR = i_frame_color(kPROGRESSBAR, kPROGRESS_HEIGHT, TRUE, TRUE);
    kLINK_COLOR = i_color_prop(gtk_bin_get_child(GTK_BIN(kLINKBUTTON)), "color", GTK_STATE_FLAG_ACTIVE);
    kBORD_COLOR = kLINE_COLOR;
    kTEXT_COLOR = i_color_prop(kTABLE, "color", GTK_STATE_FLAG_NORMAL);
    kSELTX_COLOR = i_color_prop(kTABLE, "color", GTK_STATE_FLAG_SELECTED);
    kHOTTX_COLOR = i_color_prop(kTABLE, "color", GTK_STATE_FLAG_PRELIGHT);
    kTEXTBACKDROP_COLOR = i_color_prop(kTABLE, "color", GTK_STATE_FLAG_NORMAL | GTK_STATE_FLAG_BACKDROP);
    kSELTXBACKDROP_COLOR = i_color_prop(kTABLE, "color", GTK_STATE_FLAG_SELECTED | GTK_STATE_FLAG_BACKDROP);
    kHOTTXBACKDROP_COLOR = i_color_prop(kTABLE, "color", GTK_STATE_FLAG_PRELIGHT | GTK_STATE_FLAG_BACKDROP);
    r = (real32_t)((uint8_t)(kVIEW_COLOR) / 255.f);
    g = (real32_t)((uint8_t)(kVIEW_COLOR >> 8) / 255.f);
    b = (real32_t)((uint8_t)(kVIEW_COLOR >> 16) / 255.f);
    kDARK_MODE = (.21 * r + .72 * g + .07 * b) < .5 ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

static void i_precompute_checks(void)
{
    uint32_t mx, my, mwidth, mheight, border = 0;
    cairo_surface_t *surface = NULL;
    cairo_t *cairo = NULL;

    cassert(kCHECK_WIDTH == 0);
    cassert(kCHECK_HEIGHT == 0);
    cassert(kCHECKSBITMAP == NULL);
    cassert(i_IMPOSTOR_MAPPED == TRUE);
    i_widget_margins(kCHECK[0], 30, 30, &mx, &my, &mwidth, &mheight, &border);

    /* Image with checkbox and radio states for drawing in contexts */
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 10 * mwidth, mheight);
    cairo = cairo_create(surface);
    cairo_translate(cairo, -(gdouble)(mx + mwidth), -(gdouble)my);
    i_button_images(cairo, kCHECK, (gdouble)mwidth);
    i_button_images(cairo, kCHECK + 5, (gdouble)mwidth);
    kCHECK_WIDTH = mwidth;
    kCHECK_HEIGHT = mheight;
    kCHECKSBITMAP = gdk_pixbuf_get_from_surface(surface, 0, 0, 10 * mwidth, mheight);

    /*
    Stream *stm = stm_to_file("/home/fran/Desktop/check.png", NULL);
    i_pixbuf_save(kCHECKSBITMAP, "png", stm);
    stm_close(&stm);
    */

    cairo_surface_destroy(surface);
    cairo_destroy(cairo);
}

/*---------------------------------------------------------------------------*/

/*
static gboolean on_scrollbar_enter(GtkWidget *widget, GdkEventCrossing *event, gpointer user_data) {
    GtkRequisition minimum_size;
    GtkRequisition natural_size;
    //gtk_widget_set_state_flags(scroll, GTK_STATE_FLAG_PRELIGHT, FALSE);
    gtk_widget_get_preferred_size (widget, &minimum_size, &natural_size);

    g_print("Widget entró\n");
    return FALSE;
}

static GtkWidget *WIDGET = NULL;
static GdkEvent *EVENT  = NULL;

static gboolean i_select(void *obj)
{
    gdk_event_put(EVENT);

//    gtk_widget_event(WIDGET, EVENT);
    return FALSE;
}

static void simulate_enter_notify_event(GtkWidget *widget)
{
    GdkEvent *event;

    g_signal_connect(widget, "enter-notify-event", G_CALLBACK(on_scrollbar_enter), NULL);

    // Crear un evento de enter-notify
    event = gdk_event_new(GDK_ENTER_NOTIFY);

    // Configurar el evento para el widget específico
    event->crossing.window = gtk_widget_get_window(widget);
    event->crossing.send_event = TRUE;
    event->crossing.subwindow = NULL;
    event->crossing.time = GDK_CURRENT_TIME;
    WIDGET = widget;
    EVENT = event;

    // Simular el evento
    //gdk_event_put(event);
    g_idle_add((GSourceFunc)i_select, NULL);

    // on_idle
    // gtk_widget_event(widget, event);
    // Liberar la memoria del evento
    //g_free(event);
}
*/

/*---------------------------------------------------------------------------*/

static gboolean i_OnWindowDamage(GtkWidget *widget, GdkEventExpose *event, gpointer data)
{
    cassert(widget == kWINDOW);
    unref(event);
    unref(data);

    if (i_IMPOSTOR_MAPPED == TRUE)
        return FALSE;

    i_IMPOSTOR_MAPPED = TRUE;

    {
        real32_t width, height;
        cassert(kENTRY_HEIGHT == 0);
        cassert(kPROGRESS_HEIGHT == 0);
        _oscontrol_widget_size(kENTRY, &width, &height);
        kENTRY_HEIGHT = (uint32_t)height;
        _oscontrol_widget_size(kPROGRESSBAR, &width, &height);
        kPROGRESS_HEIGHT = (uint32_t)height;
        unref(width);
    }

    i_precompute_colors();
    i_precompute_checks();

    /*
        TODO: Scrollbars size
    {
        GtkWidget *scroll = gtk_scrolled_window_get_vscrollbar(kSCROLLED);
        simulate_enter_notify_event(scroll);

    }
    */

    cassert(kHEADER == NULL);

    {
        GtkTreeViewColumn *column = gtk_tree_view_get_column(GTK_TREE_VIEW(kTABLE), 0);
        kHEADER = gtk_tree_view_column_get_button(GTK_TREE_VIEW_COLUMN(column));
    }

    gtk_widget_hide(widget);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

/* We create a hidden 'fake' Window to get style information
We didn't find another 'effective' method to consult theme colors, padding, etc. */
static void i_impostor_window(void)
{
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *tview = gtk_text_view_new();
    GtkCellRenderer *renderer = NULL;
    GtkTreeViewColumn *column1 = NULL;
    GtkTreeViewColumn *column2 = NULL;
    GtkListStore *store = NULL;
    GtkTextBuffer *tbuffer = NULL;
    cassert(kWINDOW == NULL);
    kWINDOW = gtk_offscreen_window_new();
    /*kWINDOW = gtk_window_new(GTK_WINDOW_TOPLEVEL);*/
    kLABEL = gtk_label_new("__LABEL__");
    kENTRY = gtk_entry_new();
    kBUTTON = gtk_button_new();
    kSEPARATOR = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    kLINKBUTTON = gtk_link_button_new_with_label("", "__LINK__");
    kPROGRESSBAR = gtk_progress_bar_new();
    kFRAME = gtk_frame_new(NULL);
    kTABLE = gtk_tree_view_new();
    kSCROLLED = gtk_scrolled_window_new(NULL, NULL);
    tbuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tview));
    gtk_text_buffer_set_text(tbuffer, i_HIGH_TEXT, -1);
    gtk_container_add(GTK_CONTAINER(kSCROLLED), tview);
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(kPROGRESSBAR), 1.);
    gtk_container_add(GTK_CONTAINER(kFRAME), kTABLE);
    renderer = gtk_cell_renderer_text_new();
    column1 = gtk_tree_view_column_new_with_attributes("Column1", renderer, "text", 0, NULL);
    column2 = gtk_tree_view_column_new_with_attributes("Column2", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(kTABLE), column1);
    gtk_tree_view_append_column(GTK_TREE_VIEW(kTABLE), column2);
    gtk_tree_view_column_set_sizing(GTK_TREE_VIEW_COLUMN(column1), GTK_TREE_VIEW_COLUMN_FIXED);
    gtk_tree_view_column_set_fixed_width(GTK_TREE_VIEW_COLUMN(column1), 100);
    gtk_tree_view_column_set_sizing(GTK_TREE_VIEW_COLUMN(column2), GTK_TREE_VIEW_COLUMN_FIXED);
    gtk_tree_view_column_set_fixed_width(GTK_TREE_VIEW_COLUMN(column2), 100);
    gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(kTABLE), TRUE);
    gtk_widget_set_size_request(kTABLE, (gint)200, (gint)100);
    store = gtk_list_store_new(1, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(kTABLE), GTK_TREE_MODEL(store));
    g_object_unref(store);
    kCHECK[0] = gtk_check_button_new();
    kCHECK[1] = gtk_check_button_new();
    kCHECK[2] = gtk_check_button_new();
    kCHECK[3] = gtk_check_button_new();
    kCHECK[4] = gtk_check_button_new();
    kCHECK[5] = gtk_check_button_new();
    kCHECK[6] = gtk_check_button_new();
    kCHECK[7] = gtk_check_button_new();
    kCHECK[8] = gtk_check_button_new();
    kCHECK[9] = gtk_check_button_new();
    gtk_container_add(GTK_CONTAINER(kWINDOW), vbox);
    gtk_box_pack_start(GTK_BOX(hbox1), kCHECK[0], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox1), kCHECK[1], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox1), kCHECK[2], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox1), kCHECK[3], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox1), kCHECK[4], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), kCHECK[5], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), kCHECK[6], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), kCHECK[7], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), kCHECK[8], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), kCHECK[9], FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), kBUTTON, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), kLABEL, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), kENTRY, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), kSEPARATOR, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), kLINKBUTTON, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), kPROGRESSBAR, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), kFRAME, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), kSCROLLED, TRUE, TRUE, 0);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[0]), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[1]), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[2]), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[3]), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[4]), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[5]), TRUE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[6]), TRUE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[7]), TRUE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[8]), TRUE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(kCHECK[9]), TRUE);
    gtk_widget_set_state_flags(kCHECK[0], (GtkStateFlags)GTK_STATE_FLAG_NORMAL, FALSE);
    gtk_widget_set_state_flags(kCHECK[1], (GtkStateFlags)GTK_STATE_PRELIGHT, FALSE);
    gtk_widget_set_state_flags(kCHECK[2], (GtkStateFlags)GTK_STATE_SELECTED, FALSE);
    gtk_widget_set_state_flags(kCHECK[3], (GtkStateFlags)(GTK_STATE_FLAG_BACKDROP | GTK_STATE_PRELIGHT), FALSE);
    gtk_widget_set_sensitive(kCHECK[4], FALSE);
    gtk_widget_set_state_flags(kCHECK[5], (GtkStateFlags)GTK_STATE_FLAG_NORMAL, FALSE);
    gtk_widget_set_state_flags(kCHECK[6], (GtkStateFlags)GTK_STATE_PRELIGHT, FALSE);
    gtk_widget_set_state_flags(kCHECK[7], (GtkStateFlags)GTK_STATE_SELECTED, FALSE);
    gtk_widget_set_state_flags(kCHECK[8], (GtkStateFlags)(GTK_STATE_FLAG_BACKDROP | GTK_STATE_PRELIGHT), FALSE);
    gtk_widget_set_sensitive(kCHECK[9], FALSE);
    g_signal_connect(kWINDOW, "damage-event", G_CALLBACK(i_OnWindowDamage), NULL);
    gtk_widget_show_all(kWINDOW);

    /*
    Before i_OnWindowDamage some warnings
    Ubuntu 20.04 GTK 3.24.20
    Gdk-WARNING **: 20:44:39.639: ../../../../../gdk/x11/gdkwindow-x11.c:5633 drawable is not a native X11 window
    */
}

/*---------------------------------------------------------------------------*/

device_t osglobals_device(const void *non_used)
{
    cassert(FALSE);
    cassert_unref(non_used == NULL, non_used);
    return ekDESKTOP;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_color(const syscolor_t *color)
{
    cassert_no_null(color);
    cassert(kWINDOW != NULL);

    switch (*color)
    {
    case ekSYSCOLOR_DARKMODE:
        return kDARK_MODE;

    case ekSYSCOLOR_LABEL:
        cassert(kLABEL_COLOR != 0);
        return kLABEL_COLOR;

    case ekSYSCOLOR_VIEW:
        cassert(kVIEW_COLOR != 0);
        return kVIEW_COLOR;

    case ekSYSCOLOR_LINE:
        cassert(kLINE_COLOR != 0);
        return kLINE_COLOR;

    case ekSYSCOLOR_LINK:
        cassert(kLINK_COLOR != 0);
        return kLINK_COLOR;

    case ekSYSCOLOR_BORDER:
        cassert(kBORD_COLOR != 0);
        return kBORD_COLOR;

        cassert_default();
    }

    return 0;
}

/*---------------------------------------------------------------------------*/

void osglobals_resolution(const void *non_used, real32_t *width, real32_t *height)
{
    unref(non_used);
    cassert_no_null(width);
    cassert_no_null(height);
#if GTK_CHECK_VERSION(3, 22, 0)
    {
        GdkDisplay *display = gdk_display_get_default();
        GdkMonitor *primary_monitor = gdk_display_get_primary_monitor(display);
        GdkRectangle monitor_geometry;
        gdk_monitor_get_geometry(primary_monitor, &monitor_geometry);
        *width = (real32_t)monitor_geometry.width;
        *height = (real32_t)monitor_geometry.height;
    }
#else
    *width = (real32_t)gdk_screen_width();
    *height = (real32_t)gdk_screen_height();
#endif
}

/*---------------------------------------------------------------------------*/

void osglobals_mouse_position(const void *non_used, real32_t *x, real32_t *y)
{
    /* https://stackoverflow.com/questions/55213291/query-cursor-position-with-gtk */
    gint ix, iy;
    GdkDisplay *display = gdk_display_get_default();
    GdkWindow *window = NULL;
    GdkDevice *mouse_device = NULL;
    cassert_no_null(x);
    cassert_no_null(y);
    unref(non_used);
#if GTK_CHECK_VERSION(3, 20, 0)
    {
        GdkSeat *seat = gdk_display_get_default_seat(display);
        mouse_device = gdk_seat_get_pointer(seat);
    }
#else
    {
        GdkDeviceManager *devman = gdk_display_get_device_manager(display);
        mouse_device = gdk_device_manager_get_client_pointer(devman);
    }
#endif

    window = gdk_display_get_default_group(display);
    gdk_window_get_device_position(window, mouse_device, &ix, &iy, NULL);
    *x = (real32_t)ix;
    *y = (real32_t)iy;
}

/*---------------------------------------------------------------------------*/

Cursor *osglobals_cursor(const gui_cursor_t cursor, const Image *image, const real32_t hot_x, const real32_t hot_y)
{
    GdkDisplay *display = gdk_display_get_default();
    GdkCursor *gdkcursor = NULL;
    switch (cursor)
    {
    case ekGUI_CURSOR_ARROW:
        gdkcursor = gdk_cursor_new_for_display(display, GDK_ARROW);
        break;

    case ekGUI_CURSOR_HAND:
        gdkcursor = gdk_cursor_new_for_display(display, GDK_HAND2);
        break;

    case ekGUI_CURSOR_IBEAM:
        gdkcursor = gdk_cursor_new_for_display(display, GDK_XTERM);
        break;

    case ekGUI_CURSOR_CROSS:
        gdkcursor = gdk_cursor_new_for_display(display, GDK_FLEUR);
        break;

    case ekGUI_CURSOR_SIZEWE:
        gdkcursor = gdk_cursor_new_for_display(display, GDK_SB_H_DOUBLE_ARROW);
        break;

    case ekGUI_CURSOR_SIZENS:
        gdkcursor = gdk_cursor_new_for_display(display, GDK_SB_V_DOUBLE_ARROW);
        break;

    case ekGUI_CURSOR_USER:
    {
        const GdkPixbuf *pixbuf = image_native(image);
        gdkcursor = gdk_cursor_new_from_pixbuf(display, (GdkPixbuf *)pixbuf, (gint)hot_x, (gint)hot_y);
        break;
    }

        cassert_default();
    }

    heap_auditor_add("GdkCursor");
    return (Cursor *)gdkcursor;
}

/*---------------------------------------------------------------------------*/

void osglobals_cursor_destroy(Cursor **cursor)
{
    cassert_no_null(cursor);
    cassert_no_null(*cursor);
    g_object_unref((GdkCursor *)*cursor);
    heap_auditor_delete("GdkCursor");
    *cursor = NULL;
}

/*---------------------------------------------------------------------------*/

void osglobals_value(const uint32_t index, void *value)
{
    cassert_no_null(value);
    switch (index)
    {
    case 0:
        (*(uint32_t *)value) = 0;
        break;

    case 1:
        (*(uint32_t *)value) = 0;
        break;

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void osglobals_transitions(void *nonused, const real64_t prtime, const real64_t crtime)
{
    unref(nonused);
    unref(prtime);
    unref(crtime);
    if (kRESTORE_FOCUS_WIDGET != NULL)
    {
        /*
        TODO: Review when Button reject focus
        gtk_window_set_focus(GTK_WINDOW(kRESTORE_FOCUS_WINDOW), kRESTORE_FOCUS_WIDGET);
        kRESTORE_FOCUS_WIDGET = NULL;
        kRESTORE_FOCUS_WINDOW = NULL;
        */
    }
}

/*---------------------------------------------------------------------------*/

static gboolean i_OnIdle(Listener *listener)
{
    listener_event(listener, ekGUI_EVENT_IDLE, NULL, NULL, NULL, void, void, void);
    listener_destroy(&listener);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

void osglobals_OnIdle(void *nonused, Listener *listener)
{
    unref(nonused);
    g_idle_add((GSourceFunc)i_OnIdle, listener);
}

/*---------------------------------------------------------------------------*/

static void i_null_log(const gchar *log_domain, GLogLevelFlags log_levels, const gchar *message, gpointer user_data)
{
    unref(log_domain);
    unref(log_levels);
    unref(message);
    unref(user_data);
}

/*---------------------------------------------------------------------------*/

#define IS_BLANK(c) (bool_t)((c) == ' ' || (c) == '\n' || (c) == '\t' || (c) == '\v' || (c) == '\f' || (c) == '\r')

static const char *i_get_next_section(const char *css_data, char **pcss, int *n)
{
    while (*(*pcss) != '{' && *(*pcss) != 0)
        (*pcss)++;

    /* Beginning of main section */
    if (*(*pcss) == '{')
    {
        char *st = *pcss;
        char *ed = *pcss;
        while (st > css_data)
        {
            st--;
            /* The end of previous block */
            if (*st == ';' || *st == '}')
            {
                st++;
                break;
            }
        }

        while (IS_BLANK(*st))
            st++;

        if (ed > st)
            ed--;

        while (IS_BLANK(*ed))
            ed--;

        if (ed > st || *st != '{')
            *n = ed - st + 1;
        else
            *n = 0;

        return st;
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

static void i_jump_next_section(char **pcss)
{
    uint32_t i = 0;
    cassert(*(*pcss) == '{');
    for (;;)
    {
        /* Malformed CSS */
        if (*(*pcss) == 0)
            return;

        if (*(*pcss) == '{')
        {
            i++;
        }
        else if (*(*pcss) == '}')
        {
            cassert(i > 0);
            i--;
            if (i == 0)
            {
                (*pcss)++;
                return;
            }
        }

        (*pcss)++;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_section(const char_t *sect, const char_t *str, uint32_t *n)
{
    const char_t *st = sect;
    cassert_no_null(sect);
    cassert_no_null(str);
    cassert_no_null(n);

    if (*sect == 0)
        return FALSE;

    /* Allowed start characters */
    if (*sect == '.')
        sect++;

    /* Section name must fit required name */
    for (; *str != 0; ++str, ++sect)
    {
        if (*sect == 0)
            return FALSE;

        if (unicode_tolower((uint32_t)*sect) != unicode_tolower((uint32_t)*str))
            return FALSE;
    }

    /* Valid final characters in section */
    if (*sect == 0 || *sect == '.' || *sect == ':' || *sect == ' ')
    {
        *n = (uint32_t)(sect - st);
        return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

/*
   GTK3 changes, depending on the version, the css keys of the widgets
   ('entry', '.entry', ...). We are looking for the keys in this particular version,
   to be able to alter the appearance of the widgets.
*/
static void i_parse_gtk_theme(void)
{
    GtkSettings *settings = NULL;
    gchar *theme_name = NULL;
    GtkCssProvider *prov = NULL;
    char *css_data = NULL;
    char *pcss = NULL;
    const char *section = NULL;
    int nsection = 0;

    settings = gtk_settings_get_default();
    g_object_get(settings, "gtk-theme-name", &theme_name, NULL);

    /* a GtkCssProvider with the theme loaded. This memory is owned by GTK+, and you must not free it. */
    prov = gtk_css_provider_get_named(theme_name, NULL);

    if (prov != NULL)
        css_data = gtk_css_provider_to_string(prov);
    else
        css_data = (char *)"";

    pcss = css_data;

    /*
     * Save a copy of theme.css
    {
        #include <core/hfile.h>
        String *str = str_c(css_data);
        hfile_from_string("/home/fran/Desktop/app_css_export.css", str, NULL);
        str_destroy(&str);
    }
    */

    for (;;)
    {
        char_t csect[256];
        section = i_get_next_section(css_data, &pcss, &nsection);

        if (section != NULL)
        {
            uint32_t sect_n = 0;
            str_copy_cn(csect, sizeof(csect), section, nsection);
            csect[nsection] = '\0';

            if (kCSS_ENTRY == NULL)
            {
                if (i_section(csect, "entry", &sect_n) == TRUE)
                {
                    kCSS_ENTRY = str_cn(csect, sect_n);
                }
            }

            if (kCSS_BUTTON == NULL)
            {
                if (i_section(csect, "button", &sect_n) == TRUE)
                    kCSS_BUTTON = str_cn(csect, sect_n);
            }

            if (kCSS_COMBOBOX == NULL)
            {
                if (i_section(csect, "combobox", &sect_n) == TRUE)
                    kCSS_COMBOBOX = str_cn(csect, sect_n);
                else if (i_section(csect, "GtkComboBox", &sect_n) == TRUE)
                    kCSS_COMBOBOX = str_cn(csect, sect_n);
            }

            if (kCSS_FRAME == NULL)
            {
                if (i_section(csect, "frame", &sect_n) == TRUE)
                    kCSS_FRAME = str_cn(csect, sect_n);
            }

            if (kCSS_TEXTVIEW == NULL)
            {
                if (i_section(csect, "textview", &sect_n) == TRUE)
                    kCSS_TEXTVIEW = str_cn(csect, sect_n);
                else if (i_section(csect, "GtkTextView", &sect_n) == TRUE)
                    kCSS_TEXTVIEW = str_cn(csect, sect_n);
            }

            if (kCSS_TEXTVIEWTEXT == NULL)
            {
                if (i_section(csect, "textview text", &sect_n) == TRUE)
                    kCSS_TEXTVIEWTEXT = str_cn(csect, sect_n);
            }

            if (kCSS_ENTRY == NULL || kCSS_BUTTON == NULL || kCSS_COMBOBOX == NULL || kCSS_FRAME == NULL || kCSS_TEXTVIEW == NULL || kCSS_TEXTVIEWTEXT == NULL)
                i_jump_next_section(&pcss);
            else
                break;
        }
        else
        {
            break;
        }
    }

    if (kCSS_TEXTVIEW == NULL)
    {
        if (kCSS_TEXTVIEWTEXT != NULL)
        {
            const char_t *t = tc(kCSS_TEXTVIEWTEXT);
            while (*t != 0)
            {
                if (*t == ' ')
                {
                    kCSS_TEXTVIEW = str_cn(tc(kCSS_TEXTVIEWTEXT), (uint32_t)(t - tc(kCSS_TEXTVIEWTEXT)));
                    break;
                }

                t++;
            }
        }
    }

    if (kCSS_TEXTVIEW == NULL)
    {
#if GTK_CHECK_VERSION(3, 22, 0)
        kCSS_TEXTVIEW = str_c("textview");
#else
        kCSS_TEXTVIEW = str_c("GtkTextView");
#endif
    }

    if (kCSS_TEXTVIEWTEXT == NULL && kCSS_TEXTVIEW != NULL)
        kCSS_TEXTVIEWTEXT = str_copy(kCSS_TEXTVIEW);

    if (kCSS_ENTRY == NULL)
        log_printf("No kCSS_ENTRY found in css theme");

    if (kCSS_BUTTON == NULL)
        log_printf("No kCSS_BUTTON found in css theme");

    if (kCSS_COMBOBOX == NULL)
        log_printf("No kCSS_COMBOBOX found in css theme");

    if (kCSS_FRAME == NULL)
        log_printf("No kCSS_FRAME found in css theme");

    g_free(theme_name);
    g_free(css_data);
    g_object_unref(settings);
}

/*---------------------------------------------------------------------------*/

void osglobals_init(void)
{
    /* Disable unavoidable GLib warnings when processing CSS */
    g_log_set_handler("GLib", (GLogLevelFlags)0xFFFF, i_null_log, NULL);
    i_parse_gtk_theme();
    i_impostor_window();
}

/*---------------------------------------------------------------------------*/

void osglobals_finish(void)
{
    if (kWINDOW != NULL)
    {
        /* A floating object was finalized. This means that someone
        called g_object_unref() on an object that had only a floating
        reference; the initial floating reference is not owned by anyone
        and must be removed with g_object_ref_sink(). */
        g_object_ref_sink(kWINDOW);
        g_object_unref(kWINDOW);
        kWINDOW = NULL;
        kLABEL = NULL;
        kENTRY = NULL;
        kBUTTON = NULL;
        kSEPARATOR = NULL;
        kLINKBUTTON = NULL;
        kTABLE = NULL;
        kHEADER = NULL;
    }

    if (kCHECKSBITMAP != NULL)
        g_object_unref(kCHECKSBITMAP);

    str_destopt(&kCSS_ENTRY);
    str_destopt(&kCSS_BUTTON);
    str_destopt(&kCSS_COMBOBOX);
    str_destopt(&kCSS_FRAME);
    str_destopt(&kCSS_TEXTVIEW);
    str_destopt(&kCSS_TEXTVIEWTEXT);
}

/*---------------------------------------------------------------------------*/

static __INLINE GtkWidget *i_entry(void)
{
    cassert(kENTRY != NULL);
    return kENTRY;
}

/*---------------------------------------------------------------------------*/

void osglobals_register_entry(GtkBorder *padding)
{
    if (padding != NULL)
    {
        GtkWidget *entry = i_entry();
        GtkStyleContext *c = gtk_widget_get_style_context(entry);
        gtk_style_context_get_padding(c, GTK_STATE_FLAG_NORMAL, padding);

        if (padding->top == 0 || padding->bottom == 0)
        {
            GtkRequisition s;
            uint32_t fsize;
            gtk_widget_get_preferred_size(entry, &s, NULL);
            fsize = _oscontrol_widget_font_size(entry);
            padding->top = (s.height - fsize - 2) / 2;
            padding->bottom = padding->top;
        }
    }
}

/*---------------------------------------------------------------------------*/

bool_t osglobals_impostor_mapped(void)
{
    return i_IMPOSTOR_MAPPED;
}

/*---------------------------------------------------------------------------*/

GtkStyleContext *osglobals_entry_context(void)
{
    cassert(kENTRY != NULL);
    return gtk_widget_get_style_context(kENTRY);
}

/*---------------------------------------------------------------------------*/

GtkStyleContext *osglobals_button_context(void)
{
    cassert(kBUTTON != NULL);
    return gtk_widget_get_style_context(kBUTTON);
}

/*---------------------------------------------------------------------------*/

GtkStyleContext *osglobals_table_context(void)
{
    cassert(kTABLE != NULL);
    return gtk_widget_get_style_context(kTABLE);
}

/*---------------------------------------------------------------------------*/

const char_t *osglobals_css_entry(void)
{
    cassert(str_empty(kCSS_ENTRY) == FALSE);
    return tc(kCSS_ENTRY);
}

/*---------------------------------------------------------------------------*/

const char_t *osglobals_css_button(void)
{
    cassert(str_empty(kCSS_BUTTON) == FALSE);
    return tc(kCSS_BUTTON);
}

/*---------------------------------------------------------------------------*/

const char_t *osglobals_css_combobox(void)
{
    cassert(str_empty(kCSS_COMBOBOX) == FALSE);
    return tc(kCSS_COMBOBOX);
}

/*---------------------------------------------------------------------------*/

const char_t *osglobals_css_textview(void)
{
    return tc(kCSS_TEXTVIEW);
}

/*---------------------------------------------------------------------------*/

const char_t *osglobals_css_textview_text(void)
{
    return tc(kCSS_TEXTVIEWTEXT);
}

/*---------------------------------------------------------------------------*/

color_t osglobals_text_color(void)
{
    cassert(kTEXT_COLOR != 0);
    return kTEXT_COLOR;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_seltext_color(void)
{
    cassert(kSELTX_COLOR != 0);
    return kSELTX_COLOR;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_hottext_color(void)
{
    cassert(kHOTTX_COLOR != 0);
    return kHOTTX_COLOR;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_textbackdrop_color(void)
{
    cassert(kTEXTBACKDROP_COLOR != 0);
    return kTEXTBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_seltextbackdrop_color(void)
{
    cassert(kSELTXBACKDROP_COLOR != 0);
    return kSELTXBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_hottextbackdrop_color(void)
{
    cassert(kHOTTXBACKDROP_COLOR != 0);
    return kHOTTXBACKDROP_COLOR;
}

/*---------------------------------------------------------------------------*/

color_t osglobals_border_color(void)
{
    return kLINE_COLOR;
}

/*---------------------------------------------------------------------------*/

uint32_t osglobals_check_width(void)
{
    cassert(kCHECK_WIDTH != 0);
    return kCHECK_WIDTH;
}

/*---------------------------------------------------------------------------*/

uint32_t osglobals_check_height(void)
{
    cassert(kCHECK_HEIGHT != 0);
    return kCHECK_HEIGHT;
}

/*---------------------------------------------------------------------------*/

uint32_t osglobals_entry_height(void)
{
    cassert(kENTRY_HEIGHT != 0);
    return kENTRY_HEIGHT;
}

/*---------------------------------------------------------------------------*/

uint32_t osglobals_progress_height(void)
{
    cassert(kPROGRESS_HEIGHT != 0);
    return kPROGRESS_HEIGHT;
}

/*---------------------------------------------------------------------------*/

GdkPixbuf *osglobals_checks_bitmap(void)
{
    cassert(kCHECKSBITMAP != NULL);
    return kCHECKSBITMAP;
}

/*---------------------------------------------------------------------------*/

static void i_write_rgb(Stream *stm, const char_t *prop, const color_t color)
{
    uint8_t r, g, b;
    color_get_rgb(color, &r, &g, &b);
    stm_printf(stm, "%s: rgb(%d, %d, %d);", prop, r, g, b);
}

/*---------------------------------------------------------------------------*/

String *osglobals_frame_focus_css(void)
{
    Stream *stm = stm_memory(1024);
    String *str = NULL;
    stm_printf(stm, "%s > border {", tc(kCSS_FRAME));
    i_write_rgb(stm, "border-left-color", kBORDFOCUS_COLOR);
    i_write_rgb(stm, "border-right-color", kBORDFOCUS_COLOR);
    i_write_rgb(stm, "border-top-color", kBORDFOCUS_COLOR);
    i_write_rgb(stm, "border-bottom-color", kBORDFOCUS_COLOR);
    stm_printf(stm, "} %s {", tc(kCSS_FRAME));
    i_write_rgb(stm, "border-left-color", kBORDFOCUS_COLOR);
    i_write_rgb(stm, "border-right-color", kBORDFOCUS_COLOR);
    i_write_rgb(stm, "border-top-color", kBORDFOCUS_COLOR);
    i_write_rgb(stm, "border-bottom-color", kBORDFOCUS_COLOR);
    stm_printf(stm, "}");
    str = stm_str(stm);
    stm_close(&stm);
    return str;
}

/*---------------------------------------------------------------------------*/

void osglobals_restore_focus(GtkWidget *window, GtkWidget *widget)
{
    kRESTORE_FOCUS_WINDOW = window;
    kRESTORE_FOCUS_WIDGET = widget;
}
