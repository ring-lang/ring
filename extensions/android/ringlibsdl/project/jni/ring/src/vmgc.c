/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Item GC Functions */

void ring_vm_gc_checknewreference ( void *pPointer,int nType, List *pContainer, int nIndex )
{
    Item *pItem  ;
    /*
    **  Called when we create new pointer (new reference) 
    **  The reference may be to a list or a sublist (list item) 
    **  We care only about list items (sublists) 
    */
    if ( nType == RING_OBJTYPE_LISTITEM ) {
        pItem = (Item *) pPointer ;
        pItem->gcnReferenceCount++ ;
        /* Set the Free Function */
        pItem = ring_list_getitem(pContainer,nIndex) ;
        ring_vm_gc_setfreefunc(pItem, (void(*)(void *, void*)) ring_vm_gc_deleteitem_gc);
        #if GCLog
            printf( "\nGC CheckNewReference - To Pointer %p \n",pItem ) ;
        #endif
    }
}

void ring_vm_gc_checkupdatereference ( VM *pVM,List *pList )
{
    Item *pItem  ;
    /* Reference Counting to Destination before copy from Source */
    if ( ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_POINTER ) {
        if ( ring_list_getint(pList,RING_VAR_PVALUETYPE) == RING_OBJTYPE_LISTITEM ) {
            pItem = (Item *) ring_list_getpointer(pList,RING_VAR_VALUE) ;
            ring_item_delete_gc(pVM->pRingState,pItem);
        }
    }
}

void ring_vm_gc_deleteitem_gc ( void *pState,Item *pItem )
{
    if ( pItem->gcnReferenceCount == 0 ) {
        #if GCLog
            printf( "GC Delete Item - Free Memory %p \n",pItem ) ;
        #endif
        /* Call Free Function */
        if ( pItem->nType == ITEMTYPE_POINTER ) {
            ring_vm_gc_freefunc((RingState *) pState,pItem);
        }
        ring_item_deletecontent_gc(pState,pItem);
        ring_state_free(pState,pItem);
    }
    else {
        pItem->gcnReferenceCount-- ;
    }
}

void ring_vm_gc_killreference ( VM *pVM )
{
    List *pList, *pList2  ;
    Item *pItem  ;
    char *newstr  ;
    char cStr[2]  ;
    /* Check usage before the For In Loop, If there are a reference, set it to NULL */
    if ( RING_VM_IR_PARACOUNT > 1 ) {
        if ( RING_VM_IR_READI == 1 ) {
            /* Kill the reference */
            pList = (List *) RING_VM_STACK_READP ;
            RING_VM_STACK_POP ;
            if ( ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_POINTER ) {
                ring_list_setint_gc(pVM->pRingState,pList, RING_VAR_TYPE ,RING_VM_STRING);
                ring_list_setstring_gc(pVM->pRingState,pList,RING_VAR_VALUE,"");
            }
        }
        return ;
    }
    /* The (For In) Loop generate the ICO_KILLREFERENCE instruction that call this function */
    if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
        pList = (List *) RING_VM_STACK_READP ;
        RING_VM_STACK_POP ;
        /* If we have a String then clear it (Like using for t in "test" , i.e. using literal instead of variable) */
        if ( (ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_STRING) && (pVM->lExitFlag == 0) ) {
            ring_list_setstring_gc(pVM->pRingState,pList, RING_VAR_VALUE ,"");
            return ;
        }
        /* Be sure that it's a Pointer */
        if ( ring_list_getint(pList,RING_VAR_TYPE) != RING_VM_POINTER ) {
            return ;
        }
        /* Get the Real Value that this reference points to */
        switch ( ring_list_getint(pList,RING_VAR_PVALUETYPE) ) {
            case RING_OBJTYPE_VARIABLE :
                /* We know that this case will never happens according to how (For In) loop works */
                break ;
            case RING_OBJTYPE_LISTITEM :
                pItem = (Item *) ring_list_getpointer(pList,RING_VAR_VALUE) ;
                switch ( ring_item_gettype(pItem) ) {
                    case ITEMTYPE_STRING :
                        /* Set variable value to String */
                        ring_list_setint_gc(pVM->pRingState,pList, RING_VAR_TYPE ,RING_VM_STRING);
                        if ( pVM->lExitFlag == 1 ) {
                            ring_list_setstring2_gc(pVM->pRingState,pList, RING_VAR_VALUE , ring_string_get( ring_item_getstring(pItem) ),ring_string_size(ring_item_getstring(pItem)));
                        }
                        else {
                            ring_list_setstring_gc(pVM->pRingState,pList, RING_VAR_VALUE , "");
                        }
                        break ;
                    case ITEMTYPE_NUMBER :
                        if ( pVM->lExitFlag == 1 ) {
                            /* Set variable value to Number */
                            ring_list_setint_gc(pVM->pRingState,pList, RING_VAR_TYPE ,RING_VM_NUMBER);
                            ring_list_setdouble_gc(pVM->pRingState,pList, RING_VAR_VALUE , ring_item_getnumber(pItem));
                        }
                        else {
                            ring_list_setint_gc(pVM->pRingState,pList, RING_VAR_TYPE ,RING_VM_STRING);
                            ring_list_setstring_gc(pVM->pRingState,pList, RING_VAR_VALUE , "");
                        }
                        break ;
                    case ITEMTYPE_LIST :
                        if ( pVM->lExitFlag == 1 ) {
                            /* Set variable value to List */
                            ring_list_setint_gc(pVM->pRingState,pList, RING_VAR_TYPE ,RING_VM_LIST);
                            ring_list_setlist_gc(pVM->pRingState,pList, RING_VAR_VALUE);
                            pList2 = ring_list_getlist(pList, RING_VAR_VALUE);
                            ring_vm_list_copy(pVM,pList2,ring_item_getlist(pItem));
                        }
                        else {
                            ring_list_setint_gc(pVM->pRingState,pList, RING_VAR_TYPE ,RING_VM_STRING);
                            ring_list_setstring_gc(pVM->pRingState,pList, RING_VAR_VALUE , "");
                        }
                        break ;
                }
                /* Delete Reference (Delete item using reference counting) */
                ring_item_delete_gc(pVM->pRingState,pItem);
                break ;
            case RING_OBJTYPE_SUBSTRING :
                newstr = (char *) ring_list_getpointer(pList,RING_VAR_VALUE) ;
                cStr[0] = newstr[0] ;
                cStr[1] = '\0' ;
                /* Set variable value to String that equal the Character */
                ring_list_setint_gc(pVM->pRingState,pList, RING_VAR_TYPE ,RING_VM_STRING);
                if ( pVM->lExitFlag == 1 ) {
                    ring_list_setstring_gc(pVM->pRingState,pList, RING_VAR_VALUE ,cStr);
                }
                else {
                    ring_list_setstring_gc(pVM->pRingState,pList, RING_VAR_VALUE ,"");
                }
                break ;
        }
    }
}

