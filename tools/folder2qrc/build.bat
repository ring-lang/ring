setlocal enableextensions enabledelayedexpansion
call ..\..\language\src\locatevc.bat auto %1
ring2exe folder2qrc.ring -static
copy folder2qrc.exe ..\..\bin\folder2qrc.exe
endlocal
