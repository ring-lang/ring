/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

int ring_vm_loadfunc(VM *pVM) {
	/*
	**  When pVM->nInsideEval == 1 In this case we are using eval("somefunction()")
	**  We don't use optimization, it's not required because the code will not be executed again
	*/
	return ring_vm_loadfunc2(pVM, RING_VM_IR_READC, !pVM->nInsideEval);
}

RING_API int ring_vm_loadfunc2(VM *pVM, const char *cStr, int nPerformance) {
	List *pList, *pList2, *pOptionalFunctions;
	int y, nPos;
	FuncCall *pFuncCall;
	CFunction *pCFunc;
	CFunction vCFunc;
	/* Search */
	for (y = 2; y >= 1; y--) {
		/* For OOP Support - Search in the Class Methods */
		if (y == 2) {
			/* Exit if we are  ( not inside class (no active object) ) or we call method after object name
			 */
			if ((ring_list_getsize(pVM->pObjState) == 0) || (pVM->lCallMethod == 1)) {
				continue;
			}
			pList = ring_list_getlist(pVM->pObjState, ring_list_getsize(pVM->pObjState));
			/* Pass Braces for Class Init() method */
			if ((ring_list_getsize(pVM->pObjState) > 1) && (pVM->nCallClassInit)) {
				if (strcmp(cStr, RING_CSTR_INIT) != 0) {
					pList =
					    ring_list_getlist(pVM->pObjState, ring_list_getsize(pVM->pObjState) - 1);
				}
			}
			pList = (List *)ring_list_getpointer(pList, RING_OBJSTATE_METHODS);
			if (pList == NULL) {
				continue;
			}
		} else {
			/* pFunctionsMap is a list of lists (Functions in the program) */
			pList = pVM->pFunctionsMap;
		}
		/* Use the HashTable */
		ring_vm_custmutexlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_FUNCHASHTABLE]);
		if (ring_list_gethashtable(pList) == NULL) {
			ring_list_genhashtable2_gc(pVM->pRingState, pList);
		}
		pList2 = (List *)ring_hashtable_findpointer(ring_list_gethashtable(pList), cStr);
		ring_vm_custmutexunlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_FUNCHASHTABLE]);
		if (pList2 != NULL) {
			/* Error when the method is private */
			if (ring_list_getint(pList2, RING_FUNCMAP_PRIVATEFLAG) == 1) {
				if ((ring_vm_oop_callmethodinsideclass(pVM) == 0) &&
				    (ring_vm_oop_callingclassmethodfromclassregion(pVM, pList) == 0)) {
					ring_vm_error2(pVM, RING_VM_ERROR_CALLINGPRIVATEMETHOD, cStr);
					return RING_FALSE;
				}
			}
			/* Add FuncCall Structure */
			pFuncCall = ring_vm_funccallnew(pVM);
			if (pFuncCall == NULL)
				return RING_TRUE;
			pFuncCall->nType = RING_FUNCTYPE_SCRIPT;
			pFuncCall->cName = cStr;
			pFuncCall->nPC = ring_list_getint(pList2, RING_FUNCMAP_PC);
			pFuncCall->nSP = pVM->nSP;
			pFuncCall->pFunc = NULL;
			/* File Name */
			pFuncCall->cFileName = pVM->cFileName;
			pVM->cPrevFileName = pVM->cFileName;
			pVM->cFileName = ring_list_getstring(pList2, RING_FUNCMAP_FILENAME);
			pFuncCall->cNewFileName = pVM->cFileName;
			/* Method or Function */
			pFuncCall->lMethod = !((y == 1) && (pVM->lCallMethod != 1));
			/* Line Number */
			pFuncCall->nLineNumber = RING_VM_IR_GETLINENUMBER;
			/* Store List information */
			pFuncCall->nListStart = pVM->nListStart;
			pFuncCall->nNestedLists = ring_list_getsize(pVM->pNestedLists);
			ring_vm_newnestedlists(pVM);
			if ((strcmp(cStr, RING_CSTR_MAIN) != 0) && (pVM->lCallMethod != 1) && (y != 2)) {
				/* We check that we will convert Functions only, not methods */
				if (pVM->lInsideBraceFlag == 0) {
					ring_vm_funccalluseloadfuncp(pVM, pFuncCall, nPerformance);
				} else {
					/*
					**  Inside braces we can write the function/method name directly
					**  This means the same instruction ( funcname() ) could be a function call or a
					*method call
					**  And since the object that we access using braces could be a variable (i.e.
					*function parameter)
					**  The same instruction based on different situations could be changed from
					*method call to function call
					**  Also it can be changed again from function call to method call
					**  Calling methods requires AFTERCALLMETHOD instruction
					**  While calling function requires to avoid this AFTERCALLMETHOD
					**  So we replace it with NO Operation
					**  Byte Code:
					**  ICO_LOAFUNC   <FUNCTION_NAME>
					**  ICO_CALL
					**  ICO_NOOP     OR      ICO_AFTERCALLMETHOD
					*/
					if (RING_VM_IR_OPCODEVALUE(pVM->nPC) == ICO_AFTERCALLMETHOD2) {
						RING_VM_IR_OPCODEVALUE(pVM->nPC) = ICO_NOOP;
					}
				}
			}
			/* Add nLoadAddressScope to pFuncCall */
			pFuncCall->nLoadAddressScope = pVM->nLoadAddressScope;
			pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING;
			return RING_TRUE;
		}
	}
	/* For OOP Support - Check Method not found! */
	if (pVM->lCallMethod == 1) {
		/* Pass The Call Instruction and the AfterCallMethod Instruction */
		pVM->nPC += 2;
		ring_vm_error2(pVM, RING_VM_ERROR_METHODNOTFOUND, cStr);
		return RING_FALSE;
	}
	/* Find Function in C Functions List */
	pCFunc = pVM->pCFunction;
	while (pCFunc != NULL) {
		if (strcmp(pCFunc->cName, cStr) == 0) {
			break;
		}
		pCFunc = pCFunc->pNext;
	}
	/* Check Optional Functions */
	if (pCFunc == NULL) {
		pOptionalFunctions = ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_OPTIONALFUNCTIONS);
		pOptionalFunctions = ring_list_getlist(pOptionalFunctions, RING_VAR_VALUE);
		nPos = ring_list_findstring_gc(pVM->pRingState, pOptionalFunctions, cStr, RING_ZERO);
		if (nPos != RING_ZERO) {
			pCFunc = &vCFunc;
			pCFunc->cName = ring_list_getstring(pOptionalFunctions, nPos);
			pCFunc->pFunc = ring_vm_optionalfunc;
			pCFunc->pNext = NULL;
		}
	}
	if (pCFunc != NULL) {
		/* Add FuncCall Structure */
		pFuncCall = ring_vm_funccallnew(pVM);
		if (pFuncCall == NULL)
			return RING_TRUE;
		pFuncCall->nType = RING_FUNCTYPE_C;
		pFuncCall->cName = cStr;
		pFuncCall->pFunc = pCFunc->pFunc;
		pFuncCall->nSP = pVM->nSP;
		/*
		**  File Name
		**  The old source file name
		*/
		pFuncCall->cFileName = pVM->cFileName;
		/* The new source file name */
		pFuncCall->cNewFileName = pVM->cFileName;
		/* Method or Function */
		pFuncCall->lMethod = 0;
		/* Line Number */
		pFuncCall->nLineNumber = RING_VM_IR_GETLINENUMBER;
		/* Store List information */
		pFuncCall->nListStart = pVM->nListStart;
		pFuncCall->nNestedLists = ring_list_getsize(pVM->pNestedLists);
		ring_vm_newnestedlists(pVM);
		/* Add nLoadAddressScope to pFuncCall */
		pFuncCall->nLoadAddressScope = pVM->nLoadAddressScope;
		pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING;
		ring_vm_funccalluseloadfuncp(pVM, pFuncCall, nPerformance);
		return RING_TRUE;
	}
	/* Avoid Error if it is automatic call to the main function */
	if (pVM->lCallMainFunction == 0) {
		if (strcmp(cStr, RING_CSTR_MAIN) == 0) {
			return RING_FALSE;
		}
	}
	/*
	**  Pass The Call Instruction
	**  We need this when we execute braceerror()
	**  In this case, no parameters and the call instruction is directly after the load function instruction
	**  So it's correct to use pVM->nPC++
	*/
	pVM->nPC++;
	/* Display Error Message */
	ring_vm_error2(pVM, RING_VM_ERROR_FUNCNOTFOUND, cStr);
	return RING_FALSE;
}

