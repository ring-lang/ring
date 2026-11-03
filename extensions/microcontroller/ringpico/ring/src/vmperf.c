/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

int ring_vm_pushvarptr(VM *pVM) {
	/* Check Scope Life Time */
	if (RING_VM_IR_GETINTREG != pVM->nActiveScopeID) {
		/* Reset register used for the pointer */
		RING_VM_IR_READIVALUE(RING_VM_IR_REG2) = 0;
		RING_VM_IR_SETREG2TYPE(RING_VM_REGTYPE_INT);
		RING_VM_IR_OPCODE = ICO_LOADADDRESS;
		ring_vm_loadaddress(pVM);
		return RING_FALSE;
	}
	RING_VM_STACK_PUSHPVALUE(RING_VM_IR_READPVALUE(RING_VM_IR_REG2));
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE;
	return RING_TRUE;
}

void ring_vm_pushp(VM *pVM) {
	if (ring_vm_pushvarptr(pVM)) {
		ring_vm_updatescopeinfo(pVM, RING_VARSCOPE_GLOBAL);
	}
}

void ring_vm_pushplocal(VM *pVM) {
	if (ring_vm_pushvarptr(pVM)) {
		ring_vm_updatescopeinfo(pVM, RING_VARSCOPE_LOCAL);
	}
}

void ring_vm_pusharg(VM *pVM) {
	List *pList;
	pList = ring_list_getlist(pVM->pActiveMem, RING_VM_IR_GETINTREG);
	/* Check if the variable list contains another type */
	if (ring_list_getlisttype_gc(pVM->pRingState, pList) != RING_VM_IR_GETSMALLINTREG) {
		RING_VM_IR_OPCODE = ICO_LOADADDRESS;
		RING_VM_IR_SETFLAGREG(RING_FALSE);
		ring_vm_loadaddress(pVM);
		return;
	}
	RING_VM_STACK_PUSHPVALUE(pList);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE;
	ring_vm_updatescopeinfo(pVM, RING_VARSCOPE_LOCAL);
}

void ring_vm_updatescopeinfo(VM *pVM, int nScope) {
	/* Update Scope Information */
	if (pVM->nLoadAddressScope == RING_VARSCOPE_NOTHING) {
		pVM->nLoadAddressScope = nScope;
	}
	pVM->nVarScope = nScope;
	/* Check lNewRef Flag */
	ring_list_resetlnewref_gc(pVM->pRingState, (List *)RING_VM_STACK_READP);
	/* Check if we have ICO_PUSHV */
	if (RING_VM_IR_GETFLAGREG2) {
		pVM->nPC++;
		ring_vm_varpushv(pVM);
	}
}

void ring_vm_incp(VM *pVM) {
	List *pVar;
	pVar = (List *)RING_VM_IR_READP;
	RING_VAR_SETNUMBER_GC(pVM->pRingState, pVar, RING_VAR_GETNUMBER(pVar) + 1);
}

void ring_vm_pushpv(VM *pVM) {
	ring_vm_pushp(pVM);
	ring_vm_pushv(pVM);
}

void ring_vm_incjump(VM *pVM) {
	List *pVar;
	Item *pItem;
	double nNum1, nNum2;
	int nLine, lPerformance;
	lPerformance = RING_FALSE;
	if (ring_vm_findvar(pVM, RING_VM_IR_READC) == 0) {
		ring_vm_newvar(pVM, RING_VM_IR_READC);
	}
	pVar = (List *)RING_VM_STACK_READP;
	RING_VM_STACK_POP;
	pItem = RING_VAR_ITEM_VALUE(pVar);
	nNum1 = ring_list_getdouble(pVM->pForStep, ring_list_getsize(pVM->pForStep));
	/* Check Data */
	if (!RING_VAR_ISNUMBER(pVar)) {
		ring_vm_error(pVM, RING_VM_ERROR_FORLOOPDATATYPE);
		return;
	}
	nNum2 = RING_VAR_GETNUMBER(pVar);
	RING_VAR_SETNUMBER_GC(pVM->pRingState, pVar, nNum2 + nNum1);
	/* Change Instruction for Performance */
	if (pVM->nVarScope == RING_VARSCOPE_GLOBAL) {
		/* Replace ICO_INCJUMP with IncPJUMP for better performance */
		if (nNum1 == 1.0) {
			if (ring_vm_canfuseforstep(pVM)) {
				RING_VM_IR_OPCODE = ICO_INCPJUMPFORSTEP1;
			} else {
				RING_VM_IR_OPCODE = ICO_INCPJUMPSTEP1;
			}
		} else {
			RING_VM_IR_OPCODE = ICO_INCPJUMP;
		}
		lPerformance = RING_TRUE;
	} else if (pVM->nVarScope == RING_VARSCOPE_LOCAL) {
		/* Replace ICO_INCJUMP with IncLPJUMP for better performance */
		if (nNum1 == 1.0) {
			if (ring_vm_canfuseforstep(pVM)) {
				RING_VM_IR_OPCODE = ICO_INCLPJUMPFORSTEP1;
			} else {
				RING_VM_IR_OPCODE = ICO_INCLPJUMPSTEP1;
			}
		} else {
			RING_VM_IR_OPCODE = ICO_INCLPJUMP;
		}
		RING_VM_IR_SETINTREG(pVM->nActiveScopeID);
		lPerformance = RING_TRUE;
	}
	/* Line Number and Item Pointer */
	RING_VM_IR_LOAD;
	nLine = RING_VM_IR_READIVALUE(RING_VM_IR_REG1);
	RING_VM_IR_SETLINENUMBER(nLine);
	if (lPerformance) {
		RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG2), pItem);
		RING_VM_IR_SETREG2TYPE(RING_VM_REGTYPE_POINTER);
	}
	RING_VM_IR_UNLOAD;
	/* Jump */
	pVM->nPC = RING_VM_IR_READIVALUE(RING_VM_IR_REG2);
	RING_VM_STACK_PUSHNVALUE(RING_VAR_GETNUMBER(pVar));
}

