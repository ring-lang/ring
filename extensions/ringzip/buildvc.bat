cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c %ringcflags% ring_libzip.c -I"..\ringzip" -I"..\..\language\include"
link %ringldflags% ring_libzip.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_libzip.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_libzip.obj
endlocal
