setlocal enableextensions enabledelayedexpansion
call ..\..\language\src\locatevc.bat auto %1
"C:\Qt\Qt5.12.6\5.12.6\msvc2017\bin\qmake.exe" ring_qt512_light.pro -spec win32-msvc "CONFIG+=release"
rem "C:\Qt\Qt5.12.6\Tools\QtCreator\bin\jom.exe" -f ../build-ring_qt512-Desktop_Qt_5_12_6_MSVC2017_32bit-Release/Makefile qmake_all
"C:\Qt\Qt5.12.6\Tools\QtCreator\bin\jom.exe"
copy release\ringqt_light.dll ..\..\bin
endlocal
