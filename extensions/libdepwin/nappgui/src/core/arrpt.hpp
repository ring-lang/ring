/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: arrpt.hpp
 *
 */

/* Arrays of pointers */

#ifndef __ARRPT_HPP__
#define __ARRPT_HPP__

#include <sewer/bstd.h>
#include <sewer/nowarn.hxx>
#include <typeinfo>
#include <sewer/warn.hxx>

template <class type>
struct ArrPt
{
    static ArrPt<type> *create(void);

    static ArrPt<type> *copy(const ArrPt<type> *array, type *(*func_copy)(const type *));

    static ArrPt<type> *read(Stream *stm, type *(*func_read)(Stream *));

    static void destroy(ArrPt<type> **array, void (*func_destroy)(type **));

    static void destopt(ArrPt<type> **array, void (*func_destroy)(type **));

    static void clear(ArrPt<type> *array, void (*func_destroy)(type **));

    static void write(Stream *stm, const ArrPt<type> *array, void (*func_write)(Stream *, const type *));

    static uint32_t size(const ArrPt<type> *array);

    static type *get(ArrPt<type> *array, const uint32_t pos);

    static const type *get(const ArrPt<type> *array, const uint32_t pos);

    static type *first(ArrPt<type> *array);

    static const type *first(const ArrPt<type> *array);

    static type *last(ArrPt<type> *array);

    static const type *last(const ArrPt<type> *array);

    static type **all(ArrPt<type> *array);

    static const type **all(const ArrPt<type> *array);

    static void grow(ArrPt<type> *array, const uint32_t n);

    static void append(ArrPt<type> *array, const type *value);

    static void prepend(ArrPt<type> *array, const type *value);

    static void insert(ArrPt<type> *array, const uint32_t pos, const type *value);

    static void join(ArrPt<type> *dest, const ArrPt<type> *src, type *(*func_copy)(const type));

    static void ddelete(ArrPt<type> *array, const uint32_t pos, void (*func_destroy)(type **));

    static void pop(ArrPt<type> *array, void (*func_destroy)(type **));

    static void sort(ArrPt<type> *array, int (*func_compare)(const type *, const type *));

    static uint32_t find(ArrPt<type> *array, const type *elem);

#if defined __ASSERTS__
    // Only for debuggers inspector (non used)
    template <class ttype>
    struct TypeData
    {
        ttype *elem[1024];
    };

    uint32_t reserved;
    uint32_t nsize;
    uint16_t elem_sizeof;
    TypeData<type> *content;
#endif
};

template <typename type, typename dtype>
struct ArrP2
{
    static void sort_ex(ArrPt<type> *array, int (*func_compare)(const type *, const type *, const dtype *), const dtype *data);

    static type *search(ArrPt<type> *array, int (*func_compare)(const type *, const type *), const dtype *key, uint32_t *pos);

    static const type *search(const ArrPt<type> *array, int (*func_compare)(const type *, const type *), const dtype *key, uint32_t *pos);

    static type *bsearch(ArrPt<type> *array, int (*func_compare)(const type *, const type *), const dtype *key, uint32_t *pos);

    static const type *bsearch(const ArrPt<type> *array, int (*func_compare)(const type *, const type *), const dtype *key, uint32_t *pos);
};

/*---------------------------------------------------------------------------*/

template <typename type>
ArrPt<type> *ArrPt<type>::create(void)
{
    char_t dtype[64];
    bstd_sprintf(dtype, sizeof(dtype), "ArrPt<%s>", typeid(type).name());
    return (ArrPt<type> *)array_create(sizeof(type *), dtype);
}

/*---------------------------------------------------------------------------*/

template <typename type>
ArrPt<type> *ArrPt<type>::copy(const ArrPt<type> *array, type *(*func_copy)(const type *))
{
    char_t dtype[64];
    bstd_sprintf(dtype, sizeof(dtype), "ArrPt<%s>", typeid(type).name());
    return (ArrPt<type> *)array_copy_ptr((Array *)array, (FPtr_copy)func_copy, dtype);
}

/*---------------------------------------------------------------------------*/

