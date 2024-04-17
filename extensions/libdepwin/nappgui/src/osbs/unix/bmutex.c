/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bmutex.c
 *
 */

/* Basic synchronization services */

#include "bmutex.h"
#include "osbs.inl"
#include <sewer/cassert.h>

#if !defined(__UNIX__)
#error This file is for Unix/Unix-like system
#endif

#include <stdlib.h>
#include <pthread.h>

/*---------------------------------------------------------------------------*/

Mutex *bmutex_create(void)
{
    pthread_mutex_t *mutex;
    int ret;
    mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    ret = pthread_mutex_init(mutex, NULL);
    cassert_unref(ret == 0, ret);
    _osbs_mutex_alloc();
    return (Mutex *)mutex;
}

/*---------------------------------------------------------------------------*/

void bmutex_close(Mutex **mutex)
{
    void *mem;
    int ret;
    cassert_no_null(mutex);
    cassert_no_null(*mutex);
    mem = *(void **)mutex;
    ret = pthread_mutex_destroy((pthread_mutex_t *)(*mutex));
    cassert_unref(ret == 0, ret);
    free(mem);
    _osbs_mutex_dealloc();
    *mutex = NULL;
}

/*---------------------------------------------------------------------------*/

void bmutex_lock(Mutex *mutex)
{
    int ret;
    cassert_no_null(mutex);
    ret = pthread_mutex_lock((pthread_mutex_t *)mutex);
    cassert_unref(ret == 0, ret);
}

/*---------------------------------------------------------------------------*/

void bmutex_unlock(Mutex *mutex)
{
    int ret;
    cassert_no_null(mutex);
    ret = pthread_mutex_unlock((pthread_mutex_t *)mutex);
    cassert_unref(ret == 0, ret);
}

/*---------------------------------------------------------------------------*/
