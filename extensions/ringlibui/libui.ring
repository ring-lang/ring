if isWindows()
	LoadLib("ring_libui.dll")
but ismacosx()
	LoadLib("libring_libui.dylib")
else
	LoadLib("libring_libui.so")
ok

load "ring_libui.rh"

uiInit()

func uiControl x
	return x
