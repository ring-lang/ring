cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /c /DEBUG ring_pgsql.c -I"..\..\extensions\libdepwin\pgsql_x64\include" -I"..\..\language\include"
link /DEBUG ring_pgsql.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\pgsql_x64\lib\libpq.lib /DLL /OUT:..\..\bin\ring_pgsql.dll  
del ring_pgsql.obj
endlocal
