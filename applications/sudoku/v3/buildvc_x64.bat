echo build Sudoku.c  code using Visual Studio C
cls
call ..\..\..\language\build\locatevc.bat x64
cl /c /DEBUG mylibSudoku.c -I"..\..\..\language\include"
link /DEBUG mylibSudoku.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylibSudoku.dll 
cl /c /DEBUG mylibSudokuGenerator.c -I"..\..\..\language\include"
link /DEBUG mylibSudokuGenerator.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylibSudokuGenerator.dll 

del mylibSudoku.obj

