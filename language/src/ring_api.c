/* Copyright (c) 2013-2021 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Support for C Functions */

RING_API void ring_vm_funcregister2 ( RingState *pRingState,const char *cStr, void (*pFunc)(void *) )
{
	List *pList  ;
	if ( pRingState->pRingCFunctions == NULL ) {
		pRingState->pRingCFunctions = ring_list_new_gc(pRingState,0);
	}
	pList = ring_list_newlist_gc(pRingState,pRingState->pRingCFunctions);
	ring_list_addstring_gc(pRingState,pList,cStr);
	ring_list_addfuncpointer_gc(pRingState,pList,pFunc);
}

RING_API void ring_vm_loadcfunctions ( RingState *pRingState )
{
	/* General */
	ring_vm_funcregister("len",ring_vmlib_len);
	ring_vm_funcregister("clock",ring_vmlib_clock);
	ring_vm_funcregister("lower",ring_vmlib_lower);
	ring_vm_funcregister("upper",ring_vmlib_upper);
	ring_vm_funcregister("input",ring_vmlib_input);
	ring_vm_funcregister("ascii",ring_vmlib_ascii);
	ring_vm_funcregister("char",ring_vmlib_char);
	ring_vm_funcregister("date",ring_vmlib_date);
	ring_vm_funcregister("time",ring_vmlib_time);
	ring_vm_funcregister("filename",ring_vmlib_filename);
	ring_vm_funcregister("getchar",ring_vmlib_getchar);
	ring_vm_funcregister("system",ring_vmlib_system);
	ring_vm_funcregister("random",ring_vmlib_random);
	ring_vm_funcregister("timelist",ring_vmlib_timelist);
	ring_vm_funcregister("adddays",ring_vmlib_adddays);
	ring_vm_funcregister("diffdays",ring_vmlib_diffdays);
	ring_vm_funcregister("version",ring_vmlib_version);
	ring_vm_funcregister("clockspersecond",ring_vmlib_clockspersecond);
	ring_vm_funcregister("prevfilename",ring_vmlib_prevfilename);
	ring_vm_funcregister("shutdown",ring_vmlib_shutdown);
	ring_vm_funcregister("srandom",ring_vmlib_srandom);
	/* Check Data Type */
	ring_vm_funcregister("isstring",ring_vmlib_isstring);
	ring_vm_funcregister("isnumber",ring_vmlib_isnumber);
	ring_vm_funcregister("islist",ring_vmlib_islist);
	ring_vm_funcregister("type",ring_vmlib_type);
	ring_vm_funcregister("isnull",ring_vmlib_isnull);
	ring_vm_funcregister("isobject",ring_vmlib_isobject);
	ring_vm_funcregister("ispointer",ring_vmlib_ispointer);
	/* Conversion */
	ring_vm_funcregister("hex",ring_vmlib_hex);
	ring_vm_funcregister("dec",ring_vmlib_dec);
	ring_vm_funcregister("number",ring_vmlib_number);
	ring_vm_funcregister("string",ring_vmlib_string);
	ring_vm_funcregister("str2hex",ring_vmlib_str2hex);
	ring_vm_funcregister("hex2str",ring_vmlib_hex2str);
	ring_vm_funcregister("str2list",ring_vmlib_str2list);
	ring_vm_funcregister("list2str",ring_vmlib_list2str);
	ring_vm_funcregister("str2hexcstyle",ring_vmlib_str2hexcstyle);
	/* String */
	ring_vm_funcregister("left",ring_vmlib_left);
	ring_vm_funcregister("right",ring_vmlib_right);
	ring_vm_funcregister("trim",ring_vmlib_trim);
	ring_vm_funcregister("copy",ring_vmlib_copy);
	ring_vm_funcregister("substr",ring_vmlib_substr);
	ring_vm_funcregister("lines",ring_vmlib_lines);
	ring_vm_funcregister("strcmp",ring_vmlib_strcmp);
	/* Functional */
	ring_vm_funcregister("eval",ring_vmlib_eval);
	/* Error Handling */
	ring_vm_funcregister("raise",ring_vmlib_raise);
	ring_vm_funcregister("assert",ring_vmlib_assert);
	/* Check Characters */
	ring_vm_funcregister("isalnum",ring_vmlib_isalnum);
	ring_vm_funcregister("isalpha",ring_vmlib_isalpha);
	ring_vm_funcregister("iscntrl",ring_vmlib_iscntrl);
	ring_vm_funcregister("isdigit",ring_vmlib_isdigit);
	ring_vm_funcregister("isgraph",ring_vmlib_isgraph);
	ring_vm_funcregister("islower",ring_vmlib_islower);
	ring_vm_funcregister("isprint",ring_vmlib_isprint);
	ring_vm_funcregister("ispunct",ring_vmlib_ispunct);
	ring_vm_funcregister("isspace",ring_vmlib_isspace);
	ring_vm_funcregister("isupper",ring_vmlib_isupper);
	ring_vm_funcregister("isxdigit",ring_vmlib_isxdigit);
	/* Garbage Collector & Variable Pointer */
	ring_vm_funcregister("callgc",ring_vmlib_callgc);
	ring_vm_funcregister("varptr",ring_vmlib_varptr);
	ring_vm_funcregister("intvalue",ring_vmlib_intvalue);
	ring_vm_funcregister("object2pointer",ring_vmlib_object2pointer);
	ring_vm_funcregister("pointer2object",ring_vmlib_pointer2object);
	ring_vm_funcregister("nullpointer",ring_vmlib_nullpointer);
	ring_vm_funcregister("space",ring_vmlib_space);
	ring_vm_funcregister("ptrcmp",ring_vmlib_ptrcmp);
	ring_vm_funcregister("pointer2string",ring_vmlib_pointer2string);
	ring_vm_funcregister("setpointer",ring_vmlib_setpointer);
	ring_vm_funcregister("getpointer",ring_vmlib_getpointer);
	ring_vm_funcregister("memcpy",ring_vmlib_memcpy);
	ring_vm_funcregister("callgarbagecollector",ring_vmlib_callgc);
	ring_vm_funcregister("variablepointer",ring_vmlib_varptr);
	ring_vm_funcregister("obj2ptr",ring_vmlib_object2pointer);
	ring_vm_funcregister("ptr2obj",ring_vmlib_pointer2object);
	ring_vm_funcregister("nullptr",ring_vmlib_nullpointer);
	ring_vm_funcregister("pointercompare",ring_vmlib_ptrcmp);
	ring_vm_funcregister("ptr2str",ring_vmlib_pointer2string);
	ring_vm_funcregister("setptr",ring_vmlib_setpointer);
	ring_vm_funcregister("getptr",ring_vmlib_getpointer);
	ring_vm_funcregister("memorycopy",ring_vmlib_memcpy);
	/* Ring State */
	ring_vm_funcregister("ring_state_init",ring_vmlib_state_init);
	ring_vm_funcregister("ring_state_runcode",ring_vmlib_state_runcode);
	ring_vm_funcregister("ring_state_delete",ring_vmlib_state_delete);
	ring_vm_funcregister("ring_state_runfile",ring_vmlib_state_runfile);
	ring_vm_funcregister("ring_state_findvar",ring_vmlib_state_findvar);
	ring_vm_funcregister("ring_state_newvar",ring_vmlib_state_newvar);
	ring_vm_funcregister("ring_state_runobjectfile",ring_vmlib_state_runobjectfile);
	ring_vm_funcregister("ring_state_main",ring_vmlib_state_main);
	ring_vm_funcregister("ring_state_setvar",ring_vmlib_state_setvar);
	ring_vm_funcregister("ring_state_new",ring_vmlib_state_new);
	ring_vm_funcregister("ring_state_mainfile",ring_vmlib_state_mainfile);
	ring_vm_funcregister("ring_state_filetokens",ring_vmlib_state_filetokens);
	/* Performance */
	ring_vm_funcregister("checkoverflow",ring_vmlib_checkoverflow);
	ring_vm_funcregister("addsublistsbymove",ring_vmlib_addsublistsbymove);
	ring_vm_funcregister("addsublistsbyfastcopy",ring_vmlib_addsublistsbyfastcopy);
	/*
	**  Ring See and Give 
	**  We will use ringvm_see() and ringvm_give() to change the behavior of see and give 
	**  Also we can use ring_see() and ring_give() to use the original behavior when we redefine it 
	*/
	ring_vm_funcregister("ringvm_see",ring_vmlib_see);
	ring_vm_funcregister("ringvm_give",ring_vmlib_give);
	ring_vm_funcregister("ring_see",ring_vmlib_see);
	ring_vm_funcregister("ring_give",ring_vmlib_give);
	/* Other Modules */
	ring_vm_extension(pRingState);
}

