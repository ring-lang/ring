/*
**  Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com>
**  pClassesMap ( cClass Name ,  iPC , cParentClass, aMethodsList , nFlagIsParentClassInformation, PointerToPackage )
**  pClassesMap ( cClass Name, Pointer to List that represent class inside a Package, Pointer to File )
**  pFunctionsMap ( Name, PC, FileName, Private Flag )
**  Packages List ( Package Name , Classes List )
**  Object ( is a list of two items , (1) Class Pointer  (2) Object Data  )
**  pVM->pScopeNewObj : (1) Previous scope (2) nListStart (3) pNestedLists (4) nSP
**  pVM->pObjState  (  [ Pointer to Scope, Pointer to Methods , Pointer to Class, Optional True)
**  The optional True used with LoadMethod so we can Know that we are inside class method during RT
**  We don't check the True value, we just check that the size of the list is 4
**  used in ring_vmfuncs , function ring_vm_loadfunc2()
**  used in ring_vmvars , function ring_vm_findvar2()
**  pBraceObject : The list that represent the object directly (not variable/list item)
**  pBraceObjects ( pBraceObject, nSP, nListStart, pNestedLists)
**  pSetProperty ( Object Pointer , Type (Variable/ListItem)  , Property Name, Property Variable ,
*nBeforeEqual,Value,PtrType)
*/
#include "ring.h"

void ring_vm_oop_newobj(VM *pVM) {
	const char *cClassName, *cClassName2;
	unsigned int x, nLimit, nClassPC, nType;
	List *pList, *pList2, *pList3, *pList4, *pVar, *pSelf;
	Item *pItem;
	pList2 = NULL;
	pVar = NULL;
	pItem = NULL;
	cClassName = RING_VM_IR_READC;
	/* Check using variable to get the class name */
	if (RING_VM_IR_READIVALUE(RING_VM_IR_REG2)) {
		if (ring_vm_findvar(pVM, cClassName)) {
			pVar = (List *)RING_VM_STACK_READP;
			if (RING_VAR_ISSTRING(pVar)) {
				if (strcmp(RING_VAR_GETSTRING(pVar), RING_CSTR_EMPTY) != 0) {
					ring_string_tolower(RING_VAR_GETSTRINGOBJ(pVar));
					cClassName = RING_VAR_GETSTRING(pVar);
				} else {
					ring_vm_error(pVM, RING_VM_ERROR_USINGNULLVARIABLE);
					return;
				}
			} else {
				ring_vm_error(pVM, RING_VM_ERROR_VARISNOTSTRING);
				return;
			}
			RING_VM_STACK_POP;
			pVar = NULL;
		} else {
			ring_vm_error(pVM, RING_VM_ERROR_NOTVARIABLE);
			return;
		}
	}
	nLimit = ring_vm_oop_visibleclassescount(pVM);
	if (nLimit > 0) {
		for (x = 1; x <= nLimit; x++) {
			pList = ring_vm_oop_visibleclassitem(pVM, x);
			cClassName2 = ring_list_getstring(pList, RING_CLASSMAP_CLASSNAME);
			pList = ring_vm_oop_checkpointertoclassinpackage(pVM, pList);
			if (pList == NULL) {
				continue;
			}
			nClassPC = ring_list_getint(pList, RING_CLASSMAP_PC);
			if (strcmp(cClassName, cClassName2) == 0) {
				if (ring_vm_notusingvarduringdef(pVM)) {
					/* Create the Temp Variable */
					ring_vm_createtemplist(pVM);
					pVar = (List *)RING_VM_STACK_READP;
					nType = RING_VM_STACK_OBJTYPE;
					RING_VAR_SETTYPE(pVar, RING_VM_LIST);
					RING_VAR_SETLIST_GC(pVM->pRingState, pVar);
					pList2 = RING_VAR_GETLIST(pVar);
					/* When using something like Ref(new myclass) don't create new reference */
					if (ring_vm_funccallbeforecall(pVM)) {
						ring_vm_oop_cleansetpropertylist(pVM);
						ring_list_enabledontref_gc(pVM->pRingState, pList2);
					}
				} else {
					/* Prepare Object List */
					if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
						pVar = (List *)RING_VM_STACK_READP;
						/* Check before assignment */
						if (ring_vm_gc_checkbeforeassignment(pVM, pVar)) {
							return;
						}
						RING_VAR_SETTYPE(pVar, RING_VM_LIST);
						RING_VAR_SETLIST_GC(pVM->pRingState, pVar);
						pList2 = RING_VAR_GETLIST(pVar);
					} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
						pItem = (Item *)RING_VM_STACK_READP;
						/* Check before assignment */
						if (ring_vm_gc_checkitemerroronassignment(pVM, pItem)) {
							return;
						}
						ring_item_settype_gc(pVM->pRingState, pItem, ITEMTYPE_LIST);
						pVar = ring_item_getlist(pItem);
						pList2 = pVar;
					}
					nType = RING_VM_STACK_OBJTYPE;
					ring_vm_stackdup(pVM);
				}
				ring_list_deleteallitems_gc(pVM->pRingState, pList2);
				/* Store the Class Pointer in the Object Data */
				ring_list_addpointer_gc(pVM->pRingState, pList2, pList);
				/* Create List for the Object State */
				pList3 = ring_list_newlist_gc(pVM->pRingState, pList2);
				/* Create Self variable in the state list */
				pSelf = ring_vm_newvar2(pVM, RING_CSTR_SELF, pList3);
				RING_VAR_SETTYPE(pSelf, RING_VM_POINTER);
				if (nType == RING_OBJTYPE_VARIABLE) {
					RING_VAR_SETPOINTER_GC(pVM->pRingState, pSelf, pVar);
				} else if (nType == RING_OBJTYPE_LISTITEM) {
					RING_VAR_SETPOINTER_GC(pVM->pRingState, pSelf, pItem);
				}
				RING_VAR_SETPVALUETYPE(pSelf, nType);
				/* Save the State */
				ring_vm_savestatefornewobjects(pVM);
				/* Push Class Package */
				ring_vm_oop_pushclasspackage(pVM, pList);
				/* Jump to Class INIT Method */
				ring_vm_blockflag2(pVM, pVM->nPC);
				/* Execute Parent Classes Init first */
				if (strcmp(ring_list_getstring(pList, RING_CLASSMAP_PARENTCLASS), RING_CSTR_EMPTY) !=
				    0) {
					ring_vm_blockflag2(pVM, nClassPC);
					if (!ring_vm_oop_parentinit(pVM, pList)) {
						return;
					}
				} else {
					pVM->nPC = nClassPC;
				}
				/* Set Object State as the Current Scope */
				pVM->pActiveMem = pList3;
				/* Prepare to Make Object State & Methods visible while executing the INIT method */
				RING_VM_PUSHOBJSTATE(pList3, NULL, pList, 0);
				/* Create the Super Virtual Object */
				ring_vm_oop_newsuperobj(pVM, pList3, pList);
				/* Enable NULL variables (To be class attributes) */
				pVM->nInClassRegion++;
				return;
			}
		}
	}
	ring_vm_error2(pVM, RING_VM_ERROR_CLASSNOTFOUND, cClassName);
}