void ring_vm_incpjump(VM *pVM) {
	Item *pItem;
	double nNum1, nNum2;
	RING_VM_IR_LOAD;
	RING_VM_IR_SETLINENUMBER(RING_VM_IR_READIVALUE(RING_VM_IR_REG1));
	pItem = (Item *)RING_VM_IR_READPVALUE(RING_VM_IR_REG2);
	RING_VM_IR_UNLOAD;
	nNum1 = ring_list_getdouble(pVM->pForStep, ring_list_getsize(pVM->pForStep));
	/* Check Data */
	if (!ring_item_isdouble(pItem)) {
		ring_vm_error(pVM, RING_VM_ERROR_FORLOOPDATATYPE);
		return;
	}
	nNum2 = ring_item_getdouble(pItem);
	ring_item_setdouble_gc(pVM->pRingState, pItem, nNum2 + nNum1);
	/* Jump */
	pVM->nPC = RING_VM_IR_READIVALUE(RING_VM_IR_REG2);
	RING_VM_STACK_PUSHNVALUE(ring_item_getdouble(pItem));
}

void ring_vm_inclpjump(VM *pVM) {
	/* Check Scope Life Time */
	if (RING_VM_IR_GETINTREG != pVM->nActiveScopeID) {
		ring_vm_incjump(pVM);
		return;
	}
	ring_vm_incpjump(pVM);
}

void ring_vm_loadfuncp(VM *pVM) {
	FuncCall *pFuncCall;
	/* Check not defining a Ring function that replace a C function */
	if ((RING_VM_IR_GETFLAGREG == RING_FUNCTYPE_C) &&
	    (ring_list_getsize(pVM->pFunctionsMap) != RING_VM_IR_GETSMALLINTREG)) {
		ring_vm_loadfunc(pVM);
		return;
	}
	/* Add FuncCall Structure */
	pFuncCall = ring_vm_funccallnew(pVM);
	if (pFuncCall == NULL)
		return;
	pFuncCall->nType = RING_VM_IR_GETFLAGREG;
	pFuncCall->cName = RING_VM_IR_READC;
	pFuncCall->nPC = RING_VM_IR_GETINTREG;
	pFuncCall->nSP = pVM->nSP;
	pFuncCall->nLineNumber = RING_VM_IR_GETLINENUMBER;
	pFuncCall->pFunc = (void (*)(void *))RING_VM_IR_READPVALUE(RING_VM_IR_REG2);
	/* Store the file name */
	pFuncCall->cFileName = pVM->cFileName;
	if (pFuncCall->nType == RING_FUNCTYPE_SCRIPT) {
		pVM->cPrevFileName = pVM->cFileName;
	}
	pFuncCall->cNewFileName = pVM->cFileName;
	/* Method/Function & Scope */
	pFuncCall->lMethod = RING_VM_IR_GETFLAGREG2;
	pFuncCall->lLendString = RING_VM_IR_GETFLAGREG3;
	pFuncCall->nLoadAddressScope = pVM->nLoadAddressScope;
	pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING;
	/* Store List information */
	pFuncCall->nListStart = pVM->nListStart;
	pFuncCall->nNestedLists = ring_list_getsize(pVM->pNestedLists);
	ring_vm_newnestedlists(pVM);
}

