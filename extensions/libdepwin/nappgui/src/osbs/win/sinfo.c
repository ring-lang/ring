/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: sinfo.c
 *
 */

/* Machine info */

#include "osbs.h"
#include <sewer/cassert.h>
#include <sewer/unicode.h>

#if !defined(__WINDOWS__)
#error This file is for Windows
#endif

#include <sewer/nowarn.hxx>

#include <Windows.h>
#undef __VERSION_HELPERS__

#if _MSC_VER >= 1800
#define __VERSION_HELPERS__
#endif

#if defined __VERSION_HELPERS__
#include <VersionHelpers.h>
#endif

#include <sewer/warn.hxx>

static win_t i_WIN_VERSION = ENUM_MAX(win_t);
static endian_t i_ENDIANNESS = ENUM_MAX(endian_t);
union i_check_endianness
{
    unsigned char bytes[4];
    uint32_t value;
};
static const uint32_t i_LITTLE_ENDIAN = 0x03020100;
static const uint32_t i_BIG_ENDIAN = 0x00010203;
static const uint32_t i_PDP_ENDIAN = 0x01000302;

/*---------------------------------------------------------------------------*/

platform_t osbs_platform(void)
{
    return ekWINDOWS;
}

/*---------------------------------------------------------------------------*/

static win_t i_win_version(void)
{
#if defined(__VERSION_HELPERS__)
#if defined(_WIN32_WINNT_WIN10)
    if (IsWindows10OrGreater() == TRUE)
        return ekWIN_10;
#endif
    if (IsWindows8Point1OrGreater() == TRUE)
        return ekWIN_81;
    if (IsWindows8OrGreater() == TRUE)
        return ekWIN_8;
    if (IsWindows7SP1OrGreater() == TRUE)
        return ekWIN_71;
    if (IsWindows7OrGreater() == TRUE)
        return ekWIN_7;
    if (IsWindowsVistaSP2OrGreater() == TRUE)
        return ekWIN_VI2;
    if (IsWindowsVistaSP1OrGreater() == TRUE)
        return ekWIN_VI1;
    if (IsWindowsVistaOrGreater() == TRUE)
        return ekWIN_VI;
    if (IsWindowsXPSP3OrGreater() == TRUE)
        return ekWIN_XP3;
    if (IsWindowsXPSP2OrGreater() == TRUE)
        return ekWIN_XP2;
    if (IsWindowsXPSP1OrGreater() == TRUE)
        return ekWIN_XP1;
    if (IsWindowsXPOrGreater() == TRUE)
        return ekWIN_XP;
    if (IsWindowsVersionOrGreater(HIBYTE(_WIN32_WINNT_WIN2K), LOBYTE(_WIN32_WINNT_WIN2K), 0))
        return ekWIN_2K;
    if (IsWindowsVersionOrGreater(HIBYTE(_WIN32_WINNT_NT4), LOBYTE(_WIN32_WINNT_NT4), 0))
        return ekWIN_NT4;
    return ekWIN_9x;
#else
    BOOL ok;
    OSVERSIONINFO info;
    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    ok = GetVersionEx(&info);
    cassert(ok != 0);
    if (info.dwMajorVersion < 5)
    {
        return ekWIN_2K;
    }
    else if (info.dwMajorVersion == 5)
    {
        if (info.dwMinorVersion < 1)
            return ekWIN_2K;
        else
            return ekWIN_XP;
    }
    else if (info.dwMajorVersion == 6)
    {
        if (info.dwMinorVersion == 0)
            return ekWIN_VI;
        else if (info.dwMinorVersion == 1)
            return ekWIN_7;
        else if (info.dwMinorVersion <= 3)
            return ekWIN_8;
        cassert(FALSE);
        return ekWIN_8;
    }
    else if (info.dwMajorVersion > 6 && info.dwMajorVersion < 10)
    {
        cassert(FALSE);
        return ekWIN_8;
    }
    else if (info.dwMajorVersion == 10)
    {
        if (info.dwMinorVersion == 0)
        {
            return ekWIN_10;
        }
        else
        {
            cassert(FALSE);
            return ekWIN_10;
        }
    }
    else
    {
        cassert(FALSE);
        return ekWIN_10;
    }
#endif
}

/*---------------------------------------------------------------------------*/

win_t osbs_windows(void)
{
    if (i_WIN_VERSION == ENUM_MAX(win_t))
        i_WIN_VERSION = i_win_version();
    return i_WIN_VERSION;
}

/*---------------------------------------------------------------------------*/

endian_t osbs_endian(void)
{
    if (i_ENDIANNESS == ENUM_MAX(endian_t))
    {
        union i_check_endianness i_O32_HOST_ORDER = {{0, 1, 2, 3}};
        uint32_t endianness = i_O32_HOST_ORDER.value;
        cassert(endianness == i_LITTLE_ENDIAN);
        if (endianness == i_LITTLE_ENDIAN)
            i_ENDIANNESS = ekLITEND;
        else if (endianness == i_BIG_ENDIAN)
            i_ENDIANNESS = ekBIGEND;
    }

    return i_ENDIANNESS;
}
