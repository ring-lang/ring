cls
call ../../language/src/locatevc.bat
cl /c /DEBUG ring_vmodbc.c -I"..\..\include"
link /DEBUG ring_vmodbc.obj  ..\..\lib\ring.lib odbc32.lib /DLL /OUT:..\..\bin\ring_odbc.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_vmodbc.obj