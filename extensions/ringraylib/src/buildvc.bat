cls
setlocal enableextensions enabledelayedexpansion
call ../../../language/src/locatevc.bat auto %1
cl /W2 /O2 /c /DEBUG ring_raylib.c -I"..\..\..\extensions\libdepwin\raylib2.5\include" -I"..\..\..\language\include"
link /DEBUG ring_raylib.obj  ..\..\..\lib\ring.lib ..\..\..\extensions\libdepwin\raylib2.5\lib\raylib.lib  /DLL /OUT:..\..\..\bin\ring_raylib.dll 
del ring_raylib.obj
endlocal
