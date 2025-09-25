/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

VM *ring_vm_new(RingState *pRingState) {
	VM *pVM;
	unsigned int x;
	List *pActiveMem;
	pVM = (VM *)ring_state_malloc(pRingState, sizeof(VM));
	/* Ring State */
	pVM->pRingState = pRingState;
	pRingState->pVM = pVM;
	pVM->nPC = 1;
	pVM->pCode = NULL;
	pVM->pFunctionsMap = NULL;
	pVM->nOPCode = 0;
	pVM->nSP = 0;
	pVM->pActiveMem = NULL;
	pVM->pTempMem = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	pVM->nLineNumber = 1;
	/*
	**  Set data before creating new scope
	**  Information to test the lifetime of the local scope
	*/
	pVM->nScopeID = 0;
	/* Functions Call count (Checked by ring_vm_newscope() function to avoid overflow) */
	pVM->nCurrentFuncCall = RING_ZERO;
	memset(&(pVM->aFuncCall[0]), RING_ZERO, RING_VM_STACK_SIZE * sizeof(FuncCall));
	pVM->nCurrentScope = RING_ZERO;
	/* Custom Mutex Array */
	for (x = 0; x < RING_VM_CUSTOMMUTEX_COUNT; x++) {
		pVM->aCustomMutex[x] = NULL;
	}
	for (x = 0; x < RING_VM_STACK_SIZE; x++) {
		ring_item_init_gc(pRingState, &(pVM->aStack[x]));
		ring_list_new2_gc(pVM->pRingState, RING_VM_GETSCOPE(x), RING_ZERO);
	}
	ring_vm_newscope(pVM);
	/*
	**  Flag ( 0 = check NULL variable in PUSHV  , greater than 0 = Ignore null variable )
	**  Class Region (After the Class Name)
	*/
	pVM->nInClassRegion = 0;
	/* Global variables defined by Ring - Specific copy for each thread */
	pVM->pDefinedGlobals = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Add Variables */
	pActiveMem = pVM->pActiveMem;
	pVM->pActiveMem = pVM->pDefinedGlobals;
	ring_vm_addglobalvariables(pVM);
	pVM->pActiveMem = pActiveMem;
	/* Lists */
	ring_vm_newnestedlists(pVM);
	pVM->pNestedLists = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Support for nested Load Instructions */
	pVM->nBlockCounter = 0;
	pVM->pPCBlockFlag = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Calling Functions */
	pVM->nFuncSP = 0;
	pVM->lCallMainFunction = 0;
	pVM->pCFunction = NULL;
	/* Support for Exit/Loop Commands inside For/While loops. */
	pVM->pExitMark = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	pVM->pLoopMark = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Try-Catch-Done */
	pVM->pTry = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Saving scope when creating new objects and calling class init method */
	pVM->pScopeNewObj = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Flag ( 0 = Call Function  1 = Call Method After writing object name using dot ) */
	pVM->lCallMethod = 0;
	/* List of Lists used like Stack, list structure [Pointer to State , Pointer to Methods] */
	pVM->pObjState = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Support for using Braces to access object state */
	pVM->pBraceObject = NULL;
	pVM->pBraceObjects = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Used by BraceStart, BraceEnd & FreeStack */
	pVM->lInsideBraceFlag = 0;
	/* Variable scope, where is the variable (when we use findvar) */
	pVM->nVarScope = RING_VARSCOPE_NOTHING;
	/* Flag used by Try/Catch to tell C-API that catch happens! */
	pVM->lActiveCatch = 0;
	pVM->pPackagesMap = NULL;
	/* Set the main File Name */
	pVM->cFileName = ring_list_getstring(pVM->pRingState->pRingFilesList, RING_ONE);
	pVM->cPrevFileName = ring_list_getstring(pVM->pRingState->pRingFilesList, RING_ONE);
	/* We keep information about active package to access its classes directly with new/from */
	pVM->pActivePackage = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Scope of class attribute ( 0 = public 1 = private ) */
	pVM->lPrivateFlag = 0;
	/* Set/Get Property */
	pVM->lGetSetProperty = 0;
	pVM->pGetSetObject = NULL;
	pVM->nGetSetObjType = 0;
	pVM->pSetProperty = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Assignment Pointer */
	pVM->pAssignment = NULL;
	/* For Loop - Step List */
	pVM->pForStep = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Flag for LoadA , when = 1 , if it's a pointer we get First Var. not the Pointer */
	pVM->lFirstAddress = 0;
	/* Used to know operator before = like += -= *= /= */
	pVM->nBeforeEqual = OP_EQUAL;
	/*
	**  NOAssignment used to disable instruction AssignmentPointer
	**  We uses this when we change assignment to set property
	**  It's important for ListStart to create Temp List when we use setter
	**  and try to set attribute value to a list and a function setproperty() will be called
	**  With this list as parameter stored in temp memory
	*/
	pVM->lNoAssignment = 0;
	/* The scope of the result of Load Address */
	pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING;
	/* List contains what to add  later to pObjState, prepare by loadmethod, add before call */
	pVM->pBeforeObjState = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Eval can be called from C code (OOP Set/Get/Operator Overloading) or from ring code using eval() */
	pVM->lEvalCalledFromRingCode = 0;
	/* Number of decimals after the point */
	pVM->nDecimals = RING_DECIMALS_COUNT;
	/*
	**  Do we need to reallocation for eval() or not !
	**  Size of items that we can use without reallocation (double of the original size)
	*/
	pVM->nEvalReallocationSize = 0;
	/* Flag ( 1 = we need space over allocated size so we have to do reallocation ) */
	pVM->lEvalReallocationFlag = 0;
	/* Parameters Passed to C Function */
	pVM->nCFuncParaCount = 0;
	pVM->nCFuncSP = 0;
	/*
	**  Flag to Ignore NULL output after calling C Function
	**  This flag is used by the len() function when we use len(object)
	**  So operator overloading can return the result from the method
	*/
	pVM->lIgnoreNULL = 0;
	/* If pVM->nPC <= nEvalReturnPC we end the main loop (used by evalreturn) */
	pVM->nEvalReturnPC = 0;
	/* Flag to return Item Reference (of object state) */
	pVM->nRetItemRef = 0;
	/* Mutex Functions Pointers - for threads/lock/unlock */
	pVM->pFuncMutexCreate = NULL;
	pVM->pFuncMutexLock = NULL;
	pVM->pFuncMutexUnlock = NULL;
	pVM->pFuncMutexDestroy = NULL;
	pVM->pMutex = NULL;
	/* Ignore C Pointer Type Check in extension functions */
	pVM->lIgnoreCPointerTypeCheck = 0;
	/*
	**  Flag when we call class init using new obj()
	**  Since we call init() using generated braces { }
	**  setting this flag enable LoadAddress to pass these braces
	**  To access the class attributes of the caller
	**  because {} hides the class attributes and we need to avoid that!
	*/
	pVM->nCallClassInit = 0;
	/*
	**  Flag to avoid deleting Byte Code using Return From Eval()
	**  When we use eval() then inside eval we uses eval for setter/getter/operator overloading
	**  Then deleting byte code will cause a problem in setter/getter/operator overloading
	**  In this case we set this flag to avoid the delete operation and solve the problem
	*/
	pVM->lRetEvalDontDelete = 0;
	/* Counter to know if we are inside ring_vm_runcode() */
	pVM->nRunCode = 0;
	/* Flag that we have runtime error to avoid calling the error function again */
	pVM->lActiveError = 0;
	/* The active package name (after using import command) */
	pVM->pPackageName = ring_string_new_gc(pVM->pRingState, RING_CSTR_EMPTY);
	/*
	**  Trace Program (After Each Line)
	**  lTrace = Logical Value (Trace is Active or Not)
	**  pTrace = String contains the code to be executed (Trace Function)
	**  lTraceActive = The Trace Function is Active - Don't Call Trace function from Trace Function
	**  nTraceEvent = The Trace Event (1 = New Line , etc)
	*/
	pVM->lTrace = 0;
	pVM->pTrace = ring_string_new_gc(pVM->pRingState, RING_CSTR_EMPTY);
	pVM->lTraceActive = 0;
	pVM->nTraceEvent = 0;
	pVM->pTraceData = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Eval In Scope function is Active : ringvm_evalinscope() */
	pVM->nEvalInScope = 0;
	/* Pass error in ring_vm_error() from ringvm_passerror() */
	pVM->lPassError = 0;
	/* Hide Error message - don't display it in ring_vm_error() */
	pVM->lHideErrorMsg = 0;
	/* Custom Global Scopes (using load package) */
	pVM->pGlobalScopes = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	pVM->pActiveGlobalScopes = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	pVM->nCurrentGlobalScope = 0;
	/* File name in the class region */
	pVM->cFileNameInClassRegion = NULL;
	/* To know if we are inside eval() or not */
	pVM->nInsideEval = 0;
	/* Dynamic Libraries */
	pVM->pCLibraries = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* No Setter Method (used by ring_vm_oop_setget() function) */
	pVM->nNoSetterMethod = RING_NOSETTERMETHOD_DEFAULT;
	/* Check OverFlow after arithmetic operations */
	pVM->lCheckOverFlow = 0;
	/* A Flag that the Exit command is used to terminate the (For-In) Loop */
	pVM->lExitFlag = 0;
	/* A flag to enable/disable BraceError() Method usage for the current Error */
	pVM->lCheckBraceError = 1;
	/* A flag if we are using LoadA to get the Self variable */
	pVM->lSelfLoadA = 0;
	/* List of pointers that contains lists that will be deleted later */
	pVM->pDeleteLater = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Flag used by string to number to know if all of the characters are converted or not */
	pVM->lFullStringToNum = 0;
	/* A Flag to display error when only part of the string is converted to a number */
	pVM->lSubStringToNumError = 1;
	/* A Flag to activate the optional loop instruction */
	pVM->lOptionalLoop = 0;
	/* Use to register the PC when we stop the VM */
	pVM->nPausePC = 1;
	/* Tracked List of Variables - Each variable is a pointer to a List item */
	pVM->pTrackedVariables = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	/* Create Arguments Cache */
	ring_vm_newargcache(pVM);
	return pVM;
}

