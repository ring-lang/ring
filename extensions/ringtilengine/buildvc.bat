cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c %ringcflags% ring_tilengine.c -I "..\..\extensions\libdepwin\tilengine\include" -I"..\..\language\include"
link %ringldflags% ring_tilengine.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\tilengine\lib\tilengine.lib /DLL /OUT:..\..\bin\ring_tilengine.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_tilengine.obj
endlocal

