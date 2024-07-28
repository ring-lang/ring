/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_extension ( RingState *pRingState )
{
	/* List */
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
	/* DLL */
	#if RING_VM_DLL
		ring_vm_dll_loadfunctions(pRingState);
	#endif
	/* Reflection and Meta-programming */
	#if RING_VM_REFMETA
		ring_vm_refmeta_loadfunctions(pRingState);
	#endif
	/* VM Infor */
	#if RING_VM_INFO
		ring_vm_info_loadfunctions(pRingState);
	#endif
}
