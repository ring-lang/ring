/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: gui.c
 *
 */

/* Graphics User Interface */

#include "gui.h"
#include "gui.inl"
#include "gbind.inl"
#include "menu.inl"
#include "window.inl"
#include "button.h"
#include "imageview.h"
#include "label.h"
#include "layout.h"
#include "panel.h"
#include "window.h"
#include "res_gui.h"
#include <draw2d/color.h>
#include <draw2d/draw2d.h>
#include <draw2d/guictx.h>
#include <draw2d/font.h>
#include <draw2d/image.h>
#include <geom2d/v2d.h>
#include <core/arrpt.h>
#include <core/arrst.h>
#include <core/event.h>
#include <core/heap.h>
#include <core/hfile.h>
#include <core/hfileh.h>
#include <core/respack.h>
#include <core/respackh.h>
#include <core/strings.h>
#include <osbs/bproc.h>
#include <osbs/bfile.h>
#include <osbs/log.h>
#include <sewer/blib.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

typedef struct _transtion_t Transition;
typedef struct _curicon_t CurIcon;
typedef struct _coloralt_t ColorAlt;

typedef enum _icon_t
{
    ekICON_ASSERT,
    ekICON_CRASH,
    ekICON_SYSTEM
} icon_t;

struct _transtion_t
{
    Listener *listener;
    void *owner;
};

struct _curicon_t
{
    gui_cursor_t type;
    const Image *image;
    const Cursor *cursor;
};

struct _coloralt_t
{
    color_t light;
    color_t dark;
};

DeclSt(Transition);
DeclSt(CurIcon);
DeclSt(ColorAlt);
DeclPt(Window);
DeclPt(Menu);

/*---------------------------------------------------------------------------*/

static uint32_t i_NUM_USERS = 0;
static Font *i_DEFAULT_FONT = NULL;
static String *i_CURRENT_LANG = NULL;
static ArrSt(ColorAlt) *i_ALTCOLORS = NULL;
static ArrSt(Transition) *i_TRANSITIONS = NULL;
static ArrSt(CurIcon) *i_CURSORS = NULL;
static ArrPt(ResPack) *i_PACKS = NULL;
static ArrSt(FPtr_respack) *i_FUNC_PACKS = NULL;
static ArrPt(Window) *i_WINDOWS = NULL;
static ArrPt(Menu) *i_MENUS = NULL;
static String *i_APP_NAME = NULL;
static Window *i_ASSERT_WINDOW = NULL;
static Window *i_INFO_WINDOW = NULL;
static bool_t i_SHOW_ASSERT_WINDOW = FALSE;
static bool_t i_WRITE_ASSERT_LOG = FALSE;
static bool_t i_IN_ASSERT = FALSE;
static bool_t i_DARK_MODE = FALSE;
static Listener *i_ONTHEME = NULL;
static Listener *i_ONNOTIF = NULL;
static FPtr_destroy i_FUNC_DESTROY_CURSOR = NULL;
#define kFIRST_COLOR_ALT 16

/*---------------------------------------------------------------------------*/

static void i_assert_handler(void *, const uint32_t, const char_t *, const char_t *, const char_t *, const uint32_t);

/*---------------------------------------------------------------------------*/

static void i_remove_transition(Transition *transition)
{
    cassert_no_null(transition);
    listener_destroy(&transition->listener);
}

/*---------------------------------------------------------------------------*/

static void i_remove_curicon(CurIcon *cursor)
{
    cassert_no_null(cursor);
    i_FUNC_DESTROY_CURSOR((void **)&cursor->cursor);
}

/*---------------------------------------------------------------------------*/

static void i_logfile(void)
{
    String *logfile = hfile_appdata("log.txt");
    log_file(tc(logfile));
    log_printf("Starting log for '%s'", tc(i_APP_NAME));
    str_destroy(&logfile);
}

/*---------------------------------------------------------------------------*/

static void i_gui_atexit(void)
{
    if (i_NUM_USERS != 0)
        log_printf("Error! gui is not properly closed (%d)\n", i_NUM_USERS);
}

/*---------------------------------------------------------------------------*/

