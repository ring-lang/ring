/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API Item * ring_item_new_gc ( void *pState,unsigned int nItemType )
{
	Item *pItem  ;
	pItem = (Item *) ring_state_malloc(pState,sizeof(Item));
	/* Set Type */
	pItem->nType = ITEMTYPE_NOTHING ;
	/* Delete pointer information */
	pItem->nObjectType = ITEM_OBJTYPE_NOTHING ;
	pItem->lAssignment = RING_ZERO ;
	/* Delete number information */
	pItem->data.dNumber = 0 ;
	pItem->nNumberFlag = ITEM_NUMBERFLAG_NOTHING ;
	/* Reference Count */
	ring_vm_gc_cleardata(pItem);
	ring_item_settype_gc(pState,pItem,nItemType);
	return pItem ;
}

RING_API Item * ring_item_delete_gc ( void *pState,Item *pItem )
{
	ring_vm_gc_deleteitem_gc(pState,pItem);
	return NULL ;
}

RING_API void ring_item_print ( Item *pItem )
{
	unsigned int nItemType  ;
	nItemType = pItem->nType ;
	switch ( nItemType ) {
		case ITEMTYPE_NOTHING :
			break ;
		case ITEMTYPE_STRING :
			ring_string_print(pItem->data.pString);
			break ;
		case ITEMTYPE_NUMBER :
			if ( pItem->nNumberFlag == ITEM_NUMBERFLAG_INT ) {
				printf( "%d\n ",pItem->data.iNumber ) ;
			}
			else {
				printf( "%f \n",pItem->data.dNumber ) ;
			}
			break ;
		case ITEMTYPE_POINTER :
			printf( "%p",pItem->data.pPointer ) ;
			break ;
		case ITEMTYPE_LIST :
			ring_list_print(pItem->data.pList);
			break ;
	}
}

RING_API void ring_item_init ( Item *pItem )
{
	pItem->nType = ITEMTYPE_NOTHING ;
	pItem->nNumberFlag = ITEM_NUMBERFLAG_NOTHING ;
	pItem->nObjectType = ITEM_OBJTYPE_NOTHING ;
	pItem->lAssignment = RING_ZERO ;
}

RING_API void ring_item_deletecontent_gc ( void *pState,Item *pItem )
{
	int nType  ;
	nType = pItem->nType ;
	/* Set Type */
	ring_item_init(pItem);
	switch ( nType ) {
		case ITEMTYPE_STRING :
			pItem->data.pString = ring_string_delete_gc(pState,pItem->data.pString);
			break ;
		case ITEMTYPE_LIST :
			pItem->data.pList = ring_list_delete_gc(pState,pItem->data.pList);
			break ;
	}
	/* Clear Data */
	pItem->data.dNumber = 0 ;
}

RING_API void ring_item_settype_gc ( void *pState,Item *pItem,unsigned int nItemType )
{
	if ( (nItemType == pItem->nType) && ( (nItemType == ITEMTYPE_STRING) || (nItemType == ITEMTYPE_NUMBER)  ) ) {
		/*
		**  If the current item type is a String and the new type is also a String - We do nothing 
		**  In this case the item will contains the old data 
		**  So when we set the item string again using the same size 
		**  We don't need to free & allocate the memory many times 
		**  Where we can use the same memory 
		**  This is useful when we process large data files through blocks of fixed size 
		*/
		return ;
	}
	/* When we set the type we remove the current content at first */
	ring_item_deletecontent_gc(pState,pItem);
	switch ( nItemType ) {
		case ITEMTYPE_NOTHING :
			pItem->nType = ITEMTYPE_NOTHING ;
			break ;
		case ITEMTYPE_STRING :
			pItem->nType = ITEMTYPE_STRING ;
			pItem->data.pString = ring_string_new_gc(pState,RING_CSTR_EMPTY);
			break ;
		case ITEMTYPE_NUMBER :
			pItem->nType = ITEMTYPE_NUMBER ;
			pItem->data.dNumber = 0 ;
			pItem->nNumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
			break ;
		case ITEMTYPE_POINTER :
			pItem->nType = ITEMTYPE_POINTER ;
			pItem->data.pPointer = NULL ;
			pItem->nObjectType = ITEM_OBJTYPE_NOTHING ;
			break ;
		case ITEMTYPE_LIST :
			pItem->nType = ITEMTYPE_LIST ;
			pItem->data.pList = ring_list_new_gc(pState,RING_ZERO);
			break ;
		case ITEMTYPE_FUNCPOINTER :
			pItem->nType = ITEMTYPE_FUNCPOINTER ;
			pItem->data.pFunc = NULL ;
			break ;
	}
}

RING_API void ring_itemarray_setint_gc ( void *pState,Item aItems[], unsigned int nIndex ,int nNumber )
{
	ring_item_settype_gc(pState,&aItems[nIndex],ITEMTYPE_NUMBER);
	aItems[nIndex].data.iNumber = nNumber ;
	aItems[nIndex].nNumberFlag = ITEM_NUMBERFLAG_INT ;
}

RING_API void ring_itemarray_setpointer_gc ( void *pState,Item aItems[], unsigned int nIndex ,void *pValue )
{
	ring_item_settype_gc(pState,&aItems[nIndex],ITEMTYPE_POINTER);
	aItems[nIndex].data.pPointer = pValue ;
	aItems[nIndex].nObjectType = ITEM_OBJTYPE_NOTHING ;
	aItems[nIndex].lAssignment = RING_ZERO ;
}

