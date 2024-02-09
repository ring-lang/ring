/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_string_pushv ( VM *pVM )
{
	char *newstr  ;
	char cStr[RING_CHARBUF]  ;
	if ( (pVM->nRetItemRef>=1)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
		pVM->nRetItemRef-- ;
		return ;
	}
	newstr = (char *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	cStr[0] = newstr[0] ;
	cStr[1] = '\0' ;
	RING_VM_STACK_PUSHCVALUE2(cStr,1);
}

void ring_vm_string_assignment ( VM *pVM )
{
	char *newstr  ;
	char cChar  ;
	int nSize  ;
	double nNum  ;
	if ( RING_VM_STACK_ISSTRING ) {
		nSize = RING_VM_STACK_STRINGSIZE ;
		if ( nSize == 1 ) {
			cChar = RING_VM_STACK_READC[0] ;
			RING_VM_STACK_POP ;
			newstr = (char *) RING_VM_STACK_READP ;
			RING_VM_STACK_POP ;
			newstr[0] = cChar ;
			return ;
		}
		else {
			RING_VM_STACK_POP ;
			ring_vm_error(pVM,RING_VM_ERROR_VALUEMORETHANONECHAR);
			return ;
		}
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		nNum = RING_VM_STACK_READN ;
		cChar = (char) nNum ;
		RING_VM_STACK_POP ;
		newstr = (char *) RING_VM_STACK_READP ;
		newstr[0] = cChar ;
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_VARISNOTSTRING);
		return ;
	}
}

void ring_vm_string_index ( VM *pVM, String *pString, double nNum1 )
{
	char *newstr  ;
	/* We will push a pointer of the sub char to the stack */
	if ( nNum1 < 1 || nNum1 > ring_string_size(pString) ) {
		ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
		return ;
	}
	newstr = pString->cStr ;
	newstr = newstr + ((int) (nNum1 - 1) ) ;
	RING_VM_STACK_PUSHPVALUE(newstr);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_SUBSTRING ;
}
