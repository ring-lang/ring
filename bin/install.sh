# Simple Script to copy ring binary file and libraries to the system
# 2016-2017, Mahmoud Fayed <msfclipper@yahoo.com>

# To be able to call ring from any folder 

if [ -f lib/libring.dylib ];
then
echo "`pwd`/ring \$1" > /usr/local/bin/ring
chmod +x /usr/local/bin/ring

cd ..

cp lib/libring.dylib /usr/local/lib
fi

if [ -f lib/libring.so ];
then
echo ".`pwd`/ring \$1" > /usr/local/bin/ring
chmod +x /usr/local/bin/ring

cd ..
cp lib/libring.so /usr/local/lib
fi
	
# Make the RingODBC library ready for use directly

if [ -f lib/libring_odbclib.dylib ];
then
cp lib/libring_odbclib.dylib /usr/local/lib
fi

if [ -f lib/libring_odbclib.so ];
then
cp lib/libring_odbclib.so /usr/local/lib
fi

# Make the RingMySQL library ready for use directly

if [ -f lib/libring_mysqllib.dylib ];
then
cp lib/libring_mysqllib.dylib /usr/local/lib
fi

if [ -f lib/libring_mysqllib.so ];
then
cp lib/libring_mysqllib.so /usr/local/lib
fi

# Make the RingSQLite library ready for use directly

if [ -f lib/libring_sqlitelib.dylib ];
then
cp lib/libring_sqlitelib.dylib /usr/local/lib
fi

if [ -f lib/libring_sqlitelib.so ];
then
cp lib/libring_sqlitelib.so /usr/local/lib
fi

# Make the RingInternet library ready for use directly

if [ -f lib/libring_internetlib.dylib ];
then
cp lib/libring_internetlib.dylib /usr/local/lib
fi

if [ -f lib/libring_internetlib.so ];
then
cp lib/libring_internetlib.so /usr/local/lib
fi

# Make the RingOpenSSL library ready for use directly

if [ -f lib/libring_openssllib.dylib ];
then
cp lib/libring_openssllib.dylib /usr/local/lib
fi

if [ -f lib/libring_openssllib.so ];
then
cp lib/libring_openssllib.so /usr/local/lib
fi

# Make the RingAllegro library ready for use directly
	
if [ -f lib/libringallegro.dylib ];
then
cp lib/libringallegro.dylib /usr/local/lib
fi

if [ -f lib/libringallegro.so ];
then
cp lib/libringallegro.so /usr/local/lib
fi

# Make the RingQt library ready for use directly
	
if [ -f lib/libringqt.dylib ];
then
cp lib/libringqt.dylib /usr/local/lib
fi

if [ -f lib/libringqt.so ];
then
cp lib/libringqt.so /usr/local/lib
fi

# Make the RingLibCurl library ready for use directly

if [ -f lib/libring_libcurl.dylib ];
then
cp lib/libring_libcurl.dylib /usr/local/lib
fi

if [ -f lib/libring_libcurl.so ];
then
cp lib/libring_libcurl.so /usr/local/lib
fi

# Make the RingZipLib library ready for use directly

if [ -f lib/libring_ziplib.dylib ];
then
cp lib/libring_ziplib.dylib /usr/local/lib
fi

if [ -f lib/libring_ziplib.so ];
then
cp lib/libring_ziplib.so /usr/local/lib
fi

