Load "allegro.rh"
if iswindows()
	LoadLib("ring_allegro.dll")
but ismacosx()
	LoadLib("libringallegro.dylib")
but islinux() and not isandroid()
	LoadLib("libringallegro.so")
ok