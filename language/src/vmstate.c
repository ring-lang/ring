/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_savestate(VM *pVM, List *pList) {
	List *pThis;
	VMState *pVMState;
	/* Using VMState */
	pVMState = ring_vmstate_new(pVM->pRingState);
	/* Save the state as Managed C Pointer */
	ring_list_addcustomringpointer_gc(pVM->pRingState, pList, pVMState, ring_vmstate_delete);
	pThis = ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_THIS);
	/* Save the data */
	pVMState->aNumbers[0] = RING_VM_SCOPESCOUNT;
	pVMState->aNumbers[1] = RING_VM_FUNCCALLSCOUNT;
	pVMState->aNumbers[2] = ring_list_getsize(pVM->pNestedLists);
	pVMState->aNumbers[3] = pVM->nSP;
	pVMState->aNumbers[4] = pVM->nFuncSP;
	pVMState->aNumbers[5] = ring_list_getsize(pVM->pObjState);
	pVMState->aNumbers[6] = ring_list_getsize(pVM->pBraceObjects);
	pVMState->aNumbers[7] = ring_list_getsize(pVM->pPCBlockFlag);
	pVMState->aNumbers[8] = pVM->nBlockCounter;
	pVMState->aNumbers[9] = ring_list_getsize(pVM->pScopeNewObj);
	pVMState->aNumbers[10] = ring_list_getsize(pVM->pActivePackage);
	pVMState->aNumbers[11] = pVM->nNoSetterMethod;
	pVMState->aNumbers[12] = pVM->nActiveScopeID;
	pVMState->aNumbers[13] = ring_list_getsize(pVM->pExitMark);
	pVMState->aNumbers[14] = ring_list_getsize(pVM->pLoopMark);
	pVMState->aNumbers[15] = ring_list_getsize(pVM->pTry);
	pVMState->aNumbers[16] = pVM->nListStart;
	pVMState->aNumbers[17] = pVM->lInsideBraceFlag;
	pVMState->aNumbers[18] = ring_list_getsize(pVM->pForStep);
	pVMState->aNumbers[19] = ring_list_getsize(pVM->pBeforeObjState);
	pVMState->aNumbers[20] = RING_VM_IR_GETLINENUMBER;
	pVMState->aNumbers[21] = pVM->nInClassRegion;
	pVMState->aNumbers[22] = pVM->lPrivateFlag;
	pVMState->aNumbers[23] = pVM->lGetSetProperty;
	pVMState->aNumbers[24] = pVM->nGetSetObjType;
	pVMState->aNumbers[25] = pVM->nBeforeEqual;
	pVMState->aNumbers[26] = pVM->lNoAssignment;
	pVMState->aNumbers[27] = pVM->nCurrentGlobalScope;
	pVMState->aNumbers[28] = pVM->nCallClassInit;
	pVMState->aNumbers[29] = ring_list_getint(pThis, RING_VAR_PVALUETYPE);
	pVMState->aPointers[0] = pVM->pBraceObject;
	pVMState->aPointers[1] = (void *)pVM->cFileName;
	pVMState->aPointers[2] = pVM->pActiveMem;
	pVMState->aPointers[4] = pVM->pPCBlockFlag;
	pVMState->aPointers[5] = pVM->pGetSetObject;
	pVMState->aPointers[6] = pVM->pAssignment;
	pVMState->aPointers[7] = ring_list_getpointer(pThis, RING_VAR_VALUE);
}

