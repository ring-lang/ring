/usr/local/Cellar/qt5/5.5.1/bin/qmake ring_qt.pro -r -spec macx-clang
make
cp *.dylib ../../lib
