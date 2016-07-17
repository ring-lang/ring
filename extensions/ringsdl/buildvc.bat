cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_libsdl.c -I"..\..\libdepwin\sdl2vc\include" -I"..\..\include"
link /DEBUG ring_libsdl.obj  ..\..\lib\ring.lib ..\..\libdepwin\sdl2vc\lib\x86\sdl2.lib ..\..\libdepwin\sdl2vc\lib\x86\sdl2main.lib /DLL /OUT:..\..\bin\ring_sdl.dll /SUBSYSTEM:WINDOWS,"5.01" /NODEFAULTLIB:msvcrt.lib
del ring_libsdl.obj