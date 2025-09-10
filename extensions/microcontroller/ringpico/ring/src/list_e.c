/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_list_loadfunctions(RingState *pRingState) {
	/* Lists */
	RING_API_REGISTER("add", ring_vm_listfuncs_add);
	RING_API_REGISTER("del", ring_vm_listfuncs_del);
	RING_API_REGISTER("swap", ring_vm_listfuncs_swap);
	RING_API_REGISTER("list", ring_vm_listfuncs_list);
	RING_API_REGISTER("find", ring_vm_listfuncs_find);
	RING_API_REGISTER("min", ring_vm_listfuncs_min);
	RING_API_REGISTER("max", ring_vm_listfuncs_max);
	RING_API_REGISTER("insert", ring_vm_listfuncs_insert);
	RING_API_REGISTER("sort", ring_vm_listfuncs_sort);
	RING_API_REGISTER("reverse", ring_vm_listfuncs_reverse);
	RING_API_REGISTER("binarysearch", ring_vm_listfuncs_binarysearch);
	RING_API_REGISTER("ref", ring_vm_listfuncs_reference);
	RING_API_REGISTER("reference", ring_vm_listfuncs_reference);
	RING_API_REGISTER("refcount", ring_vm_listfuncs_refcount);
	/* Instead of NewList() function from StdLib (Just to support Old Code until converting it to List() ) */
	RING_API_REGISTER("newlist", ring_vm_listfuncs_list);
}

