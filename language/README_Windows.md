![Ring](http://ring-lang.sf.net/thering.jpg)

# Ring Programming Language

## Building using Microsoft Windows 

### Get the source code

	git clone http://github.com/ring-lang/ring.git
	
### Build Ring (Compiler/VM)
	
	cd ring/language/src
	buildvc.bat
	buildvcw.bat

### Build Ring2EXE 

	cd ../../tools/ring2exe
	buildring2exe.bat 

### Generate RingConsoleColors Source Code and Build 
	
	cd ../extensions/ringconsolecolors
	gencode.bat
	buildvc.bat

### Build RingInternet
	
	cd ../extensions/ringinternet
	buildvc.bat

### Generate RingLibCurl Source Code and Build 
	
	cd ../extensions/ringcurl
	gencode.bat
	buildvc.bat

### Generate RingZip Source Code and Build 
	
	cd ../extensions/ringzip
	gencode.bat
	buildvc.bat

### Build RingPM

	cd ../tools/ringpm
	buildringpm.bat 
	
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

### Build RingMurmurHash
	
	cd ../extensions/ringmurmurhash
	buildvc.bat
	
### Generate RingAllegro Source Code and Build 
	
	cd ../extensions/ringallegro
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

Tested using Qt 5.12 and Qt 5.15

For Qt 5.12

	Install Qt 5.12 : https://download.qt.io/archive/qt/5.12/5.12.6/
	
	cd ../extensions/ringqt
	gencodeqt512_nobluetooth.bat
	buildqt512_nobluetooth.bat

To Copy the Qt runtime files to ring/bin folder

	cd ring/extensions/ringqt/binupdate
	installqt512.bat

For Qt 5.15

	Install Qt 5.15
	cd ../extensions/ringqt
	gencodeqt515_nobluetooth.bat
	buildqt515_nobluetooth.bat

To Copy the Qt runtime files to ring/bin folder

	cd ring/extensions/ringqt/binupdate
	installqt515.bat


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
	
	cd tools/ringnotepad
	ring rnote.ring
