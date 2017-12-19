if isWindows()  
	LoadLib("ring_opengl11.dll")
but ismacosx()
	LoadLib("ring_opengl11.dylib")
else
	LoadLib("ring_opengl11.so")
ok

load "ring_opengl11.rh"
