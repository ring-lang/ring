cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat auto x64
cl /nologo /W2 /O2 /c /DEBUG ring_threads.c -I"..\..\language\include"
link /DEBUG ring_threads.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_threads.dll 
del ring_threads.obj
endlocal
