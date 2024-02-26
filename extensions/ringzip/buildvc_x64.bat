cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c /DEBUG ring_libzip.c -I"..\ringzip" -I"..\..\language\include"
link /DEBUG ring_libzip.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_libzip.dll 
del ring_libzip.obj
endlocal
