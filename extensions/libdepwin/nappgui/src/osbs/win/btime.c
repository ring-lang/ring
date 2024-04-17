/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: btime.c
 *
 */

/* Basic time services */

#include "btime.h"
#include <sewer/cassert.h>

#if !defined(__WINDOWS__)
#error This file is for Windows system
#endif

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <sewer/warn.hxx>

#define EPOCHFILETIME (116444736000000000i64)

/*---------------------------------------------------------------------------*/

static uint64_t i_filetime_to_micro(const FILETIME *ft)
{
    LARGE_INTEGER li;
    __int64 t;
    //static int      tzflag;
    cassert_no_null(ft);
    li.LowPart = ft->dwLowDateTime;
    li.HighPart = (LONG)ft->dwHighDateTime;
    t = li.QuadPart;    /* In 100-nanosecond intervals */
    t -= EPOCHFILETIME; /* Offset to the Unix Epoch time */
    t /= 10;            /* In microseconds */
    return t;
}

/*---------------------------------------------------------------------------*/

static void i_micro_to_filetime(const uint64_t micro, FILETIME *ft)
{
    LARGE_INTEGER li;
    __int64 t;
    cassert_no_null(ft);
    t = micro * 10;
    t += EPOCHFILETIME;
    li.QuadPart = t;
    ft->dwLowDateTime = li.LowPart;
    ft->dwHighDateTime = li.HighPart;
}

/*---------------------------------------------------------------------------*/

uint64_t btime_now(void)
{
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    return i_filetime_to_micro(&ft);
}

//static UINT64 FileTimeToMillis(const FILETIME &ft)
//{
//    ULARGE_INTEGER uli;
//    uli.LowPart = ft.dwLowDateTime; // could use memcpy here!
//    uli.HighPart = ft.dwHighDateTime;
//
//    return static_cast<UINT64>(uli.QuadPart/10000);
//}
//
//static void MillisToSystemTime(UINT64 millis, SYSTEMTIME *st)
//{
//    UINT64 multiplier = 10000;
//    UINT64 t = multiplier * millis;
//
//    ULARGE_INTEGER li;
//    li.QuadPart = t;
//    // NOTE, DON'T have to do this any longer because we're putting
//    // in the 64bit UINT directly
//    //li.LowPart = static_cast<DWORD>(t & 0xFFFFFFFF);
//    //li.HighPart = static_cast<DWORD>(t >> 32);
//
//    FILETIME ft;
//    ft.dwLowDateTime = li.LowPart;
//    ft.dwHighDateTime = li.HighPart;
//
//    ::FileTimeToSystemTime(&ft, st);
//}

/*---------------------------------------------------------------------------*/

static __INLINE void i_systime_to_date(const SYSTEMTIME *st, Date *date)
{
    cassert_no_null(st);
    cassert_no_null(date);
    date->wday = (uint8_t)st->wDayOfWeek;
    date->mday = (uint8_t)st->wDay;
    date->month = (uint8_t)st->wMonth;
    date->year = (uint16_t)st->wYear;
    date->hour = (uint8_t)st->wHour;
    date->minute = (uint8_t)st->wMinute;
    date->second = (uint8_t)st->wSecond;
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_date_to_systime(const Date *date, SYSTEMTIME *st)
{
    cassert_no_null(date);
    cassert_no_null(st);
    st->wDayOfWeek = date->wday;
    st->wDay = date->mday;
    st->wMonth = date->month;
    st->wYear = date->year;
    st->wHour = date->hour;
    st->wMinute = date->minute;
    st->wSecond = date->second;
    st->wMilliseconds = 0;
}

/*---------------------------------------------------------------------------*/

void btime_date(Date *date)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    i_systime_to_date(&st, date);
}

/*---------------------------------------------------------------------------*/

uint64_t btime_to_micro(const Date *date)
{
    SYSTEMTIME st;
    FILETIME ft;
    i_date_to_systime(date, &st);
    SystemTimeToFileTime(&st, &ft);
    return i_filetime_to_micro(&ft);
}

/*---------------------------------------------------------------------------*/

void btime_to_date(const uint64_t micro, Date *date)
{
    FILETIME ft;
    SYSTEMTIME st;
    i_micro_to_filetime(micro, &ft);
    FileTimeToSystemTime(&ft, &st);
    i_systime_to_date(&st, date);
}

/*---------------------------------------------------------------------------*/

//void btime_active_wait(const uint32_t milliseconds);
//void btime_active_wait(const uint32_t milliseconds)
//{
//    __int64 current = i_microseconds_from_epoch();
//    current /= 1000;
//
//    for (;;)
//    {
//        __int64 now = i_microseconds_from_epoch();
//        now /= 1000;
//        if (now - current > milliseconds)
//            return;
//    }
//}
