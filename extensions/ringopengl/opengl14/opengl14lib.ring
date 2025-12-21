if isWindows()  
	LoadLib("ring_opengl14.dll")
but ismacosx()
	LoadLib("libring_opengl14.dylib")
else
	LoadLib("libring_opengl14.so")
ok

load "ring_opengl14.rh"
