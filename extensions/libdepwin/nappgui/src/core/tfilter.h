/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: tfilter.h
 *
 */

/* Text filters */

#include "core.hxx"

__EXTERN_C

_core_api void tfilter_date(const char_t *src, char_t *dest, const uint32_t size, const char_t *pattern, const uint32_t cpos, const bool_t deleted, uint32_t *ncpos);

_core_api Date tfilter_to_date(const char_t *text, const char_t *pattern);

__END_C