unsigned int ring_vm_oop_parentinit(VM *pVM, List *pList) {
	const char *cClassName, *cClassName2;
	unsigned int x, x2, nFound, nMark, lOutput;
	List *pList2, *pClassesList;
	String *pString;
	lOutput = 1;
	/* Get the parent class name from the Class List Pointer */
	cClassName = ring_list_getstring(pList, RING_CLASSMAP_PARENTCLASS);
	/* Create List for Classes Pointers */
	pClassesList = ring_list_new_gc(pVM->pRingState, RING_ZERO);
	ring_list_addpointer_gc(pVM->pRingState, pClassesList, pList);
	while (strcmp(cClassName, RING_CSTR_EMPTY) != 0) {
		/* Mark Packages Count */
		nMark = ring_list_getsize(pVM->pActivePackage);
		nFound = 0;
		for (x = 1; x <= ring_vm_oop_visibleclassescount(pVM); x++) {
			pList2 = ring_vm_oop_visibleclassitem(pVM, x);
			cClassName2 = ring_list_getstring(pList2, RING_CLASSMAP_CLASSNAME);
			pList2 = ring_vm_oop_checkpointertoclassinpackage(pVM, pList2);
			if (pList2 == NULL) {
				continue;
			}
			if (strcmp(cClassName, cClassName2) == 0) {
				/* Check that the parent class is not one of the subclasses */
				for (x2 = 1; x2 <= ring_list_getsize(pClassesList); x2++) {
					if (((List *)ring_list_getpointer(pClassesList, x2)) == pList2) {
						pString = ring_string_new_gc(pVM->pRingState, "When creating class ");
						ring_string_add_gc(pVM->pRingState, pString,
								   ring_list_getstring(pList, RING_CLASSMAP_CLASSNAME));
						ring_string_add_gc(pVM->pRingState, pString, " from class ");
						ring_string_add_gc(pVM->pRingState, pString, cClassName);
						ring_vm_error2(pVM, RING_VM_ERROR_PARENTCLASSLIKESUBCLASS,
							       ring_string_get(pString));
						ring_string_delete_gc(pVM->pRingState, pString);
						/* Delete Classes Pointers List */
						ring_list_delete_gc(pVM->pRingState, pClassesList);
						return RING_FALSE;
					}
				}
				ring_list_addpointer_gc(pVM->pRingState, pClassesList, pList2);
				/* Push Class Package */
				ring_vm_oop_pushclasspackage(pVM, pList2);
				cClassName = ring_list_getstring(pList2, RING_CLASSMAP_PARENTCLASS);
				if (strcmp(cClassName, RING_CSTR_EMPTY) != 0) {
					/* Add Class Init Method to be called */
					ring_vm_blockflag2(pVM, ring_list_getint(pList2, RING_CLASSMAP_PC));
				} else {
					pVM->nPC = ring_list_getint(pList2, RING_CLASSMAP_PC);
				}
				nFound = 1;
				break;
			}
		}
		if (nFound == 0) {
			/* Error Message */
			ring_vm_error2(pVM, RING_VM_ERROR_PARENTCLASSNOTFOUND, cClassName);
			lOutput = 0;
			break;
		}
		/* Restore Mark */
		ring_vm_oop_deletepackagesafter(pVM, nMark);
		pList = pList2;
	}
	/* Delete Classes Pointers List */
	ring_list_delete_gc(pVM->pRingState, pClassesList);
	return lOutput;
}

void ring_vm_oop_newclass(VM *pVM) {
	List *pClass, *pList;
	unsigned int x;
	pClass = (List *)RING_VM_IR_READPVALUE(RING_VM_IR_REG2);
	/* Find the Class Pointer using the Class Name */
	if (pClass == NULL) {
		for (x = 1; x <= ring_list_getsize(pVM->pRingState->pRingClassesMap); x++) {
			pList = ring_list_getlist(pVM->pRingState->pRingClassesMap, x);
			if (strcmp(ring_list_getstring(pList, RING_CLASSMAP_CLASSNAME),
				   RING_VM_IR_READCVALUE(RING_VM_IR_REG1)) == 0) {
				if (ring_list_getsize(pList) == RING_CLASSMAP_IMPORTEDCLASSSIZE) {
					/* Here the class is stored inside a package - we have the class pointer (item
					 * 2) */
					pClass = (List *)ring_list_getpointer(
					    pList, RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE);
				} else {
					pClass = pList;
				}
				RING_VM_IR_READPVALUE(RING_VM_IR_REG2) = (void *)pClass;
				break;
			}
		}
	}
	pClass = ring_vm_oop_checkpointertoclassinpackage(pVM, pClass);
	/* Make object methods visible while executing the Class Init method */
	pVM->aObjState[pVM->nCurrentObjState].pMethods = ring_list_getlist(pClass, RING_CLASSMAP_METHODSLIST);
	/* Get Parent Classes Methods */
	ring_vm_oop_parentmethods(pVM, pClass);
	/* Attributes Scope is Public */
	pVM->lPrivateFlag = 0;
	/* Support using This in the class region */
	ring_vm_oop_setthethisvariableinclassregion(pVM);
	/* Set the current global scope */
	pVM->nCurrentGlobalScope = 0;
}

void ring_vm_oop_setscope(VM *pVM) {
	/* This function will be called after creating a new object and executing the class init() method */
	/* Restore State */
	ring_vm_restorestatefornewobjects(pVM);
}

unsigned int ring_vm_oop_isobject(VM *pVM, List *pList) { return ring_list_isobject(pList); }

List *ring_vm_oop_getobj(VM *pVM) {
	List *pVar;
	Item *pItem;
	pVar = NULL;
	/* Get Object Data */
	if (!RING_VM_STACK_ISPOINTER) {
		ring_vm_error(pVM, RING_VM_ERROR_NOTOBJECT);
		return NULL;
	}
	if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
		pVar = (List *)RING_VM_STACK_READP;
		if (RING_VAR_GETTYPE(pVar) == RING_VM_NULL) {
			ring_vm_error2(pVM, RING_VM_ERROR_USINGNULLVARIABLE, RING_VAR_GETNAME(pVar));
			return NULL;
		}
		if (!RING_VAR_ISLIST(pVar)) {
			ring_vm_error(pVM, RING_VM_ERROR_NOTOBJECT);
			return NULL;
		}
		pVar = RING_VAR_GETLIST(pVar);
	} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
		pItem = (Item *)RING_VM_STACK_READP;
		if (!ring_item_islist(pItem)) {
			ring_vm_error(pVM, RING_VM_ERROR_NOTOBJECT);
			return NULL;
		}
		pVar = ring_item_getlist(pItem);
	}
	if (ring_vm_oop_isobject(pVM, pVar) == 0) {
		ring_vm_error(pVM, RING_VM_ERROR_NOTOBJECT);
		return NULL;
	}
	RING_VM_STACK_POP;
	return pVar;
}

void ring_vm_oop_property(VM *pVM) {
	List *pVar, *pScope;
	/* Get Object Pointer Before being a list by getobj */
	if (RING_VM_STACK_ISPOINTER) {
		pVM->pGetSetObject = RING_VM_STACK_READP;
		pVM->nGetSetObjType = RING_VM_STACK_OBJTYPE;
	}
	/* Get Object Data */
	pVar = ring_vm_oop_getobj(pVM);
	if (pVar == NULL) {
		return;
	}
	/* Get Object State */
	pScope = pVM->pActiveMem;
	pVM->pActiveMem = RING_OBJECT_GETOBJECTDATA(pVar);
	pVM->lGetSetProperty = 1;
	if (ring_vm_findvar(pVM, RING_VM_IR_READC) == 0) {
		/* Create the attribute if we are in the class region after the class name */
		if (pVM->nInClassRegion) {
			ring_vm_newvar(pVM, RING_VM_IR_READC);
			/* Support for Private Flag */
			ring_vm_setvarprivateflag(pVM, (List *)RING_VM_STACK_READP, pVM->lPrivateFlag);
			RING_VM_STACK_POP;
			ring_vm_findvar(pVM, RING_VM_IR_READC);
			pVM->pActiveMem = pScope;
			pVM->lGetSetProperty = 0;
			pVM->pGetSetObject = NULL;
			return;
		}
		pVM->pActiveMem = pScope;
		pVM->lGetSetProperty = 0;
		pVM->pGetSetObject = NULL;
		if (pVM->lActiveCatch == 0) {
			/*
			**  We check lActiveCatch because we may have error "accessing private attribute'
			**  while we are using ring_vm_findvar
			**  And we are using try catch done in the code
			**  In this case we don't add another error message
			**  So the try catch done can work as expected and avoid the need to another one
			**  Error Message
			*/
			ring_vm_error2(pVM, RING_VM_ERROR_PROPERTYNOTFOUND, RING_VM_IR_READC);
		}
		return;
	}
	pVM->pActiveMem = pScope;
	/* Note: We don't set pVM->pGetSetObject to NULL because it could be used by ICO_DUPLICATE */
	pVM->lGetSetProperty = 0;
}

void ring_vm_oop_loadmethod(VM *pVM) { ring_vm_oop_loadmethod2(pVM, RING_VM_IR_READC); }

