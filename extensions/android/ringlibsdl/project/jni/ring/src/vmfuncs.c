/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

int ring_vm_loadfunc ( VM *pVM )
{
	/*
	**  When pVM->nInsideEval == 1 In this case we are using eval("somefunction()") 
	**  We don't use optimization, it's not required because the code will not be executed again 
	*/
	return ring_vm_loadfunc2(pVM,RING_VM_IR_READC, ! pVM->nInsideEval ) ;
}

int ring_vm_loadfunc2 ( VM *pVM,const char *cStr,int nPerformance )
{
	List *pList,*pList2  ;
	int y  ;
	FuncCall *pFuncCall  ;
	/* Search */
	for ( y = 2 ; y >= 1 ; y-- ) {
		/* For OOP Support - Search in the Class Methods */
		if ( y == 2 ) {
			/* Exit if we are  ( not inside class (no active object) ) or we call method after object name */
			if ( ( ring_list_getsize(pVM->pObjState) == 0 ) || ( pVM->lCallMethod == 1 ) ) {
				continue ;
			}
			pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState));
			/* Pass Braces for Class Init() method */
			if ( (ring_list_getsize(pVM->pObjState) > 1) && (pVM->nCallClassInit) ) {
				if ( strcmp(cStr,"init") != 0 ) {
					pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)-1) ;
				}
			}
			pList = (List *) ring_list_getpointer(pList,RING_OBJSTATE_METHODS);
			if ( pList == NULL ) {
				continue ;
			}
		}
		else {
			/* pFunctionsMap is a list of lists (Functions in the program) */
			pList = pVM->pFunctionsMap ;
		}
		if ( ring_list_gethashtable(pList) == NULL ) {
			ring_list_genhashtable2(pList);
		}
		pList2 = (List *) ring_hashtable_findpointer(ring_list_gethashtable(pList),cStr);
		if ( pList2 != NULL ) {
			/* Error when the method is private */
			if ( ring_list_getint(pList2,RING_FUNCMAP_PRIVATEFLAG) == 1 ) {
				if ( (ring_vm_oop_callmethodinsideclass(pVM) == 0) && (ring_vm_oop_callingclassmethodfromclassregion(pVM,pList) == 0) ) {
					ring_vm_error2(pVM,RING_VM_ERROR_CALLINGPRIVATEMETHOD,cStr);
					return 0 ;
				}
			}
			/* Add FuncCall Structure */
			pFuncCall = ring_vmfunccall_new(pVM);
			pFuncCall->nType = RING_FUNCTYPE_SCRIPT ;
			pFuncCall->cName = cStr ;
			pFuncCall->nPC = ring_list_getint(pList2,RING_FUNCMAP_PC) ;
			pFuncCall->nSP = pVM->nSP ;
			pFuncCall->pFunc = NULL ;
			/* Create Temp Memory */
			pFuncCall->pTempMem = ring_list_new_gc(pVM->pRingState,RING_ZERO) ;
			/* File Name */
			pFuncCall->cFileName = pVM->cFileName ;
			pVM->cPrevFileName = pVM->cFileName ;
			pVM->cFileName = ring_list_getstring(pList2,RING_FUNCMAP_FILENAME) ;
			pFuncCall->cNewFileName = pVM->cFileName ;
			/* Method or Function */
			pFuncCall->lMethod = ! ( (y == 1) && (pVM->lCallMethod != 1) ) ;
			/* Line Number */
			pFuncCall->nLineNumber = RING_VM_IR_GETLINENUMBER ;
			/* Store List information */
			pFuncCall->nListStart = pVM->nListStart ;
			pFuncCall->pNestedLists = pVM->pNestedLists ;
			pVM->nListStart = 0 ;
			pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,RING_ZERO);
			if ( (strcmp(cStr,"main") != 0 ) && (pVM->lCallMethod != 1) && (y != 2) ) {
				/* We check that we will convert Functions only, not methods */
				if ( pVM->lInsideBraceFlag == 0 ) {
					ring_vmfunccall_useloadfuncp(pVM,pFuncCall,nPerformance);
				}
				else {
					/*
					**  Inside braces we can write the function/method name directly 
					**  This means the same instruction ( funcname() ) could be a function call or a method call 
					**  And since the object that we access using braces could be a variable (i.e. function parameter) 
					**  The same instruction based on different situations could be changed from method call to function call 
					**  Also it can be changed again from function call to method call 
					**  Calling methods requires AFTERCALLMETHOD instruction 
					**  While calling function requires to avoid this AFTERCALLMETHOD 
					**  So we replace it with NO Operation 
					**  Byte Code: 
					**  ICO_LOAFUNC   <FUNCTION_NAME> 
					**  ICO_CALL 
					**  ICO_NOOP     OR      ICO_AFTERCALLMETHOD 
					*/
					if ( RING_VM_IR_OPCODEVALUE(pVM->nPC)   == ICO_AFTERCALLMETHOD2 ) {
						RING_VM_IR_OPCODEVALUE(pVM->nPC) = ICO_NOOP ;
					}
				}
			}
			/* Add nLoadAddressScope to pFuncCall */
			pFuncCall->nLoadAddressScope = pVM->nLoadAddressScope ;
			pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
			/* Increment nFuncExecute */
			pVM->nFuncExecute++ ;
			return 1 ;
		}
	}
	/* For OOP Support - Check Method not found! */
	if ( pVM->lCallMethod == 1 ) {
		/* Pass The Call Instruction and the AfterCallMethod Instruction */
		pVM->nPC += 2 ;
		ring_vm_error2(pVM,RING_VM_ERROR_METHODNOTFOUND,cStr);
		return 0 ;
	}
	/* Find Function in C Functions List */
	pList = (List *) ring_hashtable_findpointer(ring_list_gethashtable(pVM->pCFunctionsList),cStr);
	if ( pList != NULL ) {
		/* Add FuncCall Structure */
		pFuncCall = ring_vmfunccall_new(pVM);
		pFuncCall->nType = RING_FUNCTYPE_C ;
		pFuncCall->cName = cStr ;
		pFuncCall->pFunc = ring_list_getfuncpointer(pList,RING_FUNCMAP_PC) ;
		pFuncCall->nSP = pVM->nSP ;
		/* Create Temp Memory */
		pFuncCall->pTempMem = ring_list_new_gc(pVM->pRingState,RING_ZERO) ;
		/*
		**  File Name 
		**  The old source file name 
		*/
		pFuncCall->cFileName = pVM->cFileName ;
		/* The new source file name */
		pFuncCall->cNewFileName = pVM->cFileName ;
		/* Method or Function */
		pFuncCall->lMethod = 0 ;
		/* Line Number */
		pFuncCall->nLineNumber = RING_VM_IR_GETLINENUMBER ;
		/* Store List information */
		pFuncCall->nListStart = pVM->nListStart ;
		pFuncCall->pNestedLists = pVM->pNestedLists ;
		pVM->nListStart = 0 ;
		pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,RING_ZERO);
		/* Add nLoadAddressScope to pFuncCall */
		pFuncCall->nLoadAddressScope = pVM->nLoadAddressScope ;
		pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
		ring_vmfunccall_useloadfuncp(pVM,pFuncCall,nPerformance);
		/* Increment nFuncExecute */
		pVM->nFuncExecute++ ;
		return 1 ;
	}
	/* Avoid Error if it is automatic call to the main function */
	if ( pVM->lCallMainFunction == 0 ) {
		if ( strcmp(cStr,"main") == 0 ) {
			return 0 ;
		}
	}
	/*
	**  Pass The Call Instruction 
	**  We need this when we execute braceerror() 
	**  In this case, no parameters and the call instruction is directly after the load function instruction 
	**  So it's correct to use pVM->nPC++ 
	*/
	pVM->nPC++ ;
	/* Display Error Message */
	ring_vm_error2(pVM,RING_VM_ERROR_FUNCNOTFOUND,cStr);
	return 0 ;
}

