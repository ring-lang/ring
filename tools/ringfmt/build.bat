setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
ring2exe ringfmt.ring
move ringfmt.exe ..\..\bin\ringfmt.exe
endlocal
