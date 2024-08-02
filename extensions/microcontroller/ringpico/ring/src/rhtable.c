/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

HashTable * ring_hashtable_new_gc ( void *pRingState )
{
	HashTable *pHashTable  ;
	pHashTable = (HashTable *) ring_state_malloc(pRingState,sizeof(HashTable));
	pHashTable->nItems = 0 ;
	pHashTable->nLinkedLists = RING_HASHTABLE_LINKEDLISTS ;
	pHashTable->nRebuildSize = RING_HASHTABLE_REBUILDSIZE ;
	pHashTable->pArray = (HashItem **) ring_state_calloc(pRingState,pHashTable->nLinkedLists,sizeof(HashItem *));
	return pHashTable ;
}

unsigned int ring_hashtable_hashkey ( HashTable *pHashTable,const char *cKey )
{
	unsigned int nIndex  ;
	#if RING_SIMPLEHASHFUNC
		nIndex = ring_xor_hash((unsigned char *) cKey,strlen(cKey));
	#else
		nIndex = ring_murmur3_32((const char *) cKey,strlen(cKey),RING_HASHTABLE_HASHFUNCSEED);
	#endif
	nIndex = nIndex % pHashTable->nLinkedLists ;
	return nIndex ;
}

HashItem * ring_hashtable_newitem_gc ( void *pRingState,HashTable *pHashTable,const char *cKey )
{
	unsigned int nIndex  ;
	HashItem *pItem  ;
	nIndex = ring_hashtable_hashkey(pHashTable,cKey);
	if ( pHashTable->pArray[nIndex]   == NULL ) {
		pHashTable->pArray[nIndex] = (HashItem *) ring_state_malloc(pRingState,sizeof(HashItem));
		pItem = pHashTable->pArray[nIndex] ;
	}
	else {
		pItem = pHashTable->pArray[nIndex] ;
		/* Find Position of the HashItem */
		while ( pItem->pNext != NULL ) {
			pItem = pItem->pNext ;
		}
		pItem->pNext = (HashItem *) ring_state_malloc(pRingState,sizeof(HashItem));
		pItem = pItem->pNext ;
	}
	/* Store Copy from The Key */
	pItem->cKey = ring_string_strdup(pRingState,cKey) ;
	/* Item type will be determined from the caller */
	pItem->nItemType = RING_HASHITEMTYPE_NOTYPE ;
	pItem->pNext = NULL ;
	/* Increase Items Count */
	pHashTable->nItems++ ;
	return pItem ;
}

void ring_hashtable_newnumber_gc ( void *pRingState,HashTable *pHashTable,const char *cKey,int nNumber )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_newitem_gc(pRingState,pHashTable,cKey);
	pItem->nItemType = RING_HASHITEMTYPE_NUMBER ;
	pItem->HashValue.nIndex = nNumber ;
	/* Check Rebuilding the HashTable */
	ring_hashtable_rebuild_gc(pRingState,pHashTable);
}

void ring_hashtable_newpointer_gc ( void *pRingState,HashTable *pHashTable,const char *cKey,void *pPointer )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_newitem_gc(pRingState,pHashTable,cKey);
	pItem->nItemType = RING_HASHITEMTYPE_POINTER ;
	pItem->HashValue.pValue = pPointer ;
	/* Check Rebuilding the HashTable */
	ring_hashtable_rebuild_gc(pRingState,pHashTable);
}

HashItem * ring_hashtable_finditem ( HashTable *pHashTable,const char *cKey )
{
	int nIndex  ;
	HashItem *pItem  ;
	nIndex = ring_hashtable_hashkey(pHashTable,cKey);
	pItem = pHashTable->pArray[nIndex] ;
	while ( pItem != NULL ) {
		/* Check Key */
		if ( strcmp(pItem->cKey,cKey) == 0 ) {
			return pItem ;
		}
		pItem = pItem->pNext ;
	}
	return NULL ;
}

int ring_hashtable_findnumber ( HashTable *pHashTable,const char *cKey )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_finditem(pHashTable,cKey);
	if ( pItem != NULL ) {
		return pItem->HashValue.nIndex ;
	}
	return 0 ;
}

void * ring_hashtable_findpointer ( HashTable *pHashTable,const char *cKey )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_finditem(pHashTable,cKey);
	if ( pItem != NULL ) {
		return pItem->HashValue.pValue ;
	}
	return NULL ;
}

