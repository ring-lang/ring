/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bthread.c
 *
 */

/* Basic threading services */

#include "osbs.inl"
#include "bthread.h"
#include <sewer/cassert.h>

#if !defined(__WINDOWS__)
#error This file is for Windows system
#endif

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <sewer/warn.hxx>

/*---------------------------------------------------------------------------*/

Thread *bthread_create_imp(FPtr_thread_main thmain, void *data)
{
    HANDLE thread = CreateThread(NULL, 0, cast_func_ptr(thmain, LPTHREAD_START_ROUTINE), (LPVOID)data, 0, NULL);
    cassert_no_null(thread);
    _osbs_thread_alloc();
    return (Thread *)thread;
}

/*---------------------------------------------------------------------------*/

int bthread_current_id(void)
{
    return (int)GetCurrentThreadId();
}

/*---------------------------------------------------------------------------*/

void bthread_close(Thread **thread)
{
    BOOL ok;
    cassert_no_null(thread);
    cassert_no_null(*thread);
    ok = CloseHandle((HANDLE)*thread);
    cassert(ok != 0);
    _osbs_thread_dealloc();
    *thread = NULL;
}

/*---------------------------------------------------------------------------*/

bool_t bthread_cancel(Thread *thread)
{
    cassert_no_null(thread);
    return (bool_t)TerminateThread((HANDLE)thread, 0);
}

/*---------------------------------------------------------------------------*/

uint32_t bthread_wait(Thread *thread)
{
    DWORD dwWaitResult = 0;
    cassert_no_null(thread);
    dwWaitResult = WaitForSingleObject((HANDLE)thread, INFINITE);
    if (dwWaitResult == WAIT_OBJECT_0)
    {
        DWORD exit_code = 0;
        if (GetExitCodeThread((HANDLE)thread, &exit_code) != 0)
        {
            return (uint32_t)exit_code;
        }
        else
        {
            cassert_msg(FALSE, "Thread join error");
            return UINT32_MAX;
        }
    }
    else
    {
        cassert_msg(FALSE, "Thread join error");
        return UINT32_MAX;
    }
}

/*---------------------------------------------------------------------------*/

bool_t bthread_finish(Thread *thread, uint32_t *code)
{
    DWORD res = 0;
    cassert_no_null(thread);
    res = WaitForSingleObject((HANDLE)thread, 0);
    if (res == WAIT_OBJECT_0)
    {
        if (code != NULL)
        {
            DWORD exit_code = 0;
            BOOL ok = GetExitCodeThread((HANDLE)thread, &exit_code);
            cassert_unref(ok != 0, ok);
            *code = (uint32_t)exit_code;
        }

        return TRUE;
    }
    else
    {
        cassert(res == WAIT_TIMEOUT);
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

void bthread_sleep(const uint32_t milliseconds)
{
    Sleep(milliseconds);
}
