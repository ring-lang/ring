/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* End Program / Exit from Loop / Loop (Continue) */

void ring_vm_bye ( VM *pVM )
{
    /* Check if the ringvm_evalinscope() function is active */
    if ( pVM->nEvalInScope >= 1 ) {
        puts(RING_VM_ERROR_BADCOMMAND);
        return ;
    }
    pVM->nPC = ring_list_getsize(pVM->pCode) + 1 ;
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
    ring_list_addint_gc(pVM->pRingState,pList,RING_VM_IR_READIVALUE(2));
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
    /* Set Active List */
    if ( nType == RING_COMMANDTYPE_EXIT ) {
        pActiveList = pVM->pExitMark ;
        pVM->lExitFlag = 1 ;
    }
    else {
        pActiveList = pVM->pLoopMark ;
    }
    /* Get the Number from the Stack */
    if ( RING_VM_STACK_ISNUMBER ) {
        nStep = RING_VM_STACK_READN ;
        RING_VM_STACK_POP ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_LOOPNUMBEROUTSIDERANGE);
    }
    if ( ring_list_getsize(pActiveList) > 0 ) {
        x = ring_list_getsize(pActiveList) ;
        /* Do Operation */
        if ( (nStep > 0) && (nStep <= ring_list_getsize(pActiveList) ) ) {
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
        pVM->nPC = ring_list_getint(pList,1) ;
        ring_vm_restorestate(pVM,pList,2,RING_STATE_EXIT);
    }
    else {
        if ( nType == RING_COMMANDTYPE_EXIT ) {
            ring_vm_error(pVM,RING_VM_ERROR_EXITWITHOUTLOOP);
        }
        else {
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
        ring_list_adddouble_gc(pVM->pRingState,pVM->aForStep,RING_VM_STACK_READN);
        RING_VM_STACK_POP ;
    }
    else if ( RING_VM_STACK_ISSTRING ) {
        nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
        ring_list_adddouble_gc(pVM->pRingState,pVM->aForStep,nNum1);
        RING_VM_STACK_POP ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORSTEPDATATYPE);
    }
}

void ring_vm_popstep ( VM *pVM )
{
    ring_list_deleteitem_gc(pVM->pRingState,pVM->aForStep,ring_list_getsize(pVM->aForStep));
}
