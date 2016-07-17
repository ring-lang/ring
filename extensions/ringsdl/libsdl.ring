Load "sdl.rh"
if iswindows()
	LoadLib("ring_sdl.dll")
but ismacosx()
	LoadLib("libringsdl.dylib")
else
	LoadLib("libringsdl.so")
ok