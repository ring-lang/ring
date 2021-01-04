if isWindows()
	LoadLib("ring_tilengine.dll")
but ismacosx()
	LoadLib("libring_tilengine.dylib")
else
	LoadLib("libring_tilengine.so")
ok

load "ring_tilengine.rh"

