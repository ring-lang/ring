rem clang-format -style=Google ..\src\*.c -i

rem clang-format --style=file ..\src\*.c -i 

clang-format --style=file:myformat.txt ..\src\*.c -i