/*
**  Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Header Files 
*/
#include "ring.h"

RING_API Item * ring_item_new_gc ( void *pState,int ItemType )
{
    Item *pItem  ;
    pItem = (Item *) ring_state_malloc(pState,sizeof(Item));
    /* Set Type */
    pItem->nType = ITEMTYPE_NOTHING ;
    /* Delete pointer information */
    pItem->data.pPointer = NULL ;
    pItem->nObjectType = 0 ;
    /* Delete number information */
    pItem->data.dNumber = 0 ;
    pItem->data.iNumber = 0 ;
    pItem->NumberFlag = ITEM_NUMBERFLAG_NOTHING ;
    /* Reference Count */
    ring_vm_gc_cleardata(pItem);
    ring_item_settype_gc(pState,pItem,ItemType);
    return pItem ;
}

RING_API Item * ring_item_delete_gc ( void *pState,Item *pItem )
{
    assert(pItem != NULL);
    ring_vm_gc_deleteitem_gc(pState,pItem);
    return NULL ;
}

RING_API void ring_item_print ( Item *pItem )
{
    int ItemType  ;
    assert(pItem != NULL);
    ItemType = pItem->nType ;
    switch ( ItemType ) {
        case ITEMTYPE_NOTHING :
            /* Work */
            break ;
        case ITEMTYPE_STRING :
            /* Work */
            ring_string_print(pItem->data.pString);
            break ;
        case ITEMTYPE_NUMBER :
            /* Work */
            if ( pItem->NumberFlag == ITEM_NUMBERFLAG_INT ) {
                printf( "%d\n ",pItem->data.iNumber ) ;
            }
            else {
                printf( "%f \n",pItem->data.dNumber ) ;
            }
            break ;
        case ITEMTYPE_POINTER :
            /* Work */
            printf( "%p",pItem->data.pPointer ) ;
            break ;
        case ITEMTYPE_LIST :
            /* Work */
            ring_list_print(pItem->data.pList);
            break ;
    }
}

RING_API void ring_item_content_delete_gc ( void *pState,Item *pItem )
{
    assert(pItem != NULL);
    switch ( pItem->nType ) {
        case ITEMTYPE_STRING :
            /* Work */
            pItem->data.pString = ring_string_delete_gc(pState,pItem->data.pString);
            break ;
        case ITEMTYPE_LIST :
            /* Work */
            pItem->data.pList = ring_list_delete_gc(pState,pItem->data.pList);
            break ;
    }
    /* Set Type */
    pItem->nType = ITEMTYPE_NOTHING ;
    /* Delete pointer information */
    pItem->data.pPointer = NULL ;
    pItem->nObjectType = 0 ;
    /* Delete number information */
    pItem->data.dNumber = 0 ;
    pItem->data.iNumber = 0 ;
    pItem->NumberFlag = ITEM_NUMBERFLAG_NOTHING ;
}

