/*
**  Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
/* Functions */

void ring_vm_refmeta_loadfunctions ( RingState *pRingState )
{
    /* Functions */
    RING_API_REGISTER("locals",ring_vm_refmeta_locals);
    RING_API_REGISTER("globals",ring_vm_refmeta_globals);
    RING_API_REGISTER("functions",ring_vm_refmeta_functions);
    RING_API_REGISTER("cfunctions",ring_vm_refmeta_cfunctions);
    RING_API_REGISTER("islocal",ring_vm_refmeta_islocal);
    RING_API_REGISTER("isglobal",ring_vm_refmeta_isglobal);
    RING_API_REGISTER("isfunction",ring_vm_refmeta_isfunction);
    RING_API_REGISTER("iscfunction",ring_vm_refmeta_iscfunction);
    /* OOP */
    RING_API_REGISTER("packages",ring_vm_refmeta_packages);
    RING_API_REGISTER("ispackage",ring_vm_refmeta_ispackage);
    RING_API_REGISTER("classes",ring_vm_refmeta_classes);
    RING_API_REGISTER("isclass",ring_vm_refmeta_isclass);
    RING_API_REGISTER("packageclasses",ring_vm_refmeta_packageclasses);
    RING_API_REGISTER("ispackageclass",ring_vm_refmeta_ispackageclass);
    RING_API_REGISTER("classname",ring_vm_refmeta_classname);
    RING_API_REGISTER("objectid",ring_vm_refmeta_objectid);
    RING_API_REGISTER("attributes",ring_vm_refmeta_attributes);
    RING_API_REGISTER("methods",ring_vm_refmeta_methods);
    RING_API_REGISTER("isattribute",ring_vm_refmeta_isattribute);
    RING_API_REGISTER("ismethod",ring_vm_refmeta_ismethod);
    RING_API_REGISTER("isprivateattribute",ring_vm_refmeta_isprivateattribute);
    RING_API_REGISTER("isprivatemethod",ring_vm_refmeta_isprivatemethod);
    RING_API_REGISTER("addattribute",ring_vm_refmeta_addattribute);
    RING_API_REGISTER("addmethod",ring_vm_refmeta_addmethod);
    RING_API_REGISTER("getattribute",ring_vm_refmeta_getattribute);
    RING_API_REGISTER("setattribute",ring_vm_refmeta_setattribute);
    RING_API_REGISTER("mergemethods",ring_vm_refmeta_mergemethods);
    RING_API_REGISTER("packagename",ring_vm_refmeta_packagename);
    /* VM */
    RING_API_REGISTER("ringvm_fileslist",ring_vm_refmeta_ringvmfileslist);
    RING_API_REGISTER("ringvm_calllist",ring_vm_refmeta_ringvmcalllist);
    RING_API_REGISTER("ringvm_memorylist",ring_vm_refmeta_ringvmmemorylist);
    RING_API_REGISTER("ringvm_functionslist",ring_vm_refmeta_ringvmfunctionslist);
    RING_API_REGISTER("ringvm_classeslist",ring_vm_refmeta_ringvmclasseslist);
    RING_API_REGISTER("ringvm_packageslist",ring_vm_refmeta_ringvmpackageslist);
    RING_API_REGISTER("ringvm_cfunctionslist",ring_vm_refmeta_ringvmcfunctionslist);
    RING_API_REGISTER("ringvm_settrace",ring_vm_refmeta_ringvmsettrace);
    RING_API_REGISTER("ringvm_tracedata",ring_vm_refmeta_ringvmtracedata);
    RING_API_REGISTER("ringvm_traceevent",ring_vm_refmeta_ringvmtraceevent);
    RING_API_REGISTER("ringvm_tracefunc",ring_vm_refmeta_ringvmtracefunc);
    RING_API_REGISTER("ringvm_scopescount",ring_vm_refmeta_ringvmscopescount);
    RING_API_REGISTER("ringvm_evalinscope",ring_vm_refmeta_ringvmevalinscope);
    RING_API_REGISTER("ringvm_passerror",ring_vm_refmeta_ringvmpasserror);
    RING_API_REGISTER("ringvm_hideerrormsg",ring_vm_refmeta_ringvmhideerrormsg);
    RING_API_REGISTER("ringvm_callfunc",ring_vm_refmeta_ringvmcallfunc);
    RING_API_REGISTER("ringvm_info",ring_vm_refmeta_ringvminfo);
    RING_API_REGISTER("ringvm_genarray",ring_vm_refmeta_ringvmgenarray);
    RING_API_REGISTER("ringvm_codelist",ring_vm_refmeta_ringvmcodelist);
}
/* Functions */

