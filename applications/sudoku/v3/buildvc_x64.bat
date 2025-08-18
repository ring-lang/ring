echo build Sudoku.c  code using Visual Studio C
cls
call ..\..\..\language\build\locatevc.bat x64
cl /c %ringcflags% mylibSudoku.c -I"..\..\..\language\include"
link %ringldflags% mylibSudoku.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylibSudoku.dll 
cl /c %ringcflags% mylibSudokuGenerator.c -I"..\..\..\language\include"
link %ringldflags% mylibSudokuGenerator.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylibSudokuGenerator.dll 

del mylibSudoku.obj

