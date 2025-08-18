cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c %ringcflags% ringwinlib.c -I"..\..\language\include"
link %ringldflags% ringwinlib.obj  ..\..\lib\ring.lib kernel32.lib user32.lib /DLL /OUT:..\..\bin\ring_winlib.dll 
del ringwinlib.obj
endlocal
