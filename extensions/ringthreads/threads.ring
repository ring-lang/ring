if isWindows()
	LoadLib("ring_threads.dll")
but ismacosx()
	LoadLib("libring_threads.dylib")
else
	LoadLib("libring_threads.so")
ok

load "ring_threads.rh"

