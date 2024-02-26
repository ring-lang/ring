cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ext\*.c -I"..\..\language\include" -I"ext\"
link /DEBUG *.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_sockets.dll /SUBSYSTEM:CONSOLE,"5.01"
del *.obj
endlocal