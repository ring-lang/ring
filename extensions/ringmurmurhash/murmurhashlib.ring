if iswindows()
	LoadLib("ring_murmurhash.dll")
but ismacosx()
	LoadLib("libring_murmurhash.dylib")
else
	LoadLib("libring_murmurhash.so")
ok
