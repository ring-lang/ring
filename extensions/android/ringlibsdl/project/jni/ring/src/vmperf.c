/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_pushp ( VM *pVM )
{
	RING_VM_STACK_PUSHP ;
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
	ring_vm_updatescopeinfo(pVM,RING_VARSCOPE_GLOBAL);
}

void ring_vm_pushplocal ( VM *pVM )
{
	/* Check Scope Life Time */
	if ( RING_VM_IR_GETINTREG != pVM->nActiveScopeID ) {
		/* Reset register used for the pointer */
		RING_VM_IR_READIVALUE(RING_VM_IR_REG2) = 0 ;
		RING_VM_IR_SETREG2TYPE(RING_VM_REGTYPE_INT);
		RING_VM_IR_OPCODE = ICO_LOADADDRESS ;
		ring_vm_loadaddress(pVM);
		return ;
	}
	RING_VM_STACK_PUSHPVALUE(RING_VM_IR_READPVALUE(RING_VM_IR_REG2)) ;
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
	ring_vm_updatescopeinfo(pVM,RING_VARSCOPE_LOCAL);
}

void ring_vm_pusharg ( VM *pVM )
{
	List *pList  ;
	pList = ring_list_getlist(pVM->pActiveMem,RING_VM_IR_GETINTREG);
	/* Check if the variable list contains another type */
	if ( ring_list_getlisttype(pList) != RING_VM_IR_GETSMALLINTREG ) {
		RING_VM_IR_OPCODE = ICO_LOADADDRESS ;
		RING_VM_IR_SETFLAGREG(RING_FALSE);
		ring_vm_loadaddress(pVM);
		return ;
	}
	RING_VM_STACK_PUSHPVALUE(pList) ;
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
	ring_vm_updatescopeinfo(pVM,RING_VARSCOPE_LOCAL);
}

void ring_vm_updatescopeinfo ( VM *pVM,int nScope )
{
	/* Update Scope Information */
	if ( pVM->nLoadAddressScope == RING_VARSCOPE_NOTHING ) {
		pVM->nLoadAddressScope = nScope ;
	}
	pVM->nVarScope = nScope ;
	/* Check lNewRef Flag */
	ring_list_resetlnewref((List *) RING_VM_STACK_READP);
	/* Check if we have ICO_PUSHV */
	if ( RING_VM_IR_GETFLAGREG2 ) {
		pVM->nPC++ ;
		ring_vm_varpushv(pVM);
	}
}

void ring_vm_incp ( VM *pVM )
{
	List *pVar  ;
	pVar = (List *) RING_VM_IR_READP ;
	ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,ring_list_getdouble(pVar,RING_VAR_VALUE) + 1);
}

void ring_vm_pushpv ( VM *pVM )
{
	ring_vm_pushp(pVM);
	ring_vm_varpushv(pVM);
}

void ring_vm_incjump ( VM *pVM )
{
	List *pVar  ;
	Item *pItem  ;
	double nNum1,nNum2  ;
	int nLine, lPerformance  ;
	lPerformance = RING_FALSE ;
	if ( ring_vm_findvar(pVM, RING_VM_IR_READC ) == 0 ) {
		ring_vm_newvar(pVM, RING_VM_IR_READC);
	}
	pVar = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	pItem = ring_list_getitem(pVar,RING_VAR_VALUE) ;
	nNum1 = ring_list_getdouble(pVM->pForStep,ring_list_getsize(pVM->pForStep));
	/* Check Data */
	if ( ! ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
		ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
		return ;
	}
	nNum2 = ring_list_getdouble(pVar,RING_VAR_VALUE) ;
	ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,nNum2 +nNum1);
	/* Change Instruction for Performance */
	if ( pVM->nVarScope == RING_VARSCOPE_GLOBAL ) {
		/* Replace ICO_INCJUMP with IncPJUMP for better performance */
		if ( nNum1 == 1.0 ) {
			RING_VM_IR_OPCODE = ICO_INCPJUMPSTEP1 ;
		}
		else {
			RING_VM_IR_OPCODE = ICO_INCPJUMP ;
		}
		lPerformance = RING_TRUE ;
	}
	else if ( pVM->nVarScope == RING_VARSCOPE_LOCAL ) {
		/* Replace ICO_INCJUMP with IncLPJUMP for better performance */
		if ( nNum1 == 1.0 ) {
			RING_VM_IR_OPCODE = ICO_INCLPJUMPSTEP1 ;
		}
		else {
			RING_VM_IR_OPCODE = ICO_INCLPJUMP ;
		}
		RING_VM_IR_SETINTREG(pVM->nActiveScopeID);
		lPerformance = RING_TRUE ;
	}
	/* Line Number and Item Pointer */
	RING_VM_IR_LOAD ;
	nLine = RING_VM_IR_READIVALUE(RING_VM_IR_REG1) ;
	RING_VM_IR_SETLINENUMBER(nLine);
	if ( lPerformance ) {
		RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG2),pItem);
		RING_VM_IR_SETREG2TYPE(RING_VM_REGTYPE_POINTER);
	}
	RING_VM_IR_UNLOAD ;
	/* Jump */
	pVM->nPC = RING_VM_IR_READIVALUE(RING_VM_IR_REG2) ;
	RING_VM_STACK_PUSHNVALUE(ring_list_getdouble(pVar,RING_VAR_VALUE));
}

