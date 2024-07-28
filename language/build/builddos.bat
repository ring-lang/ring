cd ..\src

@echo off
set __opath=%path%
set path=C:\WATCOM\bin;C:\WATCOM\binb
set __oinc=%include%
set include=C:\WATCOM\h;..\include
set watcom=C:\WATCOM\.
rename dll_e.c dll_e.no
rename ringw.c ringw.no
wcl386 ring.c *.c
wcl386 ring.obj *.obj
rename dll_e.no dll_e.c
rename ringw.no ringw.c
set include=%__oinc%
set __oinc=
set path=%__opath%
set __opath=
