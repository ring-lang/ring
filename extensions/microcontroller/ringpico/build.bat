setlocal enableextensions enabledelayedexpansion

call config.bat

@echo off
rem generate ringappcode.c and ringappcode.h
ring main.ring -geo -norun
del main.c
move ringappcode.c picolib/src/loadapp >nul
move ringappcode.h picolib/src/loadapp >nul

@echo on
rem build the project
%RING_PICO_SDK%\cmake\bin\cmake.EXE --build %RING_PICO_EXAMPLES%\pico-examples\build --config Debug --target all --

endlocal