/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_pooldata
    #define ring_pooldata
    /*
    **  Macro 
    **  Memory pool is thread safe because ring_vm_runcodefromthread() create new state 
    */
    #if RING_MSDOS
        #define RING_USEPOOLMANAGER 0
    #else
        #define RING_USEPOOLMANAGER 1
    #endif
    #define RING_TRACKALLOCATIONS 0
    #define RING_POOLMANAGER_ITEMSINBLOCK 1000000
    #define RING_POOLMANAGER_ITEMSTRINGSIZE 44
    #define RING_POOLMANAGER_ITEMSTRINGSIZEL2 192
    #define RING_POOLMANAGER_ITEMSINBLOCKL2 2048
    #define RING_VM_STATE_NUMBERS_COUNT 30
    #define RING_VM_STATE_POINTERS_COUNT 9
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
    typedef struct VMState {
        int aNumbers[RING_VM_STATE_NUMBERS_COUNT]  ;
        void *aPointers[RING_VM_STATE_POINTERS_COUNT]  ;
    } VMState ;
    typedef struct PoolDataL2 {
        union PoolDataL2Types {
            VMState vVMState  ;
            char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEL2]  ;
        } PoolDataL2Types ;
        struct PoolDataL2 *pNext  ;
    } PoolDataL2 ;
    typedef struct PoolManager {
        PoolData *pCurrentItem  ;
        void *pBlockStart  ;
        void *pBlockEnd  ;
        PoolDataL2 *pCurrentItemL2  ;
        void *pBlockStartL2  ;
        void *pBlockEndL2  ;
        List *aBlocks  ;
        unsigned int nAllocCount  ;
        unsigned int nFreeCount  ;
        unsigned int nSmallAllocCount  ;
        unsigned int nSmallFreeCount  ;
        unsigned int nItemsInBlock  ;
        unsigned int nItemsInBlockL2  ;
        unsigned int lDeleteMemory  ;
    } PoolManager ;
#endif
