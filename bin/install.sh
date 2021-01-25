# Simple Script to copy ring binary file and libraries to the system
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

# To be able to call ring from any folder 

if [ -f ../lib/libring.dylib ];
then
ln -s "`pwd`/ring" /usr/local/bin/ring

ln -s "`pwd`/ring2exe" /usr/local/bin/ring2exe

ln -s "`pwd`/folder2qrc" /usr/local/bin/folder2qrc

ln -s "`pwd`/ringpm" /usr/local/bin/ringpm

ln -s "`pwd`/ringrepl" /usr/local/bin/ringrepl

cd ..

ln -s "`pwd`/lib/libring.dylib" /usr/local/lib
fi

if [ -f ../lib/libring.so ];
then
sudo ln -s "`pwd`/ring" /usr/bin/ring

sudo ln -s "`pwd`/ring2exe" /usr/bin/ring2exe

sudo ln -s "`pwd`/folder2qrc" /usr/bin/folder2qrc

sudo ln -s "`pwd`/ringpm" /usr/bin/ringpm

sudo ln -s "`pwd`/ringrepl" /usr/bin/ringrepl

cd ..
sudo ln -s "`pwd`/lib/libring.so" /usr/lib
sudo ln -s "`pwd`/lib/libring.so" /usr/lib64
fi
	
# Make the RingODBC library ready for use directly

if [ -f lib/libring_odbc.dylib ];
then
ln -s "`pwd`/lib/libring_odbc.dylib" /usr/local/lib
fi

if [ -f lib/libring_odbc.so ];
then
sudo ln -s "`pwd`/lib/libring_odbc.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_odbc.so" /usr/lib64
fi

# Make the RingMySQL library ready for use directly

if [ -f lib/libring_mysql.dylib ];
then
ln -s "`pwd`/lib/libring_mysql.dylib" /usr/local/lib
fi

if [ -f lib/libring_mysql.so ];
then
sudo ln -s "`pwd`/lib/libring_mysql.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_mysql.so" /usr/lib64
fi

# Make the RingSQLite library ready for use directly

if [ -f lib/libring_sqlite.dylib ];
then
ln -s "`pwd`/lib/libring_sqlite.dylib" /usr/local/lib
fi

if [ -f lib/libring_sqlite.so ];
then
sudo ln -s "`pwd`/lib/libring_sqlite.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_sqlite.so" /usr/lib64
fi

# Make the RingInternet library ready for use directly

if [ -f lib/libring_internet.dylib ];
then
ln -s "`pwd`/lib/libring_internet.dylib" /usr/local/lib
fi

if [ -f lib/libring_internet.so ];
then
sudo ln -s "`pwd`/lib/libring_internet.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_internet.so" /usr/lib64
fi

# Make the RingOpenSSL library ready for use directly

if [ -f lib/libring_openssl.dylib ];
then
ln -s "`pwd`/lib/libring_openssl.dylib" /usr/local/lib
fi

if [ -f lib/libring_openssl.so ];
then
sudo ln -s "`pwd`/lib/libring_openssl.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_openssl.so" /usr/lib64
fi

# Make the RingAllegro library ready for use directly
	
if [ -f lib/libringallegro.dylib ];
then
ln -s "`pwd`/lib/libringallegro.dylib" /usr/local/lib
fi

if [ -f lib/libringallegro.so ];
then
sudo ln -s "`pwd`/lib/libringallegro.so" /usr/lib
sudo ln -s "`pwd`/lib/libringallegro.so" /usr/lib64
fi

# Make the RingQt library ready for use directly
	
if [ -f lib/libringqt.dylib ];
then
ln -s "`pwd`/lib/libringqt.dylib" /usr/local/lib
fi

if [ -f lib/libringqt.so ];
then
sudo ln -s "`pwd`/lib/libringqt.so" /usr/lib
sudo ln -s "`pwd`/lib/libringqt.so" /usr/lib64
fi

# Make the RingLibCurl library ready for use directly

if [ -f lib/libring_libcurl.dylib ];
then
ln -s "`pwd`/lib/libring_libcurl.dylib" /usr/local/lib
fi