void ring_vm_oop_loadmethod2(VM *pVM, const char *cMethod) {
	List *pVar, *pList, *pList2, *pList3, *pSuper;
	unsigned int lResult;
	FuncCall *pFuncCall;
	/* Check calling method related to Parent Class */
	pSuper = ring_vm_oop_getsuperobj(pVM);
	if (pSuper != NULL) {
		ring_vm_oop_loadsuperobjmethod(pVM, pSuper);
		/* Move list from pObjState to pBeforeObjState */
		ring_vm_oop_movetobeforeobjstate(pVM);
		return;
	}
	/* Get Object Data */
	pVar = ring_vm_oop_getobj(pVM);
	if (pVar == NULL) {
		return;
	}
	/* Get Object Class */
	pList = (List *)RING_OBJECT_GETCLASSPOINTER(pVar);
	/* Push Class Package */
	ring_vm_oop_pushclasspackage(pVM, pList);
	/* Get Class Methods */
	pList2 = ring_list_getlist(pList, RING_CLASSMAP_METHODSLIST);
	RING_VM_PUSHOBJSTATE(RING_OBJECT_GETOBJECTDATA(pVar), pList2, pList, 1);
	/* Get Parent Classes Methods */
	ring_vm_oop_parentmethods(pVM, pList);
	/* Call Method */
	pList3 = pVM->pFunctionsMap;
	pVM->pFunctionsMap = pList2;
	pVM->lCallMethod = 1;
	lResult = ring_vm_loadfunc2(pVM, cMethod, RING_FALSE);
	pVM->lCallMethod = 0;
	pVM->pFunctionsMap = pList3;
	/* Move list from pObjState to pBeforeObjState */
	if (lResult) {
		ring_vm_oop_movetobeforeobjstate(pVM);
		if ((pVM->nInsideEval == 0) && (pVM->lInsideBraceFlag == 0)) {
			pFuncCall = RING_VM_LASTFUNCCALL;
			RING_VM_IR_OPCODE = ICO_LOADMETHODP;
			RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG2), (void *)pList);
			RING_VM_IR_SETREG2TYPE(RING_VM_REGTYPE_POINTER);
			RING_VM_IR_SETINTREG(pFuncCall->nPC);
			RING_VM_IR_SETFLAGREG(pFuncCall->nType);
			RING_VM_IR_SETFLAGREG2(pFuncCall->lMethod);
		}
	}
}

void ring_vm_oop_loadmethodp(VM *pVM) {
	List *pVar, *pList, *pList2, *pObjData, *pCachedClass;
	Item *pItem;
	pList = NULL;
	if (RING_VM_STACK_ISPOINTER) {
		if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
			pVar = (List *)RING_VM_STACK_READP;
			if (RING_VAR_ISLIST(pVar)) {
				pList = RING_VAR_GETLIST(pVar);
			}
		} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
			pItem = (Item *)RING_VM_STACK_READP;
			if (ring_item_islist(pItem)) {
				pList = (List *)ring_item_getlist(pItem);
			}
		}
	}
	pCachedClass = (List *)RING_VM_IR_READPVALUE(RING_VM_IR_REG2);
	if ((pList == NULL) || ((List *)RING_OBJECT_GETCLASSPOINTER(pList) != pCachedClass)) {
		RING_VM_IR_OPCODE = ICO_LOADMETHOD;
		ring_vm_oop_loadmethod(pVM);
		return;
	}
	RING_VM_STACK_POP;
	pList2 = ring_list_getlist(pCachedClass, RING_CLASSMAP_METHODSLIST);
	pObjData = RING_OBJECT_GETOBJECTDATA(pList);
	ring_vm_oop_pushclasspackage(pVM, pCachedClass);
	RING_VM_PUSHOBJSTATE(pObjData, pList2, pCachedClass, 1);
	ring_vm_oop_usemethodp(pVM);
	ring_vm_oop_movetobeforeobjstate(pVM);
}

void ring_vm_oop_loadbracemethodp(VM *pVM) {
	List *pCachedClass, *pMethods;
	ObjState *pOS;
	if ((pVM->lInsideBraceFlag == RING_FALSE) || (pVM->nCurrentObjState == RING_ZERO) ||
	    (pVM->lCallMethod == RING_TRUE)) {
		RING_VM_IR_OPCODE = ICO_LOADFUNC;
		ring_vm_loadfunc(pVM);
		return;
	}
	pOS = &pVM->aObjState[pVM->nCurrentObjState];
	pCachedClass = (List *)RING_VM_IR_READPVALUE(RING_VM_IR_REG2);
	pMethods = pOS->pMethods;
	if ((pOS->pClass != pCachedClass) || (pMethods == NULL) ||
	    (ring_list_getsize(pMethods) != RING_VM_IR_GETSMALLINTREG)) {
		RING_VM_IR_OPCODE = ICO_LOADFUNC;
		ring_vm_loadfunc(pVM);
		return;
	}
	ring_vm_oop_usemethodp(pVM);
}

void ring_vm_oop_usemethodp(VM *pVM) {
	FuncCall *pFuncCall;
	pFuncCall = ring_vm_funccallnew(pVM);
	if (pFuncCall == NULL) {
		return;
	}
	pFuncCall->nType = RING_VM_IR_GETFLAGREG;
	pFuncCall->cName = RING_VM_IR_READC;
	pFuncCall->nPC = RING_VM_IR_GETINTREG;
	pFuncCall->nSP = pVM->nSP;
	pFuncCall->pFunc = NULL;
	pFuncCall->lMethod = RING_VM_IR_GETFLAGREG2;
	pFuncCall->nLineNumber = RING_VM_IR_GETLINENUMBER;
	pFuncCall->cFileName = pVM->cFileName;
	pFuncCall->cNewFileName = pVM->cFileName;
	pVM->cPrevFileName = pVM->cFileName;
	pFuncCall->nLoadAddressScope = pVM->nLoadAddressScope;
	pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING;
	pFuncCall->nListStart = pVM->nListStart;
	pFuncCall->nNestedLists = ring_list_getsize(pVM->pNestedLists);
	ring_vm_newnestedlists(pVM);
}

void ring_vm_oop_movetobeforeobjstate(VM *pVM) {
	if (pVM->lActiveCatch == 1) {
		/* Try/Catch restore aObjState and may become empty */
		return;
	}
	/* Move list from pObjState to pBeforeObjState */
	pVM->nBeforeObjStateCount++;
	pVM->aBeforeObjState[pVM->nBeforeObjStateCount] = pVM->aObjState[pVM->nCurrentObjState];
	RING_VM_POPOBJSTATE;
}

void ring_vm_oop_parentmethods(VM *pVM, List *pList) {
	const char *cClassName, *cClassName2;
	unsigned int x, nFound, nMark;
	List *pList3, *pList4;
	pList3 = ring_list_getlist(pList, RING_CLASSMAP_METHODSLIST);
	if (ring_list_getint(pList, RING_CLASSMAP_ISPARENTINFO) == RING_FALSE) {
		ring_list_setint_gc(pVM->pRingState, pList, RING_CLASSMAP_ISPARENTINFO, RING_TRUE);
		cClassName = ring_list_getstring(pList, RING_CLASSMAP_PARENTCLASS);
		/* Mark Packages Count */
		nMark = ring_list_getsize(pVM->pActivePackage);
		while (strcmp(cClassName, RING_CSTR_EMPTY) != 0) {
			/* Push Class Package */
			ring_vm_oop_pushclasspackage(pVM, pList);
			nFound = 0;
			for (x = 1; x <= ring_vm_oop_visibleclassescount(pVM); x++) {
				pList4 = ring_vm_oop_visibleclassitem(pVM, x);
				cClassName2 = ring_list_getstring(pList4, RING_CLASSMAP_CLASSNAME);
				/* Prev. Step must be before Next. step - We check the name include the package */
				pList4 = ring_vm_oop_checkpointertoclassinpackage(pVM, pList4);
				if (pList4 == NULL) {
					continue;
				}
				if (strcmp(cClassName, cClassName2) == 0) {
					/* Push Class Package */
					ring_vm_oop_pushclasspackage(pVM, pList4);
					ring_list_copy_gc(pVM->pRingState, pList3,
							  ring_list_getlist(pList4, RING_CLASSMAP_METHODSLIST));
					cClassName = ring_list_getstring(pList4, RING_CLASSMAP_PARENTCLASS);
					nFound = 1;
					break;
				}
			}
			if (nFound == 0) {
				ring_vm_error(pVM, RING_VM_ERROR_PARENTCLASSNOTFOUND);
				break;
			}
			/* Exit when the parent class already contains it's parent classes data */
			if (ring_list_getint(pList4, RING_CLASSMAP_ISPARENTINFO) == 1) {
				break;
			}
		}
		/* Restore Mark */
		ring_vm_oop_deletepackagesafter(pVM, nMark);
	}
}

void ring_vm_oop_aftercallmethod(VM *pVM) {
	if (pVM->nCurrentObjState != 0) {
		RING_VM_POPOBJSTATE;
	}
}

void ring_vm_oop_printobj(VM *pVM, List *pList) { ring_list_printobj(pList, pVM->nDecimals); }

void ring_vm_oop_setbraceobj(VM *pVM, List *pList) {
	/* Support using { } to access object after object name */
	if (ring_vm_oop_isobject(pVM, pList)) {
		pVM->pBraceObject = pList;
	}
}

