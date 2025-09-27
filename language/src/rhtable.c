/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API HashTable *ring_hashtable_new_gc(void *pRingState) {
	HashTable *pHashTable;
	pHashTable = (HashTable *)ring_state_malloc(pRingState, sizeof(HashTable));
	pHashTable->nItems = 0;
	pHashTable->nLinkedLists = RING_HASHTABLE_LINKEDLISTS;
	pHashTable->nRebuildSize = RING_HASHTABLE_REBUILDSIZE;
	pHashTable->pArray = (HashItem **)ring_state_calloc(pRingState, pHashTable->nLinkedLists, sizeof(HashItem *));
	return pHashTable;
}

RING_API unsigned int ring_hashtable_hashkey_gc(void *pRingState, HashTable *pHashTable, const char *cKey) {
	unsigned int nIndex;
#if RING_SIMPLEHASHFUNC
	nIndex = ring_hashlib_xorhash((unsigned char *)cKey, strlen(cKey));
#else
	nIndex = ring_hashlib_murmurthree32((const char *)cKey, strlen(cKey), RING_HASHTABLE_HASHFUNCSEED);
#endif
	/* nLinkedLists is always a power of two (starts at 2 and doubles). Use bit mask instead of modulo for speed. */
	nIndex = nIndex & (pHashTable->nLinkedLists - 1);
	return nIndex;
}

RING_API HashItem *ring_hashtable_newitem_gc(void *pRingState, HashTable *pHashTable, const char *cKey) {
	unsigned int nIndex;
	HashItem *pItem;
	/* Check for overflow before adding new item */
	if (pHashTable->nItems == UINT_MAX) {
		printf(RING_HASHTABLESIZEOVERFLOW);
		exit(RING_EXIT_FAIL);
	}
	nIndex = ring_hashtable_hashkey_gc(pRingState, pHashTable, cKey);
	if (pHashTable->pArray[nIndex] == NULL) {
		pHashTable->pArray[nIndex] = (HashItem *)ring_state_malloc(pRingState, sizeof(HashItem));
		pItem = pHashTable->pArray[nIndex];
	} else {
		pItem = pHashTable->pArray[nIndex];
		/* Find Position of the HashItem */
		while (pItem->pNext != NULL) {
			pItem = pItem->pNext;
		}
		pItem->pNext = (HashItem *)ring_state_malloc(pRingState, sizeof(HashItem));
		pItem = pItem->pNext;
	}
	/* Store Copy from The Key */
	pItem->cKey = ring_string_strdup_gc(pRingState, cKey);
	/* Item type will be determined from the caller */
	pItem->nItemType = RING_HASHITEMTYPE_NOTYPE;
	pItem->pNext = NULL;
	/* Increase Items Count */
	pHashTable->nItems++;
	return pItem;
}

RING_API void ring_hashtable_newnumber_gc(void *pRingState, HashTable *pHashTable, const char *cKey,
					  unsigned int nNumber) {
	HashItem *pItem;
	pItem = ring_hashtable_newitem_gc(pRingState, pHashTable, cKey);
	pItem->nItemType = RING_HASHITEMTYPE_NUMBER;
	pItem->HashValue.nIndex = nNumber;
	/* Check Rebuilding the HashTable */
	ring_hashtable_rebuild_gc(pRingState, pHashTable);
}

RING_API void ring_hashtable_newpointer_gc(void *pRingState, HashTable *pHashTable, const char *cKey, void *pPointer) {
	HashItem *pItem;
	pItem = ring_hashtable_newitem_gc(pRingState, pHashTable, cKey);
	pItem->nItemType = RING_HASHITEMTYPE_POINTER;
	pItem->HashValue.pValue = pPointer;
	/* Check Rebuilding the HashTable */
	ring_hashtable_rebuild_gc(pRingState, pHashTable);
}

RING_API HashItem *ring_hashtable_finditem_gc(void *pRingState, HashTable *pHashTable, const char *cKey) {
	int nIndex;
	HashItem *pItem;
	nIndex = ring_hashtable_hashkey_gc(pRingState, pHashTable, cKey);
	pItem = pHashTable->pArray[nIndex];
	while (pItem != NULL) {
		/* Check Key */
		if (strcmp(pItem->cKey, cKey) == 0) {
			return pItem;
		}
		pItem = pItem->pNext;
	}
	return NULL;
}

RING_API unsigned int ring_hashtable_findnumber_gc(void *pRingState, HashTable *pHashTable, const char *cKey) {
	HashItem *pItem;
	pItem = ring_hashtable_finditem_gc(pRingState, pHashTable, cKey);
	if (pItem != NULL) {
		return pItem->HashValue.nIndex;
	}
	return RING_FALSE;
}

RING_API void *ring_hashtable_findpointer_gc(void *pRingState, HashTable *pHashTable, const char *cKey) {
	HashItem *pItem;
	pItem = ring_hashtable_finditem_gc(pRingState, pHashTable, cKey);
	if (pItem != NULL) {
		return pItem->HashValue.pValue;
	}
	return NULL;
}

