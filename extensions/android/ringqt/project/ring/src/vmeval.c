/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

int ring_vm_eval ( VM *pVM,const char *cStr )
{
	int nPC,nCont,nLastPC,nRunVM,x,nSize,nMark,lUpdate  ;
	Scanner *pScanner  ;
	int aPara[3]  ;
	List *pIR  ;
	nSize = strlen( cStr ) ;
	if ( nSize == 0 ) {
		return 0 ;
	}
	nPC = pVM->nPC ;
	/* Add virtual file name */
	ring_list_addstring_gc(pVM->pRingState,pVM->pRingState->pRingFilesList,"eval");
	ring_list_addstring_gc(pVM->pRingState,pVM->pRingState->pRingFilesStack,"eval");
	pScanner = ring_scanner_new(pVM->pRingState);
	for ( x = 0 ; x < nSize ; x++ ) {
		ring_scanner_readchar(pScanner,cStr[x]);
	}
	nCont = ring_scanner_checklasttoken(pScanner);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	nLastPC = RING_VM_INSTRUCTIONSCOUNT ;
	nRunVM = 0 ;
	/* Get Functions/Classes Size before change by parser */
	aPara[0] = nLastPC ;
	aPara[1] = ring_list_getsize(pVM->pFunctionsMap) ;
	aPara[2] = ring_list_getsize(pVM->pClassesMap) ;
	/* Call Parser */
	if ( nCont == 1 ) {
		pVM->pRingState->lNoLineNumber = 1 ;
		nRunVM = ring_parser_start(pScanner->Tokens,pVM->pRingState);
		pVM->pRingState->lNoLineNumber = 0 ;
	}
	/* Prepare the ByteCode */
	if ( nRunVM == 1 ) {
		/*
		**  Generate Code 
		**  Generate  Hash Table 
		*/
		ring_list_genhashtable2(pVM->pFunctionsMap);
		if ( pVM->nEvalCalledFromRingCode ) {
			ring_scanner_addreturn3(pVM->pRingState,aPara);
		}
		else {
			ring_scanner_addreturn2(pVM->pRingState);
		}
		ring_vm_blockflag2(pVM,nPC);
		pVM->pRingState->nInstructionsCount += ring_list_getsize(pVM->pRingState->pRingGenCode) ;
		pVM->nPC = nLastPC+1 ;
		if ( RING_VM_INSTRUCTIONSCOUNT  > pVM->nEvalReallocationSize ) {
			pVM->pByteCode = (ByteCode *) ring_realloc(pVM->pByteCode , sizeof(ByteCode) * RING_VM_INSTRUCTIONSCOUNT);
			if ( pVM->nEvalCalledFromRingCode ) {
				/* Here eval() function is called from .ring files ( not by the VM for setter/getter/operator overloadi */
				pVM->nEvalReallocationFlag = 1 ;
			}
			/* Update the Eval Reallocation Size after Reallocation */
			pVM->nEvalReallocationSize = RING_VM_INSTRUCTIONSCOUNT ;
		}
		else {
			pVM->nEvalReallocationFlag = 0 ;
		}
		/* Load New Code */
		nMark = pVM->pRingState->nInstructionsCount ;
		lUpdate = pVM->nEvalCalledFromRingCode ;
		pVM->pRingState->nInstructionsCount -= ring_list_getsize(pVM->pRingState->pRingGenCode) ;
		for ( x = 1 ; x <= RING_VM_INSTRUCTIONSLISTSIZE ; x++ ) {
			/* Let Return commands Jump to Return From Eval command */
			if ( lUpdate ) {
				pIR = ring_list_getlist(pVM->pCode,x);
				if ( ring_list_getint(pIR,RING_PARSER_ICG_OPERATIONCODE) == ICO_RETURN ) {
					ring_list_setint_gc(pVM->pRingState,pIR,RING_PARSER_ICG_OPERATIONCODE,ICO_JUMP);
					ring_list_addint_gc(pVM->pRingState,pIR,nMark);
				}
				else if ( (ring_list_getint(pIR,RING_PARSER_ICG_OPERATIONCODE) == ICO_NEWFUNC) || (ring_list_getint(pIR,RING_PARSER_ICG_OPERATIONCODE) == ICO_NEWCLASS) ) {
					lUpdate = 0 ;
				}
			}
			ring_vm_tobytecode(pVM,x);
		}
		pVM->pRingState->nInstructionsCount += ring_list_getsize(pVM->pRingState->pRingGenCode) ;
		ring_list_deleteallitems_gc(pVM->pRingState,pVM->pRingState->pRingGenCode);
		/*
		**  The mainloop will be called again 
		**  We do this to execute eval instructions directly 
		**  This is necessary when we have GUI library that takes the event loop 
		**  Then an event uses the eval() function to execute instructions 
		**  We don't call the main loop here we call it from ring_vm_call() 
		**  We do this to execute the eval() instructions in the correct scope 
		**  Because when we call a C Function like eval() we have parameters scope 
		**  Before we call the main loop from ring_vm_call the parameters scope will be deleted 
		**  And the local scope will be restored so we can use it from eval() 
		**  Update ReallocationSize 
		*/
		pVM->nEvalReallocationSize = pVM->nEvalReallocationSize - (RING_VM_INSTRUCTIONSCOUNT-nLastPC) ;
	}
	/* Clean Memory */
	ring_scanner_delete(pScanner);
	/*
	**  Since we have a Syntax Error, We must delete the generated code 
	**  Without doing this, RingREPL will suffer from many problems after having a Syntax Error 
	**  Like executing (Old Code) when writing new code after having a Syntax Error 
	*/
	ring_list_deleteallitems_gc(pVM->pRingState,pVM->pRingState->pRingGenCode);
	ring_list_deletelastitem_gc(pVM->pRingState,pVM->pRingState->pRingFilesList);
	ring_list_deletelastitem_gc(pVM->pRingState,pVM->pRingState->pRingFilesStack);
	/* Check Error */
	if ( (nCont == 0) || (nRunVM == 0) ) {
		ring_vm_error(pVM,RING_VM_ERROR_EVAL);
	}
	return nRunVM ;
}

