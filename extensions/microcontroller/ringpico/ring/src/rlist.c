/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API List * ring_list_new_gc ( void *pState,unsigned int nSize )
{
	List *pList  ;
	pList = (List *) ring_state_malloc(pState,sizeof(List));
	return ring_list_new2_gc(pState,pList,nSize) ;
}

RING_API List * ring_list_new2_gc ( void *pState,List *pList,unsigned int nSize )
{
	unsigned int x  ;
	Items *pItems,*pItemsLast  ;
	pList->nSize = nSize ;
	if ( nSize > 0 ) {
		pItems = ring_items_new_gc(pState);
		/* Set Item type and value */
		ring_item_settype_gc(pState,pItems->pValue,ITEMTYPE_NUMBER);
		pList->pFirst = pItems ;
		pItemsLast = pItems ;
		for ( x = 2 ; x <= nSize ; x++ ) {
			pItems = ring_items_new_gc(pState);
			if ( pItems == NULL ) {
				printf( RING_OOM ) ;
				exit(RING_EXIT_FAIL);
			}
			/* Set Item type and value */
			ring_item_settype_gc(pState,pItems->pValue,ITEMTYPE_NUMBER);
			pItemsLast->pNext = pItems ;
			pItems->pPrev = pItemsLast ;
			pItemsLast = pItems ;
		}
		pList->pLast = pItems ;
	}
	else {
		pList->pFirst = NULL ;
		pList->pLast = NULL ;
	}
	pList->pItemsArray = NULL ;
	pList->pHashTable = NULL ;
	pList->pBlocks = NULL ;
	ring_list_clearcache(pState,pList);
	ring_list_clearrefdata(pList);
	return pList ;
}

RING_API List * ring_list_delete_gc ( void *pState,List *pList )
{
	return ring_list_deleteref_gc(pState,pList) ;
}

RING_API void ring_list_deletecontent_gc ( void *pState,List *pList )
{
	/* Delete All Items */
	ring_list_deleteallitems_gc(pState,pList);
	ring_state_free(pState,pList);
}

RING_API void ring_list_copy_gc ( void *pState,List *pNewList, List *pList )
{
	unsigned int x,nMax  ;
	List *pNewList2  ;
	/*
	**  This function don't add a new list before copying items 
	**  if you want to add a list to another one, create new list in the target then copy to it 
	**  Copy Items 
	*/
	nMax = ring_list_getsize(pList) ;
	if ( nMax == 0 ) {
		return ;
	}
	for ( x = 1 ; x <= nMax ; x++ ) {
		if ( ring_list_isint(pList,x) ) {
			ring_list_addint_gc(pState,pNewList,ring_list_getint(pList,x));
		}
		else if ( ring_list_isdouble(pList,x) ) {
			ring_list_adddouble_gc(pState,pNewList,ring_list_getdouble(pList,x));
		}
		else if ( ring_list_isstring(pList,x) ) {
			ring_list_addstring2_gc(pState,pNewList,ring_list_getstring(pList,x),ring_list_getstringsize(pList,x));
		}
		else if ( ring_list_ispointer(pList,x) ) {
			ring_list_addpointer_gc(pState,pNewList,ring_list_getpointer(pList,x));
		}
		else if ( ring_list_isfuncpointer(pList,x) ) {
			ring_list_addfuncpointer_gc(pState,pNewList,ring_list_getfuncpointer(pList,x));
		}
		else if ( ring_list_islist(pList,x) ) {
			pNewList2 = ring_list_newlist_gc(pState,pNewList);
			ring_list_copy_gc(pState,pNewList2,ring_list_getlist(pList,x));
		}
	}
}

RING_API void ring_list_deleteallitems_gc ( void *pState,List *pList )
{
	Items *pItems,*pItemsNext  ;
	pItems = pList->pLast ;
	if ( pItems != NULL ) {
		pItemsNext = pItems ;
		/* Delete Items */
		while ( pItemsNext != NULL ) {
			pItemsNext = pItems->pPrev ;
			ring_items_delete_gc(pState,pItems);
			pItems = pItemsNext ;
		}
	}
	pList->pFirst = NULL ;
	pList->pLast = NULL ;
	pList->nSize = 0 ;
	ring_list_finishdelete_gc(pState,pList);
}

RING_API void ring_list_finishdelete_gc ( void *pState,List *pList )
{
	ListBlocks *pBlocks  ;
	ring_list_clearcache(pState,pList);
	/* Free HashTable */
	if ( pList->pHashTable != NULL ) {
		pList->pHashTable = ring_hashtable_delete_gc(pState,pList->pHashTable);
	}
	/* Delete Blocks (if we have allocated large block of memory) */
	while ( pList->pBlocks != NULL ) {
		/* Unregister the block */
		if ( pList->pBlocks->nType == RING_LISTBLOCKTYPE_ITEM ) {
			ring_state_willunregisterblock(pState,((struct Item *) pList->pBlocks->pValue ) + 1);
			ring_state_unregisterblock(pState,((struct Item *) pList->pBlocks->pValue ) + 1);
		}
		else if ( pList->pBlocks->nType == RING_LISTBLOCKTYPE_ITEMS ) {
			ring_state_unregisterblock(pState,((struct Items *) pList->pBlocks->pValue ) + 1);
		}
		else if ( pList->pBlocks->nType == RING_LISTBLOCKTYPE_LIST ) {
			ring_state_unregisterblock(pState,((struct List *) pList->pBlocks->pValue ) + 1);
		}
		ring_state_free(pState,pList->pBlocks->pValue);
		pBlocks = pList->pBlocks ;
		pList->pBlocks = pBlocks->pNext ;
		ring_state_free(pState,pBlocks);
	}
}