if [ -f lib/libring_libcurl.so ];
then
sudo ln -s "`pwd`/lib/libring_libcurl.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_libcurl.so" /usr/lib64
fi

# Make the RingZipLib library ready for use directly

if [ -f lib/libring_libzip.dylib ];
then
ln -s "`pwd`/lib/libring_libzip.dylib" /usr/local/lib
fi

if [ -f lib/libring_libzip.so ];
then
sudo ln -s "`pwd`/lib/libring_libzip.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_libzip.so" /usr/lib64
fi

# Make the RingFreeGLUT library ready for use directly

if [ -f lib/libring_freeglut.dylib ];
then
ln -s "`pwd`/lib/libring_freeglut.dylib" /usr/local/lib
fi

if [ -f lib/libring_freeglut.so ];
then
sudo ln -s "`pwd`/lib/libring_freeglut.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_freeglut.so" /usr/lib64
fi

# Make the RingOpenGL library ready for use directly

if [ -f lib/libring_opengl11.dylib ];
then
ln -s "`pwd`/lib/libring_opengl11.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl11.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl11.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl11.so" /usr/lib64
fi


if [ -f lib/libring_opengl12.dylib ];
then
ln -s "`pwd`/lib/libring_opengl12.dylib" /usr/lib
fi

if [ -f lib/libring_opengl12.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl12.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl12.so" /usr/lib64
fi

if [ -f lib/libring_opengl13.dylib ];
then
ln -s "`pwd`/lib/libring_opengl13.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl13.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl13.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl13.so" /usr/lib64
fi

if [ -f lib/libring_opengl14.dylib ];
then
ln -s "`pwd`/lib/libring_opengl14.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl14.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl14.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl14.so" /usr/lib64
fi

if [ -f lib/libring_opengl15.dylib ];
then
ln -s "`pwd`/lib/libring_opengl15.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl15.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl15.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl15.so" /usr/lib64
fi

if [ -f lib/libring_opengl20.dylib ];
then
ln -s "`pwd`/lib/libring_opengl20.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl20.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl20.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl20.so" /usr/lib64
fi

if [ -f lib/libring_opengl21.dylib ];
then
ln -s "`pwd`/lib/libring_opengl21.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl21.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl21.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl21.so" /usr/lib64
fi

if [ -f lib/libring_opengl30.dylib ];
then
ln -s "`pwd`/lib/libring_opengl30.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl30.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl30.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl30.so" /usr/lib64
fi

if [ -f lib/libring_opengl31.dylib ];
then
ln -s "`pwd`/lib/libring_opengl31.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl31.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl31.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl31.so" /usr/lib64
fi

if [ -f lib/libring_opengl32.dylib ];
then
ln -s "`pwd`/lib/libring_opengl32.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl32.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl32.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl32.so" /usr/lib64
fi

if [ -f lib/libring_opengl33.dylib ];
then
ln -s "`pwd`/lib/libring_opengl33.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl33.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl33.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl33.so" /usr/lib64
fi

if [ -f lib/libring_opengl40.dylib ];
then
ln -s "`pwd`/lib/libring_opengl40.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl40.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl40.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl40.so" /usr/lib64
fi

if [ -f lib/libring_opengl41.dylib ];
then
ln -s "`pwd`/lib/libring_opengl41.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl41.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl41.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl41.so" /usr/lib64
fi

if [ -f lib/libring_opengl42.dylib ];
then
ln -s "`pwd`/lib/libring_opengl42.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl42.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl42.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl42.so" /usr/lib64
fi

if [ -f lib/libring_opengl43.dylib ];
then
ln -s "`pwd`/lib/libring_opengl43.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl43.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl43.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl43.so" /usr/lib64
fi

if [ -f lib/libring_opengl44.dylib ];
then
ln -s "`pwd`/lib/libring_opengl44.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl44.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl44.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl44.so" /usr/lib64
fi

if [ -f lib/libring_opengl45.dylib ];
then
ln -s "`pwd`/lib/libring_opengl45.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl45.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl45.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl45.so" /usr/lib64
fi

if [ -f lib/libring_opengl46.dylib ];
then
ln -s "`pwd`/lib/libring_opengl46.dylib" /usr/local/lib
fi

if [ -f lib/libring_opengl46.so ];
then
sudo ln -s "`pwd`/lib/libring_opengl46.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_opengl46.so" /usr/lib64
fi

# Make the RingMurmurHash library ready for use directly

if [ -f lib/libring_murmurhash.dylib ];
then
ln -s "`pwd`/lib/libring_murmurhash.dylib" /usr/local/lib
fi

if [ -f lib/libring_murmurhash.so ];
then
sudo ln -s "`pwd`/lib/libring_murmurhash.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_murmurhash.so" /usr/lib64
fi

# Make the RingLibuv library ready for use directly

if [ -f lib/libring_uv.dylib ];
then
ln -s "`pwd`/lib/libring_uv.dylib" /usr/local/lib
fi

if [ -f lib/libring_uv.so ];
then
sudo ln -s "`pwd`/lib/libring_uv.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_uv.so" /usr/lib64
fi

# Make the RingPostgreSQL library ready for use directly

if [ -f lib/libring_pgsql.dylib ];
then
ln -s "`pwd`/lib/libring_pgsql.dylib" /usr/local/lib
fi

if [ -f lib/libring_pgsql.so ];
then
sudo ln -s "`pwd`/lib/libring_pgsql.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_pgsql.so" /usr/lib64
fi

# Make the RingConsoleColors library ready for use directly

if [ -f lib/libring_consolecolors.dylib ];
then
ln -s "`pwd`/lib/libring_consolecolors.dylib" /usr/local/lib
fi

if [ -f lib/libring_consolecolors.so ];
then
sudo ln -s "`pwd`/lib/libring_consolecolors.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_consolecolors.so" /usr/lib64
fi

# Make the RingLibSDL library ready for use directly

if [ -f lib/libringsdl.dylib ];
then
ln -s "`pwd`/lib/libringsdl.dylib" /usr/local/lib
fi

if [ -f lib/libringsdl.so ];
then
sudo ln -s "`pwd`/lib/libringsdl.so" /usr/lib
sudo ln -s "`pwd`/lib/libringsdl.so" /usr/lib64
fi

# Make the RingRayLib library ready for use directly

if [ -f lib/libringraylib.dylib ];
then
ln -s "`pwd`/lib/libringraylib.dylib" /usr/local/lib
cp extensions/ringraylib/src/macOS_raylib-2.5/lib/libraylib.* /usr/local/lib
fi

if [ -f lib/libringraylib.so ];
then
sudo ln -s "`pwd`/lib/libringraylib.so" /usr/lib
sudo ln -s "`pwd`/lib/libringraylib.so" /usr/lib64
sudo cp extensions/ringraylib/src/linux_raylib-2.5/lib/libraylib.so.* /usr/lib
sudo cp extensions/ringraylib/src/linux_raylib-2.5/lib/libraylib.so.* /usr/lib64
fi

# Make the RingSockets library ready for use directly

if [ -f lib/libring_sockets.dylib ];
then
ln -s "`pwd`/lib/libring_sockets.dylib" /usr/local/lib
fi

if [ -f lib/libring_sockets.so ];
then
sudo ln -s "`pwd`/lib/libring_sockets.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_sockets.so" /usr/lib64
fi

# Make the RingThreads library ready for use directly

if [ -f lib/libring_threads.dylib ];
then
ln -s "`pwd`/lib/libring_threads.dylib" /usr/local/lib
fi

if [ -f lib/libring_threads.so ];
then
sudo ln -s "`pwd`/lib/libring_threads.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_threads.so" /usr/lib64
fi

# Make the RingLibUI library ready for use directly

if [ -f lib/libring_libui.dylib ];
then
ln -s "`pwd`/lib/libring_libui.dylib" /usr/local/lib
cp extensions/ringlibui/macOS/libui.* /usr/local/lib
fi

if [ -f lib/libring_libui.so ];
then
sudo ln -s "`pwd`/lib/libring_libui.so" /usr/lib
sudo ln -s "`pwd`/lib/libring_libui.so" /usr/lib64
sudo cp extensions/ringlibui/linux/libui.so.* /usr/lib
sudo cp extensions/ringlibui/linux/libui.so.* /usr/lib
fi