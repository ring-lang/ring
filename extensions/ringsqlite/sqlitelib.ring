if iswindows()
	LoadLib("ring_sqlite.dll")
but ismacosx()
	LoadLib("libring_sqlite.dylib")
else
	LoadLib("libring_sqlite.so")
ok