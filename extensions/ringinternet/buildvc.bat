cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_internet.c -I"..\..\libdepwin\libcurl\include" -I"..\..\include"
link /DEBUG ring_internet.obj  ..\..\lib\ring.lib ..\..\libdepwin\libcurl\lib\libcurl.lib /DLL /OUT:..\..\bin\ring_internet.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_internet.obj