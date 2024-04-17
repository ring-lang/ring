/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: log.h
 * https://nappgui.com/en/osbs/log.html
 *
 */

/* Manages an application log */

#include "osbs.hxx"

__EXTERN_C

_osbs_api uint32_t log_printf(const char_t *format, ...) __PRINTF(1, 2);

_osbs_api void log_output(const bool_t std, const bool_t err);

_osbs_api void log_file(const char_t *pathname);

_osbs_api const char_t *log_get_file(void);

__END_C
