/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: date.h
 * https://nappgui.com/en/core/date.html
 *
 */

/* Dates */

#include "core.hxx"

__EXTERN_C

_core_api Date date_system(void);

_core_api Date date_pack(const int16_t year, const uint8_t month, const uint8_t mday, const uint8_t hour, const uint8_t minute, const uint8_t second);

_core_api Date date_add_seconds(const Date *date, int32_t seconds);

_core_api Date date_add_minutes(const Date *date, int32_t minutes);

_core_api Date date_add_hours(const Date *date, int32_t hours);

_core_api Date date_add_days(const Date *date, int32_t days);

_core_api int16_t date_year(void);

_core_api int date_cmp(const Date *date1, const Date *date2);

_core_api int64_t date_ellapsed_seconds(const Date *from, const Date *to);

_core_api bool_t date_between(const Date *date, const Date *from, const Date *to);

_core_api bool_t date_is_null(const Date *date);

_core_api bool_t date_is_valid(const Date *date);

_core_api week_day_t date_weekday(const Date *date);

_core_api String *date_format(const Date *date, const char_t *format);

_core_api extern Date kDATE_NULL;

__END_C
