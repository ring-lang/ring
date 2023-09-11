cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat auto x64

cl /c %ringcflags% ring_consolecolors.c -I"..\..\language\include"
link %ringldflags% ring_consolecolors.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_consolecolors.dll 
del ring_consolecolors.obj

endlocal
