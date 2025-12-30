/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_info_loadfunctions(RingState *pRingState) {
	RING_API_REGISTER("ringvm_fileslist", ring_vm_info_ringvmfileslist);
	RING_API_REGISTER("ringvm_calllist", ring_vm_info_ringvmcalllist);
	RING_API_REGISTER("ringvm_memorylist", ring_vm_info_ringvmmemorylist);
	RING_API_REGISTER("ringvm_functionslist", ring_vm_info_ringvmfunctionslist);
	RING_API_REGISTER("ringvm_classeslist", ring_vm_info_ringvmclasseslist);
	RING_API_REGISTER("ringvm_packageslist", ring_vm_info_ringvmpackageslist);
	RING_API_REGISTER("ringvm_cfunctionslist", ring_vm_info_ringvmcfunctionslist);
	RING_API_REGISTER("ringvm_settrace", ring_vm_info_ringvmsettrace);
	RING_API_REGISTER("ringvm_tracedata", ring_vm_info_ringvmtracedata);
	RING_API_REGISTER("ringvm_traceevent", ring_vm_info_ringvmtraceevent);
	RING_API_REGISTER("ringvm_tracefunc", ring_vm_info_ringvmtracefunc);
	RING_API_REGISTER("ringvm_scopescount", ring_vm_info_ringvmscopescount);
	RING_API_REGISTER("ringvm_evalinscope", ring_vm_info_ringvmevalinscope);
	RING_API_REGISTER("ringvm_passerror", ring_vm_info_ringvmpasserror);
	RING_API_REGISTER("ringvm_hideerrormsg", ring_vm_info_ringvmhideerrormsg);
	RING_API_REGISTER("ringvm_callfunc", ring_vm_info_ringvmcallfunc);
	RING_API_REGISTER("ringvm_info", ring_vm_info_ringvminfo);
	RING_API_REGISTER("ringvm_genarray", ring_vm_info_ringvmgenarray);
	RING_API_REGISTER("ringvm_codelist", ring_vm_info_ringvmcodelist);
	RING_API_REGISTER("ringvm_ismempool", ring_vm_info_ringvmismempool);
	RING_API_REGISTER("ringvm_runcode", ring_vm_info_ringvmruncode);
	RING_API_REGISTER("ringvm_ringolists", ring_vm_info_ringvmringolists);
	RING_API_REGISTER("ringvm_translatecfunction", ring_vm_info_ringvmtranslatecfunction);
	RING_API_REGISTER("ringvm_writeringo", ring_vm_info_ringvmwriteringo);
}