void gui_start(void)
{
    if (i_NUM_USERS == 0)
    {
        draw2d_start();
        i_DEFAULT_FONT = NULL;
        i_CURRENT_LANG = str_c("");
        i_ALTCOLORS = arrst_create(ColorAlt);
        i_TRANSITIONS = arrst_create(Transition);
        i_CURSORS = arrst_create(CurIcon);
        i_PACKS = arrpt_create(ResPack);
        i_FUNC_PACKS = arrst_create(FPtr_respack);
        i_WINDOWS = arrpt_create(Window);
        i_MENUS = arrpt_create(Menu);
        i_SHOW_ASSERT_WINDOW = TRUE;
        i_WRITE_ASSERT_LOG = TRUE;
        i_IN_ASSERT = FALSE;
        i_ASSERT_WINDOW = NULL;
        i_APP_NAME = hfile_exename();
        i_ONTHEME = NULL;
        i_ONNOTIF = NULL;
        i_FUNC_DESTROY_CURSOR = NULL;
        cassert_set_func(NULL, i_assert_handler);
        blib_atexit(i_gui_atexit);
        i_logfile();
    }

    i_NUM_USERS += 1;
}

/*---------------------------------------------------------------------------*/

void gui_finish(void)
{
    cassert(i_NUM_USERS > 0);
    if (i_NUM_USERS == 1)
    {
        ptr_destopt(window_destroy, &i_ASSERT_WINDOW, Window);
        ptr_destopt(font_destroy, &i_DEFAULT_FONT, Font);
        str_destroy(&i_APP_NAME);
        str_destroy(&i_CURRENT_LANG);
        cassert(arrst_size(i_TRANSITIONS, Transition) == 0);
        arrst_destroy(&i_ALTCOLORS, NULL, ColorAlt);
        arrst_destroy(&i_TRANSITIONS, NULL, Transition);
        arrst_destroy(&i_CURSORS, i_remove_curicon, CurIcon);
        arrpt_destroy(&i_PACKS, respack_destroy, ResPack);
        arrst_destroy(&i_FUNC_PACKS, NULL, FPtr_respack);
        arrpt_destroy(&i_WINDOWS, NULL, Window);
        arrpt_destroy(&i_MENUS, NULL, Menu);
        listener_destroy(&i_ONTHEME);
        listener_destroy(&i_ONNOTIF);
        draw2d_finish();
    }

    i_NUM_USERS -= 1;
}

/*---------------------------------------------------------------------------*/

void gui_respack(FPtr_respack func_respack)
{
    cassert_no_nullf(func_respack);
    arrst_append(i_FUNC_PACKS, func_respack, FPtr_respack);
}

/*---------------------------------------------------------------------------*/

void gui_language(const char_t *lang)
{
    str_upd(&i_CURRENT_LANG, lang);

    arrpt_clear(i_PACKS, respack_destroy, ResPack);
    arrst_foreach(func_pack, i_FUNC_PACKS, FPtr_respack)
        ResPack *pack = (*func_pack)(lang);
        arrpt_append(i_PACKS, pack, ResPack);
    arrpt_end()

    arrpt_foreach(menu, i_MENUS, Menu)
        _menu_locale(menu);
    arrpt_end()

    arrpt_foreach(window, i_WINDOWS, Window)
        _window_locale(window);
    arrpt_end()

    if (i_ONNOTIF != NULL)
        listener_event(i_ONNOTIF, ekGUI_NOTIF_LANGUAGE, NULL, lang, NULL, void, char_t, void);
}

/*---------------------------------------------------------------------------*/

const char_t *gui_text(const ResId id)
{
    bool_t is_resid;
    const char_t *text = respack_atext(i_PACKS, id, &is_resid);
    cassert_unref(is_resid == TRUE, is_resid);
    return text;
}

/*---------------------------------------------------------------------------*/

const Image *gui_image(const ResId id)
{
    bool_t is_resid;
    Image *image = respack_aobj(i_PACKS, id, image_from_data, image_destroy, &is_resid, Image);
    cassert_unref(is_resid == TRUE, is_resid);
    return image;
}

/*---------------------------------------------------------------------------*/

