/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_vm_h
#define ring_vm_h
/*
**  Data
**  Stack Size
*/
#if RING_LOWMEM
	#define RING_VM_STACK_SIZE 32
	#define RING_VM_STACK_CHECKOVERFLOW 30
	#define RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER 24
#else
	#define RING_VM_STACK_SIZE 1004
	#define RING_VM_STACK_CHECKOVERFLOW 1000
	#define RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER 100
#endif
#define RING_VM_ARGCACHE_SIZE RING_VM_STACK_SIZE
/* Mutex Data */
#define RING_VM_CUSTOMMUTEX_COUNT 5
#define RING_VM_CUSTOMMUTEX_VARHASHTABLE 0
#define RING_VM_CUSTOMMUTEX_FUNCHASHTABLE 1
#define RING_VM_CUSTOMMUTEX_ITEMREFCOUNT 2
#define RING_VM_CUSTOMMUTEX_LISTREFCOUNT 3
#define RING_VM_CUSTOMMUTEX_LNEWREF 4
#define RING_VM_BC_ITEMS_COUNT 2
#define RING_VM_MAXDIGITSINNUMBER 15
/* Check if we can use double in the byte code */
#if RING_USEDOUBLEINBYTECODE
	#define RING_BYTECODEDOUBLE double
#else
	#define RING_BYTECODEDOUBLE float
#endif
/* Register Type */
#define RING_VM_REGTYPE_INT 0
#define RING_VM_REGTYPE_DOUBLE 1
#define RING_VM_REGTYPE_STRING 2
#define RING_VM_REGTYPE_POINTER 3
#define RING_VM_REGTYPE_DEFAULT RING_VM_REGTYPE_INT
typedef union Register {
	int iNumber;
	void *pPointer;
	const char *pString;
	unsigned int uiNumber;
	RING_BYTECODEDOUBLE dNumber;
} Register;
typedef struct ByteCode {
	unsigned int nOPCode : 8;
	unsigned int lFlagReg : 1;
	unsigned int lFlagReg2 : 1;
	unsigned int lLiteral : 1;
	unsigned int lUnusedFlag : 1;
	unsigned int nReg1Type : 2;
	unsigned int nReg2Type : 2;
	unsigned int nSmallIntReg : 16;
	unsigned int nIntReg : 32;
	Register aReg[RING_VM_BC_ITEMS_COUNT];
} ByteCode;
typedef struct CFunction {
	const char *cName;
	void (*pFunc)(void *);
	struct CFunction *pNext;
} CFunction;
typedef struct FuncCall {
	const char *cName;
	const char *cFileName;
	const char *cNewFileName;
	List *pTempMem;
	void (*pFunc)(void *);
	VMState *pVMState;
	unsigned int nPC;
	unsigned int nSP;
	unsigned int nLineNumber;
	unsigned int nCallerPC;
	unsigned int nListStart;
	unsigned int nForStep;
	unsigned int nExitMark;
	unsigned int nLoopMark;
	unsigned int nCurrentGlobalScope;
	unsigned int nActiveScopeID;
	unsigned int nNestedLists;
	unsigned int nParaCount;
	unsigned int nType : 8;
	unsigned int nStatus : 8;
	unsigned int nLoadAddressScope : 8;
	unsigned int lMethod : 8;
} FuncCall;
typedef struct VM {
	RingState *pRingState;
	List *pCode;
	List *pFunctionsMap;
	List *pClassesMap;
	List *pPackagesMap;
	List *pTempMem;
	List *pNestedLists;
	List *pPCBlockFlag;
	List *pExitMark;
	List *pLoopMark;
	List *pTry;
	List *pScopeNewObj;
	List *pObjState;
	List *pBraceObject;
	List *pBraceObjects;
	List *pActiveMem;
	List *pActivePackage;
	List *pSetProperty;
	List *pForStep;
	List *pBeforeObjState;
	List *pCLibraries;
	List *pTraceData;
	List *pGlobalScopes;
	List *pActiveGlobalScopes;
	List *pDeleteLater;
	List *pDefinedGlobals;
	List *pTrackedVariables;
	String *pPackageName;
	String *pTrace;
	ByteCode *pByteCode;
	ByteCode *pByteCodeIR;
	const char *cFileName;
	const char *cPrevFileName;
	const char *cFileNameInClassRegion;
	void *pGetSetObject;
	void *pAssignment;
	void *(*pFuncMutexCreate)(void);
	void (*pFuncMutexDestroy)(void *);
	void (*pFuncMutexLock)(void *);
	void (*pFuncMutexUnlock)(void *);
	void *pMutex;
	CFunction *pCFunction;
	unsigned int nCurrentGlobalScope;
	unsigned int nOPCode;
	unsigned int nSP;
	unsigned int nLineNumber;
	unsigned int nListStart;
	unsigned int nBlockCounter;
	unsigned int nFuncSP;
	unsigned int nCurrentFuncCall;
	unsigned int nCurrentScope;
	unsigned int nVarScope;
	unsigned int nScopeID;
	unsigned int nActiveScopeID;
	unsigned int nLoadAddressScope;
	unsigned int nEvalReallocationSize;
	unsigned int nCFuncParaCount;
	unsigned int nCFuncSP;
	unsigned int nEvalReturnPC;
	unsigned int nPC;
	unsigned int nPausePC;
	unsigned int nArgCacheCount;
	unsigned int nInsideEval : 8;
	unsigned int nInClassRegion : 8;
	unsigned int nGetSetObjType : 8;
	unsigned int nBeforeEqual : 8;
	unsigned int nDecimals : 8;
	unsigned int nRetItemRef : 8;
	unsigned int nCallClassInit : 8;
	unsigned int nRunCode : 8;
	unsigned int nTraceEvent : 8;
	unsigned int nEvalInScope : 8;
	unsigned int nNoSetterMethod : 8;
	unsigned int lActiveCatch : 1;
	unsigned int lCallMainFunction : 1;
	unsigned int lCheckOverFlow : 1;
	unsigned int lExitFlag : 1;
	unsigned int lCheckBraceError : 1;
	unsigned int lSelfLoadA : 1;
	unsigned int lCallMethod : 1;
	unsigned int lInsideBraceFlag : 1;
	unsigned int lPrivateFlag : 1;
	unsigned int lGetSetProperty : 1;
	unsigned int lFirstAddress : 1;
	unsigned int lNoAssignment : 1;
	unsigned int lEvalCalledFromRingCode : 1;
	unsigned int lEvalReallocationFlag : 1;
	unsigned int lIgnoreNULL : 1;
	unsigned int lIgnoreCPointerTypeCheck : 1;
	unsigned int lRetEvalDontDelete : 1;
	unsigned int lActiveError : 1;
	unsigned int lTrace : 1;
	unsigned int lTraceActive : 1;
	unsigned int lPassError : 1;
	unsigned int lHideErrorMsg : 1;
	unsigned int lFullStringToNum : 1;
	unsigned int lSubStringToNumError : 1;
	unsigned int lOptionalLoop : 1;
	Item aStack[RING_VM_STACK_SIZE];
	FuncCall aFuncCall[RING_VM_STACK_SIZE];
	List aScopes[RING_VM_STACK_SIZE];
	List *aArgCache[RING_VM_ARGCACHE_SIZE];
	void *aCustomMutex[RING_VM_CUSTOMMUTEX_COUNT];
} VM;
/*
**  Macro & Constants
**  Stack
**  Stack Pointer
*/
#define RING_VM_SP_INC pVM->nSP++;
#define RING_VM_SP_VALUE pVM->nSP
/* Add */
#define RING_VM_STACK_PUSHC                                                                                            \
	RING_VM_SP_INC;                                                                                                \
	ring_itemarray_setstring_gc(pVM->pRingState, pVM->aStack, pVM->nSP, pVM->pByteCodeIR->aReg[0].pString)
