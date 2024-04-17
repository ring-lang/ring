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
#include "oswindow_win.inl"
#include "osgui.inl"
#include "osgui_win.inl"
#include "osbutton_win.inl"
#include "oscontrol_win.inl"
#include "ostabstop.inl"
#include "osmenuitem_win.inl"
#include "ospanel_win.inl"
#include <core/arrpt.h>
#include <core/arrst.h>
#include <core/event.h>
#include <core/heap.h>
#include <osbs/osbs.h>
#include <osbs/bthread.h>
#include <sewer/cassert.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

typedef enum _wstate_t
{
    ekNORMAL,
    i_ekSTATE_MANAGED
} wstate_t;

struct _oswindow_t
{
    OSControl control;
    DWORD dwStyle;
    DWORD dwExStyle;
    BOOL bMenu;
    HMENU current_popup_menu;
    HCURSOR cursor;
    bool_t in_user_resizing;
    bool_t in_internal_resize;
    bool_t abort_resize;
    bool_t launch_resize_event;
    bool_t destroy_main_view;
    uint32_t resize_strategy;
    uint32_t flags;
    wstate_t state;
    gui_role_t role;
    OSPanel *main_panel;
    Listener *OnMoved;
    Listener *OnResize;
    Listener *OnClose;
    OSTabStop tabstop;
    ArrSt(OSHotKey) *hotkeys;
};

DeclPt(Listener);

/*---------------------------------------------------------------------------*/

#define i_WM_MODAL_STOP 0x444
static HWND i_CURRENT_ACTIVE_WINDOW = NULL;
static ArrPt(Listener) *i_IDLES = NULL;

/*---------------------------------------------------------------------------*/

static void i_resizing(OSWindow *window, WPARAM edge, RECT *wrect)
{
    cassert_no_null(window);
    cassert_no_null(wrect);
    if (window->launch_resize_event == TRUE)
    {
        if (window->OnResize != NULL)
        {
            RECT rc;
            BOOL ok;
            EvSize params;
            EvSize result;
            SetRectEmpty(&rc);
            ok = AdjustWindowRectEx(&rc, window->dwStyle, window->bMenu, window->dwExStyle);
            cassert_unref(ok != 0, ok);
            params.width = (real32_t)((wrect->right - wrect->left) - (rc.right - rc.left));
            params.height = (real32_t)((wrect->bottom - wrect->top) - (rc.bottom - rc.top));
            listener_event(window->OnResize, ekGUI_EVENT_WND_SIZING, window, &params, &result, OSWindow, EvSize, EvSize);

            rc.left = 0;
            rc.top = 0;
            rc.right = (LONG)result.width;
            rc.bottom = (LONG)result.height;
            ok = AdjustWindowRectEx(&rc, window->dwStyle, window->bMenu, window->dwExStyle);
            cassert_unref(ok != 0, ok);

            switch (edge)
            {
            case WMSZ_RIGHT:
                wrect->right = wrect->left + (rc.right - rc.left);
                break;
            case WMSZ_BOTTOM:
                wrect->bottom = wrect->top + (rc.bottom - rc.top);
                break;
            case WMSZ_LEFT:
                wrect->left = wrect->right - (rc.right - rc.left);
                break;
            case WMSZ_TOP:
                wrect->top = wrect->bottom - (rc.bottom - rc.top);
                break;
            case WMSZ_BOTTOMLEFT:
                wrect->bottom = wrect->top + (rc.bottom - rc.top);
                wrect->left = wrect->right - (rc.right - rc.left);
                break;
            case WMSZ_BOTTOMRIGHT:
                wrect->bottom = wrect->top + (rc.bottom - rc.top);
                wrect->right = wrect->left + (rc.right - rc.left);
                break;
            case WMSZ_TOPLEFT:
                wrect->top = wrect->bottom - (rc.bottom - rc.top);
                wrect->left = wrect->right - (rc.right - rc.left);
                break;
            case WMSZ_TOPRIGHT:
                wrect->top = wrect->bottom - (rc.bottom - rc.top);
                wrect->right = wrect->left + (rc.right - rc.left);
                break;
            default:
                break;
            }
        }
    }
}

/*---------------------------------------------------------------------------*/

static void i_resize(OSWindow *window, LONG width, LONG height)
{
    cassert_no_null(window);
    if (window->launch_resize_event == TRUE)
    {
        if (window->OnResize != NULL)
        {
            RECT rect;
            BOOL ok;
            EvSize params;
            rect.left = 0;
            rect.top = 0;
            rect.right = width;
            rect.bottom = height;
            ok = AdjustWindowRectEx(&rect, window->dwStyle, window->bMenu, window->dwExStyle);
            cassert_unref(ok != 0, ok);
            params.width = (real32_t)width;
            params.height = (real32_t)height;
            listener_event(window->OnResize, ekGUI_EVENT_WND_SIZE, window, &params, NULL, OSWindow, EvSize, void);
        }
    }
}

