# Simple Script to copy ring binary file and libraries to the system
# 2016-2017, Mahmoud Fayed <msfclipper@yahoo.com>

# To be able to call ring from any folder 

if [ -f ../lib/libring.dylib ];
then
echo "`pwd`/ring \$1" > /usr/local/bin/ring
chmod +x /usr/local/bin/ring

cd ..

cp lib/libring.dylib /usr/local/lib
fi

if [ -f ../lib/libring.so ];
then
sudo echo "`pwd`/ring \${1:-foo}" > /usr/bin/ring 
sudo chmod +x /usr/bin/ring

cd ..
sudo cp lib/libring.so /usr/lib
fi
	
# Make the RingODBC library ready for use directly

if [ -f lib/libring_odbc.dylib ];
then
cp lib/libring_odbc.dylib /usr/local/lib
fi

if [ -f lib/libring_odbc.so ];
then
sudo cp lib/libring_odbc.so /usr/lib
fi

# Make the RingMySQL library ready for use directly

if [ -f lib/libring_mysql.dylib ];
then
cp lib/libring_mysql.dylib /usr/local/lib
fi

if [ -f lib/libring_mysql.so ];
then
sudo cp lib/libring_mysql.so /usr/lib
fi

# Make the RingSQLite library ready for use directly

if [ -f lib/libring_sqlite.dylib ];
then
cp lib/libring_sqlite.dylib /usr/local/lib
fi

if [ -f lib/libring_sqlite.so ];
then
sudo cp lib/libring_sqlite.so /usr/lib
fi

# Make the RingInternet library ready for use directly

if [ -f lib/libring_internet.dylib ];
then
cp lib/libring_internet.dylib /usr/local/lib
fi

if [ -f lib/libring_internet.so ];
then
sudo cp lib/libring_internet.so /usr/lib
fi

# Make the RingOpenSSL library ready for use directly

if [ -f lib/libring_openssl.dylib ];
then
cp lib/libring_openssl.dylib /usr/local/lib
fi

if [ -f lib/libring_openssl.so ];
then
sudo cp lib/libring_openssl.so /usr/lib
fi

# Make the RingAllegro library ready for use directly
	
if [ -f lib/libringallegro.dylib ];
then
cp lib/libringallegro.dylib /usr/local/lib
fi

if [ -f lib/libringallegro.so ];
then
sudo cp lib/libringallegro.so /usr/lib
fi

# Make the RingQt library ready for use directly
	
if [ -f lib/libringqt.dylib ];
then
cp lib/libringqt.dylib /usr/local/lib
fi

if [ -f lib/libringqt.so ];
then
sudo cp lib/libringqt.so /usr/lib
fi

# Make the RingLibCurl library ready for use directly

if [ -f lib/libring_libcurl.dylib ];
then
cp lib/libring_libcurl.dylib /usr/local/lib
fi

if [ -f lib/libring_libcurl.so ];
then
sudo cp lib/libring_libcurl.so /usr/lib
fi

# Make the RingZipLib library ready for use directly

if [ -f lib/libring_libzip.dylib ];
then
cp lib/libring_libzip.dylib /usr/lib
fi

if [ -f lib/libring_libzip.so ];
then
sudo cp lib/libring_libzip.so /usr/lib
fi

# Make the RingFreeGLUT library ready for use directly

if [ -f lib/libring_freeglut.dylib ];
then
cp lib/libring_freeglut.dylib /usr/lib
fi

if [ -f lib/libring_freeglut.so ];
then
sudo cp lib/libring_freeglut.so /usr/lib
fi

# Make the RingOpenGL library ready for use directly

if [ -f lib/libring_opengl21.dylib ];
then
cp lib/libring_opengl21.dylib /usr/lib
fi

if [ -f lib/libring_opengl21.so ];
then
sudo cp lib/libring_opengl21.so /usr/lib
fi