RING_API void ring_hashtable_deleteitem_gc(void *pRingState, HashTable *pHashTable, const char *cKey) {
	unsigned int nIndex;
	HashItem *pItem, *pPrevItem;
	nIndex = ring_hashtable_hashkey_gc(pRingState, pHashTable, cKey);
	pItem = pHashTable->pArray[nIndex];
	pPrevItem = NULL;
	while (pItem != NULL) {
		/* Check Key */
		if (strcmp(pItem->cKey, cKey) == 0) {
			if (pPrevItem == NULL) {
				pHashTable->pArray[nIndex] = pItem->pNext;
			} else {
				pPrevItem->pNext = pItem->pNext;
			}
			ring_state_free(pRingState, pItem->cKey);
			ring_state_free(pRingState, pItem);
			pHashTable->nItems--;
			return;
		}
		pPrevItem = pItem;
		pItem = pItem->pNext;
	}
}

RING_API HashTable *ring_hashtable_delete_gc(void *pRingState, HashTable *pHashTable) {
	unsigned int x;
	HashItem *pItem, *pItem2;
	if (pHashTable == NULL) {
		return NULL;
	}
	for (x = 0; x < pHashTable->nLinkedLists; x++) {
		pItem = pHashTable->pArray[x];
		while (pItem != NULL) {
			pItem2 = pItem->pNext;
			ring_state_free(pRingState, pItem->cKey);
			ring_state_free(pRingState, pItem);
			pItem = pItem2;
		}
	}
	ring_state_free(pRingState, pHashTable->pArray);
	ring_state_free(pRingState, pHashTable);
	return NULL;
}

RING_API void ring_hashtable_rebuild_gc(void *pRingState, HashTable *pHashTable) {
	HashItem **pOldArray;
	unsigned int nOldLinkedLists, x, nNewIndex;
	HashItem *pItem, *pNextItem, *pItemIterator;
	/* If the number of items doesn't meet the rebuild threshoud, do nothing */
	if (pHashTable->nItems != pHashTable->nRebuildSize) {
		return;
	}
	/* Store old table properties */
	pOldArray = pHashTable->pArray;
	nOldLinkedLists = pHashTable->nLinkedLists;
	/* Create the new, larger table structure */
	pHashTable->nRebuildSize *= 2;
	pHashTable->nLinkedLists *= 2;
	pHashTable->pArray = (HashItem **)ring_state_calloc(pRingState, pHashTable->nLinkedLists, sizeof(HashItem *));
	/* Re-hash and move all items from the old table to the new one */
	for (x = 0; x < nOldLinkedLists; x++) {
		pItem = pOldArray[x];
		while (pItem != NULL) {
			pNextItem = pItem->pNext;
			pItem->pNext = NULL;
			nNewIndex = ring_hashtable_hashkey_gc(pRingState, pHashTable, pItem->cKey);
			pItemIterator = pHashTable->pArray[nNewIndex];
			if (pItemIterator == NULL) {
				pHashTable->pArray[nNewIndex] = pItem;
			} else {
				while (pItemIterator->pNext != NULL) {
					pItemIterator = pItemIterator->pNext;
				}
				pItemIterator->pNext = pItem;
			}
			pItem = pNextItem;
		}
	}
	ring_state_free(pRingState, pOldArray);
}

RING_API void ring_hashtable_print_gc(void *pRingState, HashTable *pHashTable) {
	unsigned int x;
	HashItem *pItem;
	for (x = 0; x < pHashTable->nLinkedLists; x++) {
		pItem = pHashTable->pArray[x];
		while (pItem != NULL) {
			/* Print Item Data */
			printf("\n LinkedList (%d) : Key (%s) \n", x, pItem->cKey);
			pItem = pItem->pNext;
		}
	}
}

RING_API HashTable *ring_hashtable_new(void) { return ring_hashtable_new_gc(NULL); }

RING_API unsigned int ring_hashtable_hashkey(HashTable *pHashTable, const char *cKey) {
	return ring_hashtable_hashkey_gc(NULL, pHashTable, cKey);
}

RING_API HashItem *ring_hashtable_newitem(HashTable *pHashTable, const char *cKey) {
	return ring_hashtable_newitem_gc(NULL, pHashTable, cKey);
}

RING_API void ring_hashtable_newnumber(HashTable *pHashTable, const char *cKey, unsigned int nNumber) {
	ring_hashtable_newnumber_gc(NULL, pHashTable, cKey, nNumber);
}

RING_API void ring_hashtable_newpointer(HashTable *pHashTable, const char *cKey, void *pPointer) {
	ring_hashtable_newpointer_gc(NULL, pHashTable, cKey, pPointer);
}

RING_API HashItem *ring_hashtable_finditem(HashTable *pHashTable, const char *cKey) {
	return ring_hashtable_finditem_gc(NULL, pHashTable, cKey);
}

RING_API unsigned int ring_hashtable_findnumber(HashTable *pHashTable, const char *cKey) {
	return ring_hashtable_findnumber_gc(NULL, pHashTable, cKey);
}

RING_API void *ring_hashtable_findpointer(HashTable *pHashTable, const char *cKey) {
	return ring_hashtable_findpointer_gc(NULL, pHashTable, cKey);
}

RING_API void ring_hashtable_deleteitem(HashTable *pHashTable, const char *cKey) {
	ring_hashtable_deleteitem_gc(NULL, pHashTable, cKey);
}

RING_API HashTable *ring_hashtable_delete(HashTable *pHashTable) { return ring_hashtable_delete_gc(NULL, pHashTable); }

RING_API void ring_hashtable_rebuild(HashTable *pHashTable) { ring_hashtable_rebuild_gc(NULL, pHashTable); }

RING_API void ring_hashtable_print(HashTable *pHashTable) { ring_hashtable_print_gc(NULL, pHashTable); }