void ring_vm_gc_deletetemplists ( VM *pVM )
{
    /*
    **  This function is called from Ring code by callgc() 
    **  Function Goal 
    **  When we return Lists/Pointers from functions we create variable called ring_sys_temp 
    **  This variable is created in the caller temp. memory instead of the active function scope 
    **  This is necessary because the function scope will be deleted and we need the variable 
    **  This is important because we may assign the variable to variable name 
    **  The problem happens when we have a loop that uses f1(f2()) 
    **  and f2() return a lists/pointer 
    **  The temp list/C Pointer will not be deleted until the end of the caller function 
    **  But we have a loop and this will lead to a memory leak during loop execution 
    **  When testing al_map_rgb() in Allegro Library this problem becomes critical 
    **  This function solves this problem, by deleting temp lists/C Pointers in the current scope 
    */
    if ( pVM->nInClassRegion ) {
        return ;
    }
    ring_list_deleteallitems_gc(pVM->pRingState,ring_vm_prevtempmem(pVM));
}

void ring_vm_gc_freefunc ( RingState *pState,Item *pItem )
{
    if ( pItem->gcpFreeFunc != NULL ) {
        if ( pItem->data.pPointer  != NULL ) {
            pItem->gcpFreeFunc(pState,pItem->data.pPointer);
        }
    }
}

void ring_vm_gc_setfreefunc ( Item *pItem, void (* pFreeFunc)(void *,void *) )
{
    pItem->gcpFreeFunc = pFreeFunc ;
}

void ring_vm_gc_deletelistinitem ( void *pState,void *pList )
{
    ring_list_delete_gc(pState,(List *) pList);
}

void ring_vm_gc_listpointerismine ( List *pList,int nIndex )
{
    Item *pItem  ;
    pItem = ring_list_getitem(pList,nIndex);
    ring_vm_gc_setfreefunc(pItem,ring_vm_gc_deletelistinitem);
}

void ring_vm_gc_listpointerisnotmine ( List *pList,int nIndex )
{
    Item *pItem  ;
    pItem = ring_list_getitem(pList,nIndex);
    ring_vm_gc_setfreefunc(pItem,NULL);
}
/*
**  List GC Functions 
**  Copy list by Reference 
*/

RING_API int ring_list_iscopybyref ( List *pList )
{
    return pList->gc.lCopyByRef ;
}

RING_API void ring_list_enablecopybyref ( List *pList )
{
    pList->gc.lCopyByRef = 1 ;
}

RING_API void ring_list_disablecopybyref ( List *pList )
{
    pList->gc.lCopyByRef = 0 ;
}
/* References */

RING_API void ring_list_acceptlistbyref_gc ( void *pState,List *pList, unsigned int index,List *pRef )
{
    List *pRealList  ;
    Item *pItem  ;
    /* Setting the list could be unnecessary but, we do this to have a solid function */
    ring_list_setlist_gc(pState,pList,index);
    /* Free the old list (We expect that it's an empty list) */
    pRealList = ring_list_getlist(pList,index);
    ring_list_delete_gc(pState,pRealList);
    /* Set the Item as a List reference */
    pItem = ring_list_getitem(pList,index);
    pItem->data.pList = pRef ;
}

RING_API void ring_list_setlistbyref_gc ( void *pState,List *pList, unsigned int index,List *pRef )
{
    ring_list_acceptlistbyref_gc(pState,pList,index,pRef);
    /* Increment the Reference */
    ring_list_updaterefcount_gc(pState,pRef,RING_LISTREF_INC);
}

RING_API void ring_list_updaterefcount_gc ( void *pState,List *pList, int nChange )
{
    pList->gc.nReferenceCount += nChange ;
}

RING_API List * ring_list_newref_gc ( void *pState, List *pVariableList, List *pList )
{
    /* Note: The list may already have a container variable (Previous Reference) */
    pList->gc.lNewRef = 1 ;
    if ( pList->gc.pContainer == NULL ) {
        ring_list_acceptlistbyref_gc(pState,pVariableList,RING_VAR_VALUE,pList);
        /* If we have a reference to an object, the Self attribute will stay pointing to the Container Variable */
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_oop_updateselfpointer(((RingState *) pState)->pVM,pList,RING_OBJTYPE_VARIABLE,pVariableList);
        }
        /* We use lDontDelete to avoid deleting the container variable */
        pVariableList->gc.lDontDelete = 1 ;
        /* When deleting the list (No other references exist) - It will delete the container variable */
        pList->gc.lDeleteContainerVariable = 1 ;
        pList->gc.pContainer = pVariableList ;
    }
    else {
        /* Delete the unused container */
        ring_list_delete_gc(pState,pVariableList);
        pVariableList = (List *) pList->gc.pContainer ;
    }
    return pVariableList ;
}

RING_API int ring_list_isref ( List *pList )
{
    return (pList->gc.nReferenceCount > 0 ) || ( pList->gc.lNewRef == 1) ;
}

RING_API void ring_list_assignreftovar_gc ( void *pState,List *pRef,List *pVar,unsigned int nPos )
{
    pRef->gc.lNewRef = 0 ;
    if ( ring_list_islist(pVar,nPos) ) {
        if ( ring_list_getlist(pVar,nPos) == pRef ) {
            return ;
        }
    }
    ring_list_setlistbyref_gc(pState,pVar,nPos,pRef);
}

RING_API void ring_list_assignreftoitem_gc ( void *pState,List *pRef,Item *pItem )
{
    List *pList  ;
    pRef->gc.lNewRef = 0 ;
    pList = ring_item_getlist(pItem);
    if ( ! ( pList == pRef ) ) {
        ring_list_delete_gc(pState,pList);
        pItem->data.pList = pRef ;
        ring_list_updaterefcount_gc(pState,pRef,RING_LISTREF_INC);
    }
}

RING_API int ring_list_isrefcontainer ( List *pList )
{
    return pList->gc.lDontDelete ;
}

RING_API void ring_list_clearrefdata ( List *pList )
{
    pList->gc.pContainer = NULL ;
    pList->gc.lCopyByRef = 0 ;
    pList->gc.lNewRef = 0 ;
    pList->gc.lDontDelete = 0 ;
    pList->gc.lDeleteContainerVariable = 0 ;
    pList->gc.nReferenceCount = 0 ;
    pList->gc.lDontRef = 0 ;
    pList->gc.lErrorOnAssignment = 0 ;
    pList->gc.lErrorOnAssignment2 = 0 ;
    pList->gc.lDeletedByParent = 0 ;
    pList->gc.lDontRefAgain = 0 ;
}