RING_API void ring_list_copy_tohighlevel_gc ( void *pState,List *pNewList, List *pList )
{
	unsigned int x  ;
	List *pNewList2  ;
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
			ring_list_adddouble_gc(pState,pNewList,(double) ring_list_getint(pList,x));
		}
		else if ( ring_list_isdouble(pList,x) ) {
			ring_list_adddouble_gc(pState,pNewList,ring_list_getdouble(pList,x));
		}
		else if ( ring_list_isstring(pList,x) ) {
			ring_list_addstring2_gc(pState,pNewList,ring_list_getstring(pList,x),ring_list_getstringsize(pList,x));
		}
		else if ( ring_list_ispointer(pList,x) ) {
			ring_list_addpointer_gc(pState,pNewList,ring_list_getpointer(pList,x));
		}
		else if ( ring_list_islist(pList,x) ) {
			pNewList2 = ring_list_newlist_gc(pState,pNewList);
			ring_list_copy_tohighlevel_gc(pState,pNewList2,ring_list_getlist(pList,x));
		}
	}
}

RING_API void ring_list_addblock_gc ( void *pState,List *pList,void *pMemory,int nType )
{
	ListBlocks *pBlocks  ;
	/* Check if we will add the first block */
	if ( pList->pBlocks == NULL ) {
		pList->pBlocks = (ListBlocks *) ring_state_malloc(pState,sizeof(ListBlocks)) ;
		pList->pBlocks->pValue = pMemory ;
		pList->pBlocks->pNext = NULL ;
		pList->pBlocks->nType = nType ;
		return ;
	}
	/* Add more blocks */
	pBlocks = pList->pBlocks ;
	while ( pBlocks->pNext != NULL ) {
		pBlocks = pBlocks->pNext ;
	}
	pBlocks->pNext = (ListBlocks *) ring_state_malloc(pState,sizeof(ListBlocks)) ;
	pBlocks->pNext->pValue = pMemory ;
	pBlocks->pNext->pNext = NULL ;
	pBlocks->pNext->nType = nType ;
}

RING_API void ring_list_clearcache ( void *pState,List *pList )
{
	pList->nNextItemAfterLastAccess = 0 ;
	pList->pLastItemLastAccess = NULL ;
	/* Free Items Array */
	ring_list_deletearray_gc(pState,pList);
}

RING_API void ring_list_setcache ( void *pState,List *pList, struct Items *pItems, unsigned int nNextItem )
{
	pList->pLastItemLastAccess = pItems ;
	pList->nNextItemAfterLastAccess = nNextItem ;
}
/* List Items */

RING_API Item * ring_list_newitem_gc ( void *pState,List *pList )
{
	Items *pItems  ;
	pItems = ring_items_new_gc(pState);
	ring_list_newitembyitemsptr_gc(pState,pList,pItems);
	return pItems->pValue ;
}

RING_API void ring_list_newitembyitemsptr_gc ( void *pState,List *pList,Items *pItems )
{
	if ( (pList->nSize) > 0 ) {
		pList->pLast->pNext = pItems ;
		pItems->pPrev = pList->pLast ;
		pList->pLast = pItems ;
		/* Refresh The Cache */
		ring_list_clearcache(pState,pList);
	}
	else {
		pList->pFirst = pItems ;
		pList->pLast = pItems ;
	}
	pList->nSize++ ;
}

RING_API Item * ring_list_getitem ( List *pList,unsigned int nIndex )
{
	Items *pItems  ;
	Item *pItem  ;
	unsigned int x  ;
	pItem = NULL ;
	if ( nIndex > 0 && nIndex <= ring_list_getsize(pList) ) {
		/* Quickly get item from ItemsArray */
		if ( pList->pItemsArray != NULL ) {
			return pList->pItemsArray[nIndex-1] ;
		}
		/* Quickly Get The First or The Last Item */
		if ( nIndex == 1 ) {
			ring_list_setcache(NULL,pList,pList->pFirst,nIndex+1);
			return pList->pFirst->pValue ;
		}
		else if ( nIndex == ring_list_getsize(pList) ) {
			ring_list_setcache(NULL,pList,pList->pLast,nIndex+1);
			return pList->pLast->pValue ;
		}
		/* Quickly get the next item */
		else if ( ( nIndex == pList->nNextItemAfterLastAccess ) && ( pList->pLastItemLastAccess != NULL ) ) {
			if ( pList->pLastItemLastAccess->pNext  != NULL ) {
				pList->pLastItemLastAccess = pList->pLastItemLastAccess->pNext ;
				pList->nNextItemAfterLastAccess++ ;
				return pList->pLastItemLastAccess->pValue ;
			}
		}
		/* Quickly get the current item */
		else if ( (nIndex == pList->nNextItemAfterLastAccess - 1) && ( pList->pLastItemLastAccess != NULL ) ) {
			return pList->pLastItemLastAccess->pValue ;
		}
		/* Quickly get item after the current item */
		else if ( (nIndex > pList->nNextItemAfterLastAccess ) && ( (nIndex - pList->nNextItemAfterLastAccess) < (pList->nSize - nIndex))  && ( pList->pLastItemLastAccess != NULL ) ) {
			pItems = pList->pLastItemLastAccess ;
			for ( x = pList->nNextItemAfterLastAccess - 1 ; x <= nIndex ; x++ ) {
				if ( x == nIndex ) {
					ring_list_setcache(NULL,pList,pItems,nIndex+1);
				}
				pItem = pItems->pValue ;
				pItems = pItems->pNext ;
			}
			return pItem ;
		}
		/* Quickly get item before the current item */
		else if ( (nIndex < pList->nNextItemAfterLastAccess) &&  ( (pList->nNextItemAfterLastAccess - nIndex) < nIndex)  && ( pList->pLastItemLastAccess != NULL ) ) {
			pItems = pList->pLastItemLastAccess ;
			for ( x = pList->nNextItemAfterLastAccess - 1 ; x >= nIndex ; x-- ) {
				if ( x == nIndex ) {
					ring_list_setcache(NULL,pList,pItems,nIndex+1);
				}
				pItem = pItems->pValue ;
				pItems = pItems->pPrev ;
			}
			return pItem ;
		}
		if ( nIndex < (pList->nSize - nIndex) ) {
			/* Linear Search  From Start */
			pItems = pList->pFirst ;
			for ( x = 1 ; x <= nIndex ; x++ ) {
				if ( x == nIndex ) {
					ring_list_setcache(NULL,pList,pItems,nIndex+1);
				}
				pItem = pItems->pValue ;
				pItems = pItems->pNext ;
			}
		}
		else {
			/* Linear search from the last item */
			pItems = pList->pLast ;
			for ( x = pList->nSize ; x >= nIndex ; x-- ) {
				if ( x == nIndex ) {
					ring_list_setcache(NULL,pList,pItems,nIndex+1);
				}
				pItem = pItems->pValue ;
				pItems = pItems->pPrev ;
			}
			return pItem ;
		}
	}
	return pItem ;
}

