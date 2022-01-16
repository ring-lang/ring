rem	Simple Batch file to update Ring and RingQt in the WebAssembly-Qt Version 
rem	Author : Mahmoud Fayed <msfclipper@yahoo.com>

copy ..\..\..\..\language\src\*.c ..\project\ring\src\
copy ring_ext.c ..\project\ring\src\
copy ..\..\..\..\language\include\*.h ..\project\ring\include\
copy ring_ext.h ..\project\ring\include\
cd ..\..\..\ringqt\
call gencodewebassembly.bat
copy cpp\src\*.cpp ..\webassembly\ringqt\project\ringqt\src\
copy cpp\include\*.h ..\webassembly\ringqt\project\ringqt\include\
call gencodeqt515_nobluetooth.bat
cd ..\webassembly\ringqt\update_ring