void ring_vm_incpjump ( VM *pVM )
{
	Item *pItem  ;
	double nNum1,nNum2  ;
	RING_VM_IR_LOAD ;
	RING_VM_IR_SETLINENUMBER(RING_VM_IR_READIVALUE(RING_VM_IR_REG1));
	pItem = (Item *) RING_VM_IR_READPVALUE(RING_VM_IR_REG2) ;
	RING_VM_IR_UNLOAD ;
	nNum1 = ring_list_getdouble(pVM->pForStep,ring_list_getsize(pVM->pForStep));
	/* Check Data */
	if ( ! ring_item_isdouble(pItem) ) {
		ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
		return ;
	}
	nNum2 = ring_item_getdouble(pItem) ;
	ring_item_setdouble_gc(pVM->pRingState,pItem,nNum2 + nNum1);
	/* Jump */
	pVM->nPC = RING_VM_IR_READIVALUE(RING_VM_IR_REG2) ;
	RING_VM_STACK_PUSHNVALUE(ring_item_getdouble(pItem));
}

void ring_vm_inclpjump ( VM *pVM )
{
	/* Check Scope Life Time */
	if ( RING_VM_IR_GETINTREG != pVM->nActiveScopeID ) {
		ring_vm_incjump(pVM);
		return ;
	}
	ring_vm_incpjump(pVM);
}

void ring_vm_loadfuncp ( VM *pVM )
{
	FuncCall *pFuncCall  ;
	/* Check not defining a Ring function that replace a C function */
	if ( (RING_VM_IR_GETFLAGREG == RING_FUNCTYPE_C) && (ring_list_getsize(pVM->pFunctionsMap) != RING_VM_IR_GETSMALLINTREG) ) {
		ring_vm_loadfunc(pVM);
		return ;
	}
	/* Add FuncCall Structure */
	pFuncCall = ring_vm_funccall_new(pVM);
	if (pFuncCall == NULL) return ;
	pFuncCall->nType = RING_VM_IR_GETFLAGREG ;
	pFuncCall->cName = RING_VM_IR_READC ;
	pFuncCall->nPC = RING_VM_IR_GETINTREG ;
	pFuncCall->nSP = pVM->nSP ;
	pFuncCall->nLineNumber = RING_VM_IR_GETLINENUMBER ;
	pFuncCall->pFunc = (void(*)(void *)) RING_VM_IR_READPVALUE(RING_VM_IR_REG2) ;
	/* Store the file name */
	pFuncCall->cFileName = pVM->cFileName ;
	if ( pFuncCall->nType == RING_FUNCTYPE_SCRIPT ) {
		pVM->cPrevFileName = pVM->cFileName ;
	}
	pFuncCall->cNewFileName = pVM->cFileName ;
	/* Method/Function & Scope */
	pFuncCall->lMethod = RING_VM_IR_GETFLAGREG2 ;
	pFuncCall->nLoadAddressScope = pVM->nLoadAddressScope ;
	pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
	/* Store List information */
	pFuncCall->nListStart = pVM->nListStart ;
	pFuncCall->nNestedLists = ring_list_getsize(pVM->pNestedLists) ;
	ring_vm_newnestedlists(pVM);
}

