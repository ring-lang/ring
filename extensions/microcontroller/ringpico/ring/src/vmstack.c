/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_pushv ( VM *pVM )
{
	List *pList  ;
	if ( pVM->nSP <= pVM->nFuncSP ) {
		/*
		**  Happens after using EVAL() in this case we avoid PUSHV 
		**  Add Output Value (if Eval() parameter (Code to be executed) miss the Return <Expr> command) 
		*/
		RING_VM_STACK_PUSHCVALUE(RING_CSTR_EMPTY) ;
		return ;
	}
	if ( ! RING_VM_STACK_ISPOINTER ) {
		return ;
	}
	switch ( RING_VM_STACK_OBJTYPE ) {
		case RING_OBJTYPE_VARIABLE :
			if ( ! ring_vm_checknull(pVM,RING_CHECKNULL_SHOWERROR) ) {
				ring_vm_varpushv(pVM);
			}
			break ;
		case RING_OBJTYPE_LISTITEM :
			ring_vm_listpushv(pVM);
			break ;
		case RING_OBJTYPE_SUBSTRING :
			ring_vm_string_pushv(pVM);
			break ;
	}
}

int ring_vm_checknull ( VM *pVM,int lShowError )
{
	List *pVar  ;
	String *pString  ;
	pVar = (List *) RING_VM_STACK_READP ;
	/* Check NULL Value */
	if ( (pVM->nInClassRegion == 0) && (ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL) && ( ring_list_isstring(pVar,RING_VAR_VALUE) ) ) {
		if ( strcmp(ring_list_getstring(pVar,RING_VAR_VALUE),RING_CSTR_NULL) == 0 ) {
			if ( lShowError ) {
				/*
				**  We create pString because ring_vm_error2() could interact with Try/Catch and change the State 
				**  So we check pVM->pActiveMem before calling ring_vm_error2() function 
				*/
				pString = ring_string_new2_gc(pVM->pRingState,ring_list_getstring(pVar,RING_VAR_NAME),ring_list_getstringsize(pVar,RING_VAR_NAME));
				if ( ring_list_islist(pVM->pActiveMem,ring_list_getsize(pVM->pActiveMem)) ) {
					if ( ring_list_getlist(pVM->pActiveMem,ring_list_getsize(pVM->pActiveMem)) == pVar ) {
						/* Delete the Item from the HashTable */
						if ( pVM->pActiveMem->pHashTable != NULL ) {
							ring_hashtable_deleteitem_gc(pVM->pRingState,pVM->pActiveMem->pHashTable,ring_list_getstring(pVar,RING_VAR_NAME));
						}
						/* Delete the variable from the active scope */
						ring_list_deletelastitem_gc(pVM->pRingState,pVM->pActiveMem);
						/* We deleted the variable, so we remove it from the Stack to avoid usage after delete */
						RING_VM_STACK_POP ;
						/* We replace it with NULL */
						RING_VM_STACK_PUSHCVALUE(RING_CSTR_EMPTY);
					}
				}
				ring_vm_error2(pVM,RING_VM_ERROR_USINGNULLVARIABLE,ring_string_get(pString));
				ring_string_delete_gc(pVM->pRingState,pString);
			}
			return 1 ;
		}
	}
	return 0 ;
}

void ring_vm_varpushv ( VM *pVM )
{
	List *pVar, *pList  ;
	pVar = (List *) RING_VM_STACK_READP ;
	/* We don't use POP, because PUSHCVAR and PUSHNVAR don't do SP++ */
	switch ( ring_list_gettype(pVar,RING_VAR_VALUE) ) {
		case ITEMTYPE_NUMBER :
			RING_VM_STACK_PUSHNVAR ;
			break ;
		case ITEMTYPE_STRING :
			RING_VM_STACK_PUSHCVAR ;
			break ;
		case ITEMTYPE_LIST :
			/* Support using { } to access object after object name */
			pList = ring_list_getlist(pVar,RING_VAR_VALUE) ;
			ring_vm_oop_setbraceobj(pVM,pList);
			break ;
	}
}

