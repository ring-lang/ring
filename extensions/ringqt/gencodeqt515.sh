export RINGQT_ANDROID=
export RINGQT_NOWEBKIT=1
export RINGQT_NOBLUETOOTH=
export RINGQT_QT512=1
export RINGQT_NOQT3D=1
../../bin/ring ../codegen/parsec.ring classes/qt.cf cpp/src/ring_qt.cpp ../../libraries/guilib/classes/ring_qt.ring
cd events
../../../bin/ring qtevents.ring
cd ..
export RINGQT_QT512=
