# Simple Script to copy ring binary file and libraries to the system
# 2016-2025, Mahmoud Fayed <msfclipper@yahoo.com>

# To be able to call ring from any folder 

if [ -f ../lib/libring.dylib ];
then

BREW_PREFIX=$(brew --prefix)

ln -sf "`pwd`/ring" $BREW_PREFIX/bin/ring
xattr -d com.apple.quarantine $BREW_PREFIX/bin/ring

ln -sf "`pwd`/ring2exe" $BREW_PREFIX/bin/ring2exe
xattr -d com.apple.quarantine $BREW_PREFIX/bin/ring2exe

ln -sf "`pwd`/folder2qrc" $BREW_PREFIX/bin/folder2qrc
xattr -d com.apple.quarantine $BREW_PREFIX/bin/folder2qrc

ln -sf "`pwd`/ringpm" $BREW_PREFIX/bin/ringpm
xattr -d com.apple.quarantine $BREW_PREFIX/bin/ringpm

ln -sf "`pwd`/ringrepl" $BREW_PREFIX/bin/ringrepl
xattr -d com.apple.quarantine $BREW_PREFIX/bin/ringrepl

cd ..

ln -sf "`pwd`/lib/libring.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring.dylib

fi

if [ -f ../lib/libring.so ];
then
sudo ln -sf "`pwd`/ring" /usr/bin/ring

sudo ln -sf "`pwd`/ring2exe" /usr/bin/ring2exe

sudo ln -sf "`pwd`/folder2qrc" /usr/bin/folder2qrc

sudo ln -sf "`pwd`/ringpm" /usr/bin/ringpm

sudo ln -sf "`pwd`/ringrepl" /usr/bin/ringrepl

cd ..
sudo ln -sf "`pwd`/lib/libring.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring.so" /usr/lib64
fi
	
# Make the RingODBC library ready for use directly

if [ -f lib/libring_odbc.dylib ];
then
ln -sf "`pwd`/lib/libring_odbc.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_odbc.dylib
fi

if [ -f lib/libring_odbc.so ];
then
sudo ln -sf "`pwd`/lib/libring_odbc.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_odbc.so" /usr/lib64
fi

# Make the RingMySQL library ready for use directly

if [ -f lib/libring_mysql.dylib ];
then
ln -sf "`pwd`/lib/libring_mysql.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_mysql.dylib
fi

if [ -f lib/libring_mysql.so ];
then
sudo ln -sf "`pwd`/lib/libring_mysql.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_mysql.so" /usr/lib64
fi

# Make the RingSQLite library ready for use directly

if [ -f lib/libring_sqlite.dylib ];
then
ln -sf "`pwd`/lib/libring_sqlite.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_sqlite.dylib
fi

if [ -f lib/libring_sqlite.so ];
then
sudo ln -sf "`pwd`/lib/libring_sqlite.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_sqlite.so" /usr/lib64
fi

# Make the RingInternet library ready for use directly

if [ -f lib/libring_internet.dylib ];
then
ln -sf "`pwd`/lib/libring_internet.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_internet.dylib
fi

if [ -f lib/libring_internet.so ];
then
sudo ln -sf "`pwd`/lib/libring_internet.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_internet.so" /usr/lib64
fi

# Make the RingOpenSSL library ready for use directly

if [ -f lib/libring_openssl.dylib ];
then
ln -sf "`pwd`/lib/libring_openssl.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_openssl.dylib
fi

if [ -f lib/libring_openssl.so ];
then
sudo ln -sf "`pwd`/lib/libring_openssl.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_openssl.so" /usr/lib64
fi

# Make the RingAllegro library ready for use directly
	
if [ -f lib/libringallegro.dylib ];
then
ln -sf "`pwd`/lib/libringallegro.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libringallegro.dylib
fi

if [ -f lib/libringallegro.so ];
then
sudo ln -sf "`pwd`/lib/libringallegro.so" /usr/lib
sudo ln -sf "`pwd`/lib/libringallegro.so" /usr/lib64
fi

# Make the RingQt library ready for use directly
	
