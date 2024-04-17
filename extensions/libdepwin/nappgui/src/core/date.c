/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: date.c
 *
 */

/* Dates */

#include "date.h"
#include "strings.h"
#include <osbs/btime.h>
#include <sewer/blib.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

Date kDATE_NULL = {0, 0, 0, 0, 0, 0, 0};

/*---------------------------------------------------------------------------*/

Date date_system(void)
{
    Date date;
    btime_date(&date);
    return date;
}

/*---------------------------------------------------------------------------*/

Date date_pack(const int16_t year, const uint8_t month, const uint8_t mday, const uint8_t hour, const uint8_t minute, const uint8_t second)
{
    Date date;
    date.year = year;
    date.month = month;
    date.mday = mday;
    date.hour = hour;
    date.minute = minute;
    date.second = second;
    date.wday = date_weekday(&date);
    return date;
}

/*---------------------------------------------------------------------------*/

static Date i_add_micros(const Date *date, int64_t micros)
{
    uint64_t dmicros = btime_to_micro(date);
    Date ndate;

    if (micros > 0)
        dmicros += (uint64_t)micros;
    else
        dmicros -= (uint64_t)(-micros);

    btime_to_date(dmicros, &ndate);
    return ndate;
}

/*---------------------------------------------------------------------------*/

Date date_add_seconds(const Date *date, int32_t seconds)
{
    return i_add_micros(date, (int64_t)seconds * 1000000);
}

/*---------------------------------------------------------------------------*/

Date date_add_minutes(const Date *date, int32_t minutes)
{
    return i_add_micros(date, (int64_t)minutes * 60 * 1000000);
}

/*---------------------------------------------------------------------------*/

Date date_add_hours(const Date *date, int32_t hours)
{
    return i_add_micros(date, (int64_t)hours * 60 * 60 * 1000000);
}

/*---------------------------------------------------------------------------*/

Date date_add_days(const Date *date, int32_t days)
{
    return i_add_micros(date, (int64_t)days * 24 * 60 * 60 * 1000000);
}

/*---------------------------------------------------------------------------*/

int16_t date_year(void)
{
    Date date;
    btime_date(&date);
    return date.year;
}

/*---------------------------------------------------------------------------*/

int date_cmp(const Date *date1, const Date *date2)
{
    cassert_no_null(date1);
    cassert_no_null(date2);
    if (date1->year < date2->year)
        return -1;
    if (date1->year > date2->year)
        return 1;
    if (date1->month < date2->month)
        return -1;
    if (date1->month > date2->month)
        return 1;
    if (date1->mday < date2->mday)
        return -1;
    if (date1->mday > date2->mday)
        return 1;
    if (date1->hour < date2->hour)
        return -1;
    if (date1->hour > date2->hour)
        return 1;
    if (date1->minute < date2->minute)
        return -1;
    if (date1->minute > date2->minute)
        return 1;
    if (date1->second < date2->second)
        return -1;
    if (date1->second > date2->second)
        return 1;
    return 0;
}

/*---------------------------------------------------------------------------*/

int64_t date_ellapsed_seconds(const Date *from, const Date *to)
{
    uint64_t from_micros = btime_to_micro(from);
    uint64_t to_micros = btime_to_micro(to);

    if (to_micros > from_micros)
        return (int64_t)((to_micros - from_micros) / 1000000);
    else
        return -(int64_t)((from_micros - to_micros) / 1000000);
}

/*---------------------------------------------------------------------------*/

bool_t date_between(const Date *date, const Date *from, const Date *to)
{
    int c = date_cmp(to, from);
    int f = date_cmp(date, from);
    int t = date_cmp(date, to);

    /* 'from' is more recent date --> swap */
    if (c < 0)
    {
        int s = f;
        f = t;
        t = s;
    }

    if (f >= 0 && t <= 0)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t date_is_null(const Date *date)
{
    cassert_no_null(date);
    if (date->year == 0 && date->month == 0 && date->wday == 0 && date->mday == 0 && date->hour == 0 && date->minute == 0 && date->second == 0)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_is_leap_year(const int16_t year)
{
    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

static uint8_t i_month_days(const month_t month, const int16_t year)
{
    switch (month)
    {
    case ekJANUARY:
    case ekMARCH:
    case ekMAY:
    case ekJULY:
    case ekAUGUST:
    case ekOCTOBER:
    case ekDECEMBER:
        return 31;
    case ekAPRIL:
    case ekJUNE:
    case ekSEPTEMBER:
    case ekNOVEMBER:
        return 30;
    case ekFEBRUARY:
        if (i_is_leap_year(year) == TRUE)
            return 29;
        else
            return 28;
        cassert_default();
    }

    return 0;
}

/*---------------------------------------------------------------------------*/

bool_t date_is_valid(const Date *date)
{
    cassert_no_null(date);
    if (date->year > 9999)
        return FALSE;
    if (date->month == 0 || date->month > 12)
        return FALSE;
    if (date->mday == 0 || date->mday > i_month_days((month_t)date->month, date->year))
        return FALSE;
    if (date->hour >= 24)
        return FALSE;
    if (date->minute >= 60)
        return FALSE;
    if (date->second >= 60)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

week_day_t date_weekday(const Date *date)
{
    static uint32_t t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    uint32_t y, m, d, wd;

    cassert_no_null(date);
    cassert(date->mday >= 1 && date->mday <= i_month_days((month_t)date->month, date->year));

    y = date->year;
    m = date->month;
    d = date->mday;

    y -= m < 3;
    wd = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;

    return (week_day_t)wd;
}

/*---------------------------------------------------------------------------*/

String *date_format(const Date *date, const char_t *format)
{
    char_t dest[256];
    cassert_no_null(date);
    if (blib_strftime(dest, sizeof(dest), format, date->year, date->month, date->mday, date->wday, date->hour, date->minute, date->second) != 0)
        return str_c(dest);
    else
        return str_printf("%04d/%02d/%02d-%02d:%02d:%02d", date->year, date->month, date->mday, date->hour, date->minute, date->second);
}
