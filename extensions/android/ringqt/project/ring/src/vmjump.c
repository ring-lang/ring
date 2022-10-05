/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Jump Functions */

void ring_vm_jump ( VM *pVM )
{
    RING_VM_JUMP ;
}

void ring_vm_jumpzero ( VM *pVM )
{
    List *pList  ;
    Item *pItem  ;
    if ( RING_VM_STACK_ISNUMBER ) {
        if ( RING_VM_STACK_READN  == 0 ) {
            ring_vm_jump(pVM);
        }
    }
    else if ( RING_VM_STACK_ISSTRING ) {
        if ( strcmp(RING_VM_STACK_READC,"") == 0 ) {
            ring_vm_jump(pVM);
        }
    }
    else if ( RING_VM_STACK_ISPOINTER ) {
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pList = (List *) RING_VM_STACK_READP ;
            pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
            if ( ring_list_getsize(pList) == 0 ) {
                ring_vm_jump(pVM);
            }
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) RING_VM_STACK_READP ;
            pList = ring_item_getlist(pItem) ;
            if ( ring_list_getsize(pList) == 0 ) {
                ring_vm_jump(pVM);
            }
        }
    }
    RING_VM_STACK_POP ;
}

void ring_vm_jumpfor ( VM *pVM )
{
    double nNum1,nNum2,nNum3  ;
    /* Check Data */
    if ( RING_VM_STACK_ISNUMBER ) {
        nNum1 = RING_VM_STACK_READN ;
        RING_VM_STACK_POP ;
    }
    else if ( RING_VM_STACK_ISSTRING ) {
        nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
        RING_VM_STACK_POP ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
        return ;
    }
    nNum2 = ring_list_getdouble(pVM->aForStep,ring_list_getsize(pVM->aForStep));
    /* Check Data */
    if ( RING_VM_STACK_ISNUMBER ) {
        nNum3 = RING_VM_STACK_READN ;
        RING_VM_STACK_POP ;
    }
    else if ( RING_VM_STACK_ISSTRING ) {
        nNum3 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
        RING_VM_STACK_POP ;
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
        return ;
    }
    /*
    **  nNum2 = Step value that can be positive or negative 
    **  nNum1 = Items Count , nNum3 = Index 
    */
    if ( nNum2 < 0 ) {
        if ( ! ( nNum3 >= nNum1 ) ) {
            ring_vm_jump(pVM);
        }
    }
    else {
        if ( ! ( nNum3 <= nNum1 ) ) {
            ring_vm_jump(pVM);
        }
    }
}

void ring_vm_jumpone ( VM *pVM )
{
    List *pList  ;
    Item *pItem  ;
    if ( RING_VM_STACK_ISNUMBER ) {
        if ( RING_VM_STACK_READN  != 0 ) {
            ring_vm_jump(pVM);
        }
    }
    else if ( RING_VM_STACK_ISSTRING ) {
        if ( strcmp(RING_VM_STACK_READC,"") != 0 ) {
            ring_vm_jump(pVM);
        }
    }
    else if ( RING_VM_STACK_ISPOINTER ) {
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pList = (List *) RING_VM_STACK_READP ;
            pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
            if ( ring_list_getsize(pList) != 0 ) {
                ring_vm_jump(pVM);
            }
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) RING_VM_STACK_READP ;
            pList = ring_item_getlist(pItem) ;
            if ( ring_list_getsize(pList) != 0 ) {
                ring_vm_jump(pVM);
            }
        }
    }
    RING_VM_STACK_POP ;
}

void ring_vm_jumpone2 ( VM *pVM )
{
    List *pList  ;
    Item *pItem  ;
    /* Add 1, required for jump in many 'OR' in conditions */
    if ( RING_VM_STACK_ISNUMBER ) {
        if ( RING_VM_STACK_READN  != 0 ) {
            ring_vm_jump(pVM);
            return ;
        }
    }
    else if ( RING_VM_STACK_ISSTRING ) {
        if ( strcmp(RING_VM_STACK_READC,"") != 0 ) {
            ring_vm_jump(pVM);
            return ;
        }
    }
    else if ( RING_VM_STACK_ISPOINTER ) {
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pList = (List *) RING_VM_STACK_READP ;
            pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
            if ( ring_list_getsize(pList) != 0 ) {
                ring_vm_jump(pVM);
                return ;
            }
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) RING_VM_STACK_READP ;
            pList = ring_item_getlist(pItem) ;
            if ( ring_list_getsize(pList) != 0 ) {
                ring_vm_jump(pVM);
                return ;
            }
        }
    }
    RING_VM_STACK_POP ;
    RING_VM_STACK_PUSHNVALUE(0);
}

void ring_vm_jumpzero2 ( VM *pVM )
{
    List *pList  ;
    Item *pItem  ;
    /* Add 1, required for jump in many 'AND' in conditions */
    if ( RING_VM_STACK_ISNUMBER ) {
        if ( RING_VM_STACK_READN  == 0 ) {
            ring_vm_jump(pVM);
            return ;
        }
    }
    else if ( RING_VM_STACK_ISSTRING ) {
        if ( strcmp(RING_VM_STACK_READC,"") == 0 ) {
            ring_vm_jump(pVM);
            return ;
        }
    }
    else if ( RING_VM_STACK_ISPOINTER ) {
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pList = (List *) RING_VM_STACK_READP ;
            pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
            if ( ring_list_getsize(pList) == 0 ) {
                ring_vm_jump(pVM);
                return ;
            }
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) RING_VM_STACK_READP ;
            pList = ring_item_getlist(pItem) ;
            if ( ring_list_getsize(pList) == 0 ) {
                ring_vm_jump(pVM);
                return ;
            }
        }
    }
    RING_VM_STACK_POP ;
    RING_VM_STACK_PUSHNVALUE(1);
}