RING_API void ring_list_deleteitem_gc ( void *pState,List *pList,unsigned int nIndex )
{
	unsigned int x  ;
	Items *pItems,*pItemsPrev  ;
	/* Goto the Item */
	if ( nIndex > 0 && nIndex <= ring_list_getsize(pList) ) {
		/* Quickly Get the Last Item */
		if ( nIndex == ring_list_getsize(pList) ) {
			pItems = pList->pLast ;
			pItemsPrev = pItems->pPrev ;
		}
		/* Linear Search */
		else {
			pItems = pList->pFirst ;
			pItemsPrev = NULL ;
			for ( x = 1 ; x < nIndex ; x++ ) {
				pItemsPrev = pItems ;
				pItems = pItems->pNext ;
			}
		}
		/* Delete The Item */
		if ( nIndex == 1 ) {
			pList->pFirst = pItems->pNext ;
		}
		if ( nIndex == ring_list_getsize(pList) ) {
			pList->pLast = pItemsPrev ;
		}
		if ( pItemsPrev != NULL ) {
			pItemsPrev->pNext = pItems->pNext ;
		}
		if ( pItems != NULL ) {
			if ( pItems->pNext != NULL ) {
				pItems->pNext->pPrev = pItemsPrev ;
			}
			ring_items_delete_gc(pState,pItems);
			pList->nSize = pList->nSize - 1 ;
		}
	}
	/* Refresh The Cache */
	ring_list_clearcache(pState,pList);
}

RING_API int ring_list_gettype ( List *pList, unsigned int nIndex )
{
	Item *pItem  ;
	pItem = ring_list_getitem(pList,nIndex);
	if ( pItem != NULL ) {
		return ring_item_gettype(pItem) ;
	}
	return 0 ;
}

RING_API int ring_list_isstring ( List *pList, unsigned int nIndex )
{
	return (ring_list_gettype(pList,nIndex) == ITEMTYPE_STRING) ;
}

RING_API int ring_list_isnumber ( List *pList, unsigned int nIndex )
{
	return (ring_list_gettype(pList,nIndex) == ITEMTYPE_NUMBER) ;
}

RING_API int ring_list_islist ( List *pList, unsigned int nIndex )
{
	return (ring_list_gettype(pList,nIndex) == ITEMTYPE_LIST) ;
}

RING_API int ring_list_ispointer ( List *pList, unsigned int nIndex )
{
	return (ring_list_gettype(pList,nIndex) == ITEMTYPE_POINTER) ;
}
/* int */

RING_API void ring_list_setint_gc ( void *pState,List *pList, unsigned int nIndex ,int nNumber )
{
	Item *pItem  ;
	pItem = ring_list_getitem(pList,nIndex);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_NUMBER);
	pItem->data.iNumber = nNumber ;
	pItem->nNumberFlag = ITEM_NUMBERFLAG_INT ;
}

RING_API void ring_list_addint_gc ( void *pState,List *pList,int x )
{
	ring_list_newitem_gc(pState,pList);
	ring_list_setint_gc(pState,pList,ring_list_getsize(pList),x);
}
/* Pointers */

RING_API void ring_list_setpointer_gc ( void *pState,List *pList, unsigned int nIndex ,void *pValue )
{
	Item *pItem  ;
	pItem = ring_list_getitem(pList,nIndex);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_POINTER);
	pItem->data.pPointer = pValue ;
}

RING_API void ring_list_setpointerandtype_gc ( void *pState,List *pList, unsigned int nIndex ,void *pValue,int nType )
{
	Item *pItem  ;
	ring_list_setpointer_gc(pState,pList,nIndex,pValue);
	pItem = ring_list_getitem(pList,nIndex);
	pItem->nObjectType = nType ;
}

RING_API void ring_list_addpointer_gc ( void *pState,List *pList,void *pValue )
{
	ring_list_newitem_gc(pState,pList);
	ring_list_setpointer_gc(pState,pList,ring_list_getsize(pList),pValue);
}

RING_API void ring_list_addpointerandtype_gc ( void *pState,List *pList,void *pValue,int nType )
{
	Item *pItem  ;
	pItem = ring_list_newitem_gc(pState,pList);
	ring_list_setpointer_gc(pState,pList,ring_list_getsize(pList),pValue);
	pItem->nObjectType = nType ;
}
/* double */

RING_API void ring_list_setdouble_gc ( void *pState,List *pList, unsigned int nIndex ,double nNumber )
{
	Item *pItem  ;
	pItem = ring_list_getitem(pList,nIndex);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_NUMBER);
	pItem->data.dNumber = nNumber ;
	pItem->nNumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
}

RING_API void ring_list_adddouble_gc ( void *pState,List *pList,double x )
{
	ring_list_newitem_gc(pState,pList);
	ring_list_setdouble_gc(pState,pList,ring_list_getsize(pList),x);
}
/* String */

RING_API void ring_list_setstring_gc ( void *pState,List *pList, unsigned int nIndex ,const char *cStr )
{
	Item *pItem  ;
	String *pString  ;
	pItem = ring_list_getitem(pList,nIndex);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_STRING);
	pString = ring_item_getstring(pItem);
	ring_string_set_gc(pState,pString,cStr);
}

RING_API void ring_list_setstring2_gc ( void *pState,List *pList, unsigned int nIndex ,const char *cStr,int nStrSize )
{
	Item *pItem  ;
	String *pString  ;
	pItem = ring_list_getitem(pList,nIndex);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_STRING);
	pString = ring_item_getstring(pItem);
	ring_string_set2_gc(pState,pString,cStr,nStrSize);
}

RING_API void ring_list_addstring_gc ( void *pState,List *pList,const char *cStr )
{
	ring_list_newitem_gc(pState,pList);
	ring_list_setstring_gc(pState,pList,ring_list_getsize(pList),cStr);
}