VM *ring_vm_delete(VM *pVM) {
	unsigned int x;
	pVM->pNestedLists = ring_list_delete_gc(pVM->pRingState, pVM->pNestedLists);
	pVM->pPCBlockFlag = ring_list_delete_gc(pVM->pRingState, pVM->pPCBlockFlag);
	pVM->pTempMem = ring_list_delete_gc(pVM->pRingState, pVM->pTempMem);
	pVM->pExitMark = ring_list_delete_gc(pVM->pRingState, pVM->pExitMark);
	pVM->pLoopMark = ring_list_delete_gc(pVM->pRingState, pVM->pLoopMark);
	pVM->pTry = ring_list_delete_gc(pVM->pRingState, pVM->pTry);
	pVM->pScopeNewObj = ring_list_delete_gc(pVM->pRingState, pVM->pScopeNewObj);
	pVM->pObjState = ring_list_delete_gc(pVM->pRingState, pVM->pObjState);
	pVM->pBraceObjects = ring_list_delete_gc(pVM->pRingState, pVM->pBraceObjects);
	pVM->pActivePackage = ring_list_delete_gc(pVM->pRingState, pVM->pActivePackage);
	pVM->pSetProperty = ring_list_delete_gc(pVM->pRingState, pVM->pSetProperty);
	pVM->pForStep = ring_list_delete_gc(pVM->pRingState, pVM->pForStep);
	pVM->pBeforeObjState = ring_list_delete_gc(pVM->pRingState, pVM->pBeforeObjState);
	/* Free (Stack, FuncCall & Scopes) */
	for (x = 0; x < RING_VM_STACK_SIZE; x++) {
		ring_item_deletecontent_gc(pVM->pRingState, &(pVM->aStack[x]));
		/* Delete Temp. memory lists in FuncCall */
		if (pVM->aFuncCall[x].pTempMem != NULL) {
			pVM->aFuncCall[x].pTempMem = ring_list_delete_gc(pVM->pRingState, pVM->aFuncCall[x].pTempMem);
		}
		/* Delete scope lists */
		if ((x < 1) || (pVM->pRingState->lRunFromSubThread && (x < 2))) {
			continue;
		}
		ring_list_deleteallitems_gc(pVM->pRingState, RING_VM_GETSCOPE(x));
	}
	/* Delete the bytecode */
	ring_vm_deleteallbytecode(pVM);
	/* Delete Mutex */
	ring_vm_mutexdestroy(pVM);
	pVM->pPackageName = ring_string_delete_gc(pVM->pRingState, pVM->pPackageName);
	pVM->pTrace = ring_string_delete_gc(pVM->pRingState, pVM->pTrace);
	pVM->pTraceData = ring_list_delete_gc(pVM->pRingState, pVM->pTraceData);
	/* Custom Global Scope (using Load Package) */
	pVM->pGlobalScopes = ring_list_delete_gc(pVM->pRingState, pVM->pGlobalScopes);
	pVM->pActiveGlobalScopes = ring_list_delete_gc(pVM->pRingState, pVM->pActiveGlobalScopes);
/* Dynamic Libraries */
#if RING_VM_DLL
	ring_vm_dll_closealllibs(pVM);
#endif
	pVM->pCLibraries = ring_list_delete_gc(pVM->pRingState, pVM->pCLibraries);
	pVM->pDeleteLater = ring_list_delete_gc(pVM->pRingState, pVM->pDeleteLater);
	pVM->pDefinedGlobals = ring_list_delete_gc(pVM->pRingState, pVM->pDefinedGlobals);
	pVM->pTrackedVariables = ring_list_delete_gc(pVM->pRingState, pVM->pTrackedVariables);
	/* Delete Arguments Cache */
	ring_vm_deleteargcache(pVM);
	/* Delete C Functions */
	ring_vm_deletecfunctions(pVM);
	pVM->pRingState->pVM = NULL;
	ring_state_free(pVM->pRingState, pVM);
	pVM = NULL;
	return pVM;
}

