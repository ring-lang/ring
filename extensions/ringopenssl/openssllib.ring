if iswindows()
	LoadLib("ring_openssl.dll")
but ismacosx()
	LoadLib("ring_openssl.dylib")
else
	LoadLib("ring_openssl.so")
ok