/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: qsort.inl
 *
 */

/* Quick sort with data */

#include "sewer.hxx"

__EXTERN_C

void _qsort_ex(const void *data, const uint32_t num_elems, const uint32_t sizeof_elem, FPtr_compare_ex func_compare, const void *user_data);

__END_C
