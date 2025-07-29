setlocal enableextensions enabledelayedexpansion
call ../../../language/build/locatevc.bat auto %1
ring2exe test.ring
endlocal