RING_API List * ring_list_deleteref_gc ( void *pState,List *pList )
{
    List *pVariable  ;
    int nOPCode  ;
    /* Check lDontDelete (Used by Container Variables) */
    if ( pList->gc.lDontDelete ) {
        /* This is a container that we will not delete, but will be deleted by that list that know about it */
        return pList ;
    }
    /* Check lErrorOnAssignment used by lists during definition */
    if ( ring_list_iserroronassignment(pList) ) {
        /* We are trying to delete a sub list which is protected */
        nOPCode = ((RingState *) pState)->pVM->nOPCode ;
        if ( (nOPCode == ICO_ASSIGNMENT) || (nOPCode == ICO_LISTSTART) || (nOPCode == ICO_NEWOBJ) ) {
            pList->gc.lDeletedByParent = 1 ;
            return pList ;
        }
    }
    /* Avoid deleting objects when the list is just a reference */
    if ( ring_list_isref(pList) ) {
        /* We don't delete the list because there are other references */
        pList->gc.lNewRef = 0 ;
        if ( ring_list_getrefcount(pList) > 1 ) {
            ring_list_updaterefcount_gc(pState,pList,RING_LISTREF_DEC);
            pList = ring_list_collectcycles_gc(pState,pList);
        }
        else {
            ring_list_addpointer_gc(pState,((RingState *) pState)->pVM->aDeleteLater,pList);
        }
        return pList ;
    }
    /* Delete Container Variable (If the list have one) */
    if ( pList->gc.lDeleteContainerVariable ) {
        pVariable = (List *) pList->gc.pContainer ;
        pList->gc.lDeleteContainerVariable = 0 ;
        pList->gc.pContainer = NULL ;
        /* Delete the Container */
        pVariable->gc.lDontDelete = 0 ;
        pVariable->gc.nReferenceCount = 0 ;
        ring_list_delete_gc(pState,pVariable);
        return NULL ;
    }
    ring_list_deletecontent_gc(pState,pList);
    return NULL ;
}

RING_API List * ring_list_getrefcontainer ( List *pList )
{
    return (List *) pList->gc.pContainer ;
}

RING_API List * ring_list_collectcycles_gc ( void *pState,List *pList )
{
    List *aProcess, *pActiveList, *pSubList  ;
    int x,y,lDelete  ;
    Item *pItem  ;
    /* Be sure that we have a circular list */
    if ( ! ring_list_iscircular_gc(pState,pList) ) {
        return pList ;
    }
    /* Create the List */
    aProcess = ring_list_new_gc(pState,0);
    /* Add the Root */
    ring_list_addpointer_gc(pState,aProcess,pList);
    /*
    **  Process the List 
    **  Set nTempRC to -1 for all references and be sure that we have circular reference 
    */
    for ( x = 1 ; x <= ring_list_getsize(aProcess) ; x++ ) {
        pActiveList = (List *) ring_list_getpointer(aProcess,x);
        for ( y = 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
            if ( ring_list_islist(pActiveList,y) ) {
                pSubList = ring_list_getlist(pActiveList,y);
                pSubList->gc.nTempRC = -1 ;
                if ( ! ring_list_findpointer(aProcess,pSubList) ) {
                    ring_list_addpointer_gc(pState,aProcess,pSubList);
                }
            }
        }
    }
    /* Delete all items in aProcess except the Root */
    while ( ring_list_getsize(aProcess) > 1 ) {
        ring_list_deleteitem_gc(pState,aProcess,ring_list_getsize(aProcess));
    }
    /* Increment nTempRC for each reference even if it's repeated but follow each reference once */
    for ( x = 1 ; x <= ring_list_getsize(aProcess) ; x++ ) {
        pActiveList = (List *) ring_list_getpointer(aProcess,x);
        for ( y = 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
            if ( ring_list_islist(pActiveList,y) ) {
                pSubList = ring_list_getlist(pActiveList,y);
                pSubList->gc.nTempRC++ ;
                if ( ! ring_list_findpointer(aProcess,pSubList) ) {
                    ring_list_addpointer_gc(pState,aProcess,pSubList);
                }
            }
        }
    }
    /* Delete all items in aProcess except the Root */
    while ( ring_list_getsize(aProcess) > 1 ) {
        ring_list_deleteitem_gc(pState,aProcess,ring_list_getsize(aProcess));
    }
    /* Be sure that we don't have external references */
    lDelete = 1 ;
    for ( x = 1 ; x <= ring_list_getsize(aProcess) ; x++ ) {
        pActiveList = (List *) ring_list_getpointer(aProcess,x);
        for ( y = 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
            if ( ring_list_islist(pActiveList,y) ) {
                pSubList = ring_list_getlist(pActiveList,y);
                if ( (pSubList != pList) && ring_list_containssublist_gc(pState,pSubList,pList) ) {
                    if ( pSubList->gc.nReferenceCount > pSubList->gc.nTempRC ) {
                        lDelete = 0 ;
                        break ;
                    }
                }
                if ( ! ring_list_findpointer(aProcess,pSubList) ) {
                    ring_list_addpointer_gc(pState,aProcess,pSubList);
                }
            }
        }
    }
    /* Check if we can delete the Cycle */
    if ( (pList->gc.nReferenceCount <= pList->gc.nTempRC ) && (lDelete==1) ) {
        /*
        **  Delete the Cycle 
        **  Delete all items in aProcess except the Root 
        */
        while ( ring_list_getsize(aProcess) > 1 ) {
            ring_list_deleteitem_gc(pState,aProcess,ring_list_getsize(aProcess));
        }
        /* Convert the item that contains circular reference from List to Empty String (To be able to delete it) */
        for ( x = 1 ; x <= ring_list_getsize(aProcess) ; x++ ) {
            pActiveList = (List *) ring_list_getpointer(aProcess,x);
            for ( y = 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
                if ( ring_list_islist(pActiveList,y) ) {
                    pSubList = ring_list_getlist(pActiveList,y);
                    if ( ! ring_list_findpointer(aProcess,pSubList) ) {
                        ring_list_addpointer_gc(pState,aProcess,pSubList);
                    }
                    if ( pSubList == pList ) {
                        pItem = ring_list_getitem(pActiveList,y);
                        pItem->nType = ITEMTYPE_STRING ;
                        pItem->data.pString = ring_string_new_gc(pState,"") ;
                    }
                }
            }
        }
        /* It's important to set nReferenceCount to 0 because the same reference may contains many circular references */
        pList->gc.nReferenceCount = 0 ;
        pList = ring_list_delete_gc(pState,pList);
    }
    /* Delete the List */
    aProcess = ring_list_delete_gc(pState,aProcess);
    return pList ;
}

