/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_list_h
    #define ring_list_h
    /* Data */
    typedef struct List {
        struct Items *pFirst  ;
        struct Items *pLast  ;
        int nSize  ;
        int nNextItemAfterLastAccess  ;
        struct Items *pLastItemLastAccess  ;
        struct Item **pItemsArray  ;
        struct HashTable *pHashTable  ;
        struct Item *pItemBlock  ;
        struct Items *pItemsBlock  ;
        char lCopyByRef  ;
    } List ;
    /* Constants */
    #define RING_VM_LISTOFOBJS_FINDSTRING 1
    #define RING_VM_LISTOFOBJS_FINDNUMBER 0
    /* Macro */
    #define ring_list_isdouble(pList,index) ( ring_list_getitem(pList,index)->NumberFlag == ITEM_NUMBERFLAG_DOUBLE)
    #define ring_list_isint(pList,index) ( ring_list_getitem(pList,index)->NumberFlag == ITEM_NUMBERFLAG_INT )
    #define ring_list_deletelastitem(x) ring_list_deleteitem(x,ring_list_getsize(x))
    #define ring_list_gethashtable(x) (x->pHashTable)
    #define ring_list_getint(pList,index) ( ring_list_getitem(pList,index)->data.iNumber )
    #define ring_list_getpointer(pList,index) ( ring_list_getitem(pList,index)->data.pPointer )
    #define ring_list_getfuncpointer(pList,index) ( ring_list_getitem(pList,index)->data.pFunc )
    #define ring_list_callfuncpointer(pList,index,x) ( ring_list_getitem(pList,index)->data.pFunc(x) )
    #define ring_list_getdouble(pList,index) ring_list_getitem(pList,index)->data.dNumber
    #define ring_list_getstring(pList,index) ( ring_string_get(ring_item_getstring(ring_list_getitem(pList,index))) )
    #define ring_list_getstringobject(pList,index) ( ring_item_getstring(ring_list_getitem(pList,index)) )
    #define ring_list_getstringsize(pList,index) ( ring_string_size(ring_item_getstring(ring_list_getitem(pList,index))) )
    #define ring_list_getsize(x) (x->nSize)
    #define ring_list_deletelastitem_gc(s,x) ring_list_deleteitem_gc(s,x,ring_list_getsize(x))
    /*
    **  Functions 
    **  Main List Functions 
    */

    RING_API List * ring_list_new_gc ( void *pState,int nSize ) ;

    RING_API List * ring_list_new2_gc ( void *pState,List *pList,int nSize ) ;

    RING_API void ring_list_newitem_gc ( void *pState,List *pList ) ;

    RING_API Item * ring_list_getitem ( List *pList,int index ) ;

    RING_API List * ring_list_delete_gc ( void *pState,List *pList ) ;

    RING_API void ring_list_deleteitem_gc ( void *pState,List *pList,int index ) ;

    RING_API void ring_list_print ( List *pList ) ;

    RING_API void ring_list_print2 ( List *pList,int nDecimals ) ;

    RING_API int ring_list_gettype ( List *pList, int index ) ;
    /* int */

    RING_API void ring_list_setint_gc ( void *pState,List *pList, int index ,int number ) ;

    RING_API void ring_list_addint_gc ( void *pState,List *pList,int x ) ;
    /* Pointers */

    RING_API void ring_list_setpointer_gc ( void *pState,List *pList, int index ,void *pValue ) ;

    RING_API void ring_list_addpointer_gc ( void *pState,List *pList,void *pValue ) ;
    /* Function Pointers */

    RING_API void ring_list_setfuncpointer_gc ( void *pState,List *pList, int index ,void (*pFunc)(void *) ) ;

    RING_API void ring_list_addfuncpointer_gc ( void *pState,List *pList,void (*pFunc)(void *) ) ;

    RING_API int ring_list_isfuncpointer ( List *pList, int index ) ;
    /* double */

    RING_API void ring_list_setdouble_gc ( void *pState,List *pList, int index ,double number ) ;

    RING_API void ring_list_adddouble_gc ( void *pState,List *pList,double x ) ;
    /* String */

    RING_API void ring_list_setstring_gc ( void *pState,List *pList, int index ,const char *str ) ;

    RING_API void ring_list_setstring2_gc ( void *pState,List *pList, int index ,const char *str,int nStrSize ) ;

    RING_API void ring_list_addstring_gc ( void *pState,List *pList,const char *str ) ;

    RING_API void ring_list_addstring2_gc ( void *pState,List *pList,const char *str,int nStrSize ) ;
    /* List */

    RING_API List * ring_list_newlist_gc ( void *pState,List *pList ) ;

    RING_API void ring_list_setlist_gc ( void *pState,List *pList, int index ) ;

    RING_API List * ring_list_getlist ( List *pList, int index ) ;

    RING_API void ring_list_copy_gc ( void *pState,List *pNewList, List *pList ) ;

    RING_API int ring_list_isnumber ( List *pList, int index ) ;

    RING_API int ring_list_isstring ( List *pList, int index ) ;

    RING_API int ring_list_islist ( List *pList, int index ) ;

    RING_API int ring_list_ispointer ( List *pList, int index ) ;

    RING_API void ring_list_deleteallitems_gc ( void *pState,List *pList ) ;
    /* Insert Items */

    RING_API void ring_list_insertitem_gc ( void *pState,List *pList,int x ) ;

    RING_API void ring_list_insertint_gc ( void *pState,List *pList,int nPos,int x ) ;

    RING_API void ring_list_insertdouble_gc ( void *pState,List *pList,int nPos,double x ) ;

    RING_API void ring_list_insertpointer_gc ( void *pState,List *pList,int nPos,void *pValue ) ;

    RING_API void ring_list_insertstring_gc ( void *pState,List *pList,int nPos,const char *str ) ;

    RING_API void ring_list_insertstring2_gc ( void *pState,List *pList,int nPos,const char *str,int nStrSize ) ;

    RING_API void ring_list_insertfuncpointer_gc ( void *pState,List *pList,int nPos,void (*pFunc)(void *) ) ;

    RING_API List * ring_list_insertlist_gc ( void *pState,List *pList,int nPos ) ;
    /* Is item inside list, support nested Lists */

    RING_API int ring_list_isiteminsidelist ( List *pList,Item *pItem ) ;
    /* Linear Search */

    RING_API int ring_list_findstring ( List *pList,const char *str,int nColumn ) ;

    RING_API int ring_list_finddouble ( List *pList,double nNum1,int nColumn ) ;

    RING_API int ring_list_findpointer ( List *pList,void *pPointer ) ;

    RING_API int ring_list_findinlistofobjs ( List *pList,int nType,double nNum1,const char *str,int nColumn,char *cAttribute ) ;

    RING_API int ring_list_findcpointer ( List *pList,List *pValue,int nColumn ) ;
    /* Sort and Binary Search */

    RING_API void ring_list_sortnum ( List *pList,int left,int right,int nColumn,const char *cAttribute ) ;

    RING_API void ring_list_sortstr_gc ( void *pState,List *pList,int left,int right,int nColumn,const char *cAttribute ) ;

    RING_API int ring_list_binarysearchnum ( List *pList,double nNum1,int nColumn,const char *cAttribute ) ;

    RING_API int ring_list_binarysearchstr ( List *pList,const char *cFind,int nColumn,const char *cAttribute ) ;

    RING_API void ring_list_swap ( List *pList,int x,int y ) ;

    RING_API double ring_list_getdoublecolumn ( List *pList,int nIndex,int nColumn,const char *cAttribute ) ;

    RING_API char * ring_list_getstringcolumn ( List *pList,int nIndex,int nColumn,const char *cAttribute ) ;
    /* List Items to Array */

    RING_API void ring_list_genarray_gc ( void *pState,List *pList ) ;

    RING_API void ring_list_deletearray_gc ( void *pState,List *pList ) ;
    /* List Items to HashTable */

    RING_API void ring_list_genhashtable_gc ( void *pState,List *pList ) ;

    RING_API void ring_list_genhashtable2_gc ( void *pState,List *pList ) ;

    RING_API void ring_list_clear ( List *pList ) ;
    /* Delete item from list using the item pointer */

    RING_API int ring_list_deliteminsidelist_gc ( void *pState,List *pList,Item *pItem ) ;

    RING_API void ring_list_swaptwolists ( List *pList1, List *pList2 ) ;

    RING_API void ring_list_copy_tohighlevel_gc ( void *pState,List *pNewList, List *pList ) ;
    /* Define functions without RingState * */

    RING_API List * ring_list_new ( int nSize ) ;

    RING_API void ring_list_genarray ( List *pList ) ;

    RING_API List * ring_list_delete ( List *pList ) ;

    RING_API void ring_list_deletearray ( List *pList ) ;

    RING_API void ring_list_newitem ( List *pList ) ;

    RING_API void ring_list_deleteitem ( List *pList,int index ) ;
    /* int */

    RING_API void ring_list_setint ( List *pList, int index ,int number ) ;

    RING_API void ring_list_addint ( List *pList,int x ) ;
    /* Pointers */

    RING_API void ring_list_setpointer ( List *pList, int index ,void *pValue ) ;

    RING_API void ring_list_addpointer ( List *pList,void *pValue ) ;
    /* Function Pointers */

    RING_API void ring_list_setfuncpointer ( List *pList, int index ,void (*pFunc)(void *) ) ;

    RING_API void ring_list_addfuncpointer ( List *pList,void (*pFunc)(void *) ) ;
    /* double */

    RING_API void ring_list_setdouble ( List *pList, int index ,double number ) ;

    RING_API void ring_list_adddouble ( List *pList,double x ) ;
    /* String */

    RING_API void ring_list_setstring ( List *pList, int index ,const char *str ) ;

    RING_API void ring_list_setstring2 ( List *pList, int index ,const char *str,int nStrSize ) ;

    RING_API void ring_list_addstring ( List *pList,const char *str ) ;

    RING_API void ring_list_addstring2 ( List *pList,const char *str,int nStrSize ) ;
    /* List */

    RING_API List * ring_list_newlist ( List *pList ) ;

    RING_API void ring_list_setlist ( List *pList, int index ) ;

    RING_API void ring_list_copy ( List *pNewList, List *pList ) ;

    RING_API void ring_list_deleteallitems ( List *pList ) ;
    /* Insert Items */

    RING_API void ring_list_insertitem ( List *pList,int x ) ;

    RING_API void ring_list_insertint ( List *pList,int nPos,int x ) ;

    RING_API void ring_list_insertdouble ( List *pList,int nPos,double x ) ;

    RING_API void ring_list_insertpointer ( List *pList,int nPos,void *pValue ) ;

    RING_API void ring_list_insertstring ( List *pList,int nPos,const char *str ) ;

    RING_API void ring_list_insertstring2 ( List *pList,int nPos,const char *str,int nStrSize ) ;

    RING_API void ring_list_insertfuncpointer ( List *pList,int nPos,void (*pFunc)(void *) ) ;

    RING_API List * ring_list_insertlist ( List *pList,int nPos ) ;

    RING_API void ring_list_sortstr ( List *pList,int left,int right,int nColumn,const char *cAttribute ) ;
    /* List Items to HashTable */

    RING_API void ring_list_genhashtable ( List *pList ) ;

    RING_API void ring_list_genhashtable2 ( List *pList ) ;
#endif
