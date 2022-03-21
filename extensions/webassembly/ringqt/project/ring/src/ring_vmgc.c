/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* GC Functions */

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
        ring_item_content_delete_gc(pState,pItem);
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
/* Memory Functions (General) */

RING_API void * ring_malloc ( size_t size )
{
    void *pMemory  ;
    pMemory = malloc(size) ;
    /* Check Memory */
    if ( pMemory == NULL ) {
        printf( RING_OOM ) ;
        exit(0);
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
        exit(0);
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
        exit(0);
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
            if ( size <= RING_POOLMANAGER_ITEMSIZE ) {
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
                    if ( size <= RING_POOLMANAGER_ITEMSIZE ) {
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
            if ( pRingState->vPoolManager.pBlockStart != NULL ) {
                pRingState->vPoolManager.aBlocks = ring_list_delete(pRingState->vPoolManager.aBlocks) ;
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
