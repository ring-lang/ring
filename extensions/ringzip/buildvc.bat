cls
call ../../language/src/locatevc.bat
cl /c /DEBUG ring_libzip.c -I"..\ringzip" -I"..\..\language\include"
link /DEBUG ring_libzip.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_libzip.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_libzip.obj