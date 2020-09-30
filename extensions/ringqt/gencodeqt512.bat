set RINGQT_WEBASSEMBLY=
set RINGQT_ANDROID=
set RINGQT_NOWEBKIT=1
set RINGQT_NOBLUETOOTH=
set RINGQT_QT512=1
ring ..\codegen\parsec.ring classes\qt.cf cpp\src\ring_qt.cpp ..\..\libraries\guilib\classes\ring_qt.ring
cd events
ring qtevents.ring
cd ..
set RINGQT_QT512=
