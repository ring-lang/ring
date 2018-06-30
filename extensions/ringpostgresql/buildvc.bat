cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_pgsql.c -I"..\..\libdepwin\pgsql\include" -I"..\..\include"
link /DEBUG ring_pgsql.obj  ..\..\lib\ring.lib ..\..\libdepwin\pgsql\lib\libpq.lib /DLL /OUT:..\..\bin\ring_pgsql.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_pgsql.obj