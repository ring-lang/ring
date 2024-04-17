/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osstyleXP.c
 *
 */

/* Windows XP Styles 
 * Based on CVisualStylesXP by David Yuheng Zhao 
 */

/////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2001-2002 by David Yuheng Zhao
//
// Distribute and change freely, except: don't remove my name from the source
/////////////////////////////////////////////////////////////////////////////

#include "osstyleXP.inl"
#include <core/heap.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>

#pragma comment(lib, "uxtheme.lib")

#ifndef DTPB_WINDOWDC
#define DTPB_WINDOWDC 0x00000001
#endif

#ifndef DTPB_USECTLCOLORSTATIC
#define DTPB_USECTLCOLORSTATIC 0x00000002
#endif

typedef struct _osstyleXP_t OSStyleXP;
typedef BOOL(__stdcall *PFNISAPPTHEMED)(void);
typedef BOOL(__stdcall *PFNISTHEMEACTIVE)(void);
typedef HTHEME(__stdcall *PFNOPENTHEMEDATA)(HWND hwnd, LPCWSTR pszClassList);
typedef HRESULT(__stdcall *PFNCLOSETHEMEDATA)(HTHEME hTheme);
typedef HRESULT(__stdcall *PFNGETTHEMEBACKGROUNDCONTENTRECT)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pBoundingRect, RECT *pContentRect);
typedef HRESULT(__stdcall *PFNDRAWTHEMEBACKGROUND)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);
typedef BOOL(__stdcall *PFNISTHEMEBACKGROUNDPARTIALLYTRANSPARENT)(HTHEME hTheme, int iPartId, int iStateId);
typedef HRESULT(__stdcall *PFNDRAWTHEMEPARENTBACKGROUNDEX)(HWND hwnd, HDC hdc, DWORD dwFlags, const RECT *prc);
typedef HRESULT(__stdcall *PFNDRAWTHEMEEDGE)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pDestRect, UINT uEdge, UINT uFlags, RECT *pContentRect);
typedef HRESULT(__stdcall *PFNGETTHEMEFONT)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, int iPropId, LOGFONT *pFont);
typedef HRESULT(__stdcall *PFNDRAWTHEMETEXT)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, LPCWSTR pszText, int iCharCount, DWORD dwTextFlags, DWORD dwTextFlags2, const RECT *pRect);

struct _osstyleXP_t
{
    HMODULE themeDll;
    HTHEME theme;
    PFNISAPPTHEMED IsAppThemed;
    PFNISTHEMEACTIVE IsThemeActive;
    PFNOPENTHEMEDATA OpenThemeData;
    PFNCLOSETHEMEDATA CloseThemeData;
    PFNGETTHEMEBACKGROUNDCONTENTRECT GetThemeBackgroundContentRect;
    PFNDRAWTHEMEBACKGROUND DrawThemeBackground;
    PFNISTHEMEBACKGROUNDPARTIALLYTRANSPARENT IsThemeBackgroundPartiallyTransparent;
    PFNDRAWTHEMEPARENTBACKGROUNDEX DrawThemeParentBackgroundEx;
    PFNDRAWTHEMEEDGE DrawThemeEdge;
    PFNGETTHEMEFONT GetThemeFont;
    PFNDRAWTHEMETEXT DrawThemeText;
};

static OSStyleXP i_STYLEXP;

/*---------------------------------------------------------------------------*/

