========
RingBeep
========

A simple extension for the beep() function in Windows API

Created to be a simple example about creating extensions

At first we write the configuration file in : ringbeep.cf

	notepad ringbeep.cf

Then we run : gencode.bat to generate ringbeep.c

	gencode.bat

Then we build the extension using : 

	buildvc.bat

Then we test the function using

	ring test.ring


