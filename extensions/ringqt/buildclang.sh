BREW_PREFIX=$(brew --prefix)

$BREW_PREFIX/bin/qmake ring_qt515.pro -r -spec macx-clang
make
cp *.dylib ../../lib
