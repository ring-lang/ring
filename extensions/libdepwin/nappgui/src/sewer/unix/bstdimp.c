/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bstdimp.c
 *
 */

/* Basic standard functions */

#include "bstd.h"
#include "blib.h"

#if !defined(__UNIX__)
#error This file is for Unix/Unix-like system
#endif

#include "bmem.h"
#include "cassert.h"
#include "ptr.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

/*---------------------------------------------------------------------------*/

uint32_t bstd_sprintf(char_t *buffer, const uint32_t size, const char_t *format, ...)
{
    int length;
    va_list args;
    setlocale(LC_NUMERIC, "C");
    va_start(args, format);
    length = vsnprintf((char *)buffer, (size_t)size, (const char *)format, args);
    va_end(args);
    cassert(length >= 0);
    return (uint32_t)length;
}

/*---------------------------------------------------------------------------*/

uint32_t bstd_vsprintf(char_t *buffer, const uint32_t size, const char_t *format, va_list args)
{
    int length;
    cassert_no_null(format);
    setlocale(LC_NUMERIC, "C");
    length = vsnprintf((char *)buffer, (size_t)size, (const char *)format, args);
    cassert(length >= 0);
    return (uint32_t)length;
}

/*---------------------------------------------------------------------------*/

uint32_t bstd_printf(const char_t *format, ...)
{
    int handle = STDOUT_FILENO;
    int length;
    char sbuffer[1024];
    char *dbuffer = NULL;
    char *buffer = NULL;
    ssize_t res = 0;

    {
        va_list args;
        setlocale(LC_NUMERIC, "C");
        va_start(args, format);
        length = vsnprintf(NULL, 0, format, args);
        va_end(args);
    }

    if (length < 1024)
    {
        buffer = sbuffer;
    }
    else
    {
        dbuffer = (char *)bmem_malloc((uint32_t)length + 1);
        buffer = dbuffer;
    }

    {
        va_list args;
        va_start(args, format);
        length = vsprintf(buffer, format, args);
        va_end(args);
    }

    res = write(handle, (const void *)buffer, (size_t)length);
    unref(res);

    if (dbuffer != NULL)
        bmem_free((byte_t *)dbuffer);

    return (uint32_t)length;
}

/*---------------------------------------------------------------------------*/

uint32_t bstd_eprintf(const char_t *format, ...)
{
    int handle = STDERR_FILENO;
    int length;
    char sbuffer[1024];
    char *dbuffer = NULL;
    char *buffer = NULL;
    ssize_t res = 0;

    {
        va_list args;
        setlocale(LC_NUMERIC, "C");
        va_start(args, format);
        length = vsnprintf(NULL, 0, format, args);
        va_end(args);
    }

    if (length < 1024)
    {
        buffer = sbuffer;
    }
    else
    {
        dbuffer = (char *)bmem_malloc((uint32_t)length + 1);
        buffer = dbuffer;
    }

    {
        va_list args;
        va_start(args, format);
        length = vsprintf(buffer, format, args);
        va_end(args);
    }

    res = write(handle, (const void *)buffer, (size_t)length);
    unref(res);

    if (dbuffer != NULL)
        bmem_free((byte_t *)dbuffer);

    return (uint32_t)length;
}

/*---------------------------------------------------------------------------*/

uint32_t bstd_writef(const char_t *str)
{
    size_t size = strlen(str);
    ssize_t wsize = write(STDOUT_FILENO, (const void *)str, size);
    return (uint32_t)wsize;
}

/*---------------------------------------------------------------------------*/

uint32_t bstd_ewritef(const char_t *str)
{
    size_t size = strlen(str);
    ssize_t wsize = write(STDERR_FILENO, (const void *)str, size);
    return (uint32_t)wsize;
}

/*---------------------------------------------------------------------------*/

bool_t bstd_read(byte_t *data, const uint32_t size, uint32_t *rsize)
{
    ssize_t lrsize = read(STDIN_FILENO, (void *)data, (size_t)size);
    ptr_assign(rsize, (uint32_t)lrsize);
    return lrsize >= 0 ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t bstd_write(const byte_t *data, const uint32_t size, uint32_t *wsize)
{
    ssize_t lwsize = write(STDOUT_FILENO, (const void *)data, (size_t)size);
    ptr_assign(wsize, (uint32_t)lwsize);
    return lwsize >= 0 ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t bstd_ewrite(const byte_t *data, const uint32_t size, uint32_t *wsize)
{
    ssize_t lwsize = write(STDERR_FILENO, (const void *)data, (size_t)size);
    ptr_assign(wsize, (uint32_t)lwsize);
    return lwsize >= 0 ? TRUE : FALSE;
}

/*---------------------------------------------------------------------------*/

void blib_debug_break(void)
{
    raise(SIGSTOP);
}
