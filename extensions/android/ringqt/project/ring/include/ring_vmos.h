/* Copyright (c) 2013-2021 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmos_h
	#define ring_vmos_h
	/* Functions */

	void ring_vm_os_loadfunctions ( RingState *pRingState ) ;

	void ring_vm_os_ismsdos ( void *pPointer ) ;

	void ring_vm_os_iswindows ( void *pPointer ) ;

	void ring_vm_os_iswindows64 ( void *pPointer ) ;

	void ring_vm_os_isunix ( void *pPointer ) ;

	void ring_vm_os_ismacosx ( void *pPointer ) ;

	void ring_vm_os_islinux ( void *pPointer ) ;

	void ring_vm_os_isfreebsd ( void *pPointer ) ;

	void ring_vm_os_isandroid ( void *pPointer ) ;

	void ring_vm_os_windowsnl ( void *pPointer ) ;

	void ring_vm_os_currentdir ( void *pPointer ) ;

	void ring_vm_os_exefilename ( void *pPointer ) ;

	void ring_vm_os_chdir ( void *pPointer ) ;

	void ring_vm_os_exefolder ( void *pPointer ) ;
	/* Constants */
	#define RING_VM_POINTER_LIBNAME "os"
	#ifdef _WIN32
		#include "windows.h"
		typedef int (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); ;
		LPFN_ISWOW64PROCESS fnCheckWindows64  ;
	#endif
#endif
