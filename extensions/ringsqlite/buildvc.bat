cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_vmsqlite.c sqlite3.c -I"..\..\include"  
link /DEBUG ring_vmsqlite.obj sqlite3.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_sqlite.dll /SUBSYSTEM:CONSOLE,"5.01" 
del *.obj
