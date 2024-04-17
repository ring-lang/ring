/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: setst.h
 * https://nappgui.com/en/core/setst.html
 *
 */

/* Sets of structures */

#define setst_create(func_compare, type) \
    setst_##type##_create(func_compare, (uint16_t)sizeof(type))

#define setst_destroy(set, func_remove, type) \
    setst_##type##_destroy(set, func_remove)

#define setst_size(set, type) \
    setst_##type##_size(set)

#define setst_get(set, key, type) \
    setst_##type##_get(set, key)

#define setst_get_const(set, key, type) \
    setst_##type##_get_const(set, key)

#define setst_insert(set, key, type) \
    setst_##type##_insert(set, key)

#define setst_delete(set, key, func_remove, type) \
    setst_##type##_delete(set, key, func_remove)

#define setst_first(set, type) \
    setst_##type##_first(set)

#define setst_first_const(set, type) \
    setst_##type##_first_const(set)

#define setst_last(set, type) \
    setst_##type##_last(set)

#define setst_last_const(set, type) \
    setst_##type##_last_const(set)

#define setst_next(set, type) \
    setst_##type##_next(set)

#define setst_next_const(set, type) \
    setst_##type##_next_const(set)

#define setst_prev(set, type) \
    setst_##type##_prev(set)

#define setst_prev_const(set, type) \
    setst_##type##_prev_const(set)

#define setst_foreach(elem, set, type) \
    { \
        register type *elem = setst_first(set, type); \
        register uint32_t elem##_i = 0, elem##_total = setst_size(set, type); \
        while (elem != NULL) \
        {

#define setst_foreach_const(elem, set, type) \
    { \
        register const type *elem = setst_first_const(set, type); \
        register uint32_t elem##_i = 0, elem##_total = setst_size(set, type); \
        while (elem != NULL) \
        {

#define setst_fornext(elem, set, type) \
    elem = setst_next(set, type); \
    elem##_i += 1; \
    unref(elem##_total); \
    } \
    }

#define setst_fornext_const(elem, set, type) \
    elem = setst_next_const(set, type); \
    elem##_i += 1; \
    unref(elem##_total); \
    } \
    }

#define setst_forback(elem, set, type) \
    { \
        register type *elem = setst_last(set, type); \
        register uint32_t elem##_total = setst_size(set, type), elem##_i = elem##_total - 1; \
        while (elem != NULL) \
        {

#define setst_forback_const(elem, set, type) \
    { \
        register type *elem = setst_last_const(set, type); \
        register uint32_t elem##_total = setst_size(set, type), elem##_i = elem##_total - 1; \
        while (elem != NULL) \
        {

#define setst_forprev(set, type) \
    elem = setst_prev(set, type); \
    elem##_i -= 1; \
    unref(elem##_total); \
    } \
    }

#define setst_forprev_const(set, type) \
    elem = setst_prev_const(set, type); \
    elem##_i -= 1; \
    unref(elem##_total); \
    } \
    }