void ring_vm_start(RingState *pRingState, VM *pVM) {
	pVM->pCode = pRingState->pRingGenCode;
	pVM->pFunctionsMap = pRingState->pRingFunctionsMap;
	pVM->pClassesMap = pRingState->pRingClassesMap;
	pVM->pPackagesMap = pRingState->pRingPackagesMap;
	if (pRingState->lRunFromObjectFile == 0) {
		ring_vm_defragmentation(pRingState, pVM);
	}
	ring_vm_loadcode(pVM);
	ring_vm_towardsmainloop(pRingState);
}

void ring_vm_towardsmainloop(RingState *pRingState) {
	VM *pVM;
	pVM = pRingState->pVM;
	ring_vm_loadcfunctions(pRingState);
	if (RING_VM_INSTRUCTIONSCOUNT > 0) {
		pVM->nPC = 1;
		ring_vm_mainloop(pVM);
	}
}

void ring_vm_init(RingState *pRingState) {
	Scanner *pScanner;
	VM *pVM;
	unsigned int nRunVM, nFreeFilesList = 0;
	/* Check file */
	if (pRingState->pRingFilesList == NULL) {
		pRingState->pRingFilesList = ring_list_new_gc(pRingState, RING_ZERO);
		pRingState->pRingFilesStack = ring_list_new_gc(pRingState, RING_ZERO);
		nFreeFilesList = 1;
	}
	ring_list_addstring_gc(pRingState, pRingState->pRingFilesList, RING_CSTR_EMBEDDEDCODE);
	ring_list_addstring_gc(pRingState, pRingState->pRingFilesStack, RING_CSTR_EMBEDDEDCODE);
	/* Read File */
	pScanner = ring_scanner_new(pRingState);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	/* Call Parser */
	nRunVM = ring_parser_start(pRingState, pScanner->pTokens);
	ring_scanner_delete(pScanner);
	/* Files List */
	ring_list_deleteitem_gc(pRingState, pRingState->pRingFilesStack,
				ring_list_getsize(pRingState->pRingFilesStack));
	if (nFreeFilesList) {
		/* Run the Program */
		if (nRunVM == 1) {
			/* Add return to the end of the program */
			ring_scanner_addreturn(pRingState);
			pVM = ring_vm_new(pRingState);
			ring_vm_start(pRingState, pVM);
		}
	}
	return;
}

void ring_vm_defragmentation(RingState *pRingState, VM *pVM) {
	List *pRingFilesList;
	/* Create Lists */
	pVM->pFunctionsMap = ring_list_new(RING_ZERO);
	pVM->pClassesMap = ring_list_new(RING_ZERO);
	pVM->pPackagesMap = ring_list_new(RING_ZERO);
	pRingFilesList = ring_list_new(RING_ZERO);
	/* Copy Lists */
	ring_list_copy(pVM->pFunctionsMap, pRingState->pRingFunctionsMap);
	ring_list_copy(pVM->pClassesMap, pRingState->pRingClassesMap);
	ring_list_copy(pVM->pPackagesMap, pRingState->pRingPackagesMap);
	ring_list_copy(pRingFilesList, pRingState->pRingFilesList);
	ring_list_delete_gc(pRingState, pRingState->pRingFunctionsMap);
	ring_list_delete_gc(pRingState, pRingState->pRingClassesMap);
	ring_list_delete_gc(pRingState, pRingState->pRingPackagesMap);
	ring_list_delete_gc(pRingState, pRingState->pRingFilesList);
	pRingState->pRingFunctionsMap = pVM->pFunctionsMap;
	pRingState->pRingClassesMap = pVM->pClassesMap;
	pRingState->pRingPackagesMap = pVM->pPackagesMap;
	pRingState->pRingFilesList = pRingFilesList;
	/* Update Pointers */
	ring_vm_updateclassespointers(pRingState);
	/* Set the main File Name */
	pVM->cFileName = ring_list_getstring(pVM->pRingState->pRingFilesList, RING_ONE);
	pVM->cPrevFileName = ring_list_getstring(pVM->pRingState->pRingFilesList, RING_ONE);
}

