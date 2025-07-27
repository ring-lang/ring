cls
setlocal enableextensions enabledelayedexpansion
call ../../../language/build/locatevc.bat auto %1
cl /EHsc test.cpp
endlocal
