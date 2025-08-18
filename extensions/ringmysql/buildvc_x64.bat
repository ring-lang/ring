cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c %ringcflags% ring_vmmysql.c -I"..\..\language\include" -I"..\..\extensions\libdepwin\mysql_x64\include" 
link %ringldflags% ring_vmmysql.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\MySQL_x64\lib\libmysql.lib /DLL /OUT:..\..\bin\ring_mysql.dll
del ring_vmmysql.obj
endlocal
