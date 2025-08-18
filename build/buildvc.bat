@echo off
IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=5.15.19

cd ..

setlocal

echo Building Ring Compiler/VM...
cd language\build
@call buildvc >nul
@call buildvcw >nul
cd ..\..

cd extensions

echo Building Ring Allegro...
cd ringallegro
@call buildvc_allegro5.2.8.bat >nul
cd ..

echo Building Ring OpenGL...
cd ringopengl\opengl21
@call buildvc.bat >nul
cd ..\..

echo Building Ring CJSON...
cd ringcjson
@call buildvc >nul
cd ..

echo Building Ring Console Colors...
cd ringconsolecolors
@call buildvc >nul
cd ..

echo Building Ring FreeGLUT...
cd ringfreeglut
@call buildvc >nul
cd ..

echo Building Ring stbImage...
cd ringstbimage
@call buildvc >nul
cd ..

echo Building Ring Threads...
cd ringthreads
@call buildvc >nul
cd ..

echo Building Ring RayLib...
cd ringraylib5\src
@call buildvc >nul
cd ..\..

echo Building Ring Qt...
cd ringqt
del /q debug\*.* >nul
del /q release\*.* >nul
@call gencode_core >nul
@call buildvc_core >nul

del /q debug\*.* >nul
del /q release\*.* >nul
@call gencode_light >nul
@call buildvc_light >nul

del /q debug\*.* >nul
del /q release\*.* >nul
@call gencode_nobluetooth >nul
@call buildvc_nobluetooth >nul
cd binupdate
@call installqt515 >nul
cd ..\..

echo Building RingLibuv...
cd ringlibuv
@call buildvc >nul
cd ..

echo Building RingInternet...
cd ringinternet
@call buildvc >nul
cd ..

echo Building RingCurl...
cd ringcurl
@call buildvc >nul
cd ..

echo Building RingOpenSSL...
cd ringopenssl
@call buildvc >nul
cd ..

echo Building RingLibui...
cd ringlibui
@call buildvc >nul
cd ..

echo Building RingBeep...
cd ringbeep
@call buildvc >nul
cd ..

echo Building RingODBC...
cd ringodbc
@call buildvc >nul
cd ..

echo Building RingHTTPLib...
cd ringhttplib32
@call buildvc >nul
cd ..

echo Building RingMouseEvent...
cd ringmouseevent
@call buildvc >nul
cd ..

echo Building RingMurmurHash...
cd ringmurmurhash
@call buildvc >nul
cd ..

echo Building RingSockets...
cd ringsockets
@call buildvc >nul
cd ..

echo Building RingSQLite...
cd ringsqlite
@call buildvc >nul
cd ..

echo Building RingZip...
cd ringzip
@call buildvc >nul
cd ..

echo Building RingWinAPI...
cd ringwinapi
@call buildvc >nul
cd ..

echo Building RingWinCREG...
cd ringwincreg
@call buildvc >nul
cd ..

echo Building RingWinLib...
cd ringwinlib
@call buildvc >nul
cd ..

echo Building RingTilengine...
cd ringtilengine
@call buildvc >nul
cd ..

echo Building RingLibSDL...
cd ringsdl
@call buildvc >nul
cd ..

echo Building RingMySQL...
cd ringmysql
@call buildvc >nul
cd ..

echo Building RingPostgreSQL...
cd ringpostgresql
@call buildvc >nul
cd ..

echo Building RingRogueUtil...
cd ringrogueutil
@call buildvc >nul
cd ..

echo Building RingPDFGen...
cd ringpdfgen
@call buildvc >nul
cd ..

echo Building RingFastPro...
cd ringfastpro
@call buildvc >nul
cd ..\..

echo Building Tools...
cd tools\ring2exe
@call build >nul
cd ..\ringpm
@call build >nul
cd ..\ringrepl
@call build >nul
cd ..\folder2qrc
@call build >nul
cd ..\..\language\tests
@call build >nul
cd ..\..

echo Building Sudoku...
cd applications\sudoku\v2
@call buildvc >nul
cd ..\v3
@call buildvc >nul
cd ..\..\..

echo Building Tutorial Extensions...
cd extensions/tutorial/createtable
@call buildvc >nul
cd ../displaylist
@call buildvc >nul
cd ../filterlist
@call buildvc >nul
cd ../generatelist
@call buildvc >nul
cd ../helloworld
@call buildvc >nul
cd ../helloworld2
@call buildvc >nul
cd ../incrementlist
@call buildvc >nul
cd ../integerpointer
@call buildvc >nul
cd ../mandelbrot
@call buildvc >nul
cd ../replicatelist
@call buildvc >nul
cd ../sayhello
@call buildvc >nul
cd ../stringpointer
@call buildvc >nul
cd ../sumlist
@call buildvc >nul
cd ../sumtwonumbers
@call buildvc >nul
cd ../updatetable
@call buildvc >nul
cd ..\..\..

echo Building Mandelbrot Sample...
cd samples\Drawing\Mandelbrot
@call buildvc >nul
cd ..\..\..

echo Copying RingNotepad.exe...
copy tools\ringnotepad\rnoteexe\RingNotepad.exe . >nul

echo Copying DLL files...
cd bin
copy ..\extensions\libdepwin\extra\*.dll . >nul
copy ..\extensions\libdepwin\cruntime\*.dll . >nul
copy ..\extensions\libdepwin\libcurl\bin\*.dll . >nul
copy ..\extensions\libdepwin\openssl\bin\*.dll . >nul
copy ..\extensions\libdepwin\Allegro5.2.8\bin\*.dll . >nul
copy ..\extensions\libdepwin\freeglut\bin\*.dll . >nul
copy ..\extensions\libdepwin\glew\bin\Release\win32\*.dll . >nul
copy ..\extensions\libdepwin\raylib5\lib\*.dll . >nul
copy ..\extensions\libdepwin\libuishared\*.dll . >nul
copy ..\extensions\libdepwin\tilengine\lib\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_vc\lib\x86\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_image\lib\x86\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_mixer\lib\x86\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_net\lib\x86\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_ttf\lib\x86\*.dll . >nul
copy ..\extensions\libdepwin\mysql\lib\*.dll . >nul
copy ..\extensions\libdepwin\pgsql\lib\*.dll . >nul
copy ..\extensions\libdepwin\libuv\*.dll . >nul

endlocal