void ring_vm_loadaddress ( VM *pVM )
{
	int x,lFound  ;
	FuncCall *pFuncCall  ;
	lFound = ring_vm_findvar(pVM, RING_VM_IR_READC ) ;
	if ( lFound == 0 ) {
		ring_vm_newvar(pVM, RING_VM_IR_READC);
		/* Support for private attributes */
		ring_vm_var_setprivateflag(pVM,(List *) RING_VM_STACK_READP,pVM->lPrivateFlag);
	}
	/* Don't change instruction if it's LoadAFirst */
	if ( (pVM->lFirstAddress == 1) || (lFound == 0) ) {
		return ;
	}
	if ( pVM->nVarScope == RING_VARSCOPE_GLOBAL ) {
		if ( strcmp(RING_VM_IR_READC,RING_CSTR_THIS) != 0 ) {
			/* Replace LoadAddress with PUSHP for better performance */
			RING_VM_IR_OPCODE = ICO_PUSHP ;
			RING_VM_IR_SETREG1TOPOINTERFROMSTACK ;
			/* Check if we have ICO_PUSHV */
			RING_VM_IR_SETFLAGREG2(RING_VM_IR_OPCODEVALUE(pVM->nPC - 1) == ICO_PUSHV);
		}
	}
	else if ( pVM->nVarScope == RING_VARSCOPE_LOCAL ) {
		if ( ring_vm_isinsideloop(pVM) ) {
			/* Replace LoadAddress with PUSHPLOCAL for better performance */
			RING_VM_IR_OPCODE = ICO_PUSHPLOCAL ;
			RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(RING_VM_IR_REG2),RING_VM_STACK_READP);
			RING_VM_IR_SETINTREG(pVM->nActiveScopeID);
			RING_VM_IR_SETREG2TYPE(RING_VM_REGTYPE_POINTER);
			/* Check if we have ICO_PUSHV */
			RING_VM_IR_SETFLAGREG2(RING_VM_IR_OPCODEVALUE(pVM->nPC - 1) == ICO_PUSHV);
		}
		else if ( ! RING_VM_IR_GETFLAGREG ) {
			RING_VM_IR_SETFLAGREG(RING_TRUE);
			/* Check if we can use ICO_PUSHARG */
			for ( x = 1 ; x <= ring_vm_funccall_paracount(pVM) ; x++ ) {
				if ( x <= ring_list_getsize(pVM->pActiveMem) && ring_list_islist(pVM->pActiveMem,x) ) {
					if ( ring_list_getlist(pVM->pActiveMem,x) == RING_VM_STACK_READP ) {
						RING_VM_IR_OPCODE = ICO_PUSHARG ;
						RING_VM_IR_SETINTREG(x);
						RING_VM_IR_SETSMALLINTREG(ring_list_getlisttype(((List *) RING_VM_STACK_READP)));
						/* Check if we have ICO_PUSHV */
						RING_VM_IR_SETFLAGREG2(RING_VM_IR_OPCODEVALUE(pVM->nPC - 1) == ICO_PUSHV);
						break ;
					}
				}
			}
		}
	}
	/* Save Scope in nLoadAddressScope */
	if ( pVM->nLoadAddressScope == RING_VARSCOPE_NOTHING ) {
		pVM->nLoadAddressScope = pVM->nVarScope ;
	}
}