void ring_vm_call(VM *pVM) {
	/* Check if we call method using ObjName.MethodName() */
	if (RING_VM_IR_READIVALUE(RING_VM_IR_REG2)) {
		ring_vm_preparecallmethod(pVM);
	}
	ring_vm_call2(pVM);
}

RING_API void ring_vm_call2(VM *pVM) {
	List *pList;
	FuncCall *pFuncCall;
	pFuncCall = RING_VM_LASTFUNCCALL;
	pFuncCall->nStatus = RING_FUNCSTATUS_CALL;
	/* Restore nLoadAddressScope from pFuncCall */
	pVM->nLoadAddressScope = pFuncCall->nLoadAddressScope;
	/* Restore List Status */
	ring_vm_restorenestedlists(pVM, pFuncCall->nListStart, pFuncCall->nNestedLists);
	/* Store the Caller Position */
	pFuncCall->nCallerPC = pVM->nPC;
	/* Call Function */
	if (pFuncCall->nType == RING_FUNCTYPE_SCRIPT) {
		/* Calling Method from brace */
		if (pFuncCall->lMethod) {
			ring_vm_oop_callmethodfrombrace(pVM);
		}
		/* Clear List/Nested Lists State */
		ring_vm_newnestedlists(pVM);
		pVM->nPC = pFuncCall->nPC;
		/* Save State */
		if (pFuncCall->lMethod || pVM->pAssignment || pVM->nListStart || pVM->nBlockCounter ||
		    pVM->nInsideEval || pVM->nInClassRegion || ring_list_getsize(pVM->pObjState) ||
		    ring_list_getsize(pVM->pTraceData))
			pFuncCall->pVMState = ring_vm_savestateformethods(pVM);
		/* Global Scope */
		pFuncCall->nCurrentGlobalScope = pVM->nCurrentGlobalScope;
		/* For Loop */
		pFuncCall->nForStep = ring_list_getsize(pVM->pForStep);
		pFuncCall->nExitMark = ring_list_getsize(pVM->pExitMark);
		pFuncCall->nLoopMark = ring_list_getsize(pVM->pLoopMark);
		pFuncCall->nActiveScopeID = pVM->nActiveScopeID;
		/* Clear nLoadAddressScope */
		pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING;
		/* Avoid accessing object data or methods */
		if ((pFuncCall->lMethod == 0) && (ring_list_getsize(pVM->pObjState) != 0) &&
		    (RING_VM_LASTOBJSTATE != NULL)) {
			pList = ring_list_newlist_gc(pVM->pRingState, pVM->pObjState);
			ring_list_addpointer_gc(pVM->pRingState, pList, NULL);
			ring_list_addpointer_gc(pVM->pRingState, pList, NULL);
			ring_list_addpointer_gc(pVM->pRingState, pList, NULL);
		}
	} else if (pFuncCall->nType == RING_FUNCTYPE_C) {
		/* Trace */
		RING_VM_TRACEEVENT(RING_VM_TRACEEVENT_BEFORECFUNC);
		/* Get Parameters */
		pVM->nCFuncSP = pFuncCall->nSP;
		pVM->nCFuncParaCount = pVM->nSP - pFuncCall->nSP;
		/* Prepare to check function termination by try/catch */
		pVM->lActiveCatch = 0;
		/* Enable C Pointer Type Check */
		pVM->lIgnoreCPointerTypeCheck = 0;
		/* Call Function */
		pFuncCall->pFunc(pVM);
		/* Correct Stack Position */
		if (pVM->nSP > pFuncCall->nSP + pVM->nCFuncParaCount) {
			ring_vm_stackswap(pVM, pVM->nSP, pFuncCall->nSP + 1);
			pVM->nSP = pFuncCall->nSP + 1;
		} else {
			pVM->nSP = pFuncCall->nSP;
			/*
			**  Function Output
			**  IgnoreNULL is Used by len(object) to get output from operator overloading method
			*/
			if (pVM->lIgnoreNULL == 0) {
				RING_VM_STACK_PUSHCVALUE(RING_CSTR_EMPTY);
			} else {
				pVM->lIgnoreNULL = 0;
			}
		}
		/* Trace */
		RING_VM_TRACEEVENT(RING_VM_TRACEEVENT_AFTERCFUNC);
		/* Check for function termination by try/catch */
		if (pVM->lActiveCatch == 1) {
			/*
			**  We don't remove the function from call list because ring_vm_catch() do when restore state
			**  We don't delete the scope because ring_vm_catch() will do when restore state
			**  We don't restore pActiveMem because it's managed correctly by state functions (Save/Restore)
			*for Try/Catch
			**  Avoiding the pActiveMem restore here is important when we have raise() function called after
			*try/catch
			*/
			return;
		}
		/* Return (Delete Function Call List) */
		RING_VM_DELETELASTFUNCCALL;
		/* Restore nFuncSP value */
		if (RING_VM_FUNCCALLSCOUNT > 0) {
			pFuncCall = RING_VM_LASTFUNCCALL;
			pVM->nFuncSP = pFuncCall->nSP;
		} else {
			pVM->nFuncSP = 0;
		}
		/* if eval() is called, start the main loop again */
		if (pVM->lEvalCalledFromRingCode == 1) {
			pVM->lEvalCalledFromRingCode = 0;
			/*
			**  We use Stack POP to remove the empty string that we return after functions
			**  This enable the code generated from eval() to be able to return any value
			**  Using the return command
			*/
			RING_VM_STACK_POP;
			ring_vm_mainloopforeval(pVM);
		}
	}
}

