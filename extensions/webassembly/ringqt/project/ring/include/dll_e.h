/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_dll_extension_h
    #define ring_dll_extension_h
    #ifdef _WIN32
        #include <windows.h>
        #define LoadDLL(x) LoadLibrary(x)
        #define GetDLLFunc GetProcAddress
        #define CloseDLL FreeLibrary
        typedef HINSTANCE LpHandleType ;
    #else
        #include <dlfcn.h>
        #define LoadDLL(x) dlopen(x, RTLD_LAZY)
        #define GetDLLFunc dlsym
        #define CloseDLL dlclose
        typedef void * LpHandleType ;
    #endif
    typedef void (*loadlibfuncptr)(RingState *) ;

    void ring_vm_dll_loadfunctions ( RingState *pRingState ) ;

    void ring_vm_dll_loadlib ( void *pPointer ) ;

    void ring_vm_dll_closelib ( void *pPointer ) ;

    void ring_vm_dll_closealllibs ( VM *pVM ) ;
#endif
