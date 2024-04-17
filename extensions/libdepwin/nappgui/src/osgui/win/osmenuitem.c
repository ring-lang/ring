/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmenuitem.c
 *
 */

/* Operating System native menu item */

#include "osmenuitem.h"
#include "osmenuitem_win.inl"
#include "osmenu_win.inl"
#include "osgui_win.inl"
#include "osimg.inl"
#include <core/heap.h>
#include <core/event.h>
#include <core/strings.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

static const char_t *i_KEY_TEXT[] =
    {
        "",  /*ekKEY_UNASSIGNED      = 0*/
        "A", /*ekKEY_A               = 1*/
        "S", /*ekKEY_S               = 2*/
        "D", /*ekKEY_D               = 3*/
        "F", /*ekKEY_F               = 4*/
        "H", /*ekKEY_H               = 5*/
        "G", /*ekKEY_G               = 6*/
        "Z", /*ekKEY_Z               = 7*/
        "X", /*ekKEY_X               = 8*/
        "C", /*ekKEY_C               = 9*/

        "V",  /*ekKEY_V               = 10*/
        "\\", /*ekKEY_BSLASH          = 11*/
        "B",  /*ekKEY_B               = 12*/
        "Q",  /*ekKEY_Q               = 13*/
        "W",  /*ekKEY_W               = 14*/
        "E",  /*ekKEY_E               = 15*/
        "R",  /*ekKEY_R               = 16*/
        "Y",  /*ekKEY_Y               = 17*/
        "T",  /*ekKEY_T               = 18*/
        "1",  /*ekKEY_1               = 19*/

        "2", /*ekKEY_2               = 20*/
        "3", /*ekKEY_3               = 21*/
        "4", /*ekKEY_4               = 22*/
        "6", /*ekKEY_6               = 23*/
        "5", /*ekKEY_5               = 24*/
        "9", /*ekKEY_9               = 25*/
        "7", /*ekKEY_7               = 26*/
        "8", /*ekKEY_8               = 27*/
        "0", /*ekKEY_0               = 28*/
        "}", /*ekKEY_RCURLY          = 29*/

        "O",     /*ekKEY_O               = 30*/
        "U",     /*ekKEY_U               = 31*/
        "{",     /*ekKEY_LCURLY          = 32*/
        "I",     /*ekKEY_I               = 33*/
        "P",     /*ekKEY_P               = 34*/
        "Intro", /*ekKEY_RETURN          = 35*/
        "L",     /*ekKEY_L               = 36*/
        "J",     /*ekKEY_J               = 37*/
        ";",     /*ekKEY_SEMICOLON       = 38*/
        "K",     /*ekKEY_K               = 39*/

        "\'",   /*ekKEY_QUEST           = 40*/
        ",",    /*ekKEY_COMMA           = 41*/
        "-",    /*ekKEY_MINUS           = 42*/
        "N",    /*ekKEY_N               = 43*/
        "M",    /*ekKEY_M               = 44*/
        ".",    /*ekKEY_PERIOD          = 45*/
        "Tab",  /*ekKEY_TAB             = 46*/
        " ",    /*ekKEY_SPACE           = 47*/
        ">",    /*ekKEY_GTLT            = 48*/
        "Back", /*ekKEY_BACK            = 49*/

        "Esc",  /*ekKEY_ESCAPE          = 50*/
        "F17",  /*ekKEY_F17             = 51*/
        ".",    /*ekKEY_NUMPAD_DECIMAL  = 52*/
        "*",    /*ekKEY_NUMPAD_MULT     = 53*/
        "+",    /*ekKEY_NUMPAD_ADD      = 54*/
        "Lock", /*ekKEY_NUMLOCK         = 55*/
        "/",    /*ekKEY_NUMPAD_DIV      = 56*/
        "Itro", /*ekKEY_NUMPAD_RETURN   = 57*/
        "-",    /*ekKEY_NUMPAD_SUBTRACT = 58*/
        "F18",  /*ekKEY_F18             = 59*/

        "F19", /*ekKEY_F19             = 60*/
        " ",   /*ekKEY_NUMPAD_EQUAL    = 61*/
        "0",   /*ekKEY_NUMPAD0         = 62*/
        "1",   /*ekKEY_NUMPAD1         = 63*/
        "2",   /*ekKEY_NUMPAD2         = 64*/
        "3",   /*ekKEY_NUMPAD3         = 65*/
        "4",   /*ekKEY_NUMPAD4         = 66*/
        "5",   /*ekKEY_NUMPAD5         = 67*/
        "6",   /*ekKEY_NUMPAD6         = 68*/
        "7",   /*ekKEY_NUMPAD7         = 69*/

        "8",   /*ekKEY_NUMPAD8         = 70*/
        "9",   /*ekKEY_NUMPAD9         = 71*/
        "F5",  /*ekKEY_F5              = 72*/
        "F6",  /*ekKEY_F6              = 73*/
        "F7",  /*ekKEY_F7              = 74*/
        "F3",  /*ekKEY_F3              = 75*/
        "F8",  /*ekKEY_F8              = 76*/
        "F9",  /*ekKEY_F9              = 77*/
        "F11", /*ekKEY_F11             = 78*/
        "F13", /*ekKEY_F13             = 79*/

        "F16",  /*ekKEY_F16             = 80*/
        "F14",  /*ekKEY_F14             = 81*/
        "F10",  /*ekKEY_F10             = 82*/
        "F12",  /*ekKEY_F12             = 83*/
        "F15",  /*ekKEY_F15             = 84*/
        "Up",   /*ekKEY_PAGEUP          = 85*/
        "Home", /*ekKEY_HOME            = 86*/
        " ",    /*ekKEY_SUPR            = 87*/
        "F4",   /*ekKEY_F4              = 88*/
        "Down", /*ekKEY_PAGEDOWN        = 89*/

        "F2",  /*ekKEY_F2              = 90*/
        "End", /*ekKEY_END             = 91*/
        "F1",  /*ekKEY_F1              = 92*/
        "←",   /*ekKEY_LEFT            = 93*/
        "→",   /*ekKEY_RIGHT           = 94*/
        "↓",   /*ekKEY_DOWN            = 95*/
        "↑"    /*ekKEY_UP              = 96*/
};

