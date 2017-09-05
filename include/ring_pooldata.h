/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_pooldata
#define ring_pooldata
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
#endif
