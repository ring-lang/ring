cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ring_freeglut.c -I "..\..\extensions\libdepwin\freeglut\include" -I"..\..\language\include"
link /DEBUG ring_freeglut.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\freeglut\lib\freeglut.lib /DLL /OUT:..\..\bin\ring_freeglut.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_freeglut.obj
endlocal
