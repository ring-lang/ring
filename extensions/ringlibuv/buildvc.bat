cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /W2 /O2 /c /DEBUG ring_libuv.c -I"..\..\extensions\libdepwin\libuv\include" -I"..\..\language\include"
link /DEBUG ring_libuv.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libuv\libuv.lib /DLL /OUT:..\..\bin\ring_uv.dll /SUBSYSTEM:WINDOWS,"5.01" /NODEFAULTLIB:msvcrt.lib
del ring_libuv.obj
endlocal
