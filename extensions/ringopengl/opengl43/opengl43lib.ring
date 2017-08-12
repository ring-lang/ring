if isWindows()  
	LoadLib("ring_opengl43.dll")
but ismacosx()
	LoadLib("ring_opengl43.dylib")
else
	LoadLib("ring_opengl43.so")
ok

load "ring_opengl43.rh"
