setlocal

rem build Ring Compiler/VM
cd language
cd src
call buildvc
call buildvcw
cd ..
cd ..

rem open extensions folder
cd extensions

rem build Ring allegro
cd ringallegro
call buildvc_allegro5.2.8.bat

rem build Ring OpenGL
cd ..
cd ringopengl
cd opengl21
call buildvc.bat
cd ..
cd ..

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
cd ringraylib
cd src
call buildvc
cd ..
cd ..

rem build Ring Qt
cd ringqt
del /q debug\*.*
del /q release\*.*
call buildvc_core
call buildvc_light
call buildvc_nobluetooth
cd binupdate
call installqt515
cd ..
cd ..

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
cd ..

rem build Tools
cd tools
cd ring2exe
call build
cd ..
cd ringpm
call build
cd ..
cd ringrepl
call build
cd ..
cd folder2qrc
call build
cd ..
cd ..
cd language
cd tests
call build
cd ..
cd ..

rem build Sudoku
cd applications\sudoku\v2
call buildvc
cd ..\v3
call buildvc
cd ..\..\..\

rem copy dll files
copy B:\ring\extensions\libdepwin\Allegro5.2.8\bin\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\freeglut\bin\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\glew\bin\Release\win32\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\raylib2.5\bin\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\libuishared\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\tilengine\lib\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\libsdl\SDL2_vc\lib\x86\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\libsdl\SDL2_image\lib\x86\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\libsdl\SDL2_mixer\lib\x86\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\libsdl\SDL2_net\lib\x86\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\libsdl\SDL2_ttf\lib\x86\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\mysql\lib\*.dll b:\ring\bin
copy B:\ring\extensions\libdepwin\pgsql\lib\*.dll b:\ring\bin


endlocal