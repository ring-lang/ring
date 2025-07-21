cls
setlocal enableextensions enabledelayedexpansion
call ../../../language/build/locatevc.bat auto x64 %1
cl /EHsc test.cpp
endlocal
