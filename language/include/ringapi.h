/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_api_h
#define ring_api_h
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
#define RING_API_RANGEEXCEEDED "Range Exceeded!"
#define RING_OUTPUT_RETLIST 0
#define RING_OUTPUT_RETLISTBYREF 1
#define RING_OUTPUT_RETNEWREF 2
#define RING_VARVALUE_INT 1
#define RING_VARVALUE_FLOAT 2
#define RING_API_MINLISTSIZEFORUSINGBLOCKS 30
/* API For C Functions */
#define RING_API_STATE (((VM *)pPointer)->pRingState)
#define RING_API_PARACOUNT (ring_vm_api_paracount(pPointer))
#define RING_API_GETSTRING(nPara) (ring_vm_api_getstring(pPointer, nPara))
#define RING_API_GETNUMBER(nPara) (ring_vm_api_getnumber(pPointer, nPara))
#define RING_API_GETPOINTER(nPara) (ring_vm_api_getpointer(pPointer, nPara))
#define RING_API_ISSTRING(nPara) (ring_vm_api_isstring(pPointer, nPara))
#define RING_API_ISNUMBER(nPara) (ring_vm_api_isnumber(pPointer, nPara))
#define RING_API_ISPOINTER(nPara) (ring_vm_api_ispointer(pPointer, nPara))
#define RING_API_GETPOINTERTYPE(nPara) (ring_vm_api_getpointertype(pPointer, nPara))
#define RING_API_ERROR(cError) (ring_vm_error((VM *)pPointer, cError))
#define RING_API_ISLIST(nPara) (ring_vm_api_islist(pPointer, nPara))
#define RING_API_GETLIST(nPara) (ring_vm_api_getlist(pPointer, nPara))
#define RING_API_RETNUMBER(nNumber) ring_vm_api_retnumber(pPointer, nNumber)
#define RING_API_RETSTRING(cStr) ring_vm_api_retstring(pPointer, cStr)
#define RING_API_RETSTRING2(cStr, nSize) ring_vm_api_retstring2(pPointer, cStr, nSize)
#define RING_API_RETSTRINGSIZE(nSize) ring_vm_api_retstringsize(pPointer, nSize)
#define RING_API_RETLIST(pList) ring_vm_api_retlist(pPointer, pList)
#define RING_API_NEWLIST ring_vm_api_newlist(pPointer)
#define RING_API_RETCPOINTER(pPtr, cType) (ring_vm_api_retcpointer(pPointer, (void *)pPtr, cType))
#define RING_API_GETCPOINTER(nPara, cType) (ring_vm_api_getcpointer(pPointer, nPara, cType))
#define RING_API_GETSTRINGRAW ring_vm_api_getstringraw(pPointer)
#define RING_API_GETSTRINGSIZE(nPara) (ring_vm_api_getstringsize(pPointer, nPara))
#define RING_API_SETNULLPOINTER(nPara) (ring_vm_api_setcpointernull(pPointer, nPara))
#define RING_API_GETCPOINTERSTATUS(nPara) ring_list_getint(RING_API_GETLIST(nPara), RING_CPOINTER_STATUS)
#define RING_API_ISCPOINTERNOTASSIGNED(nPara) (RING_API_GETCPOINTERSTATUS(nPara) == RING_CPOINTERSTATUS_NOTASSIGNED)
#define RING_API_VARPOINTER(cName, cType) (ring_vm_api_varptr(pPointer, cName, cType))
#define RING_API_INTVALUE(nPara) (ring_vm_api_intvalue(pPointer, nPara))
#define RING_API_FLOATVALUE(nPara) (ring_vm_api_floatvalue(pPointer, nPara))
#define RING_API_GETINTPOINTER(nPara) (int *)RING_API_VARPOINTER(RING_API_GETSTRING(nPara), "int")
#define RING_API_GETFLOATPOINTER(nPara) (float *)RING_API_VARPOINTER(RING_API_GETSTRING(nPara), "float")
#define RING_API_GETDOUBLEPOINTER(nPara) RING_API_VARPOINTER(RING_API_GETSTRING(nPara), "double")
#define RING_API_ACCEPTINTVALUE(nPara) RING_API_INTVALUE(RING_API_GETSTRING(nPara))
#define RING_API_ACCEPTFLOATVALUE(nPara) RING_API_FLOATVALUE(RING_API_GETSTRING(nPara))
#define RING_API_IGNORECPOINTERTYPE ring_vm_api_ignorecpointertypecheck(pPointer)
#define RING_API_ISCPOINTER(nPara) ring_vm_api_iscpointer(pPointer, nPara)
#define RING_API_ISOBJECT(nPara) ring_vm_api_isobject(pPointer, nPara)
#define RING_API_GETCPOINTER2POINTER(nPara, cType) (ring_vm_api_getcpointer2pointer(pPointer, nPara, cType))
#define RING_API_RETMANAGEDCPOINTER(pPtr, cType, pFreeFunc)                                                            \
	(ring_vm_api_retcpointer2(pPointer, (void *)pPtr, cType, pFreeFunc))
#define RING_API_RETLISTBYREF(pList) ring_vm_api_retlist2(pPointer, pList, RING_OUTPUT_RETLISTBYREF)
#define RING_API_RETNEWREF(pList) ring_vm_api_retlist2(pPointer, pList, RING_OUTPUT_RETNEWREF)
#define ring_vm_funcregister(cName, pFunc) ring_vm_funcregister2(pRingState, cName, pFunc)
#define RING_API_REGISTER(cName, pFunc) ring_vm_funcregister2(pRingState, cName, pFunc)
#define RING_API_MALLOC(nSize) ring_state_malloc(((VM *)pPointer)->pRingState, nSize)
#define RING_API_CALLOC(nCount, nSize) ring_state_calloc(((VM *)pPointer)->pRingState, nCount, nSize)
#define RING_API_REALLOC(pPtr, nOldSize, nNewSize)                                                                     \
	ring_state_realloc(((VM *)pPointer)->pRingState, pPtr, nOldSize, nNewSize)
