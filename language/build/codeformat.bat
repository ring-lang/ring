rem Just if you want to format the C code.

clang-format -style="{BasedOnStyle: Microsoft, UseTab: Always}" ..\src\*.c -i
clang-format -style="{BasedOnStyle: Microsoft, UseTab: Always}" ..\include\*.h -i
