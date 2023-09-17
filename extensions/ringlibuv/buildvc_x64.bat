cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /W2 /O2 /c /DEBUG ring_libuv.c -I"..\..\extensions\libdepwin\libuv_x64\include" -I"..\..\language\include"
link /DEBUG ring_libuv.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libuv_x64\lib\uv_a.lib ws2_32.lib user32.lib advapi32.lib ws2_32.lib Iphlpapi.lib userenv.lib /DLL /OUT:..\..\bin\ring_uv.dll  /NODEFAULTLIB:msvcrt.lib
del ring_libuv.obj
endlocal
