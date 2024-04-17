/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osbs.c
 *
 */

/* Osbs library (Operating System Basic Services) */

#include "osbs.h"
#include "osbs.inl"
#include "bmutex.h"
#include "log.h"
#include "log.inl"
#include <sewer/sewer.h>
#include <sewer/blib.h>
#include <sewer/bmath.h>
#include <sewer/bmem.h>
#include <sewer/bmem.inl>
#include <sewer/cassert.h>

static uint32_t i_NUM_USERS = 0;
static Mutex *i_MUTEX = NULL;
static uint32_t i_NUM_BARRIERS_ALLOC = 0;
static uint32_t i_NUM_BARRIERS_DEALLOC = 0;
static uint32_t i_NUM_DIRECTORIES_OPENED = 0;
static uint32_t i_NUM_DIRECTORIES_CLOSED = 0;
static uint32_t i_NUM_FILES_OPENED = 0;
static uint32_t i_NUM_FILES_CLOSED = 0;
static uint32_t i_NUM_MUTEX_ALLOC = 0;
static uint32_t i_NUM_MUTEX_DEALLOC = 0;
static uint32_t i_NUM_PROCS_ALLOC = 0;
static uint32_t i_NUM_PROCS_DEALLOC = 0;
static uint32_t i_NUM_DLIBS_ALLOC = 0;
static uint32_t i_NUM_DLIBS_DEALLOC = 0;
static uint32_t i_NUM_THREADS_ALLOC = 0;
static uint32_t i_NUM_THREADS_DEALLOC = 0;
static uint32_t i_NUM_SOCKETS_ALLOC = 0;
static uint32_t i_NUM_SOCKETS_DEALLOC = 0;

/*---------------------------------------------------------------------------*/

static void i_osbs_atexit(void)
{
    cassert(i_NUM_USERS == 0);
}

/*---------------------------------------------------------------------------*/

void osbs_start(void)
{
    if (i_NUM_USERS == 0)
    {
        cassert(sizeof(bool_t) == 1);
        cassert(sizeof(byte_t) == 1);
        cassert(sizeof(char_t) == 1);
        cassert(sizeof(uint8_t) == 1);
        cassert(sizeof(uint16_t) == 2);
        cassert(sizeof(uint32_t) == 4);
        cassert(sizeof(uint64_t) == 8);
        cassert(sizeof(enum_t) == 4);
        cassert(sizeof(real32_t) == 4);
        cassert(sizeof(real64_t) == 8);
        cassert((1 == 1) == TRUE);
        cassert((1 != 1) == FALSE);
#if defined(__x86__)
        cassert(sizeofptr == 4);
#elif defined(__x64__)
        cassert(sizeofptr == 8);
#elif defined(__ARM__)
        cassert(sizeofptr == 4);
#elif defined(__ARM64__)
        cassert(sizeofptr == 8);
#endif

        i_NUM_USERS = 1;
        sewer_start();
        _log_start();
        _osbs_start_sockets();
        blib_atexit(i_osbs_atexit);
    }
    else
    {
        i_NUM_USERS += 1;
    }
}

/*---------------------------------------------------------------------------*/

void osbs_finish(void)
{
    cassert(i_NUM_USERS > 0);
    if (i_NUM_USERS == 1)
    {
        _osbs_finish_sockets();
        sewer_finish();
        _log_finish();

        i_NUM_USERS = 0;

        if (i_NUM_BARRIERS_ALLOC != i_NUM_BARRIERS_DEALLOC)
            log_printf("Non-dealloc Barriers: %u/%u", i_NUM_BARRIERS_ALLOC, i_NUM_BARRIERS_DEALLOC);

        if (i_NUM_DIRECTORIES_OPENED != i_NUM_DIRECTORIES_CLOSED)
            log_printf("Non-closed Directories: %u/%u", i_NUM_DIRECTORIES_OPENED, i_NUM_DIRECTORIES_CLOSED);

        if (i_NUM_FILES_OPENED != i_NUM_FILES_CLOSED)
            log_printf("Non-closed Files: %u/%u", i_NUM_FILES_OPENED, i_NUM_FILES_CLOSED);

        if (i_NUM_MUTEX_ALLOC != i_NUM_MUTEX_DEALLOC)
            log_printf("Non-dealloc Mutex: %u/%u", i_NUM_MUTEX_ALLOC, i_NUM_MUTEX_DEALLOC);

        if (i_NUM_PROCS_ALLOC != i_NUM_PROCS_DEALLOC)
            log_printf("Non-dealloc Procs: %u/%u", i_NUM_PROCS_ALLOC, i_NUM_PROCS_DEALLOC);

        if (i_NUM_DLIBS_ALLOC != i_NUM_DLIBS_DEALLOC)
            log_printf("Non-dealloc DLibs: %u/%u", i_NUM_DLIBS_ALLOC, i_NUM_DLIBS_DEALLOC);

        if (i_NUM_THREADS_ALLOC != i_NUM_THREADS_DEALLOC)
            log_printf("Non-dealloc Threads: %u/%u", i_NUM_THREADS_ALLOC, i_NUM_THREADS_DEALLOC);

        if (i_NUM_SOCKETS_ALLOC != i_NUM_SOCKETS_DEALLOC)
            log_printf("Non-closed Sockets: %u/%u", i_NUM_SOCKETS_ALLOC, i_NUM_SOCKETS_DEALLOC);
    }
    else
    {
        i_NUM_USERS -= 1;
    }
}

/*---------------------------------------------------------------------------*/

void osbs_memory_mt(Mutex *mutex)
{
    i_MUTEX = mutex;
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_incr(uint32_t *value)
{
    if (i_MUTEX != NULL)
    {
        bmutex_lock(i_MUTEX);
        *value += 1;
        bmutex_unlock(i_MUTEX);
    }
    else
    {
        *value += 1;
    }
}

/*---------------------------------------------------------------------------*/

void _osbs_directory_alloc(void)
{
    i_incr(&i_NUM_DIRECTORIES_OPENED);
}

/*---------------------------------------------------------------------------*/

void _osbs_file_alloc(void)
{
    i_incr(&i_NUM_FILES_OPENED);
}

/*---------------------------------------------------------------------------*/

void _osbs_mutex_alloc(void)
{
    i_incr(&i_NUM_MUTEX_ALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_proc_alloc(void)
{
    i_incr(&i_NUM_PROCS_ALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_dlib_alloc(void)
{
    i_incr(&i_NUM_DLIBS_ALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_thread_alloc(void)
{
    i_incr(&i_NUM_THREADS_ALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_socket_alloc(void)
{
    i_incr(&i_NUM_SOCKETS_ALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_directory_dealloc(void)
{
    i_incr(&i_NUM_DIRECTORIES_CLOSED);
}

/*---------------------------------------------------------------------------*/

void _osbs_file_dealloc(void)
{
    i_incr(&i_NUM_FILES_CLOSED);
}

/*---------------------------------------------------------------------------*/

void _osbs_mutex_dealloc(void)
{
    i_incr(&i_NUM_MUTEX_DEALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_proc_dealloc(void)
{
    i_incr(&i_NUM_PROCS_DEALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_dlib_dealloc(void)
{
    i_incr(&i_NUM_DLIBS_DEALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_thread_dealloc(void)
{
    i_incr(&i_NUM_THREADS_DEALLOC);
}

/*---------------------------------------------------------------------------*/

void _osbs_socket_dealloc(void)
{
    i_incr(&i_NUM_SOCKETS_DEALLOC);
}
