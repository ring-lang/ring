/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
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
/*
**  Library 
**  General 
*/

void ring_vmlib_len ( void *pPointer ) ;

void ring_vmlib_add ( void *pPointer ) ;

void ring_vmlib_del ( void *pPointer ) ;

void ring_vmlib_get ( void *pPointer ) ;

void ring_vmlib_clock ( void *pPointer ) ;

void ring_vmlib_lower ( void *pPointer ) ;

void ring_vmlib_upper ( void *pPointer ) ;

void ring_vmlib_input ( void *pPointer ) ;

void ring_vmlib_ascii ( void *pPointer ) ;

void ring_vmlib_char ( void *pPointer ) ;

void ring_vmlib_date ( void *pPointer ) ;

void ring_vmlib_time ( void *pPointer ) ;

void ring_vmlib_filename ( void *pPointer ) ;

void ring_vmlib_getchar ( void *pPointer ) ;

void ring_vmlib_system ( void *pPointer ) ;

void ring_vmlib_random ( void *pPointer ) ;

void ring_vmlib_timelist ( void *pPointer ) ;

void ring_vmlib_adddays ( void *pPointer ) ;

void ring_vmlib_diffdays ( void *pPointer ) ;

void ring_vmlib_version ( void *pPointer ) ;

void ring_vmlib_clockspersecond ( void *pPointer ) ;

void ring_vmlib_prevfilename ( void *pPointer ) ;

int ring_vmlib_adddays_isleapyear ( int nYear ) ;

void ring_vmlib_swap ( void *pPointer ) ;

void ring_vmlib_shutdown ( void *pPointer ) ;

void ring_vmlib_srandom ( void *pPointer ) ;
/* Check Data Type */

void ring_vmlib_isstring ( void *pPointer ) ;

void ring_vmlib_isnumber ( void *pPointer ) ;

void ring_vmlib_islist ( void *pPointer ) ;

void ring_vmlib_type ( void *pPointer ) ;

void ring_vmlib_isnull ( void *pPointer ) ;

void ring_vmlib_isobject ( void *pPointer ) ;

void ring_vmlib_ispointer ( void *pPointer ) ;
/* Conversion */

void ring_vmlib_hex ( void *pPointer ) ;

void ring_vmlib_dec ( void *pPointer ) ;

void ring_vmlib_number ( void *pPointer ) ;

void ring_vmlib_string ( void *pPointer ) ;

void ring_vmlib_str2hex ( void *pPointer ) ;

void ring_vmlib_hex2str ( void *pPointer ) ;

void ring_vmlib_str2list ( void *pPointer ) ;

void ring_vmlib_list2str ( void *pPointer ) ;

void ring_vmlib_str2hexcstyle ( void *pPointer ) ;
/* String */

void ring_vmlib_left ( void *pPointer ) ;

void ring_vmlib_right ( void *pPointer ) ;

void ring_vmlib_trim ( void *pPointer ) ;

void ring_vmlib_copy ( void *pPointer ) ;

void ring_vmlib_substr ( void *pPointer ) ;

void ring_vmlib_lines ( void *pPointer ) ;

void ring_vmlib_strcmp ( void *pPointer ) ;
/* Functional */

void ring_vmlib_eval ( void *pPointer ) ;
/* Error Handling */

void ring_vmlib_raise ( void *pPointer ) ;

void ring_vmlib_assert ( void *pPointer ) ;
/* Check Characters */

void ring_vmlib_isfunc ( void *pPointer,int (*pFunc)(int) ) ;

void ring_vmlib_isalnum ( void *pPointer ) ;

void ring_vmlib_isalpha ( void *pPointer ) ;

void ring_vmlib_iscntrl ( void *pPointer ) ;

void ring_vmlib_isdigit ( void *pPointer ) ;

void ring_vmlib_isgraph ( void *pPointer ) ;

void ring_vmlib_islower ( void *pPointer ) ;

void ring_vmlib_isprint ( void *pPointer ) ;

void ring_vmlib_ispunct ( void *pPointer ) ;

void ring_vmlib_isspace ( void *pPointer ) ;

void ring_vmlib_isupper ( void *pPointer ) ;

void ring_vmlib_isxdigit ( void *pPointer ) ;
/* Garbage Collector & Variable Pointer */

void ring_vmlib_callgc ( void *pPointer ) ;

void ring_vmlib_varptr ( void *pPointer ) ;

void ring_vmlib_intvalue ( void *pPointer ) ;

void ring_vmlib_object2pointer ( void *pPointer ) ;

void ring_vmlib_pointer2object ( void *pPointer ) ;

void ring_vmlib_nullpointer ( void *pPointer ) ;

void ring_vmlib_space ( void *pPointer ) ;

void ring_vmlib_ptrcmp ( void *pPointer ) ;

void ring_vmlib_pointer2string ( void *pPointer ) ;

void ring_vmlib_setpointer ( void *pPointer ) ;

void ring_vmlib_getpointer ( void *pPointer ) ;

void ring_vmlib_memcpy ( void *pPointer ) ;
/* Ring State */

void ring_vmlib_state_init ( void *pPointer ) ;

void ring_vmlib_state_runcode ( void *pPointer ) ;

void ring_vmlib_state_delete ( void *pPointer ) ;

void ring_vmlib_state_runfile ( void *pPointer ) ;

void ring_vmlib_state_findvar ( void *pPointer ) ;

void ring_vmlib_state_newvar ( void *pPointer ) ;

void ring_vmlib_state_runobjectfile ( void *pPointer ) ;

void ring_vmlib_state_main ( void *pPointer ) ;

void ring_vmlib_state_setvar ( void *pPointer ) ;

void ring_vmlib_state_new ( void *pPointer ) ;

void ring_vmlib_state_mainfile ( void *pPointer ) ;

void ring_vmlib_state_filetokens ( void *pPointer ) ;
/* Ring See and Give */

void ring_vmlib_see ( void *pPointer ) ;

void ring_vmlib_give ( void *pPointer ) ;
/* Performance */

void ring_vmlib_checkoverflow ( void *pPointer ) ;

void ring_vmlib_addsublistsbymove ( void *pPointer ) ;

void ring_vmlib_addsublistsbyfastcopy ( void *pPointer ) ;
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
#define RING_API_RETLIST(x) ring_vm_api_retlist((VM *) pPointer,x)
#define RING_API_NEWLIST ring_vm_api_newlist((VM *) pPointer)
#define RING_API_RETCPOINTER(x,y) (ring_vm_api_retcpointer((VM *) pPointer,(void *) x,y))
#define RING_API_GETCPOINTER(x,y) (ring_vm_api_getcpointer((VM *) pPointer,x,y))
#define RING_API_PUSHPVALUE(x) ((VM *) pPointer)->nSP++ ; ring_itemarray_setpointer(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP , x )
#define RING_API_OBJTYPE ((VM *) pPointer)->aStack[((VM *) pPointer)->nSP].nObjectType
#define RING_FUNC(x) void x(void *pPointer)
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
#define RING_API_BEFORENEWTHREAD ((VM *) pPointer)->lStopThisThread = 1;
#define RING_API_AFTERNEWTHREAD while( ((VM *) pPointer)->lStopThisThread ) ;
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
#define ring_vm_funcregister(x,y) ring_vm_funcregister2(pRingState,x,y)
/*
**  Note : The C Function Get Lists as pointers because of (List Pass by Reference) 
**  The List Maybe a Variable/ListItem or may represent Object or C Pointer inside a List 
**  C Pointer List , [ Pointer Value , Type String , Status Number 0=Not Copied 1=Copied 2= Not Assigned Yet] 
*/
#endif
