/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  List 
*/

RING_API List * ring_list_new ( int nSize )
{
	int x  ;
	List *pList  ;
	Items *pItems,*pItemsLast  ;
	pList = (List *) malloc(sizeof(List)) ;
	if ( pList == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	pList->nSize = nSize ;
	if ( nSize > 0 ) {
		pItems = ring_items_new();
		pList->pFirst = pItems ;
		pItemsLast = pItems ;
		for ( x = 2 ; x <= nSize ; x++ ) {
			pItems = ring_items_new();
			if ( pItems == NULL ) {
				printf( "OUT OF MEMEORY \n  " ) ;
				exit(0);
			}
			pItemsLast->pNext = pItems ;
			pItems->pPrev = pItemsLast ;
			pItemsLast = pItems ;
		}
		pList->pLast = pItems ;
	} else {
		pList->pFirst = NULL ;
		pList->pLast = NULL ;
	}
	pList->nNextItemAfterLastAccess = 0 ;
	pList->pLastItemLastAccess = NULL ;
	pList->pItemsArray = NULL ;
	pList->pHashTable = NULL ;
	return pList ;
}

RING_API List * ring_list_delete ( List *pList )
{
	Items *pItems,*pItemsNext  ;
	pItems = pList->pFirst ;
	pItemsNext = pItems ;
	/* Delete Items */
	while ( pItemsNext != NULL ) {
		pItemsNext = pItems->pNext ;
		ring_items_delete(pItems);
		pItems = pItemsNext ;
	}
	/* Free Items Array */
	ring_list_deletearray(pList);
	/* Free HashTable */
	if ( pList->pHashTable != NULL ) {
		pList->pHashTable = ring_hashtable_delete(pList->pHashTable);
	}
	free( pList ) ;
	pList = NULL ;
	return pList ;
}

RING_API void ring_list_copy ( List *pNewList, List *pList )
{
	int x  ;
	List *pNewList2  ;
	assert(pList != NULL);
	/*
	**  This function don't add a new list before copying items 
	**  if you want to add a list to another one, create new list in the target then copy to it 
	**  Copy Items 
	*/
	if ( ring_list_getsize(pList) == 0 ) {
		return ;
	}
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		if ( ring_list_isint(pList,x) ) {
			ring_list_addint(pNewList,ring_list_getint(pList,x));
		}
		else if ( ring_list_isdouble(pList,x) ) {
			ring_list_adddouble(pNewList,ring_list_getdouble(pList,x));
		}
		else if ( ring_list_isstring(pList,x) ) {
			ring_list_addstring2(pNewList,ring_list_getstring(pList,x),ring_list_getstringsize(pList,x));
		}
		else if ( ring_list_ispointer(pList,x) ) {
			ring_list_addpointer(pNewList,ring_list_getpointer(pList,x));
		}
		else if ( ring_list_islist(pList,x) ) {
			pNewList2 = ring_list_newlist(pNewList);
			ring_list_copy(pNewList2,ring_list_getlist(pList,x));
		}
	}
}

RING_API void ring_list_print ( List *pList )
{
	int x,t,nSize  ;
	double y  ;
	const char *cStr  ;
	List *pList2  ;
	assert(pList != NULL);
	/* Print Items */
	if ( ring_list_getsize(pList) < 0 ) {
		return ;
	}
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		if ( ring_list_isstring(pList,x) ) {
			cStr = ring_list_getstring(pList,x) ;
			nSize = ring_list_getstringsize(pList,x);
			for ( t = 0 ; t < nSize ; t++ ) {
				printf( "%c",cStr[t] ) ;
			}
			printf( "\n" ) ;
		}
		else if ( ring_list_isnumber(pList,x) ) {
			if ( ring_list_isdouble(pList,x) ) {
				y = ring_list_getdouble(pList,x) ;
				if ( y == (int) y ) {
					printf( "%.0f\n",y ) ;
				} else {
					printf( "%.2f\n",y ) ;
				}
			}
			else if ( ring_list_isint(pList,x) ) {
				printf( "%d\n",ring_list_getint(pList,x) ) ;
			}
		}
		else if ( ring_list_islist(pList,x) ) {
			pList2 = ring_list_getlist(pList,x) ;
			if ( ring_vm_oop_isobject(pList2) ) {
				ring_vm_oop_printobj(pList2);
			}
			else {
				ring_list_print(pList2);
			}
		}
		else if ( ring_list_ispointer(pList,x) ) {
			printf( "%p\n",ring_list_getpointer(pList,x) ) ;
		}
	}
}

