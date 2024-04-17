/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscomwin.c
 *
 */

/* Operating System native common windows */

#include "oscomwin.h"
#include "oscontrol_win.inl"
#include "oswindow_win.inl"
#include <draw2d/color.h>
#include <core/event.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is only for Windows
#endif

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <ShlObj.h>
#include <sewer/warn.hxx>

/*---------------------------------------------------------------------------*/

static char_t i_FILENAME[4 * MAX_PATH];
typedef struct _cdata_t CData;

struct _cdata_t
{
    LONG x;
    LONG y;
    align_t halign;
    align_t valign;
    WCHAR title[256];
};

/*---------------------------------------------------------------------------*/

static void i_allowed_file_types(const char_t **ftypes, const uint32_t size, TCHAR *file_types, const uint32_t bufsize, BOOL *dirselect)
{
    uint32_t lbufsize = bufsize;
    cassert_no_null(file_types);
    cassert_no_null(dirselect);
    file_types[0] = '\0';

    if (ftypes != NULL)
    {
        if (size == 1 && strcmp((const char *)ftypes[0], "..DIR..") == 0)
        {
            *dirselect = TRUE;
        }
        else
        {
            uint32_t i;
            for (i = 0; i < size; ++i)
            {
                TCHAR type[32];
                register uint32_t tsize;
                tsize = unicode_convers(ftypes[i], (char_t *)type, ekUTF8, ekUTF16, sizeof(type));
                cassert(tsize < sizeof(type));
                tsize += 4; // "*."
                if (lbufsize > tsize * 2)
                {
                    register int bytes;
                    bytes = wsprintf(file_types, L"*.%s", type);
                    file_types += bytes + 1;
                    bytes = wsprintf(file_types, L"*.%s", type);
                    file_types += bytes + 1;
                    lbufsize -= tsize * 2;
                }
            }

            *file_types = '\0';
            *dirselect = FALSE;
        }
    }
    else
    {
        int bytes;
        bytes = wsprintf(file_types, L"*.*");
        file_types += bytes + 1;
        bytes = wsprintf(file_types, L"*.*");
        file_types += bytes + 1;
        *file_types = '\0';
        *dirselect = FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static int CALLBACK i_folder_browse(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
    unref(lParam);
    unref(lpData);
    if (uMsg == BFFM_INITIALIZED)
    {
        SendMessage(hwnd, BFFM_SETSELECTION, 1, (LPARAM)i_FILENAME);
        return 1;
    }

    return 0;
}

/*---------------------------------------------------------------------------*/

static void i_force_extension(WCHAR *file, INT buffer_size, const char_t *extension)
{
    WCHAR ext[32];
    WCHAR *file_ext = NULL;
    register uint32_t ext_size;
    ext_size = unicode_convers(extension, (char_t *)ext, ekUTF8, ekUTF16, sizeof(ext));
    cassert(ext_size < sizeof(ext));
    _wcslwr_s(ext, 32);

    {
        int i = 0;
        int last_dot = -1;
        while (file[i] != '\0')
        {
            if (file[i] == '.')
                last_dot = i;
            i++;
        }

        if (last_dot != -1)
            file_ext = file + last_dot + 1;
    }

    if (file_ext != NULL)
        file_ext[0] = '\0';
    else
        wcscat_s(file, buffer_size, L".");

    wcscat_s(file, buffer_size, ext);
}

/*---------------------------------------------------------------------------*/

const char_t *oscomwin_file(OSWindow *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir, const bool_t open)
{
    TCHAR file_types[256];
    BOOL dirselect;
    unref(parent);
    i_allowed_file_types(ftypes, size, file_types, sizeof(file_types), &dirselect);
    if (dirselect == TRUE)
    {
        if (open == TRUE)
        {
            BROWSEINFO bi;
            TCHAR dir[MAX_PATH];
            LPITEMIDLIST item;
            ZeroMemory(&bi, sizeof(bi));
            bi.hwndOwner = _oswindow_hwnd(parent);
            bi.pidlRoot = NULL;
            bi.pszDisplayName = dir;
            bi.lpszTitle = NULL;
            bi.ulFlags = 0;

            if (start_dir != NULL)
            {
                register uint32_t bytes = unicode_convers(start_dir, i_FILENAME, ekUTF8, ekUTF16, sizeof(i_FILENAME));
                cassert_unref(bytes < sizeof(i_FILENAME), bytes);
                bi.lpfn = i_folder_browse;
            }
            else
            {
                bi.lpfn = NULL;
            }

            bi.lParam = 0;
            bi.iImage = -1;

            item = SHBrowseForFolder(&bi);
            if (item != NULL)
            {
                register uint32_t bytes;
                SHGetPathFromIDList(item, dir);
                bytes = unicode_convers((const char_t *)dir, i_FILENAME, ekUTF16, ekUTF8, sizeof(i_FILENAME));
                cassert(bytes < MAX_PATH);
                return i_FILENAME;
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            cassert(FALSE);
            return NULL;
        }
    }
    else
    {
        OPENFILENAME ofn;
        TCHAR file[MAX_PATH];
        BOOL ok;
        ZeroMemory(&ofn, sizeof(ofn));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = NULL;
        ofn.hInstance = NULL;
        ofn.lpstrFilter = file_types;
        ofn.lpstrCustomFilter = NULL;
        ofn.nMaxCustFilter = 0;
        ofn.nFilterIndex = 1;
        ofn.lpstrFile = file;
        ofn.lpstrFile[0] = '\0';
        ofn.nMaxFile = sizeof(file);
        ofn.lpstrFileTitle = NULL;
        ofn.nMaxFileTitle = 0;
        ofn.lpstrInitialDir = NULL;
        ofn.lpstrTitle = NULL;
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

        if (open == TRUE)
            ok = GetOpenFileName(&ofn);
        else
            ok = GetSaveFileName(&ofn);

        if (ok == TRUE)
        {
            register uint32_t bytes;
            if (open == FALSE && size == 1)
                i_force_extension(file, MAX_PATH, ftypes[0]);

            bytes = unicode_convers((const char_t *)file, i_FILENAME, ekUTF16, ekUTF8, sizeof(i_FILENAME));
            cassert(bytes < MAX_PATH);
            return i_FILENAME;
        }
        else
        {
            return NULL;
        }
    }
}

/*---------------------------------------------------------------------------*/

static UINT_PTR CALLBACK i_color_msg(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_INITDIALOG)
    {
        CHOOSECOLOR *col = (CHOOSECOLOR *)lParam;
        CData *cdata = (CData *)col->lCustData;
        RECT rect;
        BOOL ret = GetWindowRect(hwnd, &rect);
        int screen_width = GetSystemMetrics(SM_CXSCREEN);
        int screen_height = GetSystemMetrics(SM_CYSCREEN);
        cassert_unref(ret != 0, ret);

        if (cdata->halign != ekLEFT || cdata->valign != ekTOP)
        {
            switch (cdata->halign)
            {
            case ekLEFT:
            case ekJUSTIFY:
                break;
            case ekCENTER:
                cdata->x -= (rect.right - rect.left) / 2;
                break;
            case ekRIGHT:
                cdata->x -= rect.right - rect.left;
                break;
            }

            switch (cdata->valign)
            {
            case ekTOP:
            case ekJUSTIFY:
                break;
            case ekCENTER:
                cdata->y -= (rect.bottom - rect.top) / 2;
                break;
            case ekRIGHT:
                cdata->y -= rect.bottom - rect.top;
                break;
            }
        }

        // Avoid to show the dialog outside the screen
        if (cdata->x + (rect.right - rect.left) > screen_width)
            cdata->x = screen_width - (rect.right - rect.left);

        if (cdata->y + (rect.bottom - rect.top) > screen_height)
            cdata->y = screen_height - (rect.bottom - rect.top);

        SetWindowPos(hwnd, NULL, cdata->x, cdata->y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        if (cdata->title[0] != 0)
            SetWindowText(hwnd, cdata->title);
    }

    unref(wParam);
    return 0;
}

/*---------------------------------------------------------------------------*/

void oscomwin_color(OSWindow *parent, const char_t *title, const real32_t x, const real32_t y, const align_t halign, const align_t valign, const color_t current, color_t *colors, const uint32_t n, Listener *OnChange)
{
    CHOOSECOLOR col;
    COLORREF cols[16];
    CData cdata;
    register uint32_t i;

    col.lStructSize = sizeof(CHOOSECOLOR);
    col.hwndOwner = NULL;

    if (parent != NULL)
        col.hwndOwner = ((OSControl *)parent)->hwnd;

    col.hInstance = NULL;
    col.rgbResult = _oscontrol_colorref(current);

    for (i = 0; i < 16; ++i)
    {
        if (i < n)
            cols[i] = _oscontrol_colorref(colors[i]);
        else
            cols[i] = _oscontrol_colorref(kCOLOR_WHITE);
    }

    cdata.x = (LONG)x;
    cdata.y = (LONG)y;
    cdata.halign = halign;
    cdata.valign = valign;

    if (title != NULL)
        unicode_convers(title, (char_t *)cdata.title, ekUTF8, ekUTF16, sizeof(cdata.title));
    else
        cdata.title[0] = 0;

    col.lpCustColors = cols;
    col.Flags = CC_ANYCOLOR | CC_RGBINIT | CC_FULLOPEN | CC_ENABLEHOOK;
    col.lCustData = (LPARAM)&cdata;
    col.lpfnHook = i_color_msg;
    col.lpTemplateName = NULL;

    if (ChooseColor(&col) == TRUE)
    {
        color_t c = _oscontrol_from_colorref(col.rgbResult);
        listener_event(OnChange, ekGUI_EVENT_COLOR, NULL, &c, NULL, void, color_t, void);
    }

    listener_destroy(&OnChange);
}
/*
void oscommon_file(OSWindow *owner_window, const uchar_t **allowed_file_types, const uint32_t num_file_types, const bool_t for_open, Listener *OnAccept_listener);
void oscommon_file(
                    OSWindow *owner_window,
                    const uchar_t **allowed_file_types,
                    const uint32_t num_file_types,
                    const bool_t for_open,
                    Listener *OnAccept_listener)
{
    unreferenced(owner_window);
    unreferenced(allowed_file_types);
    unreferenced(num_file_types);
    unreferenced(for_open);
    unreferenced(OnAccept_listener);
    cassert(FALSE);
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_close(void);
void oscommon_colour_close(void)
{
    cassert(FALSE);
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_convert_to_hud(void);
void oscommon_colour_convert_to_hud(void)
{
    cassert(FALSE);
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_set_size(const real32_t width, const real32_t height);
void oscommon_colour_set_size(const real32_t width, const real32_t height)
{
    unreferenced(width);
    unreferenced(height);
    cassert(FALSE);
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_get_size(real32_t *width, real32_t *height);
void oscommon_colour_get_size(real32_t *width, real32_t *height)
{
    unreferenced(width);
    unreferenced(height);
    cassert(FALSE);
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_set_origin(const real32_t x, const real32_t y);
void oscommon_colour_set_origin(const real32_t x, const real32_t y)
{
    unreferenced(x);
    unreferenced(y);
    cassert(FALSE);
}*/

/*---------------------------------------------------------------------------*/

/*
void oscommon_colour_get_origin(real32_t *x, real32_t *y);
void oscommon_colour_get_origin(real32_t *x, real32_t *y)
{
    unreferenced(x);
    unreferenced(y);
    cassert(FALSE);
}*/