void ring_vm_updateclassespointers(RingState *pRingState) {
	unsigned int x, x2, x3, x4, lFound;
	List *pList, *pList2, *pList3, *pPackageList;
	const char *cString;
	char cPackageName[RING_HUGEBUF];
	char cClassName[RING_HUGEBUF];
	/* Update Package Pointers in Packages Classes */
	for (x = 1; x <= ring_list_getsize(pRingState->pRingPackagesMap); x++) {
		pList = ring_list_getlist(pRingState->pRingPackagesMap, x);
		/* Get The Classes List */
		pList2 = ring_list_getlist(pList, RING_PACKAGES_CLASSESLIST);
		for (x2 = 1; x2 <= ring_list_getsize(pList2); x2++) {
			pList3 = ring_list_getlist(pList2, x2);
			ring_list_setpointer(pList3, RING_CLASSMAP_POINTERTOPACKAGE, pList);
		}
	}
	/*
	**  Update Class Pointers in Classes Map when the class belong to a Package
	**  This updates works when the class name is : packagename.classname
	*/
	for (x = 1; x <= ring_list_getsize(pRingState->pRingClassesMap); x++) {
		pList = ring_list_getlist(pRingState->pRingClassesMap, x);
		cString = ring_list_getstring(pList, RING_CLASSMAP_CLASSNAME);
		if (ring_list_getstringsize(pList, RING_CLASSMAP_CLASSNAME) > RING_HUGEBUF) {
			/* Avoid large names */
			continue;
		}
		x2 = ring_list_getstringsize(pList, RING_CLASSMAP_CLASSNAME);
		while (x2 > 0) {
			x2--;
			if (cString[x2] == '.') {
				/*
				**  Now we have a class name stored as packagename.classname
				**  Get Package Name
				*/
				for (x3 = 0; x3 < x2; x3++) {
					cPackageName[x3] = cString[x3];
				}
				cPackageName[x2] = '\0';
				/* Get Class Name */
				for (x3 = x2 + 1; x3 <= ring_list_getstringsize(pList, RING_CLASSMAP_CLASSNAME) - 1;
				     x3++) {
					cClassName[x3 - x2 - 1] = cString[x3];
				}
				cClassName[ring_list_getstringsize(pList, RING_CLASSMAP_CLASSNAME) - 1 - x2] = '\0';
				/* Get The Package List */
				for (x3 = 1; x3 <= ring_list_getsize(pRingState->pRingPackagesMap); x3++) {
					pPackageList = ring_list_getlist(pRingState->pRingPackagesMap, x3);
					if (strcmp(ring_list_getstring(pPackageList, RING_PACKAGES_PACKAGENAME),
						   cPackageName) == 0) {
						/* Get The Classes List */
						pList2 = ring_list_getlist(pPackageList, RING_PACKAGES_CLASSESLIST);
						for (x4 = 1; x4 <= ring_list_getsize(pList2); x4++) {
							pList3 = ring_list_getlist(pList2, x4);
							if (strcmp(ring_list_getstring(pList3, RING_CLASSMAP_CLASSNAME),
								   cClassName) == 0) {
								/* Now We have the Class - Update Pointer */
								ring_list_setpointer(
								    pList,
								    RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE,
								    (void *)pList3);
								/* Update Package Pointer in the Class List */
								ring_list_setpointer(pList3,
										     RING_CLASSMAP_POINTERTOPACKAGE,
										     (void *)pPackageList);
								break;
							}
						}
						break;
					}
				}
			}
		}
	}
	/* Update Class Pointer in Code */
	for (x = 1; x <= ring_list_getsize(pRingState->pRingGenCode); x++) {
		pList = ring_list_getlist(pRingState->pRingGenCode, x);
		if (ring_list_getint(pList, RING_PARSER_ICG_OPERATIONCODE) == ICO_NEWCLASS) {
			cString = ring_list_getstring(pList, RING_PARSER_ICG_PARA1);
			lFound = 0;
			for (x2 = 1; x2 <= ring_list_getsize(pRingState->pRingClassesMap); x2++) {
				pList2 = ring_list_getlist(pRingState->pRingClassesMap, x2);
				if (strcmp(cString, ring_list_getstring(pList2, RING_CLASSMAP_CLASSNAME)) == 0) {
					lFound = 1;
					ring_list_setpointer(pList, RING_PARSER_ICG_PARA2, pList2);
					break;
				}
			}
			/* If we can't find the list (the class is inside a package) */
			if (lFound == 0) {
				ring_list_setpointer(pList, RING_PARSER_ICG_PARA2, NULL);
			}
		}
	}
}

void ring_vm_deletecfunctions(VM *pVM) {
	CFunction *pCFunc;
	while (pVM->pCFunction != NULL) {
		pCFunc = pVM->pCFunction;
		pVM->pCFunction = pVM->pCFunction->pNext;
		ring_state_free(pVM->pRingState, pCFunc);
	}
}

RING_API void ring_vm_loadcode(VM *pVM) {
	unsigned int x, nSize;
/*
**  We may allocate larger than the size that we need to avoid reallocation when we use eval()
**  eval() will check if there is a need to reallocation or not
**  This optimization increase the performance of applications that uses eval()
*/
#if RING_LOWMEM
	nSize = RING_VM_INSTRUCTIONSLISTSIZE;
#else
	nSize = RING_VM_INSTRUCTIONSLISTSIZE + RING_VM_EXTRASIZE;
#endif
	pVM->pByteCode = (ByteCode *)ring_calloc(nSize, sizeof(ByteCode));
	for (x = 1; x <= RING_VM_INSTRUCTIONSLISTSIZE; x++) {
		ring_vm_tobytecode(pVM, x);
	}
	pVM->nEvalReallocationSize = nSize;
	pVM->pRingState->nInstructionsCount = ring_list_getsize(pVM->pCode);
	ring_list_deleteallitems_gc(pVM->pRingState, pVM->pRingState->pRingGenCode);
}

