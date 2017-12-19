if isWindows()  
	LoadLib("ring_opengl41.dll")
but ismacosx()
	LoadLib("ring_opengl41.dylib")
else
	LoadLib("ring_opengl41.so")
ok

load "ring_opengl41.rh"
