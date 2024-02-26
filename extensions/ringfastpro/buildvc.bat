cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat
cl /c /DEBUG fastpro.c -I"..\..\language\include"
link /DEBUG fastpro.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_fastpro.dll /SUBSYSTEM:CONSOLE,"5.01" 
del fastpro.obj
endlocal