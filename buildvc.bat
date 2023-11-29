IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=5.15.15

setlocal

rem build Ring Compiler/VM
cd language\src
call buildvc
call buildvcw
cd ..\..

rem open extensions folder
cd extensions

rem build Ring allegro
cd ringallegro
call buildvc_allegro5.2.8.bat

rem build Ring OpenGL
cd ..\ringopengl\opengl21
call buildvc.bat
cd ..\..

rem build Ring CJSON
cd ringcjson
call buildvc
cd ..

rem build Ring Console Colors
cd ringconsolecolors
call buildvc
cd ..

rem build Ring FreeGLUT
cd ringfreeglut
call buildvc
cd ..

rem build Ring stbImage
cd ringstbimage
call buildvc
cd ..

rem build Ring Threads
cd ringthreads
call buildvc
cd ..

rem build Ring RayLib
cd ringraylib\src
call buildvc
cd ..\..

rem build Ring Qt
cd ringqt
del /q debug\*.*
del /q release\*.*
call buildvc_core
call buildvc_light
call buildvc_nobluetooth
cd binupdate
call installqt515
cd ..\..

rem build RingLibuv
cd ringlibuv
call buildvc
cd ..

rem build RingInternet
cd ringinternet
call buildvc
cd ..

rem build RingCurl
cd ringcurl
call buildvc
cd ..

rem build RingOpenSSL
cd ringopenssl
call buildvc
cd ..

rem build RingLibui
cd ringlibui
call buildvc
cd ..

rem build RingBeep
cd ringbeep
call buildvc
cd ..

rem build RingODBC
cd ringodbc
call buildvc
cd ..

rem build RingHTTPLib
cd ringhttplib
call buildvc
cd ..

rem build RingMouseEvent
cd ringmouseevent
call buildvc
cd ..

rem build RingMurmurHash
cd ringmurmurhash
call buildvc
cd ..

rem build RingSockets
cd ringsockets
call buildvc
cd ..

rem build RingSQLite
cd ringsqlite
call buildvc
cd ..

rem build RingZip
cd ringzip
call buildvc
cd ..

rem build RingWinAPI
cd ringwinapi
call buildvc
cd ..

rem build RingWinCREG
cd ringwincreg
call buildvc
cd ..

rem build RingWinLib
cd ringwinlib
call buildvc
cd ..

rem build RingTilengine
cd ringtilengine
call buildvc
cd ..

rem build RingLibSDL
cd ringsdl
call buildvc
cd ..

rem build RingMySQL
cd ringmysql
call buildvc
cd ..

rem build RingPostgreSQL
cd ringpostgresql
call buildvc
cd ..

rem build RingListPro
cd ringlistpro
call buildvc
cd ..\..\

rem build Tools
cd tools\ring2exe
call build
cd ..\ringpm
call build
cd ..\ringrepl
call build
cd ..\folder2qrc
call build
cd ..\..\language\tests
call build
cd ..\..

rem build Sudoku
cd applications\sudoku\v2
call buildvc
cd ..\v3
call buildvc
cd ..\..\..\

rem build extensions/tutorial 
cd extensions/tutorial/createtable
call buildvc
cd ../displaylist
call buildvc
cd ../filterlist
call buildvc
cd ../generatelist
call buildvc
cd ../helloworld
call buildvc
cd ../helloworld2
call buildvc
cd ../incrementlist
call buildvc
cd ../integerpointer
call buildvc
cd ../mandelbrot
call buildvc
cd ../replicatelist
call buildvc
cd ../sayhello
call buildvc
cd ../stringpointer
call buildvc
cd ../sumlist
call buildvc
cd ../sumtwonumbers
call buildvc
cd ../updatetable
call buildvc
cd ..\..\..\

cd samples\Drawing\Mandelbrot
call buildvc
cd ..\..\..\

copy tools\ringnotepad\rnoteexe\RingNotepad.exe .

cd bin

rem copy dll files
copy ..\extensions\libdepwin\extra\*.dll .
copy ..\extensions\libdepwin\cruntime\*.dll .
copy ..\extensions\libdepwin\libcurl\bin\*.dll .
copy ..\extensions\libdepwin\openssl\bin\*.dll .
copy ..\extensions\libdepwin\Allegro5.2.8\bin\*.dll .
copy ..\extensions\libdepwin\freeglut\bin\*.dll .
copy ..\extensions\libdepwin\glew\bin\Release\win32\*.dll .
copy ..\extensions\libdepwin\raylib2.5\bin\*.dll .
copy ..\extensions\libdepwin\libuishared\*.dll .
copy ..\extensions\libdepwin\tilengine\lib\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_vc\lib\x86\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_image\lib\x86\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_mixer\lib\x86\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_net\lib\x86\*.dll .
copy ..\extensions\libdepwin\libsdl\SDL2_ttf\lib\x86\*.dll .
copy ..\extensions\libdepwin\mysql\lib\*.dll .
copy ..\extensions\libdepwin\pgsql\lib\*.dll .
copy ..\extensions\libdepwin\libuv\*.dll .



endlocal