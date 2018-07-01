if iswindows()
	LoadLib("ring_pgsql.dll")
but ismacosx()
	LoadLib("libring_pgsql.dylib")
else
	LoadLib("libring_pgsql.so")
ok