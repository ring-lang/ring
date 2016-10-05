/usr/local/Cellar/qt55/5.5.1/bin/qmake ring_qt.pro -r -spec macx-clang
make
cp *.dylib ../../lib