#define RING_VM_STACK_PUSHNL                                                                                           \
	RING_VM_SP_INC;                                                                                                \
	ring_itemarray_setstring_gc(pVM->pRingState, pVM->aStack, pVM->nSP, "\n")
#define RING_VM_STACK_PUSHN                                                                                            \
	RING_VM_SP_INC;                                                                                                \
	ring_itemarray_setdouble_gc(pVM->pRingState, pVM->aStack, pVM->nSP, pVM->pByteCodeIR->aReg[0].dNumber)
#define RING_VM_STACK_PUSHP                                                                                            \
	RING_VM_SP_INC;                                                                                                \
	ring_itemarray_setpointer_gc(pVM->pRingState, pVM->aStack, pVM->nSP, pVM->pByteCodeIR->aReg[0].pPointer)
/* Note, use RING_VM_STACK_OBJTYPE to read/write the pointer type */
#define RING_VM_STACK_TRUE ring_itemarray_setdouble_gc(pVM->pRingState, pVM->aStack, pVM->nSP, 1)
#define RING_VM_STACK_FALSE ring_itemarray_setdouble_gc(pVM->pRingState, pVM->aStack, pVM->nSP, 0)
#define RING_VM_STACK_PUSHCVAR                                                                                         \
	ring_itemarray_setstring2_gc(pVM->pRingState, pVM->aStack, pVM->nSP,                                           \
				     ring_list_getstring(pVar, RING_VAR_VALUE),                                        \
				     ring_list_getstringsize(pVar, RING_VAR_VALUE))
#define RING_VM_STACK_PUSHNVAR                                                                                         \
	ring_itemarray_setdouble_gc(pVM->pRingState, pVM->aStack, pVM->nSP, ring_list_getdouble(pVar, RING_VAR_VALUE))
#define RING_VM_STACK_PUSHPVALUE(pPointer)                                                                             \
	RING_VM_SP_INC;                                                                                                \
	ring_itemarray_setpointer_gc(pVM->pRingState, pVM->aStack, pVM->nSP, pPointer)
#define RING_VM_STACK_PUSHCVALUE(cString)                                                                              \
	RING_VM_SP_INC;                                                                                                \
	ring_itemarray_setstring_gc(pVM->pRingState, pVM->aStack, pVM->nSP, cString)
#define RING_VM_STACK_PUSHNVALUE(nNumber)                                                                              \
	RING_VM_SP_INC;                                                                                                \
	ring_itemarray_setdouble_gc(pVM->pRingState, pVM->aStack, pVM->nSP, nNumber)
#define RING_VM_STACK_SETCVALUE(cString) ring_itemarray_setstring_gc(pVM->pRingState, pVM->aStack, pVM->nSP, cString)
#define RING_VM_STACK_SETNVALUE(nNumber) ring_itemarray_setdouble_gc(pVM->pRingState, pVM->aStack, pVM->nSP, nNumber)
#define RING_VM_STACK_SETPVALUE(pPointer) ring_itemarray_setpointer_gc(pVM->pRingState, pVM->aStack, pVM->nSP, pPointer)
#define RING_VM_STACK_SETCVALUE2(cString, nSize)                                                                       \
	ring_itemarray_setstring2_gc(pVM->pRingState, pVM->aStack, pVM->nSP, cString, nSize)
#define RING_VM_STACK_SETCSIZE(nSize) ring_itemarray_setstring2_gc(pVM->pRingState, pVM->aStack, pVM->nSP, NULL, nSize)
#define RING_VM_STACK_PUSHCVALUE2(cString, nSize)                                                                      \
	RING_VM_SP_INC;                                                                                                \
	ring_itemarray_setstring2_gc(pVM->pRingState, pVM->aStack, pVM->nSP, cString, nSize)
#define RING_VM_STACK_SETPVALUEAT(nIndex, pPointer)                                                                    \
	ring_itemarray_setpointer_gc(pVM->pRingState, pVM->aStack, nIndex, pPointer)
