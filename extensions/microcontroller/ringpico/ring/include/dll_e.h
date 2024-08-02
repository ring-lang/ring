/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_dll_extension_h
	#define ring_dll_extension_h
	#ifdef _WIN32
		#define LoadDLL(cFileName) LoadLibrary(cFileName)
		#define GetDLLFunc GetProcAddress
		#define CloseDLL FreeLibrary
		typedef HINSTANCE LpHandleType ;
	#else
		#if RING_MSDOS
		#else
			#include <dlfcn.h>
		#endif
		#define LoadDLL(cFileName) dlopen(cFileName, RTLD_LAZY)
		#define GetDLLFunc dlsym
		#define CloseDLL dlclose
		typedef void * LpHandleType ;
	#endif
	typedef void (*loadlibfuncptr)(RingState *) ;

	void ring_vm_dll_loadfunctions ( RingState *pRingState ) ;

	void ring_vm_dll_loadlib ( void *pPointer ) ;

	void ring_vm_dll_closelib ( void *pPointer ) ;

	void ring_vm_dll_closealllibs ( VM *pVM ) ;
	/* Constants */
	#define RING_DLL_INITFUNC "ringlib_init"
	#define RING_DLL_LIBFILEMSG "Library File : "
	#define RING_VM_POINTER_DLL "DLL"
#endif
