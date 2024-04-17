/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: heap.inl
 *
 */

/* Basic memory system */

#include <sewer/config.hxx>

__EXTERN_C

void _heap_start(void);

void _heap_finish(void);

void _heap_page_size(const uint32_t size);

__END_C
