/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmenu.c
 *
 */

/* Operating System native menu */

#include "osmenu.h"
#include "osmenu_win.inl"
#include "osgui_win.inl"
#include "osmenuitem_win.inl"
#include "oswindow_win.inl"
#include <core/arrpt.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

/*
    https://blogs.msdn.microsoft.com/oldnewthing/20031230-00/?p=41273

    CreateMenu creates a horizontal menu bar, suitable for attaching to a top-level window. This is the sort of menu that says "File, Edit", and so on.
    CreatePopupMenu creates a vertical popup menu, suitable for use as a submenu of another menu (either a horizontal menu bar or another popup menu) or as the root of a context menu.
    If you get the two confused, you can get strange menu behavior. Windows on rare occasions detects that you confused the two and converts as appropriate, but I wouldn't count on Windows successfully reading your mind.

    There is no way to take a menu and ASK IT WHETHER IT IS HORIZONTAL OR VERTICAL. You just have to know.

    Answers to other questions about menus:
        When a window is destroyed, its menu is also destroyed. When a menu is destroyed, the entire menu tree is destroyed. (All its submenus are destroyed, all the submenu's submenus, etc.) And when you destroy a menu, it had better not be the submenu of some other menu. That other menu would have an invalid menu as a submenu!
        If you remove a submenu from its parent, then you become responsible for destroying it, since it no longer gets destroyed automatically when the parent is destroyed.
        It is legal for a menu to be a submenu of multiple parent menus. Be extra careful when you do this, however, because if one of the parents is destroyed, it will destroy the submenu with it, leaving the other parent with an invalid submenu.
        And finally: The menu nesting limit is currently 25 on Windows XP. That may change in the future, of course. (As with window nesting, Windows 95 let you go ahead and nest menus all you wanted. In fact, you could go really evil and create an infinite loop of menus. You crashed pretty quickly thereafter, of course...)
*/

struct _osmenu_t
{
    HMENU hmenu;
    OSWindow *window;
    bool_t is_popup;
    OSMenuItem *parent;
    ArrPt(OSMenuItem) *items;
};

/*---------------------------------------------------------------------------*/

OSMenu *osmenu_create(const uint32_t flags)
{
    OSMenu *menu = heap_new0(OSMenu);
    menu->hmenu = CreatePopupMenu();
    menu->window = NULL;
    menu->is_popup = TRUE;
    menu->parent = NULL;
    menu->items = arrpt_create(OSMenuItem);
    unref(flags);
    return menu;
}

/*---------------------------------------------------------------------------*/

void osmenu_destroy(OSMenu **menu)
{
    BOOL ok = FALSE;
    int c;
    cassert_no_null(menu);
    cassert_no_null(*menu);
    cassert_no_null((*menu)->hmenu);
    c = GetMenuItemCount((*menu)->hmenu);
    cassert(GetMenuItemCount((*menu)->hmenu) == 0);
    cassert(arrpt_size((*menu)->items, OSMenuItem) == 0);
    arrpt_destroy(&(*menu)->items, NULL, OSMenuItem);
    ok = EndMenu();
    cassert(ok != 0);
    ok = DestroyMenu((*menu)->hmenu);
    cassert_unref(ok != 0, ok);
    heap_delete(menu, OSMenu);
}

/*---------------------------------------------------------------------------*/

void osmenu_add_item(OSMenu *menu, OSMenuItem *item)
{
    cassert_no_null(menu);
    arrpt_append(menu->items, item, OSMenuItem);
    _osmenuitem_insert_in_hmenu(item, menu);
}

/*---------------------------------------------------------------------------*/

void osmenu_delete_item(OSMenu *menu, OSMenuItem *item)
{
    uint32_t pos = UINT32_MAX;
    bool_t ok;
    cassert_no_null(menu);
    pos = arrpt_find(menu->items, item, OSMenuItem);
    arrpt_delete(menu->items, pos, NULL, OSMenuItem);
    ok = _osmenuitem_remove_from_hmenu(item, menu);
    cassert_unref(ok == TRUE, ok);
}

/*---------------------------------------------------------------------------*/

static void i_remove_all_items(OSMenu *menu)
{
    register uint32_t n, n0 = 0;
    cassert_no_null(menu);
    cassert_no_null(menu->hmenu);
    n = (uint32_t)GetMenuItemCount(menu->hmenu);
    arrpt_foreach(item, menu->items, OSMenuItem)
        if (_osmenuitem_remove_from_hmenu(item, menu) == TRUE)
            n0 += 1;
    arrpt_end()

    cassert_unref(n == n0, n);
    cassert(GetMenuItemCount(menu->hmenu) == 0);
}

/*---------------------------------------------------------------------------*/