struct _osmenuitem_t
{
    OSMenu *menu;
    OSMenu *sub_menu;
    String *text;
    uint16_t id;
    uint16_t empty;
    bool_t visible;
    bool_t enabled;
    uint8_t state;
    uint8_t unused;
    HBITMAP hbitmap;
    vkey_t key;
    uint32_t modifiers;
    Listener *OnClick;
};

/*---------------------------------------------------------------------------*/

static __INLINE OSMenuItem *i_create(const uint16_t id, const uint8_t state, const char_t *text)
{
    OSMenuItem *item = heap_new0(OSMenuItem);
    item->text = text != NULL ? str_c(text) : NULL;
    item->id = id;
    item->visible = TRUE;
    item->enabled = TRUE;
    item->state = state;
    item->key = ENUM_MAX(vkey_t);
    item->modifiers = UINT32_MAX;
    return item;
}

/*---------------------------------------------------------------------------*/

OSMenuItem *osmenuitem_create(const uint32_t flags)
{
    uint16_t id = _osgui_unique_child_id();

    if (flags == ekMENU_ITEM)
    {
        return i_create(id, ekGUI_OFF, "");
    }
    else
    {
        cassert(flags == ekMENU_SEPARATOR);
        return i_create(id, UINT8_MAX, NULL);
    }
}

/*---------------------------------------------------------------------------*/