void ring_vm_call ( VM *pVM )
{
	List *pList  ;
	/* Check if we call method using ObjName.MethodName() */
	if ( RING_VM_IR_PARACOUNT == 3 ) {
		if ( RING_VM_IR_READIVALUE(RING_VM_IR_REG2) ) {
			/*
			**  Now we make the object state visible by moving it from pBeforeObjState to pObjState 
			**  We do this here and not in LoadMethod to avoid accessing the object state when passing parameters 
			**  This fix a problem when we pass the self object to avoid passing ObjName that comes before the method 
			*/
			if ( ring_list_getsize(pVM->pBeforeObjState) > 0 ) {
				pList = ring_list_newlist_gc(pVM->pRingState,pVM->pObjState);
				ring_list_swaptwolists(pList,ring_list_getlist(pVM->pBeforeObjState,ring_list_getsize(pVM->pBeforeObjState)));
				ring_list_deleteitem_gc(pVM->pRingState,pVM->pBeforeObjState,ring_list_getsize(pVM->pBeforeObjState));
			}
		}
	}
	ring_vm_call2(pVM);
}

void ring_vm_call2 ( VM *pVM )
{
	List *pList, *pActiveMem  ;
	int x,nSP,nMax1  ;
	FuncCall *pFuncCall  ;
	/* Decrement FuncExecute Counter */
	if ( pVM->nFuncExecute > 0 ) {
		pVM->nFuncExecute-- ;
	}
	pFuncCall = RING_VM_LASTFUNCCALL ;
	pFuncCall->nStatus = RING_FUNCSTATUS_CALL ;
	/* Restore nLoadAddressScope from pFuncCall */
	pVM->nLoadAddressScope = pFuncCall->nLoadAddressScope ;
	/* Restore List Status */
	pVM->nListStart = pFuncCall->nListStart ;
	if ( pVM->pNestedLists != pFuncCall->pNestedLists ) {
		pVM->pNestedLists = ring_list_delete_gc(pVM->pRingState,pVM->pNestedLists);
		pVM->pNestedLists = (List *) pFuncCall->pNestedLists ;
	}
	/* Calling Method from brace */
	if ( (pFuncCall->nType == RING_FUNCTYPE_SCRIPT) && (pFuncCall->lMethod == 1) ) {
		/* The first test to be sure it's not a C Function Call */
		ring_vm_oop_callmethodfrombrace(pVM);
	}
	/* Store the Caller Position */
	pFuncCall->nCallerPC = pVM->nPC ;
	/* Store FuncExe Counter Value */
	pFuncCall->nFuncExec = pVM->nFuncExecute ;
	pVM->nFuncExecute = 0 ;
	/* Call Function */
	if ( pFuncCall->nType == RING_FUNCTYPE_SCRIPT ) {
		/* Clear List/Nested Lists State */
		pVM->nListStart = 0 ;
		pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,RING_ZERO);
		pVM->nPC = pFuncCall->nPC ;
		/* Save State */
		pFuncCall->pVMState = ring_vm_savestateforfunctions(pVM);
		/* Clear nLoadAddressScope */
		pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
		/* Avoid accessing object data or methods */
		if ( pFuncCall->lMethod == 0 ) {
			/* Check if we need this */
			if ( ring_list_getsize(pVM->pObjState) == 0 ) {
				return ;
			}
			if ( RING_VM_LASTOBJSTATE == NULL ) {
				return ;
			}
			pList = ring_list_newlist_gc(pVM->pRingState,pVM->pObjState);
			ring_list_addpointer_gc(pVM->pRingState,pList,NULL);
			ring_list_addpointer_gc(pVM->pRingState,pList,NULL);
			ring_list_addpointer_gc(pVM->pRingState,pList,NULL);
		}
	}
	else if ( pFuncCall->nType == RING_FUNCTYPE_C ) {
		/* Trace */
		ring_vm_traceevent(pVM,RING_VM_TRACEEVENT_BEFORECFUNC);
		/*
		**  Save Active Memory 
		**  We save Active Memory to restore it , we don't depend on scopes list of lists 
		**  because we may call function from class init 
		**  and class init don't create new scope for executing init 
		*/
		pActiveMem = pVM->pActiveMem ;
		/* Create New Scope */
		ring_vm_newscope(pVM);
		/* Get Parameters */
		nSP = pFuncCall->nSP ;
		pVM->nCFuncParaCount = pVM->nSP - nSP ;
		/* Use Order (First In - First Out) As Queue , the first parameter comes first */
		if ( nSP < pVM->nSP ) {
			nMax1 = pVM->nSP ;
			for ( x = nSP+1 ; x <= nMax1 ; x++ ) {
				pVM->nSP = x ;
				if ( RING_VM_STACK_ISSTRING ) {
					ring_list_addstring2_gc(pVM->pRingState,pVM->pActiveMem,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
					RING_VM_STACK_SETNVALUE(0.0);
				}
				else if ( RING_VM_STACK_ISNUMBER ) {
					ring_list_adddouble_gc(pVM->pRingState,pVM->pActiveMem,RING_VM_STACK_READN);
				}
				else if ( RING_VM_STACK_ISPOINTER ) {
					ring_list_addpointerandtype_gc(pVM->pRingState,pVM->pActiveMem,RING_VM_STACK_READP,RING_VM_STACK_OBJTYPE);
				}
			}
			pVM->nSP = nSP ;
		}
		/* Prepare to check function termination by try/catch */
		pVM->nActiveCatch = 0 ;
		/* Enable C Pointer Type Check */
		pVM->lIgnoreCPointerTypeCheck = 0 ;
		/* Call Function */
		pFuncCall->pFunc(pVM) ;
		/* Trace */
		ring_vm_traceevent(pVM,RING_VM_TRACEEVENT_AFTERCFUNC);
		/* Restore nFuncEx state */
		pVM->nFuncExecute = pFuncCall->nFuncExec ;
		/* Check for function termination by try/catch */
		if ( pVM->nActiveCatch == 1 ) {
			/*
			**  We don't remove the function from call list because ring_vm_catch() do when restore state 
			**  We don't delete the scope because ring_vm_catch() will do when restore state 
			**  We don't restore pActiveMem because it's managed correctly by state functions (Save/Restore) for Try/Catch 
			**  Avoiding the pActiveMem restore here is important when we have raise() function called after try/catch 
			*/
			return ;
		}
		/* Function Output */
		if ( nSP == pVM->nSP ) {
			/* IgnoreNULL is Used by len(object) to get output from operator overloading method */
			if ( pVM->lIgnoreNULL  == 0 ) {
				RING_VM_STACK_PUSHCVALUE("");
			}
			else {
				pVM->lIgnoreNULL = 0 ;
			}
		}
		/*
		**  We move the list to the previous scope 
		**  Because we may have nested functions calls like refcount( list(nSize) ) 
		**  Move returned List to the previous scope 
		*/
		if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_movetoprevscope(pVM,RING_FUNCTYPE_C);
		}
		/* Return (Delete Scope, Restore ActiveMem) */
		ring_list_deleteitem_gc(pVM->pRingState,pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
		ring_vm_deletescope(pVM);
		/* Restore ActiveMem */
		pVM->pActiveMem = pActiveMem ;
		/* Restore nFuncSP value */
		if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
			pFuncCall = RING_VM_LASTFUNCCALL ;
			pVM->nFuncSP = pFuncCall->nSP ;
		}
		else {
			pVM->nFuncSP = 0 ;
		}
		/* if eval() is called, start the main loop again */
		if ( pVM->lEvalCalledFromRingCode == 1 ) {
			pVM->lEvalCalledFromRingCode = 0 ;
			/*
			**  We use Stack POP to remove the empty string that we return after functions 
			**  This enable the code generated from eval() to be able to return any value 
			**  Using the return command 
			*/
			RING_VM_STACK_POP ;
			ring_vm_mainloopforeval(pVM);
		}
	}
}

