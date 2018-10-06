Rem Simple Batch File to copy ring DLL files and libraries to the bin folder
Rem 2016, Mahmoud Fayed <msfclipper@yahoo.com>

cd ..

copy lib\*.dll bin
copy libdepwin\allegro5.2.4\bin\*.dll bin
copy libdepwin\freeglut\bin\*.dll bin
copy libdepwin\glew\bin\Release\Win32\*.dll bin
copy libdepwin\libcurl\bin\*.dll bin
copy libdepwin\mysql\lib\*.dll bin
copy libdepwin\openssl\bin\*.dll bin
copy libdepwin\libuv\*.dll bin

copy C:\Qt\Qt5.5.1\5.5\mingw492_32\bin\*.dll bin