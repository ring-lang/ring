rem	Simple Batch file to update Ring only WebAssembly-Qt Version 
rem	Author : Mahmoud Fayed <msfclipper@yahoo.com>

copy ..\..\..\..\language\src\*.c ..\project\ring\src\
copy ring_ext.c ..\project\ring\src\
copy ..\..\..\..\language\include\*.h ..\project\ring\include\
copy ring_ext.h ..\project\ring\include\
