/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ringext_h
#define ringext_h
/* Constants */
#define RING_VM_LISTFUNCS 1
#define RING_VM_REFMETA 1
#define RING_VM_INFO 1
#define RING_VM_MATH 1
#define RING_VM_FILE 1
#define RING_VM_OS 1
#define RING_VM_DLL 0
/* Compiler - Scanner - Reading Files Functions */
#define RING_FILE FILE *
#define RING_OPENFILE(x,y) fopen(x,y)
#define RING_CLOSEFILE(x) fclose(x)
#define RING_READCHAR(x,y,z) y = getc(x)  /* z is unused here = number of characters - default = 1 */
#endif
