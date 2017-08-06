if isWindows()
	LoadLib("ring_freeglut.dll")
but ismacosx()
	LoadLib("ring_freeglut.dylib")
else
	LoadLib("ring_freeglut.so")
ok

load "ring_freeglut.rh"
