========
RingBeep
========

A simple extension for the beep() function in Windows API

Created to be a simple example about creating extensions

At first we write the configuration file in : ringbeep.cf

	notepad ringbeep.cf

The file ringbeep.cf contains 

	<code>
	#include "windows.h"
	</code>

	int Beep(int dwFreq,int dwDuration)

Then we run : gencode.bat to generate ringbeep.c

	gencode.bat

The gencode.bat contains the next command to call Ring Extensions Generator

	ring ..\codegen\parsec.ring ringbeep.cf ringbeep.c


Then we build the extension using : 

	buildvc.bat

The file buildvc.bat contains the next commands to build the extension using Visual C/C++ 

	cls
	call ../../src/locatevc.bat
	cl /c /DEBUG ringbeep.c -I"..\..\include"
	link /DEBUG ringbeep.obj  ..\..\lib\ring.lib kernel32.lib /DLL /OUT:ringbeep.dll /SUBSYSTEM:CONSOLE,"5.01" 
	del ringbeep.obj

Then we test the function using

	ring test.ring

The file test.ring contains

	loadlib("ringbeep.dll")

	for f = 750 to 1000 step 50
		beep(f,300)
	next
