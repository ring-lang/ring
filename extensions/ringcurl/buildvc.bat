cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_libcurl.c -I"..\..\libdepwin\libcurl\include" -I"..\..\include"
link /DEBUG ring_libcurl.obj  ..\..\lib\ring.lib ..\..\libdepwin\libcurl\lib\libcurl.lib /DLL /OUT:..\..\bin\ring_libcurl.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_libcurl.obj