void ring_vm_return ( VM *pVM )
{
	List *pList  ;
	Item vTempItem  ;
	FuncCall *pFuncCall  ;
	/* Support for nested "Load" instructions */
	if ( pVM->nBlockCounter >= 1 ) {
		ring_vm_removeblockflag(pVM);
		/* Be sure it's not a function call or method call */
		if ( pVM->nPC != 0 ) {
			return ;
		}
	}
	if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
		pFuncCall = RING_VM_LASTFUNCCALL ;
		pVM->nPC = pFuncCall->nCallerPC ;
		pVM->nFuncExecute = pFuncCall->nFuncExec ;
		/* Restore List Status */
		pVM->nListStart = pFuncCall->nListStart ;
		if ( pVM->pNestedLists != pFuncCall->pNestedLists ) {
			pVM->pNestedLists = ring_list_delete_gc(pVM->pRingState,pVM->pNestedLists);
			pVM->pNestedLists = pFuncCall->pNestedLists ;
		}
		/* Restore File Name */
		pVM->cPrevFileName = pVM->cFileName ;
		pVM->cFileName = (char *) pFuncCall->cFileName ;
		/* Avoid wrong Stack Pointer Value */
		if ( pVM->nSP > pVM->nFuncSP+1 ) {
			/*
			**  Happens when using Return inside braces like : new object { return } 
			**  Swap Two Items in the Stack (Move the Function Output to Correct Position) 
			*/
			vTempItem = pVM->aStack[pVM->nFuncSP+1] ;
			pVM->aStack[pVM->nFuncSP+1] = pVM->aStack[pVM->nSP] ;
			pVM->aStack[pVM->nSP] = vTempItem ;
			/* Set the Stack Size to the correct value (Function Output Only) */
			pVM->nSP = pVM->nFuncSP+1 ;
		}
		/* Move returned List to the previous scope */
		if ( RING_VM_STACK_ISPOINTER ) {
			/*
			**  if the variable belong to the object state, don't move to prev. scope 
			**  We do this to enable returning a reference 
			**  So when we return an object we can access it directly using { } 
			*/
			if ( ring_vm_isstackpointertoobjstate(pVM) == 0 ) {
				ring_vm_movetoprevscope(pVM,RING_FUNCTYPE_SCRIPT);
			}
		}
		ring_vm_deletescope(pVM);
		/* Restore State */
		ring_vm_restorestateforfunctions(pVM,pFuncCall->pVMState);
		ring_list_deleteitem_gc(pVM->pRingState,pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
		/* Restore nFuncSP value */
		if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
			pFuncCall = RING_VM_LASTFUNCCALL ;
			pVM->nFuncSP = pFuncCall->nSP ;
		}
		else {
			pVM->nFuncSP = 0 ;
		}
		/* Trace */
		ring_vm_traceevent(pVM,RING_VM_TRACEEVENT_RETURN);
	}
	else {
		/* Call Main Function */
		if ( pVM->lCallMainFunction == 0 ) {
			pVM->nPC-- ;
			pVM->nSP = 0 ;
			if ( ring_vm_loadfunc2(pVM,"main",RING_FALSE) ) {
				ring_vm_call(pVM);
				pVM->lCallMainFunction = 1 ;
				return ;
			}
		}
		/* End the execution Loop (Close the program) */
		ring_vm_bye(pVM);
	}
}

