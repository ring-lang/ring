cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto x64
cl /nologo /W2 /c ring_threads.c -I"..\..\language\include"
link ring_threads.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_threads.dll 
del ring_threads.obj
endlocal