void ring_vm_tobytecode(VM *pVM, int nIns) {
	List *pIR;
	unsigned int x, nType;
	ByteCode *pByteCode;
	Item *pItem;
	String *pString;
	pByteCode = pVM->pByteCode + pVM->pRingState->nInstructionsCount + nIns - 1;
	pIR = ring_list_getlist(pVM->pCode, nIns);
	/* Check Instruction Size */
	if (ring_list_getsize(pIR) > RING_VM_BC_ITEMS_COUNT + 1) {
		printf(RING_LONGINSTRUCTION);
		printf("In File : %s  - Byte-Code PC : %d  ", pVM->cFileName, nIns);
		exit(RING_EXIT_FAIL);
	}
	/* Get the Operation Code */
	pItem = ring_list_getitem_gc(pVM->pRingState, pIR, RING_PARSER_ICG_OPERATIONCODE);
	/* Avoid Performance Instructions (Happens when called from New Thread) */
	switch (pItem->data.iNumber) {
	case ICO_PUSHPLOCAL:
		pItem->data.iNumber = ICO_LOADADDRESS;
		break;
	case ICO_INCLPJUMP:
		pItem->data.iNumber = ICO_INCJUMP;
		break;
	case ICO_INCLPJUMPSTEP1:
		pItem->data.iNumber = ICO_INCJUMP;
		break;
	}
	pByteCode->nOPCode = pItem->data.iNumber;
	/* Set the default values */
	pByteCode->lFlagReg = 0;
	pByteCode->lFlagReg2 = 0;
	pByteCode->lLiteral = 0;
	pByteCode->lUnusedFlag = 0;
	pByteCode->nReg1Type = RING_VM_REGTYPE_DEFAULT;
	pByteCode->nReg2Type = RING_VM_REGTYPE_DEFAULT;
	pByteCode->nSmallIntReg = 0;
	pByteCode->nIntReg = 0;
	pByteCode->aReg[RING_VM_IR_REG1].dNumber = 0.0;
	pByteCode->aReg[RING_VM_IR_REG2].dNumber = 0.0;
	for (x = 2; x <= ring_list_getsize(pIR); x++) {
		pItem = ring_list_getitem_gc(pVM->pRingState, pIR, x);
		/* Copy the item data */
		switch (pItem->nType) {
		case ITEMTYPE_NUMBER:
			if (ring_item_isdouble(pItem)) {
				pByteCode->aReg[x - 2].dNumber = ring_item_getdouble(pItem);
				nType = RING_VM_REGTYPE_DOUBLE;
			} else {
				pByteCode->aReg[x - 2].iNumber = ring_item_getint(pItem);
				nType = RING_VM_REGTYPE_INT;
			}
			break;
		case ITEMTYPE_STRING:
			pString = ring_item_getstring(pItem);
			pByteCode->aReg[x - 2].pString =
			    ring_string_strdup_gc(pVM->pRingState, ring_string_get(pString));
			nType = RING_VM_REGTYPE_STRING;
			break;
		case ITEMTYPE_POINTER:
			pByteCode->aReg[x - 2].pPointer = ring_item_getpointer(pItem);
			nType = RING_VM_REGTYPE_POINTER;
			break;
		}
		/* Set the Register type */
		switch (x - 2) {
		case 0:
			pByteCode->nReg1Type = nType;
			break;
		case 1:
			pByteCode->nReg2Type = nType;
			break;
		}
	}
}

void ring_vm_deletebytecode(VM *pVM, int nIns) {
	pVM->pByteCodeIR = pVM->pByteCode + nIns - 1;
	ring_vm_clearregisterstring(pVM, RING_VM_IR_REG1);
	ring_vm_clearregisterstring(pVM, RING_VM_IR_REG2);
}

void ring_vm_clearregisterstring(VM *pVM, int nReg) {
	if (pVM->pByteCodeIR->lLiteral) {
		return;
	}
	switch (nReg) {
	case RING_VM_IR_REG1:
		if (pVM->pByteCodeIR->nReg1Type == RING_VM_REGTYPE_STRING) {
			ring_state_free(pVM->pRingState, (void *)pVM->pByteCodeIR->aReg[RING_VM_IR_REG1].pString);
			pVM->pByteCodeIR->nReg1Type = RING_VM_REGTYPE_DEFAULT;
		}
		break;
	case RING_VM_IR_REG2:
		if (pVM->pByteCodeIR->nReg2Type == RING_VM_REGTYPE_STRING) {
			ring_state_free(pVM->pRingState, (void *)pVM->pByteCodeIR->aReg[RING_VM_IR_REG2].pString);
			pVM->pByteCodeIR->nReg2Type = RING_VM_REGTYPE_DEFAULT;
		}
		break;
	}
}

void ring_vm_setreg1topointerfromstack(VM *pVM) {
	RING_VM_IR_CLEARREG1STRING;
	RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG1), RING_VM_STACK_READP);
	RING_VM_IR_SETREG1TYPE(RING_VM_REGTYPE_POINTER);
}

