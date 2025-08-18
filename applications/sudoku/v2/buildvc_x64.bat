echo build Sudoku.c  code using Visual Studio C
cls
call ..\..\..\language\build\locatevc.bat x64
cl /c %ringcflags% mylibSudoku.c -I"..\..\..\language\include"
link %ringldflags% mylibSudoku.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylibSudoku.dll
del mylibSudoku.obj