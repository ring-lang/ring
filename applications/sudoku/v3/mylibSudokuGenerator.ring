if iswindows()
	LoadLib("mylibSudokuGenerator.dll")
but ismacosx()
	LoadLib("libmylibSudokuGenerator.dylib")
else
	LoadLib("libmylibSudokuGenerator.so")
ok