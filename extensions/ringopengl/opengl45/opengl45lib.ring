if isWindows()  
	LoadLib("ring_opengl45.dll")
but ismacosx()
	LoadLib("ring_opengl45.dylib")
else
	LoadLib("ring_opengl45.so")
ok

load "ring_opengl45.rh"
