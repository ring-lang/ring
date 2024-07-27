/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_list_h
	#define ring_list_h
	/* Data */
	typedef struct ListBlocks {
		void *pValue  ;
		struct ListBlocks *pNext  ;
		int nType  ;
	} ListBlocks ;
	typedef struct List {
		struct Items *pFirst  ;
		struct Items *pLast  ;
		unsigned int nSize  ;
		unsigned int nNextItemAfterLastAccess  ;
		struct Items *pLastItemLastAccess  ;
		struct Item **pItemsArray  ;
		struct HashTable *pHashTable  ;
		struct ListBlocks *pBlocks  ;
		/* Garbage Collector Data (Reference Counting) */
		ListGCData vGC  ;
	} List ;
	/* Constants */
	#define RING_LISTOFOBJS_FINDSTRING 1
	#define RING_LISTOFOBJS_FINDNUMBER 0
	#define RING_LISTREF_INC 1
	#define RING_LISTREF_DEC -1
	#define RING_LISTBLOCKTYPE_ITEM 1
	#define RING_LISTBLOCKTYPE_ITEMS 2
	#define RING_LISTBLOCKTYPE_LIST 3
	#define RING_LIST_KEYINDEX 1
	/* Macro */
	#define ring_list_isdouble(pList,nIndex) (ring_list_gettype(pList,nIndex) == ITEMTYPE_NUMBER) && ( ring_list_getitem(pList,nIndex)->nNumberFlag == ITEM_NUMBERFLAG_DOUBLE)
	#define ring_list_isint(pList,nIndex) (ring_list_gettype(pList,nIndex) == ITEMTYPE_NUMBER) && ( ring_list_getitem(pList,nIndex)->nNumberFlag == ITEM_NUMBERFLAG_INT )
	#define ring_list_deletelastitem(pList) ring_list_deleteitem(pList,ring_list_getsize(pList))
	#define ring_list_gethashtable(pList) (pList->pHashTable)
	#define ring_list_getint(pList,nIndex) ( ring_list_getitem(pList,nIndex)->data.iNumber )
	#define ring_list_getpointer(pList,nIndex) ( ring_list_getitem(pList,nIndex)->data.pPointer )
	#define ring_list_getpointertype(pList,nIndex) ( ring_list_getitem(pList,nIndex)->nObjectType )
	#define ring_list_getfuncpointer(pList,nIndex) ( ring_list_getitem(pList,nIndex)->data.pFunc )
	#define ring_list_callfuncpointer(pList,nIndex,pPointer) ( ring_list_getitem(pList,nIndex)->data.pFunc(pPointer) )
	#define ring_list_getdouble(pList,nIndex) ring_list_getitem(pList,nIndex)->data.dNumber
	#define ring_list_getstring(pList,nIndex) ( ring_string_get(ring_item_getstring(ring_list_getitem(pList,nIndex))) )
	#define ring_list_getstringobject(pList,nIndex) ( ring_item_getstring(ring_list_getitem(pList,nIndex)) )
	#define ring_list_getstringsize(pList,nIndex) ( ring_string_size(ring_item_getstring(ring_list_getitem(pList,nIndex))) )
	#define ring_list_getsize(pList) (pList->nSize)
	#define ring_list_deletelastitem_gc(pState,pList) ring_list_deleteitem_gc(pState,pList,ring_list_getsize(pList))
	#define ring_list_incdouble(pList,nIndex) ++ring_list_getitem(pList,nIndex)->data.dNumber
	/*
	**  Functions 
	**  Main List Functions 
	*/

	RING_API List * ring_list_new_gc ( void *pState,unsigned int nSize ) ;

	RING_API List * ring_list_new2_gc ( void *pState,List *pList,unsigned int nSize ) ;

	RING_API Item * ring_list_newitem_gc ( void *pState,List *pList ) ;

	RING_API void ring_list_newitembyitemsptr_gc ( void *pState,List *pList,Items *pItems ) ;

	RING_API Item * ring_list_getitem ( List *pList,unsigned int nIndex ) ;

	RING_API List * ring_list_delete_gc ( void *pState,List *pList ) ;

	RING_API void ring_list_deletecontent_gc ( void *pState,List *pList ) ;

	RING_API void ring_list_deleteitem_gc ( void *pState,List *pList,unsigned int nIndex ) ;

	RING_API int ring_list_gettype ( List *pList, unsigned int nIndex ) ;

	RING_API void ring_list_addblock_gc ( void *pState,List *pList,void *pMemory,int nType ) ;

	RING_API void ring_list_clearcache ( void *pState,List *pList ) ;

	RING_API void ring_list_setcache ( void *pState,List *pList, struct Items *pItems, unsigned int nNextItem ) ;

	RING_API Items * ring_list_getitemcontainer ( List *pList,unsigned int nIndex ) ;
	/* int */

	RING_API void ring_list_setint_gc ( void *pState,List *pList, unsigned int nIndex ,int nNumber ) ;

	RING_API void ring_list_addint_gc ( void *pState,List *pList,int x ) ;
	/* Pointers */

	RING_API void ring_list_setpointer_gc ( void *pState,List *pList, unsigned int nIndex ,void *pValue ) ;

	RING_API void ring_list_setpointerandtype_gc ( void *pState,List *pList, unsigned int nIndex ,void *pValue,int nType ) ;

	RING_API void ring_list_addpointer_gc ( void *pState,List *pList,void *pValue ) ;

	RING_API void ring_list_addpointerandtype_gc ( void *pState,List *pList,void *pValue,int nType ) ;
	/* Function Pointers */

	RING_API void ring_list_setfuncpointer_gc ( void *pState,List *pList, unsigned int nIndex ,void (*pFunc)(void *) ) ;

	RING_API void ring_list_addfuncpointer_gc ( void *pState,List *pList,void (*pFunc)(void *) ) ;

	RING_API int ring_list_isfuncpointer ( List *pList, unsigned int nIndex ) ;
	/* double */

	RING_API void ring_list_setdouble_gc ( void *pState,List *pList, unsigned int nIndex ,double nNumber ) ;

	RING_API void ring_list_adddouble_gc ( void *pState,List *pList,double x ) ;
	/* String */

	RING_API void ring_list_setstring_gc ( void *pState,List *pList, unsigned int nIndex ,const char *cStr ) ;

	RING_API void ring_list_setstring2_gc ( void *pState,List *pList, unsigned int nIndex ,const char *cStr,int nStrSize ) ;

	RING_API void ring_list_addstring_gc ( void *pState,List *pList,const char *cStr ) ;

	RING_API void ring_list_addstring2_gc ( void *pState,List *pList,const char *cStr,int nStrSize ) ;
	/* List */

	RING_API List * ring_list_newlist_gc ( void *pState,List *pList ) ;

	RING_API void ring_list_setlist_gc ( void *pState,List *pList, unsigned int nIndex ) ;

	RING_API List * ring_list_getlist ( List *pList, unsigned int nIndex ) ;

	RING_API List * ring_list_newlistbyptr_gc ( void *pState,List *pList,List *pNewList ) ;

	RING_API void ring_list_copy_gc ( void *pState,List *pNewList, List *pList ) ;

	RING_API int ring_list_isnumber ( List *pList, unsigned int nIndex ) ;

	RING_API int ring_list_isstring ( List *pList, unsigned int nIndex ) ;

	RING_API int ring_list_islist ( List *pList, unsigned int nIndex ) ;

	RING_API int ring_list_ispointer ( List *pList, unsigned int nIndex ) ;

	RING_API void ring_list_deleteallitems_gc ( void *pState,List *pList ) ;

	RING_API void ring_list_finishdelete_gc ( void *pState,List *pList ) ;
	/* Insert Items */

	RING_API void ring_list_insertitem_gc ( void *pState,List *pList,unsigned int x ) ;

	RING_API void ring_list_insertint_gc ( void *pState,List *pList,unsigned int nPos,int x ) ;

	RING_API void ring_list_insertdouble_gc ( void *pState,List *pList,unsigned int nPos,double x ) ;

	RING_API void ring_list_insertpointer_gc ( void *pState,List *pList,unsigned int nPos,void *pValue ) ;

	RING_API void ring_list_insertstring_gc ( void *pState,List *pList,unsigned int nPos,const char *cStr ) ;

	RING_API void ring_list_insertstring2_gc ( void *pState,List *pList,unsigned int nPos,const char *cStr,int nStrSize ) ;

	RING_API void ring_list_insertfuncpointer_gc ( void *pState,List *pList,unsigned int nPos,void (*pFunc)(void *) ) ;

	RING_API List * ring_list_insertlist_gc ( void *pState,List *pList,unsigned int nPos ) ;
	/* Is item inside list, support nested Lists */

	RING_API int ring_list_isiteminsidelist ( List *pList,Item *pItem ) ;
	/* Linear Search */

	RING_API int ring_list_findstring ( List *pList,const char *cStr,unsigned int nColumn ) ;

	RING_API int ring_list_finddouble ( List *pList,double nNum1,unsigned int nColumn ) ;

	RING_API int ring_list_findpointer ( List *pList,void *pPointer ) ;
	/* Sort and Binary Search */

	RING_API void ring_list_sortnum ( List *pList,int left,int right,unsigned int nColumn,const char *cAttribute ) ;

	RING_API void ring_list_sortstr_gc ( void *pState,List *pList,int left,int right,unsigned int nColumn,const char *cAttribute ) ;

	RING_API int ring_list_binarysearchnum ( List *pList,double nNum1,unsigned int nColumn,const char *cAttribute ) ;

	RING_API int ring_list_binarysearchstr ( List *pList,const char *cFind,unsigned int nColumn,const char *cAttribute ) ;

	RING_API void ring_list_swap ( List *pList,unsigned int x,unsigned int y ) ;
	/* List Items to Array */

	RING_API void ring_list_genarray_gc ( void *pState,List *pList ) ;

	RING_API void ring_list_deletearray_gc ( void *pState,List *pList ) ;
	/* List Items to HashTable */

	RING_API void ring_list_genhashtable_gc ( void *pState,List *pList ) ;

	RING_API void ring_list_genhashtable2_gc ( void *pState,List *pList ) ;
	/* Delete item from list using the item pointer */

	RING_API int ring_list_deliteminsidelist_gc ( void *pState,List *pList,Item *pItem ) ;

	RING_API void ring_list_swaptwolists ( List *pList1, List *pList2 ) ;

	RING_API void ring_list_copy_tohighlevel_gc ( void *pState,List *pNewList, List *pList ) ;
	/* Define functions without RingState * */

	RING_API List * ring_list_new ( unsigned int nSize ) ;

	RING_API void ring_list_genarray ( List *pList ) ;

	RING_API List * ring_list_delete ( List *pList ) ;

	RING_API void ring_list_deletearray ( List *pList ) ;

	RING_API void ring_list_newitem ( List *pList ) ;

	RING_API void ring_list_deleteitem ( List *pList,unsigned int nIndex ) ;
	/* int */

	RING_API void ring_list_setint ( List *pList, unsigned int nIndex ,int nNumber ) ;

	RING_API void ring_list_addint ( List *pList,int x ) ;
	/* Pointers */

	RING_API void ring_list_setpointer ( List *pList, unsigned int nIndex ,void *pValue ) ;

	RING_API void ring_list_addpointer ( List *pList,void *pValue ) ;
	/* Function Pointers */

	RING_API void ring_list_setfuncpointer ( List *pList, unsigned int nIndex ,void (*pFunc)(void *) ) ;

	RING_API void ring_list_addfuncpointer ( List *pList,void (*pFunc)(void *) ) ;
	/* double */

	RING_API void ring_list_setdouble ( List *pList, unsigned int nIndex ,double nNumber ) ;

	RING_API void ring_list_adddouble ( List *pList,double x ) ;
	/* String */

	RING_API void ring_list_setstring ( List *pList, unsigned int nIndex ,const char *cStr ) ;

	RING_API void ring_list_setstring2 ( List *pList, unsigned int nIndex ,const char *cStr,int nStrSize ) ;

	RING_API void ring_list_addstring ( List *pList,const char *cStr ) ;

	RING_API void ring_list_addstring2 ( List *pList,const char *cStr,int nStrSize ) ;
	/* List */

	RING_API List * ring_list_newlist ( List *pList ) ;

	RING_API void ring_list_setlist ( List *pList, unsigned int nIndex ) ;

	RING_API void ring_list_copy ( List *pNewList, List *pList ) ;

	RING_API void ring_list_deleteallitems ( List *pList ) ;
	/* Insert Items */

	RING_API void ring_list_insertitem ( List *pList,unsigned int x ) ;

	RING_API void ring_list_insertint ( List *pList,unsigned int nPos,int x ) ;

	RING_API void ring_list_insertdouble ( List *pList,unsigned int nPos,double x ) ;

	RING_API void ring_list_insertpointer ( List *pList,unsigned int nPos,void *pValue ) ;

	RING_API void ring_list_insertstring ( List *pList,unsigned int nPos,const char *cStr ) ;

	RING_API void ring_list_insertstring2 ( List *pList,unsigned int nPos,const char *cStr,int nStrSize ) ;

	RING_API void ring_list_insertfuncpointer ( List *pList,unsigned int nPos,void (*pFunc)(void *) ) ;

	RING_API List * ring_list_insertlist ( List *pList,unsigned int nPos ) ;

	RING_API void ring_list_sortstr ( List *pList,int left,int right,unsigned int nColumn,const char *cAttribute ) ;
	/* List Items to HashTable */

	RING_API void ring_list_genhashtable ( List *pList ) ;

	RING_API void ring_list_genhashtable2 ( List *pList ) ;
	/* Functions that know about using Lists for Ring Objects & C Pointers */

	RING_API void ring_list_print ( List *pList ) ;

	RING_API void ring_list_print2 ( List *pList,unsigned int nDecimals ) ;

	RING_API int ring_list_findinlistofobjs ( List *pList,int nType,double nNum1,const char *cStr,unsigned int nColumn,char *cAttribute ) ;

	RING_API int ring_list_findcpointer ( List *pList,List *pValue,unsigned int nColumn ) ;

	RING_API double ring_list_getdoublecolumn ( List *pList,unsigned int nIndex,unsigned int nColumn,const char *cAttribute ) ;

	RING_API char * ring_list_getstringcolumn ( List *pList,unsigned int nIndex,unsigned int nColumn,const char *cAttribute ) ;

	RING_API void ring_list_addringpointer ( List *pList,void *pValue ) ;

	RING_API void ring_list_addringpointer_gc ( void *pState,List *pList,void *pValue ) ;

	RING_API void ring_list_addcustomringpointer_gc ( void *pState,List *pList,void *pValue,void (* pFreeFunc)(void *,void *) ) ;

	RING_API int ring_list_isobject ( List *pList ) ;

	RING_API void ring_list_printobj ( List *pList, unsigned int nDecimals ) ;

	RING_API int ring_list_iscpointerlist ( List *pList ) ;

	RING_API int ring_list_cpointercmp ( List *pList,List *pList2 ) ;
#endif
