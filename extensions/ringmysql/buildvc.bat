cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_vmmysql.c -I"..\..\include" -I"..\..\libdepwin\mysql\include" 
link /DEBUG ring_vmmysql.obj  ..\..\lib\ring.lib ..\..\libdepwin\MySQL\lib\libmysql.lib /DLL /OUT:..\..\bin\ring_mysql.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_vmmysql.obj