void ring_vm_info_ringvmfileslist(void *pPointer) {
	VM *pVM;
	List *pList;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	ring_list_copy_gc(pVM->pRingState, pList, pVM->pRingState->pRingFilesList);
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmcalllist(void *pPointer) {
	VM *pVM;
	List *pList, *pList2;
	unsigned int x;
	FuncCall *pFuncCall;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	/* Copy Important Information */
	for (x = 1; x <= RING_VM_FUNCCALLSCOUNT; x++) {
		pFuncCall = RING_VM_GETFUNCCALL(x);
		pList2 = ring_list_newlist_gc(pVM->pRingState, pList);
		ring_list_addint_gc(pVM->pRingState, pList2, pFuncCall->nType);
		ring_list_addstring_gc(pVM->pRingState, pList2, pFuncCall->cName);
		ring_list_addint_gc(pVM->pRingState, pList2, pFuncCall->nPC);
		ring_list_addint_gc(pVM->pRingState, pList2, pFuncCall->nSP);
		ring_list_addint_gc(pVM->pRingState, pList2, pFuncCall->lMethod);
		ring_list_addint_gc(pVM->pRingState, pList2, pFuncCall->nCallerPC);
		ring_list_addint_gc(pVM->pRingState, pList2, pFuncCall->nLineNumber);
		ring_list_addint_gc(pVM->pRingState, pList2, pFuncCall->nParaCount);
	}
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmmemorylist(void *pPointer) {
	VM *pVM;
	List *pList, *pList2;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	RING_VM_COPYSCOPESTOLIST(pList);
	pList2 = RING_API_NEWLIST;
	ring_list_copy_gc(pVM->pRingState, pList2, pList);
	RING_API_RETLISTBYREF(pList2);
}

void ring_vm_info_ringvmfunctionslist(void *pPointer) {
	VM *pVM;
	List *pList;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	ring_list_copy_gc(pVM->pRingState, pList, pVM->pFunctionsMap);
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmclasseslist(void *pPointer) {
	VM *pVM;
	List *pList;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	ring_list_copy_gc(pVM->pRingState, pList, pVM->pClassesMap);
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmpackageslist(void *pPointer) {
	VM *pVM;
	List *pList;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	ring_list_copy_gc(pVM->pRingState, pList, pVM->pPackagesMap);
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmcfunctionslist(void *pPointer) {
	VM *pVM;
	List *pList;
	CFunction *pCFunc;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	/* Add C Functions to the list */
	pCFunc = pVM->pCFunction;
	while (pCFunc != NULL) {
		ring_list_addstring_gc(pVM->pRingState, pList, pCFunc->cName);
		pCFunc = pCFunc->pNext;
	}
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmsettrace(void *pPointer) {
	VM *pVM;
	char *cStr;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		cStr = RING_API_GETSTRING(1);
		if (strcmp(cStr, RING_CSTR_EMPTY) == 0) {
			pVM->lTrace = 0;
			ring_string_set_gc(((VM *)pPointer)->pRingState, pVM->pTrace, RING_CSTR_EMPTY);
		} else {
			pVM->lTrace = 1;
			ring_string_set_gc(((VM *)pPointer)->pRingState, pVM->pTrace, cStr);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmtracedata(void *pPointer) {
	VM *pVM;
	List *pList;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	ring_list_copy_gc(pVM->pRingState, pList, pVM->pTraceData);
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmtraceevent(void *pPointer) {
	VM *pVM;
	pVM = (VM *)pPointer;
	RING_API_RETNUMBER(pVM->nTraceEvent);
}

void ring_vm_info_ringvmtracefunc(void *pPointer) {
	VM *pVM;
	pVM = (VM *)pPointer;
	RING_API_RETSTRING(ring_string_get(pVM->pTrace));
}

void ring_vm_info_ringvmscopescount(void *pPointer) {
	/* We the current scope of this function */
	RING_API_RETNUMBER(RING_API_SCOPESCOUNT);
}

void ring_vm_info_ringvmevalinscope(void *pPointer) {
	VM *pVM;
	List *pActiveMem;
	const char *cStr;
	int nScope, nSize, x;
	VMState *pVMState;
	List aScopes[RING_VM_STACK_SIZE];
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISNUMBER(1) && RING_API_ISSTRING(2)) {
		/* We must get cStr before we change the pVM->pActiveMem */
		nScope = (int)RING_API_GETNUMBER(1);
		cStr = RING_API_GETSTRING(2);
		nSize = RING_VM_SCOPESCOUNT;
		if ((nScope < 1) || (nScope >= nSize)) {
			RING_API_ERROR(RING_API_BADPARARANGE);
			return;
		}
		/* Save State */
		pVMState = ring_vm_savestateformethods(pVM);
		pActiveMem = pVM->pActiveMem;
		pVM->pActiveMem = RING_VM_GETSCOPE(nScope);
		ring_vm_newscopeid(pVM);
		/* Prepare the current scope */
		for (x = nScope + 1; x <= RING_VM_STACK_SIZE - 1; x++) {
			aScopes[x] = pVM->aScopes[x];
			ring_list_new2_gc(pVM->pRingState, RING_VM_GETSCOPE(x), RING_ZERO);
		}
		RING_VM_SETCURRENTSCOPE(nScope);
		pVM->nEvalInScope++;
		ring_vm_runcode(pVM, cStr);
		pVM->nEvalInScope--;
		/* Restore the current scope */
		for (x = nScope + 1; x <= RING_VM_STACK_SIZE - 1; x++) {
			ring_list_deleteallitems_gc(pVM->pRingState, RING_VM_GETSCOPE(x));
			pVM->aScopes[x] = aScopes[x];
		}
		RING_VM_SETCURRENTSCOPE(nSize);
		pVM->pActiveMem = pActiveMem;
		ring_vm_newscopeid(pVM);
		/* Restore State */
		ring_vm_restorestateformethods(pVM, pVMState);
		ring_vmstate_delete(pVM->pRingState, pVMState);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmpasserror(void *pPointer) {
	VM *pVM;
	pVM = (VM *)pPointer;
	pVM->lPassError = 1;
}

void ring_vm_info_ringvmhideerrormsg(void *pPointer) {
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISNUMBER(1)) {
		pVM->lHideErrorMsg = (int)RING_API_GETNUMBER(1);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmcallfunc(void *pPointer) {
	VM *pVM;
	String *pString;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		/* We create a string, because the current scope will be deleted by ring_vm_callfunc() */
		pString = ring_string_new_gc(((VM *)pPointer)->pRingState, RING_API_GETSTRING(1));
		ring_vm_callfunction(pVM, ring_string_get(pString));
		ring_string_delete_gc(((VM *)pPointer)->pRingState, pString);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvminfo(void *pPointer) {
	VM *pVM;
	List *pList;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	/*
	**  Add the list items
	**  Lists Size (12 Items)
	*/
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)ring_list_getsize(pVM->pRingState->pRingFilesList));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)ring_list_getsize(pVM->pRingState->pRingFilesStack));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)RING_VM_INSTRUCTIONSCOUNT);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)RING_VM_SCOPESCOUNT);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)ring_list_getsize(pVM->pTempMem));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)ring_list_getsize(pVM->pPCBlockFlag));
	ring_list_adddouble_gc(pVM->pRingState, pList, pVM->nLoadAddressScope);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)ring_list_getsize(pVM->pBeforeObjState));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)RING_VM_FUNCCALLSCOUNT);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)ring_list_getsize(pVM->pTry));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)ring_list_getsize(pVM->pScopeNewObj));
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)ring_list_getsize(pVM->pSetProperty));
	/* Values */
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->nInsideEval);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->lRetEvalDontDelete);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->nRunCode);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->pRingState->lRunFromSubThread);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->nPC);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->nSP);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->nFuncSP);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)RING_VM_IR_GETLINENUMBER);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->nDecimals);
	ring_list_adddouble_gc(pVM->pRingState, pList, (double)pVM->lActiveError);
	ring_list_addstring(pList, pVM->cFileName);
	/*
	**  Memory Pool
	**  Check if used or not
	*/
	if (pVM->pRingState->vPoolManager.pBlockStart == NULL) {
		ring_list_adddouble_gc(pVM->pRingState, pList, 0.0);
	} else {
		ring_list_adddouble_gc(pVM->pRingState, pList, 1.0);
	}
	/* Check if we have current item or not! */
	if (pVM->pRingState->vPoolManager.pCurrentItem != NULL) {
		ring_list_adddouble_gc(pVM->pRingState, pList, 1.0);
	} else {
		ring_list_adddouble_gc(pVM->pRingState, pList, 0.0);
	}
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmgenarray(void *pPointer) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		ring_list_genarray(RING_API_GETLIST(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmcodelist(void *pPointer) {
	VM *pVM;
	List *pList;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	ring_vm_bytecode2list(pVM, pList);
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmismempool(void *pPointer) {
	VM *pVM;
	List *pList;
	pVM = (VM *)pPointer;
	/* Try creating a large list */
	pList = ring_list_new_gc(pVM->pRingState, RING_VMINFO_ITEMSTOCHECKMEMPOOL);
	if (pVM->pRingState->vPoolManager.pCurrentItem != NULL) {
		RING_API_RETNUMBER(1);
	} else {
		RING_API_RETNUMBER(0);
	}
	/* Delete the List */
	ring_list_delete_gc(pVM->pRingState, pList);
}

void ring_vm_info_ringvmruncode(void *pPointer) {
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		ring_vm_runcode(pVM, RING_API_GETSTRING(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_info_ringvmringolists(void *pPointer) {
	VM *pVM;
	List *pList;
	List *pListFunctions, *pListClasses, *pListPackages, *pListCode, *pListFiles, *pListStack;
	unsigned int nSize;
	int lOutput;
	char *cBuffer;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (!RING_API_ISSTRING(1)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
	cBuffer = RING_API_GETSTRING(1);
	nSize = RING_API_GETSTRINGSIZE(1);
	if ((nSize == RING_ZERO) || (nSize < RING_OBJFILE_MINSIZE) || (strcmp(cBuffer + nSize - 6, "\n$!${$") != 0)) {
		RING_API_ERROR(RING_OBJFILEWRONGTYPE);
		return;
	}
	pList = RING_API_NEWLIST;
	pListFiles = ring_list_newlist_gc(pVM->pRingState, pList);
	pListFunctions = ring_list_newlist_gc(pVM->pRingState, pList);
	pListClasses = ring_list_newlist_gc(pVM->pRingState, pList);
	pListPackages = ring_list_newlist_gc(pVM->pRingState, pList);
	pListCode = ring_list_newlist_gc(pVM->pRingState, pList);
	pListStack = ring_list_newlist_gc(pVM->pRingState, pList);
	lOutput = ring_objfile_processstring(pVM->pRingState, cBuffer, nSize, pListFiles, pListFunctions, pListClasses,
					     pListPackages, pListCode, pListStack);
	if (lOutput == RING_FALSE) {
		RING_API_ERROR(RING_OBJFILEWRONGTYPE);
		return;
	}
	ring_list_deleteitem_gc(pVM->pRingState, pList, ring_list_getsize(pList));
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_info_ringvmtranslatecfunction(void *pPointer) {
	VM *pVM;
	CFunction *pCFunc;
	const char *cStr, *cStr2;
	RingState *pRingState;
	List *pTranslatedCFunctions;
	pVM = (VM *)pPointer;
	pRingState = pVM->pRingState;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (!(RING_API_ISSTRING(1) && RING_API_ISSTRING(2))) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
	cStr = RING_API_GETSTRING(1);
	cStr2 = RING_API_GETSTRING(2);
	pCFunc = pVM->pCFunction;
	while (pCFunc != NULL) {
		if (strcmp(pCFunc->cName, cStr) == 0) {
			break;
		}
		pCFunc = pCFunc->pNext;
	}
	if (pCFunc == NULL) {
		RING_API_ERROR("Can't find the C function!");
		return;
	}
	/* Add the function to the optional functions list to have a static literal for the function name */
	pTranslatedCFunctions = pVM->pLiterals;
	ring_list_addstring(pTranslatedCFunctions, cStr2);
	cStr2 = ring_list_getstring(pTranslatedCFunctions, ring_list_getsize(pTranslatedCFunctions));
	RING_API_REGISTER(cStr2, pCFunc->pFunc);
}

void ring_vm_info_ringvmwriteringo(void *pPointer) {
	VM *pVM;
	List *pList;
	List *pListFunctions, *pListClasses, *pListPackages, *pListCode, *pListFiles;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if ((!RING_API_ISSTRING(1)) || (!RING_API_ISLIST(2))) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}
	pList = RING_API_GETLIST(2);
	if ((ring_list_getsize(pList) != 5) || (!ring_list_islist(pList, 1)) || (!ring_list_islist(pList, 2)) ||
	    (!ring_list_islist(pList, 3)) || (!ring_list_islist(pList, 4)) || (!ring_list_islist(pList, 5))) {
		RING_API_ERROR("The list must contain five items, and each item must be a sublist.");
		return;
	}
	pListFiles = ring_list_getlist(pList, 1);
	pListFunctions = ring_list_getlist(pList, 2);
	pListClasses = ring_list_getlist(pList, 3);
	pListPackages = ring_list_getlist(pList, 4);
	pListCode = ring_list_getlist(pList, 5);
	ring_objfile_writecontent(pVM->pRingState, RING_API_GETSTRING(1), pListFiles, pListFunctions, pListClasses,
				  pListPackages, pListCode);
}