void ring_vm_preparecallmethod(VM *pVM) {
	List *pList;
	/*
	**  Now we make the object state visible by moving it from pBeforeObjState to pObjState
	**  We do this here and not in LoadMethod to avoid accessing the object state when passing parameters
	**  This fix a problem when we pass the self object to avoid passing ObjName that comes before the metho
	*/
	if (ring_list_getsize(pVM->pBeforeObjState) > 0) {
		pList = ring_list_newlist_gc(pVM->pRingState, pVM->pObjState);
		ring_list_swaptwolists(
		    pList, ring_list_getlist(pVM->pBeforeObjState, ring_list_getsize(pVM->pBeforeObjState)));
		ring_list_deleteitem_gc(pVM->pRingState, pVM->pBeforeObjState, ring_list_getsize(pVM->pBeforeObjState));
	}
}

void ring_vm_return(VM *pVM) {
	FuncCall *pFuncCall;
	void *pThisObject, *pCallerThisObject;
	int lThisCheck;
	lThisCheck = RING_TRUE;
	pThisObject =
	    ring_list_getpointer(ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_THIS), RING_VAR_VALUE);
	/* Support for nested "Load" instructions */
	if (pVM->nBlockCounter >= 1) {
		ring_vm_removeblockflag(pVM);
		/* Be sure it's not a function call or method call */
		if (pVM->nPC != 0) {
			/* Set the lIgnoreNULL Flag */
			if (!ring_list_getsize(pVM->pObjState)) {
				pVM->lIgnoreNULL = 0;
			}
			return;
		}
	}
	if (RING_VM_FUNCCALLSCOUNT > 0) {
		pFuncCall = RING_VM_LASTFUNCCALL;
		/* Check if the function is not called */
		if (pFuncCall->nCallerPC == 0) {
			ring_vm_error(pVM, RING_VM_ERROR_RETURNINPARA);
			return;
		}
		pVM->nPC = pFuncCall->nCallerPC;
		/* Restore List Status */
		ring_vm_restorenestedlists(pVM, pFuncCall->nListStart, pFuncCall->nNestedLists);
		/* Restore File Name */
		pVM->cPrevFileName = pVM->cFileName;
		pVM->cFileName = (char *)pFuncCall->cFileName;
		/* Restore Line Number */
		RING_VM_IR_SETLINENUMBER(pFuncCall->nLineNumber);
		/* Restore Global Scope */
		pVM->nCurrentGlobalScope = pFuncCall->nCurrentGlobalScope;
		/* Restore For Loop data */
		ring_vm_backstate(pVM, pVM->pForStep, pFuncCall->nForStep);
		ring_vm_backstate(pVM, pVM->pExitMark, pFuncCall->nExitMark);
		ring_vm_backstate(pVM, pVM->pLoopMark, pFuncCall->nLoopMark);
		pVM->nActiveScopeID = pFuncCall->nActiveScopeID;
		/* Avoid wrong Stack Pointer Value */
		if (pVM->nSP > pVM->nFuncSP + 1) {
			/*
			**  Happens when using Return inside braces like : new object { return }
			**  Swap Two Items in the Stack (Move the Function Output to Correct Position)
			*/
			ring_vm_stackswap(pVM, pVM->nFuncSP + 1, pVM->nSP);
			/* Set the Stack Size to the correct value (Function Output Only) */
			pVM->nSP = pVM->nFuncSP + 1;
		}
		/* Move returned List to the previous scope */
		if (RING_VM_STACK_ISPOINTER) {
			/*
			**  if the variable belong to the object state, don't move to prev. scope
			**  We do this to enable returning a reference
			**  So when we return an object we can access it directly using { }
			*/
			if (ring_vm_isstackpointertoobjstate(pVM) == 0) {
				ring_vm_movetoprevscope(pVM);
			}
		} else {
			lThisCheck = RING_FALSE;
			pVM->nLoadAddressScope = pFuncCall->nLoadAddressScope;
		}
		ring_vm_deletescope(pVM);
		/* Restore State */
		if (pFuncCall->pVMState != NULL) {
			ring_vm_restorestateformethods(pVM, pFuncCall->pVMState);
		} else {
			/*
			**  The function doesn't save the state where ring_list_getsize(pVM->pObjState) == 0
			**  But return command could be used from braces opened in the called function
			**  So, we must clean the pVM->pObjState list in this case
			*/
			if (ring_list_getsize(pVM->pObjState)) {
				ring_list_deleteallitems_gc(pVM->pRingState, pVM->pObjState);
			}
		}
		RING_VM_DELETELASTFUNCCALL;
		/* Restore nFuncSP value */
		if (RING_VM_FUNCCALLSCOUNT > 0) {
			pFuncCall = RING_VM_LASTFUNCCALL;
			pVM->nFuncSP = pFuncCall->nSP;
			pCallerThisObject = ring_list_getpointer(
			    ring_list_getlist(pVM->pDefinedGlobals, RING_GLOBALVARPOS_THIS), RING_VAR_VALUE);
			if (lThisCheck && (!(pFuncCall->lMethod && (pThisObject == pCallerThisObject))) &&
			    (pVM->nRetItemRef == 0) && (pVM->nLoadAddressScope == RING_VARSCOPE_OBJSTATE)) {
				/*
				**  When we return object attribute that contains a list by reference
				**  We keep supporting this from multiple methods calls (From the same class)
				**  But we disable this if we have a call from a function (not method)
				**  Or we have a call from a method in another class
				*/
				pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING;
			}
		} else {
			pVM->nFuncSP = 0;
		}
		/* Trace */
		RING_VM_TRACEEVENT(RING_VM_TRACEEVENT_RETURN);
	} else {
		/* Call Main Function */
		if (pVM->lCallMainFunction == 0) {
			pVM->nPC--;
			pVM->nSP = 0;
			if (ring_vm_loadfunc2(pVM, RING_CSTR_MAIN, RING_FALSE)) {
				ring_vm_call(pVM);
				pVM->lCallMainFunction = 1;
				return;
			}
		}
		/* End the execution Loop (Close the program) */
		ring_vm_bye(pVM);
	}
}