RING_API void ring_list_deleteallitems ( List *pList )
{
	Items *pItems,*pItemsNext  ;
	pItems = pList->pFirst ;
	if ( pItems == NULL ) {
		return ;
	}
	pItemsNext = pItems ;
	/* Delete Items */
	while ( pItemsNext != NULL ) {
		pItemsNext = pItems->pNext ;
		ring_items_delete(pItems);
		pItems = pItemsNext ;
	}
	pList->pFirst = NULL ;
	pList->pLast = NULL ;
	pList->pLastItemLastAccess = NULL ;
	pList->nSize = 0 ;
	pList->nNextItemAfterLastAccess = 0 ;
}
/* List Items */

RING_API void ring_list_newitem ( List *pList )
{
	Items *pItems  ;
	assert(pList != NULL);
	pItems = ring_items_new();
	if ( (pList->nSize) > 0 ) {
		pList->pLast->pNext = pItems ;
		pItems->pPrev = pList->pLast ;
		pList->pLast = pItems ;
	} else {
		pList->pFirst = pItems ;
		pList->pLast = pItems ;
	}
	pList->nSize = pList->nSize + 1 ;
}

RING_API Item * ring_list_getitem ( List *pList,int index )
{
	int x  ;
	Items *pItems  ;
	Item *pItem  ;
	pItem = NULL ;
	assert(pList != NULL);
	if ( index > 0 && ( ring_list_getsize(pList) > 0 ) && index <= ring_list_getsize(pList) ) {
		/* Quickly get item from ItemsArray */
		if ( pList->pItemsArray != NULL ) {
			return pList->pItemsArray[index-1] ;
		}
		/* Quickly Get The First or The Last Item */
		if ( index == 1 ) {
			pList->pLastItemLastAccess = pList->pFirst ;
			pList->nNextItemAfterLastAccess = index + 1 ;
			return pList->pFirst->pValue ;
		}
		else if ( index == ring_list_getsize(pList) ) {
			pList->pLastItemLastAccess = pList->pLast ;
			pList->nNextItemAfterLastAccess = index + 1 ;
			return pList->pLast->pValue ;
		}
		/* Quickly get the next item */
		else if ( ( index == pList->nNextItemAfterLastAccess ) && ( pList->pLastItemLastAccess != NULL ) ) {
			pList->pLastItemLastAccess = pList->pLastItemLastAccess->pNext ;
			pList->nNextItemAfterLastAccess++ ;
			return pList->pLastItemLastAccess->pValue ;
		}
		/* Quickly get the current item */
		else if ( (index == pList->nNextItemAfterLastAccess - 1) && ( pList->pLastItemLastAccess != NULL ) ) {
			return pList->pLastItemLastAccess->pValue ;
		}
		/* Quickly get item after the current item */
		else if ( ( index > pList->nNextItemAfterLastAccess )  && ( pList->pLastItemLastAccess != NULL ) ) {
			pItems = pList->pLastItemLastAccess ;
			for ( x = pList->nNextItemAfterLastAccess - 1 ; x <= index ; x++ ) {
				if ( x == index ) {
					pList->nNextItemAfterLastAccess = index+1 ;
					pList->pLastItemLastAccess = pItems ;
				}
				pItem = pItems->pValue ;
				pItems = pItems->pNext ;
			}
			return pItem ;
		}
		/* Quickly get item before the current item */
		else if ( ( ( pList->nNextItemAfterLastAccess - index ) < index ) && ( pList->pLastItemLastAccess != NULL ) ) {
			pItems = pList->pLastItemLastAccess ;
			for ( x = pList->nNextItemAfterLastAccess - 1 ; x >= index ; x-- ) {
				if ( x == index ) {
					pList->nNextItemAfterLastAccess = index+1 ;
					pList->pLastItemLastAccess = pItems ;
				}
				pItem = pItems->pValue ;
				pItems = pItems->pPrev ;
			}
			return pItem ;
		}
		/* Linear Search  From Start */
		pItems = pList->pFirst ;
		for ( x = 1 ; x <= index ; x++ ) {
			if ( x == index ) {
				pList->nNextItemAfterLastAccess = index+1 ;
				pList->pLastItemLastAccess = pItems ;
			}
			pItem = pItems->pValue ;
			pItems = pItems->pNext ;
		}
	}
	return pItem ;
}

RING_API void ring_list_setactiveitem ( List *pList, Items *pItems, int index )
{
	assert(pList != NULL);
	pList->pLastItemLastAccess = pItems ;
	pList->nNextItemAfterLastAccess = index + 1 ;
}