/* Check */
#define RING_VM_STACK_ISSTRING ring_itemarray_isstring(pVM->aStack, pVM->nSP)
#define RING_VM_STACK_ISNUMBER ring_itemarray_isnumber(pVM->aStack, pVM->nSP)
#define RING_VM_STACK_ISPOINTER ring_itemarray_ispointer(pVM->aStack, pVM->nSP)
#define RING_VM_STACK_PREVISPOINTER ring_itemarray_ispointer(pVM->aStack, pVM->nSP - 1)
#define RING_VM_STACK_ISSTRINGVALUE(nIndex) ring_itemarray_isstring(pVM->aStack, nIndex)
#define RING_VM_STACK_ISNUMBERVALUE(nIndex) ring_itemarray_isnumber(pVM->aStack, nIndex)
#define RING_VM_STACK_ISPOINTERVALUE(nIndex) ring_itemarray_ispointer(pVM->aStack, nIndex)
/* Read */
#define RING_VM_STACK_READC ring_itemarray_getstring(pVM->aStack, pVM->nSP)
#define RING_VM_STACK_GETSTRINGRAW ring_itemarray_getstringraw(pVM->aStack, pVM->nSP)
#define RING_VM_STACK_STRINGSIZE ring_itemarray_getstringsize(pVM->aStack, pVM->nSP)
#define RING_VM_STACK_READN ring_itemarray_getdouble(pVM->aStack, pVM->nSP)
#define RING_VM_STACK_READP ring_itemarray_getpointer(pVM->aStack, pVM->nSP)
#define RING_VM_STACK_OBJTYPE pVM->aStack[pVM->nSP].nObjectType
#define RING_VM_STACK_ASSIGNMENTFLAG pVM->aStack[pVM->nSP].lAssignment
#define RING_VM_STACK_PREVOBJTYPE pVM->aStack[pVM->nSP - 1].nObjectType
#define RING_VM_STACK_READCVALUE(nIndex) ring_itemarray_getstring(pVM->aStack, nIndex)
#define RING_VM_STACK_STRINGSIZEVALUE(nIndex) ring_itemarray_getstringsize(pVM->aStack, nIndex)
#define RING_VM_STACK_READNVALUE(nIndex) ring_itemarray_getdouble(pVM->aStack, nIndex)
#define RING_VM_STACK_READPVALUE(nIndex) ring_itemarray_getpointer(pVM->aStack, nIndex)
#define RING_VM_STACK_OBJTYPEVALUE(nIndex) pVM->aStack[nIndex].nObjectType
#define RING_VM_STACK_ISASSIGNMENTDEST ((pVM->pAssignment == RING_VM_STACK_READP) && RING_VM_STACK_ASSIGNMENTFLAG)
/* Delete */
#define RING_VM_STACK_POP pVM->nSP--
/* Objects/Pointer  - Type */
#define RING_OBJTYPE_NOTYPE 0
#define RING_OBJTYPE_VARIABLE 1
#define RING_OBJTYPE_LISTITEM 2
#define RING_OBJTYPE_SUBSTRING 3
/* Variable Structure */
#define RING_VAR_LISTSIZE 5
#define RING_VAR_NAME 1
#define RING_VAR_TYPE 2
#define RING_VAR_VALUE 3
#define RING_VAR_PVALUETYPE 4
#define RING_VAR_PRIVATEFLAG 5
/* Global variable position */
#define RING_GLOBALVARPOS_GETTEMPVAR 5
#define RING_GLOBALVARPOS_ERRORMSG 6
#define RING_GLOBALVARPOS_SETTEMPVAR 7
#define RING_GLOBALVARPOS_THIS 11
#define RING_GLOBALVARPOS_OPTIONALFUNCTIONS 15
/* Variable Type */
#define RING_VM_NULL 0
#define RING_VM_STRING 1
#define RING_VM_NUMBER 2
#define RING_VM_LIST 3
#define RING_VM_POINTER 4
/* Instructions */
#define RING_VM_INSTRUCTIONSCOUNT pVM->pRingState->nInstructionsCount
#define RING_VM_INSTRUCTIONSLISTSIZE ring_list_getsize(pVM->pRingState->pRingGenCode)
#define RING_VM_DELETELASTINSTRUCTION                                                                                  \
	ring_vm_deletebytecode(pVM, RING_VM_INSTRUCTIONSCOUNT);                                                        \
	pVM->pRingState->nInstructionsCount--
/* IR (Instruction Register) */
#define RING_VM_JUMP pVM->nPC = pVM->pByteCodeIR->aReg[0].iNumber
#define RING_VM_IR_READC pVM->pByteCodeIR->aReg[0].pString
#define RING_VM_IR_READCVALUE(nReg) pVM->pByteCodeIR->aReg[nReg].pString
#define RING_VM_IR_READP pVM->pByteCodeIR->aReg[0].pPointer
#define RING_VM_IR_READPVALUE(nReg) pVM->pByteCodeIR->aReg[nReg].pPointer
#define RING_VM_IR_READI pVM->pByteCodeIR->aReg[0].iNumber
#define RING_VM_IR_READIVALUE(nReg) pVM->pByteCodeIR->aReg[nReg].iNumber
#define RING_VM_IR_READUIVALUE(nReg) pVM->pByteCodeIR->aReg[nReg].uiNumber
#define RING_VM_IR_READD pVM->pByteCodeIR->aReg[0].dNumber
#define RING_VM_IR_READDVALUE(nReg) pVM->pByteCodeIR->aReg[nReg].dNumber
#define RING_VM_IR_OPCODE pVM->pByteCodeIR->nOPCode
#define RING_VM_IR_OPCODEVALUE(nIns) (pVM->pByteCode + nIns)->nOPCode
#define RING_VM_IR_ITEM(nReg) &(pVM->pByteCodeIR->aReg[nReg])
#define RING_VM_IR_LOAD pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1
#define RING_VM_IR_UNLOAD pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 2
#define RING_VM_IR_GETLINENUMBER pVM->nLineNumber
#define RING_VM_IR_SETLINENUMBER(nLine) pVM->nLineNumber = nLine
#define RING_VM_IR_ITEMSETINT(pItem, nValue) (*pItem).iNumber = nValue
#define RING_VM_IR_ITEMSETPOINTER(pItem, pPtr) (*pItem).pPointer = pPtr
#define RING_VM_IR_ITEMTYPE Register
#define RING_VM_IR_ITEMATINS(nIns, nReg) &((pVM->pByteCode + nIns)->aReg[nReg])
#define RING_VM_PC_CURRENTINS pVM->nPC - 2
#define RING_VM_PC_PREVINS pVM->nPC - 3
#define RING_VM_IR_CLEARREG1STRING ring_vm_clearregisterstring(pVM, RING_VM_IR_REG1)
#define RING_VM_PUSHNULLTHENJUMP                                                                                       \
	RING_VM_STACK_PUSHCVALUE(RING_CSTR_EMPTY);                                                                     \
	RING_VM_JUMP
