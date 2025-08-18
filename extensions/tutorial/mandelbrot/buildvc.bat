cls
setlocal enableextensions enabledelayedexpansion
call ../../../language/build/locatevc.bat
cl /c %ringcflags% mylib.c -I"..\..\..\language\include"
link %ringldflags% mylib.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylib.dll /SUBSYSTEM:CONSOLE,"5.01" 
del mylib.obj
endlocal