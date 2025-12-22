if isWindows()  
	LoadLib("ring_opengl20.dll")
but ismacosx()
	LoadLib("libring_opengl20.dylib")
else
	LoadLib("libring_opengl20.so")
ok

load "ring_opengl20.rh"
