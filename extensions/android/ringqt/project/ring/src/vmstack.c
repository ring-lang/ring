/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Stack and Variables */

void ring_vm_pushv ( VM *pVM )
{
    List *pList  ;
    if ( pVM->nSP <= pVM->nFuncSP ) {
        /*
        **  Happens after using EVAL() in this case we avoid PUSHV 
        **  Add Output Value (if Eval() parameter (Code to be executed) miss the Return <Expr> command) 
        */
        RING_VM_STACK_PUSHCVALUE("") ;
        return ;
    }
    switch ( RING_VM_STACK_OBJTYPE ) {
        case RING_OBJTYPE_VARIABLE :
            if ( ! ring_vm_checknull(pVM) ) {
                ring_vm_varpushv(pVM);
            }
            break ;
        case RING_OBJTYPE_LISTITEM :
            ring_vm_listpushv(pVM);
            break ;
        case RING_OBJTYPE_SUBSTRING :
            ring_vm_string_pushv(pVM);
            break ;
    }
}

int ring_vm_checknull ( VM *pVM )
{
    List *pVar  ;
    pVar = (List *) RING_VM_STACK_READP ;
    /* Check NULL Value */
    if ( (pVM->nInClassRegion == 0) && (ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL) && ( ring_list_isstring(pVar,RING_VAR_VALUE) ) ) {
        if ( strcmp(ring_list_getstring(pVar,RING_VAR_VALUE),"NULL") == 0 ) {
            ring_vm_error2(pVM,RING_VM_ERROR_USINGNULLVARIABLE,ring_list_getstring(pVar,RING_VAR_NAME));
            if ( ring_list_getlist(pVM->pActiveMem,ring_list_getsize(pVM->pActiveMem)) == pVar ) {
                /* Delete the Item from the HashTable */
                ring_hashtable_deleteitem_gc(pVM->pRingState,pVM->pActiveMem->pHashTable,ring_list_getstring(pVar,RING_VAR_NAME));
                ring_list_deletelastitem_gc(pVM->pRingState,pVM->pActiveMem);
            }
            return 1 ;
        }
    }
    return 0 ;
}

void ring_vm_varpushv ( VM *pVM )
{
    List *pVar, *pList  ;
    pVar = (List *) RING_VM_STACK_READP ;
    /* We don't use POP, because PUSHCVAR and PUSHNVAR don't do SP++ */
    switch ( ring_list_gettype(pVar,RING_VAR_VALUE) ) {
        case ITEMTYPE_NUMBER :
            RING_VM_STACK_PUSHNVAR ;
            break ;
        case ITEMTYPE_STRING :
            RING_VM_STACK_PUSHCVAR ;
            break ;
        case ITEMTYPE_LIST :
            /* Support using { } to access object after object name */
            pList = ring_list_getlist(pVar,RING_VAR_VALUE) ;
            ring_vm_oop_setbraceobj(pVM,pList);
            break ;
    }
}

void ring_vm_loadaddress ( VM *pVM )
{
    if ( ring_vm_findvar(pVM, RING_VM_IR_READC  ) == 0 ) {
        ring_vm_newvar(pVM, RING_VM_IR_READC);
        /* Support for private attributes */
        ring_list_setint_gc(pVM->pRingState,(List *) RING_VM_STACK_READP,RING_VAR_PRIVATEFLAG,pVM->nPrivateFlag);
    }
    /* Don't change instruction if it's LoadAFirst */
    if ( pVM->nFirstAddress == 1 ) {
        return ;
    }
    if ( pVM->nVarScope == RING_VARSCOPE_GLOBAL ) {
        /* Replace LoadAddress with PUSHP for better performance */
        RING_VM_IR_OPCODE = ICO_PUSHP ;
        ring_item_setpointer_gc(pVM->pRingState,RING_VM_IR_ITEM(1),RING_VM_STACK_READP);
    }
    else if ( pVM->nVarScope == RING_VARSCOPE_LOCAL ) {
        if ( pVM->lUsePushPLocal ) {
            /* Replace LoadAddress with PUSHPLOCAL for better performance */
            RING_VM_IR_OPCODE = ICO_PUSHPLOCAL ;
            ring_vm_newbytecodeitem(pVM,3);
            ring_vm_newbytecodeitem(pVM,4);
            ring_item_setpointer_gc(pVM->pRingState,RING_VM_IR_ITEM(3),RING_VM_STACK_READP);
            ring_item_setint_gc(pVM->pRingState,RING_VM_IR_ITEM(4),ring_list_getint(pVM->aScopeID,ring_list_getsize(pVM->aScopeID)));
            #if RING_SHOWICFINAL
                RING_VM_IR_PARACOUNT = RING_VM_IR_PARACOUNT + 2 ;
                ring_list_addpointer_gc(pVM->pRingState,RING_VM_IR_LIST,RING_VM_STACK_READP);
                ring_list_addint_gc(pVM->pRingState,RING_VM_IR_LIST,ring_list_getint(pVM->aScopeID,ring_list_getsize(pVM->aScopeID)));
            #endif
        }
    }
    /* Save Scope in nLoadAddressScope */
    if ( pVM->nLoadAddressScope == RING_VARSCOPE_NOTHING ) {
        pVM->nLoadAddressScope = pVM->nVarScope ;
    }
}

