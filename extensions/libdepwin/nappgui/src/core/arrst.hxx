/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: arrst.hxx
 * https://nappgui.com/en/core/arrst.html
 *
 */

/* Array macros for type checking at compile time */

#define ArrStDebug(type) \
    struct type##Data \
    { \
        type elem[1024]; \
    }; \
\
    struct Arr##St##type \
    { \
        uint32_t reserved; \
        uint32_t size; \
        uint16_t elem_sizeof; \
        struct type##Data *content; \
    }

#define ArrStFuncs(type) \
    ArrSt(type); \
\
    static __TYPECHECK ArrSt(type) *arrst_##type##_create(const uint16_t esize); \
    static ArrSt(type) *arrst_##type##_create(const uint16_t esize) \
    { \
        return (ArrSt(type) *)array_create(esize, (const char_t *)(ARRST #type)); \
    } \
\
    static __TYPECHECK ArrSt(type) *arrst_##type##_copy(const struct Arr##St##type *array, void(func_copy)(type *, const type *)); \
    static ArrSt(type) *arrst_##type##_copy(const struct Arr##St##type *array, void(func_copy)(type *, const type *)) \
    { \
        return (ArrSt(type) *)array_copy((Array *)array, (FPtr_scopy)func_copy, (const char_t *)(ARRST #type)); \
    } \
\
    static __TYPECHECK ArrSt(type) *arrst_##type##_read(Stream *stream, const uint16_t esize, void(func_read)(Stream *, type *)); \
    static ArrSt(type) *arrst_##type##_read(Stream *stream, const uint16_t esize, void(func_read)(Stream *, type *)) \
    { \
        return (ArrSt(type) *)array_read(stream, esize, (FPtr_read_init)func_read, (const char_t *)(ARRST #type)); \
    } \
\
    static __TYPECHECK void arrst_##type##_destroy(struct Arr##St##type **array, void(func_remove)(type *)); \
    static void arrst_##type##_destroy(struct Arr##St##type **array, void(func_remove)(type *)) \
    { \
        array_destroy((Array **)array, (FPtr_remove)func_remove, (const char_t *)(ARRST #type)); \
    } \
\
    static __TYPECHECK void arrst_##type##_destopt(struct Arr##St##type **array, void(func_remove)(type *)); \
    static void arrst_##type##_destopt(struct Arr##St##type **array, void(func_remove)(type *)) \
    { \
        array_destopt((Array **)array, (FPtr_remove)func_remove, (const char_t *)(ARRST #type)); \
    } \
\
    static __TYPECHECK void arrst_##type##_clear(struct Arr##St##type *array, void(func_remove)(type *)); \
    static void arrst_##type##_clear(struct Arr##St##type *array, void(func_remove)(type *)) \
    { \
        array_clear((Array *)array, (FPtr_remove)func_remove); \
    } \
\
    static __TYPECHECK void arrst_##type##_write(Stream *stream, const struct Arr##St##type *array, void(func_write)(Stream *, const type *)); \
    static void arrst_##type##_write(Stream *stream, const struct Arr##St##type *array, void(func_write)(Stream *, const type *)) \
    { \
        array_write(stream, (const Array *)array, (FPtr_write)func_write); \
    } \
\
    static __TYPECHECK uint32_t arrst_##type##_size(const struct Arr##St##type *array); \
    static uint32_t arrst_##type##_size(const struct Arr##St##type *array) \
    { \
        return array_size((const Array *)array); \
    } \
\
    static __TYPECHECK type *arrst_##type##_get(struct Arr##St##type *array, const uint32_t pos); \
    static type *arrst_##type##_get(struct Arr##St##type *array, const uint32_t pos) \
    { \
        return (type *)array_get((Array *)array, pos); \
    } \
\
    static __TYPECHECK const type *arrst_##type##_get_const(const struct Arr##St##type *array, const uint32_t pos); \
    static const type *arrst_##type##_get_const(const struct Arr##St##type *array, const uint32_t pos) \
    { \
        return (const type *)array_get((Array *)array, pos); \
    } \
\
    static __TYPECHECK type *arrst_##type##_last(struct Arr##St##type *array); \
    static type *arrst_##type##_last(struct Arr##St##type *array) \
    { \
        return (type *)array_get_last((Array *)array); \
    } \
\
    static __TYPECHECK const type *arrst_##type##_last_const(const struct Arr##St##type *array); \
    static const type *arrst_##type##_last_const(const struct Arr##St##type *array) \
    { \
        return (const type *)array_get_last((const Array *)array); \
    } \
\
    static __TYPECHECK type *arrst_##type##_all(struct Arr##St##type *array); \
    static type *arrst_##type##_all(struct Arr##St##type *array) \
    { \
        return (type *)array_all((Array *)array); \
    } \
\
    static __TYPECHECK const type *arrst_##type##_all_const(const struct Arr##St##type *array); \
    static const type *arrst_##type##_all_const(const struct Arr##St##type *array) \
    { \
        return (const type *)array_all((Array *)array); \
    } \
\
    static __TYPECHECK type *arrst_##type##_insert(struct Arr##St##type *array, const uint32_t pos, const uint32_t n); \
    static type *arrst_##type##_insert(struct Arr##St##type *array, const uint32_t pos, const uint32_t n) \
    { \
        return (type *)array_insert((Array *)array, pos, n); \
    } \
\
    static __TYPECHECK type *arrst_##type##_insert0(struct Arr##St##type *array, const uint32_t pos, const uint32_t n); \
    static type *arrst_##type##_insert0(struct Arr##St##type *array, const uint32_t pos, const uint32_t n) \
    { \
        return (type *)array_insert0((Array *)array, pos, n); \
    } \
\
    static __TYPECHECK void arrst_##type##_join(struct Arr##St##type *dest, const struct Arr##St##type *src, void(func_copy)(type *, const type *)); \
    static void arrst_##type##_join(struct Arr##St##type *dest, const struct Arr##St##type *src, void(func_copy)(type *, const type *)) \
    { \
        array_join((Array *)dest, (const Array *)src, (FPtr_scopy)func_copy); \
    } \
\
    static __TYPECHECK void arrst_##type##_delete(struct Arr##St##type *array, const uint32_t pos, void(func_remove)(type *)); \
    static void arrst_##type##_delete(struct Arr##St##type *array, const uint32_t pos, void(func_remove)(type *)) \
    { \
        array_delete((Array *)array, pos, 1, (FPtr_remove)func_remove); \
    } \
\
    static __TYPECHECK void arrst_##type##_pop(struct Arr##St##type *array, void(func_remove)(type *)); \
    static void arrst_##type##_pop(struct Arr##St##type *array, void(func_remove)(type *)) \
    { \
        array_pop((Array *)array, (FPtr_remove)func_remove); \
    } \
\
    static __TYPECHECK void arrst_##type##_sort(struct Arr##St##type *array, int(func_compare)(const type *, const type *)); \
    static void arrst_##type##_sort(struct Arr##St##type *array, int(func_compare)(const type *, const type *)) \
    { \
        array_sort((Array *)array, (FPtr_compare)func_compare); \
    } \
\
    static __TYPECHECK void arrst_##type##_sort_ex(struct Arr##St##type *array, FPtr_compare_ex func_compare, void *data); \
    static void arrst_##type##_sort_ex(struct Arr##St##type *array, FPtr_compare_ex func_compare, void *data) \
    { \
        array_sort_ex((Array *)array, func_compare, data); \
    } \
\
    static __TYPECHECK type *arrst_##type##_search(struct Arr##St##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos); \
    static type *arrst_##type##_search(struct Arr##St##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos) \
    { \
        return (type *)array_search((Array *)array, func_compare, key, pos); \
    } \
\
    static __TYPECHECK const type *arrst_##type##_search_const(const struct Arr##St##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos); \
    static const type *arrst_##type##_search_const(const struct Arr##St##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos) \
    { \
        return (const type *)array_search((const Array *)array, func_compare, key, pos); \
    } \
\
    static __TYPECHECK type *arrst_##type##_bsearch(struct Arr##St##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos); \
    static type *arrst_##type##_bsearch(struct Arr##St##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos) \
    { \
        return (type *)array_bsearch((Array *)array, func_compare, key, pos); \
    } \
\
    static __TYPECHECK const type *arrst_##type##_bsearch_const(const struct Arr##St##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos); \
    static const type *arrst_##type##_bsearch_const(const struct Arr##St##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos) \
    { \
        return (const type *)array_bsearch((const Array *)array, func_compare, key, pos); \
    } \
    __INLINE void arrst_##type##_end(void)
