/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ringext_h
	#define ringext_h
	#define RING_VM_PICO 1
	#define RING_VM_LISTFUNCS 1
	#define RING_VM_MATH 1
	#define RING_VM_FILE 1
	#define RING_VM_OS 1
	#define RING_VM_REFMETA 1
	#define RING_VM_INFO 1
	#if RING_LOWMEM
		#define RING_VM_DLL 0
	#else
		#define RING_VM_DLL 1
	#endif
	#define RING_FILE FILE *
	#define RING_OPENFILE(cFile,cMode) fopen(cFile,cMode)
	#define RING_CLOSEFILE(pFile) fclose(pFile)
	#define RING_READCHAR(pFile,cOut,nCount) cOut = getc(pFile)  /* nCount is unused here = number of characters - default = 1 */
#endif