void ring_vm_assignment ( VM *pVM )
{
    List *pVar,*pList  ;
    String *cStr1, *pString  ;
    double nNum1  ;
    Item *pItem  ;
    if ( RING_VM_STACK_PREVOBJTYPE == RING_OBJTYPE_SUBSTRING ) {
        if ( pVM->nBeforeEqual == 0 ) {
            ring_vm_string_assignment(pVM);
        }
        else {
            ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
        }
    }
    else if ( RING_VM_STACK_PREVOBJTYPE == RING_OBJTYPE_LISTITEM ) {
        ring_vm_listassignment(pVM);
    }
    else if ( RING_VM_STACK_PREVOBJTYPE ==RING_OBJTYPE_VARIABLE ) {
        if ( (RING_VM_STACK_ISSTRING) && (pVM->nBeforeEqual <= 1 ) ) {
            cStr1 = RING_VM_STACK_GETSTRINGRAW ;
            RING_VM_STACK_POP ;
            pVar = (List *) RING_VM_STACK_READP ;
            RING_VM_STACK_POP ;
            if ( pVM->nBeforeEqual == 0 ) {
                ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_STRING);
                ring_list_setstring2_gc(pVM->pRingState,pVar, RING_VAR_VALUE , ring_string_get(cStr1),ring_string_size(cStr1));
            }
            else {
                /* Check NULL Variable */
                if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL ) {
                    ring_vm_error2(pVM,RING_VM_ERROR_USINGNULLVARIABLE,ring_list_getstring(pVar,RING_VAR_NAME));
                    return ;
                }
                if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
                    pString = ring_list_getstringobject(pVar,RING_VAR_VALUE);
                    ring_string_add2_gc(pVM->pRingState,pString,ring_string_get(cStr1),ring_string_size(cStr1));
                }
                else if ( ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
                    ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) +ring_vm_stringtonum(pVM,ring_string_get(cStr1)));
                }
            }
        }
        else if ( RING_VM_STACK_ISNUMBER ) {
            nNum1 = RING_VM_STACK_READN ;
            RING_VM_STACK_POP ;
            pVar = (List *) RING_VM_STACK_READP ;
            RING_VM_STACK_POP ;
            if ( pVM->nBeforeEqual == 0 ) {
                ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_NUMBER);
                ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , nNum1);
            }
            else {
                /* Check NULL Variable */
                if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL ) {
                    ring_vm_error2(pVM,RING_VM_ERROR_USINGNULLVARIABLE,ring_list_getstring(pVar,RING_VAR_NAME));
                    return ;
                }
                ring_vm_beforeequallist(pVM,pVar,nNum1);
            }
        }
        else if ( (RING_VM_STACK_ISPOINTER) && (pVM->nBeforeEqual == 0 ) ) {
            if ( (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) || (RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM) ) {
                /* Get The Source List */
                if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
                    pVar = ring_list_getlist((List *) RING_VM_STACK_READP,RING_VAR_VALUE);
                }
                else {
                    pItem = (Item *) RING_VM_STACK_READP ;
                    pVar = ring_item_getlist(pItem);
                }
                if ( pVar->lCopyByRef ) {
                    pList = pVar ;
                }
                else {
                    /* We use (Temp) List - to avoid problems when coping from parent list to child list */
                    pList = ring_list_new_gc(pVM->pRingState,0);
                    ring_vm_list_copy(pVM,pList,pVar);
                }
                RING_VM_STACK_POP ;
                pVar = (List *) RING_VM_STACK_READP ;
                RING_VM_STACK_POP ;
                ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_LIST);
                ring_list_setlist_gc(pVM->pRingState,pVar,RING_VAR_VALUE);
                /* Copy The List */
                if ( pList->lCopyByRef ) {
                    pList->lCopyByRef = 0 ;
                    pVar = ring_list_getlist(pVar,RING_VAR_VALUE) ;
                    ring_list_swaptwolists(pList,pVar);
                }
                else {
                    ring_vm_list_copy(pVM,ring_list_getlist(pVar,RING_VAR_VALUE),pList);
                    /* Update self object pointer */
                    if ( ring_vm_oop_isobject(ring_list_getlist(pVar,RING_VAR_VALUE)) ) {
                        ring_vm_oop_updateselfpointer(pVM,ring_list_getlist(pVar,RING_VAR_VALUE),RING_OBJTYPE_VARIABLE,pVar);
                    }
                    ring_list_delete_gc(pVM->pRingState,pList);
                }
            }
        }
        else {
            ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
        }
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_ASSIGNNOTVARIABLE);
    }
    pVM->nBeforeEqual = 0 ;
    /* Clear Assignment Pointer */
    pVM->pAssignment = NULL ;
}

