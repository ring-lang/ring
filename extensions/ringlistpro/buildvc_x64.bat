cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /c /DEBUG listpro.c -I"..\..\language\include"
link /DEBUG listpro.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_listpro.dll
del listpro.obj
endlocal