/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_items_h
#define ring_items_h
typedef struct Items {
	struct Item *pValue;
	struct Items *pNext;
	struct Items *pPrev;
	unsigned char lDelete;
} Items;

RING_API Items *ring_items_new_gc(void *pState);

RING_API Items *ring_items_delete_gc(void *pState, Items *pItems);

RING_API void ring_items_print_gc(void *pState, Items *pItems);

RING_API Items *ring_items_new(void);

RING_API Items *ring_items_delete(Items *pItems);

RING_API void ring_items_print(Items *pItems);
#endif
