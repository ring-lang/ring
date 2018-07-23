/*
**  Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
/* Load Functions */

void ring_vm_listfuncs_loadfunctions ( RingState *pRingState )
{
	/* Lists */
	ring_vm_funcregister("list",ring_vmlib_list);
	ring_vm_funcregister("find",ring_vmlib_find);
	ring_vm_funcregister("min",ring_vmlib_min);
	ring_vm_funcregister("max",ring_vmlib_max);
	ring_vm_funcregister("insert",ring_vmlib_insert);
	ring_vm_funcregister("sort",ring_vmlib_sort);
	ring_vm_funcregister("reverse",ring_vmlib_reverse);
	ring_vm_funcregister("binarysearch",ring_vmlib_binarysearch);
}
/* Functions */

void ring_vmlib_list ( void *pPointer )
{
	List *pList  ;
	int x,nSize  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		nSize = RING_API_GETNUMBER(1) ;
		if ( nSize > 0 ) {
			pList = RING_API_NEWLIST ;
			for ( x = 1 ; x <=nSize ; x++ ) {
				ring_list_adddouble(pList,0.0);
			}
			RING_API_RETLIST(pList);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/*
**  Find() Usage Syntax 
**  Find(List,ItemValue) ----> Item Index 
**  Find(List,ItemValue,nColumn) ---> Item Index 
**  Find(List,ItemValue,nColumn,cProperty) ---> Item Index 
*/

void ring_vmlib_find ( void *pPointer )
{
	int nNum1,nColumn  ;
	List *pList  ;
	if ( ! ( (RING_API_PARACOUNT >= 2) && (RING_API_PARACOUNT <= 4) ) ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		nNum1 = 0 ;
		pList = RING_API_GETLIST(1) ;
		if ( ring_list_getsize(pList) > 0 ) {
			nColumn = 0 ;
			if ( RING_API_PARACOUNT >= 3 ) {
				if ( RING_API_ISNUMBER(3) ) {
					nColumn = RING_API_GETNUMBER(3) ;
				}
				else {
					RING_API_ERROR(RING_API_BADPARATYPE);
				}
			}
			if ( RING_API_PARACOUNT == 4 ) {
				if ( RING_API_ISSTRING(4) ) {
					if ( RING_API_ISSTRING(2) ) {
						nNum1 = ring_list_findinlistofobjs(pList,RING_VM_LISTOFOBJS_FINDSTRING,0.0,RING_API_GETSTRING(2),nColumn,RING_API_GETSTRING(4));
					}
					else if ( RING_API_ISNUMBER(2) ) {
						nNum1 = ring_list_findinlistofobjs(pList,RING_VM_LISTOFOBJS_FINDNUMBER,RING_API_GETNUMBER(2),"",nColumn,RING_API_GETSTRING(4));
					}
					else {
						RING_API_ERROR(RING_API_BADPARATYPE);
					}
					if ( nNum1 == -1 ) {
						RING_API_ERROR(RING_VM_ERROR_PROPERTYNOTFOUND);
					}
				}
				else {
					RING_API_ERROR(RING_API_BADPARATYPE);
				}
			}
			else {
				if ( RING_API_ISSTRING(2) ) {
					nNum1 = ring_list_findstring(pList,RING_API_GETSTRING(2),nColumn);
				}
				else if ( RING_API_ISNUMBER(2) ) {
					nNum1 = ring_list_finddouble(pList,RING_API_GETNUMBER(2),nColumn);
				}
				else if ( RING_API_ISCPOINTER(2) ) {
					nNum1 = ring_list_findcpointer(pList,RING_API_GETLIST(2),nColumn);
				}
				else {
					RING_API_ERROR(RING_API_BADPARATYPE);
				}
				if ( nNum1 == -1 ) {
					RING_API_ERROR(RING_VM_ERROR_BADCOLUMNNUMBER);
				}
			}
		}
		RING_API_RETNUMBER(nNum1);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_min ( void *pPointer )
{
	double nNum1  ;
	List *pList  ;
	int x  ;
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISLIST(1) ) {
			pList = RING_API_GETLIST(1) ;
			if ( ring_list_getsize(pList) > 0 ) {
				if ( ring_list_isnumber(pList,1) ) {
					nNum1 = ring_list_getdouble(pList,1) ;
				}
				else {
					RING_API_ERROR(RING_API_BADPARATYPE);
					return ;
				}
				if ( ring_list_getsize(pList) > 1 ) {
					for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
						if ( ring_list_isnumber(pList,x) ) {
							if ( ring_list_getdouble(pList,x) < nNum1 ) {
								nNum1 = ring_list_getdouble(pList,x) ;
							}
						}
						else {
							RING_API_ERROR(RING_API_BADPARATYPE);
							return ;
						}
					}
				}
				RING_API_RETNUMBER(nNum1);
			}
			else {
				RING_API_ERROR(RING_API_EMPTYLIST);
				return ;
			}
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	else if ( RING_API_PARACOUNT == 2 ) {
		if ( RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) ) {
			if ( RING_API_GETNUMBER(1) < RING_API_GETNUMBER(2) ) {
				RING_API_RETNUMBER(RING_API_GETNUMBER(1));
			}
			else {
				RING_API_RETNUMBER(RING_API_GETNUMBER(2));
			}
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}

void ring_vmlib_max ( void *pPointer )
{
	double nNum1  ;
	List *pList  ;
	int x  ;
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISLIST(1) ) {
			pList = RING_API_GETLIST(1) ;
			if ( ring_list_getsize(pList) > 0 ) {
				if ( ring_list_isnumber(pList,1) ) {
					nNum1 = ring_list_getdouble(pList,1) ;
				}
				else {
					RING_API_ERROR(RING_API_BADPARATYPE);
					return ;
				}
				if ( ring_list_getsize(pList) > 1 ) {
					for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
						if ( ring_list_isnumber(pList,x) ) {
							if ( ring_list_getdouble(pList,x) > nNum1 ) {
								nNum1 = ring_list_getdouble(pList,x) ;
							}
						}
						else {
							RING_API_ERROR(RING_API_BADPARATYPE);
							return ;
						}
					}
				}
				RING_API_RETNUMBER(nNum1);
			}
			else {
				RING_API_ERROR(RING_API_EMPTYLIST);
				return ;
			}
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	else if ( RING_API_PARACOUNT == 2 ) {
		if ( RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) ) {
			if ( RING_API_GETNUMBER(1) > RING_API_GETNUMBER(2) ) {
				RING_API_RETNUMBER(RING_API_GETNUMBER(1));
			}
			else {
				RING_API_RETNUMBER(RING_API_GETNUMBER(2));
			}
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}

void ring_vmlib_insert ( void *pPointer )
{
	List *pList, *pList2  ;
	int nPos  ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISLIST(1) && RING_API_ISNUMBER(2) ) {
		pList = RING_API_GETLIST(1) ;
		nPos = (int) RING_API_GETNUMBER(2) ;
		if ( (nPos < 0) || (nPos > ring_list_getsize(pList) ) ) {
			RING_API_ERROR(RING_VM_ERROR_INDEXOUTOFRANGE);
			return ;
		}
		if ( RING_API_ISSTRING(3) ) {
			ring_list_insertstring2(pList,nPos,RING_API_GETSTRING(3),RING_API_GETSTRINGSIZE(3));
		}
		else if ( RING_API_ISNUMBER(3) ) {
			ring_list_insertdouble(pList,nPos,RING_API_GETNUMBER(3));
		}
		else if ( RING_API_ISLIST(3) ) {
			pList2 = ring_list_insertlist(pList,nPos);
			ring_vm_list_copy((VM *) pPointer,pList2,RING_API_GETLIST(3));
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Quicksort Algorithm */

void ring_vmlib_sort ( void *pPointer )
{
	List *pList, *pList2, *pList3  ;
	int x,nParaCount,nColumn,nPos  ;
	char *cAttribute  ;
	nParaCount = RING_API_PARACOUNT ;
	if ( ! ( (nParaCount >= 1) && (nParaCount <= 3) ) ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		pList = RING_API_NEWLIST ;
		pList2 = RING_API_GETLIST(1);
		ring_vm_list_copy((VM *) pPointer,pList,pList2);
		if ( ring_list_getsize(pList) < 2 ) {
			RING_API_RETLIST(pList2);
			return ;
		}
		if ( nParaCount == 1 ) {
			if ( ring_list_isnumber(pList,1) ) {
				/* Check that all items are numbers */
				for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
					if ( ! ring_list_isnumber(pList,x) ) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return ;
					}
				}
				ring_list_sortnum(pList,1,ring_list_getsize(pList),0,"");
			}
			else if ( ring_list_isstring(pList,1) ) {
				/* Check that all items are strings */
				for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
					if ( ! ring_list_isstring(pList,x) ) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return ;
					}
				}
				ring_list_sortstr(pList,1,ring_list_getsize(pList),0,"");
			}
			else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		}
		else if ( (nParaCount == 2) && RING_API_ISNUMBER(2) && ring_list_islist(pList,1) ) {
			nColumn = RING_API_GETNUMBER(2) ;
			pList3 = ring_list_getlist(pList,1);
			if ( ring_list_isnumber(pList3,nColumn) ) {
				/* Check that all items are numbers */
				for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
					pList3 = ring_list_getlist(pList,x);
					if ( ! ring_list_isnumber(pList3,nColumn) ) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return ;
					}
				}
				ring_list_sortnum(pList,1,ring_list_getsize(pList),nColumn,"");
			}
			else if ( ring_list_isstring(pList3,nColumn) ) {
				/* Check that all items are strings */
				for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
					pList3 = ring_list_getlist(pList,x);
					if ( ! ring_list_isstring(pList3,nColumn) ) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return ;
					}
				}
				ring_list_sortstr(pList,1,ring_list_getsize(pList),nColumn,"");
			}
			else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		}
		else if ( (nParaCount == 3) && RING_API_ISNUMBER(2) && ring_list_islist(pList,1) && RING_API_ISSTRING(3) ) {
			nColumn = RING_API_GETNUMBER(2) ;
			cAttribute = RING_API_GETSTRING(3) ;
			ring_string_lower(cAttribute);
			pList3 = ring_list_getlist(pList,1);
			if ( nColumn > 1 ) {
				pList3 = ring_list_getlist(pList3,nColumn);
			}
			if ( ring_vm_oop_isobject(pList3) ) {
				nPos = ring_list_findstring(ring_list_getlist(pList3,RING_OBJECT_OBJECTDATA),cAttribute,RING_VAR_NAME);
				if ( nPos == 0 ) {
					RING_API_ERROR(RING_VM_ERROR_PROPERTYNOTFOUND);
					return ;
				}
				pList3 = ring_list_getlist(pList3,RING_OBJECT_OBJECTDATA) ;
				pList3 = ring_list_getlist(pList3,nPos) ;
				if ( ring_list_isstring(pList3,RING_VAR_VALUE) ) {
					ring_list_sortstr(pList,1,ring_list_getsize(pList),nColumn,cAttribute);
				}
				else if ( ring_list_isnumber(pList3,RING_VAR_VALUE) ) {
					ring_list_sortnum(pList,1,ring_list_getsize(pList),nColumn,cAttribute);
				}
				else {
					RING_API_ERROR(RING_API_BADPARATYPE);
				}
			}
			else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
		RING_API_RETLIST(pList);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Binary Search */

void ring_vmlib_binarysearch ( void *pPointer )
{
	List *pList, *pList2  ;
	int x,nParaCount,nColumn  ;
	nParaCount = RING_API_PARACOUNT ;
	if ( (nParaCount != 2) && (nParaCount != 3) ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		pList = RING_API_GETLIST(1);
		if ( pList->pItemsArray == NULL ) {
			ring_list_genarray_gc(((VM *) pPointer)->pRingState,pList);
		}
		if ( nParaCount == 2 ) {
			if ( RING_API_ISSTRING(2) ) {
				/* Check that all items are strings */
				for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
					if ( ! ring_list_isstring(pList,x) ) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return ;
					}
				}
				RING_API_RETNUMBER(ring_list_binarysearchstr(pList,RING_API_GETSTRING(2),0,""));
			}
			else if ( RING_API_ISNUMBER(2) ) {
				/* Check that all items are numbers */
				for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
					if ( ! ring_list_isnumber(pList,x) ) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return ;
					}
				}
				RING_API_RETNUMBER(ring_list_binarysearchnum(pList,RING_API_GETNUMBER(2),0,""));
			}
			else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		}
		else {
			nColumn = RING_API_GETNUMBER(3) ;
			if ( RING_API_ISSTRING(2) ) {
				/* Check that all items are strings */
				for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
					pList2 = ring_list_getlist(pList,x);
					if ( ! ring_list_isstring(pList2,nColumn) ) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return ;
					}
				}
				RING_API_RETNUMBER(ring_list_binarysearchstr(pList,RING_API_GETSTRING(2),nColumn,""));
			}
			else if ( RING_API_ISNUMBER(2) ) {
				/* Check that all items are numbers */
				for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
					pList2 = ring_list_getlist(pList,x);
					if ( ! ring_list_isnumber(pList2,nColumn) ) {
						RING_API_ERROR(RING_API_BADPARATYPE);
						return ;
					}
				}
				RING_API_RETNUMBER(ring_list_binarysearchnum(pList,RING_API_GETNUMBER(2),nColumn,""));
			}
			else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_reverse ( void *pPointer )
{
	List *pList,*pList2,*pList3  ;
	int x  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		pList = RING_API_NEWLIST ;
		pList2 = RING_API_GETLIST(1) ;
		for ( x = ring_list_getsize(pList2) ; x >= 1 ; x-- ) {
			if ( ring_list_isstring(pList2,x) ) {
				ring_list_addstring(pList,ring_list_getstring(pList2,x));
			}
			else if ( ring_list_isnumber(pList2,x) ) {
				ring_list_adddouble(pList,ring_list_getdouble(pList2,x));
			}
			else if ( ring_list_islist(pList2,x) ) {
				pList3 = ring_list_newlist_gc(((VM *) pPointer)->pRingState,pList);
				ring_vm_list_copy((VM *) pPointer,pList3,ring_list_getlist(pList2,x));
			}
		}
		RING_API_RETLIST(pList);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
