/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: regex.h
 * https://nappgui.com/en/core/regex.html
 *
 */

/* Regular expresions */

#include "core.hxx"

__EXTERN_C

_core_api RegEx *regex_create(const char_t *pattern);

_core_api void regex_destroy(RegEx **regex);

_core_api bool_t regex_match(const RegEx *regex, const char_t *str);

__END_C
