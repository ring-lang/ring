/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_newnestedlists ( VM *pVM )
{
	pVM->nListStart = 0 ;
}

void ring_vm_restorenestedlists ( VM *pVM,int nListStart,int nNestedLists )
{
	pVM->nListStart = nListStart ;
	if ( ring_list_getsize(pVM->pNestedLists) > nNestedLists ) {
		ring_vm_removelistprotection(pVM,pVM->pNestedLists,nNestedLists+1);
		ring_vm_backstate(pVM,pVM->pNestedLists,nNestedLists);
	}
}

void ring_vm_liststart ( VM *pVM )
{
	List *pVar,*pList,*pNewList  ;
	int nType,nCont  ;
	Item *pItem  ;
	pVar = NULL ;
	pNewList = NULL ;
	pItem = NULL ;
	pVM->nListStart++ ;
	if ( pVM->nListStart == 1 ) {
		/* Check if we need to create temp list when we call function, pass list by value */
		nCont = ring_vm_notusingvarduringdef(pVM) ;
		if ( nCont ) {
			/* Create the Temp list */
			ring_vm_createtemplist(pVM);
			pVar = (List *) RING_VM_STACK_READP ;
			nType = RING_VM_STACK_OBJTYPE ;
		}
		else {
			if ( RING_VM_STACK_ISPOINTER == 0 ) {
				/* Create the List in the Temp Memory. */
				ring_vm_newtempvar(pVM, RING_TEMP_VAR,ring_vm_prevtempmem(pVM));
				if ( pVM->nLoadAddressScope == RING_VARSCOPE_NOTHING ) {
					pVM->nLoadAddressScope = RING_VARSCOPE_LOCAL ;
				}
			}
			nType = RING_VM_STACK_OBJTYPE ;
			if ( nType == RING_OBJTYPE_LISTITEM ) {
				pItem = (Item *) RING_VM_STACK_READP ;
			}
			else {
				pVar = (List *) RING_VM_STACK_READP ;
			}
			/* Support code like  aList = [1,2,3] + 4 */
			ring_vm_stack_dup(pVM);
		}
		if ( nType == RING_OBJTYPE_VARIABLE ) {
			/* Check error on assignment */
			if ( ring_vm_checkvarerroronassignment(pVM,pVar) ) {
				return ;
			}
			ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_LIST);
			ring_list_setlist_gc(pVM->pRingState,pVar, RING_VAR_VALUE);
			pNewList = ring_list_getlist(pVar,RING_VAR_VALUE) ;
			ring_list_deleteallitems_gc(pVM->pRingState,pNewList);
			ring_list_addpointer_gc(pVM->pRingState,pVM->pNestedLists,pNewList);
		}
		else if ( (nType == RING_OBJTYPE_LISTITEM) && (pItem != NULL) ) {
			/* Check error on assignment */
			if ( ring_vm_checkitemerroronassignment(pVM,pItem) ) {
				return ;
			}
			ring_item_settype_gc(pVM->pRingState,pItem,ITEMTYPE_LIST);
			pNewList = ring_item_getlist(pItem);
			ring_list_deleteallitems_gc(pVM->pRingState,pNewList);
			ring_list_addpointer_gc(pVM->pRingState,pVM->pNestedLists,pNewList);
		}
		if ( nCont ) {
			ring_list_enablecopybyref(pNewList);
		}
	}
	else {
		pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
		ring_list_addpointer_gc(pVM->pRingState,pVM->pNestedLists,ring_list_newlist_gc(pVM->pRingState,pList));
	}
	/* Enable Error on Assignment */
	pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
	ring_list_enableerroronassignment(pList);
	/* When using something like Ref([1,2,3]) - Don't create new reference */
	if ( (pNewList != NULL) && (ring_vm_funccall_beforecall(pVM)) ) {
		ring_list_enabledontref(pNewList);
	}
}