void osmenuitem_destroy(OSMenuItem **item)
{
    cassert_no_null(item);
    cassert_no_null(*item);
    cassert((*item)->menu == NULL);
    cassert((*item)->sub_menu == NULL);
    listener_destroy(&(*item)->OnClick);

    if ((*item)->hbitmap != NULL)
    {
        BOOL ok = DeleteObject((*item)->hbitmap);
        cassert_unref(ok != 0, ok);
    }

    str_destopt(&(*item)->text);
    heap_delete(item, OSMenuItem);
}

/*---------------------------------------------------------------------------*/

void osmenuitem_OnClick(OSMenuItem *item, Listener *listener)
{
    cassert_no_null(item);
    listener_update(&item->OnClick, listener);
}

/*---------------------------------------------------------------------------*/

static UINT i_item_type(const gui_state_t state)
{
    switch (state)
    {
    case ekGUI_ON:
    case ekGUI_OFF:
        return MFT_STRING;
    case ekGUI_MIXED:
        return MFT_STRING | MFT_RADIOCHECK;
        cassert_default();
    }

    return MFT_STRING;
}

/*---------------------------------------------------------------------------*/

static UINT i_item_state(const gui_state_t state, const bool_t enabled)
{
    UINT ustate = 0;

    if (enabled == TRUE)
        ustate |= MFS_ENABLED;
    else
        ustate |= MFS_DISABLED;

    switch (state)
    {
    case ekGUI_ON:
    case ekGUI_MIXED:
        ustate |= MFS_CHECKED;
        break;
    case ekGUI_OFF:
        ustate |= MFS_UNCHECKED;
        break;
        cassert_default();
    }

    return ustate;
}

/*---------------------------------------------------------------------------*/

void osmenuitem_enabled(OSMenuItem *item, const bool_t enabled)
{
    cassert_no_null(item);
    cassert(item->state != UINT8_MAX);
    if (item->enabled != enabled)
    {
        item->enabled = enabled;
        if (item->menu != NULL && item->visible == TRUE)
        {
            MENUITEMINFO info;
            BOOL ok = FALSE;
            info.fMask = MIIM_STATE;
            info.cbSize = sizeof(MENUITEMINFO);
            info.fState = i_item_state((gui_state_t)item->state, item->enabled);
            ok = SetMenuItemInfo(_osmenu_hmenu(item->menu), item->id, FALSE, &info);
            cassert(ok == TRUE);
        }
    }
}

/*---------------------------------------------------------------------------*/

static void i_item_text(const char_t *text, const vkey_t key, const uint32_t modifiers, WCHAR *item_wtext, const uint32_t max_chars)
{
    char_t item_text[512];

    cassert_no_null(text);
    cassert_no_null(item_text);

    if (key != ENUM_MAX(vkey_t))
    {
        const char_t *mod = "";
        const char_t *wkey = "";
        if (modifiers & ekMKEY_CONTROL)
        {
            if (modifiers & ekMKEY_ALT)
            {
                if (modifiers & ekMKEY_SHIFT)
                    mod = "Ctrl+Alt+Shift+";
                else
                    mod = "Ctrl+Alt+";
            }
            else
            {
                if (modifiers & ekMKEY_SHIFT)
                    mod = "Ctrl+Shift+";
                else
                    mod = "Ctrl+";
            }
        }
        else
        {
            if (modifiers & ekMKEY_ALT)
            {
                if (modifiers & ekMKEY_SHIFT)
                    mod = "Alt+Shift+";
                else
                    mod = "Alt+";
            }
            else
            {
                if (modifiers & ekMKEY_SHIFT)
                    mod = "Shift+";
                else
                    mod = "";
            }
        }

        wkey = i_KEY_TEXT[key];
        bstd_sprintf(item_text, sizeof(item_text), "%s\t%s%s", text, mod, wkey);
    }
    else
    {
        bstd_sprintf(item_text, sizeof(item_text), "%s", text);
    }

    unicode_convers(item_text, (char_t *)item_wtext, ekUTF8, ekUTF16, sizeof(WCHAR) * max_chars);
}

