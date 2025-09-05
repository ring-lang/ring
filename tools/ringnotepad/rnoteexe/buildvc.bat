echo off
setlocal enableextensions enabledelayedexpansion
call ../../../language/build/locatevc.bat auto %1

cls

rc rnote.rc
cl rnote.c rnote.res /link advapi32.lib shell32.lib

copy rnote.exe ..\..\..\RingNotepad.exe
endlocal