RING_API void ring_list_addstring2_gc ( void *pState,List *pList,const char *cStr,int nStrSize )
{
	ring_list_newitem_gc(pState,pList);
	ring_list_setstring2_gc(pState,pList,ring_list_getsize(pList),cStr,nStrSize);
}
/* List */

RING_API List * ring_list_newlist_gc ( void *pState,List *pList )
{
	Item *pItem  ;
	pItem = ring_list_newitem_gc(pState,pList);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_LIST);
	return ring_item_getlist(pItem) ;
}

RING_API void ring_list_setlist_gc ( void *pState,List *pList, unsigned int nIndex )
{
	Item *pItem  ;
	pItem = ring_list_getitem(pList,nIndex);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_LIST);
}

RING_API List * ring_list_getlist ( List *pList, unsigned int nIndex )
{
	Item *pItem  ;
	List *pList2  ;
	pItem = ring_list_getitem(pList,nIndex);
	pList2 = ring_item_getlist(pItem);
	return pList2 ;
}

RING_API List * ring_list_newlistbyptr_gc ( void *pState,List *pList,List *pNewList )
{
	Item *pItem  ;
	pItem = ring_list_newitem_gc(pState,pList);
	pItem->nType = ITEMTYPE_LIST ;
	pItem->data.pList = pNewList ;
	return pNewList ;
}
/* Function Pointers */

RING_API void ring_list_setfuncpointer_gc ( void *pState,List *pList, unsigned int nIndex ,void (*pFunc)(void *) )
{
	Item *pItem  ;
	pItem = ring_list_getitem(pList,nIndex);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_FUNCPOINTER);
	pItem->data.pFunc = pFunc ;
}

RING_API void ring_list_addfuncpointer_gc ( void *pState,List *pList,void (*pFunc)(void *) )
{
	ring_list_newitem_gc(pState,pList);
	ring_list_setfuncpointer_gc(pState,pList,ring_list_getsize(pList),pFunc);
}

RING_API int ring_list_isfuncpointer ( List *pList, unsigned int nIndex )
{
	return (ring_list_gettype(pList,nIndex) == ITEMTYPE_FUNCPOINTER) ;
}
/*
**  Insert Items 
**  When you insert item, it will be inserted after nPos 
*/

RING_API void ring_list_insertitem_gc ( void *pState,List *pList,unsigned int x )
{
	Items *pItems, *pPos  ;
	if ( x > ring_list_getsize(pList) ) {
		return ;
	}
	else if ( x == ring_list_getsize(pList) ) {
		ring_list_newitem_gc(pState,pList);
		return ;
	}
	pItems = ring_items_new_gc(pState);
	/* Insert Item at the first of the list */
	if ( x==0 ) {
		pItems->pNext = pList->pFirst ;
		pItems->pPrev = NULL ;
		pList->pFirst->pPrev = pItems ;
		pList->pFirst = pItems ;
		pList->nSize = pList->nSize + 1 ;
		/* Clear the cache to delete the array of items if it does exist */
		ring_list_clearcache(pState,pList);
		return ;
	}
	/*
	**  Get the position 
	**  When we get an item, pLastItemLastAccess will be changed to Items * of that item 
	*/
	ring_list_getitem(pList,x);
	pPos = pList->pLastItemLastAccess ;
	if ( (pPos == NULL) || (pList->pItemsArray != NULL) ) {
		/* This support making list cache optional without having problems here */
		pPos = ring_list_getitemcontainer(pList,x) ;
	}
	pItems->pNext = pPos->pNext ;
	pItems->pNext->pPrev = pItems ;
	pItems->pPrev = pPos ;
	pPos->pNext = pItems ;
	pList->nSize = pList->nSize + 1 ;
	/* Clear the cache to delete the array of items if it does exist */
	ring_list_clearcache(pState,pList);
	ring_list_setcache(pState,pList, pItems, x+2);
}

RING_API void ring_list_insertint_gc ( void *pState,List *pList,unsigned int nPos,int x )
{
	ring_list_insertitem_gc(pState,pList,nPos);
	ring_list_setint_gc(pState,pList,nPos+1,x);
}

RING_API void ring_list_insertdouble_gc ( void *pState,List *pList,unsigned int nPos,double x )
{
	ring_list_insertitem_gc(pState,pList,nPos);
	ring_list_setdouble_gc(pState,pList,nPos+1,x);
}

RING_API void ring_list_insertpointer_gc ( void *pState,List *pList,unsigned int nPos,void *pValue )
{
	ring_list_insertitem_gc(pState,pList,nPos);
	ring_list_setpointer_gc(pState,pList,nPos+1,pValue);
}

RING_API void ring_list_insertstring_gc ( void *pState,List *pList,unsigned int nPos,const char *cStr )
{
	ring_list_insertitem_gc(pState,pList,nPos);
	ring_list_setstring_gc(pState,pList,nPos+1,cStr);
}

RING_API void ring_list_insertstring2_gc ( void *pState,List *pList,unsigned int nPos,const char *cStr,int nStrSize )
{
	ring_list_insertitem_gc(pState,pList,nPos);
	ring_list_setstring2_gc(pState,pList,nPos+1,cStr,nStrSize);
}

RING_API void ring_list_insertfuncpointer_gc ( void *pState,List *pList,unsigned int nPos,void (*pFunc)(void *) )
{
	ring_list_insertitem_gc(pState,pList,nPos);
	ring_list_setfuncpointer_gc(pState,pList,nPos+1,pFunc);
}

RING_API List * ring_list_insertlist_gc ( void *pState,List *pList,unsigned int nPos )
{
	Item *pItem  ;
	List *pList2  ;
	ring_list_insertitem_gc(pState,pList,nPos);
	pItem = ring_list_getitem(pList,nPos+1);
	ring_item_settype_gc(pState,pItem,ITEMTYPE_LIST);
	pList2 = ring_item_getlist(pItem);
	return pList2 ;
}
/* Is item inside list, support nested Lists */

