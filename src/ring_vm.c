/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  Main 
*/

VM * ring_vm_new ( RingState *pRingState )
{
	VM *pVM  ;
	int x  ;
	List *pList  ;
	pVM = (VM *) malloc(sizeof(VM)) ;
	if ( pVM == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	pVM->nPC = 1 ;
	pVM->pCode = NULL ;
	pVM->pFunctionsMap = NULL ;
	pVM->nOPCode = 0 ;
	pVM->nSP = 0 ;
	pVM->pMem = ring_list_new(0);
	pVM->pActiveMem = NULL ;
	pVM->pTempMem = ring_list_new(0);
	pVM->nLineNumber = 1 ;
	/* Information to test the lifetime of the local scope */
	pVM->nScopeID = 0 ;
	pVM->aScopeID = ring_list_new(0);
	ring_vm_newscope(pVM);
	for ( x = 0 ; x < RING_VM_STACK_SIZE ; x++ ) {
		pVM->aStack[x].nType = ITEMTYPE_NOTHING ;
		pVM->aStack[x].nObjectType = 0 ;
		pVM->aStack[x].NumberFlag = ITEM_NUMBERFLAG_NOTHING ;
	}
	/* Ring State */
	pVM->pRingState = pRingState ;
	/*
	**  Add Variables 
	**  We write variable name in lower case because Identifiers is converted to lower by Compiler(Scanner) 
	*/
	ring_vm_addnewnumbervar(pVM,"true",1);
	ring_vm_addnewnumbervar(pVM,"false",0);
	ring_vm_addnewstringvar(pVM,"nl","\n");
	ring_vm_addnewstringvar(pVM,"null","");
	ring_vm_addnewpointervar(pVM,"ring_gettemp_var",NULL,0);
	ring_vm_addnewstringvar(pVM,"ccatcherror","NULL");
	ring_vm_addnewpointervar(pVM,"ring_settemp_var",NULL,0);
	ring_vm_addnewnumbervar(pVM,"ring_tempflag_var",0);
	ring_vm_addnewcpointervar(pVM,"stdin",stdin,"file");
	ring_vm_addnewcpointervar(pVM,"stdout",stdout,"file");
	ring_vm_addnewcpointervar(pVM,"stderr",stderr,"file");
	/* Add Command Line Parameters */
	pList = ring_vm_newvar2("sysargv",pVM->pActiveMem);
	ring_list_setint(pList,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist(pList,RING_VAR_VALUE);
	pList = ring_list_getlist(pList,RING_VAR_VALUE);
	for ( x = 0 ; x < pVM->pRingState->argc ; x++ ) {
		ring_list_addstring(pList,pVM->pRingState->argv[x]);
	}
	/* Lists */
	pVM->nListStart = 0 ;
	pVM->pNestedLists = ring_list_new(0);
	/* Support for nested Load Instructions */
	pVM->nBlockFlag = 0 ;
	pVM->aPCBlockFlag = ring_list_new(0);
	/* Calling Functions */
	pVM->pFuncCallList = ring_list_new(0);
	pVM->nFuncSP = 0 ;
	pVM->nFuncExecute = 0 ;
	if ( pRingState->pRingCFunctions == NULL ) {
		pRingState->pRingCFunctions = ring_list_new(0);
	}
	pVM->pCFunctionsList = pRingState->pRingCFunctions ;
	pVM->nCallMainFunction = 0 ;
	/* Support for Exit/Loop Commands inside For/While loops. */
	pVM->pExitMark = ring_list_new(0);
	pVM->pLoopMark = ring_list_new(0);
	/* Try-Catch-Done */
	pVM->pTry = ring_list_new(0);
	/* Saving scope when creating new objects and calling class init method */
	pVM->aScopeNewObj = ring_list_new(0);
	/* Flag ( 0 = Call Function  1 = Call Method After writing object name using dot ) */
	pVM->nCallMethod = 0 ;
	/* List of Lists used like Stack, list structure [Pointer to State , Pointer to Methods] */
	pVM->pObjState = ring_list_new(0);
	/* Support for using Braces to access object state */
	pVM->pBraceObject = NULL ;
	pVM->aBraceObjects = ring_list_new(0);
	/* Used by BraceStart, BraceEnd & FreeStack */
	pVM->nInsideBraceFlag = 0 ;
	/* Variable scope, where is the varaible (when we use findvar) */
	pVM->nVarScope = RING_VARSCOPE_NOTHING ;
	/* Flag used by Try/Catch to tell C-API that catch happens! */
	pVM->nActiveCatch = 0 ;
	/* Flag ( 0 = check NULL variable in PUSHV  , greater than 0 = Ignore null variable ) */
	pVM->nCheckNULLVar = 0 ;
	pVM->pPackagesMap = NULL ;
	/* Set the main File Name */
	pVM->cFileName = ring_list_getstring(pVM->pRingState->pRingFilesList,1) ;
	/* We keep information about active package to access its classes directly with new/from */
	pVM->aActivePackage = ring_list_new(0);
	/* Scope of class attribute ( 0 = public 1 = private ) */
	pVM->nPrivateFlag = 0 ;
	/* Set/Get Property */
	pVM->nGetSetProperty = 0 ;
	pVM->pGetSetObject = NULL ;
	pVM->nGetSetObjType = 0 ;
	pVM->aSetProperty = ring_list_new(0);
	/* Assignment Pointer */
	pVM->pAssignment = NULL ;
	/* C Pointers List (Copied Pointers Only that are active i.e. Not NULL) */
	pVM->aCPointers = ring_list_new(0) ;
	/* For Loop - Step List */
	pVM->aForStep = ring_list_new(0);
	/* Flag for LoadA , when = 1 , if it's a pointer we get First Var. not the Pointer */
	pVM->nFirstAddress = 0 ;
	/* Used to know operator before = like += -= *= /= */
	pVM->nBeforeEqual = 0 ;
	/*
	**  NOAssignment used to disable instruction AssignmentPointer 
	**  We uses this when we change assignment to set property 
	**  It's important for ListStart to create Temp List when we use setter 
	**  and try to set attribute value to a list and a function setproperty() will be called 
	**  With this list as parameter stored in temp memory 
	*/
	pVM->nNOAssignment = 0 ;
	/* List contains the scope of the result of Load Address */
	pVM->aLoadAddressScope = ring_list_new(0);
	/* List contains what to add  later to pObjState, prepare by loadmethod, add before call */
	pVM->aBeforeObjState = ring_list_new(0) ;
	/* Saving pointers to aLoadAddressScope before func. para. to restore after them */
	pVM->pLoadAddressScope = ring_list_new(0);
	/* Another flag like nFuncExec but not used by see command or return command */
	pVM->nFuncExecute2 = 0 ;
	/* Create List for Temp Items (added to ByteCode) inside TempMem */
	pVM->aNewByteCodeItems = ring_list_new(0);
	/* Eval can be called from C code (OOP Set/Get/Operator Overloading) or from ring code using eval() */
	pVM->nEvalCalledFromRingCode = 0 ;
	/* Number of decimals after the point */
	pVM->nDecimals = 2 ;
	/*
	**  Do we need to reallocation for eval() or not ! 
	**  Size of items that we can use without reallocation (double of the original size) 
	*/
	pVM->nEvalReallocationSize = 0 ;
	/* Flag ( 1 = we need space over allocated size so we have to do reallocation ) */
	pVM->nEvalReallocationFlag = 0 ;
	/* Parameters Count Passed to C Function */
	pVM->nCFuncParaCount = 0 ;
	/*
	**  Flag to Ignore NULL output after calling C Function 
	**  This flag is used by the len() function when we use len(object) 
	**  So operator overloading can return the result from the method 
	*/
	pVM->nIgnoreNULL = 0 ;
	/* If pVM->nPC <= nEvalReturnPC we end the main loop (used by evalreturn) */
	pVM->nEvalReturnPC = 0 ;
	/* Flag to return Item Reference (of object state) */
	pVM->nRetItemRef = 0 ;
	/* Mutex Functions Pointers - for threads/lock/unlock */
	pVM->pFuncMutexLock = NULL ;
	pVM->pFuncMutexUnlock = NULL ;
	pVM->pFuncMutexDestroy = NULL ;
	pVM->pMutex = NULL ;
	/* Ignore C Pointer Type Check in extension functions */
	pVM->nIgnoreCPointerTypeCheck = 0 ;
	/*
	**  Flag when we call class init using new obj() 
	**  Since we call init() using generated braces { } 
	**  setting this flag enable LoadAddress to pass these braces 
	**  To access the class attributes of the caller 
	**  because {} hides the class attributes and we need to avoid that! 
	*/
	pVM->nCallClassInit = 0 ;
	/*
	**  Flag to avoid deleteing Byte Code using Return From Eval() 
	**  When we use eval() then inside eval we uses eval for setter/getter/operator overloading 
	**  Then deleting byte code will cause a problem in setter/getter/operator overloading 
	**  In this case we set this flag to avoid the delete operation and solve the problem 
	*/
	pVM->nRetEvalDontDelete = 0 ;
	return pVM ;
}

VM * ring_vm_delete ( VM *pVM )
{
	int x  ;
	assert(pVM);
	pVM->pMem = ring_list_delete(pVM->pMem);
	pVM->pNestedLists = ring_list_delete(pVM->pNestedLists);
	pVM->pFuncCallList = ring_list_delete(pVM->pFuncCallList);
	pVM->aPCBlockFlag = ring_list_delete(pVM->aPCBlockFlag);
	pVM->pTempMem = ring_list_delete(pVM->pTempMem);
	pVM->pExitMark = ring_list_delete(pVM->pExitMark);
	pVM->pLoopMark = ring_list_delete(pVM->pLoopMark);
	pVM->pTry = ring_list_delete(pVM->pTry);
	pVM->aScopeNewObj = ring_list_delete(pVM->aScopeNewObj);
	pVM->pObjState = ring_list_delete(pVM->pObjState);
	pVM->aBraceObjects = ring_list_delete(pVM->aBraceObjects);
	pVM->aScopeID = ring_list_delete(pVM->aScopeID);
	pVM->aActivePackage = ring_list_delete(pVM->aActivePackage);
	pVM->aSetProperty = ring_list_delete(pVM->aSetProperty);
	pVM->aCPointers = ring_list_delete(pVM->aCPointers);
	pVM->aForStep = ring_list_delete(pVM->aForStep);
	pVM->aLoadAddressScope = ring_list_delete(pVM->aLoadAddressScope);
	pVM->aBeforeObjState = ring_list_delete(pVM->aBeforeObjState);
	pVM->pLoadAddressScope = ring_list_delete(pVM->pLoadAddressScope);
	pVM->aNewByteCodeItems = ring_list_delete(pVM->aNewByteCodeItems);
	/* Free Stack */
	for ( x = 0 ; x < RING_VM_STACK_SIZE ; x++ ) {
		ring_item_content_delete(&(pVM->aStack[x]));
	}
	free( pVM->pByteCode ) ;
	/* Delete Mutex */
	ring_vm_mutexdestroy(pVM);
	free( pVM ) ;
	pVM = NULL ;
	return pVM ;
}

RING_API void ring_vm_loadcode ( VM *pVM )
{
	int x,nSize  ;
	/*
	**  We allocation double of the size that we need to avoid reallocation when we use eval() 
	**  eval() will check if there is a need to reallocation or not 
	**  This optimization increase the performance of applications that uses eval() 
	*/
	nSize = (ring_list_getsize(pVM->pCode))*RING_VM_EXTRASIZE ;
	pVM->pByteCode = (ByteCode *) calloc(nSize,sizeof(ByteCode)) ;
	for ( x = 1 ; x <= ring_list_getsize(pVM->pCode) ; x++ ) {
		ring_vm_tobytecode(pVM,x);
	}
	pVM->nEvalReallocationSize = nSize ;
}

void ring_vm_start ( RingState *pRingState,VM *pVM )
{
	pVM->pCode = pRingState->pRingGenCode ;
	pVM->pFunctionsMap = pRingState->pRingFunctionsMap ;
	pVM->pClassesMap = pRingState->pRingClassesMap ;
	pVM->pPackagesMap = pRingState->pRingPackagesMap ;
	ring_vm_loadcode(pVM);
	ring_vm_loadcfunctions(pRingState);
	/* Generate Items Array &  Hash Table */
	ring_list_genarray(pRingState->pRingCFunctions);
	ring_list_genhashtable2(pRingState->pRingCFunctions);
	if ( ring_list_getsize(pVM->pCode) > 0 ) {
		pVM->nPC = 1 ;
		ring_vm_mainloop(pVM);
	}
}

void ring_vm_mainloop ( VM *pVM )
{
	#if RING_VMSHOWOPCODE
	do {
		if ( pVM->pRingState->nPrintInstruction ) {
			ring_vm_fetch2(pVM);
		}
		else {
			ring_vm_fetch(pVM);
		}
		if ( pVM->nPC <= pVM->nEvalReturnPC ) {
			pVM->nEvalReturnPC = 0 ;
			break ;
		}
	} while (pVM->nPC <= ring_list_getsize(pVM->pCode))  ;
	#else
	do {
		ring_vm_fetch(pVM);
		if ( pVM->nPC <= pVM->nEvalReturnPC ) {
			pVM->nEvalReturnPC = 0 ;
			break ;
		}
	} while (pVM->nPC <= ring_list_getsize(pVM->pCode))  ;
	#endif
}

void ring_vm_fetch ( VM *pVM )
{
	pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1 ;
	pVM->nOPCode = RING_VM_IR_OPCODE ;
	pVM->nPC++ ;
	ring_vm_execute(pVM);
	if ( pVM->nSP > 253 ) {
		ring_vm_error(pVM,RING_VM_ERROR_STACKOVERFLOW);
	}
}

void ring_vm_fetch2 ( VM *pVM )
{
	pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1 ;
	pVM->nOPCode = RING_VM_IR_OPCODE ;
	#if RING_VMSHOWOPCODE
	if ( pVM->pRingState->nPrintInstruction ) {
		ring_print_line();
		printf( "\nVM Pointer  : %p  " , (void *) pVM ) ;
		printf( "\nOperation  : %s  " , RING_IC_OP[pVM->nOPCode] ) ;
		printf( "\nPC         : %d  " ,pVM->nPC ) ;
		printf( "\nLine Number    : %d  , File %s \n " ,pVM->nLineNumber,pVM->cFileName ) ;
		if ( (pVM->nOPCode == ICO_PUSHC) || (pVM->nOPCode == ICO_LOADADDRESS) || (pVM->nOPCode == ICO_LOADFUNC) ) {
			printf( "\nData       : %s \n",RING_VM_IR_READC ) ;
		}
	}
	#endif
	pVM->nPC++ ;
	ring_vm_execute(pVM);
	#if RING_VMSHOWOPCODE
	if ( pVM->pRingState->nPrintInstruction ) {
		printf( "\nSP (After) : %d  - FuncSP : %d \n LineNumber %d \n" , (int) pVM->nSP,pVM->nFuncSP,pVM->nLineNumber ) ;
		ring_print_line();
	}
	#endif
	if ( pVM->nSP > 253 ) {
		ring_vm_error(pVM,RING_VM_ERROR_STACKOVERFLOW);
	}
}

void ring_vm_execute ( VM *pVM )
{
	switch ( pVM->nOPCode ) {
		/* Stack and Variables */
		case ICO_PUSHC :
			RING_VM_STACK_PUSHC ;
			break ;
		case ICO_PUSHN :
			RING_VM_STACK_PUSHN ;
			break ;
		case ICO_PUSHV :
			ring_vm_pushv(pVM);
			break ;
		case ICO_LOADADDRESS :
			ring_vm_loadaddress(pVM);
			break ;
		case ICO_ASSIGNMENT :
			ring_vm_assignment(pVM);
			break ;
		case ICO_INC :
			ring_vm_inc(pVM);
			break ;
		case ICO_LOADAPUSHV :
			ring_vm_loadapushv(pVM);
			break ;
		case ICO_NEWLINE :
			ring_vm_newline(pVM);
			break ;
		case ICO_FREESTACK :
			ring_vm_freestack(pVM);
			break ;
		case ICO_FILENAME :
			pVM->cFileName = RING_VM_IR_READC ;
			break ;
		/* Jump */
		case ICO_JUMP :
			ring_vm_jump(pVM);
			break ;
		case ICO_JUMPZERO :
			ring_vm_jumpzero(pVM);
			break ;
		case ICO_JUMPFOR :
			ring_vm_jumpfor(pVM);
			break ;
		case ICO_JUMPONE :
			ring_vm_jumpone(pVM);
			break ;
		case ICO_JUMPZERO2 :
			ring_vm_jumpzero2(pVM);
			break ;
		case ICO_JUMPONE2 :
			ring_vm_jumpone2(pVM);
			break ;
		/* Compare */
		case ICO_LESSEQUAL :
			ring_vm_lessequal(pVM);
			break ;
		case ICO_EQUAL :
			ring_vm_equal(pVM);
			break ;
		case ICO_LESS :
			ring_vm_less(pVM);
			break ;
		case ICO_GREATER :
			ring_vm_greater(pVM);
			break ;
		case ICO_GREATEREQUAL :
			ring_vm_greaterequal(pVM);
			break ;
		case ICO_NOTEQUAL :
			ring_vm_notequal(pVM);
			break ;
		/* Math */
		case ICO_SUM :
			ring_vm_sum(pVM);
			break ;
		case ICO_SUB :
			ring_vm_sub(pVM);
			break ;
		case ICO_MUL :
			ring_vm_mul(pVM);
			break ;
		case ICO_DIV :
			ring_vm_div(pVM);
			break ;
		case ICO_MOD :
			ring_vm_mod(pVM);
			break ;
		case ICO_NEG :
			ring_vm_neg(pVM);
			break ;
		case ICO_PLUSPLUS :
			ring_vm_plusplus(pVM);
			break ;
		case ICO_MINUSMINUS :
			ring_vm_minusminus(pVM);
			break ;
		/* Logic */
		case ICO_AND :
			ring_vm_and(pVM);
			break ;
		case ICO_OR :
			ring_vm_or(pVM);
			break ;
		case ICO_NOT :
			ring_vm_not(pVM);
			break ;
		/* Lists */
		case ICO_LISTSTART :
			ring_vm_liststart(pVM);
			break ;
		case ICO_LISTITEM :
			ring_vm_listitem(pVM);
			break ;
		case ICO_LISTEND :
			ring_vm_listend(pVM);
			break ;
		case ICO_LOADINDEXADDRESS :
			ring_vm_loadindexaddress(pVM);
			break ;
		/* Functions */
		case ICO_LOADFUNC :
			ring_vm_loadfunc(pVM);
			break ;
		case ICO_CALL :
			ring_vm_call(pVM);
			break ;
		case ICO_RETURN :
			ring_vm_return(pVM);
			break ;
		case ICO_RETNULL :
			ring_vm_returnnull(pVM);
			break ;
		case ICO_RETFROMEVAL :
			ring_vm_returneval(pVM);
			break ;
		case ICO_RETITEMREF :
			ring_vm_retitemref(pVM);
			break ;
		case ICO_NEWFUNC :
			ring_vm_newfunc(pVM);
			break ;
		case ICO_BLOCKFLAG :
			ring_vm_blockflag(pVM);
			break ;
		case ICO_FUNCEXE :
			pVM->nFuncExecute++ ;
			break ;
		case ICO_ENDFUNCEXE :
			pVM->nFuncExecute-- ;
			break ;
		case ICO_ANONYMOUS :
			ring_vm_anonymous(pVM);
			break ;
		/* User Interface */
		case ICO_PRINT :
			ring_vm_see(pVM);
			break ;
		case ICO_GIVE :
			ring_vm_give(pVM);
			break ;
		/* End Program - Exit from Loop - Loop (Continue) */
		case ICO_BYE :
			ring_vm_bye(pVM);
			break ;
		case ICO_EXITMARK :
			ring_vm_exitmark(pVM);
			break ;
		case ICO_POPEXITMARK :
			ring_vm_popexitmark(pVM);
			break ;
		case ICO_EXIT :
			ring_vm_exit(pVM,1);
			break ;
		case ICO_LOOP :
			ring_vm_exit(pVM,2);
			break ;
		/* For Better Performance */
		case ICO_PUSHP :
			ring_vm_pushp(pVM);
			break ;
		case ICO_INCP :
			ring_vm_incp(pVM);
			break ;
		case ICO_PUSHPV :
			ring_vm_pushpv(pVM);
			break ;
		case ICO_INCJUMP :
			ring_vm_incjump(pVM);
			break ;
		case ICO_INCPJUMP :
			ring_vm_incpjump(pVM);
			break ;
		case ICO_JUMPVARLENUM :
			ring_vm_jumpvarlenum(pVM);
			break ;
		case ICO_JUMPVARPLENUM :
			ring_vm_jumpvarplenum(pVM);
			break ;
		case ICO_LOADFUNCP :
			ring_vm_loadfuncp(pVM);
			break ;
		case ICO_PUSHPLOCAL :
			ring_vm_pushplocal(pVM);
			break ;
		case ICO_INCLPJUMP :
			ring_vm_inclpjump(pVM);
			break ;
		case ICO_JUMPVARLPLENUM :
			ring_vm_jumpvarlplenum(pVM);
			break ;
		case ICO_INCPJUMPSTEP1 :
			ring_vm_incpjumpstep1(pVM);
			break ;
		case ICO_JUMPVARPLENUMSTEP1 :
			ring_vm_jumpvarplenumstep1(pVM);
			break ;
		/* Try-Catch-Done */
		case ICO_TRY :
			ring_vm_try(pVM);
			break ;
		case ICO_DONE :
			ring_vm_done(pVM);
			break ;
		/* Duplicate and Range */
		case ICO_DUPLICATE :
			ring_vm_dup(pVM);
			break ;
		case ICO_RANGE :
			ring_vm_range(pVM);
			break ;
		/* OOP */
		case ICO_NEWOBJ :
			ring_vm_oop_newobj(pVM);
			break ;
		case ICO_SETSCOPE :
			ring_vm_oop_setscope(pVM);
			break ;
		case ICO_LOADSUBADDRESS :
			ring_vm_oop_property(pVM);
			break ;
		case ICO_LOADMETHOD :
			ring_vm_oop_loadmethod(pVM);
			break ;
		case ICO_AFTERCALLMETHOD :
			ring_vm_oop_aftercallmethod(pVM);
			break ;
		case ICO_AFTERCALLMETHOD2 :
			ring_vm_oop_aftercallmethod(pVM);
			break ;
		case ICO_NEWCLASS :
			ring_vm_oop_newclass(pVM);
			break ;
		case ICO_BRACESTART :
			ring_vm_oop_bracestart(pVM);
			break ;
		case ICO_BRACEEND :
			ring_vm_oop_braceend(pVM);
			break ;
		case ICO_IMPORT :
			ring_vm_oop_import(pVM);
			break ;
		case ICO_PRIVATE :
			pVM->nPrivateFlag = 1 ;
			break ;
		case ICO_SETPROPERTY :
			ring_vm_oop_setproperty(pVM);
			break ;
		case ICO_CALLCLASSINIT :
			pVM->nCallClassInit = ! pVM->nCallClassInit ;
			break ;
		/* Other */
		case ICO_SETREFERENCE :
			ring_vm_setreference(pVM);
			break ;
		case ICO_KILLREFERENCE :
			ring_vm_gc_killreference(pVM);
			break ;
		case ICO_ASSIGNMENTPOINTER :
			ring_vm_assignmentpointer(pVM);
			break ;
		case ICO_BEFOREEQUAL :
			pVM->nBeforeEqual = RING_VM_IR_READI ;
			break ;
		/* Bitwise Operators */
		case ICO_BITAND :
			ring_vm_bitand(pVM);
			break ;
		case ICO_BITOR :
			ring_vm_bitor(pVM);
			break ;
		case ICO_BITXOR :
			ring_vm_bitxor(pVM);
			break ;
		case ICO_BITNOT :
			ring_vm_bitnot(pVM);
			break ;
		case ICO_BITSHL :
			ring_vm_bitshl(pVM);
			break ;
		case ICO_BITSHR :
			ring_vm_bitshr(pVM);
			break ;
		/* For Step */
		case ICO_STEPNUMBER :
			ring_vm_stepnumber(pVM);
			break ;
		case ICO_POPSTEP :
			ring_vm_popstep(pVM);
			break ;
		case ICO_LOADAFIRST :
			pVM->nFirstAddress = 1 ;
			ring_vm_loadaddress(pVM);
			pVM->nFirstAddress = 0 ;
			break ;
	}
}

RING_API void ring_vm_error ( VM *pVM,const char *cStr )
{
	int x  ;
	List *pList  ;
	if ( ring_list_getsize(pVM->pTry) == 0 ) {
		ring_state_cgiheader(pVM->pRingState);
		printf( "\nLine %d %s \n",pVM->nLineNumber,cStr ) ;
		/* Print Calling Information */
		for ( x =ring_list_getsize(pVM->pFuncCallList) ; x >= 1 ; x-- ) {
			pList = ring_list_getlist(pVM->pFuncCallList,x);
			printf( "In %s ",ring_list_getstring(pList,RING_FUNCCL_NAME) ) ;
		}
		printf( "in file %s ",ring_list_getstring(pVM->pRingState->pRingFilesList,1) ) ;
		exit(0);
	}
	ring_vm_catch(pVM,cStr);
}

void ring_vm_eval ( VM *pVM,const char *cStr )
{
	int nPC,nCont,nLastPC,nRunVM,x,nSize  ;
	Scanner *pScanner  ;
	int aPara[3]  ;
	ByteCode *pByteCode  ;
	nSize = strlen( cStr ) ;
	if ( nSize == 0 ) {
		return ;
	}
	nPC = pVM->nPC ;
	/* Add virtual file name */
	ring_list_addstring(pVM->pRingState->pRingFilesList,"eval");
	ring_list_addstring(pVM->pRingState->pRingFilesStack,"eval");
	pScanner = ring_scanner_new(pVM->pRingState);
	for ( x = 0 ; x < nSize ; x++ ) {
		ring_scanner_readchar(cStr[x],pScanner);
	}
	nCont = ring_scanner_checklasttoken(pScanner);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	nLastPC = ring_list_getsize(pVM->pCode);
	/* Get Functions/Classes Size before change by parser */
	aPara[0] = nLastPC ;
	aPara[1] = ring_list_getsize(pVM->pFunctionsMap) ;
	aPara[2] = ring_list_getsize(pVM->pClassesMap) ;
	/* Call Parser */
	if ( nCont == 1 ) {
		nRunVM = ring_parser_start(pScanner->Tokens,pVM->pRingState);
	} else {
		ring_vm_error(pVM,"Error in eval!");
		ring_scanner_delete(pScanner);
		return ;
	}
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
		pVM->nPC = nLastPC+1 ;
		if ( ring_list_getsize(pVM->pCode)  > pVM->nEvalReallocationSize ) {
			pByteCode = (ByteCode *) realloc(pVM->pByteCode , sizeof(ByteCode) * ring_list_getsize(pVM->pCode));
			if ( pByteCode == NULL ) {
				printf( RING_OOM ) ;
				ring_scanner_delete(pScanner);
				exit(0);
			}
			pVM->pByteCode = pByteCode ;
			if ( pVM->nEvalCalledFromRingCode ) {
				/* Here eval() function is called from .ring files ( not by the VM for setter/getter/operator overloading) */
				pVM->nEvalReallocationFlag = 1 ;
			}
		}
		else {
			pVM->nEvalReallocationFlag = 0 ;
		}
		/* Load New Code */
		for ( x = pVM->nPC ; x <= ring_list_getsize(pVM->pCode) ; x++ ) {
			ring_vm_tobytecode(pVM,x);
		}
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
		pVM->nEvalReallocationSize = pVM->nEvalReallocationSize - (ring_list_getsize(pVM->pCode)-nLastPC) ;
	}
	ring_scanner_delete(pScanner);
	ring_list_deletelastitem(pVM->pRingState->pRingFilesList);
	ring_list_deletelastitem(pVM->pRingState->pRingFilesStack);
}

void ring_vm_tobytecode ( VM *pVM,int x )
{
	List *pIR  ;
	int x2  ;
	ByteCode *pByteCode  ;
	Item *pItem  ;
	pByteCode = pVM->pByteCode + x - 1 ;
	pIR = ring_list_getlist(pVM->pCode,x);
	pByteCode->nSize = ring_list_getsize(pIR) ;
	#if RING_SHOWICFINAL
	pByteCode->pList = pIR ;
	#endif
	for ( x2 = 1 ; x2 <= ring_list_getsize(pIR) ; x2++ ) {
		pItem = ring_list_getitem(pIR,x2) ;
		pByteCode->aData[x2-1] = pItem ;
	}
	/* Clear Other Items */
	for ( x2 = ring_list_getsize(pIR)+1 ; x2 <= 16 ; x2++ ) {
		pByteCode->aData[x2-1] = NULL ;
	}
}

void ring_vm_returneval ( VM *pVM )
{
	int aPara[3]  ;
	ByteCode *pByteCode  ;
	ring_vm_return(pVM);
	aPara[0] = RING_VM_IR_READIVALUE(1) ;
	aPara[1] = RING_VM_IR_READIVALUE(2) ;
	aPara[2] = RING_VM_IR_READIVALUE(3) ;
	if ( ( pVM->nRetEvalDontDelete == 0 ) && (aPara[1] == ring_list_getsize(pVM->pFunctionsMap)) && (aPara[2] == ring_list_getsize(pVM->pClassesMap)) ) {
		/*
		**  The code interpreted by eval doesn't add new functions or new classes 
		**  This means that the code can be deleted without any problems 
		**  We do that to avoid memory leaks 
		*/
		while ( ring_list_getsize(pVM->pCode) != aPara[0] ) {
			ring_list_deletelastitem(pVM->pCode);
		}
		if ( pVM->nEvalReallocationFlag == 1 ) {
			pVM->nEvalReallocationFlag = 0 ;
			pByteCode = (ByteCode *) realloc(pVM->pByteCode , sizeof(ByteCode) * ring_list_getsize(pVM->pCode));
			if ( pByteCode == NULL ) {
				printf( RING_OOM ) ;
				exit(0);
			}
			pVM->pByteCode = pByteCode ;
		}
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
}

void ring_vm_error2 ( VM *pVM,const char *cStr,const char *cStr2 )
{
	String *pError  ;
	pError = ring_string_new(cStr);
	ring_string_add(pError,": ");
	ring_string_add(pError,cStr2);
	ring_vm_error(pVM,ring_string_get(pError));
	ring_string_delete(pError);
}

void ring_vm_newbytecodeitem ( VM *pVM,int x )
{
	Item *pItem  ;
	ring_list_addint(pVM->aNewByteCodeItems,0);
	pItem = ring_list_getitem(pVM->aNewByteCodeItems,ring_list_getsize(pVM->aNewByteCodeItems));
	RING_VM_IR_ITEM(x) = pItem ;
}

RING_API void ring_vm_runcode ( VM *pVM,const char *cStr )
{
	ring_vm_mutexlock(pVM);
	pVM->nEvalCalledFromRingCode = 1 ;
	pVM->nRetEvalDontDelete = 0 ;
	ring_vm_eval(pVM,cStr);
	pVM->nEvalCalledFromRingCode = 0 ;
	ring_vm_mutexunlock(pVM);
	ring_vm_mainloop(pVM);
}

void ring_vm_init ( RingState *pRingState )
{
	Scanner *pScanner  ;
	VM *pVM  ;
	int nRunVM,nFreeFilesList = 0 ;
	/* Check file */
	if ( pRingState->pRingFilesList == NULL ) {
		pRingState->pRingFilesList = ring_list_new(0);
		pRingState->pRingFilesStack = ring_list_new(0);
		nFreeFilesList = 1 ;
	}
	ring_list_addstring(pRingState->pRingFilesList,"Ring_EmbeddedCode");
	ring_list_addstring(pRingState->pRingFilesStack,"Ring_EmbeddedCode");
	/* Read File */
	pScanner = ring_scanner_new(pRingState);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	/* Call Parser */
	nRunVM = ring_parser_start(pScanner->Tokens,pRingState);
	ring_scanner_delete(pScanner);
	/* Files List */
	ring_list_deleteitem(pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
	if ( nFreeFilesList ) {
		/* Run the Program */
		if ( nRunVM == 1 ) {
			/* Add return to the end of the program */
			ring_scanner_addreturn(pRingState);
			pVM = ring_vm_new(pRingState);
			ring_vm_start(pRingState,pVM);
			pRingState->pVM = pVM ;
		}
	}
	return ;
}

void ring_vm_retitemref ( VM *pVM )
{
	List *pList  ;
	pVM->nRetItemRef++ ;
	/* We free the stack to avoid effects on aLoadAddressScope which is used by isstackpointertoobjstate */
	ring_vm_freestack(pVM);
	/*
	**  Check if we are in the operator method to increment the counter again 
	**  We do this to avoid another PUSHV on the list item 
	**  The first one after return expression in the operator method 
	**  The second one before return from eval() that is used by operator overloading 
	**  This to avoid using & two times like  &  & 
	*/
	if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
		pList = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
		/* Using strstr() we check sub string value because the function name in the call list is long name */
		if ( strstr(ring_list_getstring(pList,RING_FUNCCL_NAME),"method operator()") == ring_list_getstring(pList,RING_FUNCCL_NAME) ) {
			pVM->nRetItemRef++ ;
		}
	}
}

void ring_vm_printstack ( VM *pVM )
{
	int x,nSP  ;
	printf( "\n*****************************************\n" ) ;
	printf( "Stack Size %d \n",pVM->nSP ) ;
	nSP = pVM->nSP ;
	if ( nSP > 0 ) {
		for ( x = 1 ; x <= nSP ; x++ ) {
			/* Print Values */
			if ( RING_VM_STACK_ISSTRING ) {
				printf( "(String) : %s  \n",RING_VM_STACK_READC ) ;
			}
			else if ( RING_VM_STACK_ISNUMBER ) {
				printf( "(Number) : %f  \n",RING_VM_STACK_READN ) ;
			}
			else if ( RING_VM_STACK_ISPOINTER ) {
				printf( "(Pointer) : %p  \n",RING_VM_STACK_READP ) ;
				if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
					printf( "(Pointer Type) : Variable \n" ) ;
					ring_list_print((List *) RING_VM_STACK_READP);
				}
				else if ( RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM ) {
					printf( "(Pointer Type) : ListItem \n" ) ;
					ring_item_print((Item *) RING_VM_STACK_READP);
				}
			}
			RING_VM_STACK_POP ;
			printf( "\n*****************************************\n" ) ;
		}
	}
}
/* Threads */

RING_API void ring_vm_mutexfunctions ( VM *pVM,void *(*pFunc)(void),void (*pFuncLock)(void *),void (*pFuncUnlock)(void *),void (*pFuncDestroy)(void *) )
{
	if ( pVM->pMutex == NULL ) {
		pVM->pMutex = pFunc() ;
		pVM->pFuncMutexLock = pFuncLock ;
		pVM->pFuncMutexUnlock = pFuncUnlock ;
		pVM->pFuncMutexDestroy = pFuncDestroy ;
	}
}

RING_API void ring_vm_mutexlock ( VM *pVM )
{
	if ( pVM->pMutex != NULL ) {
		pVM->pFuncMutexLock(pVM->pMutex);
	}
}

RING_API void ring_vm_mutexunlock ( VM *pVM )
{
	if ( pVM->pMutex != NULL ) {
		pVM->pFuncMutexUnlock(pVM->pMutex);
	}
}

RING_API void ring_vm_mutexdestroy ( VM *pVM )
{
	if ( pVM->pMutex != NULL ) {
		pVM->pFuncMutexDestroy(pVM->pMutex);
		pVM->pMutex = NULL ;
	}
}

RING_API void ring_vm_runcodefromthread ( VM *pVM,const char *cStr )
{
	RingState *pState  ;
	List *pList,*pList2,*pList3,*pList4,*pList5  ;
	Item *pItem  ;
	/* Create the RingState */
	pState = ring_state_init();
	pState->nPrintInstruction = pVM->pRingState->nPrintInstruction ;
	/* Share the same Mutex between VMs */
	ring_vm_mutexlock(pVM);
	pState->pVM->pMutex = pVM->pMutex ;
	pState->pVM->pFuncMutexDestroy = pVM->pFuncMutexDestroy ;
	pState->pVM->pFuncMutexLock = pVM->pFuncMutexLock ;
	pState->pVM->pFuncMutexUnlock = pVM->pFuncMutexUnlock ;
	/* Share the global scope between threads */
	pItem = pState->pVM->pMem->pFirst->pValue ;
	pState->pVM->pMem->pFirst->pValue = pVM->pMem->pFirst->pValue ;
	/* Save the state */
	pList = pState->pVM->pCode ;
	pList2 = pState->pVM->pFunctionsMap ;
	pList3 = pState->pVM->pClassesMap ;
	pList4 = pState->pVM->pPackagesMap ;
	pList5 = pState->pVM->pCFunctionsList ;
	/* Share the code between the VMs */
	pState->pVM->pFunctionsMap = pVM->pRingState->pRingFunctionsMap ;
	pState->pVM->pClassesMap = pVM->pRingState->pRingClassesMap ;
	pState->pVM->pPackagesMap = pVM->pRingState->pRingPackagesMap ;
	pState->pVM->pCFunctionsList = pVM->pCFunctionsList ;
	pState->pRingFunctionsMap = pVM->pRingState->pRingFunctionsMap ;
	pState->pRingClassesMap = pVM->pRingState->pRingClassesMap ;
	pState->pRingPackagesMap = pVM->pRingState->pRingPackagesMap ;
	pState->pRingCFunctions = pVM->pRingState->pRingCFunctions ;
	/* Get a copy from the byte code List */
	pState->pVM->nScopeID = pVM->nScopeID + 10000 ;
	pState->pVM->pCode = ring_list_new(0) ;
	ring_list_copy(pState->pVM->pCode,pVM->pRingState->pRingGenCode);
	pState->pRingGenCode = pState->pVM->pCode ;
	ring_vm_loadcode(pState->pVM);
	/* Avoid the call to the main function */
	pState->pVM->nCallMainFunction = 1 ;
	ring_vm_mutexunlock(pVM);
	/* Run the code */
	ring_state_runcode(pState,cStr);
	ring_list_delete(pState->pVM->pCode);
	/* Restore the first scope - global scope */
	pState->pVM->pMem->pFirst->pValue = pItem ;
	/* Avoid deleteing the shared code and the Mutex */
	pState->pVM->pCode = pList ;
	pState->pVM->pFunctionsMap = pList2 ;
	pState->pVM->pClassesMap = pList3 ;
	pState->pVM->pPackagesMap = pList4 ;
	pState->pVM->pCFunctionsList = pList5 ;
	pState->pRingGenCode = pList ;
	pState->pRingFunctionsMap = pList2 ;
	pState->pRingClassesMap = pList3 ;
	pState->pRingPackagesMap = pList4 ;
	pState->pRingCFunctions = pList5 ;
	pState->pVM->pMutex = NULL ;
	pState->pVM->pFuncMutexDestroy = NULL ;
	pState->pVM->pFuncMutexLock = NULL ;
	pState->pVM->pFuncMutexUnlock = NULL ;
	/* Delete the RingState */
	ring_state_delete(pState);
}
