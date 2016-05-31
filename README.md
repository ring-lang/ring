![Ring](http://ring-lang.sourceforge.net/thering.jpg)
=============
Description
=============

The Ring is an Innovative and practical general-purpose multi-paradigm scripting language that
can be embedded in C/C++ projects, extended using C/C++ code and/or used as standalone language.
The supported programming paradigms are Imperative, Procedural, Object-Oriented, Functional,
Meta programming, Declarative programming using nested structures, and Natural programming.
The language is portable (Windows, Linux, Mac OS X, Android, etc.) and can be used to create
Console, GUI, Web, Games and Mobile applications. 
The language is designed to be Simple, Small, Flexible and Fast. 
Its Dynamic Language (Dynamic Typing and Weakly Typed) that compile the source code to
byte code then execute it by the Ring Virtual Machine, which is integrated with the
Ring Compiler in one program. 
The first version of the language (around 100,000 lines of C/C++/Ring code) is released on
January 25th, 2016.

The language is simple, trying to be natural, encourage organization and comes with 
transparent and visual implementation. It comes with compact syntax and a group of features that
enable the programmer to create natural interfaces and declarative domain-specific 
languages in a fraction of time. It is very small, fast and comes with smart garbage
collector that puts the memory under the programmer control. It supports many 
programming paradigms, comes with useful and practical libraries. The language is
designed for productivity and developing high quality solutions that can scale.

The language is designed for a Clear Goal

* Applications programming language.

* Productivity and developing high quality solutions that can scale.

* Small and fast language that can be embedded in C/C++ projects.

* Simple language that can be used in education and introducing Compiler/VM concepts.

* General-Purpose language that can be used for creating domain-specific libraries, frameworks and tools.

* Practical language designed for creating the next version of the Programming Without Coding Technology software.

[Read more!](http://ring-lang.sourceforge.net/#why)

#Build from source code

## Building using MacOS X

### Get the source code

	git clone http://github.com/ring-lang/ring.git
	
### Install homebrew (follow the directions on [homebrew's homepage](http://brew.sh/)).
	
### Install Libraries 
	
	brew install mysql-connector-c allegro qt52
	
### Build Ring (Compiler/VM)
	
	cd ring/src
	./buildclangcomplete.sh
	
	
### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
	./gencode.sh
	./buildclang.sh

	
### Generate RingQt Source Code and Build
	
	cd ../ringqt
	./gencode.sh
	./buildclang.sh

### To be able to call ring from any folder 
	cd ../../
	sudo ./install.sh
	
### Run Ring Notepad
	
	cd applications/rnote
	sudo ring rnote.ring

### Screen Shot
	
![Ring](http://ring-lang.sourceforge.net/ringmac.png)

### Run Ring Applications and Games from Ring Notepad

The next screen shot for the SuperMan Game (Developed using Ring)

![Ring](http://ring-lang.sourceforge.net/supermanmac.png)

To run the stars fighter game from the terminal
	
	cd ../../ringlibs/gameengine
	ring loadgame1.ring

To run the Flappy Bird 3000 game 

	ring loadgame2.ring

To run the SuperMan game 

	ring loadgame3.ring
	
## Building using Ubuntu Linux 

### Get the source code

	git clone http://github.com/ring-lang/ring.git
	
### Install Libraries 
	
	cd ring/src
	./installdep.sh 
	
### Build Ring (Compiler/VM)
	
	sudo ./buildgcccomplete.sh
	
### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
	./gencode.sh
	./buildgcc.sh

	
### Generate RingQt Source Code and Build
	
	cd ../ringqt
	./gencode.sh
	./buildgcc.sh

### To be able to call ring from any folder 
	cd ../../
	sudo ./install.sh
	
### Run Ring Notepad
	
	cd applications/rnote
	sudo ring rnote.ring

### Screen Shot
	
![Ring](http://ring-lang.sourceforge.net/ringubuntu.jpg)

## Building using Microsoft Windows 

### Get the source code

	git clone http://github.com/ring-lang/ring.git
	
### Install Libraries 
	
	MySQL     : https://dev.mysql.com/downloads/connector/c/
	LibCurl   : https://curl.haxx.se/libcurl/
	OpenSSL   : https://www.openssl.org
	Allegro 5 : http://liballeg.org/download.html#windows
	Qt 5.5    : https://download.qt.io/archive/qt/5.5/5.5.1/
	
	You can quickly install MySQL, LibCurl, OpenSSL and Allegro libraries 
	from this link : https://sourceforge.net/projects/ring-lang/files/Ring%201.0/libdepwin.zip/download
	Then extract and copy the libraries folders to Ring/libdepwin
	
### Build Ring (Compiler/VM)
	
	cd ring/src
	buildvccomplete.bat
	
### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
	gencode.bat
	buildvc.bat
	
### Generate RingQt Source Code and Build
	
	cd ../ringqt
	gencode.bat
	buildvc.bat

### To be able to call ring from any folder 
	
	cd ../../
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

### Screen Shot
	
![Ring](http://ring-lang.sourceforge.net/ringwin.jpg)


=====================
Visual Implementation
=====================

The Ring programming language is designed using the PWCT visual programming tool (http://pwct.org)
and you will find the visual source of the language in the folder "visualsrc" - *.ssf files and 
the generated source code (In the C Language) in the [src folder](https://github.com/ring-lang/ring/tree/master/src)
and the [include folder](https://github.com/ring-lang/ring/tree/master/include). 
The next screen shots demonstrates how to visually modify the Ring Compiler and Virtual Machine (VM)
then generate the C code.

The next screen shot from the ring_vm.ssf file (Generate [ring_vm.c](https://github.com/ring-lang/ring/blob/master/src/ring_vm.c) and [ring_vm.h](https://github.com/ring-lang/ring/blob/master/include/ring_vm.h))
![Ring](http://ring-lang.sourceforge.net/ringvisualsrc1.jpg)

The next screen shot from the ring_list.ssf file (Generate [ring_list.c](https://github.com/ring-lang/ring/blob/master/src/ring_list.c) and [ring_list.h](https://github.com/ring-lang/ring/blob/master/include/ring_list.h))
![Ring](http://ring-lang.sourceforge.net/ringvisualsrc2.jpg)