#define RING_VM_IR_SETINTREG(nValue) pVM->pByteCodeIR->nIntReg = nValue
#define RING_VM_IR_GETINTREG pVM->pByteCodeIR->nIntReg
#define RING_VM_IR_SETFLAGREG(nValue) pVM->pByteCodeIR->lFlagReg = nValue
#define RING_VM_IR_GETFLAGREG pVM->pByteCodeIR->lFlagReg
#define RING_VM_IR_SETREG1TOPOINTERFROMSTACK ring_vm_setreg1topointerfromstack(pVM)
#define RING_VM_IR_SETREG1TYPE(nType) pVM->pByteCodeIR->nReg1Type = nType
#define RING_VM_IR_SETREG2TYPE(nType) pVM->pByteCodeIR->nReg2Type = nType
#define RING_VM_IR_REG1 0
#define RING_VM_IR_REG2 1
#define RING_VM_IR_SETFLAGREG2(nValue) pVM->pByteCodeIR->lFlagReg2 = nValue
#define RING_VM_IR_GETFLAGREG2 pVM->pByteCodeIR->lFlagReg2
#define RING_VM_IR_SETSMALLINTREG(nValue) pVM->pByteCodeIR->nSmallIntReg = nValue
#define RING_VM_IR_GETSMALLINTREG pVM->pByteCodeIR->nSmallIntReg
#define RING_VM_IR_SETINTREGATINS(nIns, nValue) (pVM->pByteCode + nIns)->nIntReg = nValue
#define RING_VM_IR_INTATINS(nIns) (pVM->pByteCode + nIns)->nIntReg
#define RING_VM_PUSHNTHENJUMP                                                                                          \
	RING_VM_STACK_PUSHN;                                                                                           \
	pVM->nPC = pVM->pByteCodeIR->aReg[1].iNumber
/*
**  Calling Functions
**  Note : When you insert items check performance functions for update too!
**  Function Call List ( Type, Func Name , Position(PC) , Stack Pointer , TempMem, ...
**  Types
*/
#define RING_FUNCTYPE_SCRIPT 0
#define RING_FUNCTYPE_C 1
/* Status */
#define RING_FUNCSTATUS_LOAD 0
#define RING_FUNCSTATUS_CALL 1
#define RING_FUNCSTATUS_STARTED 2
/* Util */
#define RING_VM_LASTOBJSTATE pVM->pObjState->pLast->pValue->data.pList->pFirst->pValue->data.pPointer
#define RING_VM_LASTFUNCCALL &(pVM->aFuncCall[pVM->nCurrentFuncCall])
#define RING_VM_GETFUNCCALL(x) &(pVM->aFuncCall[x])
#define RING_VM_FUNCCALLSCOUNT pVM->nCurrentFuncCall
#define RING_VM_DELETELASTFUNCCALL                                                                                     \
	ring_vm_funccalldelete(pVM->pRingState, RING_VM_LASTFUNCCALL);                                                 \
	pVM->nCurrentFuncCall--
#define RING_VM_BACKTOFUNCCALL(x)                                                                                      \
	while (RING_VM_FUNCCALLSCOUNT > x) {                                                                           \
		RING_VM_DELETELASTFUNCCALL;                                                                            \
	}
/* Parameters */
#define RING_FUNCPARA_EXPECTEDSIZE 32
/* pFunctionsMap ( Func Name , Position , File Name, Private Flag) */
#define RING_FUNCMAP_NAME 1
#define RING_FUNCMAP_PC 2
#define RING_FUNCMAP_FILENAME 3
#define RING_FUNCMAP_PRIVATEFLAG 4
/* FunctionMap List Size */
#define RING_FUNCMAP_NORMALSIZE 4
/* Variable Scope */
#define RING_VM_SMALLLISTSIZE 6
#define RING_VARSCOPE_NOTHING 0
#define RING_VARSCOPE_LOCAL 1
#define RING_VARSCOPE_OBJSTATE 2
#define RING_VARSCOPE_DEFINEDGLOBALS 3
#define RING_VARSCOPE_GLOBAL 4
#define RING_VARSCOPE_NEWOBJSTATE 5
#define RING_VARSCOPE_SIZETOUSEHASHTABLE RING_VM_SMALLLISTSIZE
/* Util */
#define RING_VM_SCOPESCOUNT pVM->nCurrentScope
#define RING_VM_GETLASTSCOPE &(pVM->aScopes[pVM->nCurrentScope])
#define RING_VM_GETSCOPE(x) &(pVM->aScopes[x])
#define RING_VM_NEWSCOPE RING_VM_GETSCOPE(++(pVM->nCurrentScope))
#define RING_VM_DELETELASTSCOPE                                                                                        \
	ring_list_deleteallitems_gc(pVM->pRingState, RING_VM_GETLASTSCOPE);                                            \
	pVM->nCurrentScope--
#define RING_VM_BACKTOSCOPELIST(x)                                                                                     \
	while (RING_VM_GETLASTSCOPE != x)                                                                              \
		ring_vm_deletescope(pVM);
#define RING_VM_COPYSCOPESTOLIST(x) ring_vm_copyscopestolist(pVM, x)
#define RING_SHAREDSCOPETYPE List *
#define RING_VM_SAVEGLOBALSCOPE(x) &(x->aScopes[1])
#define RING_VM_RESTOREGLOBALSCOPE(x, y) x->aScopes[1] = *y
#define RING_VM_SHAREGLOBALSCOPE(dest, src) dest->aScopes[1] = src->aScopes[1]
#define RING_VM_SETCURRENTSCOPE(x) pVM->nCurrentScope = x;
/* State */
#define RING_STATE_TRYCATCH 1
#define RING_STATE_EXIT 2
#define RING_STATE_RETURN 3
/* Memory */
#define RING_MEMORY_GLOBALSCOPE 1
/* Lists & List as Hash */
#define RING_LISTHASH_KEY 1
#define RING_LISTHASH_VALUE 2
#define RING_LISTHASH_SIZE 2
#define RING_LIST_CHECKOPERATIONONSUBLIST (ring_vm_isoperationaftersublist(pVM))
/* C Pointer List (inside Variable Value) */
#define RING_CPOINTER_POINTER 1
#define RING_CPOINTER_TYPE 2
#define RING_CPOINTER_STATUS 3
#define RING_CPOINTER_LISTSIZE 3
/* C Pointer Status */
#define RING_CPOINTERSTATUS_NOTCOPIED 0
#define RING_CPOINTERSTATUS_COPIED 1
#define RING_CPOINTERSTATUS_NOTASSIGNED 2
/* Temp Object */
#define RING_TEMP_VAR "ring_sys_tempvar"
#define RING_TEMP_REF "ring_sys_tempref"
/* Trace */
#define RING_VM_TRACEEVENT_NEWLINE 1
#define RING_VM_TRACEEVENT_NEWFUNC 2
#define RING_VM_TRACEEVENT_RETURN 3
#define RING_VM_TRACEEVENT_ERROR 4
#define RING_VM_TRACEEVENT_BEFORECFUNC 5
#define RING_VM_TRACEEVENT_AFTERCFUNC 6
#define RING_VM_TRACEEVENT(cEvent)                                                                                     \
	if (pVM->lTrace)                                                                                               \
		ring_vm_traceevent(pVM, cEvent);