void ring_vm_returnn(VM *pVM) {
	RING_VM_STACK_PUSHN;
	ring_vm_return(pVM);
}

void ring_vm_returnnull(VM *pVM) {
	RING_VM_STACK_PUSHCVALUE(RING_CSTR_EMPTY);
	ring_vm_return(pVM);
}

void ring_vm_newfunc(VM *pVM) {
	unsigned int x, nSP, nMax, lFreeParameter;
	List *aRefList, *pVar, *pRef;
	char *pParameter;
	const char *cParameters;
	char cPara[RING_FUNCPARA_EXPECTEDSIZE];
	FuncCall *pFuncCall;
	/* Set the default global scope */
	pVM->nCurrentGlobalScope = 0;
	/* Create new scope */
	if (!ring_vm_newscope(pVM)) {
		return;
	}
	/* Set the Local Scope ID */
	ring_vm_newscopeid(pVM);
	/* Set the SP then Check Parameters */
	pFuncCall = RING_VM_LASTFUNCCALL;
	pFuncCall->nStatus = RING_FUNCSTATUS_STARTED;
	pFuncCall->nParaCount = RING_VM_IR_READIVALUE(RING_VM_IR_REG2);
	nSP = pFuncCall->nSP;
	pVM->nFuncSP = nSP;
	if (RING_VM_IR_READIVALUE(RING_VM_IR_REG2) > 0) {
		/* Read Parameters (Separated by Space) */
		cParameters = RING_VM_IR_READCVALUE(RING_VM_IR_REG1);
		nMax = strlen(cParameters);
		lFreeParameter = nMax > RING_FUNCPARA_EXPECTEDSIZE - 1;
		if (lFreeParameter) {
			pParameter = (char *)ring_state_malloc(pVM->pRingState, nMax + 1);
		} else {
			pParameter = (char *)cPara;
		}
		/* Set Parameters Value */
		aRefList = NULL;
		for (x = RING_VM_IR_READIVALUE(RING_VM_IR_REG2); x >= 1; x--) {
			if (nSP < pVM->nSP) {
				if (RING_VM_IR_READIVALUE(RING_VM_IR_REG2) == 1) {
					strcpy(pParameter, cParameters);
				} else {
					ring_general_word(cParameters, x, pParameter);
				}
				if (RING_VM_STACK_ISSTRING) {
					ring_vm_addstringarg(pVM, pParameter, RING_VM_STACK_READC,
							     RING_VM_STACK_STRINGSIZE);
					RING_VM_STACK_SETNVALUE(0.0);
				} else if (RING_VM_STACK_ISNUMBER) {
					ring_vm_addnumberarg(pVM, pParameter, RING_VM_STACK_READN);
				} else if (RING_VM_STACK_ISPOINTER) {
					if (!ring_vm_gc_isrefparameter(pVM, pParameter)) {
						ring_vm_addpointerarg(pVM, pParameter, RING_VM_STACK_READP,
								      RING_VM_STACK_OBJTYPE);
						if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
							pVar = (List *)RING_VM_STACK_READP;
							if (ring_list_islist(pVar, RING_VAR_VALUE)) {
								pRef = ring_list_getlist(pVar, RING_VAR_VALUE);
								ring_list_disablecopybyref_gc(pVM->pRingState, pRef);
							}
						}
					} else {
						pVar = (List *)RING_VM_STACK_READP;
						pRef = ring_list_getlist(pVar, RING_VAR_VALUE);
						if (aRefList == NULL) {
							aRefList = ring_list_new_gc(pVM->pRingState, RING_ZERO);
						}
						ring_list_addpointer_gc(pVM->pRingState, aRefList, pRef);
					}
				}
				RING_VM_STACK_POP;
			} else {
				pVM->cFileName = pVM->cPrevFileName;
				RING_VM_DELETELASTFUNCCALL;
				if (lFreeParameter) {
					ring_state_free(pVM->pRingState, pParameter);
				}
				ring_vm_error(pVM, RING_VM_ERROR_LESSPARAMETERSCOUNT);
				return;
			}
		}
		/* Set lNewRef for aRefList members */
		if (aRefList != NULL) {
			for (x = 1; x <= ring_list_getsize(aRefList); x++) {
				pRef = (List *)ring_list_getpointer(aRefList, x);
				ring_list_disablelnewref_gc(pVM->pRingState, pRef);
			}
			ring_list_delete_gc(pVM->pRingState, aRefList);
		}
		/* Clean Memory */
		if (lFreeParameter) {
			ring_state_free(pVM->pRingState, pParameter);
		}
	}
	if (nSP < pVM->nSP) {
		pVM->cFileName = pVM->cPrevFileName;
		RING_VM_DELETELASTFUNCCALL;
		ring_vm_error(pVM, RING_VM_ERROR_EXTRAPARAMETERSCOUNT);
		return;
	}
	/* Support this in the method */
	if (ring_list_getsize(pVM->pClassesMap) || ring_list_getsize(pVM->pPackagesMap)) {
		ring_vm_oop_setthethisvariable(pVM);
	}
	/* Trace */
	RING_VM_TRACEEVENT(RING_VM_TRACEEVENT_NEWFUNC);
}