static void i_add_all_items(OSMenu *menu)
{
    cassert_no_null(menu);
    cassert_no_null(menu->hmenu);
    arrpt_foreach(item, menu->items, OSMenuItem)
        _osmenuitem_insert_in_hmenu(item, menu);
    arrpt_end()
}

/*---------------------------------------------------------------------------*/

void osmenu_launch(OSMenu *menu, OSWindow *window, const real32_t x, const real32_t y)
{
    cassert_no_null(menu);
    cassert(menu->window == NULL);
    if (menu->is_popup == FALSE)
    {
        BOOL ok = FALSE;
        i_remove_all_items(menu);
        ok = DestroyMenu(menu->hmenu);
        cassert(ok != 0);
        menu->hmenu = CreatePopupMenu();
        i_add_all_items(menu);
        menu->is_popup = TRUE;
    }

    {
        HWND hwnd = NULL;
        BOOL ok = FALSE;
        register UINT flags = TPM_LEFTALIGN | TPM_TOPALIGN | TPM_RIGHTBUTTON | TPM_NOANIMATION;
        hwnd = _oswindow_set_current_popup_menu(window, menu->hmenu);
        ok = TrackPopupMenu(menu->hmenu, flags, (int)x, (int)y, PARAM(nReserved, 0), hwnd, NULL);
        cassert(ok != 0);
    }
}

/*---------------------------------------------------------------------------*/

void osmenu_hide(OSMenu *menu)
{
    BOOL ok = FALSE;
    cassert_no_null(menu);
    unref(menu);
    ok = EndMenu();
    cassert(ok != 0);
}

/*---------------------------------------------------------------------------*/

HMENU _osmenu_hmenu(OSMenu *menu)
{
    cassert_no_null(menu);
    cassert_no_null(menu->hmenu);
    return menu->hmenu;
}

/*---------------------------------------------------------------------------*/

HMENU _osmenu_menubar(OSMenu *menu, OSWindow *window)
{
    cassert_no_null(menu);
    cassert_no_null(menu->hmenu);
    cassert(menu->window == NULL);
    if (menu->is_popup == TRUE)
    {
        BOOL ok = FALSE;
        i_remove_all_items(menu);
        ok = DestroyMenu(menu->hmenu);
        cassert(ok != 0);
        menu->hmenu = CreateMenu();
        i_add_all_items(menu);
        menu->is_popup = FALSE;
    }

    menu->window = window;
    return menu->hmenu;
}

/*---------------------------------------------------------------------------*/

HMENU _osmenu_menubar_unlink(OSMenu *menu, OSWindow *window)
{
    cassert_no_null(menu);
    cassert_unref(menu->window == window, window);
    cassert(menu->is_popup == FALSE);
    menu->window = NULL;
    return menu->hmenu;
}

/*---------------------------------------------------------------------------*/

void _osmenu_recompute(OSMenu *menu)
{
    cassert_no_null(menu);
    i_remove_all_items(menu);
    i_add_all_items(menu);
    if (menu->window != NULL)
    {
        HWND hwnd = ((OSControl *)menu->window)->hwnd;
        BOOL ok = DrawMenuBar(hwnd);
        cassert_unref(ok != 0, ok);
    }
}

/*---------------------------------------------------------------------------*/

void _osmenu_attach_to_item(OSMenu *menu, OSMenuItem *item)
{
    cassert_no_null(menu);
    cassert(menu->parent == NULL);
    cassert(menu->hmenu != NULL);
    menu->parent = item;
    /* A Submenu is always a PopUp menu */
    /*if (menu->hmenu == NULL)
    {
        menu->hmenu = CreatePopupMenu();
        menu->is_popup = TRUE;
        i_add_all_items(menu->hmenu, &menu->items);
    }*/
}

/*---------------------------------------------------------------------------*/

void _osmenu_detach_from_item(OSMenu *menu, OSMenuItem *item)
{
    cassert_no_null(menu);
    cassert_unref(menu->parent == item, item);
    menu->parent = NULL;
}

/*---------------------------------------------------------------------------*/

void _osmenu_append_item(HMENU menu, const Font *font, const char_t *text, const Image *image, OSControl *owner)
{
    int index;
    MENUITEMINFO info;
    //BOOL res;
    cassert_no_null(font);
    cassert_no_null(text);
    unref(image);
    cassert_no_null(owner);
    index = GetMenuItemCount(menu);
    info.cbSize = sizeof(MENUITEMINFO);
    info.fMask = MIIM_FTYPE | MIIM_DATA;
    info.fType = MFT_OWNERDRAW;
    info.dwItemData = (ULONG_PTR)owner;

    //    res = InsertMenuItem(menu, 0, TRUE, );
    /*cassert(FALSE);*/
}
