/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

// Updated & Enhanced by Abdallah Mohamed ( @0xNinjaCyclone )

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
	nIndex = ring_xor_hash((unsigned char *) cKey,strlen(cKey));
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
			/* To avoid duplicating an exist items */
			if ( strcmp(cKey, pItem->cKey) == 0 ) {
				return NULL;
			}
			pItem = pItem->pNext ;
		}
		/* Check the last item */
		if ( strcmp(cKey, pItem->cKey) == 0 ) {
			return NULL;
		}
		pItem->pNext = (HashItem *) ring_state_malloc(pRingState,sizeof(HashItem));
		pItem = pItem->pNext ;
	}
	/* Check if the allocation gets failed */
	if ( !pItem ) {
		return NULL;
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
	ring_hashtable_insertint_gc( pRingState, pHashTable, cKey, nNumber );
}

void ring_hashtable_newpointer_gc ( void *pRingState,HashTable *pHashTable,const char *cKey,void *pPointer )
{
	ring_hashtable_insertptr_gc( pRingState, pHashTable, cKey, pPointer );
}

int ring_hashtable_insertint_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, int nNumber )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_newitem_gc( pRingState, pHashTable, cKey );

	if ( pItem ) {
		pItem->nItemType = RING_HASHITEMTYPE_NUMBER ;
		pItem->HashValue.nIndex = nNumber ;
		/* Check Rebuilding the HashTable */
		ring_hashtable_rebuild_gc( pRingState, pHashTable );
		return 1;
	}

	return 0;
}

int ring_hashtable_insertptr_gc ( void *pRingState, HashTable *pHashTable, const char *cKey,void *pPointer )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_newitem_gc( pRingState, pHashTable, cKey );

	if ( pItem ) {
		pItem->nItemType = RING_HASHITEMTYPE_POINTER ;
		pItem->HashValue.pValue = pPointer ;
		/* Check Rebuilding the HashTable */
		ring_hashtable_rebuild_gc( pRingState, pHashTable );
		return 1;
	}

	return 0;
}

int ring_hashtable_insertdbl_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, double dNumber )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_newitem_gc( pRingState, pHashTable, cKey );

	if ( pItem ) {
		pItem->nItemType = RING_HASHITEMTYPE_DOUBLE ;
		pItem->HashValue.dValue = dNumber ;
		/* Check Rebuilding the HashTable */
		ring_hashtable_rebuild_gc( pRingState, pHashTable );
		return 1;
	}

	return 0;
}

int ring_hashtable_insertstr_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, char *cpStr ) 
{
	HashItem *pItem  ;
	pItem = ring_hashtable_newitem_gc( pRingState, pHashTable, cKey );

	if ( pItem ) {
		pItem->nItemType = RING_HASHITEMTYPE_STRING ;
		pItem->HashValue.cpStr = cpStr ;
		/* Check Rebuilding the HashTable */
		ring_hashtable_rebuild_gc( pRingState, pHashTable );
		return 1;
	}

	return 0;
}

int ring_hashtable_insertlst_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, List *pList ) 
{
	HashItem *pItem  ;
	pItem = ring_hashtable_newitem_gc( pRingState, pHashTable, cKey );

	if ( pItem ) {
		pItem->nItemType = RING_HASHITEMTYPE_LIST ;
		pItem->HashValue.pList = pList ;
		/* Check Rebuilding the HashTable */
		ring_hashtable_rebuild_gc( pRingState, pHashTable );
		return 1;
	}

	return 0;
}

int ring_hashtable_insertfnp_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, void (*fpFunc)(void *) )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_newitem_gc( pRingState, pHashTable, cKey );

	if ( pItem ) {
		pItem->nItemType = RING_HASHITEMTYPE_FUNCTIONPOINTER ;
		pItem->HashValue.fpFunc = fpFunc ;
		/* Check Rebuilding the HashTable */
		ring_hashtable_rebuild_gc( pRingState, pHashTable );
		return 1;
	}

	return 0;
}

