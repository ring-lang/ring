![Ring](http://ring-lang.sf.net/thering.jpg)

# Ring Programming Language

## Building using Ubuntu Linux 

This version is tested using Ubuntu 22.04 LTS

### Install Git

	sudo apt-get install git

### Upgrade the packages 

	sudo apt-get update && sudo apt-get upgrade

### Get the source code

	git clone https://github.com/ring-lang/ring.git
	
### Install Libraries 
	
	cd ring/language/src
	./installdep.sh 
	
### Build Ring (Compiler/VM)
	
	sudo ./buildgcc.sh

### Build Ring2EXE 

	cd ring/tools/ring2exe
	sudo ./build.sh	

### Generate RingConsoleColors Source Code and Build 
	
	cd ring/extensions/ringconsolecolors
	./gencode.sh
	./buildgcc.sh

### Build RingInternet
	
	cd ring/extensions/ringinternet
	./buildgcc.sh

### Generate RingLibCurl Source Code and Build 
	
	cd ring/extensions/ringcurl
	./gencode.sh
	./buildgcc.sh

### Generate RingZip Source Code and Build 
	
	cd ring/extensions/ringzip
	./gencode.sh
	./buildgcc.sh

### Build RingPM

	cd ring/tools/ringpm
	sudo ./build.sh	
	
### Build RingODBC
	
	cd ring/extensions/ringodbc
	./buildgcc.sh

### Build RingMySQL
	
	cd ring/extensions/ringmysql
	./buildgcc.sh

### Build RingSQLite
	
	cd ring/extensions/ringsqlite
	./buildgcc.sh

### Generate RingPostgreSQL Source Code and Build 
	
	cd ring/extensions/ringpostgresql
	./gencode.sh
	./buildgcc.sh

### Build RingOpenSSL
	
	cd ring/extensions/ringopenssl
	./buildgcc.sh

### Build RingMurmurHash
	
	cd ring/extensions/ringmurmurhash
	./buildgcc.sh		
	
### Generate RingAllegro Source Code and Build 
	
	cd ring/extensions/ringallegro
	./gencode.sh
	./buildgcc.sh
	
### Generate RingLibuv Source Code and Build 

We will build Libuv first

	cd ring/extensions/ringlibuv/libuv
	sudo apt-get install libtool m4 automake
	sh autogen.sh
	./configure
	make
	make check
	sudo make install

Then we will build RingLibuv
	
	cd ring/extensions/ringlibuv
	./gencode.sh
	./buildgcc.sh

### Generate RingFreeGLUT Source Code and Build 
	
	cd ring/extensions/ringfreeglut
	./gencode.sh
	./buildgcc.sh

### Generate RingOpenGL Source Code and Build 

The ringopengl folder contains many sub folders for different OpenGL versions
Starting from OpenGL 1.1 to OpenGL 4.6
	
	cd ring/extensions/ringopengl/opengl21
	./gencode.sh
	./buildgcc.sh

### Generate RingQt Source Code and Build
	
	cd ring/extensions/ringqt
	./gencode.sh
	./buildgcc.sh

### To be able to call ring from any folder 
	cd ring/bin
	sudo ./install.sh
	
### Run Ring Notepad
	
	cd ring/tools/ringnotepad
	sudo ring rnote.ring