void ring_vm_returnnull ( VM *pVM )
{
	RING_VM_STACK_PUSHCVALUE("");
	ring_vm_return(pVM);
}

void ring_vm_newfunc ( VM *pVM )
{
	int x,nSP,nMax,lFreeParameter  ;
	List *pList,*aRefList,*pVar,*pRef  ;
	char *pParameter  ;
	char *cParameters  ;
	char cPara[RING_FUNCPARA_EXPECTEDSIZE]  ;
	FuncCall *pFuncCall  ;
	ring_vm_newscope(pVM);
	/* Set the Local Scope ID */
	pVM->nActiveScopeID = ++ pVM->nScopeID ;
	/* Set the SP then Check Parameters */
	pFuncCall = RING_VM_LASTFUNCCALL ;
	pFuncCall->nStatus = RING_FUNCSTATUS_STARTED ;
	nSP = pFuncCall->nSP ;
	pVM->nFuncSP = nSP ;
	if ( RING_VM_IR_PARACOUNT > 2 ) {
		/* Read Parameters (Separated by Space) */
		cParameters = RING_VM_IR_READCVALUE(RING_VM_IR_REG2) ;
		nMax = RING_VM_IR_READCVALUESIZE(RING_VM_IR_REG2) ;
		lFreeParameter = nMax > RING_FUNCPARA_EXPECTEDSIZE - 1 ;
		if ( lFreeParameter ) {
			pParameter = (char *) ring_state_malloc(pVM->pRingState,nMax+1);
		}
		else {
			pParameter = (char *) cPara ;
		}
		/* Set Parameters Value */
		aRefList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
		for ( x = RING_VM_IR_READIVALUE(RING_VM_IR_REG3) ; x >= 1 ; x-- ) {
			if ( nSP < pVM->nSP ) {
				ring_string_word(cParameters,x,pParameter);
				if ( RING_VM_STACK_ISSTRING ) {
					ring_vm_addstringarg(pVM,pParameter,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
					RING_VM_STACK_SETNVALUE(0.0);
				}
				else if ( RING_VM_STACK_ISNUMBER ) {
					ring_vm_addnumberarg(pVM,pParameter,RING_VM_STACK_READN);
				}
				else if ( RING_VM_STACK_ISPOINTER ) {
					if ( ! ring_list_isrefparameter(pVM,pParameter) ) {
						ring_vm_addpointerarg(pVM,pParameter,RING_VM_STACK_READP,RING_VM_STACK_OBJTYPE);
						if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
							pVar = (List *) RING_VM_STACK_READP ;
							if ( ring_list_islist(pVar,RING_VAR_VALUE) ) {
								pRef = ring_list_getlist(pVar,RING_VAR_VALUE);
								ring_list_disablecopybyref(pRef);
							}
						}
					}
					else {
						pVar = (List *) RING_VM_STACK_READP ;
						pRef = ring_list_getlist(pVar,RING_VAR_VALUE);
						ring_list_addpointer_gc(pVM->pRingState,aRefList,pRef);
					}
				}
				RING_VM_STACK_POP ;
			}
			else {
				pVM->cFileName = pVM->cPrevFileName ;
				ring_list_deleteitem_gc(pVM->pRingState,pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
				if ( lFreeParameter ) {
					ring_state_free(pVM->pRingState,pParameter);
				}
				ring_vm_error(pVM,RING_VM_ERROR_LESSPARAMETERSCOUNT);
				return ;
			}
		}
		/* Set lNewRef for aRefList members */
		for ( x = 1 ; x <= ring_list_getsize(aRefList) ; x++ ) {
			pRef = (List *) ring_list_getpointer(aRefList,x) ;
			ring_list_disablelnewref(pRef);
		}
		/* Clean Memory */
		ring_list_delete_gc(pVM->pRingState,aRefList);
		if ( lFreeParameter ) {
			ring_state_free(pVM->pRingState,pParameter);
		}
	}
	if ( nSP < pVM->nSP ) {
		pVM->cFileName = pVM->cPrevFileName ;
		ring_list_deleteitem_gc(pVM->pRingState,pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
		ring_vm_error(pVM,RING_VM_ERROR_EXTRAPARAMETERSCOUNT);
		return ;
	}
	/* Set the Temp. Memory size at start */
	pFuncCall->nTempMemSizeAtStart = ring_list_getsize(pFuncCall->pTempMem) ;
	/* Support this in the method */
	ring_vm_oop_setthethisvariable(pVM);
	/* Trace */
	ring_vm_traceevent(pVM,RING_VM_TRACEEVENT_NEWFUNC);
}

void ring_vm_blockflag ( VM *pVM )
{
	ring_vm_blockflag2(pVM,RING_VM_IR_READI);
}

void ring_vm_blockflag2 ( VM *pVM,int nPC )
{
	List *pList  ;
	pVM->nBlockCounter++ ;
	pList = ring_list_newlist_gc(pVM->pRingState,pVM->pPCBlockFlag);
	ring_list_addint_gc(pVM->pRingState,pList,nPC);
	/* Save State */
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pExitMark));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pLoopMark));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pTry));
}

