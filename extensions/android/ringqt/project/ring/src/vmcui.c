/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_see ( VM *pVM )
{
	Item *pItem  ;
	char cStr[RING_MEDIUMBUF]  ;
	List *pList  ;
	char *cString  ;
	int x  ;
	if ( pVM->nFuncExecute > 0 ) {
		pVM->nFuncExecute-- ;
	}
	if ( RING_VM_STACK_ISSTRING ) {
		cString = RING_VM_STACK_READC ;
		if ( strlen(cString) != (unsigned int) RING_VM_STACK_STRINGSIZE ) {
			for ( x = 0 ; x < RING_VM_STACK_STRINGSIZE ; x++ ) {
				printf( "%c",cString[x] ) ;
			}
		}
		else {
			printf( "%s",cString ) ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = ring_list_getlist((List *) RING_VM_STACK_READP,RING_VAR_VALUE);
			if ( ring_vm_oop_isobject(pList) ) {
				ring_vm_oop_printobj(pVM,pList);
			}
			else {
				ring_list_print2(pList,pVM->nDecimals);
			}
		}
		else if ( RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
			if ( ring_vm_oop_isobject(pList) ) {
				ring_vm_oop_printobj(pVM,pList);
			}
			else {
				ring_list_print2(pList,pVM->nDecimals);
			}
		}
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		ring_vm_numtostring(pVM,RING_VM_STACK_READN,cStr);
		printf( "%s",cStr ) ;
	}
	RING_VM_STACK_POP ;
	ring_vm_freestack(pVM);
	fflush(stdout);
}

void ring_vm_give ( VM *pVM )
{
	char cLine[RING_LARGEBUF]  ;
	List *pVar  ;
	Item *pItem  ;
	/* Get Input From the User and save it in the variable */
	ring_general_readline(cLine, RING_LARGEBUF);
	if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pVar = (List *) RING_VM_STACK_READP ;
			RING_VM_STACK_POP ;
			ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_STRING);
			ring_list_setstring_gc(pVM->pRingState,pVar, RING_VAR_VALUE, cLine);
		}
		else if ( RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			RING_VM_STACK_POP ;
			ring_item_settype_gc(pVM->pRingState,pItem,ITEMTYPE_STRING);
			ring_string_set_gc(pVM->pRingState,ring_item_getstring(pItem),cLine);
		}
	}
}