void ring_vm_blockflag(VM *pVM) { ring_vm_blockflag2(pVM, RING_VM_IR_READI); }

void ring_vm_blockflag2(VM *pVM, int nPC) {
	List *pList;
	pVM->nBlockCounter++;
	pList = ring_list_newlist_gc(pVM->pRingState, pVM->pPCBlockFlag);
	ring_list_addint_gc(pVM->pRingState, pList, nPC);
	/* Save State */
	ring_list_addint_gc(pVM->pRingState, pList, ring_list_getsize(pVM->pExitMark));
	ring_list_addint_gc(pVM->pRingState, pList, ring_list_getsize(pVM->pLoopMark));
	ring_list_addint_gc(pVM->pRingState, pList, ring_list_getsize(pVM->pTry));
}

void ring_vm_removeblockflag(VM *pVM) {
	List *pList;
	pList = ring_list_getlist(pVM->pPCBlockFlag, ring_list_getsize(pVM->pPCBlockFlag));
	pVM->nPC = ring_list_getint(pList, RING_PCBLOCKFLAG_PC);
	pVM->nBlockCounter--;
	/* Restore State */
	ring_vm_backstate(pVM, pVM->pExitMark, ring_list_getint(pList, RING_PCBLOCKFLAG_EXITMARK));
	ring_vm_backstate(pVM, pVM->pLoopMark, ring_list_getint(pList, RING_PCBLOCKFLAG_LOOPMARK));
	ring_vm_backstate(pVM, pVM->pTry, ring_list_getint(pList, RING_PCBLOCKFLAG_TRY));
	ring_list_deleteitem_gc(pVM->pRingState, pVM->pPCBlockFlag, ring_list_getsize(pVM->pPCBlockFlag));
}

