cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat auto x64
cl /c /DEBUG ring_stbimage.c -I"..\..\language\include"
link /DEBUG ring_stbimage.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_stbimage.dll 
del ring_stbimage.obj
endlocal