RING_API void ring_list_deleteitem ( List *pList,int index )
{
	int x  ;
	Items *pItems,*pItemsPrev  ;
	assert(pList != NULL);
	/* Goto the Item */
	if ( index > 0 && ( ring_list_getsize(pList) > 0 ) && index <= ring_list_getsize(pList) ) {
		pItems = pList->pFirst ;
		pItemsPrev = NULL ;
		for ( x = 1 ; x < index ; x++ ) {
			pItemsPrev = pItems ;
			pItems = pItems->pNext ;
		}
		/* Delete The Item */
		if ( index == 1 ) {
			pList->pFirst = pItems->pNext ;
		}
		if ( index == ring_list_getsize(pList) ) {
			pList->pLast = pItemsPrev ;
		}
		if ( pItemsPrev != NULL ) {
			pItemsPrev->pNext = pItems->pNext ;
			if ( pItems->pNext != NULL ) {
				pItems->pNext->pPrev = pItemsPrev ;
			}
		}
		ring_items_delete(pItems);
		pList->nSize = pList->nSize - 1 ;
	}
	/* Refresh The Cache */
	pList->nNextItemAfterLastAccess = 0 ;
	pList->pLastItemLastAccess = NULL ;
}

RING_API int ring_list_gettype ( List *pList, int index )
{
	Item *pItem  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	if ( pItem != NULL ) {
		return ring_item_gettype(pItem) ;
	}
	return 0 ;
}

RING_API int ring_list_isstring ( List *pList, int index )
{
	if ( ring_list_gettype(pList,index) == ITEMTYPE_STRING ) {
		return 1 ;
	}
	return 0 ;
}

RING_API int ring_list_isnumber ( List *pList, int index )
{
	if ( ring_list_gettype(pList,index) == ITEMTYPE_NUMBER ) {
		return 1 ;
	}
	return 0 ;
}

RING_API int ring_list_islist ( List *pList, int index )
{
	if ( ring_list_gettype(pList,index) == ITEMTYPE_LIST ) {
		return 1 ;
	}
	return 0 ;
}

RING_API int ring_list_ispointer ( List *pList, int index )
{
	if ( ring_list_gettype(pList,index) == ITEMTYPE_POINTER ) {
		return 1 ;
	}
	return 0 ;
}
/* int */

RING_API void ring_list_setint ( List *pList, int index ,int number )
{
	Item *pItem  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	ring_item_settype(pItem,ITEMTYPE_NUMBER);
	pItem->data.iNumber = number ;
	pItem->NumberFlag = ITEM_NUMBERFLAG_INT ;
}

RING_API void ring_list_addint ( List *pList,int x )
{
	assert(pList != NULL);
	ring_list_newitem(pList);
	ring_list_setint(pList,ring_list_getsize(pList),x);
}
/* Pointers */

RING_API void ring_list_setpointer ( List *pList, int index ,void *pValue )
{
	Item *pItem  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	ring_item_settype(pItem,ITEMTYPE_POINTER);
	pItem->data.pPointer = pValue ;
}

RING_API void ring_list_addpointer ( List *pList,void *pValue )
{
	assert(pList != NULL);
	ring_list_newitem(pList);
	ring_list_setpointer(pList,ring_list_getsize(pList),pValue);
}
/* double */

RING_API void ring_list_setdouble ( List *pList, int index ,double number )
{
	Item *pItem  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	ring_item_settype(pItem,ITEMTYPE_NUMBER);
	pItem->data.dNumber = number ;
	pItem->NumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
}

RING_API void ring_list_adddouble ( List *pList,double x )
{
	assert(pList != NULL);
	ring_list_newitem(pList);
	ring_list_setdouble(pList,ring_list_getsize(pList),x);
}
/* String */

RING_API void ring_list_setstring ( List *pList, int index ,const char *str )
{
	Item *pItem  ;
	String *pString  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	ring_item_settype(pItem,ITEMTYPE_STRING);
	pString = ring_item_getstring(pItem);
	ring_string_set(pString,str);
}

RING_API void ring_list_setstring2 ( List *pList, int index ,const char *str,int nStrSize )
{
	Item *pItem  ;
	String *pString  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	ring_item_settype(pItem,ITEMTYPE_STRING);
	pString = ring_item_getstring(pItem);
	ring_string_set2(pString,str,nStrSize);
}

RING_API void ring_list_addstring ( List *pList,const char *str )
{
	assert(pList != NULL);
	ring_list_newitem(pList);
	ring_list_setstring(pList,ring_list_getsize(pList),str);
}

RING_API void ring_list_addstring2 ( List *pList,const char *str,int nStrSize )
{
	assert(pList != NULL);
	ring_list_newitem(pList);
	ring_list_setstring2(pList,ring_list_getsize(pList),str,nStrSize);
}
/* List */

