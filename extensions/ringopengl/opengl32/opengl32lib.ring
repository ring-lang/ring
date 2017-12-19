if isWindows()  
	LoadLib("ring_opengl32.dll")
but ismacosx()
	LoadLib("ring_opengl32.dylib")
else
	LoadLib("ring_opengl32.so")
ok

load "ring_opengl32.rh"