void ring_vm_returneval ( VM *pVM )
{
	int aPara[3]  ;
	/* This function will always be called after each eval() execution */
	ring_vm_return(pVM);
	ring_vm_mutexlock(pVM);
	aPara[0] = RING_VM_IR_READIVALUE(1) ;
	aPara[1] = RING_VM_IR_READIVALUE(2) ;
	aPara[2] = RING_VM_IR_READIVALUE(3) ;
	if ( ( pVM->nRetEvalDontDelete == 0 ) && (aPara[1] == ring_list_getsize(pVM->pFunctionsMap)) && (aPara[2] == ring_list_getsize(pVM->pClassesMap)) ) {
		/*
		**  The code interpreted by eval doesn't add new functions or new classes 
		**  This means that the code can be deleted without any problems 
		**  We do that to avoid memory leaks 
		*/
		ring_vm_cleanevalcode(pVM,aPara[0]);
	}
	/*
	**  nEvalReturnPC is checked by the ring_vm_mainloop to end the loop 
	**  if the pVM->nPC becomes <= pVM->nEvalReturnPC the loop will be terminated 
	**  Remember that this is just a sub loop (another main loop) created after using eval() 
	**  If we don't terminate the sub main loop , this is just an extra overhead 
	**  Also terminating the sub main loop is a must when we do GUI programming 
	**  Because in GUI programming, the main loop calls the GUI Main Loop 
	**  During GUI main loop when event happens that calls a ring code 
	**  Eval will be used and a sub main loop will be executed 
	**  If we don't terminate the sub main loop, we can't return to the GUI Main Loop 
	**  It's necessary to return to the GUI main loop 
	**  When the GUI Main Loop Ends, we return to the Ring Main Loop 
	*/
	pVM->nEvalReturnPC = aPara[0] ;
	ring_vm_mutexunlock(pVM);
}

