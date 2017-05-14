echo off
rem call vc.bat
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86

cls

rc rnote.rc
cl /DEBUG rnote.c rnote.res /link advapi32.lib shell32.lib /SUBSYSTEM:WINDOWS,"5.01" 

copy rnote.exe ..\