void ring_vm_incpjumpstep1(VM *pVM) {
	Item *pItem;
	RING_VM_IR_LOAD;
	RING_VM_IR_SETLINENUMBER(RING_VM_IR_READIVALUE(RING_VM_IR_REG1));
	pItem = (Item *)RING_VM_IR_READPVALUE(RING_VM_IR_REG2);
	RING_VM_IR_UNLOAD;
	/* Jump */
	pVM->nPC = RING_VM_IR_READIVALUE(RING_VM_IR_REG2);
	/* Check Data */
	if (!ring_item_isdouble(pItem)) {
		ring_vm_error(pVM, RING_VM_ERROR_FORLOOPDATATYPE);
		return;
	}
	RING_VM_STACK_PUSHNVALUE(ring_item_incdouble(pItem));
}

void ring_vm_inclpjumpstep1(VM *pVM) {
	/* Check Scope Life Time */
	if (RING_VM_IR_GETINTREG != pVM->nActiveScopeID) {
		ring_vm_incjump(pVM);
		return;
	}
	ring_vm_incpjumpstep1(pVM);
}

int ring_vm_canfuseforstep(VM *pVM) {
	unsigned int nTarget;
	nTarget = RING_VM_IR_READIVALUE(RING_VM_IR_REG2);
	if ((nTarget < 1) || (nTarget + 1 > RING_VM_INSTRUCTIONSCOUNT)) {
		return RING_FALSE;
	}
	return (RING_VM_IR_OPCODEVALUE(nTarget - 1) == ICO_PUSHN);
}

void ring_vm_inclpjumpforstep1(VM *pVM) {
	if (RING_VM_IR_GETINTREG != pVM->nActiveScopeID) {
		ring_vm_incjump(pVM);
		return;
	}
	ring_vm_incpjumpforstep1(pVM);
}

void ring_vm_incpjumpforstep1(VM *pVM) {
	Item *pItem;
	ByteCode *pPushN, *pJumpFor;
	unsigned int nTarget;
	RING_VM_IR_LOAD;
	RING_VM_IR_SETLINENUMBER(RING_VM_IR_READIVALUE(RING_VM_IR_REG1));
	pItem = (Item *)RING_VM_IR_READPVALUE(RING_VM_IR_REG2);
	RING_VM_IR_UNLOAD;
	nTarget = RING_VM_IR_READIVALUE(RING_VM_IR_REG2);
	if (!ring_item_isdouble(pItem)) {
		pVM->nPC = nTarget;
		ring_vm_error(pVM, RING_VM_ERROR_FORLOOPDATATYPE);
		return;
	}
	ring_item_incdouble(pItem);
	pPushN = pVM->pByteCode + nTarget - 1;
	pJumpFor = pPushN + 1;
	if (ring_item_getdouble(pItem) > pPushN->aReg[0].dNumber) {
		pVM->nPC = pJumpFor->aReg[0].iNumber;
	} else {
		pVM->nPC = nTarget + 2;
	}
	pVM->pByteCodeIR = pJumpFor;
	if (ring_vm_timetofreetemplists(pVM)) {
		ring_vm_freetemplists(pVM);
	}
}

void ring_vm_setopcode(VM *pVM) {
	int nIns, nOPCode;
	nIns = RING_VM_IR_READIVALUE(RING_VM_IR_REG2) - 1;
	nOPCode = RING_VM_IR_READI;
	RING_VM_IR_OPCODEVALUE(nIns) = nOPCode;
}

void ring_vm_sumn(VM *pVM) {
	if (RING_VM_STACK_ISNUMBER) {
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN + RING_VM_IR_READD);
		return;
	}
	RING_VM_STACK_PUSHN;
	ring_vm_sum(pVM);
}

void ring_vm_subn(VM *pVM) {
	if (RING_VM_STACK_ISNUMBER) {
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN - RING_VM_IR_READD);
		return;
	}
	RING_VM_STACK_PUSHN;
	ring_vm_sub(pVM);
}

void ring_vm_muln(VM *pVM) {
	if (RING_VM_STACK_ISNUMBER) {
		RING_VM_CHECKOVERFLOW(RING_VM_STACK_READN, RING_VM_IR_READD);
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN * RING_VM_IR_READD);
		return;
	}
	RING_VM_STACK_PUSHN;
	ring_vm_mul(pVM);
}

