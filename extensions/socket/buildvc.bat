cls
call ../../../src/locatevc.bat
cl /c /DEBUG ext\socket.c -I"..\..\..\include"
link /DEBUG socket.obj  ..\..\..\lib\ring.lib /DLL /OUT:socket.dll /SUBSYSTEM:CONSOLE,"5.01"
del socket.obj
