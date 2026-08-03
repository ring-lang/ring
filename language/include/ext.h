/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ringext_h
#define ringext_h
#ifndef RING_VM_LISTFUNCS
	#define RING_VM_LISTFUNCS 1
#endif
#ifndef RING_VM_MATH
	#define RING_VM_MATH 1
#endif
#ifndef RING_VM_FILE
	#define RING_VM_FILE 1
#endif
#ifndef RING_VM_OS
	#define RING_VM_OS 1
#endif
#ifndef RING_VM_REFMETA
	#define RING_VM_REFMETA 1
#endif
#ifndef RING_VM_INFO
	#define RING_VM_INFO 1
#endif
#if RING_NODLL
	#define RING_VM_DLL 0
#else
	#define RING_VM_DLL 1
#endif
#define RING_FILE FILE *
#define RING_OPENFILE(cFile, cMode) fopen(cFile, cMode)
#define RING_CLOSEFILE(pFile) fclose(pFile)
#define RING_READCHAR(pFile, cOut, nCount)                                                                             \
	cOut = getc(pFile) /* nCount is unused here = number of characters - default = 1 */
#endif
