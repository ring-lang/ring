if iswindows()
	LoadLib("ring_raylib.dll")
but ismacosx()
	LoadLib("libringraylib.dylib")
else
	LoadLib("libringraylib.so")
ok

load "raylib.rh"
load "raygui.rh"
load "functions.ring"
load "shader.ring"
load package "classes.ring"
