===================================================
Ring For Mobile Games Development using RingLibSDL
===================================================

(1) Download Requirements

	* The Android SDK Tools
		https://developer.android.com/studio/index.html
	* The Android NDK 
		https://developer.android.com/ndk/index.html
	* Apache Ant v1.8 or later 
		http://ant.apache.org/bindownload.cgi
	* Java SE Development Kit (JDK) v6 or later
		http://www.oracle.com/technetwork/java/javase/downloads/jdk7-downloads-1880260.html

(2) Update the Android SDK to get the API and tools packages required for development



(3) Open the project folder : ring/android/ringlibsdl/project

You can add the source code (*.ring) and Images/Sound Files to the assets folder.

You will find the Flappy Bird 3000 Game ready for building.

The execution starts from the start.ring file

	load "game2.ring"


(4) Building the project

Move to the ring/android/ringlibsdl/project folder 

We can build using the next command (We need to do this for one time only).

	ndk-build

Then we can create the package (*.apk) using the next command.

	ant debug
