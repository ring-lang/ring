cls
setlocal enableextensions enabledelayedexpansion
call ../../../language/build/locatevc.bat x64
cl /c %ringcflags% mylib.c -I"..\..\..\language\include"
link %ringldflags% mylib.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylib.dll
del mylib.obj
endlocal