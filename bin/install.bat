Rem Simple Batch File to copy ring DLL files and libraries to the bin folder
Rem 2016-2021, Mahmoud Fayed <msfclipper@yahoo.com>

cd ..

copy lib\*.dll bin
copy extensions\libdepwin\allegro5.2.7.1\bin\*.dll bin
copy extensions\libdepwin\freeglut\bin\*.dll bin
copy extensions\libdepwin\glew\bin\Release\Win32\*.dll bin
copy extensions\libdepwin\libcurl\bin\*.dll bin
copy extensions\libdepwin\libsdl\SDL2_vc\lib\x86\*.dll bin
copy extensions\libdepwin\libsdl\SDL2_image\lib\x86\*.dll bin
copy extensions\libdepwin\libsdl\SDL2_mixer\lib\x86\*.dll bin
copy extensions\libdepwin\libsdl\SDL2_net\lib\x86\*.dll bin
copy extensions\libdepwin\libsdl\SDL2_ttf\lib\x86\*.dll bin
copy extensions\libdepwin\libuv\*.dll bin
copy extensions\libdepwin\mysql\lib\*.dll bin
copy extensions\libdepwin\openssl\bin\*.dll bin
copy extensions\libdepwin\pgsql\lib\*.dll bin
copy extensions\libdepwin\raylib2.5\bin\*.dll bin
cd bin
rem Delete Allegro Dlls (Debug Version)
del allegro*debug-5.2.dll 