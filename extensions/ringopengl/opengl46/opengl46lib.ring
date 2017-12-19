if isWindows()  
	LoadLib("ring_opengl46.dll")
but ismacosx()
	LoadLib("ring_opengl46.dylib")
else
	LoadLib("ring_opengl46.so")
ok

load "ring_opengl46.rh"
