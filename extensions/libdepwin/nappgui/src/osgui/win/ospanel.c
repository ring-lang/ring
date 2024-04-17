/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospanel.c
 *
 */

/* Operating System native panel */

#include "ospanel.h"
#include "ospanel.inl"
#include "osgui_win.inl"
#include "oscontrol_win.inl"
#include "osbutton_win.inl"
#include "oscombo_win.inl"
#include "osedit_win.inl"
#include "oslabel_win.inl"
#include "ospopup_win.inl"
#include "osslider_win.inl"
#include "osscroll_win.inl"
#include "ostext_win.inl"
#include "osupdown_win.inl"
#include "oscontrol.inl"
#include "osscrolls.inl"
#include <draw2d/color.h>
#include <core/arrst.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

typedef struct _area_t Area;

struct _area_t
{
    void *obj;
    RECT rect;
    HBRUSH bgbrush;
    COLORREF bgcolor;
    HBRUSH skbrush;
};

struct _ospanel_t
{
    OSControl control;
    OSScrolls *scroll;
    HDC memhdc;
    HBITMAP dbuffer;
    uint32_t flags;
    RECT border;
    ArrSt(Area) *areas;
};

DeclSt(Area);

/*---------------------------------------------------------------------------*/

static void i_remove_area(Area *area)
{
    cassert_no_null(area);
    _oscontrol_destroy_brush(&area->bgbrush);
    _oscontrol_destroy_brush(&area->skbrush);
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_area(HDC hdc, const Area *area)
{
    cassert_no_null(area);
    if (area->bgbrush != NULL)
    {
        FillRect(hdc, &area->rect, area->bgbrush);
    }
    else
    {
        HBRUSH defbrush = GetSysColorBrush(COLOR_3DFACE);
        FillRect(hdc, &area->rect, defbrush);
    }

    if (area->skbrush != NULL)
    {
        FrameRect(hdc, &area->rect, area->skbrush);
    }
}

/*---------------------------------------------------------------------------*/

static HBRUSH i_brush(OSControl *control, const ArrSt(Area) *areas, COLORREF *c)
{
    OSFrame rect;
    RECT rc;
    oscontrol_frame(control, &rect);
    rc.left = rect.left;
    rc.right = rect.right;
    rc.top = rect.top;
    rc.bottom = rect.bottom;

    arrst_forback_const(area, areas, Area)
        {
            RECT inter;
            if (IntersectRect(&inter, &area->rect, &rc) == TRUE)
            {
                if (area->bgbrush != NULL)
                {
                    ptr_assign(c, area->bgcolor);
                    return area->bgbrush;
                }
            }
        }
    arrst_end()
    return NULL;
}

/*---------------------------------------------------------------------------*/

static LRESULT CALLBACK i_WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSPanel *panel = (OSPanel *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(panel);

    switch (uMsg)
    {
    case WM_COMMAND:
    {
        OSControl *control = (OSControl *)GetWindowLongPtr((HWND)lParam, GWLP_USERDATA);
        cassert_no_null(control);
        switch (control->type)
        {
        case ekGUI_TYPE_BUTTON:
            _osbutton_command((OSButton *)control, wParam, TRUE);
            break;

        case ekGUI_TYPE_EDITBOX:
            _osedit_command((OSEdit *)control, wParam);
            break;

        case ekGUI_TYPE_TEXTVIEW:
            _ostext_command((OSText *)control, wParam);
            break;

        case ekGUI_TYPE_POPUP:
            _ospopup_command((OSPopUp *)control, wParam);
            break;

        case ekGUI_TYPE_COMBOBOX:
            _oscombo_command((OSCombo *)control, wParam);
            break;

        case ekGUI_TYPE_LABEL:
        case ekGUI_TYPE_SLIDER:
        case ekGUI_TYPE_UPDOWN:
        case ekGUI_TYPE_PROGRESS:
        case ekGUI_TYPE_TABLEVIEW:
        case ekGUI_TYPE_TREEVIEW:
        case ekGUI_TYPE_BOXVIEW:
        case ekGUI_TYPE_SPLITVIEW:
        case ekGUI_TYPE_CUSTOMVIEW:
        case ekGUI_TYPE_PANEL:
        case ekGUI_TYPE_LINE:
        case ekGUI_TYPE_HEADER:
        case ekGUI_TYPE_WINDOW:
        case ekGUI_TYPE_TOOLBAR:
            cassert_default();
        }

        return 0;
    }

    case WM_VSCROLL:
    case WM_HSCROLL:
        if ((HWND)lParam != NULL)
        {
            OSControl *control = (OSControl *)GetWindowLongPtr((HWND)lParam, GWLP_USERDATA);
            if (control->type == ekGUI_TYPE_SLIDER)
                _osslider_message((OSSlider *)control, wParam);
        }
        else
        {
            gui_scroll_t event = osscroll_event(wParam);
            if (event != ENUM_MAX(gui_scroll_t))
            {
                gui_orient_t orient = uMsg == WM_HSCROLL ? ekGUI_HORIZONTAL : ekGUI_VERTICAL;
                osscrolls_event(panel->scroll, orient, event, TRUE);
            }
        }
        break;

    case WM_NCCALCSIZE:
        if (panel->flags & ekVIEW_BORDER)
            _osgui_nccalcsize(hwnd, wParam, lParam, FALSE, 0, &panel->border);
        break;

    case WM_NCPAINT:
        if (panel->flags & ekVIEW_BORDER)
        {
            bool_t focused = (bool_t)(GetFocus() == hwnd);
            _osgui_ncpaint(hwnd, focused, &panel->border, NULL);
        }
        break;

    case WM_MEASUREITEM:
    {
        cassert(FALSE);
        break;
    }

    case WM_NOTIFY:
    {
        const NMHDR *nmhdr = (const NMHDR *)lParam;
        OSControl *control = (OSControl *)GetWindowLongPtr(nmhdr->hwndFrom, GWLP_USERDATA);
        cassert_no_null(control);
        if (control->type == ekGUI_TYPE_UPDOWN)
            _osupdown_OnNotification((OSUpDown *)control, nmhdr, lParam);
        return 0;
    }

    /* The TBS_TRANSPARENTBKGND style probably doesn't work right because you don't
    implement WM_PRINTCLIENT in the parent. */
    case WM_PRINTCLIENT:
        return 0;

    case WM_CTLCOLORSTATIC:
    {
        HBRUSH defbrush = (HBRUSH)CallWindowProc(panel->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
        OSControl *control = (OSControl *)GetWindowLongPtr((HWND)lParam, GWLP_USERDATA);
        if (control != NULL)
        {
            if (control->type == ekGUI_TYPE_LABEL)
            {
                COLORREF color, bgcolor;
                HBRUSH bgbrush;
                color = _oslabel_color((OSLabel *)control);
                bgbrush = _oslabel_background_color((OSLabel *)control, &bgcolor);

                if (color != 0)
                    SetTextColor((HDC)wParam, color);

                if (bgbrush != NULL)
                {
                    SetBkColor((HDC)wParam, bgcolor);
                    return (LRESULT)bgbrush;
                }
            }

            if (panel->areas != NULL)
            {
                COLORREF bgcolor;
                HBRUSH brush = i_brush(control, panel->areas, &bgcolor);
                if (brush != NULL)
                {
                    SetBkColor((HDC)wParam, bgcolor);
                    return (LRESULT)brush;
                }
            }
        }

        return (LRESULT)defbrush;
    }

    case WM_CTLCOLOREDIT:
    {
        HBRUSH defbrush = (HBRUSH)CallWindowProc(panel->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);
        OSControl *control = (OSControl *)GetWindowLongPtr((HWND)lParam, GWLP_USERDATA);
        HDC hdc = (HDC)wParam;
        cassert_no_null(control);
        if (control->type == ekGUI_TYPE_EDITBOX)
        {
            COLORREF color = UINT32_MAX, bgcolor = UINT32_MAX;
            HBRUSH bgbrush = NULL;

            color = _osedit_color((OSEdit *)control);
            bgbrush = _osedit_background_color((OSEdit *)control, &bgcolor);

            if (color != 0)
                SetTextColor(hdc, color);

            if (bgbrush != NULL)
            {
                SetBkColor(hdc, bgcolor);
                return (LRESULT)bgbrush;
            }
        }
        else
        {
            cassert_msg(FALSE, "Unexpected control type");
        }

        return (LRESULT)defbrush;
    }

    case WM_CTLCOLORBTN:
    {
        OSControl *control = (OSControl *)GetWindowLongPtr((HWND)lParam, GWLP_USERDATA);
        cassert_unref(control->type != ekGUI_TYPE_COMBOBOX, control);
        break;
    }

    case WM_MOUSEWHEEL:
        if (panel->scroll != NULL)
        {
            gui_scroll_t event = ekGUI_SCROLL_STEP_LEFT;
            if (GET_WHEEL_DELTA_WPARAM(wParam) < 0)
                event = ekGUI_SCROLL_STEP_RIGHT;
            osscrolls_event(panel->scroll, ekGUI_VERTICAL, event, TRUE);
        }
        break;
    }

    {
        LRESULT res = CallWindowProc(panel->control.def_wnd_proc, hwnd, uMsg, wParam, lParam);

        if (uMsg == WM_ERASEBKGND && panel->areas != NULL)
        {
            RECT rc;
            uint32_t n = arrst_size(panel->areas, Area);
            GetClientRect(hwnd, &rc);

            if (panel->scroll != NULL)
            {
                uint32_t x = osscrolls_x_pos(panel->scroll);
                uint32_t y = osscrolls_y_pos(panel->scroll);
                SetWindowOrgEx((HDC)wParam, (int)x, (int)y, NULL);
            }

            if (n == 1)
            {
                const Area *area = arrst_get(panel->areas, 0, Area);
                if (EqualRect(&rc, &area->rect) == TRUE)
                {
                    i_area((HDC)wParam, area);
                }
                else
                {
                    HBRUSH defbrush = (HBRUSH)GetClassLongPtr(hwnd, GCLP_HBRBACKGROUND);
                    FillRect((HDC)wParam, &rc, defbrush);
                    i_area((HDC)wParam, area);
                }
            }
            else
            {
                HBRUSH defbrush = (HBRUSH)GetClassLongPtr(hwnd, GCLP_HBRBACKGROUND);
                FillRect((HDC)wParam, &rc, defbrush);
                arrst_foreach(area, panel->areas, Area)
                    i_area((HDC)wParam, area);
                arrst_end()
            }

            if (panel->scroll != NULL)
                SetWindowOrgEx((HDC)wParam, 0, 0, NULL);
        }

        return res;
    }
}

/*---------------------------------------------------------------------------*/

OSPanel *ospanel_create(const uint32_t flags)
{
    OSPanel *panel = heap_new0(OSPanel);
    DWORD dwStyle = WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

    if (flags & ekVIEW_HSCROLL)
        dwStyle |= WS_HSCROLL;

    if (flags & ekVIEW_VSCROLL)
        dwStyle |= WS_VSCROLL;

    panel->control.type = ekGUI_TYPE_PANEL;
    _oscontrol_init((OSControl *)panel, PARAM(dwExStyle, WS_EX_NOPARENTNOTIFY), dwStyle, kVIEW_CLASS, 0, 0, i_WndProc, kDEFAULT_PARENT_WINDOW);

    if ((flags & ekVIEW_HSCROLL) || (flags & ekVIEW_VSCROLL))
        panel->scroll = osscrolls_create((OSControl *)panel, (bool_t)(flags & ekVIEW_HSCROLL) != 0, (bool_t)(flags & ekVIEW_VSCROLL) != 0);

    panel->flags = flags;
    return panel;
}

/*---------------------------------------------------------------------------*/

void ospanel_destroy(OSPanel **panel)
{
    cassert_no_null(panel);
    cassert_no_null(*panel);

    if ((*panel)->memhdc != NULL)
    {
        BOOL ok = FALSE;
        cassert_no_null((*panel)->dbuffer);
        ok = DeleteDC((*panel)->memhdc);
        cassert(ok != 0);
        ok = DeleteObject((*panel)->dbuffer);
        cassert(ok != 0);
    }
    else
    {
        cassert((*panel)->dbuffer == NULL);
    }

    if ((*panel)->areas != NULL)
        arrst_destroy(&(*panel)->areas, i_remove_area, Area);

    if ((*panel)->scroll != NULL)
        osscrolls_destroy(&(*panel)->scroll);

    cassert(_oscontrol_num_children((OSControl *)(*panel)) == 0);
    _oscontrol_destroy((OSControl *)(*panel));
    heap_delete(panel, OSPanel);
}

/*---------------------------------------------------------------------------*/

void ospanel_area(OSPanel *panel, void *obj, const color_t bgcolor, const color_t skcolor, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    cassert_no_null(panel);
    if (obj != NULL)
    {
        Area *area = NULL;

        if (panel->areas == NULL)
            panel->areas = arrst_create(Area);

        arrst_foreach(larea, panel->areas, Area)
            if (larea->obj == obj)
            {
                area = larea;
                break;
            }
        arrst_end()

        if (area == NULL)
        {
            area = arrst_new(panel->areas, Area);
            area->obj = obj;
            area->bgbrush = NULL;
            area->skbrush = NULL;
        }

        area->rect.left = (LONG)x;
        area->rect.top = (LONG)y;
        area->rect.right = (LONG)(x + width);
        area->rect.bottom = (LONG)(y + height);
        _oscontrol_update_brush(bgcolor, &area->bgbrush, &area->bgcolor);
        _oscontrol_update_brush(skcolor, &area->skbrush, NULL);
    }
    else
    {
        if (panel->areas != NULL)
            arrst_clear(panel->areas, i_remove_area, Area);
    }
}

/*---------------------------------------------------------------------------*/

void ospanel_scroller_size(const OSPanel *panel, real32_t *width, real32_t *height)
{
    cassert_no_null(panel);
    if (width != NULL)
        *width = (real32_t)osscrolls_bar_width(panel->scroll, FALSE);

    if (height != NULL)
        *height = (real32_t)osscrolls_bar_height(panel->scroll, FALSE);
}

/*---------------------------------------------------------------------------*/

void ospanel_content_size(OSPanel *panel, const real32_t width, const real32_t height, const real32_t line_width, const real32_t line_height)
{
    cassert_no_null(panel);
    osscrolls_content_size(panel->scroll, (uint32_t)width, (uint32_t)height, (uint32_t)line_width, (uint32_t)line_height);
}

/*---------------------------------------------------------------------------*/

void ospanel_display(OSPanel *panel)
{
    cassert_no_null(panel);
    if (panel->areas != NULL)
        InvalidateRect(panel->control.hwnd, NULL, TRUE);
}

/*---------------------------------------------------------------------------*/

void ospanel_attach(OSPanel *panel, OSPanel *parent_panel)
{
    cassert_no_null(panel);
    cassert_no_null(parent_panel);
    _oscontrol_attach_to_parent((OSControl *)panel, (OSControl *)parent_panel);
}

/*---------------------------------------------------------------------------*/

void ospanel_detach(OSPanel *panel, OSPanel *parent_panel)
{
    _oscontrol_detach_from_parent((OSControl *)panel, (OSControl *)parent_panel);
}

/*---------------------------------------------------------------------------*/

void ospanel_visible(OSPanel *panel, const bool_t visible)
{
    _oscontrol_set_visible((OSControl *)panel, visible);
}

/*---------------------------------------------------------------------------*/

void ospanel_enabled(OSPanel *panel, const bool_t enabled)
{
    _oscontrol_set_enabled((OSControl *)panel, enabled);
}

/*---------------------------------------------------------------------------*/

void ospanel_size(const OSPanel *panel, real32_t *width, real32_t *height)
{
    _oscontrol_get_size((const OSControl *)panel, width, height);
}

/*---------------------------------------------------------------------------*/

void ospanel_origin(const OSPanel *panel, real32_t *x, real32_t *y)
{
    _oscontrol_get_origin((const OSControl *)panel, x, y);
}

/*---------------------------------------------------------------------------*/

void ospanel_frame(OSPanel *panel, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    cassert_no_null(panel);
    _oscontrol_set_frame((OSControl *)panel, x, y, width, height);
    if (panel->scroll != NULL)
        osscrolls_control_size(panel->scroll, (uint32_t)width, (uint32_t)height);
}

/*---------------------------------------------------------------------------*/

OSPanel *_ospanel_create_default(void)
{
    OSPanel *panel = heap_new0(OSPanel);
    panel->control.type = ekGUI_TYPE_PANEL;
    _oscontrol_init_hidden((OSControl *)panel, PARAM(dwExStyle, WS_EX_NOPARENTNOTIFY), PARAM(dwStyle, WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS), kVIEW_CLASS, 0, 0, i_WndProc, GetDesktopWindow());
    return panel;
}

/*---------------------------------------------------------------------------*/

void _ospanel_destroy_default(OSPanel **panel)
{
    ospanel_destroy(panel);
}

/*---------------------------------------------------------------------------*/

static BOOL CALLBACK i_destroy_child(HWND hwnd, LPARAM lParam)
{
    OSControl *control = OSControlPtr(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    if (control != NULL)
        oscontrol_detach_and_destroy(&control, OSPanelPtr(lParam));
    return TRUE;
}

/*---------------------------------------------------------------------------*/

void _ospanel_destroy(OSPanel **panel)
{
    cassert_no_null(panel);
    cassert_no_null(*panel);
    EnumChildWindows((*panel)->control.hwnd, i_destroy_child, (LPARAM)*panel);
    ospanel_destroy(panel);
}

/*---------------------------------------------------------------------------*/

void _ospanel_resize_double_buffer(OSPanel *panel, LONG width, LONG height)
{
    HDC hdc = NULL;
    cassert_no_null(panel);
    hdc = GetDC(panel->control.hwnd);
    if __FALSE_EXPECTED ((panel->memhdc == NULL))
    {
        cassert(panel->dbuffer == NULL);
        panel->memhdc = CreateCompatibleDC(hdc);
        cassert_no_null(panel->memhdc);
    }
    else
    {
        BOOL ok = FALSE;
        cassert(panel->dbuffer != NULL);
        ok = DeleteObject(panel->dbuffer);
        cassert(ok != 0);
    }

    panel->dbuffer = CreateCompatibleBitmap(hdc, (int)width, (int)height);
    cassert_no_null(panel->dbuffer);
    SelectObject(panel->memhdc, panel->dbuffer);
}

/*---------------------------------------------------------------------------*/

static BOOL CALLBACK i_draw_rect(HWND hwnd, LPARAM lParam)
{
    OSControl *control = (OSControl *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    cassert_no_null(control);

    if (control->type != ekGUI_TYPE_PANEL)
    {
        HDC hdc = (HDC)lParam;
        RECT rect;
        GetClientRect(hwnd, &rect);
        MapWindowPoints(hwnd, GetAncestor(hwnd, GA_ROOT), (LPPOINT)&rect, 2);
        Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

HDC _ospanel_paint_double_buffer(OSPanel *panel, const uint32_t resize_strategy, LONG *width, LONG *height)
{
    RECT rect;
    cassert_no_null(panel);
    cassert_no_null(width);
    cassert_no_null(height);

    GetClientRect(panel->control.hwnd, &rect);
    *width = rect.right - rect.left;
    *height = rect.bottom - rect.top;

    if (resize_strategy == 1 || resize_strategy == 2)
    {
        HDC hdc;
        HBRUSH hbrBkGnd;

        hdc = GetDC(panel->control.hwnd);
        hbrBkGnd = CreateSolidBrush(GetSysColor(COLOR_BTNFACE));
        FillRect(panel->memhdc, &rect, hbrBkGnd);

        if (resize_strategy == 2)
        {
            SelectObject(panel->memhdc, GetStockObject(BLACK_PEN));
            EnumChildWindows(panel->control.hwnd, i_draw_rect, (LPARAM)panel->memhdc);
        }

        ReleaseDC(panel->control.hwnd, hdc);
        DeleteObject(hbrBkGnd);
    }
    else if (resize_strategy == 3)
    {
        SendMessage(panel->control.hwnd, WM_PRINT, (WPARAM)panel->memhdc, (LPARAM)(PRF_CLIENT | PRF_NONCLIENT | PRF_CHILDREN | PRF_OWNED));
    }
    else
    {
        cassert(FALSE);
    }

    return panel->memhdc;
}

/*---------------------------------------------------------------------------*/

void _ospanel_attach_control(OSPanel *panel, OSControl *control)
{
    _oscontrol_attach_to_parent(control, (OSControl *)panel);
}

/*---------------------------------------------------------------------------*/

void _ospanel_detach_control(OSPanel *panel, OSControl *control)
{
    _oscontrol_detach_from_parent(control, (OSControl *)panel);
}

/*---------------------------------------------------------------------------*/

COLORREF _ospanel_background_color(OSPanel *panel, OSControl *control)
{
    if (panel->areas != NULL)
    {
        COLORREF c;
        if (i_brush(control, panel->areas, &c) != NULL)
            return c;
    }

    return GetSysColor(COLOR_3DFACE);
}

/*---------------------------------------------------------------------------*/

bool_t ospanel_with_scroll(const OSPanel *panel)
{
    cassert_no_null(panel);
    return (bool_t)(panel->scroll != NULL);
}

/*---------------------------------------------------------------------------*/

void _ospanel_scroll_pos(OSPanel *panel, int *scroll_x, int *scroll_y)
{
    cassert_no_null(panel);
    cassert_no_null(scroll_x);
    cassert_no_null(scroll_y);
    if (panel->scroll != NULL)
    {
        *scroll_x = (int)osscrolls_x_pos(panel->scroll);
        *scroll_y = (int)osscrolls_y_pos(panel->scroll);
    }
    else
    {
        *scroll_x = 0;
        *scroll_y = 0;
    }
}

/*---------------------------------------------------------------------------*/

void ospanel_scroll_frame(const OSPanel *panel, OSFrame *rect)
{
    uint32_t x, y, w, h;
    cassert_no_null(panel);
    cassert_no_null(rect);
    osscrolls_visible_area(panel->scroll, &x, &y, &w, &h, NULL, NULL);
    rect->left = (int32_t)x;
    rect->top = (int32_t)y;
    rect->right = (int32_t)(x + w);
    rect->bottom = (int32_t)(y + h);
}

/*---------------------------------------------------------------------------*/

void ospanel_scroll(OSPanel *panel, const int32_t x, const int32_t y)
{
    cassert_no_null(panel);
    if (panel->scroll != NULL)
        osscrolls_set(panel->scroll, (uint32_t)x, (uint32_t)y, TRUE);
}
