/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API void ring_vm_mutexfunctions ( VM *pVM,void *(*pFuncCreate)(void),void (*pFuncLock)(void *),void (*pFuncUnlock)(void *),void (*pFuncDestroy)(void *) )
{
	if ( pVM->pMutex == NULL ) {
		pVM->pFuncMutexCreate = pFuncCreate ;
		pVM->pFuncMutexLock = pFuncLock ;
		pVM->pFuncMutexUnlock = pFuncUnlock ;
		pVM->pFuncMutexDestroy = pFuncDestroy ;
		if ( pFuncCreate != NULL ) {
			pVM->pMutex = pFuncCreate() ;
			pVM->pRingState->vPoolManager.pMutex = pFuncCreate() ;
		}
	}
}

RING_API void ring_vm_mutexlock ( VM *pVM )
{
	if ( (pVM->pMutex != NULL) && (pVM->pFuncMutexLock != NULL) ) {
		pVM->pFuncMutexLock(pVM->pMutex);
	}
}

RING_API void ring_vm_mutexunlock ( VM *pVM )
{
	if ( (pVM->pMutex != NULL) && (pVM->pFuncMutexUnlock != NULL) ) {
		pVM->pFuncMutexUnlock(pVM->pMutex);
	}
}

RING_API void ring_vm_mutexdestroy ( VM *pVM )
{
	if ( (pVM->pMutex != NULL) && (pVM->pFuncMutexDestroy != NULL) ) {
		pVM->pFuncMutexDestroy(pVM->pMutex);
		pVM->pMutex = NULL ;
		pVM->pFuncMutexDestroy(pVM->pRingState->vPoolManager.pMutex);
		pVM->pRingState->vPoolManager.pMutex = NULL ;
	}
}

RING_API void * ring_vm_custmutexcreate ( VM *pVM )
{
	if ( pVM->pFuncMutexCreate != NULL ) {
		return pVM->pFuncMutexCreate() ;
	}
	return NULL ;
}

RING_API void ring_vm_custmutexlock ( VM *pVM, void *pMutex )
{
	if ( (pMutex != NULL) && (pVM->pFuncMutexLock != NULL) ) {
		pVM->pFuncMutexLock(pMutex);
	}
}

RING_API void ring_vm_custmutexunlock ( VM *pVM, void *pMutex )
{
	if ( (pMutex != NULL) && (pVM->pFuncMutexUnlock != NULL) ) {
		pVM->pFuncMutexUnlock(pMutex);
	}
}

RING_API void ring_vm_custmutexdestroy ( VM *pVM, void *pMutex )
{
	if ( (pMutex != NULL) && (pVM->pFuncMutexDestroy != NULL) ) {
		pVM->pFuncMutexDestroy(pMutex);
	}
}

RING_API void ring_vm_runcodefromthread ( VM *pVM,const char *cStr )
{
	RingState *pState  ;
	pState = ring_vm_createthreadstate(pVM);
	/* Run the code */
	ring_state_runcode(pState,cStr);
	ring_vm_deletethreadstate(pVM,pState);
}

RING_API RingState * ring_vm_createthreadstate ( VM *pVM )
{
	RingState *pState  ;
	List *pGlobal, *pVarList, *pScope  ;
	unsigned int x, y  ;
	/* Create the RingState */
	pState = ring_state_init();
	/* Flag that we are running from thread */
	pState->lRunFromThread = 1 ;
	pState->lPrintInstruction = pVM->pRingState->lPrintInstruction ;
	/* Share the same Mutex between VMs */
	ring_vm_mutexlock(pVM);
	pState->pVM->pFuncMutexCreate = pVM->pFuncMutexCreate ;
	pState->pVM->pFuncMutexDestroy = pVM->pFuncMutexDestroy ;
	pState->pVM->pFuncMutexLock = pVM->pFuncMutexLock ;
	pState->pVM->pFuncMutexUnlock = pVM->pFuncMutexUnlock ;
	pState->pVM->pMutex = pVM->pMutex ;
	pState->vPoolManager.pMutex = pVM->pRingState->vPoolManager.pMutex ;
	/* Share the global scope between threads */
	RING_VM_SHAREGLOBALSCOPE(pState->pVM,pVM);
	pGlobal = RING_VM_GETSCOPE(RING_MEMORY_GLOBALSCOPE) ;
	if ( pGlobal->pItemsArray == NULL ) {
		ring_list_genarray(pGlobal);
	}
	for ( x = 1 ; x <= ring_list_getsize(pGlobal) ; x++ ) {
		pVarList = ring_list_getlist(pGlobal,x) ;
		if ( pVarList->pItemsArray == NULL ) {
			ring_list_genarray(pVarList);
		}
	}
	/* Share the other global scopes */
	ring_list_delete(pState->pVM->pGlobalScopes);
	pState->pVM->pGlobalScopes = pVM->pGlobalScopes ;
	if ( pVM->pGlobalScopes->pItemsArray  == NULL ) {
		ring_list_genarray(pVM->pGlobalScopes);
	}
	for ( x = 1 ; x <= ring_list_getsize(pVM->pGlobalScopes) ; x++ ) {
		pScope = ring_list_getlist(pVM->pGlobalScopes,x) ;
		if ( pScope->pItemsArray == NULL ) {
			ring_list_genarray(pScope);
		}
		for ( y = 1 ; y <= ring_list_getsize(pScope) ; y++ ) {
			pVarList = ring_list_getlist(pScope,y) ;
			if ( pVarList->pItemsArray == NULL ) {
				ring_list_genarray(pVarList);
			}
		}
	}
	/* Get Items for the Memory Pool From the Main Thread */
	ring_poolmanager_newblockfromsubthread(pState,RING_VM_ITEMSFORNEWTHREAD,pVM->pRingState);
	/* Share Memory Blocks (Could be used for Lists in Global Scope) */
	ring_list_delete(pState->vPoolManager.pBlocks);
	pState->vPoolManager.pBlocks = pVM->pRingState->vPoolManager.pBlocks ;
	/* Save the state */
	pState->pVM->pCode = ring_list_delete(pState->pVM->pCode);
	pState->pVM->pFunctionsMap = ring_list_delete(pState->pVM->pFunctionsMap);
	pState->pVM->pClassesMap = ring_list_delete(pState->pVM->pClassesMap);
	pState->pVM->pPackagesMap = ring_list_delete(pState->pVM->pPackagesMap);
	/*
	**  Share the code between the VMs 
	**  Copy Functions/Classes/Packages lists 
	*/
	pState->pVM->pFunctionsMap = ring_list_new(RING_ZERO) ;
	pState->pVM->pClassesMap = ring_list_new(RING_ZERO) ;
	pState->pVM->pPackagesMap = ring_list_new(RING_ZERO) ;
	ring_list_copy(pState->pVM->pFunctionsMap,pVM->pRingState->pRingFunctionsMap);
	ring_list_copy(pState->pVM->pClassesMap,pVM->pRingState->pRingClassesMap);
	ring_list_copy(pState->pVM->pPackagesMap,pVM->pRingState->pRingPackagesMap);
	pState->pVM->pCFunction = pVM->pCFunction ;
	pState->pRingFunctionsMap = pState->pVM->pFunctionsMap ;
	pState->pRingClassesMap = pState->pVM->pClassesMap ;
	pState->pRingPackagesMap = pState->pVM->pPackagesMap ;
	/* Get a copy from the byte code List */
	pState->pVM->pCode = ring_list_new(RING_ZERO) ;
	pState->pRingGenCode = pState->pVM->pCode ;
	/* Get a copy from the Byte Code */
	ring_vm_bytecodefornewthread(pState->pVM,pVM);
	/* Avoid the call to the main function */
	pState->pVM->lCallMainFunction = 1 ;
	ring_vm_mutexunlock(pVM);
	return pState ;
}

