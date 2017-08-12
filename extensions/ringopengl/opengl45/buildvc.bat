cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_opengl45.c -I "..\..\..\libdepwin\glew\include" -I "..\..\..\libdepwin\freeglut\include" -I"..\..\..\include"
link /DEBUG ring_opengl45.obj  ..\..\..\lib\ring.lib ..\..\..\libdepwin\glew\lib\release\win32\glew32.lib ..\..\..\libdepwin\freeglut\lib\freeglut.lib /DLL /OUT:..\..\..\bin\ring_opengl45.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_opengl45.obj