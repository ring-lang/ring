cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto x64
cl /c %ringcflags% ring_tilengine.c -I "..\..\extensions\libdepwin\tilengine_x64\include" -I"..\..\language\include"
link %ringldflags% ring_tilengine.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\tilengine_x64\lib\tilengine.lib /DLL /OUT:..\..\bin\ring_tilengine.dll 
del ring_tilengine.obj
endlocal