void ring_vm_oop_bracestart(VM *pVM) {
	List *pList, *pVar;
	Item *pItem;
	unsigned int lShowError;
	/* Check Error */
	lShowError = 0;
	if ((pVM->pBraceObject == NULL) || (!RING_VM_STACK_ISPOINTER)) {
		lShowError = 1;
	} else if (RING_VM_STACK_ISPOINTER) {
		if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
			pVar = (List *)RING_VM_STACK_READP;
			if (RING_VAR_ISLIST(pVar)) {
				pList = RING_VAR_GETLIST(pVar);
				lShowError = (ring_vm_oop_isobject(pVM, pList) == 0);
			} else {
				lShowError = 1;
			}
		} else if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM) {
			pItem = (Item *)RING_VM_STACK_READP;
			if (ring_item_islist(pItem)) {
				pList = (List *)ring_item_getlist(pItem);
				lShowError = (ring_vm_oop_isobject(pVM, pList) == 0);
			} else {
				lShowError = 1;
			}
		}
	}
	if (lShowError) {
		/* Disable handling this error using BraceError() Method */
		pVM->lCheckBraceError = 0;
		ring_vm_error(pVM, RING_VM_ERROR_BRACEWITHOUTOBJECT);
		return;
	}
	pVM->nCurrentObjState++;
	if (pVM->nCurrentObjState > RING_VM_STACK_CHECKOVERFLOW) {
		ring_vm_error(pVM, RING_VM_ERROR_STACKOVERFLOW);
		return;
	}
	ring_vm_savestateforbraces(pVM);
	/* Check Don't Ref. and Don't Ref Again */
	ring_list_disabledontref_gc(pVM->pRingState, pList);
	ring_list_disabledontrefagain_gc(pVM->pRingState, pList);
}

void ring_vm_oop_braceend(VM *pVM) {
	VMState *pVMState;
	pVMState = (VMState *)ring_list_getpointer(pVM->pBraceObjects, ring_list_getsize(pVM->pBraceObjects));
	ring_vm_restorestateforbraces(pVM, pVMState);
}

void ring_vm_oop_bracestack(VM *pVM) {
	VMState *pVMState;
	pVMState = (VMState *)ring_list_getpointer(pVM->pBraceObjects, ring_list_getsize(pVM->pBraceObjects));
	pVM->nSP = pVMState->aNumbers[RING_BRACEOBJECTS_NSP];
	if (pVM->nFuncSP > pVM->nSP) {
		/*
		**  This fixes a problem when we use oObject {  eval(code) } return cString
		**  Where pVM->nSP maybe less than pVM->nFuncSP while we are inside function
		*/
		if (RING_VM_FUNCCALLSCOUNT > 0) {
			pVM->nSP = pVM->nFuncSP;
		}
	}
}

void ring_vm_oop_newsuperobj(VM *pVM, List *pState, List *pClass) {
	List *pSuper, *pSuper2, *pMethods, *pList;
	const char *cParentClassName, *cClassName;
	unsigned int x;
	pSuper = ring_vm_newvar2(pVM, "super", pState);
	RING_VAR_SETTYPE(pSuper, RING_VM_LIST);
	RING_VAR_SETLIST_GC(pVM->pRingState, pSuper);
	pSuper2 = RING_VAR_GETLIST(pSuper);
	pMethods = ring_list_getlist(pClass, RING_CLASSMAP_METHODSLIST);
	ring_list_addpointer_gc(pVM->pRingState, pSuper2, pMethods);
	cParentClassName = ring_list_getstring(pClass, RING_CLASSMAP_PARENTCLASS);
	while (strcmp(cParentClassName, RING_CSTR_EMPTY) != 0) {
		for (x = 1; x <= ring_vm_oop_visibleclassescount(pVM); x++) {
			pList = ring_vm_oop_visibleclassitem(pVM, x);
			cClassName = ring_list_getstring(pList, RING_CLASSMAP_CLASSNAME);
			pList = ring_vm_oop_checkpointertoclassinpackage(pVM, pList);
			if (pList == NULL) {
				continue;
			}
			if (strcmp(cClassName, cParentClassName) == 0) {
				cParentClassName = ring_list_getstring(pList, RING_CLASSMAP_PARENTCLASS);
				pMethods = ring_list_getlist(pList, RING_CLASSMAP_METHODSLIST);
				ring_list_addpointer_gc(pVM->pRingState, pSuper2, pMethods);
				break;
			}
		}
	}
	/* Disable deleting the Super list through Ring code */
	ring_list_enableerroronassignment2_gc(pVM->pRingState, pSuper2);
}

List *ring_vm_oop_getsuperobj(VM *pVM) {
	List *pVar;
	if ((RING_VM_STACK_ISPOINTER) && (pVM->nCurrentObjState != 0)) {
		if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
			pVar = (List *)RING_VM_STACK_READP;
			if ((RING_VAR_ISLIST(pVar)) && (strcmp(RING_VAR_GETNAME(pVar), "super") == 0)) {
				pVar = RING_VAR_GETLIST(pVar);
				RING_VM_STACK_POP;
				return pVar;
			}
		}
	}
	return NULL;
}

void ring_vm_oop_loadsuperobjmethod(VM *pVM, List *pSuper) {
	unsigned int x;
	List *pState, *pMethods, *pClass, *pVar;
	pState = pVM->aObjState[pVM->nCurrentObjState].pScope;
	pMethods = pVM->aObjState[pVM->nCurrentObjState].pMethods;
	pClass = pVM->aObjState[pVM->nCurrentObjState].pClass;
	for (x = 1; x <= ring_list_getsize(pSuper); x++) {
		if (ring_list_getpointer(pSuper, x) == pMethods) {
			if ((x + 1) <= ring_list_getsize(pSuper)) {
				pMethods = (List *)ring_list_getpointer(pSuper, (x + 1));
				break;
			} else {
				ring_vm_error(pVM, RING_VM_ERROR_SUPERCLASSNOTFOUND);
				return;
			}
		}
	}
	RING_VM_PUSHOBJSTATE(pState, pMethods, pClass, 0);
	/* Call Method */
	pVar = pVM->pFunctionsMap;
	pVM->pFunctionsMap = pMethods;
	pVM->lCallMethod = 1;
	ring_vm_loadfunc(pVM);
	pVM->lCallMethod = 0;
	pVM->pFunctionsMap = pVar;
}

void ring_vm_oop_import(VM *pVM) { ring_vm_oop_import2(pVM, RING_VM_IR_READC); }

void ring_vm_oop_import2(VM *pVM, const char *cPackage) {
	unsigned int x;
	List *pList, *pList2;
	const char *cPackage2;
	for (x = 1; x <= ring_list_getsize(pVM->pPackagesMap); x++) {
		pList = ring_list_getlist(pVM->pPackagesMap, x);
		cPackage2 = ring_list_getstring(pList, RING_PACKAGES_PACKAGENAME);
		if (strcmp(cPackage, cPackage2) == 0) {
			/* Get Package Classes */
			pList2 = ring_list_getlist(pList, RING_PACKAGES_CLASSESLIST);
			ring_vm_oop_import3(pVM, pList2);
			/* Set Active Package Name */
			ring_string_set_gc(pVM->pRingState, pVM->pPackageName, cPackage);
			return;
		}
	}
	/* Error Message */
	ring_vm_error2(pVM, RING_VM_ERROR_PACKAGENOTFOUND, cPackage);
}

void ring_vm_oop_import3(VM *pVM, List *pList) {
	unsigned int x;
	List *pList2, *pList3;
	/* Import Package Classes */
	for (x = 1; x <= ring_list_getsize(pList); x++) {
		pList2 = ring_list_getlist(pList, x);
		pList3 = ring_list_newlist_gc(pVM->pRingState, pVM->pClassesMap);
		ring_list_addstring_gc(pVM->pRingState, pList3, ring_list_getstring(pList2, RING_CLASSMAP_CLASSNAME));
		ring_list_addpointer_gc(pVM->pRingState, pList3, pList2);
		ring_list_addpointer_gc(pVM->pRingState, pList3, (void *)pVM->cFileName);
	}
}

List *ring_vm_oop_checkpointertoclassinpackage(VM *pVM, List *pList) {
	if (ring_list_getsize(pList) == RING_CLASSMAP_IMPORTEDCLASSSIZE) {
		if (ring_list_getpointer(pList, RING_CLASSMAP_POINTERTOFILENAME) != NULL) {
			if (strcmp((char *)ring_list_getpointer(pList, RING_CLASSMAP_POINTERTOFILENAME),
				   pVM->cFileName) != 0) {
				return NULL;
			}
		}
		return (List *)ring_list_getpointer(pList, RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE);
	}
	return pList;
}

unsigned int ring_vm_oop_visibleclassescount(VM *pVM) {
	List *pList;
	if (ring_list_getsize(pVM->pActivePackage) > 0) {
		pList = (List *)ring_list_getpointer(pVM->pActivePackage, ring_list_getsize(pVM->pActivePackage));
		pList = ring_list_getlist(pList, RING_PACKAGES_CLASSESLIST);
		return ring_list_getsize(pVM->pClassesMap) + ring_list_getsize(pList);
	}
	return ring_list_getsize(pVM->pClassesMap);
}