#define RING_API_FREE(pPtr) ring_state_free(((VM *)pPointer)->pRingState, pPtr)
#define RING_API_FREEFUNC ring_state_free
#define RING_FUNC(cName) void cName(void *pPointer)
#define RING_LIBINIT RING_API void ringlib_init(RingState *pRingState)
#define RING_API_GETCHARPOINTER(nPara) RING_API_VARPOINTER(RING_API_GETSTRING(nPara), "char")
#define RING_API_ISLISTORNULL(nPara) (ring_vm_api_islistornull(pPointer, nPara))
#define RING_API_IGNORETHISDIMENSION UINT_MAX
#define RING_API_NEWLISTUSINGBLOCKS1D(nSize)                                                                           \
	ring_vm_api_newlistusingblocks(pPointer, nSize, RING_API_IGNORETHISDIMENSION)
#define RING_API_NEWLISTUSINGBLOCKS2D(nRows, nCols) ring_vm_api_newlistusingblocks(pPointer, nRows, nCols)
#define RING_API_CALLERSCOPE ring_vm_api_callerscope(pPointer)
#define RING_API_SCOPESCOUNT ring_vm_api_scopescount(pPointer)
/*
**  Note : The C Function Get Lists as pointers because of (List Pass by Reference)
**  The List Maybe a Variable/ListItem or may represent Object or C Pointer inside a List
**  C Pointer List , [ Pointer Value , Type String , Status Number 0=Not Copied 1=Copied 2= Not Assigned Yet]
*/
/* Support for C Functions */

void ring_vm_extension(RingState *pRingState);

RING_API void ring_vm_loadcfunctions(RingState *pRingState);

RING_API void ring_vm_funcregister2(RingState *pRingState, const char *cStr, void (*pFunc)(void *));

RING_API int ring_vm_api_isstring(void *pPointer, int nPara);

RING_API int ring_vm_api_isnumber(void *pPointer, int nPara);

RING_API int ring_vm_api_isptr(void *pPointer, int nPara);

RING_API void ring_vm_api_setptr(void *pPointer, int nPara, void *pPtr, int nType);

RING_API char *ring_vm_api_getstring(void *pPointer, int nPara);

RING_API unsigned int ring_vm_api_getstringsize(void *pPointer, int nPara);

RING_API double ring_vm_api_getnumber(void *pPointer, int nPara);

RING_API void *ring_vm_api_getpointer(void *pPointer, int nPara);

RING_API int ring_vm_api_getpointertype(void *pPointer, int nPara);

RING_API List *ring_vm_api_getlist(void *pPointer, int nPara);

RING_API int ring_vm_api_islist(void *pPointer, int nPara);

RING_API int ring_vm_api_islistornull(void *pPointer, int nPara);

RING_API int ring_vm_api_ispointer(void *pPointer, int nPara);

RING_API void ring_vm_api_retlist(void *pPointer, List *pList);

RING_API void ring_vm_api_retcpointer(void *pPointer, void *pGeneral, const char *cType);

RING_API void *ring_vm_api_getcpointer(void *pPointer, int nPara, const char *cType);

RING_API void ring_vm_api_setcpointernull(void *pPointer, int nPara);

RING_API void *ring_vm_api_varptr(void *pPointer, const char *cStr, const char *cStr2);

RING_API void ring_vm_api_varvalue(void *pPointer, const char *cStr, int nType);

RING_API int ring_vm_api_iscpointerlist(void *pPointer, List *pList);

RING_API int ring_vm_api_iscpointer(void *pPointer, int nPara);

RING_API int ring_vm_api_isobject(void *pPointer, int nPara);

RING_API int ring_vm_api_cpointercmp(void *pPointer, List *pList, List *pList2);

RING_API void *ring_vm_api_getcpointer2pointer(void *pPointer, int nPara, const char *cType);

RING_API void ring_vm_api_retcpointer2(void *pPointer, void *pGeneral, const char *cType,
				       void (*pFreeFunc)(void *, void *));

RING_API void ring_vm_api_retlist2(void *pPointer, List *pList, int nRef);

RING_API void ring_vm_api_intvalue(void *pPointer, const char *cStr);

RING_API void ring_vm_api_floatvalue(void *pPointer, const char *cStr);

RING_API List *ring_vm_api_newlist(void *pPointer);

RING_API List *ring_vm_api_newlistusingblocks(void *pPointer, unsigned int nSize, unsigned int nSize2);

RING_API List *ring_vm_api_callerscope(void *pPointer);

RING_API int ring_vm_api_scopescount(void *pPointer);

RING_API int ring_vm_api_paracount(void *pPointer);

RING_API void ring_vm_api_ignorecpointertypecheck(void *pPointer);

RING_API void ring_vm_api_retnumber(void *pPointer, double nNumber);

RING_API void ring_vm_api_retstring(void *pPointer, const char *cStr);

RING_API void ring_vm_api_retstring2(void *pPointer, const char *cStr, unsigned int nSize);

RING_API void ring_vm_api_retstringsize(void *pPointer, unsigned int nSize);

RING_API String *ring_vm_api_getstringraw(void *pPointer);
#endif
