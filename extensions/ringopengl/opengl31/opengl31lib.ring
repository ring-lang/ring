if isWindows()  
	LoadLib("ring_opengl31.dll")
but ismacosx()
	LoadLib("ring_opengl31.dylib")
else
	LoadLib("ring_opengl31.so")
ok

load "ring_opengl31.rh"
