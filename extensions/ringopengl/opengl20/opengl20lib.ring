if isWindows()  
	LoadLib("ring_opengl20.dll")
but ismacosx()
	LoadLib("ring_opengl20.dylib")
else
	LoadLib("ring_opengl20.so")
ok

load "ring_opengl20.rh"