RING_API List * ring_list_newlist ( List *pList )
{
	Item *pItem  ;
	List *pList2  ;
	assert(pList != NULL);
	ring_list_newitem(pList);
	pItem = ring_list_getitem(pList,ring_list_getsize(pList));
	ring_item_settype(pItem,ITEMTYPE_LIST);
	pList2 = ring_item_getlist(pItem);
	return pList2 ;
}

RING_API List * ring_list_getlist ( List *pList, int index )
{
	Item *pItem  ;
	List *pList2  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	pList2 = ring_item_getlist(pItem);
	return pList2 ;
}

RING_API void ring_list_setlist ( List *pList, int index )
{
	Item *pItem  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	ring_item_settype(pItem,ITEMTYPE_LIST);
}
/* Function Pointers */

RING_API void ring_list_setfuncpointer ( List *pList, int index ,void (*pFunc)(void *) )
{
	Item *pItem  ;
	assert(pList != NULL);
	pItem = ring_list_getitem(pList,index);
	ring_item_settype(pItem,ITEMTYPE_FUNCPOINTER);
	pItem->data.pFunc = pFunc ;
}

RING_API void ring_list_addfuncpointer ( List *pList,void (*pFunc)(void *) )
{
	assert(pList != NULL);
	ring_list_newitem(pList);
	ring_list_setfuncpointer(pList,ring_list_getsize(pList),pFunc);
}

RING_API int ring_list_isfuncpointer ( List *pList, int index )
{
	if ( ring_list_gettype(pList,index) == ITEMTYPE_FUNCPOINTER ) {
		return 1 ;
	}
	return 0 ;
}

void ring_list_testfuncpointer ( void *pPointer )
{
	List *pList  ;
	pList = (List *) pPointer ;
	puts(" Message from a function called by function pointer  ");
	printf( "List Size %d  \n",pList->nSize ) ;
}
/*
**  Insert Items 
**  When you insert item, it will be inserted after nPos 
*/

RING_API void ring_list_insertitem ( List *pList,int x )
{
	Items *pItems  ;
	assert(pList != NULL);
	if ( ( x < 0 ) || ( x > ring_list_getsize(pList) ) ) {
		return ;
	}
	else if ( x == ring_list_getsize(pList) ) {
		ring_list_newitem(pList);
		return ;
	}
	pItems = ring_items_new();
	/* Insert Item at the first of the list */
	if ( x==0 ) {
		pItems->pNext = pList->pFirst ;
		pItems->pPrev = NULL ;
		pList->pFirst->pPrev = pItems ;
		pList->pFirst = pItems ;
		pList->nSize = pList->nSize + 1 ;
		return ;
	}
	ring_list_getitem(pList,x);
	/* When we get an item, pLastItemLastAccess will be changed to Items * of that item */
	pItems->pNext = pList->pLastItemLastAccess->pNext ;
	pItems->pNext->pPrev = pItems ;
	pItems->pPrev = pList->pLastItemLastAccess ;
	pList->pLastItemLastAccess->pNext = pItems ;
	pList->nSize = pList->nSize + 1 ;
}

RING_API void ring_list_insertint ( List *pList,int nPos,int x )
{
	assert(pList != NULL);
	ring_list_insertitem(pList,nPos);
	ring_list_setint(pList,nPos+1,x);
}

RING_API void ring_list_insertdouble ( List *pList,int nPos,double x )
{
	assert(pList != NULL);
	ring_list_insertitem(pList,nPos);
	ring_list_setdouble(pList,nPos+1,x);
}

RING_API void ring_list_insertpointer ( List *pList,int nPos,void *pValue )
{
	assert(pList != NULL);
	ring_list_insertitem(pList,nPos);
	ring_list_setpointer(pList,nPos+1,pValue);
}

RING_API void ring_list_insertstring ( List *pList,int nPos,const char *str )
{
	assert(pList != NULL);
	ring_list_insertitem(pList,nPos);
	ring_list_setstring(pList,nPos+1,str);
}

RING_API void ring_list_insertstring2 ( List *pList,int nPos,const char *str,int nStrSize )
{
	assert(pList != NULL);
	ring_list_insertitem(pList,nPos);
	ring_list_setstring2(pList,nPos+1,str,nStrSize);
}

RING_API void ring_list_insertfuncpointer ( List *pList,int nPos,void (*pFunc)(void *) )
{
	assert(pList != NULL);
	ring_list_insertitem(pList,nPos);
	ring_list_setfuncpointer(pList,nPos+1,pFunc);
}