void ring_vm_mainloopforeval ( VM *pVM )
{
	int nDontDelete,nType,nOut,nSP,nFuncSP,nInClassRegion,nInsideEval,nStartPC  ;
	List *pStackList  ;
	double nNumber  ;
	String *pString  ;
	void *pPointer, *pAssignment  ;
	/* Check many nested Eval */
	if ( pVM->nInsideEval == RING_VM_MAXNESTEDEVAL ) {
		ring_vm_error(pVM,RING_VM_ERROR_MAXNESTEDEVAL);
		return ;
	}
	pVM->pRingState->lStartPoolManager = 1 ;
	pVM->nInsideEval++ ;
	nDontDelete = pVM->nRetEvalDontDelete ;
	pVM->nRetEvalDontDelete = 0 ;
	/* Save Stack */
	nSP = pVM->nSP ;
	nFuncSP = pVM->nFuncSP ;
	pStackList = ring_vm_savestack(pVM);
	pAssignment = pVM->pAssignment ;
	nInClassRegion = pVM->nInClassRegion ;
	nInsideEval = pVM->nInsideEval ;
	nStartPC = pVM->nPC ;
	/* Allows showing the OPCODE */
	if ( pVM->pRingState->nPrintInstruction ) {
		do {
			ring_vm_fetch2(pVM);
			if ( pVM->nPC <= pVM->nEvalReturnPC ) {
				pVM->nEvalReturnPC = 0 ;
				break ;
			}
			if ( pVM->nInsideEval != nInsideEval ) {
				ring_vm_cleanevalcode(pVM,nStartPC - 1);
				break ;
			}
		} while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT)  ;
	}
	else {
		do {
			ring_vm_fetch(pVM);
			if ( pVM->nPC <= pVM->nEvalReturnPC ) {
				pVM->nEvalReturnPC = 0 ;
				break ;
			}
			if ( pVM->nInsideEval != nInsideEval ) {
				ring_vm_cleanevalcode(pVM,nStartPC - 1);
				break ;
			}
		} while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT)  ;
	}
	if ( pVM->nInsideEval == nInsideEval ) {
		pVM->nInsideEval-- ;
	}
	pVM->nRetEvalDontDelete = nDontDelete ;
	/* Save Output */
	nOut = RING_EVALOUTPUT_NULL ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nOut = RING_EVALOUTPUT_NUMBER ;
		nNumber = RING_VM_STACK_READN ;
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		nOut = RING_EVALOUTPUT_STRING ;
		pString = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		nOut = RING_EVALOUTPUT_POINTER ;
		pPointer = RING_VM_STACK_READP ;
		nType = RING_VM_STACK_OBJTYPE ;
		if ( nType == RING_OBJTYPE_VARIABLE ) {
			if ( ring_vm_checknull(pVM,RING_CHECKNULL_NOERROR) ) {
				nOut = RING_EVALOUTPUT_NULL ;
			}
		}
	}
	/* Restore Stack */
	ring_vm_restorestack(pVM,pStackList);
	ring_list_delete_gc(pVM->pRingState,pStackList);
	pVM->nSP = nSP ;
	pVM->nFuncSP = nFuncSP ;
	pVM->pAssignment = pAssignment ;
	pVM->nInClassRegion = nInClassRegion ;
	/* Push Output */
	if ( nOut == RING_EVALOUTPUT_NUMBER ) {
		RING_VM_STACK_PUSHNVALUE(nNumber);
	}
	else if ( nOut == RING_EVALOUTPUT_STRING ) {
		RING_VM_STACK_PUSHCVALUE2(ring_string_get(pString),ring_string_size(pString));
		ring_string_delete_gc(pVM->pRingState,pString);
	}
	else if ( nOut == RING_EVALOUTPUT_POINTER ) {
		RING_VM_STACK_PUSHPVALUE(pPointer);
		RING_VM_STACK_OBJTYPE = nType ;
	}
}

