/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  Mutex 
*/

RING_API void ring_vm_mutexfunctions ( VM *pVM,void *(*pFunc)(void),void (*pFuncLock)(void *),void (*pFuncUnlock)(void *),void (*pFuncDestroy)(void *) )
{
    if ( pVM->pMutex == NULL ) {
        pVM->pMutex = pFunc() ;
        pVM->pFuncMutexLock = pFuncLock ;
        pVM->pFuncMutexUnlock = pFuncUnlock ;
        pVM->pFuncMutexDestroy = pFuncDestroy ;
    }
}

RING_API void ring_vm_mutexlock ( VM *pVM )
{
    if ( pVM->pMutex != NULL ) {
        pVM->pFuncMutexLock(pVM->pMutex);
    }
}

RING_API void ring_vm_mutexunlock ( VM *pVM )
{
    if ( pVM->pMutex != NULL ) {
        pVM->pFuncMutexUnlock(pVM->pMutex);
    }
}

RING_API void ring_vm_mutexdestroy ( VM *pVM )
{
    if ( pVM->pMutex != NULL ) {
        pVM->pFuncMutexDestroy(pVM->pMutex);
        pVM->pMutex = NULL ;
    }
}
/* Threads */

RING_API void ring_vm_runcodefromthread ( VM *pVM,const char *cStr )
{
    RingState *pState  ;
    List *pList,*pList2,*pList3,*pList4,*pList5,*pGlobal, *pVarList  ;
    Item *pItem  ;
    unsigned int nMemoryBlocksCount, x  ;
    Items *pItems  ;
    /* Create the RingState */
    pState = ring_state_init();
    /*
    **  Flag that we are running from thread 
    **  We check this flag when generating hash tables of lists (for functions or scope) 
    **  In this case we generate the hash table without the memory pool 
    **  Because the memory of the current memory pool of this state will be deleted when deleting the state 
    **  And the lists of the hash table will be needed to be used by the main VM 
    */
    pState->lRunFromThread = 1 ;
    pState->nPrintInstruction = pVM->pRingState->nPrintInstruction ;
    /* Share the same Mutex between VMs */
    ring_vm_mutexlock(pVM);
    pState->pVM->pMutex = pVM->pMutex ;
    pState->pVM->pFuncMutexDestroy = pVM->pFuncMutexDestroy ;
    pState->pVM->pFuncMutexLock = pVM->pFuncMutexLock ;
    pState->pVM->pFuncMutexUnlock = pVM->pFuncMutexUnlock ;
    /* Share the global scope between threads */
    pItem = pState->pVM->pMem->pFirst->pValue ;
    pState->pVM->pMem->pFirst->pValue = pVM->pMem->pFirst->pValue ;
    pGlobal = ring_item_getlist(pVM->pMem->pFirst->pValue ) ;
    for ( x = 1 ; x <= ring_list_getsize(pGlobal) ; x++ ) {
        pVarList = ring_list_getlist(pGlobal,x) ;
        if ( pVarList->pItemsArray == NULL ) {
            ring_list_genarray(pVarList);
        }
    }
    /* Get Items for the Memory Pool From the Main Thread */
    ring_poolmanager_newblockfromsubthread(pState,100000,pVM->pRingState);
    /* Share Memory Blocks (Could be used for Lists in Global Scope) */
    nMemoryBlocksCount = ring_list_getsize(pVM->pRingState->vPoolManager.aBlocks) ;
    /*
    **  Thread Safe Code instead of ring_list_copy(pState->vPoolManager.aBlocks,pVM->pRingState->vPoolManage 
    **  Because the List structure contains (Cache) that we update when we access each item 
    **  So we use the next code to avoid using/updating this cache 
    */
    if ( nMemoryBlocksCount > 0 ) {
        pItems = pVM->pRingState->vPoolManager.aBlocks->pFirst ;
        while ( pItems != NULL ) {
            /* Copy the Sub List - Each sub list contains two items [ Pointer, Pointer ] */
            if ( pItems->pValue != NULL ) {
                pList = ring_item_getlist(pItems->pValue) ;
                if ( pList != NULL ) {
                    if ( (pList->pFirst != NULL) && (pList->pLast != NULL) ) {
                        if ( (pList->pFirst->pValue != NULL) && (pList->pLast->pValue != NULL) ) {
                            pList2 = ring_list_newlist(pState->vPoolManager.aBlocks);
                            ring_list_addpointer(pList2,ring_item_getpointer(pList->pFirst->pValue));
                            ring_list_addpointer(pList2,ring_item_getpointer(pList->pLast->pValue));
                        }
                    }
                }
            }
            pItems = pItems->pNext ;
        }
    }
    /* Save the state */
    pList = pState->pVM->pCode ;
    pList2 = pState->pVM->pFunctionsMap ;
    pList3 = pState->pVM->pClassesMap ;
    pList4 = pState->pVM->pPackagesMap ;
    pList5 = pState->pVM->pCFunctionsList ;
    /*
    **  Share the code between the VMs 
    **  Copy Functions/Classes/Packages lists 
    */
    pState->pVM->pFunctionsMap = ring_list_new(0) ;
    pState->pVM->pClassesMap = ring_list_new(0) ;
    pState->pVM->pPackagesMap = ring_list_new(0) ;
    pState->pVM->pCFunctionsList = ring_list_new(0) ;
    ring_list_copy(pState->pVM->pFunctionsMap,pVM->pRingState->pRingFunctionsMap);
    ring_list_copy(pState->pVM->pClassesMap,pVM->pRingState->pRingClassesMap);
    ring_list_copy(pState->pVM->pPackagesMap,pVM->pRingState->pRingPackagesMap);
    ring_list_copy(pState->pVM->pCFunctionsList,pVM->pRingState->pRingCFunctions);
    ring_list_genarray(pState->pVM->pCFunctionsList);
    ring_list_genhashtable2(pState->pVM->pCFunctionsList);
    pState->pRingFunctionsMap = pState->pVM->pFunctionsMap ;
    pState->pRingClassesMap = pState->pVM->pClassesMap ;
    pState->pRingPackagesMap = pState->pVM->pPackagesMap ;
    pState->pRingCFunctions = pState->pVM->pCFunctionsList ;
    /* Get a copy from the byte code List */
    pState->pVM->nScopeID = pVM->nScopeID + 10000 ;
    pState->pVM->pCode = ring_list_new_gc(pState,0) ;
    pState->pRingGenCode = pState->pVM->pCode ;
    /* Get a copy from the Byte Code */
    ring_vm_bytecodefornewthread(pState->pVM,pVM);
    /* Avoid the call to the main function */
    pState->pVM->nCallMainFunction = 1 ;
    ring_vm_mutexunlock(pVM);
    /* Run the code */
    ring_state_runcode(pState,cStr);
    ring_vm_mutexlock(pVM);
    /* Return Memory Pool Items to the Main Thread */
    ring_poolmanager_deleteblockfromsubthread(pState,pVM->pRingState);
    /* Delete Code List */
    ring_list_delete_gc(pState,pState->pVM->pCode);
    ring_list_delete_gc(pState,pState->pVM->pFunctionsMap);
    ring_list_delete_gc(pState,pState->pVM->pClassesMap);
    ring_list_delete_gc(pState,pState->pVM->pPackagesMap);
    ring_list_delete_gc(pState,pState->pVM->pCFunctionsList);
    /* Restore the first scope - global scope */
    pState->pVM->pMem->pFirst->pValue = pItem ;
    /* Avoid deleting the shared lists and the Mutex */
    pState->pVM->pCode = pList ;
    pState->pVM->pFunctionsMap = pList2 ;
    pState->pVM->pClassesMap = pList3 ;
    pState->pVM->pPackagesMap = pList4 ;
    pState->pVM->pCFunctionsList = pList5 ;
    pState->pRingGenCode = pList ;
    pState->pRingFunctionsMap = pList2 ;
    pState->pRingClassesMap = pList3 ;
    pState->pRingPackagesMap = pList4 ;
    pState->pRingCFunctions = pList5 ;
    pState->pVM->pMutex = NULL ;
    pState->pVM->pFuncMutexDestroy = NULL ;
    pState->pVM->pFuncMutexLock = NULL ;
    pState->pVM->pFuncMutexUnlock = NULL ;
    /* Avoid deleting the Shared Memory Blocks */
    if ( nMemoryBlocksCount > 0 ) {
        for ( x = 1 ; x <=nMemoryBlocksCount ; x++ ) {
            ring_list_deleteitem(pState->vPoolManager.aBlocks,1);
        }
    }
    ring_vm_mutexunlock(pVM);
    /* Avoid deleting the Mutex */
    pState->pVM->pMutex = NULL ;
    /* Delete the RingState */
    ring_state_delete(pState);
}

