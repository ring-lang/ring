/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_pooldata
#define ring_pooldata
/*
**  Macro 
**  We disable the memory pool to have malloc() and free() - thread safe 
*/
#define RING_USEPOOLMANAGER 0
#define RING_POOLMANAGER_ITEMSINBLOCK 10000
#define RING_POOLMANAGER_ITEMSIZE 64
/* Data */
typedef struct PoolData {
	union PoolDataTypes {
		String vString  ;
		Item vItem  ;
		Items vItems  ;
		List vList  ;
		HashTable vHashTable  ;
		HashItem vHashItem  ;
		char vChar[RING_POOLMANAGER_ITEMSIZE]  ;
	} PoolDataTypes ;
	struct PoolData *pNext  ;
} PoolData ;
typedef struct PoolManager {
	PoolData *pCurrentItem  ;
	void *pBlockStart  ;
	void *pBlockEnd  ;
} PoolManager ;
#endif
