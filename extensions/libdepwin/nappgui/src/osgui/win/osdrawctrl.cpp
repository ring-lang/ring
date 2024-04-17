/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osdrawctrl.cpp
 *
 */

/* Drawing custom GUI controls */

#include "osimg.inl"
#include "osdrawctrl.h"
#include "osdrawctrl_win.inl"
#include "osstyleXP.inl"
#include <draw2d/color.h>
#include <draw2d/dctxh.h>
#include <draw2d/font.h>
#include <osbs/osbs.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

#if _MSC_VER > 1400
#define DLISS_NORMAL LISS_NORMAL
#define DLISS_HOT LISS_HOT
#define DLISS_SELECTED LISS_SELECTED
#define DLISS_SELECTEDNOTFOCUS LISS_SELECTEDNOTFOCUS
#define DLISS_DISABLED LISS_DISABLED
#else
#define DLISS_NORMAL LIS_NORMAL
#define DLISS_HOT LIS_HOT
#define DLISS_SELECTED LIS_SELECTED
#define DLISS_SELECTEDNOTFOCUS LIS_SELECTEDNOTFOCUS
#define DLISS_DISABLED LIS_DISABLED
#endif

static LONG kCHECKBOX_WIDTH = 0;
static LONG kCHECKBOX_HEIGHT = 0;

/*---------------------------------------------------------------------------*/

Font *osdrawctrl_font(const DCtx *ctx)
{
    HTHEME theme = osstyleXP_OpenTheme(GetDesktopWindow(), L"Explorer::ListView");
    Font *font = NULL;

    unref(ctx);

    if (theme != NULL)
    {
        LOGFONTW lfont;
        if (GetThemeFont(theme, NULL, LVP_LISTITEM, DLISS_NORMAL, TMT_FONT, &lfont) == S_OK)
        {
            // TODO: Create a font from LOGFONT
            font = font_system(font_regular_size(), 0);
        }

        osstyleXP_CloseTheme(theme);
    }

    if (font == NULL)
        font = font_system(font_regular_size(), 0);

    return font;
}

/*---------------------------------------------------------------------------*/

uint32_t osdrawctrl_row_padding(const DCtx *ctx)
{
    unref(ctx);
    return 4;
}

/*---------------------------------------------------------------------------*/

uint32_t osdrawctrl_check_width(const DCtx *ctx)
{
    unref(ctx);
    if (kCHECKBOX_WIDTH == 0)
        kCHECKBOX_WIDTH = GetSystemMetrics(SM_CXMENUCHECK);
    return (uint32_t)kCHECKBOX_WIDTH;
}

/*---------------------------------------------------------------------------*/

uint32_t osdrawctrl_check_height(const DCtx *ctx)
{
    unref(ctx);
    if (kCHECKBOX_HEIGHT == 0)
        kCHECKBOX_HEIGHT = GetSystemMetrics(SM_CXMENUCHECK);
    return (uint32_t)kCHECKBOX_HEIGHT;
}

/*---------------------------------------------------------------------------*/

ctrl_msel_t osdrawctrl_multisel(const DCtx *ctx, const vkey_t key)
{
    unref(ctx);
    if (key == ekKEY_LCTRL || key == ekKEY_RCTRL)
        return ekCTRL_MSEL_SINGLE;
    else if (key == ekKEY_LSHIFT || key == ekKEY_RSHIFT)
        return ekCTRL_MSEL_BURST;
    return ekCTRL_MSEL_NO;
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_clear(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const enum_t nonused)
{
    RECT rect;
    real32_t offset_x = 0, offset_y = 0;
    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);
    rect.left = (LONG)x + (LONG)offset_x;
    rect.top = (LONG)y + (LONG)offset_y;
    rect.right = rect.left + (LONG)width;
    rect.bottom = rect.top + (LONG)height;
    FillRect((HDC)dctx_native(ctx), &rect, GetSysColorBrush(COLOR_WINDOW));
    unref(nonused);
}

/*---------------------------------------------------------------------------*/

static __INLINE int i_list_state(const ctrl_state_t state)
{
    switch (state)
    {
    case ekCTRL_STATE_NORMAL:
    case ekCTRL_STATE_BKNORMAL:
        return DLISS_NORMAL;
    case ekCTRL_STATE_HOT:
    case ekCTRL_STATE_BKHOT:
        return DLISS_HOT;
    case ekCTRL_STATE_PRESSED:
        return DLISS_SELECTED;
    case ekCTRL_STATE_BKPRESSED:
        return DLISS_SELECTEDNOTFOCUS;
    case ekCTRL_STATE_DISABLED:
        return DLISS_DISABLED;
        cassert_default();
    }

    return DLISS_NORMAL;
}

/*---------------------------------------------------------------------------*/