RING_API void ring_vm_bytecodefornewthread ( VM *pVM,VM *pOldVM )
{
    int x,y,nSize,nCount,nType  ;
    ByteCode *pByteCode  ;
    String *pString  ;
    /* Get the Instructions Count */
    pVM->pRingState->nInstructionsCount = pOldVM->pRingState->nInstructionsCount ;
    /* Allocate memory for the Byte Code */
    nSize = pOldVM->nEvalReallocationSize ;
    pVM->pByteCode = (ByteCode *) ring_calloc(nSize,sizeof(ByteCode));
    pVM->nEvalReallocationSize = nSize ;
    /* Copy the Byte Code */
    memcpy(pVM->pByteCode,pOldVM->pByteCode,nSize*sizeof(ByteCode));
    /* Create new strings */
    for ( x = 1 ; x <= RING_VM_INSTRUCTIONSCOUNT ; x++ ) {
        pByteCode = pVM->pByteCode + x - 1 ;
        nCount = pByteCode->nInsSize - 1 ;
        for ( y = 0 ; y < nCount ; y++ ) {
            /* Get The Register Type */
            if ( y == 0 ) {
                nType = pByteCode->nReg1Type ;
            }
            else if ( y == 1 ) {
                nType = pByteCode->nReg2Type ;
            }
            else {
                nType = pByteCode->nReg3Type ;
            }
            /* Create new string */
            if ( nType == RING_VM_REGTYPE_STRING ) {
                pString = ring_string_new2(ring_string_get(pByteCode->aReg[y].pString),ring_string_size(pByteCode->aReg[y].pString));
                pByteCode->aReg[y].pString = pString ;
            }
        }
    }
}