void ring_vm_inc ( VM *pVM )
{
    List *pVar  ;
    if ( ring_vm_findvar(pVM, RING_VM_IR_READC ) == 0 ) {
        ring_vm_newvar(pVM, RING_VM_IR_READC);
    }
    if ( ( ring_list_getsize(pVM->pMem) == 1 )  && (pVM->pActiveMem == ring_vm_getglobalscope(pVM)) ) {
        /* Replace ICO_INC with IncP for better performance */
        RING_VM_IR_OPCODE = ICO_INCP ;
        ring_item_setpointer_gc(pVM->pRingState,RING_VM_IR_ITEM(1),RING_VM_STACK_READP);
    }
    pVar = (List *) RING_VM_STACK_READP ;
    RING_VM_STACK_POP ;
    ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,ring_list_getdouble(pVar,RING_VAR_VALUE) + 1);
}

void ring_vm_loadapushv ( VM *pVM )
{
    if ( ring_vm_findvar(pVM, RING_VM_IR_READC  ) == 0 ) {
        ring_vm_newvar(pVM, RING_VM_IR_READC);
    }
    if ( pVM->nVarScope == RING_VARSCOPE_GLOBAL ) {
        /* Replace LoadAPushV with PUSHPV for better performance */
        RING_VM_IR_OPCODE = ICO_PUSHPV ;
        ring_item_setpointer_gc(pVM->pRingState,RING_VM_IR_ITEM(1),RING_VM_STACK_READP);
    }
    ring_vm_varpushv(pVM);
}

void ring_vm_newline ( VM *pVM )
{
    pVM->nLineNumber = RING_VM_IR_READI ;
    ring_vm_traceevent(pVM,RING_VM_TRACEEVENT_NEWLINE);
}

void ring_vm_freestack ( VM *pVM )
{
    int nSP  ;
    /* Clear Assignment Pointer */
    pVM->pAssignment = NULL ;
    /* Clear Load Address Scope Information */
    pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
    /* Clear the Exit Command flag */
    pVM->lExitFlag = 0 ;
    /* In the class region */
    if ( pVM->nInClassRegion ) {
        /*
        **  Description 
        **  In the class Region we don't free stack to support Object + New Object 
        **  So we can add objects quickly to lists and access them using braces { } 
        **  But If we did this only we may get stack overflow if we did some work in the class region like 
        **  Using Switch (Which use duplication) or calling functions without storing the output using Assignment 
        **  To solve this situation we Use RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER 
        **  So we can support Object + New Object and avoid Stack Overflow too! 
        **  This feature is GREAT in the language where we can quickly move applications from 
        **  Using procedural programming and global variables to Classes and Object Attributes 
        */
        nSP = ring_vm_newobjectstackpointer(pVM) ;
        if ( pVM->nSP > nSP + RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER ) {
            pVM->nSP = nSP+RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER ;
        }
        return ;
    }
    if ( ( ring_list_getsize(pVM->pFuncCallList) == 0 ) && (pVM->nInsideBraceFlag == 0) ) {
        pVM->nSP = 0 ;
        pVM->nFuncSP = 0 ;
        /* Clear General Temp Memory */
        ring_list_deleteallitems_gc(pVM->pRingState,pVM->pTempMem);
    }
    else {
        if ( pVM->nInsideBraceFlag == 0 ) {
            pVM->nSP = pVM->nFuncSP ;
        }
        else {
            ring_vm_oop_bracestack(pVM);
        }
    }
}

