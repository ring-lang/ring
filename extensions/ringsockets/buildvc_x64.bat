cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c %ringcflags% ext\*.c -I"..\..\language\include" -I"ext\"
link %ringldflags% *.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_sockets.dll 
del *.obj
endlocal