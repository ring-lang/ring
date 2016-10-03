/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Lists */

void ring_vm_liststart ( VM *pVM )
{
	List *pVar,*pList  ;
	int nType  ;
	Item *pItem  ;
	int nCont  ;
	pVar = NULL ;
	pItem = NULL ;
	pVM->nListStart++ ;
	if ( pVM->nListStart == 1 ) {
		/* Check if we need to create temp list when we call function, pass list by value */
		nCont = 0 ;
		if ( RING_VM_STACK_ISPOINTER ) {
			if ( pVM->pAssignment != RING_VM_STACK_READP ) {
				nCont = 1 ;
			}
		}
		if ( (pVM->nFuncExecute > 0)  || ( nCont == 1 ) ) {
			if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
				ring_vm_createtemplist(pVM);
			} else {
				/* Create the list in the General Temp Memory */
				ring_vm_newtempvar(pVM, RING_TEMP_VARIABLE ,pVM->pTempMem);
			}
			pVar = (List *) RING_VM_STACK_READP ;
			nType = RING_VM_STACK_OBJTYPE ;
		} else {
			if ( RING_VM_STACK_ISPOINTER == 0 ) {
				ring_vm_error(pVM,RING_VM_ERROR_NOTVARIABLE);
				return ;
			}
			nType = RING_VM_STACK_OBJTYPE ;
			if ( nType == RING_OBJTYPE_LISTITEM ) {
				pItem = (Item *) RING_VM_STACK_READP ;
			} else {
				pVar = (List *) RING_VM_STACK_READP ;
			}
			RING_VM_STACK_POP ;
		}
		if ( nType == RING_OBJTYPE_VARIABLE ) {
			ring_list_setint(pVar, RING_VAR_TYPE ,RING_VM_LIST);
			ring_list_setlist(pVar, RING_VAR_VALUE);
			ring_list_deleteallitems(ring_list_getlist(pVar,RING_VAR_VALUE));
			ring_list_addpointer(pVM->pNestedLists,ring_list_getlist(pVar,RING_VAR_VALUE));
		}
		else if ( (nType == RING_OBJTYPE_LISTITEM) && (pItem != NULL) ) {
			ring_item_settype(pItem,ITEMTYPE_LIST);
			pVar = ring_item_getlist(pItem);
			ring_list_deleteallitems(pVar);
			ring_list_addpointer(pVM->pNestedLists,pVar);
		}
	} else {
		pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
		ring_list_addpointer(pVM->pNestedLists,ring_list_newlist(pList));
	}
}

void ring_vm_listitem ( VM *pVM )
{
	String *cStr1  ;
	double nNum1  ;
	List *pList,*pList2,*pList3  ;
	Item *pItem  ;
	pList = (List *) ring_list_getpointer(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
	if ( RING_VM_STACK_ISSTRING ) {
		cStr1 = ring_string_new(RING_VM_STACK_READC);
		RING_VM_STACK_POP ;
		ring_list_addstring(pList, ring_string_get(cStr1));
		ring_string_delete(cStr1);
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		ring_list_adddouble(pList, nNum1);
	}
	else if ( RING_VM_STACK_ISPOINTER ) {
		if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
			pList2 = (List *) RING_VM_STACK_READP ;
			RING_VM_STACK_POP ;
			pList2 = ring_list_getlist(pList2,RING_VAR_VALUE);
			pList3 = ring_list_newlist(pList);
			ring_list_copy(pList3,pList2);
		}
		else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_VM_STACK_READP ;
			RING_VM_STACK_POP ;
			pList2 = ring_item_getlist(pItem);
			pList3 = ring_list_newlist(pList);
			ring_list_copy(pList3,pList2);
		}
	}
}

void ring_vm_listend ( VM *pVM )
{
	pVM->nListStart-- ;
	ring_list_deleteitem(pVM->pNestedLists,ring_list_getsize(pVM->pNestedLists));
}

void ring_vm_loadindexaddress ( VM *pVM )
{
	double nNum1  ;
	List *pVar  ;
	Item *pItem  ;
	char cStr2[2]  ;
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
				} else {
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
				} else {
					RING_VM_STACK_POP ;
					ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
					return ;
				}
			} else {
				ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
				return ;
			}
		}
		else if ( RING_VM_STACK_ISSTRING ) {
			cStr2[0] = RING_VM_STACK_READC[((int) nNum1)-1] ;
			cStr2[1] = '\0' ;
			RING_VM_STACK_SETCVALUE(cStr2);
			return ;
		} else {
			ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
			return ;
		}
		RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
	}
	else if ( RING_VM_STACK_ISSTRING ) {
		pString = ring_string_new(RING_VM_STACK_READC);
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
						pVM->nSP++ ;
						ring_vm_expr_spoo(pVM,"[]",ring_string_get(pString),ring_string_size(pString));
						return ;
					}
					ring_vm_listgetvalue(pVM,pVar,ring_string_get(pString));
				} else {
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
						pVM->nSP++ ;
						ring_vm_expr_spoo(pVM,"[]",ring_string_get(pString),ring_string_size(pString));
						return ;
					}
					ring_vm_listgetvalue(pVM,pVar,ring_string_get(pString));
				} else {
					ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
				}
			} else {
				ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
			}
		} else {
			ring_vm_error(pVM,RING_VM_ERROR_OBJECTISNOTLIST);
			/* Don't return here, we need to delete the string to avoid memory leak */
		}
		ring_string_delete(pString);
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_INDEXOUTOFRANGE);
	}
}