void ring_vm_refmeta_locals ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2, *pList3  ;
    pVM = (VM *) pPointer ;
    /* We use -1 to skip the current scope of the locals() function */
    pList = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)-1) ;
    pList2 = RING_API_NEWLIST ;
    for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        pList3 = ring_list_getlist(pList,x);
        ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList2,ring_list_getstring(pList3,RING_VAR_NAME));
    }
    RING_API_RETLIST(pList2);
}

void ring_vm_refmeta_globals ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2, *pList3  ;
    pVM = (VM *) pPointer ;
    pList = ring_vm_getglobalscope(pVM) ;
    pList2 = RING_API_NEWLIST ;
    /* We avoid internal global variables like true, false */
    for ( x = RING_VM_INTERNALGLOBALSCOUNT + 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        pList3 = ring_list_getlist(pList,x);
        ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList2,ring_list_getstring(pList3,RING_VAR_NAME));
    }
    RING_API_RETLIST(pList2);
}

void ring_vm_refmeta_functions ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    pVM = (VM *) pPointer ;
    pList = RING_API_NEWLIST ;
    for ( x = 1 ; x <= ring_list_getsize(pVM->pFunctionsMap) ; x++ ) {
        pList2 = ring_list_getlist(pVM->pFunctionsMap,x);
        ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,ring_list_getstring(pList2,RING_FUNCMAP_NAME));
    }
    RING_API_RETLIST(pList);
}

void ring_vm_refmeta_cfunctions ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    pVM = (VM *) pPointer ;
    pList = RING_API_NEWLIST ;
    for ( x = 1 ; x <= ring_list_getsize(pVM->pCFunctionsList) ; x++ ) {
        pList2 = ring_list_getlist(pVM->pCFunctionsList,x);
        ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,ring_list_getstring(pList2,RING_FUNCMAP_NAME));
    }
    RING_API_RETLIST(pList);
}

void ring_vm_refmeta_islocal ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        pVM = (VM *) pPointer ;
        cStr = ring_string_lower(RING_API_GETSTRING(1)) ;
        /* We use -1 to skip the current scope of the locals() function */
        pList = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)-1) ;
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            pList2 = ring_list_getlist(pList,x);
            if ( strcmp(ring_list_getstring(pList2,RING_VAR_NAME),cStr) == 0 ) {
                RING_API_RETNUMBER(1);
                return ;
            }
        }
        RING_API_RETNUMBER(0);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_isglobal ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        pVM = (VM *) pPointer ;
        cStr = ring_string_lower(RING_API_GETSTRING(1)) ;
        pList = ring_vm_getglobalscope(pVM) ;
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            pList2 = ring_list_getlist(pList,x);
            if ( strcmp(ring_list_getstring(pList2,RING_VAR_NAME),cStr) == 0 ) {
                RING_API_RETNUMBER(1);
                return ;
            }
        }
        RING_API_RETNUMBER(0);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_isfunction ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        pVM = (VM *) pPointer ;
        cStr = ring_string_lower(RING_API_GETSTRING(1)) ;
        pList = pVM->pFunctionsMap ;
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            pList2 = ring_list_getlist(pList,x);
            if ( strcmp(ring_list_getstring(pList2,RING_FUNCMAP_NAME),cStr) == 0 ) {
                RING_API_RETNUMBER(1);
                return ;
            }
        }
        RING_API_RETNUMBER(0);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_iscfunction ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        pVM = (VM *) pPointer ;
        cStr = ring_string_lower(RING_API_GETSTRING(1)) ;
        pList = pVM->pCFunctionsList ;
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            pList2 = ring_list_getlist(pList,x);
            if ( strcmp(ring_list_getstring(pList2,RING_FUNCMAP_NAME),cStr) == 0 ) {
                RING_API_RETNUMBER(1);
                return ;
            }
        }
        RING_API_RETNUMBER(0);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}
