/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_list_extension_h
    #define ring_list_extension_h
    /* Load Functions */

    void ring_vm_listfuncs_loadfunctions ( RingState *pRingState ) ;
    /* List Functions */

    void ring_vm_listfuncs_add ( void *pPointer ) ;

    void ring_vm_listfuncs_del ( void *pPointer ) ;

    void ring_vm_listfuncs_swap ( void *pPointer ) ;

    void ring_vm_listfuncs_list ( void *pPointer ) ;

    void ring_vm_listfuncs_find ( void *pPointer ) ;

    void ring_vm_listfuncs_max ( void *pPointer ) ;

    void ring_vm_listfuncs_min ( void *pPointer ) ;

    void ring_vm_listfuncs_insert ( void *pPointer ) ;

    void ring_vm_listfuncs_sort ( void *pPointer ) ;

    void ring_vm_listfuncs_binarysearch ( void *pPointer ) ;

    void ring_vm_listfuncs_reverse ( void *pPointer ) ;
#endif
