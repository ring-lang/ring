rem	Simple Batch file to update Ring and RingQt in the WebAssembly-Qt Version 
rem	Author : Mahmoud Fayed <msfclipper@yahoo.com>

copy ..\..\..\..\src\*.c ..\project\
copy ring_ext.c ..\project\
copy ..\..\..\..\include\*.h ..\project\
copy ring_ext.h ..\project\
cd ..\..\..\ringqt\
call gencodewebassembly.bat
copy cpp\src\*.cpp ..\webassembly\ringqt\project\
copy cpp\include\*.h ..\webassembly\ringqt\project\
call gencodeqt512_nobluetooth.bat
cd ..\webassembly\ringqt\update_ring