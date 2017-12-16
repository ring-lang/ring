/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* User Interface - Commands Implementation (Faster) - Because we don't have functions call */

void ring_vm_see ( VM *pVM )
{
	Item *pItem  ;
	char cStr[100]  ;
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
		} else {
			printf( "%s",cString ) ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = ring_list_getlist((List *) RING_VM_STACK_READP,RING_VAR_VALUE);
			if ( ring_vm_oop_isobject(pList) ) {
				ring_vm_oop_printobj(pList);
			} else {
				ring_list_print(pList);
			}
		}
		else if ( RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
			if ( ring_vm_oop_isobject(pList) ) {
				ring_vm_oop_printobj(pList);
			} else {
				ring_list_print(pList);
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
	int x  ;
	char cLine[256]  ;
	List *pVar  ;
	Item *pItem  ;
	/* Get Input From the User and save it in the variable */
	fgets(cLine , 256 , stdin );
	/* Remove New Line */
	for ( x = 0 ; x <= 255 ; x++ ) {
		if ( cLine[x] == '\n' ) {
			cLine[x] = '\0' ;
			break ;
		}
	}
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
/* User Interface Functions (Another implementation) - Flexibile (We can replace functions in Ring Code) */

void ring_vmlib_see ( void *pPointer )
{
	char *cString  ;
	int x  ;
	char cStr[100]  ;
	List *pList  ;
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_ISSTRING(1) ) {
		cString = RING_API_GETSTRING(1) ;
		if ( strlen(cString) != (unsigned int) RING_API_GETSTRINGSIZE(1) ) {
			for ( x = 0 ; x < RING_API_GETSTRINGSIZE(1) ; x++ ) {
				printf( "%c",cString[x] ) ;
			}
		} else {
			printf( "%s",cString ) ;
		}
	}
	else if ( RING_API_ISNUMBER(1) ) {
		ring_vm_numtostring(pVM,RING_API_GETNUMBER(1),cStr);
		printf( "%s",cStr ) ;
	}
	else if ( RING_API_ISLIST(1) ) {
		pList = RING_API_GETLIST(1);
		if ( ring_vm_oop_isobject(pList) ) {
			ring_vm_oop_printobj(pList);
		} else {
			ring_list_print(pList);
		}
	}
	fflush(stdout);
}

void ring_vmlib_give ( void *pPointer )
{
	int x  ;
	char cLine[256]  ;
	/* Get Input From the User and save it in the variable */
	fgets(cLine , 256 , stdin );
	/* Remove New Line */
	for ( x = 0 ; x <= 255 ; x++ ) {
		if ( cLine[x] == '\n' ) {
			cLine[x] = '\0' ;
			break ;
		}
	}
	RING_API_RETSTRING(cLine);
}
