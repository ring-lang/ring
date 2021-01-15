cls
call ../../language/src/locatevc.bat
cl /W2 /O2 /c /DEBUG ring_tilengine.c -I "..\..\extensions\libdepwin\tilengine\include" -I"..\..\language\include"
link /DEBUG ring_tilengine.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\tilengine\lib\tilengine.lib /DLL /OUT:..\..\bin\ring_tilengine.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_tilengine.obj
