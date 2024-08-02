setlocal enableextensions enabledelayedexpansion

call config.bat

%RING_PICO_SDK%\pico-env

cd build
cmake ..
cd ..

@echo off
rem generate ringappcode.c and ringappcode.h
ring main.ring -geo -norun
del main.c
move ringappcode.c picolib/src/loadapp >nul
move ringappcode.h picolib/src/loadapp >nul

@echo on
rem build the project
cmake --build build

endlocal