void ring_vm_removeblockflag ( VM *pVM )
{
	List *pList  ;
	pList = ring_list_getlist(pVM->pPCBlockFlag,ring_list_getsize(pVM->pPCBlockFlag));
	pVM->nPC = ring_list_getint(pList,RING_PCBLOCKFLAG_PC);
	pVM->nBlockCounter-- ;
	/* Restore State */
	ring_vm_backstate(pVM,pVM->pExitMark,ring_list_getint(pList,RING_PCBLOCKFLAG_EXITMARK));
	ring_vm_backstate(pVM,pVM->pLoopMark,ring_list_getint(pList,RING_PCBLOCKFLAG_LOOPMARK));
	ring_vm_backstate(pVM,pVM->pTry,ring_list_getint(pList,RING_PCBLOCKFLAG_TRY));
	ring_list_deleteitem_gc(pVM->pRingState,pVM->pPCBlockFlag,ring_list_getsize(pVM->pPCBlockFlag));
}

void ring_vm_movetoprevscope ( VM *pVM,int nFuncType )
{
	Item *pItem  ;
	List *pList,*pList2,*pList3  ;
	/*
	**  When the function return a value of type List or nested List 
	**  We copy the list to the previous scope, change the pointer 
	*/
	if ( ring_list_getsize(pVM->pMem) < 2 ) {
		return ;
	}
	/* Check Flag */
	if ( pVM->lDontMoveToPrevScope ) {
		pVM->lDontMoveToPrevScope = 0 ;
		return ;
	}
	/* Get The Source List */
	if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
		pList = (List *) RING_VM_STACK_READP ;
		if ( ring_list_islist(pList,RING_VAR_VALUE) ) {
			pList = ring_list_getlist(pList,RING_VAR_VALUE);
		}
		else {
			return ;
		}
	}
	else if ( RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM ) {
		pItem = (Item *) RING_VM_STACK_READP ;
		pList = ring_item_getlist(pItem);
	}
	else {
		return ;
	}
	/* Create the Temp. Variable */
	ring_vm_createtemplist(pVM);
	pList3 = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	ring_list_setint_gc(pVM->pRingState,pList3,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist_gc(pVM->pRingState,pList3,RING_VAR_VALUE);
	pList2 = ring_list_getlist(pList3,RING_VAR_VALUE);
	/* Check Dont Ref flag to avoid reusage in wrong scope */
	if ( ring_list_isdontref(pList) ) {
		/*
		**  We don't care about this flag here 
		**  It's important when we pass (new obj) to ref() function 
		**  In Ring functions, We just disable it 
		**  Ref() In this case will not lead us here because it uses lMoveToPrevScope 
		**  Which is checked in the start of this function 
		*/
		ring_list_disabledontref(pList);
	}
	/* Copy the list */
	if ( ring_list_isref(pList) ) {
		ring_list_setlistbyref_gc(pVM->pRingState,pList3,RING_VAR_VALUE,pList);
	}
	else {
		if ( ring_list_iscopybyref(pList) ) {
			ring_list_swaptwolists(pList2,pList);
		}
		else {
			ring_vm_list_copy(pVM,pList2,pList);
			ring_list_enabledontref(pList2);
			/* When we return a local object - Swap Container Lists */
			if ( ring_vm_oop_isobject(pList) ) {
				if ( ring_vm_oop_objtypefromobjlist(pList) == RING_OBJTYPE_VARIABLE ) {
					ring_list_swaptwolists(pList3,ring_vm_oop_objvarfromobjlist(pList));
					ring_vm_oop_updateselfpointer(pVM,pList,RING_OBJTYPE_VARIABLE,pList3);
					RING_VM_STACK_SETPVALUE(pList3);
					RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
					return ;
				}
			}
		}
		/* Update self object pointer */
		if ( ring_vm_oop_isobject(pList2) ) {
			ring_vm_oop_updateselfpointer(pVM,pList2,RING_OBJTYPE_VARIABLE,pList3);
		}
	}
	RING_VM_STACK_SETPVALUE(pList3);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
}

