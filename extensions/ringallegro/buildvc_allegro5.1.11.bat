cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_allegro.c -I"..\..\libdepwin\allegro5.1.11\include" -I"..\..\include"
link /DEBUG ring_allegro.obj  ..\..\lib\ring.lib ..\..\libdepwin\allegro5.1.11\lib\allegro_monolith.lib /DLL /OUT:..\..\bin\ring_allegro.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_allegro.obj