void ring_vm_restorestate(VM *pVM, List *pList, unsigned int nPos, unsigned int nFlag) {
	List *pThis;
	VMState *pVMState, *pVMStateForFunc, *pVMStateForObj;
	unsigned int x;
	List *aListsToDelete, *pListPointer;
	FuncCall *pFuncCall;
	/* Using VMState */
	pVMState = (VMState *)ring_list_getpointer(pList, nPos);
	/*
	**  Set Scope
	**  Delete Scopes using the correct function
	**  We need to delete each scope using ring_vm_deletescope() - so don't use ring_vm_backstate
	**  We also avoid doing this in the Class Region (After class name)
	**  Because in the class region we don't use the Scopes List
	*/
	pVM->nInClassRegion = pVMState->aNumbers[21];
	if (!pVM->nInClassRegion) {
		/*
		**  In the loop condition we use pVMState->aPointers[2] instead of pVM->pActiveMem
		**  Because ring_vm_deletescope() update the pVM->pActiveMem value
		*/
		RING_VM_BACKTOSCOPELIST((List *)pVMState->aPointers[2]);
	}
	pVM->pActiveMem = (List *)pVMState->aPointers[2];
	/* Stack & Executing Functions */
	pVM->nSP = pVMState->aNumbers[3];
	pVM->nFuncSP = pVMState->aNumbers[4];
	/* We also return to the Active Object */
	ring_vm_backstate(pVM, pVM->pObjState, pVMState->aNumbers[5]);
	ring_vm_backstate(pVM, pVM->pBraceObjects, pVMState->aNumbers[6]);
	pVM->pBraceObject = (List *)pVMState->aPointers[0];
	/* FileName & Packages */
	pVM->cFileName = (const char *)pVMState->aPointers[1];
	/* Create aListsToDelete */
	aListsToDelete = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* pPCBlockFlag, pScopeNewObj , pActivePackage */
	if (((List *)pVMState->aPointers[4]) != pVM->pPCBlockFlag) {
		ring_list_addpointer_gc(pVM->pRingState, aListsToDelete, pVM->pPCBlockFlag);
		pVM->pPCBlockFlag = (List *)pVMState->aPointers[4];
	}
	ring_vm_backstate(pVM, pVM->pPCBlockFlag, pVMState->aNumbers[7]);
	pVM->nBlockCounter = pVMState->aNumbers[8];
	ring_vm_backstate(pVM, pVM->pActivePackage, pVMState->aNumbers[10]);
	pVM->nNoSetterMethod = pVMState->aNumbers[11];
	pVM->nActiveScopeID = pVMState->aNumbers[12];
	/* We also return to the function call list */
	if (nFlag == RING_STATE_TRYCATCH) {
		/*
		**  Since Try/Catch can terminate many functions when error happens
		**  We need to clean memory and remove pNestedLists, pPCBlockFlag & pSetProperty
		**  Clean memory used for function calls
		*/
		for (x = pVMState->aNumbers[1] + 1; x <= RING_VM_FUNCCALLSCOUNT; x++) {
			pFuncCall = RING_VM_GETFUNCCALL(x);
			ring_vm_gc_removelistprotection(pVM, pVM->pNestedLists, pFuncCall->nNestedLists + 1);
			ring_vm_backstate(pVM, pVM->pNestedLists, pFuncCall->nNestedLists);
			if (pFuncCall->pVMState != NULL) {
				pVMStateForFunc = pFuncCall->pVMState;
				/* Delete pPCBlockFlag */
				pListPointer = (List *)pVMStateForFunc->aPointers[2];
				if (pListPointer != pVM->pPCBlockFlag) {
					if (!ring_list_findpointer_gc(pVM->pRingState, aListsToDelete, pListPointer)) {
						ring_list_addpointer_gc(pVM->pRingState, aListsToDelete, pListPointer);
					}
				}
				/* Delete pSetProperty */
				pListPointer = (List *)pVMStateForFunc->aPointers[6];
				if (!ring_list_findpointer_gc(pVM->pRingState, aListsToDelete, pListPointer)) {
					ring_list_addpointer_gc(pVM->pRingState, aListsToDelete, pListPointer);
				}
			}
		}
		/*
		**  Clean memory used for new objects (class region)
		**  If we have error in the class region while try catch is used outside it
		**  Then we clean the memory used by the new object
		**  Like pNestedLists, aPCBlocFlag & pSetProperty
		*/
		for (x = pVMState->aNumbers[9] + 1; x <= ring_list_getsize(pVM->pScopeNewObj); x++) {
			pVMStateForObj = (VMState *)ring_list_getpointer(pVM->pScopeNewObj, x);
			ring_vm_gc_removelistprotection(pVM, pVM->pNestedLists, pVMStateForObj->aNumbers[28] + 1);
			ring_vm_backstate(pVM, pVM->pNestedLists, pVMStateForObj->aNumbers[28]);
			/* Delete pPCBlockFlag */
			pListPointer = (List *)pVMStateForObj->aPointers[7];
			if (pListPointer != pVM->pPCBlockFlag) {
				if (!ring_list_findpointer_gc(pVM->pRingState, aListsToDelete, pListPointer)) {
					ring_list_addpointer_gc(pVM->pRingState, aListsToDelete, pListPointer);
				}
			}
			/* Delete pSetProperty */
			pListPointer = (List *)pVMStateForObj->aPointers[8];
			if (!ring_list_findpointer_gc(pVM->pRingState, aListsToDelete, pListPointer)) {
				ring_list_addpointer_gc(pVM->pRingState, aListsToDelete, pListPointer);
			}
		}
	}
	ring_vm_backstate(pVM, pVM->pScopeNewObj, pVMState->aNumbers[9]);
	RING_VM_BACKTOFUNCCALL(pVMState->aNumbers[1]);
	/* Loop/Exit Mark */
	if (nFlag != RING_STATE_EXIT) {
		ring_vm_backstate(pVM, pVM->pExitMark, pVMState->aNumbers[13]);
		ring_vm_backstate(pVM, pVM->pLoopMark, pVMState->aNumbers[14]);
		/* For Step */
		ring_vm_backstate(pVM, pVM->pForStep, pVMState->aNumbers[18]);
	}
	/* Try/Catch/Done */
	if (nFlag != RING_STATE_TRYCATCH) {
		ring_vm_backstate(pVM, pVM->pTry, pVMState->aNumbers[15]);
	}
	ring_vm_gc_removelistprotection(pVM, pVM->pNestedLists, pVMState->aNumbers[2] + 1);
	ring_vm_backstate(pVM, pVM->pNestedLists, pVMState->aNumbers[2]);
	pVM->nListStart = pVMState->aNumbers[16];
	pVM->lInsideBraceFlag = pVMState->aNumbers[17];
	ring_vm_backstate(pVM, pVM->pBeforeObjState, pVMState->aNumbers[19]);
	RING_VM_IR_SETLINENUMBER(pVMState->aNumbers[20]);
	pVM->lPrivateFlag = pVMState->aNumbers[22];
	pVM->lGetSetProperty = pVMState->aNumbers[23];
	pVM->pGetSetObject = (void *)pVMState->aPointers[5];
	pVM->nGetSetObjType = pVMState->aNumbers[24];
	pVM->pAssignment = (void *)pVMState->aPointers[6];
	pVM->nBeforeEqual = pVMState->aNumbers[25];
	pVM->lNoAssignment = pVMState->aNumbers[26];
	/* We restore the global scope before the This variable, because This use global scope */
	pVM->nCurrentGlobalScope = pVMState->aNumbers[27];
	pVM->nCallClassInit = pVMState->aNumbers[28];
	/* Restore This variable */
	pThis = ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_THIS);
	ring_list_setpointer_gc(pVM->pRingState, pThis, RING_VAR_VALUE, pVMState->aPointers[7]);
	ring_list_setint_gc(pVM->pRingState, pThis, RING_VAR_PVALUETYPE, pVMState->aNumbers[29]);
	/* Process aListsToDelete */
	for (x = 1; x <= ring_list_getsize(aListsToDelete); x++) {
		pListPointer = (List *)ring_list_getpointer(aListsToDelete, x);
		ring_list_delete_gc(pVM->pRingState, pListPointer);
	}
	ring_list_delete_gc(pVM->pRingState, aListsToDelete);
}

