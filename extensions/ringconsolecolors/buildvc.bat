cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_consolecolors.c -I"..\..\include"
link /DEBUG ring_consolecolors.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_consolecolors.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_consolecolors.obj