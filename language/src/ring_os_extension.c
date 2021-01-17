/*
**  Copyright (c) 2013-2021 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
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
	ring_vm_funcregister("getarch",ring_vm_os_getarch);
	ring_vm_funcregister("system",ring_vm_os_system);
	ring_vm_funcregister("shutdown",ring_vm_os_shutdown);
	ring_vm_funcregister("nofprocessors",ring_vm_os_nofprocessors);
	ring_vm_funcregister("uptime",ring_vm_os_uptime);
	ring_vm_funcregister("randomize",ring_vm_os_randomize);
	/* Environment Variables */
	ring_vm_funcregister("sysget",ring_vm_os_sysget);
	ring_vm_funcregister("sysset",ring_vm_os_sysset);
	ring_vm_funcregister("sysunset",ring_vm_os_sysunset);
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
	#ifdef _WIN64
		RING_API_RETNUMBER(1);
	#elif _WIN32
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
	ring_general_currentdir(cDirPath);
	RING_API_RETSTRING(cDirPath);
}

void ring_vm_os_exefilename ( void *pPointer )
{
	char cDirPath[RING_PATHSIZE]  ;
	if ( ring_general_exefilename(cDirPath) ) {
		RING_API_RETSTRING(cDirPath);
	}
}

void ring_vm_os_chdir ( void *pPointer )
{
	RING_API_RETNUMBER(ring_general_chdir(RING_API_GETSTRING(1)));
}

void ring_vm_os_exefolder ( void *pPointer )
{
	char cDirPath[RING_PATHSIZE]  ;
	ring_general_exefolder(cDirPath);
	RING_API_RETSTRING(cDirPath);
}

void ring_vm_os_getarch ( void *pPointer )
{
	#if (defined(_M_X64) || defined(__x86_64__))
		RING_API_RETSTRING("x64");
	#elif (defined(_M_IX86) || defined(__i386__) || defined(__i386) || defined(_X86_) || defined(__I86__))
		RING_API_RETSTRING("x86");
	#elif (defined(__arm64__) || defined(__aarch64__) || defined(_M_ARM64))
		RING_API_RETSTRING("arm64");
	#elif (defined(__arm__) || defined(_M_ARM) || defined(__aarch32__))
		RING_API_RETSTRING("arm");
	#else
		RING_API_RETSTRING("unknown");
	#endif
}

void ring_vm_os_system ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		system(RING_API_GETSTRING(1));
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_os_shutdown ( void *pPointer )
{
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
			exit(RING_API_GETNUMBER(1));
			return ;
		}
	}
	exit(0);
}
/* Environment Variables */

void ring_vm_os_sysget ( void *pPointer )
{
	char *pData  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		pData = getenv(RING_API_GETSTRING(1));
		if ( pData != NULL ) {
			RING_API_RETSTRING(pData);
		}
		else {
			RING_API_RETSTRING("");
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
/* Visual C/C++ doesn't provide setenv() & unsetenv() functions */
#ifdef _MSC_VER

	int setenv ( const char *name, const char *value, int overwrite )
	{
		errno_t errcode = 0 ;
		size_t envsize = 0 ;
		if ( ! overwrite ) {
			errcode = getenv_s(&envsize, NULL, 0, name);
			if ( errcode || envsize ) {
				return (int) errcode ;
			}
		}
		return (int) _putenv_s(name, value) ;
	}

	int unsetenv ( const char *name )
	{
		return (int) _putenv_s(name, "") ;
	}
#endif

void ring_vm_os_sysset ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) ) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( setenv (RING_API_GETSTRING(1),RING_API_GETSTRING(2),1) == 0 ) {
		RING_API_RETNUMBER(1);
	}
	else {
		RING_API_RETNUMBER(0);
	}
}

void ring_vm_os_sysunset ( void *pPointer )
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		if ( unsetenv(RING_API_GETSTRING(1)) == 0 ) {
			RING_API_RETNUMBER(1);
		}
		else {
			RING_API_RETNUMBER(0);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_os_nofprocessors ( void *pPointer )
{
	#ifdef _WIN32
		SYSTEM_INFO sysinfo  ;
		GetSystemInfo(&sysinfo);
		RING_API_RETNUMBER(sysinfo.dwNumberOfProcessors);
	#else
		RING_API_RETNUMBER((double)sysconf(_SC_NPROCESSORS_ONLN));
	#endif
}
/*
**  Mac OS doesn't provide clock_gettime function prior v. 10.12 
**  Custom function is going to work on all Mac OS versions 
*/
#if defined __MACH__

	int ring_vm_os_gettime ( int clk_id, struct timespec* ts )
	{
		uint64_t nsec = mach_absolute_time() ;
		ts->tv_sec = nsec / NANOSEC ;
		ts->tv_nsec = nsec % NANOSEC; ;
		return 0 ;
	}
#endif

double ring_vm_os_getuptime ( void )
{
	#ifdef _WIN32
		LARGE_INTEGER ElapsedMicroseconds  ;
		QueryPerformanceCounter(&ElapsedMicroseconds);
		return ElapsedMicroseconds.QuadPart ;
	#else
		struct timespec ts  ;
		ring_vm_os_gettime(CLOCK_UPTIME, &ts);
		/* Compensate to match 0.1 ms resolution on Windows */
		return ( ( ts.tv_sec * NANOSEC ) + ( ts.tv_nsec ) ) / 100 ;
	#endif
}

void ring_vm_os_uptime ( void *pPointer )
{
	RING_API_RETNUMBER(ring_vm_os_getuptime());
}
/*
**  Thread safe 
**  64 bit thread safe random generator using high precision timer as seed on the Unix systems 
**  Or using Windows Security Features by the CRT having the _s ("secure") suffix since XP 
**  This random generator doesn't require a seed to be given by the user 
*/

void ring_vm_os_randomize ( void *pPointer )
{
	RING_UNSIGNEDLONGLONG nNum1,nNum2  ;
	#if ! defined(_WIN32)
		struct timespec ts  ;
		ring_vm_os_gettime(CLOCK_UPTIME, &ts);
		/* Compensate to match 0.1 ms resolution on Windows */
		nNum1 = ( ( ts.tv_sec * NANOSEC ) + ts.tv_nsec ) / 100 ;
		/* Randomize by using high precision timer */
		#if defined(__ANDROID__)
			RING_API_ERROR("The Randomize() function is not supported on Android");
			return ;
		#else
			nNum1 *= rand_r( (unsigned int *) &ts.tv_nsec ) ;
		#endif
	#else
		LARGE_INTEGER ElapsedMicroseconds  ;
		QueryPerformanceCounter(&ElapsedMicroseconds);
		rand_s(&nNum2);
		nNum1 = ElapsedMicroseconds.QuadPart * nNum2 ;
	#endif
	if ( RING_API_PARACOUNT == 0 ) {
		RING_API_RETNUMBER(nNum1);
	}
	else if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
			nNum2 = RING_API_GETNUMBER(nNum1) ;
			if ( nNum2 > 0 ) {
				RING_API_RETNUMBER(nNum1 % ++nNum2);
			}
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARACOUNT);
	}
}