int ring_hashtable_updateint ( HashTable *pHashTable, const char *cKey, int nNumber )
{
	HashItem *pItem;
	pItem = ring_hashtable_finditem( pHashTable, cKey );

	if ( pItem ) {
		pItem->HashValue.nIndex = nNumber;
		pItem->nItemType = RING_HASHITEMTYPE_INTEGER;
		return 1;
	}

	return 0;
}

int ring_hashtable_updateptr ( HashTable *pHashTable, const char *cKey, void *pPointer )
{
	HashItem *pItem;
	pItem = ring_hashtable_finditem( pHashTable, cKey );

	if ( pItem ) {
		pItem->HashValue.pValue = pPointer;
		pItem->nItemType = RING_HASHITEMTYPE_POINTER;
		return 1;
	}

	return 0;
}

int ring_hashtable_updatedbl ( HashTable *pHashTable, const char *cKey, double dNumber )
{
	HashItem *pItem;
	pItem = ring_hashtable_finditem( pHashTable, cKey );

	if ( pItem ) {
		pItem->HashValue.dValue = dNumber;
		pItem->nItemType = RING_HASHITEMTYPE_DOUBLE;
		return 1;
	}

	return 0;
}

int ring_hashtable_updatestr ( HashTable *pHashTable, const char *cKey, char *cpStr )
{
	HashItem *pItem;
	pItem = ring_hashtable_finditem( pHashTable, cKey );

	if ( pItem ) {
		pItem->HashValue.cpStr = cpStr;
		pItem->nItemType = RING_HASHITEMTYPE_STRING;
		return 1;
	}

	return 0;
}

int ring_hashtable_updatelst ( HashTable *pHashTable, const char *cKey, List *pList )
{
	HashItem *pItem;
	pItem = ring_hashtable_finditem( pHashTable, cKey );

	if ( pItem ) {
		pItem->HashValue.pList = pList;
		pItem->nItemType = RING_HASHITEMTYPE_LIST;
		return 1;
	}

	return 0;
}

int ring_hashtable_updatefnp ( HashTable *pHashTable, const char *cKey, void (*fpFunc)(void *) )
{
	HashItem *pItem;
	pItem = ring_hashtable_finditem( pHashTable, cKey );

	if ( pItem ) {
		pItem->HashValue.fpFunc = fpFunc;
		pItem->nItemType = RING_HASHITEMTYPE_LIST;
		return 1;
	}

	return 0;
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

double ring_hashtable_finddouble ( HashTable *pHashTable,const char *cKey )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_finditem(pHashTable,cKey);
	if ( pItem != NULL ) {
		return pItem->HashValue.dValue ;
	}
	return 0 ;
}

char *ring_hashtable_findstring ( HashTable *pHashTable,const char *cKey )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_finditem(pHashTable,cKey);
	if ( pItem != NULL ) {
		return pItem->HashValue.cpStr ;
	}
	return NULL ;
}

List *ring_hashtable_findlist ( HashTable *pHashTable,const char *cKey )
{
	HashItem *pItem  ;
	pItem = ring_hashtable_finditem(pHashTable,cKey);
	if ( pItem != NULL ) {
		return pItem->HashValue.pList ;
	}
	return NULL ;
}

void (*ring_hashtable_findfunctionpointer( HashTable *pHashTable,const char *cKey ))(void *) 
{
	HashItem *pItem  ;
	pItem = ring_hashtable_finditem(pHashTable,cKey);
	if ( pItem != NULL ) {
		return pItem->HashValue.fpFunc ;
	}
	return NULL ;
}

void ring_hashtable_deleteitem_gc ( void *pRingState,HashTable *pHashTable,const char *cKey )
{
	ring_hashtable_deleteitem2_gc( pRingState, pHashTable, cKey );
}

