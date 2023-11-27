/*
**  Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> 
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
    RING_API_REGISTER("ref",ring_vm_listfuncs_reference);
    RING_API_REGISTER("reference",ring_vm_listfuncs_reference);
    RING_API_REGISTER("refcount",ring_vm_listfuncs_refcount);
    /* Instead of NewList() function from StdLib (Just to support Old Code until converting it to List() ) */
    RING_API_REGISTER("newlist",ring_vm_listfuncs_list);
    RING_API_REGISTER("updatelist",ring_vm_listfuncs_updatelist);
}
/* Functions */

void ring_vm_listfuncs_add ( void *pPointer )
{
    List *pList,*pList2  ;
    Item *pItem  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        /* Avoid Objects */
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
            return ;
        }
        /* Check the Range */
        if ( ring_list_getsize(pList) == UINT_MAX ) {
            RING_API_ERROR(RING_API_RANGEEXCEEDED);
            return ;
        }
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
            if ( ring_list_isref(pList2) ) {
                ring_list_insertlist(pList,ring_list_getsize(pList));
                pItem = ring_list_getitem(pList,ring_list_getsize(pList));
                ring_list_assignreftoitem_gc(pVM->pRingState,pList2,pItem);
            }
            else {
                ring_vm_addlisttolist(pVM,pList2,pList);
            }
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
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        /* Avoid Objects */
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
            return ;
        }
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
    double nNum1,nNum2  ;
    unsigned int nSize  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 3 ) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        /* Avoid Objects */
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
            return ;
        }
        if ( RING_API_ISNUMBER(2)  && RING_API_ISNUMBER(3) ) {
            nNum1 = RING_API_GETNUMBER(2) ;
            nNum2 = RING_API_GETNUMBER(3) ;
            nSize = ring_list_getsize(pList);
            if ( (nNum1 > 0) && (nNum2 > 0) && (nNum1!= nNum2) && (nNum1<= nSize) && (nNum2 <= nSize) ) {
                ring_list_swap(pList,(unsigned int) nNum1, (unsigned int) nNum2);
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
                pList = RING_API_NEWLISTUSINGBLOCKS1D(nSize) ;
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
                pList = RING_API_NEWLISTUSINGBLOCKS2D(nSize,nSize2) ;
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
    unsigned int nNum1, nColumn  ;
    List *pList  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( ! ( (RING_API_PARACOUNT >= 2) && (RING_API_PARACOUNT <= 4) ) ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        nNum1 = 0 ;
        pList = RING_API_GETLIST(1) ;
        /* Avoid Objects */
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
            return ;
        }
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
                        nNum1 = ring_list_findinlistofobjs(pList,RING_LISTOFOBJS_FINDSTRING,0.0,RING_API_GETSTRING(2),nColumn,RING_API_GETSTRING(4));
                    }
                    else if ( RING_API_ISNUMBER(2) ) {
                        nNum1 = ring_list_findinlistofobjs(pList,RING_LISTOFOBJS_FINDNUMBER,RING_API_GETNUMBER(2),"",nColumn,RING_API_GETSTRING(4));
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
    unsigned int x  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT == 1 ) {
        if ( RING_API_ISLIST(1) ) {
            pList = RING_API_GETLIST(1) ;
            /* Avoid Objects */
            if ( ring_vm_oop_isobject(pList) ) {
                ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
                return ;
            }
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
    unsigned int x  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT == 1 ) {
        if ( RING_API_ISLIST(1) ) {
            pList = RING_API_GETLIST(1) ;
            /* Avoid Objects */
            if ( ring_vm_oop_isobject(pList) ) {
                ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
                return ;
            }
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
    unsigned int nPos  ;
    double x  ;
    Item *pItem  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 3 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) && RING_API_ISNUMBER(2) ) {
        pList = RING_API_GETLIST(1) ;
        /* Avoid Objects */
        if ( ring_vm_oop_isobject(pList) ) {
            ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
            return ;
        }
        /* Check the Range */
        if ( ring_list_getsize(pList) == UINT_MAX ) {
            RING_API_ERROR(RING_API_RANGEEXCEEDED);
            return ;
        }
        x = RING_API_GETNUMBER(2) ;
        if ( (x < 0) || (x > ring_list_getsize(pList) ) ) {
            RING_API_ERROR(RING_VM_ERROR_INDEXOUTOFRANGE);
            return ;
        }
        nPos = (unsigned int) x ;
        if ( RING_API_ISSTRING(3) ) {
            ring_list_insertstring2(pList,nPos,RING_API_GETSTRING(3),RING_API_GETSTRINGSIZE(3));
        }
        else if ( RING_API_ISNUMBER(3) ) {
            ring_list_insertdouble(pList,nPos,RING_API_GETNUMBER(3));
        }
        else if ( RING_API_ISLIST(3) ) {
            pList2 = ring_list_insertlist(pList,nPos);
            pItem = ring_list_getitem(pList,nPos+1);
            if ( ring_list_isref(RING_API_GETLIST(3)) ) {
                ring_list_assignreftoitem_gc(pVM->pRingState,RING_API_GETLIST(3),pItem);
            }
            else {
                ring_vm_list_copy(pVM,pList2,RING_API_GETLIST(3));
                /* Update self object pointer */
                if ( ring_vm_oop_isobject(pList2) ) {
                    ring_vm_oop_updateselfpointer(pVM,pList2,RING_OBJTYPE_LISTITEM,pItem);
                }
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
/* Quicksort Algorithm */

void ring_vm_listfuncs_sort ( void *pPointer )
{
    List *pList, *pList2, *pList3  ;
    int nParaCount  ;
    unsigned int x, nPos, nColumn  ;
    char *cAttribute  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    nParaCount = RING_API_PARACOUNT ;
    if ( ! ( (nParaCount >= 1) && (nParaCount <= 3) ) ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_NEWLIST ;
        pList2 = RING_API_GETLIST(1);
        /* Avoid Objects */
        if ( ring_vm_oop_isobject(pList2) ) {
            ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
            return ;
        }
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
    int nParaCount  ;
    unsigned int x, nColumn  ;
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
    unsigned int x  ;
    Item *pItem  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_NEWLIST ;
        pList2 = RING_API_GETLIST(1) ;
        /* Avoid Objects */
        if ( ring_vm_oop_isobject(pList2) ) {
            ring_vm_error(pVM,RING_VM_ERROR_VARISNOTLIST);
            return ;
        }
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
                pItem = ring_list_getitem(pList,ring_list_getsize(pList));
                /* Update self object pointer */
                if ( ring_vm_oop_isobject(pList3) ) {
                    ring_vm_oop_updateselfpointer(pVM,pList3,RING_OBJTYPE_LISTITEM,pItem);
                }
            }
        }
        RING_API_RETLIST(pList);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_listfuncs_reference ( void *pPointer )
{
    List *pList  ;
    if ( RING_API_PARACOUNT == 1 ) {
        if ( RING_API_ISLIST(1) ) {
            pList = RING_API_GETLIST(1) ;
            RING_API_RETNEWREF(pList);
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
        return ;
    }
    RING_API_ERROR(RING_API_BADPARACOUNT);
}

void ring_vm_listfuncs_refcount ( void *pPointer )
{
    List *pList  ;
    if ( RING_API_PARACOUNT == 1 ) {
        if ( RING_API_ISLIST(1) ) {
            pList = RING_API_GETLIST(1) ;
            RING_API_RETNUMBER(ring_list_getrefcount(pList));
        }
        else {
            RING_API_RETNUMBER(1);
        }
        return ;
    }
    RING_API_ERROR(RING_API_BADPARACOUNT);
}
/* Updating many items in the list */

void ring_vm_listfuncs_updatelist ( void *pPointer )
{
    const char *cOperation  ;
    const char *cSelection  ;
    List *pList, *pSubList  ;
    int nOPCode,nRow,nCol,nStart,nEnd,iValue  ;
    int x  ;
    double nValue  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    /* Check Parameters */
    if ( (RING_API_PARACOUNT < 4) || (RING_API_PARACOUNT > 7) ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( ! ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) ) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return ;
    }
    /* Get Parameters */
    pList = RING_API_GETLIST(1) ;
    cOperation = RING_API_GETSTRING(2) ;
    cSelection = RING_API_GETSTRING(3) ;
    /* Set instruction values */
    nOPCode = 0 ;
    nRow = 0 ;
    nCol = 0 ;
    nStart = 0 ;
    nEnd = 0 ;
    /* Check Selection */
    if ( strcmp(cSelection,"row") == 0 ) {
        if ( RING_API_PARACOUNT == 5 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) ) {
                nOPCode = 1 ;
                nRow = (int) RING_API_GETNUMBER(4) ;
                nValue = RING_API_GETNUMBER(5) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"col") == 0 ) {
        if ( RING_API_PARACOUNT == 5 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) ) {
                nOPCode = 2 ;
                nCol = (int) RING_API_GETNUMBER(4) ;
                nValue = RING_API_GETNUMBER(5) ;
                nStart = 1 ;
                nEnd = ring_list_getsize(pList) ;
                iValue = (int) RING_API_GETNUMBER(5) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"rowcells") == 0 ) {
        if ( RING_API_PARACOUNT == 7 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) && RING_API_ISNUMBER(6)  && RING_API_ISNUMBER(7) ) {
                nOPCode = 3 ;
                nRow = (int) RING_API_GETNUMBER(4) ;
                nStart = (int) RING_API_GETNUMBER(5) ;
                nEnd = (int) RING_API_GETNUMBER(6) ;
                nValue = RING_API_GETNUMBER(7) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"colcells") == 0 ) {
        if ( RING_API_PARACOUNT == 7 ) {
            if ( RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5) && RING_API_ISNUMBER(6)  && RING_API_ISNUMBER(7) ) {
                nOPCode = 4 ;
                nCol = (int) RING_API_GETNUMBER(4) ;
                nStart = (int) RING_API_GETNUMBER(5) ;
                nEnd = (int) RING_API_GETNUMBER(6) ;
                nValue = RING_API_GETNUMBER(7) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    else if ( strcmp(cSelection,"items") == 0 ) {
        if ( RING_API_PARACOUNT == 4 ) {
            if ( RING_API_ISNUMBER(4) ) {
                nOPCode = 5 ;
                nValue = RING_API_GETNUMBER(4) ;
            }
            else {
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
        }
        else {
            RING_API_ERROR(RING_API_BADPARACOUNT);
            return ;
        }
    }
    /* Set the operation code */
    if ( strcmp(cOperation,"set") == 0 ) {
        nOPCode += 100 ;
    }
    else if ( strcmp(cOperation,"add") == 0 ) {
        nOPCode += 200 ;
    }
    else if ( strcmp(cOperation,"sub") == 0 ) {
        nOPCode += 300 ;
    }
    else if ( strcmp(cOperation,"mul") == 0 ) {
        nOPCode += 400 ;
    }
    else if ( strcmp(cOperation,"div") == 0 ) {
        nOPCode += 500 ;
    }
    else if ( strcmp(cOperation,"copy") == 0 ) {
        nOPCode += 600 ;
    }
    else if ( strcmp(cOperation,"sum") == 0 ) {
        nOPCode += 700 ;
    }
    /* Execute */
    switch ( nOPCode ) {
        /* Set */
        case 101 :
            /* Set Row */
            break ;
        case 102 :
            /* Set Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,nValue);
                        }
                    }
                }
            }
            break ;
        case 103 :
            /* Set Row Cells */
            break ;
        case 104 :
            /* Set Col Cells */
            break ;
        case 105 :
            /* Set Items */
            break ;
        /* Add */
        case 201 :
            /* Add to Row */
            break ;
        case 202 :
            /* Add to Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)+nValue);
                        }
                    }
                }
            }
            break ;
        case 203 :
            /* Add to Row Cells */
            break ;
        case 204 :
            /* Add to Col Cells */
            break ;
        case 205 :
            /* Add to Items */
            break ;
        /* Sub */
        case 301 :
            /* Sub from Row */
            break ;
        case 302 :
            /* Sub from Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)-nValue);
                        }
                    }
                }
            }
            break ;
        case 303 :
            /* Sub from Row Cells */
            break ;
        case 304 :
            /* Sub from Col Cells */
            break ;
        case 305 :
            /* Sub from Items */
            break ;
        /* Mul */
        case 401 :
            /* Mul Row */
            break ;
        case 402 :
            /* Mul Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)*nValue);
                        }
                    }
                }
            }
            break ;
        case 403 :
            /* Mul Row Cells */
            break ;
        case 404 :
            /* Mul Col Cells */
            break ;
        case 405 :
            /* Mul Items */
            break ;
        /* Div */
        case 501 :
            /* Div Row */
            break ;
        case 502 :
            /* Div Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( ring_list_getsize(pSubList) >= nCol ) {
                        if ( ring_list_isdouble(pSubList,nCol) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)/nValue);
                        }
                    }
                }
            }
            break ;
        case 503 :
            /* Div Row Cells */
            break ;
        case 504 :
            /* Div Col Cells */
            break ;
        case 505 :
            /* Div Items */
            break ;
        /* Copy */
        case 601 :
            /* Copy Row */
            break ;
        case 602 :
            /* Copy Col */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= nValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,nValue) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nValue,ring_list_getdouble(pSubList,nCol));
                        }
                    }
                }
            }
            break ;
        case 603 :
            /* Copy Row Cells */
            break ;
        case 604 :
            /* Copy Col Cells */
            break ;
        case 605 :
            /* Copy Items */
            break ;
        /* Sum (Using two rows/cols) */
        case 701 :
            /* Sum two rows */
            break ;
        case 702 :
            /* Sum two columns */
            for ( x = nStart ; x <= nEnd ; x++ ) {
                if ( ring_list_islist(pList,x) ) {
                    pSubList = ring_list_getlist(pList,x) ;
                    if ( (ring_list_getsize(pSubList) >= nCol) && (ring_list_getsize(pSubList) >= nValue) ) {
                        if ( ring_list_isdouble(pSubList,nCol) && ring_list_isdouble(pSubList,nValue) ) {
                            ring_list_setdouble_gc(pVM->pRingState,pSubList,nCol,ring_list_getdouble(pSubList,nCol)+ring_list_getdouble(pSubList,nValue));
                        }
                    }
                }
            }
            break ;
        case 703 :
            /* Sum Row Cells */
            break ;
        case 704 :
            /* Sum Col Cells */
            break ;
        case 705 :
            /* Sum Items */
            break ;
    }
}