RING_API int ring_list_isiteminsidelist ( List *pList,Item *pItem )
{
	unsigned int x  ;
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

RING_API int ring_list_deliteminsidelist_gc ( void *pState,List *pList,Item *pItem )
{
	unsigned int x  ;
	Item *pItem2  ;
	List *pList2  ;
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pItem2 = ring_list_getitem(pList,x);
		if ( pItem == pItem2 ) {
			ring_list_deleteitem_gc(pState,pList,x);
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
/* Get Items * using item index */

RING_API Items * ring_list_getitemcontainer ( List *pList,unsigned int nIndex )
{
	Items *pItems  ;
	unsigned int x  ;
	pItems = NULL ;
	if ( nIndex > 0 && nIndex <= ring_list_getsize(pList) ) {
		/* Get First/Last item */
		if ( nIndex == 1 ) {
			return pList->pFirst ;
		}
		else if ( nIndex == ring_list_getsize(pList) ) {
			return pList->pLast ;
		}
		pItems = pList->pFirst ;
		for ( x = 1 ; x < nIndex ; x++ ) {
			pItems = pItems->pNext ;
		}
	}
	return pItems ;
}
/* Linear Search */

RING_API int ring_list_findstring ( List *pList,const char *cStr,unsigned int nColumn )
{
	unsigned int x,nCount  ;
	List *pList2  ;
	nCount = ring_list_getsize(pList);
	/* Find Item */
	if ( nCount > 0 ) {
		if ( nColumn == 0 ) {
			for ( x = 1 ; x <= nCount ; x++ ) {
				if ( ring_list_isstring(pList,x) ) {
					if ( strcmp(cStr,ring_list_getstring(pList,x)) == 0 ) {
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
				if ( ring_list_getsize(pList2)< nColumn ) {
					return -1 ;
				}
				if ( ring_list_isstring(pList2,nColumn) ) {
					if ( strcmp(cStr,ring_list_getstring(pList2,nColumn)) == 0 ) {
						return x ;
					}
				}
			}
		}
	}
	return 0 ;
}

RING_API int ring_list_finddouble ( List *pList,double nNum1,unsigned int nColumn )
{
	unsigned int x,nCount  ;
	List *pList2  ;
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
				if ( ring_list_getsize(pList2)< nColumn ) {
					return -1 ;
				}
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
	unsigned int x  ;
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

RING_API void ring_list_sortnum ( List *pList,int left,int right,unsigned int nColumn,const char *cAttribute )
{
	unsigned int x,y,nMid  ;
	double nMidvalue  ;
	x = left ;
	y = right ;
	nMid = (x+y)/2 ;
	nMidvalue = ring_list_getdoublecolumn(pList,nMid,nColumn,cAttribute);
	while ( x <= y ) {
		while ( ring_list_getdoublecolumn(pList,x,nColumn,cAttribute) < nMidvalue ) {
			x++ ;
		}
		while ( ring_list_getdoublecolumn(pList,y,nColumn,cAttribute) > nMidvalue ) {
			y-- ;
		}
		if ( x <= y ) {
			ring_list_swap(pList,x,y);
			x++ ;
			y-- ;
		}
	}
	if ( left < y ) {
		ring_list_sortnum(pList, left, y,nColumn,cAttribute);
	}
	if ( y < right ) {
		ring_list_sortnum(pList, x, right,nColumn,cAttribute);
	}
}

RING_API void ring_list_sortstr_gc ( void *pState,List *pList,int left,int right,unsigned int nColumn,const char *cAttribute )
{
	unsigned int x,y,nMid  ;
	String *pMidvalue  ;
	x = left ;
	y = right ;
	nMid = (x+y)/2 ;
	pMidvalue = ring_string_new_gc(pState,ring_list_getstringcolumn(pList,nMid,nColumn,cAttribute));
	while ( x <= y ) {
		while ( strcmp(ring_list_getstringcolumn(pList,x,nColumn,cAttribute),ring_string_get(pMidvalue)) < 0 ) {
			x++ ;
		}
		while ( strcmp(ring_list_getstringcolumn(pList,y,nColumn,cAttribute),ring_string_get(pMidvalue)) > 0 ) {
			y-- ;
		}
		if ( x <= y ) {
			ring_list_swap(pList,x,y);
			x++ ;
			y-- ;
		}
	}
	ring_string_delete_gc(pState,pMidvalue);
	if ( left < y ) {
		ring_list_sortstr_gc(pState,pList, left, y,nColumn,cAttribute);
	}
	if ( y < right ) {
		ring_list_sortstr_gc(pState,pList, x, right, nColumn,cAttribute);
	}
}

RING_API int ring_list_binarysearchnum ( List *pList,double nNum1,unsigned int nColumn,const char *cAttribute )
{
	int nFirst,nMid,nLast  ;
	nFirst = 1 ;
	nLast = ring_list_getsize(pList) ;
	while ( nFirst <= nLast ) {
		nMid = (nFirst+nLast)/2 ;
		if ( ring_list_getdoublecolumn(pList,nMid,nColumn,cAttribute) == nNum1 ) {
			return nMid ;
		}
		else if ( ring_list_getdoublecolumn(pList,nMid,nColumn,cAttribute) < nNum1 ) {
			nFirst = nMid + 1 ;
		}
		else {
			nLast = nMid - 1 ;
		}
	}
	return 0 ;
}

RING_API int ring_list_binarysearchstr ( List *pList,const char *cFind,unsigned int nColumn,const char *cAttribute )
{
	int nFirst,nMid,nLast,nRes  ;
	nFirst = 1 ;
	nLast = ring_list_getsize(pList) ;
	while ( nFirst <= nLast ) {
		nMid = (nFirst+nLast)/2 ;
		nRes = strcmp(ring_list_getstringcolumn(pList,nMid,nColumn,cAttribute) ,cFind) ;
		if ( nRes == 0 ) {
			return nMid ;
		}
		else if ( nRes < 0 ) {
			nFirst = nMid + 1 ;
		}
		else {
			nLast = nMid - 1 ;
		}
	}
	return 0 ;
}

RING_API void ring_list_swap ( List *pList,unsigned int x,unsigned int y )
{
	Item *pItem  ;
	Items *pItems, *pItems2  ;
	pItem = ring_list_getitem(pList,x);
	pItems = ring_list_getitemcontainer(pList,x) ;
	pItems2 = ring_list_getitemcontainer(pList,y);
	pItems->pValue = pItems2->pValue ;
	pItems2->pValue = pItem ;
}
/* List Items to Array */

RING_API void ring_list_genarray_gc ( void *pState,List *pList )
{
	unsigned int x  ;
	Item **pArray  ;
	Items *pItems  ;
	if ( pList->pItemsArray != NULL ) {
		ring_state_free(pState,pList->pItemsArray);
		pList->pItemsArray = NULL ;
	}
	if ( ring_list_getsize(pList) == 0 ) {
		return ;
	}
	/*
	**  Here we  don't use ring_list_getitem 
	**  Because ring_list_getitem() use/update Cache 
	*/
	pArray = (Item **) ring_state_malloc(pState,ring_list_getsize(pList) * sizeof(Item *));
	pItems = pList->pFirst ;
	for ( x = 0 ; x < ring_list_getsize(pList) ; x++ ) {
		pArray[x] = pItems->pValue ;
		pItems = pItems->pNext ;
	}
	pList->pItemsArray = pArray ;
}

RING_API void ring_list_deletearray_gc ( void *pState,List *pList )
{
	if ( pList->pItemsArray != NULL ) {
		ring_state_free(pState,pList->pItemsArray);
		pList->pItemsArray = NULL ;
	}
}
/* List Items to HashTable */

RING_API void ring_list_genhashtable_gc ( void *pState,List *pList )
{
	unsigned int x  ;
	if ( pList->pHashTable != NULL ) {
		pList->pHashTable = ring_hashtable_delete_gc(pState,pList->pHashTable);
	}
	pList->pHashTable = ring_hashtable_new_gc(pState);
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		if ( ring_list_isstring(pList,x) ) {
			ring_hashtable_newnumber_gc(pState,pList->pHashTable,ring_list_getstring(pList,x),x);
		}
	}
}

RING_API void ring_list_genhashtable2_gc ( void *pState,List *pList )
{
	unsigned int x  ;
	List *pList2  ;
	/* This Func. Take list of lists , the first item of the sub list is a string (key) */
	if ( pList->pHashTable != NULL ) {
		pList->pHashTable = ring_hashtable_delete_gc(pState,pList->pHashTable);
	}
	pList->pHashTable = ring_hashtable_new_gc(pState);
	for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		if ( ring_list_islist(pList,x) ) {
			pList2 = ring_list_getlist(pList,x);
			if ( (ring_list_getsize(pList2) >= RING_LIST_KEYINDEX) && (ring_list_isstring(pList2,RING_LIST_KEYINDEX)) ) {
				ring_hashtable_newpointer_gc(pState,pList->pHashTable,ring_list_getstring(pList2,RING_LIST_KEYINDEX),pList2);
			}
		}
	}
}
/* Define functions without State Pointer */

RING_API List * ring_list_new ( unsigned int nSize )
{
	return ring_list_new_gc(NULL,nSize) ;
}

RING_API void ring_list_genarray ( List *pList )
{
	ring_list_genarray_gc(NULL,pList);
}

RING_API List * ring_list_delete ( List *pList )
{
	return ring_list_delete_gc(NULL,pList) ;
}

RING_API void ring_list_deletearray ( List *pList )
{
	ring_list_deletearray_gc(NULL,pList);
}

RING_API void ring_list_newitem ( List *pList )
{
	ring_list_newitem_gc(NULL,pList);
}

RING_API void ring_list_deleteitem ( List *pList,unsigned int nIndex )
{
	ring_list_deleteitem_gc(NULL,pList,nIndex);
}
/* int */

RING_API void ring_list_setint ( List *pList, unsigned int nIndex ,int nNumber )
{
	ring_list_setint_gc(NULL,pList,nIndex,nNumber);
}

RING_API void ring_list_addint ( List *pList,int x )
{
	ring_list_addint_gc(NULL,pList,x);
}
/* Pointers */

RING_API void ring_list_setpointer ( List *pList, unsigned int nIndex ,void *pValue )
{
	ring_list_setpointer_gc(NULL,pList,nIndex,pValue);
}

RING_API void ring_list_addpointer ( List *pList,void *pValue )
{
	ring_list_addpointer_gc(NULL,pList,pValue);
}
/* Function Pointers */

RING_API void ring_list_setfuncpointer ( List *pList, unsigned int nIndex ,void (*pFunc)(void *) )
{
	ring_list_setfuncpointer_gc(NULL,pList,nIndex,pFunc);
}

RING_API void ring_list_addfuncpointer ( List *pList,void (*pFunc)(void *) )
{
	ring_list_addfuncpointer_gc(NULL,pList,pFunc);
}
/* double */

RING_API void ring_list_setdouble ( List *pList, unsigned int nIndex ,double nNumber )
{
	ring_list_setdouble_gc(NULL,pList,nIndex,nNumber);
}

RING_API void ring_list_adddouble ( List *pList,double x )
{
	ring_list_adddouble_gc(NULL,pList,x);
}
/* String */

RING_API void ring_list_setstring ( List *pList, unsigned int nIndex ,const char *cStr )
{
	ring_list_setstring_gc(NULL,pList,nIndex,cStr);
}

RING_API void ring_list_setstring2 ( List *pList, unsigned int nIndex ,const char *cStr,int nStrSize )
{
	ring_list_setstring2_gc(NULL,pList,nIndex,cStr,nStrSize);
}

RING_API void ring_list_addstring ( List *pList,const char *cStr )
{
	ring_list_addstring_gc(NULL,pList,cStr);
}

RING_API void ring_list_addstring2 ( List *pList,const char *cStr,int nStrSize )
{
	ring_list_addstring2_gc(NULL,pList,cStr,nStrSize);
}
/* List */

RING_API List * ring_list_newlist ( List *pList )
{
	return ring_list_newlist_gc(NULL,pList) ;
}

RING_API void ring_list_setlist ( List *pList, unsigned int nIndex )
{
	ring_list_setlist_gc(NULL,pList,nIndex);
}

RING_API void ring_list_copy ( List *pNewList, List *pList )
{
	ring_list_copy_gc(NULL,pNewList,pList);
}

RING_API void ring_list_deleteallitems ( List *pList )
{
	ring_list_deleteallitems_gc(NULL,pList);
}
/* Insert Items */

RING_API void ring_list_insertitem ( List *pList,unsigned int x )
{
	ring_list_insertitem_gc(NULL,pList,x);
}

RING_API void ring_list_insertint ( List *pList,unsigned int nPos,int x )
{
	ring_list_insertint_gc(NULL,pList,nPos,x);
}

RING_API void ring_list_insertdouble ( List *pList,unsigned int nPos,double x )
{
	ring_list_insertdouble_gc(NULL,pList,nPos,x);
}

RING_API void ring_list_insertpointer ( List *pList,unsigned int nPos,void *pValue )
{
	ring_list_insertpointer_gc(NULL,pList,nPos,pValue);
}

RING_API void ring_list_insertstring ( List *pList,unsigned int nPos,const char *cStr )
{
	ring_list_insertstring_gc(NULL,pList,nPos,cStr);
}

RING_API void ring_list_insertstring2 ( List *pList,unsigned int nPos,const char *cStr,int nStrSize )
{
	ring_list_insertstring2_gc(NULL,pList,nPos,cStr,nStrSize);
}

RING_API void ring_list_insertfuncpointer ( List *pList,unsigned int nPos,void (*pFunc)(void *) )
{
	ring_list_insertfuncpointer_gc(NULL,pList,nPos,pFunc);
}

RING_API List * ring_list_insertlist ( List *pList,unsigned int nPos )
{
	return ring_list_insertlist_gc(NULL,pList,nPos) ;
}

RING_API void ring_list_sortstr ( List *pList,int left,int right,unsigned int nColumn,const char *cAttribute )
{
	ring_list_sortstr_gc(NULL,pList,left,right,nColumn,cAttribute);
}
/* List Items to HashTable */

RING_API void ring_list_genhashtable ( List *pList )
{
	ring_list_genhashtable_gc(NULL,pList);
}

RING_API void ring_list_genhashtable2 ( List *pList )
{
	ring_list_genhashtable2_gc(NULL,pList);
}
/* Swap two lists */

RING_API void ring_list_swaptwolists ( List *pList1, List *pList2 )
{
	List pTempList  ;
	/* Get data from pList1 to pTempList */
	memcpy(&pTempList,pList1,sizeof(List));
	/* Get data from pList2 to pList1 */
	memcpy(pList1,pList2,sizeof(List));
	/* Get data from pTempList to pList2 */
	memcpy(pList2,&pTempList,sizeof(List));
}
/* List Functions that know about using Lists for Ring Objects & C Pointers */

RING_API void ring_list_print ( List *pList )
{
	ring_list_print2(pList,RING_DECIMALS);
}

RING_API void ring_list_print2 ( List *pList,unsigned int nDecimals )
{
	unsigned int x,t,nSize  ;
	double y  ;
	const char *cStr  ;
	List *pList2  ;
	char cOptions[RING_SMALLBUF]  ;
	char cString[RING_MEDIUMBUF]  ;
	/* Print Items */
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
				}
				else {
					sprintf(cOptions , "%s%df" , "%.",nDecimals);
					#if RING_NOSNPRINTF
						sprintf(cString, cOptions, y);
					#else
						snprintf(cString, RING_MEDIUMBUF, cOptions, y);
					#endif
					printf("%s\n",cString);
				}
			}
			else if ( ring_list_isint(pList,x) ) {
				printf( "%d\n",ring_list_getint(pList,x) ) ;
			}
		}
		else if ( ring_list_islist(pList,x) ) {
			pList2 = ring_list_getlist(pList,x) ;
			if ( ring_list_isobject(pList2) ) {
				ring_list_printobj(pList2,nDecimals);
			}
			else {
				if ( ring_list_isref(pList2) ) {
					printf( "[...] (RC:%d)\n",ring_list_getrefcount(pList2) ) ;
				}
				else {
					ring_list_print2(pList2,nDecimals);
				}
			}
		}
		else if ( ring_list_ispointer(pList,x) ) {
			printf( "%p\n",ring_list_getpointer(pList,x) ) ;
		}
		else if ( ring_list_isfuncpointer(pList,x) ) {
			printf( "%p\n",ring_list_getfuncpointer(pList,x) ) ;
		}
	}
}

