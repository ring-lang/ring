cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c /DEBUG fastpro.c -I"..\..\language\include"
link /DEBUG fastpro.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_fastpro.dll
del fastpro.obj
endlocal