echo off
cls
REM Get the Current path for the Ring Notepad
set RNOTEPATH=%cd%
REM Change the current directory to the application folder
cd /d %~dp1
REM Execute the program
"%RNOTEPATH%/ring" %1
exit