template <typename type>
ArrPt<type> *ArrPt<type>::read(Stream *stm, type *(*func_read)(Stream *))
{
    char_t dtype[64];
    bstd_sprintf(dtype, sizeof(dtype), "ArrPt<%s>", typeid(type).name());
    return (ArrPt<type> *)array_read_ptr(stm, (FPtr_read)func_read, dtype);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::destroy(ArrPt<type> **array, void (*func_destroy)(type **))
{
    char_t dtype[64];
    bstd_sprintf(dtype, sizeof(dtype), "ArrPt<%s>", typeid(type).name());
    array_destroy_ptr((Array **)array, (FPtr_destroy)func_destroy, dtype);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::destopt(ArrPt<type> **array, void (*func_destroy)(type **))
{
    char_t dtype[64];
    bstd_sprintf(dtype, sizeof(dtype), "ArrPt<%s>", typeid(type).name());
    array_destopt_ptr((Array **)array, (FPtr_destroy)func_destroy, dtype);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::clear(ArrPt<type> *array, void (*func_destroy)(type **))
{
    array_clear_ptr((Array *)array, (FPtr_destroy)func_destroy);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::write(Stream *stm, const ArrPt<type> *array, void (*func_write)(Stream *, const type *))
{
    array_write_ptr(stm, (const Array *)array, (FPtr_write)func_write);
}

/*---------------------------------------------------------------------------*/

template <typename type>
uint32_t ArrPt<type>::size(const ArrPt<type> *array)
{
    return array_size((Array *)array);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type *ArrPt<type>::get(ArrPt<type> *array, const uint32_t pos)
{
    return *(type **)array_get((Array *)array, pos);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type *ArrPt<type>::get(const ArrPt<type> *array, const uint32_t pos)
{
    return *(const type **)array_get((const Array *)array, pos);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type *ArrPt<type>::first(ArrPt<type> *array)
{
    return *(type **)array_get((Array *)array, 0);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type *ArrPt<type>::first(const ArrPt<type> *array)
{
    return *(const type **)array_get((const Array *)array, 0);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type *ArrPt<type>::last(ArrPt<type> *array)
{
    return *(type **)array_get_last((Array *)array);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type *ArrPt<type>::last(const ArrPt<type> *array)
{
    return *(const type **)array_get_last((const Array *)array);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type **ArrPt<type>::all(ArrPt<type> *array)
{
    return (type **)array_all((Array *)array);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type **ArrPt<type>::all(const ArrPt<type> *array)
{
    return (const type **)array_all((Array *)array);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::grow(ArrPt<type> *array, const uint32_t n)
{
    array_insert((Array *)array, UINT32_MAX, n);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::append(ArrPt<type> *array, const type *value)
{
    *(type **)array_insert((Array *)array, UINT32_MAX, 1) = (type *)value;
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::prepend(ArrPt<type> *array, const type *value)
{
    *(type **)array_insert((Array *)array, 0, 1) = value;
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::insert(ArrPt<type> *array, const uint32_t pos, const type *value)
{
    *(type **)array_insert((Array *)array, pos, 1) = value;
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::join(ArrPt<type> *dest, const ArrPt<type> *src, type *(*func_copy)(const type))
{
    array_join_ptr((Array *)dest, (const Array *)src, (FPtr_copy)func_copy);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::ddelete(ArrPt<type> *array, const uint32_t pos, void (*func_destroy)(type **))
{
    array_delete_ptr((Array *)array, pos, 1, (FPtr_destroy)func_destroy);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::pop(ArrPt<type> *array, void (*func_destroy)(type **))
{
    array_pop_ptr((Array *)array, (FPtr_destroy)func_destroy);
}

/*---------------------------------------------------------------------------*/

template <typename type>
void ArrPt<type>::sort(ArrPt<type> *array, int (*func_compare)(const type *, const type *))
{
    array_sort_ptr((Array *)array, (FPtr_compare)func_compare);
}

/*---------------------------------------------------------------------------*/

template <typename type>
uint32_t ArrPt<type>::find(ArrPt<type> *array, const type *elem)
{
    return array_find_ptr((const Array *)array, (const void *)elem);
}

/*---------------------------------------------------------------------------*/

template <typename type, typename dtype>
void ArrP2<type, dtype>::sort_ex(ArrPt<type> *array, int (*func_compare)(const type *, const type *, const dtype *), const dtype *data)
{
    array_sort_ptr_ex((Array *)array, (FPtr_compare_ex)func_compare, (void *)data);
}

/*---------------------------------------------------------------------------*/

template <typename type, typename dtype>
type *ArrP2<type, dtype>::search(ArrPt<type> *array, int (*func_compare)(const type *, const type *), const dtype *key, uint32_t *pos)
{
    return (type *)array_search_ptr((Array *)array, (FPtr_compare)func_compare, (const void *)key, pos);
}

/*---------------------------------------------------------------------------*/

template <typename type, typename dtype>
const type *ArrP2<type, dtype>::search(const ArrPt<type> *array, int (*func_compare)(const type *, const type *), const dtype *key, uint32_t *pos)
{
    return (const type *)array_search_ptr((const Array *)array, (FPtr_compare)func_compare, (const void *)key, pos);
}

/*---------------------------------------------------------------------------*/

template <typename type, typename dtype>
type *ArrP2<type, dtype>::bsearch(ArrPt<type> *array, int (*func_compare)(const type *, const type *), const dtype *key, uint32_t *pos)
{
    return (type *)array_bsearch_ptr((Array *)array, (FPtr_compare)func_compare, (const void *)key, pos);
}

/*---------------------------------------------------------------------------*/

template <typename type, typename dtype>
const type *ArrP2<type, dtype>::bsearch(const ArrPt<type> *array, int (*func_compare)(const type *, const type *), const dtype *key, uint32_t *pos)
{
    return (const type *)array_bsearch_ptr((const Array *)array, (FPtr_compare)func_compare, (const void *)key, pos);
}

#endif
