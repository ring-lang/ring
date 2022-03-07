/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* String As Array */

void ring_vm_string_pushv ( VM *pVM )
{
    char *newstr  ;
    char cStr[2]  ;
    if ( (pVM->nRetItemRef>=1)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
        pVM->nRetItemRef-- ;
        return ;
    }
    newstr = (char *) RING_VM_STACK_READP ;
    RING_VM_STACK_POP ;
    cStr[0] = newstr[0] ;
    cStr[1] = '\0' ;
    RING_VM_STACK_PUSHCVALUE2(cStr,1);
}

void ring_vm_string_assignment ( VM *pVM )
{
    String *cStr1  ;
    char *newstr  ;
    if ( RING_VM_STACK_ISSTRING ) {
        cStr1 = ring_string_new_gc(pVM->pRingState,RING_VM_STACK_READC);
        RING_VM_STACK_POP ;
        if ( ring_string_size(cStr1) == 1 ) {
            newstr = (char *) RING_VM_STACK_READP ;
            RING_VM_STACK_POP ;
            newstr[0] = ring_string_get(cStr1)[0] ;
            ring_string_delete_gc(pVM->pRingState,cStr1);
            return ;
        }
        else {
            ring_string_delete_gc(pVM->pRingState,cStr1);
            ring_vm_error(pVM,RING_VM_ERROR_VALUEMORETHANONECHAR);
            return ;
        }
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_VARISNOTSTRING);
        return ;
    }
}

void ring_vm_string_index ( VM *pVM, String *pString, double nNum1 )
{
    char *newstr  ;
    /* We will push a pointer of the sub char to the stack */
    if ( nNum1 < 1 || nNum1 > ring_string_size(pString) ) {
        ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
        return ;
    }
    newstr = pString->cStr ;
    newstr = newstr + ((int) (nNum1 - 1) ) ;
    RING_VM_STACK_PUSHPVALUE(newstr);
    RING_VM_STACK_OBJTYPE = RING_OBJTYPE_SUBSTRING ;
}