/* Loops */
#define RING_COMMANDTYPE_EXIT 1
#define RING_COMMANDTYPE_LOOP 2
/* Check NULL */
#define RING_CHECKNULL_SHOWERROR 1
#define RING_CHECKNULL_NOERROR 0
/* EVAL Output */
#define RING_EVALOUTPUT_NULL 0
#define RING_EVALOUTPUT_NUMBER 1
#define RING_EVALOUTPUT_STRING 2
#define RING_EVALOUTPUT_POINTER 3
/* Temp Lists */
#define RING_VM_TEMPLISTSCOUNTERMAX 4
#define RING_TEMPLIST_SIZE 2
#define RING_TEMPLIST_PC 1
#define RING_TEMPLIST_LIST 2
/* Threads */
#define RING_VM_ITEMSFORNEWTHREAD 100000
/* pPCBlockFlag */
#define RING_PCBLOCKFLAG_PC 1
#define RING_PCBLOCKFLAG_EXITMARK 2
#define RING_PCBLOCKFLAG_LOOPMARK 3
#define RING_PCBLOCKFLAG_TRY 4
/* pTry */
#define RING_TRY_PC 1
#define RING_TRY_INSIDEEVAL 2
#define RING_TRY_STATE 3
#define RING_VM_RETURNIFACTIVECATCH                                                                                    \
	if (pVM->lActiveCatch)                                                                                         \
		return;
/* ExitMark/LoopMark */
#define RING_MARKLIST_PC 1
#define RING_MARKLIST_STATE 2
/* C Strings */
#define RING_CSTR_EMBEDDEDCODE "Ring_EmbeddedCode"
#define RING_CSTR_EVAL "eval"
/* Decimals */
#define RING_DECIMALS_COUNT 2
#define RING_VM_CHECKOVERFLOW(nNum1, nNum2)                                                                            \
	if (pVM->lCheckOverFlow && ring_vm_checkoverflow(pVM, nNum1, nNum2))                                           \
		return;
/* Extra Byte Code Generation */
#define RING_VM_BYTECODE_START List *pByteCodeIns;
#define RING_VM_BYTECODE_END ring_vm_useextrabytecode(pVM);
#define RING_VM_BYTECODE_INS(x)                                                                                        \
	pByteCodeIns = ring_list_newlist_gc(pVM->pRingState, pVM->pCode);                                              \
	ring_list_addint_gc(pVM->pRingState, pByteCodeIns, x);
#define RING_VM_BYTECODE_INSINT(x, y)                                                                                  \
	RING_VM_BYTECODE_INS(x);                                                                                       \
	ring_list_addint_gc(pVM->pRingState, pByteCodeIns, y);
#define RING_VM_BYTECODE_INSINTINT(x, y, z)                                                                            \
	RING_VM_BYTECODE_INSINT(x, y);                                                                                 \
	ring_list_addint_gc(pVM->pRingState, pByteCodeIns, z);
#define RING_VM_BYTECODE_INSSTR(x, y)                                                                                  \
	RING_VM_BYTECODE_INS(x);                                                                                       \
	ring_list_addstring_gc(pVM->pRingState, pByteCodeIns, y);
/* Runtime Error Messages */
#define RING_VM_ERROR_DIVIDEBYZERO "Error (R1) : Can't divide by zero"
#define RING_VM_ERROR_INDEXOUTOFRANGE "Error (R2) : Array Access (Index out of range)"
#define RING_VM_ERROR_FUNCNOTFOUND "Error (R3) : Calling Function without definition"
#define RING_VM_ERROR_STACKOVERFLOW "Error (R4) : Stack Overflow"
#define RING_VM_ERROR_OBJECTISNOTLIST "Error (R5) : Can't access the list item, Object is not list"
#define RING_VM_ERROR_NOTVARIABLE "Error (R6) : Variable is required"
#define RING_VM_ERROR_VALUEMORETHANONECHAR "Error (R7) : Can't assign to a string letter more than one character"
#define RING_VM_ERROR_VARISNOTSTRING "Error (R8) : Variable is not a string"
#define RING_VM_ERROR_EXITWITHOUTLOOP "Error (R9) : Using exit command outside loops"
#define RING_VM_ERROR_EXITNUMBEROUTSIDERANGE "Error (R10) : Using exit command with number outside the range"
#define RING_VM_ERROR_CLASSNOTFOUND "Error (R11) : Error in class name, class not found"
#define RING_VM_ERROR_PROPERTYNOTFOUND "Error (R12) : Error in property name, property not found"
#define RING_VM_ERROR_NOTOBJECT "Error (R13) : Object is required"
#define RING_VM_ERROR_METHODNOTFOUND "Error (R14) : Calling Method without definition"
#define RING_VM_ERROR_PARENTCLASSNOTFOUND "Error (R15) : Error in parent class name, class not found"
#define RING_VM_ERROR_BRACEWITHOUTOBJECT "Error (R16) : Using braces to access unknown object"
#define RING_VM_ERROR_SUPERCLASSNOTFOUND "Error (R17) : Error, using 'Super' without parent class"
#define RING_VM_ERROR_NUMERICOVERFLOW "Error (R18) : Numeric Overflow"
#define RING_VM_ERROR_LESSPARAMETERSCOUNT "Error (R19) : Calling function with less number of parameters"
#define RING_VM_ERROR_EXTRAPARAMETERSCOUNT "Error (R20) : Calling function with extra number of parameters"
#define RING_VM_ERROR_BADVALUES "Error (R21) : Using operator with values of incorrect type"
#define RING_VM_ERROR_LOOPWITHOUTLOOP "Error (R22) : Using loop command outside loops"
#define RING_VM_ERROR_LOOPNUMBEROUTSIDERANGE "Error (R23) : Using loop command with number outside the range"
#define RING_VM_ERROR_USINGNULLVARIABLE "Error (R24) : Using uninitialized variable"
#define RING_VM_ERROR_PACKAGENOTFOUND "Error (R25) : Error in package name, Package not found"
#define RING_VM_ERROR_CALLINGPRIVATEMETHOD "Error (R26) : Calling private method from outside the class"
#define RING_VM_ERROR_USINGPRIVATEATTRIBUTE "Error (R27) : Using private attribute from outside the class"
#define RING_VM_ERROR_FORSTEPDATATYPE "Error (R28) : Using bad data type as step value"
#define RING_VM_ERROR_FORLOOPDATATYPE "Error (R29) : Using bad data type in for loop"
#define RING_VM_ERROR_PARENTCLASSLIKESUBCLASS "Error (R30) : Parent class name is identical to child class name"
#define RING_VM_ERROR_TRYINGTOMODIFYTHESELFPOINTER "Error (R31) : Trying to destroy the object using the self reference"
#define RING_VM_ERROR_BADCALLPARA "Error (R32) : The CALL command expect a variable contains string"
#define RING_VM_ERROR_BADDECIMALNUMBER "Error (R33) : Bad decimals number (correct range >= 0 and <= 90)"
#define RING_VM_ERROR_ASSIGNNOTVARIABLE "Error (R34) : Variable is required for the assignment operation"
#define RING_VM_ERROR_CANTOPENFILE "Error (R35) : Can't create/open the file"
#define RING_VM_ERROR_BADCOLUMNNUMBER                                                                                  \
	"Error (R36) : The column number is not correct! It's greater than the number of columns in the list"
