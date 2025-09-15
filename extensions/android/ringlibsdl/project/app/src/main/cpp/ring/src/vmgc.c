/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"
/* Item GC Functions */

RING_API void ring_vm_gc_setfreefunc(Item *pItem, void (*pFreeFunc)(void *, void *)) { pItem->pGCFreeFunc = pFreeFunc; }

RING_API void ring_vm_gc_removetrack(RingState *pState, List *pList) {
	int nPos;
	if (pList->vGC.lTrackedList) {
		nPos = ring_list_findpointer_gc(pState, pState->pVM->pTrackedVariables, pList);
		if (nPos) {
			ring_list_deleteitem_gc(pState, pState->pVM->pTrackedVariables, nPos);
		}
		pList->vGC.lTrackedList = RING_FALSE;
	}
}

RING_API void ring_vm_gc_freefunc(RingState *pState, Item *pItem) {
	if (pItem->pGCFreeFunc != NULL) {
		if (pItem->data.pPointer != NULL) {
			pItem->pGCFreeFunc(pState, pItem->data.pPointer);
		}
	}
}

RING_API void ring_vm_gc_newitemreference(void *pState, Item *pItem) {
	if (pItem->nGCReferenceCount == RING_VM_REFCOUNTMAX) {
		printf(RING_REFCOUNTOVERFLOW);
		exit(RING_EXIT_FAIL);
	}
	pItem->nGCReferenceCount++;
}

RING_API void ring_vm_gc_cleardata(void *pState, Item *pItem) {
	pItem->nGCReferenceCount = 0;
	pItem->pGCFreeFunc = NULL;
}

RING_API void ring_vm_gc_deletelistinitem(void *pState, void *pList) { ring_list_delete_gc(pState, (List *)pList); }

RING_API void ring_vm_gc_finishitemdelete(void *pState, Item *pItem) {
	/* Call Free Function */
	if (pItem->nType == ITEMTYPE_POINTER) {
		ring_vm_gc_freefunc((RingState *)pState, pItem);
	}
	ring_item_deletecontent_gc(pState, pItem);
	ring_state_free(pState, pItem);
}

RING_API void ring_vm_gc_deleteitem(void *pState, Item *pItem) {
	VM *pVM;
	int nRefCount;
	/* Single Thread */
	if (pState == NULL || (((RingState *)pState)->pVM == NULL) || (((RingState *)pState)->pVM->pMutex == NULL)) {
		if (pItem->nGCReferenceCount == 0) {
			ring_vm_gc_finishitemdelete(pState, pItem);
		} else {
			pItem->nGCReferenceCount--;
		}
		return;
	}
	/*
	**  Many Threads
	**  Get pVM
	*/
	pVM = ((RingState *)pState)->pVM;
	/* Get nRefCount */
	ring_vm_custmutexlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_ITEMREFCOUNT]);
	nRefCount = pItem->nGCReferenceCount;
	ring_vm_custmutexunlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_ITEMREFCOUNT]);
	/* Delete/RefCountDecrement */
	if (nRefCount == 0) {
		ring_vm_gc_finishitemdelete(pState, pItem);
	} else {
		ring_vm_custmutexlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_ITEMREFCOUNT]);
		pItem->nGCReferenceCount--;
		ring_vm_custmutexunlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_ITEMREFCOUNT]);
	}
}

RING_API void ring_vm_gc_checknewreference(VM *pVM, void *pPointer, int nType, List *pContainer, int nIndex) {
	Item *pItem;
	/*
	**  Called when we create new pointer (new reference)
	**  The reference may be to a list or a sublist (list item)
	**  We care only about list items (sublists)
	*/
	if (nType == RING_OBJTYPE_LISTITEM) {
		pItem = (Item *)pPointer;
		ring_vm_custmutexlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_ITEMREFCOUNT]);
		ring_vm_gc_newitemreference(pVM->pRingState, pItem);
		/* Set the Free Function */
		pItem = ring_list_getitem_gc(pVM->pRingState, pContainer, nIndex);
		ring_vm_gc_setfreefunc(pItem, (void (*)(void *, void *))ring_vm_gc_deleteitem);
		/* Add the variable list to Tracked Variables */
		if (!pContainer->vGC.lTrackedList) {
			pContainer->vGC.lTrackedList = 1;
			ring_list_addpointer_gc(pVM->pRingState, pVM->pTrackedVariables, pContainer);
		}
		ring_vm_custmutexunlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_ITEMREFCOUNT]);
	}
}

RING_API void ring_vm_gc_checkupdatereference(VM *pVM, List *pList) {
	Item *pItem;
	/* Reference Counting to Destination before copy from Source */
	if (ring_list_getint(pList, RING_VAR_TYPE) == RING_VM_POINTER) {
		if (ring_list_getint(pList, RING_VAR_PVALUETYPE) == RING_OBJTYPE_LISTITEM) {
			pItem = (Item *)ring_list_getpointer(pList, RING_VAR_VALUE);
			ring_item_delete_gc(pVM->pRingState, pItem);
		}
	}
}

RING_API void ring_vm_gc_killreference(VM *pVM) {
	List *pList, *pList2;
	Item *pItem;
	char *newstr;
	char cStr[RING_CHARBUF];
	/* Check usage before the For In Loop, If there are a reference, set it to NULL */
	if (RING_VM_IR_READI == 1) {
		/* Kill the reference */
		pList = (List *)RING_VM_STACK_READP;
		RING_VM_STACK_POP;
		if (ring_list_getint(pList, RING_VAR_TYPE) == RING_VM_POINTER) {
			/* Delete Reference (Delete item using reference counting) */
			if (ring_list_getint(pList, RING_VAR_PVALUETYPE) == RING_OBJTYPE_LISTITEM) {
				pItem = (Item *)ring_list_getpointer(pList, RING_VAR_VALUE);
				ring_item_delete_gc(pVM->pRingState, pItem);
			}
			ring_list_setint_gc(pVM->pRingState, pList, RING_VAR_TYPE, RING_VM_STRING);
			ring_list_setstring_gc(pVM->pRingState, pList, RING_VAR_VALUE, RING_CSTR_EMPTY);
		}
		return;
	}
	/* The (For In) Loop generate the ICO_KILLREFERENCE instruction that call this function */
	if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
		pList = (List *)RING_VM_STACK_READP;
		RING_VM_STACK_POP;
		/* If we have a String then clear it (Like using for t in "test" , i.e. using literal instead of
		 * variable) */
		if (((ring_list_getint(pList, RING_VAR_TYPE) == RING_VM_STRING) ||
		     (ring_list_getint(pList, RING_VAR_TYPE) == RING_VM_NULL)) &&
		    (pVM->lExitFlag == 0)) {
			ring_list_setint_gc(pVM->pRingState, pList, RING_VAR_TYPE, RING_VM_STRING);
			ring_list_setstring_gc(pVM->pRingState, pList, RING_VAR_VALUE, RING_CSTR_EMPTY);
			return;
		}
		/* Be sure that it's a Pointer */
		if (ring_list_getint(pList, RING_VAR_TYPE) != RING_VM_POINTER) {
			return;
		}
		/* Get the Real Value that this reference points to */
		switch (ring_list_getint(pList, RING_VAR_PVALUETYPE)) {
		case RING_OBJTYPE_VARIABLE:
			/* We know that this case will never happens according to how (For In) loop works */
			break;
		case RING_OBJTYPE_LISTITEM:
			pItem = (Item *)ring_list_getpointer(pList, RING_VAR_VALUE);
			switch (ring_item_gettype(pItem)) {
			case ITEMTYPE_STRING:
				/* Set variable value to String */
				ring_list_setint_gc(pVM->pRingState, pList, RING_VAR_TYPE, RING_VM_STRING);
				if (pVM->lExitFlag == 1) {
					ring_list_setstring2_gc(pVM->pRingState, pList, RING_VAR_VALUE,
								ring_string_get(ring_item_getstring(pItem)),
								ring_string_size(ring_item_getstring(pItem)));
				} else {
					ring_list_setstring_gc(pVM->pRingState, pList, RING_VAR_VALUE, RING_CSTR_EMPTY);
				}
				break;
			case ITEMTYPE_NUMBER:
				if (pVM->lExitFlag == 1) {
					/* Set variable value to Number */
					ring_list_setint_gc(pVM->pRingState, pList, RING_VAR_TYPE, RING_VM_NUMBER);
					ring_list_setdouble_gc(pVM->pRingState, pList, RING_VAR_VALUE,
							       ring_item_getnumber_gc(pVM->pRingState, pItem));
				} else {
					ring_list_setint_gc(pVM->pRingState, pList, RING_VAR_TYPE, RING_VM_STRING);
					ring_list_setstring_gc(pVM->pRingState, pList, RING_VAR_VALUE, RING_CSTR_EMPTY);
				}
				break;
			case ITEMTYPE_LIST:
				if (pVM->lExitFlag == 1) {
					/* Set variable value to List */
					ring_list_setint_gc(pVM->pRingState, pList, RING_VAR_TYPE, RING_VM_LIST);
					ring_list_setlist_gc(pVM->pRingState, pList, RING_VAR_VALUE);
					pList2 = ring_list_getlist(pList, RING_VAR_VALUE);
					ring_vm_listcopy(pVM, pList2, ring_item_getlist(pItem));
				} else {
					ring_list_setint_gc(pVM->pRingState, pList, RING_VAR_TYPE, RING_VM_STRING);
					ring_list_setstring_gc(pVM->pRingState, pList, RING_VAR_VALUE, RING_CSTR_EMPTY);
				}
				break;
			}
			/* Delete Reference (Delete item using reference counting) */
			ring_item_delete_gc(pVM->pRingState, pItem);
			break;
		case RING_OBJTYPE_SUBSTRING:
			newstr = (char *)ring_list_getpointer(pList, RING_VAR_VALUE);
			cStr[0] = newstr[0];
			cStr[1] = '\0';
			/* Set variable value to String that equal the Character */
			ring_list_setint_gc(pVM->pRingState, pList, RING_VAR_TYPE, RING_VM_STRING);
			if (pVM->lExitFlag == 1) {
				ring_list_setstring_gc(pVM->pRingState, pList, RING_VAR_VALUE, cStr);
			} else {
				ring_list_setstring_gc(pVM->pRingState, pList, RING_VAR_VALUE, RING_CSTR_EMPTY);
			}
			break;
		}
	}
}

