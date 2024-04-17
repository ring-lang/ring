/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: rbtree.c
 *
 */

/* Red - Black trees */

#include "rbtree.h"
#include "heap.h"
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

typedef enum i_type_t
{
    i_RED_NODE = 0,
    i_BLACK_NODE = 1
} i_type_t;

typedef struct i_node_t i_Node;
typedef i_Node *i_NodePt;
typedef struct i_iterator_t i_Iterator;

struct i_node_t
{
    i_type_t type;
    i_Node *lnode;
    i_Node *rnode;
};

#define i_NODE_DATA(node) \
    ((void)((i_Node *)node == node), \
     ((byte_t *)node + sizeof(i_Node)))

struct i_iterator_t
{
    uint16_t path_size;
    uint16_t path_alloc;
    i_NodePt *path;
};

struct _rbtree_t
{
    uint32_t elems;
    uint16_t esize;
    uint16_t ksize;
    i_Node *root;
    FPtr_compare func_compare;
    i_Iterator it;
};

/*---------------------------------------------------------------------------*/

static i_Node *i_create_node(const uint16_t esize, const uint16_t ksize)
{
    i_Node *node = (i_Node *)heap_malloc(sizeof32(i_Node) + esize + ksize, "RBNode");
    node->type = i_RED_NODE;
    node->lnode = NULL;
    node->rnode = NULL;
    return node;
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_dealloc_node(i_Node **node, const uint16_t esize, const uint16_t ksize)
{
    heap_free((byte_t **)node, sizeof32(i_Node) + esize + ksize, "RBNode");
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_destroy_node_data(
    i_Node *node,
    __DEBUG_PARAMC(const uint16_t esize)
        const uint16_t ksize,
    FPtr_remove func_remove,
    FPtr_destroy func_destroy,
    FPtr_destroy func_destroy_key)
{
    cassert_no_null(node);

    if (func_destroy_key != NULL)
    {
        void **key = (void **)i_NODE_DATA(node);
        cassert(ksize == sizeofptr);
        func_destroy_key(key);
    }

    if (func_remove != NULL)
    {
        void *data = i_NODE_DATA(node) + ksize;
        cassert(func_destroy == NULL);
        func_remove(data);
    }
    else if (func_destroy != NULL)
    {
        void **data = (void **)(i_NODE_DATA(node) + ksize);
#if defined(__ASSERTS__)
        cassert(esize == sizeofptr);
#endif
        func_destroy(data);
    }
}

/*---------------------------------------------------------------------------*/

static void i_destroy_node(
    i_Node **node,
    const uint16_t esize,
    const uint16_t ksize,
    FPtr_remove func_remove,
    FPtr_destroy func_destroy,
    FPtr_destroy func_destroy_key)
{
    cassert_no_null(node);
    cassert_no_null(*node);

    if ((*node)->lnode != NULL)
        i_destroy_node(&(*node)->lnode, esize, ksize, func_remove, func_destroy, func_destroy_key);

    if ((*node)->rnode != NULL)
        i_destroy_node(&(*node)->rnode, esize, ksize, func_remove, func_destroy, func_destroy_key);

    i_destroy_node_data(*node, __DEBUG_PARAMC(esize) ksize, func_remove, func_destroy, func_destroy_key);
    i_dealloc_node(node, esize, ksize);
}

/*---------------------------------------------------------------------------*/

static void i_destroy_rbtree(RBTree **tree, FPtr_remove func_remove, FPtr_destroy func_destroy, FPtr_destroy func_destroy_key, const char_t *type)
{
    cassert_no_null(tree);
    cassert_no_null(*tree);

    if ((*tree)->root != NULL)
        i_destroy_node(&(*tree)->root, (*tree)->esize, (*tree)->ksize, func_remove, func_destroy, func_destroy_key);

    heap_delete_n(&(*tree)->it.path, (*tree)->it.path_alloc, i_NodePt);
    heap_free((byte_t **)tree, sizeof(RBTree), type);
}

/*---------------------------------------------------------------------------*/

RBTree *rbtree_create(FPtr_compare func_compare, const uint16_t esize, const uint16_t ksize, const char_t *type)
{
    RBTree *tree = (RBTree *)heap_malloc(sizeof(RBTree), type);
    tree->func_compare = func_compare;
    tree->elems = 0;
    tree->esize = esize;
    tree->ksize = ksize > 0 ? ksize + ksize % sizeofptr : ksize; /* Node element alignment */
    tree->root = NULL;
    tree->it.path_size = 0;
    tree->it.path_alloc = 8;
    tree->it.path = heap_new_n(tree->it.path_alloc, i_NodePt);
    return tree;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_log2(const uint32_t value)
{
    register uint32_t valuep = value;
    register uint32_t log2p = 0;
    cassert(value > 0);
    while (valuep > 0)
    {
        valuep >>= 1;
        log2p++;
    }
    return log2p;
}

/*---------------------------------------------------------------------------*/

static void i_update_iterator_size(const uint32_t nelems, i_Iterator *it)
{
    register uint32_t path_alloc = i_log2(nelems + 1);
    path_alloc += 1;
    path_alloc <<= 1;
    cassert_no_null(it);
    if (it->path_alloc != path_alloc)
    {
        it->path = heap_realloc_n(it->path, it->path_alloc, path_alloc, i_NodePt);
        it->path_alloc = (uint16_t)path_alloc;
    }
}

/*---------------------------------------------------------------------------*/

void rbtree_destroy(RBTree **tree, FPtr_remove func_remove, FPtr_destroy func_destroy_key, const char_t *type)
{
    i_destroy_rbtree(tree, func_remove, NULL, func_destroy_key, type);
}

/*---------------------------------------------------------------------------*/

void rbtree_destroy_ptr(RBTree **tree, FPtr_destroy func_destroy, FPtr_destroy func_destroy_key, const char_t *type)
{
    i_destroy_rbtree(tree, NULL, func_destroy, func_destroy_key, type);
}

/*---------------------------------------------------------------------------*/

uint32_t rbtree_size(const RBTree *tree)
{
    cassert_no_null(tree);
    return tree->elems;
}

/*---------------------------------------------------------------------------*/
#if defined(__ASSERTS__)
static __INLINE i_Node *i_current_node(const i_Iterator *it)
{
    i_Node *node;
    cassert_no_null(it);
    cassert(it->path_size < it->path_alloc);
    node = it->path[it->path_size - 1];
    cassert_no_null(node);
    if (node->type == i_RED_NODE)
    {
        if (node->lnode != NULL)
            cassert(node->lnode->type == i_BLACK_NODE);
        if (node->rnode != NULL)
            cassert(node->rnode->type == i_BLACK_NODE);
    }
    return node;
}

#define i_cnode(it) i_current_node(it)

#else
#define i_cnode(it) it->path[it->path_size - 1]

#endif

/*---------------------------------------------------------------------------*/

static int i_node_by_key(i_Node *root, const void *key, const bool_t isptr, FPtr_compare func_compare, i_Iterator *it)
{
    cassert_no_null(root);
    cassert(root->type == i_BLACK_NODE);
    cassert_no_nullf(func_compare);
    cassert_no_null(it);
    it->path_size = 1;
    it->path[0] = root;

    for (;;)
    {
        register const i_Node *cnode = it->path[it->path_size - 1];
        register const byte_t *cdata;
        register int compare;
        cassert_no_null(cnode);
        cdata = i_NODE_DATA(cnode);
        compare = func_compare(isptr == TRUE ? *((byte_t **)cdata) : cdata, key);
        if (__TRUE_EXPECTED(compare > 0))
        {
            if (__TRUE_EXPECTED(cnode->lnode != NULL))
            {
                it->path[it->path_size++] = cnode->lnode;
            }
            else
            {
                return 1;
            }
        }
        else if (__TRUE_EXPECTED(compare < 0))
        {
            if (__TRUE_EXPECTED(cnode->rnode != NULL))
            {
                it->path[it->path_size++] = cnode->rnode;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return 0;
        }
    }
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_get(const RBTree *tree, const void *key, const bool_t isptr)
{
    cassert_no_null(tree);
    if (__TRUE_EXPECTED(tree->root != NULL))
    {
        register int result = i_node_by_key(tree->root, key, isptr, tree->func_compare, &((RBTree *)tree)->it);
        if (result == 0)
        {
            byte_t *elem;
            cassert(tree->it.path_size > 0);
            cassert(tree->it.path_size <= tree->it.path_alloc);
            elem = i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize;
            return isptr ? *((byte_t **)elem) : elem;
        }
    }

    ((RBTree *)tree)->it.path_size = 0;
    return NULL;
}

/*---------------------------------------------------------------------------*/

static bool_t i_first(i_Node *root, i_Iterator *it)
{
    if (root != NULL)
    {
        i_Node *lnode = root->lnode;
        cassert_no_null(it);
        it->path_size = 1;
        it->path[0] = root;
        while (lnode != NULL)
        {
            it->path[it->path_size] = lnode;
            it->path_size += 1;
            lnode = lnode->lnode;
        }

        return TRUE;
    }
    else
    {
        it->path_size = 0;
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_last(i_Node *root, i_Iterator *it)
{
    if (root != NULL)
    {
        i_Node *rnode = root->rnode;
        cassert_no_null(it);
        it->path_size = 1;
        it->path[0] = root;
        while (rnode != NULL)
        {
            it->path[it->path_size] = rnode;
            it->path_size += 1;
            rnode = rnode->rnode;
        }

        return TRUE;
    }
    else
    {
        it->path_size = 0;
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_inorder_next(i_Iterator *it)
{
    i_Node *cnode = i_cnode(it);
    cassert_no_null(cnode);
    if (cnode->rnode != NULL)
    {
        cnode = cnode->rnode;
        it->path[it->path_size] = cnode;
        it->path_size += 1;

        while (cnode->lnode != NULL)
        {
            cassert(it->path_size <= it->path_alloc);
            cnode = cnode->lnode;
            it->path[it->path_size] = cnode;
            it->path_size += 1;
        }

        return TRUE;
    }
    else
    {
        while (it->path_size > 1)
        {
            i_Node *parent;
            it->path_size -= 1;
            parent = it->path[it->path_size - 1];
            cassert_no_null(parent);

            if (parent->lnode == cnode)
                return TRUE;
            else
                cnode = parent;
        }

        /*! <We are in the last inorder element> */
        it->path_size = 0;
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_inorder_prev(i_Iterator *it)
{
    i_Node *cnode = i_cnode(it);
    cassert_no_null(cnode);
    if (cnode->lnode != NULL)
    {
        cnode = cnode->lnode;
        it->path[it->path_size] = cnode;
        it->path_size += 1;

        while (cnode->rnode != NULL)
        {
            cassert(it->path_size <= it->path_alloc);
            cnode = cnode->rnode;
            it->path[it->path_size] = cnode;
            it->path_size += 1;
        }

        return TRUE;
    }
    else
    {
        while (it->path_size > 1)
        {
            i_Node *parent;
            it->path_size -= 1;
            parent = it->path[it->path_size - 1];
            cassert_no_null(parent);

            if (parent->rnode == cnode)
                return TRUE;
            else
                cnode = parent;
        }

        /*! <We are in the first inorder element> */
        it->path_size = 0;
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_rotate_left(i_Node *node, i_Node *parent, i_Node **root)
{
    i_Node *rnode;
    cassert_no_null(node);
    rnode = node->rnode;
    cassert_no_null(rnode);
    node->rnode = rnode->lnode;
    rnode->lnode = node;

    if (__TRUE_EXPECTED(parent != NULL))
    {
        if (parent->lnode == node)
        {
            parent->lnode = rnode;
        }
        else
        {
            cassert(parent->rnode == node);
            parent->rnode = rnode;
        }
    }
    else
    {
        cassert_no_null(root);
        cassert(node == *root);
        *root = rnode;
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_rotate_right(i_Node *node, i_Node *parent, i_Node **root)
{
    i_Node *lnode;
    cassert_no_null(node);
    lnode = node->lnode;
    cassert_no_null(lnode);
    node->lnode = lnode->rnode;
    lnode->rnode = node;

    if (__TRUE_EXPECTED(parent != NULL))
    {
        if (parent->lnode == node)
        {
            parent->lnode = lnode;
        }
        else
        {
            cassert(parent->rnode == node);
            parent->rnode = lnode;
        }
    }
    else
    {
        cassert_no_null(root);
        cassert(node == *root);
        *root = lnode;
    }
}

/*---------------------------------------------------------------------------*/

static void i_restructure_after_insert(i_Iterator *it, i_Node **root)
{
    register uint32_t i;
    cassert_no_null(it);
    cassert(it->path_size > 1);
    i = it->path_size;

    while (i > 0)
    {
        i_Node *cnode = it->path[i - 1];
        cassert_no_null(cnode);
        cassert(cnode->type == i_RED_NODE);

        if (i > 1)
        {
            i_Node *parent = it->path[i - 2];
            cassert_no_null(parent);
            if (parent->type == i_RED_NODE)
            {
                i_Node *grand;
                cassert(i > 2);
                grand = it->path[i - 3];
                cassert_no_null(grand);
                cassert(grand->type == i_BLACK_NODE);

                if (parent == grand->lnode)
                {
                    i_Node *uncle = grand->rnode;

                    if (uncle != NULL && uncle->type == i_RED_NODE)
                    {
                        parent->type = i_BLACK_NODE;
                        uncle->type = i_BLACK_NODE;
                        grand->type = i_RED_NODE;
                        i -= 2;
                    }
                    else
                    {
                        i_Node *grand2;

                        if (cnode == parent->rnode)
                        {
                            i_rotate_left(parent, grand, root);
                            parent = cnode;
                        }

                        if (__TRUE_EXPECTED(i > 3))
                            grand2 = it->path[i - 4];
                        else
                            grand2 = NULL;

                        parent->type = i_BLACK_NODE;
                        grand->type = i_RED_NODE;
                        i_rotate_right(grand, grand2, root);
                        return;
                    }
                }
                /*! <Symmetric case "right" and "left" exchanged> */
                else
                {
                    i_Node *uncle = grand->lnode;
                    if (uncle != NULL && uncle->type == i_RED_NODE)
                    {
                        parent->type = i_BLACK_NODE;
                        uncle->type = i_BLACK_NODE;
                        grand->type = i_RED_NODE;
                        i -= 2;
                    }
                    else
                    {
                        i_Node *grand2;

                        if (cnode == parent->lnode)
                        {
                            i_rotate_right(parent, grand, root);
                            parent = cnode;
                        }

                        if (__TRUE_EXPECTED(i > 3))
                            grand2 = it->path[i - 4];
                        else
                            grand2 = NULL;

                        parent->type = i_BLACK_NODE;
                        grand->type = i_RED_NODE;
                        i_rotate_left(grand, grand2, root);
                        return;
                    }
                }
            }
            else
            {
                /*! <Parent is BLACK. Reestructure is finish> */
                return;
            }
        }
        else
        {
            /*! <Current node is the root> */
            cnode->type = i_BLACK_NODE;
            return;
        }
    }
}

/*---------------------------------------------------------------------------*/

static i_Node *i_insert_node(
    i_Node **root,
    const uint32_t elems,
    const void *key,
    const bool_t isptr,
    FPtr_compare func_compare,
    i_Iterator *it,
    const uint16_t esize,
    const uint16_t ksize)
{
    cassert_no_null(root);
    cassert_no_null(it);

    if (__TRUE_EXPECTED(*root != NULL))
    {
        register int result = i_node_by_key(*root, key, isptr, func_compare, it);
        cassert(it->path_size > 0);
        cassert(it->path_size < it->path_alloc);

        if (result != 0)
        {
            i_Node *new_node;
            i_Node *parent;
            new_node = i_create_node(esize, ksize);
            parent = it->path[it->path_size - 1];
            cassert_no_null(parent);

            if (result > 0)
            {
                cassert(parent->lnode == NULL);
                parent->lnode = new_node;
            }
            else
            {
                cassert(parent->rnode == NULL);
                parent->rnode = new_node;
            }

            i_update_iterator_size(1 + elems, it);
            cassert(it->path_size < it->path_alloc);
            it->path[it->path_size] = new_node;
            it->path_size += 1;
            i_restructure_after_insert(it, root);
            return new_node;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        i_Node *new_node = i_create_node(ksize, esize);
        new_node->type = i_BLACK_NODE;
        *root = new_node;
        return new_node;
    }
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_insert(RBTree *tree, const void *key, FPtr_copy func_key_copy)
{
    i_Node *new_node = i_insert_node(&tree->root, tree->elems, key, FALSE, tree->func_compare, &tree->it, tree->ksize, tree->esize);
    tree->it.path_size = 0;
    if (new_node != NULL)
    {
        tree->elems += 1;
        if (func_key_copy != NULL)
        {
            void **dkey = (void **)i_NODE_DATA(new_node);
            cassert(tree->ksize == sizeofptr);
            *dkey = func_key_copy(key);
        }
        else if (tree->ksize > 0)
        {
            bmem_copy(i_NODE_DATA(new_node), (const byte_t *)key, tree->ksize);
        }

        return i_NODE_DATA(new_node) + tree->ksize;
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

bool_t rbtree_insert_ptr(RBTree *tree, void *ptr)
{
    i_Node *new_node = i_insert_node(&tree->root, tree->elems, ptr, TRUE, tree->func_compare, &tree->it, tree->ksize, tree->esize);
    tree->it.path_size = 0;
    if (new_node != NULL)
    {
        tree->elems += 1;
        cassert(tree->ksize == 0);
        *((byte_t **)(i_NODE_DATA(new_node) + tree->ksize)) = (byte_t *)ptr;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static void i_restructure_after_delete(i_Iterator *it, i_Node **root)
{
    register uint32_t i;

    cassert_no_null(it);
    cassert(it->path_size > 0);
    cassert_no_null(root);

    i = it->path_size;

    while (i > 1)
    {
        i_Node *cnode = it->path[i - 1];
        if (cnode == NULL || cnode->type == i_BLACK_NODE)
        {
            i_Node *parent = it->path[i - 2];
            cassert_no_null(parent);
            if (cnode == parent->lnode)
            {
                i_Node *brother = parent->rnode;
                cassert_no_null(brother);

                /*! <Case 1: The brother is red> */
                if (brother->type == i_RED_NODE)
                {
                    i_Node *grand = (i > 2) ? it->path[i - 3] : NULL;
                    brother->type = i_BLACK_NODE;
                    parent->type = i_RED_NODE;
                    i_rotate_left(parent, grand, root);
                    cassert(i >= 2);
                    it->path[i] = it->path[i - 1];
                    it->path[i - 1] = it->path[i - 2];
                    it->path[i - 2] = brother;
                    i += 1;

                    brother = parent->rnode;
                    cassert_no_null(brother);
                }

                cassert(brother->type == i_BLACK_NODE);

                /*! <Case 2: Two children of brother are BLACK> */
                if ((brother->lnode == NULL || brother->lnode->type == i_BLACK_NODE) && (brother->rnode == NULL || brother->rnode->type == i_BLACK_NODE))
                {
                    brother->type = i_RED_NODE;
                    cassert(i > 0);
                    i -= 1;
                }
                else
                {
                    i_Node *grand = NULL;
                    /*! <Case 3: Left child of brother is RED> */
                    if (brother->rnode == NULL || brother->rnode->type == i_BLACK_NODE)
                    {
                        cassert_no_null(brother->lnode);
                        cassert(brother->lnode->type == i_RED_NODE);
                        brother->lnode->type = i_BLACK_NODE;
                        brother->type = i_RED_NODE;
                        i_rotate_right(brother, parent, root);
                        brother = parent->rnode;
                        cassert_no_null(brother);
                    }

                    /*! <Case 4: Right child of brother is RED> */
                    cassert(brother->type == i_BLACK_NODE);
                    cassert_no_null(brother->rnode);
                    cassert(brother->rnode->type == i_RED_NODE);
                    brother->type = parent->type;
                    brother->rnode->type = i_BLACK_NODE;
                    parent->type = i_BLACK_NODE;
                    grand = (i > 2) ? it->path[i - 3] : NULL;
                    i_rotate_left(parent, grand, root);
                    i = 1;
                }
            }
            /*! <Symmetric case "right" and "left" exchanged> */
            else
            {
                i_Node *brother = parent->lnode;
                cassert_no_null(brother);
                /*! <Case 1: The brother is red> */
                if (brother->type == i_RED_NODE)
                {
                    i_Node *grand = (i > 2) ? it->path[i - 3] : NULL;
                    brother->type = i_BLACK_NODE;
                    parent->type = i_RED_NODE;
                    i_rotate_right(parent, grand, root);
                    cassert(i >= 2);
                    it->path[i] = it->path[i - 1];
                    it->path[i - 1] = it->path[i - 2];
                    it->path[i - 2] = brother;
                    i += 1;
                    brother = parent->lnode;
                    cassert_no_null(brother);
                }

                cassert(brother->type == i_BLACK_NODE);

                /*! <Case 2: Two children of brother are BLACK> */
                if ((brother->rnode == NULL || brother->rnode->type == i_BLACK_NODE) && (brother->lnode == NULL || brother->lnode->type == i_BLACK_NODE))
                {
                    brother->type = i_RED_NODE;
                    cassert(i > 0);
                    i -= 1;
                }
                else
                {
                    i_Node *grand = NULL;

                    /*! <Case 3: Right child of brother is RED> */
                    if (brother->lnode == NULL || brother->lnode->type == i_BLACK_NODE)
                    {
                        cassert_no_null(brother->rnode);
                        cassert(brother->rnode->type == i_RED_NODE);
                        brother->rnode->type = i_BLACK_NODE;
                        brother->type = i_RED_NODE;
                        i_rotate_left(brother, parent, root);
                        brother = parent->lnode;
                        cassert_no_null(brother);
                    }

                    /*! <Case 4: Left child of brother is RED> */
                    cassert(brother->type == i_BLACK_NODE);
                    cassert_no_null(brother->lnode);
                    cassert(brother->lnode->type == i_RED_NODE);
                    brother->type = parent->type;
                    brother->lnode->type = i_BLACK_NODE;
                    parent->type = i_BLACK_NODE;
                    grand = (i > 2) ? it->path[i - 3] : NULL;
                    i_rotate_right(parent, grand, root);
                    i = 1;
                }
            }
        }
        /*! <Red node> */
        else
        {
            break;
        }
    }

    cassert(i > 0);
    it->path[i - 1]->type = i_BLACK_NODE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_delete_element(
    i_Node **root,
    const uint32_t elems,
    const void *key,
    const bool_t isptr,
    FPtr_compare func_compare,
    i_Iterator *it,
    const uint16_t esize,
    const uint16_t ksize,
    FPtr_remove func_remove,
    FPtr_destroy func_destroy,
    FPtr_destroy func_destroy_key)
{
    cassert_no_null(root);

    if (__TRUE_EXPECTED(*root != NULL))
    {
        register int result = i_node_by_key(*root, key, isptr, func_compare, it);
        if (__TRUE_EXPECTED(result == 0))
        {
            i_Node *deleted_node = NULL;
            i_Node *mark_for_delete = NULL;
            cassert(it->path_size > 0);
            cassert(it->path_size <= it->path_alloc);
            mark_for_delete = it->path[it->path_size - 1];
            cassert_no_null(mark_for_delete);
            i_destroy_node_data(mark_for_delete, __DEBUG_PARAMC(esize) ksize, func_remove, func_destroy, func_destroy_key);

            if (mark_for_delete->lnode != NULL && mark_for_delete->rnode != NULL)
            {
                i_inorder_next(it);
                cassert(it->path_size > 0);
                cassert(it->path_size <= it->path_alloc);
                deleted_node = it->path[it->path_size - 1];
                cassert_no_null(deleted_node);
                cassert(bmem_overlaps(i_NODE_DATA(mark_for_delete), i_NODE_DATA(deleted_node), esize + ksize, esize + ksize) == FALSE);
                bmem_copy(i_NODE_DATA(mark_for_delete), i_NODE_DATA(deleted_node), esize + ksize);
            }
            else
            {
                deleted_node = mark_for_delete;
            }

            /*! <Deleted_node isn't the root> */
            if (__TRUE_EXPECTED(it->path_size > 1))
            {
                register i_Node *parent;
                register i_Node *child;

                parent = it->path[it->path_size - 2];
                cassert_no_null(parent);

                if (deleted_node->lnode != NULL)
                {
                    cassert(deleted_node->rnode == NULL);
                    child = deleted_node->lnode;
                }
                else
                {
                    child = deleted_node->rnode;
                }

                if (parent->lnode == deleted_node)
                {
                    parent->lnode = child;
                }
                else
                {
                    cassert(parent->rnode == deleted_node);
                    parent->rnode = child;
                }

                it->path[it->path_size - 1] = child;
            }
            /*! <Deleted_node is the root> */
            else
            {
                cassert(it->path_size == 1);

                if (deleted_node->lnode != NULL)
                {
                    cassert(deleted_node->rnode == NULL);
                    *root = deleted_node->lnode;
                    it->path[0] = deleted_node->lnode;
                }
                else if (deleted_node->rnode != NULL)
                {
                    *root = deleted_node->rnode;
                    it->path[0] = deleted_node->rnode;
                }
                else
                {
                    *root = NULL;
                    it->path_size = 0;
                }
            }

            cassert(elems > 0);
            i_update_iterator_size(elems - 1, it);

            if (__TRUE_EXPECTED(it->path_size > 0))
            {
                if (deleted_node->type == i_BLACK_NODE)
                {
                    i_restructure_after_delete(it, root);
                }
#if defined(__ASSERTS__)
                else
                {
                    cassert(it->path[it->path_size - 1] == NULL || it->path[it->path_size - 1]->type == i_BLACK_NODE);
                    if (it->path_size > 1)
                        cassert(it->path[it->path_size - 2]->type == i_BLACK_NODE);
                }
#endif
            }
            else
            {
                cassert(*root == NULL);
            }

            i_dealloc_node(&deleted_node, esize, ksize);
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t rbtree_delete(RBTree *tree, const void *key, FPtr_remove func_remove, FPtr_destroy func_destroy_key)
{
    cassert_no_null(tree);
    if (i_delete_element(&tree->root, tree->elems, key, (bool_t)(func_destroy_key != NULL), tree->func_compare, &tree->it, tree->esize, tree->ksize, func_remove, NULL, func_destroy_key) == TRUE)
    {
        cassert(tree->elems > 0);
        tree->it.path_size = 0;
        tree->elems -= 1;
        return TRUE;
    }
    else
    {
        tree->it.path_size = 0;
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t rbtree_delete_ptr(RBTree *tree, const void *key, FPtr_destroy func_destroy, FPtr_destroy func_destroy_key)
{
    cassert_no_null(tree);
    if (i_delete_element(&tree->root, tree->elems, key, TRUE, tree->func_compare, &tree->it, tree->esize, tree->ksize, NULL, func_destroy, func_destroy_key) == TRUE)
    {
        cassert(tree->elems > 0);
        tree->it.path_size = 0;
        tree->elems -= 1;
        return TRUE;
    }
    else
    {
        tree->it.path_size = 0;
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_first(RBTree *tree)
{
    cassert_no_null(tree);
    if (i_first(tree->root, &tree->it) == TRUE)
        return i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize;
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_last(RBTree *tree)
{
    cassert_no_null(tree);
    if (i_last(tree->root, &tree->it) == TRUE)
        return i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize;
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_next(RBTree *tree)
{
    cassert_no_null(tree);
    if (i_inorder_next(&tree->it) == TRUE)
        return i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize;
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_prev(RBTree *tree)
{
    cassert_no_null(tree);
    if (i_inorder_prev(&tree->it) == TRUE)
        return i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize;
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_first_ptr(RBTree *tree)
{
    cassert_no_null(tree);
    if (i_first(tree->root, &tree->it) == TRUE)
        return *(byte_t **)(i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize);
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_last_ptr(RBTree *tree)
{
    cassert_no_null(tree);
    if (i_last(tree->root, &tree->it) == TRUE)
        return *(byte_t **)(i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize);
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_next_ptr(RBTree *tree)
{
    cassert_no_null(tree);
    if (i_inorder_next(&tree->it) == TRUE)
        return *(byte_t **)(i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize);
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

byte_t *rbtree_prev_ptr(RBTree *tree)
{
    cassert_no_null(tree);
    if (i_inorder_prev(&tree->it) == TRUE)
        return *(byte_t **)(i_NODE_DATA(tree->it.path[tree->it.path_size - 1]) + tree->ksize);
    else
        return NULL;
}

/*---------------------------------------------------------------------------*/

#define i_tochar(str) ((const char_t *)(str) + sizeof(uint32_t))
const char_t *rbtree_get_key(const RBTree *tree)
{
    cassert_no_null(tree);
    if (tree->it.path_size > 0)
    {
        const String *str = *(String **)i_NODE_DATA(tree->it.path[tree->it.path_size - 1]);
        return i_tochar(str);
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

static void i_check_in_depth(
    const i_Node *node,
    uint32_t path_accum,
    uint32_t black_path_accum,
    uint32_t *black_depth,
    uint32_t *min_depth,
    uint32_t *max_depth)
{
    cassert_no_null(node);
    cassert_no_null(black_depth);
    cassert_no_null(min_depth);
    cassert_no_null(max_depth);

    path_accum += 1;

    if (node->type == i_BLACK_NODE)
        black_path_accum += 1;

    if (node->lnode == NULL && node->rnode == NULL)
    {
        if (path_accum < *min_depth)
            *min_depth = path_accum;

        if (path_accum > *max_depth)
            *max_depth = path_accum;

        if (*black_depth == UINT32_MAX)
            *black_depth = black_path_accum;
        else
            cassert(black_path_accum == *black_depth);
    }
    else
    {
        if (node->lnode != NULL)
        {
            if (node->type == i_RED_NODE)
                cassert(node->lnode->type == i_BLACK_NODE);

            i_check_in_depth(node->lnode, path_accum, black_path_accum, black_depth, min_depth, max_depth);
        }

        if (node->rnode != NULL)
        {
            if (node->type == i_RED_NODE)
                cassert(node->rnode->type == i_BLACK_NODE);

            i_check_in_depth(node->rnode, path_accum, black_path_accum, black_depth, min_depth, max_depth);
        }
    }
}

/*---------------------------------------------------------------------------*/

bool_t rbtree_check(const RBTree *tree)
{
    uint32_t black_depth = UINT32_MAX;
    uint32_t min_depth = UINT32_MAX;
    uint32_t max_depth = 0;

    cassert_no_null(tree);

    if (tree->root == NULL)
        return TRUE;

    cassert(tree->root->type == i_BLACK_NODE);
    i_check_in_depth(tree->root, 0, 0, &black_depth, &min_depth, &max_depth);

    {
        uint32_t max_theoric_depth = i_log2(tree->elems + 1);
        max_theoric_depth <<= 1;
        cassert_unref(max_depth < max_theoric_depth, max_theoric_depth);
        cassert(max_depth >> 1 <= min_depth);
    }

    return TRUE;
}
