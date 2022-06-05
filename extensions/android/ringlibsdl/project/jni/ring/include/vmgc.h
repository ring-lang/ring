/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_gc_h
    #define ring_gc_h
    /*
    **  Functions 
    **  GC Functions 
    */

    void ring_vm_gc_cleardata ( Item *pItem ) ;

    void ring_vm_gc_checkreferences ( VM *pVM ) ;

    void ring_vm_gc_checknewreference ( void *pPointer,int nType ) ;

    void ring_vm_gc_checkupdatereference ( VM *pVM,List *pList ) ;

    void ring_vm_gc_deleteitem ( Item *pItem ) ;

    void ring_vm_gc_killreference ( VM *pVM ) ;

    void ring_vm_gc_deletetemplists ( VM *pVM ) ;

    void ring_vm_gc_newitemreference ( Item *pItem ) ;

    void ring_vm_gc_freefunc ( RingState *pState,Item *pItem ) ;

    void ring_vm_gc_setfreefunc ( Item *pItem, void (* pFreeFunc)(void *,void *) ) ;
    /* Memory Functions (General) */

    RING_API void * ring_malloc ( size_t size ) ;

    RING_API void ring_free ( void *ptr ) ;

    RING_API void * ring_calloc ( size_t nitems, size_t size ) ;

    RING_API void * ring_realloc ( void *ptr, size_t size ) ;
    /* Memory Functions (Ring StateAware) */

    RING_API void * ring_state_malloc ( void *pState,size_t size ) ;

    RING_API void ring_state_free ( void *pState,void *pMemory ) ;

    RING_API void * ring_state_calloc ( void *pState,size_t nitems, size_t size ) ;

    RING_API void * ring_state_realloc ( void *pState,void *ptr,size_t nAllocatedSize,size_t size ) ;

    void ring_vm_gc_deleteitem_gc ( void *pState,Item *pItem ) ;

    RING_API void ring_state_registerblock ( void *pState,void *pStart, void *pEnd ) ;

    RING_API void ring_state_unregisterblock ( void *pState,void *pStart ) ;
    /* Macro */
    #define GCLog 0
    /* Pool Manager Functions */

    void ring_poolmanager_newblock ( RingState *pRingState ) ;

    void * ring_poolmanager_allocate ( RingState *pRingState,size_t size ) ;

    int ring_poolmanager_find ( RingState *pRingState,void *pMemory ) ;

    int ring_poolmanager_free ( RingState *pRingState,void *pMemory ) ;

    void ring_poolmanager_new ( RingState *pRingState ) ;

    void ring_poolmanager_delete ( RingState *pRingState ) ;

    void ring_poolmanager_newblockfromsubthread ( RingState *pSubRingState,int nCount,RingState *pMainRingState ) ;

    void ring_poolmanager_deleteblockfromsubthread ( RingState *pSubRingState,RingState *pMainRingState ) ;
#endif