RING_API void ring_vm_deletethreadstate ( VM *pVM,RingState *pState )
{
	List *pList,*pList2,*pList3,*pList4, *pBlocks  ;
	CFunction *pCFunc, *pCFunc2  ;
	ring_vm_mutexlock(pVM);
	/* Return Memory Pool Items to the Main Thread */
	ring_poolmanager_deleteblockfromsubthread(pState,pVM->pRingState);
	/* Delete Code List */
	ring_list_delete_gc(pState,pState->pVM->pCode);
	ring_list_delete_gc(pState,pState->pVM->pFunctionsMap);
	ring_list_delete_gc(pState,pState->pVM->pClassesMap);
	ring_list_delete_gc(pState,pState->pVM->pPackagesMap);
	/* Restore other global scopes */
	pState->pVM->pGlobalScopes = ring_list_new(RING_ZERO) ;
	/* Create Lists */
	pList = ring_list_new(RING_ZERO) ;
	pList2 = ring_list_new(RING_ZERO) ;
	pList3 = ring_list_new(RING_ZERO) ;
	pList4 = ring_list_new(RING_ZERO) ;
	/* Avoid deleting the shared lists and the Mutex */
	pState->pVM->pCode = pList ;
	pState->pVM->pFunctionsMap = pList2 ;
	pState->pVM->pClassesMap = pList3 ;
	pState->pVM->pPackagesMap = pList4 ;
	pState->pRingGenCode = pList ;
	pState->pRingFunctionsMap = pList2 ;
	pState->pRingClassesMap = pList3 ;
	pState->pRingPackagesMap = pList4 ;
	pState->pVM->pFuncMutexCreate = NULL ;
	pState->pVM->pFuncMutexDestroy = NULL ;
	pState->pVM->pFuncMutexLock = NULL ;
	pState->pVM->pFuncMutexUnlock = NULL ;
	pState->pVM->pMutex = NULL ;
	pState->vPoolManager.pMutex = NULL ;
	pCFunc = pVM->pCFunction ;
	if ( pState->pVM->pCFunction != NULL ) {
		/* Delete Extra C Functions (Loaded by the Sub Thread) */
		while ( pState->pVM->pCFunction != pCFunc ) {
			pCFunc2 = pState->pVM->pCFunction ;
			pState->pVM->pCFunction = pState->pVM->pCFunction->pNext ;
			ring_state_free(NULL,pCFunc2);
		}
		/* Avoid deleting C functions loaded by the Main thread */
		pState->pVM->pCFunction = NULL ;
	}
	/* Avoid deleting the Shared Memory Blocks */
	pState->vPoolManager.pBlocks = ring_list_new(RING_ZERO) ;
	ring_vm_mutexunlock(pVM);
	/* Delete the RingState */
	ring_state_delete(pState);
}

RING_API void ring_vm_bytecodefornewthread ( VM *pVM,VM *pOldVM )
{
	int x,y,nSize,nType  ;
	ByteCode *pByteCode  ;
	char *pString  ;
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
		for ( y = 0 ; y < RING_VM_BC_ITEMS_COUNT ; y++ ) {
			/* Get The Register Type */
			if ( y == 0 ) {
				nType = pByteCode->nReg1Type ;
			}
			else if ( y == 1 ) {
				nType = pByteCode->nReg2Type ;
			}
			/* Create new string */
			if ( nType == RING_VM_REGTYPE_STRING ) {
				pString = ring_string_strdup(NULL,pByteCode->aReg[y].pString);
				pByteCode->aReg[y].pString = pString ;
			}
		}
	}
}
