if iswindows()
	LoadLib("ring_mysql.dll")
but ismacosx()
	LoadLib("libring_mysql.dylib")
else
	LoadLib("libring_mysql.so")
ok