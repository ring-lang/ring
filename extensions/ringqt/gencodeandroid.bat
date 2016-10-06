set RINGQT_ANDROID=1
ring ..\codegen\parsec.ring qt.cf ring_qt.cpp ring_qt.ring
ring qtevents.ring
copy *.cpp ..\..\android\ringqt\project
copy *.h ..\..\android\ringqt\project
copy qt.cf ..\..\android\ringqt\project
copy ring_qt.ring ..\..\android\ringqt\project