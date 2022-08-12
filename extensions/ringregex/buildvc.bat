cls
call ../../language/src/locatevc.bat
cl /c /DEBUG ring_regex.c -I"..\..\language\include" -I"..\libdepwin\regex\include" 
link /DEBUG ring_regex.obj  ..\..\lib\ring.lib ..\libdepwin\regex\lib\regex.lib /DLL /OUT:..\..\bin\ring_regex.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_regex.obj
