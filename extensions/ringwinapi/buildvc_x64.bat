echo off
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64

cl /c /DEBUG ring_winapi.c -I"..\..\language\include"

link /DEBUG ring_winapi.obj advapi32.lib Kernel32.lib shell32.lib ..\..\lib\ring.lib  /DLL /OUT:ring_winapi.dll 

copy ring_winapi.dll ..\..\bin\ring_winapi.dll

del ring_winapi.obj
del ring_winapi.ilk
del ring_winapi.exp
del ring_winapi.pdb
del ring_winapi.lib
del ring_winapi.dll

endlocal

