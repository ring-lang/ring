/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: array.h
 *
 */

/* Array data structure */

#include "core.hxx"

__EXTERN_C

_core_api Array *array_create(const uint16_t esize, const char_t *type);

_core_api Array *array_copy(const Array *array, FPtr_scopy func_copy, const char_t *type);

_core_api Array *array_copy_ptr(const Array *array, FPtr_copy func_copy, const char_t *type);

_core_api Array *array_read(Stream *stream, const uint16_t esize, FPtr_read_init func_read_init, const char_t *type);

_core_api Array *array_read_ptr(Stream *stream, FPtr_read func_read, const char_t *type);

_core_api void array_destroy(Array **array, FPtr_remove func_remove, const char_t *type);

_core_api void array_destopt(Array **array, FPtr_remove func_remove, const char_t *type);

_core_api void array_destroy_ptr(Array **array, FPtr_destroy func_destroy, const char_t *type);

_core_api void array_destopt_ptr(Array **array, FPtr_destroy func_destroy, const char_t *type);

_core_api void array_clear(Array *array, FPtr_remove func_remove);

_core_api void array_clear_ptr(Array *array, FPtr_destroy func_destroy);

_core_api void array_write(Stream *stream, const Array *array, FPtr_write func_write);

_core_api void array_write_ptr(Stream *stream, const Array *array, FPtr_write func_write);

_core_api uint32_t array_size(const Array *array);

_core_api uint32_t array_esize(const Array *array);

_core_api byte_t *array_get(const Array *array, const uint32_t pos);

_core_api byte_t *array_get_last(const Array *array);

_core_api byte_t *array_all(const Array *array);

_core_api byte_t *array_insert(Array *array, const uint32_t pos, const uint32_t n);

_core_api byte_t *array_insert0(Array *array, const uint32_t pos, const uint32_t n);

_core_api void array_join(Array *dest, const Array *src, FPtr_scopy func_copy);

_core_api void array_join_ptr(Array *dest, const Array *src, FPtr_copy func_copy);

_core_api void array_delete(Array *array, const uint32_t pos, const uint32_t n, FPtr_remove func_remove);

_core_api void array_delete_ptr(Array *array, const uint32_t pos, const uint32_t n, FPtr_destroy func_destroy);

_core_api void array_pop(Array *array, FPtr_remove func_remove);

_core_api void array_pop_ptr(Array *array, FPtr_destroy func_destroy);

_core_api void array_sort(Array *array, FPtr_compare func_compare);

_core_api void array_sort_ex(Array *array, FPtr_compare_ex func_compare, void *data);

_core_api void array_sort_ptr(Array *array, FPtr_compare func_compare);

_core_api void array_sort_ptr_ex(Array *array, FPtr_compare_ex func_compare, void *data);

_core_api uint32_t array_find_ptr(const Array *array, const void *elem);

_core_api byte_t *array_search(const Array *array, FPtr_compare func_compare, const void *key, uint32_t *pos);

_core_api byte_t *array_search_ptr(const Array *array, FPtr_compare func_compare, const void *key, uint32_t *pos);

_core_api byte_t *array_bsearch(const Array *array, FPtr_compare func_compare, const void *key, uint32_t *pos);

_core_api byte_t *array_bsearch_ptr(const Array *array, FPtr_compare func_compare, const void *key, uint32_t *pos);

__END_C
