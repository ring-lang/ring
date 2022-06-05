/*
**  Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
/* Load Functions */

void ring_vm_listfuncs_loadfunctions ( RingState *pRingState )
{
    /* Lists */
    RING_API_REGISTER("add",ring_vm_listfuncs_add);
    RING_API_REGISTER("del",ring_vm_listfuncs_del);
    RING_API_REGISTER("swap",ring_vm_listfuncs_swap);
    RING_API_REGISTER("list",ring_vm_listfuncs_list);
    RING_API_REGISTER("find",ring_vm_listfuncs_find);
    RING_API_REGISTER("min",ring_vm_listfuncs_min);
    RING_API_REGISTER("max",ring_vm_listfuncs_max);
    RING_API_REGISTER("insert",ring_vm_listfuncs_insert);
    RING_API_REGISTER("sort",ring_vm_listfuncs_sort);
    RING_API_REGISTER("reverse",ring_vm_listfuncs_reverse);
    RING_API_REGISTER("binarysearch",ring_vm_listfuncs_binarysearch);
    /* Instead of NewList() function from StdLib (Just to support Old Code until converting it to List() ) */
    RING_API_REGISTER("newlist",ring_vm_listfuncs_list);
}
/* Functions */

void ring_vm_listfuncs_add ( void *pPointer )
{
    List *pList,*pList2  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( RING_API_ISSTRING(2) ) {
            ring_list_addstring2_gc(pVM->pRingState,pList,RING_API_GETSTRING(2),RING_API_GETSTRINGSIZE(2));
            RING_API_RETSTRING2(RING_API_GETSTRING(2),RING_API_GETSTRINGSIZE(2));
        }
        else if ( RING_API_ISNUMBER(2) ) {
            ring_list_adddouble_gc(pVM->pRingState,pList,RING_API_GETNUMBER(2));
            RING_API_RETNUMBER(RING_API_GETNUMBER(2));
        }
        else if ( RING_API_ISLIST(2) ) {
            pList2 = RING_API_GETLIST(2) ;
            ring_vm_addlisttolist(pVM,pList2,pList);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_listfuncs_del ( void *pPointer )
{
    List *pList  ;
    double nNum1  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( RING_API_ISNUMBER(2) ) {
            nNum1 = RING_API_GETNUMBER(2) ;
            if ( ( nNum1 < 1 ) || ( nNum1 > ring_list_getsize(pList) ) ) {
                RING_API_ERROR("Error in second parameter, item number outside the list size range!");
                return ;
            }
            ring_list_deleteitem_gc(((VM *) pPointer)->pRingState,pList,nNum1);
        }
        else {
            RING_API_ERROR("Error in second parameter, Function requires number!");
            return ;
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_listfuncs_swap ( void *pPointer )
{
    List *pList  ;
    int nNum1,nNum2,nSize  ;
    if ( RING_API_PARACOUNT != 3 ) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( RING_API_ISNUMBER(2)  && RING_API_ISNUMBER(3) ) {
            nNum1 = (int) RING_API_GETNUMBER(2) ;
            nNum2 = (int) RING_API_GETNUMBER(3) ;
            nSize = ring_list_getsize(pList);
            if ( (nNum1 > 0) && (nNum2 > 0) && (nNum1!= nNum2) && (nNum1<= nSize) && (nNum2 <= nSize) ) {
                ring_list_swap(pList,nNum1, nNum2);
            }
            else {
                RING_API_ERROR(RING_API_BADPARARANGE);
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_listfuncs_list ( void *pPointer )
{
    List *pList, *pList2  ;
    int x,y,nSize,nSize2  ;
    Items *pItems  ;
    Item *pItem  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT == 1 ) {
        if ( RING_API_ISNUMBER(1) ) {
            nSize = RING_API_GETNUMBER(1) ;
            if ( nSize > 0 ) {
                pList = RING_API_NEWLIST ;
                /*
                **  Allocate Memory 
                **  We allocate an extra item (nSize+1) to avoid using the block address as the first item 
                **  Because we may delete the first item (And we need to avoid deleting the block too) 
                */
                pItems = (Items *) ring_calloc(nSize+1,sizeof(Items));
                pList->pItemsBlock = pItems ;
                ring_state_registerblock(pVM->pRingState,pItems+1,pItems+nSize);
                pItem = (Item *) ring_calloc(nSize+1,sizeof(Item));
                pList->pItemBlock = pItem ;
                ring_state_registerblock(pVM->pRingState,pItem+1,pItem+nSize);
                for ( x = 1 ; x <=nSize ; x++ ) {
                    /*
                    **  Add the Items 
                    **  Prepare the Item pointer 
                    */
                    pItems++ ;
                    pItem++ ;
                    /* Add Item */
                    if ( x > 1 ) {
                        pList->pLast->pNext = pItems ;
                        pItems->pPrev = pList->pLast ;
                        pList->pLast = pItems ;
                    }
                    else {
                        pList->pFirst = pItems ;
                        pList->pLast = pItems ;
                    }
                    /* Add Item Value */
                    pItems->pValue = pItem ;
                    pItem->nType = ITEMTYPE_NUMBER ;
                    pItem->data.dNumber = 0 ;
                    pItem->data.iNumber = 0 ;
                    pItem->NumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
                }
                /* Set the List Data */
                pList->nSize = nSize ;
                RING_API_RETLISTBYREF(pList);
                return ;
            }
        }
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
    else if ( RING_API_PARACOUNT == 2 ) {
        if ( RING_API_ISNUMBER(1) &&  RING_API_ISNUMBER(2) ) {
            nSize = RING_API_GETNUMBER(1) ;
            nSize2 = RING_API_GETNUMBER(2) ;
            if ( (nSize > 0) && (nSize2 > 0) ) {
                pList = RING_API_NEWLIST ;
                /* Allocate Memory */
                pItems = (Items *) ring_calloc((nSize*nSize2)+1,sizeof(Items));
                pList->pItemsBlock = pItems ;
                ring_state_registerblock(pVM->pRingState,pItems+1,pItems+(nSize*nSize2));
                pItem = (Item *) ring_calloc((nSize*nSize2)+1,sizeof(Item));
                pList->pItemBlock = pItem ;
                ring_state_registerblock(pVM->pRingState,pItem+1,pItem+(nSize*nSize2));
                for ( x = 1 ; x <=nSize ; x++ ) {
                    pList2 = ring_list_newlist(pList);
                    for ( y = 1 ; y <=nSize2 ; y++ ) {
                        /*
                        **  Add the Items 
                        **  Prepare the Item pointer 
                        */
                        pItems++ ;
                        pItem++ ;
                        /* Add Item */
                        if ( y > 1 ) {
                            pList2->pLast->pNext = pItems ;
                            pItems->pPrev = pList2->pLast ;
                            pList2->pLast = pItems ;
                        }
                        else {
                            pList2->pFirst = pItems ;
                            pList2->pLast = pItems ;
                        }
                        /* Add Item Value */
                        pItems->pValue = pItem ;
                        pItem->nType = ITEMTYPE_NUMBER ;
                        pItem->data.dNumber = 0 ;
                        pItem->data.iNumber = 0 ;
                        pItem->NumberFlag = ITEM_NUMBERFLAG_DOUBLE ;
                    }
                    /* Set the Sub List Data */
                    pList2->nSize = nSize2 ;
                }
                /* Set the List Data */
                pList->nNextItemAfterLastAccess = 0 ;
                pList->pLastItemLastAccess = NULL ;
                RING_API_RETLISTBYREF(pList);
                return ;
            }
        }
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
    else {
        RING_API_ERROR(RING_API_BADPARACOUNT);
    }
}
/*
**  Find() Usage Syntax 
**  Find(List,ItemValue) ----> Item Index 
**  Find(List,ItemValue,nColumn) ---> Item Index 
**  Find(List,ItemValue,nColumn,cProperty) ---> Item Index 
*/

void ring_vm_listfuncs_find ( void *pPointer )
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

void ring_vm_listfuncs_min ( void *pPointer )
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

void ring_vm_listfuncs_max ( void *pPointer )
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

void ring_vm_listfuncs_insert ( void *pPointer )
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

void ring_vm_listfuncs_sort ( void *pPointer )
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

void ring_vm_listfuncs_binarysearch ( void *pPointer )
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

void ring_vm_listfuncs_reverse ( void *pPointer )
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
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}
