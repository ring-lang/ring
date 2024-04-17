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

#include "bfile.h"

#if !defined(__LINUX__)
#error This file is only for Linux system
#endif

#include <sewer/cassert.h>
#include <sewer/unicode.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#define MAX_PATH 512

ssize_t readlink(const char *pathname, char *buf, size_t bufsiz);

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_exec(char_t *pathname, const uint32_t size)
{
    size_t lsize = readlink("/proc/self/exe", pathname, size);
    pathname[lsize] = '\0';
    return lsize;
}

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_data(char_t *pathname, const uint32_t size)
{
    struct passwd *pw = getpwuid(getuid());
    uint32_t s;
    unicode_convers((const char_t *)pw->pw_dir, pathname, ekUTF8, ekUTF8, size);
    s = unicode_nbytes(pathname, ekUTF8);
    return unicode_convers("/.config", pathname + s - 1, ekUTF8, ekUTF8, size - s);
}

/*---------------------------------------------------------------------------*/

uint32_t bfile_dir_home(char_t *pathname, const uint32_t size)
{
    struct passwd *pw = getpwuid(getuid());
    return unicode_convers((const char_t *)pw->pw_dir, pathname, ekUTF8, ekUTF8, size);
}
