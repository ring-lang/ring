setlocal enableextensions enabledelayedexpansion
call ..\..\language\build\locatevc.bat auto %1
ring2exe ringrepl.ring -static
copy ringrepl.exe ..\..\bin\ringrepl.exe
endlocal