#define RING_VM_ERROR_BADCOMMAND "Error (R37) : Sorry, The command is not supported in this context"
#define RING_VM_ERROR_LIBLOADERROR "Error (R38) : Runtime Error in loading the dynamic library"
#define RING_VM_ERROR_TEMPFILENAME "Error (R39) : Error occurred creating unique filename."
#define RING_VM_ERROR_NUMERICUNDERFLOW "Error (R40) : Numeric underflow"
#define RING_VM_ERROR_NUMERICINVALID "Error (R41) : Invalid numeric string"
#define RING_VM_ERROR_EVAL "Error (R42) : Error in eval() function"
#define RING_VM_ERROR_PROTECTEDVALUE "Error (R43) : The variable contains a protected value"
#define RING_VM_ERROR_MAXNESTEDEVAL "Error (R44) : Maximum nested Eval()"
#define RING_VM_ERROR_VARISNOTLIST "Error (R45) : Variable is not a list"
#define RING_VM_ERROR_NORINGLIBINIT "Error (R46) : The dynamic library doesn't contain the ringlib_init() function!"
#define RING_VM_ERROR_FUNCNOTSUPPORTED "Error (R47) : The function is not supported in this platform"
#define RING_VM_ERROR_ASSERTIONFAILED "Error (R48) : Assertion Failed!"
#define RING_VM_ERROR_VMISNOTREADY "Error (R49) : The Ring VM is not created/ready"
#define RING_VM_ERROR_NOOPERATORMETHOD "Error (R50) : Object does not support operator overloading"
#define RING_VM_ERROR_VALUEERROR "Error (R51) : Value Error"
#define RING_VM_ERROR_RETURNINPARA "Error (R52) : Using Return inside function parameters is not allowed"
#define RING_VM_ERROR_FUNCREDEFINE "Error (R53) : Function redefinition, function is already defined!"
#define RING_VM_ERROR_ATTRREDEFINE "Error (R54) : Object attribute redefinition, attribute is already defined!"
/* Extra Size (for eval) */
#define RING_VM_EXTRASIZE (1024 * 128)
#define RING_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define RING_VM_MAXNESTEDEVAL 255
/*
**  Functions
**  Main
*/

VM *ring_vm_new(RingState *pRingState);

VM *ring_vm_delete(VM *pVM);

RING_API void ring_vm_loadcode(VM *pVM);

void ring_vm_start(RingState *pRingState, VM *pVM);

void ring_vm_towardsmainloop(RingState *pRingState);

RING_API void ring_vm_fetch(VM *pVM);

RING_API void ring_vm_fetch2(VM *pVM);

void ring_vm_execute(VM *pVM);

RING_API void ring_vm_error(VM *pVM, const char *cStr);

void ring_vm_error2(VM *pVM, const char *cStr, const char *cStr2);

RING_API void ring_vm_shutdown(VM *pVM, int nExitCode);

int ring_vm_eval(VM *pVM, const char *cStr);

void ring_vm_tobytecode(VM *pVM, int nIns);

void ring_vm_deletebytecode(VM *pVM, int nIns);

void ring_vm_mainloop(VM *pVM);

RING_API void ring_vm_runcode(VM *pVM, const char *cStr);

void ring_vm_init(RingState *pRingState);

void ring_vm_printstack(VM *pVM);

RING_API void ring_vm_showerrormessage(VM *pVM, const char *cStr);

void ring_vm_addglobalvariables(VM *pVM);

void ring_vm_mainloopforeval(VM *pVM);

void ring_vm_clearregisterstring(VM *pVM, int nReg);

void ring_vm_setreg1topointerfromstack(VM *pVM);

RING_API void ring_vm_showbytecode(VM *pVM);

void ring_vm_defragmentation(RingState *pRingState, VM *pVM);

void ring_vm_updateclassespointers(RingState *pRingState);

void ring_vm_bytecode2list(VM *pVM, List *pOutput);

void ring_vm_useextrabytecode(VM *pVM);

void ring_vm_afterscopeidoverflow(VM *pVM);

void ring_vm_deletecfunctions(VM *pVM);

void ring_vm_deleteallbytecode(VM *pVM);
/* Stack and Variables */

void ring_vm_pushv(VM *pVM);

void ring_vm_loadaddress(VM *pVM);

void ring_vm_assignment(VM *pVM);

void ring_vm_inc(VM *pVM);

void ring_vm_loadapushv(VM *pVM);

void ring_vm_newline(VM *pVM);

void ring_vm_freestack(VM *pVM);

void ring_vm_setreference(VM *pVM);

void ring_vm_beforeequallist(VM *pVM, List *pVar, double nNum1, int nBeforeEqual);

void ring_vm_beforeequalitem(VM *pVM, Item *pItem, double nNum1, int nBeforeEqual);

void ring_vm_assignmentpointer(VM *pVM);