List *ring_vm_oop_visibleclassitem(VM *pVM, unsigned int nIndex) {
	List *pList;
	if (nIndex <= ring_list_getsize(pVM->pClassesMap)) {
		return ring_list_getlist(pVM->pClassesMap, nIndex);
	}
	pList = (List *)ring_list_getpointer(pVM->pActivePackage, ring_list_getsize(pVM->pActivePackage));
	pList = ring_list_getlist(pList, RING_PACKAGES_CLASSESLIST);
	pList = ring_list_getlist(pList, nIndex - ring_list_getsize(pVM->pClassesMap));
	return pList;
}

void ring_vm_oop_pushclasspackage(VM *pVM, List *pList) {
	List *pList2;
	pList2 = ring_list_getlist(pList, RING_CLASSMAP_POINTERTOPACKAGE);
	if (pList2 != NULL) {
		ring_list_addpointer_gc(pVM->pRingState, pVM->pActivePackage, pList2);
	}
}

void ring_vm_oop_deletepackagesafter(VM *pVM, unsigned int nIndex) {
	unsigned int t;
	if (nIndex <= ring_list_getsize(pVM->pActivePackage)) {
		for (t = ring_list_getsize(pVM->pActivePackage); t > nIndex; t--) {
			ring_list_deleteitem_gc(pVM->pRingState, pVM->pActivePackage, t);
		}
	}
}

unsigned int ring_vm_oop_callmethodinsideclass(VM *pVM) {
	List *pList, *pList2;
	FuncCall *pFuncCall;
	unsigned int x;
	/*
	**  This function tell us if we are inside Class method during runtime or not
	**  pObjState is used when we Call Method or We use braces { } to access object
	**  if the size of pObjState List is 4 , then it's class method execution not brace
	**  Braces can be used before calling class methods
	**  Also braces can be used inside class methods to access objects
	**  Inside class method you can access any object using { } , you can access the self object
	**  Braces & Methods calls can be nested
	**  Check Calling from function
	*/
	if (RING_VM_FUNCCALLSCOUNT > 0) {
		for (x = RING_VM_FUNCCALLSCOUNT; x >= 1; x--) {
			pFuncCall = RING_VM_GETFUNCCALL(x);
			/* Be sure that the function is already called using ICO_CALL */
			if (pFuncCall->nCallerPC != 0) {
				if (pFuncCall->lMethod == 0) {
					return RING_FALSE;
				} else {
					break;
				}
			}
		}
	}
	/*
	**  pObjState can know about method call if it's called using callmethod
	**  Or it's called from inside { } as function
	**  Return 1 if last item is a method
	*/
	if (pVM->nCurrentObjState >= 1) {
		if ((pVM->aObjState[pVM->nCurrentObjState].lIsMethod) && (pVM->lCallMethod == 0)) {
			return RING_TRUE;
		}
	}
	/* Check using braces { } to access object from a method in the Class */
	if (pVM->nCurrentObjState >= 2) {
		pList = pVM->aObjState[pVM->nCurrentObjState].pClass;
		for (x = pVM->nCurrentObjState - 1; x >= 1; x--) {
			if (pVM->aObjState[x].lIsMethod) {
				pList2 = pVM->aObjState[x].pClass;
				if (pList == pList2) {
					return RING_TRUE;
				} else {
					break;
				}
			}
		}
	}
	return RING_FALSE;
}

void ring_vm_oop_setget(VM *pVM, List *pVar) {
	List *pList, *pList2;
	Item *pGetSetItem;
	String *pString, *pString2;
	RING_VM_IR_ITEMTYPE *pItem;
	unsigned int nIns;
	RING_VM_BYTECODE_START;
	/* Check Setter & Getter for Public Attributes */
	RING_VM_IR_LOAD;
	if (RING_VM_IR_OPCODE != ICO_ASSIGNMENTPOINTER) {
		RING_VM_IR_UNLOAD;
		/*
		**  Get Property
		**  Check to do a Stack POP for the Attribute List
		*/
		pString2 = ring_string_new_gc(pVM->pRingState, "get");
		ring_string_add_gc(pVM->pRingState, pString2, RING_VAR_GETNAME(pVar));
		/* Check Type */
		pList2 = NULL;
		if (pVM->nGetSetObjType == RING_OBJTYPE_VARIABLE) {
			pList2 = RING_VAR_GETLIST((List *)(pVM->pGetSetObject));
		} else if (pVM->nGetSetObjType == RING_OBJTYPE_LISTITEM) {
			pGetSetItem = (Item *)pVM->pGetSetObject;
			pList2 = ring_item_getlist(pGetSetItem);
		}
		if (ring_vm_oop_ismethod(pVM, pList2, ring_string_get(pString2))) {
			/* Create String */
			pString = ring_string_new_gc(pVM->pRingState, "get");
			ring_string_add_gc(pVM->pRingState, pString, RING_VAR_GETNAME(pVar));
			/* Set Variable ring_gettemp_var */
			pList = pVM->pGetTempVar;
			RING_VAR_SETPOINTER_GC(pVM->pRingState, pList, pVM->pGetSetObject);
			RING_VAR_SETPVALUETYPE(pList, pVM->nGetSetObjType);
			RING_VM_STACK_POP;
			if (pVM->lGetSetProperty == 0) {
				/* For Better Performance : Don't Eval() when we call Getter Method from Braces */
				ring_vm_loadfunc2(pVM, ring_string_get(pString2), RING_FALSE);
				ring_vm_call2(pVM);
				/* Prepare the Object State */
				ring_vm_oop_preparecallmethodfrombrace(pVM);
				ring_string_delete_gc(pVM->pRingState, pString2);
				ring_string_delete_gc(pVM->pRingState, pString);
				return;
			}
			if (RING_VM_IR_READIVALUE(RING_VM_IR_REG2) == 0) {
				nIns = pVM->nPC - 2;
				/* Create the Byte Code */
				RING_VM_BYTECODE_INSSTR(ICO_LOADADDRESS, RING_CSTR_GETTEMPVAR);
				RING_VM_BYTECODE_INSSTR(ICO_LOADMETHOD, ring_string_get(pString));
				RING_VM_BYTECODE_INSINTINT(ICO_CALL, RING_ZERO, RING_ONE);
				RING_VM_BYTECODE_INS(ICO_AFTERCALLMETHOD);
				RING_VM_BYTECODE_INS(ICO_PUSHV);
				RING_VM_BYTECODE_INS(ICO_RETURN);
				/* Use the Byte Code */
				RING_VM_BYTECODE_END;
				/* Note: Reallocation may change mem. locations */
				pItem = RING_VM_IR_ITEMATINS(nIns, RING_VM_IR_REG2);
				RING_VM_IR_ITEMSETINT(pItem, pVM->nPC);
			} else {
				ring_vm_blockflag2(pVM, pVM->nPC);
				pVM->nPC = RING_VM_IR_READIVALUE(RING_VM_IR_REG2);
			}
			/* Delete String */
			ring_string_delete_gc(pVM->pRingState, pString);
		}
		ring_string_delete_gc(pVM->pRingState, pString2);
	} else {
		RING_VM_IR_UNLOAD;
		/*
		**  Set Property
		**  Delete All Items to avoid a memory leak in real time applications
		*/
		ring_list_deleteallitems_gc(pVM->pRingState, pVM->pSetProperty);
		pList = ring_list_newlist_gc(pVM->pRingState, pVM->pSetProperty);
		/* Add object pointer & Type */
		ring_list_addpointer_gc(pVM->pRingState, pList, pVM->pGetSetObject);
		ring_list_addint_gc(pVM->pRingState, pList, pVM->nGetSetObjType);
		/* Add property name */
		ring_list_addstring_gc(pVM->pRingState, pList, RING_VAR_GETNAME(pVar));
		/* Property Variable */
		ring_list_addpointer_gc(pVM->pRingState, pList, pVar);
		/*
		**  Check if we don't have the Setter Method
		**  We do this to enable the Assignment Pointer and Disable Set Property for Lists and Objects
		*/
		pString2 = ring_string_new_gc(pVM->pRingState, "set");
		ring_string_add_gc(pVM->pRingState, pString2, RING_VAR_GETNAME(pVar));
		/* Check Type */
		pList2 = NULL;
		if (pVM->nGetSetObjType == RING_OBJTYPE_VARIABLE) {
			pList2 = RING_VAR_GETLIST((List *)(pVM->pGetSetObject));
		} else if (pVM->nGetSetObjType == RING_OBJTYPE_LISTITEM) {
			pGetSetItem = (Item *)pVM->pGetSetObject;
			pList2 = ring_item_getlist(pGetSetItem);
		}
		pVM->nNoSetterMethod = RING_NOSETTERMETHOD_DEFAULT;
		if (!ring_vm_oop_ismethod(pVM, pList2, ring_string_get(pString2))) {
			pVM->nNoSetterMethod = RING_NOSETTERMETHOD_ENABLE;
		}
		ring_string_delete_gc(pVM->pRingState, pString2);
	}
}

