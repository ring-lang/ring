cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c %ringcflags% ringbeep.c -I"..\..\language\include"
link %ringldflags% ringbeep.obj  ..\..\lib\ring.lib kernel32.lib /DLL /OUT:ringbeep.dll 
del ringbeep.obj
endlocal