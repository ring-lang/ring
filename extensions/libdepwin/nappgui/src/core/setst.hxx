/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: setst.hxx
 * https://nappgui.com/en/core/setst.html
 *
 */

/* Set macros for type checking at compile time */

#define SetStDebug(type) \
    struct NodeSt##type \
    { \
        uint32_t rb; \
        struct NodeSt##type *left; \
        struct NodeSt##type *right; \
        type data; \
    }; \
\
    struct Set##St##type \
    { \
        uint32_t elems; \
        uint16_t esize; \
        uint16_t ksize; \
        struct NodeSt##type *root; \
        FPtr_compare func_compare; \
    }

#define SetStFuncs(type) \
    SetSt(type); \
\
    static __TYPECHECK SetSt(type) *setst_##type##_create(int(func_compare)(const type *, const type *), const uint16_t esize); \
    static SetSt(type) *setst_##type##_create(int(func_compare)(const type *, const type *), const uint16_t esize) \
    { \
        return (SetSt(type) *)rbtree_create((FPtr_compare)func_compare, esize, 0, (const char_t *)(SETST #type)); \
    } \
\
    static __TYPECHECK void setst_##type##_destroy(struct Set##St##type **set, void(func_remove)(type *)); \
    static void setst_##type##_destroy(struct Set##St##type **set, void(func_remove)(type *)) \
    { \
        rbtree_destroy((RBTree **)set, (FPtr_remove)func_remove, NULL, (const char_t *)(SETST #type)); \
    } \
\
    static __TYPECHECK uint32_t setst_##type##_size(const struct Set##St##type *set); \
    static uint32_t setst_##type##_size(const struct Set##St##type *set) \
    { \
        return rbtree_size((const RBTree *)set); \
    } \
\
    static __TYPECHECK type *setst_##type##_get(struct Set##St##type *set, const type *key); \
    static type *setst_##type##_get(struct Set##St##type *set, const type *key) \
    { \
        return (type *)rbtree_get((RBTree *)set, (const void *)key, FALSE); \
    } \
\
    static __TYPECHECK const type *setst_##type##_get_const(const struct Set##St##type *set, const type *key); \
    static const type *setst_##type##_get_const(const struct Set##St##type *set, const type *key) \
    { \
        return (const type *)rbtree_get((RBTree *)set, (const void *)key, FALSE); \
    } \
\
    static __TYPECHECK type *setst_##type##_insert(struct Set##St##type *set, const type *key); \
    static type *setst_##type##_insert(struct Set##St##type *set, const type *key) \
    { \
        return (type *)rbtree_insert((RBTree *)set, (const void *)key, NULL); \
    } \
\
    static __TYPECHECK bool_t setst_##type##_delete(struct Set##St##type *set, const type *key, void(func_remove)(type *)); \
    static bool_t setst_##type##_delete(struct Set##St##type *set, const type *key, void(func_remove)(type *)) \
    { \
        return rbtree_delete((RBTree *)set, (const void *)key, (FPtr_remove)func_remove, NULL); \
    } \
\
    static __TYPECHECK type *setst_##type##_first(struct Set##St##type *set); \
    static type *setst_##type##_first(struct Set##St##type *set) \
    { \
        return (type *)rbtree_first((RBTree *)set); \
    } \
\
    static __TYPECHECK const type *setst_##type##_first_const(const struct Set##St##type *set); \
    static const type *setst_##type##_first_const(const struct Set##St##type *set) \
    { \
        return (const type *)rbtree_first((RBTree *)set); \
    } \
\
    static __TYPECHECK type *setst_##type##_last(struct Set##St##type *set); \
    static type *setst_##type##_last(struct Set##St##type *set) \
    { \
        return (type *)rbtree_last((RBTree *)set); \
    } \
\
    static __TYPECHECK const type *setst_##type##_last_const(const struct Set##St##type *set); \
    static const type *setst_##type##_last_const(const struct Set##St##type *set) \
    { \
        return (const type *)rbtree_last((RBTree *)set); \
    } \
\
    static __TYPECHECK type *setst_##type##_next(struct Set##St##type *set); \
    static type *setst_##type##_next(struct Set##St##type *set) \
    { \
        return (type *)rbtree_next((RBTree *)set); \
    } \
\
    static __TYPECHECK const type *setst_##type##_next_const(const struct Set##St##type *set); \
    static const type *setst_##type##_next_const(const struct Set##St##type *set) \
    { \
        return (const type *)rbtree_next((RBTree *)set); \
    } \
\
    static __TYPECHECK type *setst_##type##_prev(struct Set##St##type *set); \
    static type *setst_##type##_prev(struct Set##St##type *set) \
    { \
        return (type *)rbtree_prev((RBTree *)set); \
    } \
\
    static __TYPECHECK const type *setst_##type##_prev_const(const struct Set##St##type *set); \
    static const type *setst_##type##_prev_const(const struct Set##St##type *set) \
    { \
        return (const type *)rbtree_prev((RBTree *)set); \
    } \
\
    __INLINE void setst_##type##_end(void)
