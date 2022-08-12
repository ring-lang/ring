if iswindows()
	LoadLib("ring_regex.dll")
but ismacosx()
	LoadLib("libring_regex.dylib")
else
	LoadLib("libring_regex.so")
ok
