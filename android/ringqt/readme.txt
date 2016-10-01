===================================================
Ring For Mobile App Development 
(Android, iOS and Windows Phone) using Qt 5.5.1
===================================================

(1) Download Requirements
	http://doc.qt.io/qt-5/androidgs.html
	* The Android SDK Tools
		https://developer.android.com/studio/index.html
	* The Android NDK 
		https://developer.android.com/ndk/index.html
	* Apache Ant v1.8 or later 
		http://ant.apache.org/bindownload.cgi
	* Java SE Development Kit (JDK) v6 or later
		http://www.oracle.com/technetwork/java/javase/downloads/jdk7-downloads-1880260.html

(2) Update the Android SDK to get the API and tools packages required for development

(3) Install Qt for Android
		https://download.qt.io/archive/qt/5.5/5.5.1/

(4) Run Qt Creator, Select Tools > Options > Android to add the 
    Android NDK and SDK paths. 
		http://doc.qt.io/qtcreator/creator-developing-android.html

(5) Using Qt Creator Open the project 
	Folder : project
	Project file : project.pro

(6) You will find the code in resources\test.ring
	You can modify the code then build and run for Desktop or Mobile.

Comments

(1) The main project file is main.cpp 
	This file load Ring Compiler/Virtual Machine and RingQt 
	Then copy files during the runtime from the resources to temp. folder 
	Then run the test.ring
	Through main.cpp you can extract more files from the resources to temp. folder once you
	add them (create projects with many files).

(2) The next functions are missing from this Ring edition
	* Database (ODBC, SQLite & MySQL)
	* Security and Internet functions (LibCurl & OpenSSL)
	* RingAllegro (Allegro Library)
	* RingLibSDL (LibSDL Library)
	Just use Qt Classes through RingQt
	For database access use the QSqlDatabase Class
	Note: All of the missing libraries ((LibCurl, OpenSSL & Allegro) can be compiled for Android.
	      But they are not included in this Qt project.