/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"

Items * ring_items_new_gc ( void *pState )
{
    Items *pItems  ;
    pItems = (Items *) ring_state_malloc(pState,sizeof(Items));
    pItems->pValue = ring_item_new_gc(pState,ITEMTYPE_NOTHING) ;
    pItems->pNext = NULL ;
    pItems->pPrev = NULL ;
    return pItems ;
}

Items * ring_items_delete_gc ( void *pState,Items *pItems )
{
    assert(pItems != NULL);
    pItems->pValue = ring_item_delete_gc(pState,pItems->pValue);
    ring_state_free(pState,pItems);
    pItems = NULL ;
    return pItems ;
}

void ring_items_print ( Items *pItems )
{
    assert(pItems != NULL);
    ring_item_print(pItems->pValue);
}
/* Functions without State pointer */

Items * ring_items_new ( void )
{
    return ring_items_new_gc(NULL) ;
}

Items * ring_items_delete ( Items *pItems )
{
    return ring_items_delete_gc(NULL,pItems) ;
}
