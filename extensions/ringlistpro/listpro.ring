if iswindows()
	LoadLib("ring_listpro.dll")
but ismacosx()
	LoadLib("libring_listpro.dylib")
else
	LoadLib("libring_listpro.so")
ok