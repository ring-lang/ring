Creating Extensions - Tutorial - Integer Pointer
================================================

A simple extension written in C language

C Source Code

The file mylib.c contains

	#include "ring.h"
	#include "stdlib.h"

	void changeValue(int *var)
	{
		*var = (*var) + 1;
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

		int *p1 = RING_API_GETINTPOINTER(1);
		changeValue(p1);
		RING_API_ACCEPTINTVALUE(1);

	}

	RING_LIBINIT
	{
		RING_API_REGISTER("changevalue",ring_changevalue);
	}

Our function get one parameter as String

This String must contains the Variable Name (lower-case)

Using RING_API_GETINTPOINTER we get a pointer to this variable (int *)

After that we call changeValue() function to change the variable value 

We refersh our Ring variable value using RING_API_ACCEPTINTVALUE

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

	? "Test passing global variables as integer pointer"
	nNum1 = 100
	changevalue(:nNum1)
	? nNum1

	changevalue(:nNum1)
	? nNum1

	test()

	new point { x=10 y=20 z=30 ? self test() }

	func test

		? "Using test() function - Pass local variables"
		y = 1516
		changevalue(:y)
		? y
		changevalue(:y)
		? y

	class point 

		x y z

		func test

			? "Using test() method - pass object attributes"

			changevalue(:x)
			? x

			changevalue(:y)
			? y

			changevalue(:z)
			? z

Output

	Loading Library
	Test passing global variables as integer pointer
	101
	102
	Using test() function - Pass local variables
	1517
	1518
	x: 10
	y: 20
	z: 30
	
	Using test() method - pass object attributes
	11
	21
	31

