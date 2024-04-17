/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: rbtree.h
 *
 */

/* Red - Black trees */

#include "core.hxx"

__EXTERN_C

_core_api RBTree *rbtree_create(FPtr_compare func_compare, const uint16_t esize, const uint16_t ksize, const char_t *type);

_core_api void rbtree_destroy(RBTree **tree, FPtr_remove func_remove, FPtr_destroy func_destroy_key, const char_t *type);

_core_api void rbtree_destroy_ptr(RBTree **tree, FPtr_destroy func_destroy, FPtr_destroy func_destroy_key, const char_t *type);

_core_api uint32_t rbtree_size(const RBTree *tree);

_core_api byte_t *rbtree_get(const RBTree *tree, const void *key, const bool_t isptr);

_core_api byte_t *rbtree_insert(RBTree *tree, const void *key, FPtr_copy func_key_copy);

_core_api bool_t rbtree_insert_ptr(RBTree *tree, void *ptr);

_core_api bool_t rbtree_delete(RBTree *tree, const void *key, FPtr_remove func_remove, FPtr_destroy func_destroy_key);

_core_api bool_t rbtree_delete_ptr(RBTree *tree, const void *key, FPtr_destroy func_destroy, FPtr_destroy func_destroy_key);

_core_api byte_t *rbtree_first(RBTree *tree);

_core_api byte_t *rbtree_last(RBTree *tree);

_core_api byte_t *rbtree_next(RBTree *tree);

_core_api byte_t *rbtree_prev(RBTree *tree);

_core_api byte_t *rbtree_first_ptr(RBTree *tree);

_core_api byte_t *rbtree_last_ptr(RBTree *tree);

_core_api byte_t *rbtree_next_ptr(RBTree *tree);

_core_api byte_t *rbtree_prev_ptr(RBTree *tree);

_core_api const char_t *rbtree_get_key(const RBTree *tree);

_core_api bool_t rbtree_check(const RBTree *tree);

__END_C
