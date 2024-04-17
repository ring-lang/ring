/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: menuitem.c
 *
 */

/* Menu Item */

#include "menuitem.h"
#include "menuitem.inl"
#include "menu.inl"
#include "gui.inl"
#include <draw2d/guictx.h>
#include <draw2d/image.h>
#include <core/event.h>
#include <core/objh.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _menu_item_t
{
    Object object;
    GuiCtx *context;
    bool_t is_separator;
    uint16_t index;
    ResId textid;
    String *text;
    Image *image;
    void *ositem;
    Menu *submenu;
    Listener *OnClick;
};

/*---------------------------------------------------------------------------*/

static MenuItem *i_create(
    const GuiCtx *context,
    const bool_t is_separator,
    Image **image,
    void **ositem,
    Menu **submenu,
    Listener **OnClick)
{
    MenuItem *item = obj_new(MenuItem);
    item->context = guictx_retain(context);
    item->is_separator = is_separator;
    item->index = UINT16_MAX;
    item->textid = NULL;
    item->text = str_c("");
    item->image = ptr_dget(image, Image);
    item->ositem = ptr_dget_no_null(ositem, void);
    item->submenu = ptr_dget(submenu, Menu);
    item->OnClick = ptr_dget(OnClick, Listener);
    return item;
}

/*---------------------------------------------------------------------------*/

void _menuitem_destroy(MenuItem **item)
{
    cassert_no_null(item);
    cassert_no_null(*item);
    cassert((*item)->index == UINT16_MAX);
    cassert_no_null((*item)->context);
    cassert_no_nullf((*item)->context->func_menuitem_destroy);
    cassert((*item)->OnClick == NULL);
    if ((*item)->submenu != NULL)
    {
        void *ositem;
        cassert_no_nullf((*item)->context->func_detach_menu_from_menu_item);
        _menu_unset_parent((*item)->submenu);
        ositem = _menu_ositem((*item)->submenu);
        (*item)->context->func_detach_menu_from_menu_item((*item)->ositem, ositem);
        _menu_destroy(&(*item)->submenu);
    }

    (*item)->context->func_menuitem_destroy(&(*item)->ositem);
    str_destopt(&(*item)->text);
    ptr_destopt(image_destroy, &(*item)->image, Image);
    guictx_release(&(*item)->context);
    obj_delete(item, MenuItem);
}

/*---------------------------------------------------------------------------*/

/*
static void i_synchro_menuitem_mark(
                        const GuiCtx *context,
                        const enum gui_menuitem_mode_t edit_mode,
                        bool_t *edit_value,
                        void *ositem,
                        const String *on_text,
                        const String *off_text)
{
    cassert_no_null(context);

    if (edit_value != NULL)
    {
        switch (edit_mode)
        {
            case ekGUI_MENUITEM_MODE_TOOGLE_MARK:
                cassert_no_nullf(context->func_menuitem_set_state);
                context->func_menuitem_set_state(ositem, (enum_t)((*edit_value == TRUE) ? ekGUI_ON : ekGUI_OFF));
                break;
            case ekGUI_MENUITEM_MODE_TOOGLE_TEXT:
                cassert_no_nullf(context->func_menuitem_set_text);
                context->func_menuitem_set_text(ositem, (*edit_value == TRUE) ? tc(off_text) : tc(on_text));
                break;
            case ekGUI_MENUITEM_MODE_PUSH:
            cassert_default();
        }
    }
}*/

/*---------------------------------------------------------------------------*/

static void i_OnMenuItemClick(MenuItem *item, Event *e)
{
    cassert_no_null(item);
    cassert(item->is_separator == FALSE);
    cassert(event_sender_imp(e, NULL) == item->ositem);

    /*
    switch (item->edit_mode)
    {
        case ekGUI_MENUITEM_MODE_TOOGLE_MARK:
        case ekGUI_MENUITEM_MODE_TOOGLE_TEXT:

            if (item->edit_value != NULL)
            {
                if (*item->edit_value == TRUE)
                    *item->edit_value = FALSE;
                else
                    *item->edit_value = TRUE;
            }

            i_synchro_menuitem_mark(item->context, item->edit_mode, item->edit_value, item->ositem, item->on_text, item->off_text);
            break;
        case ekGUI_MENUITEM_MODE_PUSH:
            break;
        cassert_default();
    }*/

    if (item->OnClick != NULL)
    {
        EvMenu *p = event_params(e, EvMenu);
        cassert(p->index == UINT32_MAX);
        cassert(p->text == NULL);
        p->index = item->index;
        p->text = tc(item->text);
        listener_pass_event(item->OnClick, e, item, MenuItem);
    }
}

/*---------------------------------------------------------------------------*/

MenuItem *menuitem_create(void)
{
    const GuiCtx *context = NULL;
    void *ositem = NULL;
    Menu *submenu = NULL;
    Image *image = NULL;
    Listener *OnClick = NULL;
    MenuItem *item = NULL;
    context = guictx_get_current();
    cassert_no_null(context);
    cassert_no_nullf(context->func_menuitem_create);
    cassert_no_nullf(context->func_menuitem_OnClick);
    ositem = context->func_menuitem_create((enum_t)ekMENU_ITEM);
    item = i_create(context, PARAM(is_separator, FALSE), &image, &ositem, &submenu, &OnClick);
    context->func_menuitem_OnClick(item->ositem, obj_listener(item, i_OnMenuItemClick, MenuItem));
    return item;
}