void ring_vm_oop_setproperty(VM *pVM) {
	List *pList, *pList2;
	Item *pGetSetItem;
	String *pString, *pString2;
	unsigned int nIns;
	RING_VM_BYTECODE_START;
	/* If we don't have a setter method and we have a new list or new object */
	if (pVM->nNoSetterMethod == RING_NOSETTERMETHOD_IGNORESETPROPERTY) {
		pVM->nNoSetterMethod = RING_NOSETTERMETHOD_DEFAULT;
		return;
	}
	/* To Access Property Data */
	if (ring_list_getsize(pVM->pSetProperty) < 1) {
		/* This case happens when using This.Attribute inside nested braces in a class method */
		ring_vm_assignment(pVM);
		return;
	}
	pList = ring_list_getlist(pVM->pSetProperty, ring_list_getsize(pVM->pSetProperty));
	/* Add Before Equal Flag */
	if (ring_list_getsize(pList) == 4) {
		ring_list_addint_gc(pVM->pRingState, pList, pVM->nBeforeEqual);
	}
	/* Before (First Time) */
	if (RING_VM_IR_GETFLAGREG2 == RING_FALSE) {
		/* Set Before/After SetProperty Flag to After */
		RING_VM_IR_SETFLAGREG2(RING_TRUE);
		/* Set Variable ring_gettemp_var */
		pList2 = pVM->pGetTempVar;
		RING_VAR_SETPOINTER_GC(pVM->pRingState, pList2, ring_list_getpointer(pList, RING_SETPROPERTY_OBJPTR));
		RING_VAR_SETPVALUETYPE(pList2, ring_list_getint(pList, RING_SETPROPERTY_OBJTYPE));
		/* Set Variable ring_settemp_var */
		pList2 = pVM->pSetTempVar;
		if (RING_VM_STACK_ISNUMBER) {
			RING_VAR_SETTYPE(pList2, RING_VM_NUMBER);
			RING_VAR_SETNUMBER_GC(pVM->pRingState, pList2, RING_VM_STACK_READN);
			ring_list_adddouble_gc(pVM->pRingState, pList, RING_VM_STACK_READN);
		} else if (RING_VM_STACK_ISSTRING) {
			RING_VAR_SETTYPE(pList2, RING_VM_STRING);
			RING_VAR_SETSTRING2_GC(pVM->pRingState, pList2, RING_VM_STACK_READC, RING_VM_STACK_STRINGSIZE);
			ring_list_addstring2_gc(pVM->pRingState, pList, RING_VM_STACK_READC, RING_VM_STACK_STRINGSIZE);
		} else if (RING_VM_STACK_ISPOINTER) {
			RING_VAR_SETTYPE(pList2, RING_VM_POINTER);
			RING_VAR_SETPOINTER_GC(pVM->pRingState, pList2, RING_VM_STACK_READP);
			RING_VAR_SETPVALUETYPE(pList2, RING_VM_STACK_OBJTYPE);
			ring_list_addpointer_gc(pVM->pRingState, pList, RING_VM_STACK_READP);
			ring_list_addint_gc(pVM->pRingState, pList, RING_VM_STACK_OBJTYPE);
		}
		/* Set the Flag Register to Zero */
		RING_VM_IR_SETFLAGREG(0);
		/* Check if the Setter method exist */
		pString2 = ring_string_new_gc(pVM->pRingState, "set");
		ring_string_add_gc(pVM->pRingState, pString2, ring_list_getstring(pList, RING_SETPROPERTY_ATTRNAME));
		/* Check Type */
		pList2 = NULL;
		if (ring_list_getint(pList, RING_SETPROPERTY_OBJTYPE) == RING_OBJTYPE_VARIABLE) {
			pList2 = RING_VAR_GETLIST((List *)(ring_list_getpointer(pList, RING_SETPROPERTY_OBJPTR)));
		} else if (ring_list_getint(pList, RING_SETPROPERTY_OBJTYPE) == RING_OBJTYPE_LISTITEM) {
			pGetSetItem = (Item *)ring_list_getpointer(pList, RING_SETPROPERTY_OBJPTR);
			pList2 = ring_item_getlist(pGetSetItem);
		}
		/* The Flag Reg size is 1 bit while ring_vm_oop_ismethod could return 0, 1 or 2 */
		RING_VM_IR_SETFLAGREG(ring_vm_oop_ismethod(pVM, pList2, ring_string_get(pString2)) !=
				      RING_ISMETHOD_NOTFOUND);
		ring_string_delete_gc(pVM->pRingState, pString2);
		/* Execute the same instruction again (next time the part "After (Second Time)" will run ) */
		pVM->nPC--;
		if (RING_VM_IR_GETFLAGREG) {
			if (RING_VM_IR_GETINTREG == RING_ZERO) {
				/* Create String */
				pString = ring_string_new_gc(pVM->pRingState, "set");
				ring_string_add_gc(pVM->pRingState, pString,
						   ring_list_getstring(pList, RING_SETPROPERTY_ATTRNAME));
				/*
				**  Get Instruction Position
				**  We use -1 instead of -2 because we already used pVM->nPC--
				*/
				nIns = pVM->nPC - 1;
				/* Create the Byte Code */
				RING_VM_BYTECODE_INSSTR(ICO_LOADADDRESS, RING_CSTR_GETTEMPVAR);
				RING_VM_BYTECODE_INSSTR(ICO_LOADMETHOD, ring_string_get(pString));
				RING_VM_BYTECODE_INSSTR(ICO_LOADAPUSHV, RING_CSTR_SETTEMPVAR);
				RING_VM_BYTECODE_INSINTINT(ICO_CALL, RING_ZERO, RING_ONE);
				RING_VM_BYTECODE_INS(ICO_AFTERCALLMETHOD);
				RING_VM_BYTECODE_INS(ICO_PUSHV);
				RING_VM_BYTECODE_INS(ICO_RETURN);
				/* Use the Byte Code */
				RING_VM_BYTECODE_END;
				/* Note: Reallocation may change mem. locations */
				RING_VM_IR_SETINTREGATINS(nIns, pVM->nPC);
				/* Delete String */
				ring_string_delete_gc(pVM->pRingState, pString);
			} else {
				ring_vm_blockflag2(pVM, pVM->nPC);
				pVM->nPC = RING_VM_IR_GETINTREG;
			}
		}
	}
	/* After (Second Time) */
	else {
		/* Set Before/After SetProperty Flag to Before */
		RING_VM_IR_SETFLAGREG2(RING_FALSE);
		if (!RING_VM_IR_GETFLAGREG) {
			/*
			**  The set method is not found!, we have to do the assignment operation
			**  Push Variable Then Push Value then Assignment
			*/
			RING_VM_STACK_PUSHPVALUE(ring_list_getpointer(pList, RING_SETPROPERTY_ATTRVAR));
			RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE;
			/* Restore Before Equal Flag */
			pVM->nBeforeEqual = ring_list_getint(pList, RING_SETPROPERTY_NBEFOREEQUAL);
			/* Push Value */
			if (ring_list_isdouble(pList, RING_SETPROPERTY_VALUE)) {
				RING_VM_STACK_PUSHNVALUE(ring_list_getdouble(pList, RING_SETPROPERTY_VALUE));
			} else if (ring_list_isstring(pList, RING_SETPROPERTY_VALUE)) {
				RING_VM_STACK_PUSHCVALUE2(ring_list_getstring(pList, RING_SETPROPERTY_VALUE),
							  ring_list_getstringsize(pList, RING_SETPROPERTY_VALUE));
			} else if (ring_list_ispointer(pList, RING_SETPROPERTY_VALUE)) {
				RING_VM_STACK_PUSHPVALUE(ring_list_getpointer(pList, RING_SETPROPERTY_VALUE));
				RING_VM_STACK_OBJTYPE = ring_list_getint(pList, RING_SETPROPERTY_VALUEOBJTYPE);
			}
			ring_vm_assignment(pVM);
		}
		ring_list_deleteitem_gc(pVM->pRingState, pVM->pSetProperty, ring_list_getsize(pVM->pSetProperty));
	}
}

