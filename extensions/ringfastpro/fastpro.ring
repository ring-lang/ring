if iswindows()
	LoadLib("ring_fastpro.dll")
but ismacosx()
	LoadLib("libring_fastpro.dylib")
else
	LoadLib("libring_fastpro.so")
ok