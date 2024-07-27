/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_gc_h
	#define ring_gc_h
	/*
	**  Functions 
	**  Item GC Functions 
	*/
	#define ring_vm_gc_cleardata(pItem) pItem->nGCReferenceCount = 0; pItem->pGCFreeFunc = NULL

	void ring_vm_gc_checknewreference ( VM *pVM,void *pPointer,int nType,List *pContainer, int nIndex ) ;

	void ring_vm_gc_checkupdatereference ( VM *pVM,List *pList ) ;

	void ring_vm_gc_deleteitem ( Item *pItem ) ;

	void ring_vm_gc_killreference ( VM *pVM ) ;

	void ring_vm_gc_deletetemplists ( VM *pVM ) ;
	#define ring_vm_gc_newitemreference(pItem) pItem->nGCReferenceCount++

	void ring_vm_gc_freefunc ( RingState *pState,Item *pItem ) ;

	void ring_vm_gc_setfreefunc ( Item *pItem, void (* pFreeFunc)(void *,void *) ) ;

	void ring_vm_gc_deletelistinitem ( void *pState,void *pList ) ;

	void ring_vm_gc_listpointerismine ( List *pList,int nIndex ) ;

	void ring_vm_gc_listpointerisnotmine ( List *pList,int nIndex ) ;

	void ring_vm_gc_removetrack ( RingState *pState,List *pList ) ;
	/*
	**  List GC Functions 
	**  Copy list by Reference 
	*/

	RING_API int ring_list_iscopybyref ( List *pList ) ;

	RING_API void ring_list_enablecopybyref ( List *pList ) ;

	RING_API void ring_list_disablecopybyref ( List *pList ) ;
	/* References */

	RING_API void ring_list_acceptlistbyref_gc ( void *pState,List *pList, unsigned int index,List *pRef ) ;

	RING_API void ring_list_setlistbyref_gc ( void *pState,List *pList, unsigned int index,List *pRef ) ;

	RING_API void ring_list_updaterefcount_gc ( void *pState,List *pList, int nChange ) ;

	RING_API List * ring_list_newref_gc ( void *pState, List *pVariableList, List *pList ) ;

	RING_API int ring_list_isref ( List *pList ) ;

	RING_API void ring_list_assignreftovar_gc ( void *pState,List *pRef,List *pVar,unsigned int nPos ) ;

	RING_API void ring_list_assignreftoitem_gc ( void *pState,List *pRef,Item *pItem ) ;

	RING_API int ring_list_isrefcontainer ( List *pList ) ;

	RING_API void ring_list_clearrefdata ( List *pList ) ;

	RING_API List * ring_list_deleteref_gc ( void *pState,List *pList ) ;

	RING_API List * ring_list_getrefcontainer ( List *pList ) ;

	RING_API List * ring_list_collectcycles_gc ( void *pState,List *pList ) ;

	RING_API int ring_list_containssublist_gc ( void *pState,List *pList,List *pCheck ) ;

	RING_API int ring_list_iscircular_gc ( void *pState,List *pList ) ;

	RING_API int ring_list_checkrefinleftside ( void *pState,List *pList ) ;

	RING_API int ring_list_checkrefvarinleftside ( void *pState,List *pVar ) ;

	RING_API int ring_list_getrefcount ( List *pList ) ;

	RING_API int ring_list_isrefparameter ( VM *pVM,const char *cVariable ) ;

	RING_API int ring_list_isdontref ( List *pList ) ;

	RING_API void ring_list_enabledontref ( List *pList ) ;

	RING_API void ring_list_disabledontref ( List *pList ) ;

	RING_API void ring_list_resetlnewref ( List *pVar ) ;

	RING_API int ring_list_isnewref ( List *pList ) ;

	RING_API void ring_list_disablelnewref ( List *pRef ) ;

	RING_API int ring_list_isdontrefagain ( List *pList ) ;

	RING_API void ring_list_enabledontrefagain ( List *pList ) ;

	RING_API void ring_list_disabledontrefagain ( List *pList ) ;
	/* Error on assignment */

	RING_API void ring_list_enableerroronassignment ( List *pList ) ;

	RING_API void ring_list_disableerroronassignment ( List *pList ) ;

	RING_API int ring_list_iserroronassignment ( List *pList ) ;
	/* Error on assignment2 */

	RING_API void ring_list_enableerroronassignment2 ( List *pList ) ;

	RING_API void ring_list_disableerroronassignment2 ( List *pList ) ;

	RING_API int ring_list_iserroronassignment2 ( List *pList ) ;
	/* Argument Type */

	void ring_list_setlisttype ( List *pList,int nType ) ;

	int ring_list_getlisttype ( List *pList ) ;

	int ring_list_isargcache ( List *pList ) ;

	void ring_list_enableargcache ( List *pList ) ;
	/* Don't Delete */

	RING_API void ring_list_enabledontdelete ( List *pList ) ;

	RING_API void ring_list_disabledontdelete ( List *pList ) ;
	/* Memory Functions (General) */

	RING_API void * ring_malloc ( size_t nSize ) ;

	RING_API void ring_free ( void *pPointer ) ;

	RING_API void * ring_calloc ( size_t nItems, size_t nSize ) ;

	RING_API void * ring_realloc ( void *pPointer, size_t nSize ) ;
	/* Memory Functions (Ring StateAware) */

	RING_API void * ring_state_malloc ( void *pState,size_t nSize ) ;

	RING_API void ring_state_free ( void *pState,void *pMemory ) ;

	RING_API void * ring_state_calloc ( void *pState,size_t nItems, size_t nSize ) ;

	RING_API void * ring_state_realloc ( void *pState,void *pPointer,size_t nAllocatedSize,size_t nSize ) ;

	void ring_vm_gc_deleteitem_gc ( void *pState,Item *pItem ) ;

	RING_API void ring_state_registerblock ( void *pState,void *pStart, void *pEnd ) ;

	RING_API void ring_state_unregisterblock ( void *pState,void *pStart ) ;

	RING_API void ring_state_willunregisterblock ( void *pState,void *pStart ) ;
	/* Pool Manager Functions */

	void ring_poolmanager_newblock ( RingState *pRingState ) ;

	void * ring_poolmanager_allocate ( RingState *pRingState,size_t nSize ) ;

	int ring_poolmanager_find ( RingState *pRingState,void *pMemory ) ;

	int ring_poolmanager_free ( RingState *pRingState,void *pMemory ) ;

	void ring_poolmanager_new ( RingState *pRingState ) ;

	void ring_poolmanager_delete ( RingState *pRingState ) ;

	void ring_poolmanager_newblockfromsubthread ( RingState *pSubRingState,int nCount,RingState *pMainRingState ) ;

	void ring_poolmanager_deleteblockfromsubthread ( RingState *pSubRingState,RingState *pMainRingState ) ;
	/* VMState Memory Functions */

	VMState * ring_vmstate_new ( RingState *pRingState ) ;

	void ring_vmstate_delete ( void *pState,void *pMemory ) ;
#endif
