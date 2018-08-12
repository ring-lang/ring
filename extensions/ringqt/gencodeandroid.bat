set RINGQT_ANDROID=1
set RINGQT_NOWEBKIT=
ring ..\codegen\parsec.ring generator\qt.cf cpp\src\ring_qt.cpp ring_qt.ring
cd events
ring qtevents.ring
cd ..
copy cpp\src\*.cpp ..\..\android\ringqt\project
copy cpp\include\*.h ..\..\android\ringqt\project
copy ring_qt.ring ..\..\android\ringqt\project