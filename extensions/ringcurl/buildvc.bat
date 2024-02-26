cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ring_libcurl.c -I"..\..\extensions\libdepwin\libcurl\include" -I"..\..\language\include"
link /DEBUG ring_libcurl.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libcurl\lib\libcurl.lib /DLL /OUT:..\..\bin\ring_libcurl.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_libcurl.obj
endlocal