RING_API int ring_list_containssublist_gc ( void *pState,List *pList,List *pCheck )
{
    List *aProcess, *pActiveList, *pSubList  ;
    int x,y,lFound  ;
    /* Check if the List is a circular reference */
    lFound = 0 ;
    aProcess = ring_list_new_gc(pState,0);
    ring_list_addpointer_gc(pState,aProcess,pList);
    for ( x = 1 ; x <= ring_list_getsize(aProcess) ; x++ ) {
        pActiveList = (List *) ring_list_getpointer(aProcess,x);
        for ( y = 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
            if ( ring_list_islist(pActiveList,y) ) {
                pSubList = ring_list_getlist(pActiveList,y);
                if ( ! ring_list_findpointer(aProcess,pSubList) ) {
                    ring_list_addpointer_gc(pState,aProcess,pSubList);
                }
                if ( pSubList == pCheck ) {
                    lFound = 1 ;
                    break ;
                }
            }
        }
    }
    aProcess = ring_list_delete_gc(pState,aProcess);
    return lFound ;
}

RING_API int ring_list_iscircular_gc ( void *pState,List *pList )
{
    return ring_list_containssublist_gc(pState,pList,pList) ;
}

RING_API int ring_list_checkrefinleftside ( void *pState,List *pList )
{
    /* If we have Ref()/Reference() at the Left-Side then Delete the reference */
    if ( pList->gc.lNewRef ) {
        pList->gc.lNewRef = 0 ;
        return 1 ;
    }
    return 0 ;
}

RING_API int ring_list_checkrefvarinleftside ( void *pState,List *pVar )
{
    /*
    **  Check Temp. Reference variable 
    **  Because of this function, we have RING_TEMP_VAR & RING_TEMP_REF 
    **  If we used RING_TEMP_VAR in all cases (Even when we create var using Ref()) 
    **  This could prevent assignment to variables contains temp. lists created while passing para. to functions 
    */
    if ( strcmp(ring_list_getstring(pVar,RING_VAR_NAME),RING_TEMP_REF) == 0 ) {
        return 1 ;
    }
    if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_LIST ) {
        if ( ring_list_islist(pVar,RING_VAR_VALUE) ) {
            return ring_list_checkrefinleftside(pState,ring_list_getlist(pVar,RING_VAR_VALUE)) ;
        }
    }
    return 0 ;
}

RING_API int ring_list_getrefcount ( List *pList )
{
    return pList->gc.nReferenceCount + 1 ;
}

RING_API int ring_list_isrefparameter ( VM *pVM,const char *cVariable )
{
    int lRef  ;
    List *pRef, *pVar, *pList  ;
    lRef = 0 ;
    /* Check Reference */
    if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
        pList = (List *) RING_VM_STACK_READP ;
        if ( ring_list_isrefcontainer(pList) ) {
            pRef = ring_list_getlist(pList,RING_VAR_VALUE);
            if ( pRef->gc.lNewRef ) {
                lRef = 1 ;
                pVar = ring_vm_addlistarg(pVM,cVariable);
                ring_list_assignreftovar_gc(pVM->pRingState,pRef,pVar,RING_VAR_VALUE);
                /* If the same reference is passed as parameter multiple times then keep treating it as new reference */
                pRef->gc.lNewRef = 1 ;
            }
        }
    }
    return lRef ;
}

RING_API int ring_list_isdontref ( List *pList )
{
    return pList->gc.lDontRef ;
}

RING_API void ring_list_enabledontref ( List *pList )
{
    pList->gc.lDontRef = 1 ;
}

RING_API void ring_list_disabledontref ( List *pList )
{
    pList->gc.lDontRef = 0 ;
}

RING_API void ring_list_disablelnewref ( List *pRef )
{
    pRef->gc.lNewRef = 0 ;
}

RING_API void ring_list_resetlnewref ( List *pVar )
{
    List *pList  ;
    if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_LIST ) {
        pList = ring_list_getlist(pVar,RING_VAR_VALUE) ;
        ring_list_disablelnewref(pList);
    }
}

RING_API int ring_list_isnewref ( List *pList )
{
    return pList->gc.lNewRef ;
}

RING_API int ring_list_isdontrefagain ( List *pList )
{
    return pList->gc.lDontRefAgain ;
}

RING_API void ring_list_enabledontrefagain ( List *pList )
{
    pList->gc.lDontRefAgain = 1 ;
}

RING_API void ring_list_disabledontrefagain ( List *pList )
{
    pList->gc.lDontRefAgain = 0 ;
}
/* Protecting lists */

RING_API void ring_list_enableerroronassignment ( List *pList )
{
    pList->gc.lErrorOnAssignment = 1 ;
}

RING_API void ring_list_disableerroronassignment ( List *pList )
{
    pList->gc.lErrorOnAssignment = 0 ;
}

RING_API int ring_list_iserroronassignment ( List *pList )
{
    return pList->gc.lErrorOnAssignment ;
}

int ring_vm_checkvarerroronassignment ( VM *pVM,List *pVar )
{
    List *pList  ;
    if ( ring_list_islist(pVar,RING_VAR_VALUE) ) {
        pList = ring_list_getlist(pVar,RING_VAR_VALUE) ;
        if ( ring_list_iserroronassignment(pList) || ring_list_iserroronassignment2(pList) ) {
            ring_vm_error(pVM,RING_VM_ERROR_PROTECTEDVALUE);
            return 1 ;
        }
    }
    return 0 ;
}

int ring_vm_checkitemerroronassignment ( VM *pVM,Item *pItem )
{
    List *pList  ;
    if ( ring_item_gettype(pItem) == ITEMTYPE_LIST ) {
        pList = ring_item_getlist(pItem) ;
        if ( ring_list_iserroronassignment(pList) || ring_list_iserroronassignment2(pList) ) {
            ring_vm_error(pVM,RING_VM_ERROR_PROTECTEDVALUE);
            return 1 ;
        }
    }
    return 0 ;
}

int ring_vm_checkbeforeassignment ( VM *pVM,List *pVar )
{
    /*
    **  Check if the content is protected (List during definition) 
    **  Also, Check Ref()/Reference() usage in the Left-Side 
    */
    if ( ring_list_checkrefvarinleftside(pVM->pRingState,pVar) || ring_vm_checkvarerroronassignment(pVM,pVar) ) {
        /*
        **  Take in mind using Ref()/Reference() in Right-Side too 
        **  I.e. Ref(tmp) = Ref(tmp) 
        **  We don't need to think about it - Because it's like Ref( Ref( Ref( ....) ) ) 
        */
        return 1 ;
    }
    return 0 ;
}

