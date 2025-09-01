/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_stringpushv(VM *pVM) {
	char *cNewStr;
	char cStr[RING_CHARBUF];
	if (pVM->nRetItemRef) {
		pVM->nRetItemRef--;
		return;
	}
	cNewStr = (char *)RING_VM_STACK_READP;
	RING_VM_STACK_POP;
	cStr[0] = cNewStr[0];
	cStr[1] = '\0';
	RING_VM_STACK_PUSHCVALUE2(cStr, RING_ONE);
}

void ring_vm_stringassignment(VM *pVM) {
	char *cNewStr;
	char cChar;
	int nSize;
	double nNum;
	if (RING_VM_STACK_ISSTRING) {
		nSize = RING_VM_STACK_STRINGSIZE;
		if (nSize == 1) {
			cChar = RING_VM_STACK_READC[0];
			RING_VM_STACK_POP;
			cNewStr = (char *)RING_VM_STACK_READP;
			RING_VM_STACK_POP;
			cNewStr[0] = cChar;
			return;
		} else {
			RING_VM_STACK_POP;
			ring_vm_error(pVM, RING_VM_ERROR_VALUEMORETHANONECHAR);
			return;
		}
	} else if (RING_VM_STACK_ISNUMBER) {
		nNum = RING_VM_STACK_READN;
		cChar = (char)nNum;
		RING_VM_STACK_POP;
		cNewStr = (char *)RING_VM_STACK_READP;
		cNewStr[0] = cChar;
	} else {
		ring_vm_error(pVM, RING_VM_ERROR_VARISNOTSTRING);
		return;
	}
}

void ring_vm_stringindex(VM *pVM, String *pString, double nNum1) {
	char *cNewStr;
	/* We will push a pointer of the sub char to the stack */
	if (nNum1 < 1 || nNum1 > ring_string_size(pString)) {
		ring_vm_error(pVM, RING_VM_ERROR_INDEXOUTOFRANGE);
		return;
	}
	cNewStr = pString->cStr;
	cNewStr = cNewStr + ((unsigned int)(nNum1 - 1));
	RING_VM_STACK_PUSHPVALUE(cNewStr);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_SUBSTRING;
}
