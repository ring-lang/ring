![Ring](http://ring-lang.sf.net/thering.jpg)

# Ring Programming Language

## Innovative and practical general-purpose multi-paradigm language

| |*Resources*|*Operating System*|*Status*|
|---|---|---|---|             																															 
|Download |[![Download](http://ring-lang.sf.net/binaryrelease.svg)](http://ring-lang.sf.net/download.html)|**macOS (Compiler: gcc C)**      |[![Build Status](https://travis-ci.org/ring-lang/ring.png)](https://travis-ci.org/ring-lang/ring)|   
|Help |[![Help](http://ring-lang.sf.net/documentation.svg)](http://ring-lang.sf.net/doc1.8/index.html)|**Ubuntu Linux (Compiler: gcc C)** |[![Build Status](https://travis-ci.org/ring-lang/ring.png)](https://travis-ci.org/ring-lang/ring)|                  
|Try |[![Try](http://ring-lang.sf.net/interactive%20ring-use%20online-green.svg)](http://ring-lang.sf.net/cgi-bin/ringlang.cgi)|**macOS (Compiler: clang C)**      |[![Build Status](https://travis-ci.org/ring-lang/ring.png)](https://travis-ci.org/ring-lang/ring)|   
|Support |[![Support](http://ring-lang.sf.net/group-ask%20questions-yellowgreen.svg)](https://groups.google.com/forum/#!forum/ring-lang)|**Ubuntu Linux (Compiler: clang C)** |[![Build Status](https://travis-ci.org/ring-lang/ring.png)](https://travis-ci.org/ring-lang/ring)|                  

# Description

The Ring is an Innovative and practical general-purpose multi-paradigm language.
The supported programming paradigms are Imperative, Procedural, Object-Oriented, Functional,
Meta programming, Declarative programming using nested structures, and Natural programming.
The language is portable (Windows, Linux, macOS, Android, etc.) and can be used to create
Console, GUI, Web, Games and Mobile applications. 
The language is designed to be Simple, Small, Flexible and Fast. [Read more!](http://ring-lang.sf.net/#why)

![Ring](http://ring-lang.sf.net/newringshots.gif)

# Building from source code

You can build Ring using CMake or using Scripts (Batch Files or Shell Scripts).

The next steps explains building using scripts.

We provide instructions for building on the next platforms :-

(1) Microsoft Windows 

(2) Ubuntu Linux

(3) Fedora Linux

(4) macOS

## Building using Microsoft Windows 

### Get the source code

	git clone http://github.com/ring-lang/ring.git
	
### Build Ring (Compiler/VM)
	
	cd ring/src
	buildvc.bat
	buildvcw.bat

### Build Ring2EXE 

	cd ../ring2exe
	buildring2exe.bat 
	
### Build RingODBC
	
	cd ../extensions/ringodbc
	buildvc.bat

### Build RingMySQL
	
	cd ../extensions/ringmysql
	buildvc.bat

### Build RingSQLite
	
	cd ../extensions/ringsqlite
	buildvc.bat

### Build RingPostgreSQL
	
	cd ../extensions/ringpostgresql
	gencode.bat
	buildvc.bat

### Build RingOpenSSL
	
	cd ../extensions/ringopenssl
	buildvc.bat

### Build RingInternet
	
	cd ../extensions/ringinternet
	buildvc.bat

### Build RingMurmurHash
	
	cd ../extensions/ringmurmurhash
	buildvc.bat
	
### Generate RingConsoleColors Source Code and Build 
	
	cd ../extensions/ringconsolecolors
	gencode.bat
	buildvc.bat
	
### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
	gencode.bat
	buildvc.bat

### Generate RingLibCurl Source Code and Build 
	
	cd ../extensions/ringcurl
	gencode.bat
	buildvc.bat
	
### Generate RingZip Source Code and Build 
	
	cd ../extensions/ringzip
	gencode.bat
	buildvc.bat

### Generate RingLibuv Source Code and Build 
	
	cd ../extensions/ringlibuv
	gencode.bat
	buildvc.bat

### Generate RingFreeGLUT Source Code and Build 
	
	cd ../extensions/ringfreeglut
	gencode.bat
	buildvc.bat

### Generate RingOpenGL Source Code and Build 

The ringopengl folder contains many sub folders for different OpenGL versions
Starting from OpenGL 1.1 to OpenGL 4.6
	
	cd ../extensions/ringopengl/opengl21
	gencode.bat
	buildvc.bat
	
### Generate RingQt Source Code and Build

	Install Qt 5.5 : https://download.qt.io/archive/qt/5.5/5.5.1/
	
	cd ../extensions/ringqt
	gencode.bat
	buildmingw32.bat

### To be able to call ring from any folder 
	
	cd ../../bin
	install.bat
	
#### Add Ring/bin to System path

	Hit "windows key".
	Type "Edit the System environment variables"
	Select "Advanced" tab.
	Click on "Enviroment Variables..."
	Double click on "Path"
	Add at the end the new path separated by semicolon. 
		;C:\Ring\Bin
	
### Run Ring Notepad
	
	cd applications/rnote
	ring rnote.ring

## Building using Ubuntu Linux 

### Get the source code

	git clone http://github.com/ring-lang/ring.git
	
### Install Libraries 
	
	cd ring/src
	./installdep.sh 
	
### Build Ring (Compiler/VM)
	
	sudo ./buildgcc.sh

### Build Ring2EXE 

	cd ../ring2exe
	sudo ./buildring2exe.sh	
	
### Build RingODBC
	
	cd ../extensions/ringodbc
	./buildgcc.sh

### Build RingMySQL
	
	cd ../extensions/ringmysql
	./buildgcc.sh

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

### Build RingInternet
	
	cd ../extensions/ringinternet
	./buildgcc.sh

### Build RingMurmurHash
	
	cd ../extensions/ringmurmurhash
	./buildgcc.sh		
	
### Generate RingConsoleColors Source Code and Build 
	
	cd ../extensions/ringconsolecolors
	./gencode.sh
	./buildgcc.sh
	
### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
	./gencode.sh
	./buildgcc.sh

### Generate RingLibCurl Source Code and Build 
	
	cd ../extensions/ringcurl
	./gencode.sh
	./buildgcc.sh
	
### Generate RingZip Source Code and Build 
	
	cd ../extensions/ringzip
	./gencode.sh
	./buildgcc.sh

### Generate RingLibuv Source Code and Build 

We will build Libuv first

	cd ../extensions/ringlibuv/libuv
	sudo apt-get libtool install m4 automake
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
	./buildgcc.sh

### To be able to call ring from any folder 
	cd ../../bin
	sudo ./install.sh
	
### Run Ring Notepad
	
	cd applications/rnote
	sudo ring rnote.ring


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

### Build RingInternet
	
	cd ../extensions/ringinternet
	./buildgcc.sh

### Build RingMurmurHash
	
	cd ../extensions/ringmurmurhash
	./buildgcc.sh	
	
### Generate RingConsoleColors Source Code and Build 
	
	cd ../extensions/ringconsolecolors
	./gencode.sh
	./buildgcc.sh
	
### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
	./gencode.sh
	./buildgcc.sh

### Generate RingLibCurl Source Code and Build 
	
	cd ../extensions/ringcurl
	./gencode.sh
	./buildgcc.sh
	
### Generate RingZip Source Code and Build 
	
	cd ../extensions/ringzip
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
	./gencodemacos.sh
	./buildclang.sh

### To be able to call ring from any folder 
	cd ../../bin
	sudo ./install.sh
	
### Run Ring Notepad
	
	cd applications/rnote
	ring rnote.ring


## Building using CMake 

This will build the Ring compiler and Ring Virtual Machine 

	cmake .
	make
