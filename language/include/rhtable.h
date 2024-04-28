/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

// Updated & Enhanced by Abdallah Mohamed ( @0xNinjaCyclone )

#ifndef ring_hashtable_h
	#define ring_hashtable_h
	/* Data */
	typedef struct HashItem {
		char  *cKey  ;
		union HashValue {
			int nIndex  ;
			void *pValue  ;
			double dValue ;
			char *cpStr ;
			List *pList ;
			void (*fpFunc)(void *) ;
		} HashValue ;
		struct HashItem *pNext  ;
		char nItemType  ;
	} HashItem ;
	typedef struct HashTable {
		HashItem **pArray  ;
		int nItems  ;
		int nLinkedLists  ;
		int nRebuildSize  ;
	} HashTable ;
	/* Constants */
	#define RING_HASHITEMTYPE_NOTYPE 0
	#define RING_HASHITEMTYPE_INTEGER 1
	#define RING_HASHITEMTYPE_NUMBER RING_HASHITEMTYPE_INTEGER
	#define RING_HASHITEMTYPE_POINTER 2
	#define RING_HASHITEMTYPE_DOUBLE 3
	#define RING_HASHITEMTYPE_STRING 4
	#define RING_HASHITEMTYPE_LIST 5
	#define RING_HASHITEMTYPE_FUNCTIONPOINTER 6
	#define RING_HASHTABLE_LINKEDLISTS 2
	#define RING_HASHTABLE_REBUILDSIZE 7
	/* Functions */

	HashTable * ring_hashtable_new_gc ( void *pRingState ) ;

	unsigned int ring_hashtable_hashkey ( HashTable *pHashTable,const char *cKey ) ;

	HashItem * ring_hashtable_newitem_gc ( void *pRingState,HashTable *pHashTable,const char *cKey ) ;

	void ring_hashtable_newnumber_gc ( void *pRingState,HashTable *pHashTable,const char *cKey,int nNumber ) ;

	void ring_hashtable_newpointer_gc ( void *pRingState,HashTable *pHashTable,const char *cKey,void *pPointer ) ;

	int ring_hashtable_insertint_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, int nNumber ) ;

	int ring_hashtable_insertptr_gc ( void *pRingState, HashTable *pHashTable, const char *cKey,void *pPointer ) ;

	int ring_hashtable_insertdbl_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, double dNumber ) ;

	int ring_hashtable_insertstr_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, char *cpStr ) ;

	int ring_hashtable_insertlst_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, List *pList ) ;

	int ring_hashtable_insertfnp_gc ( void *pRingState, HashTable *pHashTable, const char *cKey, void (*fpFunc)(void *) ) ;

	int ring_hashtable_updateint ( HashTable *pHashTable, const char *cKey, int nNumber ) ;

	int ring_hashtable_updateptr ( HashTable *pHashTable, const char *cKey, void *pPointer ) ;

	int ring_hashtable_updatedbl ( HashTable *pHashTable, const char *cKey, double dNumber ) ;

	int ring_hashtable_updatestr ( HashTable *pHashTable, const char *cKey, char *cpStr ) ;

	int ring_hashtable_updatelst ( HashTable *pHashTable, const char *cKey, List *pList ) ;

	int ring_hashtable_updatefnp ( HashTable *pHashTable, const char *cKey, void (*fpFunc)(void *) ) ;

	HashItem * ring_hashtable_finditem ( HashTable *pHashTable,const char *cKey ) ;

	int ring_hashtable_findnumber ( HashTable *pHashTable,const char *cKey ) ;

	void * ring_hashtable_findpointer ( HashTable *pHashTable,const char *cKey ) ;

	double ring_hashtable_finddouble ( HashTable *pHashTable,const char *cKey ) ;

	char *ring_hashtable_findstring ( HashTable *pHashTable,const char *cKey ) ;

	List *ring_hashtable_findlist ( HashTable *pHashTable,const char *cKey ) ;

	void (*ring_hashtable_findfunctionpointer( HashTable *pHashTable,const char *cKey ))(void *) ;

	void ring_hashtable_deleteitem_gc ( void *pRingState,HashTable *pHashTable,const char *cKey ) ;

	int ring_hashtable_deleteitem2_gc ( void *pRingState, HashTable *pHashTable, const char *cKey ) ;

	HashTable * ring_hashtable_delete_gc ( void *pRingState,HashTable *pHashTable ) ;

	int ring_hashtable_first ( HashTable *pHashTable, unsigned int *unpPosition, char **cpKey, HashItem **pItem ) ;

	int ring_hashtable_next ( HashTable *pHashTable, unsigned int *unpPosition, char **cpKey, HashItem **pItem ) ;

	void ring_hashtable_print ( HashTable *pHashTable ) ;

	void ring_hashtable_print2 ( HashTable *pHashTable ) ;

	int ring_hashtable_haskey ( HashTable *pHashTable, const char *cpKey ) ;

	int ring_hashtable_gettype ( HashTable *pHashTable, const char *cpKey ) ;

	int ring_hashtable_compare ( HashTable *pHashTable, HashTable *pHashTable2 ) ;

	List *ring_hashtable_getkeys_gc ( void *pRingState, HashTable *pHashTable ) ;

	HashTable *ring_hashtable_clone_gc ( void *pRingState, HashTable *pHashTable ) ;

	void ring_hashtable_rebuild_gc ( void *pRingState,HashTable *pHashTable ) ;
	/* Functions without the State pointer */

	HashTable * ring_hashtable_new ( void ) ;

	HashItem * ring_hashtable_newitem ( HashTable *pHashTable,const char *cKey ) ;

	void ring_hashtable_deleteitem ( HashTable *pHashTable,const char *cKey ) ;

	void ring_hashtable_deleteitem ( HashTable *pHashTable, const char *cKey ) ;

	int ring_hashtable_deleteitem2 ( HashTable *pHashTable, const char *cKey ) ;

	HashTable * ring_hashtable_delete ( HashTable *pHashTable ) ;

	void ring_hashtable_rebuild ( HashTable *pHashTable ) ;

	void ring_hashtable_newnumber ( HashTable *pHashTable,const char *cKey,int nNumber ) ;

	void ring_hashtable_newpointer ( HashTable *pHashTable,const char *cKey,void *pPointer ) ;

	int ring_hashtable_insertint ( HashTable *pHashTable, const char *cKey, int nNumber ) ;

	int ring_hashtable_insertptr ( HashTable *pHashTable, const char *cKey,void *pPointer ) ;

	int ring_hashtable_insertdbl ( HashTable *pHashTable, const char *cKey, double dNumber ) ;

	int ring_hashtable_insertstr ( HashTable *pHashTable, const char *cKey, char *cpStr ) ;

	int ring_hashtable_insertlst ( HashTable *pHashTable, const char *cKey, List *pList ) ;

	int ring_hashtable_insertfnp ( HashTable *pHashTable, const char *cKey, void (*fpFunc)(void *) ) ;

	List *ring_hashtable_getkeys( HashTable *pHashTable ) ;

	HashTable *ring_hashtable_clone ( HashTable *pHashTable ) ;

#endif
