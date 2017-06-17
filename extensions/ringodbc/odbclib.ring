if iswindows()
	LoadLib("ring_odbc.dll")
but ismacosx()
	LoadLib("ring_odbc.dylib")
else
	LoadLib("ring_odbc.so")
ok