RING_API void ring_vm_showbytecode(VM *pVM) {
	unsigned int x, y, nCount, nType;
	ByteCode *pByteCode;
	/* Print Header */
	printf("\n\n");
	ring_general_printline();
	puts(" Byte Code - After Execution by the VM");
	ring_general_printline();
	/* Print the ByteCode */
	nCount = RING_VM_INSTRUCTIONSCOUNT;
	if (nCount > 0) {
		printf("\n %6s  %18s  %19s %18s %7s\n", "PC", "OPCode", "Reg1", "Reg2", "IntReg");
		for (x = 1; x <= nCount; x++) {
			/* Get the Instruction */
			pByteCode = pVM->pByteCode + x - 1;
			printf("\n %6d  %18s  ", x, RING_IC_OP[pByteCode->nOPCode]);
			for (y = 0; y < RING_VM_BC_ITEMS_COUNT; y++) {
				/* Get The Register Type */
				if (y == 0) {
					nType = pByteCode->nReg1Type;
				} else if (y == 1) {
					nType = pByteCode->nReg2Type;
				}
				/* Display the Register Value */
				switch (nType) {
				case RING_VM_REGTYPE_STRING:
					printf(" %18s", pByteCode->aReg[y].pString);
					break;
				case RING_VM_REGTYPE_INT:
					printf(" %18d", pByteCode->aReg[y].iNumber);
					break;
				case RING_VM_REGTYPE_DOUBLE:
					printf(" %18f", pByteCode->aReg[y].dNumber);
					break;
				case RING_VM_REGTYPE_POINTER:
					printf(" %18p", pByteCode->aReg[y].pPointer);
					break;
				}
			}
			printf(" %7d", pByteCode->nIntReg);
		}
		printf("\n");
	}
	/* Print Footer */
	puts(RING_CSTR_EMPTY);
	ring_general_printline();
	puts(RING_CSTR_EMPTY);
}

void ring_vm_bytecode2list(VM *pVM, List *pOutput) {
	unsigned int x, y, nCount, nType;
	ByteCode *pByteCode;
	List *pIns;
	nCount = RING_VM_INSTRUCTIONSCOUNT;
	if (nCount > 0) {
		for (x = 1; x <= nCount; x++) {
			/* Create the instruction list */
			pIns = ring_list_newlist_gc(pVM->pRingState, pOutput);
			/* Get the Instruction */
			pByteCode = pVM->pByteCode + x - 1;
			ring_list_adddouble_gc(pVM->pRingState, pIns, pByteCode->nOPCode);
			for (y = 0; y < RING_VM_BC_ITEMS_COUNT; y++) {
				/* Get The Register Type */
				if (y == 0) {
					nType = pByteCode->nReg1Type;
				} else if (y == 1) {
					nType = pByteCode->nReg2Type;
				}
				/* Add the Register Value */
				switch (nType) {
				case RING_VM_REGTYPE_STRING:
					ring_list_addstring_gc(pVM->pRingState, pIns, pByteCode->aReg[y].pString);
					break;
				case RING_VM_REGTYPE_INT:
					ring_list_adddouble_gc(pVM->pRingState, pIns, pByteCode->aReg[y].iNumber);
					break;
				case RING_VM_REGTYPE_DOUBLE:
					ring_list_adddouble_gc(pVM->pRingState, pIns, pByteCode->aReg[y].dNumber);
					break;
				case RING_VM_REGTYPE_POINTER:
					ring_list_addpointer_gc(pVM->pRingState, pIns, pByteCode->aReg[y].pPointer);
					break;
				}
			}
		}
	}
}

void ring_vm_afterscopeidoverflow(VM *pVM) {
	unsigned int x, nCount;
	ByteCode *pByteCode;
	nCount = RING_VM_INSTRUCTIONSCOUNT;
	for (x = 1; x <= nCount; x++) {
		/* Get the Instruction */
		pByteCode = pVM->pByteCode + x - 1;
		switch (pByteCode->nOPCode) {
		case ICO_PUSHPLOCAL:
			pByteCode->nOPCode = ICO_LOADADDRESS;
			pByteCode->aReg[RING_VM_IR_REG2].iNumber = RING_ZERO;
			pByteCode->nReg2Type = RING_VM_REGTYPE_INT;
			break;
		case ICO_INCLPJUMP:
			pByteCode->nOPCode = ICO_INCJUMP;
			break;
		case ICO_INCLPJUMPSTEP1:
			pByteCode->nOPCode = ICO_INCJUMP;
			break;
		}
	}
}

void ring_vm_deleteallbytecode(VM *pVM) {
	unsigned int x;
	for (x = 1; x <= RING_VM_INSTRUCTIONSCOUNT; x++) {
		ring_vm_deletebytecode(pVM, x);
	}
	ring_state_free(pVM->pRingState, pVM->pByteCode);
}

void ring_vm_mainloop(VM *pVM) {
	pVM->pRingState->lStartPoolManager = 1;
	/* Allows showing the OPCODE */
	if (pVM->pRingState->lPrintInstruction) {
		do {
			ring_vm_fetch2(pVM);
		} while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT);
	} else {
		do {
			ring_vm_fetch(pVM);
		} while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT);
	}
}

RING_API void ring_vm_fetch(VM *pVM) {
	pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1;
	pVM->nOPCode = RING_VM_IR_OPCODE;
	pVM->nPC++;
	ring_vm_execute(pVM);
	if (pVM->nSP > RING_VM_STACK_CHECKOVERFLOW) {
		ring_vm_error(pVM, RING_VM_ERROR_STACKOVERFLOW);
	}
}

RING_API void ring_vm_fetch2(VM *pVM) {
	pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1;
	pVM->nOPCode = RING_VM_IR_OPCODE;
	if (pVM->pRingState->lPrintInstruction) {
		ring_general_printline();
		printf("VM Pointer    : %p  ", (void *)pVM);
		printf("\nVM IR Pointer : %p  ", (void *)pVM->pByteCodeIR);
		printf("\nOperation     : %s  ", RING_IC_OP[pVM->nOPCode]);
		printf("\nPC            : %d  ", pVM->nPC);
		printf("\nScopes Count  : %d  ", RING_VM_SCOPESCOUNT);
		printf("\nScope Pointer : %p  ", pVM->pActiveMem);
		printf("\nFile Name     : %s \nLine Number   : %d\n", pVM->cFileName, RING_VM_IR_GETLINENUMBER);
		if ((pVM->nOPCode == ICO_PUSHC) || (pVM->nOPCode == ICO_LOADADDRESS) ||
		    (pVM->nOPCode == ICO_LOADFUNC)) {
			printf("Data          : %s \n", RING_VM_IR_READC);
		}
	}
	pVM->nPC++;
	ring_vm_execute(pVM);
	if (pVM->pRingState->lPrintInstruction) {
		printf("\nSP (After)    : %d  \nFuncSP        : %d \nLineNumber    : %d \n", (int)pVM->nSP,
		       pVM->nFuncSP, RING_VM_IR_GETLINENUMBER);
	}
	if (pVM->nSP > RING_VM_STACK_CHECKOVERFLOW) {
		ring_vm_error(pVM, RING_VM_ERROR_STACKOVERFLOW);
	}
}

