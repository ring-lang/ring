/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  List 
*/

RING_API List * ring_list_new_gc ( void *pState,int nSize )
{
    List *pList  ;
    pList = (List *) ring_state_malloc(pState,sizeof(List));
    return ring_list_new2_gc(pState,pList,nSize) ;
}

RING_API List * ring_list_new2_gc ( void *pState,List *pList,int nSize )
{
    int x  ;
    Items *pItems,*pItemsLast  ;
    pList->nSize = nSize ;
    if ( nSize > 0 ) {
        pItems = ring_items_new_gc(pState);
        pList->pFirst = pItems ;
        pItemsLast = pItems ;
        for ( x = 2 ; x <= nSize ; x++ ) {
            pItems = ring_items_new_gc(pState);
            if ( pItems == NULL ) {
                printf( "OUT OF MEMORY \n  " ) ;
                exit(0);
            }
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
    pList->nNextItemAfterLastAccess = 0 ;
    pList->pLastItemLastAccess = NULL ;
    pList->pItemsArray = NULL ;
    pList->pHashTable = NULL ;
    pList->pItemBlock = NULL ;
    pList->pItemsBlock = NULL ;
    pList->lCopyByRef = 0 ;
    return pList ;
}

RING_API List * ring_list_delete_gc ( void *pState,List *pList )
{
    /* Delete All Items */
    ring_list_deleteallitems_gc(pState,pList);
    ring_state_free(pState,pList);
    pList = NULL ;
    return pList ;
}

RING_API void ring_list_copy_gc ( void *pState,List *pNewList, List *pList )
{
    int x,nMax  ;
    List *pNewList2  ;
    assert(pList != NULL);
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

RING_API void ring_list_print ( List *pList )
{
    ring_list_print2(pList,2);
}

RING_API void ring_list_print2 ( List *pList,int nDecimals )
{
    int x,t,nSize  ;
    double y  ;
    const char *cStr  ;
    List *pList2  ;
    char cOptions[10]  ;
    char cString[100]  ;
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
                }
                else {
                    sprintf(cOptions , "%s%df" , "%.",nDecimals);
                    snprintf(cString , 100, cOptions , y);
                    printf("%s\n",cString);
                }
            }
            else if ( ring_list_isint(pList,x) ) {
                printf( "%d\n",ring_list_getint(pList,x) ) ;
            }
        }
        else if ( ring_list_islist(pList,x) ) {
            pList2 = ring_list_getlist(pList,x) ;
            if ( ring_vm_oop_isobject(pList2) ) {
                ring_vm_oop_printobj(NULL,pList2);
            }
            else {
                ring_list_print2(pList2,nDecimals);
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

RING_API void ring_list_deleteallitems_gc ( void *pState,List *pList )
{
    Items *pItems,*pItemsNext  ;
    pItems = pList->pFirst ;
    if ( pItems != NULL ) {
        pItemsNext = pItems ;
        /* Delete Items */
        while ( pItemsNext != NULL ) {
            pItemsNext = pItems->pNext ;
            ring_items_delete_gc(pState,pItems);
            pItems = pItemsNext ;
        }
    }
    pList->pFirst = NULL ;
    pList->pLast = NULL ;
    pList->pLastItemLastAccess = NULL ;
    pList->nSize = 0 ;
    pList->nNextItemAfterLastAccess = 0 ;
    /* Free Items Array */
    ring_list_deletearray_gc(pState,pList);
    /* Free HashTable */
    if ( pList->pHashTable != NULL ) {
        pList->pHashTable = ring_hashtable_delete_gc(pState,pList->pHashTable);
    }
    /* Delete Blocks (if we have allocated large block of memory) */
    if ( pList->pItemBlock != NULL ) {
        ring_state_unregisterblock(pState,pList->pItemBlock+1);
        ring_state_free(pState,pList->pItemBlock);
        pList->pItemBlock = NULL ;
    }
    if ( pList->pItemsBlock != NULL ) {
        ring_state_unregisterblock(pState,pList->pItemsBlock+1);
        ring_state_free(pState,pList->pItemsBlock);
        pList->pItemsBlock = NULL ;
    }
    pList->lCopyByRef = 0 ;
}

RING_API void ring_list_copy_tohighlevel_gc ( void *pState,List *pNewList, List *pList )
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
/* List Items */

RING_API void ring_list_newitem_gc ( void *pState,List *pList )
{
    Items *pItems  ;
    assert(pList != NULL);
    pItems = ring_items_new_gc(pState);
    if ( (pList->nSize) > 0 ) {
        pList->pLast->pNext = pItems ;
        pItems->pPrev = pList->pLast ;
        pList->pLast = pItems ;
    }
    else {
        pList->pFirst = pItems ;
        pList->pLast = pItems ;
    }
    pList->nSize = pList->nSize + 1 ;
    /* Refresh The Cache */
    pList->nNextItemAfterLastAccess = 0 ;
    pList->pLastItemLastAccess = NULL ;
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
            if ( pList->pLastItemLastAccess->pNext  != NULL ) {
                pList->pLastItemLastAccess = pList->pLastItemLastAccess->pNext ;
                pList->nNextItemAfterLastAccess++ ;
                return pList->pLastItemLastAccess->pValue ;
            }
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

RING_API void ring_list_deleteitem_gc ( void *pState,List *pList,int index )
{
    int x  ;
    Items *pItems,*pItemsPrev  ;
    assert(pList != NULL);
    /* Goto the Item */
    if ( index > 0 && ( ring_list_getsize(pList) > 0 ) && index <= ring_list_getsize(pList) ) {
        /* Quickly Get the Last Item */
        if ( index == ring_list_getsize(pList) ) {
            pItems = pList->pLast ;
            pItemsPrev = pItems->pPrev ;
        }
        /* Linear Search */
        else {
            pItems = pList->pFirst ;
            pItemsPrev = NULL ;
            for ( x = 1 ; x < index ; x++ ) {
                pItemsPrev = pItems ;
                pItems = pItems->pNext ;
            }
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

RING_API void ring_list_setint_gc ( void *pState,List *pList, int index ,int number )
{
    Item *pItem  ;
    assert(pList != NULL);
    pItem = ring_list_getitem(pList,index);
    ring_item_settype_gc(pState,pItem,ITEMTYPE_NUMBER);
    pItem->data.iNumber = number ;
    pItem->NumberFlag = ITEM_NUMBERFLAG_INT ;
}

RING_API void ring_list_addint_gc ( void *pState,List *pList,int x )
{
    assert(pList != NULL);
    ring_list_newitem_gc(pState,pList);
    ring_list_setint_gc(pState,pList,ring_list_getsize(pList),x);
}
/* Pointers */

RING_API void ring_list_setpointer_gc ( void *pState,List *pList, int index ,void *pValue )
{
    Item *pItem  ;
    assert(pList != NULL);
    pItem = ring_list_getitem(pList,index);
    ring_item_settype_gc(pState,pItem,ITEMTYPE_POINTER);
    pItem->data.pPointer = pValue ;
}

RING_API void ring_list_addpointer_gc ( void *pState,List *pList,void *pValue )
{
    assert(pList != NULL);
    ring_list_newitem_gc(pState,pList);
    ring_list_setpointer_gc(pState,pList,ring_list_getsize(pList),pValue);
}
/* double */

RING_API void ring_list_setdouble_gc ( void *pState,List *pList, int index ,double number )
{
    Item *pItem  ;
    assert(pList != NULL);
    pItem = ring_list_getitem(pList,index);
    ring_item_settype_gc(pState,pItem,ITEMTYPE_NUMBER);
    pItem->data.dNumber = number ;
    pItem->NumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
}

RING_API void ring_list_adddouble_gc ( void *pState,List *pList,double x )
{
    assert(pList != NULL);
    ring_list_newitem_gc(pState,pList);
    ring_list_setdouble_gc(pState,pList,ring_list_getsize(pList),x);
}
/* String */

RING_API void ring_list_setstring_gc ( void *pState,List *pList, int index ,const char *str )
{
    Item *pItem  ;
    String *pString  ;
    assert(pList != NULL);
    pItem = ring_list_getitem(pList,index);
    ring_item_settype_gc(pState,pItem,ITEMTYPE_STRING);
    pString = ring_item_getstring(pItem);
    ring_string_set_gc(pState,pString,str);
}

RING_API void ring_list_setstring2_gc ( void *pState,List *pList, int index ,const char *str,int nStrSize )
{
    Item *pItem  ;
    String *pString  ;
    assert(pList != NULL);
    pItem = ring_list_getitem(pList,index);
    ring_item_settype_gc(pState,pItem,ITEMTYPE_STRING);
    pString = ring_item_getstring(pItem);
    ring_string_set2_gc(pState,pString,str,nStrSize);
}

RING_API void ring_list_addstring_gc ( void *pState,List *pList,const char *str )
{
    assert(pList != NULL);
    ring_list_newitem_gc(pState,pList);
    ring_list_setstring_gc(pState,pList,ring_list_getsize(pList),str);
}

RING_API void ring_list_addstring2_gc ( void *pState,List *pList,const char *str,int nStrSize )
{
    assert(pList != NULL);
    ring_list_newitem_gc(pState,pList);
    ring_list_setstring2_gc(pState,pList,ring_list_getsize(pList),str,nStrSize);
}
/* List */

RING_API List * ring_list_newlist_gc ( void *pState,List *pList )
{
    Item *pItem  ;
    List *pList2  ;
    assert(pList != NULL);
    ring_list_newitem_gc(pState,pList);
    pItem = ring_list_getitem(pList,ring_list_getsize(pList));
    ring_item_settype_gc(pState,pItem,ITEMTYPE_LIST);
    pList2 = ring_item_getlist(pItem);
    return pList2 ;
}

RING_API void ring_list_setlist_gc ( void *pState,List *pList, int index )
{
    Item *pItem  ;
    assert(pList != NULL);
    pItem = ring_list_getitem(pList,index);
    ring_item_settype_gc(pState,pItem,ITEMTYPE_LIST);
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
/* Function Pointers */

RING_API void ring_list_setfuncpointer_gc ( void *pState,List *pList, int index ,void (*pFunc)(void *) )
{
    Item *pItem  ;
    assert(pList != NULL);
    pItem = ring_list_getitem(pList,index);
    ring_item_settype_gc(pState,pItem,ITEMTYPE_FUNCPOINTER);
    pItem->data.pFunc = pFunc ;
}

RING_API void ring_list_addfuncpointer_gc ( void *pState,List *pList,void (*pFunc)(void *) )
{
    assert(pList != NULL);
    ring_list_newitem_gc(pState,pList);
    ring_list_setfuncpointer_gc(pState,pList,ring_list_getsize(pList),pFunc);
}

RING_API int ring_list_isfuncpointer ( List *pList, int index )
{
    if ( ring_list_gettype(pList,index) == ITEMTYPE_FUNCPOINTER ) {
        return 1 ;
    }
    return 0 ;
}
/*
**  Insert Items 
**  When you insert item, it will be inserted after nPos 
*/

RING_API void ring_list_insertitem_gc ( void *pState,List *pList,int x )
{
    Items *pItems  ;
    assert(pList != NULL);
    if ( ( x < 0 ) || ( x > ring_list_getsize(pList) ) ) {
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

RING_API void ring_list_insertint_gc ( void *pState,List *pList,int nPos,int x )
{
    assert(pList != NULL);
    ring_list_insertitem_gc(pState,pList,nPos);
    ring_list_setint_gc(pState,pList,nPos+1,x);
}

RING_API void ring_list_insertdouble_gc ( void *pState,List *pList,int nPos,double x )
{
    assert(pList != NULL);
    ring_list_insertitem_gc(pState,pList,nPos);
    ring_list_setdouble_gc(pState,pList,nPos+1,x);
}

RING_API void ring_list_insertpointer_gc ( void *pState,List *pList,int nPos,void *pValue )
{
    assert(pList != NULL);
    ring_list_insertitem_gc(pState,pList,nPos);
    ring_list_setpointer_gc(pState,pList,nPos+1,pValue);
}

RING_API void ring_list_insertstring_gc ( void *pState,List *pList,int nPos,const char *str )
{
    assert(pList != NULL);
    ring_list_insertitem_gc(pState,pList,nPos);
    ring_list_setstring_gc(pState,pList,nPos+1,str);
}

RING_API void ring_list_insertstring2_gc ( void *pState,List *pList,int nPos,const char *str,int nStrSize )
{
    assert(pList != NULL);
    ring_list_insertitem_gc(pState,pList,nPos);
    ring_list_setstring2_gc(pState,pList,nPos+1,str,nStrSize);
}

RING_API void ring_list_insertfuncpointer_gc ( void *pState,List *pList,int nPos,void (*pFunc)(void *) )
{
    assert(pList != NULL);
    ring_list_insertitem_gc(pState,pList,nPos);
    ring_list_setfuncpointer_gc(pState,pList,nPos+1,pFunc);
}

RING_API List * ring_list_insertlist_gc ( void *pState,List *pList,int nPos )
{
    Item *pItem  ;
    List *pList2  ;
    assert(pList != NULL);
    ring_list_insertitem_gc(pState,pList,nPos);
    pItem = ring_list_getitem(pList,nPos+1);
    ring_item_settype_gc(pState,pItem,ITEMTYPE_LIST);
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

RING_API int ring_list_deliteminsidelist_gc ( void *pState,List *pList,Item *pItem )
{
    int x  ;
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
                if ( ring_list_getsize(pList2)< nColumn ) {
                    return -1 ;
                }
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

RING_API int ring_list_findinlistofobjs ( List *pList,int nType,double nNum1,const char *str,int nColumn,char *cAttribute )
{
    int x,nCount,nPos  ;
    List *pList2  ;
    assert(pList != NULL);
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
            if ( ring_vm_oop_isobject(pList2) == 0 ) {
                continue ;
            }
            nPos = ring_list_findstring(ring_list_getlist(pList2,RING_OBJECT_OBJECTDATA),cAttribute,RING_VAR_NAME);
            if ( nPos == 0 ) {
                return -1 ;
            }
            pList2 = ring_list_getlist(pList2,RING_OBJECT_OBJECTDATA) ;
            pList2 = ring_list_getlist(pList2,nPos) ;
            if ( nType  == RING_VM_LISTOFOBJS_FINDSTRING ) {
                if ( strcmp(str,ring_list_getstring(pList2,RING_VAR_VALUE)) == 0 ) {
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

RING_API int ring_list_findcpointer ( List *pList,List *pValue,int nColumn )
{
    int x,nCount  ;
    List *pList2, *pList3  ;
    assert(pList != NULL);
    nCount = ring_list_getsize(pList);
    /* Find Item */
    if ( nCount > 0 ) {
        if ( nColumn == 0 ) {
            for ( x = 1 ; x <= nCount ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pList2 = ring_list_getlist(pList,x);
                    if ( ring_vm_api_iscpointerlist(pList2) ) {
                        if ( ring_vm_api_cpointercmp(pList2,pValue) ) {
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
                    if ( ring_vm_api_cpointercmp(pList3,pValue) ) {
                        return x ;
                    }
                }
            }
        }
    }
    return 0 ;
}
/* Sort (QuickSort) and Binary Search */

RING_API void ring_list_sortnum ( List *pList,int left,int right,int nColumn,const char *cAttribute )
{
    int x,y,mid  ;
    double midvalue  ;
    x = left ;
    y = right ;
    mid = (x+y)/2 ;
    midvalue = ring_list_getdoublecolumn(pList,mid,nColumn,cAttribute);
    while ( x <= y ) {
        while ( ring_list_getdoublecolumn(pList,x,nColumn,cAttribute) < midvalue ) {
            x++ ;
        }
        while ( ring_list_getdoublecolumn(pList,y,nColumn,cAttribute) > midvalue ) {
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

RING_API void ring_list_sortstr_gc ( void *pState,List *pList,int left,int right,int nColumn,const char *cAttribute )
{
    int x,y,mid  ;
    String *midvalue  ;
    x = left ;
    y = right ;
    mid = (x+y)/2 ;
    midvalue = ring_string_new_gc(pState,ring_list_getstringcolumn(pList,mid,nColumn,cAttribute));
    while ( x <= y ) {
        while ( strcmp(ring_list_getstringcolumn(pList,x,nColumn,cAttribute),ring_string_get(midvalue)) < 0 ) {
            x++ ;
        }
        while ( strcmp(ring_list_getstringcolumn(pList,y,nColumn,cAttribute),ring_string_get(midvalue)) > 0 ) {
            y-- ;
        }
        if ( x <= y ) {
            ring_list_swap(pList,x,y);
            x++ ;
            y-- ;
        }
    }
    ring_string_delete_gc(pState,midvalue);
    if ( left < y ) {
        ring_list_sortstr_gc(pState,pList, left, y,nColumn,cAttribute);
    }
    if ( y < right ) {
        ring_list_sortstr_gc(pState,pList, x, right, nColumn,cAttribute);
    }
}

RING_API int ring_list_binarysearchnum ( List *pList,double nNum1,int nColumn,const char *cAttribute )
{
    int nFirst,nMiddle,nLast  ;
    nFirst = 1 ;
    nLast = ring_list_getsize(pList) ;
    while ( nFirst <= nLast ) {
        nMiddle = (nFirst+nLast)/2 ;
        if ( ring_list_getdoublecolumn(pList,nMiddle,nColumn,cAttribute) == nNum1 ) {
            return nMiddle ;
        }
        else if ( ring_list_getdoublecolumn(pList,nMiddle,nColumn,cAttribute) < nNum1 ) {
            nFirst = nMiddle + 1 ;
        }
        else {
            nLast = nMiddle - 1 ;
        }
    }
    return 0 ;
}

RING_API int ring_list_binarysearchstr ( List *pList,const char *cFind,int nColumn,const char *cAttribute )
{
    int nFirst,nMiddle,nLast,nRes  ;
    nFirst = 1 ;
    nLast = ring_list_getsize(pList) ;
    while ( nFirst <= nLast ) {
        nMiddle = (nFirst+nLast)/2 ;
        nRes = strcmp(ring_list_getstringcolumn(pList,nMiddle,nColumn,cAttribute) ,cFind) ;
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

RING_API double ring_list_getdoublecolumn ( List *pList,int nIndex,int nColumn,const char *cAttribute )
{
    int nPos  ;
    if ( nColumn == 0 ) {
        return ring_list_getdouble(pList,nIndex) ;
    }
    else {
        if ( strcmp(cAttribute,"") == 0 ) {
            return ring_list_getdouble(ring_list_getlist(pList,nIndex),nColumn) ;
        }
        else {
            pList = ring_list_getlist(pList,nIndex);
            if ( nColumn > 1 ) {
                pList = ring_list_getlist(pList,nColumn);
            }
            if ( ring_vm_oop_isobject(pList) ) {
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

RING_API char * ring_list_getstringcolumn ( List *pList,int nIndex,int nColumn,const char *cAttribute )
{
    int nPos  ;
    static char nullstring[] = "" ;
    if ( nColumn == 0 ) {
        return ring_list_getstring(pList,nIndex) ;
    }
    else {
        if ( strcmp(cAttribute,"") == 0 ) {
            return ring_list_getstring(ring_list_getlist(pList,nIndex),nColumn) ;
        }
        else {
            pList = ring_list_getlist(pList,nIndex);
            if ( nColumn > 1 ) {
                pList = ring_list_getlist(pList,nColumn);
            }
            if ( ring_vm_oop_isobject(pList) ) {
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
/* List Items to Array */

RING_API void ring_list_genarray_gc ( void *pState,List *pList )
{
    int x  ;
    Item **pArray  ;
    if ( ring_list_getsize(pList) == 0 ) {
        return ;
    }
    if ( pList->pItemsArray != NULL ) {
        ring_state_free(pState,pList->pItemsArray);
    }
    /*
    **  Here we save the pointer in pArray and not in pList->pItemsArray 
    **  Because we will fill the array with items pointers using ring_list_getitem() 
    **  And ring_list_getitem() check for using pList->pItemsArray 
    */
    pArray = (Item **) ring_state_malloc(pState,ring_list_getsize(pList) * sizeof(Item *));
    for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        pArray[x-1] = ring_list_getitem(pList,x);
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
    int x  ;
    if ( pList->pHashTable != NULL ) {
        pList->pHashTable = ring_hashtable_delete_gc(pState,pList->pHashTable);
    }
    pList->pHashTable = ring_hashtable_new_gc(pState);
    for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        ring_hashtable_newnumber_gc(pState,pList->pHashTable,ring_list_getstring(pList,x),x);
    }
}

RING_API void ring_list_genhashtable2_gc ( void *pState,List *pList )
{
    int x  ;
    List *pList2  ;
    /* This Func. Take list of lists , the first item of the sub list is a string (key) */
    if ( pList->pHashTable != NULL ) {
        pList->pHashTable = ring_hashtable_delete_gc(pState,pList->pHashTable);
    }
    pList->pHashTable = ring_hashtable_new_gc(pState);
    for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        pList2 = ring_list_getlist(pList,x);
        ring_hashtable_newpointer_gc(pState,pList->pHashTable,ring_list_getstring(pList2,1),pList2);
    }
}
/* Copy list by reference */

RING_API void ring_list_clear ( List *pList )
{
    pList->pFirst = NULL ;
    pList->pLast = NULL ;
    pList->nSize = 0 ;
    pList->nNextItemAfterLastAccess = 0 ;
    pList->pLastItemLastAccess = NULL ;
    pList->pItemsArray = NULL ;
    pList->pHashTable = NULL ;
    pList->pItemBlock = NULL ;
    pList->pItemsBlock = NULL ;
}
/* Define functions without State Pointer */

RING_API List * ring_list_new ( int nSize )
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

RING_API void ring_list_deleteitem ( List *pList,int index )
{
    ring_list_deleteitem_gc(NULL,pList,index);
}
/* int */

RING_API void ring_list_setint ( List *pList, int index ,int number )
{
    ring_list_setint_gc(NULL,pList,index,number);
}

RING_API void ring_list_addint ( List *pList,int x )
{
    ring_list_addint_gc(NULL,pList,x);
}
/* Pointers */

RING_API void ring_list_setpointer ( List *pList, int index ,void *pValue )
{
    ring_list_setpointer_gc(NULL,pList,index,pValue);
}

RING_API void ring_list_addpointer ( List *pList,void *pValue )
{
    ring_list_addpointer_gc(NULL,pList,pValue);
}
/* Function Pointers */

RING_API void ring_list_setfuncpointer ( List *pList, int index ,void (*pFunc)(void *) )
{
    ring_list_setfuncpointer_gc(NULL,pList,index,pFunc);
}

RING_API void ring_list_addfuncpointer ( List *pList,void (*pFunc)(void *) )
{
    ring_list_addfuncpointer_gc(NULL,pList,pFunc);
}
/* double */

RING_API void ring_list_setdouble ( List *pList, int index ,double number )
{
    ring_list_setdouble_gc(NULL,pList,index,number);
}

RING_API void ring_list_adddouble ( List *pList,double x )
{
    ring_list_adddouble_gc(NULL,pList,x);
}
/* String */

RING_API void ring_list_setstring ( List *pList, int index ,const char *str )
{
    ring_list_setstring_gc(NULL,pList,index,str);
}

RING_API void ring_list_setstring2 ( List *pList, int index ,const char *str,int nStrSize )
{
    ring_list_setstring2_gc(NULL,pList,index,str,nStrSize);
}

RING_API void ring_list_addstring ( List *pList,const char *str )
{
    ring_list_addstring_gc(NULL,pList,str);
}

RING_API void ring_list_addstring2 ( List *pList,const char *str,int nStrSize )
{
    ring_list_addstring2_gc(NULL,pList,str,nStrSize);
}
/* List */

RING_API List * ring_list_newlist ( List *pList )
{
    return ring_list_newlist_gc(NULL,pList) ;
}

RING_API void ring_list_setlist ( List *pList, int index )
{
    ring_list_setlist_gc(NULL,pList,index);
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

RING_API void ring_list_insertitem ( List *pList,int x )
{
    ring_list_insertitem_gc(NULL,pList,x);
}

RING_API void ring_list_insertint ( List *pList,int nPos,int x )
{
    ring_list_insertint_gc(NULL,pList,nPos,x);
}

RING_API void ring_list_insertdouble ( List *pList,int nPos,double x )
{
    ring_list_insertdouble_gc(NULL,pList,nPos,x);
}

RING_API void ring_list_insertpointer ( List *pList,int nPos,void *pValue )
{
    ring_list_insertpointer_gc(NULL,pList,nPos,pValue);
}

RING_API void ring_list_insertstring ( List *pList,int nPos,const char *str )
{
    ring_list_insertstring_gc(NULL,pList,nPos,str);
}

RING_API void ring_list_insertstring2 ( List *pList,int nPos,const char *str,int nStrSize )
{
    ring_list_insertstring2_gc(NULL,pList,nPos,str,nStrSize);
}

RING_API void ring_list_insertfuncpointer ( List *pList,int nPos,void (*pFunc)(void *) )
{
    ring_list_insertfuncpointer_gc(NULL,pList,nPos,pFunc);
}

RING_API List * ring_list_insertlist ( List *pList,int nPos )
{
    return ring_list_insertlist_gc(NULL,pList,nPos) ;
}

RING_API void ring_list_sortstr ( List *pList,int left,int right,int nColumn,const char *cAttribute )
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
    List TempList  ;
    /* Get data from pList1 to TempList */
    memcpy(&TempList,pList1,sizeof(List));
    /* Get data from pList2 to pList1 */
    memcpy(pList1,pList2,sizeof(List));
    /* Get data from TempList to pList2 */
    memcpy(pList2,&TempList,sizeof(List));
}