void osstyleXP_init(void)
{
    bmem_zero(&i_STYLEXP, OSStyleXP);
    i_STYLEXP.themeDll = LoadLibrary(L"UxTheme.dll");
    i_STYLEXP.IsAppThemed = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "IsAppThemed"), PFNISAPPTHEMED);
    i_STYLEXP.IsThemeActive = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "IsThemeActive"), PFNISTHEMEACTIVE);
    i_STYLEXP.OpenThemeData = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "OpenThemeData"), PFNOPENTHEMEDATA);
    i_STYLEXP.CloseThemeData = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "CloseThemeData"), PFNCLOSETHEMEDATA);
    i_STYLEXP.GetThemeBackgroundContentRect = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "GetThemeBackgroundContentRect"), PFNGETTHEMEBACKGROUNDCONTENTRECT);
    i_STYLEXP.DrawThemeBackground = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "DrawThemeBackground"), PFNDRAWTHEMEBACKGROUND);
    i_STYLEXP.IsThemeBackgroundPartiallyTransparent = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "IsThemeBackgroundPartiallyTransparent"), PFNISTHEMEBACKGROUNDPARTIALLYTRANSPARENT);
    i_STYLEXP.DrawThemeParentBackgroundEx = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "DrawThemeParentBackgroundEx"), PFNDRAWTHEMEPARENTBACKGROUNDEX);
    i_STYLEXP.DrawThemeEdge = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "DrawThemeEdge"), PFNDRAWTHEMEEDGE);
    i_STYLEXP.GetThemeFont = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "GetThemeFont"), PFNGETTHEMEFONT);
    i_STYLEXP.DrawThemeText = cast_func_ptr(GetProcAddress(i_STYLEXP.themeDll, "DrawThemeText"), PFNDRAWTHEMETEXT);
}

/*---------------------------------------------------------------------------*/

void osstyleXP_remove(void)
{
    cassert(i_STYLEXP.themeDll != NULL);
    FreeLibrary(i_STYLEXP.themeDll);
    i_STYLEXP.themeDll = NULL;
}

/*---------------------------------------------------------------------------*/

static BOOL i_IsAppThemed(void)
{
    return i_STYLEXP.IsAppThemed();
}

/*---------------------------------------------------------------------------*/

static BOOL i_IsThemeActive(void)
{
    return i_STYLEXP.IsThemeActive();
}

/*---------------------------------------------------------------------------*/

HTHEME osstyleXP_OpenTheme(HWND hwnd, LPCWSTR pszClassList)
{
    HTHEME theme = NULL;
    if (i_IsAppThemed() == TRUE && i_IsThemeActive() == TRUE)
        theme = i_STYLEXP.OpenThemeData(hwnd, pszClassList);
    return theme;
}

/*---------------------------------------------------------------------------*/

