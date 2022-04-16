/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Lists */

void ring_vm_liststart ( VM *pVM )
{
    List *pVar,*pList  ;
    int nType  ;
    Item *pItem  ;
    int nCont  ;
    pVar = NULL ;
    pItem = NULL ;
    pVM->nListStart++ ;
    if ( pVM->nListStart == 1 ) {
        /* Check if we need to create temp list when we call function, pass list by value */
        nCont = 0 ;
        if ( RING_VM_STACK_ISPOINTER ) {
            if ( pVM->pAssignment != RING_VM_STACK_READP ) {
                nCont = 1 ;
            }
            else {
                /* Clear the Assignment Pointer */
                pVM->pAssignment = NULL ;
                /* Be Sure that we are modifying Object Attribute (Not Global/Local Variable) */
                if ( pVM->nVarScope == RING_VARSCOPE_NEWOBJSTATE ) {
                    /*
                    **  When we access object attribute from braces then create temp. variable for set property operation 
                    **  We do this if we are not inside the class region (after the class name where we define attributes) 
                    */
                    if ( (ring_list_getsize(pVM->aBraceObjects) > 0) && ( ! ring_vm_oop_callmethodinsideclass(pVM)) && (! pVM->nInClassRegion) ) {
                        nCont = 1 ;
                    }
                    ring_vm_cleansetpropertylist(pVM);
                }
            }
        }
        else {
            nCont = 1 ;
        }
        if ( (pVM->nFuncExecute > 0)  || ( nCont == 1 ) ) {
            /* Create the Temp list */
            ring_vm_createtemplist(pVM);
            pVar = (List *) RING_VM_STACK_READP ;
            nType = RING_VM_STACK_OBJTYPE ;
        }
        else {
            if ( RING_VM_STACK_ISPOINTER == 0 ) {
                /* Create the List in the Temp Memory. */
                ring_vm_newtempvar(pVM, RING_TEMP_VARIABLE ,ring_vm_prevtempmem(pVM));
                if ( pVM->nLoadAddressScope == RING_VARSCOPE_NOTHING ) {
                    pVM->nLoadAddressScope = RING_VARSCOPE_LOCAL ;
                }
            }
            nType = RING_VM_STACK_OBJTYPE ;
            if ( nType == RING_OBJTYPE_LISTITEM ) {
                pItem = (Item *) RING_VM_STACK_READP ;
            }
            else {
                pVar = (List *) RING_VM_STACK_READP ;
            }
            RING_VM_STACK_POP ;
        }
        if ( nType == RING_OBJTYPE_VARIABLE ) {
            ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_LIST);
            ring_list_setlist_gc(pVM->pRingState,pVar, RING_VAR_VALUE);
            ring_list_deleteallitems_gc(pVM->pRingState,ring_list_getlist(pVar,RING_VAR_VALUE));
            ring_list_addpointer_gc(pVM->pRingState,pVM->pNestedLists,ring_list_getlist(pVar,RING_VAR_VALUE));
        }
        else if ( (nType == RING_OBJTYPE_LISTITEM) && (pItem != NULL) ) {
            ring_item_settype_gc(pVM->pRingState,pItem,ITEMTYPE_LIST);
            pVar = ring_item_getlist(pItem);
            ring_list_deleteallitems_gc(pVM->pRingState,pVar);
            ring_list_addpointer_gc(pVM->pRingState,pVM->pNestedLists,pVar);
        }
    }
    else {
        pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
        ring_list_addpointer_gc(pVM->pRingState,pVM->pNestedLists,ring_list_newlist_gc(pVM->pRingState,pList));
    }
}

void ring_vm_listitem ( VM *pVM )
{
    String *cStr1  ;
    double nNum1  ;
    List *pList,*pList2,*pList3,*pList4  ;
    Item *pItem  ;
    pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
    if ( RING_VM_STACK_ISSTRING ) {
        ring_list_addstring2_gc(pVM->pRingState,pList, RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
        RING_VM_STACK_POP ;
    }
    else if ( RING_VM_STACK_ISNUMBER ) {
        ring_list_adddouble_gc(pVM->pRingState,pList, RING_VM_STACK_READN);
        RING_VM_STACK_POP ;
    }
    else if ( RING_VM_STACK_ISPOINTER ) {
        /* We use a Temp. list (pList4) to support adding the list to itself by value */
        pList4 = ring_list_new_gc(pVM->pRingState,0);
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pList2 = (List *) RING_VM_STACK_READP ;
            RING_VM_STACK_POP ;
            pList2 = ring_list_getlist(pList2,RING_VAR_VALUE);
            pList3 = ring_list_newlist_gc(pVM->pRingState,pList);
            ring_vm_list_copy(pVM,pList4,pList2);
            ring_list_swaptwolists(pList3,pList4);
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) RING_VM_STACK_READP ;
            RING_VM_STACK_POP ;
            pList2 = ring_item_getlist(pItem);
            pList3 = ring_list_newlist_gc(pVM->pRingState,pList);
            ring_vm_list_copy(pVM,pList4,pList2);
            ring_list_swaptwolists(pList3,pList4);
        }
        ring_list_delete_gc(pVM->pRingState,pList4);
    }
}

