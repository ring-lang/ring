/*
**  Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> 
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
		ring_list_addstring(pList2,ring_list_getstring(pList3,RING_VAR_NAME));
	}
	RING_API_RETLIST(pList2);
}

void ring_vm_refmeta_globals ( void *pPointer )
{
	VM *pVM  ;
	int x  ;
	List *pList, *pList2, *pList3  ;
	pVM = (VM *) pPointer ;
	pList = ring_list_getlist(pVM->pMem,1) ;
	pList2 = RING_API_NEWLIST ;
	/* We avoid internal global variables like true, false */
	for ( x = RING_VM_INTERNALGLOBALSCOUNT + 1 ; x <= ring_list_getsize(pList) ; x++ ) {
		pList3 = ring_list_getlist(pList,x);
		ring_list_addstring(pList2,ring_list_getstring(pList3,RING_VAR_NAME));
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
		ring_list_addstring(pList,ring_list_getstring(pList2,RING_FUNCMAP_NAME));
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
		ring_list_addstring(pList,ring_list_getstring(pList2,RING_FUNCMAP_NAME));
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
		pList = ring_list_getlist(pVM->pMem,1) ;
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
		ring_list_addstring(pList,ring_list_getstring(pList2,RING_PACKAGENAME));
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
	if ( RING_API_GETSTRING(1) ) {
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
		ring_list_addstring(pList,ring_list_getstring(pList2,RING_CLASSMAP_CLASSNAME));
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
					ring_list_addstring(pList3,ring_list_getstring(ring_list_getlist(pList2,x),RING_CLASSMAP_CLASSNAME));
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
				ring_list_addstring(pList2,ring_list_getstring(ring_list_getlist(pList,x),RING_VAR_NAME));
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
				ring_list_addstring(pList2,ring_list_getstring(ring_list_getlist(pList,x),RING_FUNCMAP_NAME));
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
				ring_vm_newvar2(cStr,pList);
			}
			else if ( RING_API_ISLIST(2) ) {
				pList2 = RING_API_GETLIST(2) ;
				for ( x = 1 ; x <= ring_list_getsize(pList2) ; x++ ) {
					if ( ring_list_isstring(pList2,x) ) {
						cStr = ring_list_getstring(pList2,x);
						ring_string_lower(cStr);
						/* Create Variable List */
						ring_vm_newvar2(cStr,pList);
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
					pList3 = ring_list_newlist(pList);
					/* Copy function to class methods */
					ring_list_copy(pList3,pList2);
					/* Set the Function Name */
					ring_list_setstring(pList3,RING_FUNCMAP_NAME,ring_string_lower(RING_API_GETSTRING(2)));
					/* Refresh the HashTable */
					ring_list_genhashtable2(pList);
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
						ring_list_setdouble(pList,RING_VAR_VALUE,RING_API_GETNUMBER(3));
					}
					else if ( RING_API_ISSTRING(3) ) {
						ring_list_setstring2(pList,RING_VAR_VALUE,RING_API_GETSTRING(3),RING_API_GETSTRINGSIZE(3));
					}
					else if ( RING_API_ISLIST(3) ) {
						ring_list_setlist(pList,RING_VAR_VALUE);
						pList = ring_list_getlist(pList,RING_VAR_VALUE);
						ring_list_deleteallitems(pList);
						ring_list_copy(pList,RING_API_GETLIST(3));
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
		ring_list_copy(pList2,pList3);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
