cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /nologo /W2 /O2 /c /DEBUG ring_threads.c -I"..\..\language\include"
link /DEBUG ring_threads.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_threads.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_threads.obj
endlocal
