if isWindows()
	LoadLib("ring_opengl21.dll")
but ismacosx()
	LoadLib("ring_opengl21.dylib")
else
	LoadLib("ring_opengl21.so")
ok

load "ring_opengl21.rh"