if [ -f lib/libringqt.dylib ];
then
ln -sf "`pwd`/lib/libringqt.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libringqt.dylib
fi

if [ -f lib/libringqt.so ];
then
sudo ln -sf "`pwd`/lib/libringqt.so" /usr/lib
sudo ln -sf "`pwd`/lib/libringqt.so" /usr/lib64
fi

# Make the RingQt (Light) library ready for use directly
	
if [ -f lib/libringqt_light.dylib ];
then
ln -sf "`pwd`/lib/libringqt_light.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libringqt_light.dylib
fi

if [ -f lib/libringqt_light.so ];
then
sudo ln -sf "`pwd`/lib/libringqt_light.so" /usr/lib
sudo ln -sf "`pwd`/lib/libringqt_light.so" /usr/lib64
fi

# Make the RingQt (Core) library ready for use directly
	
if [ -f lib/libringqt_core.dylib ];
then
ln -sf "`pwd`/lib/libringqt_core.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libringqt_core.dylib
fi

if [ -f lib/libringqt_core.so ];
then
sudo ln -sf "`pwd`/lib/libringqt_core.so" /usr/lib
sudo ln -sf "`pwd`/lib/libringqt_core.so" /usr/lib64
fi

# Make the RingLibCurl library ready for use directly

if [ -f lib/libring_libcurl.dylib ];
then
ln -sf "`pwd`/lib/libring_libcurl.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_libcurl.dylib
fi

if [ -f lib/libring_libcurl.so ];
then
sudo ln -sf "`pwd`/lib/libring_libcurl.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_libcurl.so" /usr/lib64
fi

# Make the RingZipLib library ready for use directly

if [ -f lib/libring_libzip.dylib ];
then
ln -sf "`pwd`/lib/libring_libzip.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_libzip.dylib
fi

if [ -f lib/libring_libzip.so ];
then
sudo ln -sf "`pwd`/lib/libring_libzip.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_libzip.so" /usr/lib64
fi

# Make the RingFreeGLUT library ready for use directly

if [ -f lib/libring_freeglut.dylib ];
then
ln -sf "`pwd`/lib/libring_freeglut.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_freeglut.dylib
fi

if [ -f lib/libring_freeglut.so ];
then
sudo ln -sf "`pwd`/lib/libring_freeglut.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_freeglut.so" /usr/lib64
fi

# Make the RingOpenGL library ready for use directly

