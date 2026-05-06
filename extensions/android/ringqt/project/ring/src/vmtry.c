/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_try(VM *pVM) {
	List *pList;
	pList = ring_list_newlist_gc(pVM->pRingState, pVM->pTry);
	ring_list_addint_gc(pVM->pRingState, pList, RING_VM_IR_READI);
	ring_list_addint_gc(pVM->pRingState, pList, pVM->nInsideEval);
	ring_vm_savestate(pVM, pList);
	pVM->lActiveCatch = RING_FALSE;
}

void ring_vm_catch(VM *pVM, const char *cError) {
	List *pList;
	pList = ring_list_getlist(pVM->pTry, ring_list_getsize(pVM->pTry));
	pVM->nPC = ring_list_getint(pList, RING_TRY_PC);
	pVM->nInsideEval = ring_list_getint(pList, RING_TRY_INSIDEEVAL);
	/* Set the cCatchError variable to contain the error message */
	RING_VAR_SETSTRING_GC(pVM->pRingState, pVM->pErrorMsg, cError);
	/* Avoid invalidated cError (variable) content by restore */
	ring_vm_restorestate(pVM, pList, RING_TRY_STATE, RING_STATE_TRYCATCH);
	/* Tell C-API caller (CALL command) that catch happens! */
	pVM->lActiveCatch = RING_TRUE;
	/* Catch Statements must be executed without try effects */
	ring_vm_done(pVM);
}

void ring_vm_done(VM *pVM) { ring_list_deleteitem_gc(pVM->pRingState, pVM->pTry, ring_list_getsize(pVM->pTry)); }
