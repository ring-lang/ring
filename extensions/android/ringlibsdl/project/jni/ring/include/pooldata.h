/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_pooldata
	#define ring_pooldata
	/*
	**  Macro 
	**  Memory pool is thread safe because ring_vm_runcodefromthread() create new state 
	*/
	#define RING_USEPOOLMANAGER 1
	#if RING_LOWMEM
		#define RING_POOLMANAGER_ITEMSINBLOCK 128
		#define RING_POOLMANAGER_ITEMSINBLOCKL2 8
		#define RING_POOLMANAGER_ITEMSINBLOCKL3 4
		#define RING_POOLMANAGER_ITEMSINBLOCKStateLevel 8
	#else
		#define RING_POOLMANAGER_ITEMSINBLOCK 100000
		#define RING_POOLMANAGER_ITEMSINBLOCKL2 4096
		#define RING_POOLMANAGER_ITEMSINBLOCKL3 2048
		#define RING_POOLMANAGER_ITEMSINBLOCKStateLevel 2048
	#endif
	#define RING_POOLMANAGER_NOTFOUND 0
	/* Level 1 */
	#define RING_POOLMANAGER_ITEMSTRINGSIZE 48
	#define RING_POOLMANAGER_LEVEL1 1
	/* Level 2 */
	#define RING_POOLMANAGER_ITEMSTRINGSIZEL2 256
	#define RING_POOLMANAGER_LEVEL2 2
	/* Level 3 */
	#define RING_POOLMANAGER_ITEMSTRINGSIZEL3 512
	#define RING_POOLMANAGER_LEVEL3 3
	/* State Level */
	#define RING_POOLMANAGER_ITEMSTRINGSIZEStateLevel 192
	/* State */
	#define RING_VM_STATE_NUMBERS_COUNT 32
	#define RING_VM_STATE_POINTERS_COUNT 9
	/* Blocks List */
	#define RING_VM_BLOCKSTART 1
	#define RING_VM_BLOCKEND 2
	/* Data */
	typedef struct PoolData {
		union PoolDataTypes {
			String vString  ;
			Item vItem  ;
			Items vItems  ;
			List vList  ;
			HashTable vHashTable  ;
			HashItem vHashItem  ;
			char cChar[RING_POOLMANAGER_ITEMSTRINGSIZE]  ;
		} PoolDataTypes ;
		struct PoolData *pNext  ;
	} PoolData ;
	typedef struct PoolDataL2 {
		char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEL2]  ;
		struct PoolDataL2 *pNext  ;
	} PoolDataL2 ;
	typedef struct PoolDataL3 {
		char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEL3]  ;
		struct PoolDataL3 *pNext  ;
	} PoolDataL3 ;
	typedef struct VMState {
		int aNumbers[RING_VM_STATE_NUMBERS_COUNT]  ;
		void *aPointers[RING_VM_STATE_POINTERS_COUNT]  ;
	} VMState ;
	typedef struct PoolDataStateLevel {
		union PoolDataStateLevelTypes {
			VMState vVMState  ;
			char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEStateLevel]  ;
		} PoolDataStateLevelTypes ;
		struct PoolDataStateLevel *pNext  ;
	} PoolDataStateLevel ;
	typedef struct PoolManager {
		/* Level 1 */
		PoolData *pCurrentItem  ;
		void *pBlockStart  ;
		void *pBlockEnd  ;
		/* Level 2 */
		PoolDataL2 *pCurrentItemL2  ;
		void *pBlockStartL2  ;
		void *pBlockEndL2  ;
		/* Level 3 */
		PoolDataL3 *pCurrentItemL3  ;
		void *pBlockStartL3  ;
		void *pBlockEndL3  ;
		/* State Level */
		PoolDataStateLevel *pCurrentItemStateLevel  ;
		void *pBlockStartStateLevel  ;
		void *pBlockEndStateLevel  ;
		List *pBlocks  ;
		void *pMutex  ;
		unsigned int nItemsInBlock  ;
		unsigned int nItemsInBlockL2  ;
		unsigned int nItemsInBlockL3  ;
		unsigned int nItemsInBlockStateLevel  ;
		unsigned int lDeleteMemory  ;
	} PoolManager ;
#endif