VMState *ring_vm_savestateformethods(VM *pVM) {
	List *pThis;
	VMState *pVMState;
	/* Using VMState */
	pVMState = ring_vmstate_new(pVM->pRingState);
	pThis = ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_THIS);
	/* Save the Data */
	pVMState->aNumbers[0] = pVM->lNoAssignment;
	pVMState->aNumbers[1] = pVM->lGetSetProperty;
	pVMState->aNumbers[2] = ring_list_getsize(pVM->pTry);
	pVMState->aNumbers[3] = ring_list_getsize(pVM->pBraceObjects);
	pVMState->aNumbers[4] = ring_list_getsize(pVM->pObjState);
	pVMState->aNumbers[5] = pVM->lInsideBraceFlag;
	pVMState->aNumbers[6] = pVM->nGetSetObjType;
	pVMState->aNumbers[7] = pVM->nCurrentGlobalScope;
	pVMState->aNumbers[8] = pVM->nBlockCounter;
	pVMState->aNumbers[9] = pVM->lPrivateFlag;
	pVMState->aNumbers[10] = pVM->nCallClassInit;
	pVMState->aNumbers[11] = ring_list_getint(pThis, RING_VAR_PVALUETYPE);
	pVMState->aNumbers[12] = pVM->nInClassRegion;
	pVMState->aNumbers[13] = pVM->nActiveScopeID;
	pVMState->aNumbers[14] = ring_list_getsize(pVM->pScopeNewObj);
	pVMState->aNumbers[15] = pVM->nNoSetterMethod;
	pVMState->aNumbers[16] = pVM->nBeforeEqual;
	pVMState->aPointers[0] = pVM->pBraceObject;
	pVMState->aPointers[1] = pVM->pActiveMem;
	pVMState->aPointers[2] = pVM->pPCBlockFlag;
	pVMState->aPointers[3] = pVM->pAssignment;
	pVMState->aPointers[4] = pVM->pGetSetObject;
	pVMState->aPointers[5] = ring_list_getpointer(pThis, RING_VAR_VALUE);
	pVMState->aPointers[6] = pVM->pSetProperty;
	pVM->pSetProperty = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Save State */
	pVM->lInsideBraceFlag = 0;
	/* Save BlockFlag */
	pVM->nBlockCounter = 0;
	pVM->pPCBlockFlag = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Save lPrivateFlag, set it to 0 (public not private) */
	pVM->lPrivateFlag = 0;
	/* Save nCallClassInit */
	pVM->nCallClassInit = 0;
	pVM->nInClassRegion = 0;
	pVM->pAssignment = NULL;
	pVM->lNoAssignment = 0;
	pVM->pBraceObject = NULL;
	pVM->nBeforeEqual = OP_EQUAL;
	pVM->lGetSetProperty = 0;
	pVM->pGetSetObject = NULL;
	pVM->nGetSetObjType = 0;
	pVM->nNoSetterMethod = RING_NOSETTERMETHOD_DEFAULT;
	return pVMState;
}

