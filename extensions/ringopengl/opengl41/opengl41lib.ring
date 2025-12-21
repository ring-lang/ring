if isWindows()  
	LoadLib("ring_opengl41.dll")
but ismacosx()
	LoadLib("libring_opengl41.dylib")
else
	LoadLib("libring_opengl41.so")
ok

load "ring_opengl41.rh"
