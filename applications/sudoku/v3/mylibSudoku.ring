if iswindows()
	LoadLib("mylibSudoku.dll")
but ismacosx()
	LoadLib("libmylibSudoku.dylib")
else
	LoadLib("libmylibSudoku.so")
ok