static __INLINE int i_header_state(const ctrl_state_t state)
{
    switch (state)
    {
    case ekCTRL_STATE_NORMAL:
    case ekCTRL_STATE_BKNORMAL:
        return HIS_NORMAL;
    case ekCTRL_STATE_HOT:
    case ekCTRL_STATE_BKHOT:
        return HIS_HOT;
    case ekCTRL_STATE_PRESSED:
    case ekCTRL_STATE_BKPRESSED:
        return HIS_PRESSED;
    case ekCTRL_STATE_DISABLED:
        return HIS_NORMAL;
        cassert_default();
    }

    return HIS_NORMAL;
}

/*---------------------------------------------------------------------------*/

static __INLINE HTHEME i_button_theme(DCtx *ctx)
{
    OSDraw *custom_data = dctx_get_data(ctx, OSDraw);
    cassert_no_null(custom_data);
    return custom_data->button_theme;
}

/*---------------------------------------------------------------------------*/

static __INLINE HTHEME i_list_theme(DCtx *ctx)
{
    OSDraw *custom_data = dctx_get_data(ctx, OSDraw);
    cassert_no_null(custom_data);
    return custom_data->list_theme;
}

/*---------------------------------------------------------------------------*/

static __INLINE HTHEME i_header_theme(DCtx *ctx)
{
    OSDraw *custom_data = dctx_get_data(ctx, OSDraw);
    cassert_no_null(custom_data);
    return custom_data->header_theme;
}

/*---------------------------------------------------------------------------*/

