cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_raylib.c -I"..\..\libdepwin\raylib2.5\include" -I"..\..\include"
link /DEBUG ring_raylib.obj  ..\..\lib\ring.lib ..\..\libdepwin\raylib2.5\lib\raylib_static.lib winmm.lib gdi32.lib /DLL /OUT:..\..\bin\ring_raylib.dll 
del ring_raylib.obj