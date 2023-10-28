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
    #define RING_POOLMANAGER_ITEMSTRINGSIZE 80
    #define RING_POOLMANAGER_ITEMSTRINGSIZEL2 256
    #define RING_POOLMANAGER_ITEMSINBLOCKL2 1000
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
