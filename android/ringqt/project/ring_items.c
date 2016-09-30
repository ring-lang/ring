/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"

Items * ring_items_new ( void )
{
	Items *pItems  ;
	pItems = (Items *) malloc(sizeof(Items)) ;
	if ( pItems == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	pItems->pValue = ring_item_new(ITEMTYPE_NOTHING) ;
	pItems->pNext = NULL ;
	pItems->pPrev = NULL ;
	return pItems ;
}

Items * ring_items_delete ( Items *pItems )
{
	assert(pItems != NULL);
	pItems->pValue = ring_item_delete(pItems->pValue);
	free( pItems ) ;
	pItems = NULL ;
	return pItems ;
}

void ring_items_print ( Items *pItems )
{
	assert(pItems != NULL);
	ring_item_print(pItems->pValue);
}
