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
    /* Level 1 */
    #define RING_POOLMANAGER_ITEMSTRINGSIZE 44
    #define RING_POOLMANAGER_ITEMSINBLOCK 1000000
    /* Level 2 */
    #define RING_POOLMANAGER_ITEMSTRINGSIZEL2 512
    #define RING_POOLMANAGER_ITEMSINBLOCKL2 4096
    /* Level 3 */
    #define RING_POOLMANAGER_ITEMSTRINGSIZEL3 1024
    #define RING_POOLMANAGER_ITEMSINBLOCKL3 2048
    /* Level 4 */
    #define RING_POOLMANAGER_ITEMSTRINGSIZEL4 8192
    #define RING_POOLMANAGER_ITEMSINBLOCKL4 128
    /* Level 5 */
    #define RING_POOLMANAGER_ITEMSTRINGSIZEL5 10*1024*1024
    #define RING_POOLMANAGER_ITEMSINBLOCKL5 4
    /* Level 6 */
    #define RING_POOLMANAGER_ITEMSTRINGSIZEL6 192
    #define RING_POOLMANAGER_ITEMSINBLOCKL6 2048
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
    typedef struct PoolDataL2 {
        char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEL2]  ;
        struct PoolDataL2 *pNext  ;
    } PoolDataL2 ;
    typedef struct PoolDataL3 {
        char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEL3]  ;
        struct PoolDataL3 *pNext  ;
    } PoolDataL3 ;
    typedef struct PoolDataL4 {
        char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEL4]  ;
        struct PoolDataL4 *pNext  ;
    } PoolDataL4 ;
    typedef struct PoolDataL5 {
        char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEL5]  ;
        struct PoolDataL5 *pNext  ;
    } PoolDataL5 ;
    typedef struct VMState {
        int aNumbers[RING_VM_STATE_NUMBERS_COUNT]  ;
        void *aPointers[RING_VM_STATE_POINTERS_COUNT]  ;
    } VMState ;
    typedef struct PoolDataL6 {
        union PoolDataL6Types {
            VMState vVMState  ;
            char cChar[RING_POOLMANAGER_ITEMSTRINGSIZEL6]  ;
        } PoolDataL6Types ;
        struct PoolDataL6 *pNext  ;
    } PoolDataL6 ;
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
        /* Level 4 */
        PoolDataL4 *pCurrentItemL4  ;
        void *pBlockStartL4  ;
        void *pBlockEndL4  ;
        /* Level 5 */
        PoolDataL5 *pCurrentItemL5  ;
        void *pBlockStartL5  ;
        void *pBlockEndL5  ;
        /* Level 6 */
        PoolDataL6 *pCurrentItemL6  ;
        void *pBlockStartL6  ;
        void *pBlockEndL6  ;
        List *aBlocks  ;
        unsigned int nAllocCount  ;
        unsigned int nFreeCount  ;
        unsigned int nSmallAllocCount  ;
        unsigned int nSmallFreeCount  ;
        unsigned int nItemsInBlock  ;
        unsigned int nItemsInBlockL2  ;
        unsigned int nItemsInBlockL3  ;
        unsigned int nItemsInBlockL4  ;
        unsigned int nItemsInBlockL5  ;
        unsigned int nItemsInBlockL6  ;
        unsigned int lDeleteMemory  ;
    } PoolManager ;
#endif
