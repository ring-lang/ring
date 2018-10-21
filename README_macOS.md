![Ring](http://ring-lang.sf.net/thering.jpg)

# Ring Programming Language

## Building using macOS

### Get the source code

	git clone http://github.com/ring-lang/ring.git
	
### Install homebrew (follow the directions on [homebrew's homepage](http://brew.sh/)).
	
### Install Libraries 
	
	cd ring/src
	./installdepmac.sh 
	
### Build Ring (Compiler/VM)
	
	./buildclang.sh

### Build Ring2EXE 

	cd ../ring2exe
	sudo ./buildring2exe.sh	
	
### Build RingODBC
	
	cd ../extensions/ringodbc
	./buildclang.sh

### Build RingMySQL
	
	cd ../extensions/ringmysql
	./buildclang.sh

### Build RingSQLite
	
	cd ../extensions/ringsqlite
	./buildclang.sh

### Generate RingPostgreSQL Source Code and Build 
	
	cd ../extensions/ringpostgresql
	./gencode.sh
	./buildclang.sh

### Build RingOpenSSL
	
	cd ../extensions/ringopenssl
	./buildclang.sh

### Build RingInternet
	
	cd ../extensions/ringinternet
	./buildclang.sh
	
### Build RingMurmurHash
	
	cd ../extensions/ringmurmurhash
	./buildclang.sh
	
### Generate RingConsoleColors Source Code and Build 
	
	cd ../extensions/ringconsolecolors
	./gencode.sh
	./buildclang.sh


### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
	./gencode.sh
	./buildclang.sh

### Generate RingLibCurl Source Code and Build 
	
	cd ../extensions/ringcurl
	./gencode.sh
	./buildclang.sh
	
### Generate RingZip Source Code and Build 
	
	cd ../extensions/ringzip
	./gencode.sh
	./buildclang.sh

### Generate RingLibuv Source Code and Build 
	
	cd ../extensions/ringlibuv
	./gencode.sh
	./buildclang.sh

### Generate RingFreeGLUT Source Code and Build 
	
	cd ../extensions/ringfreeglut
	./gencode.sh
	./buildclang.sh

### Generate RingOpenGL Source Code and Build 

The ringopengl folder contains many sub folders for different OpenGL versions
Starting from OpenGL 1.1 to OpenGL 4.6
	
	cd ../extensions/ringopengl/opengl21
	./gencode.sh
	./buildclang.sh
	
### Generate RingQt Source Code and Build
	
	cd ../extensions/ringqt
	./gencodemac.sh
	./buildclang.sh

### To be able to call ring from any folder 
	cd ../../bin
	sudo ./install.sh
	
### Run Ring Notepad
	
	cd applications/rnote
	ring rnote.ring