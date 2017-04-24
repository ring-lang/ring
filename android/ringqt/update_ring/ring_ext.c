/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
#include "ring_qt.h"
void ring_vm_extension ( RingState *pRingState )
{
	/* Reflection and Meta-programming */
	#if RING_VM_REFMETA
	ring_vm_refmeta_loadfunctions(pRingState);
	#endif
	/* List Functions */
	#if RING_VM_LISTFUNCS
	ring_vm_listfuncs_loadfunctions(pRingState);
	#endif
	/* Math */
	#if RING_VM_MATH
	ring_vm_math_loadfunctions(pRingState);
	#endif
	/* File */
	#if RING_VM_FILE
	ring_vm_file_loadfunctions(pRingState);
	#endif
	/* OS */
	#if RING_VM_OS
	ring_vm_os_loadfunctions(pRingState);
	#endif
	/* MySQL */
	#if RING_VM_MYSQL
	ring_vm_mysql_loadfunctions(pRingState);
	#endif
	/* ODBC */
	#if RING_VM_ODBC
	ring_vm_odbc_loadfunctions(pRingState);
	#endif
	/* OPENSSL */
	#if RING_VM_OPENSSL
	ring_vm_openssl_loadfunctions(pRingState);
	#endif
	/* CURL */
	#if RING_VM_CURL
	ring_vm_curl_loadfunctions(pRingState);
	#endif
	/* DLL */
	#if RING_VM_DLL
	ring_vm_dll_loadfunctions(pRingState);
	#endif
    ring_qt_start(pRingState);

}
