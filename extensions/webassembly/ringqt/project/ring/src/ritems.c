/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

Items * ring_items_new_gc ( void *pState )
{
	Items *pItems  ;
	char *pMem  ;
	Item *pItem  ;
	pMem = (char *) ring_state_malloc(pState,sizeof(Item)+sizeof(Items));
	pItem = (Item *) pMem ;
	/* Clear Item */
	pItem->nType = ITEMTYPE_NOTHING ;
	pItem->nObjectType = 0 ;
	pItem->data.dNumber = 0 ;
	pItem->nNumberFlag = ITEM_NUMBERFLAG_NOTHING ;
	ring_vm_gc_cleardata(pItem);
	ring_vm_gc_newitemreference(pItem);
	pMem = pMem + sizeof(Item) ;
	pItems = (Items *) pMem ;
	pItems->pValue = pItem ;
	pItems->pNext = NULL ;
	pItems->pPrev = NULL ;
	pItems->lDelete = 1 ;
	return pItems ;
}

Items * ring_items_delete_gc ( void *pState,Items *pItems )
{
	char *pMem  ;
	Item *pItem  ;
	if ( ! pItems->lDelete ) {
		ring_item_delete_gc(pState,pItems->pValue);
		return NULL ;
	}
	pItems->pValue = ring_item_delete_gc(pState,pItems->pValue);
	pMem = (char *) pItems ;
	pMem = pMem - sizeof(Item) ;
	pItem = (Item *) pMem ;
	pItem = ring_item_delete_gc(pState,pItem);
	return NULL ;
}

void ring_items_print ( Items *pItems )
{
	ring_item_print(pItems->pValue);
}

Items * ring_items_new ( void )
{
	return ring_items_new_gc(NULL) ;
}

Items * ring_items_delete ( Items *pItems )
{
	return ring_items_delete_gc(NULL,pItems) ;
}