BOOL osstyleXP_OpenThemeData(HWND hwnd, LPCWSTR pszClassList)
{
    cassert(i_STYLEXP.theme == NULL);
    i_STYLEXP.theme = osstyleXP_OpenTheme(hwnd, pszClassList);
    return (i_STYLEXP.theme != NULL) ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

void osstyleXP_CloseTheme(HTHEME theme)
{
    HRESULT res = 0;
    cassert_no_null(theme);
    res = i_STYLEXP.CloseThemeData(theme);
    cassert_unref(res == S_OK, res);
}

/*---------------------------------------------------------------------------*/

void osstyleXP_CloseThemeData(void)
{
    osstyleXP_CloseTheme(i_STYLEXP.theme);
    i_STYLEXP.theme = NULL;
}

/*---------------------------------------------------------------------------*/

void osstyleXP_GetThemeBackgroundContentRect(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pBoundingRect, RECT *pContentRect)
{
    HRESULT res = i_STYLEXP.GetThemeBackgroundContentRect(hTheme, hdc, iPartId, iStateId, pBoundingRect, pContentRect);
    cassert_unref(res == S_OK, res);
}

/*---------------------------------------------------------------------------*/

void osstyleXP_DrawThemeBackground2(HTHEME theme, int iPartId, int iStateId, HDC hdc, const RECT *rc)
{
    HRESULT res = i_STYLEXP.DrawThemeBackground(theme, hdc, iPartId, iStateId, rc, NULL);
    cassert_unref(res == S_OK, res);
}

/*---------------------------------------------------------------------------*/

void osstyleXP_DrawThemeBackground(HWND hwnd, HDC hdc, int iPartId, int iStateId, const BOOL draw_parent_bg, const RECT *rc, RECT *border)
{
    HRESULT res = 0;
    cassert_no_null(i_STYLEXP.theme);
    if (draw_parent_bg == TRUE)
    {
        if (i_STYLEXP.DrawThemeParentBackgroundEx != NULL)
        {
            if (i_STYLEXP.IsThemeBackgroundPartiallyTransparent(i_STYLEXP.theme, iPartId, iStateId) == TRUE)
                i_STYLEXP.DrawThemeParentBackgroundEx(hwnd, hdc, DTPB_WINDOWDC | DTPB_USECTLCOLORSTATIC, (RECT *)rc);
        }
    }

    res = i_STYLEXP.DrawThemeBackground(i_STYLEXP.theme, hdc, iPartId, iStateId, rc, NULL);
    cassert_unref(res == S_OK, res);

    if (border != NULL)
    {
        res = i_STYLEXP.GetThemeBackgroundContentRect(i_STYLEXP.theme, hdc, iPartId, iStateId, rc, border);
        cassert_unref(res == S_OK, res);
    }
}

/*---------------------------------------------------------------------------*/

void osstyleXP_DrawNonThemedButtonBackground(HWND hwnd, HDC hdc, BOOL has_focus, UINT state, const RECT *rc, RECT *border)
{
    RECT rcback;
    HBRUSH brush = NULL;
    cassert_no_null(border);

    {
        HWND parent = GetParent(hwnd);
        if (parent != NULL)
            brush = (HBRUSH)SendMessage(parent, WM_CTLCOLORBTN, (WPARAM)hdc, (LPARAM)hwnd);
        else
            brush = (HBRUSH)GetStockObject(GRAY_BRUSH);
    }

    FillRect(hdc, rc, brush);

    rcback = *border;
    if (has_focus & ((state & DFCS_PUSHED) == 0))
        InflateRect(&rcback, -1, -1);

    DrawFrameControl(hdc, &rcback, DFC_BUTTON, state);
    InflateRect(border, -4, -4);
}

/*---------------------------------------------------------------------------*/

void osstyleXP_DrawThemeEdge(HDC hdc, int iPartId, int iStateId, const RECT *rc)
{
    HRESULT res = 0;
    cassert_no_null(i_STYLEXP.theme);
    i_STYLEXP.DrawThemeEdge(i_STYLEXP.theme, hdc, iPartId, iStateId, rc, EDGE_BUMP, BF_TOP | BF_LEFT | BF_RIGHT | BF_BOTTOM, NULL);
    cassert_unref(res == S_OK, res);
}

/*---------------------------------------------------------------------------*/

BOOL osstyleXP_HasThemeFont(HDC hdc, int iPartId, int iStateId, int iPropId)
{
    LOGFONTW font;
    HRESULT res = 0;
    cassert_no_null(i_STYLEXP.theme);
    res = i_STYLEXP.GetThemeFont(i_STYLEXP.theme, hdc, iPartId, iStateId, iPropId, &font);
    return (BOOL)(res == S_OK);
}

/*---------------------------------------------------------------------------*/

void osstyleXP_DrawThemeText2(HTHEME theme, HDC hdc, int iPartId, int iStateId, const WCHAR *text, int num_chars, DWORD flags, const RECT *rc)
{
    HRESULT res = 0;
    cassert_no_null(theme);
    res = i_STYLEXP.DrawThemeText(theme, hdc, iPartId, iStateId, text, (int)num_chars, flags, 0, rc);
    cassert_unref(res == S_OK, res);
}

/*---------------------------------------------------------------------------*/

void osstyleXP_DrawThemeText(HDC hdc, int iPartId, int iStateId, const WCHAR *text, uint32_t num_chars, DWORD flags, const RECT *rc)
{
    HRESULT res = 0;
    cassert_no_null(i_STYLEXP.theme);
    res = i_STYLEXP.DrawThemeText(i_STYLEXP.theme, hdc, iPartId, iStateId, text, (int)num_chars, flags, 0, rc);
    cassert_unref(res == S_OK, res);
}
