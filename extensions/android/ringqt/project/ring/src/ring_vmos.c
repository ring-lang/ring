/*
**  Copyright (c) 2013-2021 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#ifdef _WIN32
	#include "windows.h"
	typedef int (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); ;
	LPFN_ISWOW64PROCESS fnCheckWindows64  ;
#endif
#include "ring.h"
#include "ring_vmos.h"
/* Functions */

void ring_vm_os_loadfunctions ( RingState *pRingState )
{
	ring_vm_funcregister("ismsdos",ring_vm_os_ismsdos);
	ring_vm_funcregister("iswindows",ring_vm_os_iswindows);
	ring_vm_funcregister("iswindows64",ring_vm_os_iswindows64);
	ring_vm_funcregister("isunix",ring_vm_os_isunix);
	ring_vm_funcregister("ismacosx",ring_vm_os_ismacosx);
	ring_vm_funcregister("islinux",ring_vm_os_islinux);
	ring_vm_funcregister("isfreebsd",ring_vm_os_isfreebsd);
	ring_vm_funcregister("isandroid",ring_vm_os_isandroid);
	ring_vm_funcregister("windowsnl",ring_vm_os_windowsnl);
	ring_vm_funcregister("currentdir",ring_vm_os_currentdir);
	ring_vm_funcregister("exefilename",ring_vm_os_exefilename);
	ring_vm_funcregister("chdir",ring_vm_os_chdir);
	ring_vm_funcregister("exefolder",ring_vm_os_exefolder);
}

void ring_vm_os_ismsdos ( void *pPointer )
{
	#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
		RING_API_RETNUMBER(1);
	#else
		RING_API_RETNUMBER(0);
	#endif
}

void ring_vm_os_iswindows ( void *pPointer )
{
	#ifdef _WIN32
		RING_API_RETNUMBER(1);
	#else
		RING_API_RETNUMBER(0);
	#endif
}

void ring_vm_os_iswindows64 ( void *pPointer )
{
	int lSystem64  ;
	#ifdef _WIN32
		HMODULE pModule  ;
		lSystem64 = 0 ;
		pModule = GetModuleHandle(TEXT("kernel32"));
		if ( pModule != NULL ) {
			fnCheckWindows64 = (LPFN_ISWOW64PROCESS) GetProcAddress(pModule,"IsWow64Process") ;
			if ( fnCheckWindows64 != NULL ) {
				fnCheckWindows64(GetCurrentProcess(),&lSystem64);
				RING_API_RETNUMBER(lSystem64);
				return ;
			}
		}
	#endif
	RING_API_RETNUMBER(0.0);
}

void ring_vm_os_isunix ( void *pPointer )
{
	#if defined(unix) || defined(__unix__) || defined(__unix)
		RING_API_RETNUMBER(1);
	#else
		RING_API_RETNUMBER(0);
	#endif
}

void ring_vm_os_ismacosx ( void *pPointer )
{
	#if defined(__APPLE__)  || defined(__MACH__)
		RING_API_RETNUMBER(1);
	#else
		RING_API_RETNUMBER(0);
	#endif
}

void ring_vm_os_islinux ( void *pPointer )
{
	#ifdef __linux__
		RING_API_RETNUMBER(1);
	#else
		RING_API_RETNUMBER(0);
	#endif
}

void ring_vm_os_isfreebsd ( void *pPointer )
{
	#ifdef __FreeBSD__
		RING_API_RETNUMBER(1);
	#else
		RING_API_RETNUMBER(0);
	#endif
}

void ring_vm_os_isandroid ( void *pPointer )
{
	#ifdef __ANDROID__
		RING_API_RETNUMBER(1);
	#else
		RING_API_RETNUMBER(0);
	#endif
}

void ring_vm_os_windowsnl ( void *pPointer )
{
	RING_API_RETSTRING("\r\n");
}

void ring_vm_os_currentdir ( void *pPointer )
{
	char cDirPath[RING_PATHSIZE]  ;
	ring_currentdir(cDirPath);
	RING_API_RETSTRING(cDirPath);
}

void ring_vm_os_exefilename ( void *pPointer )
{
	char cDirPath[RING_PATHSIZE]  ;
	if ( ring_exefilename(cDirPath) ) {
		RING_API_RETSTRING(cDirPath);
	}
}

void ring_vm_os_chdir ( void *pPointer )
{
	RING_API_RETNUMBER(ring_chdir(RING_API_GETSTRING(1)));
}

void ring_vm_os_exefolder ( void *pPointer )
{
	char cDirPath[RING_PATHSIZE]  ;
	ring_exefolder(cDirPath);
	RING_API_RETSTRING(cDirPath);
}
