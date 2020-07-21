cls
call ../../language/src/locatevc.bat
cl /c /DEBUG ring_internet.c -I"..\..\extensions\libdepwin\libcurl\include" -I"..\..\include"
link /DEBUG ring_internet.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libcurl\lib\libcurl.lib /DLL /OUT:..\..\bin\ring_internet.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_internet.obj