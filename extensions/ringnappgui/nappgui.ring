if isWindows()
	LoadLib("ring_nappgui.dll")
but ismacosx()
	LoadLib("libring_nappgui.dylib")
else
	LoadLib("libring_nappgui.so")
ok

load "ring_nappgui.rh"
