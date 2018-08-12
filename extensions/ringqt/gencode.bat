set RINGQT_ANDROID=
set RINGQT_NOWEBKIT=
ring ..\codegen\parsec.ring classes\qt.cf cpp\src\ring_qt.cpp guilib\ring_qt.ring
cd events
ring qtevents.ring
cd ..

