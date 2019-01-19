==============
RingMouseEvent
==============

A simple extension for the mouse_event() function in Windows API

Created to be a simple example about creating extensions

At first we write the configuration file in : ringmouseevent.cf

	notepad ringmouseevent.cf

The file ringmouseevent.cf contains 

	<code>
	#include "windows.h"
	#include "winuser.h"
	</code>

	<runcode>
	aNumberTypes + "DWORD"
	aNumberTypes + "ULONG_PTR"
	</runcode>

	void mouse_event(DWORD dwFlags,DWORD dx, DWORD dy,DWORD dwData,ULONG_PTR dwExtraInfo)


Then we run : gencode.bat to generate ringmousevent.c

	gencode.bat

The gencode.bat contains the next command to call Ring Extensions Generator

	ring ..\codegen\parsec.ring ringmousevent.cf ringmousevent.c


Then we build the extension using : 

	buildvc.bat

The file buildvc.bat contains the next commands to build the extension using Visual C/C++ 

	cls
	call ../../src/locatevc.bat
	cl /c /DEBUG ringmouseevent.c -I"..\..\include"
	link /DEBUG ringmouseevent.obj  ..\..\lib\ring.lib kernel32.lib user32.lib /DLL /OUT:ringmouseevent.dll /SUBSYSTEM:CONSOLE,"5.01" 
	del ringmouseevent.obj

Then we test the function using

	ring test.ring

The file test.ring contains

	loadlib("ringmouseevent.dll")

	MOUSEEVENTF_LEFTDOWN = 2
	MOUSEEVENTF_LEFTUP   = 4

	x = 0
	Y = 0
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, X, Y, 0, 0)

