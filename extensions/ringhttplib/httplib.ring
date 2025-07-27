if isWindows()
	LoadLib("ring_httplib.dll")
but ismacosx()
	LoadLib("libring_httplib.dylib")
else
	LoadLib("libring_httplib.so")
ok

load "ring_httplib.rh"
load "httplib_classes.ring"
load "httplib_constants.ring"
