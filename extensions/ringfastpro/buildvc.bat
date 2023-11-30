cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat
cl /c /DEBUG listpro.c -I"..\..\language\include"
link /DEBUG listpro.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_listpro.dll /SUBSYSTEM:CONSOLE,"5.01" 
del listpro.obj
endlocal