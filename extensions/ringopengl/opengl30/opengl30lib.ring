if isWindows()  
	LoadLib("ring_opengl30.dll")
but ismacosx()
	LoadLib("libring_opengl30.dylib")
else
	LoadLib("libring_opengl30.so")
ok

load "ring_opengl30.rh"