const byte_t *gui_file(const ResId id, uint32_t *size)
{
    bool_t is_resid;
    const byte_t *data = respack_afile(i_PACKS, id, size, &is_resid);
    cassert_unref(is_resid == TRUE, is_resid);
    return data;
}

/*---------------------------------------------------------------------------*/

bool_t gui_dark_mode(void)
{
    return i_DARK_MODE;
}

/*---------------------------------------------------------------------------*/

color_t gui_alt_color(const color_t light_color, const color_t dark_color)
{
    uint32_t n = arrst_size(i_ALTCOLORS, ColorAlt);
    ColorAlt *alt = arrst_new(i_ALTCOLORS, ColorAlt);
    alt->light = light_color;
    alt->dark = dark_color;
    cassert(kFIRST_COLOR_ALT + n <= 0xFFFF);
    color_indexed((uint16_t)(kFIRST_COLOR_ALT + n), i_DARK_MODE ? alt->dark : alt->light);
    return (color_t)(kFIRST_COLOR_ALT + n);
}

/*---------------------------------------------------------------------------*/

color_t gui_label_color(void)
{
    return (color_t)ekSYSCOLOR_LABEL;
}

/*---------------------------------------------------------------------------*/

color_t gui_view_color(void)
{
    return (color_t)ekSYSCOLOR_VIEW;
}

/*---------------------------------------------------------------------------*/

color_t gui_line_color(void)
{
    return (color_t)ekSYSCOLOR_LINE;
}

/*---------------------------------------------------------------------------*/

color_t gui_link_color(void)
{
    return (color_t)ekSYSCOLOR_LINK;
}

/*---------------------------------------------------------------------------*/

color_t gui_border_color(void)
{
    return (color_t)ekSYSCOLOR_BORDER;
}

/*---------------------------------------------------------------------------*/

S2Df gui_resolution(void)
{
    S2Df res = {0, 0};
    const GuiCtx *context = guictx_get_current();
    cassert_no_null(context);
    cassert_no_nullf(context->func_globals_resolution);
    context->func_globals_resolution(NULL, &res.width, &res.height);
    return res;
}

/*---------------------------------------------------------------------------*/

V2Df gui_mouse_pos(void)
{
    V2Df pos = {0, 0};
    const GuiCtx *context = guictx_get_current();
    cassert_no_null(context);
    cassert_no_nullf(context->func_globals_mouse_position);
    context->func_globals_mouse_position(NULL, &pos.x, &pos.y);
    return pos;
}

/*---------------------------------------------------------------------------*/

static void i_precompute_system_colors(void)
{
    syscolor_t scol = ekSYSCOLOR_DARKMODE;
    const GuiCtx *context = guictx_get_current();

    cassert_no_null(context);
    cassert_no_nullf(context->func_globals_color);

    i_DARK_MODE = (bool_t)context->func_globals_color(&scol);

    scol = ekSYSCOLOR_LABEL;
    color_indexed((uint16_t)scol, context->func_globals_color(&scol));

    scol = ekSYSCOLOR_VIEW;
    color_indexed((uint16_t)scol, context->func_globals_color(&scol));

    scol = ekSYSCOLOR_LINE;
    color_indexed((uint16_t)scol, context->func_globals_color(&scol));

    scol = ekSYSCOLOR_LINK;
    color_indexed((uint16_t)scol, context->func_globals_color(&scol));

    scol = ekSYSCOLOR_BORDER;
    color_indexed((uint16_t)scol, context->func_globals_color(&scol));

    arrst_foreach(alt, i_ALTCOLORS, ColorAlt)
        cassert(kFIRST_COLOR_ALT + alt_i <= 0xFFFF);
        color_indexed((uint16_t)(kFIRST_COLOR_ALT + alt_i), i_DARK_MODE ? alt->dark : alt->light);
    arrst_end()
}

/*---------------------------------------------------------------------------*/

void gui_update(void)
{
    i_precompute_system_colors();

    arrpt_foreach(window, i_WINDOWS, Window)
        _window_update(window);
    arrpt_end()

    if (i_ONTHEME != NULL)
        listener_event(i_ONTHEME, 0, NULL, NULL, NULL, void, void, void);
}

/*---------------------------------------------------------------------------*/

void gui_OnThemeChanged(Listener *listener)
{
    listener_update(&i_ONTHEME, listener);
}