void ring_vm_removelistprotection ( VM *pVM,List *pNestedLists )
{
    int x  ;
    List *pList  ;
    for ( x = 1 ; x <= ring_list_getsize(pNestedLists) ; x++ ) {
        ring_vm_removelistprotectionat(pVM,pNestedLists,x);
    }
}

void ring_vm_removelistprotectionat ( VM *pVM,List *pNestedLists,int nPos )
{
    List *pList  ;
    /* Disable Error on Assignment */
    pList = (List *) ring_list_getpointer(pNestedLists,nPos);
    ring_list_disableerroronassignment(pList);
    /* Check if list is deleted by Parent */
    if ( pList->gc.lDeletedByParent ) {
        pList->gc.lDeletedByParent = 0 ;
        ring_list_delete_gc(pVM->pRingState,pList);
    }
}

RING_API int ring_list_iserroronassignment2 ( List *pList )
{
    return pList->gc.lErrorOnAssignment2 ;
}

RING_API void ring_list_enableerroronassignment2 ( List *pList )
{
    pList->gc.lErrorOnAssignment2 = 1 ;
}

RING_API void ring_list_disableerroronassignment2 ( List *pList )
{
    pList->gc.lErrorOnAssignment2 = 0 ;
}
/* Memory Functions (General) */

RING_API void * ring_malloc ( size_t size )
{
    void *pMemory  ;
    pMemory = malloc(size) ;
    /* Check Memory */
    if ( pMemory == NULL ) {
        printf( RING_OOM ) ;
        printf( "Ring (MALLOC) - Can't allocate %lu bytes\n",(unsigned long) size ) ;
        exit(1);
    }
    return pMemory ;
}

RING_API void ring_free ( void *ptr )
{
    free( ptr ) ;
}

RING_API void * ring_calloc ( size_t nitems, size_t size )
{
    void *pMemory  ;
    pMemory = calloc(nitems,size) ;
    /* Check Memory */
    if ( pMemory == NULL ) {
        printf( RING_OOM ) ;
        printf( "Ring (CALLOC) - Can't allocate %lu bytes\n",(unsigned long) (nitems*size) ) ;
        exit(1);
    }
    return pMemory ;
}

RING_API void * ring_realloc ( void *ptr, size_t size )
{
    void *pMemory  ;
    pMemory = realloc(ptr,size) ;
    /* Check Memory */
    if ( pMemory == NULL ) {
        printf( RING_OOM ) ;
        printf( "Ring (REALLOC) - Can't allocate %lu bytes\n",(unsigned long) size ) ;
        exit(1);
    }
    return pMemory ;
}
/* Memory Functions (RingState Aware) */

RING_API void * ring_state_malloc ( void *pState,size_t size )
{
    #if RING_USEPOOLMANAGER
        if ( pState != NULL ) {
            #if RING_TRACKALLOCATIONS
                ((RingState *) pState)->vPoolManager.nAllocCount++ ;
            #endif
            if ( ! ((RingState *) pState)->lDisablePoolManager ) {
                if ( ((RingState *) pState)->pVM != NULL ) {
                    if ( size <= sizeof(PoolDataL3) ) {
                        return ring_poolmanager_allocate((RingState *) pState,size) ;
                    }
                }
            }
        }
    #endif
    return ring_malloc(size) ;
}

RING_API void ring_state_free ( void *pState,void *pMemory )
{
    void *pBlockStart  ;
    void *pBlockEnd  ;
    List *pBlocks, *pBlock  ;
    int x  ;
    RingState *pRingState  ;
    pRingState = (RingState *) pState ;
    #if RING_USEPOOLMANAGER
        /* Use Pool Manager */
        if ( pState != NULL ) {
            #if RING_TRACKALLOCATIONS
                ((RingState *) pState)->vPoolManager.nFreeCount++ ;
            #endif
            if ( ring_poolmanager_free(((RingState *) pState),pMemory) ) {
                return ;
            }
        }
    #endif
    /* Check sections inside Memory Blocks */
    if ( pRingState != NULL ) {
        pBlocks = pRingState->vPoolManager.aBlocks ;
        if ( (pBlocks != NULL) && (! pRingState->lDontCheckStateBlocks) ) {
            if ( ring_list_getsize(pBlocks) > 0 ) {
                for ( x = 1 ; x <= ring_list_getsize(pBlocks) ; x++ ) {
                    pBlock = ring_list_getlist(pBlocks,x) ;
                    pBlockStart = ring_list_getpointer(pBlock,1);
                    pBlockEnd = ring_list_getpointer(pBlock,2);
                    if ( (pMemory >= pBlockStart) && (pMemory <= pBlockEnd) ) {
                        /* We have the memory inside a block, so we will not delete it! */
                        return ;
                    }
                }
            }
        }
    }
    ring_free(pMemory);
}

RING_API void * ring_state_calloc ( void *pState,size_t nitems, size_t size )
{
    void *pMem  ;
    size_t nTotal  ;
    #if RING_USEPOOLMANAGER
        if ( pState != NULL ) {
            #if RING_TRACKALLOCATIONS
                ((RingState *) pState)->vPoolManager.nAllocCount++ ;
            #endif
            nTotal = nitems*size ;
            if ( (nTotal <= sizeof(PoolDataL3) ) && (! ((RingState *) pState)->lDisablePoolManager) ) {
                if ( ((RingState *) pState)->pVM != NULL ) {
                    pMem = ring_poolmanager_allocate((RingState *) pState,nTotal) ;
                    memset(pMem,0,nTotal);
                    return pMem ;
                }
            }
        }
    #endif
    return ring_calloc(nitems,size) ;
}

