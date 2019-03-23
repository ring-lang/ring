call ..\..\src\locatevc.bat
"C:\Qt\Qt5.12.2\5.12.2\msvc2017\bin\qmake.exe" B:\ring\extensions\ringqt\ring_qt512.pro -spec win32-msvc "CONFIG+=qtquickcompiler"
"C:\Qt\Qt5.12.2\Tools\QtCreator\bin\jom.exe" -f B:/ring/extensions/build-ring_qt512-Desktop_Qt_5_12_2_MSVC2017_32bit-Release/Makefile qmake_all
"C:\Qt\Qt5.12.2\Tools\QtCreator\bin\jom.exe"
copy release\ringqt.dll ..\..\bin