void ring_vm_assignment ( VM *pVM )
{
	List *pVar,*pList, *pList2  ;
	String *pStr1, *pString  ;
	double nNum1  ;
	Item *pItem  ;
	int nBeforeEqual  ;
	nBeforeEqual = pVM->nBeforeEqual ;
	pVM->nBeforeEqual = OP_EQUAL ;
	switch ( RING_VM_STACK_PREVOBJTYPE ) {
		case RING_OBJTYPE_SUBSTRING :
			if ( nBeforeEqual == OP_EQUAL ) {
				ring_vm_string_assignment(pVM);
			}
			else {
				ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
			}
			break ;
		case RING_OBJTYPE_LISTITEM :
			ring_vm_listassignment(pVM,nBeforeEqual);
			break ;
		case RING_OBJTYPE_VARIABLE :
			if ( (RING_VM_STACK_ISSTRING) && (nBeforeEqual <= OP_PLUSEQUAL ) ) {
				pStr1 = RING_VM_STACK_GETSTRINGRAW ;
				RING_VM_STACK_POP ;
				pVar = (List *) RING_VM_STACK_READP ;
				RING_VM_STACK_POP ;
				/* Check Before Assignment */
				if ( ring_vm_checkbeforeassignment(pVM,pVar) ) {
					return ;
				}
				if ( nBeforeEqual == OP_EQUAL ) {
					ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_STRING);
					ring_list_setstring2_gc(pVM->pRingState,pVar, RING_VAR_VALUE , ring_string_get(pStr1),ring_string_size(pStr1));
				}
				else {
					/* Check NULL Variable */
					if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL ) {
						ring_vm_error2(pVM,RING_VM_ERROR_USINGNULLVARIABLE,ring_list_getstring(pVar,RING_VAR_NAME));
						return ;
					}
					if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
						pString = ring_list_getstringobject(pVar,RING_VAR_VALUE);
						ring_string_add2_gc(pVM->pRingState,pString,ring_string_get(pStr1),ring_string_size(pStr1));
					}
					else if ( ring_list_isnumber(pVar,RING_VAR_VALUE) ) {
						ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) +ring_vm_stringtonum(pVM,ring_string_get(pStr1)));
					}
				}
			}
			else if ( RING_VM_STACK_ISNUMBER ) {
				nNum1 = RING_VM_STACK_READN ;
				RING_VM_STACK_POP ;
				pVar = (List *) RING_VM_STACK_READP ;
				RING_VM_STACK_POP ;
				/* Check Before Assignment */
				if ( ring_vm_checkbeforeassignment(pVM,pVar) ) {
					return ;
				}
				if ( nBeforeEqual == OP_EQUAL ) {
					ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_NUMBER);
					ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , nNum1);
				}
				else {
					/* Check NULL Variable */
					if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL ) {
						ring_vm_error2(pVM,RING_VM_ERROR_USINGNULLVARIABLE,ring_list_getstring(pVar,RING_VAR_NAME));
						return ;
					}
					ring_vm_beforeequallist(pVM,pVar,nNum1,nBeforeEqual);
				}
			}
			else if ( (RING_VM_STACK_ISPOINTER) && (nBeforeEqual == OP_EQUAL ) ) {
				if ( (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) || (RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM) ) {
					/* Get The Source List */
					if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
						pVar = ring_list_getlist((List *) RING_VM_STACK_READP,RING_VAR_VALUE);
					}
					else {
						pItem = (Item *) RING_VM_STACK_READP ;
						pVar = ring_item_getlist(pItem);
					}
					RING_VM_STACK_POP ;
					/* Check if we are assigning the list to itself */
					if ( ring_list_getlist((List *) RING_VM_STACK_READP,RING_VAR_VALUE) == pVar ) {
						return ;
					}
					if ( ring_list_isref(pVar) || ring_list_iscopybyref(pVar) ) {
						pList = pVar ;
					}
					else {
						/* We use (Temp) List - to avoid problems when coping from parent list to child list */
						pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
						ring_vm_list_copy(pVM,pList,pVar);
					}
					pVar = (List *) RING_VM_STACK_READP ;
					RING_VM_STACK_POP ;
					/* Check Before Assignment */
					if ( ring_vm_checkbeforeassignment(pVM,pVar) ) {
						return ;
					}
					ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_LIST);
					/* Copy The List */
					if ( ring_list_isref(pList) ) {
						ring_list_assignreftovar_gc(pVM->pRingState,pList,pVar,RING_VAR_VALUE);
					}
					else {
						ring_list_setlist_gc(pVM->pRingState,pVar,RING_VAR_VALUE);
						if ( ring_list_iscopybyref(pList) ) {
							ring_list_disablecopybyref(pList);
							ring_list_swaptwolists(ring_list_getlist(pVar,RING_VAR_VALUE),pList);
						}
						else {
							ring_vm_list_copy(pVM,ring_list_getlist(pVar,RING_VAR_VALUE),pList);
							ring_list_delete_gc(pVM->pRingState,pList);
						}
						/* Update self object pointer */
						if ( ring_vm_oop_isobject(ring_list_getlist(pVar,RING_VAR_VALUE)) ) {
							ring_vm_oop_updateselfpointer(pVM,ring_list_getlist(pVar,RING_VAR_VALUE),RING_OBJTYPE_VARIABLE,pVar);
						}
					}
				}
			}
			else {
				ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
			}
			break ;
		default :
			ring_vm_error(pVM,RING_VM_ERROR_ASSIGNNOTVARIABLE);
	}
	/* Clear Assignment Pointer */
	pVM->pAssignment = NULL ;
}

