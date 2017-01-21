if iswindows()
	LoadLib("ring_libcurl.dll")
but ismacosx()
	LoadLib("ring_libcurl.dylib")
else
	LoadLib("ring_libcurl.so")
ok

Load "ring_libcurl.rh"
