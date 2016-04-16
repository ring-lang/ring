/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Functions */

void ring_vm_loadfunc ( VM *pVM )
{
	ring_vm_loadfunc2(pVM,RING_VM_IR_READC,1);
}

int ring_vm_loadfunc2 ( VM *pVM,const char *cStr,int nPerformance )
{
	List *pList,*pList2,*pList3  ;
	int y  ;
	String *pString  ;
	char cLine[30]  ;
	/* nFuncExecute is used also by See command while nFuncExecute2 is not */
	pVM->nFuncExecute++ ;
	pVM->nFuncExecute2++ ;
	/* pFunctionsMap is a list of lists (Functions in the program) */
	pList = pVM->pFunctionsMap ;
	/* Search */
	for ( y = 1 ; y <= 2 ; y++ ) {
		/* For OOP Support - Search in the Class Methods */
		if ( y == 2 ) {
			/* Exit if we are  ( not inside class (no active object) ) or we call method after object name */
			if ( ( ring_list_getsize(pVM->pObjState) == 0 ) || ( pVM->nCallMethod == 1 ) ) {
				break ;
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
				break ;
			}
		}
		if ( ring_list_gethashtable(pList) == NULL ) {
			ring_list_genhashtable2(pList);
		}
		pList2 = (List *) ring_hashtable_findpointer(ring_list_gethashtable(pList),cStr);
		if ( pList2 != NULL ) {
			/* Error when the method is private */
			if ( ring_list_getint(pList2,RING_FUNCMAP_PRIVATEFLAG) == 1 ) {
				if ( ring_vm_oop_callmethodinsideclass(pVM) == 0 ) {
					ring_vm_error2(pVM,RING_VM_ERROR_CALLINGPRIVATEMETHOD,cStr);
					return 0 ;
				}
			}
			pList3 = ring_list_newlist(pVM->pFuncCallList);
			ring_list_addint(pList3,RING_FUNCTYPE_SCRIPT);
			/* Add the function name */
			pString = ring_string_new("");
			/* Add type Function or Method */
			if ( (y == 1) && (pVM->nCallMethod != 1) ) {
				ring_string_add(pString,"function ");
			} else {
				ring_string_add(pString,"method ");
			}
			ring_string_add(pString,cStr);
			ring_string_add(pString,"() in file ");
			ring_string_add(pString,ring_list_getstring(pList2,RING_FUNCMAP_FILENAME));
			sprintf( cLine , "\ncalled from line %d " , pVM->nLineNumber ) ;
			ring_string_add(pString,cLine);
			ring_list_addstring(pList3,ring_string_get(pString));
			ring_string_delete(pString);
			ring_list_addint(pList3,ring_list_getint(pList2,RING_FUNCMAP_PC));
			ring_list_addint(pList3,pVM->nSP);
			/* Create Temp Memory */
			ring_list_newlist(pList3);
			/* File Name */
			ring_list_addpointer(pList3,pVM->cFileName);
			pVM->cFileName = ring_list_getstring(pList2,RING_FUNCMAP_FILENAME) ;
			/* Method or Function */
			if ( (y == 1) && (pVM->nCallMethod != 1) ) {
				ring_list_addint(pList3,0);
			} else {
				ring_list_addint(pList3,1);
			}
			if ( (strcmp(cStr,"main") != 0 ) && (pVM->nCallMethod != 1) && (y != 2) && (nPerformance == 1) ) {
				/*
				**  We check that we will convert Functions only, not methods 
				**  Replace Instruction with ICO_LOADFUNCP for better performance 
				*/
				RING_VM_IR_OPCODE = ICO_LOADFUNCP ;
				/*
				**  Leave the first parameter (contains the function name as wanted) 
				**  Create the items 
				*/
				ring_vm_newbytecodeitem(pVM,2);
				ring_vm_newbytecodeitem(pVM,3);
				ring_vm_newbytecodeitem(pVM,4);
				ring_vm_newbytecodeitem(pVM,5);
				#if RING_SHOWICFINAL
				/* Update generated code list, so the new items could appear */
				RING_VM_IR_PARACOUNT = RING_VM_IR_PARACOUNT + 4 ;
				ring_list_addint(RING_VM_IR_LIST,ring_list_getint(pList2,RING_FUNCMAP_PC));
				ring_list_addint(RING_VM_IR_LIST,RING_FUNCTYPE_SCRIPT);
				ring_list_addpointer(RING_VM_IR_LIST,ring_list_getstring(pList2,RING_FUNCMAP_FILENAME));
				ring_list_addint(RING_VM_IR_LIST,ring_list_getint(pList3,RING_FUNCCL_METHODORFUNC));
				#endif
				ring_item_setint(RING_VM_IR_ITEM(2),ring_list_getint(pList2,RING_FUNCMAP_PC));
				ring_item_setint(RING_VM_IR_ITEM(3),RING_FUNCTYPE_SCRIPT);
				ring_item_setpointer(RING_VM_IR_ITEM(4),ring_list_getstring(pList2,RING_FUNCMAP_FILENAME));
				ring_item_setint(RING_VM_IR_ITEM(5),ring_list_getint(pList3,RING_FUNCCL_METHODORFUNC));
			}
			/* Add aLoadAddressScope pointer to pLoadAddressScope */
			ring_vm_saveloadaddressscope(pVM);
			return 1 ;
		}
	}
	/* For OOP Support - Check Method not found! */
	if ( pVM->nCallMethod == 1 ) {
		ring_vm_error2(pVM,RING_VM_ERROR_METHODNOTFOUND,cStr);
		return 0 ;
	}
	/* Find Function in C Functions List */
	pList = (List *) ring_hashtable_findpointer(ring_list_gethashtable(pVM->pCFunctionsList),cStr);
	if ( pList != NULL ) {
		pList2 = ring_list_newlist(pVM->pFuncCallList);
		ring_list_addint(pList2,RING_FUNCTYPE_C);
		ring_list_addstring(pList2,cStr);
		ring_list_addfuncpointer(pList2,ring_list_getfuncpointer(pList,RING_FUNCMAP_PC));
		ring_list_addint(pList2,pVM->nSP);
		/* Create Temp Memory */
		ring_list_newlist(pList2);
		/* Add aLoadAddressScope pointer to pLoadAddressScope */
		ring_vm_saveloadaddressscope(pVM);
		return 1 ;
	}
	/* Avoid Error if it is automatic call to the main function */
	if ( pVM->nCallMainFunction == 0 ) {
		if ( strcmp(cStr,"main") == 0 ) {
			return 0 ;
		}
	}
	ring_vm_error2(pVM,RING_VM_ERROR_FUNCNOTFOUND,cStr);
	return 0 ;
}

