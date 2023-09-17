Rem Simple Batch File to copy Qt 5.15.15 DLL files to the bin folder
Rem 2020-2023, Mahmoud Fayed <msfclipper@yahoo.com>

cd ..\..\..\bin

copy C:\Qt\5.15.15\msvc2019\bin\*.dll .
copy C:\Qt\5.15.15\msvc2019\bin\QtWebEngineProcess.exe .
xcopy C:\Qt\5.15.15\msvc2019\plugins . /E /H /C /R /Q /Y
md qml
xcopy C:\Qt\5.15.15\msvc2019\qml qml /E /H /C /R /Q /Y
md translations
xcopy C:\Qt\5.15.15\msvc2019\translations translations /E /H /C /R /Q /Y
md resources
xcopy C:\Qt\5.15.15\msvc2019\resources resources /E /H /C /R /Q /Y

cd ..\extensions\ringqt\binupdate