void ring_vm_createtemplist ( VM *pVM )
{
	List *pList, *pList2  ;
	int x,lFound  ;
	/*
	**  Get the Parent List 
	**  Create the list in the TempMem related to the function 
	**  The advantage of TempMem over Scope is that TempMem out of search domain (Var Name is not important) 
	**  Variable name in TemMem is not important, we use it for storage (no search) 
	*/
	pList = ring_vm_prevtempmem(pVM) ;
	/*
	**  Don't allow more than one temp. list per VM instruction 
	**  This avoid a memory leak when using code like this:  while true if [] ok end 
	*/
	lFound = 0 ;
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		if ( ring_list_islist(pList,x) ) {
			pList2 = ring_list_getlist(pList,x) ;
			if ( ring_list_getsize(pList2) == RING_TEMPLIST_SIZE ) {
				if ( ring_list_isint(pList2,RING_TEMPLIST_PC) && ring_list_islist(pList2,RING_TEMPLIST_LIST) ) {
					if ( ring_list_getint(pList2,RING_TEMPLIST_PC) == pVM->nPC ) {
						lFound = 1 ;
						pList = ring_list_getlist(pList2,RING_TEMPLIST_LIST) ;
						ring_list_deleteallitems_gc(pVM->pRingState,pList);
					}
				}
			}
		}
	}
	if ( lFound == 0 ) {
		pList2 = ring_list_newlist_gc(pVM->pRingState,pList);
		ring_list_addint_gc(pVM->pRingState,pList2,pVM->nPC);
		pList = ring_list_newlist_gc(pVM->pRingState,pList2);
	}
	/* Create the variable */
	ring_vm_newtempvar(pVM,RING_TEMP_VAR,pList);
	/* Set the Address scope as local */
	if ( pVM->nLoadAddressScope == RING_VARSCOPE_NOTHING ) {
		pVM->nLoadAddressScope = RING_VARSCOPE_LOCAL ;
	}
}