void ring_vm_movetoprevscope(VM *pVM) {
	Item *pItem;
	List *pList, *pList2, *pList3;
	/*
	**  When the function return a value of type List or nested List
	**  We copy the list to the previous scope, change the pointer
	**  Get The Source List
	*/
	if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
		pList = (List *)RING_VM_STACK_READP;
		if (ring_list_islist(pList, RING_VAR_VALUE)) {
			pList = ring_list_getlist(pList, RING_VAR_VALUE);
		} else {
			return;
		}
	} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
		pItem = (Item *)RING_VM_STACK_READP;
		pList = ring_item_getlist(pItem);
	} else {
		return;
	}
	/* Create the Temp. Variable */
	ring_vm_createtemplist(pVM);
	pList3 = (List *)RING_VM_STACK_READP;
	RING_VM_STACK_POP;
	ring_list_setint_gc(pVM->pRingState, pList3, RING_VAR_TYPE, RING_VM_LIST);
	ring_list_setlist_gc(pVM->pRingState, pList3, RING_VAR_VALUE);
	pList2 = ring_list_getlist(pList3, RING_VAR_VALUE);
	/* Check Dont Ref flag to avoid reusage in wrong scope */
	if (ring_list_isdontref_gc(pVM->pRingState, pList)) {
		/*
		**  We don't care about this flag here
		**  It's important when we pass (new obj) to ref() function
		**  In Ring functions, We just disable it
		**  Ref() In this case will not lead us here because it uses lMoveToPrevScope
		**  Which is checked in the start of this function
		*/
		ring_list_disabledontref_gc(pVM->pRingState, pList);
	}
	/* Copy the list */
	if (ring_list_isref_gc(pVM->pRingState, pList)) {
		ring_list_setlistbyref_gc(pVM->pRingState, pList3, RING_VAR_VALUE, pList);
	} else {
		if (ring_list_iscopybyref_gc(pVM->pRingState, pList)) {
			ring_list_swaptwolists(pList2, pList);
		} else {
			ring_vm_listcopy(pVM, pList2, pList);
			ring_list_enabledontref_gc(pVM->pRingState, pList2);
			/*
			**  When we return a local object - Swap Container Lists
			**  The idea is to return the same object (Keep the Object ID without change)
			*/
			if (ring_vm_oop_isobject(pVM, pList)) {
				if (ring_vm_oop_objtypefromobjlist(pVM, pList) == RING_OBJTYPE_VARIABLE) {
					/* Take in mind that pList could be stored in a Global Variable - Then
					 * passed/returned from function */
					ring_list_setstring_gc(
					    pVM->pRingState, pList3, RING_VAR_NAME,
					    ring_list_getstring(ring_vm_oop_objvarfromobjlist(pVM, pList),
								RING_VAR_NAME));
					ring_list_swaptwolists(pList3, ring_vm_oop_objvarfromobjlist(pVM, pList));
					ring_vm_oop_updateselfpointer(pVM, pList, RING_OBJTYPE_VARIABLE, pList3);
					RING_VM_STACK_SETPVALUE(pList3);
					RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE;
					return;
				}
			}
		}
		/* Update self object pointer */
		if (ring_vm_oop_isobject(pVM, pList2)) {
			ring_vm_oop_updateselfpointer(pVM, pList2, RING_OBJTYPE_VARIABLE, pList3);
		}
	}
	RING_VM_STACK_SETPVALUE(pList3);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE;
}

void ring_vm_createtemplist(VM *pVM) {
	List *pList, *pList2;
	int nID;
	unsigned int x, lFound;
	/*
	**  Get the Parent List
	**  Create the list in the TempMem related to the function
	**  The advantage of TempMem over Scope is that TempMem out of search domain (Var Name is not important)
	**  Variable name in TemMem is not important, we use it for storage (no search)
	*/
	pList = ring_vm_prevtempmem(pVM);
	/*
	**  Don't allow more than one temp. list per VM instruction
	**  This avoid a memory leak when using code like this:  while true if [] ok end
	*/
	nID = ((pVM->nPC) << RING_BYTEBITS) + pVM->nOPCode;
	lFound = 0;
	for (x = 1; x <= ring_list_getsize(pList); x++) {
		if (ring_list_islist(pList, x)) {
			pList2 = ring_list_getlist(pList, x);
			if (ring_list_getsize(pList2) == RING_TEMPLIST_SIZE) {
				if (ring_list_isint(pList2, RING_TEMPLIST_PC) &&
				    ring_list_islist(pList2, RING_TEMPLIST_LIST)) {
					if (ring_list_getint(pList2, RING_TEMPLIST_PC) == nID) {
						lFound = 1;
						pList = ring_list_getlist(pList2, RING_TEMPLIST_LIST);
						ring_list_deleteallitems_gc(pVM->pRingState, pList);
						break;
					}
				}
			}
		}
	}
	if (lFound == 0) {
		pList2 = ring_list_newlist_gc(pVM->pRingState, pList);
		ring_list_addint_gc(pVM->pRingState, pList2, nID);
		pList = ring_list_newlist_gc(pVM->pRingState, pList2);
	}
	/* Create the variable */
	ring_vm_newtempvar(pVM, RING_TEMP_VAR, pList);
	/* Set the Address scope as local */
	if (pVM->nLoadAddressScope == RING_VARSCOPE_NOTHING) {
		pVM->nLoadAddressScope = RING_VARSCOPE_LOCAL;
	}
}