RING_API void ring_item_settype_gc ( void *pState,Item *pItem,int ItemType )
{
    assert(pItem != NULL);
    if ( (ItemType == ITEMTYPE_STRING) && (pItem->nType == ITEMTYPE_STRING) ) {
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
    ring_item_content_delete_gc(pState,pItem);
    switch ( ItemType ) {
        case ITEMTYPE_NOTHING :
            pItem->nType = ITEMTYPE_NOTHING ;
            break ;
        case ITEMTYPE_STRING :
            pItem->nType = ITEMTYPE_STRING ;
            pItem->data.pString = ring_string_new_gc(pState,"");
            break ;
        case ITEMTYPE_NUMBER :
            pItem->nType = ITEMTYPE_NUMBER ;
            pItem->data.dNumber = 0 ;
            pItem->data.iNumber = 0 ;
            break ;
        case ITEMTYPE_POINTER :
            pItem->nType = ITEMTYPE_POINTER ;
            pItem->data.pPointer = NULL ;
            pItem->nObjectType = 0 ;
            break ;
        case ITEMTYPE_LIST :
            pItem->nType = ITEMTYPE_LIST ;
            pItem->data.pList = ring_list_new_gc(pState,0);
            break ;
        case ITEMTYPE_FUNCPOINTER :
            pItem->nType = ITEMTYPE_FUNCPOINTER ;
            pItem->data.pFunc = NULL ;
            break ;
    }
}
/*
**  Functions to deal with array of items 
**  int 
*/

RING_API void ring_itemarray_setint_gc ( void *pState,Item pList[], int index ,int number )
{
    ring_item_settype_gc(pState,&pList[index],ITEMTYPE_NUMBER);
    pList[index].data.iNumber = number ;
    pList[index].NumberFlag = ITEM_NUMBERFLAG_INT ;
}
/* Pointers */

RING_API void ring_itemarray_setpointer_gc ( void *pState,Item pList[], int index ,void *pValue )
{
    ring_item_settype_gc(pState,&pList[index],ITEMTYPE_POINTER);
    pList[index].data.pPointer = pValue ;
    pList[index].nObjectType = 0 ;
}
/* double */

RING_API void ring_itemarray_setdouble_gc ( void *pState,Item pList[], int index ,double number )
{
    ring_item_settype_gc(pState,&pList[index],ITEMTYPE_NUMBER);
    pList[index].data.dNumber = number ;
    pList[index].NumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
}
/* String */

RING_API void ring_itemarray_setstring_gc ( void *pState,Item pList[], int index ,const char *str )
{
    ring_item_settype_gc(pState,&pList[index],ITEMTYPE_STRING);
    ring_string_set_gc(pState,pList[index].data.pString ,str);
}

RING_API void ring_itemarray_setstring2_gc ( void *pState,Item pList[], int index ,const char *str,int nStrSize )
{
    ring_item_settype_gc(pState,&pList[index],ITEMTYPE_STRING);
    ring_string_set2_gc(pState,pList[index].data.pString ,str,nStrSize);
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
    pItem->NumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
}

RING_API void ring_item_setpointer_gc ( void *pState,Item *pItem,void *pValue )
{
    ring_item_settype_gc(pState,pItem,ITEMTYPE_POINTER);
    pItem->data.pPointer = pValue ;
    pItem->nObjectType = 0 ;
}

RING_API void ring_item_setint_gc ( void *pState,Item *pItem,int x )
{
    ring_item_settype_gc(pState,pItem,ITEMTYPE_NUMBER);
    pItem->data.iNumber = x ;
    pItem->NumberFlag = ITEM_NUMBERFLAG_INT ;
}
/* Functions without state pointer */

RING_API Item * ring_item_new ( int ItemType )
{
    return ring_item_new_gc(NULL,ItemType) ;
}

RING_API Item * ring_item_delete ( Item *pItem )
{
    return ring_item_delete_gc(NULL,pItem) ;
}

RING_API void ring_item_settype ( Item *pItem,int ItemType )
{
    ring_item_settype_gc(NULL,pItem,ItemType);
}

RING_API void ring_item_content_delete ( Item *pItem )
{
    ring_item_content_delete_gc(NULL,pItem);
}
/*
**  Functions to deal with array of items 
**  int 
*/

RING_API void ring_itemarray_setint ( Item pList[], int index ,int number )
{
    ring_itemarray_setint_gc(NULL,pList,index,number);
}
/* Pointers */

RING_API void ring_itemarray_setpointer ( Item pList[], int index ,void *pValue )
{
    ring_itemarray_setpointer_gc(NULL,pList,index,pValue);
}
/* double */

RING_API void ring_itemarray_setdouble ( Item pList[], int index ,double number )
{
    ring_itemarray_setdouble_gc(NULL,pList,index,number);
}
/* String */

RING_API void ring_itemarray_setstring ( Item pList[], int index ,const char *str )
{
    ring_itemarray_setstring_gc(NULL,pList,index,str);
}

RING_API void ring_itemarray_setstring2 ( Item pList[], int index ,const char *str,int nStrSize )
{
    ring_itemarray_setstring2_gc(NULL,pList,index,str,nStrSize);
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
    if ( pItem->NumberFlag == ITEM_NUMBERFLAG_INT ) {
        return (double) pItem->data.iNumber ;
    }
    else {
        return pItem->data.dNumber ;
    }
}
