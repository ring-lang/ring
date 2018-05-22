# Load the DLL files 
	if iswindows()
		LoadLib("ringqt.dll")
	but ismacosx()
		LoadLib("libringqt.dylib")
	but islinux()
		LoadLib("libringqt.so")
	ok
# Load the main library 
	load "qt.rh"
	load "ring_qt.ring"
# Load the Objects Library 
	load "objectslib/objects.ring"
	load "objectslib/subwindows.ring"
# Load the modern library (Better functions and classes)	
	load "modernlib/commonfunctions.ring"
	load "modernlib/newguiclasses.ring"