/* OOP */

void ring_vm_refmeta_packages ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    pVM = (VM *) pPointer ;
    pList = RING_API_NEWLIST ;
    for ( x = 1 ; x <= ring_list_getsize(pVM->pPackagesMap) ; x++ ) {
        pList2 = ring_list_getlist(pVM->pPackagesMap,x);
        ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,ring_list_getstring(pList2,RING_PACKAGENAME));
    }
    RING_API_RETLIST(pList);
}

void ring_vm_refmeta_ispackage ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        pVM = (VM *) pPointer ;
        cStr = ring_string_lower(RING_API_GETSTRING(1)) ;
        pList = pVM->pPackagesMap ;
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            pList2 = ring_list_getlist(pList,x);
            if ( strcmp(ring_list_getstring(pList2,RING_PACKAGENAME),cStr) == 0 ) {
                RING_API_RETNUMBER(1);
                return ;
            }
        }
        RING_API_RETNUMBER(0);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_classes ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    pVM = (VM *) pPointer ;
    pList = RING_API_NEWLIST ;
    for ( x = 1 ; x <= ring_list_getsize(pVM->pClassesMap) ; x++ ) {
        pList2 = ring_list_getlist(pVM->pClassesMap,x);
        ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,ring_list_getstring(pList2,RING_CLASSMAP_CLASSNAME));
    }
    RING_API_RETLIST(pList);
}

