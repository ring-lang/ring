/* Copyright (c) 2013-2021 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmlistfuncs_h
	#define ring_vmlistfuncs_h
	/* Load Functions */

	void ring_vm_listfuncs_loadfunctions ( RingState *pRingState ) ;
	/* List Functions */

	void ring_vmlib_list ( void *pPointer ) ;

	void ring_vmlib_find ( void *pPointer ) ;

	void ring_vmlib_max ( void *pPointer ) ;

	void ring_vmlib_min ( void *pPointer ) ;

	void ring_vmlib_insert ( void *pPointer ) ;

	void ring_vmlib_sort ( void *pPointer ) ;

	void ring_vmlib_binarysearch ( void *pPointer ) ;

	void ring_vmlib_reverse ( void *pPointer ) ;
#endif