void ring_vm_inc ( VM *pVM )
{
	List *pVar  ;
	if ( ring_vm_findvar(pVM, RING_VM_IR_READC ) == 0 ) {
		ring_vm_newvar(pVM, RING_VM_IR_READC);
	}
	if ( ( RING_VM_SCOPESCOUNT == 1 )  && (pVM->pActiveMem == ring_vm_getglobalscope(pVM)) ) {
		/* Replace ICO_INC with IncP for better performance */
		RING_VM_IR_OPCODE = ICO_INCP ;
		RING_VM_IR_SETREG1TOPOINTERFROMSTACK ;
	}
	pVar = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	ring_list_setdouble_gc(pVM->pRingState,pVar,RING_VAR_VALUE,ring_list_getdouble(pVar,RING_VAR_VALUE) + 1);
}

void ring_vm_loadapushv ( VM *pVM )
{
	if ( ring_vm_findvar(pVM, RING_VM_IR_READC  ) == 0 ) {
		ring_vm_newvar(pVM, RING_VM_IR_READC);
		/* Support for private attributes */
		ring_vm_var_setprivateflag(pVM,(List *) RING_VM_STACK_READP,pVM->lPrivateFlag);
	}
	if ( pVM->nVarScope == RING_VARSCOPE_GLOBAL ) {
		/* Replace LoadAPushV with PUSHPV for better performance */
		RING_VM_IR_OPCODE = ICO_PUSHPV ;
		RING_VM_IR_SETREG1TOPOINTERFROMSTACK ;
	}
	ring_vm_varpushv(pVM);
}

void ring_vm_newline ( VM *pVM )
{
	RING_VM_IR_SETLINENUMBER(RING_VM_IR_READI);
	RING_VM_TRACEEVENT(RING_VM_TRACEEVENT_NEWLINE);
}

void ring_vm_freestack ( VM *pVM )
{
	int nSP  ;
	/* Clear Assignment Pointer */
	pVM->pAssignment = NULL ;
	/* Clear Load Address Scope Information */
	pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
	/* Clear the Exit Command flag */
	pVM->lExitFlag = 0 ;
	/* In the class region */
	if ( pVM->nInClassRegion ) {
		/*
		**  Description 
		**  In the class Region we don't free stack to support Object + New Object 
		**  So we can add objects quickly to lists and access them using braces { } 
		**  But If we did this only we may get stack overflow if we did some work in the class region like 
		**  Using Switch (Which use duplication) or calling functions without storing the output using Assignment 
		**  To solve this situation we Use RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER 
		**  So we can support Object + New Object and avoid Stack Overflow too! 
		**  This feature is GREAT in the language where we can quickly move applications from 
		**  Using procedural programming and global variables to Classes and Object Attributes 
		*/
		nSP = ring_vm_newobjectstackpointer(pVM) ;
		if ( pVM->nSP > nSP + RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER ) {
			pVM->nSP = nSP+RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER ;
		}
		return ;
	}
	if ( ( RING_VM_FUNCCALLSCOUNT == 0 ) && (pVM->lInsideBraceFlag == 0) ) {
		pVM->nSP = 0 ;
		pVM->nFuncSP = 0 ;
	}
	else {
		if ( pVM->lInsideBraceFlag == 0 ) {
			pVM->nSP = pVM->nFuncSP ;
		}
		else {
			ring_vm_oop_bracestack(pVM);
		}
	}
}