void ring_vm_listpushv ( VM *pVM )
{
	Item *pItem  ;
	pItem = (Item *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	/* Push Item Data */
	if ( ring_item_gettype(pItem) == ITEMTYPE_STRING ) {
		if ( (pVM->nRetItemRef>=1)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
			RING_VM_STACK_PUSHPVALUE(pItem);
			RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
			pVM->nRetItemRef-- ;
			return ;
		}
		pVM->nSP++ ;
		RING_VM_STACK_SETCVALUE2(ring_string_get(ring_item_getstring(pItem)),ring_string_size(ring_item_getstring(pItem)));
	}
	else if ( ring_item_gettype(pItem) == ITEMTYPE_NUMBER ) {
		if ( (pVM->nRetItemRef>=1)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
			RING_VM_STACK_PUSHPVALUE(pItem);
			RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
			pVM->nRetItemRef-- ;
			return ;
		}
		RING_VM_STACK_PUSHNVALUE(ring_item_getnumber(pItem));
	}
	else if ( ring_item_gettype(pItem) == ITEMTYPE_LIST ) {
		if ( (pVM->nRetItemRef>=1)  && (ring_vm_isstackpointertoobjstate(pVM)==1) ) {
			pVM->nRetItemRef-- ;
		}
		RING_VM_STACK_PUSHPVALUE(pItem);
		RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
		ring_vm_oop_setbraceobj(pVM, (List *) ring_item_getlist(pItem));
	}
}

void ring_vm_listassignment ( VM *pVM )
{
	Item *pItem  ;
	String *cStr1, *pString  ;
	double nNum1  ;
	List *pList,*pVar  ;
	pVar = NULL ;
	if ( (RING_VM_STACK_ISSTRING) && (pVM->nBeforeEqual <= 1) ) {
		cStr1 = ring_string_new(RING_VM_STACK_READC);
		assert(cStr1 != NULL);
		RING_VM_STACK_POP ;
		pItem = (Item *) RING_VM_STACK_READP ;
		assert(pItem != NULL);
		RING_VM_STACK_POP ;
		if ( pVM->nBeforeEqual == 0 ) {
			ring_item_setstring(pItem, ring_string_get(cStr1));
		} else {
			if ( ring_item_isstring(pItem) ) {
				pString = ring_item_getstring(pItem);
				ring_string_add(pString,ring_string_get(cStr1));
			}
			else if ( ring_item_isdouble(pItem) ) {
				ring_item_setdouble(pItem,ring_item_getdouble(pItem)+ring_vm_stringtonum(pVM,ring_string_get(cStr1)));
			}
		}
		ring_string_delete(cStr1);
	}
	else if ( RING_VM_STACK_ISNUMBER ) {
		nNum1 = RING_VM_STACK_READN ;
		RING_VM_STACK_POP ;
		pItem = (Item *) RING_VM_STACK_READP ;
		assert(pItem != NULL);
		RING_VM_STACK_POP ;
		if ( pVM->nBeforeEqual == 0 ) {
			ring_item_setdouble(pItem , nNum1);
		} else {
			ring_vm_beforeequalitem(pVM,pItem,nNum1);
		}
	}
	else if ( (RING_VM_STACK_ISPOINTER) && (pVM->nBeforeEqual == 0) ) {
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
		ring_item_settype(pItem,ITEMTYPE_LIST);
		pList = ring_item_getlist(pItem);
		ring_list_deleteallitems(pList);
		ring_vm_list_copy(pVM,pList,pVar);
		/* Update self object Pointer */
		if ( ring_vm_oop_isobject(pList) ) {
			ring_vm_oop_updateselfpointer(pList,RING_OBJTYPE_LISTITEM,pItem);
		}
	} else {
		ring_vm_error(pVM,RING_VM_ERROR_BADVALUES);
	}
}

void ring_vm_listgetvalue ( VM *pVM,List *pVar,const char *cStr )
{
	int x  ;
	List *pList  ;
	Item *pItem  ;
	String *pString,*pString2  ;
	pString = ring_string_new("");
	pString2 = ring_string_new(cStr);
	if ( ring_list_getsize(pVar) > 0 ) {
		for ( x = 1 ; x <= ring_list_getsize(pVar) ; x++ ) {
			if ( ring_list_islist(pVar,x) ) {
				pList = ring_list_getlist(pVar,x);
				if ( ring_list_getsize(pList)  >= RING_LISTHASH_SIZE ) {
					if ( ring_list_isstring(pList,RING_LISTHASH_KEY) ) {
						ring_string_set(pString,ring_list_getstring(pList,RING_LISTHASH_KEY));
						if ( strcmp(ring_string_lower(ring_string_get(pString)),ring_string_lower(ring_string_get(pString2))) == 0 ) {
							pItem = ring_list_getitem(pList,RING_LISTHASH_VALUE);
							RING_VM_STACK_PUSHPVALUE(pItem);
							RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
							/* Delete Strings */
							ring_string_delete(pString);
							ring_string_delete(pString2);
							return ;
						}
					}
				}
			}
		}
	}
	/* Add Item if not found */
	pList = ring_list_newlist(pVar);
	ring_list_addstring(pList,cStr);
	ring_list_addstring(pList,"");
	pItem = ring_list_getitem(pList,RING_LISTHASH_VALUE);
	RING_VM_STACK_PUSHPVALUE(pItem);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_LISTITEM ;
	/* Delete Strings */
	ring_string_delete(pString);
	ring_string_delete(pString2);
}
