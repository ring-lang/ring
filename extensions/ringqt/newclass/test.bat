set RINGQT_ANDROID=
ring ..\codegen\parsec.ring qt.cf ring_qt.cpp ring_qt.ring
ring qtevents.ring
set PATH=C:\Qt\Qt5.5.1\5.5\mingw492_32\bin;C:\Qt\Qt5.5.1\Tools\mingw492_32\bin;%PATH%
qmake "ring_qt.pro"  
mingw32-make