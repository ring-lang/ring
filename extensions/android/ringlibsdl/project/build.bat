echo off
cls

rem You will need to modify this batch file based on your environment

set JAVA_HOME=C:\Program Files (x86)\Java\jdk1.8.0_05
set ANDROID_HOME=B:\mahmoud\Tools\JavaAndroid\adt-bundle-windows-x86-20140702\sdk
set NDK_ROOT=B:\mahmoud\Tools\JavaAndroid\android-ndk-r10c

set path=%path%;B:\mahmoud\Tools\JavaAndroid\android-ndk-r10c
set path=%path%;;B:\mahmoud\Tools\JavaAndroid\apache-ant-1.9.4\bin

ndk-build