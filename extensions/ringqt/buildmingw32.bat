set PATH=C:\Qt\Qt5.5.1\5.5\mingw492_32\bin;C:\Qt\Qt5.5.1\Tools\mingw492_32\bin;%PATH%
qmake "ring_qt.pro"  
mingw32-make 
copy release\ringqt.dll ..\..\bin