int ring_vm_api_islist ( void *pPointer,int x )
{
	int nType  ;
	if ( RING_API_ISPOINTER(x) ) {
		nType = RING_API_GETPOINTERTYPE(x);
		if ( nType == RING_OBJTYPE_VARIABLE || nType == RING_OBJTYPE_LISTITEM ) {
			return 1 ;
		}
	}
	return 0 ;
}

RING_API List * ring_vm_api_getlist ( void *pPointer,int x )
{
	int nType  ;
	Item *pItem  ;
	List *pList  ;
	if ( RING_API_ISPOINTER(x) ) {
		nType = RING_API_GETPOINTERTYPE(x);
		if ( nType == RING_OBJTYPE_VARIABLE ) {
			pList = (List *) RING_API_GETPOINTER(x) ;
			return ring_list_getlist(pList,3) ;
		}
		else if ( nType == RING_OBJTYPE_LISTITEM ) {
			pItem = (Item *) RING_API_GETPOINTER(x) ;
			return ring_item_getlist(pItem) ;
		}
	}
	return NULL ;
}

RING_API void ring_vm_api_retlist ( void *pPointer,List *pList )
{
	ring_vm_api_retlist2(pPointer,pList,0);
}

RING_API List * ring_vm_api_newlist ( VM *pVM )
{
	List *pList  ;
	pList = ring_list_newlist_gc(pVM->pRingState,pVM->pActiveMem);
	return pList ;
}

RING_API void ring_vm_api_retcpointer2 ( void *pPointer,void *pGeneral,const char *cType, void (* pFreeFunc)(void *,void *) )
{
	List *pList  ;
	Item *pItem  ;
	/* Create the list */
	pList = RING_API_NEWLIST ;
	/* The variable value will be a list contains the pointer */
	ring_list_addpointer_gc(((VM *) pPointer)->pRingState,pList,pGeneral);
	/* Add the pointer type */
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,cType);
	/* Add the status number ( 0 = Not Copied ,1 = Copied  2 = Not Assigned yet) */
	ring_list_addint_gc(((VM *) pPointer)->pRingState,pList,RING_CPOINTERSTATUS_NOTASSIGNED);
	/* Set the Free Function */
	if ( pFreeFunc != NULL ) {
		pItem = ring_list_getitem(pList,RING_CPOINTER_POINTER);
		ring_vm_gc_setfreefunc(pItem,pFreeFunc);
	}
	RING_API_RETLIST(pList);
}

RING_API void * ring_vm_api_getcpointer ( void *pPointer,int x,const char *cType )
{
	List *pList  ;
	if ( RING_API_ISLIST(x) ) {
		pList = RING_API_GETLIST(x) ;
		if ( ring_list_ispointer(pList,1) ) {
			if ( ring_list_getpointer(pList,1) != NULL ) {
				if ( (strcmp(ring_list_getstring(pList,2),cType) == 0) || (((VM *) pPointer)->nIgnoreCPointerTypeCheck==1) ) {
					/*
					**  Check if the pointer is copied or not 
					**  We check for 2 (not assigned) also, happens when f1 ( x , f2() ) and f2 return C pointer 
					*/
					if ( (ring_list_getint(pList,3) == 0) || (ring_list_getint(pList,3) == 2) ) {
						return ring_list_getpointer(pList,1) ;
					}
					ring_list_setpointer_gc(((VM *) pPointer)->pRingState,pList,1,NULL);
					RING_API_ERROR(RING_API_NULLPOINTER);
					return NULL ;
				}
				RING_API_ERROR(RING_API_BADPARATYPE);
				return NULL ;
			}
			else {
				if ( (strcmp(ring_list_getstring(pList,2),"NULLPOINTER") == 0) || (strcmp(ring_list_getstring(pList,2),cType) == 0) ) {
					return NULL ;
				}
			}
			RING_API_ERROR(RING_API_NULLPOINTER);
			return NULL ;
		}
	}
	RING_API_ERROR(RING_API_NOTPOINTER);
	return NULL ;
}

RING_API void ring_vm_api_setcpointernull ( void *pPointer,int x )
{
	List *pList  ;
	pList = (List *) RING_API_GETLIST(x) ;
	/* Check pointer status ( 0 = Not copied , 1 = Copied ) */
	if ( ring_list_getint(pList,3) == RING_CPOINTERSTATUS_NOTCOPIED ) {
		ring_list_setpointer_gc(((VM *) pPointer)->pRingState,pList,1,NULL);
		return ;
	}
}

RING_API void * ring_vm_api_varptr ( void *pPointer,const char  *cStr,const char *cStr2 )
{
	VM *pVM  ;
	List *pList, *pActiveMem  ;
	Item *pItem  ;
	/*
	**  Usage 
	**  To get pointer to a ring variable value (pointer to double or int) i.e. int * or double * 
	**  We need this because some C Functions get int * or double * as parameter 
	*/
	pVM = (VM *) pPointer ;
	/* Set the Active Scope */
	pActiveMem = pVM->pActiveMem ;
	pVM->pActiveMem = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)-1);
	if ( ring_vm_findvar(pVM, cStr ) == 0 ) {
		/* Restore the Active Scope */
		pVM->pActiveMem = pActiveMem ;
		RING_API_ERROR(RING_VM_ERROR_NOTVARIABLE);
		return NULL ;
	}
	/* Restore the Active Scope */
	pVM->pActiveMem = pActiveMem ;
	pList = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	if ( ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_NUMBER ) {
		pItem = ring_list_getitem(pList,RING_VAR_VALUE);
		if ( strcmp(cStr2,"double") == 0 ) {
			return &(pItem->data.dNumber) ;
		}
		else if ( strcmp(cStr2,"int") == 0 ) {
			return &(pItem->data.iNumber) ;
		}
	}
	else if ( ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_STRING ) {
		pItem = ring_list_getitem(pList,RING_VAR_VALUE);
		return pItem->data.pString->cStr ;
	}
	return NULL ;
}

RING_API void ring_vm_api_intvalue ( void *pPointer,const char  *cStr )
{
	VM *pVM  ;
	List *pList, *pActiveMem  ;
	Item *pItem  ;
	/*
	**  Usage 
	**  Convert the variable value from int to double 
	**  When we pass int * for Ring Variable Value to a C Function 
	**  We need to convert again from int to double, because Ring uses double 
	*/
	pVM = (VM *) pPointer ;
	/* Set the Active Scope */
	pActiveMem = pVM->pActiveMem ;
	pVM->pActiveMem = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)-1);
	if ( ring_vm_findvar(pVM, cStr ) == 0 ) {
		/* Restore the Active Scope */
		pVM->pActiveMem = pActiveMem ;
		RING_API_ERROR(RING_VM_ERROR_NOTVARIABLE);
		return ;
	}
	/* Restore the Active Scope */
	pVM->pActiveMem = pActiveMem ;
	pList = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	if ( ring_list_getint(pList,RING_VAR_TYPE) == RING_VM_NUMBER ) {
		pItem = ring_list_getitem(pList,RING_VAR_VALUE);
		pItem->data.dNumber = (double) pItem->data.iNumber ;
	}
}

RING_API void ring_list_addcpointer ( List *pList,void *pGeneral,const char *cType )
{
	List *pList2  ;
	/* create sub list */
	pList2 = ring_list_newlist(pList);
	/* The variable value will be a list contains the pointer */
	ring_list_addpointer(pList2,pGeneral);
	/* Add the pointer type */
	ring_list_addstring(pList2,cType);
	/* Add the status number ( 0 = Not Copied ,1 = Copied  2 = Not Assigned yet) */
	ring_list_addint(pList2,2);
}

RING_API int ring_vm_api_iscpointerlist ( List *pList )
{
	if ( ring_list_getsize(pList) != 3 ) {
		return 0 ;
	}
	if ( ring_list_ispointer(pList,1) && ring_list_isstring(pList,2) && ring_list_isnumber(pList,3) ) {
		return 1 ;
	}
	return 0 ;
}

RING_API int ring_vm_api_iscpointer ( void *pPointer,int x )
{
	if ( RING_API_ISLIST(x) ) {
		return ring_vm_api_iscpointerlist(RING_API_GETLIST(x)) ;
	}
	return 0 ;
}

RING_API int ring_vm_api_isobject ( void *pPointer,int x )
{
	if ( RING_API_ISLIST(x) ) {
		return ring_vm_oop_isobject(RING_API_GETLIST(x)) ;
	}
	return 0 ;
}

RING_API int ring_vm_api_cpointercmp ( List *pList,List *pList2 )
{
	if ( ring_list_getpointer(pList,RING_CPOINTER_POINTER) == ring_list_getpointer(pList2,RING_CPOINTER_POINTER) ) {
		return 1 ;
	}
	else {
		return 0 ;
	}
}

