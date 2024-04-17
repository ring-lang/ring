/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: menu.c
 *
 */

/* Menu */

#include "menu.h"
#include "menu.inl"
#include "gui.inl"
#include "menuitem.h"
#include "menuitem.inl"
#include "window.inl"
#include <draw2d/guictx.h>
#include <core/arrpt.h>
#include <core/objh.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _menu_t
{
    Object object;
    GuiCtx *context;
    bool_t has_parent;
    void *ositem;
    ArrPt(MenuItem) *items;
};

/*---------------------------------------------------------------------------*/

static Menu *i_create_menu(const GuiCtx *context, const bool_t has_parent, void **ositem, ArrPt(MenuItem) **items)
{
    Menu *menu = obj_new(Menu);
    menu->context = guictx_retain(context);
    menu->has_parent = has_parent;
    menu->ositem = ptr_dget_no_null(ositem, void);
    menu->items = ptr_dget_no_null(items, ArrPt(MenuItem));
    _gui_add_menu(menu);
    return menu;
}

/*---------------------------------------------------------------------------*/

Menu *menu_create(void)
{
    const GuiCtx *context = NULL;
    bool_t has_parent = FALSE;
    void *ositem = NULL;
    ArrPt(MenuItem) *items;
    context = guictx_get_current();
    cassert_no_null(context);
    cassert_no_nullf(context->func_menu_create);
    ositem = context->func_menu_create((enum_t)0);
    items = arrpt_create(MenuItem);
    return i_create_menu(context, has_parent, &ositem, &items);
}

/*---------------------------------------------------------------------------*/

static void i_detach_menuitems(ArrPt(MenuItem) *items, void *ositem, FPtr_gctx_set_ptr func_detach_menuitem_from_menu)
{
    register uint32_t i, num_items;
    register MenuItem **item;
    cassert_no_nullf(func_detach_menuitem_from_menu);
    num_items = arrpt_size(items, MenuItem);
    item = arrpt_all(items, MenuItem);
    for (i = 0; i < num_items; ++i, ++item)
    {
        void *renderable_menu_item;
        _menuitem_unset_parent(*item);
        renderable_menu_item = _menuitem_get_renderable(*item);
        func_detach_menuitem_from_menu(ositem, renderable_menu_item);
    }
}

/*---------------------------------------------------------------------------*/

static void i_destroy(Menu **menu)
{
    cassert_no_null(menu);
    cassert_no_null(*menu);
    cassert((*menu)->has_parent == FALSE);
    cassert_no_null((*menu)->context);
    cassert_no_nullf((*menu)->context->func_menu_destroy);
    i_detach_menuitems((*menu)->items, (*menu)->ositem, (*menu)->context->func_detach_menuitem_from_menu);
    arrpt_destroy(&(*menu)->items, _menuitem_destroy, MenuItem);
    (*menu)->context->func_menu_destroy(&(*menu)->ositem);
    guictx_release(&(*menu)->context);
    obj_delete(menu, Menu);
}

/*---------------------------------------------------------------------------*/

void menu_destroy(Menu **menu)
{
    cassert_no_null(menu);
    _gui_delete_menu(*menu);
    i_destroy(menu);
}

/*---------------------------------------------------------------------------*/

void _menu_destroy(Menu **menu)
{
    i_destroy(menu);
}

/*---------------------------------------------------------------------------*/

void menu_item(Menu *menu, MenuItem *item)
{
    void *ositem = NULL;
    cassert_no_null(menu);
    cassert_no_null(menu->context);
    cassert_no_nullf(menu->context->func_attach_menuitem_to_menu);
    cassert_no_null(item);
    _menuitem_set_parent(item, arrpt_size(menu->items, MenuItem));
    ositem = _menuitem_get_renderable(item);
    menu->context->func_attach_menuitem_to_menu(menu->ositem, ositem);
    arrpt_append(menu->items, item, MenuItem);
}

/*---------------------------------------------------------------------------*/

void menu_launch(Menu *menu, const V2Df position)
{
    Window *main_window = NULL;
    void *window_renderable = NULL;
    cassert_no_null(menu);
    cassert_no_null(menu->context);
    cassert_no_nullf(menu->context->func_menu_launch_popup);
    main_window = _gui_main_window();
    window_renderable = _window_ositem(main_window);
    menu->context->func_menu_launch_popup(menu->ositem, window_renderable, position.x, position.y);
}

/*---------------------------------------------------------------------------*/

void menu_hide(Menu *menu)
{
    cassert_no_null(menu);
}

/*---------------------------------------------------------------------------*/

void menu_off_items(Menu *menu)
{
    cassert_no_null(menu);
    arrpt_foreach(item, menu->items, MenuItem)
        menuitem_state(item, ekGUI_OFF);
    arrpt_end()
}

/*---------------------------------------------------------------------------*/

MenuItem *menu_get_item(Menu *menu, const uint32_t index)
{
    cassert_no_null(menu);
    return arrpt_get(menu->items, index, MenuItem);
}

/*---------------------------------------------------------------------------*/

uint32_t menu_size(const Menu *menu)
{
    cassert_no_null(menu);
    return arrpt_size(menu->items, MenuItem);
}

/*---------------------------------------------------------------------------*/

void *menu_imp(const Menu *menu)
{
    cassert_no_null(menu);
    return menu->ositem;
}

/*---------------------------------------------------------------------------*/

/*
void menu_detach_all_menuitems(Menu *menu);
void menu_detach_all_menuitems(Menu *menu)
{
    cassert_no_null(menu);
    cassert_no_null(menu->context);
    cassert_no_nullf(menu->context->func_detach_menuitem_from_menu);
    i_detach_menuitems(menu->items, menu->ositem, menu->context->func_detach_menuitem_from_menu);
    arrptr_clear_and_destroy(menu->items, _menuitem_destroy, MenuItem);
}*/

/*---------------------------------------------------------------------------*/

/*
uint32_t menu_num_items(const Menu *menu);
uint32_t menu_num_items(const Menu *menu)
{
    cassert_no_null(menu);
    return arrptr_length(menu->items, MenuItem);
}*/

/*---------------------------------------------------------------------------*/

/*
uint32_t menu_item_index(const Menu *menu, const MenuItem *menuitem);
uint32_t menu_item_index(const Menu *menu, const MenuItem *menuitem)
{
    register uint32_t i, num_items;
    register const MenuItem **item;
    cassert_no_null(menu);
    num_items = arrptr_length(menu->items, MenuItem);
    item = arrptr_get_c_buffer(menu->items, MenuItem);
    for (i = 0; i < num_items; ++i, ++item)
    {
        if ((*item) == menuitem)
            return i;
    }
    return UINT32_MAX;
}*/

/*---------------------------------------------------------------------------*/

void _menu_set_parent(Menu *menu)
{
    cassert_no_null(menu);
    cassert(menu->has_parent == FALSE);
    menu->has_parent = TRUE;
}

/*---------------------------------------------------------------------------*/

void _menu_unset_parent(Menu *menu)
{
    cassert_no_null(menu);
    cassert(menu->has_parent == TRUE);
    menu->has_parent = FALSE;
}

/*---------------------------------------------------------------------------*/

void _menu_locale(Menu *menu)
{
    cassert_no_null(menu);
    arrpt_foreach(item, menu->items, MenuItem)
        _menuitem_locale(item);
    arrpt_end()
}

/*---------------------------------------------------------------------------*/

void *_menu_ositem(Menu *menu)
{
    cassert_no_null(menu);
    return menu->ositem;
}