void ring_vm_freeloadaddressscope(VM *pVM);

void ring_vm_setfilename(VM *pVM);

void ring_vm_loadaddressfirst(VM *pVM);

void ring_vm_varpushv(VM *pVM);

unsigned int ring_vm_checknull(VM *pVM, int lShowError);

void ring_vm_pushvfreestack(VM *pVM);

void ring_vm_stackswap(VM *pVM, int nSP1, int nSP2);

unsigned int ring_vm_varcontainsobjhaveoperatormethod(VM *pVM, List *pVar);

unsigned int ring_vm_itemcontainsobjhaveoperatormethod(VM *pVM, Item *pItem);
/* Compare */

void ring_vm_equal(VM *pVM);

void ring_vm_lessequal(VM *pVM);

void ring_vm_less(VM *pVM);

void ring_vm_greater(VM *pVM);

void ring_vm_greaterequal(VM *pVM);

void ring_vm_notequal(VM *pVM);
/* Math */

void ring_vm_sum(VM *pVM);

void ring_vm_sub(VM *pVM);

void ring_vm_mul(VM *pVM);

void ring_vm_div(VM *pVM);

void ring_vm_mod(VM *pVM);

void ring_vm_neg(VM *pVM);

void ring_vm_exprppoo(VM *pVM, const char *cStr);

void ring_vm_exprnpoo(VM *pVM, const char *cStr, double nNum1);

void ring_vm_exprspoo(VM *pVM, const char *cStr, const char *cStr2, unsigned int nStrSize);

void ring_vm_plusplus(VM *pVM);

void ring_vm_minusminus(VM *pVM);

void ring_vm_pow(VM *pVM);

void ring_vm_addlisttolist(VM *pVM, List *pList, List *pList2);

int ring_vm_checkoverflow(VM *pVM, double nNum1, double nNum2);

RING_API char *ring_vm_numtostring(VM *pVM, double nNum1, char *cStr);

RING_API double ring_vm_stringtonum(VM *pVM, const char *cStr);
/* Logic */

void ring_vm_and(VM *pVM);

void ring_vm_or(VM *pVM);

void ring_vm_not(VM *pVM);

int ring_vm_stringtologicvalue(VM *pVM, const char *cStr);

int ring_vm_listtologicvalue(VM *pVM, List *pList);
/* Variables */

unsigned int ring_vm_newscope(VM *pVM);

void ring_vm_deletescope(VM *pVM);

unsigned int ring_vm_findvar(VM *pVM, const char *cStr);

unsigned int ring_vm_findvar2(VM *pVM, unsigned int nLevel, List *pList2, const char *cStr);

void ring_vm_newvar(VM *pVM, const char *cStr);

List *ring_vm_newvar2(VM *pVM, const char *cStr, List *pParent);

void ring_vm_addnewnumbervar(VM *pVM, const char *cStr, double nNumber);

void ring_vm_addnewstringvar(VM *pVM, const char *cStr, const char *cStr2);

void ring_vm_addnewpointervar(VM *pVM, const char *cStr, void *pPointer, unsigned int nType);

List *ring_vm_addnewlistvar(VM *pVM, const char *cStr);

void ring_vm_newtempvar(VM *pVM, const char *cStr, List *pTempList);

void ring_vm_addnewstringvar2(VM *pVM, const char *cStr, const char *cStr2, unsigned int nStrSize);

void ring_vm_addnewcpointervar(VM *pVM, const char *cStr, void *pPointer, const char *cStr2);

void ring_vm_setvarprivateflag(VM *pVM, List *pVar, unsigned int nFlag);

unsigned int ring_vm_getvarprivateflag(VM *pVM, List *pVar);

void ring_vm_copyscopestolist(VM *pVM, List *pList);

void ring_vm_addvarpointertoscopehash(VM *pVM, List *pParent, const char *cVar, List *pList);

unsigned int ring_vm_notusingvarduringdef(VM *pVM);
/* Parameters */

void ring_vm_newargcache(VM *pVM);

void ring_vm_deleteargcache(VM *pVM);

List *ring_vm_addstringarg(VM *pVM, const char *cVar, const char *cStr, unsigned int nStrSize);

List *ring_vm_addnumberarg(VM *pVM, const char *cVar, double nNumber);

List *ring_vm_addpointerarg(VM *pVM, const char *cVar, void *pPointer, unsigned int nType);

List *ring_vm_addlistarg(VM *pVM, const char *cVar);
/* Jump */

void ring_vm_jumpzero(VM *pVM);

void ring_vm_jumpfor(VM *pVM);

void ring_vm_jumpone(VM *pVM);

void ring_vm_jumpzero2(VM *pVM);

void ring_vm_jumpone2(VM *pVM);
/* Lists */

void ring_vm_newnestedlists(VM *pVM);

void ring_vm_restorenestedlists(VM *pVM, unsigned int nListStart, unsigned int nNestedLists);

void ring_vm_liststart(VM *pVM);

void ring_vm_listitem(VM *pVM);

void ring_vm_listitemn(VM *pVM);

void ring_vm_listitemc(VM *pVM);

void ring_vm_listend(VM *pVM);

void ring_vm_loadindexaddress(VM *pVM);

void ring_vm_listpushv(VM *pVM);

void ring_vm_listassignment(VM *pVM, unsigned int nBeforeEqual);

void ring_vm_listgetvalue(VM *pVM, List *pVar, const char *cStr);

unsigned int ring_vm_isoperationaftersublist(VM *pVM);

void ring_vm_listcopy(VM *pVM, List *pNewList, List *pList);
/* Functions */

int ring_vm_loadfunc(VM *pVM);

RING_API int ring_vm_loadfunc2(VM *pVM, const char *cStr, int nPerformance);

void ring_vm_call(VM *pVM);

RING_API void ring_vm_call2(VM *pVM);

void ring_vm_preparecallmethod(VM *pVM);

void ring_vm_return(VM *pVM);

void ring_vm_returnnull(VM *pVM);

void ring_vm_returnn(VM *pVM);

void ring_vm_returneval(VM *pVM);

void ring_vm_newfunc(VM *pVM);

void ring_vm_blockflag(VM *pVM);

void ring_vm_blockflag2(VM *pVM, int nPC);

void ring_vm_removeblockflag(VM *pVM);

void ring_vm_movetoprevscope(VM *pVM);

