if isWindows()  
	LoadLib("ring_opengl33.dll")
but ismacosx()
	LoadLib("ring_opengl33.dylib")
else
	LoadLib("ring_opengl33.so")
ok

load "ring_opengl33.rh"
