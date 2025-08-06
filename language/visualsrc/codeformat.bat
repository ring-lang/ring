ring commentsnl.ring

clang-format -style="{ColumnLimit: 120, UseTab: Always, IndentWidth: 8, TabWidth: 8, IndentPPDirectives: BeforeHash, SortIncludes: Never}" ..\src\*.c -i
clang-format -style="{ColumnLimit: 120, UseTab: Always, IndentWidth: 8, TabWidth: 8, IndentPPDirectives: BeforeHash, SortIncludes: Never}" ..\include\*.h -i
