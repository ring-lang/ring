/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_info_loadfunctions ( RingState *pRingState )
{
	RING_API_REGISTER("ringvm_fileslist",ring_vm_info_ringvmfileslist);
	RING_API_REGISTER("ringvm_calllist",ring_vm_info_ringvmcalllist);
	RING_API_REGISTER("ringvm_memorylist",ring_vm_info_ringvmmemorylist);
	RING_API_REGISTER("ringvm_functionslist",ring_vm_info_ringvmfunctionslist);
	RING_API_REGISTER("ringvm_classeslist",ring_vm_info_ringvmclasseslist);
	RING_API_REGISTER("ringvm_packageslist",ring_vm_info_ringvmpackageslist);
	RING_API_REGISTER("ringvm_cfunctionslist",ring_vm_info_ringvmcfunctionslist);
	RING_API_REGISTER("ringvm_settrace",ring_vm_info_ringvmsettrace);
	RING_API_REGISTER("ringvm_tracedata",ring_vm_info_ringvmtracedata);
	RING_API_REGISTER("ringvm_traceevent",ring_vm_info_ringvmtraceevent);
	RING_API_REGISTER("ringvm_tracefunc",ring_vm_info_ringvmtracefunc);
	RING_API_REGISTER("ringvm_scopescount",ring_vm_info_ringvmscopescount);
	RING_API_REGISTER("ringvm_evalinscope",ring_vm_info_ringvmevalinscope);
	RING_API_REGISTER("ringvm_passerror",ring_vm_info_ringvmpasserror);
	RING_API_REGISTER("ringvm_hideerrormsg",ring_vm_info_ringvmhideerrormsg);
	RING_API_REGISTER("ringvm_callfunc",ring_vm_info_ringvmcallfunc);
	RING_API_REGISTER("ringvm_info",ring_vm_info_ringvminfo);
	RING_API_REGISTER("ringvm_genarray",ring_vm_info_ringvmgenarray);
	RING_API_REGISTER("ringvm_codelist",ring_vm_info_ringvmcodelist);
	RING_API_REGISTER("ringvm_ismempool",ring_vm_info_ringvmismempool);
	RING_API_REGISTER("ringvm_runcode",ring_vm_info_ringvmruncode);
}

void ring_vm_info_ringvmfileslist ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	ring_list_copy_gc(pVM->pRingState,pList,pVM->pRingState->pRingFilesList);
	RING_API_RETLIST(pList);
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmcalllist ( void *pPointer )
{
	VM *pVM  ;
	List *pList, *pList2  ;
	int x  ;
	FuncCall *pFuncCall  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	/* Copy Important Information */
	for ( x = 1 ; x <= RING_VM_FUNCCALLSCOUNT ; x++ ) {
		pFuncCall = RING_VM_GETFUNCCALL(x) ;
		pList2 = ring_list_newlist_gc(pVM->pRingState,pList);
		ring_list_addint_gc(pVM->pRingState,pList2,pFuncCall->nType);
		ring_list_addstring_gc(pVM->pRingState,pList2,pFuncCall->cName);
		ring_list_addint_gc(pVM->pRingState,pList2,pFuncCall->nPC);
		ring_list_addint_gc(pVM->pRingState,pList2,pFuncCall->nSP);
		ring_list_addint_gc(pVM->pRingState,pList2,pFuncCall->lMethod);
		ring_list_addint_gc(pVM->pRingState,pList2,pFuncCall->nCallerPC);
	}
	RING_API_RETLIST(pList);
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmmemorylist ( void *pPointer )
{
	VM *pVM  ;
	List *pList, *pList2  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(((VM *) pPointer)->pRingState,RING_ZERO) ;
	RING_VM_COPYSCOPESTOLIST(pList);
	pList2 = RING_API_NEWLIST ;
	ring_list_copy_gc(pVM->pRingState,pList2,pList);
	ring_list_delete_gc(((VM *) pPointer)->pRingState,pList);
	RING_API_RETLIST(pList2);
}

void ring_vm_info_ringvmfunctionslist ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	ring_list_copy_gc(pVM->pRingState,pList,pVM->pFunctionsMap);
	RING_API_RETLIST(pList);
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmclasseslist ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	ring_list_copy_gc(pVM->pRingState,pList,pVM->pClassesMap);
	RING_API_RETLIST(pList);
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmpackageslist ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	ring_list_copy_gc(pVM->pRingState,pList,pVM->pPackagesMap);
	RING_API_RETLIST(pList);
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmcfunctionslist ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	CFunction *pCFunc  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	/* Add C Functions to the list */
	pCFunc = pVM->pCFunction ;
	while ( pCFunc != NULL ) {
		ring_list_addstring_gc(pVM->pRingState,pList,pCFunc->cName);
		pCFunc = pCFunc->pNext ;
	}
	RING_API_RETLIST(pList);
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmsettrace ( void *pPointer )
{
	VM *pVM  ;
	char *cStr  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		if ( strcmp(cStr,RING_CSTR_EMPTY) == 0 ) {
			pVM->lTrace = 0 ;
			ring_string_set_gc(((VM *) pPointer)->pRingState,pVM->pTrace,RING_CSTR_EMPTY);
		}
		else {
			pVM->lTrace = 1 ;
			ring_string_set_gc(((VM *) pPointer)->pRingState,pVM->pTrace,cStr);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmtracedata ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	ring_list_copy_gc(pVM->pRingState,pList,pVM->pTraceData);
	RING_API_RETLIST(pList);
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmtraceevent ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	RING_API_RETNUMBER(pVM->nTraceEvent);
}

void ring_vm_info_ringvmtracefunc ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	RING_API_RETSTRING(ring_string_get(pVM->pTrace));
}

void ring_vm_info_ringvmscopescount ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	/* We the current scope of this function */
	RING_API_RETNUMBER(RING_API_SCOPESCOUNT);
}

