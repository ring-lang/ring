/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: log.c
 *
 */

/* Manages an application log */

#include "log.h"
#include "log.inl"
#include "bfile.h"
#include "bmutex.h"
#include "btime.h"
#include <sewer/blib.h>
#include <sewer/cassert.h>
#include <sewer/bstd.h>

/*---------------------------------------------------------------------------*/

static Mutex *i_LOG_MUTEX = NULL;
static bool_t i_LOG_STDOUT = TRUE;
static bool_t i_LOG_STDERR = FALSE;
static char_t i_LOG_FILEPATH[512] = "";

/*---------------------------------------------------------------------------*/

void _log_start(void)
{
    cassert(i_LOG_MUTEX == NULL);
    i_LOG_MUTEX = bmutex_create();
}

/*---------------------------------------------------------------------------*/

void _log_finish(void)
{
    cassert(i_LOG_MUTEX != NULL);
    bmutex_close(&i_LOG_MUTEX);
}

/*---------------------------------------------------------------------------*/

static void i_lock(void)
{
    if (i_LOG_MUTEX != NULL)
        bmutex_lock(i_LOG_MUTEX);
}

/*---------------------------------------------------------------------------*/

static void i_unlock(void)
{
    if (i_LOG_MUTEX != NULL)
        bmutex_unlock(i_LOG_MUTEX);
}

/*---------------------------------------------------------------------------*/

uint32_t log_printf(const char_t *format, ...)
{
    char_t time_buffer[32];
    char_t msg_buffer[1024];
    uint32_t time_size = 0;
    uint32_t msg_size = 0;
    uint32_t total_size = 0;

    {
        Date date;
        btime_date(&date);
        time_size = bstd_sprintf(time_buffer, 32, "[%02d:%02d:%02d] ", date.hour, date.minute, date.second);
    }

    {
        va_list args;
        va_start(args, format);
        msg_size = bstd_vsprintf(msg_buffer, 1024, format, args);
        cassert(msg_size < 1024);
        va_end(args);
    }

    i_lock();

    if (i_LOG_STDOUT == TRUE)
        total_size = bstd_printf("%s%s\n", time_buffer, msg_buffer);

    if (i_LOG_STDERR == TRUE)
        total_size = bstd_eprintf("%s%s\n", time_buffer, msg_buffer);

    if (i_LOG_FILEPATH[0] != '\0')
    {
        File *file = bfile_open(i_LOG_FILEPATH, ekAPPEND, NULL);
        if (file != NULL)
        {
            bfile_write(file, (const byte_t *)time_buffer, time_size, NULL, NULL);
            bfile_write(file, (const byte_t *)msg_buffer, msg_size, NULL, NULL);
            bfile_write(file, (const byte_t *)"\r\n", 2, NULL, NULL);
            bfile_close(&file);
        }
    }

    i_unlock();
    return total_size;
}

/*---------------------------------------------------------------------------*/

void log_output(const bool_t std, const bool_t err)
{
    i_lock();
    i_LOG_STDOUT = std;
    i_LOG_STDERR = err;
    i_unlock();
}

/*---------------------------------------------------------------------------*/

void log_file(const char_t *pathname)
{
    i_lock();
    if (pathname != NULL)
    {
        File *file = NULL;
        blib_strcpy(i_LOG_FILEPATH, 512, pathname);
        file = bfile_create(i_LOG_FILEPATH, NULL);
        if (file != NULL)
            bfile_close(&file);
    }
    else
    {
        i_LOG_FILEPATH[0] = '\0';
    }
    i_unlock();
}

/*---------------------------------------------------------------------------*/

const char_t *log_get_file(void)
{
    if (i_LOG_FILEPATH[0] == '\0')
        return NULL;
    else
        return i_LOG_FILEPATH;
}
