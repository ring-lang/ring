/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_os_loadfunctions ( RingState *pRingState )
{
	RING_API_REGISTER("ismsdos",ring_vm_os_ismsdos);
	RING_API_REGISTER("iswindows",ring_vm_os_iswindows);
	RING_API_REGISTER("iswindows64",ring_vm_os_iswindows64);
	RING_API_REGISTER("isunix",ring_vm_os_isunix);
	RING_API_REGISTER("ismacosx",ring_vm_os_ismacosx);
	RING_API_REGISTER("islinux",ring_vm_os_islinux);
	RING_API_REGISTER("isfreebsd",ring_vm_os_isfreebsd);
	RING_API_REGISTER("isandroid",ring_vm_os_isandroid);
	RING_API_REGISTER("windowsnl",ring_vm_os_windowsnl);
	RING_API_REGISTER("currentdir",ring_vm_os_currentdir);
	RING_API_REGISTER("exefilename",ring_vm_os_exefilename);
	RING_API_REGISTER("chdir",ring_vm_os_chdir);
	RING_API_REGISTER("exefolder",ring_vm_os_exefolder);
	RING_API_REGISTER("getarch",ring_vm_os_getarch);
	RING_API_REGISTER("system",ring_vm_os_system);
	RING_API_REGISTER("shutdown",ring_vm_os_shutdown);
	#if RING_EXTRAOSFUNCTIONS
		/* Environment Variables */
		RING_API_REGISTER("sysget",ring_vm_os_sysget);
		RING_API_REGISTER("sysset",ring_vm_os_sysset);
		RING_API_REGISTER("sysunset",ring_vm_os_sysunset);
		RING_API_REGISTER("nofprocessors",ring_vm_os_nofprocessors);
		RING_API_REGISTER("uptime",ring_vm_os_uptime);
		RING_API_REGISTER("randomize",ring_vm_os_randomize);
		RING_API_REGISTER("syssleep",ring_vm_os_syssleep);
	#endif
}

void ring_vm_os_ismsdos ( void *pPointer )
{
	#if RING_MSDOS
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
		return ;
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
		#if RING_SYSTEMFUNCTION
			system(RING_API_GETSTRING(1));
		#endif
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
	exit(RING_EXIT_OK);
}
#if RING_EXTRAOSFUNCTIONS
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
				RING_API_RETSTRING(RING_CSTR_EMPTY);
			}
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	/* Visual C/C++ doesn't provide setenv() & unsetenv() functions */
	#ifdef _WIN32

		int setenv ( const char *name, const char *value, int overwrite )
		{
			int errcode = 0 ;
			size_t envsize = 0 ;
			#ifdef __BORLANDC__
				puts(RING_VM_UNSUPPORTEDFUNCTION);
				return 0 ;
			#else
				if ( ! overwrite ) {
					errcode = getenv_s(&envsize, NULL, 0, name);
					if ( errcode || envsize ) {
						return (int) errcode ;
					}
				}
				return (int) _putenv_s(name, value) ;
			#endif
		}

		int unsetenv ( const char *name )
		{
			#ifdef __BORLANDC__
				puts(RING_VM_UNSUPPORTEDFUNCTION);
				return 0 ;
			#else
				return (int) _putenv_s(name, RING_CSTR_EMPTY) ;
			#endif
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
		if ( setenv (RING_API_GETSTRING(1),RING_API_GETSTRING(2),RING_TRUE) == 0 ) {
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

		int ring_vm_os_gettime ( int clk_id, struct timespec* pTS )
		{
			RING_UNSIGNEDLONGLONG nSec  ;
			nSec = mach_absolute_time() ;
			pTS->tv_sec = nSec / NANOSEC ;
			pTS->tv_nsec = nSec % NANOSEC; ;
			return 0 ;
		}
	#endif

	void ring_vm_os_uptime ( void *pPointer )
	{
		double nTime  ;
		#ifdef _WIN32
			LARGE_INTEGER PerformanceCounterTicks, PerformanceCounterFrequency  ;
			QueryPerformanceFrequency(&PerformanceCounterFrequency);
			QueryPerformanceCounter(&PerformanceCounterTicks);
			/* Return the elapsed time in units of 0.1 microseconds for backward compatibility */
			nTime = ((double) PerformanceCounterTicks.QuadPart / (double) PerformanceCounterFrequency.QuadPart) * (double) 10000000.0 ;
		#else
			struct timespec ts  ;
			ring_vm_os_gettime(CLOCK_UPTIME, &ts);
			/* Compensate to match 0.1 ms resolution on Windows */
			nTime = ( ( ts.tv_sec * NANOSEC ) + ( ts.tv_nsec ) ) / 100 ;
		#endif
		RING_API_RETNUMBER(nTime);
	}
	/*
	**  Thread safe 
	**  53 bit thread safe random generator using high precision timer as seed on the Unix systems 
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
			nNum1 = ( ( (RING_UNSIGNEDLONGLONG) ts.tv_sec * NANOSEC ) + ts.tv_nsec ) / 100 ;
			/* Randomize by using high precision timer */
			#if defined(__ANDROID__)
				RING_API_ERROR(RING_VM_ERROR_FUNCNOTSUPPORTED);
				return ;
			#else
				nNum1 = rand_r( (unsigned int *) &ts.tv_nsec ) | ( nNum1 << 32 ) ;
			#endif
		#else
			#ifdef __BORLANDC__
				RING_API_ERROR(RING_VM_UNSUPPORTEDFUNCTION);
			#else
				LARGE_INTEGER ElapsedMicroseconds  ;
				unsigned int nNum  ;
				QueryPerformanceCounter(&ElapsedMicroseconds);
				#ifdef rand_s
					rand_s(&nNum);
				#else
					nNum = rand();
				#endif
				nNum1 = (RING_UNSIGNEDLONGLONG ) nNum | ( ElapsedMicroseconds.QuadPart << 32 ) ;
			#endif
		#endif
		if ( RING_API_PARACOUNT == 0 ) {
			/* Double have Integer precision up to 2^53 */
			RING_API_RETNUMBER(nNum1 & 0x001FFFFFFFFFFFFF);
		}
		else if ( RING_API_PARACOUNT == 1 ) {
			if ( RING_API_ISNUMBER(1) ) {
				nNum2 = RING_API_GETNUMBER(1) ;
				if ( nNum2 > 0 ) {
					RING_API_RETNUMBER((nNum1 & 0x001FFFFFFFFFFFFF) % ++nNum2);
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

	void ring_vm_os_syssleep ( void *pPointer )
	{
		int nTime  ;
		if ( RING_API_PARACOUNT != 1 ) {
			RING_API_ERROR(RING_API_BADPARACOUNT);
			return ;
		}
		if ( ! RING_API_ISNUMBER(1) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
		nTime = (int) RING_API_GETNUMBER(1) ;
		#ifdef _WIN32
			Sleep(nTime);
			RING_API_RETNUMBER(1.0);
			return ;
		#elif _POSIX_C_SOURCE >= 199309L
			struct timespec sTimeSpec  ;
			sTimeSpec.tv_sec = nTime / 1000 ;
			sTimeSpec.tv_nsec = (nTime % 1000) * 1000000 ;
			nanosleep(&sTimeSpec, NULL);
			RING_API_RETNUMBER(1.0);
			return ;
		#elif __MACH__
			usleep(nTime*1000);
			RING_API_RETNUMBER(1.0);
			return ;
		#else
			RING_API_RETNUMBER(0.0);
			return ;
		#endif
	}
#endif
