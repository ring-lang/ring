setlocal enableextensions enabledelayedexpansion

set RINGSCRIPTPATH=%~dp0
set RINGEXEPATH="%RINGSCRIPTPATH%..\..\bin\ring.exe"

%RINGEXEPATH% %RINGSCRIPTPATH%ring2exe.ring %RINGSCRIPTPATH%ring2exe.ring -static
copy %RINGSCRIPTPATH%ring2exe.exe %RINGSCRIPTPATH%..\..\bin\ring2exe.exe
cleartemp

endlocal