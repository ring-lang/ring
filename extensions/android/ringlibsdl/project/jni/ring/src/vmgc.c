/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Item GC Functions */

void ring_vm_gc_cleardata ( Item *pItem )
{
    pItem->gc.nReferenceCount = 0 ;
    pItem->gc.pFreeFunc = NULL ;
}

void ring_vm_gc_checkreferences ( VM *pVM )
{
    int x  ;
    List *pList, *pList2  ;
    Item *pItem  ;
    /* Check References (Called when we delete a scope) */
    pList = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem));
    for ( x = ring_list_getsize(pList) ; x >= 1 ; x-- ) {
        pList2 = ring_list_getlist(pList,x);
        if ( ring_list_getsize(pList2) == RING_VAR_LISTSIZE ) {
            if ( ring_list_getint(pList2,RING_VAR_TYPE) == RING_VM_POINTER ) {
                if ( ring_list_getint(pList2,RING_VAR_PVALUETYPE) == RING_OBJTYPE_LISTITEM ) {
                    pItem = (Item *) ring_list_getpointer(pList2,RING_VAR_VALUE) ;
                    #if GCLog
                        printf( "GC CheckReferences - Free Memory %p \n",pItem ) ;
                    #endif
                    ring_item_delete_gc(pVM->pRingState,pItem);
                }
            }
        }
    }
}

