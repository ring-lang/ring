/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_item_h
	#define ring_item_h
	/* Data */
	typedef struct Item {
		/* Data */
		union {
			struct String *pString  ;
			double dNumber  ;
			int iNumber  ;
			void *pPointer  ;
			struct List *pList  ;
			void (*pFunc)(void *) ;
			float fNumber  ;
		} data ;
		/* Item Type */
		unsigned int nType:3  ;
		/* The number type, 0 = Nothing , 1 = int , 2 = double */
		unsigned int nNumberFlag:2  ;
		/*
		**  what is the type of the object that the pointer refer to 
		**  Used when putting the item in the stack to refer to list or listitem 
		*/
		unsigned int nObjectType:2  ;
		/* Garbage Collector Data (Reference Counting) */
		unsigned int nGCReferenceCount: RING_VM_BITSFORREFCOUNT  ;
		void (*pGCFreeFunc)(void *,void *) ;
	} Item ;
	/* Constants */
	#define ITEMTYPE_NOTHING 0
	#define ITEMTYPE_STRING 1
	#define ITEMTYPE_NUMBER 2
	#define ITEMTYPE_POINTER 3
	#define ITEMTYPE_LIST 4
	#define ITEMTYPE_FUNCPOINTER 5
	#define ITEM_NUMBERFLAG_NOTHING 0
	#define ITEM_NUMBERFLAG_INT 1
	#define ITEM_NUMBERFLAG_DOUBLE 2
	#define ITEM_OBJTYPE_NOTHING 0
	/* Macro */
	#define ring_item_getstring(x) x->data.pString
	#define ring_item_getdouble(x) x->data.dNumber
	#define ring_item_getint(x) x->data.iNumber
	#define ring_item_getlist(x) x->data.pList
	#define ring_item_getpointer(x) x->data.pPointer
	#define ring_item_gettype(x) x->nType
	#define ring_itemarray_getint(pList,nIndex) ( pList[nIndex].data.iNumber )
	#define ring_itemarray_getpointer(pList,nIndex) ( pList[nIndex].data.pPointer )
	#define ring_itemarray_getdouble(pList,nIndex) pList[nIndex].data.dNumber
	#define ring_itemarray_getstringraw(pList,nIndex) ( pList[nIndex].data.pString )
	#define ring_itemarray_getstring(pList,nIndex) ring_string_get(pList[nIndex].data.pString )
	#define ring_itemarray_getstringsize(pList,nIndex) ring_string_size(pList[nIndex].data.pString )
	/* Check */
	#define ring_itemarray_isstring(pList,nIndex) (pList[nIndex].nType == ITEMTYPE_STRING)
	#define ring_itemarray_isnumber(pList,nIndex) (pList[nIndex].nType == ITEMTYPE_NUMBER)
	#define ring_itemarray_ispointer(pList,nIndex) (pList[nIndex].nType == ITEMTYPE_POINTER)
	#define ring_item_isstring(x) (x->nType == ITEMTYPE_STRING)
	#define ring_item_islist(x) (x->nType == ITEMTYPE_LIST)
	#define ring_item_isdouble(x) ( (x->nType == ITEMTYPE_NUMBER) && ( x->nNumberFlag == ITEM_NUMBERFLAG_DOUBLE ) )
	#define ring_item_incdouble(x) ++x->data.dNumber
	/* Functions */

	RING_API Item * ring_item_new_gc ( void *pState,unsigned int nItemType ) ;

	RING_API Item * ring_item_delete_gc ( void *pState,Item *pItem ) ;

	RING_API void ring_item_settype_gc ( void *pState,Item *pItem,unsigned int nItemType ) ;

	RING_API void ring_item_print ( Item *pItem ) ;

	RING_API void ring_item_deletecontent_gc ( void *pState,Item *pItem ) ;
	/*
	**  Functions to deal with array of items 
	**  int 
	*/

	RING_API void ring_itemarray_setint_gc ( void *pState,Item pList[], unsigned int nIndex ,int nNumber ) ;
	/* Pointers */

	RING_API void ring_itemarray_setpointer_gc ( void *pState,Item pList[], unsigned int nIndex ,void *pValue ) ;
	/* double */

	RING_API void ring_itemarray_setdouble_gc ( void *pState,Item pList[], unsigned int nIndex ,double nNumber ) ;
	/* String */

	RING_API void ring_itemarray_setstring_gc ( void *pState,Item pList[], unsigned int nIndex ,const char *cStr ) ;

	RING_API void ring_itemarray_setstring2_gc ( void *pState,Item pList[], unsigned int nIndex ,const char *cStr,int nStrSize ) ;
	/* Functions to deal with one item */

	RING_API void ring_item_setstring_gc ( void *pState,Item *pItem,const char *cStr ) ;

	RING_API void ring_item_setdouble_gc ( void *pState,Item *pItem,double x ) ;

	RING_API void ring_item_setpointer_gc ( void *pState,Item *pItem,void *pValue ) ;

	RING_API void ring_item_setint_gc ( void *pState,Item *pItem,int x ) ;

	RING_API void ring_item_setstring2_gc ( void *pState,Item *pItem,const char *cStr,int nStrSize ) ;

	RING_API void ring_item_init ( Item *pItem ) ;
	/* Functions without state pointer */

	RING_API Item * ring_item_new ( unsigned int nItemType ) ;

	RING_API Item * ring_item_delete ( Item *pItem ) ;

	RING_API void ring_item_settype ( Item *pItem,unsigned int nItemType ) ;

	RING_API void ring_item_deletecontent ( Item *pItem ) ;
	/*
	**  Functions to deal with array of items 
	**  int 
	*/

	RING_API void ring_itemarray_setint ( Item pList[], unsigned int nIndex ,int nNumber ) ;
	/* Pointers */

	RING_API void ring_itemarray_setpointer ( Item pList[], unsigned int nIndex ,void *pValue ) ;
	/* double */

	RING_API void ring_itemarray_setdouble ( Item pList[], unsigned int nIndex ,double nNumber ) ;
	/* String */

	RING_API void ring_itemarray_setstring ( Item pList[], unsigned int nIndex ,const char *cStr ) ;

	RING_API void ring_itemarray_setstring2 ( Item pList[], unsigned int nIndex ,const char *cStr,int nStrSize ) ;
	/* Functions to deal with one item */

	RING_API void ring_item_setstring ( Item *pItem,const char *cStr ) ;

	RING_API void ring_item_setdouble ( Item *pItem,double x ) ;

	RING_API void ring_item_setpointer ( Item *pItem,void *pValue ) ;

	RING_API void ring_item_setint ( Item *pItem,int x ) ;

	RING_API void ring_item_setstring2 ( Item *pItem,const char *cStr,int nStrSize ) ;
	/* Functions to deal with numbers (int/double) */

	RING_API double ring_item_getnumber ( Item *pItem ) ;
#endif