void ring_vm_setreference ( VM *pVM )
{
	List *pList  ;
	int nType  ;
	void *pPointer  ;
	/*
	**  Check if we have value (string/number) not variable 
	**  In this case we need assignment 
	*/
	if ( ! RING_VM_STACK_ISPOINTER ) {
		ring_vm_assignment(pVM);
		return ;
	}
	/* Read Source */
	pPointer = RING_VM_STACK_READP ;
	nType = RING_VM_STACK_OBJTYPE ;
	RING_VM_STACK_POP ;
	/* Read Destination */
	pList = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	/* Reference Counting to Destination before copy from Source */
	ring_vm_gc_checkupdatereference(pVM,pList);
	/* Copy by reference */
	ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_POINTER);
	ring_list_setpointer_gc(pVM->pRingState,pList,RING_VAR_VALUE,pPointer);
	if ( ring_list_getsize(pList) >= RING_VAR_PVALUETYPE ) {
		ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_PVALUETYPE,nType);
	}
	else {
		/* Happens when the (For-in) loop variable is similar to Function Argument */
		ring_list_addint_gc(pVM->pRingState,pList,nType);
	}
	/* Reference Counting (To Source After copy to Destination) */
	ring_vm_gc_checknewreference(pVM,pPointer,nType,pList,RING_VAR_VALUE);
}

void ring_vm_list_copy ( VM *pVM,List *pNewList, List *pList )
{
	int x,nMax  ;
	List *pNewList2, *pSourceList  ;
	Item *pItem  ;
	/* Copy Items */
	nMax = ring_list_getsize(pList) ;
	if ( nMax == 0 ) {
		return ;
	}
	for ( x = 1 ; x <= nMax ; x++ ) {
		if ( ring_list_isint(pList,x) ) {
			ring_list_addint_gc(pVM->pRingState,pNewList,ring_list_getint(pList,x));
		}
		else if ( ring_list_isdouble(pList,x) ) {
			ring_list_adddouble_gc(pVM->pRingState,pNewList,ring_list_getdouble(pList,x));
		}
		else if ( ring_list_isstring(pList,x) ) {
			ring_list_addstring2_gc(pVM->pRingState,pNewList,ring_list_getstring(pList,x),ring_list_getstringsize(pList,x));
		}
		else if ( ring_list_ispointer(pList,x) ) {
			ring_list_addpointer_gc(pVM->pRingState,pNewList,ring_list_getpointer(pList,x));
		}
		else if ( ring_list_isfuncpointer(pList,x) ) {
			ring_list_addfuncpointer_gc(pVM->pRingState,pNewList,ring_list_getfuncpointer(pList,x));
		}
		else if ( ring_list_islist(pList,x) ) {
			pNewList2 = ring_list_newlist_gc(pVM->pRingState,pNewList);
			pSourceList = ring_list_getlist(pList,x) ;
			if ( ring_list_isref(pSourceList) ) {
				/* Copy By Reference */
				ring_list_setlistbyref_gc(pVM->pRingState,pNewList, ring_list_getsize(pNewList),pSourceList);
			}
			else {
				/* Copy By Value */
				ring_vm_list_copy(pVM,pNewList2,pSourceList);
				/* Update Self Object Pointer */
				if ( ring_vm_oop_isobject(pNewList2) ) {
					pItem = ring_list_getitem(pNewList,ring_list_getsize(pNewList));
					ring_vm_oop_updateselfpointer(pVM,pNewList2,RING_OBJTYPE_LISTITEM,pItem);
				}
			}
		}
	}
	/* Check if the List is a C Pointer List */
	if ( ring_list_iscpointerlist(pList) ) {
		/* Mark the C Pointer List as Not Copied */
		ring_list_setint_gc(pVM->pRingState,pList,RING_CPOINTER_STATUS,RING_CPOINTERSTATUS_NOTCOPIED);
		ring_list_setint_gc(pVM->pRingState,pNewList,RING_CPOINTER_STATUS,RING_CPOINTERSTATUS_NOTCOPIED);
		/* Copy The Pointer by Reference */
		pNewList->pFirst->pValue = ring_item_delete_gc(pVM->pRingState,pNewList->pFirst->pValue);
		pItem = ring_list_getitem(pList,RING_CPOINTER_POINTER) ;
		pNewList->pFirst->pValue = pItem ;
		ring_vm_gc_newitemreference(pItem);
		ring_list_genarray_gc(pVM->pRingState,pNewList);
	}
}

