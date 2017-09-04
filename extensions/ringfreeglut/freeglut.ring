if isWindows()
	LoadLib("ring_freeglut.dll")
but ismacosx()
	LoadLib("libring_freeglut.dylib")
else
	LoadLib("libring_freeglut.so")
ok

load "ring_freeglut.rh"
