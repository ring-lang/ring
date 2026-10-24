IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=6.12.0

SET RINGQT6_DIR=%~dp0

setlocal enableextensions enabledelayedexpansion
cd /d "%RINGQT6_DIR%"
call ..\..\language\build\locatevc.bat x64
cd /d "%RINGQT6_DIR%"
"%RING_QT_DIR%\%RING_QT_VERSION%\msvc2022_64\bin\qmake.exe" ring_qt6_nobluetooth.pro -spec win32-msvc "CONFIG+=release"
"%RING_QT_DIR%\Tools\QtCreator\bin\jom\jom.exe" /l /s
copy "%RINGQT6_DIR%release\ringqt.dll" "%RINGQT6_DIR%..\..\bin"
endlocal
