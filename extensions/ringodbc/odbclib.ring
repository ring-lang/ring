if iswindows()
	LoadLib("ring_odbc.dll")
but ismacosx()
	LoadLib("libring_odbc.dylib")
else
	LoadLib("libring_odbc.so")
ok