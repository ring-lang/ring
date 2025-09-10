/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API void ring_vm_mutexfunctions(VM *pVM, void *(*pFuncCreate)(void), void (*pFuncLock)(void *),
				     void (*pFuncUnlock)(void *), void (*pFuncDestroy)(void *)) {
	int x;
	if (pVM->pMutex == NULL) {
		pVM->pRingState->lUsingThreads = RING_TRUE;
		pVM->pFuncMutexCreate = pFuncCreate;
		pVM->pFuncMutexLock = pFuncLock;
		pVM->pFuncMutexUnlock = pFuncUnlock;
		pVM->pFuncMutexDestroy = pFuncDestroy;
		if (pFuncCreate != NULL) {
			pVM->pMutex = pFuncCreate();
			pVM->pRingState->vPoolManager.pMutex = pFuncCreate();
			for (x = 0; x < RING_VM_CUSTOMMUTEX_COUNT; x++) {
				pVM->aCustomMutex[x] = pFuncCreate();
			}
		}
	}
}

RING_API void ring_vm_mutexlock(VM *pVM) {
	if ((pVM->pMutex != NULL) && (pVM->pFuncMutexLock != NULL)) {
		pVM->pFuncMutexLock(pVM->pMutex);
	}
}

RING_API void ring_vm_mutexunlock(VM *pVM) {
	if ((pVM->pMutex != NULL) && (pVM->pFuncMutexUnlock != NULL)) {
		pVM->pFuncMutexUnlock(pVM->pMutex);
	}
}

RING_API void ring_vm_mutexdestroy(VM *pVM) {
	int x;
	if ((pVM->pMutex != NULL) && (pVM->pFuncMutexDestroy != NULL)) {
		pVM->pFuncMutexDestroy(pVM->pMutex);
		pVM->pMutex = NULL;
		pVM->pFuncMutexDestroy(pVM->pRingState->vPoolManager.pMutex);
		pVM->pRingState->vPoolManager.pMutex = NULL;
		for (x = 0; x < RING_VM_CUSTOMMUTEX_COUNT; x++) {
			pVM->pFuncMutexDestroy(pVM->aCustomMutex[x]);
			pVM->aCustomMutex[x] = NULL;
		}
	}
}

RING_API void *ring_vm_custmutexcreate(VM *pVM) {
	if (pVM->pFuncMutexCreate != NULL) {
		return pVM->pFuncMutexCreate();
	}
	return NULL;
}

RING_API void ring_vm_custmutexlock(VM *pVM, void *pMutex) {
	if ((pMutex != NULL) && (pVM->pFuncMutexLock != NULL)) {
		pVM->pFuncMutexLock(pMutex);
	}
}

RING_API void ring_vm_custmutexunlock(VM *pVM, void *pMutex) {
	if ((pMutex != NULL) && (pVM->pFuncMutexUnlock != NULL)) {
		pVM->pFuncMutexUnlock(pMutex);
	}
}

RING_API void ring_vm_custmutexdestroy(VM *pVM, void *pMutex) {
	if ((pMutex != NULL) && (pVM->pFuncMutexDestroy != NULL)) {
		pVM->pFuncMutexDestroy(pMutex);
	}
}

RING_API void ring_vm_statecustmutexlock(void *pState, unsigned int nMutex) {
	VM *pVM;
	if (pState == NULL || (((RingState *)pState)->pVM == NULL)) {
		return;
	}
	pVM = ((RingState *)pState)->pVM;
	if ((pVM->aCustomMutex[nMutex] != NULL) && (pVM->pFuncMutexLock != NULL)) {
		pVM->pFuncMutexLock(pVM->aCustomMutex[nMutex]);
	}
}

RING_API void ring_vm_statecustmutexunlock(void *pState, unsigned int nMutex) {
	VM *pVM;
	if (pState == NULL || (((RingState *)pState)->pVM == NULL)) {
		return;
	}
	pVM = ((RingState *)pState)->pVM;
	if ((pVM->aCustomMutex[nMutex] != NULL) && (pVM->pFuncMutexLock != NULL)) {
		pVM->pFuncMutexUnlock(pVM->aCustomMutex[nMutex]);
	}
}