void ring_vm_listitem ( VM *pVM )
{
	String *pStr1  ;
	double nNum1  ;
	List *pList,*pList2,*pList3,*pList4  ;
	Item *pItem  ;
	pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
	if ( RING_VM_STACK_ISSTRING ) {
		ring_list_addstring2_gc(pVM->pRingState,pList, RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
		RING_VM_STACK_POP ;
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		ring_list_adddouble_gc(pVM->pRingState,pList, RING_VM_STACK_READN);
		RING_VM_STACK_POP ;
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		/* We use a Temp. list (pList4) to support adding the list to itself by value */
		pList4 = ring_list_new_gc(pVM->pRingState,RING_ZERO);
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList2 = (List *) RING_VM_STACK_READP ;
			RING_VM_STACK_POP ;
			pList2 = ring_list_getlist(pList2,RING_VAR_VALUE);
			pList3 = ring_list_newlist_gc(pVM->pRingState,pList);
			if ( ring_list_isref(pList2) ) {
				/* Copy by ref (pList2 to pList3) */
				ring_list_assignreftovar_gc(pVM->pRingState,pList2,pList,ring_list_getsize(pList));
			}
			else {
				ring_vm_list_copy(pVM,pList4,pList2);
				ring_list_swaptwolists(pList3,pList4);
				/* Update self object Pointer */
				if ( ring_vm_oop_isobject(pList3) ) {
					pItem = ring_list_getitem(pList,ring_list_getsize(pList));
					ring_vm_oop_updateselfpointer(pVM,pList3,RING_OBJTYPE_LISTITEM,pItem);
				}
			}
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			RING_VM_STACK_POP ;
			pList2 = ring_item_getlist(pItem);
			pList3 = ring_list_newlist_gc(pVM->pRingState,pList);
			if ( ring_list_isref(pList2) ) {
				/* Copy by ref (pList2 to pList3) */
				pItem = ring_list_getitem(pList,ring_list_getsize(pList)) ;
				ring_list_assignreftoitem_gc(pVM->pRingState,pList2,pItem);
			}
			else {
				ring_vm_list_copy(pVM,pList4,pList2);
				ring_list_swaptwolists(pList3,pList4);
				/* Update self object Pointer */
				if ( ring_vm_oop_isobject(pList3) ) {
					pItem = ring_list_getitem(pList,ring_list_getsize(pList));
					ring_vm_oop_updateselfpointer(pVM,pList3,RING_OBJTYPE_LISTITEM,pItem);
				}
			}
		}
		ring_list_delete_gc(pVM->pRingState,pList4);
	}
}

void ring_vm_listitemn ( VM *pVM )
{
	List *pList  ;
	pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
	ring_list_adddouble_gc(pVM->pRingState,pList,RING_VM_IR_READD);
}

void ring_vm_listitemc ( VM *pVM )
{
	List *pList  ;
	pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
	ring_list_addstring_gc(pVM->pRingState,pList,RING_VM_IR_READCVALUE(RING_VM_IR_REG1));
}

