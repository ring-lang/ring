cls
setlocal enableextensions enabledelayedexpansion
call ../../../language/src/locatevc.bat auto %1
cl /EHsc test.cpp
endlocal