/*---------------------------------------------------------------------------*/

void osmenuitem_visible(OSMenuItem *item, const bool_t visible)
{
    cassert_no_null(item);
    if (item->visible != visible)
    {
        item->visible = visible;
        if (item->menu != NULL)
            _osmenu_recompute(item->menu);
    }
}

/*---------------------------------------------------------------------------*/

void osmenuitem_text(OSMenuItem *item, const char_t *text)
{
    cassert_no_null(item);
    cassert(item->state != UINT8_MAX);
    cassert_no_null(text);
    str_upd(&item->text, text);

    if (item->menu != NULL && item->visible == TRUE)
    {
        WCHAR item_text[512];
        MENUITEMINFO info;
        BOOL ok = FALSE;
        i_item_text(tc(item->text), item->key, item->modifiers, item_text, 512);
        info.cbSize = sizeof(MENUITEMINFO);
        info.fMask = MIIM_STRING;
        info.dwTypeData = item_text;
        ok = SetMenuItemInfo(_osmenu_hmenu(item->menu), item->id, FALSE, &info);
        cassert(ok == TRUE);
    }
}

/*---------------------------------------------------------------------------*/

void osmenuitem_image(OSMenuItem *item, const Image *image)
{
    cassert_no_null(item);

    if (item->hbitmap != NULL)
    {
        BOOL ok = DeleteObject(item->hbitmap);
        cassert_unref(ok != 0, ok);
        item->hbitmap = NULL;
    }

    if (image != NULL)
        item->hbitmap = osimg_hbitmap(image, 0);

    if (item->menu != NULL && item->visible == TRUE)
    {
        MENUITEMINFO info;
        BOOL ok = FALSE;
        info.cbSize = sizeof(MENUITEMINFO);
        info.fMask = MIIM_BITMAP;
        info.hbmpItem = item->hbitmap;
        ok = SetMenuItemInfo(_osmenu_hmenu(item->menu), item->id, FALSE, &info);
        cassert(ok == TRUE);
    }
}

/*---------------------------------------------------------------------------*/

static BYTE i_fvirt(const uint32_t modifiers)
{
    BYTE virt = FVIRTKEY;
    if (modifiers & ekMKEY_CONTROL)
        virt |= FCONTROL;
    if (modifiers & ekMKEY_ALT)
        virt |= FALT;
    if (modifiers & ekMKEY_SHIFT)
        virt |= FSHIFT;
    return virt;
}

/*---------------------------------------------------------------------------*/

void osmenuitem_key(OSMenuItem *item, const uint32_t key, const uint32_t modifiers)
{
    cassert_no_null(item);
    cassert(item->state != UINT8_MAX);
    if (item->key == ENUM_MAX(vkey_t))
    {
        if (key != ENUM_MAX(vkey_t))
            _osgui_add_accelerator(i_fvirt(modifiers), kVIRTUAL_KEY[key], item->id, NULL);
    }
    else
    {
        if (key != ENUM_MAX(vkey_t))
            _osgui_change_accelerator(i_fvirt(modifiers), kVIRTUAL_KEY[key], item->id);
        else
            _osgui_remove_accelerator(item->id);
    }

    item->key = key;
    item->modifiers = modifiers;

    if (item->menu != NULL && item->visible == TRUE)
    {
        WCHAR item_text[512];
        MENUITEMINFO info;
        BOOL ok = FALSE;
        i_item_text(tc(item->text), item->key, item->modifiers, item_text, 512);
        info.cbSize = sizeof(MENUITEMINFO);
        info.fMask = MIIM_STRING;
        info.dwTypeData = item_text;
        ok = SetMenuItemInfo(_osmenu_hmenu(item->menu), item->id, FALSE, &info);
        cassert(ok == TRUE);
    }
}

/*---------------------------------------------------------------------------*/

