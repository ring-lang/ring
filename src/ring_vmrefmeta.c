/*
**  Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#include "ring_vmrefmeta.h"
/* Functions */

void ring_vm_refmeta_loadfunctions ( RingState *pRingState )
{
	/* Functions */
	ring_vm_funcregister("locals",ring_vm_refmeta_locals);
	ring_vm_funcregister("globals",ring_vm_refmeta_globals);
	ring_vm_funcregister("functions",ring_vm_refmeta_functions);
	ring_vm_funcregister("cfunctions",ring_vm_refmeta_cfunctions);
	ring_vm_funcregister("islocal",ring_vm_refmeta_islocal);
	ring_vm_funcregister("isglobal",ring_vm_refmeta_isglobal);
	ring_vm_funcregister("isfunction",ring_vm_refmeta_isfunction);
	ring_vm_funcregister("iscfunction",ring_vm_refmeta_iscfunction);
	/* OOP */
	ring_vm_funcregister("packages",ring_vm_refmeta_packages);
	ring_vm_funcregister("ispackage",ring_vm_refmeta_ispackage);
	ring_vm_funcregister("classes",ring_vm_refmeta_classes);
	ring_vm_funcregister("isclass",ring_vm_refmeta_isclass);
	ring_vm_funcregister("packageclasses",ring_vm_refmeta_packageclasses);
	ring_vm_funcregister("ispackageclass",ring_vm_refmeta_ispackageclass);
	ring_vm_funcregister("classname",ring_vm_refmeta_classname);
	ring_vm_funcregister("objectid",ring_vm_refmeta_objectid);
	ring_vm_funcregister("attributes",ring_vm_refmeta_attributes);
	ring_vm_funcregister("methods",ring_vm_refmeta_methods);
	ring_vm_funcregister("isattribute",ring_vm_refmeta_isattribute);
	ring_vm_funcregister("ismethod",ring_vm_refmeta_ismethod);
	ring_vm_funcregister("isprivateattribute",ring_vm_refmeta_isprivateattribute);
	ring_vm_funcregister("isprivatemethod",ring_vm_refmeta_isprivatemethod);
	ring_vm_funcregister("addattribute",ring_vm_refmeta_addattribute);
	ring_vm_funcregister("addmethod",ring_vm_refmeta_addmethod);
	ring_vm_funcregister("getattribute",ring_vm_refmeta_getattribute);
	ring_vm_funcregister("setattribute",ring_vm_refmeta_setattribute);
	ring_vm_funcregister("mergemethods",ring_vm_refmeta_mergemethods);
	ring_vm_funcregister("packagename",ring_vm_refmeta_packagename);
	/* VM */
	ring_vm_funcregister("ringvm_fileslist",ring_vm_refmeta_ringvmfileslist);
	ring_vm_funcregister("ringvm_calllist",ring_vm_refmeta_ringvmcalllist);
	ring_vm_funcregister("ringvm_memorylist",ring_vm_refmeta_ringvmmemorylist);
	ring_vm_funcregister("ringvm_functionslist",ring_vm_refmeta_ringvmfunctionslist);
	ring_vm_funcregister("ringvm_classeslist",ring_vm_refmeta_ringvmclasseslist);
	ring_vm_funcregister("ringvm_packageslist",ring_vm_refmeta_ringvmpackageslist);
	ring_vm_funcregister("ringvm_cfunctionslist",ring_vm_refmeta_ringvmcfunctionslist);
	ring_vm_funcregister("ringvm_settrace",ring_vm_refmeta_ringvmsettrace);
	ring_vm_funcregister("ringvm_tracedata",ring_vm_refmeta_ringvmtracedata);
	ring_vm_funcregister("ringvm_traceevent",ring_vm_refmeta_ringvmtraceevent);
	ring_vm_funcregister("ringvm_tracefunc",ring_vm_refmeta_ringvmtracefunc);
	ring_vm_funcregister("ringvm_scopescount",ring_vm_refmeta_ringvmscopescount);
	ring_vm_funcregister("ringvm_evalinscope",ring_vm_refmeta_ringvmevalinscope);
	ring_vm_funcregister("ringvm_passerror",ring_vm_refmeta_ringvmpasserror);
	ring_vm_funcregister("ringvm_hideerrormsg",ring_vm_refmeta_ringvmhideerrormsg);
	ring_vm_funcregister("ringvm_callfunc",ring_vm_refmeta_ringvmcallfunc);
	ring_vm_funcregister("ringvm_info",ring_vm_refmeta_ringvminfo);
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
	const char *cStr  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_GETSTRING(1) ) {
		pVM = (VM *) pPointer ;
		cStr = RING_API_GETSTRING(1) ;
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
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_isglobal ( void *pPointer )
{
	VM *pVM  ;
	int x  ;
	List *pList, *pList2  ;
	const char *cStr  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_GETSTRING(1) ) {
		pVM = (VM *) pPointer ;
		cStr = RING_API_GETSTRING(1) ;
		pList = ring_vm_getglobalscope(pVM) ;
		for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
			pList2 = ring_list_getlist(pList,x);
			if ( strcmp(ring_list_getstring(pList2,RING_VAR_NAME),cStr) == 0 ) {
				RING_API_RETNUMBER(1);
				return ;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_isfunction ( void *pPointer )
{
	VM *pVM  ;
	int x  ;
	List *pList, *pList2  ;
	const char *cStr  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_GETSTRING(1) ) {
		pVM = (VM *) pPointer ;
		cStr = RING_API_GETSTRING(1) ;
		pList = pVM->pFunctionsMap ;
		for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
			pList2 = ring_list_getlist(pList,x);
			if ( strcmp(ring_list_getstring(pList2,RING_FUNCMAP_NAME),cStr) == 0 ) {
				RING_API_RETNUMBER(1);
				return ;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_iscfunction ( void *pPointer )
{
	VM *pVM  ;
	int x  ;
	List *pList, *pList2  ;
	const char *cStr  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_GETSTRING(1) ) {
		pVM = (VM *) pPointer ;
		cStr = RING_API_GETSTRING(1) ;
		pList = pVM->pCFunctionsList ;
		for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
			pList2 = ring_list_getlist(pList,x);
			if ( strcmp(ring_list_getstring(pList2,RING_FUNCMAP_NAME),cStr) == 0 ) {
				RING_API_RETNUMBER(1);
				return ;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
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
		cStr = RING_API_GETSTRING(1) ;
		ring_string_lower(cStr);
		pList = pVM->pPackagesMap ;
		for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
			pList2 = ring_list_getlist(pList,x);
			if ( strcmp(ring_list_getstring(pList2,RING_PACKAGENAME),cStr) == 0 ) {
				RING_API_RETNUMBER(1);
				return ;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
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
	if ( RING_API_GETSTRING(1) ) {
		pVM = (VM *) pPointer ;
		cStr = RING_API_GETSTRING(1) ;
		ring_string_lower(cStr);
		pList = pVM->pClassesMap ;
		for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
			pList2 = ring_list_getlist(pList,x);
			if ( strcmp(ring_list_getstring(pList2,RING_CLASSMAP_CLASSNAME),cStr) == 0 ) {
				RING_API_RETNUMBER(1);
				return ;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
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
	} else {
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
	if ( RING_API_GETSTRING(1) &&  RING_API_GETSTRING(2) ) {
		pVM = (VM *) pPointer ;
		cStr = RING_API_GETSTRING(1) ;
		ring_string_lower(cStr);
		cStr2 = RING_API_GETSTRING(2) ;
		ring_string_lower(cStr2);
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
	} else {
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
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
			cStr = RING_API_GETSTRING(2) ;
			ring_string_lower(cStr);
			pList = ring_list_getlist(pList,RING_OBJECT_OBJECTDATA);
			for ( x = 3 ; x <= ring_list_getsize(pList) ; x++ ) {
				if ( strcmp(cStr,ring_list_getstring(ring_list_getlist(pList,x),RING_VAR_NAME))==0 ) {
					RING_API_RETNUMBER(1);
					return ;
				}
			}
			RING_API_RETNUMBER(0);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
			cStr = RING_API_GETSTRING(2) ;
			ring_string_lower(cStr);
			RING_API_RETNUMBER(ring_vm_oop_ismethod((VM *) pPointer,pList,cStr));
		}
	} else {
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
			cStr = RING_API_GETSTRING(2) ;
			ring_string_lower(cStr);
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
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
			cStr = RING_API_GETSTRING(2) ;
			ring_string_lower(cStr);
			x = ring_vm_oop_ismethod((VM *) pPointer,pList,cStr) ;
			if ( x==2 ) {
				RING_API_RETNUMBER(1);
			}
			else {
				RING_API_RETNUMBER(0);
			}
		}
	} else {
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
			} else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
					if ( pVM->pRingState->lRunFromThread ) {
						ring_list_genhashtable2(pList);
					}
					else {
						ring_list_genhashtable2_gc(pVM->pRingState,pList);
					}
					RING_API_RETNUMBER(1);
					return ;
				}
			}
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
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
	} else {
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
	} else {
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
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( RING_API_ISNUMBER(1) && RING_API_ISSTRING(2) ) {
		/* We must get cStr before we change the pVM->pActiveMem */
		cStr = RING_API_GETSTRING(2) ;
		nScope = (int) RING_API_GETNUMBER(1) ;
		pActiveMem = pVM->pActiveMem ;
		pVM->pActiveMem = ring_list_getlist(pVM->pMem,nScope) ;
		pVM->nActiveScopeID++ ;
		nSize = pVM->pMem->nSize ;
		pVM->pMem->nSize = nScope ;
		pVM->nEvalInScope++ ;
		/* Save State */
		pState = ring_list_new_gc(((VM *) pPointer)->pRingState,0);
		ring_vm_savestate2(pVM,pState);
		ring_vm_runcode(pVM,cStr);
		/* Restore State */
		ring_vm_restorestate2(pVM,pState,1);
		ring_list_delete_gc(((VM *) pPointer)->pRingState,pState);
		pVM->nEvalInScope-- ;
		pVM->pMem->nSize = nSize ;
		pVM->pActiveMem = pActiveMem ;
	} else {
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
	} else {
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
	} else {
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
	ring_list_adddouble_gc(pVM->pRingState, pList, (double) ring_list_getsize(pVM->aLoadAddressScope));
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
