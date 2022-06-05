/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* For Better Performance */

void ring_vm_pushp ( VM *pVM )
{
    RING_VM_STACK_PUSHP ;
    RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
    /* Update Scope Information */
    if ( pVM->nLoadAddressScope  == RING_VARSCOPE_NOTHING ) {
        pVM->nLoadAddressScope = RING_VARSCOPE_GLOBAL ;
    }
    pVM->nVarScope = RING_VARSCOPE_GLOBAL ;
}

void ring_vm_pushplocal ( VM *pVM )
{
    /* Check Scope Life Time */
    if ( RING_VM_IR_READIVALUE(4) != pVM->nActiveScopeID ) {
        RING_VM_IR_OPCODE = ICO_LOADADDRESS ;
        ring_list_deliteminsidelist_gc(pVM->pRingState,pVM->aNewByteCodeItems,RING_VM_IR_ITEM(3));
        ring_list_deliteminsidelist_gc(pVM->pRingState,pVM->aNewByteCodeItems,RING_VM_IR_ITEM(4));
        #if RING_SHOWICFINAL
            RING_VM_IR_PARACOUNT = RING_VM_IR_PARACOUNT - 2 ;
            ring_list_deleteitem_gc(pVM->pRingState,RING_VM_IR_LIST,ring_list_getsize(RING_VM_IR_LIST));
            ring_list_deleteitem_gc(pVM->pRingState,RING_VM_IR_LIST,ring_list_getsize(RING_VM_IR_LIST));
        #endif
        pVM->nPC-- ;
        return ;
    }
    RING_VM_STACK_PUSHPVALUE(RING_VM_IR_READPVALUE(3)) ;
    RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
    /* Update Scope Information */
    if ( pVM->nLoadAddressScope  == RING_VARSCOPE_NOTHING ) {
        pVM->nLoadAddressScope = RING_VARSCOPE_LOCAL ;
    }
    pVM->nVarScope = RING_VARSCOPE_LOCAL ;
}

void ring_vm_incp ( VM *pVM )
{
    List *pVar  ;
    pVar = (List *) RING_VM_IR_READP ;
    ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,ring_list_getdouble(pVar,RING_VAR_VALUE) + 1);
}

void ring_vm_pushpv ( VM *pVM )
{
    ring_vm_pushp(pVM);
    ring_vm_varpushv(pVM);
}

void ring_vm_incjump ( VM *pVM )
{
    List *pVar  ;
    double nNum1,nNum2  ;
    if ( ring_vm_findvar(pVM, RING_VM_IR_READC ) == 0 ) {
        ring_vm_newvar(pVM, RING_VM_IR_READC);
    }
    nNum1 = ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep));
    /* Change Instruction for Performance */
    if ( pVM->nVarScope == RING_VARSCOPE_GLOBAL ) {
        /* Replace ICO_INCJUMP with IncPJUMP for better performance */
        if ( nNum1 == 1.0 ) {
            RING_VM_IR_OPCODE = ICO_INCPJUMPSTEP1 ;
        }
        else {
            RING_VM_IR_OPCODE = ICO_INCPJUMP ;
        }
        ring_item_setpointer_gc(pVM->pRingState,RING_VM_IR_ITEM(1),RING_VM_STACK_READP);
    }
    else if ( pVM->nVarScope == RING_VARSCOPE_LOCAL ) {
        /* Replace ICO_INCJUMP with IncLPJUMP for better performance */
        RING_VM_IR_OPCODE = ICO_INCLPJUMP ;
        ring_item_setpointer_gc(pVM->pRingState,RING_VM_IR_ITEM(3),RING_VM_STACK_READP);
        ring_item_setint_gc(pVM->pRingState,RING_VM_IR_ITEM(4),ring_list_getint(pVM->aScopeID,ring_list_getsize(pVM->aScopeID)));
    }
    pVar = (List *) RING_VM_STACK_READP ;
    RING_VM_STACK_POP ;
    /* Check Data */
    if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_vm_stringtonum(pVM,ring_list_getstring(pVar,RING_VAR_VALUE));
        ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,nNum2);
    }
    else if ( ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
        return ;
    }
    ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,nNum2 +nNum1);
    /* Jump */
    pVM->nPC = RING_VM_IR_READIVALUE(2) ;
}

void ring_vm_incpjump ( VM *pVM )
{
    List *pVar  ;
    double nNum1,nNum2  ;
    pVar = (List *) RING_VM_IR_READP ;
    nNum1 = ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep));
    /* Check Data */
    if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_vm_stringtonum(pVM,ring_list_getstring(pVar,RING_VAR_VALUE));
    }
    else if ( ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
        return ;
    }
    ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,nNum2 + nNum1);
    /* Jump */
    pVM->nPC = RING_VM_IR_READIVALUE(2) ;
}