RING_API int ring_list_findinlistofobjs ( List *pList,int nType,double nNum1,const char *cStr,unsigned int nColumn,char *cAttribute )
{
	unsigned int x,nCount,nPos  ;
	List *pList2  ;
	nCount = ring_list_getsize(pList);
	ring_string_lower(cAttribute);
	/* Find Item */
	if ( (nCount > 0) && (nColumn > 0) ) {
		for ( x = 1 ; x <= nCount ; x++ ) {
			if ( ring_list_islist(pList,x) == 0 ) {
				continue ;
			}
			pList2 = ring_list_getlist(pList,x);
			if ( nColumn > 1 ) {
				if ( ring_list_islist(pList2,nColumn) ) {
					pList2 = ring_list_getlist(pList2,nColumn);
				}
				else {
					continue ;
				}
			}
			if ( ring_list_isobject(pList2) == 0 ) {
				continue ;
			}
			nPos = ring_list_findstring(ring_list_getlist(pList2,RING_OBJECT_OBJECTDATA),cAttribute,RING_VAR_NAME);
			if ( nPos == 0 ) {
				return -1 ;
			}
			pList2 = ring_list_getlist(pList2,RING_OBJECT_OBJECTDATA) ;
			pList2 = ring_list_getlist(pList2,nPos) ;
			if ( nType  == RING_LISTOFOBJS_FINDSTRING ) {
				if ( strcmp(cStr,ring_list_getstring(pList2,RING_VAR_VALUE)) == 0 ) {
					return x ;
				}
			}
			else {
				if ( ring_list_getdouble(pList2,RING_VAR_VALUE) == nNum1 ) {
					return x ;
				}
			}
		}
	}
	return 0 ;
}

