![Ring](https://ring-lang.github.io/theringlogo.jpg)

# Ring Programming Language

## Building using Microsoft Windows 

### Get the source code

	git clone http://github.com/ring-lang/ring.git

### Complete Build (Compiler/VM, Extensions, Tools, etc.)

* Install Qt 5.15.16  (in C:\Qt) so we have the folder (C:\Qt\5.15.16)

* If you have another version from Qt 5.15 (like Qt 5.15.2) - Or Qt is installed in another folder 
The next batch files uses environment variables (RING_QT_DIR & RING_QT_VERSION) to set the path

* To build 32bit version: 

	ring/build/buildvc.bat
	
* To build 64bit version: 

	ring/build/buildvc_x64.bat

* Add ring/bin folder to your system path 

* Run Ring Notepad 

	ringpm run ringnotepad

### Custom Build

#### 64bit version

The next steps demonstrates how to build the 32bit version

To build the 64bit version add _x64 to the batch file name (i.e. use buildvc_x64.bat instead of buildvc.bat)
Also, use ring/bin/install_x64.bat instead of ring/bin/install.bat

#### Build Ring (Compiler/VM)
	
	cd ring/language/build
	buildvc.bat
	buildvcw.bat

#### Build Ring2EXE 

	cd ring/tools/ring2exe
	build.bat 

#### Generate RingConsoleColors Source Code and Build 
	
	cd ring/extensions/ringconsolecolors
	gencode.bat
	buildvc.bat

#### Build RingInternet
	
	cd ring/extensions/ringinternet
	buildvc.bat

#### Generate RingLibCurl Source Code and Build 
	
	cd ring/extensions/ringcurl
	gencode.bat
	buildvc.bat

#### Generate RingZip Source Code and Build 
	
	cd ring/extensions/ringzip
	gencode.bat
	buildvc.bat

#### Build RingPM

	cd ring/tools/ringpm
	build.bat 

#### Build RingREPL

	cd ring/tools/ringrepl
	build.bat 

#### Build Folder2QRC

	cd ring/tools/folder2qrc
	build.bat 
	
#### Build RingODBC
	
	cd ring/extensions/ringodbc
	buildvc.bat

#### Build RingMySQL
	
	cd ring/extensions/ringmysql
	buildvc.bat

#### Build RingSQLite
	
	cd ring/extensions/ringsqlite
	buildvc.bat

#### Build RingPostgreSQL
	
	cd ring/extensions/ringpostgresql
	gencode.bat
	buildvc.bat

#### Build RingOpenSSL
	
	cd ring/extensions/ringopenssl
	buildvc.bat

#### Build RingMurmurHash
	
	cd ring/extensions/ringmurmurhash
	buildvc.bat
	
#### Generate RingAllegro Source Code and Build 
	
	cd ring/extensions/ringallegro
	gencode.bat
	buildvc.bat
	
#### Generate RingLibuv Source Code and Build 
	
	cd ring/extensions/ringlibuv
	gencode.bat
	buildvc.bat

#### Generate RingFreeGLUT Source Code and Build 
	
	cd ring/extensions/ringfreeglut
	gencode.bat
	buildvc.bat

#### Generate RingOpenGL Source Code and Build 

The ringopengl folder contains many sub folders for different OpenGL versions
Starting from OpenGL 1.1 to OpenGL 4.6
	
	cd ring/extensions/ringopengl/opengl21
	gencode.bat
	buildvc.bat
	
### Generate RingQt Source Code and Build

Tested using Qt 5.15

	Install Qt 5.15
	cd ring/extensions/ringqt
	gencode_light.bat
	buildvc_light.bat
	gencode_nobluetooth.bat
	buildvc_nobluetooth.bat

To Copy the Qt runtime files to ring/bin folder

	cd ring/extensions/ringqt/binupdate
	installqt515.bat


#### To be able to call ring from any folder 
	
	cd ring/bin
	install.bat
	
##### Add Ring/bin to System path

	Hit "windows key".
	Type "Edit the System environment variables"
	Select "Advanced" tab.
	Click on "Environment Variables..."
	Double click on "Path"
	Add at the end the new path separated by semicolon. 
		;C:\Ring\Bin
	
#### Run Ring Notepad
	
	cd ring/tools/ringnotepad
	ring rnote.ring

Also, We can run Ring Notepad using Ring Package Manager

	ringpm run ringnotepad

#### More Extensions

The previous steps demonstrates building Ring and some of the Ring extensions.

There are more extensions in ring/extensions folder like RingCJSON, RingHTTPLib, etc.
