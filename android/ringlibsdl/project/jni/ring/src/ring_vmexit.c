/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* End Program / Exit from Loop / Loop (Continue) */

void ring_vm_bye ( VM *pVM )
{
	pVM->nPC = ring_list_getsize(pVM->pCode) + 1 ;
}

void ring_vm_exitmark ( VM *pVM )
{
	List *pList  ;
	/* Exit Mark */
	pList = ring_list_newlist(pVM->pExitMark);
	ring_list_addint(pList,RING_VM_IR_READI);
	ring_vm_savestate(pVM,pList);
	/* Loop Mark */
	pList = ring_list_newlist(pVM->pLoopMark);
	ring_list_addint(pList,RING_VM_IR_READIVALUE(2));
	ring_vm_savestate(pVM,pList);
}

void ring_vm_popexitmark ( VM *pVM )
{
	/* POP Exit Mark */
	ring_list_deleteitem(pVM->pExitMark,ring_list_getsize(pVM->pExitMark));
	/* POP Loop Mark */
	ring_list_deleteitem(pVM->pLoopMark,ring_list_getsize(pVM->pLoopMark));
}

void ring_vm_exit ( VM *pVM,int nType )
{
	List *pList,*pActiveList  ;
	int x,y  ;
	/* Set Active List */
	if ( nType == 1 ) {
		pActiveList = pVM->pExitMark ;
	} else {
		pActiveList = pVM->pLoopMark ;
	}
	if ( ring_list_getsize(pActiveList) > 0 ) {
		x = ring_list_getsize(pActiveList) ;
		if ( RING_VM_IR_PARACOUNT > 1 ) {
			if ( (RING_VM_IR_READD > 0) && ( RING_VM_IR_READD <= ring_list_getsize(pActiveList) ) ) {
				x = ring_list_getsize(pActiveList) - RING_VM_IR_READD + 1 ;
				for ( y = x + 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
					ring_list_deleteitem(pActiveList,y);
				}
			} else {
				if ( nType == 1 ) {
					ring_vm_error(pVM,RING_VM_ERROR_EXITNUMBEROUTSIDERANGE);
				} else {
					ring_vm_error(pVM,RING_VM_ERROR_LOOPNUMBEROUTSIDERANGE);
				}
				return ;
			}
		}
		pList = ring_list_getlist(pActiveList,x);
		pVM->nPC = ring_list_getint(pList,1) ;
		ring_vm_restorestate(pVM,pList,2,RING_STATE_EXIT);
	} else {
		if ( nType == 1 ) {
			ring_vm_error(pVM,RING_VM_ERROR_EXITWITHOUTLOOP);
		} else {
			ring_vm_error(pVM,RING_VM_ERROR_LOOPWITHOUTLOOP);
		}
		return ;
	}
}
/* For Loop - Step */

void ring_vm_stepnumber ( VM *pVM )
{
	double nNum1  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		ring_list_adddouble(pVM->aForStep,RING_VM_STACK_READN);
		RING_VM_STACK_POP ;
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		ring_list_adddouble(pVM->aForStep,nNum1);
		RING_VM_STACK_POP ;
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_FORSTEPDATATYPE);
	}
}

void ring_vm_popstep ( VM *pVM )
{
	ring_list_deleteitem(pVM->aForStep,ring_list_getsize(pVM->aForStep));
}
