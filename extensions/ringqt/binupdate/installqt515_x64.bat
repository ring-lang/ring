Rem Simple Batch File to copy Qt 5.15.19 DLL files to the bin folder
Rem 2020-2025, Mahmoud Fayed <msfclipper@yahoo.com>

IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=5.15.19

cd ..\..\..\bin

copy %RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\bin\*.dll .
copy %RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\bin\QtWebEngineProcess.exe .
xcopy %RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\plugins . /E /H /C /R /Q /Y
if not exist qml md qml
xcopy %RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\qml qml /E /H /C /R /Q /Y
if not exist translations md translations
xcopy %RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\translations translations /E /H /C /R /Q /Y
if not exist resources md resources
xcopy %RING_QT_DIR%\%RING_QT_VERSION%\msvc2019_64\resources resources /E /H /C /R /Q /Y

cd ..\extensions\ringqt\binupdate
