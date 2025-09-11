/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_refmeta_loadfunctions(RingState *pRingState) {
	/* Functions */
	RING_API_REGISTER("locals", ring_vm_refmeta_locals);
	RING_API_REGISTER("globals", ring_vm_refmeta_globals);
	RING_API_REGISTER("functions", ring_vm_refmeta_functions);
	RING_API_REGISTER("cfunctions", ring_vm_refmeta_cfunctions);
	RING_API_REGISTER("islocal", ring_vm_refmeta_islocal);
	RING_API_REGISTER("isglobal", ring_vm_refmeta_isglobal);
	RING_API_REGISTER("isfunction", ring_vm_refmeta_isfunction);
	RING_API_REGISTER("iscfunction", ring_vm_refmeta_iscfunction);
	/* OOP */
	RING_API_REGISTER("packages", ring_vm_refmeta_packages);
	RING_API_REGISTER("ispackage", ring_vm_refmeta_ispackage);
	RING_API_REGISTER("classes", ring_vm_refmeta_classes);
	RING_API_REGISTER("isclass", ring_vm_refmeta_isclass);
	RING_API_REGISTER("packageclasses", ring_vm_refmeta_packageclasses);
	RING_API_REGISTER("ispackageclass", ring_vm_refmeta_ispackageclass);
	RING_API_REGISTER("classname", ring_vm_refmeta_classname);
	RING_API_REGISTER("objectid", ring_vm_refmeta_objectid);
	RING_API_REGISTER("attributes", ring_vm_refmeta_attributes);
	RING_API_REGISTER("methods", ring_vm_refmeta_methods);
	RING_API_REGISTER("isattribute", ring_vm_refmeta_isattribute);
	RING_API_REGISTER("ismethod", ring_vm_refmeta_ismethod);
	RING_API_REGISTER("isprivateattribute", ring_vm_refmeta_isprivateattribute);
	RING_API_REGISTER("isprivatemethod", ring_vm_refmeta_isprivatemethod);
	RING_API_REGISTER("addattribute", ring_vm_refmeta_addattribute);
	RING_API_REGISTER("addmethod", ring_vm_refmeta_addmethod);
	RING_API_REGISTER("getattribute", ring_vm_refmeta_getattribute);
	RING_API_REGISTER("setattribute", ring_vm_refmeta_setattribute);
	RING_API_REGISTER("mergemethods", ring_vm_refmeta_mergemethods);
	RING_API_REGISTER("packagename", ring_vm_refmeta_packagename);
	RING_API_REGISTER("importpackage", ring_vm_refmeta_importpackage);
	RING_API_REGISTER("parentclassname", ring_vm_refmeta_parentclassname);
}

void ring_vm_refmeta_locals(void *pPointer) {
	unsigned int x;
	List *pList, *pList2, *pList3;
	/* We skip the current scope of the locals() function */
	pList = RING_API_CALLERSCOPE;
	pList2 = RING_API_NEWLIST;
	for (x = 1; x <= ring_list_getsize(pList); x++) {
		pList3 = ring_list_getlist(pList, x);
		ring_list_addstring_gc(((VM *)pPointer)->pRingState, pList2,
				       ring_list_getstring(pList3, RING_VAR_NAME));
	}
	RING_API_RETLISTBYREF(pList2);
}

void ring_vm_refmeta_globals(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2, *pList3;
	pVM = (VM *)pPointer;
	pList = ring_vm_getglobalscope(pVM);
	pList2 = RING_API_NEWLIST;
	/* We avoid internal global variables like true, false */
	for (x = 1; x <= ring_list_getsize(pList); x++) {
		pList3 = ring_list_getlist(pList, x);
		ring_list_addstring_gc(((VM *)pPointer)->pRingState, pList2,
				       ring_list_getstring(pList3, RING_VAR_NAME));
	}
	RING_API_RETLISTBYREF(pList2);
}