RING_API List * ring_list_insertlist ( List *pList,int nPos )
{
	Item *pItem  ;
	List *pList2  ;
	assert(pList != NULL);
	ring_list_insertitem(pList,nPos);
	pItem = ring_list_getitem(pList,nPos+1);
	ring_item_settype(pItem,ITEMTYPE_LIST);
	pList2 = ring_item_getlist(pItem);
	return pList2 ;
}
/* Is item inside list, support nested Lists */

RING_API int ring_list_isiteminsidelist ( List *pList,Item *pItem )
{
	int x  ;
	Item *pItem2  ;
	List *pList2  ;
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pItem2 = ring_list_getitem(pList,x);
		if ( pItem == pItem2 ) {
			return 1 ;
		}
		if ( ring_list_islist(pList,x) ) {
			pList2 = ring_item_getlist(pItem2);
			if ( ring_list_isiteminsidelist(pList2,pItem) ) {
				return 1 ;
			}
		}
	}
	return 0 ;
}
/* Delete item from list using the item pointer */

RING_API int ring_list_deliteminsidelist ( List *pList,Item *pItem )
{
	int x  ;
	Item *pItem2  ;
	List *pList2  ;
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pItem2 = ring_list_getitem(pList,x);
		if ( pItem == pItem2 ) {
			ring_list_deleteitem(pList,x);
			return 1 ;
		}
		if ( ring_list_islist(pList,x) ) {
			pList2 = ring_item_getlist(pItem2);
			if ( ring_list_isiteminsidelist(pList2,pItem) ) {
				return 1 ;
			}
		}
	}
	return 0 ;
}
/* Linear Search */

RING_API int ring_list_findstring ( List *pList,const char *str,int nColumn )
{
	int x,nCount  ;
	List *pList2  ;
	assert(pList != NULL);
	nCount = ring_list_getsize(pList);
	/* Find Item */
	if ( nCount > 0 ) {
		if ( nColumn == 0 ) {
			for ( x = 1 ; x <= nCount ; x++ ) {
				if ( ring_list_isstring(pList,x) ) {
					if ( strcmp(str,ring_list_getstring(pList,x)) == 0 ) {
						return x ;
					}
				}
			}
		}
		else {
			for ( x = 1 ; x <= nCount ; x++ ) {
				if ( ring_list_islist(pList,x) == 0 ) {
					continue ;
				}
				pList2 = ring_list_getlist(pList,x);
				if ( ring_list_isstring(pList2,nColumn) ) {
					if ( strcmp(str,ring_list_getstring(pList2,nColumn)) == 0 ) {
						return x ;
					}
				}
			}
		}
	}
	return 0 ;
}

RING_API int ring_list_finddouble ( List *pList,double nNum1,int nColumn )
{
	int x,nCount  ;
	List *pList2  ;
	assert(pList != NULL);
	nCount = ring_list_getsize(pList);
	/* Find Item */
	if ( nCount > 0 ) {
		if ( nColumn == 0 ) {
			for ( x = 1 ; x <= nCount ; x++ ) {
				if ( ring_list_isdouble(pList,x) ) {
					if ( ring_list_getdouble(pList,x) == nNum1 ) {
						return x ;
					}
				}
			}
		}
		else {
			for ( x = 1 ; x <= nCount ; x++ ) {
				if ( ring_list_islist(pList,x) == 0 ) {
					continue ;
				}
				pList2 = ring_list_getlist(pList,x);
				if ( ring_list_isdouble(pList2,nColumn) ) {
					if ( ring_list_getdouble(pList2,nColumn) == nNum1 ) {
						return x ;
					}
				}
			}
		}
	}
	return 0 ;
}

RING_API int ring_list_findpointer ( List *pList,void *pPointer )
{
	int x  ;
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		if ( ring_list_ispointer(pList,x) ) {
			if ( ring_list_getpointer(pList,x) == pPointer ) {
				return x ;
			}
		}
	}
	return 0 ;
}
/* Sort (QuickSort) and Binary Search */

RING_API void ring_list_sortnum ( List *pList,int left,int right,int nColumn )
{
	int x,y,mid  ;
	double midvalue  ;
	x = left ;
	y = right ;
	mid = (x+y)/2 ;
	midvalue = ring_list_getdoublecolumn(pList,mid,nColumn);
	while ( x <= y ) {
		while ( ring_list_getdoublecolumn(pList,x,nColumn) < midvalue ) {
			x++ ;
		}
		while ( ring_list_getdoublecolumn(pList,y,nColumn) > midvalue ) {
			y-- ;
		}
		if ( x <= y ) {
			ring_list_swap(pList,x,y);
			x++ ;
			y-- ;
		}
	}
	if ( left < y ) {
		ring_list_sortnum(pList, left, y,nColumn);
	}
	if ( y < right ) {
		ring_list_sortnum(pList, x, right,nColumn);
	}
}

