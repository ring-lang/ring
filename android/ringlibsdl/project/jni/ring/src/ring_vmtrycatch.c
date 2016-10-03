/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Try Catch Done */

void ring_vm_try ( VM *pVM )
{
	List *pList  ;
	pList = ring_list_newlist(pVM->pTry);
	ring_list_addint(pList,RING_VM_IR_READI);
	ring_vm_savestate(pVM,pList);
	pVM->nActiveCatch = 0 ;
}

void ring_vm_catch ( VM *pVM,const char *cError )
{
	List *pList  ;
	pList = ring_list_getlist(pVM->pTry,ring_list_getsize(pVM->pTry));
	pVM->nPC = ring_list_getint(pList,1) ;
	ring_vm_restorestate(pVM,pList,2,RING_STATE_TRYCATCH);
	/* Define variable cCatchError to contain the error message */
	ring_list_setstring(ring_list_getlist(ring_list_getlist(pVM->pMem,1),6),3,cError);
	/* Tell C-API caller (CALL command) that catch happens! */
	pVM->nActiveCatch = 1 ;
	/* Catch Statements must be executed without try effects */
	ring_vm_done(pVM);
}

void ring_vm_done ( VM *pVM )
{
	ring_list_deleteitem(pVM->pTry,ring_list_getsize(pVM->pTry));
}
