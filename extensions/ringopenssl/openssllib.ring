if iswindows()
	LoadLib("ring_openssl.dll")
but ismacosx()
	LoadLib("libring_openssl.dylib")
else
	LoadLib("libring_openssl.so")
ok