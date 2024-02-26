cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ring_libui.c -I "..\..\extensions\libdepwin\libuishared" -I"..\..\language\include"
link /DEBUG ring_libui.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libuishared\libui.lib /DLL /OUT:..\..\bin\ring_libui.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_libui.obj
endlocal
