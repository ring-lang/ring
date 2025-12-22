if isWindows()  
	LoadLib("libring_opengl32.dll")
but ismacosx()
	LoadLib("libring_opengl32.dylib")
else
	LoadLib("libring_opengl32.so")
ok

load "ring_opengl32.rh"