void ring_vm_anonymous(VM *pVM) {
	char *cStr;
	if (RING_VM_STACK_ISSTRING) {
		cStr = RING_VM_STACK_READC;
		RING_VM_STACK_POP;
		ring_general_lower(cStr);
		ring_vm_loadfunc2(pVM, cStr, RING_FALSE);
	} else {
		ring_vm_error(pVM, RING_VM_ERROR_BADCALLPARA);
	}
}

List *ring_vm_prevtempmem(VM *pVM) {
	List *pTemp;
	FuncCall *pFuncCall;
	int x;
	/* We use the general temp. memory as the default parent */
	pTemp = pVM->pTempMem;
	/* Get Temp Memory of the previous function */
	for (x = RING_VM_FUNCCALLSCOUNT - 1; x >= 1; x--) {
		pFuncCall = RING_VM_GETFUNCCALL(x);
		if (pFuncCall->nCallerPC != 0) {
			/* Get Temp Mem */
			pTemp = pFuncCall->pTempMem;
			break;
		}
	}
	return pTemp;
}

void ring_vm_freetemplistsins(VM *pVM) {
	if (ring_vm_timetofreetemplists(pVM)) {
		ring_vm_freetemplists(pVM);
	}
}

int ring_vm_timetofreetemplists(VM *pVM) {
	/* We must start by executing the instruction for the first time (So we use decrement) */
	if (RING_VM_IR_GETSMALLINTREG == 0) {
		RING_VM_IR_SETSMALLINTREG(RING_VM_TEMPLISTSCOUNTERMAX);
		return RING_TRUE;
	}
	RING_VM_IR_SETSMALLINTREG(RING_VM_IR_GETSMALLINTREG - 1);
	return RING_FALSE;
}

void ring_vm_freetemplists(VM *pVM) {
	List *pTempMem, *pList, *pList2;
	unsigned int x, x2, lFound, nStart, lListsDeleted;
	FuncCall *pFuncCall;
	lListsDeleted = 0;
	/* Clear lists inside pDeleteLater */
	for (x = ring_list_getsize(pVM->pDeleteLater); x >= 1; x--) {
		pList = (List *)ring_list_getpointer(pVM->pDeleteLater, x);
		lFound = 0;
		/* Be sure that the list doesn't exist in opened objects */
		for (x2 = 1; x2 <= ring_list_getsize(pVM->pBraceObjects); x2++) {
			pList2 = ring_list_getlist(pVM->pBraceObjects, x2);
			if (ring_list_getpointer(pList2, RING_BRACEOBJECTS_BRACEOBJECT) == pList) {
				lFound = 1;
				break;
			}
		}
		if (lFound == 0) {
			ring_list_delete_gc(pVM->pRingState, pList);
			ring_list_deleteitem_gc(pVM->pRingState, pVM->pDeleteLater, x);
			lListsDeleted = 1;
		}
	}
	/* Check that we are not in the class region */
	if (pVM->nInClassRegion) {
		/*
		**  Because we may create a new object in the temp. memory
		**  To avoid deleting the object while it's under construction during class region code execution
		**  Example: new mytest   class test    x=1 while x < 10  x++ end
		*/
		return;
	}
	/* Get the current temp. list */
	if (RING_VM_FUNCCALLSCOUNT > 0) {
		pFuncCall = RING_VM_LASTFUNCCALL;
		pTempMem = pFuncCall->pTempMem;
	} else {
		pTempMem = pVM->pTempMem;
	}
	if ((RING_VM_IR_GETINTREG == 0) || (RING_VM_IR_READUIVALUE(RING_VM_IR_REG2) != pVM->nActiveScopeID)) {
		RING_VM_IR_SETINTREG(ring_list_getsize(pTempMem) + 1);
		RING_VM_IR_READUIVALUE(RING_VM_IR_REG2) = pVM->nActiveScopeID;
	}
	nStart = RING_VM_IR_GETINTREG;
	/* Delete Temp. Lists created during the function call */
	if (nStart == 1) {
		/* No Temp. Lists are created before the code execution of the function */
		ring_list_deleteallitems_gc(pVM->pRingState, pTempMem);
	} else {
		/*
		**  We start from nStart to avoid deleting any list passed by reference and exist in the temp. memory
		**  i.e. we have a situation like  f1(f2()) where f2() return a list that are passed to f1()
		**  So when this code is executed from f1() we have to avoid deleting this list
		**  Because if we deleted it, the function code may access it which means ---> Usage after delete
		*/
		for (x = nStart; x <= ring_list_getsize(pTempMem); x++) {
			ring_list_deleteitem_gc(pVM->pRingState, pTempMem, nStart);
		}
		lListsDeleted = 1;
	}
	if (lListsDeleted == 0) {
		/* Delay (Free Temp. Lists) operation in the future */
		RING_VM_IR_SETSMALLINTREG(RING_VM_TEMPLISTSCOUNTERMAX * 100);
	}
}

