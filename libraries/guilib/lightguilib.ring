# Load the DLL files 
	if iswindows()
		LoadLib("ringqt_light.dll")
	but ismacosx()
		LoadLib("libringqt_light.dylib")
	but islinux()
		LoadLib("libringqt_light.so")
	ok
# Load the main library 
	load "constants/qt.rh"
	load "classes/ring_qt_light.ring"
# Load the MVC Custom classes for the GUILib 
		load "mvc/controllerparent.ring"
		load "mvc/viewparent.ring"
# Load the modern library (Better functions and classes)	
	load "modernlib/modernlib.ring"
# Load the Web Assembly library 
	load "webassembly/webassembly.ring"