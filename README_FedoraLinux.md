![Ring](http://ring-lang.sf.net/thering.jpg)

# Ring Programming Language


## Building using Fedora Linux 

### Get the source code

	git clone http://github.com/ring-lang/ring.git
	
### Install Libraries 
	
	cd ring/src
	./installdepfedora.sh 
	
### Build Ring (Compiler/VM)
	
	sudo ./buildgcc.sh

### Build Ring2EXE 

	cd ../ring2exe
	sudo ./buildring2exe.sh		

### Generate RingConsoleColors Source Code and Build 
	
	cd ../extensions/ringconsolecolors
	./gencode.sh
	./buildgcc.sh

### Build RingInternet
	
	cd ../extensions/ringinternet
	./buildgcc.sh

### Generate RingLibCurl Source Code and Build 
	
	cd ../extensions/ringcurl
	./gencode.sh
	./buildgcc.sh

### Generate RingZip Source Code and Build 
	
	cd ../extensions/ringzip
	./gencode.sh
	./buildgcc.sh
	
### Build RingPM 

	cd ../ringpm
	sudo ./buildringpm.sh	

### Build RingODBC
	
	cd ../extensions/ringodbc
	./buildgcc.sh

### Build RingMySQL
	
	cd ../extensions/ringmysql
	./buildgccfedora.sh

### Build RingSQLite
	
	cd ../extensions/ringsqlite
	./buildgcc.sh

### Generate RingPostgreSQL Source Code and Build 
	
	cd ../extensions/ringpostgresql
	./gencode.sh
	./buildgcc.sh

### Build RingOpenSSL
	
	cd ../extensions/ringopenssl
	./buildgcc.sh

### Build RingMurmurHash
	
	cd ../extensions/ringmurmurhash
	./buildgcc.sh	
	

### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
	./gencode.sh
	./buildgcc.sh
	
### Generate RingLibuv Source Code and Build 

We will build Libuv first

	cd ../extensions/ringlibuv/libuv
	sudo dnf install libtool m4 autoconf automake
	sh autogen.sh
	./configure
	make
	make check
	sudo make install

Then we will build RingLibuv
	
	cd ..
	./gencode.sh
	./buildgcc.sh

### Generate RingFreeGLUT Source Code and Build 
	
	cd ../extensions/ringfreeglut
	./gencode.sh
	./buildgcc.sh

### Generate RingOpenGL Source Code and Build 

The ringopengl folder contains many sub folders for different OpenGL versions
Starting from OpenGL 1.1 to OpenGL 4.6
	
	cd ../extensions/ringopengl/opengl21
	./gencode.sh
	./buildgcc.sh

### Generate RingQt Source Code and Build
	
	cd ../extensions/ringqt
	./gencode.sh
	./buildgccfedora.sh

### To be able to call ring from any folder 
	cd ../../bin
	sudo ./install.sh
	
### Run Ring Notepad
	
	cd applications/rnote
	sudo ring rnote.ring
