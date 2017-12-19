if isWindows()  
	LoadLib("ring_opengl13.dll")
but ismacosx()
	LoadLib("ring_opengl13.dylib")
else
	LoadLib("ring_opengl13.so")
ok

load "ring_opengl13.rh"
