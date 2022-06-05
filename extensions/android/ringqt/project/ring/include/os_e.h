/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_os_extension_h
    #define ring_os_extension_h
    /* Functions */

    void ring_vm_os_loadfunctions ( RingState *pRingState ) ;

    void ring_vm_os_ismsdos ( void *pPointer ) ;

    void ring_vm_os_iswindows ( void *pPointer ) ;

    void ring_vm_os_iswindows64 ( void *pPointer ) ;

    void ring_vm_os_isunix ( void *pPointer ) ;

    void ring_vm_os_ismacosx ( void *pPointer ) ;

    void ring_vm_os_islinux ( void *pPointer ) ;

    void ring_vm_os_isfreebsd ( void *pPointer ) ;

    void ring_vm_os_isandroid ( void *pPointer ) ;

    void ring_vm_os_windowsnl ( void *pPointer ) ;

    void ring_vm_os_currentdir ( void *pPointer ) ;

    void ring_vm_os_exefilename ( void *pPointer ) ;

    void ring_vm_os_chdir ( void *pPointer ) ;

    void ring_vm_os_exefolder ( void *pPointer ) ;

    void ring_vm_os_getarch ( void *pPointer ) ;

    void ring_vm_os_system ( void *pPointer ) ;

    void ring_vm_os_shutdown ( void *pPointer ) ;
    /* Environment Variables */

    void ring_vm_os_sysget ( void *pPointer ) ;

    void ring_vm_os_sysset ( void *pPointer ) ;

    void ring_vm_os_sysunset ( void *pPointer ) ;

    void ring_vm_os_nofprocessors ( void *pPointer ) ;

    void ring_vm_os_uptime ( void *pPointer ) ;

    void ring_vm_os_randomize ( void *pPointer ) ;
    /* Constants */
    #define RING_VM_POINTER_LIBNAME "os"
    #ifdef _WIN32
        #include "windows.h"
        typedef int (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); ;
        static LPFN_ISWOW64PROCESS fnCheckWindows64  ;
        #define ring_vm_os_gettime clock_gettime
    #else
        #define MILISEC 1000
        #define MICROSEC (MILISEC*MILISEC)
        #define NANOSEC (MICROSEC*MILISEC)
        #if __MACH__
            /* Mac OS X */
            #include <mach-o/dyld.h>
            #include <mach/mach_time.h>
        #else
            #define ring_vm_os_gettime clock_gettime
        #endif
        #ifdef __FreeBSD__
            #define CLOCK_UPTIME CLOCK_UPTIME_PRECISE
        #else
            #if !defined(CLOCK_MONOTONIC_RAW)
                #define CLOCK_MONOTONIC_RAW 0
            #endif
            #define CLOCK_UPTIME CLOCK_MONOTONIC_RAW
        #endif
    #endif
#endif