RING_API int ring_list_findcpointer ( List *pList,List *pValue,unsigned int nColumn )
{
	unsigned int x,nCount  ;
	List *pList2, *pList3  ;
	nCount = ring_list_getsize(pList);
	/* Find Item */
	if ( nCount > 0 ) {
		if ( nColumn == 0 ) {
			for ( x = 1 ; x <= nCount ; x++ ) {
				if ( ring_list_islist(pList,x) ) {
					pList2 = ring_list_getlist(pList,x);
					if ( ring_list_iscpointerlist(pList2) ) {
						if ( ring_list_cpointercmp(pList2,pValue) ) {
							return x ;
						}
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
				if ( ring_list_islist(pList2,nColumn) ) {
					pList3 = ring_list_getlist(pList2,nColumn);
					if ( ring_list_cpointercmp(pList3,pValue) ) {
						return x ;
					}
				}
			}
		}
	}
	return 0 ;
}

RING_API double ring_list_getdoublecolumn ( List *pList,unsigned int nIndex,unsigned int nColumn,const char *cAttribute )
{
	int nPos  ;
	if ( nColumn == 0 ) {
		return ring_list_getdouble(pList,nIndex) ;
	}
	else {
		if ( strcmp(cAttribute,RING_CSTR_EMPTY) == 0 ) {
			return ring_list_getdouble(ring_list_getlist(pList,nIndex),nColumn) ;
		}
		else {
			pList = ring_list_getlist(pList,nIndex);
			if ( nColumn > 1 ) {
				pList = ring_list_getlist(pList,nColumn);
			}
			if ( ring_list_isobject(pList) ) {
				nPos = ring_list_findstring(ring_list_getlist(pList,RING_OBJECT_OBJECTDATA),cAttribute,RING_VAR_NAME);
				pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA) ;
				pList = ring_list_getlist(pList,nPos) ;
				if ( ring_list_isdouble(pList,RING_VAR_VALUE) ) {
					return ring_list_getdouble(pList,RING_VAR_VALUE) ;
				}
			}
		}
	}
	return 0.0 ;
}

RING_API char * ring_list_getstringcolumn ( List *pList,unsigned int nIndex,unsigned int nColumn,const char *cAttribute )
{
	int nPos  ;
	static char nullstring[] = RING_CSTR_EMPTY ;
	if ( nColumn == 0 ) {
		return ring_list_getstring(pList,nIndex) ;
	}
	else {
		if ( strcmp(cAttribute,RING_CSTR_EMPTY) == 0 ) {
			return ring_list_getstring(ring_list_getlist(pList,nIndex),nColumn) ;
		}
		else {
			pList = ring_list_getlist(pList,nIndex);
			if ( nColumn > 1 ) {
				pList = ring_list_getlist(pList,nColumn);
			}
			if ( ring_list_isobject(pList) ) {
				nPos = ring_list_findstring(ring_list_getlist(pList,RING_OBJECT_OBJECTDATA),cAttribute,RING_VAR_NAME);
				pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA) ;
				pList = ring_list_getlist(pList,nPos) ;
				if ( ring_list_isstring(pList,RING_VAR_VALUE) ) {
					return ring_list_getstring(pList,RING_VAR_VALUE) ;
				}
			}
		}
	}
	return nullstring ;
}

