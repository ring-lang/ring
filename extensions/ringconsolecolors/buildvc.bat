cls
setlocal enableextensions enabledelayedexpansion
rem buildvc.bat [debug]
rem we pass the parameter as second parameter to locatevc.bat
call ../../language/build/locatevc.bat auto %1

cl /c %ringcflags% ring_consolecolors.c -I"..\..\language\include"
link %ringldflags% ring_consolecolors.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_consolecolors.dll /SUBSYSTEM:CONSOLE,"%ringsubsystem%" 
del ring_consolecolors.obj

endlocal
