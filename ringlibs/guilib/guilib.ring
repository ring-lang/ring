# Load the DLL files 
	if iswindows()
		LoadLib("ringqt.dll")
	but ismacosx()
		LoadLib("libringqt.dylib")
	but islinux()
		LoadLib("libringqt.so")
	ok
# Load the main library 
	load "constants/qt.rh"
	load "classes/ring_qt.ring"
# Load the General Objects Library 
	load "objectslib.ring"
	# Load the Objects Library - Custom classes for the GUILib 
		load "objectslib/subwindows.ring"
# Load the modern library (Better functions and classes)	
	load "modernlib/modernlib.ring"
