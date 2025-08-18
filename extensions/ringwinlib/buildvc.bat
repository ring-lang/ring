cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c %ringcflags% ringwinlib.c -I"..\..\language\include"
link %ringldflags% ringwinlib.obj  ..\..\lib\ring.lib kernel32.lib user32.lib /DLL /OUT:..\..\bin\ring_winlib.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ringwinlib.obj
endlocal
