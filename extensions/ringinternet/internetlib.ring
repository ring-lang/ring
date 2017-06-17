if iswindows()
	LoadLib("ring_internet.dll")
but ismacosx()
	LoadLib("ring_internet.dylib")
else
	LoadLib("ring_internet.so")
ok