Rem Simple Batch File to copy Qt 5.15.15 DLL files to the bin folder
Rem 2020-2023, Mahmoud Fayed <msfclipper@yahoo.com>

cd ..\..\..\bin

copy C:\Qt\5.15.15\msvc2019_64\bin\*.dll .
copy C:\Qt\5.15.15\msvc2019_64\bin\QtWebEngineProcess.exe .
xcopy C:\Qt\5.15.15\msvc2019_64\plugins . /E /H /C /R /Q /Y
md qml
xcopy C:\Qt\5.15.15\msvc2019_64\qml qml /E /H /C /R /Q /Y
md translations
xcopy C:\Qt\5.15.15\msvc2019_64\translations translations /E /H /C /R /Q /Y
md resources
xcopy C:\Qt\5.15.15\msvc2019_64\resources resources /E /H /C /R /Q /Y

cd ..\extensions\ringqt\binupdate
