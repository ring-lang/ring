/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_vminfo_extension_h
	#define ring_vminfo_extension_h
	/* Constants */
	#define RING_VMINFO_ITEMSTOCHECKMEMPOOL 10000

	void ring_vm_info_loadfunctions ( RingState *pRingState ) ;

	void ring_vm_info_ringvmfileslist ( void *pPointer ) ;

	void ring_vm_info_ringvmcalllist ( void *pPointer ) ;

	void ring_vm_info_ringvmmemorylist ( void *pPointer ) ;

	void ring_vm_info_ringvmfunctionslist ( void *pPointer ) ;

	void ring_vm_info_ringvmclasseslist ( void *pPointer ) ;

	void ring_vm_info_ringvmpackageslist ( void *pPointer ) ;

	void ring_vm_info_ringvmcfunctionslist ( void *pPointer ) ;

	void ring_vm_info_ringvmsettrace ( void *pPointer ) ;

	void ring_vm_info_ringvmtracedata ( void *pPointer ) ;

	void ring_vm_info_ringvmtraceevent ( void *pPointer ) ;

	void ring_vm_info_ringvmtracefunc ( void *pPointer ) ;

	void ring_vm_info_ringvmscopescount ( void *pPointer ) ;

	void ring_vm_info_ringvmevalinscope ( void *pPointer ) ;

	void ring_vm_info_ringvmpasserror ( void *pPointer ) ;

	void ring_vm_info_ringvmhideerrormsg ( void *pPointer ) ;

	void ring_vm_info_ringvmcallfunc ( void *pPointer ) ;

	void ring_vm_info_ringvminfo ( void *pPointer ) ;

	void ring_vm_info_ringvmgenarray ( void *pPointer ) ;

	void ring_vm_info_ringvmcodelist ( void *pPointer ) ;

	void ring_vm_info_ringvmismempool ( void *pPointer ) ;

	void ring_vm_info_ringvmruncode ( void *pPointer ) ;
#endif
