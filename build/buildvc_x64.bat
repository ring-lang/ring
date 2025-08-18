@echo off
IF "%RING_QT_DIR%"=="" SET RING_QT_DIR=C:\Qt
IF "%RING_QT_VERSION%"=="" SET RING_QT_VERSION=5.15.19

cd ..

setlocal

echo Building Ring Compiler/VM...
cd language\build
@call buildvc_x64 >nul
@call buildvcw_x64 >nul
cd ..\..

cd extensions

echo Building Ring Allegro...
cd ringallegro
@call buildvc_x64.bat >nul
cd ..

echo Building Ring OpenGL...
cd ringopengl\opengl21
@call buildvc_x64.bat >nul
cd ..\..

echo Building Ring CJSON...
cd ringcjson
@call buildvc_x64 >nul
cd ..

echo Building Ring Console Colors...
cd ringconsolecolors
@call buildvc_x64 >nul
cd ..

echo Building Ring FreeGLUT...
cd ringfreeglut
@call buildvc_x64 >nul
cd ..

echo Building Ring stbImage...
cd ringstbimage
@call buildvc_x64 >nul
cd ..

echo Building Ring Threads...
cd ringthreads
@call buildvc_x64 >nul
cd ..

echo Building Ring RayLib...
cd ringraylib5\src
@call buildvc_x64 >nul
cd ..\..

echo Building Ring Qt (Core)...
cd ringqt
del /q debug\*.* >nul
del /q release\*.* >nul
@call gencode_core >nul
@call buildvc_core_x64 >nul

echo Building Ring Qt (LightGUILib)...
del /q debug\*.* >nul
del /q release\*.* >nul
@call gencode_light >nul
@call buildvc_light_x64 >nul

echo Building Ring Qt (GUILib)...
del /q debug\*.* >nul
del /q release\*.* >nul
@call gencode_nobluetooth >nul
@call buildvc_nobluetooth_x64 >nul
cd binupdate
@call installqt515_x64 >nul
..\..\..\bin\ring removedebugdlls.ring
cd ..\..

echo Building RingLibuv...
cd ringlibuv
@call buildvc_x64 >nul
cd ..

echo Building RingInternet...
cd ringinternet
@call buildvc_x64 >nul
cd ..

echo Building RingCurl...
cd ringcurl
@call buildvc_x64 >nul
cd ..

echo Building RingOpenSSL...
cd ringopenssl
@call buildvc_x64 >nul
cd ..

echo Building RingLibui...
cd ringlibui
@call buildvc_x64 >nul
cd ..

echo Building RingBeep...
cd ringbeep
@call buildvc_x64 >nul
cd ..

echo Building RingODBC...
cd ringodbc
@call buildvc_x64 >nul
cd ..

echo Building RingHTTPLib...
cd ringhttplib
@call buildvc_x64 >nul
cd ..

echo Building RingMouseEvent...
cd ringmouseevent
@call buildvc_x64 >nul
cd ..

echo Building RingMurmurHash...
cd ringmurmurhash
@call buildvc_x64 >nul
cd ..

echo Building RingSockets...
cd ringsockets
@call buildvc_x64 >nul
cd ..

echo Building RingSQLite...
cd ringsqlite
@call buildvc_x64 >nul
cd ..

echo Building RingZip...
cd ringzip
@call buildvc_x64 >nul
cd ..

echo Building RingWinAPI...
cd ringwinapi
@call buildvc_x64 >nul
cd ..

echo Building RingWinCREG...
cd ringwincreg
@call buildvc_x64 >nul
cd ..

echo Building RingWinLib...
cd ringwinlib
@call buildvc_x64 >nul
cd ..

echo Building RingTilengine...
cd ringtilengine
@call buildvc_x64 >nul
cd ..

echo Building RingLibSDL...
cd ringsdl
@call buildvc_x64 >nul
cd ..

echo Building RingMySQL...
cd ringmysql
@call buildvc_x64 >nul
cd ..

echo Building RingPostgreSQL...
cd ringpostgresql
@call buildvc_x64 >nul
cd ..

echo Building RingRogueUtil...
cd ringrogueutil
@call buildvc_x64 >nul
cd ..

echo Building RingPDFGen...
cd ringpdfgen
@call buildvc_x64 >nul
cd ..

echo Building RingFastPro...
cd ringfastpro
@call buildvc_x64 >nul
cd ..\..

echo Building Tools...
echo Building Ring2EXE...
cd tools\ring2exe
@call build >nul
echo Building RingPM...
cd ..\ringpm
@call build >nul
echo Building RingREPL...
cd ..\ringrepl
@call build >nul
echo Building Folder2Qrc...
cd ..\folder2qrc
@call build >nul
echo Building Tests...
cd ..\..\language\tests
@call build >nul
cd ..\..

echo Building Applications\Sudoku...
cd applications\sudoku\v2
@call buildvc_x64 >nul
cd ..\v3
@call buildvc_x64 >nul
cd ..\..\..

echo Building Extensions\Tutorial...
cd extensions/tutorial/createtable
@call buildvc_x64 >nul
cd ../displaylist
@call buildvc_x64 >nul
cd ../filterlist
@call buildvc_x64 >nul
cd ../generatelist
@call buildvc_x64 >nul
cd ../helloworld
@call buildvc_x64 >nul
cd ../helloworld2
@call buildvc_x64 >nul
cd ../incrementlist
@call buildvc_x64 >nul
cd ../integerpointer
@call buildvc_x64 >nul
cd ../mandelbrot
@call buildvc_x64 >nul
cd ../replicatelist
@call buildvc_x64 >nul
cd ../sayhello
@call buildvc_x64 >nul
cd ../stringpointer
@call buildvc_x64 >nul
cd ../sumlist
@call buildvc_x64 >nul
cd ../sumtwonumbers
@call buildvc_x64 >nul
cd ../updatetable
@call buildvc_x64 >nul
cd ..\..\..

echo Building samples\Drawing\Mandelbrot Sample...
cd samples\Drawing\Mandelbrot
@call buildvc_x64 >nul
cd ..\..\..

echo Copying RingNotepad.exe...
copy tools\ringnotepad\rnoteexe\RingNotepad.exe . >nul

echo Copying DLL files...
cd bin
copy ..\extensions\libdepwin\extra\*.dll . >nul
copy ..\extensions\libdepwin\cruntime_x64\*.dll . >nul
copy ..\extensions\libdepwin\Allegro5.2.8\bin\x64\*.dll . >nul
copy ..\extensions\libdepwin\freeglut\bin\x64\*.dll . >nul
copy ..\extensions\libdepwin\glew\bin\Release\x64\*.dll . >nul
copy ..\extensions\libdepwin\raylib5_x64\lib\*.dll . >nul
copy ..\extensions\libdepwin\libuishared_x64\*.dll . >nul
copy ..\extensions\libdepwin\tilengine_x64\lib\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_vc\lib\x64\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_image\lib\x64\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_mixer\lib\x64\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_net\lib\x64\*.dll . >nul
copy ..\extensions\libdepwin\libsdl\SDL2_ttf\lib\x64\*.dll . >nul
copy ..\extensions\libdepwin\mysql_x64\lib\*.dll . >nul
copy ..\extensions\libdepwin\pgsql_x64\lib\*.dll . >nul

@call cleartemp >nul

endlocal