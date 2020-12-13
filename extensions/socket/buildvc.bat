cls
call ../../../ring/language/src/locatevc.bat
cl /c /DEBUG ext\socket.c -I"..\..\..\ring\language\include"
link /DEBUG socket.obj  ..\ring\lib\ring.lib /DLL /OUT:socket.dll /SUBSYSTEM:CONSOLE,"5.01"
del socket.obj