void ring_vm_listend ( VM *pVM )
{
    pVM->nListStart-- ;
    ring_list_deleteitem_gc(pVM->pRingState,pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
}

void ring_vm_loadindexaddress ( VM *pVM )
{
    double nNum1  ;
    List *pVar  ;
    Item *pItem  ;
    char cStr2[2]  ;
    String *pString  ;
    if ( RING_VM_STACK_ISNUMBER ) {
        nNum1 = RING_VM_STACK_READN ;
        RING_VM_STACK_POP ;
        if ( RING_VM_STACK_ISPOINTER ) {
            if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
                pVar = (List *) RING_VM_STACK_READP ;
                if ( ring_list_islist(pVar,RING_VAR_VALUE) ) {
                    pVar = ring_list_getlist(pVar,RING_VAR_VALUE);
                    /* Check that it's list not object */
                    if ( ring_vm_oop_isobject(pVar) == 1 ) {
                        ring_vm_expr_npoo(pVM,"[]",nNum1);
                        return ;
                    }
                    RING_VM_STACK_POP ;
                    if ( nNum1 < 1 || nNum1 > ring_list_getsize(pVar) ) {
                        ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
                        return ;
                    }
                    pItem = ring_list_getitem(pVar,nNum1);
                    RING_VM_STACK_PUSHPVALUE(pItem);
                }
                else if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
                    RING_VM_STACK_POP ;
                    if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL ) {
                        ring_vm_error(pVM,RING_VM_ERROR_USINGNULLVARIABLE);
                        return ;
                    }
                    pString = ring_list_getstringobject(pVar,RING_VAR_VALUE) ;
                    ring_vm_string_index(pVM,pString,nNum1);
                    return ;
                }
                else {
                    RING_VM_STACK_POP ;
                    ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
                    return ;
                }
            }
            else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
                pItem = (Item *) RING_VM_STACK_READP ;
                if ( ring_item_islist(pItem) ) {
                    pVar = ring_item_getlist(pItem);
                    /* Check that it's list not object */
                    if ( ring_vm_oop_isobject(pVar) == 1 ) {
                        ring_vm_expr_npoo(pVM,"[]",nNum1);
                        return ;
                    }
                    RING_VM_STACK_POP ;
                    if ( nNum1 < 1 || nNum1 > ring_list_getsize(pVar) ) {
                        ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
                        return ;
                    }
                    pItem = ring_list_getitem(pVar,nNum1);
                    RING_VM_STACK_PUSHPVALUE(pItem);
                }
                else if ( ring_item_isstring(pItem) ) {
                    RING_VM_STACK_POP ;
                    pString = ring_item_getstring(pItem);
                    ring_vm_string_index(pVM,pString,nNum1);
                    return ;
                }
                else {
                    RING_VM_STACK_POP ;
                    ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
                    return ;
                }
            }
            else {
                ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
                return ;
            }
        }
        else if ( RING_VM_STACK_ISSTRING ) {
            cStr2[0] = RING_VM_STACK_READC[((int) nNum1)-1] ;
            cStr2[1] = '\0' ;
            RING_VM_STACK_SETCVALUE2(cStr2,1);
            return ;
        }
        else {
            ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
            return ;
        }
        RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
    }
    else if ( RING_VM_STACK_ISSTRING ) {
        pString = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
        RING_VM_STACK_POP ;
        /* Use String to find the item */
        if ( RING_VM_STACK_ISPOINTER ) {
            if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
                pVar = (List *) RING_VM_STACK_READP ;
                RING_VM_STACK_POP ;
                if ( ring_list_islist(pVar,RING_VAR_VALUE) ) {
                    pVar = ring_list_getlist(pVar,RING_VAR_VALUE);
                    /* Check that it's list not object */
                    if ( ring_vm_oop_isobject(pVar) == 1 ) {
                        pVM->nSP++ ;
                        ring_vm_expr_spoo(pVM,"[]",ring_string_get(pString),ring_string_size(pString));
                    }
                    else {
                        ring_vm_listgetvalue(pVM,pVar,ring_string_get(pString));
                    }
                }
                else {
                    ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
                }
            }
            else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
                pItem = (Item *) RING_VM_STACK_READP ;
                RING_VM_STACK_POP ;
                if ( ring_item_islist(pItem) ) {
                    pVar = ring_item_getlist(pItem);
                    /* Check that it's list not object */
                    if ( ring_vm_oop_isobject(pVar) == 1 ) {
                        pVM->nSP++ ;
                        ring_vm_expr_spoo(pVM,"[]",ring_string_get(pString),ring_string_size(pString));
                    }
                    else {
                        ring_vm_listgetvalue(pVM,pVar,ring_string_get(pString));
                    }
                }
                else {
                    ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
                }
            }
            else {
                ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
            }
        }
        else {
            ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
            /* Don't return here, we need to delete the string to avoid memory leak */
        }
        ring_string_delete_gc(pVM->pRingState,pString);
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
    }
}

