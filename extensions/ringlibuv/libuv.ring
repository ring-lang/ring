if iswindows()
	LoadLib("ring_uv.dll")
but ismacosx()
	LoadLib("libringuv.dylib")
but islinux() and not isandroid()
	LoadLib("libringuv.so")
ok
Load "ring_libuv.rh"