RING_API void * ring_state_realloc ( void *pState,void *ptr,size_t nAllocatedSize,size_t size )
{
    #if RING_USEPOOLMANAGER
        void *pMemory  ;
        PoolData *pPoolData  ;
        PoolDataL2 *pPoolDataL2  ;
        PoolDataL3 *pPoolDataL3  ;
        int x, nLevel, nUseMalloc  ;
        nUseMalloc = 0 ;
        if ( pState != NULL ) {
            #if RING_TRACKALLOCATIONS
                ((RingState *) pState)->vPoolManager.nAllocCount++ ;
            #endif
            if ( ((RingState *) pState)->pVM != NULL ) {
                nLevel = ring_poolmanager_find((RingState *) pState,ptr) ;
                /* Level 1 */
                if ( nLevel == 1 ) {
                    pPoolData = (PoolData*) ptr ;
                    if ( size <= sizeof(PoolData) ) {
                        /*
                        **  The Pointer belong to memory pool and new size less than RING_POOLMANAGER_ITEMSIZE 
                        **  In this case, just return the same pointer since we have space for the new data 
                        */
                        return ptr ;
                    }
                    else {
                        nUseMalloc = 1 ;
                    }
                }
                /* Level 2 */
                else if ( nLevel == 2 ) {
                    pPoolDataL2 = (PoolDataL2*) ptr ;
                    if ( size <= sizeof(PoolDataL2) ) {
                        return ptr ;
                    }
                    else {
                        nUseMalloc = 1 ;
                    }
                }
                /* Level 3 */
                else if ( nLevel == 3 ) {
                    pPoolDataL3 = (PoolDataL3*) ptr ;
                    if ( size <= sizeof(PoolDataL3) ) {
                        return ptr ;
                    }
                    else {
                        nUseMalloc = 1 ;
                    }
                }
                if ( nUseMalloc == 1 ) {
                    /* Allocate new buffer, copy data to it and then free existing pointer from pool */
                    pMemory = ring_state_malloc(pState,size);
                    /* Copy existing data */
                    for ( x = 0 ; x < nAllocatedSize ; x++ ) {
                        ((unsigned char*) pMemory)[x] = ((unsigned char*) ptr)[x] ;
                    }
                    ring_poolmanager_free(((RingState *) pState),ptr);
                    return pMemory ;
                }
            }
        }
    #endif
    return ring_realloc(ptr,size) ;
}

RING_API void ring_state_registerblock ( void *pState,void *pStart, void *pEnd )
{
    List *pList  ;
    RingState *pRingState  ;
    pRingState = (RingState *) pState ;
    pRingState->lDontCheckStateBlocks = 1 ;
    pList = ring_list_newlist_gc(pRingState,pRingState->vPoolManager.aBlocks);
    ring_list_addpointer_gc(pRingState,pList,pStart);
    ring_list_addpointer_gc(pRingState,pList,pEnd);
    pRingState->lDontCheckStateBlocks = 0 ;
}

RING_API void ring_state_unregisterblock ( void *pState,void *pStart )
{
    int x  ;
    List *pList  ;
    RingState *pRingState  ;
    pRingState = (RingState *) pState ;
    pRingState->lDontCheckStateBlocks = 1 ;
    for ( x = 1 ; x <= ring_list_getsize(pRingState->vPoolManager.aBlocks) ; x++ ) {
        pList = ring_list_getlist(pRingState->vPoolManager.aBlocks,x);
        if ( ring_list_getpointer(pList,1) == pStart ) {
            ring_list_deleteitem_gc(pRingState,pRingState->vPoolManager.aBlocks,x);
            break ;
        }
    }
    pRingState->lDontCheckStateBlocks = 0 ;
}

void ring_vm_gc_deleteitem ( Item *pItem )
{
    ring_vm_gc_deleteitem_gc(NULL,pItem);
}
/* Pool Manager Functions */

void ring_poolmanager_new ( RingState *pRingState )
{
    /* Level 1 */
    pRingState->vPoolManager.pCurrentItem = NULL ;
    pRingState->vPoolManager.pBlockStart = NULL ;
    pRingState->vPoolManager.pBlockEnd = NULL ;
    pRingState->vPoolManager.nItemsInBlock = RING_POOLMANAGER_ITEMSINBLOCK ;
    /* Level 2 */
    pRingState->vPoolManager.pCurrentItemL2 = NULL ;
    pRingState->vPoolManager.pBlockStartL2 = NULL ;
    pRingState->vPoolManager.pBlockEndL2 = NULL ;
    pRingState->vPoolManager.nItemsInBlockL2 = RING_POOLMANAGER_ITEMSINBLOCKL2 ;
    /* Level 3 */
    pRingState->vPoolManager.pCurrentItemL3 = NULL ;
    pRingState->vPoolManager.pBlockStartL3 = NULL ;
    pRingState->vPoolManager.pBlockEndL3 = NULL ;
    pRingState->vPoolManager.nItemsInBlockL3 = RING_POOLMANAGER_ITEMSINBLOCKL3 ;
    /* State Level */
    pRingState->vPoolManager.pCurrentItemStateLevel = NULL ;
    pRingState->vPoolManager.pBlockStartStateLevel = NULL ;
    pRingState->vPoolManager.pBlockEndStateLevel = NULL ;
    pRingState->vPoolManager.nItemsInBlockStateLevel = RING_POOLMANAGER_ITEMSINBLOCKStateLevel ;
    pRingState->vPoolManager.aBlocks = ring_list_new_gc(pRingState,0) ;
    pRingState->vPoolManager.lDeleteMemory = 1 ;
}

