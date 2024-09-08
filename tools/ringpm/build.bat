setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
ring2exe ringpm.ring
move ringpm.exe ..\..\bin\ringpm.exe
endlocal
