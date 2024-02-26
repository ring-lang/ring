cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ringbeep.c -I"..\..\language\include"
link /DEBUG ringbeep.obj  ..\..\lib\ring.lib kernel32.lib /DLL /OUT:ringbeep.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ringbeep.obj
endlocal