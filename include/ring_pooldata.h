/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_pooldata
#define ring_pooldata
typedef struct PoolData {
	union PoolDataTypes {
		struct String vString  ;
		struct Item vItem  ;
		struct Items vItems  ;
		struct List vList  ;
		struct HashTable vHashTable  ;
		struct HashItem vHashItem  ;
		char vChar[64]  ;
	} PoolDataTypes ;
	struct PoolData *pNext  ;
} PoolData ;
#endif
