cls
setlocal enableextensions enabledelayedexpansion
call ../../../language/build/locatevc.bat
cl /c /DEBUG mylib.c -I"..\..\..\language\include"
link /DEBUG mylib.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylib.dll /SUBSYSTEM:CONSOLE,"5.01" 
del mylib.obj
endlocal