RING_API void ring_vm_runcode ( VM *pVM,const char *cStr )
{
	int nEvalReturnPC,nEvalReallocationFlag,nPC,nRunVM,nSP,nFuncSP,nLineNumber  ;
	List *pStackList  ;
	/* Save state to take in mind nested events execution */
	pVM->nRunCode++ ;
	nEvalReturnPC = pVM->nEvalReturnPC ;
	nEvalReallocationFlag = pVM->nEvalReallocationFlag ;
	nPC = pVM->nPC ;
	nSP = pVM->nSP ;
	nFuncSP = pVM->nFuncSP ;
	pStackList = ring_vm_savestack(pVM);
	nLineNumber = RING_VM_IR_GETLINENUMBER ;
	ring_vm_mutexlock(pVM);
	pVM->nEvalCalledFromRingCode = 1 ;
	/* Take in mind nested events */
	if ( pVM->nRunCode != 1 ) {
		pVM->nRetEvalDontDelete = 1 ;
	}
	nRunVM = ring_vm_eval(pVM,cStr);
	pVM->nEvalCalledFromRingCode = 0 ;
	ring_vm_mutexunlock(pVM);
	if ( nRunVM ) {
		pVM->nFuncExecute = 0 ;
		ring_vm_mainloopforeval(pVM);
	}
	/* Restore state to take in mind nested events execution */
	pVM->nRunCode-- ;
	pVM->nEvalReturnPC = nEvalReturnPC ;
	pVM->nEvalReallocationFlag = nEvalReallocationFlag ;
	pVM->nPC = nPC ;
	if ( pVM->nRunCode != 0 ) {
		/* It's a nested event (Here we don't care about the output and we can restore the stack) */
		ring_vm_restorestack(pVM,pStackList);
	}
	/* Here we free the list because, restorestack() don't free it */
	ring_list_delete_gc(pVM->pRingState,pStackList);
	/* Restore Stack to avoid Stack Overflow */
	pVM->nSP = nSP ;
	pVM->nFuncSP = nFuncSP ;
	RING_VM_IR_SETLINENUMBER(nLineNumber);
}

void ring_vm_cleanevalcode ( VM *pVM,int nCodeSize )
{
	int nExtraSize  ;
	ByteCode *pByteCode  ;
	nExtraSize = RING_VM_INSTRUCTIONSCOUNT - nCodeSize ;
	while ( RING_VM_INSTRUCTIONSCOUNT != nCodeSize ) {
		RING_VM_DELETELASTINSTRUCTION ;
	}
	if ( pVM->nEvalReallocationFlag == 1 ) {
		pVM->nEvalReallocationFlag = 0 ;
		pByteCode = (ByteCode *) ring_realloc(pVM->pByteCode , sizeof(ByteCode) * RING_VM_INSTRUCTIONSCOUNT);
		pVM->pByteCode = pByteCode ;
		/* Update the Eval Reallocation Size after Reallocation */
		pVM->nEvalReallocationSize = pVM->nEvalReallocationSize - nExtraSize ;
	}
	else {
		pVM->nEvalReallocationSize = pVM->nEvalReallocationSize + nExtraSize ;
	}
}

RING_API void ring_vm_callfunction ( VM *pVM,char *cFuncName )
{
	/* Lower Case and pass () in the end */
	ring_string_lower(cFuncName);
	/* Prepare (Remove effects of the current function) */
	ring_list_deletelastitem_gc(pVM->pRingState,pVM->pFuncCallList);
	/* Load the function and call it */
	ring_vm_loadfunc2(pVM,cFuncName,0);
	ring_vm_call2(pVM);
	/* Execute the function */
	ring_vm_mainloopforeval(pVM);
	/* Free Stack */
	ring_vm_freestack(pVM);
	/* Avoid normal steps after this function, because we deleted the scope in Prepare */
	pVM->nActiveCatch = 1 ;
}