/*---------------------------------------------------------------------------*/

MenuItem *menuitem_separator(void)
{
    const GuiCtx *context = NULL;
    void *ositem = NULL;
    Menu *submenu = NULL;
    Image *image = NULL;
    Listener *OnClick = NULL;
    context = guictx_get_current();
    cassert_no_null(context);
    cassert_no_nullf(context->func_menuitem_create);
    ositem = context->func_menuitem_create((enum_t)ekMENU_SEPARATOR);
    return i_create(context, PARAM(has_parent, FALSE), &image, &ositem, &submenu, &OnClick);
}

/*---------------------------------------------------------------------------*/

void menuitem_OnClick(MenuItem *item, Listener *listener)
{
    cassert_no_null(item);
    listener_update(&item->OnClick, listener);
}

/*---------------------------------------------------------------------------*/

void menuitem_enabled(MenuItem *item, const bool_t enabled)
{
    cassert_no_null(item);
    cassert_no_null(item->context);
    cassert_no_nullf(item->context->func_menuitem_set_enabled);
    item->context->func_menuitem_set_enabled(item->ositem, enabled);
}

/*---------------------------------------------------------------------------*/

void menuitem_visible(MenuItem *item, const bool_t visible)
{
    cassert_no_null(item);
    cassert_no_null(item->context);
    cassert_no_nullf(item->context->func_menuitem_set_visible);
    item->context->func_menuitem_set_visible(item->ositem, visible);
}

/*---------------------------------------------------------------------------*/

static void i_update_text(MenuItem *item, const char_t *text, ResId *resid)
{
    const char_t *ltext = NULL;
    cassert_no_null(item);
    cassert(item->is_separator == FALSE);
    cassert_no_null(item->context);
    cassert_no_nullf(item->context->func_menuitem_set_text);
    ltext = _gui_respack_text(text, resid);
    item->context->func_menuitem_set_text(item->ositem, ltext);
    str_upd(&item->text, ltext);
}

/*---------------------------------------------------------------------------*/

void menuitem_text(MenuItem *item, const char_t *text)
{
    cassert_no_null(item);
    i_update_text(item, text, &item->textid);
}

/*---------------------------------------------------------------------------*/

void menuitem_image(MenuItem *item, const Image *image)
{
    const Image *limage = _gui_respack_image((ResId)image, NULL);
    cassert_no_null(item);
    cassert_no_null(item->context);
    cassert_no_nullf(item->context->func_menuitem_set_image);
    ptr_destopt(image_destroy, &item->image, Image);
    item->image = ptr_copyopt(image_copy, limage, Image);
    item->context->func_menuitem_set_image(item->ositem, limage);
}

/*---------------------------------------------------------------------------*/

void menuitem_key(MenuItem *item, const vkey_t key, const uint32_t modifiers)
{
    cassert_no_null(item);
    cassert(item->is_separator == FALSE);
    cassert_no_null(item->context);
    cassert_no_nullf(item->context->func_menuitem_set_key_equivalent);
    item->context->func_menuitem_set_key_equivalent(item->ositem, key, modifiers);
}

/*---------------------------------------------------------------------------*/

void menuitem_submenu(MenuItem *item, Menu **submenu)
{
    void *ositem = NULL;
    cassert_no_null(item);
    cassert(item->is_separator == FALSE);
    cassert(item->submenu == NULL);
    cassert_no_null(submenu);
    cassert_no_null(item->context);
    cassert_no_nullf(item->context->func_attach_menu_to_menu_item);
    _menu_set_parent(*submenu);
    ositem = _menu_ositem(*submenu);
    item->context->func_attach_menu_to_menu_item(item->ositem, ositem);
    item->submenu = *submenu;
    *submenu = NULL;
}

/*---------------------------------------------------------------------------*/

void menuitem_state(MenuItem *item, const gui_state_t state)
{
    cassert_no_null(item);
    cassert(item->is_separator == FALSE);
    cassert_no_null(item->context);
    cassert_no_nullf(item->context->func_menuitem_set_state);
    item->context->func_menuitem_set_state(item->ositem, (enum_t)state);
}

/*---------------------------------------------------------------------------*/

void *_menuitem_get_renderable(const MenuItem *item)
{
    cassert_no_null(item);
    return item->ositem;
}

/*---------------------------------------------------------------------------*/

void _menuitem_set_parent(MenuItem *item, const uint32_t index)
{
    cassert_no_null(item);
    cassert(item->index == UINT16_MAX);
    item->index = (uint16_t)index;
}

/*---------------------------------------------------------------------------*/

void _menuitem_unset_parent(MenuItem *item)
{
    cassert_no_null(item);
    cassert(item->index != UINT16_MAX);
    listener_destroy(&item->OnClick);
    item->index = UINT16_MAX;
}

/*---------------------------------------------------------------------------*/

void _menuitem_locale(MenuItem *item)
{
    if (item->textid != NULL)
        i_update_text(item, item->textid, NULL);

    if (item->submenu != NULL)
        _menu_locale(item->submenu);
}
