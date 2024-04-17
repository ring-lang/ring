/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: arrpt.h
 * https://nappgui.com/en/core/arrpt.html
 *
 */

/* Arrays of pointers */

#define arrpt_create(type) \
    arrpt_##type##_create((uint16_t)sizeof(type *))

#define arrpt_copy(array, func_copy, type) \
    arrpt_##type##_copy(array, func_copy)

#define arrpt_read(stream, func_read, type) \
    arrpt_##type##_read(stream, func_read)

#define arrpt_destroy(array, func_destroy, type) \
    arrpt_##type##_destroy(array, func_destroy)

#define arrpt_destopt(array, func_destroy, type) \
    arrpt_##type##_destopt(array, func_destroy)

#define arrpt_clear(array, func_destroy, type) \
    arrpt_##type##_clear(array, func_destroy)

#define arrpt_write(stream, array, func_write, type) \
    arrpt_##type##_write(stream, array, func_write)

#define arrpt_size(array, type) \
    arrpt_##type##_size(array)

#define arrpt_get(array, pos, type) \
    arrpt_##type##_get(array, pos)

#define arrpt_get_const(array, pos, type) \
    arrpt_##type##_get_const(array, pos)

#define arrpt_first(array, type) \
    arrpt_##type##_first(array)

#define arrpt_first_const(array, type) \
    arrpt_##type##_first_const(array)

#define arrpt_last(array, type) \
    arrpt_##type##_last(array)

#define arrpt_last_const(array, type) \
    arrpt_##type##_last_const(array)

#define arrpt_all(array, type) \
    arrpt_##type##_all(array)

#define arrpt_all_const(array, type) \
    arrpt_##type##_all_const(array)

#define arrpt_grow(array, n, type) \
    arrpt_##type##_insert(array, UINT32_MAX, n)

#define arrpt_append(array, value, type) \
    (*(const type **)arrpt_##type##_insert(array, UINT32_MAX, 1)) = (value)

#define arrpt_prepend(array, value, type) \
    (*(const type **)arrpt_##type##_insert(array, 0, 1)) = (value)

#define arrpt_insert(array, pos, value, type) \
    (*(const type **)arrpt_##type##_insert(array, pos, 1)) = (value)

#define arrpt_insert_n(array, pos, n, type) \
    arrpt_##type##_insert(array, pos, n)

#define arrpt_join(dest, src, func_copy, type) \
    arrpt_##type##_join(dest, src, func_copy)

#define arrpt_delete(array, pos, func_destroy, type) \
    arrpt_##type##_delete(array, pos, func_destroy)

#define arrpt_pop(array, func_destroy, type) \
    arrpt_##type##_pop(array, func_destroy)

#define arrpt_sort(array, func_compare, type) \
    arrpt_##type##_sort(array, func_compare)

#define arrpt_sort_ex(array, func_compare, data, type, dtype) \
    ((void)((data) == (dtype *)(data)), \
     FUNC_CHECK_COMPARE_EX(func_compare, type, dtype), \
     arrpt_##type##_sort_ex(array, (FPtr_compare_ex)func_compare, (void *)data))

#define arrpt_find(array, elem, type) \
    arrpt_##type##_find(array, elem)

#define arrpt_search(array, func_compare, key, pos, type, ktype) \
    ((void)((key) == (ktype *)(key)), \
     FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype), \
     arrpt_##type##_search(array, (FPtr_compare)func_compare, (const void *)key, pos))

#define arrpt_search_const(array, func_compare, key, pos, type, ktype) \
    ((void)((key) == (ktype *)(key)), \
     FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype), \
     arrpt_##type##_search_const(array, (FPtr_compare)func_compare, (const void *)key, pos))

#define arrpt_bsearch(array, func_compare, key, pos, type, ktype) \
    ((void)((key) == (ktype *)(key)), \
     FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype), \
     arrpt_##type##_bsearch(array, (FPtr_compare)func_compare, (const void *)key, pos))

#define arrpt_bsearch_const(array, func_compare, key, pos, type, ktype) \
    ((void)((key) == (ktype *)(key)), \
     FUNC_CHECK_COMPARE_KEY(func_compare, type, ktype), \
     arrpt_##type##_bsearch_const(array, (FPtr_compare)func_compare, (const void *)key, pos))

#define arrpt_foreach(elem, array, type) \
    { \
        register type **elem##_buf = arrpt_all(array, type); \
        register uint32_t elem##_i, elem##_total = arrpt_size(array, type); \
        for (elem##_i = 0; elem##_i < elem##_total; ++elem##_i, ++elem##_buf) \
        { \
            register type *elem = (*elem##_buf);

#define arrpt_foreach_const(elem, array, type) \
    { \
        register const type **elem##_buf = arrpt_all_const(array, type); \
        register uint32_t elem##_i, elem##_total = arrpt_size(array, type); \
        for (elem##_i = 0; elem##_i < elem##_total; ++elem##_i, ++elem##_buf) \
        { \
            register const type *elem = (*elem##_buf);

#define arrpt_forback(elem, array, type) \
    { \
        register type **elem##_buf = arrpt_all(array, type); \
        register uint32_t i, elem##_i, elem##_total = arrpt_size(array, type); \
        elem##_buf += elem##_total - 1; \
        elem##_i = elem##_total - 1; \
        for (i = 0; i < elem##_total; ++i, --elem##_i, --elem##_buf) \
        { \
            register type *elem = (*elem##_buf);

#define arrpt_forback_const(elem, array, type) \
    { \
        register const type **elem##_buf = arrpt_all_const(array, type); \
        register uint32_t i, elem##_i, elem##_total = arrpt_size(array, type); \
        elem##_buf += elem##_total - 1; \
        elem##_i = elem##_total - 1; \
        for (i = 0; i < elem##_total; ++i, --elem##_i, --elem##_buf) \
        { \
            register const type *elem = (*elem##_buf);

#define arrpt_end() \
    } \
    }
