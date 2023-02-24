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
    #define RING_POOLMANAGER_ITEMSINBLOCK 2000000
    #define RING_POOLMANAGER_ITEMSTRINGSIZE 64
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
    typedef struct PoolManager {
        PoolData *pCurrentItem  ;
        void *pBlockStart  ;
        void *pBlockEnd  ;
        unsigned int nAllocCount  ;
        unsigned int nFreeCount  ;
        unsigned int nSmallAllocCount  ;
        unsigned int nSmallFreeCount  ;
        unsigned int nItemsInBlock  ;
        List *aBlocks  ;
        unsigned int lDeleteMemory  ;
    } PoolManager ;
#endif
