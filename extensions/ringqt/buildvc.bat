setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat auto %1
"C:\Qt\Qt5.5.0\5.5\msvc2013\bin\qmake.exe" B:\ring\extensions\ringqt\ring_qt.pro -r -spec win32-msvc2013
"C:\Qt\Qt5.5.0\Tools\QtCreator\bin\jom.exe" 
endlocal