void ring_vm_anonymous ( VM *pVM )
{
	char *cStr  ;
	if ( RING_VM_STACK_ISSTRING ) {
		cStr = RING_VM_STACK_READC ;
		RING_VM_STACK_POP ;
		ring_string_lower(cStr);
		ring_vm_loadfunc2(pVM,cStr,RING_FALSE);
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_BADCALLPARA);
	}
}

int ring_vm_isstackpointertoobjstate ( VM *pVM )
{
	return (pVM->nLoadAddressScope == RING_VARSCOPE_OBJSTATE) || (pVM->nLoadAddressScope ==RING_VARSCOPE_GLOBAL) ;
}

List * ring_vm_prevtempmem ( VM *pVM )
{
	List *pList, *pTemp  ;
	FuncCall *pFuncCall  ;
	int x  ;
	/* We use the general temp. memory as the default parent */
	pTemp = pVM->pTempMem ;
	/* Get Temp Memory of the previous function */
	for ( x = ring_list_getsize(pVM->pFuncCallList)-1 ; x >= 1 ; x-- ) {
		pFuncCall = (FuncCall *) ring_list_getpointer(pVM->pFuncCallList,x) ;
		if ( pFuncCall->nCallerPC != 0 ) {
			/* Get Temp Mem */
			pTemp = pFuncCall->pTempMem ;
			break ;
		}
	}
	return pTemp ;
}

void ring_vm_freetemplistsins ( VM *pVM )
{
	if ( ring_vm_timetofreetemplists(pVM) ) {
		ring_vm_freetemplists(pVM, & RING_VM_IR_READI, & RING_VM_IR_READIVALUE(RING_VM_IR_REG2));
	}
}

void ring_vm_freetemplists ( VM *pVM, int *nTempCount, int *nScopeID )
{
	List *pTempMem, *pList, *pList2  ;
	int x,x2,lFound,nStart,lMutex  ;
	FuncCall *pFuncCall  ;
	nStart = 1 ;
	lMutex = 0 ;
	/* Clear lists inside pDeleteLater */
	for ( x = ring_list_getsize(pVM->pDeleteLater) ; x >= 1 ; x-- ) {
		pList = (List *) ring_list_getpointer(pVM->pDeleteLater,x) ;
		lFound = 0 ;
		/* Be sure that the list doesn't exist in opened objects */
		for ( x2 = 1 ; x2 <= ring_list_getsize(pVM->pBraceObjects) ; x2++ ) {
			pList2 = ring_list_getlist(pVM->pBraceObjects,x2);
			if ( ring_list_getpointer(pList2,RING_BRACEOBJECTS_BRACEOBJECT) == pList ) {
				lFound = 1 ;
				break ;
			}
		}
		if ( lFound == 0 ) {
			ring_list_delete_gc(pVM->pRingState,pList);
			ring_list_deleteitem_gc(pVM->pRingState,pVM->pDeleteLater,x);
		}
	}
	/* Check that we are not in the class region */
	if ( pVM->nInClassRegion ) {
		/*
		**  Because we may create a new object in the temp. memory 
		**  To avoid deleting the object while it's under construction during class region code execution 
		**  Example: new mytest   class test    x=1 while x < 10  x++ end 
		*/
		return ;
	}
	/* Get the current temp. list */
	if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
		pFuncCall = RING_VM_LASTFUNCCALL ;
		pTempMem = pFuncCall->pTempMem ;
	}
	else {
		lMutex = 1 ;
		pTempMem = pVM->pTempMem ;
	}
	if ( ( *nTempCount == 0) || (*nScopeID !=pVM->nActiveScopeID) ) {
		*nTempCount = ring_list_getsize(pTempMem) + 1 ;
		*nScopeID = pVM->nActiveScopeID ;
	}
	nStart = *nTempCount ;
	/* Lock (Important for Threads Support) */
	if ( lMutex ) {
		ring_vm_mutexlock(pVM);
	}
	/* Delete Temp. Lists created during the function call */
	if ( nStart == 1 ) {
		/* No Temp. Lists are created before the code execution of the function */
		ring_list_deleteallitems_gc(pVM->pRingState,pTempMem);
	}
	else {
		/*
		**  We start from nStart to avoid deleting any list passed by reference and exist in the temp. memory 
		**  i.e. we have a situation like  f1(f2()) where f2() return a list that are passed to f1() 
		**  So when this code is executed from f1() we have to avoid deleting this list 
		**  Because if we deleted it, the function code may access it which means ---> Usage after delete 
		*/
		for ( x = nStart ; x <= ring_list_getsize(pTempMem) ; x++ ) {
			ring_list_deleteitem_gc(pVM->pRingState,pTempMem,nStart);
		}
	}
	/* Unlock (If we are using Threads) */
	if ( lMutex ) {
		ring_vm_mutexunlock(pVM);
	}
}

