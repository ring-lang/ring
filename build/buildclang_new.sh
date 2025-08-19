#!/bin/bash
set -e
cd ..

echo "Building Ring for macOS..."
echo "Building Ring Compiler/VM..."
cd language/build
sudo ./buildclang.sh > /dev/null
cd ../..

cd extensions

echo "Building Extensions..."
echo "Building RingAllegro..."
cd ringallegro
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingFreeGLUT..."
cd ../ringfreeglut
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingMurmurHash..."
cd ../ringmurmurhash
./buildclang.sh > /dev/null

echo "Building RingQt (Core)..."
cd ../ringqt
./gencode_core.sh > /dev/null
./buildclang_core.sh > /dev/null

echo "Building RingQt (LightGUILib)..."
./gencode_light.sh > /dev/null
./buildclang_light.sh > /dev/null

echo "Building RingQt (GUILib)..."
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingStbimage..."
cd ../ringstbimage
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingZip..."
cd ../ringzip
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingHTTPLib..."
cd ../ringhttplib
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingMySQL..."
cd ../ringmysql
./buildclang.sh > /dev/null

echo "Building RingRayLib..."
cd ../ringraylib5/src
./gencode.sh > /dev/null
./buildgccmac.sh > /dev/null

echo "Building RingThreads..."
cd ../../ringthreads
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingCJSON..."
cd ../ringcjson
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingInternet..."
cd ../ringinternet
./buildclang.sh > /dev/null

echo "Building RingODBC..."
cd ../ringodbc
./buildclang.sh > /dev/null

echo "Building RingRogueUtil..."
cd ../ringrogueutil
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingConsoleColors..."
cd ../ringconsolecolors
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingLibUI..."
cd ../ringlibui
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingOpenGL..."
cd ../ringopengl/opengl21
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingCurl..."
cd ../../ringcurl
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingLibuv..."
cd ../ringlibuv
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingOpenSSL..."
cd ../ringopenssl
./buildclang.sh > /dev/null

echo "Building RingSockets..."
cd ../ringsockets
./buildclang.sh > /dev/null

echo "Building RingPDFGen..."
cd ../ringpdfgen
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingFastPro..."
cd ../ringfastpro
./buildclang.sh > /dev/null

echo "Building RingPostgreSQL..."
cd ../ringpostgresql
./gencode.sh > /dev/null
./buildclang.sh > /dev/null

echo "Building RingSQLite..."
cd ../ringsqlite
./buildclang.sh > /dev/null

echo "Building Ring2EXE..."
cd ../../tools/ring2exe
./build.sh > /dev/null

echo "Building RingPM..."
cd ../ringpm
./build.sh > /dev/null

echo "Building RingREPL..."
cd ../ringrepl
./build.sh > /dev/null

echo "Building Folder2QRC..."
cd ../folder2qrc
./build.sh > /dev/null

echo "Installing Ring..."
cd ../../bin
./install.sh > /dev/null

echo "Building Ring Tests..."
cd ../language/tests
./build.sh > /dev/null