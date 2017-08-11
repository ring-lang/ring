if isWindows()  
	LoadLib("ring_opengl15.dll")
but ismacosx()
	LoadLib("ring_opengl15.dylib")
else
	LoadLib("ring_opengl15.so")
ok

load "ring_opengl15.rh"