int ring_hashtable_deleteitem2_gc ( void *pRingState, HashTable *pHashTable, const char *cKey ) 
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
			// Decrease the counter
			pHashTable->nItems--;
			return 1;
		}
		pPrevItem = pItem ;
		pItem = pItem->pNext ;
	}

	return 0;
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
	pHashTable->nRebuildSize *= 10 ;
	if ( pHashTable->nLinkedLists < 10 ) {
		pHashTable->nLinkedLists = 10 ;
	}
	pHashTable->nLinkedLists *= 10 ;
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
			else if ( pItem->nItemType == RING_HASHITEMTYPE_DOUBLE ) {
				ring_hashtable_insertdbl( pHashTable, pItem->cKey, pItem->HashValue.dValue );
			}
			else if ( pItem->nItemType == RING_HASHITEMTYPE_STRING ) {
				ring_hashtable_insertstr( pHashTable, pItem->cKey, pItem->HashValue.cpStr );
			}
			else if ( pItem->nItemType == RING_HASHITEMTYPE_LIST ) {
				ring_hashtable_insertlst( pHashTable, pItem->cKey, pItem->HashValue.pList );
			}
			else if ( pItem->nItemType == RING_HASHITEMTYPE_FUNCTIONPOINTER ) {
				ring_hashtable_insertfnp( pHashTable, pItem->cKey, pItem->HashValue.fpFunc );
			}
			pItem2 = pItem->pNext ;
			ring_state_free(pRingState,pItem->cKey);
			ring_state_free(pRingState,pItem);
			pItem = pItem2 ;
		}
	}
	ring_state_free(pRingState,pArray);
}

int ring_hashtable_first ( HashTable *pHashTable, unsigned int *unpPosition, char **cpKey, HashItem **pItem )
{
	// Set to the first chain 
	( *unpPosition ) = 0;

	( *pItem ) = pHashTable->pArray[ *unpPosition ];

	if ( !(*pItem) ) {
		do {
			if ( ++(*unpPosition) == pHashTable->nLinkedLists )
				return 0; // The table is empty

			( *pItem ) = pHashTable->pArray[ *unpPosition ];
		} while ( !(*pItem) );
	}

	if ( *pItem ) {	
		if ( cpKey )
			( *cpKey ) = ( *pItem )->cKey;
			
		return 1;
	}

	return 0;
}