void ring_vm_listpushv ( VM *pVM )
{
    Item *pItem  ;
    pItem = (Item *) RING_VM_STACK_READP ;
    RING_VM_STACK_POP ;
    /* Push Item Data */
    if ( ring_item_gettype(pItem) == ITEMTYPE_STRING ) {
        if ( (pVM->nRetItemRef>=1)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
            RING_VM_STACK_PUSHPVALUE(pItem);
            RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
            pVM->nRetItemRef-- ;
            return ;
        }
        pVM->nSP++ ;
        RING_VM_STACK_SETCVALUE2(ring_string_get(ring_item_getstring(pItem)),ring_string_size(ring_item_getstring(pItem)));
    }
    else if ( ring_item_gettype(pItem) == ITEMTYPE_NUMBER ) {
        if ( (pVM->nRetItemRef>=1)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
            RING_VM_STACK_PUSHPVALUE(pItem);
            RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
            pVM->nRetItemRef-- ;
            return ;
        }
        RING_VM_STACK_PUSHNVALUE(ring_item_getnumber(pItem));
    }
    else if ( ring_item_gettype(pItem) == ITEMTYPE_LIST ) {
        if ( (pVM->nRetItemRef>=1)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
            pVM->nRetItemRef-- ;
        }
        RING_VM_STACK_PUSHPVALUE(pItem);
        RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
        ring_vm_oop_setbraceobj(pVM, (List *) ring_item_getlist(pItem));
    }
}

void ring_vm_listassignment ( VM *pVM )
{
    Item *pItem  ;
    String *cStr1, *pString  ;
    double nNum1  ;
    List *pList,*pVar, *pTempList  ;
    pVar = NULL ;
    if ( (RING_VM_STACK_ISSTRING) && (pVM->nBeforeEqual <= 1) ) {
        cStr1 = RING_VM_STACK_GETSTRINGRAW ;
        assert(cStr1 != NULL);
        RING_VM_STACK_POP ;
        pItem = (Item *) RING_VM_STACK_READP ;
        assert(pItem != NULL);
        RING_VM_STACK_POP ;
        if ( pVM->nBeforeEqual == 0 ) {
            ring_item_setstring2_gc(pVM->pRingState,pItem, ring_string_get(cStr1),ring_string_size(cStr1));
        }
        else {
            if ( ring_item_isstring(pItem) ) {
                pString = ring_item_getstring(pItem);
                ring_string_add2_gc(pVM->pRingState,pString,ring_string_get(cStr1),ring_string_size(cStr1));
            }
            else if ( ring_item_isdouble(pItem) ) {
                ring_item_setdouble_gc(pVM->pRingState,pItem,ring_item_getdouble(pItem)+ring_vm_stringtonum(pVM,ring_string_get(cStr1)));
            }
        }
    }
    else if ( RING_VM_STACK_ISNUMBER ) {
        nNum1 = RING_VM_STACK_READN ;
        RING_VM_STACK_POP ;
        pItem = (Item *) RING_VM_STACK_READP ;
        assert(pItem != NULL);
        RING_VM_STACK_POP ;
        if ( pVM->nBeforeEqual == 0 ) {
            ring_item_setdouble_gc(pVM->pRingState,pItem , nNum1);
        }
        else {
            ring_vm_beforeequalitem(pVM,pItem,nNum1);
        }
    }
    else if ( (RING_VM_STACK_ISPOINTER) && (pVM->nBeforeEqual == 0) ) {
        /* Get Source */
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pVar = (List *) RING_VM_STACK_READP ;
            pVar = ring_list_getlist(pVar,RING_VAR_VALUE);
        }
        else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) RING_VM_STACK_READP ;
            pVar = ring_item_getlist(pItem);
        }
        RING_VM_STACK_POP ;
        pItem = (Item *) RING_VM_STACK_READP ;
        RING_VM_STACK_POP ;
        ring_item_settype_gc(pVM->pRingState,pItem,ITEMTYPE_LIST);
        pList = ring_item_getlist(pItem);
        ring_list_deleteallitems_gc(pVM->pRingState,pList);
        if ( pVar->lCopyByRef ) {
            pVar->lCopyByRef = 0 ;
            ring_list_swaptwolists(pList,pVar);
        }
        else {
            pTempList = ring_list_new_gc(pVM->pRingState,0);
            ring_vm_list_copy(pVM,pTempList,pVar);
            ring_list_swaptwolists(pList,pTempList);
            /* Update self object Pointer */
            if ( ring_vm_oop_isobject(pList) ) {
                ring_vm_oop_updateselfpointer(pVM,pList,RING_OBJTYPE_LISTITEM,pItem);
            }
            ring_list_delete_gc(pVM->pRingState,pTempList);
        }
    }
    else {
        ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
    }
}