void ring_vm_setreference ( VM *pVM )
{
    List *pList  ;
    int nType  ;
    void *pPointer  ;
    /*
    **  Check if we have value (string/number) not variable 
    **  In this case we need assignment 
    */
    if ( ! RING_VM_STACK_ISPOINTER ) {
        ring_vm_assignment(pVM);
        return ;
    }
    /* Read Source */
    pPointer = RING_VM_STACK_READP ;
    nType = RING_VM_STACK_OBJTYPE ;
    RING_VM_STACK_POP ;
    /* Read Destination */
    pList = (List *) RING_VM_STACK_READP ;
    RING_VM_STACK_POP ;
    /* Reference Counting to Destination before copy from Source */
    ring_vm_gc_checkupdatereference(pVM,pList);
    /* Copy by reference */
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_POINTER);
    ring_list_setpointer_gc(pVM->pRingState,pList,RING_VAR_VALUE,pPointer);
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_PVALUETYPE,nType);
    /* Reference Counting (To Source After copy to Destination) */
    ring_vm_gc_checknewreference(pPointer,nType);
}

void ring_vm_list_copy ( VM *pVM,List *pNewList, List *pList )
{
    int x,nMax  ;
    List *pNewList2  ;
    Item *pItem  ;
    assert(pList != NULL);
    /* Copy Items */
    nMax = ring_list_getsize(pList) ;
    if ( nMax == 0 ) {
        return ;
    }
    for ( x = 1 ; x <= nMax ; x++ ) {
        if ( ring_list_isint(pList,x) ) {
            ring_list_addint_gc(pVM->pRingState,pNewList,ring_list_getint(pList,x));
        }
        else if ( ring_list_isdouble(pList,x) ) {
            ring_list_adddouble_gc(pVM->pRingState,pNewList,ring_list_getdouble(pList,x));
        }
        else if ( ring_list_isstring(pList,x) ) {
            ring_list_addstring2_gc(pVM->pRingState,pNewList,ring_list_getstring(pList,x),ring_list_getstringsize(pList,x));
        }
        else if ( ring_list_ispointer(pList,x) ) {
            ring_list_addpointer_gc(pVM->pRingState,pNewList,ring_list_getpointer(pList,x));
        }
        else if ( ring_list_isfuncpointer(pList,x) ) {
            ring_list_addfuncpointer_gc(pVM->pRingState,pNewList,ring_list_getfuncpointer(pList,x));
        }
        else if ( ring_list_islist(pList,x) ) {
            pNewList2 = ring_list_newlist_gc(pVM->pRingState,pNewList);
            ring_vm_list_copy(pVM,pNewList2,ring_list_getlist(pList,x));
            /* Update Self Object Pointer */
            if ( ring_vm_oop_isobject(pNewList2) ) {
                pItem = ring_list_getitem(pNewList,ring_list_getsize(pNewList));
                ring_vm_oop_updateselfpointer(pVM,pNewList2,RING_OBJTYPE_LISTITEM,pItem);
            }
        }
    }
    /* Check if the List if a C Pointer List */
    if ( ring_list_getsize(pList) == RING_CPOINTER_LISTSIZE ) {
        if ( ring_list_ispointer(pList,RING_CPOINTER_POINTER)  && ring_list_isstring(pList,RING_CPOINTER_TYPE) && ring_list_isint(pList,RING_CPOINTER_STATUS) ) {
            /* Mark the C Pointer List as Not Copied */
            ring_list_setint_gc(pVM->pRingState,pList,RING_CPOINTER_STATUS,RING_CPOINTERSTATUS_NOTCOPIED);
            ring_list_setint_gc(pVM->pRingState,pNewList,RING_CPOINTER_STATUS,RING_CPOINTERSTATUS_NOTCOPIED);
            /* Copy The Pointer by Reference */
            pNewList->pFirst->pValue = ring_item_delete_gc(pVM->pRingState,pNewList->pFirst->pValue);
            pItem = ring_list_getitem(pList,1) ;
            pNewList->pFirst->pValue = pItem ;
            ring_vm_gc_newitemreference(pItem);
        }
    }
}

