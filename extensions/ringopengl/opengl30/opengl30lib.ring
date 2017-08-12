if isWindows()  
	LoadLib("ring_opengl30.dll")
but ismacosx()
	LoadLib("ring_opengl30.dylib")
else
	LoadLib("ring_opengl30.so")
ok

load "ring_opengl30.rh"
