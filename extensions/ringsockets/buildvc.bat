cls
call ../../language/src/locatevc.bat
cl /c /DEBUG ext\sockets.c -I"..\..\language\include"
link /DEBUG sockets.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_sockets.dll /SUBSYSTEM:CONSOLE,"5.01"
del sockets.obj
