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

#if !defined(__UNIX__)
#error This file is for Unix/Unix-like system
#endif

static endian_t i_ENDIANNESS = ENUM_MAX(endian_t);
union i_check_endianness
{
    unsigned char bytes[4];
    uint32_t value;
};
static const uint32_t i_LITTLE_ENDIAN = 0x03020100;
static const uint32_t i_BIG_ENDIAN = 0x00010203;

/*---------------------------------------------------------------------------*/

platform_t osbs_platform(void)
{
#if defined(__MACOS__)
    return ekMACOS;
#elif defined(__LINUX__)
    return ekLINUX;
#elif defined(__IOS__)
    return ekIOS;
#else
#error
#endif
}

/*---------------------------------------------------------------------------*/

win_t osbs_windows(void)
{
    return ekWIN_NO;
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