void ring_vm_gc_checknewreference ( void *pPointer,int nType )
{
    Item *pItem  ;
    /*
    **  Called when we create new pointer (new reference) 
    **  The reference may be to a list or a sublist (list item) 
    **  We care only about list items (sublists) 
    */
    if ( nType == RING_OBJTYPE_LISTITEM ) {
        pItem = (Item *) pPointer ;
        pItem->gc.nReferenceCount++ ;
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
    if ( pItem->gc.nReferenceCount == 0 ) {
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
        pItem->gc.nReferenceCount-- ;
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

void ring_vm_gc_newitemreference ( Item *pItem )
{
    pItem->gc.nReferenceCount++ ;
}

void ring_vm_gc_freefunc ( RingState *pState,Item *pItem )
{
    if ( pItem->gc.pFreeFunc != NULL ) {
        if ( pItem->data.pPointer  != NULL ) {
            pItem->gc.pFreeFunc(pState,pItem->data.pPointer);
        }
    }
}

void ring_vm_gc_setfreefunc ( Item *pItem, void (* pFreeFunc)(void *,void *) )
{
    pItem->gc.pFreeFunc = pFreeFunc ;
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
    if ( pList->gc.pContainer == NULL ) {
        ring_list_setlistbyref_gc(pState,pVariableList,RING_VAR_VALUE,pList);
        if ( pList->gc.lNewRef == 0 ) {
            pList->gc.lNewRef = 1 ;
        }
        else {
            /* Avoid increasing the counter when writing Ref(Ref(Ref(....Ref(aList)....))) */
            ring_list_updaterefcount_gc(pState,pList,RING_LISTREF_DEC);
        }
        /* If we have a reference to an object, the Self attribute will stay pointing to the Container Variable */
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_oop_updateselfpointer(((RingState *) pState)->pVM,pList,RING_OBJTYPE_VARIABLE,pVariableList);
        }
        /* We increase the Counter to avoid deleting the container variable */
        pVariableList->gc.lDontDelete = 1 ;
        /* When deleting the list (No other references exist) - It will delete the container variable */
        pList->gc.lDeleteContainerVariable = 1 ;
        pList->gc.pContainer = pVariableList ;
    }
    else {
        /* Check if it's a new reference! */
        if ( ! pList->gc.lNewRef ) {
            pList->gc.lNewRef = 1 ;
            ring_list_updaterefcount_gc(pState,pList,RING_LISTREF_INC);
        }
        pVariableList = (List *) pList->gc.pContainer ;
    }
    return pVariableList ;
}

RING_API int ring_list_isref ( List *pList )
{
    return pList->gc.nReferenceCount ;
}

RING_API void ring_list_assignreftovar_gc ( void *pState,List *pRef,List *pVar,unsigned int nPos )
{
    int lNewRef  ;
    lNewRef = pRef->gc.lNewRef ;
    pRef->gc.lNewRef = 0 ;
    if ( ! ( ring_list_getlist(pVar,nPos) == pRef ) ) {
        if ( lNewRef ) {
            ring_list_acceptlistbyref_gc(pState,pVar,nPos,pRef);
        }
        else {
            ring_list_setlistbyref_gc(pState,pVar,nPos,pRef);
        }
    }
}

RING_API void ring_list_assignreftoitem_gc ( void *pState,List *pRef,Item *pItem )
{
    List *pList  ;
    pList = ring_item_getlist(pItem);
    if ( pList == pRef ) {
        if ( pRef->gc.lNewRef ) {
            ring_list_updaterefcount_gc(pState,pRef,RING_LISTREF_DEC);
        }
        pRef->gc.lNewRef = 0 ;
        return ;
    }
    ring_list_delete_gc(pState,pList);
    pItem->data.pList = pRef ;
    if ( pRef->gc.lNewRef ) {
        pRef->gc.lNewRef = 0 ;
    }
    else {
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
}

RING_API List * ring_list_deleteref_gc ( void *pState,List *pList )
{
    List *pVariable  ;
    /* Check lDontDelete (Used by Container Variables) */
    if ( pList->gc.lDontDelete ) {
        /* This is a container that we will not delete, but will be deleted by that list that know about it */
        return pList ;
    }
    /* Avoid deleting objects when the list is just a reference */
    if ( ring_list_isref(pList) ) {
        /* We don't delete the list because there are other references */
        ring_list_updaterefcount_gc(pState,pList,RING_LISTREF_DEC);
        if ( pList->gc.lNewRef && ring_list_isref(pList) ) {
            /* Deleting a Ref() before assignment while we have other references */
            pList->gc.lNewRef = 0 ;
            ring_list_updaterefcount_gc(pState,pList,RING_LISTREF_DEC);
        }
        pList = ring_list_collectcycles_gc(pState,pList);
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
    return pList->gc.pContainer ;
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
        /* Decrement References */
        for ( x = 1 ; x <= ring_list_getsize(aProcess) ; x++ ) {
            pActiveList = (List *) ring_list_getpointer(aProcess,x);
            for ( y = 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
                if ( ring_list_islist(pActiveList,y) ) {
                    pSubList = ring_list_getlist(pActiveList,y);
                    if ( (pSubList != pList) && ring_list_containssublist_gc(pState,pSubList,pList) ) {
                        pSubList->gc.nReferenceCount = 0 ;
                    }
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
        /* Convert the item that contains circular reference from List to Number (To be able to delete it) */
        for ( x = 1 ; x <= ring_list_getsize(aProcess) ; x++ ) {
            pActiveList = (List *) ring_list_getpointer(aProcess,x);
            for ( y = 1 ; y <= ring_list_getsize(pActiveList) ; y++ ) {
                if ( ring_list_islist(pActiveList,y) ) {
                    pSubList = ring_list_getlist(pActiveList,y);
                    if ( ! ring_list_findpointer(aProcess,pSubList) ) {
                        ring_list_addpointer_gc(pState,aProcess,pSubList);
                    }
                    else {
                        pItem = ring_list_getitem(pActiveList,y);
                        pItem->nType = ITEMTYPE_NUMBER ;
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
    if ( ring_list_isref(pList) ) {
        if ( pList->gc.lNewRef ) {
            pList->gc.lNewRef = 0 ;
            ring_list_updaterefcount_gc(pState,pList,RING_LISTREF_DEC);
            return 1 ;
        }
    }
    return 0 ;
}

RING_API int ring_list_checkrefvarinleftside ( void *pState,List *pVar )
{
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
    List *pRef, *pVar  ;
    lRef = 0 ;
    /* Check Reference */
    if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
        if ( ((List *) RING_VM_STACK_READP)->gc.lDontDelete ) {
            pRef = ring_list_getlist((List *) RING_VM_STACK_READP,RING_VAR_VALUE);
            if ( pRef->gc.lNewRef ) {
                lRef = 1 ;
                pVar = ring_vm_newvar2(pVM,cVariable,pVM->pActiveMem);
                ring_list_setint_gc(pVM->pRingState,pVar,RING_VAR_TYPE,RING_VM_LIST);
                ring_list_assignreftovar_gc(pVM->pRingState,pRef,pVar,RING_VAR_VALUE);
            }
        }
    }
    return lRef ;
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
            if ( size <= sizeof(PoolData) ) {
                if ( ((RingState *) pState)->pVM != NULL ) {
                    return ring_poolmanager_allocate((RingState *) pState,size) ;
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
        if ( pBlocks != NULL ) {
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
    #if RING_USEPOOLMANAGER
        if ( pState != NULL ) {
            #if RING_TRACKALLOCATIONS
                ((RingState *) pState)->vPoolManager.nAllocCount++ ;
            #endif
        }
    #endif
    return ring_calloc(nitems,size) ;
}

RING_API void * ring_state_realloc ( void *pState,void *ptr,size_t nAllocatedSize,size_t size )
{
    #if RING_USEPOOLMANAGER
        void *pMemory  ;
        PoolData *pPoolData  ;
        int x  ;
        if ( pState != NULL ) {
            #if RING_TRACKALLOCATIONS
                ((RingState *) pState)->vPoolManager.nAllocCount++ ;
            #endif
            if ( ((RingState *) pState)->pVM != NULL ) {
                if ( ring_poolmanager_find((RingState *) pState,ptr) ) {
                    pPoolData = (PoolData*) ptr ;
                    if ( size <= sizeof(PoolData) ) {
                        /*
                        **  The Pointer belong to memory pool and new size less than RING_POOLMANAGER_ITEMSIZE 
                        **  In this case, just return the same pointer since we have space for the new data 
                        */
                        return ptr ;
                    }
                    else {
                        /* Allocate new buffer, copy data to it and then free existing pointer from pool */
                        pMemory = ring_malloc(size);
                        /* Copy existing data */
                        for ( x = 0 ; x < nAllocatedSize ; x++ ) {
                            ((unsigned char*) pMemory)[x] = ((unsigned char*) ptr)[x] ;
                        }
                        ring_poolmanager_free(((RingState *) pState),ptr);
                        return pMemory ;
                    }
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
    /*
    **  Here we don't use ring_list_newlist_gc() or ring_list_addpointer_gc() functions 
    **  To avoid checking the pRingState->vPoolManager.aBlocks list while we are updating it 
    */
    pList = ring_list_newlist(pRingState->vPoolManager.aBlocks);
    ring_list_addpointer(pList,pStart);
    ring_list_addpointer(pList,pEnd);
}

RING_API void ring_state_unregisterblock ( void *pState,void *pStart )
{
    int x  ;
    List *pList  ;
    RingState *pRingState  ;
    pRingState = (RingState *) pState ;
    for ( x = 1 ; x <= ring_list_getsize(pRingState->vPoolManager.aBlocks) ; x++ ) {
        pList = ring_list_getlist(pRingState->vPoolManager.aBlocks,x);
        if ( ring_list_getpointer(pList,1) == pStart ) {
            /*
            **  Here we don't use ring_list_deleteitem_gc() function 
            **  To avoid checking the pRingState->vPoolManager.aBlocks list while we are updating it 
            */
            ring_list_deleteitem(pRingState->vPoolManager.aBlocks,x);
            return ;
        }
    }
}

void ring_vm_gc_deleteitem ( Item *pItem )
{
    ring_vm_gc_deleteitem_gc(NULL,pItem);
}
/* Pool Manager Functions */

void ring_poolmanager_new ( RingState *pRingState )
{
    pRingState->vPoolManager.pCurrentItem = NULL ;
    pRingState->vPoolManager.pBlockStart = NULL ;
    pRingState->vPoolManager.pBlockEnd = NULL ;
    pRingState->vPoolManager.aBlocks = ring_list_new(0) ;
    pRingState->vPoolManager.nItemsInBlock = RING_POOLMANAGER_ITEMSINBLOCK ;
    pRingState->vPoolManager.lDeleteMemory = 1 ;
}

void ring_poolmanager_newblock ( RingState *pRingState )
{
    PoolData *pMemory  ;
    int x  ;
    /* Get Block Memory */
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
    if ( pRingState->vPoolManager.pCurrentItem != NULL ) {
        pMemory = pRingState->vPoolManager.pCurrentItem ;
        pRingState->vPoolManager.pCurrentItem = pRingState->vPoolManager.pCurrentItem->pNext ;
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
        if ( pRingState->vPoolManager.pBlockStart != NULL ) {
            if ( (pMemory >= pRingState->vPoolManager.pBlockStart) && (pMemory <= pRingState->vPoolManager.pBlockEnd ) ) {
                return 1 ;
            }
        }
    }
    /* Reaching this point means that the Pool Manager doesn't own this memory to free it! */
    return 0 ;
}

int ring_poolmanager_free ( RingState *pRingState,void *pMemory )
{
    PoolData *pPoolData  ;
    if ( ring_poolmanager_find(pRingState, pMemory) ) {
        pPoolData = (PoolData *) pMemory ;
        pPoolData->pNext = pRingState->vPoolManager.pCurrentItem ;
        pRingState->vPoolManager.pCurrentItem = pPoolData ;
        #if RING_TRACKALLOCATIONS
            pRingState->vPoolManager.nSmallFreeCount++ ;
        #endif
        return 1 ;
    }
    /* Reaching this point means that the Pool Manager doesn't own this memory to free it! */
    return 0 ;
}

void ring_poolmanager_delete ( RingState *pRingState )
{
    if ( pRingState != NULL ) {
        if ( pRingState->vPoolManager.lDeleteMemory ) {
            pRingState->vPoolManager.aBlocks = ring_list_delete(pRingState->vPoolManager.aBlocks) ;
            if ( pRingState->vPoolManager.pBlockStart != NULL ) {
                free( pRingState->vPoolManager.pBlockStart ) ;
                pRingState->vPoolManager.pBlockStart = NULL ;
                pRingState->vPoolManager.pBlockEnd = NULL ;
                pRingState->vPoolManager.pCurrentItem = NULL ;
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
