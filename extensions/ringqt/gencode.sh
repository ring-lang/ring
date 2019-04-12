export RINGQT_ANDROID=
export RINGQT_NOWEBKIT=1
export RINGQT_QT512=1
../../bin/ring ../codegen/parsec.ring classes/qt.cf cpp/src/ring_qt.cpp guilib/ring_qt.ring
cd events
../../../bin/ring qtevents.ring
cd ..

