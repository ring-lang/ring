setlocal enableextensions enabledelayedexpansion
call ..\..\language\src\locatevc.bat auto %1
"C:\Qt\5.15.0\msvc2019\bin\qmake.exe" ring_qt515_light.pro -spec win32-msvc "CONFIG+=release"
"C:\Qt\Tools\QtCreator\bin\jom\jom.exe"
copy release\ringqt_light.dll ..\..\bin
endlocal
