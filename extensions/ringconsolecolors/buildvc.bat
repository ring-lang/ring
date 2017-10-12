cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_consolecolors.c -I"..\..\include"
link /DEBUG ring_consolecolors.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_consolecolors.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_consolecolors.obj