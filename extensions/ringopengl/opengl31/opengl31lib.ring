if isWindows()  
	LoadLib("ring_opengl31.dll")
but ismacosx()
	LoadLib("libring_opengl31.dylib")
else
	LoadLib("libring_opengl31.so")
ok

load "ring_opengl31.rh"