void osmenuitem_state(OSMenuItem *item, const gui_state_t state)
{
    cassert_no_null(item);
    cassert(item->state != UINT8_MAX);
    if (item->state != (uint8_t)state)
    {
        item->state = state;
        if (item->menu != NULL && item->visible == TRUE)
        {
            MENUITEMINFO info;
            BOOL ok = FALSE;
            info.fMask = MIIM_FTYPE | MIIM_STATE;
            info.cbSize = sizeof(MENUITEMINFO);
            info.fType = i_item_type((gui_state_t)item->state);
            info.fState = i_item_state((gui_state_t)item->state, item->enabled);
            ok = SetMenuItemInfo(_osmenu_hmenu(item->menu), item->id, FALSE, &info);
            cassert(ok == TRUE);
        }
    }
}

/*---------------------------------------------------------------------------*/

void osmenuitem_submenu(OSMenuItem *item, OSMenu *menu)
{
    cassert_no_null(item);
    cassert(item->sub_menu == NULL);
    item->sub_menu = menu;
    _osmenu_attach_to_item(menu, item);
}

/*---------------------------------------------------------------------------*/

void osmenuitem_unset_submenu(OSMenuItem *item, OSMenu *menu)
{
    cassert_no_null(item);
    cassert(item->sub_menu == menu);
    item->sub_menu = NULL;
    _osmenu_detach_from_item(menu, item);
}

/*---------------------------------------------------------------------------*/

void _osmenuitem_insert_in_hmenu(OSMenuItem *item, OSMenu *menu)
{
    cassert_no_null(item);
    cassert(item->menu == NULL);
    item->menu = menu;

    if (item->visible == TRUE)
    {
        MENUITEMINFO info;
        BOOL ok = FALSE;
        cassert_no_null(item);
        info.cbSize = sizeof(MENUITEMINFO);

        if (item->state != UINT8_MAX)
        {
            WCHAR item_text[512];
            i_item_text(tc(item->text), item->key, item->modifiers, item_text, 512);
            info.fMask = MIIM_FTYPE | MIIM_STRING | MIIM_STATE | MIIM_DATA | MIIM_ID;
            info.fType = i_item_type((gui_state_t)item->state);
            info.fState = i_item_state((gui_state_t)item->state, item->enabled);
            info.dwTypeData = item_text;
            info.dwItemData = (ULONG_PTR)item;
            info.wID = item->id;

            if (item->hbitmap != NULL)
            {
                info.fMask |= MIIM_BITMAP;
                info.hbmpItem = item->hbitmap;
            }

            if (item->sub_menu != NULL)
            {
                info.fMask |= MIIM_SUBMENU;
                info.hSubMenu = _osmenu_hmenu(item->sub_menu);
            }
        }
        else
        {
            info.fMask = MIIM_FTYPE | MIIM_ID;
            info.fType = MFT_SEPARATOR;
            info.wID = item->id;
        }

        ok = InsertMenuItem(_osmenu_hmenu(item->menu), item->id, FALSE, &info);
        cassert(ok != 0);
    }
}

/*---------------------------------------------------------------------------*/

bool_t _osmenuitem_remove_from_hmenu(OSMenuItem *item, OSMenu *menu)
{
    bool_t ok = FALSE;
    DWORD err;
    cassert_no_null(item);
    cassert_unref(item->menu == menu, menu);
    ok = (bool_t)RemoveMenu(_osmenu_hmenu(item->menu), item->id, MF_BYCOMMAND);
    err = GetLastError();
    cassert(ok == TRUE);
    item->menu = NULL;
    return ok;
}

/*---------------------------------------------------------------------------*/

static gui_state_t i_state(UINT type, UINT state)
{
    if (type == (MFT_STRING | MFT_RADIOCHECK))
        return ekGUI_MIXED;

    cassert(type == MFT_STRING);

    if ((state & MFS_CHECKED) == MFS_CHECKED)
        return ekGUI_ON;

    cassert((state & MFS_UNCHECKED) == MFS_UNCHECKED);
    return ekGUI_OFF;
}

