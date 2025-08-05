rem Just if you want to format the C code.

clang-format -style="{ColumnLimit: 120, UseTab: Always, IndentWidth: 8, TabWidth: 8}" ..\src\*.c -i
clang-format -style="{ColumnLimit: 120, UseTab: Always, IndentWidth: 8, TabWidth: 8}" ..\include\*.h -i
