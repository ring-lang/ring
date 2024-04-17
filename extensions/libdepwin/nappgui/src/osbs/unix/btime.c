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

#if !defined(__UNIX__)
#error This file is for Unix/Unix-like system
#endif

#include <sys/time.h>

#if defined(__LINUX__)
#include <time.h>
#endif

/*---------------------------------------------------------------------------*/

static __INLINE uint64_t i_timeval_to_micro(const struct timeval *tv)
{
    cassert_no_null(tv);
    return (uint64_t)tv->tv_sec * 1000000 + (uint64_t)tv->tv_usec;
}

/*---------------------------------------------------------------------------*/

static void i_micro_to_timeval(const uint64_t micro, struct timeval *tv)
{
    cassert_no_null(tv);
    tv->tv_sec = (time_t)(micro / 1000000);
    tv->tv_usec = (suseconds_t)(micro % 1000000);
}

/*---------------------------------------------------------------------------*/

uint64_t btime_now(void)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return i_timeval_to_micro(&now);
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_tm_to_date(const struct tm *tinfo, Date *date)
{
    cassert_no_null(tinfo);
    cassert_no_null(date);
    date->wday = (uint8_t)tinfo->tm_wday;
    date->mday = (uint8_t)tinfo->tm_mday;
    date->month = (uint8_t)(1 + tinfo->tm_mon);
    date->year = 1900 + (int16_t)tinfo->tm_year;
    date->hour = (uint8_t)tinfo->tm_hour;
    date->minute = (uint8_t)tinfo->tm_min;
    date->second = (uint8_t)tinfo->tm_sec;
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_date_to_tm(const Date *date, struct tm *tinfo)
{
    cassert_no_null(date);
    cassert_no_null(tinfo);
    tinfo->tm_wday = date->wday;
    tinfo->tm_mday = date->mday;
    tinfo->tm_mon = date->month - 1;
    tinfo->tm_year = date->year - 1900;
    tinfo->tm_hour = date->hour;
    tinfo->tm_min = date->minute;
    tinfo->tm_sec = date->second;
}

/*---------------------------------------------------------------------------*/

void btime_date(Date *date)
{
    time_t rawtime;
    struct tm *tinfo;
    cassert_no_null(date);
    time(&rawtime);
    tinfo = localtime(&rawtime);
    i_tm_to_date(tinfo, date);
}

/*---------------------------------------------------------------------------*/

uint64_t btime_to_micro(const Date *date)
{
    struct tm tinfo;
    struct timeval tv;
    i_date_to_tm(date, &tinfo);

    /*
    https://stackoverflow.com/questions/38298261/why-there-is-no-inverse-function-for-gmtime-in-libc
	This function performs the reverse translation that localtime does.
	The  mktime() function converts a broken-down time structure, expressed as
    local time, to calendar time representation. The function ignores the values
    supplied by the caller in the tm_wday and tm_yday fields. The value
    specified in the tm_isdst field informs mktime() whether or not daylight
    saving time (DST) is in effect for the time supplied in the tm structure:
    a positive value means DST is in effect;
 */
    tinfo.tm_isdst = 1;
    tv.tv_sec = mktime(&tinfo);
    tv.tv_usec = 0;
    return i_timeval_to_micro(&tv);
}

/*---------------------------------------------------------------------------*/

void btime_to_date(const uint64_t micro, Date *date)
{
    struct timeval tv;
    time_t time;
    struct tm *tinfo;
    i_micro_to_timeval(micro, &tv);
    /* https://stackoverflow.com/questions/9252849/convert-timeval-to-time-t */
    time = (time_t)tv.tv_sec;
    tinfo = localtime(&time);
    i_tm_to_date(tinfo, date);
}