void ring_vm_restorestateformethods(VM *pVM, VMState *pVMState) {
	List *pThis;
	/* Restore State */
	pVM->lNoAssignment = pVMState->aNumbers[0];
	pVM->lGetSetProperty = pVMState->aNumbers[1];
	ring_vm_backstate(pVM, pVM->pTry, pVMState->aNumbers[2]);
	ring_vm_backstate(pVM, pVM->pBraceObjects, pVMState->aNumbers[3]);
	pVM->pBraceObject = (List *)pVMState->aPointers[0];
	ring_vm_backstate(pVM, pVM->pObjState, pVMState->aNumbers[4]);
	pVM->lInsideBraceFlag = pVMState->aNumbers[5];
	pVM->nGetSetObjType = pVMState->aNumbers[6];
	/* Restore global scope, Must be before this because this depend on it */
	pVM->nCurrentGlobalScope = pVMState->aNumbers[7];
	pVM->pActiveMem = (List *)pVMState->aPointers[1];
	/* Restore BlockFLag */
	pVM->pPCBlockFlag = ring_list_delete_gc(pVM->pRingState, pVM->pPCBlockFlag);
	pVM->nBlockCounter = pVMState->aNumbers[8];
	pVM->pPCBlockFlag = (List *)pVMState->aPointers[2];
	/* Restore lPrivateFlag */
	pVM->lPrivateFlag = pVMState->aNumbers[9];
	/* Restore nCallClassInit */
	pVM->nCallClassInit = pVMState->aNumbers[10];
	pVM->pAssignment = (void *)pVMState->aPointers[3];
	pVM->nInClassRegion = pVMState->aNumbers[12];
	pVM->nActiveScopeID = pVMState->aNumbers[13];
	ring_vm_backstate(pVM, pVM->pScopeNewObj, pVMState->aNumbers[14]);
	pVM->nBeforeEqual = pVMState->aNumbers[16];
	pVM->nNoSetterMethod = pVMState->aNumbers[15];
	pVM->pGetSetObject = (void *)pVMState->aPointers[4];
	/* Restore This variable */
	pThis = ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_THIS);
	ring_list_setpointer_gc(pVM->pRingState, pThis, RING_VAR_VALUE, pVMState->aPointers[5]);
	ring_list_setint_gc(pVM->pRingState, pThis, RING_VAR_PVALUETYPE, pVMState->aNumbers[11]);
	/* Restore pSetProperty */
	pVM->pSetProperty = ring_list_delete_gc(pVM->pRingState, pVM->pSetProperty);
	pVM->pSetProperty = (List *)pVMState->aPointers[6];
}

