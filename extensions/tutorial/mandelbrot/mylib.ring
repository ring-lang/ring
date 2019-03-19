if iswindows()
	LoadLib("mylib.dll")
but ismacosx()
	LoadLib("libmylib.dylib")
else
	LoadLib("libmylib.so")
ok
