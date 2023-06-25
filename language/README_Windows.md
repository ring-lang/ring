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

	cd ring/tools/ring2exe
	build.bat 

### Generate RingConsoleColors Source Code and Build 
	
	cd ring/extensions/ringconsolecolors
	gencode.bat
	buildvc.bat

### Build RingInternet
	
	cd ring/extensions/ringinternet
	buildvc.bat

### Generate RingLibCurl Source Code and Build 
	
	cd ring/extensions/ringcurl
	gencode.bat
	buildvc.bat

### Generate RingZip Source Code and Build 
	
	cd ring/extensions/ringzip
	gencode.bat
	buildvc.bat

### Build RingPM

	cd ring/tools/ringpm
	build.bat 
	
### Build RingODBC
	
	cd ring/extensions/ringodbc
	buildvc.bat

### Build RingMySQL
	
	cd ring/extensions/ringmysql
	buildvc.bat

### Build RingSQLite
	
	cd ring/extensions/ringsqlite
	buildvc.bat

### Build RingPostgreSQL
	
	cd ring/extensions/ringpostgresql
	gencode.bat
	buildvc.bat

### Build RingOpenSSL
	
	cd ring/extensions/ringopenssl
	buildvc.bat

### Build RingMurmurHash
	
	cd ring/extensions/ringmurmurhash
	buildvc.bat
	
### Generate RingAllegro Source Code and Build 
	
	cd ring/extensions/ringallegro
	gencode.bat
	buildvc.bat
	
### Generate RingLibuv Source Code and Build 
	
	cd ring/extensions/ringlibuv
	gencode.bat
	buildvc.bat

### Generate RingFreeGLUT Source Code and Build 
	
	cd ring/extensions/ringfreeglut
	gencode.bat
	buildvc.bat

### Generate RingOpenGL Source Code and Build 

The ringopengl folder contains many sub folders for different OpenGL versions
Starting from OpenGL 1.1 to OpenGL 4.6
	
	cd ring/extensions/ringopengl/opengl21
	gencode.bat
	buildvc.bat
	
### Generate RingQt Source Code and Build

Tested using Qt 5.15

	Install Qt 5.15
	cd ring/extensions/ringqt
	gencodeqt515_light.bat
	buildqt515_light.bat
	gencodeqt515_nobluetooth.bat
	buildqt515_nobluetooth.bat

To Copy the Qt runtime files to ring/bin folder

	cd ring/extensions/ringqt/binupdate
	installqt515.bat


### To be able to call ring from any folder 
	
	cd ring/bin
	install.bat
	
#### Add Ring/bin to System path

	Hit "windows key".
	Type "Edit the System environment variables"
	Select "Advanced" tab.
	Click on "Environment Variables..."
	Double click on "Path"
	Add at the end the new path separated by semicolon. 
		;C:\Ring\Bin
	
### Run Ring Notepad
	
	cd ring/tools/ringnotepad
	ring rnote.ring
