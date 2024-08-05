/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_jumpfor ( VM *pVM )
{
	double nStart,nEnd,nStep  ;
	/* Check Data */
	if ( RING_VM_STACK_ISNUMBER ) {
		nEnd = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		nEnd = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_RETURNIFACTIVECATCH ;
		RING_VM_STACK_POP ;
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
		return ;
	}
	nStep = ring_list_getdouble(pVM->pForStep,ring_list_getsize(pVM->pForStep));
	/* Check Data */
	if ( RING_VM_STACK_ISNUMBER ) {
		nStart = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
		return ;
	}
	/*
	**  nStep = Step value that can be positive or negative 
	**  nEnd = Items Count , nStart = Index 
	**  Here we write a condition to terminate the loop 
	*/
	if ( ( (nStep < 0) && (nStart < nEnd) ) || ( (nStep > 0) && (nStart > nEnd) ) || ( nStep == 0 ) ) {
		RING_VM_JUMP ;
	}
	/* CALL FreeTempLists */
	if ( ring_vm_timetofreetemplists(pVM) ) {
		ring_vm_freetemplists(pVM);
	}
}

void ring_vm_jumpzero ( VM *pVM )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_STACK_READN  == 0 ) {
			RING_VM_JUMP ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		if ( strcmp(RING_VM_STACK_READC,RING_CSTR_EMPTY) == 0 ) {
			RING_VM_JUMP ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
		}
		if ( ring_vm_listtologicvalue(pVM,pList) == 0 ) {
			RING_VM_JUMP ;
		}
	}
	RING_VM_STACK_POP ;
}

void ring_vm_jumpone ( VM *pVM )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_STACK_READN  != 0 ) {
			RING_VM_JUMP ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		if ( strcmp(RING_VM_STACK_READC,RING_CSTR_EMPTY) != 0 ) {
			RING_VM_JUMP ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
		}
		if ( ring_vm_listtologicvalue(pVM,pList) != 0 ) {
			RING_VM_JUMP ;
		}
	}
	RING_VM_STACK_POP ;
}

void ring_vm_jumpone2 ( VM *pVM )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_STACK_READN  != 0 ) {
			RING_VM_STACK_SETNVALUE(RING_TRUEF);
			RING_VM_JUMP ;
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		if ( strcmp(RING_VM_STACK_READC,RING_CSTR_EMPTY) != 0 ) {
			RING_VM_STACK_SETNVALUE(RING_TRUEF);
			RING_VM_JUMP ;
			return ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
		}
		if ( ring_vm_listtologicvalue(pVM,pList) != 0 ) {
			if ( ! ( ring_vm_oop_isobject(pList) && ring_vm_oop_ismethod(pVM,pList,RING_CSTR_OPERATOR) ) ) {
				RING_VM_STACK_SETNVALUE(RING_TRUEF);
				RING_VM_JUMP ;
			}
			return ;
		}
	}
	/* Add zero, required for jump in many 'OR' in conditions */
	RING_VM_STACK_POP ;
	RING_VM_STACK_PUSHNVALUE(RING_ZERO);
}

void ring_vm_jumpzero2 ( VM *pVM )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_STACK_READN  == 0 ) {
			RING_VM_JUMP ;
			return ;
		}
		else {
			RING_VM_STACK_SETNVALUE(RING_TRUEF);
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		if ( strcmp(RING_VM_STACK_READC,RING_CSTR_EMPTY) == 0 ) {
			RING_VM_STACK_SETNVALUE(RING_FALSEF);
			RING_VM_JUMP ;
			return ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
		}
		if ( ring_vm_listtologicvalue(pVM,pList) == 0 ) {
			RING_VM_STACK_SETNVALUE(RING_FALSEF);
			RING_VM_JUMP ;
			return ;
		}
		if ( ring_vm_oop_isobject(pList) && ring_vm_oop_ismethod(pVM,pList,RING_CSTR_OPERATOR) ) {
			return ;
		}
	}
	/* Add one, required for jump in many 'AND' in conditions */
	RING_VM_STACK_POP ;
	RING_VM_STACK_PUSHNVALUE(RING_ONE);
}
