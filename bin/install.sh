# Simple Script to copy ring binary file and libraries to the system
# 2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>

# To be able to call ring from any folder 

if [ -f ../lib/libring.dylib ];
then
echo "`pwd`/ring \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/local/bin/ring
chmod +x /usr/local/bin/ring

echo "`pwd`/../ring2exe/ring2exe \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/local/bin/ring2exe
chmod +x /usr/local/bin/ring2exe

echo "`pwd`/../ring2exe/folder2qrc \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/local/bin/folder2qrc
chmod +x /usr/local/bin/folder2qrc

echo "`pwd`/../ringpm/ringpm \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/local/bin/ringpm
chmod +x /usr/local/bin/ringpm

cd ..

cp lib/libring.dylib /usr/local/lib
fi

if [ -f ../lib/libring.so ];
then
sudo echo "`pwd`/ring \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/bin/ring 
sudo chmod +x /usr/bin/ring

echo "`pwd`/../ring2exe/ring2exe \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/bin/ring2exe
chmod +x /usr/bin/ring2exe

echo "`pwd`/../ring2exe/folder2qrc \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/bin/folder2qrc
chmod +x /usr/bin/folder2qrc

sudo echo "`pwd`/../ringpm/ringpm \$1 \$2 \$3 \$4 \$5 \$6 \$7" > /usr/bin/ringpm 
sudo chmod +x /usr/bin/ringpm

cd ..
sudo cp lib/libring.so /usr/lib
sudo cp lib/libring.so /usr/lib64
fi
	
# Make the RingODBC library ready for use directly

if [ -f lib/libring_odbc.dylib ];
then
cp lib/libring_odbc.dylib /usr/local/lib
fi

if [ -f lib/libring_odbc.so ];
then
sudo cp lib/libring_odbc.so /usr/lib
sudo cp lib/libring_odbc.so /usr/lib64
fi

# Make the RingMySQL library ready for use directly

if [ -f lib/libring_mysql.dylib ];
then
cp lib/libring_mysql.dylib /usr/local/lib
fi

if [ -f lib/libring_mysql.so ];
then
sudo cp lib/libring_mysql.so /usr/lib
sudo cp lib/libring_mysql.so /usr/lib64
fi

# Make the RingSQLite library ready for use directly

if [ -f lib/libring_sqlite.dylib ];
then
cp lib/libring_sqlite.dylib /usr/local/lib
fi

if [ -f lib/libring_sqlite.so ];
then
sudo cp lib/libring_sqlite.so /usr/lib
sudo cp lib/libring_sqlite.so /usr/lib64
fi

# Make the RingInternet library ready for use directly

if [ -f lib/libring_internet.dylib ];
then
cp lib/libring_internet.dylib /usr/local/lib
fi

if [ -f lib/libring_internet.so ];
then
sudo cp lib/libring_internet.so /usr/lib
sudo cp lib/libring_internet.so /usr/lib64
fi

# Make the RingOpenSSL library ready for use directly

if [ -f lib/libring_openssl.dylib ];
then
cp lib/libring_openssl.dylib /usr/local/lib
fi

if [ -f lib/libring_openssl.so ];
then
sudo cp lib/libring_openssl.so /usr/lib
sudo cp lib/libring_openssl.so /usr/lib64
fi

# Make the RingAllegro library ready for use directly
	
if [ -f lib/libringallegro.dylib ];
then
cp lib/libringallegro.dylib /usr/local/lib
fi

if [ -f lib/libringallegro.so ];
then
sudo cp lib/libringallegro.so /usr/lib
sudo cp lib/libringallegro.so /usr/lib64
fi

# Make the RingQt library ready for use directly
	
if [ -f lib/libringqt.dylib ];
then
cp lib/libringqt.dylib /usr/local/lib
fi

if [ -f lib/libringqt.so ];
then
sudo cp lib/libringqt.so /usr/lib
sudo cp lib/libringqt.so /usr/lib64
fi

# Make the RingLibCurl library ready for use directly

if [ -f lib/libring_libcurl.dylib ];
then
cp lib/libring_libcurl.dylib /usr/local/lib
fi

if [ -f lib/libring_libcurl.so ];
then
sudo cp lib/libring_libcurl.so /usr/lib
sudo cp lib/libring_libcurl.so /usr/lib64
fi

# Make the RingZipLib library ready for use directly

if [ -f lib/libring_libzip.dylib ];
then
cp lib/libring_libzip.dylib /usr/local/lib
fi

if [ -f lib/libring_libzip.so ];
then
sudo cp lib/libring_libzip.so /usr/lib
sudo cp lib/libring_libzip.so /usr/lib64
fi

# Make the RingFreeGLUT library ready for use directly

if [ -f lib/libring_freeglut.dylib ];
then
cp lib/libring_freeglut.dylib /usr/local/lib
fi

if [ -f lib/libring_freeglut.so ];
then
sudo cp lib/libring_freeglut.so /usr/lib
sudo cp lib/libring_freeglut.so /usr/lib64
fi

# Make the RingOpenGL library ready for use directly

if [ -f lib/libring_opengl11.dylib ];
then
cp lib/libring_opengl11.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl11.so ];
then
sudo cp lib/libring_opengl11.so /usr/lib
sudo cp lib/libring_opengl11.so /usr/lib64
fi


if [ -f lib/libring_opengl12.dylib ];
then
cp lib/libring_opengl12.dylib /usr/lib
fi

if [ -f lib/libring_opengl12.so ];
then
sudo cp lib/libring_opengl12.so /usr/lib
sudo cp lib/libring_opengl12.so /usr/lib64
fi