void ring_vm_createtemplist(VM *pVM);

void ring_vm_anonymous(VM *pVM);

unsigned int ring_vm_isstackpointertoobjstate(VM *pVM);

void ring_vm_retitemref(VM *pVM);

List *ring_vm_prevtempmem(VM *pVM);

void ring_vm_cleanevalcode(VM *pVM, unsigned int nCodeSize);

FuncCall *ring_vm_funccallnew(VM *pVM);

void ring_vm_funccalldelete(void *pState, void *pMemory);

void ring_vm_funccalluseloadfuncp(VM *pVM, FuncCall *pFuncCall, int nPerformance);

int ring_vm_funccallbeforecall(VM *pVM);

unsigned int ring_vm_funccallparacount(VM *pVM);

void ring_vm_newscopeid(VM *pVM);

void ring_vm_optionalfunc(void *pPointer);
/* String As Array */

void ring_vm_stringpushv(VM *pVM);

void ring_vm_stringassignment(VM *pVM);

void ring_vm_stringindex(VM *pVM, String *pString, double x);
/* Try Catch Done */

void ring_vm_try(VM *pVM);

void ring_vm_catch(VM *pVM, const char *cError);

void ring_vm_done(VM *pVM);
/* Duplicate and Range */

void ring_vm_stackdup(VM *pVM);

void ring_vm_range(VM *pVM);

List *ring_vm_rangenewlist(VM *pVM);
/* Faster instructions */

void ring_vm_pushp(VM *pVM);

void ring_vm_incp(VM *pVM);

void ring_vm_pushpv(VM *pVM);

void ring_vm_incjump(VM *pVM);

void ring_vm_incpjump(VM *pVM);

void ring_vm_loadfuncp(VM *pVM);

void ring_vm_pushplocal(VM *pVM);

void ring_vm_pusharg(VM *pVM);

void ring_vm_inclpjump(VM *pVM);

void ring_vm_incpjumpstep1(VM *pVM);

void ring_vm_inclpjumpstep1(VM *pVM);

void ring_vm_updatescopeinfo(VM *pVM, int nScope);
/* End Program / Exit from Loop / Loop (Continue) */

void ring_vm_bye(VM *pVM);

void ring_vm_exitmark(VM *pVM);

void ring_vm_popexitmark(VM *pVM);

void ring_vm_exit(VM *pVM, int nType);

void ring_vm_optionalloop(VM *pVM);
/* State */

void ring_vm_savestate(VM *pVM, List *pList);

void ring_vm_restorestate(VM *pVM, List *pList, unsigned int nPos, unsigned int nFlag);

void ring_vm_backstate(VM *pVM, List *pList, unsigned int nToSize);

VMState *ring_vm_savestateformethods(VM *pVM);

void ring_vm_restorestateformethods(VM *pVM, VMState *pVMState);

void ring_vm_savestatefornewobjects(VM *pVM);

void ring_vm_restorestatefornewobjects(VM *pVM);

void ring_vm_savestateforbraces(VM *pVM, List *pObjState);

void ring_vm_restorestateforbraces(VM *pVM, List *pList);

unsigned int ring_vm_newobjectstackpointer(VM *pVM);

List *ring_vm_savestack(VM *pVM);

void ring_vm_restorestack(VM *pVM, List *pList);
/* Bitwise */

void ring_vm_bitand(VM *pVM);

void ring_vm_bitor(VM *pVM);

void ring_vm_bitxor(VM *pVM);

void ring_vm_bitnot(VM *pVM);

void ring_vm_bitshl(VM *pVM);

void ring_vm_bitshr(VM *pVM);

void ring_vm_bitshift(VM *pVM, const char *cOperator);
/* Step Number */

void ring_vm_stepnumber(VM *pVM);

void ring_vm_stepfromreg(VM *pVM);

void ring_vm_popstep(VM *pVM);
/* Threads */

RING_API void ring_vm_mutexfunctions(VM *pVM, void *(*pFuncCreate)(void), void (*pFuncLock)(void *),
				     void (*pFuncUnlock)(void *), void (*pFuncDestroy)(void *));

RING_API void ring_vm_mutexlock(VM *pVM);

RING_API void ring_vm_mutexunlock(VM *pVM);

RING_API void ring_vm_mutexdestroy(VM *pVM);

RING_API void *ring_vm_custmutexcreate(VM *pVM);

RING_API void ring_vm_custmutexlock(VM *pVM, void *pMutex);

RING_API void ring_vm_custmutexunlock(VM *pVM, void *pMutex);

RING_API void ring_vm_custmutexdestroy(VM *pVM, void *pMutex);

RING_API void ring_vm_runcodefromthread(VM *pVM, const char *cStr);

RING_API void ring_vm_bytecodefornewthread(VM *pVM, VM *pOldVM);

RING_API RingState *ring_vm_createthreadstate(VM *pVM);

RING_API void ring_vm_deletethreadstate(VM *pVM, RingState *pState);

RING_API void ring_vm_statecustmutexlock(void *pState, unsigned int nMutex);

RING_API void ring_vm_statecustmutexunlock(void *pState, unsigned int nMutex);
/* Trace */

void ring_vm_traceevent(VM *pVM, char nEvent);
/* Fast Function Call for Extensions (Without Eval) */

RING_API void ring_vm_callfunction(VM *pVM, char *cFuncName);
/* Fast Function Call for Ring VM (Without Eval) */

RING_API void ring_vm_callfuncwithouteval(VM *pVM, const char *cFunc, unsigned int lMethod);
/* Custom Global Scope */

void ring_vm_newglobalscope(VM *pVM);

void ring_vm_endglobalscope(VM *pVM);

void ring_vm_setglobalscope(VM *pVM);

List *ring_vm_getglobalscope(VM *pVM);
/* Temp Lists */

void ring_vm_freetemplistsins(VM *pVM);

void ring_vm_freetemplists(VM *pVM);

int ring_vm_timetofreetemplists(VM *pVM);
/* Better Performance */

void ring_vm_len(VM *pVM);

void ring_vm_setopcode(VM *pVM);

unsigned int ring_vm_isinsideloop(VM *pVM);

void ring_vm_sumn(VM *pVM);

void ring_vm_subn(VM *pVM);

void ring_vm_muln(VM *pVM);

void ring_vm_divn(VM *pVM);

void ring_vm_modn(VM *pVM);

void ring_vm_pown(VM *pVM);
#endif
