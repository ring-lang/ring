call ..\..\src\locatevc.bat
"C:\Qt\Qt5.12.3\5.12.3\msvc2017\bin\qmake.exe" ring_qt512.pro -spec win32-msvc "CONFIG+=qtquickcompiler"
rem "C:\Qt\Qt5.12.3\Tools\QtCreator\bin\jom.exe" -f ../build-ring_qt512-Desktop_Qt_5_12_3_MSVC2017_32bit-Release/Makefile qmake_all
"C:\Qt\Qt5.12.3\Tools\QtCreator\bin\jom.exe"
copy release\ringqt.dll ..\..\bin