void ring_vm_refmeta_functions(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	for (x = 1; x <= ring_list_getsize(pVM->pFunctionsMap); x++) {
		pList2 = ring_list_getlist(pVM->pFunctionsMap, x);
		ring_list_addstring_gc(((VM *)pPointer)->pRingState, pList,
				       ring_list_getstring(pList2, RING_FUNCMAP_NAME));
	}
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_refmeta_cfunctions(void *pPointer) {
	VM *pVM;
	List *pList;
	CFunction *pCFunc;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	pCFunc = pVM->pCFunction;
	while (pCFunc != NULL) {
		ring_list_addstring_gc(((VM *)pPointer)->pRingState, pList, pCFunc->cName);
		pCFunc = pCFunc->pNext;
	}
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_refmeta_islocal(void *pPointer) {
	unsigned int x;
	List *pList, *pList2;
	char *cStr;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		cStr = ring_general_lower(RING_API_GETSTRING(1));
		/* We skip the current scope of the locals() function */
		pList = RING_API_CALLERSCOPE;
		for (x = 1; x <= ring_list_getsize(pList); x++) {
			pList2 = ring_list_getlist(pList, x);
			if (strcmp(ring_list_getstring(pList2, RING_VAR_NAME), cStr) == 0) {
				RING_API_RETNUMBER(1);
				return;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_isglobal(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2;
	char *cStr;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		pVM = (VM *)pPointer;
		cStr = ring_general_lower(RING_API_GETSTRING(1));
		pList = ring_vm_getglobalscope(pVM);
		for (x = 1; x <= ring_list_getsize(pList); x++) {
			pList2 = ring_list_getlist(pList, x);
			if (strcmp(ring_list_getstring(pList2, RING_VAR_NAME), cStr) == 0) {
				RING_API_RETNUMBER(1);
				return;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_isfunction(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2;
	char *cStr;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		pVM = (VM *)pPointer;
		cStr = ring_general_lower(RING_API_GETSTRING(1));
		pList = pVM->pFunctionsMap;
		for (x = 1; x <= ring_list_getsize(pList); x++) {
			pList2 = ring_list_getlist(pList, x);
			if (strcmp(ring_list_getstring(pList2, RING_FUNCMAP_NAME), cStr) == 0) {
				RING_API_RETNUMBER(1);
				return;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_iscfunction(void *pPointer) {
	VM *pVM;
	char *cStr;
	CFunction *pCFunc;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		pVM = (VM *)pPointer;
		cStr = ring_general_lower(RING_API_GETSTRING(1));
		/* Linear Search */
		pCFunc = pVM->pCFunction;
		while (pCFunc != NULL) {
			if (strcmp(pCFunc->cName, cStr) == 0) {
				RING_API_RETNUMBER(1);
				return;
			}
			pCFunc = pCFunc->pNext;
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_packages(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	for (x = 1; x <= ring_list_getsize(pVM->pPackagesMap); x++) {
		pList2 = ring_list_getlist(pVM->pPackagesMap, x);
		ring_list_addstring_gc(((VM *)pPointer)->pRingState, pList,
				       ring_list_getstring(pList2, RING_PACKAGES_PACKAGENAME));
	}
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_refmeta_ispackage(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2;
	char *cStr;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		pVM = (VM *)pPointer;
		cStr = ring_general_lower(RING_API_GETSTRING(1));
		pList = pVM->pPackagesMap;
		for (x = 1; x <= ring_list_getsize(pList); x++) {
			pList2 = ring_list_getlist(pList, x);
			if (strcmp(ring_list_getstring(pList2, RING_PACKAGES_PACKAGENAME), cStr) == 0) {
				RING_API_RETNUMBER(1);
				return;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_classes(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2;
	pVM = (VM *)pPointer;
	pList = RING_API_NEWLIST;
	for (x = 1; x <= ring_list_getsize(pVM->pClassesMap); x++) {
		pList2 = ring_list_getlist(pVM->pClassesMap, x);
		ring_list_addstring_gc(((VM *)pPointer)->pRingState, pList,
				       ring_list_getstring(pList2, RING_CLASSMAP_CLASSNAME));
	}
	RING_API_RETLISTBYREF(pList);
}

void ring_vm_refmeta_isclass(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2;
	char *cStr;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		pVM = (VM *)pPointer;
		cStr = ring_general_lower(RING_API_GETSTRING(1));
		pList = pVM->pClassesMap;
		for (x = 1; x <= ring_list_getsize(pList); x++) {
			pList2 = ring_list_getlist(pList, x);
			if (strcmp(ring_list_getstring(pList2, RING_CLASSMAP_CLASSNAME), cStr) == 0) {
				RING_API_RETNUMBER(1);
				return;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_packageclasses(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2, *pList3;
	char *cStr;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_GETSTRING(1)) {
		pVM = (VM *)pPointer;
		cStr = RING_API_GETSTRING(1);
		ring_general_lower(cStr);
		pList = pVM->pPackagesMap;
		for (x = 1; x <= ring_list_getsize(pList); x++) {
			pList2 = ring_list_getlist(pList, x);
			if (strcmp(ring_list_getstring(pList2, RING_PACKAGES_PACKAGENAME), cStr) == 0) {
				pList3 = RING_API_NEWLIST;
				pList2 = ring_list_getlist(pList2, RING_PACKAGES_CLASSESLIST);
				/* We can use the variable x for the loop again because we have return */
				for (x = 1; x <= ring_list_getsize(pList2); x++) {
					ring_list_addstring_gc(
					    ((VM *)pPointer)->pRingState, pList3,
					    ring_list_getstring(ring_list_getlist(pList2, x), RING_CLASSMAP_CLASSNAME));
				}
				RING_API_RETLISTBYREF(pList3);
				return;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_ispackageclass(void *pPointer) {
	VM *pVM;
	unsigned int x;
	List *pList, *pList2;
	char *cStr, *cStr2;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1) && RING_API_ISSTRING(2)) {
		pVM = (VM *)pPointer;
		cStr = ring_general_lower(RING_API_GETSTRING(1));
		cStr2 = ring_general_lower(RING_API_GETSTRING(2));
		pList = pVM->pPackagesMap;
		for (x = 1; x <= ring_list_getsize(pList); x++) {
			pList2 = ring_list_getlist(pList, x);
			if (strcmp(ring_list_getstring(pList2, RING_PACKAGES_PACKAGENAME), cStr) == 0) {
				pList2 = ring_list_getlist(pList2, RING_PACKAGES_CLASSESLIST);
				/* We can use the variable x for the loop again because we have return */
				for (x = 1; x <= ring_list_getsize(pList2); x++) {
					if (strcmp(ring_list_getstring(ring_list_getlist(pList2, x),
								       RING_CLASSMAP_CLASSNAME),
						   cStr2) == 0) {
						RING_API_RETNUMBER(1);
						return;
					}
				}
				RING_API_RETNUMBER(0);
				return;
			}
		}
		RING_API_RETNUMBER(0);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_classname(void *pPointer) {
	List *pList;
	char *cStr;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			cStr = ring_list_getstring((List *)ring_list_getpointer(pList, RING_OBJECT_CLASSPOINTER),
						   RING_CLASSMAP_CLASSNAME);
			RING_API_RETSTRING(cStr);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_objectid(void *pPointer) {
	List *pList;
	char cStr[RING_MEDIUMBUF];
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		sprintf(cStr, "%p", (void *)pList);
		RING_API_RETSTRING(cStr);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_attributes(void *pPointer) {
	List *pList, *pList2;
	unsigned int x;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			pList = ring_list_getlist(pList, RING_OBJECT_OBJECTDATA);
			pList2 = RING_API_NEWLIST;
			for (x = 3; x <= ring_list_getsize(pList); x++) {
				ring_list_addstring_gc(((VM *)pPointer)->pRingState, pList2,
						       ring_list_getstring(ring_list_getlist(pList, x), RING_VAR_NAME));
			}
			RING_API_RETLISTBYREF(pList2);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_methods(void *pPointer) {
	List *pList, *pList2;
	unsigned int x;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			pList = (List *)ring_list_getpointer(pList, RING_OBJECT_CLASSPOINTER);
			pList = ring_list_getlist(pList, RING_CLASSMAP_METHODSLIST);
			pList2 = RING_API_NEWLIST;
			for (x = 1; x <= ring_list_getsize(pList); x++) {
				ring_list_addstring_gc(
				    ((VM *)pPointer)->pRingState, pList2,
				    ring_list_getstring(ring_list_getlist(pList, x), RING_FUNCMAP_NAME));
			}
			RING_API_RETLISTBYREF(pList2);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_isattribute(void *pPointer) {
	List *pList;
	char *cStr;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1) && RING_API_ISSTRING(2)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			cStr = ring_general_lower(RING_API_GETSTRING(2));
			RING_API_RETNUMBER(ring_vm_oop_isattribute((VM *)pPointer, pList, cStr));
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_ismethod(void *pPointer) {
	List *pList;
	char *cStr;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList) == 0) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
		if (RING_API_ISSTRING(2)) {
			cStr = ring_general_lower(RING_API_GETSTRING(2));
			RING_API_RETNUMBER(ring_vm_oop_ismethod((VM *)pPointer, pList, cStr));
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_isprivateattribute(void *pPointer) {
	List *pList;
	unsigned int x;
	char *cStr;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1) && RING_API_ISSTRING(2)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			cStr = ring_general_lower(RING_API_GETSTRING(2));
			pList = ring_list_getlist(pList, RING_OBJECT_OBJECTDATA);
			for (x = 3; x <= ring_list_getsize(pList); x++) {
				if (strcmp(cStr, ring_list_getstring(ring_list_getlist(pList, x), RING_VAR_NAME)) ==
				    0) {
					if (ring_vm_getvarprivateflag(pVM, ring_list_getlist(pList, x)) == 1) {
						RING_API_RETNUMBER(1);
					} else {
						RING_API_RETNUMBER(0);
					}
					return;
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

void ring_vm_refmeta_isprivatemethod(void *pPointer) {
	List *pList;
	unsigned int x;
	char *cStr;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList) == 0) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
		if (RING_API_ISSTRING(2)) {
			cStr = ring_general_lower(RING_API_GETSTRING(2));
			x = ring_vm_oop_ismethod((VM *)pPointer, pList, cStr);
			if (x == RING_ISMETHOD_PRIVATEMETHOD) {
				RING_API_RETNUMBER(1);
			} else {
				RING_API_RETNUMBER(0);
			}
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_addattribute(void *pPointer) {
	List *pList, *pList2;
	char *cStr;
	unsigned int x;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			((VM *)pPointer)->nInClassRegion++;
			if (RING_API_ISSTRING(2)) {
				cStr = RING_API_GETSTRING(2);
				ring_vm_oop_addattribute((VM *)pPointer, pList, cStr);
			} else if (RING_API_ISLIST(2)) {
				pList2 = RING_API_GETLIST(2);
				for (x = 1; x <= ring_list_getsize(pList2); x++) {
					if (ring_list_isstring(pList2, x)) {
						cStr = ring_list_getstring(pList2, x);
						if (!ring_vm_oop_addattribute((VM *)pPointer, pList, cStr)) {
							break;
						}
					}
				}
			} else {
				((VM *)pPointer)->nInClassRegion--;
				RING_API_ERROR(RING_API_BADPARATYPE);
				return;
			}
			((VM *)pPointer)->nInClassRegion--;
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_addmethod(void *pPointer) {
	List *pList, *pList2, *pList3;
	char *cStr;
	unsigned int x;
	VM *pVM;
	/* Parameters : Object, MethodName, Anonymous Function */
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 3) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			/* Check if the method is already defined */
			if (ring_vm_oop_ismethod(pVM, pList, RING_API_GETSTRING(2))) {
				RING_API_ERROR(RING_VM_ERROR_FUNCREDEFINE);
				return;
			}
			pList = (List *)ring_list_getlist(pList, RING_OBJECT_CLASSPOINTER);
			pList = (List *)ring_list_getlist(pList, RING_CLASSMAP_METHODSLIST);
			cStr = RING_API_GETSTRING(3);
			ring_general_lower(cStr);
			for (x = 1; x <= ring_list_getsize(pVM->pFunctionsMap); x++) {
				pList2 = ring_list_getlist(pVM->pFunctionsMap, x);
				if (strcmp(ring_list_getstring(pList2, RING_FUNCMAP_NAME), cStr) == 0) {
					/* Add new list to the class methods list */
					pList3 = ring_list_newlist_gc(pVM->pRingState, pList);
					/* Copy function to class methods */
					ring_list_copy_gc(pVM->pRingState, pList3, pList2);
					/* Set the Function Name */
					ring_list_setstring_gc(pVM->pRingState, pList3, RING_FUNCMAP_NAME,
							       ring_general_lower(RING_API_GETSTRING(2)));
					/* Refresh the HashTable */
					ring_vm_custmutexlock(pVM,
							      pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_FUNCHASHTABLE]);
					if (ring_list_gethashtable(pList) != NULL) {
						ring_list_genhashtable2_gc(pVM->pRingState, pList);
					}
					ring_vm_custmutexunlock(pVM,
								pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_FUNCHASHTABLE]);
					RING_API_RETNUMBER(1);
					return;
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

void ring_vm_refmeta_getattribute(void *pPointer) {
	List *pList;
	char *cStr;
	unsigned int x;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1) && RING_API_ISSTRING(2)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			pList = ring_list_getlist(pList, RING_OBJECT_OBJECTDATA);
			cStr = RING_API_GETSTRING(2);
			ring_general_lower(cStr);
			for (x = 1; x <= ring_list_getsize(pList); x++) {
				if (strcmp(ring_list_getstring(ring_list_getlist(pList, x), RING_VAR_NAME), cStr) ==
				    0) {
					pList = ring_list_getlist(pList, x);
					if (ring_list_isnumber(pList, RING_VAR_VALUE)) {
						RING_API_RETNUMBER(ring_list_getdouble(pList, RING_VAR_VALUE));
					} else if (ring_list_isstring(pList, RING_VAR_VALUE)) {
						RING_API_RETSTRING2(ring_list_getstring(pList, RING_VAR_VALUE),
								    ring_list_getstringsize(pList, RING_VAR_VALUE));
					} else if (ring_list_islist(pList, RING_VAR_VALUE)) {
						RING_API_RETLIST(ring_list_getlist(pList, RING_VAR_VALUE));
					}
					return;
				}
			}
			RING_API_ERROR(RING_VM_ERROR_PROPERTYNOTFOUND);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_setattribute(void *pPointer) {
	List *pList;
	char *cStr;
	unsigned int x;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 3) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1) && RING_API_ISSTRING(2)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			pList = ring_list_getlist(pList, RING_OBJECT_OBJECTDATA);
			cStr = RING_API_GETSTRING(2);
			ring_general_lower(cStr);
			for (x = 1; x <= ring_list_getsize(pList); x++) {
				if (strcmp(ring_list_getstring(ring_list_getlist(pList, x), RING_VAR_NAME), cStr) ==
				    0) {
					pList = ring_list_getlist(pList, x);
					if (RING_API_ISNUMBER(3)) {
						ring_list_setdouble_gc(((VM *)pPointer)->pRingState, pList,
								       RING_VAR_VALUE, RING_API_GETNUMBER(3));
					} else if (RING_API_ISSTRING(3)) {
						ring_list_setstring2_gc(((VM *)pPointer)->pRingState, pList,
									RING_VAR_VALUE, RING_API_GETSTRING(3),
									RING_API_GETSTRINGSIZE(3));
					} else if (RING_API_ISLIST(3)) {
						ring_list_setlist_gc(((VM *)pPointer)->pRingState, pList,
								     RING_VAR_VALUE);
						pList = ring_list_getlist(pList, RING_VAR_VALUE);
						ring_list_deleteallitems_gc(((VM *)pPointer)->pRingState, pList);
						ring_list_copy_gc(((VM *)pPointer)->pRingState, pList,
								  RING_API_GETLIST(3));
					}
					return;
				}
			}
			RING_API_ERROR(RING_VM_ERROR_PROPERTYNOTFOUND);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_mergemethods(void *pPointer) {
	unsigned int x;
	List *pList, *pList2, *pList3;
	VM *pVM;
	char *cStr, *cStr2;
	/*
	**  We copy class methods from class to another class
	**  First Parameter = Dest Class Name, Second Para = Source Class Name
	**  The Source Class is expected to be without Parent Class and Without Attributes
	*/
	if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1) && RING_API_ISSTRING(2)) {
		cStr = RING_API_GETSTRING(1);
		cStr2 = RING_API_GETSTRING(2);
		ring_general_lower(cStr);
		ring_general_lower(cStr2);
		pVM = (VM *)pPointer;
		/* Get the Dest Class Methods List */
		pList2 = NULL;
		for (x = 1; x <= ring_list_getsize(pVM->pClassesMap); x++) {
			pList = ring_list_getlist(pVM->pClassesMap, x);
			if (strcmp(ring_list_getstring(pList, RING_CLASSMAP_CLASSNAME), cStr) == 0) {
				/* Check if the class is imported from a Package */
				if (ring_list_getsize(pList) == RING_CLASSMAP_IMPORTEDCLASSSIZE) {
					pList =
					    ring_list_getlist(pList, RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE);
				}
				pList2 = ring_list_getlist(pList, RING_CLASSMAP_METHODSLIST);
				break;
			}
		}
		if (pList2 == NULL) {
			RING_API_ERROR(RING_VM_ERROR_CLASSNOTFOUND);
			return;
		}
		/* Get the Source Class Methods List */
		pList3 = NULL;
		for (x = 1; x <= ring_list_getsize(pVM->pClassesMap); x++) {
			pList = ring_list_getlist(pVM->pClassesMap, x);
			if (strcmp(ring_list_getstring(pList, RING_CLASSMAP_CLASSNAME), cStr2) == 0) {
				/* Check if the class is imported from a Package */
				if (ring_list_getsize(pList) == RING_CLASSMAP_IMPORTEDCLASSSIZE) {
					pList =
					    ring_list_getlist(pList, RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE);
				}
				pList3 = ring_list_getlist(pList, RING_CLASSMAP_METHODSLIST);
				break;
			}
		}
		if (pList3 == NULL) {
			RING_API_ERROR(RING_VM_ERROR_CLASSNOTFOUND);
			return;
		}
		/* Copy Methods from Source to Dest */
		ring_list_copy_gc(pVM->pRingState, pList2, pList3);
		/* Refresh the HashTable */
		ring_vm_custmutexlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_FUNCHASHTABLE]);
		if (ring_list_gethashtable(pList2) != NULL) {
			ring_list_genhashtable2_gc(pVM->pRingState, pList2);
		}
		ring_vm_custmutexunlock(pVM, pVM->aCustomMutex[RING_VM_CUSTOMMUTEX_FUNCHASHTABLE]);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_packagename(void *pPointer) {
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 0) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	RING_API_RETSTRING(ring_string_get(pVM->pPackageName));
}

void ring_vm_refmeta_importpackage(void *pPointer) {
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISSTRING(1)) {
		ring_vm_oop_import2(pVM, RING_API_GETSTRING(1));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_refmeta_parentclassname(void *pPointer) {
	List *pList;
	char *cStr;
	VM *pVM;
	pVM = (VM *)pPointer;
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}
	if (RING_API_ISLIST(1)) {
		pList = RING_API_GETLIST(1);
		if (ring_vm_oop_isobject(pVM, pList)) {
			cStr = ring_list_getstring((List *)ring_list_getpointer(pList, RING_OBJECT_CLASSPOINTER),
						   RING_CLASSMAP_PARENTCLASS);
			RING_API_RETSTRING(cStr);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
