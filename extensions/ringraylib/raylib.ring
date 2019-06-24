if iswindows()
	LoadLib("ring_raylib.dll")
but ismacosx()
	LoadLib("libringraylib.dylib")
else
	LoadLib("libringraylib.so")
ok

load "raylib.rh"
load "classes.ring"
