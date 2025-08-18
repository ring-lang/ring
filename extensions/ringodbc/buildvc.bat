cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c %ringcflags% ring_vmodbc.c -I"..\..\language\include"
link %ringldflags% ring_vmodbc.obj  ..\..\lib\ring.lib odbc32.lib /DLL /OUT:..\..\bin\ring_odbc.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_vmodbc.obj
endlocal