void ring_vm_listend ( VM *pVM )
{
	ring_vm_removelistprotectionat(pVM,pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
	pVM->nListStart-- ;
	ring_list_deleteitem_gc(pVM->pRingState,pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
}

void ring_vm_loadindexaddress ( VM *pVM )
{
	double nNum1  ;
	List *pVar  ;
	Item *pItem  ;
	char cStr2[RING_CHARBUF]  ;
	String *pString  ;
	if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		if ( RING_VM_STACK_ISPOINTER ) {
			if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
				pVar = (List *) RING_VM_STACK_READP ;
				if ( ring_list_islist(pVar,RING_VAR_VALUE) ) {
					pVar = ring_list_getlist(pVar,RING_VAR_VALUE);
					/* Check that it's list not object */
					if ( ring_vm_oop_isobject(pVar) == 1 ) {
						ring_vm_expr_npoo(pVM,"[]",nNum1);
						return ;
					}
					RING_VM_STACK_POP ;
					if ( nNum1 < 1 || nNum1 > ring_list_getsize(pVar) ) {
						ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
						return ;
					}
					pItem = ring_list_getitem(pVar,nNum1);
					RING_VM_STACK_PUSHPVALUE(pItem);
				}
				else if ( ring_list_isstring(pVar,RING_VAR_VALUE) ) {
					RING_VM_STACK_POP ;
					if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL ) {
						ring_vm_error(pVM,RING_VM_ERROR_USINGNULLVARIABLE);
						return ;
					}
					pString = ring_list_getstringobject(pVar,RING_VAR_VALUE) ;
					ring_vm_string_index(pVM,pString,nNum1);
					return ;
				}
				else {
					RING_VM_STACK_POP ;
					ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
					return ;
				}
			}
			else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
				pItem = (Item *) RING_VM_STACK_READP ;
				if ( ring_item_islist(pItem) ) {
					pVar = ring_item_getlist(pItem);
					/* Check that it's list not object */
					if ( ring_vm_oop_isobject(pVar) == 1 ) {
						ring_vm_expr_npoo(pVM,"[]",nNum1);
						return ;
					}
					RING_VM_STACK_POP ;
					if ( nNum1 < 1 || nNum1 > ring_list_getsize(pVar) ) {
						ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
						return ;
					}
					pItem = ring_list_getitem(pVar,nNum1);
					RING_VM_STACK_PUSHPVALUE(pItem);
				}
				else if ( ring_item_isstring(pItem) ) {
					RING_VM_STACK_POP ;
					pString = ring_item_getstring(pItem);
					ring_vm_string_index(pVM,pString,nNum1);
					return ;
				}
				else {
					RING_VM_STACK_POP ;
					ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
					return ;
				}
			}
			else {
				ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
				return ;
			}
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			/* Check index value */
			if ( nNum1 < 1 || nNum1 > RING_VM_STACK_STRINGSIZE ) {
				ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
				return ;
			}
			cStr2[0] = RING_VM_STACK_READC[((unsigned int) nNum1)-1] ;
			cStr2[1] = '\0' ;
			RING_VM_STACK_SETCVALUE2(cStr2,RING_ONE);
			return ;
		}
		else {
			ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
			return ;
		}
		RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		pString = ring_string_new2_gc(pVM->pRingState,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
		RING_VM_STACK_POP ;
		/* Use String to find the item */
		if ( RING_VM_STACK_ISPOINTER ) {
			if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
				pVar = (List *) RING_VM_STACK_READP ;
				RING_VM_STACK_POP ;
				if ( ring_list_islist(pVar,RING_VAR_VALUE) ) {
					pVar = ring_list_getlist(pVar,RING_VAR_VALUE);
					/* Check that it's list not object */
					if ( ring_vm_oop_isobject(pVar) == 1 ) {
						RING_VM_SP_INC ;
						ring_vm_expr_spoo(pVM,"[]",ring_string_get(pString),ring_string_size(pString));
					}
					else {
						ring_vm_listgetvalue(pVM,pVar,ring_string_get(pString));
					}
				}
				else {
					ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
				}
			}
			else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
				pItem = (Item *) RING_VM_STACK_READP ;
				RING_VM_STACK_POP ;
				if ( ring_item_islist(pItem) ) {
					pVar = ring_item_getlist(pItem);
					/* Check that it's list not object */
					if ( ring_vm_oop_isobject(pVar) == 1 ) {
						RING_VM_SP_INC ;
						ring_vm_expr_spoo(pVM,"[]",ring_string_get(pString),ring_string_size(pString));
					}
					else {
						ring_vm_listgetvalue(pVM,pVar,ring_string_get(pString));
					}
				}
				else {
					ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
				}
			}
			else {
				ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
			}
		}
		else {
			ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
			/* Don't return here, we need to delete the string to avoid memory leak */
		}
		ring_string_delete_gc(pVM->pRingState,pString);
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
	}
}

void ring_vm_listpushv ( VM *pVM )
{
	Item *pItem  ;
	char cPointer[RING_SMALLBUF]  ;
	pItem = (Item *) RING_VM_STACK_READP ;
	/* Push Item Data */
	if ( ring_item_gettype(pItem) == ITEMTYPE_STRING ) {
		if ( (pVM->nRetItemRef > 0)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
			RING_VM_STACK_SETPVALUE(pItem);
			RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
			pVM->nRetItemRef-- ;
			return ;
		}
		RING_VM_STACK_SETCVALUE2(ring_string_get(ring_item_getstring(pItem)),ring_string_size(ring_item_getstring(pItem)));
	}
	else if ( ring_item_gettype(pItem) == ITEMTYPE_NUMBER ) {
		if ( (pVM->nRetItemRef > 0)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
			RING_VM_STACK_SETPVALUE(pItem);
			RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
			pVM->nRetItemRef-- ;
			return ;
		}
		RING_VM_STACK_SETNVALUE(ring_item_getnumber(pItem));
	}
	else if ( ring_item_gettype(pItem) == ITEMTYPE_LIST ) {
		if ( (pVM->nRetItemRef > 0)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
			pVM->nRetItemRef-- ;
		}
		RING_VM_STACK_SETPVALUE(pItem);
		RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
		ring_vm_oop_setbraceobj(pVM, (List *) ring_item_getlist(pItem));
	}
	else if ( ring_item_gettype(pItem) == ITEMTYPE_POINTER ) {
		if ( (pVM->nRetItemRef > 0)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
			RING_VM_STACK_SETPVALUE(pItem);
			RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
			pVM->nRetItemRef-- ;
			return ;
		}
		sprintf( cPointer , "%p" , ring_item_getpointer(pItem) ) ;
		RING_VM_STACK_SETCVALUE2(cPointer,strlen(cPointer));
	}
}