void ring_vm_beforeequallist ( VM *pVM,List *pVar,double nNum1,int nBeforeEqual )
{
	String *pString  ;
	char cStr[RING_MEDIUMBUF]  ;
	int nOutput  ;
	if ( ring_list_isdouble(pVar,RING_VAR_VALUE) ) {
		switch ( nBeforeEqual ) {
			case OP_PLUSEQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) + nNum1);
				break ;
			case OP_MINUSEQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) - nNum1);
				break ;
			case OP_MULEQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) * nNum1);
				break ;
			case OP_DIVEQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE ,ring_list_getdouble(pVar,RING_VAR_VALUE) / nNum1);
				break ;
			case OP_MODEQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , fmod(ring_list_getdouble(pVar,RING_VAR_VALUE), nNum1));
				break ;
			case OP_BITANDEQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) & (int) nNum1);
				break ;
			case OP_BITOREQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) | (int) nNum1);
				break ;
			case OP_BITXOREQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) ^ (int) nNum1);
				break ;
			case OP_SHLEQUAL :
				nOutput = (int) ring_list_getdouble(pVar,RING_VAR_VALUE) << (int) nNum1 ;
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (double) nOutput);
				break ;
			case OP_SHREQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , (int) ring_list_getdouble(pVar,RING_VAR_VALUE) >> (int) nNum1);
				break ;
			case OP_POWEQUAL :
				ring_list_setdouble_gc(pVM->pRingState,pVar, RING_VAR_VALUE , pow( ring_list_getdouble(pVar,RING_VAR_VALUE) , nNum1));
				break ;
		}
	}
	else if ( (ring_list_isstring(pVar,RING_VAR_VALUE) == 1) && (nBeforeEqual == OP_PLUSEQUAL) ) {
		pString = ring_list_getstringobject(pVar,RING_VAR_VALUE);
		ring_string_add_gc(pVM->pRingState,pString,ring_vm_numtostring(pVM,nNum1,cStr));
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
		return ;
	}
}

void ring_vm_beforeequalitem ( VM *pVM,Item *pItem,double nNum1,int nBeforeEqual )
{
	String *pString  ;
	char cStr[RING_MEDIUMBUF]  ;
	int nOutput  ;
	if ( ring_item_isdouble(pItem) ) {
		switch ( nBeforeEqual ) {
			case OP_PLUSEQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,ring_item_getdouble(pItem) + nNum1);
				break ;
			case OP_MINUSEQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,ring_item_getdouble(pItem) - nNum1);
				break ;
			case OP_MULEQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,ring_item_getdouble(pItem) * nNum1);
				break ;
			case OP_DIVEQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,ring_item_getdouble(pItem) / nNum1);
				break ;
			case OP_MODEQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,fmod(ring_item_getdouble(pItem) , nNum1));
				break ;
			case OP_BITANDEQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,(int) ring_item_getdouble(pItem) & (int) nNum1);
				break ;
			case OP_BITOREQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,(int) ring_item_getdouble(pItem) | (int) nNum1);
				break ;
			case OP_BITXOREQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,(int) ring_item_getdouble(pItem) ^ (int) nNum1);
				break ;
			case OP_SHLEQUAL :
				nOutput = (int) ring_item_getdouble(pItem) << (int) nNum1 ;
				ring_item_setdouble_gc(pVM->pRingState,pItem ,(double) nOutput);
				break ;
			case OP_SHREQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,(int) ring_item_getdouble(pItem) >> (int) nNum1);
				break ;
			case OP_POWEQUAL :
				ring_item_setdouble_gc(pVM->pRingState,pItem ,pow( ring_item_getdouble(pItem) , nNum1 ));
				break ;
		}
	}
	else if ( (ring_item_isstring(pItem) == 1)  && (nBeforeEqual == OP_PLUSEQUAL) ) {
		pString = ring_item_getstring(pItem);
		ring_string_add_gc(pVM->pRingState,pString,ring_vm_numtostring(pVM,nNum1,cStr));
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
		return ;
	}
}