void ring_vm_list_simpointercopy ( VM *pVM,List *pList )
{
    int x  ;
    assert(pList != NULL);
    /* Copy Items */
    if ( ring_list_getsize(pList) == 0 ) {
        return ;
    }
    for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        if ( ring_list_islist(pList,x) ) {
            ring_vm_list_simpointercopy(pVM,ring_list_getlist(pList,x));
        }
    }
    /* Check if the List if a C Pointer List */
    if ( ring_list_getsize(pList) == RING_CPOINTER_LISTSIZE ) {
        if ( ring_list_ispointer(pList,RING_CPOINTER_POINTER)  && ring_list_isstring(pList,RING_CPOINTER_TYPE) && ring_list_isint(pList,RING_CPOINTER_STATUS) ) {
            /* Check value to avoid adding the pointer to the C Pointer list again */
            if ( ring_list_getint(pList,RING_CPOINTER_STATUS) == RING_CPOINTERSTATUS_NOTCOPIED ) {
                /* Mark C Pointer List As Copied */
                ring_list_setint_gc(pVM->pRingState,pList,RING_CPOINTER_STATUS,RING_CPOINTERSTATUS_COPIED);
            }
            else if ( ring_list_getint(pList,RING_CPOINTER_STATUS) == RING_CPOINTERSTATUS_NOTASSIGNED ) {
                /* Mark the C Pointer List as Not Copied */
                ring_list_setint_gc(pVM->pRingState,pList,RING_CPOINTER_STATUS,RING_CPOINTERSTATUS_NOTCOPIED);
            }
        }
    }
}

void ring_vm_beforeequallist ( VM *pVM,List *pVar,double nNum1 )
{
    String *pString  ;
    char cStr[100]  ;
    int nOutput  ;
    if ( ring_list_isdouble(pVar,RING_VAR_VALUE) ) {
        if ( pVM->nBeforeEqual == 1 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) + nNum1);
        }
        else if ( pVM->nBeforeEqual == 2 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) - nNum1);
        }
        else if ( pVM->nBeforeEqual == 3 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) * nNum1);
        }
        else if ( pVM->nBeforeEqual == 4 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) / nNum1);
        }
        else if ( pVM->nBeforeEqual == 5 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , fmod(ring_list_getdouble(pVar,RING_VAR_VALUE), nNum1));
        }
        else if ( pVM->nBeforeEqual == 6 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) & (int) nNum1);
        }
        else if ( pVM->nBeforeEqual == 7 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) | (int) nNum1);
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) | (int) nNum1);
        }
        else if ( pVM->nBeforeEqual == 8 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) ^ (int) nNum1);
        }
        else if ( pVM->nBeforeEqual == 9 ) {
            nOutput = (int) ring_list_getdouble(pVar,RING_VAR_VALUE) << (int) nNum1 ;
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (double) nOutput);
        }
        else if ( pVM->nBeforeEqual == 10 ) {
            ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) >> (int) nNum1);
        }
    }
    else if ( (ring_list_isstring(pVar,RING_VAR_VALUE) == 1) && (pVM->nBeforeEqual == 1) ) {
        pString = ring_list_getstringobject(pVar,RING_VAR_VALUE);
        ring_string_add_gc(pVM->pRingState,pString,ring_vm_numtostring(pVM,nNum1,cStr));
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
        return ;
    }
}

void ring_vm_beforeequalitem ( VM *pVM,Item *pItem,double nNum1 )
{
    String *pString  ;
    char cStr[100]  ;
    int nOutput  ;
    if ( ring_item_isdouble(pItem) ) {
        if ( pVM->nBeforeEqual == 1 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,ring_item_getdouble(pItem) + nNum1);
        }
        else if ( pVM->nBeforeEqual == 2 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,ring_item_getdouble(pItem) - nNum1);
        }
        else if ( pVM->nBeforeEqual == 3 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,ring_item_getdouble(pItem) * nNum1);
        }
        else if ( pVM->nBeforeEqual == 4 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,ring_item_getdouble(pItem) / nNum1);
        }
        else if ( pVM->nBeforeEqual == 5 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,fmod(ring_item_getdouble(pItem) , nNum1));
        }
        else if ( pVM->nBeforeEqual == 6 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,(int) ring_item_getdouble(pItem) & (int) nNum1);
        }
        else if ( pVM->nBeforeEqual == 7 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,(int) ring_item_getdouble(pItem) | (int) nNum1);
        }
        else if ( pVM->nBeforeEqual == 8 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,(int) ring_item_getdouble(pItem) ^ (int) nNum1);
        }
        else if ( pVM->nBeforeEqual == 9 ) {
            nOutput = (int) ring_item_getdouble(pItem) << (int) nNum1 ;
            ring_item_setdouble_gc(pVM->pRingState,pItem ,(double) nOutput);
        }
        else if ( pVM->nBeforeEqual == 10 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem ,(int) ring_item_getdouble(pItem) >> (int) nNum1);
        }
    }
    else if ( (ring_item_isstring(pItem) == 1)  && (pVM->nBeforeEqual == 1) ) {
        pString = ring_item_getstring(pItem);
        ring_string_add_gc(pVM->pRingState,pString,ring_vm_numtostring(pVM,nNum1,cStr));
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
        return ;
    }
}

