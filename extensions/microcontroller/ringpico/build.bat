@echo off
rem generate ringappcode.c and ringappcode.h
ring main.ring -geo -norun
del main.c
move ringappcode.c picolib/src/loadapp >nul
move ringappcode.h picolib/src/loadapp >nul

@echo on
rem build the project
C:\PL\Pico151\cmake\bin\cmake.EXE --build c:/PL/Pico151samples/pico-examples/build --config Debug --target all --

