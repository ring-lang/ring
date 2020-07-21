/* Copyright (c) 2013-2015 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_dynamiclib_h
#define ring_dynamiclib_h
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
typedef (void*) LpHandleType ;
#endif
typedef void (*loadlibfuncptr)(RingState *); ;
#endif