RING_API void ring_list_addringpointer ( List *pList,void *pValue )
{
	ring_list_addringpointer_gc(NULL,pList,pValue);
}

RING_API void ring_list_addringpointer_gc ( void *pState,List *pList,void *pValue )
{
	ring_list_addcustomringpointer_gc(pState,pList,pValue,ring_state_free);
}

RING_API void ring_list_addcustomringpointer_gc ( void *pState,List *pList,void *pValue,void (* pFreeFunc)(void *,void *) )
{
	List *pPointerList  ;
	Item *pItem  ;
	ring_list_addpointer_gc(pState,pList,pValue);
	pItem = ring_list_getitem(pList,ring_list_getsize(pList));
	ring_vm_gc_setfreefunc(pItem,pFreeFunc);
}

RING_API int ring_list_isobject ( List *pList )
{
	return ( (pList != NULL) &&
	(ring_list_getsize(pList) == RING_OBJECT_LISTSIZE) &&
	ring_list_ispointer(pList,RING_OBJECT_CLASSPOINTER) &&
	ring_list_islist(pList,RING_OBJECT_OBJECTDATA)  ) ;
}

RING_API void ring_list_printobj ( List *pList,unsigned int nDecimals )
{
	List *pList2,*pList3  ;
	unsigned int x  ;
	char cStr[RING_MEDIUMBUF]  ;
	pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA);
	for ( x = 3 ; x <= ring_list_getsize(pList) ; x++ ) {
		pList2 = ring_list_getlist(pList,x);
		printf( "%s: " , ring_list_getstring(pList2,RING_VAR_NAME) ) ;
		if ( ring_list_isstring(pList2,RING_VAR_VALUE) ) {
			printf( "%s\n" , ring_list_getstring(pList2,RING_VAR_VALUE) ) ;
		}
		else if ( ring_list_isnumber(pList2,RING_VAR_VALUE) ) {
			ring_general_numtostring(ring_list_getdouble(pList2,RING_VAR_VALUE),cStr,nDecimals);
			printf( "%s\n" ,cStr ) ;
		}
		else if ( ring_list_islist(pList2,RING_VAR_VALUE) ) {
			pList3 = ring_list_getlist(pList2,RING_VAR_VALUE) ;
			if ( ring_list_isobject(pList3) ) {
				printf( "Object...\n" ) ;
			}
			else {
				printf( "[This Attribute Contains A List]\n" ) ;
			}
		}
	}
}

RING_API int ring_list_iscpointerlist ( List *pList )
{
	return ( (ring_list_getsize(pList) == RING_CPOINTER_LISTSIZE) &&
	ring_list_ispointer(pList,RING_CPOINTER_POINTER) && ring_list_isstring(pList,RING_CPOINTER_TYPE) && ring_list_isnumber(pList,RING_CPOINTER_STATUS) ) ;
}

RING_API int ring_list_cpointercmp ( List *pList,List *pList2 )
{
	return ring_list_getpointer(pList,RING_CPOINTER_POINTER) == ring_list_getpointer(pList2,RING_CPOINTER_POINTER) ;
}
