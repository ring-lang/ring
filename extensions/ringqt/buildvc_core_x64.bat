setlocal enableextensions enabledelayedexpansion
call ..\..\language\src\locatevc.bat x64
"C:\Qt\5.15.15\msvc2019_64\bin\qmake.exe" ring_qt515_core.pro -spec win32-msvc "CONFIG+=qtquickcompiler"
"C:\Qt\Tools\QtCreator\bin\jom\jom.exe"
copy release\ringqt_core.dll ..\..\bin
endlocal