/*---------------------------------------------------------------------------*/

void gui_update_transitions(const real64_t prtime, const real64_t crtime)
{
    if (arrst_size(i_TRANSITIONS, Transition) > 0)
    {
        EvTransition params;
        params.prtime = prtime;
        params.crtime = crtime;
        params.cframe = UINT32_MAX;
        arrst_foreach(transition, i_TRANSITIONS, Transition)
            listener_event(transition->listener, ekGUI_EVENT_ANIMATION, NULL, &params, NULL, void, EvTransition, void);
        arrst_end()
    }

    {
        const GuiCtx *gctx = guictx_get_current();
        cassert_no_nullf(gctx->func_globals_transitions);
        gctx->func_globals_transitions(NULL, prtime, crtime);
    }
}

/*---------------------------------------------------------------------------*/

void gui_OnNotification(Listener *listener)
{
    listener_update(&i_ONNOTIF, listener);
}

/*---------------------------------------------------------------------------*/

void gui_OnIdle(Listener *listener)
{
    const GuiCtx *gctx = guictx_get_current();
    cassert_no_nullf(gctx->func_globals_OnIdle);
    gctx->func_globals_OnIdle(NULL, listener);
}

/*---------------------------------------------------------------------------*/

void *evbind_object_imp(Event *e, const char_t *type)
{
    const EvBind *p = event_params(e, EvBind);
    cassert_unref(str_equ_c(p->objtype_notif, type) == TRUE, type);
    return p->obj_notify;
}

/*---------------------------------------------------------------------------*/

bool_t evbind_modify_imp(Event *e, const char_t *type, const uint16_t size, const char_t *mname, const char_t *mtype, const uint16_t moffset, const uint16_t msize)
{
    const EvBind *p = event_params(e, EvBind);
    if (p->obj_notify != NULL)
        return gbind_modify_data(p->obj_notify, type, size, mname, mtype, moffset, msize, p);

    return FALSE;
}

/*---------------------------------------------------------------------------*/

Window *_gui_main_window(void)
{
    arrpt_foreach(window, i_WINDOWS, Window)
        if (_window_role(window) == ekGUI_ROLE_MAIN)
            return window;
    arrpt_end()
    return NULL;
}

/*---------------------------------------------------------------------------*/

Font *_gui_create_default_font(void)
{
    if (i_DEFAULT_FONT == NULL)
        i_DEFAULT_FONT = font_system(font_regular_size(), 0);
    return font_copy(i_DEFAULT_FONT);
}

/*---------------------------------------------------------------------------*/

bool_t _gui_effective_alt_font(const Font *font, const Font *alt_font)
{
    cassert_no_null(font);
    if (alt_font == NULL)
        return FALSE;
    if (font_equals(font, alt_font) == TRUE)
        return FALSE;
    else
        return TRUE;
}

/*---------------------------------------------------------------------------*/