void ring_vm_listassignment ( VM *pVM,int nBeforeEqual )
{
	Item *pItem  ;
	String *pStr1, *pString  ;
	double nNum1  ;
	List *pList,*pVar, *pTempList  ;
	pVar = NULL ;
	if ( (RING_VM_STACK_ISSTRING) && (nBeforeEqual <= OP_PLUSEQUAL) ) {
		pStr1 = RING_VM_STACK_GETSTRINGRAW ;
		RING_VM_STACK_POP ;
		pItem = (Item *) RING_VM_STACK_READP ;
		RING_VM_STACK_POP ;
		/* Check error on assignment */
		if ( ring_vm_checkitemerroronassignment(pVM,pItem) ) {
			return ;
		}
		if ( nBeforeEqual == OP_EQUAL ) {
			ring_item_setstring2_gc(pVM->pRingState,pItem, ring_string_get(pStr1),ring_string_size(pStr1));
		}
		else {
			if ( ring_item_isstring(pItem) ) {
				pString = ring_item_getstring(pItem);
				ring_string_add2_gc(pVM->pRingState,pString,ring_string_get(pStr1),ring_string_size(pStr1));
			}
			else if ( ring_item_isdouble(pItem) ) {
				ring_item_setdouble_gc(pVM->pRingState,pItem,ring_item_getdouble(pItem)+ring_vm_stringtonum(pVM,ring_string_get(pStr1)));
			}
		}
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		pItem = (Item *) RING_VM_STACK_READP ;
		RING_VM_STACK_POP ;
		/* Check error on assignment */
		if ( ring_vm_checkitemerroronassignment(pVM,pItem) ) {
			return ;
		}
		if ( nBeforeEqual == OP_EQUAL ) {
			ring_item_setdouble_gc(pVM->pRingState,pItem , nNum1);
		}
		else {
			ring_vm_beforeequalitem(pVM,pItem,nNum1,nBeforeEqual);
		}
	}
	else if ( (RING_VM_STACK_ISPOINTER) && (nBeforeEqual == OP_EQUAL) ) {
		/* Get Source */
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pVar = (List *) RING_VM_STACK_READP ;
			pVar = ring_list_getlist(pVar,RING_VAR_VALUE);
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			pVar = ring_item_getlist(pItem);
		}
		RING_VM_STACK_POP ;
		pItem = (Item *) RING_VM_STACK_READP ;
		RING_VM_STACK_POP ;
		/* Check error on assignment */
		if ( ring_vm_checkitemerroronassignment(pVM,pItem) ) {
			return ;
		}
		if ( ring_item_gettype(pItem) != ITEMTYPE_LIST ) {
			/* We check the type to avoid deleting the current list if it's a reference */
			ring_item_settype_gc(pVM->pRingState,pItem,ITEMTYPE_LIST);
		}
		pList = ring_item_getlist(pItem);
		/* Check if we are assigning the same item to itself, i.e. aList[x] = aList[x] */
		if ( pList == pVar ) {
			return ;
		}
		if ( ring_list_isref(pVar) ) {
			ring_list_assignreftoitem_gc(pVM->pRingState,pVar,pItem);
		}
		else {
			ring_list_deleteallitems_gc(pVM->pRingState,pList);
			if ( ring_list_iscopybyref(pVar) ) {
				ring_list_disablecopybyref(pVar);
				ring_list_swaptwolists(pList,pVar);
			}
			else {
				pTempList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
				ring_vm_list_copy(pVM,pTempList,pVar);
				ring_list_swaptwolists(pList,pTempList);
				ring_list_delete_gc(pVM->pRingState,pTempList);
			}
			/* Update self object Pointer */
			if ( ring_vm_oop_isobject(pList) ) {
				ring_vm_oop_updateselfpointer(pVM,pList,RING_OBJTYPE_LISTITEM,pItem);
			}
		}
	}
	else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
	}
}