void ring_vm_inclpjump ( VM *pVM )
{
    List *pVar  ;
    double nNum1,nNum2  ;
    /* Check Scope Life Time */
    if ( RING_VM_IR_READIVALUE(4) != pVM->nActiveScopeID ) {
        RING_VM_IR_OPCODE = ICO_INCJUMP ;
        ring_list_deliteminsidelist_gc(pVM->pRingState,pVM->aNewByteCodeItems,RING_VM_IR_ITEM(3));
        ring_list_deliteminsidelist_gc(pVM->pRingState,pVM->aNewByteCodeItems,RING_VM_IR_ITEM(4));
        #if RING_SHOWICFINAL
            RING_VM_IR_PARACOUNT = RING_VM_IR_PARACOUNT - 2 ;
            ring_list_deleteitem_gc(pVM->pRingState,RING_VM_IR_LIST,ring_list_getsize(RING_VM_IR_LIST));
            ring_list_deleteitem_gc(pVM->pRingState,RING_VM_IR_LIST,ring_list_getsize(RING_VM_IR_LIST));
        #endif
        pVM->nPC-- ;
        return ;
    }
    pVar = (List *) RING_VM_IR_READPVALUE(3) ;
    nNum1 = ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep));
    /* Check Data */
    if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_vm_stringtonum(pVM,ring_list_getstring(pVar,RING_VAR_VALUE));
    }
    else if ( ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
        return ;
    }
    ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,nNum2 + nNum1);
    /* Jump */
    pVM->nPC = RING_VM_IR_READIVALUE(2) ;
}

void ring_vm_jumpvarlenum ( VM *pVM )
{
    List *pVar  ;
    double nNum1,nNum2  ;
    if ( ring_vm_findvar(pVM, RING_VM_IR_READC  ) == 0 ) {
        ring_vm_newvar(pVM, RING_VM_IR_READC);
    }
    nNum1 = ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep));
    /* Change Instruction for Performance */
    if ( pVM->nVarScope == RING_VARSCOPE_GLOBAL ) {
        /* Replace JumpVarLENum with JumpVarPLENum for better performance */
        if ( nNum1 == 1.0 ) {
            RING_VM_IR_OPCODE = ICO_JUMPVARPLENUMSTEP1 ;
        }
        else {
            RING_VM_IR_OPCODE = ICO_JUMPVARPLENUM ;
        }
        ring_item_setpointer_gc(pVM->pRingState,RING_VM_IR_ITEM(1),RING_VM_STACK_READP);
    }
    else if ( pVM->nVarScope == RING_VARSCOPE_LOCAL ) {
        /* Replace JumpVarLENum with JumpVarLPLENum for better performance */
        RING_VM_IR_OPCODE = ICO_JUMPVARLPLENUM ;
        ring_item_setpointer_gc(pVM->pRingState,RING_VM_IR_ITEM(4),RING_VM_STACK_READP);
        ring_item_setint_gc(pVM->pRingState,RING_VM_IR_ITEM(5),ring_list_getint(pVM->aScopeID,ring_list_getsize(pVM->aScopeID)));
        #if RING_SHOWICFINAL
            RING_VM_IR_PARACOUNT = RING_VM_IR_PARACOUNT + 2 ;
            ring_list_addpointer_gc(pVM->pRingState,RING_VM_IR_LIST,RING_VM_STACK_READP);
            ring_list_addint_gc(pVM->pRingState,RING_VM_IR_LIST,ring_list_getint(pVM->aScopeID,ring_list_getsize(pVM->aScopeID)));
        #endif
    }
    pVar = (List *) RING_VM_STACK_READP ;
    RING_VM_STACK_POP ;
    /* Check Data */
    if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_vm_stringtonum(pVM,ring_list_getstring(pVar,RING_VAR_VALUE));
        ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,nNum2);
    }
    else if ( ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
        return ;
    }
    if ( nNum1 < 0 ) {
        if ( ! (nNum2 >= RING_VM_IR_READDVALUE(2)) ) {
            /* Jump */
            pVM->nPC = RING_VM_IR_READIVALUE(3) ;
        }
    }
    else {
        if ( ! (nNum2 <= RING_VM_IR_READDVALUE(2)) ) {
            /* Jump */
            pVM->nPC = RING_VM_IR_READIVALUE(3) ;
        }
    }
}

void ring_vm_jumpvarplenum ( VM *pVM )
{
    List *pVar  ;
    double nNum1,nNum2  ;
    pVar = (List *) RING_VM_IR_READP ;
    nNum1 = ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep));
    /* Check Data */
    if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_vm_stringtonum(pVM,ring_list_getstring(pVar,RING_VAR_VALUE));
    }
    else if ( ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
        return ;
    }
    if ( nNum1 < 0 ) {
        if ( ! (nNum2 >= RING_VM_IR_READDVALUE(2)) ) {
            /* Jump */
            pVM->nPC = RING_VM_IR_READIVALUE(3) ;
        }
    }
    else {
        if ( ! (nNum2 <= RING_VM_IR_READDVALUE(2)) ) {
            /* Jump */
            pVM->nPC = RING_VM_IR_READIVALUE(3) ;
        }
    }
}

