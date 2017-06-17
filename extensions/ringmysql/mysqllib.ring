if iswindows()
	LoadLib("ring_mysql.dll")
but ismacosx()
	LoadLib("ring_mysql.dylib")
else
	LoadLib("ring_mysql.so")
ok