void ring_poolmanager_newblock ( RingState *pRingState )
{
    PoolData *pMemory  ;
    PoolDataL2 *pMemoryL2  ;
    PoolDataL3 *pMemoryL3  ;
    PoolDataStateLevel *pMemoryStateLevel  ;
    int x  ;
    /*
    **  Level 1 
    **  Get Block Memory 
    */
    pMemory = (PoolData *) ring_calloc(pRingState->vPoolManager.nItemsInBlock,sizeof(PoolData));
    /* Set Linked Lists (pNext values) */
    for ( x = 0 ; x < pRingState->vPoolManager.nItemsInBlock - 1 ; x++ ) {
        pMemory[x].pNext = pMemory+x+1 ;
    }
    pMemory[pRingState->vPoolManager.nItemsInBlock-1].pNext = NULL ;
    /*
    **  Set Values in Ring State 
    **  Set First Item in Ring State 
    */
    pRingState->vPoolManager.pCurrentItem = pMemory ;
    /* Set Block Start and End */
    pRingState->vPoolManager.pBlockStart = (void *) pMemory ;
    pRingState->vPoolManager.pBlockEnd = (void *) (pMemory + pRingState->vPoolManager.nItemsInBlock - 1) ;
    /*
    **  Level 2 
    **  Get Block Memory 
    */
    pMemoryL2 = (PoolDataL2 *) ring_calloc(pRingState->vPoolManager.nItemsInBlockL2,sizeof(PoolDataL2));
    /* Set Linked Lists (pNext values) */
    for ( x = 0 ; x < pRingState->vPoolManager.nItemsInBlockL2 - 1 ; x++ ) {
        pMemoryL2[x].pNext = pMemoryL2+x+1 ;
    }
    pMemoryL2[pRingState->vPoolManager.nItemsInBlockL2-1].pNext = NULL ;
    /*
    **  Set Values in Ring State 
    **  Set First Item in Ring State 
    */
    pRingState->vPoolManager.pCurrentItemL2 = pMemoryL2 ;
    /* Set Block Start and End */
    pRingState->vPoolManager.pBlockStartL2 = (void *) pMemoryL2 ;
    pRingState->vPoolManager.pBlockEndL2 = (void *) (pMemoryL2 + pRingState->vPoolManager.nItemsInBlockL2 - 1) ;
    /*
    **  Level 3 
    **  Get Block Memory 
    */
    pMemoryL3 = (PoolDataL3 *) ring_calloc(pRingState->vPoolManager.nItemsInBlockL3,sizeof(PoolDataL3));
    /* Set Linked Lists (pNext values) */
    for ( x = 0 ; x < pRingState->vPoolManager.nItemsInBlockL3 - 1 ; x++ ) {
        pMemoryL3[x].pNext = pMemoryL3+x+1 ;
    }
    pMemoryL3[pRingState->vPoolManager.nItemsInBlockL3-1].pNext = NULL ;
    /*
    **  Set Values in Ring State 
    **  Set First Item in Ring State 
    */
    pRingState->vPoolManager.pCurrentItemL3 = pMemoryL3 ;
    /* Set Block Start and End */
    pRingState->vPoolManager.pBlockStartL3 = (void *) pMemoryL3 ;
    pRingState->vPoolManager.pBlockEndL3 = (void *) (pMemoryL3 + pRingState->vPoolManager.nItemsInBlockL3 - 1) ;
    /*
    **  State Level 
    **  Get Block Memory 
    */
    pMemoryStateLevel = (PoolDataStateLevel *) ring_calloc(pRingState->vPoolManager.nItemsInBlockStateLevel,sizeof(PoolDataStateLevel));
    /* Set Linked Lists (pNext values) */
    for ( x = 0 ; x < pRingState->vPoolManager.nItemsInBlockStateLevel - 1 ; x++ ) {
        pMemoryStateLevel[x].pNext = pMemoryStateLevel+x+1 ;
    }
    pMemoryStateLevel[pRingState->vPoolManager.nItemsInBlockStateLevel-1].pNext = NULL ;
    /*
    **  Set Values in Ring State 
    **  Set First Item in Ring State 
    */
    pRingState->vPoolManager.pCurrentItemStateLevel = pMemoryStateLevel ;
    /* Set Block Start and End */
    pRingState->vPoolManager.pBlockStartStateLevel = (void *) pMemoryStateLevel ;
    pRingState->vPoolManager.pBlockEndStateLevel = (void *) (pMemoryStateLevel + pRingState->vPoolManager.nItemsInBlockStateLevel - 1) ;
    /* Set Values For Tracking Allocations */
    pRingState->vPoolManager.nAllocCount = 0 ;
    pRingState->vPoolManager.nFreeCount = 0 ;
    pRingState->vPoolManager.nSmallAllocCount = 0 ;
    pRingState->vPoolManager.nSmallFreeCount = 0 ;
}

void * ring_poolmanager_allocate ( RingState *pRingState,size_t size )
{
    void *pMemory  ;
    pMemory = NULL ;
    /* If No memory - Create new block */
    if ( (pRingState->vPoolManager.pCurrentItem == NULL) && (pRingState->vPoolManager.pBlockStart == NULL)  && (pRingState->lStartPoolManager) && (pRingState->nOnlyTokens == 0) ) {
        ring_poolmanager_newblock(pRingState);
    }
    /* Get Item from the Pool Manager */
    if ( (size <= sizeof(PoolData)) && pRingState->vPoolManager.pCurrentItem != NULL ) {
        pMemory = pRingState->vPoolManager.pCurrentItem ;
        pRingState->vPoolManager.pCurrentItem = pRingState->vPoolManager.pCurrentItem->pNext ;
    }
    /* Get Item from Pool Manager Level 2 */
    else if ( ( (size > sizeof(PoolData)) &&  (size <= sizeof(PoolDataL2)) ) && (pRingState->vPoolManager.pCurrentItemL2 != NULL) ) {
        pMemory = pRingState->vPoolManager.pCurrentItemL2 ;
        pRingState->vPoolManager.pCurrentItemL2 = pRingState->vPoolManager.pCurrentItemL2->pNext ;
    }
    /* Get Item from Pool Manager Level 3 */
    else if ( ( (size > sizeof(PoolDataL2)) &&  (size <= sizeof(PoolDataL3)) ) && (pRingState->vPoolManager.pCurrentItemL3 != NULL) ) {
        pMemory = pRingState->vPoolManager.pCurrentItemL3 ;
        pRingState->vPoolManager.pCurrentItemL3 = pRingState->vPoolManager.pCurrentItemL3->pNext ;
    }
    /* If no free items, Allocate new item */
    else {
        pMemory = ring_malloc(size);
    }
    #if RING_TRACKALLOCATIONS
        pRingState->vPoolManager.nSmallAllocCount++ ;
    #endif
    return pMemory ;
}

int ring_poolmanager_find ( RingState *pRingState,void *pMemory )
{
    if ( pRingState != NULL ) {
        /* Level 1 */
        if ( pRingState->vPoolManager.pBlockStart != NULL ) {
            if ( (pMemory >= pRingState->vPoolManager.pBlockStart) && (pMemory <= pRingState->vPoolManager.pBlockEnd ) ) {
                return 1 ;
            }
        }
        /* Level 2 */
        if ( pRingState->vPoolManager.pBlockStartL2 != NULL ) {
            if ( (pMemory >= pRingState->vPoolManager.pBlockStartL2) && (pMemory <= pRingState->vPoolManager.pBlockEndL2) ) {
                return 2 ;
            }
        }
        /* Level 3 */
        if ( pRingState->vPoolManager.pBlockStartL3 != NULL ) {
            if ( (pMemory >= pRingState->vPoolManager.pBlockStartL3) && (pMemory <= pRingState->vPoolManager.pBlockEndL3) ) {
                return 3 ;
            }
        }
    }
    /* Reaching this point means that the Pool Manager doesn't own this memory to free it! */
    return 0 ;
}

int ring_poolmanager_free ( RingState *pRingState,void *pMemory )
{
    PoolData *pPoolData  ;
    PoolDataL2 *pPoolDataL2  ;
    PoolDataL3 *pPoolDataL3  ;
    int nLevel, lRet  ;
    lRet = 0 ;
    nLevel = ring_poolmanager_find(pRingState, pMemory) ;
    if ( nLevel == 1 ) {
        pPoolData = (PoolData *) pMemory ;
        pPoolData->pNext = pRingState->vPoolManager.pCurrentItem ;
        pRingState->vPoolManager.pCurrentItem = pPoolData ;
        lRet = 1 ;
    }
    else if ( nLevel == 2 ) {
        pPoolDataL2 = (PoolDataL2 *) pMemory ;
        pPoolDataL2->pNext = pRingState->vPoolManager.pCurrentItemL2 ;
        pRingState->vPoolManager.pCurrentItemL2 = pPoolDataL2 ;
        lRet = 1 ;
    }
    else if ( nLevel == 3 ) {
        pPoolDataL3 = (PoolDataL3 *) pMemory ;
        pPoolDataL3->pNext = pRingState->vPoolManager.pCurrentItemL3 ;
        pRingState->vPoolManager.pCurrentItemL3 = pPoolDataL3 ;
        lRet = 1 ;
    }
    #if RING_TRACKALLOCATIONS
        if ( lRet ) {
            pRingState->vPoolManager.nSmallFreeCount++ ;
        }
    #endif
    /* Reaching this point and lRet=0 means that the Pool Manager doesn't own this memory to free it! */
    return lRet ;
}

