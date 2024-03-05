/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

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
		if ( strcmp(RING_VM_STACK_READC,"") == 0 ) {
			RING_VM_JUMP ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
			if ( ring_list_getsize(pList) == 0 ) {
				RING_VM_JUMP ;
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
			if ( ring_list_getsize(pList) == 0 ) {
				RING_VM_JUMP ;
			}
		}
	}
	RING_VM_STACK_POP ;
}

void ring_vm_jumpfor ( VM *pVM )
{
	double nNum1,nNum2,nNum3  ;
	/* Check Data */
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		nNum1 = ring_vm_stringtonum(pVM,RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
		return ;
	}
	nNum2 = ring_list_getdouble(pVM->pForStep,ring_list_getsize(pVM->pForStep));
	/* Check Data */
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum3 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
		return ;
	}
	/*
	**  nNum2 = Step value that can be positive or negative 
	**  nNum1 = Items Count , nNum3 = Index 
	*/
	if ( nNum2 <= 0 ) {
		if ( ( ! ( nNum3 >= nNum1 ) ) || ( nNum2 == 0 ) ) {
			RING_VM_JUMP ;
		}
	}
	else {
		if ( ! ( nNum3 <= nNum1 ) ) {
			RING_VM_JUMP ;
		}
	}
	/* CALL FreeTempLists */
	if ( ring_vm_timetofreetemplists(pVM) ) {
		ring_vm_freetemplists(pVM,& RING_VM_IR_READIVALUE(RING_VM_IR_REG2), & RING_VM_IR_READIVALUE(RING_VM_IR_REG3));
	}
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
		if ( strcmp(RING_VM_STACK_READC,"") != 0 ) {
			RING_VM_JUMP ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
			if ( ring_list_getsize(pList) != 0 ) {
				RING_VM_JUMP ;
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
			if ( ring_list_getsize(pList) != 0 ) {
				RING_VM_JUMP ;
			}
		}
	}
	RING_VM_STACK_POP ;
}

void ring_vm_jumpone2 ( VM *pVM )
{
	List *pList  ;
	Item *pItem  ;
	/* Add 1, required for jump in many 'OR' in conditions */
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_STACK_READN  != 0 ) {
			RING_VM_JUMP ;
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		if ( strcmp(RING_VM_STACK_READC,"") != 0 ) {
			RING_VM_STACK_SETNVALUE(RING_TRUEF);
			RING_VM_JUMP ;
			return ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
			if ( ring_list_getsize(pList) != 0 ) {
				RING_VM_STACK_SETNVALUE(RING_TRUEF);
				RING_VM_JUMP ;
				return ;
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
			if ( ring_list_getsize(pList) != 0 ) {
				RING_VM_STACK_SETNVALUE(RING_TRUEF);
				RING_VM_JUMP ;
				return ;
			}
		}
	}
	RING_VM_STACK_POP ;
	RING_VM_STACK_PUSHNVALUE(0);
}

void ring_vm_jumpzero2 ( VM *pVM )
{
	List *pList  ;
	Item *pItem  ;
	/* Add 1, required for jump in many 'AND' in conditions */
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_STACK_READN  == 0 ) {
			RING_VM_JUMP ;
			return ;
		}
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		if ( strcmp(RING_VM_STACK_READC,"") == 0 ) {
			RING_VM_STACK_SETNVALUE(RING_FALSEF);
			RING_VM_JUMP ;
			return ;
		}
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			pList = ring_list_getlist(pList,RING_VAR_VALUE) ;
			if ( ring_list_getsize(pList) == 0 ) {
				RING_VM_STACK_SETNVALUE(RING_FALSEF);
				RING_VM_JUMP ;
				return ;
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pList = ring_item_getlist(pItem) ;
			if ( ring_list_getsize(pList) == 0 ) {
				RING_VM_STACK_SETNVALUE(RING_FALSEF);
				RING_VM_JUMP ;
				return ;
			}
		}
	}
	RING_VM_STACK_POP ;
	RING_VM_STACK_PUSHNVALUE(1);
}
