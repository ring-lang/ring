/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_h
#define ring_h
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
#define RING_DEBUG 0
#define RING_TESTUNITS 0
#define RING_TESTPERFORMANCE 1
#define RING_SCANNEROUTPUT 0
#define RING_PARSERSTART 1
#define RING_PARSERTRACE 1
#define RING_PARSERFINAL 0
#define RING_SHOWIC 0
#define RING_RUNVM 1
#define RING_VMSHOWOPCODE 1
#define RING_OOM "\nError : Out of Memory\n"
#define NDEBUG
/*
**  Include Files 
**  Include C Headers 
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "signal.h"
#ifdef _WIN32
#include "io.h"
#include "fcntl.h"
/* Required to get binary data from stdin (to be able to upload and read using cgi) */
#if __BORLANDC__
#define RING_SETBINARY setmode(fileno(stdin), O_BINARY)
#else
#define RING_SETBINARY _setmode(_fileno(stdin), _O_BINARY)
#endif
#else
#define RING_SETBINARY ((void)0)
#endif
#include <errno.h>
/* Include Project Headers */
#include "ring_ext.h"
#include "ring_string.h"
#include "ring_vmgcdata.h"
#include "ring_item.h"
#include "ring_items.h"
#include "ring_list.h"
#include "ring_state.h"
#include "ring_scanner.h"
#include "ring_parser.h"
#include "ring_codegen.h"
#include "ring_vm.h"
#include "ring_vmgc.h"
#include "ring_api.h"
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
#ifdef RING_VM_MYSQL
#include "ring_vmmysql.h"
#endif
#ifdef RING_VM_ODBC
#include "ring_vmodbc.h"
#endif
#ifdef RING_VM_OPENSSL
#include "ring_vmopenssl.h"
#endif
#ifdef RING_VM_CURL
#include "ring_vmcurl.h"
#endif
#ifdef RING_VM_DLL
#include "ring_vmdll.h"
#endif
#include "ring_hashlib.h"
#include "ring_hashtable.h"
#endif
