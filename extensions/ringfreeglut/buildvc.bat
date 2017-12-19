cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_freeglut.c -I "..\..\libdepwin\freeglut\include" -I"..\..\include"
link /DEBUG ring_freeglut.obj  ..\..\lib\ring.lib ..\..\libdepwin\freeglut\lib\freeglut.lib /DLL /OUT:..\..\bin\ring_freeglut.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_freeglut.obj