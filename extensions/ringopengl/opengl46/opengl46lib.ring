if isWindows()  
	LoadLib("ring_opengl46.dll")
but ismacosx()
	LoadLib("libring_opengl46.dylib")
else
	LoadLib("libring_opengl46.so")
ok

load "ring_opengl46.rh"