void ring_vm_refmeta_isclass ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        pVM = (VM *) pPointer ;
        cStr = ring_string_lower(RING_API_GETSTRING(1)) ;
        pList = pVM->pClassesMap ;
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            pList2 = ring_list_getlist(pList,x);
            if ( strcmp(ring_list_getstring(pList2,RING_CLASSMAP_CLASSNAME),cStr) == 0 ) {
                RING_API_RETNUMBER(1);
                return ;
            }
        }
        RING_API_RETNUMBER(0);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_packageclasses ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2, *pList3  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_GETSTRING(1) ) {
        pVM = (VM *) pPointer ;
        cStr = RING_API_GETSTRING(1) ;
        ring_string_lower(cStr);
        pList = pVM->pPackagesMap ;
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            pList2 = ring_list_getlist(pList,x);
            if ( strcmp(ring_list_getstring(pList2,RING_PACKAGENAME),cStr) == 0 ) {
                pList3 = RING_API_NEWLIST ;
                pList2 = ring_list_getlist(pList2,RING_CLASSESLIST) ;
                /* We can use the variable x for the loop again because we have return */
                for ( x = 1 ; x <= ring_list_getsize(pList2) ; x++ ) {
                    ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList3,ring_list_getstring(ring_list_getlist(pList2,x),RING_CLASSMAP_CLASSNAME));
                }
                RING_API_RETLIST(pList3);
                return ;
            }
        }
        RING_API_RETNUMBER(0);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_ispackageclass ( void *pPointer )
{
    VM *pVM  ;
    int x  ;
    List *pList, *pList2  ;
    char *cStr, *cStr2  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) &&  RING_API_ISSTRING(2) ) {
        pVM = (VM *) pPointer ;
        cStr = ring_string_lower(RING_API_GETSTRING(1)) ;
        cStr2 = ring_string_lower(RING_API_GETSTRING(2)) ;
        pList = pVM->pPackagesMap ;
        for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
            pList2 = ring_list_getlist(pList,x);
            if ( strcmp(ring_list_getstring(pList2,RING_PACKAGENAME),cStr) == 0 ) {
                pList2 = ring_list_getlist(pList2,RING_CLASSESLIST) ;
                /* We can use the variable x for the loop again because we have return */
                for ( x = 1 ; x <= ring_list_getsize(pList2) ; x++ ) {
                    if ( strcmp(ring_list_getstring(ring_list_getlist(pList2,x),RING_CLASSMAP_CLASSNAME),cStr2)==0 ) {
                        RING_API_RETNUMBER(1);
                        return ;
                    }
                }
                RING_API_RETNUMBER(0);
                return ;
            }
        }
        RING_API_RETNUMBER(0);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_classname ( void *pPointer )
{
    List *pList  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            cStr = ring_list_getstring((List *) ring_list_getpointer(pList,RING_OBJECT_CLASSPOINTER),RING_CLASSMAP_CLASSNAME);
            RING_API_RETSTRING(cStr);
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_objectid ( void *pPointer )
{
    List *pList  ;
    char cStr[100]  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            sprintf( cStr , "%p" , (void *) pList ) ;
            RING_API_RETSTRING(cStr);
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_attributes ( void *pPointer )
{
    List *pList, *pList2  ;
    int x  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA);
            pList2 = RING_API_NEWLIST ;
            for ( x = 3 ; x <= ring_list_getsize(pList) ; x++ ) {
                ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList2,ring_list_getstring(ring_list_getlist(pList,x),RING_VAR_NAME));
            }
            RING_API_RETLIST(pList2);
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_methods ( void *pPointer )
{
    List *pList, *pList2  ;
    int x  ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            pList = (List *) ring_list_getpointer(pList,RING_OBJECT_CLASSPOINTER);
            pList = ring_list_getlist(pList,RING_CLASSMAP_METHODSLIST);
            pList2 = RING_API_NEWLIST ;
            for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList2,ring_list_getstring(ring_list_getlist(pList,x),RING_FUNCMAP_NAME));
            }
            RING_API_RETLIST(pList2);
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_isattribute ( void *pPointer )
{
    List *pList  ;
    int x  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            cStr = ring_string_lower(RING_API_GETSTRING(2)) ;
            pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA);
            for ( x = 3 ; x <= ring_list_getsize(pList) ; x++ ) {
                if ( strcmp(cStr,ring_list_getstring(ring_list_getlist(pList,x),RING_VAR_NAME))==0 ) {
                    RING_API_RETNUMBER(1);
                    return ;
                }
            }
            RING_API_RETNUMBER(0);
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_ismethod ( void *pPointer )
{
    List *pList  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) == 0 ) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return ;
        }
        if ( RING_API_ISSTRING(2) ) {
            cStr = ring_string_lower(RING_API_GETSTRING(2)) ;
            RING_API_RETNUMBER(ring_vm_oop_ismethod((VM *) pPointer,pList,cStr));
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_isprivateattribute ( void *pPointer )
{
    List *pList  ;
    int x  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            cStr = ring_string_lower(RING_API_GETSTRING(2)) ;
            pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA);
            for ( x = 3 ; x <= ring_list_getsize(pList) ; x++ ) {
                if ( strcmp(cStr,ring_list_getstring(ring_list_getlist(pList,x),RING_VAR_NAME))==0 ) {
                    if ( ring_list_getint(ring_list_getlist(pList,x),RING_VAR_PRIVATEFLAG) == 1 ) {
                        RING_API_RETNUMBER(1);
                    }
                    else {
                        RING_API_RETNUMBER(0);
                    }
                    return ;
                }
            }
            RING_API_RETNUMBER(0);
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_isprivatemethod ( void *pPointer )
{
    List *pList  ;
    int x  ;
    char *cStr  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) == 0 ) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return ;
        }
        if ( RING_API_ISSTRING(2) ) {
            cStr = ring_string_lower(RING_API_GETSTRING(2)) ;
            x = ring_vm_oop_ismethod((VM *) pPointer,pList,cStr) ;
            if ( x==2 ) {
                RING_API_RETNUMBER(1);
            }
            else {
                RING_API_RETNUMBER(0);
            }
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_addattribute ( void *pPointer )
{
    List *pList, *pList2  ;
    char *cStr  ;
    int x  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA);
            ((VM *) pPointer)->nInClassRegion++ ;
            if ( RING_API_ISSTRING(2) ) {
                cStr = RING_API_GETSTRING(2) ;
                ring_string_lower(cStr);
                /* Create Variable List */
                ring_vm_newvar2((VM *)pPointer,cStr,pList);
            }
            else if ( RING_API_ISLIST(2) ) {
                pList2 = RING_API_GETLIST(2) ;
                for ( x = 1 ; x <= ring_list_getsize(pList2) ; x++ ) {
                    if ( ring_list_isstring(pList2,x) ) {
                        cStr = ring_list_getstring(pList2,x);
                        ring_string_lower(cStr);
                        /* Create Variable List */
                        ring_vm_newvar2((VM *)pPointer,cStr,pList);
                    }
                }
            }
            else {
                ((VM *) pPointer)->nInClassRegion-- ;
                RING_API_ERROR(RING_API_BADPARATYPE);
                return ;
            }
            ((VM *) pPointer)->nInClassRegion-- ;
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_addmethod ( void *pPointer )
{
    List *pList, *pList2, *pList3  ;
    char *cStr  ;
    int x  ;
    VM *pVM  ;
    /* Parameters : Object, MethodName, Anonymous Function */
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 3 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            pList = (List *) ring_list_getlist(pList,RING_OBJECT_CLASSPOINTER);
            pList = (List *) ring_list_getlist(pList,RING_CLASSMAP_METHODSLIST);
            cStr = RING_API_GETSTRING(3);
            ring_string_lower(cStr);
            for ( x = 1 ; x <= ring_list_getsize(pVM->pFunctionsMap) ; x++ ) {
                pList2 = ring_list_getlist(pVM->pFunctionsMap,x);
                if ( strcmp(ring_list_getstring(pList2,RING_FUNCMAP_NAME),cStr) == 0 ) {
                    /* Add new list to the class methods list */
                    pList3 = ring_list_newlist_gc(((VM *) pPointer)->pRingState,pList);
                    /* Copy function to class methods */
                    ring_list_copy_gc(pVM->pRingState,pList3,pList2);
                    /* Set the Function Name */
                    ring_list_setstring_gc(((VM *) pPointer)->pRingState,pList3,RING_FUNCMAP_NAME,ring_string_lower(RING_API_GETSTRING(2)));
                    /* Refresh the HashTable */
                    ring_list_genhashtable2(pList);
                    RING_API_RETNUMBER(1);
                    return ;
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
    RING_API_RETNUMBER(0);
}

void ring_vm_refmeta_getattribute ( void *pPointer )
{
    List *pList  ;
    char *cStr  ;
    int x  ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA);
            cStr = RING_API_GETSTRING(2) ;
            ring_string_lower(cStr);
            for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                if ( strcmp(ring_list_getstring(ring_list_getlist(pList,x),RING_VAR_NAME),cStr) == 0 ) {
                    pList = ring_list_getlist(pList,x) ;
                    if ( ring_list_isnumber(pList,RING_VAR_VALUE) ) {
                        RING_API_RETNUMBER(ring_list_getdouble(pList,RING_VAR_VALUE));
                    }
                    else if ( ring_list_isstring(pList,RING_VAR_VALUE) ) {
                        RING_API_RETSTRING2(ring_list_getstring(pList,RING_VAR_VALUE),ring_list_getstringsize(pList,RING_VAR_VALUE));
                    }
                    else if ( ring_list_islist(pList,RING_VAR_VALUE) ) {
                        RING_API_RETLIST(ring_list_getlist(pList,RING_VAR_VALUE));
                    }
                    return ;
                }
            }
            RING_API_ERROR("Error : Property is not found!");
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_setattribute ( void *pPointer )
{
    List *pList  ;
    char *cStr  ;
    int x  ;
    if ( RING_API_PARACOUNT != 3 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) && RING_API_ISSTRING(2) ) {
        pList = RING_API_GETLIST(1) ;
        if ( ring_vm_oop_isobject(pList) ) {
            pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA);
            cStr = RING_API_GETSTRING(2) ;
            ring_string_lower(cStr);
            for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
                if ( strcmp(ring_list_getstring(ring_list_getlist(pList,x),RING_VAR_NAME),cStr) == 0 ) {
                    pList = ring_list_getlist(pList,x) ;
                    if ( RING_API_ISNUMBER(3) ) {
                        ring_list_setdouble_gc(((VM *) pPointer)->pRingState,pList,RING_VAR_VALUE,RING_API_GETNUMBER(3));
                    }
                    else if ( RING_API_ISSTRING(3) ) {
                        ring_list_setstring2_gc(((VM *) pPointer)->pRingState,pList,RING_VAR_VALUE,RING_API_GETSTRING(3),RING_API_GETSTRINGSIZE(3));
                    }
                    else if ( RING_API_ISLIST(3) ) {
                        ring_list_setlist_gc(((VM *) pPointer)->pRingState,pList,RING_VAR_VALUE);
                        pList = ring_list_getlist(pList,RING_VAR_VALUE);
                        ring_list_deleteallitems_gc(((VM *) pPointer)->pRingState,pList);
                        ring_list_copy_gc(((VM *) pPointer)->pRingState,pList,RING_API_GETLIST(3));
                    }
                    return ;
                }
            }
            RING_API_ERROR("Error : Property is not found!");
        }
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_mergemethods ( void *pPointer )
{
    int x  ;
    List *pList, *pList2, *pList3  ;
    VM *pVM  ;
    char *cStr, *cStr2  ;
    /*
    **  We copy class methods from class to another class 
    **  First Parameter = Dest Class Name, Second Para = Source Class Name 
    **  The Source Class is expected to be without Parent Class and Without Attributes 
    */
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) ) {
        cStr = RING_API_GETSTRING(1) ;
        cStr2 = RING_API_GETSTRING(2) ;
        ring_string_lower(cStr);
        ring_string_lower(cStr2);
        pVM = (VM *) pPointer ;
        /* Get the Dest Class Methods List */
        pList2 = NULL ;
        for ( x = 1 ; x <= ring_list_getsize(pVM->pClassesMap) ; x++ ) {
            pList = ring_list_getlist(pVM->pClassesMap,x) ;
            if ( strcmp(ring_list_getstring(pList,RING_CLASSMAP_CLASSNAME),cStr) == 0 ) {
                /* Check if the class is imported from a Package */
                if ( ring_list_getsize(pList) == RING_CLASSMAP_IMPORTEDCLASSSIZE ) {
                    pList = ring_list_getlist(pList,RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE);
                }
                pList2 = ring_list_getlist(pList,RING_CLASSMAP_METHODSLIST) ;
                break ;
            }
        }
        if ( pList2 == NULL ) {
            RING_API_ERROR("Error, Can't find the dest class!");
            return ;
        }
        /* Get the Source Class Methods List */
        pList3 = NULL ;
        for ( x = 1 ; x <= ring_list_getsize(pVM->pClassesMap) ; x++ ) {
            pList = ring_list_getlist(pVM->pClassesMap,x) ;
            if ( strcmp(ring_list_getstring(pList,RING_CLASSMAP_CLASSNAME),cStr2) == 0 ) {
                /* Check if the class is imported from a Package */
                if ( ring_list_getsize(pList) == RING_CLASSMAP_IMPORTEDCLASSSIZE ) {
                    pList = ring_list_getlist(pList,RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE);
                }
                pList3 = ring_list_getlist(pList,RING_CLASSMAP_METHODSLIST) ;
                break ;
            }
        }
        if ( pList3 == NULL ) {
            RING_API_ERROR("Error, Can't find the source class!");
            return ;
        }
        /* Copy Methods from Source to Dest */
        ring_list_copy_gc(pVM->pRingState,pList2,pList3);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_packagename ( void *pPointer )
{
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 0 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    RING_API_RETSTRING(ring_string_get(pVM->pPackageName));
}
/* VM */

void ring_vm_refmeta_ringvmfileslist ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pRingState->pRingFilesList);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_refmeta_ringvmcalllist ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pFuncCallList);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_refmeta_ringvmmemorylist ( void *pPointer )
{
    VM *pVM  ;
    List *pList, *pList2  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(((VM *) pPointer)->pRingState,0) ;
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pMem);
    pList2 = RING_API_NEWLIST ;
    ring_list_copy_gc(pVM->pRingState,pList2,pList);
    ring_list_delete_gc(((VM *) pPointer)->pRingState,pList);
    RING_API_RETLIST(pList2);
}

