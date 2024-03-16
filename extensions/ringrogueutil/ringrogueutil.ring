if isWindows()
	LoadLib("ring_rogueutil.dll")
but ismacosx()
	LoadLib("libring_rogueutil.dylib")
else
	LoadLib("libring_rogueutil.so")
ok

load "ring_rogueutil.rh"
load "ring_mouseinfo.rh"
load "ring_mouseinfo.ring"