void ring_vm_plusplus ( VM *pVM )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			if ( ring_list_isdouble(pList,RING_VAR_VALUE) ) {
				ring_list_setdouble_gc(pVM->pRingState,pList,RING_VAR_VALUE,ring_list_getdouble(pList,RING_VAR_VALUE)+1);
				return ;
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			if ( ring_item_isdouble(pItem) ) {
				ring_item_setdouble_gc(pVM->pRingState,pItem,ring_item_getdouble(pItem)+1);
				return ;
			}
		}
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN + 1);
		return ;
	}
	ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
}

void ring_vm_minusminus ( VM *pVM )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_VM_STACK_READP ;
			if ( ring_list_isdouble(pList,RING_VAR_VALUE) ) {
				ring_list_setdouble_gc(pVM->pRingState,pList,RING_VAR_VALUE,ring_list_getdouble(pList,RING_VAR_VALUE)-1);
				return ;
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			if ( ring_item_isdouble(pItem) ) {
				ring_item_setdouble_gc(pVM->pRingState,pItem,ring_item_getdouble(pItem)-1);
				return ;
			}
		}
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		RING_VM_STACK_SETNVALUE(RING_VM_STACK_READN - 1);
		return ;
	}
	ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
}

void ring_vm_assignmentpointer ( VM *pVM )
{
	List *pList, *pList2  ;
	Item *pItem  ;
	int x, lCont  ;
	/* Check Instruction Parameters */
	if ( RING_VM_IR_READI == 1 ) {
		/*
		**  We have this option with New Lists and  New Objects only 
		**  We will accept this option only when we have the setter method 
		*/
		if ( pVM->nNoSetterMethod == RING_NOSETTERMETHOD_DEFAULT ) {
			pVM->lNoAssignment = 1 ;
		}
		else {
			/* Tell the ICO_SETPROPERTY instruction to be disabled */
			pVM->nNoSetterMethod = RING_NOSETTERMETHOD_IGNORESETPROPERTY ;
		}
	}
	if ( pVM->lNoAssignment == 0 ) {
		pVM->pAssignment = RING_VM_STACK_READP ;
		RING_VM_STACK_ASSIGNMENTFLAG = RING_TRUE ;
		/* Check trying to change the self pointer */
		pList = NULL ;
		lCont = RING_FALSE ;
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			if ( ring_list_islist((List *) pVM->pAssignment,RING_VAR_VALUE) ) {
				pList = ring_list_getlist((List *) pVM->pAssignment,RING_VAR_VALUE) ;
				lCont = RING_TRUE ;
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) pVM->pAssignment ;
			if ( ring_item_gettype(pItem) == ITEMTYPE_LIST ) {
				pList = ring_item_getlist(pItem) ;
				lCont = RING_TRUE ;
			}
		}
		if ( ! lCont ) {
			return ;
		}
		if ( ring_list_getsize(pVM->pObjState) && ring_vm_oop_isobject(pList) ) {
			/* We loop to prevent passing self to function that destroy the self */
			for ( x = 1 ; x <= ring_list_getsize(pVM->pObjState) ; x++ ) {
				pList2 = ring_list_getlist(pVM->pObjState,x);
				if ( ring_list_getpointer(pList,RING_OBJECT_OBJECTDATA) == ring_list_getpointer(pList2,RING_OBJSTATE_SCOPE) ) {
					if ( (ring_list_getrefcount(pList) == 1) || pVM->lSelfLoadA ) {
						pVM->lSelfLoadA = 0 ;
						ring_vm_error(pVM,RING_VM_ERROR_TRYINGTOMODIFYTHESELFPOINTER);
						return ;
					}
				}
			}
		}
	}
	else {
		pVM->lNoAssignment = 0 ;
	}
}

