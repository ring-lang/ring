cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c %ringcflags% ring_libzip.c -I"..\ringzip" -I"..\..\language\include"
link %ringldflags% ring_libzip.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_libzip.dll 
del ring_libzip.obj
endlocal
