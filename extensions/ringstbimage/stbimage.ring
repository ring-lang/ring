if isWindows()
	LoadLib("ring_stbimage.dll")
but ismacosx()
	LoadLib("libring_stbimage.dylib")
else
	LoadLib("libring_stbimage.so")
ok

load "stbimage.rh"