void ring_vm_endfuncexec ( VM *pVM )
{
	if ( pVM->nFuncExecute > 0 ) {
		pVM->nFuncExecute-- ;
	}
}

void ring_vm_retitemref ( VM *pVM )
{
	List *pList  ;
	FuncCall *pFuncCall  ;
	pVM->nRetItemRef++ ;
	/* We free the stack to avoid effects on nLoadAddressScope which is used by isstackpointertoobjstate */
	ring_vm_freestack(pVM);
	/*
	**  Check if we are in the operator method to increment the counter again 
	**  We do this to avoid another PUSHV on the list item 
	**  The first one after return expression in the operator method 
	**  The second one before return from eval() that is used by operator overloading 
	**  This to avoid using & two times like  &  & 
	*/
	if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
		pFuncCall = RING_VM_LASTFUNCCALL ;
		if ( strcmp(pFuncCall->cName,"operator") == 0 ) {
			pVM->nRetItemRef++ ;
		}
	}
}

int ring_vm_timetofreetemplists ( VM *pVM )
{
	/* We must start by executing the instruction for the first time (So we use decrement) */
	if ( RING_VM_IR_GETINTREG == 0 ) {
		RING_VM_IR_SETINTREG(RING_VM_TEMPLISTSCOUNTERMAX);
		return 1 ;
	}
	RING_VM_IR_SETINTREG(RING_VM_IR_GETINTREG -1);
	return 0 ;
}

FuncCall * ring_vmfunccall_new ( VM *pVM )
{
	FuncCall *pFuncCall  ;
	pFuncCall = (FuncCall *) ring_vmstate_new(pVM->pRingState) ;
	pFuncCall->pTempMem = NULL ;
	pFuncCall->nCallerPC = 0 ;
	pFuncCall->nStatus = RING_FUNCSTATUS_LOAD ;
	pFuncCall->pVMState = NULL ;
	ring_list_addcustomringpointer_gc(pVM->pRingState,pVM->pFuncCallList,pFuncCall,ring_vmfunccall_delete);
	return pFuncCall ;
}

void ring_vmfunccall_delete ( void *pState,void *pMemory )
{
	FuncCall *pFuncCall  ;
	pFuncCall = (FuncCall *) pMemory ;
	if ( pFuncCall->pTempMem != NULL ) {
		ring_list_delete_gc(pState,pFuncCall->pTempMem);
	}
	if ( pFuncCall->pVMState != NULL ) {
		ring_vmstate_delete(pState,pFuncCall->pVMState);
	}
	ring_vmstate_delete(pState,pMemory);
}

void ring_vmfunccall_useloadfuncp ( VM *pVM,FuncCall *pFuncCall,int nPerformance )
{
	if ( nPerformance == 1 ) {
		/* Replace Instruction with ICO_LOADFUNCP for better performance */
		RING_VM_IR_OPCODE = ICO_LOADFUNCP ;
		/* Leave the first parameter (contains the function name as wanted) */
		RING_VM_IR_ITEMSETLOWINT(RING_VM_IR_ITEM(RING_VM_IR_REG2),pFuncCall->nPC);
		RING_VM_IR_ITEMSETHIGHINT(RING_VM_IR_ITEM(RING_VM_IR_REG2),ring_list_getsize(pVM->pFunctionsMap));
		RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG3),(void *) pFuncCall->pFunc);
		RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG4),(void *) pFuncCall->cNewFileName);
		RING_VM_IR_SETINTREG(pFuncCall->lMethod);
		RING_VM_IR_SETFLAGREG(pFuncCall->nType);
		RING_VM_IR_SETREG3TYPE(RING_VM_REGTYPE_POINTER);
		RING_VM_IR_SETREG4TYPE(RING_VM_REGTYPE_POINTER);
		RING_VM_IR_PARACOUNT = 5 ;
	}
}
