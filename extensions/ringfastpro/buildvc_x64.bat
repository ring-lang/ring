cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c %ringcflags% fastpro.c -I"..\..\language\include"
link %ringldflags% fastpro.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_fastpro.dll
del fastpro.obj
endlocal