/*---------------------------------------------------------------------------*/

static void i_moved(OSWindow *window, const int16_t content_x, const int16_t content_y)
{
    cassert_no_null(window);
    if (window->OnMoved != NULL)
    {
        RECT rect;
        BOOL ok;
        EvPos params;
        rect.left = content_x;
        rect.top = content_y;
        rect.right = content_x + 100;
        rect.bottom = content_y + 100;
        ok = AdjustWindowRectEx(&rect, window->dwStyle, window->bMenu, window->dwExStyle);
        cassert_unref(ok != 0, ok);
        params.x = (real32_t)(rect.left);
        params.y = (real32_t)(rect.top);
        listener_event(window->OnMoved, ekGUI_EVENT_WND_MOVED, window, &params, NULL, OSWindow, EvPos, void);
    }
}

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

    return closed;
}

/*---------------------------------------------------------------------------*/

static void i_menu_command(HWND hwnd, HMENU popup_hmenu, WORD command_id)
{
    MENUITEMINFO info = {0};
    HMENU hmenu = NULL;
    BOOL ok = FALSE;
    info.cbSize = sizeof(MENUITEMINFO);
    info.fMask = MIIM_DATA | MIIM_ID | MIIM_FTYPE | MIIM_STATE;

    hmenu = GetMenu(hwnd);
    if (hmenu != NULL)
        ok = GetMenuItemInfo(hmenu, command_id, MF_BYCOMMAND, &info);

    if (ok == FALSE && popup_hmenu != NULL)
        ok = GetMenuItemInfo(popup_hmenu, command_id, MF_BYCOMMAND, &info);

    /* Command from accelerator without active menu doesn't send event */
    if (ok == TRUE)
    {
        cassert(info.wID == command_id);
        _osmenuitem_click((OSMenuItem *)info.dwItemData, info.wID, info.fType, info.fState);
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_press_defbutton(OSWindow *window)
{
    cassert_no_null(window);
    if (window->tabstop.defbutton != NULL)
    {
        HWND button_hwnd = OSControlPtr(window->tabstop.defbutton)->hwnd;
        /* Simulates the click hightlight */
        SendMessage(button_hwnd, BM_SETSTATE, 1, 0);
        SendMessage(button_hwnd, WM_PAINT, 0, 0);
        _osbutton_command(window->tabstop.defbutton, (WPARAM)MAKELONG(0, BN_CLICKED), FALSE);
        bthread_sleep(100);
        SendMessage(button_hwnd, BM_SETSTATE, 0, 0);
        SendMessage(button_hwnd, WM_PAINT, 0, 0);
        return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static void i_activate(OSWindow *window)
{
    cassert_no_null(window);
    /* Force the tabstop because 'WM_ACTIVATE' is not send if hwnd is the current active */
    SetActiveWindow(window->control.hwnd);
    ostabstop_restore(&window->tabstop);
}

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    OSWindow *window = (OSWindow *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(window);

    switch (msg)
    {
    case WM_ACTIVATE:
        if (LOWORD(wParam) == WA_ACTIVE || LOWORD(wParam) == WA_CLICKACTIVE)
        {
            i_CURRENT_ACTIVE_WINDOW = hwnd;
            ostabstop_restore(&window->tabstop);
        }
        else
        {
            cassert(LOWORD(wParam) == WA_INACTIVE);
            if (window->role == ekGUI_ROLE_OVERLAY)
            {
                if (i_close(window, ekGUI_CLOSE_DEACT) == TRUE)
                    window->role = ENUM_MAX(gui_role_t);
            }

            i_CURRENT_ACTIVE_WINDOW = NULL;
        }

        return 0;

    case WM_COMMAND:
        /* COMMAND by Control */
        if (lParam != 0)
        {
            /* Press enter when a button has de focus */
            OSControl *control = (OSControl *)GetWindowLongPtr((HWND)lParam, GWLP_USERDATA);
            cassert_no_null(control);
            cassert(control->type == ekGUI_TYPE_BUTTON);
            _osbutton_command((OSButton *)control, wParam, TRUE);
            return 0;
        }

        /* COMMAND by Menu */
        if (HIWORD(wParam) == 0)
        {
            /* DialogBox "Menu" Commands? */
            switch (LOWORD(wParam))
            {
            case IDCANCEL:
            {
                i_close(window, ekGUI_CLOSE_ESC);
                return TRUE;
            }

            case IDOK:
                i_press_defbutton(window);
                i_close(window, ekGUI_CLOSE_INTRO);
                return 0;
            }

            /* Menu Click */
            i_menu_command(hwnd, window->current_popup_menu, LOWORD(wParam));
            return 0;
        }
        /* COMMAND by Accelerator */
        else
        {
            WORD cmd = LOWORD(wParam);
            HWND ahwnd = _osgui_hwnd_accelerator(cmd);
            cassert(HIWORD(wParam) == 1);
            if (ahwnd != NULL)
            {
                /* Accelerator from button */
                OSControl *control = (OSControl *)GetWindowLongPtr(ahwnd, GWLP_USERDATA);
                DWORD nwParam = MAKELONG(cmd, BN_CLICKED);
                /* Simulates the click hightlight */
                SendMessage(control->hwnd, BM_SETSTATE, 1, 0);
                SendMessage(control->hwnd, WM_PAINT, 0, 0);
                bthread_sleep(100);
                _osbutton_toggle((OSButton *)control);
                SendMessage(control->hwnd, BM_SETSTATE, 0, 0);
                SendMessage(control->hwnd, WM_PAINT, 0, 0);
                _osbutton_command((OSButton *)control, nwParam, TRUE);
            }
            else
            {
                /* Accelerator from menu */
                i_menu_command(hwnd, window->current_popup_menu, LOWORD(wParam));
            }

            return 0;
        }

    case WM_PAINT:
        if (window->in_internal_resize == TRUE)
            return 0;
        break;

    case WM_SIZING:
        if (window->resize_strategy > 0 && window->in_user_resizing == TRUE)
        {
            cassert(FALSE);
            if (window->in_internal_resize == FALSE)
            {
                window->in_internal_resize = TRUE;
                ShowWindow(((OSControl *)window->main_panel)->hwnd, SW_HIDE);
            }
        }

        i_resizing(window, wParam, (RECT *)lParam);
        return TRUE;

    case WM_ENTERSIZEMOVE:
        window->in_user_resizing = TRUE;
        break;

    case WM_EXITSIZEMOVE:
        if (window->in_internal_resize == TRUE)
            ShowWindow(((OSControl *)window->main_panel)->hwnd, SW_SHOW);
        window->in_user_resizing = FALSE;
        window->in_internal_resize = FALSE;
        break;

    case WM_SIZE:
        if (IsWindowVisible(window->control.hwnd) == FALSE)
            return 0;

        if (window->abort_resize == TRUE)
        {
            window->abort_resize = FALSE;
            return 0;
        }

        if (wParam == SIZE_MINIMIZED)
            return 0;

        if (window->in_internal_resize == TRUE)
        {
            HDC memHdc = NULL;
            LONG width, height;
            HDC hdc;
            cassert(FALSE);
            _ospanel_resize_double_buffer(window->main_panel, LOWORD(lParam), HIWORD(lParam));
            memHdc = _ospanel_paint_double_buffer(window->main_panel, window->resize_strategy, &width, &height);
            hdc = GetDC(window->control.hwnd);
            BitBlt(hdc, 0, 0, (int)width, (int)height, memHdc, 0, 0, SRCCOPY);
            ReleaseDC(window->control.hwnd, hdc);
        }

        {
            RECT rect;
            BOOL ok;
            rect.left = 0;
            rect.top = 0;
            rect.right = LOWORD(lParam);
            rect.bottom = HIWORD(lParam);
            ok = AdjustWindowRectEx(&rect, window->dwStyle, window->bMenu, window->dwExStyle);
            cassert(ok != 0);
            i_resizing(window, 1, &rect);
        }

        if (window->resize_strategy == 0)
            window->in_internal_resize = TRUE;

        i_resize(window, LOWORD(lParam), HIWORD(lParam));

        if (window->resize_strategy == 0)
            window->in_internal_resize = FALSE;

        return 0;

    case WM_MOVE:
        i_moved(window, (int16_t)LOWORD(lParam), (int16_t)HIWORD(lParam));
        return 0;

    case WM_CLOSE:
        i_close(window, ekGUI_CLOSE_BUTTON);
        return 0;

    case WM_MEASUREITEM:
    {
        MEASUREITEMSTRUCT *mi = (MEASUREITEMSTRUCT *)lParam;
        /* Sent by menu */
        cassert((UINT)wParam == 0);
        cassert_no_null(mi);
        cassert(mi->CtlType == ODT_MENU);
        _osmenuitem_image_size((OSMenuItem *)mi->itemData, mi->itemID, &mi->itemWidth, &mi->itemHeight);
        return TRUE;
    }

    case WM_DRAWITEM:
    {
        DRAWITEMSTRUCT *di = (DRAWITEMSTRUCT *)lParam;
        /* Sent by menu */
        cassert((UINT)wParam == 0);
        cassert_no_null(di);
        cassert(di->CtlType == ODT_MENU);
        _osmenuitem_draw_image((OSMenuItem *)di->itemData, di->itemID, di->itemState, di->hDC, &di->rcItem);
        return TRUE;
    }

    case WM_SETCURSOR:
        if (window->cursor != NULL)
        {
            SetCursor(window->cursor);
            return TRUE;
        }
        break;

    case i_WM_MODAL_STOP:
        PostQuitMessage((int)wParam);
        return 0;
    }

    return CallWindowProc(window->control.def_wnd_proc, hwnd, msg, wParam, lParam);
}

/*---------------------------------------------------------------------------*/

static void i_window_style(const window_flag_t flags, DWORD *dwStyle, DWORD *dwExStyle)
{
    cassert_no_null(dwStyle);
    cassert_no_null(dwExStyle);

    *dwStyle = 0 | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
    *dwExStyle = 0;

    if (flags & ekWINDOW_EDGE)
        *dwStyle |= WS_BORDER;

    if (flags & ekWINDOW_TITLE)
    {
        *dwStyle |= WS_CAPTION | WS_DLGFRAME | WS_OVERLAPPED;
        *dwExStyle |= WS_EX_DLGMODALFRAME;
    }

    if (flags & ekWINDOW_CLOSE)
        *dwStyle |= WS_SYSMENU;

    if (flags & ekWINDOW_MAX)
        *dwStyle |= WS_MAXIMIZEBOX | WS_SYSMENU;

    if (flags & ekWINDOW_MIN)
        *dwStyle |= WS_MINIMIZEBOX | WS_SYSMENU;

    if (flags & ekWINDOW_RESIZE)
        *dwStyle |= WS_THICKFRAME;
}

/*---------------------------------------------------------------------------*/

OSWindow *oswindow_create(const uint32_t flags)
{
    OSWindow *window = heap_new0(OSWindow);
    window->control.type = ekGUI_TYPE_WINDOW;
    i_window_style(flags, &window->dwStyle, &window->dwExStyle);
    _oscontrol_init_hidden((OSControl *)window, window->dwExStyle, window->dwStyle | WS_POPUP, kWINDOW_CLASS, 0, 0, i_WndProc, GetDesktopWindow());
    window->launch_resize_event = TRUE;
    window->destroy_main_view = TRUE;
    window->flags = flags;
    window->state = ekNORMAL;
    window->role = ENUM_MAX(gui_role_t);
    ostabstop_init(&window->tabstop, window);

    {
        HICON icon = LoadIcon(_osgui_instance(), L"APPLICATION_ICON");
        if (icon != NULL)
        {
            SendMessage(window->control.hwnd, WM_SETICON, ICON_BIG, (LPARAM)icon);
            SendMessage(window->control.hwnd, WM_SETICON, ICON_SMALL, (LPARAM)icon);
        }
    }

    return window;
}

/*---------------------------------------------------------------------------*/

OSWindow *oswindow_managed(void *native_ptr)
{
    OSWindow *window = heap_new(OSWindow);
    cassert_no_null(native_ptr);
    window->control.type = ekGUI_TYPE_WINDOW;
    window->control.hwnd = (HWND)native_ptr;
    window->control.def_wnd_proc = NULL;
    window->launch_resize_event = TRUE;
    window->state = i_ekSTATE_MANAGED;
    window->role = ENUM_MAX(gui_role_t);
    window->destroy_main_view = TRUE;
    return window;
}

/*---------------------------------------------------------------------------*/

void oswindow_destroy(OSWindow **window)
{
    cassert_no_null(window);
    cassert_no_null(*window);
    if ((*window)->destroy_main_view == TRUE && (*window)->main_panel != NULL)
    {
        OSPanel *panel = (*window)->main_panel;
        oswindow_detach_panel(*window, panel);
        _ospanel_destroy(&panel);
    }

    cassert((*window)->main_panel == NULL);
    cassert(_oscontrol_num_children(OSControlPtr(*window)) == 0);
    listener_destroy(&(*window)->OnMoved);
    listener_destroy(&(*window)->OnResize);
    listener_destroy(&(*window)->OnClose);
    oswindow_hotkey_destroy(&(*window)->hotkeys);
    ostabstop_remove(&(*window)->tabstop);

    if ((*window)->state != i_ekSTATE_MANAGED)
        _oscontrol_destroy((OSControl *)(*window));

    heap_delete(window, OSWindow);
}

/*---------------------------------------------------------------------------*/

void oswindow_OnMoved(OSWindow *window, Listener *listener)
{
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    listener_update(&window->OnMoved, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_OnResize(OSWindow *window, Listener *listener)
{
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    listener_update(&window->OnResize, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_OnClose(OSWindow *window, Listener *listener)
{
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    listener_update(&window->OnClose, listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_title(OSWindow *window, const char_t *text)
{
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    _oscontrol_set_text((OSControl *)window, text);
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
    HWND parent = NULL;
    cassert_no_null(window);
    cassert(FALSE);
    cassert(window->state != i_ekSTATE_MANAGED);

    if (below_window != NULL)
        parent = below_window->control.hwnd;

    SetWindowLongPtr(window->control.hwnd, GWLP_HWNDPARENT, (LONG_PTR)parent);
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
    cassert(window->state != i_ekSTATE_MANAGED);
    ostabstop_list_add(&window->tabstop, control);
    if (control == NULL)
    {
        /* The window main panel has changed. We ensure that default button is still valid */
        window->tabstop.defbutton = oswindow_apply_default_button(window, window->tabstop.defbutton);

        /* Force to show the focus rectangle in all controls */
        /* https://stackoverflow.com/questions/46489537/focus-rectangle-not-showing-even-if-control-has-focus */
        SendMessage(window->control.hwnd, WM_UPDATEUISTATE, MAKEWPARAM(UIS_CLEAR, UISF_HIDEFOCUS | UISF_HIDEACCEL), (LPARAM)NULL);
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
    cassert(window->state != i_ekSTATE_MANAGED);
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
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    cassert(window->main_panel == NULL);
    _oscontrol_attach_to_parent((OSControl *)panel, (OSControl *)window);
    window->main_panel = panel;
}

/*---------------------------------------------------------------------------*/

void oswindow_detach_panel(OSWindow *window, OSPanel *panel)
{
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    cassert(window->main_panel == panel);
    _oscontrol_detach_from_parent((OSControl *)panel, (OSControl *)window);
    window->main_panel = NULL;
}

/*---------------------------------------------------------------------------*/

void oswindow_attach_window(OSWindow *parent_window, OSWindow *child_window)
{
    //HWND prevParent = 0;
    unref(parent_window);
    unref(child_window);
    /*prevParent = SetParent(child_window->control.hwnd, parent_window->control.hwnd);
    unref(prevParent);
    prevParent = GetParent(child_window->control.hwnd);*/
    //SetWindowLong(child_window->control.hwnd, GWL_STYLE, child_window->dwStyle | WS_CHILD);
    //SetWindowLong(child_window->control.hwnd, GWL_EXSTYLE, child_window->dwExStyle);
    //oswindow_set_z_order(child_window, parent_window);
}

/*---------------------------------------------------------------------------*/

void oswindow_detach_window(OSWindow *parent_window, OSWindow *child_window)
{
    //HWND prevParent = 0;
    unref(parent_window);
    unref(child_window);
    /* cassert_no_null(parent_window);
	cassert_no_null(child_window);
    prevParent = SetParent(child_window->control.hwnd, GetDesktopWindow());
    cassert(prevParent == parent_window->control.hwnd);*/
    /*SetWindowLong(child_window->control.hwnd, GWL_STYLE, child_window->dwStyle);
    SetWindowLong(child_window->control.hwnd, GWL_EXSTYLE, child_window->dwExStyle);*/
}

/*---------------------------------------------------------------------------*/

void oswindow_launch(OSWindow *window, OSWindow *parent_window)
{
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    if (!(window->flags & ekWINDOW_OFFSCREEN))
    {
        if (parent_window != NULL)
        {
            SetWindowPos(window->control.hwnd, parent_window->control.hwnd, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
            window->role = ekGUI_ROLE_OVERLAY;
        }
        else
        {
            window->role = ekGUI_ROLE_MAIN;
        }

        window->launch_resize_event = FALSE;
        _oscontrol_set_visible((OSControl *)window, TRUE);
        window->launch_resize_event = TRUE;

        i_activate(window);
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_hide(OSWindow *window, OSWindow *parent_window)
{
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    unref(parent_window);
    window->role = ENUM_MAX(gui_role_t);
    window->launch_resize_event = FALSE;
    _oscontrol_set_visible((OSControl *)window, FALSE);
    window->launch_resize_event = TRUE;
}

/*---------------------------------------------------------------------------*/

uint32_t oswindow_launch_modal(OSWindow *window, OSWindow *parent_window)
{
    uint32_t ret = UINT32_MAX;

    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);

    if (parent_window != NULL)
    {
        SetWindowLongPtr(window->control.hwnd, GWLP_HWNDPARENT, (LONG_PTR)parent_window->control.hwnd);
        _oscontrol_set_enabled((OSControl *)parent_window, FALSE);
    }

    window->role = ekGUI_ROLE_MODAL;
    window->launch_resize_event = FALSE;
    _oscontrol_set_visible((OSControl *)window, TRUE);
    window->launch_resize_event = TRUE;
    i_activate(window);

    /* Wait until the window is closed */
    ret = _oswindow_message_loop(window);

    if (parent_window != NULL)
    {
        _oscontrol_set_enabled((OSControl *)parent_window, TRUE);

        if (!(window->flags & ekWINDOW_MODAL_NOHIDE))
        {
            SetWindowLongPtr(window->control.hwnd, GWLP_HWNDPARENT, (LONG_PTR)GetDesktopWindow());
            SetWindowPos(parent_window->control.hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }

        i_activate(parent_window);
    }

    return ret;
}

/*---------------------------------------------------------------------------*/

void oswindow_stop_modal(OSWindow *window, const uint32_t return_value)
{
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    SendMessage(window->control.hwnd, i_WM_MODAL_STOP, (WPARAM)return_value, (LPARAM)0);
    window->role = ENUM_MAX(gui_role_t);
}

/*---------------------------------------------------------------------------*/

void oswindow_get_origin(const OSWindow *window, real32_t *x, real32_t *y)
{
    cassert_no_null(window);
    cassert_no_null(x);
    cassert_no_null(y);
    /* The window top-left corner */
    if (*x == REAL32_MAX && *y == REAL32_MAX)
    {
        RECT rect;
        _osgui_frame_without_shadows(window->control.hwnd, &rect);
        *x = (real32_t)rect.left;
        *y = (real32_t)rect.top;
    }
    /* A window inner point (in client area coordinates) */
    else
    {
        POINT pt;
        pt.x = (LONG)*x;
        pt.y = (LONG)*y;
        ClientToScreen(window->control.hwnd, &pt);
        *x = (real32_t)pt.x;
        *y = (real32_t)pt.y;
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_origin(OSWindow *window, const real32_t x, const real32_t y)
{
    RECT rect1;
    RECT rect2;
    cassert_no_null(window);

    {
        BOOL ret = GetWindowRect(window->control.hwnd, &rect1);
        cassert_unref(ret != 0, ret);
    }

    _osgui_frame_without_shadows(window->control.hwnd, &rect2);

    {
        BOOL ret = SetWindowPos(window->control.hwnd, NULL, (int)x + (rect1.left - rect2.left), (int)y + (rect1.top - rect2.top), 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        cassert_unref(ret != 0, ret);
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_get_size(const OSWindow *window, real32_t *width, real32_t *height)
{
    RECT rect;
    cassert_no_null(window);
    cassert_no_null(width);
    cassert_no_null(height);
    _osgui_frame_without_shadows(window->control.hwnd, &rect);
    *width = (real32_t)(rect.right - rect.left);
    *height = (real32_t)(rect.bottom - rect.top);
}

/*---------------------------------------------------------------------------*/

void oswindow_size(OSWindow *window, const real32_t content_width, const real32_t content_height)
{
    RECT rect;
    BOOL ok;
    cassert_no_null(window);
    cassert(window->state != i_ekSTATE_MANAGED);
    rect.left = 0;
    rect.top = 0;
    rect.right = (LONG)content_width;
    rect.bottom = (LONG)content_height;
    ok = AdjustWindowRectEx(&rect, window->dwStyle, window->bMenu, window->dwExStyle);
    cassert_unref(ok != 0, ok);
    window->launch_resize_event = FALSE;
    ok = SetWindowPos(window->control.hwnd, NULL, 0, 0, (int)(rect.right - rect.left), (int)(rect.bottom - rect.top), SWP_NOMOVE | SWP_NOZORDER);
    cassert_unref(ok != 0, ok);
    window->launch_resize_event = TRUE;
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
    cassert_no_null(window);
    window->cursor = (HCURSOR)cursor;
}

/*---------------------------------------------------------------------------*/

void oswindow_property(OSWindow *window, const gui_prop_t property, const void *value)
{
    cassert_no_null(window);
    if (property == ekGUI_PROP_RESIZE)
    {
        cassert_no_null(value);
        window->resize_strategy = *((uint32_t *)value);
    }
    else if (property == ekGUI_PROP_CHILDREN)
    {
        window->destroy_main_view = FALSE;
    }
}

/*---------------------------------------------------------------------------*/

void oswindow_widget_set_focus(OSWindow *window, OSWidget *widget)
{
    unref(window);
    cassert_no_null(widget);
    SetFocus((HWND)widget);
}

/*---------------------------------------------------------------------------*/

static BOOL CALLBACK i_get_controls(HWND hwnd, LPARAM lParam)
{
    OSControl *control = OSControlPtr(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    if (control != NULL)
    {
        ArrPt(OSControl) *controls = (ArrPt(OSControl) *)lParam;
        if (arrpt_find(controls, control, OSControl) == UINT32_MAX)
            arrpt_append(controls, control, OSControl);
    }

    EnumChildWindows(hwnd, i_get_controls, lParam);
    return TRUE;
}

/*---------------------------------------------------------------------------*/

void oswindow_find_all_controls(OSWindow *window, ArrPt(OSControl) *controls)
{
    cassert_no_null(window);
    cassert(arrpt_size(controls, OSControl) == 0);
    EnumChildWindows(window->control.hwnd, i_get_controls, (LPARAM)controls);
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
    cassert(FALSE);
    unref(app);
    unref(icon);
}

/*---------------------------------------------------------------------------*/

void oswindow_set_app_terminate(void)
{
    cassert(FALSE);
}

/*---------------------------------------------------------------------------*/

void _oswindow_destroy_idles(void)
{
    arrpt_destopt(&i_IDLES, listener_destroy, Listener);
}

/*---------------------------------------------------------------------------*/

static void i_adjust_menu_size(OSWindow *window)
{
    RECT rect;
    BOOL ok = FALSE;
    cassert_no_null(window);
    ok = GetClientRect(window->control.hwnd, &rect);
    cassert_unref(ok != 0, ok);
    ok = AdjustWindowRectEx(&rect, window->dwStyle, window->bMenu, window->dwExStyle);
    cassert_unref(ok != 0, ok);
    SetWindowPos(window->control.hwnd, NULL, 0, 0, (int)(rect.right - rect.left), (int)(rect.bottom - rect.top), SWP_NOMOVE | SWP_NOZORDER);
}

/*---------------------------------------------------------------------------*/

void _oswindow_set_menubar(OSWindow *window, HMENU hmenu)
{
    BOOL ok = FALSE;
    cassert_no_null(window);
    cassert_no_null(hmenu);
    cassert(window->bMenu == FALSE);
    cassert(GetMenu(window->control.hwnd) == NULL);
    window->bMenu = TRUE;
    i_adjust_menu_size(window);
    ok = SetMenu(window->control.hwnd, hmenu);
    cassert_unref(ok == TRUE, ok);
    cassert(GetMenu(window->control.hwnd) == hmenu);
}

/*---------------------------------------------------------------------------*/

void _oswindow_unset_menubar(OSWindow *window, HMENU hmenu)
{
    BOOL ok = FALSE;
    cassert_no_null(window);
    cassert_unref(GetMenu(window->control.hwnd) == hmenu, hmenu);
    cassert(window->bMenu == TRUE);
    window->bMenu = FALSE;
    i_adjust_menu_size(window);
    ok = SetMenu(window->control.hwnd, NULL);
    cassert_unref(ok == TRUE, ok);
    cassert(GetMenu(window->control.hwnd) == NULL);
}

/*---------------------------------------------------------------------------*/

void _oswindow_change_menubar(OSWindow *window, HMENU prev_hmenu, HMENU new_hmenu)
{
    BOOL ok = FALSE;
    cassert_no_null(window);
    cassert_no_null(prev_hmenu);
    cassert_no_null(new_hmenu);
    cassert(window->bMenu == TRUE);
    cassert(GetMenu(window->control.hwnd) == prev_hmenu);
    ok = SetMenu(window->control.hwnd, new_hmenu);
    cassert(ok == TRUE);
    cassert(GetMenu(window->control.hwnd) == new_hmenu);
}

/*---------------------------------------------------------------------------*/

HWND _oswindow_set_current_popup_menu(OSWindow *window, HMENU hmenu)
{
    cassert_no_null(window);
    window->current_popup_menu = hmenu;
    return window->control.hwnd;
}

/*---------------------------------------------------------------------------*/

HWND _oswindow_hwnd(OSWindow *window)
{
    if (window != NULL)
        return window->control.hwnd;
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

void _oswindow_OnIdle(Listener *listener)
{
    if (i_IDLES == NULL)
        i_IDLES = arrpt_create(Listener);

    arrpt_append(i_IDLES, listener, Listener);
}

/*---------------------------------------------------------------------------*/

static OSWindow *i_get_window(HWND hwnd)
{
    OSWindow *window = NULL;
    while (window == NULL && hwnd != NULL)
    {
        window = (OSWindow *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
        if (window != NULL)
        {
            if (window->control.type != ekGUI_TYPE_WINDOW)
                window = NULL;
        }

        if (window == NULL)
            hwnd = GetParent(hwnd);
    }

    return window;
}

/*---------------------------------------------------------------------------*/

static BOOL i_IsDialogMessage(HWND hDlg, LPMSG lpMsg)
{
    OSWindow *window = NULL;
    cassert_no_null(lpMsg);
    window = i_get_window(lpMsg->hwnd);

    if (window != NULL)
    {
        if (lpMsg->message == WM_KEYDOWN)
        {
            if (lpMsg->wParam == VK_TAB)
            {
                if (window->control.hwnd == hDlg)
                {
                    SHORT lshif_state = GetAsyncKeyState(VK_LSHIFT);
                    SHORT rshif_state = GetAsyncKeyState(VK_RSHIFT);
                    BOOL previous = ((0x8000 & lshif_state) != 0) || ((0x8000 & rshif_state) != 0);
                    if (previous == TRUE)
                        ostabstop_prev(&window->tabstop, TRUE);
                    else
                        ostabstop_next(&window->tabstop, TRUE);
                    return TRUE;
                }
            }
            else if (lpMsg->wParam == VK_RETURN)
            {
                bool_t def = i_press_defbutton(window);

                if (window->flags & ekWINDOW_RETURN)
                {
                    i_close(window, ekGUI_CLOSE_INTRO);
                    return TRUE;
                }

                if (def == TRUE)
                    return TRUE;
            }
            else if (lpMsg->wParam == VK_ESCAPE)
            {
                if (window->flags & ekWINDOW_ESC)
                {
                    i_close(window, ekGUI_CLOSE_ESC);
                    return TRUE;
                }
            }

            /* Check hotkeys */
            if (window->hotkeys != NULL)
            {
                vkey_t key = _osgui_vkey((WORD)lpMsg->wParam);
                uint32_t modifiers = _osgui_modifiers();
                if (oswindow_hotkey_process(window, window->hotkeys, key, modifiers) == TRUE)
                    return TRUE;
            }
        }
        else if (lpMsg->message == WM_SETFOCUS)
        {
            /*
            arrpt_foreach(tabstop, window->tabstops, OSControl)
            {
                if (tabstop->hwnd == lpMsg->hwnd)
                {
                    window->ctabstop = tabstop;
                    break;
                }
            }
            arrpt_end()
            */
        }
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_message(MSG *msg, HACCEL accelerator_table)
{
    cassert_no_null(msg);

    if (msg->message == WM_TIMER)
        return FALSE;

    if (i_CURRENT_ACTIVE_WINDOW != NULL)
    {
        BOOL accelerator_message = FALSE;

        if (accelerator_table != NULL)
            accelerator_message = TranslateAccelerator(i_CURRENT_ACTIVE_WINDOW, accelerator_table, msg);

        if (accelerator_message == TRUE)
        {
            return TRUE;
        }
        else
        {
            if (i_IsDialogMessage(i_CURRENT_ACTIVE_WINDOW, msg) != 0)
                return TRUE;
            else
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

uint32_t _oswindow_message_loop(OSWindow *window)
{
    MSG msg;
    for (;;)
    {
        BOOL doidle = FALSE;
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            HACCEL accel = _osgui_accel_table();

            if (msg.message == WM_QUIT)
                return (uint32_t)msg.wParam;

            /* This is the message loop for a modal window */
            if (window != NULL)
            {
                /*
                   The active window in the app can change in Alt+Tab navigation.
                   Will this we ensure the correct message processing
                */
                if (GetActiveWindow() != window->control.hwnd)
                    i_activate(window);
            }

            if (i_message((void *)&msg, accel) == FALSE)
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            doidle = TRUE;
        }

        if (doidle == TRUE)
        {
            if (i_IDLES != NULL)
            {
                if (arrpt_size(i_IDLES, Listener) > 0)
                {
                    Listener *idle = arrpt_first(i_IDLES, Listener);
                    arrpt_delete(i_IDLES, 0, NULL, Listener);
                    listener_event(idle, ekGUI_EVENT_IDLE, NULL, NULL, NULL, void, void, void);
                    listener_destroy(&idle);
                }
            }
        }
        else
        {
            /* Doesn't return until a message posted */
            WaitMessage();
        }
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE OSWindow *i_root(HWND hwnd)
{
    HWND root_hwnd = NULL;
    cassert_no_null(hwnd);
    root_hwnd = GetAncestor(hwnd, GA_ROOT);
    cassert_no_null(root_hwnd);
    return (OSWindow *)GetWindowLongPtr(root_hwnd, GWLP_USERDATA);
}

/*---------------------------------------------------------------------------*/

bool_t _oswindow_in_resizing(HWND child_hwnd)
{
    OSWindow *window = i_root(child_hwnd);
    cassert_no_null(window);
    return window->in_internal_resize;
}

/*---------------------------------------------------------------------------*/

bool_t _oswindow_mouse_down(OSControl *control)
{
    OSWindow *window = NULL;
    cassert_no_null(control);
    window = i_root(control->hwnd);
    cassert_no_null(window);
    return ostabstop_mouse_down(&window->tabstop, control);
}

/*---------------------------------------------------------------------------*/

void _oswindow_release_transient_focus(OSControl *control)
{
    OSWindow *window = NULL;
    cassert_no_null(control);
    window = i_root(control->hwnd);
    cassert_no_null(window);
    ostabstop_release_transient(&window->tabstop, control);
}
