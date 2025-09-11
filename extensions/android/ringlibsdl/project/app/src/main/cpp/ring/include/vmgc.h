/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_gc_h
#define ring_gc_h
/* Constants */
#define RING_LISTREF_INC 1
#define RING_LISTREF_DEC -1
/*
**  Functions
**  Item GC Functions
*/

RING_API void ring_vm_gc_setfreefunc(Item *pItem, void (*pFreeFunc)(void *, void *));

RING_API void ring_vm_gc_removetrack(RingState *pState, List *pList);

RING_API void ring_vm_gc_freefunc(RingState *pState, Item *pItem);

RING_API void ring_vm_gc_newitemreference(void *pState, Item *pItem);

RING_API void ring_vm_gc_cleardata(void *pState, Item *pItem);

RING_API void ring_vm_gc_deletelistinitem(void *pState, void *pList);

RING_API void ring_vm_gc_finishitemdelete(void *pState, Item *pItem);

RING_API void ring_vm_gc_deleteitem(void *pState, Item *pItem);

RING_API void ring_vm_gc_checknewreference(VM *pVM, void *pPointer, int nType, List *pContainer, int nIndex);

RING_API void ring_vm_gc_checkupdatereference(VM *pVM, List *pList);

RING_API void ring_vm_gc_killreference(VM *pVM);

RING_API void ring_vm_gc_deletetemplists(VM *pVM);
/*
**  List GC Functions
**  Protecting Lists
*/

RING_API int ring_vm_gc_checkvarerroronassignment(VM *pVM, List *pVar);

RING_API int ring_vm_gc_checkitemerroronassignment(VM *pVM, Item *pItem);

RING_API int ring_vm_gc_checkbeforeassignment(VM *pVM, List *pVar);

RING_API void ring_vm_gc_removelistprotection(VM *pVM, List *pNestedLists, int nStart);

RING_API void ring_vm_gc_removelistprotectionat(VM *pVM, List *pNestedLists, int nPos);
/* References */

RING_API int ring_vm_gc_isrefparameter(VM *pVM, const char *cVariable);

RING_API void ring_list_acceptlistbyref_gc(void *pState, List *pList, unsigned int index, List *pRef);

RING_API void ring_list_setlistbyref_gc(void *pState, List *pList, unsigned int index, List *pRef);

RING_API void ring_list_updaterefcount_gc(void *pState, List *pList, int nChange);

RING_API List *ring_list_newref_gc(void *pState, List *pVariableList, List *pList);

RING_API void ring_list_assignreftovar_gc(void *pState, List *pRef, List *pVar, unsigned int nPos);

RING_API void ring_list_assignreftoitem_gc(void *pState, List *pRef, Item *pItem);

RING_API List *ring_list_deleteref_gc(void *pState, List *pList);

RING_API List *ring_list_collectcycles_gc(void *pState, List *pList);

RING_API int ring_list_containssublist_gc(void *pState, List *pList, List *pCheck);

RING_API int ring_list_iscircular_gc(void *pState, List *pList);

RING_API int ring_list_checkrefinleftside_gc(void *pState, List *pList);

RING_API int ring_list_checkrefvarinleftside_gc(void *pState, List *pVar);

RING_API int ring_list_isref_gc(void *pState, List *pList);

RING_API int ring_list_isrefcontainer_gc(void *pState, List *pList);

RING_API void ring_list_clearrefdata_gc(void *pState, List *pList);

RING_API int ring_list_getrefcount_gc(void *pState, List *pList);

RING_API int ring_list_getrefcountvalue_gc(void *pState, List *pList);

RING_API int ring_list_isdontref_gc(void *pState, List *pList);

RING_API void ring_list_enabledontref_gc(void *pState, List *pList);

RING_API void ring_list_disabledontref_gc(void *pState, List *pList);

RING_API int ring_list_islnewref_gc(void *pState, List *pList);

RING_API void ring_list_enablelnewref_gc(void *pState, List *pRef);

RING_API void ring_list_disablelnewref_gc(void *pState, List *pRef);

RING_API void ring_list_resetlnewref_gc(void *pState, List *pVar);

RING_API int ring_list_isdontrefagain_gc(void *pState, List *pList);

RING_API void ring_list_enabledontrefagain_gc(void *pState, List *pList);

RING_API void ring_list_disabledontrefagain_gc(void *pState, List *pList);
/* Copy list by Reference */

RING_API int ring_list_iscopybyref_gc(void *pState, List *pList);

RING_API void ring_list_enablecopybyref_gc(void *pState, List *pList);

RING_API void ring_list_disablecopybyref_gc(void *pState, List *pList);
/* Error on assignment */

RING_API void ring_list_enableerroronassignment_gc(void *pState, List *pList);

RING_API void ring_list_disableerroronassignment_gc(void *pState, List *pList);

RING_API int ring_list_iserroronassignment_gc(void *pState, List *pList);
/* Error on assignment2 */

RING_API void ring_list_enableerroronassignment2_gc(void *pState, List *pList);

RING_API void ring_list_disableerroronassignment2_gc(void *pState, List *pList);

RING_API int ring_list_iserroronassignment2_gc(void *pState, List *pList);
/* Argument Type */

RING_API void ring_list_setlisttype_gc(void *pState, List *pList, unsigned int nType);

RING_API unsigned int ring_list_getlisttype_gc(void *pState, List *pList);

RING_API int ring_list_isargcache_gc(void *pState, List *pList);

RING_API void ring_list_enableargcache_gc(void *pState, List *pList);
/* Don't Delete */

RING_API void ring_list_enabledontdelete_gc(void *pState, List *pList);

RING_API void ring_list_disabledontdelete_gc(void *pState, List *pList);
/* Memory Functions (General) */

RING_API void *ring_malloc(size_t nSize);

RING_API void ring_free(void *pPointer);

RING_API void *ring_calloc(size_t nItems, size_t nSize);

RING_API void *ring_realloc(void *pPointer, size_t nSize);
/* Memory Functions (Ring StateAware) */

RING_API void *ring_state_malloc(void *pState, size_t nSize);

RING_API void ring_state_free(void *pState, void *pMemory);

RING_API void *ring_state_calloc(void *pState, size_t nItems, size_t nSize);

RING_API void *ring_state_realloc(void *pState, void *pPointer, size_t nAllocatedSize, size_t nSize);

RING_API void ring_state_registerblock(void *pState, void *pStart, void *pEnd);

RING_API void ring_state_unregisterblock(void *pState, void *pStart);

RING_API void ring_state_willunregisterblock(void *pState, void *pStart);
/* Pool Manager Functions */

RING_API void ring_poolmanager_new(RingState *pRingState);

RING_API void ring_poolmanager_newblock(RingState *pRingState);

RING_API void *ring_poolmanager_allocate(RingState *pRingState, size_t nSize);

RING_API int ring_poolmanager_find(RingState *pRingState, void *pMemory);

RING_API int ring_poolmanager_free(RingState *pRingState, void *pMemory);

RING_API void ring_poolmanager_delete(RingState *pRingState);

RING_API void ring_poolmanager_newblockfromsubthread(RingState *pSubRingState, int nCount, RingState *pMainRingState);

RING_API void ring_poolmanager_deleteblockfromsubthread(RingState *pSubRingState, RingState *pMainRingState);
/* VMState Memory Functions */

RING_API VMState *ring_vmstate_new(RingState *pRingState);

RING_API void ring_vmstate_delete(void *pState, void *pMemory);
#endif
