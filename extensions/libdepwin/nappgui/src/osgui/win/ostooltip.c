/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ostooltip.c
 *
 */

/* Tooltips */

#include "ostooltip.inl"
#include "osgui_win.inl"
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

#include <sewer/nowarn.hxx>
#include <Commctrl.h>
#include <sewer/warn.hxx>

/*---------------------------------------------------------------------------*/

static HWND i_create_tooltip(HWND control_hwnd, const char_t *text)
{
    HWND parent_hwnd = NULL;
    HINSTANCE instance = NULL;
    HWND tooltip_hwnd = NULL;
    TOOLINFO ti = {0};
    WCHAR wtext[WCHAR_BUFFER_SIZE];

    parent_hwnd = NULL;
    instance = _osgui_instance();

    tooltip_hwnd = CreateWindowEx(
        0, TOOLTIPS_CLASS, NULL,
        WS_POPUP | TTS_ALWAYSTIP /*| TTS_BALLOON*/,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        parent_hwnd,
        (HMENU)NULL,
        instance, NULL);

    cassert_no_null(tooltip_hwnd);

    ti.cbSize = sizeof(ti);
    ti.hwnd = parent_hwnd;
    ti.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
    ti.uId = (UINT_PTR)control_hwnd;
    unicode_convers(text, (char_t *)wtext, ekUTF8, kWINDOWS_UNICODE, sizeof(wtext));
    ti.lpszText = wtext;
    SendMessage(tooltip_hwnd, TTM_ADDTOOL, 0, (LPARAM)&ti);
    return tooltip_hwnd;
}

/*---------------------------------------------------------------------------*/

static void i_update_tooltip(HWND control_hwnd, HWND tooltip_hwnd, const char_t *text)
{
    HWND parent_hwnd = NULL;
    TOOLINFO ti = {0};
    WCHAR wtext[WCHAR_BUFFER_SIZE];
    parent_hwnd = NULL;
    ti.cbSize = sizeof(ti);
    ti.hwnd = parent_hwnd;
    ti.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
    ti.uId = (UINT_PTR)control_hwnd;
    unicode_convers(text, (char_t *)wtext, ekUTF8, kWINDOWS_UNICODE, sizeof(wtext));
    ti.lpszText = wtext;
    SendMessage(tooltip_hwnd, TTM_UPDATETIPTEXT, 0, (LPARAM)&ti);
}

/*---------------------------------------------------------------------------*/

static void i_destroy_tooltip(HWND *tooltip_hwnd, HWND control_hwnd)
{
    TOOLINFO ti;
    BOOL ret = 0;
    cassert_no_null(tooltip_hwnd);
    ti.cbSize = sizeof(ti);
    ti.uFlags = TTF_IDISHWND;
    ti.hwnd = NULL;
    ti.uId = (UINT_PTR)control_hwnd;
    SendMessage(*tooltip_hwnd, TTM_DELTOOL, 0, (LPARAM)&ti);
    ret = DestroyWindow(*tooltip_hwnd);
    cassert(ret != 0);
    *tooltip_hwnd = NULL;
}

/*---------------------------------------------------------------------------*/

void _ostooltip_set_text(HWND *tooltip_hwnd, HWND control_hwnd, const char_t *text)
{
    cassert_no_null(tooltip_hwnd);
    if (*tooltip_hwnd == NULL && text != NULL)
    {
        *tooltip_hwnd = i_create_tooltip(control_hwnd, text);
    }
    else if (*tooltip_hwnd != NULL && text != NULL)
    {
        i_update_tooltip(control_hwnd, *tooltip_hwnd, text);
    }
    else if (*tooltip_hwnd != NULL && text == NULL)
    {
        i_destroy_tooltip(tooltip_hwnd, control_hwnd);
    }
    else
    {
        cassert(*tooltip_hwnd == NULL && text == NULL);
    }
}

/*---------------------------------------------------------------------------*/

void _ostooltip_destroy_optional(HWND *tooltip_hwnd, HWND control_hwnd)
{
    cassert_no_null(tooltip_hwnd);
    if (*tooltip_hwnd != NULL)
        i_destroy_tooltip(tooltip_hwnd, control_hwnd);
}
