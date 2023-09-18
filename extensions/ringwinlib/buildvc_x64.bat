cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /c /DEBUG ringwinlib.c -I"..\..\language\include"
link /DEBUG ringwinlib.obj  ..\..\lib\ring.lib kernel32.lib user32.lib /DLL /OUT:..\..\bin\ring_winlib.dll 
del ringwinlib.obj
endlocal