if [ -f lib/libring_opengl11.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl11.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl11.dylib
fi

if [ -f lib/libring_opengl11.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl11.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl11.so" /usr/lib64
fi


if [ -f lib/libring_opengl12.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl12.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl12.dylib
fi

if [ -f lib/libring_opengl12.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl12.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl12.so" /usr/lib64
fi

if [ -f lib/libring_opengl13.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl13.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl13.dylib
fi

if [ -f lib/libring_opengl13.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl13.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl13.so" /usr/lib64
fi

if [ -f lib/libring_opengl14.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl14.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl14.dylib
fi

if [ -f lib/libring_opengl14.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl14.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl14.so" /usr/lib64
fi

if [ -f lib/libring_opengl15.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl15.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl15.dylib
fi

if [ -f lib/libring_opengl15.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl15.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl15.so" /usr/lib64
fi

if [ -f lib/libring_opengl20.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl20.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl20.dylib
fi

if [ -f lib/libring_opengl20.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl20.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl20.so" /usr/lib64
fi

if [ -f lib/libring_opengl21.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl21.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl21.dylib
fi

if [ -f lib/libring_opengl21.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl21.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl21.so" /usr/lib64
fi

if [ -f lib/libring_opengl30.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl30.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl30.dylib
fi

if [ -f lib/libring_opengl30.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl30.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl30.so" /usr/lib64
fi

if [ -f lib/libring_opengl31.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl31.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl31.dylib
fi

if [ -f lib/libring_opengl31.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl31.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl31.so" /usr/lib64
fi

if [ -f lib/libring_opengl32.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl32.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl32.dylib
fi

if [ -f lib/libring_opengl32.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl32.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl32.so" /usr/lib64
fi

if [ -f lib/libring_opengl33.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl33.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl33.dylib
fi

if [ -f lib/libring_opengl33.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl33.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl33.so" /usr/lib64
fi

if [ -f lib/libring_opengl40.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl40.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl40.dylib
fi

if [ -f lib/libring_opengl40.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl40.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl40.so" /usr/lib64
fi

if [ -f lib/libring_opengl41.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl41.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl41.dylib
fi

if [ -f lib/libring_opengl41.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl41.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl41.so" /usr/lib64
fi

if [ -f lib/libring_opengl42.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl42.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl42.dylib
fi

if [ -f lib/libring_opengl42.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl42.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl42.so" /usr/lib64
fi

if [ -f lib/libring_opengl43.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl43.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl43.dylib
fi

if [ -f lib/libring_opengl43.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl43.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl43.so" /usr/lib64
fi

if [ -f lib/libring_opengl44.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl44.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl44.dylib
fi

if [ -f lib/libring_opengl44.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl44.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl44.so" /usr/lib64
fi

if [ -f lib/libring_opengl45.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl45.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl45.dylib
fi

if [ -f lib/libring_opengl45.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl45.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl45.so" /usr/lib64
fi

if [ -f lib/libring_opengl46.dylib ];
then
ln -sf "`pwd`/lib/libring_opengl46.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_opengl46.dylib
fi

if [ -f lib/libring_opengl46.so ];
then
sudo ln -sf "`pwd`/lib/libring_opengl46.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_opengl46.so" /usr/lib64
fi

# Make the RingMurmurHash library ready for use directly

if [ -f lib/libring_murmurhash.dylib ];
then
ln -sf "`pwd`/lib/libring_murmurhash.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_murmurhash.dylib
fi

if [ -f lib/libring_murmurhash.so ];
then
sudo ln -sf "`pwd`/lib/libring_murmurhash.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_murmurhash.so" /usr/lib64
fi

# Make the RingLibuv library ready for use directly

if [ -f lib/libring_uv.dylib ];
then
ln -sf "`pwd`/lib/libring_uv.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_uv.dylib
fi

if [ -f lib/libring_uv.so ];
then
sudo ln -sf "`pwd`/lib/libring_uv.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_uv.so" /usr/lib64
fi

# Make the RingPostgreSQL library ready for use directly

if [ -f lib/libring_pgsql.dylib ];
then
ln -sf "`pwd`/lib/libring_pgsql.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_pgsql.dylib
fi

if [ -f lib/libring_pgsql.so ];
then
sudo ln -sf "`pwd`/lib/libring_pgsql.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_pgsql.so" /usr/lib64
fi

# Make the RingConsoleColors library ready for use directly

if [ -f lib/libring_consolecolors.dylib ];
then
ln -sf "`pwd`/lib/libring_consolecolors.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_consolecolors.dylib
fi

if [ -f lib/libring_consolecolors.so ];
then
sudo ln -sf "`pwd`/lib/libring_consolecolors.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_consolecolors.so" /usr/lib64
fi

# Make the RingLibSDL library ready for use directly

if [ -f lib/libringsdl.dylib ];
then
ln -sf "`pwd`/lib/libringsdl.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libringsdl.dylib
fi

if [ -f lib/libringsdl.so ];
then
sudo ln -sf "`pwd`/lib/libringsdl.so" /usr/lib
sudo ln -sf "`pwd`/lib/libringsdl.so" /usr/lib64
fi

# Make the RingRayLib library ready for use directly

if [ -f lib/libringraylib.dylib ];
then
ln -sf "`pwd`/lib/libringraylib.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libringraylib.dylib
cp extensions/ringraylib5/src/macOS_raylib-5/lib/libraylib.* $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libraylib.*
fi

if [ -f lib/libringraylib.so ];
then
sudo ln -sf "`pwd`/lib/libringraylib.so" /usr/lib
sudo ln -sf "`pwd`/lib/libringraylib.so" /usr/lib64
sudo cp extensions/ringraylib5/src/linux_raylib-5/lib/libraylib.so.* /usr/lib
sudo cp extensions/ringraylib5/src/linux_raylib-5/lib/libraylib.so.* /usr/lib64
fi

# Make the RingSockets library ready for use directly

if [ -f lib/libring_sockets.dylib ];
then
ln -sf "`pwd`/lib/libring_sockets.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_sockets.dylib
fi

if [ -f lib/libring_sockets.so ];
then
sudo ln -sf "`pwd`/lib/libring_sockets.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_sockets.so" /usr/lib64
fi

# Make the RingThreads library ready for use directly

if [ -f lib/libring_threads.dylib ];
then
ln -sf "`pwd`/lib/libring_threads.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_threads.dylib
fi

if [ -f lib/libring_threads.so ];
then
sudo ln -sf "`pwd`/lib/libring_threads.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_threads.so" /usr/lib64
fi

# Make the RingLibUI library ready for use directly

if [ -f lib/libring_libui.dylib ];
then
ln -sf "`pwd`/lib/libring_libui.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_libui.dylib
cp extensions/ringlibui/macOS/libui.* $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libui.*
fi

if [ -f lib/libring_libui.so ];
then
sudo ln -sf "`pwd`/lib/libring_libui.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_libui.so" /usr/lib64
sudo cp extensions/ringlibui/linux/libui.so.* /usr/lib
sudo cp extensions/ringlibui/linux/libui.so.* /usr/lib64
fi

# Make the RingCJSON library ready for use directly

if [ -f lib/libring_cjson.dylib ];
then
ln -sf "`pwd`/lib/libring_cjson.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_cjson.dylib
fi

if [ -f lib/libring_cjson.so ];
then
sudo ln -sf "`pwd`/lib/libring_cjson.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_cjson.so" /usr/lib64
fi

# Make the RingHTTPLib library ready for use directly

if [ -f lib/libring_httplib.dylib ];
then
ln -sf "`pwd`/lib/libring_httplib.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_httplib.dylib
fi

if [ -f lib/libring_httplib.so ];
then
sudo ln -sf "`pwd`/lib/libring_httplib.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_httplib.so" /usr/lib64
fi

# Make the RingStbImage library ready for use directly

if [ -f lib/libring_stbimage.dylib ];
then
ln -sf "`pwd`/lib/libring_stbimage.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_stbimage.dylib
fi

if [ -f lib/libring_stbimage.so ];
then
sudo ln -sf "`pwd`/lib/libring_stbimage.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_stbimage.so" /usr/lib64
fi

# Make the RingFastPro library ready for use directly

if [ -f lib/libring_fastpro.dylib ];
then
ln -sf "`pwd`/lib/libring_fastpro.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_fastpro.dylib
fi

if [ -f lib/libring_fastpro.so ];
then
sudo ln -sf "`pwd`/lib/libring_fastpro.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_fastpro.so" /usr/lib64
fi

# Make the RingRogueUtil library ready for use directly

if [ -f lib/libring_rogueutil.dylib ];
then
ln -sf "`pwd`/lib/libring_rogueutil.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_rogueutil.dylib
fi

if [ -f lib/libring_rogueutil.so ];
then
sudo ln -sf "`pwd`/lib/libring_rogueutil.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_rogueutil.so" /usr/lib64
fi

# Make the RingTilengine library ready for use directly

if [ -f lib/libring_tilengine.so ];
then
sudo ln -sf "`pwd`/lib/libring_tilengine.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_tilengine.so" /usr/lib64
sudo cp extensions/ringtilengine/linux_tilengine/lib/*.so /usr/lib
sudo cp extensions/ringtilengine/linux_tilengine/lib/*.so /usr/lib64
fi

# Make the RingPDFGen library ready for use directly

if [ -f lib/libring_pdfgen.dylib ];
then
ln -sf "`pwd`/lib/libring_pdfgen.dylib" $BREW_PREFIX/lib
xattr -d com.apple.quarantine $BREW_PREFIX/lib/libring_pdfgen.dylib
fi

if [ -f lib/libring_pdfgen.so ];
then
sudo ln -sf "`pwd`/lib/libring_pdfgen.so" /usr/lib
sudo ln -sf "`pwd`/lib/libring_pdfgen.so" /usr/lib64
fi