void ring_vm_refmeta_ringvmfunctionslist ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pFunctionsMap);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_refmeta_ringvmclasseslist ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pClassesMap);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_refmeta_ringvmpackageslist ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pPackagesMap);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_refmeta_ringvmcfunctionslist ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pCFunctionsList);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_refmeta_ringvmsettrace ( void *pPointer )
{
    VM *pVM  ;
    char *cStr  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        cStr = RING_API_GETSTRING(1) ;
        if ( strcmp(cStr,"") == 0 ) {
            pVM->lTrace = 0 ;
            ring_string_set_gc(((VM *) pPointer)->pRingState,pVM->pTrace,"");
        }
        else {
            pVM->lTrace = 1 ;
            ring_string_set_gc(((VM *) pPointer)->pRingState,pVM->pTrace,cStr);
        }
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_ringvmtracedata ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pTraceData);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_refmeta_ringvmtraceevent ( void *pPointer )
{
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    RING_API_RETNUMBER(pVM->nTraceEvent);
}

void ring_vm_refmeta_ringvmtracefunc ( void *pPointer )
{
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    RING_API_RETSTRING(ring_string_get(pVM->pTrace));
}

void ring_vm_refmeta_ringvmscopescount ( void *pPointer )
{
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    /* We uses -1 to avoid adding the current scope of this function */
    RING_API_RETNUMBER(ring_list_getsize(pVM->pMem) - 1);
}

