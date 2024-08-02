rem	Simple Batch file to update Ring - Raspberry Pi Pico Version 
rem	Author : Mahmoud Fayed <msfclipper@yahoo.com>

copy ..\..\..\..\..\language\src\*.c ..\src\
copy ..\..\..\..\..\language\include\*.h ..\include\
copy ext.c ..\src\
copy ext.h ..\include
copy rconfig.h ..\include