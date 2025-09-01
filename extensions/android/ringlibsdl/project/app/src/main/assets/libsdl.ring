if iswindows()
	LoadLib("ring_sdl.dll")
but ismacosx()
	LoadLib("libringsdl.dylib")
but islinux() and not isandroid()
	LoadLib("libringsdl.so")
ok
Load "sdl.rh"
