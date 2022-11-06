Creating Extensions - Tutorial - String Pointer
===============================================

A simple extension written in C language

C Source Code

The file mylib.c contains

	#include "ring.h"
	#include "stdlib.h"

	void changeValue(char *var)
	{
		strcpy(var,"Hello from C Code");
	}

	RING_FUNC(ring_changevalue)
	{

		if (RING_API_PARACOUNT != 1)
		{
			RING_API_ERROR(RING_API_BADPARACOUNT);
			return;
		}

		if (!RING_API_ISSTRING(1))
		{
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}

		char *p1 = RING_API_GETCHARPOINTER(1);
		changeValue(p1);

	}

	RING_LIBINIT
	{
		RING_API_REGISTER("changevalue",ring_changevalue);
	}



Our function get one parameter as String

This String must contains the Variable Name (lower-case)

Using RING_API_GETCHARPOINTER we get a pointer to this variable (char *)

After that we call changeValue() function to change the variable value 

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
	
	cString = space(100)
	changevalue(:cString)
	? cString

Output

	Loading Library
	Hello from C Code