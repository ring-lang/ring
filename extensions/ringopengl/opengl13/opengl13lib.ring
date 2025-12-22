if isWindows()  
	LoadLib("ring_opengl13.dll")
but ismacosx()
	LoadLib("libring_opengl13.dylib")
else
	LoadLib("libring_opengl13.so")
ok

load "ring_opengl13.rh"
