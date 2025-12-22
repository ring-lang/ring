if isWindows()  
	LoadLib("ring_opengl11.dll")
but ismacosx()
	LoadLib("libring_opengl11.dylib")
else
	LoadLib("libring_opengl11.so")
ok

load "ring_opengl11.rh"