RING_API void ring_vm_runcodefromthread(VM *pVM, const char *cStr) {
	RingState *pState;
	pState = ring_vm_createthreadstate(pVM);
	ring_state_runcode(pState, cStr);
	ring_vm_deletethreadstate(pVM, pState);
}

RING_API RingState *ring_vm_createthreadstate(VM *pVM) {
	RingState *pState;
	List *pGlobal, *pScope;
	unsigned int x;
	/* Create the RingState */
	pState = ring_state_init();
	/* Flag that we are using threads */
	pState->lUsingThreads = RING_TRUE;
	/* Flag that we are running from sub thread */
	pState->lRunFromSubThread = RING_TRUE;
	pState->lPrintInstruction = pVM->pRingState->lPrintInstruction;
	/* Delete the C Functions */
	ring_vm_deletecfunctions(pState->pVM);
	/* Delete previous byte code */
	if (pState->pVM->pByteCode != NULL) {
		ring_vm_deleteallbytecode(pState->pVM);
	}
	/* Lock */
	ring_vm_mutexlock(pVM);
	ring_vm_custmutexlock(pVM, pVM->pRingState->vPoolManager.pMutex);
	ring_vm_custmutexlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_FUNCHASHTABLE]);
	ring_vm_custmutexlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_VARHASHTABLE]);
	/*
	**  Share the same Mutex between VMs
	**  Share Mutex Functions
	*/
	pState->pVM->pFuncMutexCreate = pVM->pFuncMutexCreate;
	pState->pVM->pFuncMutexDestroy = pVM->pFuncMutexDestroy;
	pState->pVM->pFuncMutexLock = pVM->pFuncMutexLock;
	pState->pVM->pFuncMutexUnlock = pVM->pFuncMutexUnlock;
	/* Share Mutex Objects */
	pState->pVM->pMutex = pVM->pMutex;
	pState->vPoolManager.pMutex = pVM->pRingState->vPoolManager.pMutex;
	for (x = 0; x < RING_VM_CUSTOMMUTEX_COUNT; x++) {
		pState->pVM->aCustomMutex[x] = pVM->aCustomMutex[x];
	}
	/* Share the global scope between threads */
	RING_VM_SHAREGLOBALSCOPE(pState->pVM, pVM);
	pGlobal = RING_VM_GETSCOPE(RING_MEMORY_GLOBALSCOPE);
	if (pGlobal->pItemsArray == NULL) {
		ring_list_genarray(pGlobal);
	}
	/* Share the other global scopes */
	ring_list_delete(pState->pVM->pGlobalScopes);
	pState->pVM->pGlobalScopes = pVM->pGlobalScopes;
	if (pVM->pGlobalScopes->pItemsArray == NULL) {
		ring_list_genarray(pVM->pGlobalScopes);
	}
	for (x = 1; x <= ring_list_getsize(pVM->pGlobalScopes); x++) {
		pScope = ring_list_getlist(pVM->pGlobalScopes, x);
		if (pScope->pItemsArray == NULL) {
			ring_list_genarray(pScope);
		}
	}
	/*
	**  Get Items for the Memory Pool From the Main Thread
	**  The next function call avoid deleting the Shared Memory Blocks
	**  By setting vPoolManager.lDeleteMemory to zero (false)
	*/
	ring_poolmanager_newblockfromsubthread(pState, RING_VM_ITEMSFORNEWTHREAD, pVM->pRingState);
	/* Share Memory Blocks (Could be used for Lists in Global Scope) */
	ring_list_delete(pState->vPoolManager.pBlocks);
	pState->vPoolManager.pBlocks = pVM->pRingState->vPoolManager.pBlocks;
	/*
	**  Share the code between the VMs
	**  Copy Functions/Classes/Packages lists
	*/
	ring_list_copy(pState->pVM->pFunctionsMap, pVM->pRingState->pRingFunctionsMap);
	ring_list_copy(pState->pVM->pClassesMap, pVM->pRingState->pRingClassesMap);
	ring_list_copy(pState->pVM->pPackagesMap, pVM->pRingState->pRingPackagesMap);
	pState->pVM->pCFunction = pVM->pCFunction;
	/* Get a copy from the Byte Code */
	ring_vm_bytecodefornewthread(pState->pVM, pVM);
	/* Avoid the call to the main function */
	pState->pVM->lCallMainFunction = RING_TRUE;
	/* Unlock */
	ring_vm_mutexunlock(pVM);
	ring_vm_custmutexunlock(pVM, pVM->pRingState->vPoolManager.pMutex);
	ring_vm_custmutexunlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_FUNCHASHTABLE]);
	ring_vm_custmutexunlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_VARHASHTABLE]);
	return pState;
}

