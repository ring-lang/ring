set RINGQT_WEBASSEMBLY=
set RINGQT_ANDROID=
set RINGQT_NOWEBKIT=
set RINGQT_NOBLUETOOTH=
ring ..\codegen\parsec.ring classes\qt.cf cpp\src\ring_qt.cpp ..\..\libraries\guilib\classes\ring_qt.ring
cd events
ring qtevents.ring
cd ..

