if isWindows()  
	LoadLib("ring_opengl12.dll")
but ismacosx()
	LoadLib("ring_opengl12.dylib")
else
	LoadLib("ring_opengl12.so")
ok

load "ring_opengl12.rh"
