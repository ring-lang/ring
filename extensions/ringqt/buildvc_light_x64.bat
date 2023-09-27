IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=5.15.15

setlocal enableextensions enabledelayedexpansion
call ..\..\language\src\locatevc.bat x64
"%RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\bin\qmake.exe" ring_qt515_light.pro -spec win32-msvc "CONFIG+=release"
"%RING_QT_DIR%\Tools\QtCreator\bin\jom\jom.exe"
copy release\ringqt_light.dll ..\..\bin
endlocal