void ring_vm_info_ringvmevalinscope ( void *pPointer )
{
	VM *pVM  ;
	List *pActiveMem  ;
	const char *cStr  ;
	int nScope,nSize  ;
	VMState *pVMState  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISNUMBER(1) && RING_API_ISSTRING(2) ) {
		/* We must get cStr before we change the pVM->pActiveMem */
		nScope = (int) RING_API_GETNUMBER(1) ;
		cStr = RING_API_GETSTRING(2) ;
		pActiveMem = pVM->pActiveMem ;
		pVM->pActiveMem = RING_VM_GETSCOPE(nScope) ;
		pVM->nActiveScopeID++ ;
		/* Prepare the current scope */
		nSize = RING_VM_SCOPESCOUNT ;
		RING_VM_SETCURRENTSCOPE(nScope);
		pVM->nEvalInScope++ ;
		/* Save State */
		pVMState = ring_vm_savestateformethods(pVM);
		ring_vm_runcode(pVM,cStr);
		/* Restore State */
		ring_vm_restorestateformethods(pVM,pVMState);
		ring_vmstate_delete(pVM->pRingState,pVMState);
		pVM->nEvalInScope-- ;
		/* Restore the current scope */
		RING_VM_SETCURRENTSCOPE(nSize);
		pVM->pActiveMem = pActiveMem ;
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmpasserror ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	pVM->lPassError = 1 ;
}

void ring_vm_info_ringvmhideerrormsg ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		pVM->lHideErrorMsg = (int) RING_API_GETNUMBER(1) ;
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmcallfunc ( void *pPointer )
{
	VM *pVM  ;
	String *pString  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		/* We create a string, because the current scope will be deleted by ring_vm_callfunc() */
		pString = ring_string_new_gc(((VM *) pPointer)->pRingState,RING_API_GETSTRING(1));
		ring_vm_callfunction(pVM,ring_string_get(pString));
		ring_string_delete_gc(((VM *) pPointer)->pRingState,pString);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvminfo ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	/*
	**  Add the list items 
	**  Lists Size (12 Items) 
	*/
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pRingState->pRingFilesList));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pRingState->pRingFilesStack));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) RING_VM_INSTRUCTIONSCOUNT);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) RING_VM_SCOPESCOUNT);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pTempMem));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pPCBlockFlag));
	ring_list_adddouble_gc(pVM->pRingState, pList, pVM->nLoadAddressScope);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pBeforeObjState));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) RING_VM_FUNCCALLSCOUNT);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pTry));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pScopeNewObj));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pSetProperty));
	/* Values */
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nInsideEval);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->lRetEvalDontDelete);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nRunCode);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->pRingState->lRunFromThread);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nPC);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nSP);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nFuncSP);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) RING_VM_IR_GETLINENUMBER);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nDecimals);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->lActiveError);
	ring_list_addstring(pList,pVM->cFileName);
	/*
	**  Memory Pool 
	**  Check if used or not 
	*/
	if ( pVM->pRingState->vPoolManager.pBlockStart == NULL ) {
		ring_list_adddouble_gc(pVM->pRingState, pList, 0.0);
	}
	else {
		ring_list_adddouble_gc(pVM->pRingState, pList, 1.0);
	}
	/* Check if we have current item or not! */
	if ( pVM->pRingState->vPoolManager.pCurrentItem != NULL ) {
		ring_list_adddouble_gc(pVM->pRingState, pList, 1.0);
	}
	else {
		ring_list_adddouble_gc(pVM->pRingState, pList, 0.0);
	}
	RING_API_RETLIST(pList);
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmgenarray ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		ring_list_genarray(RING_API_GETLIST(1));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmcodelist ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	pVM = (VM *) pPointer ;
	pList = RING_API_NEWLIST ;
	ring_vm_bytecode2list(pVM,pList);
	RING_API_RETLIST(pList);
}

void ring_vm_info_ringvmismempool ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	pVM = (VM *) pPointer ;
	/* Try creating a large list */
	pList = ring_list_new_gc(pVM->pRingState,RING_VMINFO_ITEMSTOCHECKMEMPOOL);
	if ( pVM->pRingState->vPoolManager.pCurrentItem != NULL ) {
		RING_API_RETNUMBER(1);
	}
	else {
		RING_API_RETNUMBER(0);
	}
	/* Delete the List */
	ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_info_ringvmruncode ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		ring_vm_runcode(pVM,RING_API_GETSTRING(1));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
