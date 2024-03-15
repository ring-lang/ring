cd ..

# Build Ring Compiler/VM
cd language/build
sudo ./buildclang.sh

# Build RingAllegro
cd ../../extensions/ringallegro
./gencode.sh
./buildclang.sh

# Build RingFreeGLUT
cd ../ringfreeglut
./gencode.sh
./buildclang.sh

# Build RingMurmurHash
cd ../ringmurmurhash
./buildclang.sh

# Build RingQt
cd ../ringqt
./gencode_light.sh
./buildclang_light.sh
./gencode.sh
./buildclang.sh

# Build RingStbimage
cd ../ringstbimage
./gencode.sh
./buildclang.sh

# Build RingZip
cd ../ringzip
./gencode.sh
./buildclang.sh

# Build RingHTTPLib
cd ../ringhttplib
./gencode.sh
./buildclang.sh

# Build RingMySQL
cd ../ringmysql
./buildclang.sh

# Build RingRayLib
cd ../ringraylib/src
./gencode.sh
./buildgccmac.sh

# Build RingThreads
cd ../../ringthreads
./gencode.sh
./buildclang.sh

# Build RingCJSON
cd ../ringcjson
./gencode.sh
./buildclang.sh

# Build RingInternet
cd ../ringinternet
./buildclang.sh

# Build RingODBC
cd ../ringodbc
./buildclang.sh

# Build RingRogueUtil
cd ../ringrogueutil
./gencode.sh
./buildclang.sh

# Build RingConsoleColors
cd ../ringconsolecolors
./gencode.sh
./buildclang.sh

# Build RingLibUI
cd ../ringlibui
./gencode.sh
./buildclang.sh

# Build RingOpenGL
cd ../ringopengl/opengl21
./gencode.sh
./buildclang.sh

# Build RingCurl
cd ../../ringcurl
./gencode.sh
./buildclang.sh

# Build RingLibuv
cd ../ringlibuv
./gencode.sh
./buildclang.sh

# Build RingOpenSSL
cd ../ringopenssl
./buildclang.sh

# Build RingSockets
cd ../ringsockets
./buildclang.sh

# Build RingFastPro
cd ../ringfastpro
./buildclang.sh

# Build RingPostgreSQL
cd ../ringpostgresql
./gencode.sh
./buildclang.sh

# Build RingSQLite
cd ../ringsqlite
./buildclang.sh

# Build Ring2EXE
cd ../../tools/ring2exe
./build.sh

# Build RingPM
cd ../ringpm
./build.sh

# Build RingREPL
cd ../ringrepl
./build.sh

# Build Folder2QRC
cd ../folder2qrc
./build.sh

# Install
cd ../../bin
./install.sh

cd ../language/tests
./build.sh