bool_t _gui_update_font(Font **font, Font **alt_font, const Font *new_font)
{
    cassert_no_null(font);
    if (new_font != NULL && font_equals(*font, new_font) == TRUE)
        return FALSE;

    font_destroy(font);
    if (new_font != NULL)
        *font = font_copy(new_font);
    else
        *font = _gui_create_default_font();

    if (alt_font != NULL)
    {
        if (*alt_font != NULL)
        {
            uint32_t style = font_style(*alt_font);
            font_destroy(alt_font);
            *alt_font = font_with_style(*font, style);
        }
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

void _gui_add_transition_imp(void *owner, Listener *listener)
{
    arrst_foreach(transition, i_TRANSITIONS, Transition)
        if (transition->owner == owner)
        {
            cassert(FALSE);
            return;
        }
    arrst_end()

    {
        Transition *transition = arrst_new(i_TRANSITIONS, Transition);
        transition->owner = owner;
        transition->listener = listener;
    }
}

/*---------------------------------------------------------------------------*/

void _gui_delete_transition_imp(void *owner)
{
    arrst_foreach(transition, i_TRANSITIONS, Transition)
        if (transition->owner == owner)
        {
            arrst_delete(i_TRANSITIONS, transition_i, i_remove_transition, Transition);
            return;
        }
    arrst_end()
}

/*---------------------------------------------------------------------------*/

void _gui_add_window(Window *window)
{
    cassert_no_null(window);
    arrpt_append(i_WINDOWS, window, Window);
}

/*---------------------------------------------------------------------------*/

void _gui_delete_window(Window *window)
{
    uint32_t i;
    cassert_no_null(window);
    i = arrpt_find(i_WINDOWS, window, Window);
    arrpt_delete(i_WINDOWS, i, NULL, Window);

    if (i_ONNOTIF != NULL)
        listener_event(i_ONNOTIF, ekGUI_NOTIF_WIN_DESTROY, NULL, window, NULL, void, Window, void);
}

/*---------------------------------------------------------------------------*/

void _gui_add_menu(Menu *menu)
{
    cassert_no_null(menu);
    arrpt_append(i_MENUS, menu, Menu);
}

/*---------------------------------------------------------------------------*/

void _gui_delete_menu(Menu *menu)
{
    uint32_t i;
    cassert_no_null(menu);
    i = arrpt_find(i_MENUS, menu, Menu);
    arrpt_delete(i_MENUS, i, NULL, Menu);

    if (i_ONNOTIF != NULL)
        listener_event(i_ONNOTIF, ekGUI_NOTIF_MENU_DESTROY, NULL, menu, NULL, void, Menu, void);
}

/*---------------------------------------------------------------------------*/

const char_t *_gui_respack_text(const ResId id, ResId *store_id)
{
    bool_t is_resid;
    const char_t *restext = respack_atext(i_PACKS, id, &is_resid);
    if (restext != NULL)
    {
        cassert(is_resid == TRUE);
        ptr_assign(store_id, id);
        return restext;
    }
    else if (is_resid == TRUE)
    {
        ptr_assign(store_id, id);
        return "";
    }

    return (const char_t *)id;
}

/*---------------------------------------------------------------------------*/

const Image *_gui_respack_image(const ResId id, ResId *store_id)
{
    if (id != NULL)
    {
        bool_t is_resid;
        Image *resimage = respack_aobj(i_PACKS, id, image_from_data, image_destroy, &is_resid, Image);
        if (resimage != NULL)
        {
            cassert(is_resid == TRUE);
            ptr_assign(store_id, id);
            return resimage;
        }
        else if (is_resid == TRUE)
        {
            ptr_assign(store_id, id);
            return NULL;
        }

        return (const Image *)id;
    }

    return NULL;
}

/*---------------------------------------------------------------------------*/

const Cursor *_gui_cursor(const gui_cursor_t cursor, const Image *image, const real32_t hot_x, const real32_t hot_y)
{
    arrst_foreach(curs, i_CURSORS, CurIcon)
        if (cursor == ekGUI_CURSOR_USER && curs->image == image)
            return curs->cursor;
        if (cursor != ekGUI_CURSOR_USER && cursor == curs->type)
            return curs->cursor;
    arrst_end()

    {
        CurIcon *newcur = arrst_new(i_CURSORS, CurIcon);
        const GuiCtx *context = guictx_get_current();
        i_FUNC_DESTROY_CURSOR = context->func_globals_cursor_destroy;
        newcur->type = cursor;
        newcur->image = image;
        newcur->cursor = context->func_globals_cursor((enum_t)cursor, image, hot_x, hot_y);
        return newcur->cursor;
    }
}

/*---------------------------------------------------------------------------*/

static Layout *i_info_layout(ResPack *pack, const char_t *caption, const char_t *detail, const char_t *file, const uint32_t line)
{
    Layout *layout = layout_create(1, 4);
    Label *label1 = label_create();
    Label *label2 = label_multiline();
    Label *label3 = label_create();
    Label *label4 = label_create();
    Font *font = font_system(font_regular_size() + 2.f, ekFBOLD);
    String *sline = str_printf("%s: %d", respack_text(pack, LINE_TEXT), line);
    String *filename = NULL;
    String *sfile = NULL;
    str_split_pathname(file, NULL, &filename);
    sfile = str_printf("%s: %s", respack_text(pack, FILE_TEXT), tc(filename));
    label_font(label1, font);
    label_text(label1, caption);
    label_text(label2, detail);
    label_text(label3, tc(sfile));
    label_text(label4, tc(sline));
    layout_label(layout, label1, 0, 0);
    layout_label(layout, label2, 0, 1);
    layout_label(layout, label3, 0, 2);
    layout_label(layout, label4, 0, 3);
    layout_bgcolor(layout, gui_alt_color(color_rgb(255, 255, 254), color_rgb(10, 10, 10)));
    layout_skcolor(layout, gui_alt_color(color_bgr(0x4681Cf), color_bgr(0x1569E6)));
    layout_margin(layout, 5.f);
    font_destroy(&font);
    str_destroy(&filename);
    str_destroy(&sfile);
    str_destroy(&sline);
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_icons_layout(const ResPack *pack, const icon_t icon)
{
    Layout *layout = layout_create(1, 2);
    ImageView *img1 = imageview_create();
    ImageView *img2 = imageview_create();
    const Image *icon_image = NULL;
    const Image *logo_image = NULL;
    bool_t dark = gui_dark_mode();

    switch (icon)
    {
    case ekICON_ASSERT:
        icon_image = image_from_resource(pack, dark ? CONFUSED_DARK_PNG : CONFUSED_PNG);
        break;
    case ekICON_CRASH:
        icon_image = image_from_resource(pack, dark ? BOMB_DARK_PNG : BOMB_PNG);
        break;
    case ekICON_SYSTEM:
        cassert_default();
    }

    logo_image = image_from_resource(pack, dark ? LOGO_DARK_PNG : LOGO_PNG);

    imageview_image(img1, icon_image);
    imageview_image(img2, logo_image);
    layout_imageview(layout, img1, 0, 0);
    layout_imageview(layout, img2, 0, 1);
    layout_vmargin(layout, 0, 10.f);
    layout_margin4(layout, 0.f, 15.f, 0.f, 15.f);
    return layout;
}

/*---------------------------------------------------------------------------*/

static void i_OnShowAssert(void *empty, Event *e)
{
    const EvButton *params = event_params(e, EvButton);
    unref(empty);
    i_SHOW_ASSERT_WINDOW = (bool_t)(params->state == ekGUI_ON);
}

/*---------------------------------------------------------------------------*/

static void i_OnWriteLog(void *empty, Event *e)
{
    const EvButton *params = event_params(e, EvButton);
    unref(empty);
    i_WRITE_ASSERT_LOG = (bool_t)(params->state == ekGUI_ON);
}

/*---------------------------------------------------------------------------*/

static Layout *i_checks_layout(const ResPack *pack)
{
    const char_t *log_file = log_get_file();
    Layout *layout = layout_create(1, (uint32_t)(log_file != NULL ? 3 : 2));
    Button *button1 = button_check();
    Button *button2 = button_check();
    button_text(button1, respack_text(pack, SHOW_ASSERT));
    button_text(button2, respack_text(pack, ASSERT_LOG));
    button_state(button1, i_SHOW_ASSERT_WINDOW ? ekGUI_ON : ekGUI_OFF);
    button_state(button2, i_WRITE_ASSERT_LOG ? ekGUI_ON : ekGUI_OFF);
    button_OnClick(button1, listener(NULL, i_OnShowAssert, void));
    button_OnClick(button2, listener(NULL, i_OnWriteLog, void));
    layout_button(layout, button1, 0, 0);
    layout_button(layout, button2, 0, 1);

    if (log_file != NULL)
    {
        Label *label = label_create();
        Font *font = font_system(font_small_size(), 0);
        label_text(label, log_file);
        label_font(label, font);
        font_destroy(&font);
        layout_label(layout, label, 0, 2);
    }

    layout_vmargin(layout, 0, 5.f);
    return layout;
}

/*---------------------------------------------------------------------------*/

static Layout *i_assert_layout(const ResPack *pack, const char_t *message, const icon_t icon, Layout *info_layout)
{
    Layout *layout = layout_create(2, 1);
    Layout *layout1 = layout_create(1, (uint32_t)(icon == ekICON_CRASH ? 2 : 3));
    Layout *layout2 = i_icons_layout(pack, icon);
    Label *label = label_multiline();
    label_text(label, message);
    layout_layout(layout, layout2, 0, 0);
    layout_valign(layout, 0, 0, ekTOP);
    layout_hmargin(layout, 0, 5.f);
    layout_label(layout1, label, 0, 0);
    layout_layout(layout1, info_layout, 0, 1);

    if (icon != ekICON_CRASH)
    {
        Layout *layout3 = i_checks_layout(pack);
        layout_layout(layout1, layout3, 0, 2);
        layout_vmargin(layout1, 1, 5.f);
    }

    layout_hsize(layout1, 0, 300.f);
    layout_hexpand(layout, 1);
    layout_vmargin(layout1, 0, 5.f);
    layout_layout(layout, layout1, 1, 0);
    return layout;
}

/*---------------------------------------------------------------------------*/

static void i_OnContinue(void *empty, Event *event)
{
    unref(empty);
    unref(event);
    window_stop_modal(i_ASSERT_WINDOW, 0);
}

/*---------------------------------------------------------------------------*/

static void i_OnDebug(void *empty, Event *event)
{
    unref(empty);
    unref(event);
    window_stop_modal(i_ASSERT_WINDOW, 1);
}

/*---------------------------------------------------------------------------*/

static void i_OnExit(void *empty, Event *event)
{
    unref(empty);
    unref(event);
    window_stop_modal(i_ASSERT_WINDOW, 2);
}

/*---------------------------------------------------------------------------*/

static Layout *i_buttons_layout(const ResPack *pack, const icon_t icon, Button **defbutton)
{
    Layout *layout = layout_create(3, 1);
    Button *button1 = button_push();
    Button *button3 = button_push();
    button_text(button1, respack_text(pack, DEBUG_TEXT));
    button_text(button3, respack_text(pack, EXIT_TEXT));
    button_OnClick(button1, listener(NULL, i_OnDebug, void));
    button_OnClick(button3, listener(NULL, i_OnExit, void));
    layout_button(layout, button1, (uint32_t)(icon != ekICON_CRASH ? 0 : 1), 0);
    layout_button(layout, button3, 2, 0);

    if (icon != ekICON_CRASH)
    {
        Button *button2 = button_push();
        button_text(button2, respack_text(pack, CONTINUE_TEXT));
        button_OnClick(button2, listener(NULL, i_OnContinue, void));
        layout_button(layout, button2, 1, 0);
        *defbutton = button2;
    }
    else
    {
        *defbutton = button1;
    }

    layout_hmargin(layout, 0, 30.f);
    layout_hmargin(layout, 1, 10.f);
    return layout;
}

/*---------------------------------------------------------------------------*/

static Window *i_assert_window(ResPack *pack, const char_t *message, const icon_t icon, Layout *info_layout, Layout *buttons_layout, Button *defbutton)
{
    Panel *panel = panel_create();
    Layout *layout = layout_create(1, 2);
    Layout *layout1 = i_assert_layout(pack, message, icon, info_layout);
    String *title = str_printf(respack_text(pack, ASSERT_TITLE), tc(i_APP_NAME));
    Window *window = window_create(ekWINDOW_TITLE);
    layout_layout(layout, layout1, 0, 0);
    layout_layout(layout, buttons_layout, 0, 1);
    layout_vmargin(layout, 0, 20.f);
    layout_margin(layout, 15.f);
    panel_layout(panel, layout);
    window_panel(window, panel);
    window_title(window, tc(title));
    window_defbutton(window, defbutton);
    str_destroy(&title);
    return window;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_launch_assert(Window **window)
{
    Window *main_window = _gui_main_window();
    S2Df size1;
    S2Df size2;
    V2Df origin;
    uint32_t ret;

    cassert_no_null(window);

    if (main_window != NULL)
    {
        origin = window_get_origin(main_window);
        size1 = window_get_size(main_window);
    }
    else
    {
        origin = kV2D_ZEROf;
        size1 = gui_resolution();
    }

    size2 = window_get_size(*window);
    origin.x += .5f * (size1.width - size2.width);
    origin.y += 50.f;
    window_origin(*window, origin);
    ret = window_modal(*window, main_window);
    window_destroy(window);
    return ret;
}

/*---------------------------------------------------------------------------*/

static void i_assert_handler(void *item, const uint32_t group, const char_t *caption, const char_t *detail, const char_t *file, const uint32_t line)
{
    bool_t finish = FALSE;
    unref(item);

    if (i_IN_ASSERT == TRUE)
        return;

    i_IN_ASSERT = TRUE;
    /*if (app->OnAssert_listener != NULL)
    {
        EvAssert params;
        params.group = group;
        params.caption = caption;
        params.detail = detail;
        params.file = file;
        params.line = line;
        listener_event(app->OnAssert_listener, ekEVENT_ASSERT, NULL, &params, &app->show_assert_window, void, EvAssert, bool_t);
    }*/

    if (i_SHOW_ASSERT_WINDOW == TRUE)
    {
        Button *defbutton = NULL;
        ResPack *pack = res_gui_respack("");
        const char_t *message = respack_text(pack, group == 0 ? ASSERT_CRASH : ASSERT_INFO);
        String *smessage = str_printf("%s %s %s", message, respack_text(pack, CONTACT_INFO), "support@nappgui.com");
        icon_t icon = group == 0 ? ekICON_CRASH : ekICON_ASSERT;
        Layout *info_layout = i_info_layout(pack, caption, detail, file, line);
        Layout *buttons_layout = i_buttons_layout(pack, icon, &defbutton);
        uint32_t assert_ret;
        i_ASSERT_WINDOW = i_assert_window(pack, tc(smessage), icon, info_layout, buttons_layout, defbutton);
        assert_ret = i_launch_assert(&i_ASSERT_WINDOW);
        switch (assert_ret)
        {
        case 0:
            break;
        case 1:
            blib_debug_break();
            break;
        case 2:
            blib_abort();
            break;
            cassert_default();
        }

        respack_destroy(&pack);
        str_destroy(&smessage);
    }

    if (i_WRITE_ASSERT_LOG == TRUE)
    {
        if (group == 0)
        {
            log_printf("FATAL ASSERT: %s (%s:%d): %s", caption, file, line, detail);
            bproc_exit(1000);
        }
        else
        {
            log_printf("ASSERT: %s (%s:%d): %s", caption, file, line, detail);
        }
    }

    i_IN_ASSERT = finish;
}

/*---------------------------------------------------------------------------*/

static void i_OnInfoClick(void *unused, Event *e)
{
    Button *sender = event_sender(e, Button);
    uint32_t tag = button_get_tag(sender);
    window_stop_modal(i_INFO_WINDOW, tag);
    unref(unused);
}

/*---------------------------------------------------------------------------*/

static Layout *i_info_buttons_layout(const ArrPt(String) *buttons, const uint32_t defindex, Button **defbutton)
{
    uint32_t i, n = arrpt_size(buttons, String);
    Layout *layout = layout_create(n, 1);
    cassert_no_null(defbutton);
    cassert(defindex < n);
    for (i = 0; i < n; ++i)
    {
        Button *button = button_push();
        const String *text = arrpt_get_const(buttons, i, String);
        button_text(button, tc(text));
        button_tag(button, i);
        button_OnClick(button, listener(NULL, i_OnInfoClick, void));
        layout_button(layout, button, i, 0);

        if (i < n - 1)
            layout_hmargin(layout, i, 10.f);

        if (i == defindex)
            *defbutton = button;
    }

    return layout;
}

/*---------------------------------------------------------------------------*/

uint32_t gui_info_window(const bool_t fatal, const char_t *msg, const char_t *caption, const char_t *detail, const char_t *file, const uint32_t line, const ArrPt(String) *buttons, const uint32_t defindex)
{
    ResPack *pack = res_gui_respack("");
    Button *defbutton = NULL;
    icon_t icon = fatal ? ekICON_CRASH : ekICON_ASSERT;
    Layout *info_layout = i_info_layout(pack, caption, detail, file, line);
    Layout *buttons_layout = i_info_buttons_layout(buttons, defindex, &defbutton);
    i_INFO_WINDOW = i_assert_window(pack, msg, icon, info_layout, buttons_layout, defbutton);
    respack_destroy(&pack);
    return i_launch_assert(&i_INFO_WINDOW);
}
