if isWindows()  
	LoadLib("ring_opengl44.dll")
but ismacosx()
	LoadLib("libring_opengl44.dylib")
else
	LoadLib("libring_opengl44.so")
ok

load "ring_opengl44.rh"
