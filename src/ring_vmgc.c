/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"

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
					ring_item_delete(pItem);
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

void ring_vm_gc_checkupdatereference ( List *pList )
{
	Item *pItem  ;
	/* Reference Counting to Destination before copy from Source */
	if ( ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_POINTER ) {
		if ( ring_list_getint(pList,RING_VAR_PVALUETYPE) == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) ring_list_getpointer(pList,RING_VAR_VALUE) ;
			ring_item_delete(pItem);
		}
	}
}

void ring_vm_gc_deleteitem ( Item *pItem )
{
	if ( pItem->gc.nReferenceCount == 0 ) {
		#if GCLog
		printf( "GC Delete Item - Free Memory %p \n",pItem ) ;
		#endif
		ring_item_content_delete(pItem);
		free( pItem ) ;
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
		ring_vm_gc_checkupdatereference(pList);
	}
}

void ring_vm_gc_deletetemplists ( VM *pVM )
{
	int x  ;
	List *pScope,*pList  ;
	/*
	**  This function is called from Ring code by callgc() 
	**  Function Goal 
	**  When we return Lists/Pointers from functions we create variable called ring_sys_temp 
	**  This variable is created in the previous scope instead of the active function scope 
	**  This is necessary because the function scope will be deleted and we need the varaible 
	**  This is important because we may assign the variable to variable name 
	**  The problem happens when we have a loop that uses f1(f2()) 
	**  and f2() return a lists/pointer 
	**  The temp list/C Pointer will not be deleted until the end of the function 
	**  But we have a loop and this will lead to a memory leak during loop execution 
	**  When testing al_map_rgb() in Allegro Library this problem becomes critical 
	**  This function solves this problem, by deleting temp lists/C Pointers in the current scope 
	**  We use -1 to skip the currect scope of the Ring function (callgc()) 
	*/
	pScope = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)-1) ;
	/* The function works only when we expect to have temp variables */
	if ( ring_list_getsize(pScope) >= 1 ) {
		for ( x = ring_list_getsize(pScope) ; x >= 1 ; x-- ) {
			pList = ring_list_getlist(pScope,x);
			if ( ring_list_getsize(pList) != RING_VAR_LISTSIZE ) {
				continue ;
			}
			if ( strcmp(ring_list_getstring(pList,RING_VAR_NAME),RING_TEMP_VARIABLE) == 0 ) {
				ring_list_deleteitem(pScope,x);
			}
			else if ( strcmp(ring_list_getstring(pList,RING_VAR_NAME),RING_TEMP_OBJECT) == 0 ) {
				ring_list_deleteitem(pScope,x);
			}
		}
	}
	/* Delete The HashTable */
	pScope->pHashTable = ring_hashtable_delete(pScope->pHashTable) ;
	ring_list_genhashtable2(pScope);
}
