if isWindows()  
	LoadLib("ring_opengl40.dll")
but ismacosx()
	LoadLib("libring_opengl40.dylib")
else
	LoadLib("libring_opengl40.so")
ok

load "ring_opengl40.rh"