RING_API void ring_vm_deletethreadstate(VM *pVM, RingState *pState) {
	CFunction *pCFunc;
	unsigned int x;
	/* Lock */
	ring_vm_mutexlock(pVM);
	/* Return Memory Pool Items to the Main Thread */
	ring_poolmanager_deleteblockfromsubthread(pState, pVM->pRingState);
	/* Restore other global scopes */
	pState->pVM->pGlobalScopes = ring_list_new(RING_ZERO);
	/* Avoid deleting the shared lists and the Mutex */
	pState->pVM->pFuncMutexCreate = NULL;
	pState->pVM->pFuncMutexDestroy = NULL;
	pState->pVM->pFuncMutexLock = NULL;
	pState->pVM->pFuncMutexUnlock = NULL;
	pState->pVM->pMutex = NULL;
	pState->vPoolManager.pMutex = NULL;
	for (x = 0; x < RING_VM_CUSTOMMUTEX_COUNT; x++) {
		pState->pVM->aCustomMutex[x] = NULL;
	}
	if (pState->pVM->pCFunction != NULL) {
		/* Delete Extra C Functions (Loaded by the Sub Thread) */
		while (pState->pVM->pCFunction != pVM->pCFunction) {
			pCFunc = pState->pVM->pCFunction;
			pState->pVM->pCFunction = pState->pVM->pCFunction->pNext;
			ring_state_free(NULL, pCFunc);
		}
		/* Avoid deleting C functions loaded by the Main thread */
		pState->pVM->pCFunction = NULL;
	}
	/* Delete the RingState */
	ring_state_delete(pState);
	/* Unlock */
	ring_vm_mutexunlock(pVM);
}

RING_API void ring_vm_bytecodefornewthread(VM *pVM, VM *pOldVM) {
	unsigned int x, y, nSize, nType;
	ByteCode *pByteCode;
	char *pString;
	/* Get the Instructions Count */
	pVM->pRingState->nInstructionsCount = pOldVM->pRingState->nInstructionsCount;
	/* Allocate memory for the Byte Code */
	nSize = pOldVM->nEvalReallocationSize;
	pVM->pByteCode = (ByteCode *)ring_calloc(nSize, sizeof(ByteCode));
	pVM->nEvalReallocationSize = nSize;
	/* Copy the Byte Code */
	memcpy(pVM->pByteCode, pOldVM->pByteCode, nSize * sizeof(ByteCode));
	/* Create new strings */
	for (x = 1; x <= RING_VM_INSTRUCTIONSCOUNT; x++) {
		pByteCode = pVM->pByteCode + x - 1;
		for (y = 0; y < RING_VM_BC_ITEMS_COUNT; y++) {
			/* Get The Register Type */
			if (y == 0) {
				nType = pByteCode->nReg1Type;
			} else if (y == 1) {
				nType = pByteCode->nReg2Type;
			}
			/* Create new string */
			if (nType == RING_VM_REGTYPE_STRING) {
				pString = ring_string_strdup(pByteCode->aReg[y].pString);
				pByteCode->aReg[y].pString = pString;
			}
		}
	}
}