void ring_vm_jumpvarlplenum ( VM *pVM )
{
    List *pVar  ;
    double nNum1,nNum2  ;
    /* Check Scope Life Time */
    if ( RING_VM_IR_READIVALUE(5)  != pVM->nActiveScopeID ) {
        RING_VM_IR_OPCODE = ICO_JUMPVARLENUM ;
        #if RING_SHOWICFINAL
            RING_VM_IR_PARACOUNT = RING_VM_IR_PARACOUNT - 2 ;
            ring_list_deleteitem_gc(pVM->pRingState,RING_VM_IR_LIST,ring_list_getsize(RING_VM_IR_LIST));
            ring_list_deleteitem_gc(pVM->pRingState,RING_VM_IR_LIST,ring_list_getsize(RING_VM_IR_LIST));
        #endif
        pVM->nPC-- ;
        return ;
    }
    pVar = (List *) RING_VM_IR_READPVALUE(4) ;
    nNum1 = ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep));
    /* Check Data */
    if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_vm_stringtonum(pVM,ring_list_getstring(pVar,RING_VAR_VALUE));
    }
    else if ( ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
        nNum2 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
        return ;
    }
    if ( nNum1 < 0 ) {
        if ( ! (nNum2 >= RING_VM_IR_READDVALUE(2)) ) {
            /* Jump */
            pVM->nPC = RING_VM_IR_READIVALUE(3) ;
        }
    }
    else {
        if ( ! (nNum2 <= RING_VM_IR_READDVALUE(2)) ) {
            /* Jump */
            pVM->nPC = RING_VM_IR_READIVALUE(3) ;
        }
    }
}

void ring_vm_loadfuncp ( VM *pVM )
{
    List *pList  ;
    pVM->nFuncExecute++ ;
    pVM->nFuncExecute2++ ;
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->pFuncCallList);
    ring_list_addint_gc(pVM->pRingState,pList,RING_VM_IR_READIVALUE(3));
    ring_list_addstring_gc(pVM->pRingState,pList,RING_VM_IR_READC);
    ring_list_addint_gc(pVM->pRingState,pList,RING_VM_IR_READIVALUE(2));
    ring_list_addint_gc(pVM->pRingState,pList,pVM->nSP);
    ring_list_newlist_gc(pVM->pRingState,pList);
    ring_list_addpointer_gc(pVM->pRingState,pList,pVM->cFileName);
    pVM->cPrevFileName = pVM->cFileName ;
    pVM->cFileName = (char *) RING_VM_IR_READPVALUE(4) ;
    ring_list_addpointer_gc(pVM->pRingState,pList,pVM->cFileName);
    ring_list_addint_gc(pVM->pRingState,pList,RING_VM_IR_READIVALUE(5));
    ring_list_addint_gc(pVM->pRingState,pList,RING_VM_IR_READIVALUE(6));
    /* Store List information */
    ring_list_addint_gc(pVM->pRingState,pList,pVM->nListStart);
    ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pNestedLists);
    pVM->nListStart = 0 ;
    pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,0);
    ring_vm_saveloadaddressscope(pVM);
}
/* For Loop Optimization When Step = 1 */

void ring_vm_incpjumpstep1 ( VM *pVM )
{
    List *pVar  ;
    double nNum1  ;
    /* Be sure that the Step is one */
    if ( ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep)) != 1.0 ) {
        RING_VM_IR_OPCODE = ICO_INCPJUMP ;
        ring_vm_incpjump(pVM);
        return ;
    }
    pVar = (List *) RING_VM_IR_READP ;
    /* We Don't Check Data Type */
    nNum1 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
    ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,nNum1 + 1);
    /* Jump */
    pVM->nPC = RING_VM_IR_READIVALUE(2) ;
}

void ring_vm_jumpvarplenumstep1 ( VM *pVM )
{
    List *pVar  ;
    double nNum1  ;
    pVar = (List *) RING_VM_IR_READP ;
    /* Be sure that the Step is one */
    if ( ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep)) != 1.0 ) {
        RING_VM_IR_OPCODE = ICO_JUMPVARPLENUM ;
        ring_vm_jumpvarplenum(pVM);
        return ;
    }
    /* We don't Check Data type */
    nNum1 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
    if ( nNum1 > RING_VM_IR_READDVALUE(2) ) {
        /* Jump */
        pVM->nPC = RING_VM_IR_READIVALUE(3) ;
    }
}
