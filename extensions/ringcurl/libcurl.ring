Load "ring_libcurl.rh"
if iswindows()
	LoadLib("ring_libcurl.dll")
but ismacosx()
	LoadLib("ring_libcurl.dylib")
else
	LoadLib("ring_libcurl.so")
ok
