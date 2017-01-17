rem	Simple Batch file to update Ring in the Android-LibSDL Version 
rem	Author : Mahmoud Fayed <msfclipper@yahoo.com>

copy ..\..\..\src\*.c ..\project\jni\ring\src\
copy ring_ext.c ..\project\jni\ring\src\
copy ..\..\..\include\*.h ..\project\jni\ring\include\
copy ring_ext.h ..\project\jni\ring\include\