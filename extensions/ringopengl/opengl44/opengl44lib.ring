if isWindows()  
	LoadLib("ring_opengl44.dll")
but ismacosx()
	LoadLib("ring_opengl44.dylib")
else
	LoadLib("ring_opengl44.so")
ok

load "ring_opengl44.rh"