RING_API void ring_itemarray_setdouble_gc ( void *pState,Item aItems[], unsigned int nIndex ,double nNumber )
{
	ring_item_settype_gc(pState,&aItems[nIndex],ITEMTYPE_NUMBER);
	aItems[nIndex].data.dNumber = nNumber ;
	aItems[nIndex].nNumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
}

RING_API void ring_itemarray_setstring_gc ( void *pState,Item aItems[], unsigned int nIndex ,const char *cStr )
{
	ring_item_settype_gc(pState,&aItems[nIndex],ITEMTYPE_STRING);
	ring_string_set_gc(pState,aItems[nIndex].data.pString ,cStr);
}

RING_API void ring_itemarray_setstring2_gc ( void *pState,Item aItems[], unsigned int nIndex ,const char *cStr,int nStrSize )
{
	ring_item_settype_gc(pState,&aItems[nIndex],ITEMTYPE_STRING);
	ring_string_set2_gc(pState,aItems[nIndex].data.pString ,cStr,nStrSize);
}
/* Functions to deal with one item */

RING_API void ring_item_setstring_gc ( void *pState,Item *pItem,const char *cStr )
{
	ring_item_settype_gc(pState,pItem,ITEMTYPE_STRING);
	ring_string_set_gc(pState,ring_item_getstring(pItem),cStr);
}

RING_API void ring_item_setstring2_gc ( void *pState,Item *pItem,const char *cStr,int nStrSize )
{
	ring_item_settype_gc(pState,pItem,ITEMTYPE_STRING);
	ring_string_set2_gc(pState,ring_item_getstring(pItem),cStr,nStrSize);
}

RING_API void ring_item_setdouble_gc ( void *pState,Item *pItem,double x )
{
	ring_item_settype_gc(pState,pItem,ITEMTYPE_NUMBER);
	pItem->data.dNumber = x ;
	pItem->nNumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
}

RING_API void ring_item_setpointer_gc ( void *pState,Item *pItem,void *pValue )
{
	ring_item_settype_gc(pState,pItem,ITEMTYPE_POINTER);
	pItem->data.pPointer = pValue ;
	pItem->nObjectType = ITEM_OBJTYPE_NOTHING ;
}

RING_API void ring_item_setint_gc ( void *pState,Item *pItem,int x )
{
	ring_item_settype_gc(pState,pItem,ITEMTYPE_NUMBER);
	pItem->data.iNumber = x ;
	pItem->nNumberFlag = ITEM_NUMBERFLAG_INT ;
}
/* Functions without state pointer */

RING_API Item * ring_item_new ( unsigned int nItemType )
{
	return ring_item_new_gc(NULL,nItemType) ;
}

RING_API Item * ring_item_delete ( Item *pItem )
{
	return ring_item_delete_gc(NULL,pItem) ;
}

RING_API void ring_item_settype ( Item *pItem,unsigned int nItemType )
{
	ring_item_settype_gc(NULL,pItem,nItemType);
}

RING_API void ring_item_deletecontent ( Item *pItem )
{
	ring_item_deletecontent_gc(NULL,pItem);
}
/* Functions to deal with array of items */

RING_API void ring_itemarray_setint ( Item aItems[], unsigned int nIndex ,int nNumber )
{
	ring_itemarray_setint_gc(NULL,aItems,nIndex,nNumber);
}

RING_API void ring_itemarray_setpointer ( Item aItems[], unsigned int nIndex ,void *pValue )
{
	ring_itemarray_setpointer_gc(NULL,aItems,nIndex,pValue);
}

RING_API void ring_itemarray_setdouble ( Item aItems[], unsigned int nIndex ,double nNumber )
{
	ring_itemarray_setdouble_gc(NULL,aItems,nIndex,nNumber);
}

RING_API void ring_itemarray_setstring ( Item aItems[], unsigned int nIndex ,const char *cStr )
{
	ring_itemarray_setstring_gc(NULL,aItems,nIndex,cStr);
}

RING_API void ring_itemarray_setstring2 ( Item aItems[], unsigned int nIndex ,const char *cStr,int nStrSize )
{
	ring_itemarray_setstring2_gc(NULL,aItems,nIndex,cStr,nStrSize);
}
/* Functions to deal with one item */

RING_API void ring_item_setstring ( Item *pItem,const char *cStr )
{
	ring_item_setstring_gc(NULL,pItem,cStr);
}

RING_API void ring_item_setdouble ( Item *pItem,double x )
{
	ring_item_setdouble_gc(NULL,pItem,x);
}

RING_API void ring_item_setpointer ( Item *pItem,void *pValue )
{
	ring_item_setpointer_gc(NULL,pItem,pValue);
}

RING_API void ring_item_setint ( Item *pItem,int x )
{
	ring_item_setint_gc(NULL,pItem,x);
}

RING_API void ring_item_setstring2 ( Item *pItem,const char *cStr,int nStrSize )
{
	ring_item_setstring2_gc(NULL,pItem,cStr,nStrSize);
}
/* Functions to deal with Numbers (int/double) */

RING_API double ring_item_getnumber ( Item *pItem )
{
	if ( pItem->nNumberFlag == ITEM_NUMBERFLAG_INT ) {
		return (double) pItem->data.iNumber ;
	}
	return pItem->data.dNumber ;
}