List *ring_vm_oop_objvarfromobjlist(VM *pVM, List *pList) {
	unsigned int nType;
	Item *pItem;
	/* Get Object State List */
	pList = RING_OBJECT_GETOBJECTDATA(pList);
	/* Get Self Attribute List */
	pList = RING_OBJECT_GETSELFATTRIBUTE(pList);
	/* Get Object Pointer from Self Attribute List */
	nType = RING_VAR_GETPVALUETYPE(pList);
	if (nType == RING_OBJTYPE_VARIABLE) {
		pList = (List *)RING_VAR_GETPOINTER(pList);
	} else if (nType == RING_OBJTYPE_LISTITEM) {
		pItem = (Item *)RING_VAR_GETPOINTER(pList);
		pList = (List *)ring_item_getlist(pItem);
	}
	return pList;
}

unsigned int ring_vm_oop_objtypefromobjlist(VM *pVM, List *pList) {
	unsigned int nType;
	/* Get Object State List */
	pList = RING_OBJECT_GETOBJECTDATA(pList);
	/* Get Self Attribute List */
	pList = RING_OBJECT_GETSELFATTRIBUTE(pList);
	/* Get Object Type from Self Attribute List */
	nType = RING_VAR_GETPVALUETYPE(pList);
	return nType;
}

Item *ring_vm_oop_objitemfromobjlist(VM *pVM, List *pList) {
	Item *pItem;
	/* Get Object State List */
	pList = RING_OBJECT_GETOBJECTDATA(pList);
	/* Get Self Attribute List */
	pList = RING_OBJECT_GETSELFATTRIBUTE(pList);
	/* Get Object Pointer from Self Attribute List */
	pItem = (Item *)RING_VAR_GETPOINTER(pList);
	return pItem;
}

void ring_vm_oop_operatoroverloading(VM *pVM, List *pObj, const char *cStr1, unsigned int nType, const char *cStr2,
				     double nNum1, void *pPointer, unsigned int nPointerType) {
	RING_VM_STACK_POP;
	/* Check Method */
	if (!ring_vm_oop_ismethod(pVM, pObj, RING_CSTR_OPERATOR)) {
		ring_vm_error(pVM, RING_VM_ERROR_NOOPERATORMETHOD);
		return;
	}
	ring_vm_oop_operatoroverloading2(pVM, pObj, cStr1, nType, cStr2, nNum1, pPointer, nPointerType);
}

void ring_vm_oop_operatoroverloading2(VM *pVM, List *pObj, const char *cStr1, unsigned int nType, const char *cStr2,
				      double nNum1, void *pPointer, unsigned int nPointerType) {
	List *pList2;
	Item *pItem;
	unsigned int nObjType, nIns;
	RING_VM_BYTECODE_START;
	nObjType = ring_vm_oop_objtypefromobjlist(pVM, pObj);
	/* Set Variable ring_gettemp_var */
	pList2 = pVM->pGetTempVar;
	if (nObjType == RING_OBJTYPE_VARIABLE) {
		pObj = ring_vm_oop_objvarfromobjlist(pVM, pObj);
		RING_VAR_SETPOINTER_GC(pVM->pRingState, pList2, pObj);
	} else if (nObjType == RING_OBJTYPE_LISTITEM) {
		pItem = ring_vm_oop_objitemfromobjlist(pVM, pObj);
		RING_VAR_SETPOINTER_GC(pVM->pRingState, pList2, pItem);
	}
	RING_VAR_SETPVALUETYPE(pList2, nObjType);
	/* Set Variable ring_settemp_var */
	pList2 = pVM->pSetTempVar;
	if (nType == RING_OOPARA_STRING) {
		RING_VAR_SETTYPE(pList2, RING_VM_STRING);
		RING_VAR_SETSTRING_GC(pVM->pRingState, pList2, cStr2);
	} else if (nType == RING_OOPARA_NUMBER) {
		RING_VAR_SETTYPE(pList2, RING_VM_NUMBER);
		RING_VAR_SETNUMBER_GC(pVM->pRingState, pList2, nNum1);
	} else if (nType == RING_OOPARA_POINTER) {
		RING_VAR_SETTYPE(pList2, RING_VM_POINTER);
		RING_VAR_SETPOINTER_GC(pVM->pRingState, pList2, pPointer);
		RING_VAR_SETPVALUETYPE(pList2, nPointerType);
	}
	/* Get instruction position */
	nIns = pVM->nPC - 2;
	if (RING_VM_IR_INTATINS(nIns) == 0) {
		/* Create the Byte Code */
		RING_VM_BYTECODE_INSSTR(ICO_LOADADDRESS, RING_CSTR_GETTEMPVAR);
		RING_VM_BYTECODE_INSSTR(ICO_LOADMETHOD, RING_CSTR_OPERATOR);
		RING_VM_BYTECODE_INSSTR(ICO_PUSHC, cStr1);
		RING_VM_BYTECODE_INSSTR(ICO_LOADAPUSHV, RING_CSTR_SETTEMPVAR);
		RING_VM_BYTECODE_INSINTINT(ICO_CALL, RING_ZERO, RING_ONE);
		RING_VM_BYTECODE_INS(ICO_AFTERCALLMETHOD);
		RING_VM_BYTECODE_INS(ICO_PUSHV);
		RING_VM_BYTECODE_INS(ICO_RETURN);
		/* Use the Byte Code */
		RING_VM_BYTECODE_END;
		/* Note: Reallocation may change mem. locations */
		RING_VM_IR_INTATINS(nIns) = pVM->nPC;
	} else {
		ring_vm_blockflag2(pVM, pVM->nPC);
		pVM->nPC = RING_VM_IR_INTATINS(nIns);
	}
}

void ring_vm_oop_callmethodfrombrace(VM *pVM) {
	ByteCode *pByteCodeIR;
	/*
	**  We uses AfterCallMethod2 instead of AfterCallMethod to avoid conflict with normal method call
	**  AfterCallMethod2 is the same instruction as AfterCallMethod
	**  Change NOOP to After Call Method2
	*/
	pByteCodeIR = pVM->pByteCodeIR;
	RING_VM_IR_LOAD;
	if ((RING_VM_IR_OPCODE == ICO_NOOP) || (RING_VM_IR_OPCODE == ICO_AFTERCALLMETHOD2)) {
		RING_VM_IR_OPCODE = ICO_AFTERCALLMETHOD2;
		ring_vm_oop_preparecallmethodfrombrace(pVM);
	}
	pVM->pByteCodeIR = pByteCodeIR;
}

void ring_vm_oop_preparecallmethodfrombrace(VM *pVM) {
	unsigned int nSrcIndex;
	FuncCall *pFuncCall;
	const char *cStr;
	List *pList;
	nSrcIndex = pVM->nCurrentObjState;
	/* Pass Brace when we call class init , using new object() */
	if ((pVM->nCurrentObjState > 1) && (pVM->nCallClassInit)) {
		if (RING_VM_FUNCCALLSCOUNT > 0) {
			pFuncCall = RING_VM_LASTFUNCCALL;
			cStr = pFuncCall->cName;
			if (strcmp(cStr, RING_CSTR_INIT) != 0) {
				nSrcIndex = pVM->nCurrentObjState - 1;
			}
		} else {
			nSrcIndex = pVM->nCurrentObjState - 1;
		}
	}
	pVM->nCurrentObjState++;
	if (pVM->nCurrentObjState > RING_VM_STACK_CHECKOVERFLOW) {
		ring_vm_error(pVM, RING_VM_ERROR_STACKOVERFLOW);
		return;
	}
	pVM->aObjState[pVM->nCurrentObjState] = pVM->aObjState[nSrcIndex];
	pVM->aObjState[pVM->nCurrentObjState].lIsMethod = RING_TRUE;
	/* Push Class Package */
	pList = pVM->aObjState[pVM->nCurrentObjState].pClass;
	ring_vm_oop_pushclasspackage(pVM, pList);
}

unsigned int ring_vm_oop_isattribute(VM *pVM, List *pList, const char *cStr) {
	unsigned int x;
	pList = RING_OBJECT_GETOBJECTDATA(pList);
	return ring_vm_findvarusinghashtable(pVM, pList, cStr) != NULL;
}

unsigned int ring_vm_oop_ismethod(VM *pVM, List *pList, const char *cStr) {
	List *pList2, *pList3;
	unsigned int x;
	/* Get Object Class */
	pList = (List *)RING_OBJECT_GETCLASSPOINTER(pList);
	/* Get Class Methods */
	pList2 = ring_list_getlist(pList, RING_CLASSMAP_METHODSLIST);
	/* Get Parent Classes Methods */
	ring_vm_oop_parentmethods(pVM, pList);
	/* Find the Method */
	pList3 = ring_vm_findfuncusinghashtable(pVM, pList2, cStr);
	if (pList3 != NULL) {
		if (ring_list_getint(pList3, RING_FUNCMAP_PRIVATEFLAG)) {
			return RING_ISMETHOD_PRIVATEMETHOD;
		}
		return RING_ISMETHOD_PUBLICMETHOD;
	}
	return RING_ISMETHOD_NOTFOUND;
}

