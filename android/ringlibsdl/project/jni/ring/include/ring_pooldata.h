/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_pooldata
#define ring_pooldata
/*
**  Macro 
**  Memory pool is thread safe because ring_vm_runcodefromthread() create new state 
*/
#define RING_USEPOOLMANAGER 1
#define RING_TRACKALLOCATIONS 0
#define RING_POOLMANAGER_ITEMSINBLOCK 500000
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
	unsigned int nAllocCount  ;
	unsigned int nFreeCount  ;
	unsigned int nSmallAllocCount  ;
	unsigned int nSmallFreeCount  ;
} PoolManager ;
#endif
