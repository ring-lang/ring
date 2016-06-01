Rem Simple Batch File to copy ring DLL files and libraries to the bin folder
Rem 2016, Mahmoud Fayed <msfclipper@yahoo.com>

cd ..

copy lib\*.dll bin
copy libdepwin\allegro\bin\*.dll bin
copy libdepwin\libcurl\bin\*.dll bin
copy libdepwin\mysql\lib\*.dll bin
copy libdepwin\openssl\bin\*.dll bin
copy C:\Qt\Qt5.5.1\5.5\mingw492_32\bin\*.dll bin
copy extensions\ringqt\guilib.ring bin
copy extensions\ringqt\ring_qt.ring bin
copy extensions\ringqt\qt.rh bin
copy extensions\ringqt\ringqt.dll bin
copy extensions\ringallegro\gamelib.ring bin
copy extensions\ringallegro\allegro.rh bin