if [ -f lib/libring_opengl13.dylib ];
then
cp lib/libring_opengl13.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl13.so ];
then
sudo cp lib/libring_opengl13.so /usr/lib
sudo cp lib/libring_opengl13.so /usr/lib64
fi

if [ -f lib/libring_opengl14.dylib ];
then
cp lib/libring_opengl14.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl14.so ];
then
sudo cp lib/libring_opengl14.so /usr/lib
sudo cp lib/libring_opengl14.so /usr/lib64
fi

if [ -f lib/libring_opengl15.dylib ];
then
cp lib/libring_opengl15.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl15.so ];
then
sudo cp lib/libring_opengl15.so /usr/lib
sudo cp lib/libring_opengl15.so /usr/lib64
fi

if [ -f lib/libring_opengl20.dylib ];
then
cp lib/libring_opengl20.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl20.so ];
then
sudo cp lib/libring_opengl20.so /usr/lib
sudo cp lib/libring_opengl20.so /usr/lib64
fi

if [ -f lib/libring_opengl21.dylib ];
then
cp lib/libring_opengl21.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl21.so ];
then
sudo cp lib/libring_opengl21.so /usr/lib
sudo cp lib/libring_opengl21.so /usr/lib64
fi

if [ -f lib/libring_opengl30.dylib ];
then
cp lib/libring_opengl30.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl30.so ];
then
sudo cp lib/libring_opengl30.so /usr/lib
sudo cp lib/libring_opengl30.so /usr/lib64
fi

if [ -f lib/libring_opengl31.dylib ];
then
cp lib/libring_opengl31.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl31.so ];
then
sudo cp lib/libring_opengl31.so /usr/lib
sudo cp lib/libring_opengl31.so /usr/lib64
fi

if [ -f lib/libring_opengl32.dylib ];
then
cp lib/libring_opengl32.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl32.so ];
then
sudo cp lib/libring_opengl32.so /usr/lib
sudo cp lib/libring_opengl32.so /usr/lib64
fi

if [ -f lib/libring_opengl33.dylib ];
then
cp lib/libring_opengl33.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl33.so ];
then
sudo cp lib/libring_opengl33.so /usr/lib
sudo cp lib/libring_opengl33.so /usr/lib64
fi

if [ -f lib/libring_opengl40.dylib ];
then
cp lib/libring_opengl40.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl40.so ];
then
sudo cp lib/libring_opengl40.so /usr/lib
sudo cp lib/libring_opengl40.so /usr/lib64
fi

if [ -f lib/libring_opengl41.dylib ];
then
cp lib/libring_opengl41.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl41.so ];
then
sudo cp lib/libring_opengl41.so /usr/lib
sudo cp lib/libring_opengl41.so /usr/lib64
fi

if [ -f lib/libring_opengl42.dylib ];
then
cp lib/libring_opengl42.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl42.so ];
then
sudo cp lib/libring_opengl42.so /usr/lib
sudo cp lib/libring_opengl42.so /usr/lib64
fi

if [ -f lib/libring_opengl43.dylib ];
then
cp lib/libring_opengl43.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl43.so ];
then
sudo cp lib/libring_opengl43.so /usr/lib
sudo cp lib/libring_opengl43.so /usr/lib64
fi

if [ -f lib/libring_opengl44.dylib ];
then
cp lib/libring_opengl44.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl44.so ];
then
sudo cp lib/libring_opengl44.so /usr/lib
sudo cp lib/libring_opengl44.so /usr/lib64
fi

if [ -f lib/libring_opengl45.dylib ];
then
cp lib/libring_opengl45.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl45.so ];
then
sudo cp lib/libring_opengl45.so /usr/lib
sudo cp lib/libring_opengl45.so /usr/lib64
fi

if [ -f lib/libring_opengl46.dylib ];
then
cp lib/libring_opengl46.dylib /usr/local/lib
fi

if [ -f lib/libring_opengl46.so ];
then
sudo cp lib/libring_opengl46.so /usr/lib
sudo cp lib/libring_opengl46.so /usr/lib64
fi

# Make the RingMurmurHash library ready for use directly

if [ -f lib/libring_murmurhash.dylib ];
then
cp lib/libring_murmurhash.dylib /usr/local/lib
fi

if [ -f lib/libring_murmurhash.so ];
then
sudo cp lib/libring_murmurhash.so /usr/lib
sudo cp lib/libring_murmurhash.so /usr/lib64
fi

# Make the RingLibuv library ready for use directly

if [ -f lib/libring_uv.dylib ];
then
cp lib/libring_uv.dylib /usr/local/lib
fi

if [ -f lib/libring_uv.so ];
then
sudo cp lib/libring_uv.so /usr/lib
sudo cp lib/libring_uv.so /usr/lib64
fi

# Make the RingPostgreSQL library ready for use directly

if [ -f lib/libring_pgsql.dylib ];
then
cp lib/libring_pgsql.dylib /usr/local/lib
fi

if [ -f lib/libring_pgsql.so ];
then
sudo cp lib/libring_pgsql.so /usr/lib
sudo cp lib/libring_pgsql.so /usr/lib64
fi

# Make the RingConsoleColors library ready for use directly

if [ -f lib/libring_consolecolors.dylib ];
then
cp lib/libring_consolecolors.dylib /usr/local/lib
fi

if [ -f lib/libring_consolecolors.so ];
then
sudo cp lib/libring_consolecolors.so /usr/lib
sudo cp lib/libring_consolecolors.so /usr/lib64
fi