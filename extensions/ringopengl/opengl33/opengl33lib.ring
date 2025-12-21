if isWindows()  
	LoadLib("ring_opengl33.dll")
but ismacosx()
	LoadLib("libring_opengl33.dylib")
else
	LoadLib("libring_opengl33.so")
ok

load "ring_opengl33.rh"
