Rem Simple Batch File to copy ring DLL files and libraries to the bin folder
Rem 2016-2020, Mahmoud Fayed <msfclipper@yahoo.com>

cd ..

copy lib\*.dll bin
copy extensions\libdepwin\allegro5.2.4\bin\*.dll bin
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
copy C:\Qt\Qt5.12.6\5.12.6\msvc2017\bin\*.dll bin
cd bin
xcopy C:\Qt\Qt5.12.6\5.12.6\msvc2017\plugins . /E /H /C /R /Q /Y
md qml
xcopy C:\Qt\Qt5.12.6\5.12.6\msvc2017\qml qml /E /H /C /R /Q /Y
md translations
xcopy C:\Qt\Qt5.12.6\5.12.6\msvc2017\translations translations /E /H /C /R /Q /Y
xcopy C:\Qt\Qt5.12.6\5.12.6\msvc2017\resources . /E /H /C /R /Q /Y
rem Delete Allegro Dlls (Debug Version)
del allegro*debug-5.2.dll 