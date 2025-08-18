cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c %ringcflags% ring_vmodbc.c -I"..\..\language\include"
link %ringldflags% ring_vmodbc.obj  ..\..\lib\ring.lib odbc32.lib /DLL /OUT:..\..\bin\ring_odbc.dll 
del ring_vmodbc.obj
endlocal
