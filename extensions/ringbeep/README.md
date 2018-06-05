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

Then we build the extension using : 

	buildvc.bat

Then we test the function using

	ring test.ring

The file test.ring contains

	loadlib("ringbeep.dll")

	for f = 750 to 1000 step 50
		beep(f,300)
	next
