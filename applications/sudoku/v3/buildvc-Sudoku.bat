echo build Sudoku.c  code using Visual Studio C
cls
call ..\..\..\language\src\locatevc.bat
cl /c /DEBUG mylibSudoku.c -I"..\..\..\language\include"
link /DEBUG mylibSudoku.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylibSudoku.dll /SUBSYSTEM:CONSOLE,"5.01"
cl /c /DEBUG mylibSudokuGenerator.c -I"..\..\..\language\include"
link /DEBUG mylibSudokuGenerator.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylibSudokuGenerator.dll /SUBSYSTEM:CONSOLE,"5.01"

del mylibSudoku.obj
pause