// This function faciliate traversing the table ( BE CAREFUL WHEN USE IT )
int ring_hashtable_next ( HashTable *pHashTable, unsigned int *unpPosition, char **cpKey, HashItem **pItem )
{
	if ( (*pItem)->pNext )
		( *pItem ) = ( *pItem )->pNext;
	
	else {
		do {
			if ( ++(*unpPosition) == pHashTable->nLinkedLists )
				return 0; // We have reached the end of the chain

			( *pItem ) = pHashTable->pArray[ *unpPosition ];
		} while ( !(*pItem) );
	}

	if ( cpKey )
		( *cpKey ) = ( *pItem )->cKey;

	return 1;
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

void ring_hashtable_print2 ( HashTable *pHashTable )
{
	int x  ;
	HashItem *pItem  ;
	char *cpKey ;

	printf("{ ");

	if ( ring_hashtable_first(pHashTable, &x, &cpKey, &pItem) )
		do {
			printf( "'%s': ", cpKey ) ;
			if ( pItem->nItemType == RING_HASHITEMTYPE_DOUBLE )
				printf( "%ld", (long) pItem->HashValue.dValue );
			else if ( pItem->nItemType == RING_HASHITEMTYPE_STRING )
				printf( "'%s'", (char *)pItem->HashValue.cpStr );
			else if ( pItem->nItemType != RING_HASHITEMTYPE_NOTYPE )
				printf( "%p", pItem->HashValue.pValue );
			else 
				printf( "NOTYPE" );
			printf(", ");
		} while ( ring_hashtable_next(pHashTable, &x, &cpKey, &pItem) );
	
	printf("}\n");
}

int ring_hashtable_haskey ( HashTable *pHashTable, const char *cpKey )
{
	HashItem *pItem;
	int nIdx;

	// Get the entry index by the hash
	nIdx = ring_hashtable_hashkey( pHashTable, cpKey );

	// Points to the first item
	pItem = pHashTable->pArray[ nIdx ];

	// Iterate over all items
	while ( pItem )
	{
		if ( strcmp(cpKey, pItem->cKey) == 0 )
			return 1; // We have found the key

		// Jump on the next item
		pItem = pItem->pNext;
	}

	// There is no item with this key in the table
	return 0;
}

List *ring_hashtable_getkeys_gc ( void *pRingState, HashTable *pHashTable )
{
	HashItem **pItemsTable, *pItem;
	List *pKeys;
	int nEntries;

	// Intialize the keys list
	if ( !(pKeys = ring_list_new_gc( pRingState, 0 )) )
		return NULL;

	// Points to the first item ptr
	pItemsTable = pHashTable->pArray;

	// Number of entries within the table
	nEntries = pHashTable->nLinkedLists;

	// Iterate over the table
	while ( nEntries-- )
	{
		// Get the front item
		pItem = *pItemsTable++;

		// Traverse all the items under current chain
		while ( pItem )
		{
			// Insert the key
			ring_list_addstring_gc( pRingState, pKeys, pItem->cKey );

			// Jump to the next item
			pItem = pItem->pNext;
		}
	}

	return pKeys;
}

HashTable *ring_hashtable_clone_gc ( void *pRingState, HashTable *pHashTable )
{
	HashTable *pNewTable;
	HashItem *pItem, *pItem2, *pPrev, **pArray, **pArray2;
	unsigned int unTableEntries;

	pNewTable = ring_state_malloc( pRingState, sizeof(HashTable) );
	if ( !pNewTable ) {
		goto FINISH; 
	}

	// Copy states
	pNewTable->nItems = pHashTable->nItems;
	pNewTable->nLinkedLists = pHashTable->nLinkedLists;
	pNewTable->nRebuildSize = pHashTable->nRebuildSize;

	// Allocate new table
	pNewTable->pArray = ring_state_calloc( pRingState, pNewTable->nLinkedLists, sizeof(HashItem *) );

	// Failed to allocate a table?
	if ( !pNewTable->pArray ) {
		// Gets rid of the allocated table memory
		ring_state_free( pRingState, pNewTable );
		pNewTable = NULL;
		goto FINISH; // Get the hell out of here
	}

	// Points to the front's ptr of the first chain
	pArray = pHashTable->pArray;
	pArray2 = pNewTable->pArray;

	// Number of chains
	unTableEntries = pHashTable->nLinkedLists;

	// Copy all items one by one
	while ( unTableEntries-- )
	{
		// Get the front of current chain
		pItem = *pArray++;
		pPrev = NULL;

		while ( pItem )
		{
			pItem2 = ring_state_malloc( pRingState, sizeof(HashItem) );
			
			if ( !pItem2 ) {
				// f*cking OOM case.
				// We have to gets rid of the new table and return NULL to the caller
				pArray = pNewTable->pArray;

				// Number of processed chains within the new table
				unTableEntries = pNewTable->nLinkedLists - unTableEntries;

				// Iterate over all active chains
				while ( unTableEntries-- )
				{
					// Get the front 
					pItem = *pArray++;

					// Traverse current chain and free all items
					while ( pItem )
					{
						pItem2 = pItem->pNext;
						ring_state_free( pRingState, pItem->cKey );
						ring_state_free( pRingState, pItem );
						pItem = pItem2;
					}
				}

				ring_state_free( pRingState, pNewTable->pArray );
				ring_state_free( pRingState, pNewTable );
				pNewTable = NULL;
				goto FINISH; // Get the hell out of here
			}

			// Copy the original Item
			( *pItem2 ) = ( *pItem );

			// Duplicate the key
			pItem2->cKey = ring_string_strdup( pRingState, pItem->cKey );

			// The next points to nothing
			pItem2->pNext = NULL;

			if ( pPrev ) {
				pPrev->pNext = pItem2;
				pPrev = pPrev->pNext;
			}

			else {
				( *pArray2 ) = pItem2;
				pPrev = *pArray2;
			}

			pItem = pItem->pNext;
		}

		pArray2++;
	}

FINISH:
	return pNewTable;
}

int ring_hashtable_gettype ( HashTable *pHashTable, const char *cpKey )
{
	HashItem *pItem;
	pItem = ring_hashtable_finditem( pHashTable, cpKey );

	if ( pItem ) {
		return pItem->nItemType;
	}

	return RING_HASHITEMTYPE_NOTYPE;
}

int ring_hashtable_compare ( HashTable *pHashTable, HashTable *pHashTable2 ) 
{
	HashItem *pItem, *pItem2, **pArray;
	unsigned int unEntries;

	if (!(
		pHashTable->nLinkedLists == pHashTable2->nLinkedLists &&
		pHashTable->nRebuildSize == pHashTable2->nRebuildSize &&
		pHashTable->nItems == pHashTable2->nItems
	)) {
		return 0;
	}

	pArray = pHashTable->pArray;
	unEntries = pHashTable->nLinkedLists;

	while ( unEntries-- ) 
	{
		pItem = *pArray++;

		while ( pItem )
		{
			// Search for the item
			pItem2 = ring_hashtable_finditem( pHashTable2, pItem->cKey );

			if ( !pItem2 )
				return 0; // Current item's key doesn't exist

			if ( pItem->nItemType != pItem2->nItemType )
				return 0;

			if ( pItem->nItemType == RING_HASHITEMTYPE_NUMBER ) {
				if ( pItem->HashValue.nIndex != pItem2->HashValue.nIndex )
					return 0;
			}

			else if ( pItem->nItemType == RING_HASHITEMTYPE_POINTER ) {
				if ( pItem->HashValue.pValue != pItem2->HashValue.pValue )
					return 0;
			}

			else if ( pItem->nItemType == RING_HASHITEMTYPE_DOUBLE ) {
				if ( pItem->HashValue.dValue != pItem2->HashValue.dValue )
					return 0;
			}

			else if ( pItem->nItemType == RING_HASHITEMTYPE_STRING ) {
				if ( strcmp(pItem->HashValue.cpStr, pItem2->HashValue.cpStr) != 0 )
					return 0;
			}

			else if ( pItem->nItemType == RING_HASHITEMTYPE_LIST ) {
				// We check if both items have the same object
				if ( pItem->HashValue.pList != pItem2->HashValue.pList )
					return 0;
			}

			else if ( pItem->nItemType == RING_HASHITEMTYPE_FUNCTIONPOINTER ) {
				if ( pItem->HashValue.fpFunc != pItem2->HashValue.fpFunc )
					return 0;
			}

			pItem = pItem->pNext;
		}

	}

	return 1;
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

int ring_hashtable_deleteitem2 ( HashTable *pHashTable, const char *cKey )
{
	return ring_hashtable_deleteitem2_gc( NULL, pHashTable, cKey );
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

int ring_hashtable_insertint ( HashTable *pHashTable, const char *cKey, int nNumber ) 
{
	return ring_hashtable_insertint_gc( NULL, pHashTable, cKey, nNumber );
}

int ring_hashtable_insertptr ( HashTable *pHashTable, const char *cKey,void *pPointer )
{
	return ring_hashtable_insertptr_gc( NULL, pHashTable, cKey, pPointer );
}

int ring_hashtable_insertdbl ( HashTable *pHashTable, const char *cKey, double dNumber )
{
	return ring_hashtable_insertdbl_gc( NULL, pHashTable, cKey, dNumber );
}

int ring_hashtable_insertstr ( HashTable *pHashTable, const char *cKey, char *cpStr )
{
	return ring_hashtable_insertstr_gc( NULL, pHashTable, cKey, cpStr );
}

int ring_hashtable_insertlst ( HashTable *pHashTable, const char *cKey, List *pList )
{
	return ring_hashtable_insertlst_gc( NULL, pHashTable, cKey, pList );
}

int ring_hashtable_insertfnp ( HashTable *pHashTable, const char *cKey, void (*fpFunc)(void *) )
{
	return ring_hashtable_insertfnp_gc( NULL, pHashTable, cKey, fpFunc );
}

List *ring_hashtable_getkeys( HashTable *pHashTable )
{
	return ring_hashtable_getkeys_gc( NULL, pHashTable );
}

HashTable *ring_hashtable_clone ( HashTable *pHashTable )
{
	return ring_hashtable_clone_gc( NULL, pHashTable );
}