/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: setpt.hxx
 * https://nappgui.com/en/core/setpt.html
 *
 */

/* Set macros for type checking at compile time */

#define SetPtDebug(type) \
    struct NodePt##type \
    { \
        uint32_t rb; \
        struct NodePt##type *left; \
        struct NodePt##type *right; \
        type *data; \
    }; \
\
    struct Set##Pt##type \
    { \
        uint32_t elems; \
        uint16_t esize; \
        uint16_t ksize; \
        struct NodePt##type *root; \
        FPtr_compare func_compare; \
    }

#define SetPtFuncs(type) \
    SetPt(type); \
\
    static __TYPECHECK SetPt(type) *setpt_##type##_create(int(func_compare)(const type *, const type *), const uint16_t esize); \
    static SetPt(type) *setpt_##type##_create(int(func_compare)(const type *, const type *), const uint16_t esize) \
    { \
        return (SetPt(type) *)rbtree_create((FPtr_compare)func_compare, esize, 0, (const char_t *)(SETPT #type)); \
    } \
\
    static __TYPECHECK void setpt_##type##_destroy(struct Set##Pt##type **set, void(func_destroy)(type **)); \
    static void setpt_##type##_destroy(struct Set##Pt##type **set, void(func_destroy)(type **)) \
    { \
        rbtree_destroy_ptr((RBTree **)set, (FPtr_destroy)func_destroy, NULL, (const char_t *)(SETPT #type)); \
    } \
\
    static __TYPECHECK uint32_t setpt_##type##_size(const struct Set##Pt##type *set); \
    static uint32_t setpt_##type##_size(const struct Set##Pt##type *set) \
    { \
        return rbtree_size((const RBTree *)set); \
    } \
\
    static __TYPECHECK type *setpt_##type##_get(struct Set##Pt##type *set, const type *key); \
    static type *setpt_##type##_get(struct Set##Pt##type *set, const type *key) \
    { \
        return (type *)rbtree_get((RBTree *)set, (const void *)key, TRUE); \
    } \
\
    static __TYPECHECK const type *setpt_##type##_get_const(const struct Set##Pt##type *set, const type *key); \
    static const type *setpt_##type##_get_const(const struct Set##Pt##type *set, const type *key) \
    { \
        return (const type *)rbtree_get((RBTree *)set, (const void *)key, TRUE); \
    } \
\
    static __TYPECHECK bool_t setpt_##type##_insert(struct Set##Pt##type *set, type *value); \
    static bool_t setpt_##type##_insert(struct Set##Pt##type *set, type *value) \
    { \
        return rbtree_insert_ptr((RBTree *)set, (void *)value); \
    } \
\
    static __TYPECHECK bool_t setpt_##type##_delete(struct Set##Pt##type *set, const type *key, void(func_destroy)(type **)); \
    static bool_t setpt_##type##_delete(struct Set##Pt##type *set, const type *key, void(func_destroy)(type **)) \
    { \
        return rbtree_delete_ptr((RBTree *)set, (const void *)key, (FPtr_destroy)func_destroy, NULL); \
    } \
\
    static __TYPECHECK type *setpt_##type##_first(struct Set##Pt##type *set); \
    static type *setpt_##type##_first(struct Set##Pt##type *set) \
    { \
        return (type *)rbtree_first_ptr((RBTree *)set); \
    } \
\
    static __TYPECHECK const type *setpt_##type##_first_const(const struct Set##Pt##type *set); \
    static const type *setpt_##type##_first_const(const struct Set##Pt##type *set) \
    { \
        return (const type *)rbtree_first_ptr((RBTree *)set); \
    } \
\
    static __TYPECHECK type *setpt_##type##_last(struct Set##Pt##type *set); \
    static type *setpt_##type##_last(struct Set##Pt##type *set) \
    { \
        return (type *)rbtree_last_ptr((RBTree *)set); \
    } \
\
    static __TYPECHECK const type *setpt_##type##_last_const(const struct Set##Pt##type *set); \
    static const type *setpt_##type##_last_const(const struct Set##Pt##type *set) \
    { \
        return (const type *)rbtree_last_ptr((RBTree *)set); \
    } \
\
    static __TYPECHECK type *setpt_##type##_next(struct Set##Pt##type *set); \
    static type *setpt_##type##_next(struct Set##Pt##type *set) \
    { \
        return (type *)rbtree_next_ptr((RBTree *)set); \
    } \
\
    static __TYPECHECK const type *setpt_##type##_next_const(const struct Set##Pt##type *set); \
    static const type *setpt_##type##_next_const(const struct Set##Pt##type *set) \
    { \
        return (const type *)rbtree_next_ptr((RBTree *)set); \
    } \
\
    static __TYPECHECK type *setpt_##type##_prev(struct Set##Pt##type *set); \
    static type *setpt_##type##_prev(struct Set##Pt##type *set) \
    { \
        return (type *)rbtree_prev_ptr((RBTree *)set); \
    } \
\
    static __TYPECHECK const type *setpt_##type##_prev_const(const struct Set##Pt##type *set); \
    static const type *setpt_##type##_prev_const(const struct Set##Pt##type *set) \
    { \
        return (const type *)rbtree_prev_ptr((RBTree *)set); \
    } \
\
    __INLINE void setpt_##type##_end(void)
