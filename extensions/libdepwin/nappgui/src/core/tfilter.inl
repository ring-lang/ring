/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: tfilter.inl
 *
 */

/* Text filters */

#include "core.ixx"

__EXTERN_C

void tfilter_number(const char_t *src, char_t *dest, const uint32_t size, const uint32_t num_decimals, const bool_t allow_negatives);

__END_C