void ring_vm_call ( VM *pVM )
{
	List *pList, *pActiveMem  ;
	int x,nSP,nMax1,nFuncEx  ;
	pVM->nFuncExecute-- ;
	pVM->nFuncExecute2-- ;
	/* Restore aLoadAddressScope from pLoadAddressScope */
	ring_vm_restoreloadaddressscope(pVM);
	/* Check if we call method using ObjName.MethodName() */
	if ( RING_VM_IR_PARACOUNT == 3 ) {
		if ( RING_VM_IR_READIVALUE(2) ) {
			/*
			**  Now we make the object state visible by moving it from aBeforeObjState to pObjState 
			**  We do this here and not in LoadMethod to avoid accessing the object state when passing parameters 
			**  This fix a problem when we pass the self object to avoid passing ObjName that comes before the method 
			*/
			if ( ring_list_getsize(pVM->aBeforeObjState) > 0 ) {
				pList = ring_list_newlist(pVM->pObjState);
				ring_list_copy(pList,ring_list_getlist(pVM->aBeforeObjState,ring_list_getsize(pVM->aBeforeObjState)));
				ring_list_deleteitem(pVM->aBeforeObjState,ring_list_getsize(pVM->aBeforeObjState));
			}
		}
	}
	pList = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
	/* Calling Method from brace */
	if ( ring_list_getsize(pList) >= RING_FUNCCL_METHODORFUNC ) {
		/* The first test to be sure it's not a C Function Call */
		if ( ring_list_getint(pList,RING_FUNCCL_METHODORFUNC) == 1 ) {
			ring_vm_oop_callmethodfrombrace(pVM);
		}
	}
	/* Store the Caller Position */
	ring_list_addint(pList,pVM->nPC);
	/* Store FuncExe Counter Value */
	ring_list_addint(pList,pVM->nFuncExecute);
	nFuncEx = pVM->nFuncExecute ;
	pVM->nFuncExecute = 0 ;
	/* Call Function */
	if ( ring_list_getint(pList,RING_FUNCCL_TYPE) == RING_FUNCTYPE_SCRIPT ) {
		/* Store List information to allow calling function from list item and creating lists from that funct */
		ring_list_addint(pList,pVM->nListStart);
		ring_list_addpointer(pList,pVM->pNestedLists);
		pVM->nListStart = 0 ;
		pVM->pNestedLists = ring_list_new(0);
		pVM->nPC = ring_list_getint(pList,RING_FUNCCL_PC) ;
		/* Save State */
		ring_vm_savestate2(pVM,pList);
		/* Avoid accessing object data or methods */
		if ( ring_list_getint(pList,RING_FUNCCL_METHODORFUNC) == 0 ) {
			pList = ring_list_newlist(pVM->pObjState);
			ring_list_addpointer(pList,NULL);
			ring_list_addpointer(pList,NULL);
			ring_list_addpointer(pList,NULL);
		}
		/* Clear aLoadAddressScope */
		ring_list_deleteallitems(pVM->aLoadAddressScope);
	}
	else if ( ring_list_getint(pList,RING_FUNCCL_TYPE) == RING_FUNCTYPE_C ) {
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
		pVM->nCFuncParaCount = 0 ;
		nSP = ring_list_getint(pList,RING_FUNCCL_SP) ;
		/* Use Order (First In - First Out) As Queue , the first parameter comes first */
		if ( nSP < pVM->nSP ) {
			nMax1 = pVM->nSP ;
			for ( x = nSP+1 ; x <= nMax1 ; x++ ) {
				pVM->nSP = x ;
				if ( RING_VM_STACK_ISSTRING ) {
					ring_vm_addnewstringvar2(pVM,"",RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
				}
				else if ( RING_VM_STACK_ISNUMBER ) {
					ring_vm_addnewnumbervar(pVM,"",RING_VM_STACK_READN);
				}
				else if ( RING_VM_STACK_ISPOINTER ) {
					ring_vm_addnewpointervar(pVM,"",RING_VM_STACK_READP,RING_VM_STACK_OBJTYPE);
				}
				pVM->nCFuncParaCount++ ;
			}
			pVM->nSP = nSP ;
		}
		/* Prepare to check function termination by try/catch */
		pVM->nActiveCatch = 0 ;
		/* Enable C Pointer Type Check */
		pVM->nIgnoreCPointerTypeCheck = 0 ;
		/* Call Function */
		ring_list_callfuncpointer(pList,RING_FUNCCL_PC,pVM);
		/* Restore nFuncEx sate */
		pVM->nFuncExecute = nFuncEx ;
		/* Check for function termination by try/catch */
		if ( pVM->nActiveCatch == 1 ) {
			/*
			**  We don't remove the function from call list because ring_vm_catch() do when restore state 
			**  We don't delete the scope because ring_vm_catch() will do when restore state 
			**  Restore ActiveMem 
			*/
			pVM->pActiveMem = pActiveMem ;
			return ;
		}
		/* Function Output */
		if ( nSP == pVM->nSP ) {
			/* IgnoreNULL is Used by len(object) to get output from operator overloading method */
			if ( pVM->nIgnoreNULL  == 0 ) {
				RING_VM_STACK_PUSHCVALUE("");
			}
			else {
				pVM->nIgnoreNULL = 0 ;
			}
		}
		/* Move returned List to the previous scope */
		if ( RING_VM_STACK_ISPOINTER ) {
			ring_vm_movetoprevscope(pVM);
		}
		/* Return (Delete Scope, Restore ActiveMem) */
		ring_list_deleteitem(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
		ring_vm_deletescope(pVM);
		/* Restore ActiveMem */
		pVM->pActiveMem = pActiveMem ;
		/* if eval() is called, start the main loop again */
		if ( pVM->nEvalCalledFromRingCode == 1 ) {
			pVM->nEvalCalledFromRingCode = 0 ;
			/*
			**  We use Stack POP to remove the empty string that we return after functions 
			**  This enable the code generated from eval() to be able to return any value 
			**  Using the return command 
			*/
			RING_VM_STACK_POP ;
			ring_vm_mainloop(pVM);
		}
	}
}

void ring_vm_return ( VM *pVM )
{
	List *pList  ;
	/* Support for nested "Load" instructions */
	if ( pVM->nBlockFlag >= 1 ) {
		ring_vm_removeblockflag(pVM);
		/* Be sure it's not a function call or method call */
		if ( pVM->nPC != 0 ) {
			return ;
		}
	}
	if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
		pList = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
		pVM->nPC = ring_list_getint(pList,RING_FUNCCL_CALLERPC) ;
		pVM->nFuncExecute = ring_list_getint(pList,RING_FUNCCL_FUNCEXE) ;
		/* Restore List Status */
		pVM->nListStart = ring_list_getint(pList,RING_FUNCCL_LISTSTART) ;
		if ( pVM->pNestedLists != ring_list_getpointer(pList,RING_FUNCCL_NESTEDLISTS) ) {
			pVM->pNestedLists = ring_list_delete(pVM->pNestedLists);
			pVM->pNestedLists = (List *) ring_list_getpointer(pList,RING_FUNCCL_NESTEDLISTS) ;
		}
		/* Restore File Name */
		pVM->cFileName = (char *) ring_list_getpointer(pList,RING_FUNCCL_FILENAME) ;
		/* Move returned List to the previous scope */
		if ( RING_VM_STACK_ISPOINTER ) {
			/*
			**  if the variable belong to the object state, don't move to prev. scope 
			**  We do this to enable returning a reference 
			**  So when we return an object we can access it directly using { } 
			*/
			if ( ring_vm_isstackpointertoobjstate(pVM) == 0 ) {
				ring_vm_movetoprevscope(pVM);
			}
		}
		ring_vm_deletescope(pVM);
		/* Restore State */
		ring_vm_restorestate2(pVM,pList,RING_FUNCCL_STATE);
		ring_list_deleteitem(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
		/* Restore nFuncSP value */
		if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
			pList = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
			pVM->nFuncSP = ring_list_getint(pList,RING_FUNCCL_SP) ;
		} else {
			pVM->nFuncSP = 0 ;
		}
	} else {
		/* Call Main Function */
		if ( pVM->nCallMainFunction == 0 ) {
			pVM->nPC-- ;
			pVM->nSP = 0 ;
			if ( ring_vm_loadfunc2(pVM,"main",0) ) {
				ring_vm_call(pVM);
				pVM->nCallMainFunction = 1 ;
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
	int x,nSP  ;
	List *pList  ;
	assert(pVM != NULL);
	ring_vm_newscope(pVM);
	/* Set the SP then Check Parameters */
	pList = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
	assert(pList != NULL);
	nSP = ring_list_getint(pList,RING_FUNCCL_SP) ;
	pVM->nFuncSP = nSP ;
	if ( RING_VM_IR_PARACOUNT > 2 ) {
		for ( x = RING_VM_IR_PARACOUNT ; x >= 3 ; x-- ) {
			if ( nSP < pVM->nSP ) {
				if ( RING_VM_STACK_ISSTRING ) {
					ring_vm_addnewstringvar2(pVM,RING_VM_IR_READCVALUE(x-1),RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
					RING_VM_STACK_POP ;
				}
				else if ( RING_VM_STACK_ISNUMBER ) {
					ring_vm_addnewnumbervar(pVM,RING_VM_IR_READCVALUE(x-1),RING_VM_STACK_READN);
					RING_VM_STACK_POP ;
				}
				else if ( RING_VM_STACK_ISPOINTER ) {
					ring_vm_addnewpointervar(pVM,RING_VM_IR_READCVALUE(x-1),RING_VM_STACK_READP,RING_VM_STACK_OBJTYPE);
					RING_VM_STACK_POP ;
				}
			} else {
				ring_vm_error(pVM,RING_VM_ERROR_LESSPARAMETERSCOUNT);
				break ;
			}
		}
		if ( nSP < pVM->nSP ) {
			ring_vm_error(pVM,RING_VM_ERROR_EXTRAPARAMETERSCOUNT);
		}
	}
}

void ring_vm_blockflag ( VM *pVM )
{
	ring_vm_blockflag2(pVM,RING_VM_IR_READI);
}

void ring_vm_blockflag2 ( VM *pVM,int x )
{
	List *pList  ;
	pVM->nBlockFlag++ ;
	pList = ring_list_newlist(pVM->aPCBlockFlag);
	ring_list_addint(pList,x);
	/* Save State */
	ring_list_addint(pList,ring_list_getsize(pVM->pExitMark));
	ring_list_addint(pList,ring_list_getsize(pVM->pLoopMark));
	ring_list_addint(pList,ring_list_getsize(pVM->pTry));
}

void ring_vm_removeblockflag ( VM *pVM )
{
	List *pList  ;
	pList = ring_list_getlist(pVM->aPCBlockFlag,ring_list_getsize(pVM->aPCBlockFlag));
	pVM->nPC = ring_list_getint(pList,1);
	pVM->nBlockFlag-- ;
	/* Restore State */
	ring_vm_backstate(ring_list_getint(pList,2),pVM->pExitMark);
	ring_vm_backstate(ring_list_getint(pList,3),pVM->pLoopMark);
	ring_vm_backstate(ring_list_getint(pList,4),pVM->pTry);
	ring_list_deleteitem(pVM->aPCBlockFlag,ring_list_getsize(pVM->aPCBlockFlag));
}

void ring_vm_movetoprevscope ( VM *pVM )
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
	/* Get The Source List */
	if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
		pList = (List *) RING_VM_STACK_READP ;
		if ( ring_list_islist(pList,RING_VAR_VALUE) ) {
			pList = ring_list_getlist(pList,RING_VAR_VALUE);
		} else {
			return ;
		}
	}
	else if ( RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM ) {
		pItem = (Item *) RING_VM_STACK_READP ;
		pList = ring_item_getlist(pItem);
	} else {
		return ;
	}
	pList2 = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)-1);
	pList3 = ring_vm_newvar2(RING_TEMP_VARIABLE,pList2);
	ring_list_setint(pList3,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist(pList3,RING_VAR_VALUE);
	pList2 = ring_list_getlist(pList3,RING_VAR_VALUE);
	/* Copy the list */
	ring_list_copy(pList2,pList);
	/* Update self object pointer */
	if ( ring_vm_oop_isobject(pList2) ) {
		ring_vm_oop_updateselfpointer(pList2,RING_OBJTYPE_VARIABLE,pList3);
	}
	RING_VM_STACK_SETPVALUE(pList3);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
}

void ring_vm_createtemplist ( VM *pVM )
{
	List *pList  ;
	/*
	**  Create the list in the TempMem related to the function 
	**  The advantage of TempMem over Scope is that TempMem out of search domain (Var Name is not important) 
	**  Variable name in TemMem is not important, we use it for storage (no search) 
	*/
	pList = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
	pList = ring_list_getlist(pList,RING_FUNCCL_TEMPMEM);
	ring_vm_newtempvar(pVM,RING_TEMP_VARIABLE,pList);
}

void ring_vm_saveloadaddressscope ( VM *pVM )
{
	ring_list_addpointer(pVM->pLoadAddressScope,pVM->aLoadAddressScope);
	pVM->aLoadAddressScope = ring_list_new(0);
}

void ring_vm_restoreloadaddressscope ( VM *pVM )
{
	ring_list_delete(pVM->aLoadAddressScope);
	pVM->aLoadAddressScope = (List *) ring_list_getpointer(pVM->pLoadAddressScope,ring_list_getsize(pVM->pLoadAddressScope));
	ring_list_deleteitem(pVM->pLoadAddressScope,ring_list_getsize(pVM->pLoadAddressScope));
}

void ring_vm_anonymous ( VM *pVM )
{
	const char *cStr  ;
	if ( RING_VM_STACK_ISSTRING ) {
		cStr = RING_VM_STACK_READC ;
		RING_VM_STACK_POP ;
		ring_vm_loadfunc2(pVM,cStr,0);
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_BADCALLPARA);
	}
}

int ring_vm_isstackpointertoobjstate ( VM *pVM )
{
	/* if the variable belong to the object state, return 1 */
	if ( ring_list_getsize(pVM->aLoadAddressScope)  >= 1 ) {
		if ( ring_list_getint(pVM->aLoadAddressScope,1) == RING_VARSCOPE_OBJSTATE ) {
			return 1 ;
		}
	}
	return 0 ;
}
