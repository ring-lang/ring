call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
"C:\Qt\Qt5.6.0\5.6\msvc2013\bin\qmake.exe" B:\ring\extensions\ringqt\ring_qt.pro -r -spec win32-msvc2013
"C:\Qt\Qt5.6.0\Tools\QtCreator\bin\jom.exe" 