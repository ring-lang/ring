/* Copyright (c) 2013-2021 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_h
#define ring_h
/* Include C Headers */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
/* Required to get binary data from stdin (to be able to upload and read using cgi) */
#if __BORLANDC__
#define RING_SETBINARY setmode(fileno(stdin), O_BINARY)
#else
#define RING_SETBINARY _setmode(_fileno(stdin), _O_BINARY)
#endif
#else
#define RING_SETBINARY 0
#endif
/* Using ANSI C */
#if ULLONG_MAX
#define RING_ANSI_C 0
#else
#define RING_ANSI_C 1
#endif
/* Types */
#if RING_ANSI_C
/* Use ANSI C Types */
#define RING_LONGLONG long
#define RING_UNSIGNEDLONGLONG unsigned long
#define RING_LONGLONG_FORMAT "%ld"
#define RING_UNSIGNEDLONGLONG_FORMAT "%lx"
#define RING_LONGLONG_LOWVALUE -2147483647L -1
#define RING_LONGLONG_HIGHVALUE 2147483647L
#else
#define RING_LONGLONG long long
#define RING_UNSIGNEDLONGLONG unsigned long long
#define RING_LONGLONG_FORMAT "%lld"
#define RING_UNSIGNEDLONGLONG_FORMAT "%llx"
#define RING_LONGLONG_LOWVALUE -9007199254740991LL
#define RING_LONGLONG_HIGHVALUE 9007199254740991LL
#endif
/*
**  DLL/So 
**  Check Operating System 
*/
#ifdef _WIN32
/*
**  Windows 
**  Support Windows XP 
**  To avoid error message : procedure entry point InitializeConditionVariable could not be located in Kernel32.dll 
*/
#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif
#define _WIN32_WINNT 0x502
#define RING_USEDLL 1
#define RING_BUILDLIB 1
/* Linux */
#else
#define RING_USEDLL 0
#define RING_BUILDLIB 0
#endif
#if RING_USEDLL
#if RING_BUILDLIB
#define RING_API __declspec(dllexport)
#else
#define RING_API __declspec(dllimport)
#endif
#else
#define RING_API extern
#endif
/* Constants */
#define RING_TESTUNITS 0
#define RING_SCANNEROUTPUT 0
#define RING_PARSERSTART 1
#define RING_PARSERTRACE 1
#define RING_SHOWIC 0
#define RING_RUNVM 1
#define RING_VMSHOWOPCODE 1
#define RING_LOGFILE 0
#ifndef NDEBUG
#define NDEBUG
#endif
/* Environment Errors */
#define RING_SEGFAULT "\nError (E1) : Caught SegFault!\n"
#define RING_OOM "\nError (E2) : Out of Memory!\n"
#define RING_NOSCOPE "\nError (E3) : Deleting scope while no scope! \n"
#define RING_LONGINSTRUCTION "\nError (E4) : Long VM Instruction! \n"
#define RING_OBJFILEWRONGTYPE "\nError (E5) : The file type is not correct - the VM expect a ring object file\n"
#define RING_OBJFILEWRONGVERSION "\nError (E6) : The Ring Object File version is not correct!\n"
#define RING_SSCANFERROR "\nError (E7) : Internal error in using sscanf() function!\n"
#define RING_FSCANFERROR "\nError (E8) : Internal error in using fscanf() function!\n"
/* General */
#define RING_PATHSIZE 256
/* See and Give - use ringvm_see() and ringvm_give() */
#define RING_USESEEFUNCTION 1
#define RING_USEGIVEFUNCTION 1
/* Include Ring Headers */
#include "ring_ext.h"
#include "ring_string.h"
#include "ring_vmgcdata.h"
#include "ring_item.h"
#include "ring_items.h"
#include "ring_list.h"
#include "ring_hashlib.h"
#include "ring_hashtable.h"
#include "ring_pooldata.h"
#include "ring_state.h"
#include "ring_scanner.h"
#include "ring_parser.h"
#include "ring_codegen.h"
#include "ring_vm.h"
#include "ring_vmgc.h"
#include "ring_api.h"
#include "ring_objfile.h"
/* Extensions Headers */
#ifndef RING_EXTENSION
#ifdef RING_VM_MATH
#include "ring_vmmath.h"
#endif
#ifdef RING_VM_FILE
#include "ring_vmfile.h"
#endif
#ifdef RING_VM_OS
#include "ring_vmos.h"
#endif
#ifdef RING_VM_LISTFUNCS
#include "ring_vmlistfuncs.h"
#endif
#ifdef RING_VM_REFMETA
#include "ring_vmrefmeta.h"
#endif
#ifdef RING_VM_DLL
#include "ring_vmdll.h"
#endif
#endif
#endif
