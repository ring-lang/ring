==============================================
Creating Extensions - Tutorial - Hello World 2
==============================================

This extension is the same as the first one but in this time, we support Windows, Linux and macOS.

	buildvc.bat
	buildgcc.sh
	buildclang.sh

Where we use buildvc.bat in Windows, buildgcc.sh in Linux and buildclang.sh in macOS

This time we use mylib.ring instead of using LoadLib() function directly

In mylib.ring we have the next code

	if iswindows()
		LoadLib("mylib.dll")
	but ismacosx()
		LoadLib("libmylib.dylib")
	else
		LoadLib("libmylib.so")
	ok

The file test.ring contains

	? "Loading Library"
	load "mylib.ring"

	? "Calling a C Function"
	myfunction()

Then we test the function using

	ring test.ring

Output

	Loading Library
	Calling a C Function
	Hello, World!