void ring_vm_plusplus ( VM *pVM )
{
    List *pList  ;
    Item *pItem  ;
    if ( RING_VM_STACK_ISPOINTER ) {
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pList = (List *) RING_VM_STACK_READP ;
            if ( ring_list_isdouble(pList,RING_VAR_VALUE) ) {
                ring_list_setdouble_gc(pVM->pRingState,pList,RING_VAR_VALUE,ring_list_getdouble(pList,RING_VAR_VALUE)+1);
                return ;
            }
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) RING_VM_STACK_READP ;
            if ( ring_item_isdouble(pItem) ) {
                ring_item_setdouble_gc(pVM->pRingState,pItem,ring_item_getdouble(pItem)+1);
                return ;
            }
        }
    }
    else if ( RING_VM_STACK_ISNUMBER ) {
        RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN + 1);
        return ;
    }
    ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
}

void ring_vm_minusminus ( VM *pVM )
{
    List *pList  ;
    Item *pItem  ;
    if ( RING_VM_STACK_ISPOINTER ) {
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pList = (List *) RING_VM_STACK_READP ;
            if ( ring_list_isdouble(pList,RING_VAR_VALUE) ) {
                ring_list_setdouble_gc(pVM->pRingState,pList,RING_VAR_VALUE,ring_list_getdouble(pList,RING_VAR_VALUE)-1);
                return ;
            }
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) RING_VM_STACK_READP ;
            if ( ring_item_isdouble(pItem) ) {
                ring_item_setdouble_gc(pVM->pRingState,pItem,ring_item_getdouble(pItem)-1);
                return ;
            }
        }
    }
    else if ( RING_VM_STACK_ISNUMBER ) {
        RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN - 1);
        return ;
    }
    ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
}

void ring_vm_assignmentpointer ( VM *pVM )
{
    List *pList, *pList2  ;
    Item *pItem  ;
    int x  ;
    /* Check Instruction Parameters */
    if ( RING_VM_IR_PARACOUNT >= 2 ) {
        if ( RING_VM_IR_READI == 0 ) {
            /*
            **  We have this option with New Lists and  New Objects only 
            **  We will accept this option only when we have the setter method 
            */
            if ( pVM->lNoSetterMethod == 0 ) {
                pVM->nNOAssignment = 1 ;
            }
            else {
                /* Tell the ICO_SETPROPERTY instruction to be disabled */
                pVM->lNoSetterMethod = 2 ;
            }
        }
    }
    if ( pVM->nNOAssignment == 0 ) {
        pVM->pAssignment = RING_VM_STACK_READP ;
        /* Check trying to change the self pointer */
        pList = NULL ;
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            if ( ring_list_islist((List *) pVM->pAssignment,RING_VAR_VALUE) ) {
                pList = ring_list_getlist((List *) pVM->pAssignment,RING_VAR_VALUE) ;
            }
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) pVM->pAssignment ;
            if ( ring_item_gettype(pItem) == ITEMTYPE_LIST ) {
                pList = ring_item_getlist(pItem) ;
            }
            else {
                return ;
            }
        }
        else {
            return ;
        }
        if ( ring_vm_oop_isobject(pList)  && (ring_list_getsize(pVM->pObjState) > 0 ) ) {
            /* We loop to prevent passing self to function that destroy the self */
            for ( x = 1 ; x <= ring_list_getsize(pVM->pObjState) ; x++ ) {
                pList2 = ring_list_getlist(pVM->pObjState,x);
                if ( ring_list_getpointer(pList,RING_OBJECT_OBJECTDATA) == ring_list_getpointer(pList2,RING_OBJSTATE_SCOPE) ) {
                    ring_vm_error(pVM,RING_VM_ERROR_TRYINGTOMODIFYTHESELFPOINTER);
                    return ;
                }
            }
        }
    }
    else {
        pVM->nNOAssignment = 0 ;
    }
}

void ring_vm_freeloadaddressscope ( VM *pVM )
{
    /* Clear Load Address Scope Information */
    pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
}