void ring_vm_listfuncs_add(void *pPointer) {
	List *pList, *pList2;
	unsigned int lMerge, x;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT < 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		/* Avoid Objects */
		if (ring_vm_oop_isobject(pVM, pList)) {
			ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
			return;
		}
		/* Check the Range */
		if (ring_list_getsize_gc(pVM->pRingState, pList) == RING_LIST_MAXSIZE) {
			RING_API_ERROR(RING_API_RANGEEXCEEDED);
			return;
		}
		if (RING_API_ISSTRING(2)) {
			ring_list_addstring2_gc(pVM->pRingState, pList, RING_API_GETSTRING(2),
						RING_API_GETSTRINGSIZE(2));
			RING_API_RETSTRING2(RING_API_GETSTRING(2), RING_API_GETSTRINGSIZE(2));
		} else if (RING_API_ISNUMBER(2)) {
			ring_list_adddouble_gc(pVM->pRingState, pList, RING_API_GETNUMBER(2));
			RING_API_RETNUMBER(RING_API_GETNUMBER(2));
		} else if (RING_API_ISLIST(2)) {
			lMerge = 0;
			if (RING_API_PARACOUNT == 3) {
				if (!RING_API_ISNUMBER(3)) {
					RING_API_ERROR(RING_API_BADPARATYPE);
					return;
				}
				lMerge = (RING_API_GETNUMBER(3) == 1.0);
			}
			pList2 = RING_API_GETLIST(2);
			if (lMerge == 0) {
				/* The ring_vm_addlisttolist() function will check if pList2 is a Reference */
				ring_vm_addlisttolist(pVM, pList2, pList);
			} else {
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList2); x++) {
					if (ring_list_isstring_gc(pVM->pRingState, pList2, x)) {
						ring_list_addstring2_gc(
						    pVM->pRingState, pList,
						    ring_list_getstring_gc(pVM->pRingState, pList2, x),
						    ring_list_getstringsize_gc(pVM->pRingState, pList2, x));
					} else if (ring_list_isdouble_gc(pVM->pRingState, pList2, x)) {
						ring_list_adddouble_gc(
						    pVM->pRingState, pList,
						    ring_list_getdouble_gc(pVM->pRingState, pList2, x));
					} else if (ring_list_islist_gc(pVM->pRingState, pList2, x)) {
						ring_vm_addlisttolist(
						    pVM, ring_list_getlist_gc(pVM->pRingState, pList2, x), pList);
					}
				}
			}
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_listfuncs_del(void *pPointer) {
	List *pList;
	double nNum1;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		/* Avoid Objects */
		if (ring_vm_oop_isobject(pVM, pList)) {
			ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
			return;
		}
		if (RING_API_ISNUMBER(2)) {
			nNum1 = RING_API_GETNUMBER(2);
			if ((nNum1 < 1) || (nNum1 > ring_list_getsize_gc(pVM->pRingState, pList))) {
				RING_API_ERROR(RING_API_BADPARARANGE);
				return;
			}
			ring_list_deleteitem_gc(pVM->pRingState, pList, nNum1);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_listfuncs_swap(void *pPointer) {
	List *pList, *pList2;
	double nNum1, nNum2;
	unsigned int nSize;
	VM *pVM;
	pVM = (VM *)pPointer;
	/* Support Swap two lists */
	if (RING_API_PARACOUNT == 2) {
		if (RING_API_ISLIST(1) && RING_API_ISLIST(2)) {
			pList = RING_API_GETLIST(1);
			pList2 = RING_API_GETLIST(2);
			ring_list_swaptwolists_gc(pVM->pRingState, pList, pList2);
			return;
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	}
	if (RING_API_PARACOUNT != 3) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		/* Avoid Objects */
		if (ring_vm_oop_isobject(pVM, pList)) {
			ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
			return;
		}
		if (RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3)) {
			nNum1 = RING_API_GETNUMBER(2);
			nNum2 = RING_API_GETNUMBER(3);
			nSize = ring_list_getsize_gc(pVM->pRingState, pList);
			if ((nNum1 > 0) && (nNum2 > 0) && (nNum1 != nNum2) && (nNum1 <= nSize) && (nNum2 <= nSize)) {
				ring_list_swap_gc(pVM->pRingState, pList, (unsigned int)nNum1, (unsigned int)nNum2);
				ring_list_clearcache_gc(pVM->pRingState, pList);
			} else {
				RING_API_ERROR(RING_API_BADPARARANGE);
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_listfuncs_list(void *pPointer) {
	List *pList;
	unsigned int x, nSize, nSize2;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISNUMBER(1)) {
			if ((RING_API_GETNUMBER(1) < 1.0) || (RING_API_GETNUMBER(1) > RING_LIST_MAXSIZE)) {
				RING_API_ERROR(RING_API_BADPARARANGE);
				return;
			}
			nSize = RING_API_GETNUMBER(1);
			if (nSize <= RING_VM_SMALLLISTSIZE) {
				pList = RING_API_NEWLIST;
				for (x = 1; x <= nSize; x++) {
					ring_list_adddouble_gc(pVM->pRingState, pList, RING_ZEROF);
				}
			} else {
				pList = RING_API_NEWLISTUSINGBLOCKS1D(nSize);
			}
			RING_API_RETLISTBYREF(pList);
			return;
		}
		RING_API_ERROR(RING_API_BADPARATYPE);
	} else if (RING_API_PARACOUNT == 2) {
		if (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2)) {
			if ((RING_API_GETNUMBER(1) < 1.0) || (RING_API_GETNUMBER(1) > RING_LIST_MAXSIZE) ||
			    (RING_API_GETNUMBER(2) < 1.0) || (RING_API_GETNUMBER(2) > RING_LIST_MAXSIZE)) {
				RING_API_ERROR(RING_API_BADPARARANGE);
				return;
			}
			nSize = RING_API_GETNUMBER(1);
			nSize2 = RING_API_GETNUMBER(2);
			pList = RING_API_NEWLISTUSINGBLOCKS2D(nSize, nSize2);
			RING_API_RETLISTBYREF(pList);
			return;
		}
		RING_API_ERROR(RING_API_BADPARATYPE);
	} else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}
/*
**  Find() Usage Syntax
**  Find(List,ItemValue) ----> Item Index
**  Find(List,ItemValue,nColumn) ---> Item Index
**  Find(List,ItemValue,nColumn,cProperty) ---> Item Index
*/

void ring_vm_listfuncs_find(void *pPointer) {
	unsigned int nNum1, nColumn;
	List *pList;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (!((RING_API_PARACOUNT >= 2) && (RING_API_PARACOUNT <= 4))) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		nNum1 = 0;
		pList = RING_API_GETLIST(1);
		/* Avoid Objects */
		if (ring_vm_oop_isobject(pVM, pList)) {
			ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
			return;
		}
		if (ring_list_getsize_gc(pVM->pRingState, pList) > 0) {
			nColumn = 0;
			if (RING_API_PARACOUNT >= 3) {
				if (RING_API_ISNUMBER(3)) {
					nColumn = RING_API_GETNUMBER(3);
				} else {
					RING_API_ERROR(RING_API_BADPARATYPE);
				}
			}
			if (RING_API_PARACOUNT == 4) {
				if (RING_API_ISSTRING(4)) {
					if (RING_API_ISSTRING(2)) {
						nNum1 = ring_list_findinlistofobjs_gc(
						    pVM->pRingState, pList, RING_LISTOFOBJS_FINDSTRING, RING_ZEROF,
						    RING_API_GETSTRING(2), NULL, nColumn, RING_API_GETSTRING(4));
					} else if (RING_API_ISNUMBER(2)) {
						nNum1 = ring_list_findinlistofobjs_gc(
						    pVM->pRingState, pList, RING_LISTOFOBJS_FINDNUMBER,
						    RING_API_GETNUMBER(2), RING_CSTR_EMPTY, NULL, nColumn,
						    RING_API_GETSTRING(4));
					} else if (RING_API_ISCPOINTER(2)) {
						nNum1 = ring_list_findinlistofobjs_gc(
						    pVM->pRingState, pList, RING_LISTOFOBJS_FINDCPOINTER, RING_ZEROF,
						    RING_CSTR_EMPTY, RING_API_GETLIST(2), nColumn,
						    RING_API_GETSTRING(4));
					} else if (RING_API_ISLIST(2)) {
						nNum1 = ring_list_findinlistofobjs_gc(
						    pVM->pRingState, pList, RING_LISTOFOBJS_FINDLISTREF, RING_ZEROF,
						    RING_CSTR_EMPTY, RING_API_GETLIST(2), nColumn,
						    RING_API_GETSTRING(4));
					} else {
						RING_API_ERROR(RING_API_BADPARATYPE);
					}
					if (nNum1 == RING_LISTERROR_PROPERTYNOTFOUND) {
						RING_API_ERROR(RING_VM_ERROR_PROPERTYNOTFOUND);
					}
				} else {
					RING_API_ERROR(RING_API_BADPARATYPE);
				}
			} else {
				if (RING_API_ISSTRING(2)) {
					nNum1 = ring_list_findstring_gc(pVM->pRingState, pList, RING_API_GETSTRING(2),
									nColumn);
				} else if (RING_API_ISNUMBER(2)) {
					nNum1 = ring_list_finddouble_gc(pVM->pRingState, pList, RING_API_GETNUMBER(2),
									nColumn);
				} else if (RING_API_ISCPOINTER(2)) {
					nNum1 = ring_list_findcpointer_gc(pVM->pRingState, pList, RING_API_GETLIST(2),
									  nColumn);
				} else if (RING_API_ISLIST(2)) {
					nNum1 = ring_list_findlistref_gc(pVM->pRingState, pList, RING_API_GETLIST(2),
									 nColumn);
				} else {
					RING_API_ERROR(RING_API_BADPARATYPE);
				}
				if (nNum1 == RING_LISTERROR_COLUMNNOTFOUND) {
					RING_API_ERROR(RING_VM_ERROR_BADCOLUMNNUMBER);
				}
			}
		}
		RING_API_RETNUMBER(nNum1);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_listfuncs_min(void *pPointer) {
	double nNum1;
	List *pList;
	unsigned int x;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISLIST(1)) {
			pList = RING_API_GETLIST(1);
			/* Avoid Objects */
			if (ring_vm_oop_isobject(pVM, pList)) {
				ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
				return;
			}
			if (ring_list_getsize_gc(pVM->pRingState, pList) > 0) {
				if (ring_list_isnumber_gc(pVM->pRingState, pList, RING_ONE)) {
					nNum1 = ring_list_getdouble_gc(pVM->pRingState, pList, RING_ONE);
				} else {
					RING_API_ERROR(RING_API_BADPARATYPE);
					return;
				}
				if (ring_list_getsize_gc(pVM->pRingState, pList) > 1) {
					for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
						if (ring_list_isnumber_gc(pVM->pRingState, pList, x)) {
							if (ring_list_getdouble_gc(pVM->pRingState, pList, x) < nNum1) {
								nNum1 =
								    ring_list_getdouble_gc(pVM->pRingState, pList, x);
							}
						} else {
							RING_API_ERROR(RING_API_BADPARATYPE);
							return;
						}
					}
				}
				RING_API_RETNUMBER(nNum1);
			} else {
				RING_API_ERROR(RING_API_EMPTYLIST);
				return;
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else if (RING_API_PARACOUNT == 2) {
		if (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2)) {
			if (RING_API_GETNUMBER(1) < RING_API_GETNUMBER(2)) {
				RING_API_RETNUMBER(RING_API_GETNUMBER(1));
			} else {
				RING_API_RETNUMBER(RING_API_GETNUMBER(2));
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}

void ring_vm_listfuncs_max(void *pPointer) {
	double nNum1;
	List *pList;
	unsigned int x;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISLIST(1)) {
			pList = RING_API_GETLIST(1);
			/* Avoid Objects */
			if (ring_vm_oop_isobject(pVM, pList)) {
				ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
				return;
			}
			if (ring_list_getsize_gc(pVM->pRingState, pList) > 0) {
				if (ring_list_isnumber_gc(pVM->pRingState, pList, RING_ONE)) {
					nNum1 = ring_list_getdouble_gc(pVM->pRingState, pList, RING_ONE);
				} else {
					RING_API_ERROR(RING_API_BADPARATYPE);
					return;
				}
				if (ring_list_getsize_gc(pVM->pRingState, pList) > 1) {
					for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
						if (ring_list_isnumber_gc(pVM->pRingState, pList, x)) {
							if (ring_list_getdouble_gc(pVM->pRingState, pList, x) > nNum1) {
								nNum1 =
								    ring_list_getdouble_gc(pVM->pRingState, pList, x);
							}
						} else {
							RING_API_ERROR(RING_API_BADPARATYPE);
							return;
						}
					}
				}
				RING_API_RETNUMBER(nNum1);
			} else {
				RING_API_ERROR(RING_API_EMPTYLIST);
				return;
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else if (RING_API_PARACOUNT == 2) {
		if (RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2)) {
			if (RING_API_GETNUMBER(1) > RING_API_GETNUMBER(2)) {
				RING_API_RETNUMBER(RING_API_GETNUMBER(1));
			} else {
				RING_API_RETNUMBER(RING_API_GETNUMBER(2));
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}

void ring_vm_listfuncs_insert(void *pPointer) {
	List *pList, *pList2;
	unsigned int nPos;
	double x;
	Item *pItem;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 3) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1) && RING_API_ISNUMBER(2)) {
		pList = RING_API_GETLIST(1);
		/* Avoid Objects */
		if (ring_vm_oop_isobject(pVM, pList)) {
			ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
			return;
		}
		/* Check the Range */
		if (ring_list_getsize_gc(pVM->pRingState, pList) == RING_LIST_MAXSIZE) {
			RING_API_ERROR(RING_API_RANGEEXCEEDED);
			return;
		}
		x = RING_API_GETNUMBER(2);
		if ((x < 0) || (x > ring_list_getsize_gc(pVM->pRingState, pList))) {
			RING_API_ERROR(RING_VM_ERROR_INDEXOUTOFRANGE);
			return;
		}
		nPos = (unsigned int)x;
		if (RING_API_ISSTRING(3)) {
			ring_list_insertstring2_gc(pVM->pRingState, pList, nPos, RING_API_GETSTRING(3),
						   RING_API_GETSTRINGSIZE(3));
		} else if (RING_API_ISNUMBER(3)) {
			ring_list_insertdouble_gc(pVM->pRingState, pList, nPos, RING_API_GETNUMBER(3));
		} else if (RING_API_ISLIST(3)) {
			pList2 = ring_list_insertlist_gc(pVM->pRingState, pList, nPos);
			pItem = ring_list_getitem_gc(pVM->pRingState, pList, nPos + 1);
			if (ring_list_isref_gc(pVM->pRingState, RING_API_GETLIST(3))) {
				ring_list_assignreftoitem_gc(pVM->pRingState, RING_API_GETLIST(3), pItem);
			} else {
				ring_vm_listcopy(pVM, pList2, RING_API_GETLIST(3));
				/* Update self object pointer */
				if (ring_vm_oop_isobject(pVM, pList2)) {
					ring_vm_oop_updateselfpointer(pVM, pList2, RING_OBJTYPE_LISTITEM, pItem);
				}
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Quicksort Algorithm */

void ring_vm_listfuncs_sort(void *pPointer) {
	List *pList, *pList2, *pList3;
	int nParaCount;
	unsigned int x, nPos, nColumn;
	char *cAttribute;
	VM *pVM;
	pVM = (VM *)pPointer;
	nParaCount = RING_API_PARACOUNT;
	if (!((nParaCount >= 1) && (nParaCount <= 3))) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_NEWLIST;
		pList2 = RING_API_GETLIST(1);
		/* Avoid Objects */
		if (ring_vm_oop_isobject(pVM, pList2)) {
			ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
			return;
		}
		ring_vm_listcopy(pVM, pList, pList2);
		if (ring_list_getsize_gc(pVM->pRingState, pList) < 2) {
			RING_API_RETLIST(pList2);
			return;
		}
		if (nParaCount == 1) {
			if (ring_list_isnumber_gc(pVM->pRingState, pList, RING_ONE)) {
				/* Check that all items are numbers */
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
					if (!ring_list_isnumber_gc(pVM->pRingState, pList, x)) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return;
					}
				}
				ring_list_sortnum_gc(pVM->pRingState, pList, RING_ONE, ring_list_getsize(pList),
						     RING_ZERO, RING_CSTR_EMPTY);
			} else if (ring_list_isstring_gc(pVM->pRingState, pList, RING_ONE)) {
				/* Check that all items are strings */
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
					if (!ring_list_isstring_gc(pVM->pRingState, pList, x)) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return;
					}
				}
				ring_list_sortstr_gc(pVM->pRingState, pList, RING_ONE, ring_list_getsize(pList),
						     RING_ZERO, RING_CSTR_EMPTY);
			} else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		} else if ((nParaCount == 2) && RING_API_ISNUMBER(2) &&
			   ring_list_islist_gc(pVM->pRingState, pList, RING_ONE)) {
			nColumn = RING_API_GETNUMBER(2);
			pList3 = ring_list_getlist_gc(pVM->pRingState, pList, RING_ONE);
			if (ring_list_isnumber_gc(pVM->pRingState, pList3, nColumn)) {
				/* Check that all items are numbers */
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
					pList3 = ring_list_getlist_gc(pVM->pRingState, pList, x);
					if (!ring_list_isnumber_gc(pVM->pRingState, pList3, nColumn)) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return;
					}
				}
				ring_list_sortnum_gc(pVM->pRingState, pList, RING_ONE,
						     ring_list_getsize_gc(pVM->pRingState, pList), nColumn,
						     RING_CSTR_EMPTY);
			} else if (ring_list_isstring_gc(pVM->pRingState, pList3, nColumn)) {
				/* Check that all items are strings */
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
					pList3 = ring_list_getlist_gc(pVM->pRingState, pList, x);
					if (!ring_list_isstring_gc(pVM->pRingState, pList3, nColumn)) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return;
					}
				}
				ring_list_sortstr_gc(pVM->pRingState, pList, RING_ONE,
						     ring_list_getsize_gc(pVM->pRingState, pList), nColumn,
						     RING_CSTR_EMPTY);
			} else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		} else if ((nParaCount == 3) && RING_API_ISNUMBER(2) &&
			   ring_list_islist_gc(pVM->pRingState, pList, RING_ONE) && RING_API_ISSTRING(3)) {
			nColumn = RING_API_GETNUMBER(2);
			cAttribute = RING_API_GETSTRING(3);
			ring_general_lower(cAttribute);
			pList3 = ring_list_getlist_gc(pVM->pRingState, pList, RING_ONE);
			if (nColumn > 1) {
				pList3 = ring_list_getlist_gc(pVM->pRingState, pList3, nColumn);
			}
			if (ring_vm_oop_isobject(pVM, pList3)) {
				nPos = ring_list_findstring_gc(pVM->pRingState,
							       ring_list_getlist(pList3, RING_OBJECT_OBJECTDATA),
							       cAttribute, RING_VAR_NAME);
				if (nPos == 0) {
					RING_API_ERROR(RING_VM_ERROR_PROPERTYNOTFOUND);
					return;
				}
				pList3 = ring_list_getlist_gc(pVM->pRingState, pList3, RING_OBJECT_OBJECTDATA);
				pList3 = ring_list_getlist_gc(pVM->pRingState, pList3, nPos);
				if (ring_list_isstring_gc(pVM->pRingState, pList3, RING_VAR_VALUE)) {
					ring_list_sortstr_gc(pVM->pRingState, pList, RING_ONE, ring_list_getsize(pList),
							     nColumn, cAttribute);
				} else if (ring_list_isnumber_gc(pVM->pRingState, pList3, RING_VAR_VALUE)) {
					ring_list_sortnum_gc(pVM->pRingState, pList, RING_ONE,
							     ring_list_getsize_gc(pVM->pRingState, pList), nColumn,
							     cAttribute);
				} else {
					RING_API_ERROR(RING_API_BADPARATYPE);
				}
			} else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
		RING_API_RETLISTBYREF(pList);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Binary Search */

void ring_vm_listfuncs_binarysearch(void *pPointer) {
	List *pList, *pList2;
	int nParaCount;
	unsigned int x, nColumn;
	VM *pVM;
	pVM = (VM *)pPointer;
	nParaCount = RING_API_PARACOUNT;
	if ((nParaCount != 2) && (nParaCount != 3)) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		if (pList->pItemsArray == NULL) {
			ring_list_genarray(pList);
		}
		if (nParaCount == 2) {
			if (RING_API_ISSTRING(2)) {
				/* Check that all items are strings */
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
					if (!ring_list_isstring_gc(pVM->pRingState, pList, x)) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return;
					}
				}
				RING_API_RETNUMBER(ring_list_binarysearchstr_gc(
				    pVM->pRingState, pList, RING_API_GETSTRING(2), RING_ZERO, RING_CSTR_EMPTY));
			} else if (RING_API_ISNUMBER(2)) {
				/* Check that all items are numbers */
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
					if (!ring_list_isnumber_gc(pVM->pRingState, pList, x)) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return;
					}
				}
				RING_API_RETNUMBER(ring_list_binarysearchnum_gc(
				    pVM->pRingState, pList, RING_API_GETNUMBER(2), RING_ZERO, RING_CSTR_EMPTY));
			} else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		} else {
			nColumn = RING_API_GETNUMBER(3);
			if (RING_API_ISSTRING(2)) {
				/* Check that all items are strings */
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
					pList2 = ring_list_getlist_gc(pVM->pRingState, pList, x);
					if (!ring_list_isstring_gc(pVM->pRingState, pList2, nColumn)) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return;
					}
				}
				RING_API_RETNUMBER(ring_list_binarysearchstr_gc(
				    pVM->pRingState, pList, RING_API_GETSTRING(2), nColumn, RING_CSTR_EMPTY));
			} else if (RING_API_ISNUMBER(2)) {
				/* Check that all items are numbers */
				for (x = 1; x <= ring_list_getsize_gc(pVM->pRingState, pList); x++) {
					pList2 = ring_list_getlist_gc(pVM->pRingState, pList, x);
					if (!ring_list_isnumber_gc(pVM->pRingState, pList2, nColumn)) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return;
					}
				}
				RING_API_RETNUMBER(ring_list_binarysearchnum_gc(
				    pVM->pRingState, pList, RING_API_GETNUMBER(2), nColumn, RING_CSTR_EMPTY));
			} else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_listfuncs_reverse(void *pPointer) {
	List *pList, *pList2, *pList3;
	unsigned int x, nPos;
	int nSize;
	char *cStr, *cNewStr;
	Item *pItem;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_NEWLIST;
		pList2 = RING_API_GETLIST(1);
		/* Avoid Objects */
		if (ring_vm_oop_isobject(pVM, pList2)) {
			ring_vm_error(pVM, RING_VM_ERROR_VARISNOTLIST);
			return;
		}
		for (x = ring_list_getsize_gc(pVM->pRingState, pList2); x >= 1; x--) {
			if (ring_list_isstring_gc(pVM->pRingState, pList2, x)) {
				ring_list_addstring_gc(pVM->pRingState, pList,
						       ring_list_getstring_gc(pVM->pRingState, pList2, x));
			} else if (ring_list_isnumber_gc(pVM->pRingState, pList2, x)) {
				ring_list_adddouble_gc(pVM->pRingState, pList,
						       ring_list_getdouble_gc(pVM->pRingState, pList2, x));
			} else if (ring_list_islist_gc(pVM->pRingState, pList2, x)) {
				pList3 = ring_list_newlist_gc(pVM->pRingState, pList);
				ring_vm_listcopy(pVM, pList3, ring_list_getlist(pList2, x));
				pItem = ring_list_getitem_gc(pVM->pRingState, pList, ring_list_getsize(pList));
				/* Update self object pointer */
				if (ring_vm_oop_isobject(pVM, pList3)) {
					ring_vm_oop_updateselfpointer(pVM, pList3, RING_OBJTYPE_LISTITEM, pItem);
				}
			}
		}
		RING_API_RETLISTBYREF(pList);
	} else if (RING_API_ISSTRING(1)) {
		cStr = RING_API_GETSTRING(1);
		nSize = RING_API_GETSTRINGSIZE(1);
		if (nSize == 0) {
			RING_API_RETSTRING(RING_CSTR_EMPTY);
			return;
		} else if (nSize == 1) {
			RING_API_RETSTRING(cStr);
			return;
		}
		RING_API_RETSTRINGSIZE(nSize);
		cNewStr = ring_string_get(RING_API_GETSTRINGRAW);
		nPos = 0;
		for (x = nSize; x >= 1; x--) {
			cNewStr[nPos++] = cStr[x - 1];
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_listfuncs_reference(void *pPointer) {
	List *pList;
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISLIST(1)) {
			pList = RING_API_GETLIST(1);
			RING_API_RETNEWREF(pList);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
		return;
	}
	RING_API_ERROR(RING_API_BADPARACOUNT);
}

void ring_vm_listfuncs_refcount(void *pPointer) {
	List *pList;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISLIST(1)) {
			pList = RING_API_GETLIST(1);
			RING_API_RETNUMBER(ring_list_getrefcount_gc(pVM->pRingState, pList));
		} else {
			RING_API_RETNUMBER(1);
		}
		return;
	}
	RING_API_ERROR(RING_API_BADPARACOUNT);
}
