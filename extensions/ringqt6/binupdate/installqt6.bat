@echo off
Rem Simple Batch File to copy Qt 6.12.0 runtime files to the bin folder
Rem 2026, Mahmoud Fayed <msfclipper@yahoo.com>

setlocal enableextensions

IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=6.12.0

SET QT6_DIR=%RING_QT_DIR%\%RING_QT_VERSION%\msvc2022_64
IF NOT EXIST "%QT6_DIR%\bin\Qt6Core.dll" goto :noqt

Rem The script can be executed from any folder
SET RING_BIN=%~dp0..\..\..\bin
IF NOT "%~1"=="" SET RING_BIN=%~f1
IF NOT EXIST "%RING_BIN%" md "%RING_BIN%"
for %%I in ("%RING_BIN%") do SET RING_BIN=%%~fI

echo Copy Qt %RING_QT_VERSION% runtime files to %RING_BIN%

Rem Qt DLL files (Qt6*.dll and the dependencies: FFmpeg for Qt Multimedia, Direct3D/OpenGL software rendering, etc.)
copy /Y "%QT6_DIR%\bin\*.dll" "%RING_BIN%\"

Rem Qt WebEngine (the process + the resources, the translations are copied below)
copy /Y "%QT6_DIR%\bin\QtWebEngineProcess.exe" "%RING_BIN%\"
xcopy "%QT6_DIR%\resources" "%RING_BIN%\resources\" /E /H /C /R /Q /Y /I

Rem Qt plugins (platforms, styles, imageformats, multimedia, texttospeech, tls, sqldrivers, etc.)
xcopy "%QT6_DIR%\plugins" "%RING_BIN%\" /E /H /C /R /Q /Y /I

Rem QML modules (Qt Quick, Qt Multimedia, Qt WebEngine, etc.) and translations (Qt + qtwebengine_locales)
xcopy "%QT6_DIR%\qml" "%RING_BIN%\qml\" /E /H /C /R /Q /Y /I
xcopy "%QT6_DIR%\translations" "%RING_BIN%\translations\" /E /H /C /R /Q /Y /I

Rem Microsoft Visual C++ runtime
Rem Qt 6.12 (WebEngine, FFmpeg multimedia, text to speech) requires a recent runtime

SET RING_SYSTEM32=%SystemRoot%\System32
IF EXIST "%SystemRoot%\Sysnative\cmd.exe" SET RING_SYSTEM32=%SystemRoot%\Sysnative
for %%F in (msvcp140.dll msvcp140_1.dll msvcp140_2.dll msvcp140_atomic_wait.dll msvcp140_codecvt_ids.dll vcruntime140.dll vcruntime140_1.dll vcruntime140_threads.dll concrt140.dll vcomp140.dll) do IF EXIST "%RING_SYSTEM32%\%%F" copy /Y "%RING_SYSTEM32%\%%F" "%RING_BIN%\" >nul

echo Done
endlocal
exit /b 0

:noqt
echo Error: Qt %RING_QT_VERSION% (msvc2022_64) is not found in %RING_QT_DIR%
echo Set RING_QT_DIR and RING_QT_VERSION to use another Qt installation
endlocal
exit /b 1