void ring_vm_savestatefornewobjects(VM *pVM) {
	List *pThis;
	VMState *pVMState;
	/* Using VMState */
	pVMState = ring_vmstate_new(pVM->pRingState);
	/* Save the state as Managed C Pointer */
	ring_list_addcustomringpointer_gc(pVM->pRingState, pVM->pScopeNewObj, pVMState, ring_vmstate_delete);
	/*
	**  Save the Data
	**  Save the Active Memory
	*/
	pVMState->aPointers[0] = pVM->pActiveMem;
	/* Store List information to allow calling function from list item and creating lists from that funct */
	pVMState->aNumbers[0] = pVM->nListStart;
	pVMState->aNumbers[1] = ring_list_getsize(pVM->pNestedLists);
	ring_vm_newnestedlists(pVM);
	/* Save Stack Information */
	pVMState->aNumbers[2] = pVM->nSP;
	/* Save Private Flag Status */
	pVMState->aNumbers[3] = pVM->lPrivateFlag;
	/* Save InsideBrace Flag */
	pVMState->aNumbers[4] = pVM->lInsideBraceFlag;
	pVM->lInsideBraceFlag = 0;
	pVMState->aPointers[2] = pVM->pBraceObject;
	pVM->pBraceObject = NULL;
	/* Save nCallClassInit */
	pVMState->aNumbers[5] = pVM->nCallClassInit;
	pVM->nCallClassInit = 0;
	/* Save Line Number */
	pVMState->aNumbers[6] = RING_VM_IR_GETLINENUMBER;
	/* Save Function Stack */
	pVMState->aNumbers[7] = pVM->nFuncSP;
	/* Save Assignment Pointer */
	pVMState->aPointers[3] = pVM->pAssignment;
	pVM->pAssignment = NULL;
	/* Save the Object Pointer and Type */
	pVMState->aPointers[4] = RING_VM_STACK_READP;
	pVMState->aNumbers[8] = RING_VM_STACK_OBJTYPE;
	/* Save Current Global Scope */
	pVMState->aNumbers[9] = pVM->nCurrentGlobalScope;
	/* Save the This object */
	pThis = ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_THIS);
	pVMState->aPointers[5] = ring_list_getpointer(pThis, RING_VAR_VALUE);
	pVMState->aNumbers[10] = ring_list_getint(pThis, RING_VAR_PVALUETYPE);
	/* Save pObjState */
	pVMState->aNumbers[11] = ring_list_getsize(pVM->pObjState);
	/* Save lNoAssignment */
	pVMState->aNumbers[12] = pVM->lNoAssignment;
	pVM->lNoAssignment = 0;
	/* Save ExitMark */
	pVMState->aNumbers[13] = ring_list_getsize(pVM->pExitMark);
	/* Save LoopMark */
	pVMState->aNumbers[14] = ring_list_getsize(pVM->pLoopMark);
	/* Save pTry */
	pVMState->aNumbers[15] = ring_list_getsize(pVM->pTry);
	/* Save pBraceObjects */
	pVMState->aNumbers[16] = ring_list_getsize(pVM->pBraceObjects);
	/* Save pForStep */
	pVMState->aNumbers[17] = ring_list_getsize(pVM->pForStep);
	/* Save nActiveScopeID */
	pVMState->aNumbers[18] = pVM->nActiveScopeID;
	/* Save nBeforeEqual */
	pVMState->aNumbers[19] = pVM->nBeforeEqual;
	pVM->nBeforeEqual = OP_EQUAL;
	/* Save lGetSetProperty */
	pVMState->aNumbers[20] = pVM->lGetSetProperty;
	pVM->lGetSetProperty = 0;
	/* Save nGetSetObject */
	pVMState->aNumbers[21] = pVM->nGetSetObjType;
	pVM->nGetSetObjType = 0;
	/* Save pGetSetObject */
	pVMState->aPointers[6] = pVM->pGetSetObject;
	pVM->pGetSetObject = NULL;
	/* Save pFuncClassList */
	pVMState->aNumbers[22] = RING_VM_FUNCCALLSCOUNT;
	/* Save nNoSetterMethod */
	pVMState->aNumbers[23] = pVM->nNoSetterMethod;
	pVM->nNoSetterMethod = RING_NOSETTERMETHOD_DEFAULT;
	/* Save the BlockFlag */
	pVMState->aNumbers[24] = pVM->nBlockCounter;
	pVMState->aPointers[7] = pVM->pPCBlockFlag;
	pVM->nBlockCounter = 0;
	pVM->pPCBlockFlag = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Save pActivePackage */
	pVMState->aNumbers[25] = ring_list_getsize(pVM->pActivePackage);
	/* Save nInClassRegion */
	pVMState->aNumbers[26] = pVM->nInClassRegion;
	pVM->nInClassRegion = 0;
	/* Save pBeforeObjState */
	pVMState->aNumbers[27] = ring_list_getsize(pVM->pBeforeObjState);
	/* Save pSetProperty */
	pVMState->aPointers[8] = pVM->pSetProperty;
	pVM->pSetProperty = ring_list_new_gc(pVM->pRingState, RING_ZERO);
}

