/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_hashtable_h
#define ring_hashtable_h
/* Data */
typedef struct HashItem {
	char *cKey;
	union HashValue {
		unsigned int nIndex;
		void *pValue;
	} HashValue;
	struct HashItem *pNext;
	unsigned char nItemType;
} HashItem;
typedef struct HashTable {
	HashItem **pArray;
	unsigned int nItems;
	unsigned int nLinkedLists;
	unsigned int nRebuildSize;
} HashTable;
/* Constants */
#define RING_HASHITEMTYPE_NOTYPE 0
#define RING_HASHITEMTYPE_NUMBER 1
#define RING_HASHITEMTYPE_POINTER 2
#define RING_HASHTABLE_LINKEDLISTS 2
#define RING_HASHTABLE_REBUILDSIZE 16
#define RING_HASHTABLE_HASHFUNCSEED 2024
/* Functions */

RING_API HashTable *ring_hashtable_new_gc(void *pRingState);

RING_API unsigned int ring_hashtable_hashkey_gc(void *pRingState, HashTable *pHashTable, const char *cKey);

RING_API HashItem *ring_hashtable_newitem_gc(void *pRingState, HashTable *pHashTable, const char *cKey);

RING_API void ring_hashtable_newnumber_gc(void *pRingState, HashTable *pHashTable, const char *cKey,
					  unsigned int nNumber);

RING_API void ring_hashtable_newpointer_gc(void *pRingState, HashTable *pHashTable, const char *cKey, void *pPointer);

RING_API HashItem *ring_hashtable_finditem_gc(void *pRingState, HashTable *pHashTable, const char *cKey);

RING_API unsigned int ring_hashtable_findnumber_gc(void *pRingState, HashTable *pHashTable, const char *cKey);

RING_API void *ring_hashtable_findpointer_gc(void *pRingState, HashTable *pHashTable, const char *cKey);

RING_API void ring_hashtable_deleteitem_gc(void *pRingState, HashTable *pHashTable, const char *cKey);

RING_API HashTable *ring_hashtable_delete_gc(void *pRingState, HashTable *pHashTable);

RING_API void ring_hashtable_print_gc(void *pRingState, HashTable *pHashTable);

RING_API void ring_hashtable_rebuild_gc(void *pRingState, HashTable *pHashTable);
/* Functions without the State pointer */

RING_API HashTable *ring_hashtable_new(void);

RING_API unsigned int ring_hashtable_hashkey(HashTable *pHashTable, const char *cKey);

RING_API HashItem *ring_hashtable_newitem(HashTable *pHashTable, const char *cKey);

RING_API void ring_hashtable_newnumber(HashTable *pHashTable, const char *cKey, unsigned int nNumber);

RING_API void ring_hashtable_newpointer(HashTable *pHashTable, const char *cKey, void *pPointer);

RING_API HashItem *ring_hashtable_finditem(HashTable *pHashTable, const char *cKey);

RING_API unsigned int ring_hashtable_findnumber(HashTable *pHashTable, const char *cKey);

RING_API void *ring_hashtable_findpointer(HashTable *pHashTable, const char *cKey);

RING_API void ring_hashtable_deleteitem(HashTable *pHashTable, const char *cKey);

RING_API HashTable *ring_hashtable_delete(HashTable *pHashTable);

RING_API void ring_hashtable_print(HashTable *pHashTable);

RING_API void ring_hashtable_rebuild(HashTable *pHashTable);
#endif