void ring_vm_refmeta_ringvmevalinscope ( void *pPointer )
{
    VM *pVM  ;
    List *pActiveMem,*pState  ;
    const char *cStr  ;
    int nScope,nSize  ;
    Items *pLastItem  ;
    Items *pNextItem  ;
    pVM = (VM *) pPointer ;
    pNextItem = NULL ;
    pLastItem = NULL ;
    if ( RING_API_PARACOUNT != 2 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISNUMBER(1) && RING_API_ISSTRING(2) ) {
        /* We must get cStr before we change the pVM->pActiveMem */
        nScope = (int) RING_API_GETNUMBER(1) ;
        cStr = RING_API_GETSTRING(2) ;
        pActiveMem = pVM->pActiveMem ;
        pVM->pActiveMem = ring_list_getlist(pVM->pMem,nScope) ;
        pVM->nActiveScopeID++ ;
        /* Prepare the current scope */
        ring_list_deletearray_gc(pVM->pRingState,pVM->pMem);
        nSize = pVM->pMem->nSize ;
        pLastItem = pVM->pMem->pLast ;
        pVM->pMem->pLastItemLastAccess = NULL ;
        pVM->pMem->nNextItemAfterLastAccess = 0 ;
        /* When we get the item, we will have a value for pVM->pMem->pLastItemLastAccess */
        ring_list_getitem(pVM->pMem,nScope);
        if ( pVM->pMem->pLastItemLastAccess != NULL ) {
            pNextItem = pVM->pMem->pLastItemLastAccess->pNext ;
            pVM->pMem->nSize = nScope ;
            pVM->pMem->pLast = pVM->pMem->pLastItemLastAccess ;
            pVM->pMem->pLast->pNext = NULL ;
        }
        ring_list_adddouble_gc(pVM->pRingState,pVM->aScopeID,pVM->nActiveScopeID);
        pVM->nEvalInScope++ ;
        /* Save State */
        pState = ring_list_new_gc(((VM *) pPointer)->pRingState,0);
        ring_vm_savestate2(pVM,pState);
        ring_vm_runcode(pVM,cStr);
        /* Restore State */
        ring_vm_restorestate2(pVM,pState,1);
        ring_list_delete_gc(((VM *) pPointer)->pRingState,pState);
        pVM->nEvalInScope-- ;
        /* Restore the current scope */
        pVM->pMem->nSize = nSize ;
        pVM->pMem->pLast->pNext = pNextItem ;
        pVM->pMem->pLast = pLastItem ;
        pVM->pActiveMem = pActiveMem ;
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_ringvmpasserror ( void *pPointer )
{
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    pVM->lPassError = 1 ;
}

void ring_vm_refmeta_ringvmhideerrormsg ( void *pPointer )
{
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISNUMBER(1) ) {
        pVM->lHideErrorMsg = (int) RING_API_GETNUMBER(1) ;
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_ringvmcallfunc ( void *pPointer )
{
    VM *pVM  ;
    String *pString  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISSTRING(1) ) {
        /* We create a string, because the current scope will be deleted by ring_vm_callfunc() */
        pString = ring_string_new_gc(((VM *) pPointer)->pRingState,RING_API_GETSTRING(1));
        ring_vm_callfunction(pVM,ring_string_get(pString));
        ring_string_delete_gc(((VM *) pPointer)->pRingState,pString);
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_ringvminfo ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    /*
    **  Add the list items 
    **  Lists Size (14 Items) 
    */
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pRingState->pRingFilesList));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pRingState->pRingFilesStack));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pCode));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->aNewByteCodeItems));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pMem));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->aScopeID));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pTempMem));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->aPCBlockFlag));
    ring_list_adddouble_gc(pVM->pRingState, pList, pVM->nLoadAddressScope);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->aBeforeObjState));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pFuncCallList));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->pTry));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->aScopeNewObj));
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->aSetProperty));
    /* Values */
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->lInsideEval);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nRetEvalDontDelete);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nRunCode);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->pRingState->lRunFromThread);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nPC);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nSP);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nFuncSP);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nLineNumber);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nDecimals);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->nActiveError);
    ring_list_addstring(pList,pVM->cFileName);
    /*
    **  Memory Pool 
    **  Check if used or not 
    */
    if ( pVM->pRingState->vPoolManager.pBlockStart == NULL ) {
        ring_list_adddouble_gc(pVM->pRingState, pList, 0.0);
    }
    else {
        ring_list_adddouble_gc(pVM->pRingState, pList, 1.0);
    }
    /* Check if we have current item or not! */
    if ( pVM->pRingState->vPoolManager.pCurrentItem != NULL ) {
        ring_list_adddouble_gc(pVM->pRingState, pList, 1.0);
    }
    else {
        ring_list_adddouble_gc(pVM->pRingState, pList, 0.0);
    }
    /* Track Allocations */
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->pRingState->vPoolManager.nAllocCount);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->pRingState->vPoolManager.nFreeCount);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->pRingState->vPoolManager.nSmallAllocCount);
    ring_list_adddouble_gc(pVM->pRingState, pList, (double) pVM->pRingState->vPoolManager.nSmallFreeCount);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}

void ring_vm_refmeta_ringvmgenarray ( void *pPointer )
{
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_BADPARACOUNT);
        return ;
    }
    if ( RING_API_ISLIST(1) ) {
        ring_list_genarray_gc(pVM->pRingState,RING_API_GETLIST(1));
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_refmeta_ringvmcodelist ( void *pPointer )
{
    VM *pVM  ;
    List *pList  ;
    pVM = (VM *) pPointer ;
    pList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_copy_gc(pVM->pRingState,pList,pVM->pCode);
    RING_API_RETLIST(pList);
    ring_list_delete_gc(pVM->pRingState,pList);
}
