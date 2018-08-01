echo off
cls
REM Get the Current path for the Ring Executable
set RINGEXEPATH=%cd%
REM Change the current directory to the application folder
cd /d %~dp1
REM Execute the program
"%RINGEXEPATH%/ring.exe" %1
exit