void ring_vm_restorestatefornewobjects(VM *pVM) {
	List *pThis;
	VMState *pVMState;
	/* Using VMState */
	pVMState = (VMState *)ring_list_getpointer(pVM->pScopeNewObj, ring_list_getsize(pVM->pScopeNewObj));
	/*
	**  Restore State
	**  Restore the scope (before creating the object using new)
	*/
	pVM->pActiveMem = (List *)pVMState->aPointers[0];
	/* Restore List Status */
	ring_vm_restorenestedlists(pVM, pVMState->aNumbers[0], pVMState->aNumbers[1]);
	/* Restore Stack Information */
	pVM->nSP = pVMState->aNumbers[2];
	/* Restore Private Flag */
	pVM->lPrivateFlag = pVMState->aNumbers[3];
	/* Restore InsideBrace Flag */
	pVM->lInsideBraceFlag = pVMState->aNumbers[4];
	pVM->pBraceObject = (List *)pVMState->aPointers[2];
	/* Restore nCallClassInit */
	pVM->nCallClassInit = pVMState->aNumbers[5];
	/* Restore nLineNumber */
	RING_VM_IR_SETLINENUMBER(pVMState->aNumbers[6]);
	/* Restore Function Stack */
	pVM->nFuncSP = pVMState->aNumbers[7];
	/* Restore Assignment Pointer */
	pVM->pAssignment = (List *)pVMState->aPointers[3];
	/* Restore the Object Pointer and The Object Type */
	RING_VM_STACK_SETPVALUE(pVMState->aPointers[4]);
	RING_VM_STACK_OBJTYPE = pVMState->aNumbers[8];
	/* Restore current Global Scope */
	pVM->nCurrentGlobalScope = pVMState->aNumbers[9];
	/* Restore the This object */
	pThis = ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_THIS);
	ring_list_setpointer_gc(pVM->pRingState, pThis, RING_VAR_VALUE, pVMState->aPointers[5]);
	ring_list_setint_gc(pVM->pRingState, pThis, RING_VAR_PVALUETYPE, pVMState->aNumbers[10]);
	/* Restore pObjState */
	ring_vm_backstate(pVM, pVM->pObjState, pVMState->aNumbers[11]);
	/* Restore lNoAssignment */
	pVM->lNoAssignment = pVMState->aNumbers[12];
	/* Restore ExitMark */
	ring_vm_backstate(pVM, pVM->pExitMark, pVMState->aNumbers[13]);
	/* Restore LoopMark */
	ring_vm_backstate(pVM, pVM->pLoopMark, pVMState->aNumbers[14]);
	/* Restore pTry */
	ring_vm_backstate(pVM, pVM->pTry, pVMState->aNumbers[15]);
	/* Restore pBraceObjects */
	ring_vm_backstate(pVM, pVM->pBraceObjects, pVMState->aNumbers[16]);
	/* Restore pForStep */
	ring_vm_backstate(pVM, pVM->pForStep, pVMState->aNumbers[17]);
	/* Restore nActiveScopeID */
	pVM->nActiveScopeID = pVMState->aNumbers[18];
	/* Restore nBeforeEqual */
	pVM->nBeforeEqual = pVMState->aNumbers[19];
	/* Restore lGetSetProperty */
	pVM->lGetSetProperty = pVMState->aNumbers[20];
	/* Restore nGetSetObjType */
	pVM->nGetSetObjType = pVMState->aNumbers[21];
	/* Restore pGetSetObject */
	pVM->pGetSetObject = (List *)pVMState->aPointers[6];
	/* Restore Function Call List */
	RING_VM_BACKTOFUNCCALL(pVMState->aNumbers[22]);
	/* Restore nNoSetterMethod */
	pVM->nNoSetterMethod = pVMState->aNumbers[23];
	/* Restore the BlockFlag */
	pVM->nBlockCounter = pVMState->aNumbers[24];
	pVM->pPCBlockFlag = ring_list_delete_gc(pVM->pRingState, pVM->pPCBlockFlag);
	pVM->pPCBlockFlag = (List *)pVMState->aPointers[7];
	/* Restore pActivePackage */
	ring_vm_backstate(pVM, pVM->pActivePackage, pVMState->aNumbers[25]);
	/* Restore nInClassRegion */
	pVM->nInClassRegion = pVMState->aNumbers[26];
	/* Restore pBeforeObjState */
	ring_vm_backstate(pVM, pVM->pBeforeObjState, pVMState->aNumbers[27]);
	/* Restore pSetProperty */
	pVM->pSetProperty = ring_list_delete_gc(pVM->pRingState, pVM->pSetProperty);
	pVM->pSetProperty = (List *)pVMState->aPointers[8];
	ring_list_deleteitem_gc(pVM->pRingState, pVM->pScopeNewObj, ring_list_getsize(pVM->pScopeNewObj));
}

