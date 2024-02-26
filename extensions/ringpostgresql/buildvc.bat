cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ring_pgsql.c -I"..\..\extensions\libdepwin\pgsql\include" -I"..\..\language\include"
link /DEBUG ring_pgsql.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\pgsql\lib\libpq.lib /DLL /OUT:..\..\bin\ring_pgsql.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_pgsql.obj
endlocal
