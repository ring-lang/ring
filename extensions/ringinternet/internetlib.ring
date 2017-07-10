if iswindows()
	LoadLib("ring_internet.dll")
but ismacosx()
	LoadLib("libring_internet.dylib")
else
	LoadLib("libring_internet.so")
ok