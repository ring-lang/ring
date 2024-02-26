cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ring_internet.c -I"..\..\extensions\libdepwin\libcurl\include" -I"..\..\language\include"
link /DEBUG ring_internet.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libcurl\lib\libcurl.lib /DLL /OUT:..\..\bin\ring_internet.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_internet.obj
endlocal