RING_API void ring_vm_gc_deletetemplists(VM *pVM) {
	/*
	**  This function is called from Ring code by callgc()
	**  Function Goal
	**  When we return Lists/Pointers from functions we create variable called ring_sys_temp
	**  This variable is created in the caller temp. memory instead of the active function scope
	**  This is necessary because the function scope will be deleted and we need the variable
	**  This is important because we may assign the variable to variable name
	**  The problem happens when we have a loop that uses f1(f2())
	**  and f2() return a lists/pointer
	**  The temp list/C Pointer will not be deleted until the end of the caller function
	**  But we have a loop and this will lead to a memory leak during loop execution
	**  When testing al_map_rgb() in Allegro Library this problem becomes critical
	**  This function solves this problem, by deleting temp lists/C Pointers in the current scope
	*/
	if (pVM->nInClassRegion) {
		return;
	}
	ring_list_deleteallitems_gc(pVM->pRingState, ring_vm_prevtempmem(pVM));
}
/*
**  List GC Functions
**  Protecting lists
*/

RING_API int ring_vm_gc_checkvarerroronassignment(VM *pVM, List *pVar) {
	List *pList;
	if (ring_list_islist(pVar, RING_VAR_VALUE)) {
		pList = ring_list_getlist(pVar, RING_VAR_VALUE);
		if (ring_list_iserroronassignment_gc(pVM->pRingState, pList) ||
		    ring_list_iserroronassignment2_gc(pVM->pRingState, pList)) {
			ring_vm_error(pVM, RING_VM_ERROR_PROTECTEDVALUE);
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}

RING_API int ring_vm_gc_checkitemerroronassignment(VM *pVM, Item *pItem) {
	List *pList;
	if (ring_item_gettype(pItem) == ITEMTYPE_LIST) {
		pList = ring_item_getlist(pItem);
		if (ring_list_iserroronassignment_gc(pVM->pRingState, pList) ||
		    ring_list_iserroronassignment2_gc(pVM->pRingState, pList)) {
			ring_vm_error(pVM, RING_VM_ERROR_PROTECTEDVALUE);
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}

RING_API int ring_vm_gc_checkbeforeassignment(VM *pVM, List *pVar) {
	if (pVar->vGC.lCheckBeforeAssignmentDone) {
		return RING_FALSE;
	}
	/*
	**  Check if the content is protected (List during definition)
	**  Also, Check Ref()/Reference() usage in the Left-Side
	*/
	if (ring_list_checkrefvarinleftside_gc(pVM->pRingState, pVar) ||
	    ring_vm_gc_checkvarerroronassignment(pVM, pVar)) {
		/*
		**  Take in mind using Ref()/Reference() in Right-Side too
		**  I.e. Ref(tmp) = Ref(tmp)
		**  We don't need to think about it - Because it's like Ref( Ref( Ref( ....) ) )
		*/
		return RING_TRUE;
	}
	pVar->vGC.lCheckBeforeAssignmentDone = RING_TRUE;
	return RING_FALSE;
}

RING_API void ring_vm_gc_removelistprotection(VM *pVM, List *pNestedLists, int nStart) {
	unsigned int x;
	for (x = nStart; x <= ring_list_getsize(pNestedLists); x++) {
		ring_vm_gc_removelistprotectionat(pVM, pNestedLists, x);
	}
}

RING_API void ring_vm_gc_removelistprotectionat(VM *pVM, List *pNestedLists, int nPos) {
	List *pList;
	/* Disable Error on Assignment */
	pList = (List *)ring_list_getpointer(pNestedLists, nPos);
	ring_list_disableerroronassignment_gc(pVM->pRingState, pList);
	/* Check if list is deleted by Parent */
	if (pList->vGC.lDeletedByParent) {
		pList->vGC.lDeletedByParent = 0;
		ring_list_delete_gc(pVM->pRingState, pList);
	}
}
/* References */

RING_API int ring_vm_gc_isrefparameter(VM *pVM, const char *cVariable) {
	int lRef;
	List *pRef, *pVar, *pList;
	lRef = 0;
	/* Check Reference */
	if (RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE) {
		pList = (List *)RING_VM_STACK_READP;
		if (ring_list_isrefcontainer_gc(pVM->pRingState, pList)) {
			pRef = ring_list_getlist(pList, RING_VAR_VALUE);
			if (ring_list_islnewref_gc(pVM->pRingState, pRef)) {
				lRef = 1;
				pVar = ring_vm_addlistarg(pVM, cVariable);
				ring_list_assignreftovar_gc(pVM->pRingState, pRef, pVar, RING_VAR_VALUE);
				/* If the same reference is passed as parameter multiple times then keep treating it as
				 * new reference */
				ring_list_enablelnewref_gc(pVM->pRingState, pRef);
			}
		}
	}
	return lRef;
}

RING_API void ring_list_acceptlistbyref_gc(void *pState, List *pList, unsigned int index, List *pRef) {
	List *pRealList;
	Item *pItem;
	/* Setting the list could be unnecessary but, we do this to have a solid function */
	ring_list_setlist_gc(pState, pList, index);
	/* Free the old list (We expect that it's an empty list) */
	pRealList = ring_list_getlist(pList, index);
	ring_list_delete_gc(pState, pRealList);
	/* Set the Item as a List reference */
	pItem = ring_list_getitem_gc(pState, pList, index);
	pItem->data.pList = pRef;
}

RING_API void ring_list_setlistbyref_gc(void *pState, List *pList, unsigned int index, List *pRef) {
	ring_list_acceptlistbyref_gc(pState, pList, index, pRef);
	/* Increment the Reference */
	ring_list_updaterefcount_gc(pState, pRef, RING_LISTREF_INC);
}

RING_API void ring_list_updaterefcount_gc(void *pState, List *pList, int nChange) {
	ring_vm_statecustmutexlock(pState, RING_VM_CUSTOMMUTEX_LISTREFCOUNT);
	if ((pList->vGC.nReferenceCount == RING_VM_REFCOUNTMAX) && (nChange > 0)) {
		ring_vm_statecustmutexunlock(pState, RING_VM_CUSTOMMUTEX_ITEMREFCOUNT);
		printf(RING_REFCOUNTOVERFLOW);
		exit(RING_EXIT_FAIL);
	}
	pList->vGC.nReferenceCount += nChange;
	ring_vm_statecustmutexunlock(pState, RING_VM_CUSTOMMUTEX_LISTREFCOUNT);
}

RING_API List *ring_list_newref_gc(void *pState, List *pVariableList, List *pList) {
	VM *pVM;
	pVM = NULL;
	if ((pState != NULL) && ((RingState *)pState)->pVM != NULL) {
		pVM = ((RingState *)pState)->pVM;
	}
	/* Note: The list may already have a container variable (Previous Reference) */
	ring_list_enablelnewref_gc(pState, pList);
	if (pList->vGC.pContainer == NULL) {
		ring_list_acceptlistbyref_gc(pState, pVariableList, RING_VAR_VALUE, pList);
		/* If we have a reference to an object, the Self attribute will stay pointing to the Container Variable
		 */
		if (ring_vm_oop_isobject(pVM, pList)) {
			ring_vm_oop_updateselfpointer(((RingState *)pState)->pVM, pList, RING_OBJTYPE_VARIABLE,
						      pVariableList);
		}
		/* We use lDontDelete to avoid deleting the container variable */
		pVariableList->vGC.lDontDelete = 1;
		/* When deleting the list (No other references exist) - It will delete the container variable */
		pList->vGC.lDeleteContainerVariable = 1;
		pList->vGC.pContainer = pVariableList;
	} else {
		/* Delete the unused container */
		ring_list_delete_gc(pState, pVariableList);
		pVariableList = (List *)pList->vGC.pContainer;
	}
	return pVariableList;
}

RING_API void ring_list_assignreftovar_gc(void *pState, List *pRef, List *pVar, unsigned int nPos) {
	ring_list_disablelnewref_gc(pState, pRef);
	if (ring_list_islist(pVar, nPos)) {
		if (ring_list_getlist(pVar, nPos) == pRef) {
			return;
		}
	}
	ring_list_setlistbyref_gc(pState, pVar, nPos, pRef);
}

RING_API void ring_list_assignreftoitem_gc(void *pState, List *pRef, Item *pItem) {
	List *pList;
	ring_list_disablelnewref_gc(pState, pRef);
	pList = ring_item_getlist(pItem);
	if (!(pList == pRef)) {
		ring_list_delete_gc(pState, pList);
		pItem->data.pList = pRef;
		ring_list_updaterefcount_gc(pState, pRef, RING_LISTREF_INC);
	}
}

RING_API List *ring_list_deleteref_gc(void *pState, List *pList) {
	List *pVariable;
	int nOPCode;
	RingState *pRingState;
	pRingState = (RingState *)pState;
	/* Check lDontDelete (Used by Container Variables) */
	if (pList->vGC.lDontDelete) {
		/* This is a container that we will not delete, but will be deleted by that list that know about it */
		return pList;
	}
	/* Check lErrorOnAssignment used by lists during definition */
	if (ring_list_iserroronassignment_gc(pState, pList)) {
		/* We are trying to delete a sub list which is protected */
		nOPCode = pRingState->pVM->nOPCode;
		if ((nOPCode == ICO_ASSIGNMENT) || (nOPCode == ICO_LISTSTART) || (nOPCode == ICO_NEWOBJ)) {
			pList->vGC.lDeletedByParent = 1;
			return pList;
		}
	}
	/* Avoid deleting objects when the list is just a reference */
	if (ring_list_isref_gc(pState, pList)) {
		/* We don't delete the list because there are other references */
		ring_list_disablelnewref_gc(pState, pList);
		if (ring_list_getrefcount_gc(pState, pList) > 1) {
			ring_list_updaterefcount_gc(pState, pList, RING_LISTREF_DEC);
			pList = ring_list_collectcycles_gc(pState, pList);
		} else {
			ring_list_addpointer_gc(pState, pRingState->pVM->pDeleteLater, pList);
		}
		return pList;
	}
	/* Delete Container Variable (If the list have one) */
	if (pList->vGC.lDeleteContainerVariable) {
		pVariable = (List *)pList->vGC.pContainer;
		pList->vGC.lDeleteContainerVariable = 0;
		pList->vGC.pContainer = NULL;
		/* Delete the Container */
		pVariable->vGC.lDontDelete = 0;
		pVariable->vGC.nReferenceCount = 0;
		ring_list_delete_gc(pState, pVariable);
		return NULL;
	}
	/* Check if the list is a tracked list */
	ring_vm_gc_removetrack(pRingState, pList);
	ring_list_deletecontent_gc(pState, pList);
	return NULL;
}

RING_API List *ring_list_collectcycles_gc(void *pState, List *pList) {
	List *aProcess, *pActiveList, *pSubList;
	unsigned int x, y, lDelete;
	Item *pItem;
	/* Be sure that we have a circular list */
	if (!ring_list_iscircular_gc(pState, pList)) {
		return pList;
	}
	/* Create the List */
	aProcess = ring_list_new_gc(pState, RING_ZERO);
	/* Add the Root */
	ring_list_addpointer_gc(pState, aProcess, pList);
	/*
	**  Process the List
	**  Set nTempRC to -1 for all references and be sure that we have circular reference
	*/
	for (x = 1; x <= ring_list_getsize(aProcess); x++) {
		pActiveList = (List *)ring_list_getpointer(aProcess, x);
		for (y = 1; y <= ring_list_getsize(pActiveList); y++) {
			if (ring_list_islist(pActiveList, y)) {
				pSubList = ring_list_getlist(pActiveList, y);
				pSubList->vGC.nTempRC = -1;
				if (!ring_list_findpointer_gc(pState, aProcess, pSubList)) {
					ring_list_addpointer_gc(pState, aProcess, pSubList);
				}
			}
		}
	}
	/* Delete all items in aProcess except the Root */
	while (ring_list_getsize(aProcess) > 1) {
		ring_list_deleteitem_gc(pState, aProcess, ring_list_getsize(aProcess));
	}
	/* Increment nTempRC for each reference even if it's repeated but follow each reference once */
	for (x = 1; x <= ring_list_getsize(aProcess); x++) {
		pActiveList = (List *)ring_list_getpointer(aProcess, x);
		for (y = 1; y <= ring_list_getsize(pActiveList); y++) {
			if (ring_list_islist(pActiveList, y)) {
				pSubList = ring_list_getlist(pActiveList, y);
				pSubList->vGC.nTempRC++;
				if (!ring_list_findpointer_gc(pState, aProcess, pSubList)) {
					ring_list_addpointer_gc(pState, aProcess, pSubList);
				}
			}
		}
	}
	/* Delete all items in aProcess except the Root */
	while (ring_list_getsize(aProcess) > 1) {
		ring_list_deleteitem_gc(pState, aProcess, ring_list_getsize(aProcess));
	}
	/* Be sure that we don't have external references */
	lDelete = 1;
	for (x = 1; x <= ring_list_getsize(aProcess); x++) {
		pActiveList = (List *)ring_list_getpointer(aProcess, x);
		for (y = 1; y <= ring_list_getsize(pActiveList); y++) {
			if (ring_list_islist(pActiveList, y)) {
				pSubList = ring_list_getlist(pActiveList, y);
				if ((pSubList != pList) && ring_list_containssublist_gc(pState, pSubList, pList)) {
					if (ring_list_getrefcountvalue_gc(pState, pSubList) > pSubList->vGC.nTempRC) {
						lDelete = 0;
						break;
					}
				}
				if (!ring_list_findpointer_gc(pState, aProcess, pSubList)) {
					ring_list_addpointer_gc(pState, aProcess, pSubList);
				}
			}
		}
	}
	/* Check if we can delete the Cycle */
	if ((ring_list_getrefcountvalue_gc(pState, pList) <= pList->vGC.nTempRC) && (lDelete == 1)) {
		/*
		**  Delete the Cycle
		**  Delete all items in aProcess except the Root
		*/
		while (ring_list_getsize(aProcess) > 1) {
			ring_list_deleteitem_gc(pState, aProcess, ring_list_getsize(aProcess));
		}
		/* Convert the item that contains circular reference from List to Empty String (To be able to delete it)
		 */
		for (x = 1; x <= ring_list_getsize(aProcess); x++) {
			pActiveList = (List *)ring_list_getpointer(aProcess, x);
			for (y = 1; y <= ring_list_getsize(pActiveList); y++) {
				if (ring_list_islist(pActiveList, y)) {
					pSubList = ring_list_getlist(pActiveList, y);
					if (!ring_list_findpointer_gc(pState, aProcess, pSubList)) {
						ring_list_addpointer_gc(pState, aProcess, pSubList);
					}
					if (pSubList == pList) {
						pItem = ring_list_getitem_gc(pState, pActiveList, y);
						pItem->nType = ITEMTYPE_STRING;
						pItem->data.pString = ring_string_new_gc(pState, RING_CSTR_EMPTY);
					}
				}
			}
		}
		/* It's important to set nReferenceCount to 0 because the same reference may contains many circular
		 * references */
		pList->vGC.nReferenceCount = 0;
		pList = ring_list_delete_gc(pState, pList);
	}
	/* Delete the List */
	ring_list_delete_gc(pState, aProcess);
	return pList;
}

RING_API int ring_list_containssublist_gc(void *pState, List *pList, List *pCheck) {
	List *aProcess, *pActiveList, *pSubList;
	unsigned int x, y, lFound;
	/* Check if the List is a circular reference */
	lFound = 0;
	aProcess = ring_list_new_gc(pState, RING_ZERO);
	ring_list_addpointer_gc(pState, aProcess, pList);
	for (x = 1; x <= ring_list_getsize(aProcess); x++) {
		pActiveList = (List *)ring_list_getpointer(aProcess, x);
		for (y = 1; y <= ring_list_getsize(pActiveList); y++) {
			if (ring_list_islist(pActiveList, y)) {
				pSubList = ring_list_getlist(pActiveList, y);
				if (!ring_list_findpointer_gc(pState, aProcess, pSubList)) {
					ring_list_addpointer_gc(pState, aProcess, pSubList);
				}
				if (pSubList == pCheck) {
					lFound = 1;
					break;
				}
			}
		}
	}
	ring_list_delete_gc(pState, aProcess);
	return lFound;
}

RING_API int ring_list_iscircular_gc(void *pState, List *pList) {
	return ring_list_containssublist_gc(pState, pList, pList);
}

RING_API int ring_list_checkrefinleftside_gc(void *pState, List *pList) {
	/* If we have Ref()/Reference() at the Left-Side then Delete the reference */
	if (ring_list_islnewref_gc(pState, pList)) {
		ring_list_disablelnewref_gc(pState, pList);
		return RING_TRUE;
	}
	return RING_FALSE;
}

RING_API int ring_list_checkrefvarinleftside_gc(void *pState, List *pVar) {
	/*
	**  Check Temp. Reference variable
	**  Because of this function, we have RING_TEMP_VAR & RING_TEMP_REF
	**  If we used RING_TEMP_VAR in all cases (Even when we create var using Ref())
	**  This could prevent assignment to variables contains temp. lists created while passing para. to functions
	*/
	if (strcmp(ring_list_getstring(pVar, RING_VAR_NAME), RING_TEMP_REF) == 0) {
		return RING_TRUE;
	}
	if (ring_list_getint(pVar, RING_VAR_TYPE) == RING_VM_LIST) {
		if (ring_list_islist(pVar, RING_VAR_VALUE)) {
			return ring_list_checkrefinleftside_gc(pState, ring_list_getlist(pVar, RING_VAR_VALUE));
		}
	}
	return RING_FALSE;
}

RING_API int ring_list_isref_gc(void *pState, List *pList) {
	int lRef;
	ring_vm_statecustmutexlock(pState, RING_VM_CUSTOMMUTEX_LISTREFCOUNT);
	lRef = (pList->vGC.nReferenceCount > 0) || (pList->vGC.lNewRef == 1);
	ring_vm_statecustmutexunlock(pState, RING_VM_CUSTOMMUTEX_LISTREFCOUNT);
	return lRef;
}

RING_API int ring_list_isrefcontainer_gc(void *pState, List *pList) { return pList->vGC.lDontDelete; }

RING_API void ring_list_clearrefdata_gc(void *pState, List *pList) {
	pList->vGC.pContainer = NULL;
	pList->vGC.nReferenceCount = 0;
	pList->vGC.nTempRC = 0;
	pList->vGC.lCopyByRef = 0;
	pList->vGC.lNewRef = 0;
	pList->vGC.lDontDelete = 0;
	pList->vGC.lDeleteContainerVariable = 0;
	pList->vGC.lDontRef = 0;
	pList->vGC.lErrorOnAssignment = 0;
	pList->vGC.lErrorOnAssignment2 = 0;
	pList->vGC.lCheckBeforeAssignmentDone = 0;
	pList->vGC.lDeletedByParent = 0;
	pList->vGC.lDontRefAgain = 0;
	pList->vGC.lTrackedList = 0;
	pList->vGC.lArgCache = 0;
	pList->vGC.nListType = 0;
	pList->vGC.lUnusedFlag = 0;
}

RING_API int ring_list_getrefcount_gc(void *pState, List *pList) {
	return ring_list_getrefcountvalue_gc(pState, pList) + 1;
}

RING_API int ring_list_getrefcountvalue_gc(void *pState, List *pList) {
	int nCount;
	ring_vm_statecustmutexlock(pState, RING_VM_CUSTOMMUTEX_LISTREFCOUNT);
	nCount = pList->vGC.nReferenceCount;
	ring_vm_statecustmutexunlock(pState, RING_VM_CUSTOMMUTEX_LISTREFCOUNT);
	return nCount;
}

RING_API int ring_list_isdontref_gc(void *pState, List *pList) { return pList->vGC.lDontRef; }

RING_API void ring_list_enabledontref_gc(void *pState, List *pList) { pList->vGC.lDontRef = 1; }

RING_API void ring_list_disabledontref_gc(void *pState, List *pList) { pList->vGC.lDontRef = 0; }

RING_API int ring_list_islnewref_gc(void *pState, List *pList) {
	int lNewRef;
	ring_vm_statecustmutexlock(pState, RING_VM_CUSTOMMUTEX_LNEWREF);
	lNewRef = pList->vGC.lNewRef;
	ring_vm_statecustmutexunlock(pState, RING_VM_CUSTOMMUTEX_LNEWREF);
	return lNewRef;
}

RING_API void ring_list_enablelnewref_gc(void *pState, List *pRef) {
	ring_vm_statecustmutexlock(pState, RING_VM_CUSTOMMUTEX_LNEWREF);
	pRef->vGC.lNewRef = 1;
	ring_vm_statecustmutexunlock(pState, RING_VM_CUSTOMMUTEX_LNEWREF);
}

RING_API void ring_list_disablelnewref_gc(void *pState, List *pRef) {
	ring_vm_statecustmutexlock(pState, RING_VM_CUSTOMMUTEX_LNEWREF);
	pRef->vGC.lNewRef = 0;
	ring_vm_statecustmutexunlock(pState, RING_VM_CUSTOMMUTEX_LNEWREF);
}

RING_API void ring_list_resetlnewref_gc(void *pState, List *pVar) {
	List *pList;
	if (ring_list_getint(pVar, RING_VAR_TYPE) == RING_VM_LIST) {
		pList = ring_list_getlist(pVar, RING_VAR_VALUE);
		ring_list_disablelnewref_gc(pState, pList);
	}
}

RING_API int ring_list_isdontrefagain_gc(void *pState, List *pList) { return pList->vGC.lDontRefAgain; }

RING_API void ring_list_enabledontrefagain_gc(void *pState, List *pList) { pList->vGC.lDontRefAgain = 1; }

RING_API void ring_list_disabledontrefagain_gc(void *pState, List *pList) { pList->vGC.lDontRefAgain = 0; }
/* Copy list by Reference */

RING_API int ring_list_iscopybyref_gc(void *pState, List *pList) { return pList->vGC.lCopyByRef; }

RING_API void ring_list_enablecopybyref_gc(void *pState, List *pList) { pList->vGC.lCopyByRef = 1; }

RING_API void ring_list_disablecopybyref_gc(void *pState, List *pList) { pList->vGC.lCopyByRef = 0; }
/* Error on assignment */

RING_API void ring_list_enableerroronassignment_gc(void *pState, List *pList) { pList->vGC.lErrorOnAssignment = 1; }

RING_API void ring_list_disableerroronassignment_gc(void *pState, List *pList) { pList->vGC.lErrorOnAssignment = 0; }

RING_API int ring_list_iserroronassignment_gc(void *pState, List *pList) { return pList->vGC.lErrorOnAssignment; }
/* Error on assignment2 */

RING_API void ring_list_enableerroronassignment2_gc(void *pState, List *pList) { pList->vGC.lErrorOnAssignment2 = 1; }

RING_API int ring_list_iserroronassignment2_gc(void *pState, List *pList) { return pList->vGC.lErrorOnAssignment2; }

RING_API void ring_list_disableerroronassignment2_gc(void *pState, List *pList) { pList->vGC.lErrorOnAssignment2 = 0; }
/* Argument Type */

RING_API void ring_list_setlisttype_gc(void *pState, List *pList, unsigned int nType) { pList->vGC.nListType = nType; }

RING_API unsigned int ring_list_getlisttype_gc(void *pState, List *pList) { return pList->vGC.nListType; }

RING_API int ring_list_isargcache_gc(void *pState, List *pList) { return pList->vGC.lArgCache; }

RING_API void ring_list_enableargcache_gc(void *pState, List *pList) { pList->vGC.lArgCache = RING_TRUE; }
/* Don't delete */

RING_API void ring_list_enabledontdelete_gc(void *pState, List *pList) { pList->vGC.lDontDelete = RING_TRUE; }

RING_API void ring_list_disabledontdelete_gc(void *pState, List *pList) { pList->vGC.lDontDelete = RING_FALSE; }
/* Memory Functions (General) */

RING_API void *ring_malloc(size_t nSize) {
	void *pMemory;
	pMemory = malloc(nSize);
	/* Check Memory */
	if (pMemory == NULL) {
		printf(RING_OOM);
		printf("Ring (MALLOC) - Can't allocate %lu bytes\n", (unsigned long)nSize);
		exit(RING_EXIT_FAIL);
	}
	return pMemory;
}

RING_API void ring_free(void *pPointer) { free(pPointer); }

RING_API void *ring_calloc(size_t nItems, size_t nSize) {
	void *pMemory;
	pMemory = calloc(nItems, nSize);
	/* Check Memory */
	if (pMemory == NULL) {
		printf(RING_OOM);
		printf("Ring (CALLOC) - Can't allocate %lu bytes\n", (unsigned long)(nItems * nSize));
		exit(RING_EXIT_FAIL);
	}
	return pMemory;
}

RING_API void *ring_realloc(void *pPointer, size_t nSize) {
	void *pMemory;
	pMemory = realloc(pPointer, nSize);
	/* Check Memory */
	if (pMemory == NULL) {
		printf(RING_OOM);
		printf("Ring (REALLOC) - Can't allocate %lu bytes\n", (unsigned long)nSize);
		exit(RING_EXIT_FAIL);
	}
	return pMemory;
}
/* Memory Functions (RingState Aware) */

RING_API void *ring_state_malloc(void *pState, size_t nSize) {
#if RING_USEPOOLMANAGER
	if (pState != NULL) {
		if (!((RingState *)pState)->lDisablePoolManager) {
			if (((RingState *)pState)->pVM != NULL) {
				if (nSize <= sizeof(PoolDataL3)) {
					return ring_poolmanager_allocate((RingState *)pState, nSize);
				}
			}
		}
	}
#endif
	return ring_malloc(nSize);
}

RING_API void ring_state_free(void *pState, void *pMemory) {
	void *pBlockStart;
	void *pBlockEnd;
	List *pBlocks, *pBlock;
	unsigned int x, lFound;
	RingState *pRingState;
	pRingState = (RingState *)pState;
#if RING_USEPOOLMANAGER
	/* Use Pool Manager */
	if (pState != NULL) {
		if (ring_poolmanager_free(((RingState *)pState), pMemory)) {
			return;
		}
	}
#endif
	/* Check sections inside Memory Blocks */
	if (pRingState != NULL) {
		lFound = 0;
		if (pRingState->pVM != NULL) {
			ring_vm_custmutexlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
		}
		pBlocks = pRingState->vPoolManager.pBlocks;
		if (pBlocks != NULL) {
			for (x = 1; x <= ring_list_getsize(pBlocks); x++) {
				pBlock = ring_list_getlist(pBlocks, x);
				pBlockStart = ring_list_getpointer(pBlock, RING_VM_BLOCKSTART);
				pBlockEnd = ring_list_getpointer(pBlock, RING_VM_BLOCKEND);
				if ((pMemory >= pBlockStart) && (pMemory <= pBlockEnd)) {
					/* We have the memory inside a block, so we will not delete it! */
					lFound = 1;
					break;
				}
			}
		}
		if (pRingState->pVM != NULL) {
			ring_vm_custmutexunlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
		}
		if (lFound == 1) {
			return;
		}
	}
	ring_free(pMemory);
}

RING_API void *ring_state_calloc(void *pState, size_t nItems, size_t nSize) {
	void *pMem;
	size_t nTotal;
#if RING_USEPOOLMANAGER
	if (pState != NULL) {
		nTotal = nItems * nSize;
		if ((nTotal <= sizeof(PoolDataL3)) && (!((RingState *)pState)->lDisablePoolManager)) {
			if (((RingState *)pState)->pVM != NULL) {
				pMem = ring_poolmanager_allocate((RingState *)pState, nTotal);
				memset(pMem, RING_ZERO, nTotal);
				return pMem;
			}
		}
	}
#endif
	return ring_calloc(nItems, nSize);
}

RING_API void *ring_state_realloc(void *pState, void *pPointer, size_t nAllocatedSize, size_t nSize) {
#if RING_USEPOOLMANAGER
	void *pMemory;
	int nLevel, nUseMalloc;
	size_t x;
	nUseMalloc = 0;
	if (pState != NULL) {
		if (((RingState *)pState)->pVM != NULL) {
			nLevel = ring_poolmanager_find((RingState *)pState, pPointer);
			/* Level 1 */
			if (nLevel == RING_POOLMANAGER_LEVEL1) {
				if (nSize <= sizeof(PoolData)) {
					/*
					**  The Pointer belong to memory pool and new size less than
					*RING_POOLMANAGER_ITEMSIZE
					**  In this case, just return the same pointer since we have space for the new
					*data
					*/
					return pPointer;
				} else {
					nUseMalloc = 1;
				}
			}
			/* Level 2 */
			else if (nLevel == RING_POOLMANAGER_LEVEL2) {
				if (nSize <= sizeof(PoolDataL2)) {
					return pPointer;
				} else {
					nUseMalloc = 1;
				}
			}
			/* Level 3 */
			else if (nLevel == RING_POOLMANAGER_LEVEL3) {
				if (nSize <= sizeof(PoolDataL3)) {
					return pPointer;
				} else {
					nUseMalloc = 1;
				}
			}
			if (nUseMalloc == 1) {
				/* Allocate new buffer, copy data to it and then free existing pointer from pool */
				pMemory = ring_state_malloc(pState, nSize);
				/* Copy existing data */
				RING_MEMCPY((unsigned char *)pMemory, (unsigned char *)pPointer, nAllocatedSize);
				ring_poolmanager_free(((RingState *)pState), pPointer);
				return pMemory;
			}
		}
	}
#endif
	return ring_realloc(pPointer, nSize);
}

RING_API void ring_state_registerblock(void *pState, void *pStart, void *pEnd) {
	List *pList;
	RingState *pRingState;
	pRingState = (RingState *)pState;
	ring_vm_custmutexlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
	pList = ring_list_newlist(pRingState->vPoolManager.pBlocks);
	ring_list_addpointer(pList, pStart);
	ring_list_addpointer(pList, pEnd);
	ring_list_genarray(pRingState->vPoolManager.pBlocks);
	ring_vm_custmutexunlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
}

RING_API void ring_state_unregisterblock(void *pState, void *pStart) {
	unsigned int x;
	List *pList;
	RingState *pRingState;
	void *pBlockStart;
	pRingState = (RingState *)pState;
	ring_vm_custmutexlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
	for (x = 1; x <= ring_list_getsize(pRingState->vPoolManager.pBlocks); x++) {
		pList = ring_list_getlist(pRingState->vPoolManager.pBlocks, x);
		pBlockStart = ring_list_getpointer(pList, RING_VM_BLOCKSTART);
		if (pBlockStart == pStart) {
			ring_list_deleteitem(pRingState->vPoolManager.pBlocks, x);
			break;
		}
	}
	ring_list_genarray(pRingState->vPoolManager.pBlocks);
	ring_vm_custmutexunlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
}

RING_API void ring_state_willunregisterblock(void *pState, void *pStart) {
	unsigned int x, x2, x3;
	List *pList, *pVar;
	Item *pItem, *pNewItem;
	Item vTempItem;
	RingState *pRingState;
	void *pBlockStart, *pBlockEnd;
	pRingState = (RingState *)pState;
	/* Check lists size */
	if (ring_list_getsize(pRingState->pVM->pTrackedVariables) == 0) {
		return;
	}
	ring_vm_custmutexlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
	if (ring_list_getsize(pRingState->vPoolManager.pBlocks) == 0) {
		ring_vm_custmutexunlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
		return;
	}
	for (x = 1; x <= ring_list_getsize(pRingState->vPoolManager.pBlocks); x++) {
		pList = ring_list_getlist(pRingState->vPoolManager.pBlocks, x);
		pBlockStart = ring_list_getpointer(pList, RING_VM_BLOCKSTART);
		pBlockEnd = ring_list_getpointer(pList, RING_VM_BLOCKEND);
		if (pBlockStart == pStart) {
			/* Check Tracked Variables that have items inside this block */
			for (x2 = 1; x2 <= ring_list_getsize(pRingState->pVM->pTrackedVariables); x2++) {
				pVar = (List *)ring_list_getpointer(pRingState->pVM->pTrackedVariables, x2);
				if ((ring_list_getint(pVar, RING_VAR_TYPE) == RING_VM_POINTER) &&
				    (ring_list_getint(pVar, RING_VAR_PVALUETYPE) == RING_OBJTYPE_LISTITEM)) {
					pItem = (Item *)ring_list_getpointer(pVar, RING_VAR_VALUE);
					if ((((void *)pItem) >= pBlockStart) && (((void *)pItem) <= pBlockEnd)) {
						pNewItem = ring_item_new_gc(pRingState, ITEMTYPE_NOTHING);
						memcpy(&vTempItem, pNewItem, sizeof(Item));
						memcpy(pNewItem, pItem, sizeof(Item));
						memcpy(pItem, &vTempItem, sizeof(Item));
						ring_list_setpointer_gc(pRingState, pVar, RING_VAR_VALUE, pNewItem);
						/* Delete Reference (Delete item using reference counting) */
						ring_item_delete_gc(pRingState, pItem);
						for (x3 = ring_list_getsize(pRingState->pVM->pTrackedVariables);
						     x3 >= x2; x3--) {
							pVar = (List *)ring_list_getpointer(
							    pRingState->pVM->pTrackedVariables, x3);
							if ((ring_list_getint(pVar, RING_VAR_TYPE) ==
							     RING_VM_POINTER) &&
							    (ring_list_getint(pVar, RING_VAR_PVALUETYPE) ==
							     RING_OBJTYPE_LISTITEM)) {
								if (ring_list_getpointer(pVar, RING_VAR_VALUE) ==
								    pItem) {
									ring_list_setpointer_gc(
									    pRingState, pVar, RING_VAR_VALUE, pNewItem);
									ring_list_deleteitem_gc(
									    pRingState,
									    pRingState->pVM->pTrackedVariables, x3);
								}
							}
						}
					}
				}
			}
			break;
		}
	}
	ring_vm_custmutexunlock(pRingState->pVM, pRingState->vPoolManager.pMutex);
}
/* Pool Manager Functions */

RING_API void ring_poolmanager_new(RingState *pRingState) {
	/* Level 1 */
	pRingState->vPoolManager.pCurrentItem = NULL;
	pRingState->vPoolManager.pBlockStart = NULL;
	pRingState->vPoolManager.pBlockEnd = NULL;
	pRingState->vPoolManager.nItemsInBlock = RING_POOLMANAGER_ITEMSINBLOCK;
	/* Level 2 */
	pRingState->vPoolManager.pCurrentItemL2 = NULL;
	pRingState->vPoolManager.pBlockStartL2 = NULL;
	pRingState->vPoolManager.pBlockEndL2 = NULL;
	pRingState->vPoolManager.nItemsInBlockL2 = RING_POOLMANAGER_ITEMSINBLOCKL2;
	/* Level 3 */
	pRingState->vPoolManager.pCurrentItemL3 = NULL;
	pRingState->vPoolManager.pBlockStartL3 = NULL;
	pRingState->vPoolManager.pBlockEndL3 = NULL;
	pRingState->vPoolManager.nItemsInBlockL3 = RING_POOLMANAGER_ITEMSINBLOCKL3;
	/* State Level */
	pRingState->vPoolManager.pCurrentItemStateLevel = NULL;
	pRingState->vPoolManager.pBlockStartStateLevel = NULL;
	pRingState->vPoolManager.pBlockEndStateLevel = NULL;
	pRingState->vPoolManager.nItemsInBlockStateLevel = RING_POOLMANAGER_ITEMSINBLOCKStateLevel;
	pRingState->vPoolManager.pBlocks = ring_list_new(RING_ZERO);
	pRingState->vPoolManager.lDeleteMemory = 1;
	pRingState->vPoolManager.pMutex = NULL;
}

RING_API void ring_poolmanager_newblock(RingState *pRingState) {
	PoolData *pMemory;
	PoolDataL2 *pMemoryL2;
	PoolDataL3 *pMemoryL3;
	PoolDataStateLevel *pMemoryStateLevel;
	unsigned int x;
	/*
	**  Level 1
	**  Get Block Memory
	*/
	pMemory = (PoolData *)ring_calloc(pRingState->vPoolManager.nItemsInBlock, sizeof(PoolData));
	/* Set Linked Lists (pNext values) */
	for (x = 0; x < pRingState->vPoolManager.nItemsInBlock - 1; x++) {
		pMemory[x].pNext = pMemory + x + 1;
	}
	pMemory[pRingState->vPoolManager.nItemsInBlock - 1].pNext = NULL;
	/*
	**  Set Values in Ring State
	**  Set First Item in Ring State
	*/
	pRingState->vPoolManager.pCurrentItem = pMemory;
	/* Set Block Start and End */
	pRingState->vPoolManager.pBlockStart = (void *)pMemory;
	pRingState->vPoolManager.pBlockEnd = (void *)(pMemory + pRingState->vPoolManager.nItemsInBlock - 1);
	/*
	**  Level 2
	**  Get Block Memory
	*/
	pMemoryL2 = (PoolDataL2 *)ring_calloc(pRingState->vPoolManager.nItemsInBlockL2, sizeof(PoolDataL2));
	/* Set Linked Lists (pNext values) */
	for (x = 0; x < pRingState->vPoolManager.nItemsInBlockL2 - 1; x++) {
		pMemoryL2[x].pNext = pMemoryL2 + x + 1;
	}
	pMemoryL2[pRingState->vPoolManager.nItemsInBlockL2 - 1].pNext = NULL;
	/*
	**  Set Values in Ring State
	**  Set First Item in Ring State
	*/
	pRingState->vPoolManager.pCurrentItemL2 = pMemoryL2;
	/* Set Block Start and End */
	pRingState->vPoolManager.pBlockStartL2 = (void *)pMemoryL2;
	pRingState->vPoolManager.pBlockEndL2 = (void *)(pMemoryL2 + pRingState->vPoolManager.nItemsInBlockL2 - 1);
	/*
	**  Level 3
	**  Get Block Memory
	*/
	pMemoryL3 = (PoolDataL3 *)ring_calloc(pRingState->vPoolManager.nItemsInBlockL3, sizeof(PoolDataL3));
	/* Set Linked Lists (pNext values) */
	for (x = 0; x < pRingState->vPoolManager.nItemsInBlockL3 - 1; x++) {
		pMemoryL3[x].pNext = pMemoryL3 + x + 1;
	}
	pMemoryL3[pRingState->vPoolManager.nItemsInBlockL3 - 1].pNext = NULL;
	/*
	**  Set Values in Ring State
	**  Set First Item in Ring State
	*/
	pRingState->vPoolManager.pCurrentItemL3 = pMemoryL3;
	/* Set Block Start and End */
	pRingState->vPoolManager.pBlockStartL3 = (void *)pMemoryL3;
	pRingState->vPoolManager.pBlockEndL3 = (void *)(pMemoryL3 + pRingState->vPoolManager.nItemsInBlockL3 - 1);
	/*
	**  State Level
	**  Get Block Memory
	*/
	pMemoryStateLevel = (PoolDataStateLevel *)ring_calloc(pRingState->vPoolManager.nItemsInBlockStateLevel,
							      sizeof(PoolDataStateLevel));
	/* Set Linked Lists (pNext values) */
	for (x = 0; x < pRingState->vPoolManager.nItemsInBlockStateLevel - 1; x++) {
		pMemoryStateLevel[x].pNext = pMemoryStateLevel + x + 1;
	}
	pMemoryStateLevel[pRingState->vPoolManager.nItemsInBlockStateLevel - 1].pNext = NULL;
	/*
	**  Set Values in Ring State
	**  Set First Item in Ring State
	*/
	pRingState->vPoolManager.pCurrentItemStateLevel = pMemoryStateLevel;
	/* Set Block Start and End */
	pRingState->vPoolManager.pBlockStartStateLevel = (void *)pMemoryStateLevel;
	pRingState->vPoolManager.pBlockEndStateLevel =
	    (void *)(pMemoryStateLevel + pRingState->vPoolManager.nItemsInBlockStateLevel - 1);
}

RING_API void *ring_poolmanager_allocate(RingState *pRingState, size_t nSize) {
	void *pMemory;
	/* If No memory - Create new block */
	if ((pRingState->vPoolManager.pCurrentItem == NULL) && (pRingState->vPoolManager.pBlockStart == NULL) &&
	    (pRingState->lStartPoolManager) && (pRingState->lOnlyTokens == 0)) {
		ring_poolmanager_newblock(pRingState);
	}
	/* Get Item from the Pool Manager */
	if ((nSize <= sizeof(PoolData)) && pRingState->vPoolManager.pCurrentItem != NULL) {
		pMemory = pRingState->vPoolManager.pCurrentItem;
		pRingState->vPoolManager.pCurrentItem = pRingState->vPoolManager.pCurrentItem->pNext;
	}
	/* Get Item from Pool Manager Level 2 */
	else if (((nSize > sizeof(PoolData)) && (nSize <= sizeof(PoolDataL2))) &&
		 (pRingState->vPoolManager.pCurrentItemL2 != NULL)) {
		pMemory = pRingState->vPoolManager.pCurrentItemL2;
		pRingState->vPoolManager.pCurrentItemL2 = pRingState->vPoolManager.pCurrentItemL2->pNext;
	}
	/* Get Item from Pool Manager Level 3 */
	else if (((nSize > sizeof(PoolDataL2)) && (nSize <= sizeof(PoolDataL3))) &&
		 (pRingState->vPoolManager.pCurrentItemL3 != NULL)) {
		pMemory = pRingState->vPoolManager.pCurrentItemL3;
		pRingState->vPoolManager.pCurrentItemL3 = pRingState->vPoolManager.pCurrentItemL3->pNext;
	}
	/* If no free items, Allocate new item */
	else {
		pMemory = ring_malloc(nSize);
	}
	return pMemory;
}

RING_API int ring_poolmanager_find(RingState *pRingState, void *pMemory) {
	if (pRingState != NULL) {
		/* Level 1 */
		if (pRingState->vPoolManager.pBlockStart != NULL) {
			if ((pMemory >= pRingState->vPoolManager.pBlockStart) &&
			    (pMemory <= pRingState->vPoolManager.pBlockEnd)) {
				return RING_POOLMANAGER_LEVEL1;
			}
		}
		/* Level 2 */
		if (pRingState->vPoolManager.pBlockStartL2 != NULL) {
			if ((pMemory >= pRingState->vPoolManager.pBlockStartL2) &&
			    (pMemory <= pRingState->vPoolManager.pBlockEndL2)) {
				return RING_POOLMANAGER_LEVEL2;
			}
		}
		/* Level 3 */
		if (pRingState->vPoolManager.pBlockStartL3 != NULL) {
			if ((pMemory >= pRingState->vPoolManager.pBlockStartL3) &&
			    (pMemory <= pRingState->vPoolManager.pBlockEndL3)) {
				return RING_POOLMANAGER_LEVEL3;
			}
		}
	}
	/* Reaching this point means that the Pool Manager doesn't own this memory to free it! */
	return RING_POOLMANAGER_NOTFOUND;
}

RING_API int ring_poolmanager_free(RingState *pRingState, void *pMemory) {
	PoolData *pPoolData;
	PoolDataL2 *pPoolDataL2;
	PoolDataL3 *pPoolDataL3;
	int nLevel, lRet;
	lRet = 0;
	nLevel = ring_poolmanager_find(pRingState, pMemory);
	if (nLevel == RING_POOLMANAGER_LEVEL1) {
		pPoolData = (PoolData *)pMemory;
		pPoolData->pNext = pRingState->vPoolManager.pCurrentItem;
		pRingState->vPoolManager.pCurrentItem = pPoolData;
		lRet = 1;
	} else if (nLevel == RING_POOLMANAGER_LEVEL2) {
		pPoolDataL2 = (PoolDataL2 *)pMemory;
		pPoolDataL2->pNext = pRingState->vPoolManager.pCurrentItemL2;
		pRingState->vPoolManager.pCurrentItemL2 = pPoolDataL2;
		lRet = 1;
	} else if (nLevel == RING_POOLMANAGER_LEVEL3) {
		pPoolDataL3 = (PoolDataL3 *)pMemory;
		pPoolDataL3->pNext = pRingState->vPoolManager.pCurrentItemL3;
		pRingState->vPoolManager.pCurrentItemL3 = pPoolDataL3;
		lRet = 1;
	}
	/* Reaching this point and lRet=0 means that the Pool Manager doesn't own this memory to free it! */
	return lRet;
}

RING_API void ring_poolmanager_delete(RingState *pRingState) {
	if (pRingState != NULL) {
		if (pRingState->vPoolManager.lDeleteMemory) {
			pRingState->vPoolManager.pBlocks = ring_list_delete(pRingState->vPoolManager.pBlocks);
			/* Level 1 */
			if (pRingState->vPoolManager.pBlockStart != NULL) {
				free(pRingState->vPoolManager.pBlockStart);
				pRingState->vPoolManager.pBlockStart = NULL;
				pRingState->vPoolManager.pBlockEnd = NULL;
				pRingState->vPoolManager.pCurrentItem = NULL;
			}
			/* Level 2 */
			if (pRingState->vPoolManager.pBlockStartL2 != NULL) {
				free(pRingState->vPoolManager.pBlockStartL2);
				pRingState->vPoolManager.pBlockStartL2 = NULL;
				pRingState->vPoolManager.pBlockEndL2 = NULL;
				pRingState->vPoolManager.pCurrentItemL2 = NULL;
			}
			/* Level 3 */
			if (pRingState->vPoolManager.pBlockStartL3 != NULL) {
				free(pRingState->vPoolManager.pBlockStartL3);
				pRingState->vPoolManager.pBlockStartL3 = NULL;
				pRingState->vPoolManager.pBlockEndL3 = NULL;
				pRingState->vPoolManager.pCurrentItemL3 = NULL;
			}
			/* State Level */
			if (pRingState->vPoolManager.pBlockStartStateLevel != NULL) {
				free(pRingState->vPoolManager.pBlockStartStateLevel);
				pRingState->vPoolManager.pBlockStartStateLevel = NULL;
				pRingState->vPoolManager.pBlockEndStateLevel = NULL;
				pRingState->vPoolManager.pCurrentItemStateLevel = NULL;
			}
		}
	}
}

RING_API void ring_poolmanager_newblockfromsubthread(RingState *pSubRingState, int nCount, RingState *pMainRingState) {
	int x;
	PoolData *pMemory;
	/*
	**  When we create a new thread - we share the memory pool information
	**  Because memory pool items from different threads could be used in shared global lists
	**  We use ring_calloc() instead of ring_state_calloc() to be thread safe
	**  Set Values in Ring State
	**  Set First Item in Ring State
	*/
	pSubRingState->vPoolManager.pCurrentItem = (PoolData *)ring_calloc(RING_ONE, sizeof(PoolData));
	/* Set Block Start and End (Level 1) */
	pSubRingState->vPoolManager.pBlockStart = pMainRingState->vPoolManager.pBlockStart;
	pSubRingState->vPoolManager.pBlockEnd = pMainRingState->vPoolManager.pBlockEnd;
	/* Set Block Start and End (Level 2) */
	pSubRingState->vPoolManager.pBlockStartL2 = pMainRingState->vPoolManager.pBlockStartL2;
	pSubRingState->vPoolManager.pBlockEndL2 = pMainRingState->vPoolManager.pBlockEndL2;
	/* Set Block Start and End (Level 3) */
	pSubRingState->vPoolManager.pBlockStartL3 = pMainRingState->vPoolManager.pBlockStartL3;
	pSubRingState->vPoolManager.pBlockEndL3 = pMainRingState->vPoolManager.pBlockEndL3;
	/* Set Block Start and End (State Level) */
	pSubRingState->vPoolManager.pBlockStartStateLevel = pMainRingState->vPoolManager.pBlockStartStateLevel;
	pSubRingState->vPoolManager.pBlockEndStateLevel = pMainRingState->vPoolManager.pBlockEndStateLevel;
	/* Don't delete the memory because it's owned by the Main Thread */
	pSubRingState->vPoolManager.lDeleteMemory = 0;
	/* Create the Items */
	pMemory = pSubRingState->vPoolManager.pCurrentItem;
	for (x = 1; x <= nCount - 1; x++) {
		pMemory->pNext = (PoolData *)ring_calloc(RING_ONE, sizeof(PoolData));
		pMemory = pMemory->pNext;
	}
	pMemory->pNext = NULL;
	pSubRingState->vPoolManager.nItemsInBlock = nCount;
}

RING_API void ring_poolmanager_deleteblockfromsubthread(RingState *pSubRingState, RingState *pMainRingState) {
	PoolData *pMemory, *pNextMemory;
	pMemory = pSubRingState->vPoolManager.pCurrentItem;
	while (pMemory != NULL) {
		pNextMemory = pMemory->pNext;
		/*
		**  Free Memory that doesn't belong to the memory pool
		**  (1) if the memory belong to the memory pool (created in main thread, deleted by sub thread)
		**  Then it will not be deleted and will not return to main thread (To avoid lock/unlock & slow
		*performance)
		**  So, In Ring it's not a good practice to delete global/shared memory from sub threads
		**  (2) Remember that using ring_state_free() could update vPoolManager.pCurrentItem if item is inside
		*Block
		**  So, we use pNextMemory instead of vPoolManager.pCurrentItem
		*/
		ring_state_free(pSubRingState, pMemory);
		pMemory = pNextMemory;
	}
	pSubRingState->vPoolManager.pCurrentItem = NULL;
}
/* VMState Memory Functions */

RING_API VMState *ring_vmstate_new(RingState *pRingState) {
	VMState *pVMState;
#if RING_USEPOOLMANAGER
	if (pRingState != NULL) {
		/* Get Item from the Pool Manager */
		if (pRingState->vPoolManager.pCurrentItemStateLevel != NULL) {
			pVMState = (VMState *)pRingState->vPoolManager.pCurrentItemStateLevel;
			pRingState->vPoolManager.pCurrentItemStateLevel =
			    pRingState->vPoolManager.pCurrentItemStateLevel->pNext;
			return pVMState;
		}
	}
#endif
	pVMState = (VMState *)ring_malloc(sizeof(VMState));
	return pVMState;
}

RING_API void ring_vmstate_delete(void *pState, void *pMemory) {
	RingState *pRingState;
	PoolDataStateLevel *pPoolDataStateLevel;
#if RING_USEPOOLMANAGER
	if (pState != NULL) {
		pRingState = (RingState *)pState;
		if (pRingState->vPoolManager.pBlockStartStateLevel != NULL) {
			if ((pMemory >= pRingState->vPoolManager.pBlockStartStateLevel) &&
			    (pMemory <= pRingState->vPoolManager.pBlockEndStateLevel)) {
				pPoolDataStateLevel = (PoolDataStateLevel *)pMemory;
				pPoolDataStateLevel->pNext = pRingState->vPoolManager.pCurrentItemStateLevel;
				pRingState->vPoolManager.pCurrentItemStateLevel = pPoolDataStateLevel;
				return;
			}
		}
	}
#endif
	ring_free(pMemory);
}