unsigned int ring_vm_oop_cachedismethod(VM *pVM, VMState *pVMState, const char *cMethod) {
	unsigned int nSlot, nBit, lResult, lMask;
	switch (cMethod[5]) {
	case 's':
		nSlot = RING_BRACEOBJECTS_BRACESTART;
		nBit = RING_BRACEBIT_BRACESTART;
		break;
	case 'n':
		nSlot = RING_BRACEOBJECTS_BRACENEWLINE;
		nBit = RING_BRACEBIT_BRACENEWLINE;
		break;
	case 'e':
	default:
		switch (cMethod[6]) {
		case 'n':
			nSlot = RING_BRACEOBJECTS_BRACEEND;
			nBit = RING_BRACEBIT_BRACEEND;
			break;
		case 'x':
			nSlot = RING_BRACEOBJECTS_BRACEEXPREVAL;
			nBit = RING_BRACEBIT_BRACEEXPREVAL;
			break;
		default:
			nSlot = RING_BRACEOBJECTS_BRACEERROR;
			nBit = RING_BRACEBIT_BRACEERROR;
		}
	}
	lMask = pVMState->aNumbers[RING_BRACEOBJECTS_VALIDMASK];
	if (lMask & (RING_ONE << nBit)) {
		return pVMState->aNumbers[nSlot];
	}
	lResult = ring_vm_oop_ismethod(pVM, (List *)pVMState->aPointers[RING_BRACEOBJECTS_BRACEOBJECT], cMethod);
	pVMState->aNumbers[nSlot] = lResult;
	pVMState->aNumbers[RING_BRACEOBJECTS_VALIDMASK] = lMask | (RING_ONE << nBit);
	return lResult;
}

void ring_vm_oop_updateselfpointer(VM *pVM, List *pObj, unsigned int nType, void *pContainer) {
	List *pList;
	/* Get Object State */
	pList = RING_OBJECT_GETOBJECTDATA(pObj);
	/* Get Self Attribute */
	pList = RING_OBJECT_GETSELFATTRIBUTE(pList);
	/* Set Object Pointer */
	RING_VAR_SETPOINTER_GC(pVM->pRingState, pList, pContainer);
	/* Set Object Type */
	RING_VAR_SETPVALUETYPE(pList, nType);
}

void ring_vm_oop_setthethisvariable(VM *pVM) {
	List *pList, *pThis;
	pThis = pVM->pThis;
	if ((pVM->nCurrentObjState < 1) || (ring_vm_oop_callmethodinsideclass(pVM) == 0)) {
		RING_VAR_SETPOINTER_GC(pVM->pRingState, pThis, NULL);
		RING_VAR_SETPVALUETYPE(pThis, RING_OBJTYPE_NOTYPE);
		return;
	}
	/* Get Object Scope */
	pList = pVM->aObjState[pVM->nCurrentObjState].pScope;
	if (pList == NULL) {
		RING_VAR_SETPOINTER_GC(pVM->pRingState, pThis, NULL);
		RING_VAR_SETPVALUETYPE(pThis, RING_OBJTYPE_NOTYPE);
		return;
	}
	/* Get Self Attribute List */
	pList = RING_OBJECT_GETSELFATTRIBUTE(pList);
	/* Save this */
	RING_VAR_SETPOINTER_GC(pVM->pRingState, pThis, RING_VAR_GETPOINTER(pList));
	RING_VAR_SETPVALUETYPE(pThis, RING_VAR_GETPVALUETYPE(pList));
}

void ring_vm_oop_setthethisvariableinclassregion(VM *pVM) {
	List *pList, *pThis;
	pThis = pVM->pThis;
	/* Get Object Scope */
	pList = pVM->aObjState[pVM->nCurrentObjState].pScope;
	/* Get Self Attribute List */
	pList = RING_OBJECT_GETSELFATTRIBUTE(pList);
	/* Save this */
	RING_VAR_SETPOINTER_GC(pVM->pRingState, pThis, RING_VAR_GETPOINTER(pList));
	/* Create the Temp Variable for the new object */
	RING_VAR_SETPVALUETYPE(pThis, RING_VAR_GETPVALUETYPE(pList));
}

unsigned int ring_vm_oop_callingclassmethodfromclassregion(VM *pVM, List *pMethods) {
	List *pList, *pThis, *pClass, *pVar;
	Item *pItem;
	if (pVM->nInClassRegion != 0) {
		pThis = pVM->pThis;
		if (pThis == NULL) {
			return RING_FALSE;
		}
		if (RING_VAR_GETPVALUETYPE(pThis) == RING_OBJTYPE_VARIABLE) {
			pVar = (List *)RING_VAR_GETPOINTER(pThis);
			pList = RING_VAR_GETLIST(pVar);
		} else if (RING_VAR_GETPVALUETYPE(pThis) == RING_OBJTYPE_LISTITEM) {
			pItem = (Item *)RING_VAR_GETPOINTER(pThis);
			if (pItem == NULL) {
				return RING_FALSE;
			}
			pList = ring_item_getlist(pItem);
		} else {
			return RING_FALSE;
		}
		if (pList == NULL) {
			return RING_FALSE;
		}
		/* Get Object Class */
		pClass = (List *)RING_OBJECT_GETCLASSPOINTER(pList);
		if (pClass == NULL) {
			return RING_FALSE;
		}
		if (ring_list_getsize(pClass) == 0) {
			return RING_FALSE;
		}
		/* Get Class Methods */
		pList = ring_list_getlist(pClass, RING_CLASSMAP_METHODSLIST);
		if (pList == pMethods) {
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}

void ring_vm_oop_callclassinit(VM *pVM) {
	if (RING_VM_IR_READIVALUE(RING_VM_IR_REG1)) {
		pVM->nCallClassInit++;
	} else {
		pVM->nCallClassInit--;
	}
}

void ring_vm_oop_checkbracemethod(VM *pVM) {
	VMState *pVMState;
	unsigned int lResult;
	pVMState = (VMState *)ring_list_getpointer(pVM->pBraceObjects, ring_list_getsize(pVM->pBraceObjects));
	lResult = ring_vm_oop_cachedismethod(pVM, pVMState, RING_VM_IR_READC);
	RING_VM_STACK_PUSHNVALUE(lResult);
}

unsigned int ring_vm_oop_addattribute(VM *pVM, List *pList, char *cStr) {
	if (ring_vm_oop_isattribute(pVM, pList, cStr)) {
		ring_vm_error(pVM, RING_VM_ERROR_ATTRREDEFINE);
		return RING_FALSE;
	}
	pList = RING_OBJECT_GETOBJECTDATA(pList);
	ring_general_lower(cStr);
	ring_vm_newvar2(pVM, cStr, pList);
	return RING_TRUE;
}

void ring_vm_oop_cleansetpropertylist(VM *pVM) {
	if (ring_list_getsize(pVM->pSetProperty) > 0) {
		ring_list_deleteitem_gc(pVM->pRingState, pVM->pSetProperty, ring_list_getsize(pVM->pSetProperty));
	}
}

int ring_vm_oop_internalcallforbracemethod(VM *pVM, const char *cMethod) {
	VMState *pVMState;
	if (pVM->nCurrentObjState && ring_list_getsize(pVM->pBraceObjects) && (pVM->lCallMethod == 0) &&
	    (ring_vm_oop_callmethodinsideclass(pVM) == 0)) {
		pVMState = (VMState *)ring_list_getpointer(pVM->pBraceObjects, ring_list_getsize(pVM->pBraceObjects));
		if (ring_vm_oop_cachedismethod(pVM, pVMState, cMethod)) {
			RING_VM_STACK_POP;
			ring_vm_callfuncwithouteval(pVM, cMethod, RING_TRUE);
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}

void ring_vm_oop_pushobjstate(VM *pVM, List *pScope, List *pMethods, List *pClass, unsigned int lIsMethod) {
	pVM->nCurrentObjState++;
	if (pVM->nCurrentObjState > RING_VM_STACK_CHECKOVERFLOW) {
		ring_vm_error(pVM, RING_VM_ERROR_STACKOVERFLOW);
		return;
	}
	pVM->aObjState[pVM->nCurrentObjState].pScope = pScope;
	pVM->aObjState[pVM->nCurrentObjState].pMethods = pMethods;
	pVM->aObjState[pVM->nCurrentObjState].pClass = pClass;
	pVM->aObjState[pVM->nCurrentObjState].lIsMethod = lIsMethod;
}
