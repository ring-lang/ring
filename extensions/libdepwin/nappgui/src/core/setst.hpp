/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: setst.hpp
 *
 */

/* Set of structures */

#ifndef __SETST_HPP__
#define __SETST_HPP__

#include <sewer/bstd.h>
#include <sewer/nowarn.hxx>
#include <typeinfo>
#include <sewer/warn.hxx>

template <class type>
struct SetSt
{
    static SetSt<type> *create(int(func_compare)(const type *, const type *));

    static void destroy(SetSt<type> **set, void (*func_remove)(type *));

    static uint32_t size(const SetSt<type> *set);

    static type *get(SetSt<type> *set, const type *key);

    static const type *get(const SetSt<type> *set, const type *key);

    static bool_t ddelete(SetSt<type> *set, const type *key, void (*func_remove)(type *));

    static type *first(SetSt<type> *set);

    static const type *first(const SetSt<type> *set);

    static type *last(SetSt<type> *set);

    static const type *last(const SetSt<type> *set);

    static type *next(SetSt<type> *set);

    static const type *next(const SetSt<type> *set);

    static type *prev(SetSt<type> *set);

    static const type *prev(const SetSt<type> *set);

#if defined __ASSERTS__
    // Only for debuggers inspector (non used)
    template <class ttype>
    struct TypeNode
    {
        uint32_t rb;
        struct TypeNode<ttype> *left;
        struct TypeNode<ttype> *right;
        ttype data;
    };

    uint32_t elems;
    uint16_t esize;
    uint16_t ksize;
    TypeNode<type> *root;
    FPtr_compare func_compare;
#endif
};

/*---------------------------------------------------------------------------*/

template <typename type>
static const char_t *i_settype(void)
{
    static char_t dtype[64];
    bstd_sprintf(dtype, sizeof(dtype), "SetSt<%s>", typeid(type).name());
    return dtype;
}

/*---------------------------------------------------------------------------*/

template <typename type>
SetSt<type> *SetSt<type>::create(int(func_compare)(const type *, const type *))
{
    return (SetSt<type> *)rbtree_create((FPtr_compare)func_compare, (uint16_t)sizeof(type), 0, i_settype<type>());
}

/*---------------------------------------------------------------------------*/

template <typename type>
void SetSt<type>::destroy(SetSt<type> **set, void (*func_remove)(type *))
{
    rbtree_destroy((RBTree **)set, (FPtr_remove)func_remove, NULL, i_settype<type>());
}

/*---------------------------------------------------------------------------*/

template <typename type>
uint32_t SetSt<type>::size(const SetSt<type> *set)
{
    return rbtree_size((const RBTree *)set);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type *SetSt<type>::get(SetSt<type> *set, const type *key)
{
    return (type *)rbtree_get((RBTree *)set, (const void *)key, FALSE);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type *SetSt<type>::get(const SetSt<type> *set, const type *key)
{
    return (const type *)rbtree_get((RBTree *)set, (const void *)key, FALSE);
}

/*---------------------------------------------------------------------------*/

template <typename type>
bool_t SetSt<type>::ddelete(SetSt<type> *set, const type *key, void (*func_remove)(type *))
{
    return rbtree_delete((RBTree *)set, (const void *)key, (FPtr_remove)func_remove, NULL);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type *SetSt<type>::first(SetSt<type> *set)
{
    return (type *)rbtree_first((RBTree *)set);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type *SetSt<type>::first(const SetSt<type> *set)
{
    return (const type *)rbtree_first((RBTree *)set);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type *SetSt<type>::last(SetSt<type> *set)
{
    return (type *)rbtree_last((RBTree *)set);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type *SetSt<type>::last(const SetSt<type> *set)
{
    return (const type *)rbtree_last((RBTree *)set);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type *SetSt<type>::next(SetSt<type> *set)
{
    return (type *)rbtree_next((RBTree *)set);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type *SetSt<type>::next(const SetSt<type> *set)
{
    return (const type *)rbtree_next((RBTree *)set);
}

/*---------------------------------------------------------------------------*/

template <typename type>
type *SetSt<type>::prev(SetSt<type> *set)
{
    return (type *)rbtree_prev((RBTree *)set);
}

/*---------------------------------------------------------------------------*/

template <typename type>
const type *SetSt<type>::prev(const SetSt<type> *set)
{
    return (const type *)rbtree_prev((RBTree *)set);
}

#endif