static __INLINE SIZE i_sort_size(DCtx *ctx)
{
    SIZE *sz = NULL;
    OSDraw *custom_data = dctx_get_data(ctx, OSDraw);
    cassert_no_null(custom_data);
    sz = &custom_data->sort_size;
    if (sz->cx == -1)
        GetThemePartSize(custom_data->header_theme, (HDC)dctx_native(ctx), HP_HEADERSORTARROW, HSAS_SORTEDDOWN, NULL, TS_DRAW, sz);
    return *sz;
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_header(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    RECT rect;
    real32_t offset_x = 0, offset_y = 0;
    int istate = i_header_state(state);
    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);
    rect.left = (LONG)x + (LONG)offset_x + 1;
    rect.top = (LONG)y + (LONG)offset_y;
    rect.right = rect.left + (LONG)width;
    rect.bottom = rect.top + (LONG)height;
    osstyleXP_DrawThemeBackground2(i_header_theme(ctx), HP_HEADERITEM, istate, (HDC)dctx_native(ctx), &rect);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_indicator(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const indicator_t indicator)
{
    int istate = 0;

    if (indicator & ekINDDOWN_ARROW)
        istate = HSAS_SORTEDDOWN;
    else if (indicator & ekINDUP_ARROW)
        istate = HSAS_SORTEDUP;

    if (istate != 0)
    {
        RECT rect;
        real32_t offset_x = 0, offset_y = 0;
        HTHEME theme = i_header_theme(ctx);
        SIZE sz = i_sort_size(ctx);
        draw_set_raster_mode(ctx);
        dctx_offset(ctx, &offset_x, &offset_y);
        rect.left = (LONG)x + (LONG)offset_x + 1;
        rect.top = (LONG)y + (LONG)offset_y + 1;
        rect.right = rect.left + (LONG)width;
        rect.bottom = rect.top + sz.cy;
        unref(height);
        osstyleXP_DrawThemeBackground2(theme, HP_HEADERSORTARROW, istate, (HDC)dctx_native(ctx), &rect);
    }
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_fill(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    RECT rect;
    real32_t offset_x = 0, offset_y = 0;
    int istate = i_list_state(state);
    HDC hdc = (HDC)dctx_native(ctx);
    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);
    rect.left = (LONG)x + (LONG)offset_x;
    rect.top = (LONG)y + (LONG)offset_y;
    rect.right = rect.left + (LONG)width;
    rect.bottom = rect.top + (LONG)height;
    if (osbs_windows() > ekWIN_XP3)
    {
        osstyleXP_DrawThemeBackground2(i_list_theme(ctx), LVP_LISTITEM, istate, hdc, &rect);
    }
    else
    {
        /* Seems WindowsXP doesn't use Vista Styles for selected text */
        HBRUSH brush = NULL;
        if (state == ekCTRL_STATE_PRESSED || state == ekCTRL_STATE_BKPRESSED)
            brush = GetSysColorBrush(COLOR_HIGHLIGHT);
        else
            brush = GetSysColorBrush(COLOR_WINDOW);
        FillRect(hdc, &rect, brush);
    }
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_focus(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    RECT rect;
    real32_t offset_x = 0, offset_y = 0;
    unref(state);
    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);
    rect.left = (LONG)x + (LONG)offset_x;
    rect.top = (LONG)y + (LONG)offset_y;
    rect.right = rect.left + (LONG)width;
    rect.bottom = rect.top + (LONG)height;
    DrawFocusRect((HDC)dctx_native(ctx), &rect);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_line(DCtx *ctx, const int32_t x0, const int32_t y0, const int32_t x1, const int32_t y1)
{
    HDC hdc = NULL;
    real32_t offset_x = 0, offset_y = 0;
    cassert_no_null(ctx);
    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);
    hdc = (HDC)dctx_native(ctx);
    MoveToEx(hdc, (int)(x0 + offset_x), (int)(y0 + offset_y), NULL);
    LineTo(hdc, (int)(x1 + offset_x), (int)(y1 + offset_y));
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_text(DCtx *ctx, const char_t *text, const int32_t x, const int32_t y, const ctrl_state_t state)
{
    RECT rect;
    real32_t offset_x = 0, offset_y = 0;
    real32_t text_width = dctx_text_width(ctx);
    HDC hdc = (HDC)dctx_native(ctx);
    uint32_t num_bytes = 0;
    WCHAR wtext[1024];
    UINT format = DT_SINGLELINE | DT_END_ELLIPSIS;

    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);

    // For GDI-based raster text in bitmap context, we have to 'delete' the GDI object
    // Check 'Using GDI+ on a GDI HDC'
    cassert(dctx_internal_bitmap(ctx) == NULL);

    rect.left = (LONG)x + (LONG)offset_x;
    rect.right = text_width > 0 ? rect.left + (LONG)text_width : 10000;
    rect.top = (LONG)y + (LONG)offset_y;
    rect.bottom = rect.top + 10000;
    num_bytes = unicode_convers(text, (char_t *)wtext, ekUTF8, ekUTF16, sizeof(wtext));
    unref(num_bytes);

    switch (dctx_text_intalign(ctx))
    {
    case ekLEFT:
    case ekJUSTIFY:
        format |= DT_LEFT;
        break;
    case ekCENTER:
        format |= DT_CENTER;
        break;
    case ekRIGHT:
        format |= DT_RIGHT;
        break;
    }

    if (dctx_text_color(ctx) == kCOLOR_DEFAULT)
    {
        if (osbs_windows() > ekWIN_XP3)
        {
            int istate = i_list_state(state);
            osstyleXP_DrawThemeText2(i_list_theme(ctx), hdc, LVP_LISTITEM, istate, wtext, -1, format, &rect);
        }
        else
        {
            /* Seems WindowsXP doesn't use Vista Styles for selected text */
            COLORREF color = GetSysColor(COLOR_WINDOWTEXT);
            if (state == ekCTRL_STATE_PRESSED || state == ekCTRL_STATE_BKPRESSED)
                color = GetSysColor(COLOR_HIGHLIGHTTEXT);
            SetTextColor(hdc, color);
            DrawTextW(hdc, wtext, -1, &rect, format);
        }
    }
    else
    {
        DrawTextW(hdc, wtext, -1, &rect, format);
    }
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_image(DCtx *ctx, const Image *image, const int32_t x, const int32_t y, const ctrl_state_t state)
{
    HBITMAP hbitmap;
    real32_t offset_x = 0, offset_y = 0;
    HDC hdc = (HDC)dctx_native(ctx);
    HDC memhdc = NULL;
    LONG width, height;
    unref(state);
    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);
    hbitmap = osimg_hbitmap_cache(image, (COLORREF)dctx_background_color(ctx), &width, &height);
    memhdc = CreateCompatibleDC(hdc);
    SelectObject(memhdc, hbitmap);
    BitBlt(hdc, (int)x + (int)offset_x, (int)y + (int)offset_y, width, height, memhdc, 0, 0, SRCCOPY);
    DeleteDC(memhdc);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_checkbox(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    int istate = 0;
    RECT rect;
    real32_t offset_x = 0, offset_y = 0;
    HDC hdc = (HDC)dctx_native(ctx);

    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);

    switch (state)
    {
    case ekCTRL_STATE_NORMAL:
    case ekCTRL_STATE_BKNORMAL:
        istate = CBS_CHECKEDNORMAL;
        break;

    case ekCTRL_STATE_HOT:
    case ekCTRL_STATE_BKHOT:
        istate = CBS_CHECKEDHOT;
        break;

    case ekCTRL_STATE_PRESSED:
    case ekCTRL_STATE_BKPRESSED:
        istate = CBS_CHECKEDPRESSED;
        break;

    case ekCTRL_STATE_DISABLED:
        istate = CBS_CHECKEDDISABLED;
        break;

        cassert_default();
    }

    cassert((LONG)width == kCHECKBOX_WIDTH);
    cassert((LONG)height == kCHECKBOX_HEIGHT);
    rect.left = (LONG)x + (LONG)offset_x;
    rect.top = (LONG)y + (LONG)offset_y;
    rect.right = rect.left + (LONG)width;
    rect.bottom = rect.top + (LONG)height;
    osstyleXP_DrawThemeBackground2(i_button_theme(ctx), BP_CHECKBOX, istate, hdc, &rect);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_uncheckbox(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    int istate = 0;
    RECT rect;
    real32_t offset_x = 0, offset_y = 0;
    HDC hdc = (HDC)dctx_native(ctx);

    draw_set_raster_mode(ctx);
    dctx_offset(ctx, &offset_x, &offset_y);

    switch (state)
    {
    case ekCTRL_STATE_NORMAL:
    case ekCTRL_STATE_BKNORMAL:
        istate = CBS_UNCHECKEDNORMAL;
        break;

    case ekCTRL_STATE_HOT:
    case ekCTRL_STATE_BKHOT:
        istate = CBS_UNCHECKEDHOT;
        break;

    case ekCTRL_STATE_PRESSED:
    case ekCTRL_STATE_BKPRESSED:
        istate = CBS_UNCHECKEDPRESSED;
        break;

    case ekCTRL_STATE_DISABLED:
        istate = CBS_UNCHECKEDDISABLED;
        break;

        cassert_default();
    }

    cassert((LONG)width == kCHECKBOX_WIDTH);
    cassert((LONG)height == kCHECKBOX_HEIGHT);
    rect.left = (LONG)x + (LONG)offset_x;
    rect.top = (LONG)y + (LONG)offset_y;
    rect.right = rect.left + (LONG)width;
    rect.bottom = rect.top + (LONG)height;
    osstyleXP_DrawThemeBackground2(i_button_theme(ctx), BP_CHECKBOX, istate, hdc, &rect);
}

/*---------------------------------------------------------------------------*/

void osdrawctrl_header_button(HWND hwnd, HDC hdc, HFONT font, const RECT *rect, int state, const WCHAR *text, const align_t align, const Image *image)
{
    BOOL use_style = FALSE;

    cassert_no_null(rect);
    cassert(FALSE);

    use_style = osstyleXP_OpenThemeData(hwnd, L"HEADER");

    if (use_style == TRUE)
    {
        DWORD flags;
        RECT rect2;

        switch (align)
        {
        case ekLEFT:
        case ekJUSTIFY:
            flags = DT_LEFT;
            break;
        case ekCENTER:
            flags = DT_CENTER;
            break;
        case ekRIGHT:
            flags = DT_RIGHT;
            break;
            cassert_default();
        }

        flags |= DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

        osstyleXP_DrawThemeBackground(hwnd, hdc, HP_HEADERITEM, state, FALSE, rect, NULL);
        cassert(osstyleXP_HasThemeFont(hdc, HP_HEADERITEM, state, TMT_FONT) == FALSE);
        SelectObject(hdc, font);
        rect2 = *rect;
        InflateRect(&rect2, -16, 0);
        osstyleXP_DrawThemeText(hdc, HP_HEADERITEM, state, text, UINT32_MAX, flags, &rect2);
        rect2 = *rect;
        rect2.bottom = rect2.top + 10;
        osstyleXP_DrawThemeText(hdc, HP_HEADERSORTARROW, HSAS_SORTEDUP, L"W", UINT32_MAX, flags, rect);

        //LOGFONT lf;
        //SelectObject(hdc, tv->font);
        //res = GetThemeFont(i_STYLEXP.theme, hdc, iPartId, iStateId, TMT_FONT, &lf);
        //cassert_unref(res == S_OK, res);
    }
    else
    {
        cassert(FALSE);
        //UINT state = DFCS_BUTTONPUSH;
        //if (enabled == FALSE)
        //{
        //    state |= DFCS_INACTIVE;
        //}
        //else if (SendMessage(hwnd, BM_GETCHECK, (WPARAM)0, (LPARAM)0) == BST_CHECKED)
        //{
        //    state |= DFCS_PUSHED;
        //}
        //else if (_osgui_hit_test(hwnd) == TRUE)
        //{
        //    if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
        //        state |= DFCS_PUSHED;
        //    else
        //        state |= DFCS_HOT;
        //}

        //osstyleXP_DrawNonThemedButtonBackground(hwnd, hdc, FALSE, state, &rect, &border);
    }

    if (image != NULL)
    {
        //    uint32_t width, height;
        //    uint32_t offset_x, offset_y;
        //    image_size(image, &width, &height);
        //    offset_x = (rect.right - rect.left - width) / 2;
        //    offset_y = (rect.bottom - rect.top - height) / 2;
        //    osimage_draw(image, hdc, UINT32_MAX, (real32_t)offset_x, (real32_t)offset_y, (real32_t)width, (real32_t)height, !enabled);
    }

    if (use_style == TRUE)
        osstyleXP_CloseThemeData();
}
