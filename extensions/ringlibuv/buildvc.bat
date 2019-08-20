cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_libuv.c -I"..\..\libdepwin\libuv\include" -I"..\..\include"
link /DEBUG ring_libuv.obj  ..\..\lib\ring.lib ..\..\libdepwin\libuv\libuv.lib /DLL /OUT:..\..\bin\ring_uv.dll /SUBSYSTEM:WINDOWS,"5.01" /NODEFAULTLIB:msvcrt.lib
del ring_libuv.obj