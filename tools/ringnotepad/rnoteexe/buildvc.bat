echo off
rem call vc.bat
call ../../../language/src/locatevc.bat

cls

rc rnote.rc
cl /DEBUG rnote.c rnote.res /link advapi32.lib shell32.lib /SUBSYSTEM:WINDOWS,"5.01" 

copy rnote.exe ..\..\..\RingNotepad.exe
