/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_pooldata
#define ring_pooldata
/* Data */
typedef struct PoolData {
	union PoolDataTypes {
		String vString  ;
		Item vItem  ;
		Items vItems  ;
		List vList  ;
		HashTable vHashTable  ;
		HashItem vHashItem  ;
		char vChar[64]  ;
	} PoolDataTypes ;
	struct PoolData *pNext  ;
} PoolData ;
typedef struct PoolManager {
	PoolData *pCurrentItem  ;
	void *pBlockStart  ;
	void *pBlockEnd  ;
} PoolManager ;
/* Macro */
#define RING_POOLMANAGER_ITEMSINBLOCK 10000
#define RING_POOLMANAGER_ITEMSIZE 64
#define RING_USEPOOLMANAGER 0
#endif