unsigned int ring_vm_newobjectstackpointer(VM *pVM) {
	VMState *pVMState;
	pVMState = (VMState *)ring_list_getpointer(pVM->pScopeNewObj, ring_list_getsize(pVM->pScopeNewObj));
	return pVMState->aNumbers[RING_SCOPENEWOBJ_SP];
}

void ring_vm_savestateforbraces(VM *pVM, List *pObjState) {
	List *pList, *pClass, *pSetProperty;
	/*
	**  Prepare to Access Object State
	**  Store Pointer to Object State
	*/
	ring_list_addpointer_gc(pVM->pRingState, pObjState,
				ring_list_getlist(pVM->pBraceObject, RING_OBJECT_OBJECTDATA));
	/* Store Object Class Methods */
	pClass = (List *)ring_list_getpointer(pVM->pBraceObject, RING_OBJECT_CLASSPOINTER);
	ring_list_addpointer_gc(pVM->pRingState, pObjState, ring_list_getlist(pClass, RING_CLASSMAP_METHODSLIST));
	/* Store Class Pointer */
	ring_list_addpointer_gc(pVM->pRingState, pObjState, pClass);
	/* Add Brace Object & Stack Pointer to List */
	pList = ring_list_newlist_gc(pVM->pRingState, pVM->pBraceObjects);
	ring_list_addpointer_gc(pVM->pRingState, pList, pVM->pBraceObject);
	ring_list_addint_gc(pVM->pRingState, pList, pVM->nSP);
	/* Store List information to allow using braces from list item and creating lists from that brace */
	ring_list_addint_gc(pVM->pRingState, pList, pVM->nListStart);
	ring_list_addint_gc(pVM->pRingState, pList, ring_list_getsize(pVM->pNestedLists));
	ring_vm_newnestedlists(pVM);
	/* Store GetSet Object */
	pSetProperty = ring_list_newlist_gc(pVM->pRingState, pList);
	ring_list_copy_gc(pVM->pRingState, pSetProperty, pVM->pSetProperty);
	ring_list_deleteallitems_gc(pVM->pRingState, pVM->pSetProperty);
	/* Store nLoadAddressScope */
	ring_list_addint_gc(pVM->pRingState, pList, pVM->nLoadAddressScope);
	/* Store nNoSetterMethod */
	ring_list_addint_gc(pVM->pRingState, pList, pVM->nNoSetterMethod);
	/* Store DontRef Info */
	ring_list_addint_gc(pVM->pRingState, pList, ring_list_isdontref_gc(pVM->pRingState, pVM->pBraceObject));
	ring_list_addint_gc(pVM->pRingState, pList, ring_list_isdontrefagain_gc(pVM->pRingState, pVM->pBraceObject));
	pVM->pBraceObject = NULL;
	pVM->lInsideBraceFlag = 1;
}

