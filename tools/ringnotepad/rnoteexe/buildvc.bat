echo off
rem call vc.bat
setlocal enableextensions enabledelayedexpansion
call ../../../language/src/locatevc.bat auto %1

cls

rc rnote.rc
cl rnote.c rnote.res /link advapi32.lib shell32.lib /SUBSYSTEM:WINDOWS,"5.01" 

copy rnote.exe ..\..\..\RingNotepad.exe
endlocal