RING_API void ring_list_sortstr ( List *pList,int left,int right,int nColumn )
{
	int x,y,mid  ;
	String *midvalue  ;
	x = left ;
	y = right ;
	mid = (x+y)/2 ;
	midvalue = ring_string_new(ring_list_getstringcolumn(pList,mid,nColumn));
	while ( x <= y ) {
		while ( strcmp(ring_list_getstringcolumn(pList,x,nColumn),ring_string_get(midvalue)) < 0 ) {
			x++ ;
		}
		while ( strcmp(ring_list_getstringcolumn(pList,y,nColumn),ring_string_get(midvalue)) > 0 ) {
			y-- ;
		}
		if ( x <= y ) {
			ring_list_swap(pList,x,y);
			x++ ;
			y-- ;
		}
	}
	ring_string_delete(midvalue);
	if ( left < y ) {
		ring_list_sortstr(pList, left, y,nColumn);
	}
	if ( y < right ) {
		ring_list_sortstr(pList, x, right, nColumn);
	}
}

RING_API int ring_list_binarysearchnum ( List *pList,double nNum1,int nColumn )
{
	int nFirst,nMiddle,nLast  ;
	nFirst = 1 ;
	nLast = ring_list_getsize(pList) ;
	while ( nFirst <= nLast ) {
		nMiddle = (nFirst+nLast)/2 ;
		if ( ring_list_getdoublecolumn(pList,nMiddle,nColumn) == nNum1 ) {
			return nMiddle ;
		}
		else if ( ring_list_getdoublecolumn(pList,nMiddle,nColumn) < nNum1 ) {
			nFirst = nMiddle + 1 ;
		}
		else {
			nLast = nMiddle - 1 ;
		}
	}
	return 0 ;
}

RING_API int ring_list_binarysearchstr ( List *pList,const char *cFind,int nColumn )
{
	int nFirst,nMiddle,nLast,nRes  ;
	nFirst = 1 ;
	nLast = ring_list_getsize(pList) ;
	while ( nFirst <= nLast ) {
		nMiddle = (nFirst+nLast)/2 ;
		nRes = strcmp(ring_list_getstringcolumn(pList,nMiddle,nColumn) ,cFind) ;
		if ( nRes == 0 ) {
			return nMiddle ;
		}
		else if ( nRes < 0 ) {
			nFirst = nMiddle + 1 ;
		}
		else {
			nLast = nMiddle - 1 ;
		}
	}
	return 0 ;
}

RING_API void ring_list_swap ( List *pList,int x,int y )
{
	Item *pItem  ;
	Items *pItems  ;
	pItem = ring_list_getitem(pList,x);
	pItems = pList->pLastItemLastAccess ;
	ring_list_getitem(pList,y);
	pItems->pValue = pList->pLastItemLastAccess->pValue ;
	pList->pLastItemLastAccess->pValue = pItem ;
}

RING_API double ring_list_getdoublecolumn ( List *pList,int nIndex,int nColumn )
{
	if ( nColumn == 0 ) {
		return ring_list_getdouble(pList,nIndex) ;
	}
	else {
		return ring_list_getdouble(ring_list_getlist(pList,nIndex),nColumn) ;
	}
}

RING_API char * ring_list_getstringcolumn ( List *pList,int nIndex,int nColumn )
{
	if ( nColumn == 0 ) {
		return ring_list_getstring(pList,nIndex) ;
	}
	else {
		return ring_list_getstring(ring_list_getlist(pList,nIndex),nColumn) ;
	}
}
/* List Items to Array */

RING_API void ring_list_genarray ( List *pList )
{
	int x  ;
	Item **pArray  ;
	if ( ring_list_getsize(pList) == 0 ) {
		return ;
	}
	if ( pList->pItemsArray != NULL ) {
		free( pList->pItemsArray ) ;
	}
	/*
	**  Here we save the pointer in pArray and not in pList->pItemsArray 
	**  Because we will fill the array with items pointers using ring_list_getitem() 
	**  And ring_list_getitem() check for using pList->pItemsArray 
	*/
	pArray = (Item **) malloc(ring_list_getsize(pList) * sizeof(Item *)) ;
	if ( pArray == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pArray[x-1] = ring_list_getitem(pList,x);
	}
	pList->pItemsArray = pArray ;
}

