cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ring_vmmysql.c -I"..\..\language\include" -I"..\..\extensions\libdepwin\mysql\include" 
link /DEBUG ring_vmmysql.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\MySQL\lib\libmysql.lib /DLL /OUT:..\..\bin\ring_mysql.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_vmmysql.obj
endlocal