void ring_vm_freeloadaddressscope ( VM *pVM )
{
	/* Clear Load Address Scope Information */
	pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
}

void ring_vm_loadaddressfirst ( VM *pVM )
{
	pVM->lFirstAddress = 1 ;
	ring_vm_loadaddress(pVM);
	pVM->lFirstAddress = 0 ;
}

void ring_vm_printstack ( VM *pVM )
{
	int x,nSP  ;
	printf( "\n*****************************************\n" ) ;
	printf( "Stack Size %u \n",pVM->nSP ) ;
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
					ring_list_print2((List *) RING_VM_STACK_READP,pVM->nDecimals);
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

void ring_vm_len ( VM *pVM )
{
	int nSize  ;
	List *pVar, *pList  ;
	Item *pItem  ;
	String *pString  ;
	if ( RING_VM_STACK_ISSTRING ) {
		nSize = RING_VM_STACK_STRINGSIZE ;
		RING_VM_STACK_POP ;
		RING_VM_STACK_PUSHNVALUE(nSize);
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pVar = (List *) RING_VM_STACK_READP ;
			if ( ring_list_islist(pVar,RING_VAR_VALUE) ) {
				pList = ring_list_getlist(pVar,RING_VAR_VALUE) ;
				if ( ring_vm_oop_isobject(pList) == 0 ) {
					RING_VM_STACK_POP ;
					RING_VM_STACK_PUSHNVALUE(ring_list_getsize(pList));
				}
				else {
					ring_vm_expr_npoo(pVM,RING_CSTR_LEN,RING_NOVALUE);
					pVM->lIgnoreNULL = 1 ;
				}
			}
			else if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
				nSize = ring_list_getstringsize(pVar,RING_VAR_VALUE) ;
				RING_VM_STACK_POP ;
				RING_VM_STACK_PUSHNVALUE(nSize);
			}
			else {
				ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			switch ( pItem->nType ) {
				case ITEMTYPE_STRING :
					pString = ring_item_getstring(pItem) ;
					RING_VM_STACK_POP ;
					RING_VM_STACK_PUSHNVALUE(ring_string_size(pString));
					break ;
				case ITEMTYPE_LIST :
					pList = ring_item_getlist(pItem) ;
					if ( ring_vm_oop_isobject(pList) == 0 ) {
						RING_VM_STACK_POP ;
						RING_VM_STACK_PUSHNVALUE(ring_list_getsize(pList));
					}
					else {
						ring_vm_expr_npoo(pVM,RING_CSTR_LEN,RING_NOVALUE);
						pVM->lIgnoreNULL = 1 ;
					}
					break ;
				default :
					ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
			}
		}
		else {
			ring_vm_error(pVM,RING_VM_ERROR_FORLOOPDATATYPE);
		}
	}
}

void ring_vm_stackswap ( VM *pVM,int nSP1,int nSP2 )
{
	Item vTempItem  ;
	vTempItem = pVM->aStack[nSP1] ;
	pVM->aStack[nSP1] = pVM->aStack[nSP2] ;
	pVM->aStack[nSP2] = vTempItem ;
}

int ring_vm_isinsideloop ( VM *pVM )
{
	FuncCall *pFuncCall  ;
	if ( RING_VM_FUNCCALLSCOUNT ) {
		pFuncCall = RING_VM_LASTFUNCCALL ;
		return ring_list_getsize(pVM->pForStep) > pFuncCall->nForStep ;
	}
	return ring_list_getsize(pVM->pForStep) ;
}
