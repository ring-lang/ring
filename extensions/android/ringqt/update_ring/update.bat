rem	Simple Batch file to update Ring and RingQt in the Android-Qt Version 
rem	Author : Mahmoud Fayed <msfclipper@yahoo.com>

copy ..\..\..\..\language\src\*.c ..\project\ring\src\
copy ring_ext.c ..\project\ring\src\
copy ..\..\..\..\language\include\*.h ..\project\ring\include\
copy ring_ext.h ..\project\ring\include\
cd ..\..\..\ringqt\
call gencodeandroid.bat
copy cpp\src\*.cpp ..\android\ringqt\project\ringqt\src\
copy cpp\include\*.h ..\android\ringqt\project\ringqt\include\
call gencodeqt515_nobluetooth.bat
cd ..\android\ringqt\update_ring