void ring_vm_listgetvalue ( VM *pVM,List *pVar,const char *cStr )
{
    int x  ;
    List *pList  ;
    Item *pItem  ;
    const char *cStr2  ;
    if ( ring_list_getsize(pVar) > 0 ) {
        for ( x = 1 ; x <= ring_list_getsize(pVar) ; x++ ) {
            if ( ring_list_islist(pVar,x) ) {
                pList = ring_list_getlist(pVar,x);
                if ( ring_list_getsize(pList)  >= RING_LISTHASH_SIZE ) {
                    if ( ring_list_isstring(pList,RING_LISTHASH_KEY) ) {
                        cStr2 = ring_list_getstring(pList,RING_LISTHASH_KEY);
                        if ( ring_vm_strcmpnotcasesensitive(cStr,cStr2)  == 0 ) {
                            pItem = ring_list_getitem(pList,RING_LISTHASH_VALUE);
                            RING_VM_STACK_PUSHPVALUE(pItem);
                            RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
                            return ;
                        }
                    }
                }
            }
        }
    }
    /* Add Item if not found */
    pList = ring_list_newlist_gc(pVM->pRingState,pVar);
    ring_list_addstring_gc(pVM->pRingState,pList,cStr);
    ring_list_addstring_gc(pVM->pRingState,pList,"");
    pItem = ring_list_getitem(pList,RING_LISTHASH_VALUE);
    RING_VM_STACK_PUSHPVALUE(pItem);
    RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
}

int ring_vm_strcmpnotcasesensitive ( const char *cStr1,const char *cStr2 )
{
    int nNum1  ;
    while ( 1 ) {
        nNum1 = tolower(*cStr1) - tolower(*cStr2) ;
        if ( nNum1 != 0 || !*cStr1 || !*cStr2 ) {
            return nNum1 ;
        }
        cStr1++ ;
        cStr2++ ;
    }
}

void ring_vm_cleansetpropertylist ( VM *pVM )
{
    if ( ring_list_getsize(pVM->aSetProperty) > 0 ) {
        ring_list_deleteitem_gc(pVM->pRingState,pVM->aSetProperty,ring_list_getsize(pVM->aSetProperty));
    }
}

int ring_vm_isoperationaftersublist ( VM *pVM )
{
    int nOPCode  ;
    List *pParent, *pSub, *pVar  ;
    if ( pVM->nListStart > 0 ) {
        nOPCode = (pVM->pByteCode + pVM->nPC - 3)->aData[0]->data.iNumber ;
        if ( nOPCode == ICO_LISTEND ) {
            /* Get the Parent List */
            pParent = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
            /* Get the Sub List */
            pSub = ring_list_getlist(pParent,ring_list_getsize(pParent));
            /* Create a Temp. variable for the sub list */
            ring_vm_createtemplist(pVM);
            pVar = (List *) RING_VM_STACK_READP ;
            ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_LIST);
            ring_list_setlist_gc(pVM->pRingState,pVar, RING_VAR_VALUE);
            ring_list_deleteallitems_gc(pVM->pRingState,ring_list_getlist(pVar,RING_VAR_VALUE));
            ring_vm_list_copy(pVM,ring_list_getlist(pVar,RING_VAR_VALUE),pSub);
            /* Delete the sub list from the Parent List */
            ring_list_deleteitem_gc(pVM->pRingState,pParent,ring_list_getsize(pParent));
            return 1 ;
        }
    }
    return 0 ;
}
