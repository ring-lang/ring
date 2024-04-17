/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: btime.h
 * https://nappgui.com/en/osbs/btime.html
 *
 */

/* Basic time services */

#include "osbs.hxx"

__EXTERN_C

_osbs_api uint64_t btime_now(void);

_osbs_api void btime_date(Date *date);

_osbs_api uint64_t btime_to_micro(const Date *date);

_osbs_api void btime_to_date(const uint64_t micro, Date *date);

__END_C
