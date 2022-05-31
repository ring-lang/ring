/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_api_h
    #define ring_api_h
    /*
    **  Functions 
    **  Support for C Functions 
    */

    RING_API void ring_vm_funcregister2 ( RingState *pRingState,const char *cStr, void (*pFunc)(void *) ) ;

    RING_API void ring_vm_loadcfunctions ( RingState *pRingState ) ;

    RING_API List * ring_vm_api_getlist ( void *pPointer,int x ) ;

    RING_API int ring_vm_api_islist ( void *pPointer,int x ) ;

    RING_API void ring_vm_api_retlist ( void *pPointer,List *pList ) ;

    RING_API List * ring_vm_api_newlist ( VM *pVM ) ;

    RING_API void ring_vm_api_retcpointer ( void *pPointer,void *pGeneral,const char *cType ) ;

    RING_API void * ring_vm_api_getcpointer ( void *pPointer,int x,const char *cType ) ;

    RING_API void ring_vm_api_setcpointernull ( void *pPointer,int x ) ;

    void ring_vm_extension ( RingState *pRingState ) ;

    RING_API void * ring_vm_api_varptr ( void *pPointer,const char  *cStr,const char *cStr2 ) ;

    RING_API void ring_vm_api_intvalue ( void *pPointer,const char  *cStr ) ;

    RING_API void ring_list_addcpointer ( List *pList,void *pGeneral,const char *cType ) ;

    RING_API int ring_vm_api_iscpointerlist ( List *pList ) ;

    RING_API int ring_vm_api_iscpointer ( void *pPointer,int x ) ;

    RING_API int ring_vm_api_isobject ( void *pPointer,int x ) ;

    RING_API int ring_vm_api_cpointercmp ( List *pList,List *pList2 ) ;

    RING_API int ring_vm_api_ispointer ( void *pPointer,int x ) ;

    RING_API void * ring_vm_api_getcpointer2pointer ( void *pPointer,int x,const char *cType ) ;

    RING_API void ring_list_addcpointer_gc ( void *pState,List *pList,void *pGeneral,const char *cType ) ;

    RING_API void ring_vm_api_retcpointer2 ( void *pPointer,void *pGeneral,const char *cType, void (* pFreeFunc)(void *,void *) ) ;

    RING_API void ring_vm_api_retlist2 ( void *pPointer,List *pList,int lRef ) ;
    /* API For C Functions */
    #define RING_API_PARALIST (((VM *) pPointer)->pActiveMem)
    #define RING_API_PARACOUNT (((VM *) pPointer)->nCFuncParaCount)
    #define RING_API_GETSTRING(x) (ring_list_getstring(ring_list_getlist(RING_API_PARALIST,x),3))
    #define RING_API_GETNUMBER(x) (ring_list_getdouble(ring_list_getlist(RING_API_PARALIST,x),3))
    #define RING_API_GETPOINTER(x) (ring_list_getpointer(ring_list_getlist(RING_API_PARALIST,x),3))
    #define RING_API_ISSTRING(x) (ring_list_isstring(ring_list_getlist(RING_API_PARALIST,x),3))
    #define RING_API_ISNUMBER(x) (ring_list_isnumber(ring_list_getlist(RING_API_PARALIST,x),3))
    #define RING_API_ISPOINTER(x) (ring_vm_api_ispointer((VM *) pPointer,x))
    #define RING_API_GETPOINTERTYPE(x) (ring_list_getint(ring_list_getlist(RING_API_PARALIST,x),4))
    #define RING_API_ERROR(x) (ring_vm_error((VM *) pPointer,x))
    #define RING_API_ISLIST(x) (ring_vm_api_islist((VM *) pPointer,x))
    #define RING_API_GETLIST(x) (ring_vm_api_getlist((VM *) pPointer,x))
    #define RING_API_RETNUMBER(x) ((VM *) pPointer)->nSP++ ; ring_itemarray_setdouble(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP , x)
    #define RING_API_RETSTRING(x) ((VM *) pPointer)->nSP++ ; ring_itemarray_setstring(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP, x)
    #define RING_API_RETSTRING2(x,y) ((VM *) pPointer)->nSP++ ; ring_itemarray_setstring2(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP, x,y)
    #define RING_API_RETSTRINGSIZE(x) ((VM *) pPointer)->nSP++ ; ring_itemarray_setstring2(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP, NULL,x)
    #define RING_API_RETLIST(x) ring_vm_api_retlist((VM *) pPointer,x)
    #define RING_API_NEWLIST ring_vm_api_newlist((VM *) pPointer)
    #define RING_API_RETCPOINTER(x,y) (ring_vm_api_retcpointer((VM *) pPointer,(void *) x,y))
    #define RING_API_GETCPOINTER(x,y) (ring_vm_api_getcpointer((VM *) pPointer,x,y))
    #define RING_API_PUSHPVALUE(x) ((VM *) pPointer)->nSP++ ; ring_itemarray_setpointer(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP , x )
    #define RING_API_OBJTYPE ((VM *) pPointer)->aStack[((VM *) pPointer)->nSP].nObjectType
    #define RING_API_GETSTRINGRAW ring_itemarray_getstringraw(((VM *) pPointer)->aStack,((VM *) pPointer)->nSP)
    #define RING_API_GETSTRINGSIZE(x) (ring_list_getstringsize(ring_list_getlist(RING_API_PARALIST,x),3))
    #define RING_API_SETNULLPOINTER(x) (ring_vm_api_setcpointernull((VM *) pPointer,x))
    #define RING_API_GETCPOINTERSTATUS(x) ring_list_getint(RING_API_GETLIST(x),RING_CPOINTER_STATUS)
    #define RING_API_ISCPOINTERNOTASSIGNED(x) (RING_API_GETCPOINTERSTATUS(x) == RING_CPOINTERSTATUS_NOTASSIGNED)
    #define RING_API_VARPOINTER(x,y) (ring_vm_api_varptr(pPointer,x,y))
    #define RING_API_INTVALUE(x) (ring_vm_api_intvalue(pPointer,x))
    #define RING_API_GETINTPOINTER(x) (int *) RING_API_VARPOINTER(RING_API_GETSTRING(x),"int")
    #define RING_API_ACCEPTINTVALUE(x) RING_API_INTVALUE(RING_API_GETSTRING(x))
    #define RING_API_GETDOUBLEPOINTER(x) RING_API_VARPOINTER(RING_API_GETSTRING(x),"double")
    #define RING_API_IGNORECPOINTERTYPE ((VM *) pPointer)->nIgnoreCPointerTypeCheck = 1
    #define RING_API_ISCPOINTER(x) ring_vm_api_iscpointer(pPointer,x)
    #define RING_API_ISOBJECT(x) ring_vm_api_isobject(pPointer,x)
    #define RING_API_GETCPOINTER2POINTER(x,y) (ring_vm_api_getcpointer2pointer((VM *) pPointer,x,y))
    #define RING_API_RETMANAGEDCPOINTER(x,y,z) (ring_vm_api_retcpointer2((VM *) pPointer,(void *) x,y,z))
    #define RING_API_RETLISTBYREF(x) ring_vm_api_retlist2((VM *) pPointer,x,1)
    #define ring_vm_funcregister(x,y) ring_vm_funcregister2(pRingState,x,y)
    #define RING_API_REGISTER(x,y) ring_vm_funcregister2(pRingState,x,y)
    #define RING_API_MALLOC(x) ring_state_malloc(((VM *) pPointer)->pRingState,x)
    #define RING_API_CALLOC(x,y) ring_state_calloc(((VM *) pPointer)->pRingState,x,y)
    #define RING_API_REALLOC(x,y,z) ring_state_realloc(((VM *) pPointer)->pRingState,x,y,z)
    #define RING_API_FREE(x) ring_state_free(((VM *) pPointer)->pRingState,x)
    #define RING_API_FREEFUNC ring_state_free
    #define RING_FUNC(x) void x(void *pPointer)
    #define RING_LIBINIT RING_API void ringlib_init(RingState *pRingState)
    /* Constants/MACRO */
    #define RING_API_MISS1PARA "Bad parameters count, the function expect one parameter"
    #define RING_API_MISS2PARA "Bad parameters count, the function expect two parameters"
    #define RING_API_MISS3PARA "Bad parameters count, the function expect three parameters"
    #define RING_API_MISS4PARA "Bad parameters count, the function expect four parameters"
    #define RING_API_BADPARATYPE "Bad parameter type!"
    #define RING_API_BADPARACOUNT "Bad parameters count!"
    #define RING_API_BADPARARANGE "Bad parameters value, error in range!"
    #define RING_API_BADPARALENGTH "Bad parameters value, error in length!"
    #define RING_API_BADPARAVALUE "Bad parameter value!"
    #define RING_API_NOTPOINTER "Error in parameter, not pointer!"
    #define RING_API_NULLPOINTER "Error in parameter, NULL pointer!"
    #define RING_API_EMPTYLIST "Bad parameter, empty list!"
    #define RING_API_INTERNALFAILURE "Internal function call failed!"
    /*
    **  Note : The C Function Get Lists as pointers because of (List Pass by Reference) 
    **  The List Maybe a Variable/ListItem or may represent Object or C Pointer inside a List 
    **  C Pointer List , [ Pointer Value , Type String , Status Number 0=Not Copied 1=Copied 2= Not Assigned Yet] 
    */
#endif
