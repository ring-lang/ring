Rem Simple Batch File to copy Qt 5.12.6 DLL files to the bin folder
Rem 2020, Mahmoud Fayed <msfclipper@yahoo.com>

cd ..\..\..\bin

copy C:\Qt\Qt5.12.6\5.12.6\msvc2017\bin\*.dll .
copy C:\Qt\Qt5.12.6\5.12.6\msvc2017\bin\QtWebEngineProcess.exe .
xcopy C:\Qt\Qt5.12.6\5.12.6\msvc2017\plugins . /E /H /C /R /Q /Y
md qml
xcopy C:\Qt\Qt5.12.6\5.12.6\msvc2017\qml qml /E /H /C /R /Q /Y
md translations
xcopy C:\Qt\Qt5.12.6\5.12.6\msvc2017\translations translations /E /H /C /R /Q /Y
md resources
xcopy C:\Qt\Qt5.12.6\5.12.6\msvc2017\resources resources /E /H /C /R /Q /Y
