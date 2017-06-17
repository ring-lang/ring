if iswindows()
	LoadLib("ring_sqlite.dll")
but ismacosx()
	LoadLib("ring_sqlite.dylib")
else
	LoadLib("ring_sqlite.so")
ok