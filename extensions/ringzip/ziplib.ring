if iswindows()
	LoadLib("ring_libzip.dll")
but ismacosx()
	LoadLib("ring_libzip.dylib")
else
	LoadLib("ring_libzip.so")
ok

Load "ring_libzip.rh"
