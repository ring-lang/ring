set RINGQT_WEBASSEMBLY=
set RINGQT_ANDROID=1
set RINGQT_NOWEBKIT=
set RINGQT_NOBLUETOOTH=1
set RINGQT_QT512=1
ring ..\codegen\parsec.ring classes\qt.cf cpp\src\ring_qt.cpp guilib\ring_qt.ring
cd events
ring qtevents.ring
cd ..
copy cpp\src\*.cpp ..\..\android\ringqt\project
copy cpp\include\*.h ..\..\android\ringqt\project
copy ring_qt.ring ..\..\android\ringqt\project