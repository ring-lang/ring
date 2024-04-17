/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: arrst.h
 * https://nappgui.com/en/core/arrst.html
 *
 */

/* Arrays of structures */

#define arrst_create(type) \
    arrst_##type##_create((uint16_t)sizeof(type))

#define arrst_copy(array, func_copy, type) \
    arrst_##type##_copy(array, func_copy)

#define arrst_read(stream, func_read, type) \
    arrst_##type##_read(stream, (uint16_t)sizeof(type), func_read)

#define arrst_destroy(array, func_remove, type) \
    arrst_##type##_destroy(array, func_remove)

#define arrst_destopt(array, func_remove, type) \
    arrst_##type##_destopt(array, func_remove)

#define arrst_clear(array, func_remove, type) \
    arrst_##type##_clear(array, func_remove)

#define arrst_write(stream, array, func_write, type) \
    arrst_##type##_write(stream, array, func_write)

#define arrst_size(array, type) \
    arrst_##type##_size(array)

#define arrst_get(array, pos, type) \
    arrst_##type##_get(array, pos)

#define arrst_get_const(array, pos, type) \
    arrst_##type##_get_const(array, pos)

#define arrst_first(array, type) \
    arrst_##type##_get(array, 0)

#define arrst_first_const(array, type) \
    arrst_##type##_get_const(array, 0)

#define arrst_last(array, type) \
    arrst_##type##_last(array)

#define arrst_last_const(array, type) \
    arrst_##type##_last_const(array)

#define arrst_all(array, type) \
    arrst_##type##_all(array)

#define arrst_all_const(array, type) \
    arrst_##type##_all_const(array)

#define arrst_grow(array, n, type) \
    (void)arrst_##type##_insert(array, UINT32_MAX, n)

#define arrst_new(array, type) \
    arrst_##type##_insert(array, UINT32_MAX, 1)

#define arrst_new0(array, type) \
    arrst_##type##_insert0(array, UINT32_MAX, 1)

#define arrst_new_n(array, n, type) \
    arrst_##type##_insert(array, UINT32_MAX, n)

#define arrst_new_n0(array, n, type) \
    arrst_##type##_insert0(array, UINT32_MAX, n)

#define arrst_prepend_n(array, n, type) \
    arrst_##type##_insert(array, 0, n)

#define arrst_insert_n(array, pos, n, type) \
    arrst_##type##_insert(array, pos, n)

#define arrst_append(array, value, type) \
    (*arrst_##type##_insert(array, UINT32_MAX, 1)) = (value)

#define arrst_prepend(array, value, type) \
    (*arrst_##type##_insert(array, 0, 1)) = (value)

#define arrst_insert(array, pos, value, type) \
    (*arrst_##type##_insert(array, pos, 1)) = (value)

#define arrst_join(dest, src, func_copy, type) \
    arrst_##type##_join(dest, src, func_copy)

#define arrst_delete(array, pos, func_remove, type) \
    arrst_##type##_delete(array, pos, func_remove)

#define arrst_pop(array, func_remove, type) \
    arrst_##type##_pop(array, func_remove)

#define arrst_sort(array, func_compare, type) \
    arrst_##type##_sort(array, func_compare)

#define arrst_sort_ex(array, func_compare, data, type, dtype) \
    ((void)((data) == (dtype *)(data)), \
     FUNC_CHECK_COMPARE_EX(func_compare, type, dtype), \
     arrst_##type##_sort_ex(array, (FPtr_compare_ex)func_compare, (void *)data))

#define arrst_search(array, func_compare, key, pos, type, ktype) \
    ((void)((key) == (ktype *)(key)), \
     FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype), \
     arrst_##type##_search(array, (FPtr_compare)func_compare, (const void *)key, pos))

#define arrst_search_const(array, func_compare, key, pos, type, ktype) \
    ((void)((key) == (ktype *)(key)), \
     FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype), \
     arrst_##type##_search_const(array, (FPtr_compare)func_compare, (const void *)key, pos))

#define arrst_bsearch(array, func_compare, key, pos, type, ktype) \
    ((void)((key) == (ktype *)(key)), \
     FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype), \
     arrst_##type##_bsearch(array, (FPtr_compare)func_compare, (const void *)key, pos))

#define arrst_bsearch_const(array, func_compare, key, pos, type, ktype) \
    ((void)((key) == (ktype *)(key)), \
     FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype), \
     arrst_##type##_bsearch_const(array, (FPtr_compare)func_compare, (const void *)key, pos))

#define arrst_foreach(elem, array, type) \
    { \
        register type *elem = arrst_all(array, type); \
        register uint32_t elem##_i, elem##_total = arrst_size(array, type); \
        for (elem##_i = 0; elem##_i < elem##_total; ++elem##_i, ++elem) \
        {

#define arrst_foreach_const(elem, array, type) \
    { \
        register const type *elem = arrst_all_const(array, type); \
        register uint32_t elem##_i, elem##_total = arrst_size(array, type); \
        for (elem##_i = 0; elem##_i < elem##_total; ++elem##_i, ++elem) \
        {

#define arrst_forback(elem, array, type) \
    { \
        register type *elem = arrst_all(array, type); \
        register uint32_t __i, elem##_i, elem##_total = arrst_size(array, type); \
        elem += elem##_total - 1; \
        elem##_i = elem##_total - 1; \
        for (__i = 0; __i < elem##_total; ++__i, --elem##_i, --elem) \
        {

#define arrst_forback_const(elem, array, type) \
    { \
        register const type *elem = arrst_all_const(array, type); \
        register uint32_t __i, elem##_i, elem##_total = arrst_size(array, type); \
        elem += elem##_total - 1; \
        elem##_i = elem##_total - 1; \
        for (__i = 0; __i < elem##_total; ++__i, --elem##_i, --elem) \
        {

#define arrst_end() \
    } \
    }