void ring_vm_restorestateforbraces(VM *pVM, List *pList) {
	List *pObject;
	int lDontRef, lDontRefAgain;
	/* Restore List Status */
	ring_vm_restorenestedlists(pVM, ring_list_getint(pList, RING_BRACEOBJECTS_NLISTSTART),
				   ring_list_getint(pList, RING_BRACEOBJECTS_NNESTEDLISTS));
	/* Restore Stack Status */
	pVM->nSP = ring_list_getint(pList, RING_BRACEOBJECTS_NSP);
	/* Restore GetSet Object */
	ring_list_deleteallitems_gc(pVM->pRingState, pVM->pSetProperty);
	ring_list_copy_gc(pVM->pRingState, pVM->pSetProperty,
			  (List *)ring_list_getpointer(pList, RING_BRACEOBJECTS_SETPROPERTY));
	/* Restore nLoadAddressScope */
	pVM->nLoadAddressScope = ring_list_getint(pList, RING_BRACEOBJECTS_NLOADASCOPE);
	/* Restore nNoSetterMethod */
	pVM->nNoSetterMethod = ring_list_getint(pList, RING_BRACEOBJECTS_NNOSETTERMETHOD);
	/* Restore DontRef Info */
	pObject = (List *)ring_list_getpointer(pList, RING_BRACEOBJECTS_BRACEOBJECT);
	lDontRef = ring_list_getint(pList, RING_BRACEOBJECTS_ISDONTREF);
	lDontRefAgain = ring_list_getint(pList, RING_BRACEOBJECTS_ISDONTREFAGAIN);
	if (lDontRef) {
		ring_list_enabledontref_gc(pVM->pRingState, pObject);
	}
	if (lDontRefAgain) {
		ring_list_enabledontrefagain_gc(pVM->pRingState, pObject);
	}
	ring_list_deleteitem_gc(pVM->pRingState, pVM->pBraceObjects, ring_list_getsize(pVM->pBraceObjects));
	ring_list_deleteitem_gc(pVM->pRingState, pVM->pObjState, ring_list_getsize(pVM->pObjState));
	pVM->lInsideBraceFlag = (ring_list_getsize(pVM->pBraceObjects) > 0);
}

void ring_vm_backstate(VM *pVM, List *pList, unsigned int nToSize) {
	while (ring_list_getsize(pList) > nToSize) {
		ring_list_deleteitem_gc(pVM->pRingState, pList, ring_list_getsize(pList));
	}
}

List *ring_vm_savestack(VM *pVM) {
	int nSP;
	List *pList;
	Item *pItem;
	nSP = pVM->nSP;
	/* Create List */
	pList = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	while (pVM->nSP != RING_ZERO) {
		if (RING_VM_STACK_ISSTRING) {
			ring_list_addstring2_gc(pVM->pRingState, pList, RING_VM_STACK_READC, RING_VM_STACK_STRINGSIZE);
		} else if (RING_VM_STACK_ISNUMBER) {
			ring_list_adddouble_gc(pVM->pRingState, pList, RING_VM_STACK_READN);
		} else if (RING_VM_STACK_ISPOINTER) {
			ring_list_addpointer_gc(pVM->pRingState, pList, RING_VM_STACK_READP);
			pItem = ring_list_getitem_gc(pVM->pRingState, pList, ring_list_getsize(pList));
			pItem->nObjectType = RING_VM_STACK_OBJTYPE;
			pItem->lAssignment = RING_VM_STACK_ASSIGNMENTFLAG;
		}
		RING_VM_STACK_POP;
	}
	pVM->nSP = nSP;
	return pList;
}

void ring_vm_restorestack(VM *pVM, List *pList) {
	unsigned int x;
	Item *pItem;
	pVM->nSP = RING_ZERO;
	if (ring_list_getsize(pList) == RING_ZERO) {
		return;
	}
	for (x = ring_list_getsize(pList); x >= RING_ONE; x--) {
		if (ring_list_isstring(pList, x)) {
			RING_VM_STACK_PUSHCVALUE2(ring_list_getstring(pList, x), ring_list_getstringsize(pList, x));
		} else if (ring_list_isnumber(pList, x)) {
			RING_VM_STACK_PUSHNVALUE(ring_list_getdouble(pList, x));
		} else if (ring_list_ispointer(pList, x)) {
			RING_VM_STACK_PUSHPVALUE(ring_list_getpointer(pList, x));
			pItem = ring_list_getitem_gc(pVM->pRingState, pList, x);
			RING_VM_STACK_OBJTYPE = pItem->nObjectType;
			RING_VM_STACK_ASSIGNMENTFLAG = pItem->lAssignment;
		}
	}
}
