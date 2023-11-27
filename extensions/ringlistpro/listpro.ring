if iswindows()
	LoadLib("listpro.dll")
but ismacosx()
	LoadLib("liblistpro.dylib")
else
	LoadLib("liblistpro.so")
ok