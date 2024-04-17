/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: sinfo.m
 *
 */

/* Machine info */

#include "bfile.h"

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

#include <sewer/nowarn.hxx>
#include <Cocoa/Cocoa.h>
#include <mach-o/dyld.h>
#include <sewer/warn.hxx>

#include <sewer/cassert.h>
#include <sewer/unicode.h>

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_home(char_t *pathname, const uint32_t size)
{
    const char *home = getenv("HOME");
    return unicode_convers((const char_t *)home, pathname, ekUTF8, ekUTF8, size);
}

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_data(char_t *pathname, const uint32_t size)
{
    uint32_t s;
    const char *home = getenv("HOME");
    s = unicode_convers((const char_t *)home, pathname, ekUTF8, ekUTF8, size);
    if (s + 8 < size)
    {
        strcpy(pathname + s - 1, "/Library");
        s += 8;
    }
    return s;
}

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_exec(char_t *pathname, const uint32_t size)
{
    uint32_t lsize = size;
    if (_NSGetExecutablePath((char *)pathname, &lsize) != 0)
    {
        cassert_msg(FALSE, "Buffer too small");
    }

    return lsize;
}
