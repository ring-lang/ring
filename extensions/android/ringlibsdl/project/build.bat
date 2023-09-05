echo off
cls

rem You will need to modify this batch file based on your environment

set JAVA_HOME=C:\PL\Java\jdk1.8.0_05
set ANDROID_HOME=C:\PL\adt-bundle-windows-x86-20140702\sdk
set NDK_ROOT=c:\PL\android-ndk-r10c

set path=%path%;c:\PL\android-ndk-r10c
set path=%path%;;C:\PL\apache-ant-1.9.4\bin

ndk-build