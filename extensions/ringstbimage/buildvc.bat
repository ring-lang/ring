cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c %ringcflags% ring_stbimage.c -I"..\..\language\include"
link %ringldflags% ring_stbimage.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_stbimage.dll  /SUBSYSTEM:CONSOLE,"5.01" 
del ring_stbimage.obj
endlocal
