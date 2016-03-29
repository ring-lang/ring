set PATH=C:\Qt\Qt5.3.0\5.3\mingw482_32\bin;C:\Qt\Qt5.3.0\Tools\mingw482_32\bin;%PATH%
qmake "ring_qt.pro"  
mingw32-make 
copy release\ringqt.dll ..\..\bin