void ring_vm_execute(VM *pVM) {
	switch (pVM->nOPCode) {
	/* Stack and Variables */
	case ICO_PUSHC:
		RING_VM_STACK_PUSHC;
		break;
	case ICO_PUSHNL:
		RING_VM_STACK_PUSHNL;
		break;
	case ICO_PUSH2N:
		RING_VM_STACK_PUSHNVALUE(RING_VM_IR_READDVALUE(RING_VM_IR_REG1));
		RING_VM_STACK_PUSHNVALUE(RING_VM_IR_READDVALUE(RING_VM_IR_REG2));
		break;
	case ICO_PUSHN:
		RING_VM_STACK_PUSHNVALUE(RING_VM_IR_READDVALUE(RING_VM_IR_REG1));
		break;
	case ICO_PUSHV:
		ring_vm_pushv(pVM);
		break;
	case ICO_LOADADDRESS:
		ring_vm_loadaddress(pVM);
		break;
	case ICO_ASSIGNMENT:
		ring_vm_assignment(pVM);
		break;
	case ICO_INC:
		ring_vm_inc(pVM);
		break;
	case ICO_LOADAPUSHV:
		ring_vm_loadapushv(pVM);
		break;
	case ICO_NEWLINE:
		ring_vm_newline(pVM);
		break;
	case ICO_FREESTACK:
		ring_vm_freestack(pVM);
		break;
	case ICO_FILENAME:
		ring_vm_setfilename(pVM);
		break;
	case ICO_FREELOADASCOPE:
		ring_vm_freeloadaddressscope(pVM);
		break;
	/* Jump */
	case ICO_JUMP:
		RING_VM_JUMP;
		break;
	case ICO_JUMPZERO:
		ring_vm_jumpzero(pVM);
		break;
	case ICO_JUMPFOR:
		ring_vm_jumpfor(pVM);
		break;
	case ICO_JUMPONE:
		ring_vm_jumpone(pVM);
		break;
	case ICO_JUMPZERO2:
		ring_vm_jumpzero2(pVM);
		break;
	case ICO_JUMPONE2:
		ring_vm_jumpone2(pVM);
		break;
	case ICO_PUSHNULLTHENJUMP:
		RING_VM_PUSHNULLTHENJUMP;
		break;
	case ICO_PUSHNTHENJUMP:
		RING_VM_PUSHNTHENJUMP;
		break;
	/* Compare */
	case ICO_LESSEQUAL:
		ring_vm_lessequal(pVM);
		break;
	case ICO_EQUAL:
		ring_vm_equal(pVM);
		break;
	case ICO_LESS:
		ring_vm_less(pVM);
		break;
	case ICO_GREATER:
		ring_vm_greater(pVM);
		break;
	case ICO_GREATEREQUAL:
		ring_vm_greaterequal(pVM);
		break;
	case ICO_NOTEQUAL:
		ring_vm_notequal(pVM);
		break;
	/* Math */
	case ICO_SUM:
		ring_vm_sum(pVM);
		break;
	case ICO_SUB:
		ring_vm_sub(pVM);
		break;
	case ICO_MUL:
		ring_vm_mul(pVM);
		break;
	case ICO_DIV:
		ring_vm_div(pVM);
		break;
	case ICO_MOD:
		ring_vm_mod(pVM);
		break;
	case ICO_NEG:
		ring_vm_neg(pVM);
		break;
	case ICO_PLUSPLUS:
		ring_vm_plusplus(pVM);
		break;
	case ICO_MINUSMINUS:
		ring_vm_minusminus(pVM);
		break;
	case ICO_POW:
		ring_vm_pow(pVM);
		break;
	case ICO_SUMN:
		ring_vm_sumn(pVM);
		break;
	case ICO_SUBN:
		ring_vm_subn(pVM);
		break;
	case ICO_MULN:
		ring_vm_muln(pVM);
		break;
	case ICO_DIVN:
		ring_vm_divn(pVM);
		break;
	case ICO_MODN:
		ring_vm_modn(pVM);
		break;
	case ICO_POWN:
		ring_vm_pown(pVM);
		break;
	/* Logic */
	case ICO_AND:
		ring_vm_and(pVM);
		break;
	case ICO_OR:
		ring_vm_or(pVM);
		break;
	case ICO_NOT:
		ring_vm_not(pVM);
		break;
	/* Lists */
	case ICO_LISTSTART:
		ring_vm_liststart(pVM);
		break;
	case ICO_LISTITEM:
		ring_vm_listitem(pVM);
		break;
	case ICO_LISTITEMN:
		ring_vm_listitemn(pVM);
		break;
	case ICO_LISTITEMC:
		ring_vm_listitemc(pVM);
		break;
	case ICO_LISTEND:
		ring_vm_listend(pVM);
		break;
	case ICO_LOADINDEXADDRESS:
		ring_vm_loadindexaddress(pVM);
		break;
	/* Functions */
	case ICO_LOADFUNC:
		ring_vm_loadfunc(pVM);
		break;
	case ICO_CALL:
		ring_vm_call(pVM);
		break;
	case ICO_RETURN:
		ring_vm_return(pVM);
		break;
	case ICO_RETURNN:
		ring_vm_returnn(pVM);
		break;
	case ICO_RETNULL:
		ring_vm_returnnull(pVM);
		break;
	case ICO_RETFROMEVAL:
		ring_vm_returneval(pVM);
		break;
	case ICO_RETITEMREF:
		ring_vm_retitemref(pVM);
		break;
	case ICO_NEWFUNC:
		ring_vm_newfunc(pVM);
		break;
	case ICO_BLOCKFLAG:
		ring_vm_blockflag(pVM);
		break;
	case ICO_ANONYMOUS:
		ring_vm_anonymous(pVM);
		break;
	/* End Program - Exit from Loop - Loop (Continue) */
	case ICO_BYE:
		ring_vm_bye(pVM);
		break;
	case ICO_EXITMARK:
		ring_vm_exitmark(pVM);
		break;
	case ICO_POPEXITMARK:
		ring_vm_popexitmark(pVM);
		break;
	case ICO_EXIT:
		ring_vm_exit(pVM, RING_COMMANDTYPE_EXIT);
		break;
	case ICO_LOOP:
		ring_vm_exit(pVM, RING_COMMANDTYPE_LOOP);
		break;
	/* For Better Performance */
	case ICO_PUSHP:
		ring_vm_pushp(pVM);
		break;
	case ICO_INCP:
		ring_vm_incp(pVM);
		break;
	case ICO_PUSHPV:
		ring_vm_pushpv(pVM);
		break;
	case ICO_INCJUMP:
		ring_vm_incjump(pVM);
		break;
	case ICO_INCPJUMP:
		ring_vm_incpjump(pVM);
		break;
	case ICO_LOADFUNCP:
		ring_vm_loadfuncp(pVM);
		break;
	case ICO_PUSHPLOCAL:
		ring_vm_pushplocal(pVM);
		break;
	case ICO_PUSHARG:
		ring_vm_pusharg(pVM);
		break;
	case ICO_INCLPJUMP:
		ring_vm_inclpjump(pVM);
		break;
	case ICO_INCPJUMPSTEP1:
		ring_vm_incpjumpstep1(pVM);
		break;
	case ICO_INCLPJUMPSTEP1:
		ring_vm_inclpjumpstep1(pVM);
		break;
	case ICO_LEN:
		ring_vm_len(pVM);
		break;
	case ICO_SETOPCODE:
		ring_vm_setopcode(pVM);
		break;
	case ICO_CHECKBRACEMETHOD:
		ring_vm_oop_checkbracemethod(pVM);
		break;
	/* Try-Catch-Done */
	case ICO_TRY:
		ring_vm_try(pVM);
		break;
	case ICO_DONE:
		ring_vm_done(pVM);
		break;
	/* Duplicate and Range */
	case ICO_DUPLICATE:
		ring_vm_stackdup(pVM);
		break;
	case ICO_RANGE:
		ring_vm_range(pVM);
		break;
	/* OOP */
	case ICO_NEWOBJ:
		ring_vm_oop_newobj(pVM);
		break;
	case ICO_SETSCOPE:
		ring_vm_oop_setscope(pVM);
		break;
	case ICO_LOADSUBADDRESS:
		ring_vm_oop_property(pVM);
		break;
	case ICO_LOADMETHOD:
		ring_vm_oop_loadmethod(pVM);
		break;
	case ICO_AFTERCALLMETHOD:
		ring_vm_oop_aftercallmethod(pVM);
		break;
	case ICO_AFTERCALLMETHOD2:
		ring_vm_oop_aftercallmethod(pVM);
		break;
	case ICO_NEWCLASS:
		ring_vm_oop_newclass(pVM);
		break;
	case ICO_BRACESTART:
		ring_vm_oop_bracestart(pVM);
		break;
	case ICO_BRACEEND:
		ring_vm_oop_braceend(pVM);
		break;
	case ICO_IMPORT:
		ring_vm_oop_import(pVM);
		break;
	case ICO_PRIVATE:
		pVM->lPrivateFlag = 1;
		break;
	case ICO_SETPROPERTY:
		ring_vm_oop_setproperty(pVM);
		break;
	case ICO_CALLCLASSINIT:
		ring_vm_oop_callclassinit(pVM);
		break;
	/* Bitwise Operators */
	case ICO_BITAND:
		ring_vm_bitand(pVM);
		break;
	case ICO_BITOR:
		ring_vm_bitor(pVM);
		break;
	case ICO_BITXOR:
		ring_vm_bitxor(pVM);
		break;
	case ICO_BITNOT:
		ring_vm_bitnot(pVM);
		break;
	case ICO_BITSHL:
		ring_vm_bitshl(pVM);
		break;
	case ICO_BITSHR:
		ring_vm_bitshr(pVM);
		break;
	/* For Step */
	case ICO_STEPNUMBER:
		ring_vm_stepnumber(pVM);
		break;
	case ICO_STEPFROMREG:
		ring_vm_stepfromreg(pVM);
		break;
	case ICO_POPSTEP:
		ring_vm_popstep(pVM);
		break;
	case ICO_LOADAFIRST:
		ring_vm_loadaddressfirst(pVM);
		break;
	/* Custom Global Scope */
	case ICO_NEWGLOBALSCOPE:
		ring_vm_newglobalscope(pVM);
		break;
	case ICO_ENDGLOBALSCOPE:
		ring_vm_endglobalscope(pVM);
		break;
	case ICO_SETGLOBALSCOPE:
		ring_vm_setglobalscope(pVM);
		break;
	/* Temp Lists */
	case ICO_FREETEMPLISTS:
		ring_vm_freetemplistsins(pVM);
		break;
	/* Optional Loop */
	case ICO_OPTIONALLOOP:
		ring_vm_optionalloop(pVM);
		break;
	/* Other */
	case ICO_SETREFERENCE:
		ring_vm_setreference(pVM);
		break;
	case ICO_KILLREFERENCE:
		ring_vm_gc_killreference(pVM);
		break;
	case ICO_ASSIGNMENTPOINTER:
		ring_vm_assignmentpointer(pVM);
		break;
	case ICO_BEFOREEQUAL:
		pVM->nBeforeEqual = RING_VM_IR_READI;
		break;
	}
}
