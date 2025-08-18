echo off
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64

cl /c %ringcflags% ring_winapi.c -I"..\..\language\include"

link %ringldflags% ring_winapi.obj advapi32.lib Kernel32.lib shell32.lib ..\..\lib\ring.lib  /DLL /OUT:ring_winapi.dll 

copy ring_winapi.dll ..\..\bin\ring_winapi.dll

endlocal

