rem	Simple Batch file to update Ring and RingQt in the Android-Qt Version 
rem	Author : Mahmoud Fayed <msfclipper@yahoo.com>

copy ..\..\..\src\*.c ..\project\
copy ring_ext.c ..\project\
copy ..\..\..\include\*.h ..\project\
copy ring_ext.h ..\project\
cd ..\..\..\extensions\ringqt\
call gencodeandroid.bat
copy *.cpp ..\..\android\ringqt\project\
copy *.h ..\..\android\ringqt\project\
call gencode.bat
cd ..\..\android\ringqt\update_ring