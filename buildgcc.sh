# This file still under development/test

# Build Ring Compiler/VM
cd language/build
sudo ./buildgcc.sh

# Build RingAllegro
cd ../../extensions/ringallegro
./gencode.sh
./buildgcc.sh

# Build RingFreeGLUT
cd ../ringfreeglut
./gencode.sh
./buildgcc.sh

# Build RingMurmurHash
cd ../ringmurmurhash
./buildgcc.sh

# Build RingQt
cd ../ringqt
./gencode_light.sh
./buildgcc_light.sh
./gencode.sh
./buildgcc.sh

# Build RingStbimage
cd ../ringstbimage
./gencode.sh
./buildgcc.sh

# Build RingZip
cd ../ringzip
./gencode.sh
./buildgcc.sh

# Build RingHTTPLib
cd ../ringhttplib
./gencode.sh
./buildgcc.sh

# Build RingMySQL
cd ../ringmysql
./buildgcc.sh

# Build RingRayLib
cd ../ringraylib/src
./gencode.sh
./buildgcc.sh

# Build RingThreads
cd ../../ringthreads
./gencode.sh
./buildgcc.sh

# Build RingCJSON
cd ../ringcjson
./gencode.sh
./buildgcc.sh

# Build RingInternet
cd ../ringinternet
./buildgcc.sh

# Build RingODBC
cd ../ringodbc
./buildgcc.sh

# Build RingRogueUtil
cd ../ringrogueutil
./gencode.sh
./buildgcc.sh

# Build RingConsoleColors
cd ../ringconsolecolors
./gencode.sh
./buildgcc.sh

# Build RingLibUI
cd ../ringlibui
./gencode.sh
./buildgcc.sh

# Build RingOpenGL
cd ../ringopengl/opengl21
./gencode.sh
./buildgcc.sh

# Build RingLibSDL
cd ../../ringsdl
./gencode.sh
./buildgcc.sh

# Build RingCurl
cd ../ringcurl
./gencode.sh
./buildgcc.sh

# Build RingLibuv
cd ../ringlibuv
./gencode.sh
./buildgcc.sh

# Build RingOpenSSL
cd ../ringopenssl
./buildgcc.sh

# Build RingSockets
cd ../ringsockets
./buildgcc.sh

# Build RingFastPro
cd ../ringfastpro
./buildgcc.sh

# Build RingPostgreSQL
cd ../ringpostgresql
./gencode.sh
./buildgcc.sh

# Build RingSQLite
cd ../ringsqlite
./buildgcc.sh

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


