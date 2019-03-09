=============================================
Creating Extensions - Tutorial - Hello World
=============================================

A simple extension written in C language

C Source Code 

The file mylib.c contains 

	#include "ring.h"

	#include "stdlib.h"

	RING_FUNC(ring_myfunction)
	{
		printf("Hello, World!");
	}

	RING_API void ringlib_init(RingState *pRingState)
	{
		ring_vm_funcregister("myfunction",ring_myfunction);
	}


Then we build the extension using : 

	buildvc.bat

The file buildvc.bat contains the next commands to build the extension using Visual C/C++ 

	cls
	call ../../../src/locatevc.bat
	cl /c /DEBUG mylib.c -I"..\..\..\include"
	link /DEBUG mylib.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylib.dll /SUBSYSTEM:CONSOLE,"5.01" 
	del mylib.obj

Then we test the function using

	ring test.ring

The file test.ring contains

	? "Loading Library"
	loadlib("mylib.dll")

	? "Calling a C Function"
	myfunction()

Output

	Loading Library
	Calling a C Function
	Hello, World!

