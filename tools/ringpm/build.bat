setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat auto %1
ring2exe ringpm.ring -static
move ringpm.exe ..\..\bin\ringpm.exe
endlocal
