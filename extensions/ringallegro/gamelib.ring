Load "allegro.rh"
if iswindows()
	LoadLib("ring_allegro.dll")
but ismacosx()
	LoadLib("libringallegro.dylib")
else
	LoadLib("libringallegro.so")
ok