RING_API void ring_list_deletearray ( List *pList )
{
	if ( pList->pItemsArray != NULL ) {
		free( pList->pItemsArray ) ;
		pList->pItemsArray = NULL ;
	}
}
/* List Items to HashTable */

RING_API void ring_list_genhashtable ( List *pList )
{
	int x  ;
	if ( pList->pHashTable != NULL ) {
		pList->pHashTable = ring_hashtable_delete(pList->pHashTable);
	}
	pList->pHashTable = ring_hashtable_new();
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		ring_hashtable_newnumber(pList->pHashTable,ring_list_getstring(pList,x),x);
	}
}

RING_API void ring_list_genhashtable2 ( List *pList )
{
	int x  ;
	List *pList2  ;
	/* This Func. Take list of lists , the first item of the sub list is a string (key) */
	if ( pList->pHashTable != NULL ) {
		pList->pHashTable = ring_hashtable_delete(pList->pHashTable);
	}
	pList->pHashTable = ring_hashtable_new();
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pList2 = ring_list_getlist(pList,x);
		ring_hashtable_newpointer(pList->pHashTable,ring_list_getstring(pList2,1),pList2);
	}
}
/* Copy list by reference */

RING_API void ring_list_refcopy ( List *pNewList, List *pList )
{
	pNewList->pFirst = pList->pFirst ;
	pNewList->pLast = pList->pLast ;
	pNewList->nSize = pList->nSize ;
	pNewList->nNextItemAfterLastAccess = pList->nNextItemAfterLastAccess ;
	pNewList->pLastItemLastAccess = pList->pLastItemLastAccess ;
	pNewList->pItemsArray = pList->pItemsArray ;
	pNewList->pHashTable = pList->pHashTable ;
}

RING_API void ring_list_clear ( List *pList )
{
	pList->pFirst = NULL ;
	pList->pLast = NULL ;
	pList->nSize = 0 ;
	pList->nNextItemAfterLastAccess = 0 ;
	pList->pLastItemLastAccess = NULL ;
	pList->pItemsArray = NULL ;
	pList->pHashTable = NULL ;
}
/* Test */