void ring_vm_retitemref(VM *pVM) {
	FuncCall *pFuncCall;
	/* Check if we don't have item pointer */
	if (!RING_VM_STACK_ISPOINTER) {
		return;
	}
	if (!((RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) || (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_SUBSTRING))) {
		return;
	}
	/* Check if we are not using object state */
	if (!ring_vm_isstackpointertoobjstate(pVM)) {
		return;
	}
	pVM->nRetItemRef = RING_ONE;
	/*
	**  Check if we are in the operator method to increment the counter again
	**  We do this to avoid another PUSHV on the list item
	**  The first one after return expression in the operator method
	**  The second one before return from eval() that is used by operator overloading
	**  This to avoid using & two times like  &  &
	*/
	if (RING_VM_FUNCCALLSCOUNT > 0) {
		pFuncCall = RING_VM_LASTFUNCCALL;
		if ((pFuncCall->lMethod == RING_TRUE) && (strcmp(pFuncCall->cName, RING_CSTR_OPERATOR) == RING_ZERO)) {
			pVM->nRetItemRef = 2;
		}
	}
}

FuncCall *ring_vm_funccallnew(VM *pVM) {
	FuncCall *pFuncCall;
	/* Check Overflow */
	if (pVM->nCurrentFuncCall > RING_VM_STACK_CHECKOVERFLOW) {
		ring_vm_error(pVM, RING_VM_ERROR_STACKOVERFLOW);
		return NULL;
	}
	pVM->nCurrentFuncCall++;
	pFuncCall = &(pVM->aFuncCall[pVM->nCurrentFuncCall]);
	if (pFuncCall->pTempMem == NULL) {
		pFuncCall->pTempMem = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	}
	pFuncCall->nCallerPC = 0;
	pFuncCall->nStatus = RING_FUNCSTATUS_LOAD;
	pFuncCall->pVMState = NULL;
	pFuncCall->nParaCount = 0;
	if ((pVM->nSP > 0) && RING_VM_STACK_ISPOINTER) {
		RING_VM_STACK_ASSIGNMENTFLAG = RING_FALSE;
	}
	return pFuncCall;
}

void ring_vm_funccalldelete(void *pState, void *pMemory) {
	FuncCall *pFuncCall;
	pFuncCall = (FuncCall *)pMemory;
	if (pFuncCall->pTempMem != NULL) {
		if (ring_list_getsize(pFuncCall->pTempMem)) {
			ring_list_deleteallitems_gc(pState, pFuncCall->pTempMem);
		}
	}
	if (pFuncCall->pVMState != NULL) {
		ring_vmstate_delete(pState, pFuncCall->pVMState);
	}
}

void ring_vm_funccalluseloadfuncp(VM *pVM, FuncCall *pFuncCall, int nPerformance) {
	if ((nPerformance == 1) || (pFuncCall->nType == RING_FUNCTYPE_C)) {
		/* Replace Instruction with ICO_LOADFUNCP for better performance */
		RING_VM_IR_OPCODE = ICO_LOADFUNCP;
		/* Leave the first parameter (contains the function name as wanted) */
		RING_VM_IR_SETINTREG(pFuncCall->nPC);
		RING_VM_IR_SETSMALLINTREG(ring_list_getsize(pVM->pFunctionsMap));
		RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG2), (void *)pFuncCall->pFunc);
		RING_VM_IR_SETFLAGREG(pFuncCall->nType);
		RING_VM_IR_SETFLAGREG2(pFuncCall->lMethod);
		RING_VM_IR_SETREG2TYPE(RING_VM_REGTYPE_POINTER);
	}
}

int ring_vm_funccallbeforecall(VM *pVM) {
	FuncCall *pFuncCall;
	if (RING_VM_FUNCCALLSCOUNT) {
		pFuncCall = RING_VM_LASTFUNCCALL;
		return pFuncCall->nCallerPC == RING_ZERO;
	}
	return RING_FALSE;
}

unsigned int ring_vm_funccallparacount(VM *pVM) {
	FuncCall *pFuncCall;
	unsigned int x;
	if (RING_VM_FUNCCALLSCOUNT) {
		for (x = RING_VM_FUNCCALLSCOUNT; x >= 1; x--) {
			pFuncCall = RING_VM_GETFUNCCALL(x);
			if (pFuncCall->nCallerPC != RING_ZERO) {
				return pFuncCall->nParaCount;
			}
		}
	}
	return RING_ZERO;
}

void ring_vm_optionalfunc(void *pPointer) {
	VM *pVM;
	pVM = (VM *)pPointer;
	RING_VM_STACK_PUSHNVALUE(RING_ZERO);
}
