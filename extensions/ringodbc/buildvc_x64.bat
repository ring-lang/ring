cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /c /DEBUG ring_vmodbc.c -I"..\..\language\include"
link /DEBUG ring_vmodbc.obj  ..\..\lib\ring.lib odbc32.lib /DLL /OUT:..\..\bin\ring_odbc.dll 
del ring_vmodbc.obj
endlocal
