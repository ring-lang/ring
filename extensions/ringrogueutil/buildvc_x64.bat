cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c /DEBUG ring_rogueutil.c -I"..\..\language\include"
link /DEBUG ring_rogueutil.obj  ..\..\lib\ring.lib kernel32.lib Advapi32.lib  /DLL /OUT:ring_rogueutil.dll 
del ring_rogueutil.obj
endlocal