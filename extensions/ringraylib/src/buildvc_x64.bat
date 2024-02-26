cls
setlocal enableextensions enabledelayedexpansion
call ../../../language/build/locatevc.bat auto %1
cl /c %ringcflags% ring_raylib.c -I"..\..\..\extensions\libdepwin\raylib2.5_x64\include" -I"..\..\..\language\include"
link %ringldflags% ring_raylib.obj  ..\..\..\lib\ring.lib ..\..\..\extensions\libdepwin\raylib2.5_x64\lib\raylib.lib  /DLL /OUT:..\..\..\bin\ring_raylib.dll 
del ring_raylib.obj
endlocal
