if isWindows()  
	LoadLib("ring_opengl42.dll")
but ismacosx()
	LoadLib("libring_opengl42.dylib")
else
	LoadLib("libring_opengl42.so")
ok

load "ring_opengl42.rh"
