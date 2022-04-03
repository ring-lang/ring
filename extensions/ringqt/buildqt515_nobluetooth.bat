setlocal enableextensions enabledelayedexpansion
call ..\..\language\src\locatevc.bat auto %1
"C:\Qt\5.15.0\msvc2019\bin\qmake.exe" ring_qt512_nobluetooth.pro -spec win32-msvc "CONFIG+=qtquickcompiler"
"C:\Qt\Tools\QtCreator\bin\jom\jom.exe"
copy release\ringqt.dll ..\..\bin
endlocal
