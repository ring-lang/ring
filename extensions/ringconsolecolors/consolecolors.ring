if iswindows()
	LoadLib("ring_consolecolors.dll")
but ismacosx()
	LoadLib("libring_consolecolors.dylib")
else
	LoadLib("libring_consolecolors.so")
ok

Load "ring_consolecolors.rh"