void ring_vm_listgetvalue ( VM *pVM,List *pVar,const char *cStr )
{
	int x  ;
	List *pList  ;
	Item *pItem  ;
	const char *cStr2  ;
	if ( ring_list_getsize(pVar) > 0 ) {
		for ( x = 1 ; x <= ring_list_getsize(pVar) ; x++ ) {
			if ( ring_list_islist(pVar,x) ) {
				pList = ring_list_getlist(pVar,x);
				if ( ring_list_getsize(pList)  == RING_LISTHASH_SIZE ) {
					if ( ring_list_isstring(pList,RING_LISTHASH_KEY) ) {
						cStr2 = ring_list_getstring(pList,RING_LISTHASH_KEY);
						if ( ring_vm_strcmpnotcasesensitive(cStr,cStr2)  == 0 ) {
							pItem = ring_list_getitem(pList,RING_LISTHASH_VALUE);
							RING_VM_STACK_PUSHPVALUE(pItem);
							RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
							return ;
						}
					}
				}
			}
		}
	}
	/* Add Item if not found */
	pList = ring_list_newlist_gc(pVM->pRingState,pVar);
	ring_list_addstring_gc(pVM->pRingState,pList,cStr);
	ring_list_addstring_gc(pVM->pRingState,pList,RING_CSTR_EMPTY);
	pItem = ring_list_getitem(pList,RING_LISTHASH_VALUE);
	RING_VM_STACK_PUSHPVALUE(pItem);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
}

int ring_vm_strcmpnotcasesensitive ( const char *cStr1,const char *cStr2 )
{
	int nNum1  ;
	while ( 1 ) {
		nNum1 = tolower(*cStr1) - tolower(*cStr2) ;
		if ( nNum1 != 0 || !*cStr1 || !*cStr2 ) {
			return nNum1 ;
		}
		cStr1++ ;
		cStr2++ ;
	}
}

void ring_vm_cleansetpropertylist ( VM *pVM )
{
	if ( ring_list_getsize(pVM->pSetProperty) > 0 ) {
		ring_list_deleteitem_gc(pVM->pRingState,pVM->pSetProperty,ring_list_getsize(pVM->pSetProperty));
	}
}

int ring_vm_isoperationaftersublist ( VM *pVM )
{
	int nOPCode  ;
	List *pParent, *pSub, *pVar  ;
	if ( pVM->nListStart > 0 ) {
		nOPCode = RING_VM_IR_OPCODEVALUE(pVM->nPC - 3) ;
		if ( nOPCode == ICO_LISTEND ) {
			/* Get the Parent List */
			pParent = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
			/* Get the Sub List */
			pSub = ring_list_getlist(pParent,ring_list_getsize(pParent));
			/* Create a Temp. variable for the sub list */
			ring_vm_createtemplist(pVM);
			pVar = (List *) RING_VM_STACK_READP ;
			ring_list_setint_gc(pVM->pRingState,pVar, RING_VAR_TYPE ,RING_VM_LIST);
			ring_list_setlist_gc(pVM->pRingState,pVar, RING_VAR_VALUE);
			ring_list_deleteallitems_gc(pVM->pRingState,ring_list_getlist(pVar,RING_VAR_VALUE));
			ring_vm_list_copy(pVM,ring_list_getlist(pVar,RING_VAR_VALUE),pSub);
			/* Delete the sub list from the Parent List */
			ring_list_deleteitem_gc(pVM->pRingState,pParent,ring_list_getsize(pParent));
			return 1 ;
		}
	}
	return 0 ;
}

int ring_vm_notusingvarduringdef ( VM *pVM )
{
	int nCont  ;
	nCont = RING_TRUE ;
	if ( (pVM->nSP > pVM->nFuncSP) && RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_ISASSIGNMENTDEST ) {
			nCont = RING_FALSE ;
			/* Clear the Assignment Pointer */
			pVM->pAssignment = NULL ;
			ring_vm_cleansetpropertylist(pVM);
			/* Check using Ref(aList) at the Left-Side */
			if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
				if ( ring_list_checkrefvarinleftside(pVM->pRingState,(List *) RING_VM_STACK_READP) ) {
					nCont = RING_TRUE ;
				}
			}
		}
	}
	return nCont ;
}
