#!/bin/bash
set -e
cd ..

echo "Building Ring for macOS..."
echo "Building Ring Compiler/VM..."
cd language/build
sudo ./buildclang.sh > /dev/null 2>&1
cd ../..

cd extensions

echo "Building Extensions..."
echo "Building RingAllegro..."
cd ringallegro
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingFreeGLUT..."
cd ../ringfreeglut
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingMurmurHash..."
cd ../ringmurmurhash
./buildclang.sh > /dev/null 2>&1

echo "Building RingQt (Core)..."
cd ../ringqt
./gencode_core.sh > /dev/null 2>&1
./buildclang_core.sh > /dev/null 2>&1

echo "Building RingQt (LightGUILib)..."
./gencode_light.sh > /dev/null 2>&1
./buildclang_light.sh > /dev/null 2>&1

echo "Building RingQt (GUILib)..."
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingStbimage..."
cd ../ringstbimage
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingZip..."
cd ../ringzip
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingHTTPLib..."
cd ../ringhttplib
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingMySQL..."
cd ../ringmysql
./buildclang.sh > /dev/null 2>&1

echo "Building RingRayLib..."
cd ../ringraylib5/src
./gencode.sh > /dev/null 2>&1
./buildgccmac.sh > /dev/null 2>&1

echo "Building RingThreads..."
cd ../../ringthreads
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingCJSON..."
cd ../ringcjson
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingInternet..."
cd ../ringinternet
./buildclang.sh > /dev/null 2>&1

echo "Building RingODBC..."
cd ../ringodbc
./buildclang.sh > /dev/null 2>&1

echo "Building RingRogueUtil..."
cd ../ringrogueutil
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingConsoleColors..."
cd ../ringconsolecolors
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingLibUI..."
cd ../ringlibui
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingOpenGL..."
cd ../ringopengl/opengl21
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingCurl..."
cd ../../ringcurl
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingLibuv..."
cd ../ringlibuv
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingOpenSSL..."
cd ../ringopenssl
./buildclang.sh > /dev/null 2>&1

echo "Building RingSockets..."
cd ../ringsockets
./buildclang.sh > /dev/null 2>&1

echo "Building RingPDFGen..."
cd ../ringpdfgen
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingFastPro..."
cd ../ringfastpro
./buildclang.sh > /dev/null 2>&1

echo "Building RingPostgreSQL..."
cd ../ringpostgresql
./gencode.sh > /dev/null 2>&1
./buildclang.sh > /dev/null 2>&1

echo "Building RingSQLite..."
cd ../ringsqlite
./buildclang.sh > /dev/null 2>&1

echo "Building Ring2EXE..."
cd ../../tools/ring2exe
./build.sh > /dev/null 2>&1

echo "Building RingPM..."
cd ../ringpm
./build.sh > /dev/null 2>&1

echo "Building RingREPL..."
cd ../ringrepl
./build.sh > /dev/null 2>&1

echo "Building Folder2QRC..."
cd ../folder2qrc
./build.sh > /dev/null 2>&1

echo "Installing Ring..."
cd ../../bin
./install.sh > /dev/null 2>&1

echo "Building Ring Tests..."
cd ../language/tests
./build.sh > /dev/null 2>&1