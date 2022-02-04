if isWindows()
	LoadLib("ring_cjson.dll")
but ismacosx()
	LoadLib("libring_cjson.dylib")
else
	LoadLib("libring_cjson.so")
ok

load "ring_cjson.rh"

