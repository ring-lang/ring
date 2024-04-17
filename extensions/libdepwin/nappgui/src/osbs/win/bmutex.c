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

#include "osbs.inl"
#include "bmutex.h"
#include <sewer/cassert.h>

#if !defined(__WINDOWS__)
#error This file is for Windows system
#endif

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <sewer/warn.hxx>

/*---------------------------------------------------------------------------*/

Mutex *bmutex_create(void)
{
    HANDLE mutex = CreateMutex(NULL, FALSE, NULL);
    cassert_no_null(mutex);
    _osbs_mutex_alloc();
    return (Mutex *)mutex;
}

/*---------------------------------------------------------------------------*/

void bmutex_close(Mutex **mutex)
{
    BOOL ok;
    cassert_no_null(mutex);
    cassert_no_null(*mutex);
    ok = CloseHandle((HANDLE)*mutex);
    cassert(ok != 0);
    _osbs_mutex_dealloc();
    *mutex = NULL;
}

/*---------------------------------------------------------------------------*/

void bmutex_lock(Mutex *mutex)
{
    DWORD dwWaitResult = 0;
    cassert_no_null(mutex);
    dwWaitResult = WaitForSingleObject((HANDLE)mutex, INFINITE);
    cassert(dwWaitResult == WAIT_OBJECT_0);
}

/*---------------------------------------------------------------------------*/

void bmutex_unlock(Mutex *mutex)
{
    BOOL ok = FALSE;
    cassert_no_null(mutex);
    ok = ReleaseMutex((HANDLE)mutex);
    cassert(ok != 0);
}