void ring_poolmanager_delete ( RingState *pRingState )
{
    if ( pRingState != NULL ) {
        if ( pRingState->vPoolManager.lDeleteMemory ) {
            pRingState->vPoolManager.aBlocks = ring_list_delete_gc(pRingState,pRingState->vPoolManager.aBlocks) ;
            /* Level 1 */
            if ( pRingState->vPoolManager.pBlockStart != NULL ) {
                free( pRingState->vPoolManager.pBlockStart ) ;
                pRingState->vPoolManager.pBlockStart = NULL ;
                pRingState->vPoolManager.pBlockEnd = NULL ;
                pRingState->vPoolManager.pCurrentItem = NULL ;
            }
            /* Level 2 */
            if ( pRingState->vPoolManager.pBlockStartL2 != NULL ) {
                free( pRingState->vPoolManager.pBlockStartL2 ) ;
                pRingState->vPoolManager.pBlockStartL2 = NULL ;
                pRingState->vPoolManager.pBlockEndL2 = NULL ;
                pRingState->vPoolManager.pCurrentItemL2 = NULL ;
            }
            /* Level 3 */
            if ( pRingState->vPoolManager.pBlockStartL3 != NULL ) {
                free( pRingState->vPoolManager.pBlockStartL3 ) ;
                pRingState->vPoolManager.pBlockStartL3 = NULL ;
                pRingState->vPoolManager.pBlockEndL3 = NULL ;
                pRingState->vPoolManager.pCurrentItemL3 = NULL ;
            }
            /* State Level */
            if ( pRingState->vPoolManager.pBlockStartStateLevel != NULL ) {
                free( pRingState->vPoolManager.pBlockStartStateLevel ) ;
                pRingState->vPoolManager.pBlockStartStateLevel = NULL ;
                pRingState->vPoolManager.pBlockEndStateLevel = NULL ;
                pRingState->vPoolManager.pCurrentItemStateLevel = NULL ;
            }
        }
    }
}

void ring_poolmanager_newblockfromsubthread ( RingState *pSubRingState,int nCount,RingState *pMainRingState )
{
    int x  ;
    PoolData *pMemory  ;
    /*
    **  When we create a new thread - we share the memory pool information 
    **  So we create the memory pool items in the sub thread using memory pool items from the main thread 
    **  This avoid problems when memory pool items from different threads are used in shared global lists 
    **  Set Values in Ring State 
    **  Set First Item in Ring State 
    */
    pSubRingState->vPoolManager.pCurrentItem = (PoolData *) ring_state_calloc(pMainRingState,1,sizeof(PoolData)) ;
    /* Set Block Start and End */
    pSubRingState->vPoolManager.pBlockStart = pMainRingState->vPoolManager.pBlockStart ;
    pSubRingState->vPoolManager.pBlockEnd = pMainRingState->vPoolManager.pBlockEnd ;
    /* Set Values For Tracking Allocations */
    pSubRingState->vPoolManager.nAllocCount = 0 ;
    pSubRingState->vPoolManager.nFreeCount = 0 ;
    pSubRingState->vPoolManager.nSmallAllocCount = 0 ;
    pSubRingState->vPoolManager.nSmallFreeCount = 0 ;
    /* Don't delete the memory because it's owned by the Main Thread */
    pSubRingState->vPoolManager.lDeleteMemory = 0 ;
    /* Create the Items */
    pMemory = pSubRingState->vPoolManager.pCurrentItem ;
    for ( x = 1 ; x <= nCount-1 ; x++ ) {
        pMemory->pNext = (PoolData *) ring_state_calloc(pMainRingState,1,sizeof(PoolData)) ;
        pMemory = pMemory->pNext ;
    }
    pMemory->pNext = NULL ;
    pSubRingState->vPoolManager.nItemsInBlock = nCount ;
}

void ring_poolmanager_deleteblockfromsubthread ( RingState *pSubRingState,RingState *pMainRingState )
{
    PoolData *pMemory  ;
    pMemory = pSubRingState->vPoolManager.pCurrentItem ;
    while ( pMemory != NULL ) {
        pSubRingState->vPoolManager.pCurrentItem = pMemory->pNext ;
        /* Return Memory Back To The Main Thread */
        ring_state_free(pMainRingState,pMemory);
        pMemory = pSubRingState->vPoolManager.pCurrentItem ;
    }
}
/* VMState Memory Functions */

VMState * ring_vmstate_new ( RingState *pRingState )
{
    VMState *pVMState  ;
    #if RING_USEPOOLMANAGER
        if ( pRingState != NULL ) {
            /* Get Item from the Pool Manager */
            if ( pRingState->vPoolManager.pCurrentItemStateLevel != NULL ) {
                pVMState = (VMState *) pRingState->vPoolManager.pCurrentItemStateLevel ;
                pRingState->vPoolManager.pCurrentItemStateLevel = pRingState->vPoolManager.pCurrentItemStateLevel->pNext ;
                return pVMState ;
            }
        }
    #endif
    pVMState = (VMState *) ring_malloc(sizeof(VMState)) ;
    return pVMState ;
}

void ring_vmstate_delete ( void *pState,void *pMemory )
{
    RingState *pRingState  ;
    PoolDataStateLevel *pPoolDataStateLevel  ;
    #if RING_USEPOOLMANAGER
        if ( pState != NULL ) {
            pRingState = (RingState *) pState ;
            if ( pRingState->vPoolManager.pBlockStartStateLevel != NULL ) {
                if ( (pMemory >= pRingState->vPoolManager.pBlockStartStateLevel) && (pMemory <= pRingState->vPoolManager.pBlockEndStateLevel ) ) {
                    pPoolDataStateLevel = (PoolDataStateLevel *) pMemory ;
                    pPoolDataStateLevel->pNext = pRingState->vPoolManager.pCurrentItemStateLevel ;
                    pRingState->vPoolManager.pCurrentItemStateLevel = pPoolDataStateLevel ;
                    return ;
                }
            }
        }
    #endif
    ring_free(pMemory);
}