void ring_list_test ( void )
{
	List *pList,*pList2  ;
	int x  ;
	Item *pItem  ;
	String *pString  ;
	char mystr[20]  ;
	printf( "Create new list, size = 10 \n" ) ;
	pList = ring_list_new(10);
	printf( "List(1) size %d    \n", ring_list_getsize(pList) ) ;
	printf( "Create empty list \n" ) ;
	pList2 = ring_list_new(0);
	printf( "adding 15 items to the list \n" ) ;
	for ( x = 1 ; x <= 15 ; x++ ) {
		printf( "x : %d  \n" , x ) ;
		ring_list_newitem(pList2);
	}
	printf( "List(2) size %d    \n", ring_list_getsize(pList2) ) ;
	for ( x = 1 ; x <= 10 ; x++ ) {
		/* Work on items */
		pItem = ring_list_getitem(pList2,x);
		ring_item_settype(pItem,ITEMTYPE_STRING);
		pString = ring_item_getstring(pItem);
		sprintf( mystr , "The Item Number %d" , x ) ;
		ring_string_set(pString,mystr);
		ring_string_print(pString);
	}
	for ( x = 11 ; x <= 15 ; x++ ) {
		/* Work on items */
		pItem = ring_list_getitem(pList2,x);
		ring_item_settype(pItem,ITEMTYPE_NUMBER);
	}
	/* Delete Items */
	printf( "Delete item number 5 \n" ) ;
	ring_list_deleteitem(pList2,5);
	pItem = ring_list_getitem(pList2,5);
	pString = ring_item_getstring(pItem);
	ring_string_print(pString);
	printf( "Delete item number 1 \n" ) ;
	/* Print Item */
	ring_list_deleteitem(pList2,1);
	pItem = ring_list_getitem(pList2,1);
	pString = ring_item_getstring(pItem);
	ring_string_print(pString);
	printf( "Delete item number %d \n",ring_list_getsize(pList2) ) ;
	/* Print Item */
	ring_list_deleteitem(pList2,ring_list_getsize(pList2));
	printf( "get item number %d \n",ring_list_getsize(pList2) ) ;
	/* Delete Lists */
	printf( "Deleting List 1 \n" ) ;
	ring_list_delete(pList);
	printf( "Deleting List 2 \n" ) ;
	ring_list_delete(pList2);
	getchar();
	/* Create/Delete Large List */
	printf( "Create List of 1000000 Items  \n" ) ;
	pList = ring_list_new(1000000);
	printf( "Before Loop  \n" ) ;
	for ( x = 1 ; x <= 1000000 ; x++ ) {
		ring_list_setstring(pList,x,"empty item");
	}
	printf( "Done  \n" ) ;
	getchar();
	printf( "Deleting List 1 \n" ) ;
	ring_list_delete(pList);
	getchar();
	/* Create Nested Lists */
	printf( "List = {'first item',{'item (2) item(1)','item(2) item(2)'},'lastitem' , 50 , Pointer to int } \n  " ) ;
	pList = ring_list_new(5);
	/* Set Item 1 */
	pItem = ring_list_getitem(pList,1);
	ring_item_settype(pItem,ITEMTYPE_STRING);
	pString = ring_item_getstring(pItem);
	ring_string_set(pString,mystr);
	ring_string_print(pString);
	/* Set Item 2 */
	pItem = ring_list_getitem(pList,2);
	ring_item_settype(pItem,ITEMTYPE_LIST);
	pList2 = ring_item_getlist(pItem);
	ring_list_newitem(pList2);
	ring_list_newitem(pList2);
	/* Work on items */
	pItem = ring_list_getitem(pList2,1);
	ring_item_settype(pItem,ITEMTYPE_STRING);
	pString = ring_item_getstring(pItem);
	sprintf( mystr , "Item (2) Item (1) "  ) ;
	ring_string_set(pString,mystr);
	ring_string_print(pString);
	/* Work on items */
	pItem = ring_list_getitem(pList2,2);
	ring_item_settype(pItem,ITEMTYPE_STRING);
	pString = ring_item_getstring(pItem);
	sprintf( mystr , "Item (2) Item (2) "  ) ;
	ring_string_set(pString,mystr);
	ring_string_print(pString);
	/* Set Item 3 */
	pItem = ring_list_getitem(pList,3);
	ring_item_settype(pItem,ITEMTYPE_STRING);
	pString = ring_item_getstring(pItem);
	sprintf( mystr , "last item"  ) ;
	ring_string_set(pString,mystr);
	ring_string_print(pString);
	/* set item 4 */
	pItem = ring_list_getitem(pList,4);
	ring_item_settype(pItem,ITEMTYPE_NUMBER);
	/* set item 5 */
	pItem = ring_list_getitem(pList,5);
	ring_item_settype(pItem,ITEMTYPE_POINTER);
	printf( "Printing list \n  " ) ;
	ring_list_print(pList);
	/* Copy List */
	printf( "\n Copy List1 to List 2 \n  " ) ;
	pList2 = ring_list_new(0);
	ring_list_copy(pList2,pList);
	printf( "\n Printing List 2 \n  " ) ;
	ring_list_print(pList2);
	ring_list_delete(pList2);
	ring_list_delete(pList);
	/* Use list_setstring & list_getstring */
	printf( "\n use ring_list_setstring and ring_list_getstring  \n" ) ;
	pList = ring_list_new(3);
	ring_list_setstring(pList,1,"one");
	ring_list_setstring(pList,2,"two");
	ring_list_setstring(pList,3,"three");
	for ( x = 1 ; x <= 3 ; x++ ) {
		printf( "Item Number %d = %s  \n",x,ring_list_getstring(pList,x) ) ;
	}
	ring_list_delete(pList);
	/* using list_addstring */
	printf( "using ring_list_addstring  \n" ) ;
	pList = ring_list_new(0);
	ring_list_addstring(pList,"item 1");
	ring_list_addstring(pList,"item 2");
	ring_list_addstring(pList,"item 3");
	ring_list_addstring(pList,"item 4");
	ring_list_addstring(pList,"item 5");
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		printf( "Item Number %d = %s  \n",x,ring_list_getstring(pList,x) ) ;
	}
	/* Test Get item */
	printf( "Item Number 1 = %s  \n",ring_list_getstring(pList,1) ) ;
	printf( "Item Number 5 = %s  \n",ring_list_getstring(pList,5) ) ;
	printf( "Item Number 4 = %s  \n",ring_list_getstring(pList,4) ) ;
	printf( "Item Number 3 = %s  \n",ring_list_getstring(pList,3) ) ;
	printf( "Item Number 3 = %s  \n",ring_list_getstring(pList,3) ) ;
	printf( "Item Number 2 = %s  \n",ring_list_getstring(pList,2) ) ;
	printf( "Item Number 3 = %s  \n",ring_list_getstring(pList,3) ) ;
	ring_list_delete(pList);
	/* Function Pointers */
	pList = ring_list_new(0);
	ring_list_addfuncpointer(pList,ring_list_testfuncpointer);
	puts(" *** Test Function Pointer *** ");
	ring_list_callfuncpointer(pList,1,pList);
	ring_list_delete(pList);
	getchar();
}
