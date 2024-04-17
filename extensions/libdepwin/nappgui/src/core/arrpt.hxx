/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: arrpt.hxx
 * https://nappgui.com/en/core/arrpt.html
 *
 */

/* Array macros for type checking at compile time */

#define ArrPtDebug(type) \
    struct type##PtData \
    { \
        type *elem[1024]; \
    }; \
\
    struct Arr##Pt##type \
    { \
        uint32_t reserved; \
        uint32_t size; \
        uint16_t elem_sizeof; \
        struct type##PtData *content; \
    }

#define ArrPtFuncs(type) \
    ArrPt(type); \
\
    static __TYPECHECK ArrPt(type) *arrpt_##type##_create(const uint16_t esize); \
    static ArrPt(type) *arrpt_##type##_create(const uint16_t esize) \
    { \
        return (ArrPt(type) *)array_create(esize, (const char_t *)(ARRPT #type)); \
    } \
\
    static __TYPECHECK ArrPt(type) *arrpt_##type##_copy(const struct Arr##Pt##type *array, type *(func_copy)(const type *)); \
    static ArrPt(type) *arrpt_##type##_copy(const struct Arr##Pt##type *array, type *(func_copy)(const type *)) \
    { \
        return (ArrPt(type) *)array_copy_ptr((Array *)array, (FPtr_copy)func_copy, (const char_t *)(ARRPT #type)); \
    } \
\
    static __TYPECHECK ArrPt(type) *arrpt_##type##_read(Stream *stream, type *(func_read)(Stream *)); \
    static ArrPt(type) *arrpt_##type##_read(Stream *stream, type *(func_read)(Stream *)) \
    { \
        return (ArrPt(type) *)array_read_ptr(stream, (FPtr_read)func_read, (const char_t *)(ARRPT #type)); \
    } \
\
    static __TYPECHECK void arrpt_##type##_destroy(struct Arr##Pt##type **array, void(func_destroy)(type **)); \
    static void arrpt_##type##_destroy(struct Arr##Pt##type **array, void(func_destroy)(type **)) \
    { \
        array_destroy_ptr((Array **)array, (FPtr_destroy)func_destroy, (const char_t *)(ARRPT #type)); \
    } \
\
    static __TYPECHECK void arrpt_##type##_destopt(struct Arr##Pt##type **array, void(func_destroy)(type **)); \
    static void arrpt_##type##_destopt(struct Arr##Pt##type **array, void(func_destroy)(type **)) \
    { \
        array_destopt_ptr((Array **)array, (FPtr_destroy)func_destroy, (const char_t *)(ARRPT #type)); \
    } \
\
    static __TYPECHECK void arrpt_##type##_clear(struct Arr##Pt##type *array, void(func_destroy)(type **)); \
    static void arrpt_##type##_clear(struct Arr##Pt##type *array, void(func_destroy)(type **)) \
    { \
        array_clear_ptr((Array *)array, (FPtr_destroy)func_destroy); \
    } \
\
    static __TYPECHECK void arrpt_##type##_write(Stream *stream, const struct Arr##Pt##type *array, void(func_write)(Stream *, const type *)); \
    static void arrpt_##type##_write(Stream *stream, const struct Arr##Pt##type *array, void(func_write)(Stream *, const type *)) \
    { \
        array_write_ptr(stream, (const Array *)array, (FPtr_write)func_write); \
    } \
\
    static __TYPECHECK uint32_t arrpt_##type##_size(const struct Arr##Pt##type *array); \
    static uint32_t arrpt_##type##_size(const struct Arr##Pt##type *array) \
    { \
        return array_size((const Array *)array); \
    } \
\
    static __TYPECHECK type *arrpt_##type##_get(struct Arr##Pt##type *array, const uint32_t pos); \
    static type *arrpt_##type##_get(struct Arr##Pt##type *array, const uint32_t pos) \
    { \
        return *(type **)array_get((Array *)array, pos); \
    } \
\
    static __TYPECHECK const type *arrpt_##type##_get_const(const struct Arr##Pt##type *array, const uint32_t pos); \
    static const type *arrpt_##type##_get_const(const struct Arr##Pt##type *array, const uint32_t pos) \
    { \
        return *(const type **)array_get((Array *)array, pos); \
    } \
\
    static __TYPECHECK type *arrpt_##type##_first(struct Arr##Pt##type *array); \
    static type *arrpt_##type##_first(struct Arr##Pt##type *array) \
    { \
        return *(type **)array_get((Array *)array, 0); \
    } \
\
    static __TYPECHECK const type *arrpt_##type##_first_const(const struct Arr##Pt##type *array); \
    static const type *arrpt_##type##_first_const(const struct Arr##Pt##type *array) \
    { \
        return *(const type **)array_get((Array *)array, 0); \
    } \
\
    static __TYPECHECK type *arrpt_##type##_last(struct Arr##Pt##type *array); \
    static type *arrpt_##type##_last(struct Arr##Pt##type *array) \
    { \
        return *(type **)array_get_last((Array *)array); \
    } \
\
    static __TYPECHECK const type *arrpt_##type##_last_const(const struct Arr##Pt##type *array); \
    static const type *arrpt_##type##_last_const(const struct Arr##Pt##type *array) \
    { \
        return *(const type **)array_get_last((Array *)array); \
    } \
\
    static __TYPECHECK type **arrpt_##type##_all(struct Arr##Pt##type *array); \
    static type **arrpt_##type##_all(struct Arr##Pt##type *array) \
    { \
        return (type **)array_all((Array *)array); \
    } \
\
    static __TYPECHECK const type **arrpt_##type##_all_const(const struct Arr##Pt##type *array); \
    static const type **arrpt_##type##_all_const(const struct Arr##Pt##type *array) \
    { \
        return (const type **)array_all((const Array *)array); \
    } \
\
    static __TYPECHECK type **arrpt_##type##_insert(struct Arr##Pt##type *array, const uint32_t pos, const uint32_t n); \
    static type **arrpt_##type##_insert(struct Arr##Pt##type *array, const uint32_t pos, const uint32_t n) \
    { \
        return (type **)array_insert((Array *)array, pos, n); \
    } \
\
    static __TYPECHECK void arrpt_##type##_join(struct Arr##Pt##type *dest, const struct Arr##Pt##type *src, type *(func_copy)(const type *)); \
    static void arrpt_##type##_join(struct Arr##Pt##type *dest, const struct Arr##Pt##type *src, type *(func_copy)(const type *)) \
    { \
        array_join_ptr((Array *)dest, (const Array *)src, (FPtr_copy)func_copy); \
    } \
\
    static __TYPECHECK void arrpt_##type##_delete(struct Arr##Pt##type *array, const uint32_t pos, void(func_destroy)(type **)); \
    static void arrpt_##type##_delete(struct Arr##Pt##type *array, const uint32_t pos, void(func_destroy)(type **)) \
    { \
        array_delete_ptr((Array *)array, pos, 1, (FPtr_destroy)func_destroy); \
    } \
\
    static __TYPECHECK void arrpt_##type##_pop(struct Arr##Pt##type *array, void(func_destroy)(type **)); \
    static void arrpt_##type##_pop(struct Arr##Pt##type *array, void(func_destroy)(type **)) \
    { \
        array_pop_ptr((Array *)array, (FPtr_destroy)func_destroy); \
    } \
\
    static __TYPECHECK void arrpt_##type##_sort(struct Arr##Pt##type *array, int(func_compare)(const type *, const type *)); \
    static void arrpt_##type##_sort(struct Arr##Pt##type *array, int(func_compare)(const type *, const type *)) \
    { \
        array_sort_ptr((Array *)array, (FPtr_compare)func_compare); \
    } \
\
    static __TYPECHECK void arrpt_##type##_sort_ex(struct Arr##Pt##type *array, FPtr_compare_ex func_compare, void *data); \
    static void arrpt_##type##_sort_ex(struct Arr##Pt##type *array, FPtr_compare_ex func_compare, void *data) \
    { \
        array_sort_ptr_ex((Array *)array, func_compare, data); \
    } \
\
    static __TYPECHECK uint32_t arrpt_##type##_find(const struct Arr##Pt##type *array, const type *elem); \
    static uint32_t arrpt_##type##_find(const struct Arr##Pt##type *array, const type *elem) \
    { \
        return array_find_ptr((const Array *)array, (const void *)elem); \
    } \
\
    static __TYPECHECK type *arrpt_##type##_search(struct Arr##Pt##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos); \
    static type *arrpt_##type##_search(struct Arr##Pt##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos) \
    { \
        return (type *)array_search_ptr((Array *)array, func_compare, key, pos); \
    } \
\
    static __TYPECHECK const type *arrpt_##type##_search_const(const struct Arr##Pt##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos); \
    static const type *arrpt_##type##_search_const(const struct Arr##Pt##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos) \
    { \
        return (const type *)array_search_ptr((const Array *)array, func_compare, key, pos); \
    } \
\
    static __TYPECHECK type *arrpt_##type##_bsearch(struct Arr##Pt##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos); \
    static type *arrpt_##type##_bsearch(struct Arr##Pt##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos) \
    { \
        return (type *)array_bsearch_ptr((Array *)array, func_compare, key, pos); \
    } \
\
    static __TYPECHECK const type *arrpt_##type##_bsearch_const(const struct Arr##Pt##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos); \
    static const type *arrpt_##type##_bsearch_const(const struct Arr##Pt##type *array, FPtr_compare func_compare, const void *key, uint32_t *pos) \
    { \
        return (const type *)array_bsearch_ptr((const Array *)array, func_compare, key, pos); \
    } \
\
    __INLINE void arrpt_##type##_end(void)