void ring_hashtable_deleteitem_gc ( void *pRingState,HashTable *pHashTable,const char *cKey )
{
	int nIndex  ;
	HashItem *pItem, *pPrevItem  ;
	nIndex = ring_hashtable_hashkey(pHashTable,cKey);
	pItem = pHashTable->pArray[nIndex] ;
	pPrevItem = NULL ;
	while ( pItem != NULL ) {
		/* Check Key */
		if ( strcmp(pItem->cKey,cKey) == 0 ) {
			if ( pPrevItem == NULL ) {
				pHashTable->pArray[nIndex] = pItem->pNext ;
			}
			else {
				pPrevItem->pNext = pItem->pNext ;
			}
			ring_state_free(pRingState,pItem->cKey);
			ring_state_free(pRingState,pItem);
			pHashTable->nItems-- ;
			return ;
		}
		pPrevItem = pItem ;
		pItem = pItem->pNext ;
	}
}

HashTable * ring_hashtable_delete_gc ( void *pRingState,HashTable *pHashTable )
{
	int x  ;
	HashItem *pItem,*pItem2  ;
	if ( pHashTable == NULL ) {
		return NULL ;
	}
	for ( x = 0 ; x < pHashTable->nLinkedLists ; x++ ) {
		pItem = pHashTable->pArray[x] ;
		while ( pItem != NULL ) {
			pItem2 = pItem->pNext ;
			ring_state_free(pRingState,pItem->cKey);
			ring_state_free(pRingState,pItem);
			pItem = pItem2 ;
		}
	}
	ring_state_free(pRingState,pHashTable->pArray);
	ring_state_free(pRingState,pHashTable);
	return NULL ;
}

void ring_hashtable_rebuild_gc ( void *pRingState,HashTable *pHashTable )
{
	HashItem **pArray  ;
	int nLinkedLists,x  ;
	HashItem *pItem,*pItem2  ;
	if ( pHashTable->nItems != pHashTable->nRebuildSize ) {
		return ;
	}
	pArray = pHashTable->pArray ;
	nLinkedLists = pHashTable->nLinkedLists ;
	pHashTable->nRebuildSize *= 2 ;
	pHashTable->nLinkedLists *= 2 ;
	pHashTable->pArray = (HashItem **) ring_state_calloc(pRingState,pHashTable->nLinkedLists,sizeof(HashItem *));
	for ( x = 0 ; x < nLinkedLists ; x++ ) {
		pItem = pArray[x] ;
		while ( pItem != NULL ) {
			/* Rehash the item */
			if ( pItem->nItemType == RING_HASHITEMTYPE_NUMBER ) {
				ring_hashtable_newnumber(pHashTable,pItem->cKey,pItem->HashValue.nIndex);
			}
			else if ( pItem->nItemType == RING_HASHITEMTYPE_POINTER ) {
				ring_hashtable_newpointer(pHashTable,pItem->cKey,pItem->HashValue.pValue);
			}
			pItem2 = pItem->pNext ;
			ring_state_free(pRingState,pItem->cKey);
			ring_state_free(pRingState,pItem);
			pItem = pItem2 ;
			pHashTable->nItems-- ;
		}
	}
	ring_state_free(pRingState,pArray);
}

void ring_hashtable_print ( HashTable *pHashTable )
{
	int x  ;
	HashItem *pItem  ;
	for ( x = 0 ; x < pHashTable->nLinkedLists ; x++ ) {
		pItem = pHashTable->pArray[x] ;
		while ( pItem != NULL ) {
			/* Print Item Data */
			printf( "\n LinkedList (%d) : Key (%s) \n",x,pItem->cKey ) ;
			pItem = pItem->pNext ;
		}
	}
}

HashTable * ring_hashtable_new ( void )
{
	return ring_hashtable_new_gc(NULL) ;
}

HashItem * ring_hashtable_newitem ( HashTable *pHashTable,const char *cKey )
{
	return ring_hashtable_newitem_gc(NULL,pHashTable,cKey) ;
}

void ring_hashtable_deleteitem ( HashTable *pHashTable,const char *cKey )
{
	ring_hashtable_deleteitem_gc(NULL,pHashTable,cKey);
}

HashTable * ring_hashtable_delete ( HashTable *pHashTable )
{
	return ring_hashtable_delete_gc(NULL,pHashTable) ;
}

void ring_hashtable_rebuild ( HashTable *pHashTable )
{
	ring_hashtable_rebuild_gc(NULL,pHashTable);
}

void ring_hashtable_newnumber ( HashTable *pHashTable,const char *cKey,int nNumber )
{
	ring_hashtable_newnumber_gc(NULL,pHashTable,cKey,nNumber);
}

void ring_hashtable_newpointer ( HashTable *pHashTable,const char *cKey,void *pPointer )
{
	ring_hashtable_newpointer_gc(NULL,pHashTable,cKey,pPointer);
}
