cls
call ../../language/src/locatevc.bat
cl /c /DEBUG ringbeep.c -I"..\..\include"
link /DEBUG ringbeep.obj  ..\..\lib\ring.lib kernel32.lib /DLL /OUT:ringbeep.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ringbeep.obj