RING_API int ring_vm_api_ispointer ( void *pPointer,int x )
{
	List *pList, *pList2  ;
	VM *pVM  ;
	Item *pItem  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_getlist(RING_API_PARALIST,x) ;
	if ( ring_list_ispointer(pList,RING_VAR_VALUE) ) {
		return 1 ;
	}
	else if ( ring_list_isstring(pList,RING_VAR_VALUE) ) {
		/* Treat NULL Strings as NULL Pointers - so we can use NULL instead of NULLPOINTER() */
		if ( (strcmp(ring_list_getstring(pList,RING_VAR_VALUE),"") == 0) || (strcmp(ring_list_getstring(pList,RING_VAR_VALUE),"NULL") == 0) ) {
			/* Create the list for the NULL Pointer */
			ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_POINTER);
			pList2 = RING_API_NEWLIST ;
			pItem = ring_list_getitem(pVM->pActiveMem,ring_list_getsize(pVM->pActiveMem));
			/* Increase the References count for the item */
			ring_vm_gc_newitemreference(pItem);
			ring_list_setpointer_gc(pVM->pRingState,pList,RING_VAR_VALUE,pItem);
			ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_PVALUETYPE,RING_OBJTYPE_LISTITEM);
			/* The variable value will be a list contains the pointer */
			ring_list_addpointer_gc(pVM->pRingState,pList2,NULL);
			/* Add the pointer type */
			ring_list_addstring_gc(pVM->pRingState,pList2,"NULLPOINTER");
			/* Add the status number ( 0 = Not Copied ,1 = Copied  2 = Not Assigned yet) */
			ring_list_addint_gc(pVM->pRingState,pList2,RING_CPOINTERSTATUS_NOTASSIGNED);
			return 1 ;
		}
	}
	return 0 ;
}

RING_API void * ring_vm_api_getcpointer2pointer ( void *pPointer,int x,const char *cType )
{
	List *pList  ;
	Item *pItem  ;
	if ( RING_API_ISLIST(x) ) {
		pList = RING_API_GETLIST(x) ;
		if ( ring_list_ispointer(pList,1) ) {
			if ( ring_list_getpointer(pList,1) != NULL ) {
				if ( (strcmp(ring_list_getstring(pList,2),cType) == 0) || (((VM *) pPointer)->nIgnoreCPointerTypeCheck==1) ) {
					/*
					**  Check if the pointer is copied or not 
					**  We check for 2 (not assigned) also, happens when f1 ( x , f2() ) and f2 return C pointer 
					*/
					if ( (ring_list_getint(pList,3) == 0) || (ring_list_getint(pList,3) == 2) ) {
						pItem = ring_list_getitem(pList,1);
						return & (pItem->data.pPointer) ;
					}
					ring_list_setpointer_gc(((VM *) pPointer)->pRingState,pList,1,NULL);
					RING_API_ERROR(RING_API_NULLPOINTER);
					return NULL ;
				}
				RING_API_ERROR(RING_API_BADPARATYPE);
				return NULL ;
			}
			else {
				if ( strcmp(ring_list_getstring(pList,2),"NULLPOINTER") == 0 ) {
					return NULL ;
				}
			}
			RING_API_ERROR(RING_API_NULLPOINTER);
			return NULL ;
		}
	}
	RING_API_ERROR(RING_API_NOTPOINTER);
	return NULL ;
}

RING_API void ring_list_addcpointer_gc ( void *pState,List *pList,void *pGeneral,const char *cType )
{
	List *pList2  ;
	/* create sub list */
	pList2 = ring_list_newlist_gc(pState,pList);
	/* The variable value will be a list contains the pointer */
	ring_list_addpointer_gc(pState,pList2,pGeneral);
	/* Add the pointer type */
	ring_list_addstring_gc(pState,pList2,cType);
	/* Add the status number ( 0 = Not Copied ,1 = Copied  2 = Not Assigned yet) */
	ring_list_addint_gc(pState,pList2,2);
}

RING_API void ring_vm_api_retcpointer ( void *pPointer,void *pGeneral,const char *cType )
{
	ring_vm_api_retcpointer2(pPointer,pGeneral,cType,NULL);
}

