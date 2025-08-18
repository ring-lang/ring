cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto x64
cl /c %ringcflags% ring_freeglut.c -I "..\..\extensions\libdepwin\freeglut\include" -I"..\..\language\include"
link %ringldflags% ring_freeglut.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\freeglut\lib\x64\freeglut.lib /DLL /OUT:..\..\bin\ring_freeglut.dll
del ring_freeglut.obj
endlocal
