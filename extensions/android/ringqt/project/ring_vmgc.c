/* Copyright (c) 2013-2019 Mahmoud Fayed <msfclipper@yahoo.com> */
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
	List *pList  ;
	if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
		pList = (List *) RING_VM_STACK_READP ;
		ring_vm_gc_checkupdatereference(pVM,pList);
	}
}

void ring_vm_gc_deletetemplists ( VM *pVM )
{
	/*
	**  This function is called from Ring code by callgc() 
	**  Function Goal 
	**  When we return Lists/Pointers from functions we create variable called ring_sys_temp 
	**  This variable is created in the caller temp. memory instead of the active function scope 
	**  This is necessary because the function scope will be deleted and we need the varaible 
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
	return malloc(size) ;
}

RING_API void ring_free ( void *ptr )
{
	free( ptr ) ;
}

RING_API void * ring_calloc ( size_t nitems, size_t size )
{
	return calloc(nitems,size) ;
}

RING_API void * ring_realloc ( void *ptr, size_t size )
{
	return realloc(ptr,size) ;
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
			return ring_poolmanager_allocate((RingState *) pState,size) ;
		}
	}
	#endif
	return ring_malloc(size) ;
}

RING_API void ring_state_free ( void *pState,void *pMemory )
{
	#if RING_USEPOOLMANAGER
	/* Use Pool Manager */
	if ( pState != NULL ) {
		#if RING_TRACKALLOCATIONS
		((RingState *) pState)->vPoolManager.nFreeCount++ ;
		#endif
		ring_poolmanager_free(((RingState *) pState),pMemory);
		return ;
	}
	#endif
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

RING_API void * ring_state_realloc ( void *pState,void *ptr, size_t size )
{
	return ring_realloc(ptr,size) ;
}

void ring_vm_gc_deleteitem ( Item *pItem )
{
	ring_vm_gc_deleteitem_gc(NULL,pItem);
}
/* Pool Manager Functions */

void ring_poolmanager_newblock ( RingState *pRingState )
{
	PoolData *pMemory  ;
	int x  ;
	/* Get Block Memory */
	pMemory = (PoolData *) ring_calloc(RING_POOLMANAGER_ITEMSINBLOCK,sizeof(PoolData));
	/* Check Memory */
	if ( pMemory == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	/* Set Linked Lists (pNext values) */
	for ( x = 0 ; x < RING_POOLMANAGER_ITEMSINBLOCK - 1 ; x++ ) {
		pMemory[x].pNext = pMemory+x+1 ;
	}
	pMemory[RING_POOLMANAGER_ITEMSINBLOCK-1].pNext = NULL ;
	/*
	**  Set Values in Ring State 
	**  Set First Item in Ring State 
	*/
	pRingState->vPoolManager.pCurrentItem = pMemory ;
	/* Set Block Start and End */
	pRingState->vPoolManager.pBlockStart = (void *) pMemory ;
	pRingState->vPoolManager.pBlockEnd = (void *) (pMemory + RING_POOLMANAGER_ITEMSINBLOCK - 1) ;
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
	if ( (pRingState->vPoolManager.pCurrentItem == NULL) && (pRingState->vPoolManager.pBlockStart == NULL)  && (pRingState->lStartPoolManager) ) {
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
		/* Check Memory */
		if ( pMemory == NULL ) {
			printf( RING_OOM ) ;
			exit(0);
		}
	}
	#if RING_TRACKALLOCATIONS
	pRingState->vPoolManager.nSmallAllocCount++ ;
	#endif
	return pMemory ;
}

void ring_poolmanager_free ( RingState *pRingState,void *pMemory )
{
	PoolData *pPoolData  ;
	if ( pRingState != NULL ) {
		if ( pRingState->vPoolManager.pBlockStart != NULL ) {
			if ( (pMemory >= pRingState->vPoolManager.pBlockStart) && (pMemory <= pRingState->vPoolManager.pBlockEnd ) ) {
				pPoolData = (PoolData *) pMemory ;
				pPoolData->pNext = pRingState->vPoolManager.pCurrentItem ;
				pRingState->vPoolManager.pCurrentItem = pPoolData ;
				#if RING_TRACKALLOCATIONS
				pRingState->vPoolManager.nSmallFreeCount++ ;
				#endif
				return ;
			}
		}
	}
	ring_free(pMemory);
}

void ring_poolmanager_delete ( RingState *pRingState )
{
	if ( pRingState != NULL ) {
		if ( pRingState->vPoolManager.pBlockStart != NULL ) {
			free( pRingState->vPoolManager.pBlockStart ) ;
			pRingState->vPoolManager.pBlockStart = NULL ;
			pRingState->vPoolManager.pBlockEnd = NULL ;
			pRingState->vPoolManager.pCurrentItem = NULL ;
		}
	}
}
