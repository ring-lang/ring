/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: heap.h
 * https://nappgui.com/en/core/heap.html
 *
 */

/* Fast memory allocator and auditor */

#include "core.hxx"

__EXTERN_C

_core_api void heap_start_mt(void);

_core_api void heap_end_mt(void);

_core_api void heap_verbose(const bool_t verbose);

_core_api void heap_stats(const bool_t stats);

_core_api bool_t heap_leaks(void);

_core_api byte_t *heap_malloc_imp(const uint32_t size, const char_t *name, const bool_t equal_sized);

_core_api byte_t *heap_calloc_imp(const uint32_t size, const char_t *name, const bool_t equal_sized);

_core_api byte_t *heap_realloc(byte_t *mem, const uint32_t size, const uint32_t new_size, const char_t *name);

_core_api byte_t *heap_aligned_malloc_imp(const uint32_t size, const uint32_t align, const char_t *name, const bool_t equal_sized);

_core_api byte_t *heap_aligned_calloc_imp(const uint32_t size, const uint32_t align, const char_t *name, const bool_t equal_sized);

_core_api byte_t *heap_aligned_realloc(byte_t *mem, const uint32_t size, const uint32_t new_size, const uint32_t align, const char_t *name);

_core_api void heap_free(byte_t **mem, const uint32_t size, const char_t *name);

_core_api void heap_auditor_add(const char_t *name);

_core_api void heap_auditor_delete(const char_t *name);

__END_C

#define heap_malloc(size, name) \
    heap_malloc_imp(size, name, FALSE)

#define heap_calloc(size, name) \
    heap_calloc_imp(size, name, FALSE)

#define heap_aligned_malloc(size, align, name) \
    heap_aligned_malloc_imp(size, align, name, FALSE)

#define heap_aligned_calloc(size, align, name) \
    heap_aligned_calloc_imp(size, align, name, FALSE)

#define heap_new(type) \
    (type *)heap_malloc_imp((uint32_t)sizeof(type), (const char_t *)#type, TRUE)

#define heap_new0(type) \
    (type *)heap_calloc_imp((uint32_t)sizeof(type), (const char_t *)#type, TRUE)

#define heap_new_n(n, type) \
    (type *)heap_malloc_imp((uint32_t)sizeof(type) * (uint32_t)(n), (const char_t *)#type HEAPARR, FALSE)

#define heap_new_n0(n, type) \
    (type *)heap_calloc_imp((uint32_t)sizeof(type) * (uint32_t)(n), (const char_t *)#type HEAPARR, FALSE)

#define heap_realloc_n(mem, size, new_size, type) \
    ((void)((type *)mem == mem), \
     (type *)heap_realloc((byte_t *)mem, size * (uint32_t)sizeof(type), new_size * (uint32_t)sizeof(type), (const char_t *)#type HEAPARR))

#define heap_delete(obj, type) \
    ((void)((obj) == (type **)(obj)), \
     heap_free((byte_t **)(obj), (uint32_t)sizeof(type), (const char_t *)#type))

#define heap_delete_n(objs, n, type) \
    ((void)((objs) == (type **)(objs)), \
     heap_free((byte_t **)(objs), (uint32_t)sizeof(type) * (uint32_t)(n), (const char_t *)#type HEAPARR))