void ring_vm_divn(VM *pVM) {
	if (RING_VM_STACK_ISNUMBER) {
		if (RING_VM_IR_READD == RING_ZERO) {
			ring_vm_error(pVM, RING_VM_ERROR_DIVIDEBYZERO);
			return;
		}
		RING_VM_CHECKOVERFLOW(RING_VM_STACK_READN, RING_VM_IR_READD);
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN / RING_VM_IR_READD);
		return;
	}
	RING_VM_STACK_PUSHN;
	ring_vm_div(pVM);
}

void ring_vm_modn(VM *pVM) {
	if (RING_VM_STACK_ISNUMBER) {
		if (RING_VM_IR_READD == RING_ZERO) {
			ring_vm_error(pVM, RING_VM_ERROR_DIVIDEBYZERO);
			return;
		}
		RING_VM_CHECKOVERFLOW(RING_VM_STACK_READN, RING_VM_IR_READD);
		RING_VM_STACK_SETNVALUE(fmod(RING_VM_STACK_READN, RING_VM_IR_READD));
		return;
	}
	RING_VM_STACK_PUSHN;
	ring_vm_mod(pVM);
}

void ring_vm_pown(VM *pVM) {
	if (RING_VM_STACK_ISNUMBER) {
		RING_VM_CHECKOVERFLOW(RING_VM_STACK_READN, RING_VM_IR_READD);
		RING_VM_STACK_SETNVALUE(pow(RING_VM_STACK_READN, RING_VM_IR_READD));
		return;
	}
	RING_VM_STACK_PUSHN;
	ring_vm_pow(pVM);
}

void ring_vm_checkitemsarray(VM *pVM, List *pList, unsigned int nIndex) {
	if ((pList->pItemsArray != NULL) || (nIndex == 1) || (nIndex == pList->nSize) ||
	    (pList->nSize <= RING_VM_SMALLLISTSIZE) || pVM->pRingState->lUsingThreads) {
		return;
	}
	if ((RING_VM_IR_READPVALUE(RING_VM_IR_REG1) == (void *)pList) &&
	    ((unsigned int)RING_VM_IR_READIVALUE(RING_VM_IR_REG2) == pList->nSize)) {
		ring_list_genarray_gc(pVM->pRingState, pList);
		return;
	}
	RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG1), pList);
	RING_VM_IR_READIVALUE(RING_VM_IR_REG2) = pList->nSize;
}

int ring_vm_lendstring(VM *pVM, List *pVar) {
	FuncCall *pFuncCall;
	ByteCode *pIns;
	Item *pItem;
	unsigned int x, nOPCode, lBraces;
	if (pVM->lTrace || (RING_VM_FUNCCALLSCOUNT == 0)) {
		return RING_FALSE;
	}
	pFuncCall = RING_VM_LASTFUNCCALL;
	if ((pFuncCall->nType != RING_FUNCTYPE_C) || (pFuncCall->nStatus != RING_FUNCSTATUS_LOAD) ||
	    (pVM->nSP <= pFuncCall->nSP) || !ring_vm_funcacceptlendstring(pVM)) {
		return RING_FALSE;
	}
	lBraces = ring_list_getsize(pVM->pBraceObjects) > 0;
	pIns = pVM->pByteCodeIR + 1;
	for (x = 0; x < RING_VM_LENDSTRING_INSTOCHECK; x++) {
		nOPCode = pIns->nOPCode;
		if (nOPCode == ICO_CALL) {
			break;
		}
		switch (nOPCode) {
		case ICO_PUSHN:
			break;
		case ICO_PUSH2N:
			break;
		case ICO_PUSHC:
			break;
		case ICO_PUSHV:
			break;
		case ICO_PUSHP:
			break;
		case ICO_PUSHPV:
			break;
		case ICO_PUSHPLOCAL:
			break;
		case ICO_PUSHARG:
			break;
		case ICO_LOADAPUSHV:
		case ICO_LOADADDRESS:
			if (lBraces) {
				return RING_FALSE;
			}
			break;
		default:
			return RING_FALSE;
		}
		pIns++;
	}
	if (x == RING_VM_LENDSTRING_INSTOCHECK) {
		return RING_FALSE;
	}
	pItem = &pVM->aStack[pVM->nSP];
	ring_item_deletecontent_gc(pVM->pRingState, pItem);
	pItem->nType = ITEMTYPE_STRING;
	pItem->lLendString = RING_TRUE;
	pItem->data.pString = RING_VAR_GETSTRINGOBJ(pVar);
	return RING_TRUE;
}

int ring_vm_funcacceptlendstring(VM *pVM) {
	FuncCall *pFuncCall;
	pFuncCall = RING_VM_LASTFUNCCALL;
	return pFuncCall->lLendString;
}
