/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmoop
#define ring_vmoop
/*
**  Constants
**  pClassesMap
*/
#define RING_CLASSMAP_CLASSNAME 1
#define RING_CLASSMAP_PC 2
#define RING_CLASSMAP_PARENTCLASS 3
#define RING_CLASSMAP_METHODSLIST 4
#define RING_CLASSMAP_ISPARENTINFO 5
#define RING_CLASSMAP_POINTERTOPACKAGE 6
#define RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE 2
#define RING_CLASSMAP_POINTERTOFILENAME 3
#define RING_CLASSMAP_IMPORTEDCLASSSIZE 3
/* Object */
#define RING_OBJECT_LISTSIZE 2
#define RING_OBJECT_CLASSPOINTER 1
#define RING_OBJECT_OBJECTDATA 2
#define RING_OBJECT_SELFATTRIBUTE 1
#define RING_OBJECT_ISATTRIBUTESEARCHSTART 3
/* pObjState */
#define RING_OBJSTATE_SCOPE 1
#define RING_OBJSTATE_METHODS 2
#define RING_OBJSTATE_CLASS 3
/* Operator Overloading */
#define RING_OOPARA_STRING 1
#define RING_OOPARA_NUMBER 2
#define RING_OOPARA_POINTER 3
/* pBraceObjects */
#define RING_BRACEOBJECTS_BRACEOBJECT 1
#define RING_BRACEOBJECTS_NSP 2
#define RING_BRACEOBJECTS_NLISTSTART 3
#define RING_BRACEOBJECTS_NNESTEDLISTS 4
#define RING_BRACEOBJECTS_SETPROPERTY 5
#define RING_BRACEOBJECTS_NLOADASCOPE 6
#define RING_BRACEOBJECTS_NNOSETTERMETHOD 7
#define RING_BRACEOBJECTS_ISDONTREF 8
#define RING_BRACEOBJECTS_ISDONTREFAGAIN 9
/* pScopeNewObj */
#define RING_SCOPENEWOBJ_SP 2
/* pSetProperty */
#define RING_SETPROPERTY_OBJPTR 1
#define RING_SETPROPERTY_OBJTYPE 2
#define RING_SETPROPERTY_ATTRNAME 3
#define RING_SETPROPERTY_ATTRVAR 4
#define RING_SETPROPERTY_NBEFOREEQUAL 5
#define RING_SETPROPERTY_VALUE 6
#define RING_SETPROPERTY_VALUEOBJTYPE 7
/* Is Method */
#define RING_ISMETHOD_NOTFOUND 0
#define RING_ISMETHOD_PUBLICMETHOD 1
#define RING_ISMETHOD_PRIVATEMETHOD 2
/* nNoSetterMethod */
#define RING_NOSETTERMETHOD_DEFAULT 0
#define RING_NOSETTERMETHOD_ENABLE 1
#define RING_NOSETTERMETHOD_IGNORESETPROPERTY 2
/* Functions */

void ring_vm_oop_newobj(VM *pVM);

void ring_vm_oop_property(VM *pVM);

unsigned int ring_vm_oop_isobject(VM *pVM, List *pList);

List *ring_vm_oop_getobj(VM *pVM);

void ring_vm_oop_loadmethod(VM *pVM);

void ring_vm_oop_loadmethod2(VM *pVM, const char *cMethod);

void ring_vm_oop_aftercallmethod(VM *pVM);

void ring_vm_oop_setscope(VM *pVM);

void ring_vm_oop_printobj(VM *pVM, List *pList);

unsigned int ring_vm_oop_parentinit(VM *pVM, List *pList);

void ring_vm_oop_parentmethods(VM *pVM, List *pList);

void ring_vm_oop_newclass(VM *pVM);

void ring_vm_oop_setbraceobj(VM *pVM, List *pList);

void ring_vm_oop_bracestart(VM *pVM);

void ring_vm_oop_braceend(VM *pVM);

void ring_vm_oop_bracestack(VM *pVM);

void ring_vm_oop_newsuperobj(VM *pVM, List *pState, List *pClass);

List *ring_vm_oop_getsuperobj(VM *pVM);

void ring_vm_oop_loadsuperobjmethod(VM *pVM, List *pSuper);

void ring_vm_oop_import(VM *pVM);

List *ring_vm_oop_checkpointertoclassinpackage(VM *pVM, List *pList);

void ring_vm_oop_import2(VM *pVM, const char *cPackage);

void ring_vm_oop_import3(VM *pVM, List *pList);

unsigned int ring_vm_oop_visibleclassescount(VM *pVM);

List *ring_vm_oop_visibleclassitem(VM *pVM, unsigned int nIndex);

void ring_vm_oop_pushclasspackage(VM *pVM, List *pList);

void ring_vm_oop_deletepackagesafter(VM *pVM, unsigned int nIndex);

unsigned int ring_vm_oop_callmethodinsideclass(VM *pVM);

void ring_vm_oop_setget(VM *pVM, List *pVar);

void ring_vm_oop_setproperty(VM *pVM);

void ring_vm_oop_operatoroverloading(VM *pVM, List *pObj, const char *cStr1, unsigned int nType, const char *cStr2,
				     double nNum1, void *pPointer, unsigned int nPointerType);

void ring_vm_oop_operatoroverloading2(VM *pVM, List *pObj, const char *cStr1, unsigned int nType, const char *cStr2,
				      double nNum1, void *pPointer, unsigned int nPointerType);

List *ring_vm_oop_objvarfromobjlist(VM *pVM, List *pList);

unsigned int ring_vm_oop_objtypefromobjlist(VM *pVM, List *pList);

Item *ring_vm_oop_objitemfromobjlist(VM *pVM, List *pList);

void ring_vm_oop_callmethodfrombrace(VM *pVM);

unsigned int ring_vm_oop_ismethod(VM *pVM, List *pList, const char *cStr);

void ring_vm_oop_updateselfpointer(VM *pVM, List *pObj, unsigned int nType, void *pContainer);

void ring_vm_oop_movetobeforeobjstate(VM *pVM);

void ring_vm_oop_setthethisvariable(VM *pVM);

void ring_vm_oop_setthethisvariableinclassregion(VM *pVM);

unsigned int ring_vm_oop_callingclassmethodfromclassregion(VM *pVM, List *pMethods);

void ring_vm_oop_callclassinit(VM *pVM);

void ring_vm_oop_checkbracemethod(VM *pVM);

void ring_vm_oop_preparecallmethodfrombrace(VM *pVM);

unsigned int ring_vm_oop_isattribute(VM *pVM, List *pList, const char *cStr);

unsigned int ring_vm_oop_addattribute(VM *pVM, List *pList, char *cStr);

void ring_vm_oop_cleansetpropertylist(VM *pVM);
#endif
