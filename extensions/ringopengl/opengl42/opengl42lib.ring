if isWindows()  
	LoadLib("ring_opengl42.dll")
but ismacosx()
	LoadLib("ring_opengl42.dylib")
else
	LoadLib("ring_opengl42.so")
ok

load "ring_opengl42.rh"