void ring_vm_incpjumpstep1 ( VM *pVM )
{
	Item *pItem  ;
	RING_VM_IR_LOAD ;
	RING_VM_IR_SETLINENUMBER(RING_VM_IR_READIVALUE(RING_VM_IR_REG1));
	pItem = (Item *) RING_VM_IR_READPVALUE(RING_VM_IR_REG2) ;
	RING_VM_IR_UNLOAD ;
	/* Jump */
	pVM->nPC = RING_VM_IR_READIVALUE(RING_VM_IR_REG2) ;
	/* Check Data */
	if ( ! ring_item_isdouble(pItem) ) {
		ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
		return ;
	}
	RING_VM_STACK_PUSHNVALUE(ring_item_incdouble(pItem));
}

void ring_vm_inclpjumpstep1 ( VM *pVM )
{
	/* Check Scope Life Time */
	if ( RING_VM_IR_GETINTREG != pVM->nActiveScopeID ) {
		ring_vm_incjump(pVM);
		return ;
	}
	ring_vm_incpjumpstep1(pVM);
}

void ring_vm_setopcode ( VM *pVM )
{
	int nIns,nOPCode  ;
	nIns = RING_VM_IR_READIVALUE(RING_VM_IR_REG2) - 1 ;
	nOPCode = RING_VM_IR_READI ;
	RING_VM_IR_OPCODEVALUE(nIns) = nOPCode ;
}

void ring_vm_sumn ( VM *pVM )
{
	if ( RING_VM_STACK_ISNUMBER ) {
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN + RING_VM_IR_READD);
		return ;
	}
	RING_VM_STACK_PUSHN ;
	ring_vm_sum(pVM);
}

void ring_vm_subn ( VM *pVM )
{
	if ( RING_VM_STACK_ISNUMBER ) {
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN - RING_VM_IR_READD);
		return ;
	}
	RING_VM_STACK_PUSHN ;
	ring_vm_sub(pVM);
}

void ring_vm_muln ( VM *pVM )
{
	if ( RING_VM_STACK_ISNUMBER ) {
		RING_VM_CHECKOVERFLOW(RING_VM_STACK_READN,RING_VM_IR_READD) ;
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN * RING_VM_IR_READD);
		return ;
	}
	RING_VM_STACK_PUSHN ;
	ring_vm_mul(pVM);
}

void ring_vm_divn ( VM *pVM )
{
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_IR_READD == RING_ZERO ) {
			ring_vm_error(pVM,RING_VM_ERROR_DIVIDEBYZERO);
			return ;
		}
		RING_VM_CHECKOVERFLOW(RING_VM_STACK_READN,RING_VM_IR_READD) ;
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN / RING_VM_IR_READD);
		return ;
	}
	RING_VM_STACK_PUSHN ;
	ring_vm_div(pVM);
}

void ring_vm_modn ( VM *pVM )
{
	if ( RING_VM_STACK_ISNUMBER ) {
		if ( RING_VM_IR_READD == RING_ZERO ) {
			ring_vm_error(pVM,RING_VM_ERROR_DIVIDEBYZERO);
			return ;
		}
		RING_VM_CHECKOVERFLOW(RING_VM_STACK_READN,RING_VM_IR_READD) ;
		RING_VM_STACK_SETNVALUE(fmod(RING_VM_STACK_READN,RING_VM_IR_READD));
		return ;
	}
	RING_VM_STACK_PUSHN ;
	ring_vm_mod(pVM);
}

void ring_vm_pown ( VM *pVM )
{
	if ( RING_VM_STACK_ISNUMBER ) {
		RING_VM_CHECKOVERFLOW(RING_VM_STACK_READN,RING_VM_IR_READD) ;
		RING_VM_STACK_SETNVALUE(pow(RING_VM_STACK_READN,RING_VM_IR_READD));
		return ;
	}
	RING_VM_STACK_PUSHN ;
	ring_vm_pow(pVM);
}
