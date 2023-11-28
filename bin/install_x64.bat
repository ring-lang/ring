Rem Simple Batch File to copy ring DLL files (and libraries to the bin folder
Rem Ring for Windows 64bit
Rem 2023, Mahmoud Fayed <msfclipper@yahoo.com>

cd bin
copy ..\extensions\libdepwin\cruntime_x64\*.dll .
copy ..\extensions\libdepwin\Allegro5.2.8\bin\x64\*.dll .
copy ..\extensions\libdepwin\freeglut\bin\x64\*.dll .
copy ..\extensions\libdepwin\glew\bin\Release\x64\*.dll .
copy ..\extensions\libdepwin\raylib2.5_x64\bin\*.dll .
copy ..\extensions\libdepwin\libuishared_x64\*.dll .
copy ..\extensions\libdepwin\tilengine_x64\lib\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_vc\lib\x64\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_image\lib\x64\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_mixer\lib\x64\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_net\lib\x64\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_ttf\lib\x64\*.dll .
copy ..\extensions\libdepwin\mysql_x64\lib\*.dll .
copy ..\extensions\libdepwin\pgsql_x64\lib\*.dll .

rem Delete Allegro Dlls (Debug Version)
del allegro*debug-5.2.dll 