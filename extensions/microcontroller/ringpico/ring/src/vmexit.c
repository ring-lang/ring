/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_bye ( VM *pVM )
{
	/* Check if the ringvm_evalinscope() function is active */
	if ( pVM->nEvalInScope >= 1 ) {
		puts(RING_VM_ERROR_BADCOMMAND);
		return ;
	}
	pVM->nPausePC = pVM->nPC ;
	pVM->nPC = RING_VM_INSTRUCTIONSCOUNT  + 1 ;
}

void ring_vm_exitmark ( VM *pVM )
{
	List *pList  ;
	/* Exit Mark */
	pList = ring_list_newlist_gc(pVM->pRingState,pVM->pExitMark);
	ring_list_addint_gc(pVM->pRingState,pList,RING_VM_IR_READI);
	ring_vm_savestate(pVM,pList);
	/* Loop Mark */
	pList = ring_list_newlist_gc(pVM->pRingState,pVM->pLoopMark);
	ring_list_addint_gc(pVM->pRingState,pList,RING_VM_IR_READIVALUE(RING_VM_IR_REG2));
	ring_vm_savestate(pVM,pList);
}

void ring_vm_popexitmark ( VM *pVM )
{
	/* POP Exit Mark */
	ring_list_deleteitem_gc(pVM->pRingState,pVM->pExitMark,ring_list_getsize(pVM->pExitMark));
	/* POP Loop Mark */
	ring_list_deleteitem_gc(pVM->pRingState,pVM->pLoopMark,ring_list_getsize(pVM->pLoopMark));
}

void ring_vm_exit ( VM *pVM,int nType )
{
	List *pList,*pActiveList  ;
	int x,y,nStep  ;
	nStep = 0 ;
	/* Get the Number from the Stack */
	if ( RING_VM_STACK_ISNUMBER ) {
		nStep = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_LOOPNUMBEROUTSIDERANGE);
	}
	/* Set Active List */
	if ( nType == RING_COMMANDTYPE_EXIT ) {
		pActiveList = pVM->pExitMark ;
		pVM->lExitFlag = 1 ;
	}
	else {
		pActiveList = pVM->pLoopMark ;
	}
	if ( ring_list_getsize(pActiveList) > 0 ) {
		x = ring_list_getsize(pActiveList) ;
		/* Do Operation */
		if ( (nStep > 0) && (nStep <= ring_list_getsize(pActiveList) ) ) {
			/* Using commands like (loop 2) is just an implicit (exit 1) then (loop) */
			if ( (nStep > 1) && (nType == RING_COMMANDTYPE_LOOP) ) {
				nStep-- ;
				pVM->lOptionalLoop = 1 ;
				nType = RING_COMMANDTYPE_EXIT ;
				pActiveList = pVM->pExitMark ;
				pVM->lExitFlag = 1 ;
			}
			x = ring_list_getsize(pActiveList) - nStep + 1 ;
			for ( y = x + 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
				ring_list_deleteitem_gc(pVM->pRingState,pActiveList,y);
			}
		}
		else {
			if ( nType == RING_COMMANDTYPE_EXIT ) {
				ring_vm_error(pVM,RING_VM_ERROR_EXITNUMBEROUTSIDERANGE);
			}
			else {
				ring_vm_error(pVM,RING_VM_ERROR_LOOPNUMBEROUTSIDERANGE);
			}
			return ;
		}
		/*
		**  Call POP Step 
		**  If we have many nested loops with different step values 
		**  Then when we exit from more than one loop we must restore the step value too 
		*/
		if ( nStep > 1 ) {
			for ( y = 2 ; y <= nStep ; y++ ) {
				ring_vm_popstep(pVM);
			}
		}
		pList = ring_list_getlist(pActiveList,x);
		pVM->nPC = ring_list_getint(pList,RING_MARKLIST_PC) ;
		ring_vm_restorestate(pVM,pList,RING_MARKLIST_STATE,RING_STATE_EXIT);
	}
	else {
		if ( nType == RING_COMMANDTYPE_EXIT ) {
			ring_vm_error(pVM,RING_VM_ERROR_EXITWITHOUTLOOP);
		}
		else {
			ring_vm_error(pVM,RING_VM_ERROR_LOOPWITHOUTLOOP);
		}
	}
}

void ring_vm_optionalloop ( VM *pVM )
{
	if ( pVM->lOptionalLoop ) {
		pVM->lOptionalLoop = 0 ;
		RING_VM_STACK_PUSHNVALUE(1.0);
		ring_vm_exit(pVM,RING_COMMANDTYPE_LOOP);
	}
}

void ring_vm_stepnumber ( VM *pVM )
{
	double nNum1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		ring_list_adddouble_gc(pVM->pRingState,pVM->pForStep,RING_VM_STACK_READN);
		RING_VM_STACK_POP ;
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_RETURNIFACTIVECATCH ;
		ring_list_adddouble_gc(pVM->pRingState,pVM->pForStep,nNum1);
		RING_VM_STACK_POP ;
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_FORSTEPDATATYPE);
	}
}

void ring_vm_stepfromreg ( VM *pVM )
{
	ring_list_adddouble_gc(pVM->pRingState,pVM->pForStep,RING_VM_IR_READD);
}

void ring_vm_popstep ( VM *pVM )
{
	ring_list_deleteitem_gc(pVM->pRingState,pVM->pForStep,ring_list_getsize(pVM->pForStep));
}