/*---------------------------------------------------------------------------*/

void _osmenuitem_click(OSMenuItem *item, UINT id, UINT type, UINT state)
{
    cassert_no_null(item);
    cassert_unref(item->id == id, id);
    if (item->OnClick != NULL)
    {
        EvMenu params;
        params.index = UINT32_MAX;
        params.state = i_state(type, state);
        params.text = NULL;
        listener_event(item->OnClick, ekGUI_EVENT_MENU, item, &params, NULL, OSMenuItem, EvMenu, void);
    }
}

/*---------------------------------------------------------------------------*/

void _osmenuitem_image_size(OSMenuItem *item, UINT id, UINT *width, UINT *height)
{
    cassert_no_null(item);
    cassert_unref(item->id == id, id);
    cassert_no_null(width);
    cassert_no_null(height);
    cassert(FALSE);
    /*
    if (item->image != NULL)
    {
        uint32_t im_width, im_height;
        _osimage_size(item->image, &im_width, &im_height);
        *width = (UINT)im_width;
        *height = (UINT)im_height;
    }*/
}

/*---------------------------------------------------------------------------*/

void _osmenuitem_draw_image(OSMenuItem *item, UINT id, UINT state, HDC hdc, const RECT *rect)
{
    cassert_no_null(item);
    cassert_unref(item->id == id, id);
    unref(hdc);
    unref(rect);
    unref(state);

    cassert(FALSE);
    //if (item->image != NULL)
    //{
    //    cassert_no_null(rect);
    //    if ((state & ODS_GRAYED) != 0)
    //    {
    //        UINT w = rect->right - rect->left;
    //        UINT h = rect->bottom - rect->top;
    //        HBITMAP bitmap = _osimage_get_hbitmap(item->image);
    //        HBITMAP hbmMono = CreateBitmap(w, h, 1, 1, NULL);
    //        HDC hdcMono = CreateCompatibleDC(hdc);
    //        HBITMAP hbmPrev = SelectObject(hdcMono, hbmMono);
    //        HDC hdcScreen = CreateCompatibleDC(0);
    //        HBITMAP hcolPrev = SelectObject(hdcScreen, bitmap);

    //        //SetBkColor(hdcScreen, GetSysColor(COLOR_DESKTOP));
    //        BitBlt(hdcMono, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);

    //          //SetTextColor(hdc, RGB(0xFF,0,0));
    //          //SetBkColor(hdc, RGB(0,0x80,0));
    //          BitBlt(hdc, 0, 0, w, h, hdcMono, 0, 0, SRCCOPY);

    //            DeleteDC(hdcScreen);
    //          SelectObject(hdcMono, hbmPrev);
    //          DeleteDC(hdcMono);
    //          DeleteObject(hbmMono);

    //          /*
    //        // Create a monochrome bitmap.
    //     HDC *monoDC = CreateCompatibleDC(0);
    //     HBITMAP *monoBmp = CreateCompatibleBitmap(monoDC, (rect->right - rect->left), (rect->bottom - rect->top));
    //     HBITMAP *oldMonoBmp = SelectObject(monoDC, monoBmp);

    //     colorDC.SetBkColor(GetSysColor(COLOR_BTNHIGHLIGHT));
    //     monoDC.BitBlt(0, 0, size.cx, size.cy, &colorDC, 0, 0, SRCCOPY);*/

    //    }
    //    else
    //    {
    //          SetTextColor(hdc, RGB(0xFF,0,0));
    //          SetBkColor(hdc, RGB(0,0x80,0));
    //        _osimage_draw(item->image, hdc, (uint32_t)(rect->left / 2), (uint32_t)rect->top, (uint32_t)(rect->right - rect->left), (uint32_t)(rect->bottom - rect->top));
    //    }
    //}
}