RING_API void ring_vm_api_retlist2 ( void *pPointer,List *pList,int lRef )
{
	List *pList2,*pList3  ;
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	pList2 = ring_vm_prevtempmem(pVM);
	pList3 = ring_vm_newvar2(pVM,RING_TEMP_VARIABLE,pList2);
	ring_list_setint_gc(((VM *) pPointer)->pRingState,pList3,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist_gc(((VM *) pPointer)->pRingState,pList3,RING_VAR_VALUE);
	pList2 = ring_list_getlist(pList3,RING_VAR_VALUE);
	/* Copy the list */
	if ( lRef == 0 ) {
		ring_vm_list_copy((VM *) pPointer,pList2,pList);
	}
	else {
		ring_list_swaptwolists(pList,pList2);
		pList2->lCopyByRef = 1 ;
	}
	RING_API_PUSHPVALUE(pList3);
	RING_API_OBJTYPE = RING_OBJTYPE_VARIABLE ;
}
/*
**  Library 
**  General 
*/

void ring_vmlib_len ( void *pPointer )
{
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETNUMBER(RING_API_GETSTRINGSIZE(1));
	}
	else if ( RING_API_ISLIST(1) ) {
		if ( ring_vm_oop_isobject(RING_API_GETLIST(1)) == 0 ) {
			RING_API_RETNUMBER(ring_list_getsize(RING_API_GETLIST(1)));
		}
		else {
			RING_VM_STACK_PUSHPVALUE(RING_API_GETPOINTER(1));
			RING_VM_STACK_OBJTYPE = RING_API_GETPOINTERTYPE(1) ;
			ring_vm_expr_npoo(pVM,"len",0);
			pVM->nIgnoreNULL = 1 ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_clock ( void *pPointer )
{
	clock_t nNum1  ;
	nNum1 = clock();
	RING_API_RETNUMBER((double) nNum1);
}

void ring_vmlib_input ( void *pPointer )
{
	char *cLine  ;
	int nSize,nOutput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		nSize = RING_API_GETNUMBER(1);
	}
	else if ( RING_API_ISSTRING(1) ) {
		nSize = ring_vm_stringtonum((VM *) pPointer,RING_API_GETSTRING(1));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( nSize > 0 ) {
		cLine = (char *) ring_state_malloc(((VM *) pPointer)->pRingState,nSize);
		if ( cLine == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		/* Get Input From the User and save it in the variable */
		nOutput = RING_SETBINARY ;
		fread( cLine , sizeof(char) , nSize , stdin );
		/* Return String */
		RING_API_RETSTRING2(cLine,nSize);
		ring_state_free(((VM *) pPointer)->pRingState,cLine);
	}
	else {
		RING_API_ERROR("Error in first parameter,  input size < 1 !");
	}
}

void ring_vmlib_ascii ( void *pPointer )
{
	int x  ;
	unsigned char *cString  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( RING_API_GETSTRINGSIZE(1) == 1 ) {
			cString = (unsigned char *) RING_API_GETSTRING(1) ;
			x = (int) cString[0] ;
			RING_API_RETNUMBER(x);
		}
		else {
			RING_API_ERROR("Error in first parameter, the string size is not one letter !");
			return ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_char ( void *pPointer )
{
	int x  ;
	char cStr[2]  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		x = RING_API_GETNUMBER(1) ;
		cStr[0] = (char) x ;
		cStr[1] = '\0' ;
		RING_API_RETSTRING2(cStr,1);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_date ( void *pPointer )
{
	time_t timer  ;
	char buffer[25]  ;
	struct tm*tm_info  ;
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer,25,"%d/%m/%Y", tm_info);
	RING_API_RETSTRING(buffer);
}

void ring_vmlib_time ( void *pPointer )
{
	time_t timer  ;
	char buffer[25]  ;
	struct tm*tm_info  ;
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer,25,"%H:%M:%S", tm_info);
	RING_API_RETSTRING(buffer);
}

void ring_vmlib_filename ( void *pPointer )
{
	VM *pVM  ;
	List *pList  ;
	int lFunctionCall,x  ;
	const char *cOldFile  ;
	const char *cFile  ;
	pVM = (VM *) pPointer ;
	/* Get the current file name */
	cOldFile = NULL ;
	cFile = NULL ;
	lFunctionCall = 0 ;
	for ( x = ring_list_getsize(pVM->pFuncCallList) ; x >= 1 ; x-- ) {
		pList = ring_list_getlist(pVM->pFuncCallList,x);
		/*
		**  If we have ICO_LoadFunc but not ICO_CALL then we need to pass 
		**  ICO_LOADFUNC is executed, but still ICO_CALL is not executed! 
		*/
		if ( ring_list_getsize(pList) < RING_FUNCCL_CALLERPC ) {
			cOldFile = (const char *) ring_list_getpointer(pList,RING_FUNCCL_FILENAME) ;
			continue ;
		}
		if ( ring_list_getint(pList,RING_FUNCCL_TYPE) == RING_FUNCTYPE_SCRIPT ) {
			lFunctionCall = 1 ;
		}
	}
	if ( lFunctionCall ) {
		cFile = ring_list_getstring(pVM->pRingState->pRingFilesList,1) ;
	}
	else {
		if ( pVM->nInClassRegion ) {
			cFile = pVM->cFileNameInClassRegion ;
		}
		else {
			if ( cOldFile == NULL ) {
				cFile = pVM->cFileName ;
			}
			else {
				cFile = cOldFile ;
			}
		}
	}
	RING_API_RETSTRING(cFile);
}

void ring_vmlib_getchar ( void *pPointer )
{
	char cStr[2]  ;
	int nOutput  ;
	nOutput = RING_SETBINARY ;
	cStr[0] = getchar() ;
	RING_API_RETSTRING2(cStr,1);
}

void ring_vmlib_system ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		system(RING_API_GETSTRING(1));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_random ( void *pPointer )
{
	int nNum1,nNum2  ;
	nNum1 = rand() ;
	if ( RING_API_PARACOUNT == 0 ) {
		RING_API_RETNUMBER(nNum1);
	}
	else if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
			nNum2 = RING_API_GETNUMBER(1) ;
			if ( nNum2 > 0 ) {
				RING_API_RETNUMBER(nNum1 % ++nNum2);
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

void ring_vmlib_timelist ( void *pPointer )
{
	time_t timer  ;
	char buffer[25]  ;
	struct tm*tm_info  ;
	List *pList  ;
	pList = RING_API_NEWLIST ;
	time(&timer);
	tm_info = localtime(&timer);
	/*
	**  Add List Items 
	**  abbreviated weekday name 
	*/
	strftime(buffer,25,"%a", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* full weekday name */
	strftime(buffer,25,"%A", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* abbreviated month name */
	strftime(buffer,25,"%b", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* full month name */
	strftime(buffer,25,"%B", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Date & Time */
	strftime(buffer,25,"%c", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Day of the month */
	strftime(buffer,25,"%d", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Hour (24) */
	strftime(buffer,25,"%H", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Hour (12) */
	strftime(buffer,25,"%I", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Day of the year */
	strftime(buffer,25,"%j", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Month of the year */
	strftime(buffer,25,"%m", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Minutes after hour */
	strftime(buffer,25,"%M", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* AM or PM */
	strftime(buffer,25,"%p", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Seconds after the hour */
	strftime(buffer,25,"%S", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* Week of the year (sun-sat) */
	strftime(buffer,25,"%U", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* day of the week */
	strftime(buffer,25,"%w", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* date */
	strftime(buffer,25,"%x", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* time */
	strftime(buffer,25,"%X", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* year of the century */
	strftime(buffer,25,"%y", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* year */
	strftime(buffer,25,"%Y", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* time zone */
	strftime(buffer,25,"%Z", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	/* percent sign */
	strftime(buffer,25,"%%", tm_info);
	ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,buffer);
	RING_API_RETLIST(pList);
}

void ring_vmlib_adddays ( void *pPointer )
{
	const unsigned char *cStr  ;
	char buffer[25]  ;
	int x,nDay,nMonth,nYear,nDaysInMonth  ;
	int aDaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! (RING_API_ISSTRING(1) && RING_API_ISNUMBER(2)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cStr = (const unsigned char *) RING_API_GETSTRING(1) ;
	if ( (RING_API_GETSTRINGSIZE(1) == 10) ) {
		if ( isalnum(cStr[0]) && isalnum(cStr[1]) && isalnum(cStr[3]) && isalnum(cStr[4]) && isalnum(cStr[6]) && isalnum(cStr[7]) && isalnum(cStr[8]) && isalnum(cStr[9]) ) {
			sprintf( buffer , "%c%c" , cStr[0],cStr[1] ) ;
			nDay = atoi(buffer) + ((int) RING_API_GETNUMBER(2)) ;
			sprintf( buffer , "%c%c" , cStr[3],cStr[4] ) ;
			nMonth = atoi(buffer) ;
			sprintf( buffer , "%c%c%c%c" , cStr[6],cStr[7],cStr[8],cStr[9] ) ;
			nYear = atoi(buffer) ;
			/* Fix Day Number */
			nDaysInMonth = aDaysInMonth[nMonth-1] ;
			/* Fix Leap Year */
			if ( (nMonth == 2) && (ring_vmlib_adddays_isleapyear(nYear)) ) {
				nDaysInMonth = 29 ;
			}
			while ( nDay > nDaysInMonth ) {
				nDay = nDay - nDaysInMonth ;
				nMonth++ ;
				if ( nMonth == 13 ) {
					nMonth = 1 ;
					nYear++ ;
				}
				nDaysInMonth = aDaysInMonth[nMonth-1] ;
				/* Fix Leap Year */
				if ( (nMonth == 2) && (ring_vmlib_adddays_isleapyear(nYear)) ) {
					nDaysInMonth = 29 ;
				}
			}
			while ( nDay < 1 ) {
				nMonth-- ;
				if ( nMonth == 0 ) {
					nMonth = 12 ;
					nYear-- ;
				}
				nDaysInMonth = aDaysInMonth[nMonth-1] ;
				/* Fix Leap Year */
				if ( (nMonth == 2) && (ring_vmlib_adddays_isleapyear(nYear)) ) {
					nDaysInMonth = 29 ;
				}
				nDay = nDaysInMonth - abs(nDay) ;
			}
			sprintf(buffer,"%2d/%2d/%4d", nDay,nMonth,nYear);
			for ( x = 0 ; x <= 9 ; x++ ) {
				if ( buffer[x] == ' ' ) {
					buffer[x] = '0' ;
				}
			}
			RING_API_RETSTRING(buffer);
			return ;
		}
	}
	RING_API_ERROR(RING_API_BADPARATYPE);
	return ;
}

void ring_vmlib_diffdays ( void *pPointer )
{
	const unsigned char *cStr, *cStr2  ;
	struct tm tm_info,tm_info2  ;
	time_t timer,timer2  ;
	char buffer[5]  ;
	double nResult  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! (RING_API_ISSTRING(1) && RING_API_ISSTRING(2)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cStr = (const unsigned char *) RING_API_GETSTRING(1) ;
	cStr2 = (const unsigned char *) RING_API_GETSTRING(2) ;
	if ( (RING_API_GETSTRINGSIZE(1) == 10) && (RING_API_GETSTRINGSIZE(2) == 10) ) {
		if ( isalnum(cStr[0]) && isalnum(cStr[1]) && isalnum(cStr[3]) && isalnum(cStr[4]) && isalnum(cStr[6]) && isalnum(cStr[7]) && isalnum(cStr[8]) && isalnum(cStr[9]) ) {
			tm_info.tm_hour = 0 ;
			tm_info.tm_min = 0 ;
			tm_info.tm_sec = 0 ;
			sprintf( buffer , "%c%c" , cStr[0],cStr[1] ) ;
			tm_info.tm_mday = atoi(buffer) ;
			sprintf( buffer , "%c%c" , cStr[3],cStr[4] ) ;
			tm_info.tm_mon = atoi(buffer)-1 ;
			sprintf( buffer , "%c%c%c%c" , cStr[6],cStr[7],cStr[8],cStr[9] ) ;
			tm_info.tm_year = atoi(buffer) - 1900 ;
			timer = mktime(&tm_info);
			if ( tm_info.tm_year > 1097 ) {
				/*
				**  1097 + 1900 = 2997 
				**  Values over limit may cause crash 
				*/
				RING_API_ERROR(RING_API_BADPARARANGE);
				return ;
			}
			if ( isalnum(cStr2[0]) && isalnum(cStr2[1]) && isalnum(cStr2[3]) && isalnum(cStr2[4]) && isalnum(cStr2[6]) && isalnum(cStr2[7]) && isalnum(cStr2[8]) && isalnum(cStr2[9]) ) {
				tm_info2.tm_hour = 0 ;
				tm_info2.tm_min = 0 ;
				tm_info2.tm_sec = 0 ;
				sprintf( buffer , "%c%c" , cStr2[0],cStr2[1] ) ;
				tm_info2.tm_mday = atoi(buffer) ;
				sprintf( buffer , "%c%c" , cStr2[3],cStr2[4] ) ;
				tm_info2.tm_mon = atoi(buffer)-1 ;
				sprintf( buffer , "%c%c%c%c" , cStr2[6],cStr2[7],cStr2[8],cStr2[9] ) ;
				tm_info2.tm_year = atoi(buffer) - 1900 ;
				timer2 = mktime(&tm_info2);
				if ( tm_info2.tm_year > 1097 ) {
					/*
					**  1097 + 1900 = 2997 
					**  Values over limit may cause crash 
					*/
					RING_API_ERROR(RING_API_BADPARARANGE);
					return ;
				}
				nResult = difftime(timer,timer2);
				nResult  = ceil(ceil(nResult) / 86400 ) ;
				RING_API_RETNUMBER(nResult);
				return ;
			}
		}
	}
	RING_API_ERROR(RING_API_BADPARATYPE);
	return ;
}

void ring_vmlib_version ( void *pPointer )
{
	RING_API_RETSTRING(RING_STATE_VERSION);
}

void ring_vmlib_clockspersecond ( void *pPointer )
{
	RING_API_RETNUMBER(CLOCKS_PER_SEC);
}

void ring_vmlib_prevfilename ( void *pPointer )
{
	RING_API_RETSTRING(((VM *) pPointer)->cPrevFileName);
}

int ring_vmlib_adddays_isleapyear ( int nYear )
{
	if ( nYear%400 == 0 ) {
		return 1 ;
	}
	if ( nYear%100 == 0 ) {
		return 0 ;
	}
	return nYear % 4 == 0 ;
}

void ring_vmlib_shutdown ( void *pPointer )
{
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
			exit(RING_API_GETNUMBER(1));
			return ;
		}
	}
	exit(0);
}

void ring_vmlib_srandom ( void *pPointer )
{
	int nNum1  ;
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
			nNum1 = RING_API_GETNUMBER(1) ;
			if ( nNum1 >= 0 ) {
				srand(nNum1);
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
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}
/* Check Data Type */

void ring_vmlib_isstring ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETNUMBER(1);
	}
	else {
		RING_API_RETNUMBER(0);
	}
}

void ring_vmlib_isnumber ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETNUMBER(1);
	}
	else {
		RING_API_RETNUMBER(0);
	}
}

void ring_vmlib_islist ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		if ( (ring_vm_oop_isobject(RING_API_GETLIST(1) ) == 0) && (RING_API_ISCPOINTER(1) == 0) ) {
			RING_API_RETNUMBER(1);
			return ;
		}
	}
	RING_API_RETNUMBER(0);
}

void ring_vmlib_type ( void *pPointer )
{
	List *pList  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	/* The order of checking C Pointer and OBJECT before List is important because the list can be both of them */
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETSTRING("STRING");
	}
	else if ( RING_API_ISNUMBER(1) ) {
		RING_API_RETSTRING("NUMBER");
	}
	else if ( RING_API_ISCPOINTER(1) ) {
		pList = RING_API_GETLIST(1) ;
		RING_API_RETSTRING(ring_list_getstring(pList,RING_CPOINTER_TYPE));
	}
	else if ( RING_API_ISOBJECT(1) ) {
		RING_API_RETSTRING("OBJECT");
	}
	else if ( RING_API_ISLIST(1) ) {
		RING_API_RETSTRING("LIST");
	}
	else {
		RING_API_RETSTRING("UNKNOWN");
	}
}

void ring_vmlib_isnull ( void *pPointer )
{
	char *cStr  ;
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( strcmp(RING_API_GETSTRING(1),"") == 0 ) {
			RING_API_RETNUMBER(1);
			return ;
		}
		else if ( RING_API_GETSTRINGSIZE(1) == 4 ) {
			cStr = RING_API_GETSTRING(1) ;
			if ( (cStr[0] == 'n' || cStr[0] == 'N') && (cStr[1] == 'u' || cStr[1] == 'U') && (cStr[2] == 'l' || cStr[2] == 'L') && (cStr[3] == 'l' || cStr[3] == 'L') ) {
				RING_API_RETNUMBER(1);
				return ;
			}
		}
	}
	else if ( RING_API_ISCPOINTER(1) ) {
		if ( ring_list_getpointer(RING_API_GETLIST(1),RING_CPOINTER_POINTER) == NULL ) {
			RING_API_RETNUMBER(1);
			return ;
		}
	}
	RING_API_RETNUMBER(0);
}

void ring_vmlib_isobject ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		if ( ring_vm_oop_isobject(RING_API_GETLIST(1) ) == 1 ) {
			RING_API_RETNUMBER(1);
			return ;
		}
	}
	RING_API_RETNUMBER(0);
}

void ring_vmlib_ispointer ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		if ( RING_API_ISCPOINTER(1) ) {
			RING_API_RETNUMBER(1);
			return ;
		}
	}
	RING_API_RETNUMBER(0);
}
/* Conversion */

void ring_vmlib_hex ( void *pPointer )
{
	char cStr[100]  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		sprintf( cStr , RING_UNSIGNEDLONGLONG_FORMAT , (RING_UNSIGNEDLONGLONG) RING_API_GETNUMBER(1) ) ;
		RING_API_RETSTRING(cStr);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_dec ( void *pPointer )
{
	RING_UNSIGNEDLONGLONG x  ;
	int nOutput  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		nOutput = sscanf(RING_API_GETSTRING(1),RING_UNSIGNEDLONGLONG_FORMAT,&x);
		/* Display error if nOutput is Zero which means that sscanf() function failed to convert any character */
		if ( (nOutput == EOF) || (nOutput == 0) ) {
			RING_API_ERROR(RING_SSCANFERROR);
			return ;
		}
		RING_API_RETNUMBER(x);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_number ( void *pPointer )
{
	double x  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		x = ring_vm_stringtonum((VM *) pPointer,RING_API_GETSTRING(1));
		RING_API_RETNUMBER(x);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_string ( void *pPointer )
{
	double nNum1  ;
	char cStr[100]  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		nNum1 = RING_API_GETNUMBER(1);
		ring_vm_numtostring((VM *) pPointer, nNum1,cStr);
		RING_API_RETSTRING(cStr);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_str2hex ( void *pPointer )
{
	unsigned char *cString  ;
	int x,nMax  ;
	char *cString2  ;
	unsigned char bVal  ;
	static const char cHexChars[] = "0123456789abcdef" ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cString = (unsigned char *) RING_API_GETSTRING(1) ;
		nMax = RING_API_GETSTRINGSIZE(1) ;
		/* Pre-allocated the return value on the stack */
		RING_API_RETSTRINGSIZE(nMax*2);
		cString2 = ring_string_get(RING_API_GETSTRINGRAW);
		for ( x = 1 ; x <= nMax ; x++ ) {
			bVal = cString[x-1] ;
			cString2[(x-1)*2] = cHexChars[bVal >> 4] ;
			cString2[((x-1)*2)+1] = cHexChars[bVal & 0x0F] ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

unsigned char ring_vmlib_hex2str_hex2nibble ( char cVal )
{
	unsigned char bVal = 0 ;
	if ( cVal >= '0' && cVal <= '9' ) {
		bVal = cVal - '0' ;
	}
	else if ( cVal >= 'a' && cVal <= 'f' ) {
		bVal = cVal - 'a' + 10 ;
	}
	else if ( cVal >= 'A' && cVal <= 'F' ) {
		bVal = cVal - 'A' + 10 ;
	}
	else {
		bVal = 0xFF ;
	}
	return bVal ;
}

void ring_vmlib_hex2str ( void *pPointer )
{
	char cStr[3]  ;
	const char *cString  ;
	char *cString2  ;
	int x,i,nMax  ;
	unsigned char bVal, bNibble  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cString = RING_API_GETSTRING(1) ;
		nMax = RING_API_GETSTRINGSIZE(1) ;
		/* Check the String Size (The implementation expects even number of characters) */
		if ( nMax % 2 != 0 ) {
			RING_API_ERROR(RING_API_BADPARALENGTH);
			return ;
		}
		/* Pre-allocated the return value on the stack */
		RING_API_RETSTRINGSIZE(nMax/2);
		cString2 = ring_string_get(RING_API_GETSTRINGRAW);
		i = 0 ;
		for ( x = 0 ; x < nMax ; x+=2 ) {
			bNibble = ring_vmlib_hex2str_hex2nibble(cString[x]);
			if ( bNibble != 0xFF ) {
				bVal = bNibble ;
				if ( cString[x+1]   != ' ' ) {
					bNibble = ring_vmlib_hex2str_hex2nibble(cString[x+1]);
					if ( bNibble != 0xFF ) {
						bVal = (bVal << 4) + bNibble ;
					}
				}
			}
			if ( bNibble == 0xFF ) {
				RING_API_ERROR(RING_API_BADPARAVALUE);
				return ;
			}
			cString2[i] = (char) bVal ;
			i++ ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_str2list ( void *pPointer )
{
	char *cStr  ;
	int x,nSize,nStart  ;
	List *pList  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		nStart = 0 ;
		pList = RING_API_NEWLIST ;
		for ( x = 0 ; x < nSize ; x++ ) {
			if ( cStr[x] == '\n' ) {
				if ( x > nStart ) {
					if ( cStr[x-1] == '\r' ) {
						ring_list_addstring2_gc(((VM *) pPointer)->pRingState,pList,cStr+nStart,x-nStart-1);
					}
					else {
						ring_list_addstring2_gc(((VM *) pPointer)->pRingState,pList,cStr+nStart,x-nStart);
					}
				}
				else {
					ring_list_addstring_gc(((VM *) pPointer)->pRingState,pList,"");
				}
				nStart = x+1 ;
			}
		}
		if ( nSize > nStart ) {
			ring_list_addstring2_gc(((VM *) pPointer)->pRingState,pList,cStr+nStart,nSize-nStart);
		}
		RING_API_RETLIST(pList);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_list2str ( void *pPointer )
{
	List *pList  ;
	String *pString  ;
	int x  ;
	char cStr[100]  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISLIST(1) ) {
		pList = RING_API_GETLIST(1) ;
		pString = ring_string_new_gc(((VM *) pPointer)->pRingState,"");
		for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
			if ( ring_list_isstring(pList,x) ) {
				if ( x != 1 ) {
					ring_string_add_gc(((VM *) pPointer)->pRingState,pString,"\n");
				}
				ring_string_add_gc(((VM *) pPointer)->pRingState,pString,ring_list_getstring(pList,x));
			}
			else if ( ring_list_isnumber(pList,x) ) {
				if ( x != 1 ) {
					ring_string_add_gc(((VM *) pPointer)->pRingState,pString,"\n");
				}
				ring_vm_numtostring((VM *) pPointer,ring_list_getdouble(pList,x) ,cStr);
				ring_string_add_gc(((VM *) pPointer)->pRingState,pString,cStr);
			}
		}
		RING_API_RETSTRING(ring_string_get(pString));
		ring_string_delete_gc(((VM *) pPointer)->pRingState,pString);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_str2hexcstyle ( void *pPointer )
{
	char cStr[3]  ;
	unsigned char *cString  ;
	int x,nMax  ;
	char *cString2  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cString = (unsigned char *) RING_API_GETSTRING(1) ;
		nMax = RING_API_GETSTRINGSIZE(1) ;
		cString2 = (char *) ring_state_malloc(((VM *) pPointer)->pRingState,nMax*5);
		if ( cString2 == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		for ( x = 1 ; x <= nMax ; x++ ) {
			sprintf( cStr , "%x" , (unsigned char) cString[x-1] ) ;
			/* Separator */
			cString2[(x-1)*5] = ',' ;
			cString2[(x-1)*5+1] = '0' ;
			cString2[(x-1)*5+2] = 'x' ;
			cString2[(x-1)*5+3] = cStr[0] ;
			if ( cStr[1] != '\0' ) {
				cString2[((x-1)*5)+4] = cStr[1] ;
			}
			else {
				cString2[((x-1)*5)+4] = ' ' ;
			}
		}
		/* Pass the first letter to avoid the first comma */
		cString2++ ;
		RING_API_RETSTRING2(cString2,nMax*5-1);
		/* When we call free() we use the original pointer */
		cString2-- ;
		ring_state_free(((VM *) pPointer)->pRingState,cString2);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* String */

void ring_vmlib_left ( void *pPointer )
{
	double nNum1  ;
	const char *cStr  ;
	int x,nNewSize  ;
	char *pString  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( RING_API_ISNUMBER(2) ) {
			cStr = RING_API_GETSTRING(1) ;
			nNum1 = RING_API_GETNUMBER(2) ;
			if ( (nNum1 > 0 ) && (nNum1 <= RING_API_GETSTRINGSIZE(1) ) ) {
				nNewSize = (int) nNum1 ;
				/* Pre-allocated the return value on the stack */
				RING_API_RETSTRINGSIZE(nNewSize);
				pString = ring_string_get(RING_API_GETSTRINGRAW);
				RING_MEMCPY(pString,cStr,nNewSize);
			}
		}
		else {
			RING_API_ERROR("Error in second parameter, Function requires number !");
			return ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_right ( void *pPointer )
{
	double nNum1  ;
	const char *cStr  ;
	int x,nSize,nNewSize  ;
	char *pString  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( RING_API_ISNUMBER(2) ) {
			cStr = RING_API_GETSTRING(1) ;
			nNum1 = RING_API_GETNUMBER(2) ;
			nSize = RING_API_GETSTRINGSIZE(1) ;
			if ( (nNum1 > 0 ) && (nNum1 <= nSize ) ) {
				nNewSize = (int) nNum1 ;
				/* Pre-allocated the return value on the stack */
				RING_API_RETSTRINGSIZE(nNewSize);
				pString = ring_string_get(RING_API_GETSTRINGRAW);
				RING_MEMCPY(pString,cStr+(nSize-nNewSize),nNewSize);
			}
		}
		else {
			RING_API_ERROR("Error in second parameter, Function requires number !");
			return ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_trim ( void *pPointer )
{
	const char *cStr  ;
	int x,nSize,nPos1,nPos2  ;
	char *cNewStr  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		if ( nSize == 0 ) {
			RING_API_RETSTRING("");
			return ;
		}
		/* Get Limits */
		nPos1 = 0 ;
		nPos2 = nSize-1 ;
		for ( x = 0 ; x < nSize ; x++ ) {
			if ( cStr[x] != ' ' ) {
				nPos1 = x ;
				break ;
			}
		}
		for ( x = nSize-1 ; x  >= 0 ; x-- ) {
			if ( cStr[x] != ' ' ) {
				nPos2 = x ;
				break ;
			}
		}
		if ( (nPos1 == 0) && (nPos2 == nSize-1) && (cStr[0] == ' ') ) {
			RING_API_RETSTRING("");
			return ;
		}
		/* Pre-allocated the return value on the stack */
		RING_API_RETSTRINGSIZE(nPos2-nPos1+1);
		cNewStr = ring_string_get(RING_API_GETSTRINGRAW);
		if ( nPos2-nPos1+1 < RING_LOOP_THRESHOLD ) {
			for ( x = nPos1 ; x <= nPos2 ; x++ ) {
				cNewStr[x-nPos1] = cStr[x] ;
			}
		}
		else {
			memcpy(cNewStr,cStr+nPos1, nPos2-nPos1+1);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_copy ( void *pPointer )
{
	const char *cStr  ;
	int x,nSize,nStrSize,nPos,i  ;
	char *cRetStr  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( RING_API_ISNUMBER(2) ) {
			cStr = RING_API_GETSTRING(1) ;
			nStrSize = RING_API_GETSTRINGSIZE(1) ;
			nSize = RING_API_GETNUMBER(2) ;
			/* Pre-allocated the return value on the stack */
			RING_API_RETSTRINGSIZE(nSize * nStrSize);
			cRetStr = ring_string_get(RING_API_GETSTRINGRAW);
			nPos = 0 ;
			/* Copy the input string nSize times */
			for ( i = 1 ; i <= nSize ; i++ ) {
				RING_MEMCPY(cRetStr+nPos,cStr,nStrSize);
				nPos += nStrSize ;
			}
		}
		else {
			RING_API_ERROR("Error in second parameter, Function requires number !");
			return ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_substr ( void *pPointer )
{
	char *cStr,*cStr2,*cStr3,*cString  ;
	double nNum1,nNum2  ;
	unsigned int nParaCount,x,nPos,nMark,nSize,nTransform,nSize2  ;
	String *pString  ;
	/*
	**  Usage 
	**  Substr(str,10) get substring from 10 to end 
	**  Substr(str,"nice") get position of "nice" inside str 
	**  Substr(str,10,15) get substring from 10 , get 15 characters 
	**  Substr(str,"nice","good") replace "nice" with "good" 
	**  Substr(str,"nice","good",true) replace "nice" with "good" - not case sensitive 
	**  Parameters Count 
	*/
	nParaCount = RING_API_PARACOUNT ;
	/* If parameter no. 4 is not True, Treat the case as we get 3 paramters only */
	if ( nParaCount == 4 ) {
		if ( RING_API_ISNUMBER(4) ) {
			if ( RING_API_GETNUMBER(4)  == 0.0 ) {
				nParaCount = 3 ;
			}
		}
	}
	/* Get String  (First Parameter) */
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
	}
	else {
		RING_API_ERROR("Error in first parameter, Function requires string !");
		return ;
	}
	/* Process */
	nTransform = 0 ;
	if ( nParaCount == 2 ) {
		if ( RING_API_ISNUMBER(2) ) {
			nNum1 = RING_API_GETNUMBER(2) ;
			if ( nNum1 > 0 && nNum1 <= nSize ) {
				cStr2 = cStr + ( (int) nNum1 ) - 1 ;
				RING_API_RETSTRING2(cStr2,nSize-nNum1+1);
				return ;
			}
		}
		else if ( RING_API_ISSTRING(2) ) {
			cStr2 = RING_API_GETSTRING(2) ;
			nSize2 = RING_API_GETSTRINGSIZE(2) ;
			cStr3 = ring_string_find2(cStr,nSize,cStr2,nSize2);
			if ( cStr3 != NULL ) {
				nNum1 = ((RING_LONGLONG) cStr3) - ((RING_LONGLONG) cStr) + 1 ;
			}
			else {
				nNum1 = 0.0 ;
			}
			RING_API_RETNUMBER(nNum1);
		}
		else {
			RING_API_ERROR("Error in second parameter type!");
			return ;
		}
	}
	else if ( nParaCount == 3 ) {
		if ( RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3) ) {
			nNum1 = RING_API_GETNUMBER(2) ;
			nNum2 = RING_API_GETNUMBER(3) ;
			if ( (nNum1 > 0) && ( (nNum1+nNum2-1) <= nSize ) ) {
				cString = (char *) ring_state_malloc(((VM *) pPointer)->pRingState,nNum2);
				if ( cString == NULL ) {
					RING_API_ERROR(RING_OOM);
					return ;
				}
				for ( x = 0 ; x < nNum2 ; x++ ) {
					cString[x] = cStr[((int) nNum1) + x - 1 ] ;
				}
				RING_API_RETSTRING2(cString,nNum2);
				ring_state_free(((VM *) pPointer)->pRingState,cString);
			}
		}
		else if ( RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
			nTransform = 1 ;
		}
		else {
			RING_API_ERROR("Error in parameters type!");
			return ;
		}
	}
	else if ( nParaCount == 4 ) {
		if ( RING_API_ISSTRING(2) && RING_API_ISSTRING(3) && RING_API_ISNUMBER(4) ) {
			if ( RING_API_GETNUMBER(4)  == 1.0 ) {
				nTransform = 2 ;
			}
		}
		else {
			RING_API_ERROR("Error in parameters type!");
			return ;
		}
	}
	else {
		RING_API_ERROR("Error in parameters count!");
	}
	/* Transform/Replace */
	if ( nTransform > 0 ) {
		cStr2 = RING_API_GETSTRING(2) ;
		nSize2 = RING_API_GETSTRINGSIZE(2) ;
		/* Search */
		if ( nTransform == 1 ) {
			cString = ring_string_find2(cStr,nSize,cStr2,nSize2) ;
		}
		else {
			cString = ring_string_find3(cStr,nSize,cStr2,nSize2) ;
		}
		if ( cString == NULL ) {
			RING_API_RETSTRING(cStr);
			return ;
		}
		cStr3 = RING_API_GETSTRING(3) ;
		nMark = 0 ;
		pString = ring_string_new_gc(((VM *) pPointer)->pRingState,"");
		while ( cString != NULL ) {
			nPos = (unsigned int)(((RING_LONGLONG) cString) - ((RING_LONGLONG) cStr) + 1) ;
			/* Add SubString to pString */
			ring_string_add2_gc(((VM *) pPointer)->pRingState,pString,cStr+nMark,nPos-1-nMark);
			ring_string_add2_gc(((VM *) pPointer)->pRingState,pString,cStr3,RING_API_GETSTRINGSIZE(3));
			nMark = nPos + nSize2 -1 ;
			/* Search */
			if ( nTransform == 1 ) {
				cString = ring_string_find2(cStr+((int) nMark),nSize-nMark,cStr2,nSize2) ;
			}
			else {
				cString = ring_string_find3(cStr+((int) nMark),nSize-nMark,cStr2,nSize2) ;
			}
			if ( cString == NULL ) {
				/* Add SubString to pString */
				ring_string_add2_gc(((VM *) pPointer)->pRingState,pString,cStr+nMark,nSize-nMark);
			}
		}
		RING_API_RETSTRING2(ring_string_get(pString),ring_string_size(pString));
		ring_string_delete_gc(((VM *) pPointer)->pRingState,pString);
	}
}

void ring_vmlib_lower ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETSTRING2(ring_string_lower2(RING_API_GETSTRING(1),RING_API_GETSTRINGSIZE(1)),RING_API_GETSTRINGSIZE(1));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_upper ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_RETSTRING2(ring_string_upper2(RING_API_GETSTRING(1),RING_API_GETSTRINGSIZE(1)),RING_API_GETSTRINGSIZE(1));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_lines ( void *pPointer )
{
	const char *cStr  ;
	int x,nSize,nCount  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		nCount = 1 ;
		for ( x = 0 ; x < nSize ; x++ ) {
			if ( cStr[x] == '\n' ) {
				nCount++ ;
			}
		}
		RING_API_RETNUMBER(nCount);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_strcmp ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) ) {
		RING_API_RETNUMBER(strcmp(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Functional */

void ring_vmlib_eval ( void *pPointer )
{
	const char *cStr  ;
	VM *pVM  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1);
		pVM = (VM *) pPointer ;
		pVM->nEvalCalledFromRingCode = 1 ;
		if ( pVM->lInsideEval == 0 ) {
			pVM->nRetEvalDontDelete = 0 ;
		}
		if ( ring_vm_eval(pVM,cStr) == 0 ) {
			pVM->nEvalCalledFromRingCode = 0 ;
		}
		/*
		**  The CALL instruction will check nEvalCalledFromRingCode to execute the main loop again 
		**  Before executing the main loop again, The CALL instruction will set nEvalCalledFromRingCode to 0 
		*/
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Error Handling */

void ring_vmlib_raise ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_GETSTRING(1));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_assert ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		if ( RING_API_GETNUMBER(1) != 1 ) {
			RING_API_ERROR("Assertion Failed!");
			return ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Check Characters */

void ring_vmlib_isfunc ( void *pPointer,int (*pFunc)(int) )
{
	char *cStr  ;
	int nSize,x  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1) ;
		nSize = RING_API_GETSTRINGSIZE(1) ;
		for ( x = 0 ; x < nSize ; x++ ) {
			if ( ! (*pFunc)(cStr[x]) ) {
				RING_API_RETNUMBER(0);
				return ;
			}
		}
		RING_API_RETNUMBER(1);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_isalnum ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isalnum);
}

void ring_vmlib_isalpha ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isalpha);
}

void ring_vmlib_iscntrl ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,iscntrl);
}

void ring_vmlib_isdigit ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isdigit);
}

void ring_vmlib_isgraph ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isgraph);
}

void ring_vmlib_islower ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,islower);
}

void ring_vmlib_isprint ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isprint);
}

void ring_vmlib_ispunct ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,ispunct);
}

void ring_vmlib_isspace ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isspace);
}

void ring_vmlib_isupper ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isupper);
}

void ring_vmlib_isxdigit ( void *pPointer )
{
	ring_vmlib_isfunc(pPointer,isxdigit);
}
/* Garbage Collector & Variable Pointer */

void ring_vmlib_callgc ( void *pPointer )
{
	ring_vm_gc_deletetemplists((VM *) pPointer);
}

void ring_vmlib_varptr ( void *pPointer )
{
	const char *cStr , *cStr2  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) ) {
		cStr = RING_API_GETSTRING(1);
		cStr2 = RING_API_GETSTRING(2);
		RING_API_RETCPOINTER(ring_vm_api_varptr(pPointer,cStr,cStr2),cStr2);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_intvalue ( void *pPointer )
{
	const char *cStr  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cStr = RING_API_GETSTRING(1);
		ring_vm_api_intvalue(pPointer,cStr);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_object2pointer ( void *pPointer )
{
	List *pList  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISLIST(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
	pList = RING_API_GETLIST(1) ;
	RING_API_RETCPOINTER((void *) pList,"OBJECTPOINTER");
}

void ring_vmlib_pointer2object ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
	RING_API_RETLIST((List *) RING_API_GETCPOINTER(1,"OBJECTPOINTER"));
}

void ring_vmlib_nullpointer ( void *pPointer )
{
	RING_API_RETCPOINTER(NULL,"NULLPOINTER");
}

void ring_vmlib_space ( void *pPointer )
{
	char *pString  ;
	unsigned int nStrSize  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		if ( RING_API_GETNUMBER(1) < 1.0 ) {
			RING_API_ERROR(RING_API_BADPARARANGE);
			return ;
		}
		nStrSize = (unsigned int) RING_API_GETNUMBER(1) ;
		pString = (char *) ring_state_malloc(((VM *) pPointer)->pRingState,nStrSize);
		if ( pString == NULL ) {
			printf( RING_OOM ) ;
			exit(0);
		}
		memset(pString,' ',nStrSize);
		RING_API_RETSTRING2(pString,nStrSize);
		ring_state_free(((VM *) pPointer)->pRingState,pString);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_ptrcmp ( void *pPointer )
{
	List *pList, *pList2  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) && RING_API_ISCPOINTER(2) ) {
		pList = RING_API_GETLIST(1) ;
		pList2 = RING_API_GETLIST(2) ;
		RING_API_RETNUMBER(ring_vm_api_cpointercmp(pList,pList2));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_pointer2string ( void *pPointer )
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! ( RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3) ) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
	RING_API_RETSTRING2(((const char *) RING_API_GETCPOINTER(1,"OBJECTPOINTER"))+((int) RING_API_GETNUMBER(2)),(int) RING_API_GETNUMBER(3));
}

void ring_vmlib_setpointer ( void *pPointer )
{
	List *pList  ;
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! ( RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2) ) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pList = RING_API_GETLIST(1) ;
	ring_list_setpointer(pList,RING_CPOINTER_POINTER,(void *) (size_t) RING_API_GETNUMBER(2));
}

void ring_vmlib_getpointer ( void *pPointer )
{
	List *pList  ;
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! ( RING_API_ISCPOINTER(1) ) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pList = RING_API_GETLIST(1) ;
	RING_API_RETNUMBER((size_t) ring_list_getpointer(pList,RING_CPOINTER_POINTER));
}

void ring_vmlib_memcpy ( void *pPointer )
{
	void *dest  ;
	const void *src  ;
	size_t num  ;
	List *pList  ;
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ( ! ( RING_API_ISCPOINTER(1) || RING_API_ISSTRING(1)) ) || ( ! ( RING_API_ISCPOINTER(2) || RING_API_ISSTRING(2)) ) || ( ! RING_API_ISNUMBER(3)) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	/* Get Parameters */
	if ( RING_API_ISSTRING(1) ) {
		dest = (void *) RING_API_GETSTRING(1) ;
	}
	if ( RING_API_ISCPOINTER(1) ) {
		pList = RING_API_GETLIST(1) ;
		dest = (void *) ring_list_getpointer(pList,RING_CPOINTER_POINTER) ;
	}
	if ( RING_API_ISSTRING(2) ) {
		src = (const void *) RING_API_GETSTRING(2) ;
	}
	if ( RING_API_ISCPOINTER(2) ) {
		pList = RING_API_GETLIST(2) ;
		src = (const void *) ring_list_getpointer(pList,RING_CPOINTER_POINTER) ;
	}
	num = (size_t) RING_API_GETNUMBER(3) ;
	/* Call Function */
	memcpy(dest,src,num);
}
/* Ring State */

void ring_vmlib_state_init ( void *pPointer )
{
	RingState *pState  ;
	pState = ring_state_init();
	pState->nRingInsideRing = 1 ;
	RING_API_RETCPOINTER((void *) pState,"RINGSTATE");
}

void ring_vmlib_state_runcode ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	ring_state_runcode((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
}

void ring_vmlib_state_delete ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ring_state_delete((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"));
}

void ring_vmlib_state_runfile ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	ring_state_runfile((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
}

void ring_vmlib_state_findvar ( void *pPointer )
{
	List *pList  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	pList = ring_state_findvar((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
	RING_API_RETLIST(pList);
}

void ring_vmlib_state_newvar ( void *pPointer )
{
	List *pList  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	pList = ring_state_newvar((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
	RING_API_RETLIST(pList);
}

void ring_vmlib_state_runobjectfile ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	ring_state_runobjectfile((RingState *) RING_API_GETCPOINTER(1,"RINGSTATE"),RING_API_GETSTRING(2));
}

void ring_vmlib_state_main ( void *pPointer )
{
	char *cStr  ;
	int argc  ;
	char *argv[2]  ;
	argv[0] = (char *) ring_state_malloc(((VM *) pPointer)->pRingState,100);
	argv[1] = (char *) ring_state_malloc(((VM *) pPointer)->pRingState,100);
	cStr = RING_API_GETSTRING(1);
	argc = 2 ;
	strcpy(argv[0],"ring");
	strcpy(argv[1],cStr);
	ring_state_execute(cStr,0,1,0,0,0,0,0,0,0,0,argc,argv);
	ring_state_free(((VM *) pPointer)->pRingState,argv[0]);
	ring_state_free(((VM *) pPointer)->pRingState,argv[1]);
}

void ring_vmlib_state_setvar ( void *pPointer )
{
	List *pList, *pList2, *pList3  ;
	VM *pVM  ;
	RingState *pRingSubState  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	/*
	**  It's very important to use pRingSubState instead of pRingState when using the Garbage Collector functions (*_gc()) 
	**  Because the Sub Ring State will own the memory values and will try to delete it in the end of the program 
	**  So we must create it with the Garbage Collector of this sub state 
	*/
	pRingSubState = (RingState *) RING_API_GETCPOINTER(1,"RINGSTATE") ;
	pList = ring_state_findvar(pRingSubState,RING_API_GETSTRING(2));
	/* Check Variable before usage */
	if ( pList==NULL ) {
		RING_API_ERROR("Variable doesn't exist!");
		return ;
	}
	if ( RING_API_ISSTRING(3) ) {
		ring_list_setint_gc(pRingSubState,pList, RING_VAR_TYPE ,RING_VM_STRING);
		ring_list_setstring2_gc(pRingSubState,pList, RING_VAR_VALUE , RING_API_GETSTRING(3),RING_API_GETSTRINGSIZE(3));
	}
	else if ( RING_API_ISNUMBER(3) ) {
		ring_list_setint_gc(pRingSubState,pList, RING_VAR_TYPE ,RING_VM_NUMBER);
		ring_list_setdouble_gc(pRingSubState,pList, RING_VAR_VALUE ,RING_API_GETNUMBER(3));
	}
	else if ( RING_API_ISLIST(3) ) {
		pList2 = RING_API_GETLIST(3) ;
		ring_list_setint_gc(pRingSubState,pList, RING_VAR_TYPE ,RING_VM_LIST);
		ring_list_setlist_gc(pRingSubState,pList, RING_VAR_VALUE);
		pList3 = ring_list_getlist(pList,RING_VAR_VALUE);
		ring_vm_list_copy(pRingSubState->pVM,pList3,pList2);
	}
}

void ring_vmlib_state_new ( void *pPointer )
{
	RingState *pState  ;
	pState = ring_state_new();
	pState->nRingInsideRing = 1 ;
	RING_API_RETCPOINTER((void *) pState,"RINGSTATE");
}

void ring_vmlib_state_mainfile ( void *pPointer )
{
	RingState *pRingState  ;
	char *cStr  ;
	int argc  ;
	char *argv[2]  ;
	argv[0] = (char *) ring_state_malloc(((VM *) pPointer)->pRingState,100);
	argv[1] = (char *) ring_state_malloc(((VM *) pPointer)->pRingState,100);
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	pRingState = (RingState *) RING_API_GETCPOINTER(1,"RINGSTATE") ;
	cStr = RING_API_GETSTRING(2);
	argc = 2 ;
	strcpy(argv[0],"ring");
	strcpy(argv[1],cStr);
	pRingState->argc = argc ;
	pRingState->argv = argv ;
	/*
	**  Don't Delete the VM after execution 
	**  We may run GUI app from GUI app 
	**  In this case the caller already called qApp.Exec() 
	**  Deleting the VM in sub program after execution 
	**  Will lead to crash when we execute events (like button click) in the sub program 
	**  So we keep the VM to avoid the Crash 
	*/
	pRingState->nDontDeleteTheVM = 1 ;
	ring_scanner_readfile(pRingState,cStr);
}

void ring_vmlib_state_filetokens ( void *pPointer )
{
	RingState *pState  ;
	char *cFile  ;
	List *pList  ;
	int lCase  ;
	if ( RING_API_PARACOUNT < 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	pState = (RingState *) RING_API_GETCPOINTER(1,"RINGSTATE") ;
	cFile = RING_API_GETSTRING(2);
	/* Check the (Not Case Sensitive) feature */
	lCase = 1 ;
	if ( RING_API_PARACOUNT == 3 ) {
		if ( RING_API_ISNUMBER(3) ) {
			lCase = (int) RING_API_GETNUMBER(3) ;
		}
	}
	pState->nOnlyTokens = 1 ;
	pState->lNotCaseSensitive = lCase ;
	ring_scanner_readfile(pState,cFile);
	pState->lNotCaseSensitive = 1 ;
	pState->nOnlyTokens = 0 ;
	/* Copy The List */
	pList = RING_API_NEWLIST ;
	ring_list_copy_tohighlevel_gc(((VM *) pPointer)->pRingState,pList,pState->pRingFileTokens);
	RING_API_RETLIST(pList);
	pState->pRingFileTokens = ring_list_delete_gc(pState,pState->pRingFileTokens);
}
/* Performance */

void ring_vmlib_checkoverflow ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		if ( RING_API_GETNUMBER(1) == 1 ) {
			((VM *) pPointer)->lCheckOverFlow = 1 ;
		}
		else {
			((VM *) pPointer)->lCheckOverFlow = 0 ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_addsublistsbymove ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		if ( RING_API_GETNUMBER(1) == 1 ) {
			((VM *) pPointer)->lAddSubListsByMove = 1 ;
		}
		else {
			((VM *) pPointer)->lAddSubListsByMove = 0 ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vmlib_addsublistsbyfastcopy ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) ) {
		if ( RING_API_GETNUMBER(1) == 1 ) {
			((VM *) pPointer)->lAddSubListsByFastCopy = 1 ;
		}
		else {
			((VM *) pPointer)->lAddSubListsByFastCopy = 0 ;
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
